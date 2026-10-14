"""Exercise SyntaxBNF charsets through conversion and the generated ANTLR lexer."""

import importlib.util
from pathlib import Path
import subprocess
import tempfile
import unittest

import antlr4
from antlr4.atn.PredictionMode import PredictionMode
from antlr4.error.ErrorListener import ErrorListener

from BNFMetaGrammar.BNF2ANTLR import bnf2antlr_meta as converter


class CharsetTests(unittest.TestCase):
    def convert(self, source, directory, name):
        input_path = directory / f"{name}.bnf"
        input_path.write_text(source, encoding="utf-8")
        definitions, text, lexer = converter.parse_syntax_bnf(
            input_path, converter.DEFAULT_METAGRAMMAR, converter.DEFAULT_ANTLR_JAR
        )
        grammar = converter.GrammarConverter(
            definitions, text, lexer, name, input_path.name,
            converter.DEFAULT_METAGRAMMAR.name,
        ).convert()
        return definitions, grammar

    def lexer_class(self, grammar, directory, name):
        path = directory / f"{name}.g4"
        path.write_text(grammar, encoding="utf-8")
        result = subprocess.run(
            ["java", "-jar", str(converter.DEFAULT_ANTLR_JAR),
             "-Dlanguage=Python3", "-no-listener", str(path)],
            capture_output=True, text=True,
        )
        self.assertEqual(result.returncode, 0, result.stderr)
        spec = importlib.util.spec_from_file_location(
            f"{name}Lexer", directory / f"{name}Lexer.py"
        )
        if spec is None or spec.loader is None:
            raise ImportError(f"Cannot load generated lexer {name}Lexer")
        module = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(module)
        return getattr(module, f"{name}Lexer")

    def test_character_membership(self):
        # Test actual lexer behavior, including the boundaries of octal ranges.
        cases = [
            (r"[\40-\46]", set(map(chr, range(0o40, 0o46 + 1)))),
            (r"[A-Za-z]", set("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz")),
            (r"[\123-X]", set("STUVWX")),
            (r"[S-\130]", set("STUVWX")),
            (r"[^/*]", set(map(chr, range(128))) - set("/*")),
            (r"[\\]", {"\\"}),
            (r"[.\n]", {".", "\n"}),
            (r"[\r]", {"\r"}),
            (r"[^\r\n]", set(map(chr, range(128))) - {"\r", "\n"}),
            (r"[+-]", {"+", "-"}),
            (r"[\1\11\12\1234]", {chr(1), "\t", chr(0o12), chr(0o1234)}),
            (r"[\000\777\78]", {chr(0), chr(0o777), chr(7), "8"}),
            (r"[\000000123]", {"S"}),
            (r"[\200000-\200002\4177777]", {chr(0x10000), chr(0x10001), chr(0x10002), chr(0x10FFFF)}),
            (r"[\q\8\x]", set("\\q8x")),
            (r"[\135\55\136]", {"]", "-", "^"}),
            (r"[a^]", {"a", "^"}),
            (r"[\^]", {"\\", "^"}),
            (r"[^^]", set(map(chr, range(128))) - {"^"}),
            (r"[^a]", set(map(chr, range(128))) - {"a"}),
            (r"[ ^~]", {" ", "^", "~"}),
            (r"[-]", {"-"}),
            (r"[^-]", set(map(chr, range(128))) - {"-"}),
            (r"[-a]", {"-", "a"}),
            (r"[a-]", {"a", "-"}),
            (r"[-a-]", {"-", "a"}),
            (r"[--]", {"-"}),
        ]
        with tempfile.TemporaryDirectory(prefix="bnf-charsets-test-") as tmp:
            directory = Path(tmp)
            for index, (charset, expected) in enumerate(cases):
                with self.subTest(charset=charset):
                    name = f"Charset{index}"
                    _, grammar = self.convert(
                        f"<entry> ::= <sample>\n<sample> ::- {charset}\n",
                        directory, name,
                    )
                    lexer_class = self.lexer_class(grammar, directory, name)
                    for code in sorted(set(range(128)) | {ord(c) for c in expected}):
                        character = chr(code)
                        lexer = lexer_class(antlr4.InputStream(character))
                        lexer.removeErrorListeners()
                        tokens = lexer.getAllTokens()
                        accepted = bool(tokens) and tokens[0].type == lexer_class.Sample
                        self.assertEqual(accepted, character in expected, repr(character))

    def test_modes_and_continuations(self):
        source = (
            "% Example <ignored> ::: [\\]\n"
            "<entry> ::= tpi([<sample>],\\n) |\n"
            "    <sample>\n"
            "<entry> :== []\n"
            "<sample> ::- ([A-Z]|\n"
            "    [\\123-X])\n"
            "<percentage> ::: [%]\n"
        )
        with tempfile.TemporaryDirectory(prefix="bnf-modes-test-") as tmp:
            definitions, grammar = self.convert(source, Path(tmp), "Modes")
            self.assertEqual([item.name for item in definitions],
                             ["entry", "entry", "sample", "percentage"])
            self.assertIn("'tpi' '(' '[' Sample ']' ',' '\\\\' 'n' ')'", grammar)
            self.assertIn(r"[\u0053-X]", grammar)
            self.assertIn("[%]", grammar)

    def test_empty_charsets_rejected_by_parser(self):
        with tempfile.TemporaryDirectory(prefix="bnf-empty-set-test-") as tmp:
            input_path = Path(tmp) / "empty.bnf"
            for charset in ("[]", "[^]"):
                with self.subTest(charset=charset):
                    input_path.write_text(f"<sample> ::: {charset}\n")
                    # Check parsing itself, before converter validation can run.
                    with self.assertRaises(converter.ConversionError):
                        converter.parse_syntax_bnf(
                            input_path, converter.DEFAULT_METAGRAMMAR,
                            converter.DEFAULT_ANTLR_JAR,
                        )

    def test_document_boundaries(self):
        source = (
            "% Header with an example: <ignored> ::: [x]\n\n"
            "<entry> ::= <sample>* | ?* | [] |\n"
            "    (<sample>)\n"
            "<entry> :== []\n"
            "<sample> ::- <letter>+\n"
            "<letter> ::: [A-Z]\n"
            "<nothing> ::="
        )
        with tempfile.TemporaryDirectory(prefix="bnf-boundaries-test-") as tmp:
            for newline in ("\n", "\r\n"):
                for suffix in ("", "\n", "\n% Final comment"):
                    with self.subTest(newline=newline, suffix=suffix):
                        definitions, grammar = self.convert(
                            (source + suffix).replace("\n", newline),
                            Path(tmp), "Boundaries",
                        )
                        self.assertEqual(
                            [(item.name, item.operator) for item in definitions],
                            [("entry", "::="), ("entry", ":=="),
                             ("sample", "::-"), ("letter", ":::"),
                             ("nothing", "::=")],
                        )
                        self.assertIn("Sample*", grammar)
                        self.assertIn("'?*'", grammar)
                        self.assertIn("'[' ']'", grammar)
                        self.assertIn("'(' Sample ')'", grammar)
                        self.assertEqual(definitions[-1].expression.getText(), "")

    def test_charset_escapes_are_single_tokens(self):
        with tempfile.TemporaryDirectory(prefix="bnf-escape-token-test-") as tmp:
            directory = Path(tmp)
            converter.generate_metaparser(
                converter.DEFAULT_METAGRAMMAR, converter.DEFAULT_ANTLR_JAR, directory,
            )
            lexer_class, _ = converter.import_generated_metaparser(directory)
            cases = [
                (r"\1\12\1234\78", [
                    ("OCTAL_ESCAPE", r"\1"), ("OCTAL_ESCAPE", r"\12"),
                    ("OCTAL_ESCAPE", r"\1234"),
                    ("OCTAL_ESCAPE", r"\7"), ("CHARSET_CHAR", "8"),
                ]),
                (r"\000000123", [("OCTAL_ESCAPE", r"\000000123")]),
                (r"\\\n\r", [
                    ("QUOTED_ESCAPE", escape)
                    for escape in (r"\\", r"\n", r"\r")
                ]),
                (r"\]", [("CHARSET_CHAR", "\\"), ("RBRACKET", "]")]),
                (r"\-", [("CHARSET_CHAR", "\\"), ("DASH", "-")]),
                (r"\^", [("CHARSET_CHAR", "\\"), ("CHARSET_CHAR", "^")]),
                (r"\q\8\x", [("CHARSET_CHAR", char) for char in r"\q\8\x"]),
                ("\\", [("CHARSET_CHAR", "\\")]),
            ]
            for content, expected in cases:
                with self.subTest(content=content):
                    # EOF immediately after the content also exercises dangling escapes.
                    lexer = lexer_class(antlr4.InputStream("<sample> ::: [" + content))
                    tokens = lexer.getAllTokens()[3:]
                    self.assertEqual(
                        [(lexer.symbolicNames[token.type], token.text) for token in tokens],
                        expected,
                    )

    def test_charsets_are_unambiguous(self):
        class Diagnostics(ErrorListener):
            def __init__(self):
                self.errors = []
                self.ambiguities = []

            def syntaxError(self, recognizer, symbol, line, column, message, error):
                self.errors.append(message)

            def reportAmbiguity(self, recognizer, dfa, start, stop, exact, alts, configs):
                self.ambiguities.append((start, stop))

        with tempfile.TemporaryDirectory(prefix="bnf-set-ambiguity-test-") as tmp:
            directory = Path(tmp)
            converter.generate_metaparser(
                converter.DEFAULT_METAGRAMMAR, converter.DEFAULT_ANTLR_JAR, directory,
            )
            lexer_class, parser_class = converter.import_generated_metaparser(directory)
            for charset in (
                "[^a]", "[^^]", "[a^]", "[-]", "[^-]", "[-a-]", "[--]",
                r"[\1\12\1234]", r"[\40-\46]", r"[\123-X]", r"[\135\55\136\\\n]",
            ):
                with self.subTest(charset=charset):
                    diagnostics = Diagnostics()
                    lexer = lexer_class(antlr4.InputStream(f"<sample> ::: {charset}\n"))
                    lexer.removeErrorListeners()
                    lexer.addErrorListener(diagnostics)
                    parser = parser_class(antlr4.CommonTokenStream(lexer))
                    parser.removeErrorListeners()
                    parser.addErrorListener(diagnostics)
                    parser._interp.predictionMode = PredictionMode.LL_EXACT_AMBIG_DETECTION
                    parser.document()
                    self.assertEqual(diagnostics.errors, [])
                    self.assertEqual(diagnostics.ambiguities, [])

    def test_invalid_charsets(self):
        for charset in (
            "[]", "[^]", "[Z-A]", r"[X-\123]", r"[\4200000]",
            "[abc", "[\\", "[\\\n]", "[\\\r\n]",
            "[a\n]", "[a\r]", "[a\t]", "[a\x00]", "[a\x7f]", "[aé]",
        ):
            with self.subTest(charset=charset):
                with tempfile.TemporaryDirectory(prefix="bnf-invalid-test-") as tmp:
                    with self.assertRaises(converter.ConversionError):
                        self.convert(f"<sample> ::: {charset}\n", Path(tmp), "Invalid")

    def test_full_syntax_bnf(self):
        # Select the corpus explicitly; the root may also contain an HTML export.
        source = converter.select_input_file(
            converter.REPOSITORY_ROOT / "SyntaxBNF-v9.3.1.6"
        ).read_text()
        with tempfile.TemporaryDirectory(prefix="bnf-corpus-test-") as tmp:
            directory = Path(tmp)
            definitions, grammar = self.convert(source, directory, "Corpus")
            self.assertGreater(len(definitions), 300)
            lexer_class = self.lexer_class(grammar, directory, "Corpus")
            self.assertIn("~[/*]", grammar)
            self.assertIn("'tpi' '(' name", grammar)
            self.assertIn(r"~[\r\n]", grammar)
            spec = importlib.util.spec_from_file_location(
                "CorpusParser", directory / "CorpusParser.py",
            )
            module = importlib.util.module_from_spec(spec)
            spec.loader.exec_module(module)
            # A line comment must consume letters and backslashes, and stop at
            # either newline character without swallowing the following record.
            for ending in ("\n", "\r\n", "\r"):
                for comment in ("ordinary remark", r"back\slash", ""):
                    with self.subTest(ending=ending, comment=comment):
                        lexer = lexer_class(antlr4.InputStream(
                            f"% {comment}{ending}fof(a,axiom,p)."
                        ))
                        parser = module.CorpusParser(antlr4.CommonTokenStream(lexer))
                        for recognizer in (lexer, parser):
                            recognizer.removeErrorListeners()
                            recognizer.addErrorListener(converter.SyntaxErrors())
                        tree = parser.tptp_file()
                        self.assertEqual(len(tree.tptp_input()), 1)

    def test_generated_parser(self):
        source = (
            "<TPTP_file> ::= <item>*\n"
            "<item> ::= tpi(<word>)<connective><word>. | <vline><word>.\n"
            "<connective> ::= => | <=> | ?*\n"
            "<item> :== restricted\n"
            "<word> ::- <lower>+\n"
            "<lower> ::: [a-z]\n"
            "<vline> ::: [|]\n"
            "<comment> ::- [%]<lower>* | [#]<lower>*\n"
        )
        with tempfile.TemporaryDirectory(prefix="bnf-parser-test-") as tmp:
            directory = Path(tmp)
            _, grammar = self.convert(source, directory, "Converted")
            lexer_class = self.lexer_class(grammar, directory, "Converted")
            spec = importlib.util.spec_from_file_location(
                "ConvertedParser", directory / "ConvertedParser.py",
            )
            module = importlib.util.module_from_spec(spec)
            spec.loader.exec_module(module)

            def parse(text):
                lexer = lexer_class(antlr4.InputStream(text))
                parser = module.ConvertedParser(antlr4.CommonTokenStream(lexer))
                for recognizer in (lexer, parser):
                    recognizer.removeErrorListeners()
                    recognizer.addErrorListener(converter.SyntaxErrors())
                return parser.tptp_file()

            # Exercises operator grouping, exported macros, fragments, comments,
            # semantic restrictions, repetition, and the entry rule's EOF.
            tree = parse("tpi(a)=>b. %hello\n|c. #world\ntpi(d)<=>e. tpi(f)?*g.")
            self.assertEqual(len(tree.item()), 4)
            with self.assertRaises(converter.ConversionError):
                parse("|a. extra")


if __name__ == "__main__":
    unittest.main()
