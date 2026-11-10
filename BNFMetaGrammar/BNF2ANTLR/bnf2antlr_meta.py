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
    parserExpression or lexerExpression (see `definition` in BNFMetaParser.g4).
    The runtime type will be ParserExpressionContext or LexerExpressionContext."""

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

    # Each rule (`definition` in BNFMetaParser.g4) is either a parserExpression or a lexerExpression
    rules = cast(Any, parser).document().definition()

    for label, value in (
        ("len(rules)", len(rules)),
        ("type(rules[0])", type(rules[0])),
        ("type(rules[0]).__mro__", type(rules[0]).__mro__),
        ("dir(rules[0])", dir(rules[0])),
        ("type(rules[0].parserExpression())", type(rules[0].parserExpression())),
        ("dir(rules[0].parserExpression())", dir(rules[0].parserExpression())),
        ("type(rules[-1].lexerExpression())", type(rules[-1].lexerExpression())),
        ("dir(rules[-1].lexerExpression())", dir(rules[-1].lexerExpression()))
    ):
        print(f"{label} = {value!r}")
    print()

    # for i, rule in enumerate(rules):
    #     print(i, rule.name.text, rule.separator.text, rule.parserExpression(), rule.lexerExpression())
    # print()


def parse_syntax_bnf(input_path: Path, metagrammar_path: Path, antlr_jar_path: Path,
                     *, debug: bool = False
                    ) -> tuple[str, type[antlr4.Lexer], list[Definition]]:
    bnf_source_text = input_path.read_text(encoding="utf-8")
    with tempfile.TemporaryDirectory(prefix="bnf2antlr-meta-") as tmpdir:
        tmpdir_path = Path(tmpdir)
        generate_metaparser(metagrammar_path, antlr_jar_path, tmpdir_path)
        LexerClass, ParserClass = import_generated_metaparser(tmpdir_path)

        lexer = LexerClass(antlr4.InputStream(bnf_source_text))
        parser = ParserClass(antlr4.CommonTokenStream(lexer))
        for recognizer in (lexer, parser):
            recognizer.removeErrorListeners()
            recognizer.addErrorListener(SyntaxErrorListener())
        rules = parser.document().definition()
        if not rules:
            raise ConversionError(f"BNF input contains no definitions: {input_path}")
        if debug:
            debug_print_syntax_bnf(LexerClass, ParserClass, bnf_source_text)

        definitions = [
            Definition(rule.name.text[1:-1], rule.separator.text,
                       rule.parserExpression() or rule.lexerExpression(), rule)
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
    for i, alt in enumerate(alternatives):
        separator = ":" if i == 0 else "|"
        lines.append(f"    {separator} {alt}".rstrip())
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
    """Convert a `BNFMetaParser.CharSetContext`
    (subclass of `antlr4.ParserRuleContext`) instance to ANTLR text."""
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

def lexer_element(element) -> str:
    primary = element.lexerPrimary()
    if primary.NONTERMINAL():
        text = lexer_name(primary.getText()[1:-1])
    elif primary.lexerExpression():
        text = "( " + " | ".join(lexer_alternatives(primary.lexerExpression())) + " )"
    else:
        text = charset(primary.charSet())
    quantifier = element.lexerQuantifier()
    return text + (quantifier.getText() if quantifier else "")

def lexer_alternatives(expression, *, unwrap_groups: bool = True) -> list[str]:
    """Convert a parsed `lexerExpression` into a list of ANTLR alternatives.

    When unwrap_groups is True, recursively flatten a parenthesized group
    into the result if it occupies an entire alternative and has no
    quantifier. For example, ((A | B) | (C | D)) becomes four alternatives, A, B, C, and D.
    Groups such as (A | B)+ and (A | B) C retain their parentheses."""
    ans: list[str] = []
    for alt in expression.lexerAlternative():
        elements = alt.lexerElement()
        if unwrap_groups and len(elements) == 1 and not elements[0].lexerQuantifier():
            group = elements[0].lexerPrimary().lexerExpression()
            if group is not None:
                ans.extend(lexer_alternatives(group))
                continue
        ans.append(" ".join(lexer_element(elem) for elem in elements))
    return ans

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

        syntactic_alternatives = [a for d in self.syntactic for a in d.expression.parserAlternative()]

        # Collect nonterminal names referenced directly by syntactic rules (::=).
        # A ::: rule referenced directly by a ::= rule becomes a token-producing lexer rule;
        # otherwise, it becomes an ANTLR fragment.
        self.references_by_syntactic: set[str] = {
            element.NONTERMINAL().getText()[1:-1]
            for a in syntactic_alternatives for element in a.parserElement()
            if element.NONTERMINAL()
        }
        
        # All-punctuation alternatives define operators such as => and ?*
        operators_set: set[str] = {a.getText() for a in syntactic_alternatives
            if a.getText() and set(a.getText()) <= OPERATOR_CHARACTERS}
        self.operators: list[str] = sorted(operators_set, key=lambda text: (-len(text), text))
        self.operators_pattern = re.compile("|".join(
            [re.escape(op) for op in self.operators] +
            ["."]  # single-character fallback such as parentheses and commas
        ))

        # Allow keywords as ordinary symbols (see README.md)
        self.lower_word_literals: list[str] = []
        self.lower_word_wrapper_name: str|None = None
        if "lower_word" in self.references_by_syntactic and "lower_word" in self.lexical_names:
            candidates: set[str] = {
                elem.start.text
                for alt in syntactic_alternatives for elem in alt.parserElement()
                if elem.start.type == self.token_type_id_bare_word
            }
            self.lower_word_literals = sorted(
                word for word in candidates
                # Assume the definition of <lower_word> when classifying literals.
                if re.fullmatch(r"[a-z][A-Za-z0-9_]*", word)
            )
            if self.lower_word_literals:
                occupied: set[str] = {d.name.lower() for d in self.syntactic}
                self.lower_word_wrapper_name = "lower_word_token"
                suffix = 2
                while self.lower_word_wrapper_name in occupied:
                    self.lower_word_wrapper_name = f"lower_word_token_{suffix}"
                    suffix += 1

    def parser_alternative(self, alternative: antlr4.ParserRuleContext) -> str:
        """Convert one branch of a SyntaxBNF parser rule (::= or :==) into ANTLR text.
        Adjacent punctuation chars from the input are grouped together, so => becomes '=>'. """
        ans: list[str] = []
        punct_buf: str = ""  # buffers adjacent punctuation chars
        prev_stop: int = -1  # position of preceding element's last char

        def flush():
            nonlocal punct_buf
            ans.extend(literal(p) for p in self.operators_pattern.findall(punct_buf))
            punct_buf = ""

        for element in cast(Any, alternative).parserElement():
            token: antlr4.Token = element.start
            if token.start != prev_stop + 1:
                flush()
            if element.NONTERMINAL():
                flush()
                name: str = token.text[1:-1]  # remove the <...> delimiter
                if name == "lower_word" and self.lower_word_wrapper_name:
                    name = self.lower_word_wrapper_name
                else:
                    name = lexer_name(name) if name in self.lexical_names else name.lower()
                ans.append(name + ("*" if element.STAR() else ""))
            elif token.type == self.token_type_id_bare_word:
                flush()
                ans.append(literal(token.text))
            else:
                punct_buf += token.text
            prev_stop = element.stop.stop
        flush()
        return " ".join(ans)

    def print_debug_info(self):
        print(f"operators = {self.operators}")
        print(f"operators_pattern = {self.operators_pattern}")
        print()

    def convert(self, *, debug: bool = False) -> str:
        if debug:
            self.print_debug_info()

        blocks = [
            f"grammar {self.output_grammar_name};\n"
            "\n"
            f"// Generated from {self.bnf_source_file_name} using {self.metagrammar_name}.\n"
            "// ::= rules become parser rules; :== restrictions become comments;\n"
            "// ::- rules become tokens; ::: rules become lexer fragments unless\n"
            "// referenced directly by a parser rule.\n"
        ]

        for i, definition in enumerate(self.syntactic):
            alternatives = [self.parser_alternative(a)
                            for a in definition.expression.parserAlternative()]
            if i == 0 and definition.name == "TPTP_file":
                # need EOF to make the entire TPTP input parsed with the generated grammar
                alternatives = [(a + " EOF").strip() for a in alternatives]
            blocks.append(format_rule(definition.name.lower(), alternatives))

        if self.lower_word_wrapper_name:
            blocks.append(
                "// Preserve Lower_word spellings shadowed by implicit literal tokens.\n" +
                format_rule(self.lower_word_wrapper_name,
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
                text = self.bnf_source_text[context.start.start : context.stop.stop + 1]
                comments.append(f"// line {context.start.line}: {' '.join(text.split())}")
            blocks.append("\n".join(comments) + "\n")

        blocks.append("// Lexer rules derived from ::- and ::: definitions.")
        for definition in self.lexical:
            name = lexer_name(definition.name)
            if definition.separator == ":::" and definition.name not in self.references_by_syntactic:
                name = "fragment " + name
            # Comments in TPTP input are diverted to ANTLR's HIDDEN channel
            command = "-> channel(HIDDEN)" if definition.name == "comment" else ""
            alternatives = lexer_alternatives(definition.expression)
            if command and len(alternatives) > 1:
                alternatives = ["( " + " | ".join(alternatives) + " )"]
            blocks.append(format_rule(name, alternatives, command))

        blocks.append("// SyntaxBNF permits whitespace between tokens.\n"
                      "WS\n    : [ \\t\\r\\n]+ -> skip\n    ;\n")
        return "\n".join(blocks)


def main(argv=None) -> int:
    arg_parser = argparse.ArgumentParser(description=__doc__)
    arg_parser.add_argument("input", type=Path, nargs="?",
        help="BNF input file (default: select the SyntaxBNF-v* file in repository root)")
    arg_parser.add_argument("-o", dest="output", type=Path, default=DEFAULT_OUTPUT_DIRECTORY,
        help="output directory or .g4 file (default: BNFMetaGrammar/ANTLRGrammar/converted_by_meta)")
    arg_parser.add_argument("--output-grammar-name", default="TPTP",
        help="output grammar name (default: TPTP)")
    arg_parser.add_argument("--metagrammar", type=Path, default=DEFAULT_METAGRAMMAR)
    arg_parser.add_argument("--antlr-jar", type=Path, default=DEFAULT_ANTLR_JAR)
    arg_parser.add_argument("--debug", action="store_true",
        help="print generated lexer/parser class details")
    args = arg_parser.parse_args(argv)
    if not re.fullmatch(r"[A-Za-z][A-Za-z0-9_]*", args.output_grammar_name):
        arg_parser.error(f"invalid ANTLR grammar name: {args.output_grammar_name!r}")

    try:
        output_path: Path = args.output
        if output_path.suffix == ".g4":
            if output_path.stem != args.output_grammar_name: # ANTLR would reject this
                raise ConversionError(
                    f"Output file name {output_path.name!r} does not match grammar name "
                    f"{args.output_grammar_name!r}; expected {args.output_grammar_name + '.g4'!r}."
                )
        else:
            output_path /= f"{args.output_grammar_name}.g4"

        input_path: Path = select_input_file(args.input)
        bnf_source_text, LexerClass, definitions = parse_syntax_bnf(
            input_path, args.metagrammar.resolve(), args.antlr_jar.resolve(),
            debug=args.debug
        )
        converter = GrammarConverter(
            bnf_source_text, LexerClass, definitions,
            input_path.name, args.metagrammar.name, args.output_grammar_name,
        )
        output_grammar_text: str = converter.convert(debug=args.debug)

        output_path.parent.mkdir(parents=True, exist_ok=True)
        output_path.write_text(output_grammar_text, encoding="utf-8")
    except (ConversionError, OSError, subprocess.CalledProcessError) as error:
        print(f"error: {error}", file=sys.stderr)
        return 1

    counts = Counter(d.separator for d in definitions)
    parser_rules = counts['::='] + bool(converter.lower_word_wrapper_name)
    print(f"Wrote {output_path} ({parser_rules} parser rules, {counts['::-']} tokens, "
          f"{counts[':::']} macros, {counts[':==']} semantic restrictions).")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
