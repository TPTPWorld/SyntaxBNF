"""Check lower-word collisions through conversion and actual TPTP parsing."""

import importlib.util
from pathlib import Path
import subprocess
import tempfile
import unittest

from antlr4 import CommonTokenStream, InputStream
from antlr4.atn.PredictionMode import PredictionMode
from antlr4.error.ErrorListener import ErrorListener

from BNFMetaGrammar.BNF2ANTLR import bnf2antlr_meta as converter


class Diagnostics(ErrorListener):
    def __init__(self):
        self.errors = []
        self.ambiguities = []

    def syntaxError(self, recognizer, symbol, line, column, message, error):
        self.errors.append(message)

    def reportAmbiguity(self, recognizer, dfa, start, stop, exact, alts, configs):
        self.ambiguities.append((start, stop))


class LowerWordTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.temporary = tempfile.TemporaryDirectory(prefix="bnf-lower-words-test-")
        cls.addClassCleanup(cls.temporary.cleanup)
        directory = Path(cls.temporary.name)
        definitions, source, lexer = converter.parse_syntax_bnf(
            converter.REPOSITORY_ROOT / "SyntaxBNF-v9.3.1.6",
            converter.DEFAULT_METAGRAMMAR, converter.DEFAULT_ANTLR_JAR,
        )
        cls.conversion = converter.GrammarConverter(
            definitions, source, lexer, "LowerWords", "SyntaxBNF-v9.3.1.6",
            converter.DEFAULT_METAGRAMMAR.name,
        )
        cls.grammar = cls.conversion.convert()
        path = directory / "LowerWords.g4"
        path.write_text(cls.grammar)
        subprocess.run(
            ["java", "-jar", str(converter.DEFAULT_ANTLR_JAR),
             "-Dlanguage=Python3", "-no-listener", str(path)], check=True,
        )
        for name in ("LowerWordsLexer", "LowerWordsParser"):
            spec = importlib.util.spec_from_file_location(name, directory / f"{name}.py")
            module = importlib.util.module_from_spec(spec)
            spec.loader.exec_module(module)
            setattr(cls, name, getattr(module, name))

    def parse(self, source, accepted=True):
        diagnostics = Diagnostics()
        lexer = self.LowerWordsLexer(InputStream(source))
        tokens = CommonTokenStream(lexer)
        parser = self.LowerWordsParser(tokens)
        parser._interp.predictionMode = PredictionMode.LL_EXACT_AMBIG_DETECTION
        for recognizer in (lexer, parser):
            recognizer.removeErrorListeners()
            recognizer.addErrorListener(diagnostics)
        tree = parser.tptp_file()
        if accepted:
            self.assertEqual(diagnostics.errors, [], source)
            self.assertEqual(diagnostics.ambiguities, [], source)
        else:
            self.assertTrue(diagnostics.errors, source)
        return tree, tokens

    def test_four_file_uses_have_correct_parse_trees(self):
        for formula, kind in (
            ("fof(a,axiom,p(file)).", "constant"),
            ("fof(a,axiom,p(file(z))).", "functor"),
            ("fof(a,axiom,p,file).", "name"),
            ("fof(a,axiom,p,file('y.p',x)).", "source"),
        ):
            with self.subTest(kind=kind):
                tree, _ = self.parse(formula)
                annotated = tree.tptp_input(0).annotated_formula().fof_annotated()
                if kind in ("constant", "functor"):
                    plain = (annotated.fof_formula().fof_logic_formula()
                             .fof_unitary_formula().fof_atomic_formula()
                             .fof_plain_atomic_formula().fof_plain_term())
                    argument = (plain.fof_arguments().fof_term().fof_function_term()
                                .fof_plain_term())
                    if kind == "constant":
                        self.assertEqual(argument.constant().getText(), "file")
                        self.assertIsNone(argument.functor())
                    else:
                        self.assertEqual(argument.functor().getText(), "file")
                        self.assertEqual(argument.fof_arguments().getText(), "z")
                else:
                    source = annotated.annotations().source()
                    if kind == "name":
                        self.assertEqual(source.dag_source().name().getText(), "file")
                        self.assertIsNone(source.external_source())
                    else:
                        record = source.external_source().file_source()
                        self.assertEqual(record.file_name().getText(), "'y.p'")
                        self.assertEqual(record.file_info().name().getText(), "x")

    def test_all_ten_literals_in_word_positions(self):
        words = ["cnf", "file", "fof", "include", "inference", "introduced",
                 "tcf", "tff", "thf", "tpi"]
        self.assertEqual(self.conversion.lower_word_literals, words)
        for word in words:
            with self.subTest(word=word):
                _, tokens = self.parse(
                    f"fof({word},axiom,p({word},{word}(z)),{word},[{word},{word}(z)])."
                )
                self.assertTrue(all(token.type != self.LowerWordsLexer.Lower_word
                                    for token in tokens.tokens if token.text == word))

    def test_original_formula_and_whitespace(self):
        self.parse("fof(kb_SUMO_52578,axiom,"
                   "s__lexicon(s__ComputerFile,s__LexNoun,file)).")
        self.parse("fof(a,axiom,p(file (z))).")
        self.parse("fof(a,axiom,p,file ('y.p',x)).")

    def test_direct_lower_word_reference_in_formula_role(self):
        # The ::= category admits this spelling; role semantics remain in :==.
        tree, _ = self.parse("fof(a,file,p).")
        role = tree.tptp_input(0).annotated_formula().fof_annotated().formula_role()
        self.assertEqual(role.lower_word_token().getText(), "file")

    def test_special_forms_still_require_their_keywords(self):
        self.parse("fof(a,axiom,p,inference(resolution,[],[file])).")
        self.parse("fof(a,axiom,p,introduced(definition,[],[file])).")
        self.parse("include('y.p',[file,fof,inference]).")
        self.parse("fof(a,axiom,p,other('y.p',x)).", accepted=False)

    def test_dollar_words_are_not_wrapped(self):
        self.assertIn("atomic_defined_word\n    : Dollar_word\n", self.grammar)
        self.assertNotIn("dollar_word_token", self.grammar)
        self.parse("fof(a,axiom,p,file('y.p',x),[$fof(q)]).")
        self.parse("tff(a,axiom,$let(p:$o,p:=$true,p)).")
        for formula in ("fof(a,axiom,p($fof)).", "fof(a,axiom,p($fof(z))).",
                        "tff(a,axiom,$let(a,b,c))."):
            with self.subTest(formula=formula):
                self.parse(formula, accepted=False)

    def convert(self, source):
        with tempfile.TemporaryDirectory(prefix="bnf-lower-category-test-") as tmp:
            path = Path(tmp) / "sample.bnf"
            path.write_text(source)
            definitions, text, lexer = converter.parse_syntax_bnf(
                path, converter.DEFAULT_METAGRAMMAR, converter.DEFAULT_ANTLR_JAR,
            )
            conversion = converter.GrammarConverter(
                definitions, text, lexer, "Sample", path.name,
                converter.DEFAULT_METAGRAMMAR.name,
            )
            return conversion, conversion.convert()

    def test_literals_follow_lexical_macros_and_ignore_semantic_rules(self):
        conversion, grammar = self.convert(
            "<TPTP_file> ::= <lower_word>*\n"
            "<marker> ::= file | frog | data | $fof\n"
            "<marker> :== fake\n"
            "<lower_word> ::- <initial><rest>*\n"
            "<initial> ::: [\\146]\n"
            "<rest> ::: ([a-z]|[0-9_])\n"
        )
        self.assertEqual(conversion.lower_word_literals, ["file", "frog"])
        self.assertIn("lower_word_token* EOF", grammar)

    def test_wrapper_name_avoids_existing_parser_rules(self):
        conversion, grammar = self.convert(
            "<entry> ::= <lower_word>\n"
            "<lower_word_token> ::= file\n"
            "<lower_word_token_2> ::= second\n"
            "<lower_word> ::- [a-z]+\n"
        )
        self.assertEqual(conversion.lower_word_wrapper, "lower_word_token_3")
        self.assertIn("entry\n    : lower_word_token_3\n", grammar)

    def test_no_wrapper_without_lower_word_literal_overlaps(self):
        conversion, grammar = self.convert(
            "<entry> ::= <lower_word>\n"
            "<marker> ::= $fof\n"
            "<lower_word> ::- [a-z]+\n"
        )
        self.assertIsNone(conversion.lower_word_wrapper)
        self.assertIn("entry\n    : Lower_word\n", grammar)


if __name__ == "__main__":
    unittest.main()
