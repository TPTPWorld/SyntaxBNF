"""Check BNF selection and both supported converter CLI forms."""

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
        self.file("SyntaxBNF-a")
        self.file("SyntaxBNF-b")
        explicit = self.file("custom.bnf")
        with patch.object(converter, "REPOSITORY_ROOT", self.root), \
                patch("builtins.input", side_effect=AssertionError("unexpected prompt")):
            self.assertEqual(converter.select_input_file(explicit), explicit)

    def test_invalid_explicit_file_does_not_fall_back(self):
        self.file("SyntaxBNF-only")
        for path in (self.root / "missing.bnf", self.root):
            with self.subTest(path=path), patch.object(converter, "REPOSITORY_ROOT", self.root):
                with self.assertRaisesRegex(converter.ConversionError, "not a file"):
                    converter.select_input_file(path)

    def test_single_file_uses_prefix_without_version_requirement(self):
        expected = self.file("SyntaxBNF-custom.txt")
        self.file("unrelated.bnf")
        (self.root / "SyntaxBNF-directory").mkdir()
        with patch.object(converter, "REPOSITORY_ROOT", self.root), \
                patch("builtins.input", side_effect=AssertionError("unexpected prompt")):
            self.assertEqual(converter.select_input_file(), expected)

    def test_no_root_file_rejects_nested_matches(self):
        nested = self.root / "nested"
        nested.mkdir()
        (nested / "SyntaxBNF-hidden").write_text("", encoding="utf-8")
        (self.root / "SyntaxBNF-directory").mkdir()
        with patch.object(converter, "REPOSITORY_ROOT", self.root):
            with self.assertRaisesRegex(converter.ConversionError, "No files beginning"):
                converter.select_input_file()

    def test_multiple_files_require_explicit_input(self):
        self.file("SyntaxBNF-b")
        self.file("SyntaxBNF-a")
        with patch.object(converter, "REPOSITORY_ROOT", self.root), \
                patch("builtins.input", side_effect=AssertionError("unexpected prompt")):
            with self.assertRaisesRegex(
                    converter.ConversionError,
                    "Multiple SyntaxBNF files found.*specify the input file explicitly"):
                converter.select_input_file()

    def test_cli_output_only_discovers_input(self):
        self.file("SyntaxBNF-only", "automatic")
        output = self.root / "generated"
        with patch.object(converter, "REPOSITORY_ROOT", self.root), redirect_stdout(StringIO()):
            result = converter.main([str(output), "--output-grammar-name", "Chosen"])
        self.assertEqual(result, 0)
        grammar = (output / "Chosen.g4").read_text()
        self.assertIn("grammar Chosen;", grammar)
        self.assertIn("Generated from SyntaxBNF-only", grammar)
        self.assertIn("'automatic' EOF", grammar)

    def test_cli_preserves_explicit_input_output_form(self):
        self.file("SyntaxBNF-a")
        self.file("SyntaxBNF-b")
        explicit = self.file("custom.bnf", "explicit")
        output = self.root / "TPTP.g4"
        with patch.object(converter, "REPOSITORY_ROOT", self.root), \
                patch("builtins.input", side_effect=AssertionError("unexpected prompt")), \
                redirect_stdout(StringIO()):
            result = converter.main([str(explicit), str(output)])
        self.assertEqual(result, 0)
        self.assertIn("Generated from custom.bnf", output.read_text())
        self.assertIn("'explicit' EOF", output.read_text())

    def test_cli_multiple_inputs_reports_error_without_conversion(self):
        self.file("SyntaxBNF-a", "first")
        self.file("SyntaxBNF-b", "second")
        output = self.root / "TPTP.g4"
        diagnostics = StringIO()
        with patch.object(converter, "REPOSITORY_ROOT", self.root), \
                patch("builtins.input", side_effect=AssertionError("unexpected prompt")), \
                patch.object(converter, "parse_syntax_bnf") as parse, \
                redirect_stdout(StringIO()), redirect_stderr(diagnostics):
            result = converter.main([str(output)])
        self.assertEqual(result, 1)
        self.assertIn("error: Multiple SyntaxBNF files found", diagnostics.getvalue())
        self.assertIn("specify the input file explicitly", diagnostics.getvalue())
        parse.assert_not_called()
        self.assertFalse(output.exists())

    def test_cli_missing_input_reports_error_without_output(self):
        output = self.root / "TPTP.g4"
        diagnostics = StringIO()
        with patch.object(converter, "REPOSITORY_ROOT", self.root), redirect_stderr(diagnostics):
            result = converter.main([str(output)])
        self.assertEqual(result, 1)
        self.assertIn("error: No files beginning with SyntaxBNF", diagnostics.getvalue())
        self.assertFalse(output.exists())


if __name__ == "__main__":
    unittest.main()
