#!/usr/bin/env python3
"""Convert the stable TPTP SyntaxBNF notation to an ANTLR4 combined grammar
(lexer rules and parser rules in one ANTLR .g4 file).

::= defines parser rules, :== becomes comments, ::- defines tokens,
and ::: defines fragments (or tokens when referenced directly by parser rules).
"""

import argparse
import importlib.util
import re
import subprocess
import sys
import tempfile
from collections import Counter
from dataclasses import dataclass
from pathlib import Path

from antlr4 import CommonTokenStream, InputStream
from antlr4.error.ErrorListener import ErrorListener


REPOSITORY_ROOT = Path(__file__).resolve().parents[2]
DEFAULT_METAGRAMMAR = REPOSITORY_ROOT / "BNFMetaGrammar/BNFMetaParser.g4"
DEFAULT_ANTLR_JAR = REPOSITORY_ROOT / "ANTLRParsers/antlr-4.13.2-complete.jar"
DEFAULT_OUTPUT_DIRECTORY = REPOSITORY_ROOT / "BNFMetaGrammar/ANTLRGrammar/converted_by_meta"
OPERATOR_CHARACTERS = set("!#&*+-/:<=>?@^~|")


class ConversionError(RuntimeError):
    """An invalid SyntaxBNF definition."""


def select_input_file(input_path: Path | None = None) -> Path:
    """Use an explicit file, or the sole SyntaxBNF* file in the repository root."""
    if input_path is not None:
        if not input_path.is_file():
            raise ConversionError(f"BNF input is not a file: {input_path}")
        return input_path

    root = REPOSITORY_ROOT
    candidates = [path for path in root.glob("SyntaxBNF*") if path.is_file()]
    if len(candidates) == 0:
        raise ConversionError(f"No files beginning with SyntaxBNF found in {root}")
    if len(candidates) > 1:
        raise ConversionError(
            f"Multiple SyntaxBNF files found in {root}; specify the input file explicitly."
        )
    return candidates[0]


class SyntaxErrors(ErrorListener):
    def syntaxError(self, recognizer, offendingSymbol, line, column, msg, e):
        raise ConversionError(f"line {line}:{column}: {msg}")


@dataclass
class Definition:
    name: str
    operator: str
    expression: object
    context: object


def generate_metaparser(metagrammar: Path, antlr_jar: Path, output_directory: Path):
    subprocess.run(
        ["java", "-jar", str(antlr_jar), "-Dlanguage=Python3", "-no-listener",
         "-Xexact-output-dir", "-o", str(output_directory),
         "-lib", str(output_directory),
         str(metagrammar.with_name("BNFMetaLexer.g4")), str(metagrammar)],
        check=True,
    )


def import_generated_metaparser(output_directory: Path):
    # Load these files directly: ordinary imports would reuse an earlier parser.
    classes = []
    for name in ("BNFMetaLexer", "BNFMetaParser"):
        spec = importlib.util.spec_from_file_location(name, output_directory / f"{name}.py")
        if spec is None or spec.loader is None:
            raise ConversionError(f"Cannot load generated module {name}")
        module = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(module)
        classes.append(getattr(module, name))
    return classes


def parse_syntax_bnf(input_path: Path, metagrammar: Path, antlr_jar: Path):
    source = input_path.read_text(encoding="utf-8")
    with tempfile.TemporaryDirectory(prefix="bnf2antlr-meta-") as temporary:
        directory = Path(temporary)
        generate_metaparser(metagrammar, antlr_jar, directory)
        lexer_class, parser_class = import_generated_metaparser(directory)
        lexer = lexer_class(InputStream(source))
        parser = parser_class(CommonTokenStream(lexer))
        for recognizer in (lexer, parser):
            recognizer.removeErrorListeners()
            recognizer.addErrorListener(SyntaxErrors())
        definitions = [
            Definition(rule.name.text[1:-1], rule.separator.text,
                       rule.syntaxExpression() or rule.regexExpression(), rule)
            for rule in parser.document().definition()
        ]
    return definitions, source, lexer_class


def lexer_name(name: str) -> str:
    return name[0].upper() + name[1:]


def literal(text: str) -> str:
    escaped = text.translate(str.maketrans({
        "\\": r"\\", "'": r"\'", "\n": r"\n", "\r": r"\r", "\t": r"\t",
    }))
    return f"'{escaped}'"


def format_rule(name: str, alternatives: list[str], command: str = "") -> str:
    lines = [name]
    for index, alternative in enumerate(alternatives):
        separator = ":" if index == 0 else "|"
        lines.append(f"    {separator} {alternative}".rstrip())
    lines.append(f"    {command};")
    return "\n".join(lines) + "\n"


def charset_char(char) -> tuple[int, str]:
    """Return the character's code point and its ANTLR spelling."""
    text = char.getText()
    if char.OCTAL_ESCAPE():
        code = int(text[1:], 8)
        if code > 0x10FFFF:
            raise ConversionError(f"line {char.start.line}: octal escape exceeds Unicode range")
        spelling = f"\\u{code:04X}" if code <= 0xFFFF else f"\\u{{{code:X}}}"
        return code, spelling
    if char.QUOTED_ESCAPE():
        text = {r"\n": "\n", r"\r": "\r", r"\\": "\\"}[text]
    spelling = {"\\": r"\\", "\n": r"\n", "\r": r"\r", "[": r"\u005B"}.get(text, text)
    return ord(text), spelling


def charset(char_set) -> str:
    if char_set.WILDCARD():
        return "."
    content = char_set.charSetContent()
    parts = [r"\-"] if content.leadingDash else []
    for element in content.charSetElement():
        characters = [charset_char(c) for c in element.charSetChar()]
        if len(characters) == 2 and characters[0][0] > characters[1][0]:
            raise ConversionError(
                f"line {element.start.line}: descending character range {element.getText()!r}"
            )
        parts.append("-".join(spelling for _, spelling in characters))
    if content.trailingDash:
        parts.append(r"\-")
    negation = "~" if char_set.NEGATED_LBRACKET() else ""
    return negation + "[" + "".join(parts) + "]"


def regex_element(element) -> str:
    primary = element.regexPrimary()
    if primary.NONTERMINAL():
        text = lexer_name(primary.getText()[1:-1])
    elif primary.regexExpression():
        text = "( " + " | ".join(regex_alternatives(primary.regexExpression())) + " )"
    else:
        text = charset(primary.charSet())
    quantifier = element.regexQuantifier()
    return text + (quantifier.getText() if quantifier else "")


def regex_alternatives(expression) -> list[str]:
    return [
        " ".join(regex_element(element) for element in alternative.regexElement())
        for alternative in expression.regexAlternative()
    ]


def lexical_pattern(name: str, definitions: dict[str, Definition]) -> re.Pattern:
    """Match complete literal spellings against a SyntaxBNF lexical definition."""
    patterns = {}
    visiting = set()

    def rule(rule_name):
        if rule_name in visiting:
            raise ConversionError(f"Recursive lexical definition in <{name}>: <{rule_name}>")
        if rule_name not in patterns:
            if rule_name not in definitions:
                raise ConversionError(f"Undefined lexical reference <{rule_name}> in <{name}>")
            visiting.add(rule_name)
            patterns[rule_name] = expression(definitions[rule_name].expression)
            visiting.remove(rule_name)
        return patterns[rule_name]

    def expression(context):
        alternatives = []
        for alternative in context.regexAlternative():
            parts = []
            for element in alternative.regexElement():
                primary = element.regexPrimary()
                if primary.NONTERMINAL():
                    part = rule(primary.getText()[1:-1])
                elif primary.regexExpression():
                    part = expression(primary.regexExpression())
                else:
                    char_set = primary.charSet()
                    charset(char_set)  # Apply the same validation as ANTLR emission.
                    if char_set.WILDCARD():
                        part = r"[\s\S]"
                    else:
                        content = char_set.charSetContent()
                        characters = [r"\-"] if content.leadingDash else []
                        for item in content.charSetElement():
                            characters.append("-".join(
                                re.escape(chr(charset_char(char)[0]))
                                for char in item.charSetChar()
                            ))
                        if content.trailingDash:
                            characters.append(r"\-")
                        negation = "^" if char_set.NEGATED_LBRACKET() else ""
                        part = "[" + negation + "".join(characters) + "]"
                quantifier = element.regexQuantifier()
                parts.append("(?:" + part + ")" +
                             (quantifier.getText() if quantifier else ""))
            alternatives.append("".join(parts))
        return "(?:" + "|".join(alternatives) + ")"

    return re.compile(rule(name))


class GrammarConverter:
    def __init__(self, definitions, source, lexer_class, grammar_name,
                 source_name, metagrammar_name):
        self.source = source
        self.grammar_name = grammar_name
        self.source_name = source_name
        self.metagrammar_name = metagrammar_name
        self.syntax = [d for d in definitions if d.operator == "::="]
        self.semantic = [d for d in definitions if d.operator == ":=="]
        self.lexical = [d for d in definitions if d.operator in ("::-", ":::")]
        self.lexer_names = {d.name for d in self.lexical}
        self.bare_word = lexer_class.BARE_WORD
        alternatives = [a for d in self.syntax for a in d.expression.syntaxAlternative()]
        self.references = {
            element.NONTERMINAL().getText()[1:-1]
            for alternative in alternatives for element in alternative.syntaxElement()
            if element.NONTERMINAL()
        }
        # All-punctuation alternatives define operators such as => and ?*.
        operators = {a.getText() for a in alternatives
                     if a.getText() and set(a.getText()) <= OPERATOR_CHARACTERS}
        ordered = sorted(operators, key=lambda text: (-len(text), text))
        self.punctuation = re.compile("|".join([re.escape(op) for op in ordered] + ["."]))
        self.lower_word_literals = []
        self.lower_word_wrapper = None
        if "lower_word" in self.references and "lower_word" in self.lexer_names:
            candidates = {
                element.start.text
                for alternative in alternatives for element in alternative.syntaxElement()
                if element.start.type == self.bare_word
            }
            if candidates:
                pattern = lexical_pattern("lower_word", {d.name: d for d in self.lexical})
                self.lower_word_literals = sorted(
                    word for word in candidates if pattern.fullmatch(word)
                )
            if self.lower_word_literals:
                occupied = {d.name.lower() for d in self.syntax}
                self.lower_word_wrapper = "lower_word_token"
                suffix = 2
                while self.lower_word_wrapper in occupied:
                    self.lower_word_wrapper = f"lower_word_token_{suffix}"
                    suffix += 1

    def syntax_alternative(self, alternative) -> str:
        parts = []
        punctuation = ""
        previous_stop = -1

        def flush():
            nonlocal punctuation
            parts.extend(literal(p) for p in self.punctuation.findall(punctuation))
            punctuation = ""

        for element in alternative.syntaxElement():
            token = element.start
            if token.start != previous_stop + 1:
                flush()
            if element.NONTERMINAL():
                flush()
                name = token.text[1:-1]
                if name == "lower_word" and self.lower_word_wrapper:
                    name = self.lower_word_wrapper
                else:
                    name = lexer_name(name) if name in self.lexer_names else name.lower()
                parts.append(name + ("*" if element.STAR() else ""))
            elif token.type == self.bare_word:
                flush()
                parts.append(literal(token.text))
            else:
                punctuation += token.text
            previous_stop = element.stop.stop
        flush()
        return " ".join(parts)

    def convert(self) -> str:
        blocks = [
            f"grammar {self.grammar_name};\n",
            f"// Generated from {self.source_name} using {self.metagrammar_name}.\n"
            "// ::= rules are parser rules; :== restrictions are comments;\n"
            "// ::- rules are tokens; ::: rules are lexer fragments unless\n"
            "// referenced directly by a parser rule.\n",
        ]
        for index, definition in enumerate(self.syntax):
            alternatives = [self.syntax_alternative(a)
                            for a in definition.expression.syntaxAlternative()]
            if index == 0 and definition.name == "TPTP_file":
                alternatives = [(a + " EOF").strip() for a in alternatives]
            blocks.append(format_rule(definition.name.lower(), alternatives))

        if self.lower_word_wrapper:
            blocks.append(
                "// Preserve Lower_word spellings shadowed by implicit literal tokens.\n" +
                format_rule(self.lower_word_wrapper,
                            ["Lower_word"] + [literal(word) for word in self.lower_word_literals])
            )

        if self.semantic:
            comments = [
                "// Semantic restrictions from SyntaxBNF.",
                "// They constrain the language semantically and are intentionally",
                "// not added as alternative context-free productions.",
            ]
            for definition in self.semantic:
                context = definition.context
                text = self.source[context.start.start:context.stop.stop + 1]
                comments.append(f"// line {context.start.line}: {' '.join(text.split())}")
            blocks.append("\n".join(comments) + "\n")

        blocks.append("// Lexer rules derived from ::- and ::: definitions.")
        for definition in self.lexical:
            name = lexer_name(definition.name)
            if definition.operator == ":::" and definition.name not in self.references:
                name = "fragment " + name
            alternatives = regex_alternatives(definition.expression)
            command = "-> skip" if definition.name == "comment" else ""
            if command and len(alternatives) > 1:
                alternatives = ["( " + " | ".join(alternatives) + " )"]
            blocks.append(format_rule(name, alternatives, command))

        blocks.append("// SyntaxBNF permits whitespace between tokens.\n"
                      "WS\n    : [ \\t\\r\\n]+ -> skip\n    ;\n")
        return "\n".join(blocks)


def main(argv=None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("input", type=Path, nargs="?",
                        help="BNF input file (default: select the SyntaxBNF* file in repository root)")
    parser.add_argument("output", type=Path, nargs="?",
                        help="output directory or .g4 file (default: BNFMetaGrammar/ANTLRGrammar/converted_by_meta)")
    parser.add_argument("--output-grammar-name", default="TPTP",
                        help="output grammar name (default: TPTP)")
    parser.add_argument("--metagrammar", type=Path, default=DEFAULT_METAGRAMMAR)
    parser.add_argument("--antlr-jar", type=Path, default=DEFAULT_ANTLR_JAR)
    args = parser.parse_args(argv)
    # Preserve the output-only invocation when one positional argument is supplied.
    if args.output is None:
        args.input, args.output = None, args.input or DEFAULT_OUTPUT_DIRECTORY
    if not re.fullmatch(r"[A-Za-z][A-Za-z0-9_]*", args.output_grammar_name):
        parser.error(f"invalid ANTLR grammar name: {args.output_grammar_name!r}")

    try:
        input_path = select_input_file(args.input)
        definitions, source, lexer = parse_syntax_bnf(
            input_path, args.metagrammar.resolve(), args.antlr_jar.resolve(),
        )
        conversion = GrammarConverter(
            definitions, source, lexer, args.output_grammar_name,
            input_path.name, args.metagrammar.name,
        )
        grammar = conversion.convert()
        output = args.output
        if output.suffix != ".g4":
            output /= f"{args.output_grammar_name}.g4"
        output.parent.mkdir(parents=True, exist_ok=True)
        output.write_text(grammar, encoding="utf-8")
    except (ConversionError, OSError, subprocess.CalledProcessError) as error:
        print(f"error: {error}", file=sys.stderr)
        return 1

    counts = Counter(d.operator for d in definitions)
    parser_rules = counts['::='] + bool(conversion.lower_word_wrapper)
    print(f"Wrote {output} ({parser_rules} parser rules, {counts['::-']} tokens, "
          f"{counts[':::']} macros, {counts[':==']} semantic restrictions).")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
