"""Check BNF selection and optional converter CLI paths."""

from contextlib import redirect_stderr, redirect_stdout
from io import StringIO
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch

from BNFMetaGrammar.BNF2ANTLR import bnf2antlr_meta as converter


class InputSelectionTests(unittest.TestCase):
    def setUp(self):
        temporary = tempfile.TemporaryDirectory(prefix="bnf-input-test-")
        self.addCleanup(temporary.cleanup)
        self.root = Path(temporary.name)

    def file(self, name, literal="sample"):
        path = self.root / name
        path.write_text(f"<TPTP_file> ::= {literal}\n", encoding="utf-8")
        return path

    def test_explicit_file_overrides_discovery(self):
        self.file("SyntaxBNF-va")
        self.file("SyntaxBNF-vb")
        explicit = self.file("custom.bnf")
        with patch.object(converter, "REPOSITORY_ROOT", self.root), \
                patch("builtins.input", side_effect=AssertionError("unexpected prompt")):
            self.assertEqual(converter.select_input_file(explicit), explicit)

    def test_invalid_explicit_file_does_not_fall_back(self):
        self.file("SyntaxBNF-vonly")
        for path in (self.root / "missing.bnf", self.root):
            with self.subTest(path=path), patch.object(converter, "REPOSITORY_ROOT", self.root):
                with self.assertRaisesRegex(converter.ConversionError, "not a file"):
                    converter.select_input_file(path)

    def test_single_file_uses_prefix_without_version_requirement(self):
        expected = self.file("SyntaxBNF-vcustom.txt")
        self.file("unrelated.bnf")
        (self.root / "SyntaxBNF-vdirectory").mkdir()
        with patch.object(converter, "REPOSITORY_ROOT", self.root), \
                patch("builtins.input", side_effect=AssertionError("unexpected prompt")):
            self.assertEqual(converter.select_input_file(), expected)

    def test_no_root_file_rejects_nested_matches(self):
        nested = self.root / "nested"
        nested.mkdir()
        (nested / "SyntaxBNF-vhidden").write_text("", encoding="utf-8")
        (self.root / "SyntaxBNF-vdirectory").mkdir()
        with patch.object(converter, "REPOSITORY_ROOT", self.root):
            with self.assertRaisesRegex(converter.ConversionError, "No files beginning"):
                converter.select_input_file()

    def test_multiple_files_require_explicit_input(self):
        self.file("SyntaxBNF-vb")
        self.file("SyntaxBNF-va")
        with patch.object(converter, "REPOSITORY_ROOT", self.root), \
                patch("builtins.input", side_effect=AssertionError("unexpected prompt")):
            with self.assertRaisesRegex(
                    converter.ConversionError,
                    "Multiple SyntaxBNF files found.*specify the input file explicitly"):
                converter.select_input_file()

    def test_cli_no_paths_uses_default_input_and_output(self):
        self.file("SyntaxBNF-vonly", "automatic")
        output = self.root / "generated"
        with patch.object(converter, "REPOSITORY_ROOT", self.root), \
                patch.object(converter, "DEFAULT_OUTPUT_DIRECTORY", output), \
                redirect_stdout(StringIO()):
            result = converter.main(["--output-grammar-name", "Chosen"])
        self.assertEqual(result, 0)
        grammar = (output / "Chosen.g4").read_text()
        self.assertIn("grammar Chosen;", grammar)
        self.assertIn("Generated from SyntaxBNF-vonly", grammar)
        self.assertIn("'automatic' EOF", grammar)

    def test_cli_single_path_is_input_with_default_output(self):
        self.file("SyntaxBNF-va")
        self.file("SyntaxBNF-vb")
        explicit = self.file("custom.bnf", "explicit")
        output = self.root / "generated"
        with patch.object(converter, "REPOSITORY_ROOT", self.root), \
                patch.object(converter, "DEFAULT_OUTPUT_DIRECTORY", output), \
                redirect_stdout(StringIO()):
            result = converter.main([str(explicit)])
        self.assertEqual(result, 0)
        grammar = (output / "TPTP.g4").read_text()
        self.assertIn("Generated from custom.bnf", grammar)
        self.assertIn("'explicit' EOF", grammar)

    def test_cli_explicit_input_with_output_flag(self):
        self.file("SyntaxBNF-va")
        self.file("SyntaxBNF-vb")
        explicit = self.file("custom.bnf", "explicit")
        output = self.root / "TPTP.g4"
        with patch.object(converter, "REPOSITORY_ROOT", self.root), \
                patch("builtins.input", side_effect=AssertionError("unexpected prompt")), \
                redirect_stdout(StringIO()):
            result = converter.main([str(explicit), "-o", str(output)])
        self.assertEqual(result, 0)
        self.assertIn("Generated from custom.bnf", output.read_text())
        self.assertIn("'explicit' EOF", output.read_text())

    def test_cli_output_flag_discovers_input(self):
        self.file("SyntaxBNF-vonly", "automatic")
        output = self.root / "generated"
        with patch.object(converter, "REPOSITORY_ROOT", self.root), redirect_stdout(StringIO()):
            result = converter.main(["-o", str(output)])
        self.assertEqual(result, 0)
        grammar = (output / "TPTP.g4").read_text()
        self.assertIn("Generated from SyntaxBNF-vonly", grammar)
        self.assertIn("'automatic' EOF", grammar)

    def test_cli_matching_custom_output_file_and_grammar_name(self):
        explicit = self.file("custom.bnf")
        output = self.root / "CustomTPTP.g4"
        with redirect_stdout(StringIO()):
            result = converter.main([
                str(explicit), "-o", str(output), "--output-grammar-name", "CustomTPTP",
            ])
        self.assertEqual(result, 0)
        self.assertIn("grammar CustomTPTP;", output.read_text())

    def test_cli_mismatched_output_file_reports_error_without_conversion(self):
        explicit = self.file("custom.bnf")
        for filename, options, grammar_name in (
            ("CustomTPTP.g4", [], "TPTP"),
            ("TPTP.g4", ["--output-grammar-name", "CustomTPTP"], "CustomTPTP"),
            ("tptp.g4", [], "TPTP"),
        ):
            with self.subTest(filename=filename, options=options):
                output = self.root / "generated" / filename
                diagnostics = StringIO()
                with patch.object(converter, "parse_syntax_bnf") as parse, \
                        redirect_stdout(StringIO()), redirect_stderr(diagnostics):
                    result = converter.main([str(explicit), "-o", str(output), *options])
                self.assertEqual(result, 1)
                self.assertIn(
                    f"Output file name {filename!r} does not match grammar name {grammar_name!r}",
                    diagnostics.getvalue(),
                )
                parse.assert_not_called()
                self.assertFalse(output.parent.exists())

    def test_cli_mismatched_output_file_preserves_existing_file(self):
        explicit = self.file("custom.bnf")
        output = self.root / "CustomTPTP.g4"
        output.write_text("existing grammar", encoding="utf-8")
        with redirect_stdout(StringIO()), redirect_stderr(StringIO()):
            result = converter.main([str(explicit), "-o", str(output)])
        self.assertEqual(result, 1)
        self.assertEqual(output.read_text(), "existing grammar")

    def test_cli_multiple_inputs_reports_error_without_conversion(self):
        self.file("SyntaxBNF-va", "first")
        self.file("SyntaxBNF-vb", "second")
        output = self.root / "TPTP.g4"
        diagnostics = StringIO()
        with patch.object(converter, "REPOSITORY_ROOT", self.root), \
                patch.object(converter, "DEFAULT_OUTPUT_DIRECTORY", output), \
                patch("builtins.input", side_effect=AssertionError("unexpected prompt")), \
                patch.object(converter, "parse_syntax_bnf") as parse, \
                redirect_stdout(StringIO()), redirect_stderr(diagnostics):
            result = converter.main([])
        self.assertEqual(result, 1)
        self.assertIn("error: Multiple SyntaxBNF files found", diagnostics.getvalue())
        self.assertIn("specify the input file explicitly", diagnostics.getvalue())
        parse.assert_not_called()
        self.assertFalse(output.exists())

    def test_cli_missing_input_reports_error_without_output(self):
        output = self.root / "TPTP.g4"
        diagnostics = StringIO()
        with patch.object(converter, "REPOSITORY_ROOT", self.root), \
                patch.object(converter, "DEFAULT_OUTPUT_DIRECTORY", output), \
                redirect_stderr(diagnostics):
            result = converter.main([])
        self.assertEqual(result, 1)
        self.assertIn("error: No files beginning with SyntaxBNF", diagnostics.getvalue())
        self.assertFalse(output.exists())

    def test_cli_empty_input_reports_error_without_output(self):
        explicit = self.root / "empty.bnf"
        output = self.root / "generated" / "TPTP.g4"
        for source in ("", " \t\n\n", "% Only a comment\n\n% Another comment"):
            for options in ([], ["--debug"]):
                with self.subTest(source=source, options=options):
                    explicit.write_text(source, encoding="utf-8")
                    diagnostics = StringIO()
                    stdout = StringIO()
                    with redirect_stdout(stdout), redirect_stderr(diagnostics):
                        result = converter.main([str(explicit), "-o", str(output), *options])
                    self.assertEqual(result, 1)
                    self.assertIn("error: BNF input contains no definitions", diagnostics.getvalue())
                    self.assertEqual(stdout.getvalue(), "")
                    self.assertFalse(output.parent.exists())

    def test_cli_empty_input_preserves_existing_output(self):
        explicit = self.root / "empty.bnf"
        explicit.write_text("", encoding="utf-8")
        output = self.root / "TPTP.g4"
        output.write_text("existing grammar", encoding="utf-8")
        with redirect_stdout(StringIO()), redirect_stderr(StringIO()):
            result = converter.main([str(explicit), "-o", str(output)])
        self.assertEqual(result, 1)
        self.assertEqual(output.read_text(), "existing grammar")

    def test_cli_empty_production_is_valid(self):
        explicit = self.file("empty-production.bnf", literal="")
        output = self.root / "TPTP.g4"
        with redirect_stdout(StringIO()):
            result = converter.main([str(explicit), "-o", str(output)])
        self.assertEqual(result, 0)
        self.assertIn("tptp_file\n    : EOF\n", output.read_text())


if __name__ == "__main__":
    unittest.main()
