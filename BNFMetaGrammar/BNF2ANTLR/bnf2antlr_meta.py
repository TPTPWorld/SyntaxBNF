#!/usr/bin/env python3
"""Convert the stable TPTP SyntaxBNF notation to an ANTLR4 combined grammar
(lexer rules and parser rules in one ANTLR .g4 file).

::= defines parser rules, :== becomes comments, ::- defines tokens,
and ::: defines fragments (or tokens when referenced directly by parser rules).
"""

import argparse
import importlib.util
import inspect
import re
import subprocess
import sys
import tempfile
from collections import Counter
from dataclasses import dataclass
from pathlib import Path
from typing import Any, cast

import antlr4
import antlr4.error.ErrorListener


REPOSITORY_ROOT = Path(__file__).resolve().parents[2]
DEFAULT_METAGRAMMAR = REPOSITORY_ROOT / "BNFMetaGrammar/BNFMetaParser.g4"
DEFAULT_ANTLR_JAR = REPOSITORY_ROOT / "ANTLRParsers/antlr-4.13.2-complete.jar"
DEFAULT_OUTPUT_DIRECTORY = REPOSITORY_ROOT / "BNFMetaGrammar/ANTLRGrammar/converted_by_meta"
OPERATOR_CHARACTERS = set("!#&*+-/:<=>?@^~|")


@dataclass
class Definition:
    """A definition from SyntaxBNF."""

    name: str
    """LHS of the definition."""

    separator: str
    ''' "::=", ":==", "::-", or ":::" '''

    expression: Any
    """RHS of the definition:
    syntaxExpression or regexExpression (see `definition` in BNFMetaParser.g4).
    The runtime type will be SyntaxExpressionContext or RegexExpressionContext."""

    context: Any
    """The entire DefinitionContext from the runtime-generated parser class, BNFMetaParser.
    (Note: the runtime class DefinitionContext will be generated from `definition`
    in BNFMetaParser.g4 and inherits ANTLR’s generic ParserRuleContext class.)"""

class ConversionError(RuntimeError):
    """An error converting BNF to ANTLR, e.g., missing input, parser loading
    failure, or an invalid SyntaxBNF definition.
    """

class SyntaxErrorListener(antlr4.error.ErrorListener.ErrorListener):
    def syntaxError(self, recognizer, offendingSymbol, line, column, msg, e):
        raise ConversionError(f"line {line}:{column}: {msg}")


def select_input_file(input_path: Path | None = None) -> Path:
    """Use an explicit file, or the sole SyntaxBNF-v* file in the repository root."""
    if input_path is not None:
        if not input_path.is_file():
            raise ConversionError(f"BNF input is not a file: {input_path}")
        return input_path

    root = REPOSITORY_ROOT
    candidates = [path for path in root.glob("SyntaxBNF-v*") if path.is_file()]
    if len(candidates) == 0:
        raise ConversionError(f"No files beginning with SyntaxBNF-v found in {root}")
    if len(candidates) > 1:
        raise ConversionError(
            f"Multiple SyntaxBNF files found in {root}; specify the input file explicitly."
        )
    return candidates[0]

def generate_metaparser(metagrammar: Path, antlr_jar: Path, output_directory: Path):
    subprocess.run(
        ["java", "-jar", str(antlr_jar), "-Dlanguage=Python3", "-no-listener",
         "-Xexact-output-dir", "-o", str(output_directory),
         "-lib", str(output_directory),
         str(metagrammar.with_name("BNFMetaLexer.g4")), str(metagrammar)],
        check=True,
    )

def import_generated_metaparser(output_directory: Path):
    """Load generated lexer and parser"""
    classes = []
    for name in ("BNFMetaLexer", "BNFMetaParser"):
        spec = importlib.util.spec_from_file_location(name, output_directory / f"{name}.py")
        if spec is None or spec.loader is None:
            raise ConversionError(f"Cannot load generated module {name}")
        module = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(module)
        classes.append(getattr(module, name))
    return classes


def debug_print_syntax_bnf(LexerClass: type[antlr4.Lexer],
                           ParserClass: type[antlr4.Parser], bnf_source_text: str):
    """Print generated class details and inspect rules parsed from the source."""
    for label, value in (
        ("lexer_class.__name__", LexerClass.__name__),
        ("parser_class.__name__", ParserClass.__name__),
        ("lexer_class.__mro__", LexerClass.__mro__),   # Method Resolution Order
        ("parser_class.__mro__", ParserClass.__mro__),
        ("dir(lexer_class)", dir(LexerClass)),
        ("list(vars(lexer_class))", list(vars(LexerClass))),
        ("list(vars(parser_class))", list(vars(ParserClass))),
        ("lexer_class.symbolicNames", cast(Any, LexerClass).symbolicNames),
        ("lexer_class.modeNames", cast(Any, LexerClass).modeNames),
        ("parser_class.ruleNames", cast(Any, ParserClass).ruleNames),
    ):
        print(f"{label} = {value!r}")
    # print("inspect.getsource(parser_class.document):")
    # print(inspect.getsource(parser_class.document))
    print()

    lexer = LexerClass(antlr4.InputStream(bnf_source_text))
    parser = ParserClass(antlr4.CommonTokenStream(lexer))
    for recognizer in (lexer, parser):
        recognizer.removeErrorListeners()
        recognizer.addErrorListener(SyntaxErrorListener())

    # Each rule (`definition` in BNFMetaParser.g4) is either a syntaxExpression or a regexExpression
    rules = cast(Any, parser).document().definition()

    for label, value in (
        ("len(rules)", len(rules)),
        ("type(rules[0])", type(rules[0])),
        ("dir(rules[0])", dir(rules[0])),
        ("type(rules[0].syntaxExpression())", type(rules[0].syntaxExpression())),
        ("dir(rules[0].syntaxExpression())", dir(rules[0].syntaxExpression())),
        ("type(rules[-1].regexExpression())", type(rules[-1].regexExpression())),
        ("dir(rules[-1].regexExpression())", dir(rules[-1].regexExpression()))
    ):
        print(f"{label} = {value!r}")
    print()

    # for i, rule in enumerate(rules):
    #     print(i, rule.name.text, rule.separator.text, rule.syntaxExpression(), rule.regexExpression())
    # print()


def parse_syntax_bnf(input_path: Path, metagrammar_path: Path, antlr_jar_path: Path,
                     *, debug: bool = False
                    ) -> tuple[str, type[antlr4.Lexer], list[Definition]]:
    bnf_source_text = input_path.read_text(encoding="utf-8")
    with tempfile.TemporaryDirectory(prefix="bnf2antlr-meta-") as tmpdir:
        tmpdir_path = Path(tmpdir)
        generate_metaparser(metagrammar_path, antlr_jar_path, tmpdir_path)
        LexerClass, ParserClass = import_generated_metaparser(tmpdir_path)
        if debug:
            debug_print_syntax_bnf(LexerClass, ParserClass, bnf_source_text)

        lexer = LexerClass(antlr4.InputStream(bnf_source_text))
        parser = ParserClass(antlr4.CommonTokenStream(lexer))
        for recognizer in (lexer, parser):
            recognizer.removeErrorListeners()
            recognizer.addErrorListener(SyntaxErrorListener())
        rules = parser.document().definition()

        definitions = [
            Definition(rule.name.text[1:-1], rule.separator.text,
                       rule.syntaxExpression() or rule.regexExpression(), rule)
            for rule in rules
        ]

    return bnf_source_text, LexerClass, definitions


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
    def __init__(self,
                 bnf_source_text: str,
                 LexerClass: type[antlr4.Lexer],
                 definitions: list[Definition],
                 bnf_source_file_name: str,
                 metagrammar_name: str,
                 output_grammar_name: str) -> None:
        self.bnf_source_text = bnf_source_text
        self.bnf_source_file_name = bnf_source_file_name
        self.metagrammar_name = metagrammar_name
        self.output_grammar_name = output_grammar_name
        self.syntactic = [d for d in definitions if d.separator == "::="]
        self.semantic  = [d for d in definitions if d.separator == ":=="]
        self.lexical   = [d for d in definitions if d.separator in ("::-", ":::")]
        self.lexical_names = {d.name for d in self.lexical}
        self.token_type_id_bare_word: int = cast(Any, LexerClass).BARE_WORD
        alternatives = [a for d in self.syntactic for a in d.expression.syntaxAlternative()]
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
        if "lower_word" in self.references and "lower_word" in self.lexical_names:
            candidates = {
                element.start.text
                for alternative in alternatives for element in alternative.syntaxElement()
                if element.start.type == self.token_type_id_bare_word
            }
            if candidates:
                pattern = lexical_pattern("lower_word", {d.name: d for d in self.lexical})
                self.lower_word_literals = sorted(
                    word for word in candidates if pattern.fullmatch(word)
                )
            if self.lower_word_literals:
                occupied = {d.name.lower() for d in self.syntactic}
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
                    name = lexer_name(name) if name in self.lexical_names else name.lower()
                parts.append(name + ("*" if element.STAR() else ""))
            elif token.type == self.token_type_id_bare_word:
                flush()
                parts.append(literal(token.text))
            else:
                punctuation += token.text
            previous_stop = element.stop.stop
        flush()
        return " ".join(parts)

    def convert(self) -> str:
        blocks = [
            f"grammar {self.output_grammar_name};\n",
            f"// Generated from {self.bnf_source_file_name} using {self.metagrammar_name}.\n"
            "// ::= rules are parser rules; :== restrictions are comments;\n"
            "// ::- rules are tokens; ::: rules are lexer fragments unless\n"
            "// referenced directly by a parser rule.\n",
        ]
        for index, definition in enumerate(self.syntactic):
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
                text = self.bnf_source_text[context.start.start:context.stop.stop + 1]
                comments.append(f"// line {context.start.line}: {' '.join(text.split())}")
            blocks.append("\n".join(comments) + "\n")

        blocks.append("// Lexer rules derived from ::- and ::: definitions.")
        for definition in self.lexical:
            name = lexer_name(definition.name)
            if definition.separator == ":::" and definition.name not in self.references:
                name = "fragment " + name
            alternatives = regex_alternatives(definition.expression)
            command = "-> channel(HIDDEN)" if definition.name == "comment" else ""
            if command and len(alternatives) > 1:
                alternatives = ["( " + " | ".join(alternatives) + " )"]
            blocks.append(format_rule(name, alternatives, command))

        blocks.append("// SyntaxBNF permits whitespace between tokens.\n"
                      "WS\n    : [ \\t\\r\\n]+ -> skip\n    ;\n")
        return "\n".join(blocks)


def main(argv=None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("input", type=Path, nargs="?",
        help="BNF input file (default: select the SyntaxBNF-v* file in repository root)")
    parser.add_argument("-o", dest="output", type=Path, default=DEFAULT_OUTPUT_DIRECTORY,
        help="output directory or .g4 file (default: BNFMetaGrammar/ANTLRGrammar/converted_by_meta)")
    parser.add_argument("--output-grammar-name", default="TPTP",
        help="output grammar name (default: TPTP)")
    parser.add_argument("--metagrammar", type=Path, default=DEFAULT_METAGRAMMAR)
    parser.add_argument("--antlr-jar", type=Path, default=DEFAULT_ANTLR_JAR)
    parser.add_argument("--debug", action="store_true",
        help="print generated lexer/parser class details")
    args = parser.parse_args(argv)
    if not re.fullmatch(r"[A-Za-z][A-Za-z0-9_]*", args.output_grammar_name):
        parser.error(f"invalid ANTLR grammar name: {args.output_grammar_name!r}")

    try:
        input_path: Path = select_input_file(args.input)
        bnf_source_text, LexerClass, definitions = parse_syntax_bnf(
            input_path, args.metagrammar.resolve(), args.antlr_jar.resolve(),
            debug=args.debug,
        )
        converter = GrammarConverter(
            bnf_source_text, LexerClass, definitions,
            input_path.name, args.metagrammar.name, args.output_grammar_name,
        )
        output_grammar_text: str = converter.convert()
        output_path: Path = args.output
        if output_path.suffix != ".g4":
            output_path /= f"{args.output_grammar_name}.g4"
        output_path.parent.mkdir(parents=True, exist_ok=True)
        output_path.write_text(output_grammar_text, encoding="utf-8")
    except (ConversionError, OSError, subprocess.CalledProcessError) as error:
        print(f"error: {error}", file=sys.stderr)
        return 1

    counts = Counter(d.separator for d in definitions)
    parser_rules = counts['::='] + bool(converter.lower_word_wrapper)
    print(f"Wrote {output_path} ({parser_rules} parser rules, {counts['::-']} tokens, "
          f"{counts[':::']} macros, {counts[':==']} semantic restrictions).")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
