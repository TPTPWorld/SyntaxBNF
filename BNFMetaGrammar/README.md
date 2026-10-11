# SyntaxBNF metagrammar

`BNFMetaParser.g4` is an ANTLR4 parser metagrammar for the four kinds of definition in
the TPTP SyntaxBNF notation:

- `::=` syntactic parser rules
- `:==` semantic restrictions
- `::-` lexer tokens
- `:::` lexer character-class macros

It also recognizes `%` comments, blank lines, and indented continuation lines.
The parser and its companion `BNFMetaLexer.g4` are target-neutral and contain
no embedded actions.
All four definition kinds share one `definition` parser rule, with `name` and
`separator` token labels. Only the RHS distinguishes syntax from regex rules.

The lexer keeps words such as `tpi` intact in syntactic and semantic rules.
Inside regex charsets, it emits individual literal characters and complete
escape tokens. The parser recognizes set elements and range endpoints; the
converter decodes each escape token. Lexer modes follow these contexts:

| Context | Entry | Exit |
| --- | --- | --- |
| Default: rule names and comments | Start of document or end of definition | A definition operator |
| Syntactic RHS | `::=` or `:==` | An uncontinued newline |
| Regex RHS | `::-` or `:::` | An uncontinued newline |
| Charset | `[` in a regex RHS | `]` |

Charset openers use `pushMode(CHARSET)`; the closing bracket uses `popMode`
to return to REGEX. Other transitions use `mode(...)` directly.
One `WHITESPACE_PATTERN` fragment handles horizontal whitespace
and indented continuation lines in all three contexts outside charsets.

Indented continuation lines keep the RHS mode. Brackets in syntactic rules
and example definitions in comments do not enter charset mode. Literal charset
characters are printable ASCII (U+0020–U+007E), including space. Physical line
breaks, tabs, and other characters outside that range produce lexer errors;
use escapes to represent them.

Charset support is deliberately limited to SyntaxBNF notation:

- One or more octal digits after a backslash, `\\` for backslash, `\n` for
  newline, and `\r` for carriage return. These are the escape forms used in SyntaxBNF.
- Leading `^` negation, such as `[^/*]`; a later `^` is literal.
- Ranges with literal or escaped endpoints: `A-Z`, `\40-\46`, `\123-X`.
- Literal hyphens at the edges, including `[+-]`, and the existing `.` wildcard.

The lexer recognizes `[^` as a `NEGATED_LBRACKET` token, so leading negation
cannot be interpreted as a literal caret. The parser requires nonempty
`charSetContent`, rejecting `[]` and `[^]` while allowing `[-]` and `[^-]`.
Edge hyphens are recorded as `leadingDash` and `trailingDash` on that content;
a lone hyphen is always `leadingDash`.

Each `charSetElement` contains one `charSetChar`, or two separated by
`DASH` for a range. A character is a literal, `OCTAL_ESCAPE`, or `QUOTED_ESCAPE`
token; no separate range or escape wrapper rules are needed. Longest-match
lexing consumes the entire octal digit sequence: `\1234` is one escape, while `\78` is `\7`
followed by literal `8`. Other backslashes fall back to literal characters;
for example, `\q` contributes both a backslash and `q` to the set.
The converter decodes octal values, emits ANTLR negation as `~[...]`, and
rejects descending ranges and values outside Unicode's U+0000–U+10FFFF range.
There is no limit on the number of octal digits, including leading zeros. Hex escapes,
Unicode properties, POSIX classes, and set operations are not implemented.

Generate and run a parser from this directory with `BNF_FILE` set to the path of
your BNF syntax file:

```bash
java -jar ../ANTLRParsers/antlr-4.13.2-complete.jar BNFMetaLexer.g4 BNFMetaParser.g4
javac -cp ../ANTLRParsers/antlr-4.13.2-complete.jar BNFMeta*.java
java -cp "../ANTLRParsers/antlr-4.13.2-complete.jar:." \
  org.antlr.v4.gui.TestRig BNFMeta document -tree "$BNF_FILE"
```

For automatic input selection, use the
[metagrammar-driven Python converter](#metagrammar-driven-converter).

## Metagrammar-driven converter

`BNF2ANTLR/bnf2antlr_meta.py` is the metagrammar-driven converter.
It generates a temporary Python parser
from `BNFMetaGrammar/BNFMetaParser.g4` and its companion `BNFMetaLexer.g4`,
parses the complete SyntaxBNF document,
and emits a combined ANTLR4 grammar.

The converter follows the existing SyntaxBNF conventions directly:
`TPTP_file` is the entry rule,
`comment` tokens are skipped,
and macros referenced by parser rules become tokens.
It relies on the metagrammar to validate definitions
and stops at the first syntax error.
Charset conversion also checks range order and octal values.

### How to run the metagrammar-driven converter

Install the matching runtime once:

```bash
python3 -m pip install -r BNFMetaGrammar/BNF2ANTLR/requirements.txt
```

From the repository root, run the converter:

```bash
python3 BNFMetaGrammar/BNF2ANTLR/bnf2antlr_meta.py
```

By default, the converter takes as its input
the file under the repository root whose name begins with `SyntaxBNF`,
and generates `TPTP.g4` in the default output directory,
`BNFMetaGrammar/ANTLRGrammar/converted_by_meta`.

Alternatively, you can specify the input and output as follows:

```bash
python3 BNFMetaGrammar/BNF2ANTLR/bnf2antlr_meta.py \
  /path/to/Syntax/BNF \
  BNFMetaGrammar/ANTLRGrammar/CustomTPTP.g4 \
  --output-grammar-name CustomTPTP
```

The converter requires Java and the repository's `ANTLRParsers/antlr-4.13.2-complete.jar`.
Alternative metagrammar and jar paths can be selected with `--metagrammar` and `--antlr-jar`.
The selected metagrammar must have its companion `BNFMetaLexer.g4` in the same directory.

### How to test the metagrammar-driven converter

Run the charset conversion and generated-lexer checks from the repository root:

```bash
python3 -m unittest discover -s BNFMetaGrammar/BNF2ANTLR/bnf2antlr_tests -p 'test_*.py'
```
