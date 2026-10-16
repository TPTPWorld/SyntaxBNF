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
`comment` tokens are retained on the `HIDDEN` channel for tooling,
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

Run the converter, generated-lexer, and lower-word parser regression checks
from the repository root:

```bash
python3 -m unittest discover -s BNFMetaGrammar/BNF2ANTLR/bnf2antlr_tests -p 'test_*.py'
```

### Fix: Lower_word literals and the CSR003+2.ax parsing failure

Before this fix, the generated ANTLR grammar failed to parse
[CSR003+2.ax, line 275538](/home/xiaji/_TPTP/TPTP-v9.2.1/Axioms/CSR003+2.ax:275538)
in TPTP-v9.2.1:

```tptp
fof(kb_SUMO_52578,axiom,
    s__lexicon(s__ComputerFile,s__LexNoun,file) ).
```

The first error pointed to `file` at column 42 (zero-based). The rule
`file_source : 'file' '(' file_name file_info ')'` creates an implicit lexer
token for `'file'` that takes precedence over `Lower_word`. Previously,
`atomic_word` did not accept that token. The older converter's `'file('` token
avoided this constant case, but still rejected ordinary functors such as `file(z)`.

#### Parser wrapper

The converter now generates `lower_word_token` from syntactic literals whose
complete spellings match the BNF's `<lower_word>` lexical definition, following
referenced macros. All parser references to `<lower_word>` use the wrapper,
including those in `atomic_word` and `formula_role`. For `SyntaxBNF-v9.3.1.6`:

```antlr
lower_word_token
    : Lower_word
    | 'cnf' | 'file' | 'fof' | 'include' | 'inference' | 'introduced'
    | 'tcf' | 'tff' | 'thf' | 'tpi'
    ;

atomic_word
    : lower_word_token | Single_quoted | Back_quoted
    ;

formula_role
    : lower_word_token | lower_word_token '-' general_term
    ;

file_source
    : 'file' '(' file_name file_info ')'
    ;
```

This adaptation restores valid ordinary-symbol uses under ANTLR's token model.
It adds parser alternatives; the lexer definitions and special keyword
productions remain unchanged. The list is derived from `::=` productions rather
than hard-coded; comments and `:==` restrictions are excluded. If the wrapper
name is already taken, the converter uses an available numbered suffix.

ANTLR's [lexer priority documentation](https://github.com/antlr/antlr4/blob/4.13.2/doc/predicates.md#predicates-in-lexer-rules)
and [implicit-lexer construction](https://github.com/antlr/antlr4/blob/4.13.2/tool/src/org/antlr/v4/tool/GrammarTransformPipeline.java#L433-L459)
explain why implicit literal tokens take precedence.

#### Correctly parsed uses of file

Each of the following is correctly parsed:

```tptp
fof(a,axiom,p(file)).            % constant
fof(a,axiom,p(file(z))).         % functor
fof(a,axiom,p,file).             % formula-name reference
fof(a,axiom,p,file('y.p',x)).     % file_source
```

In the source field, the following `(` distinguishes a file-source record from
a name reference. Spaces before `(` are supported. All ten literals can also
be ordinary constants, functors, formula names, and general data. Special
productions still require their exact keyword: `other('y.p',x)` is rejected in
a file-source position. Name references require an appropriate formula in a
complete derivation.

#### Why Dollar_word is excluded

The fix covers only `Lower_word`. The six overlapping dollar-prefixed literals
already have dedicated productions for their standard semantically valid uses:
`$thf`, `$tff`, `$fof`, `$cnf`, and `$fot` in `formula_data`, and `$let` in
structured `thf_let` and `txf_let` expressions. These examples already parse:

```tptp
fof(a,axiom,p,file('y.p',x),[$fof(q)]).
tff(a,axiom,$let(p:$o,p:=$true,p)).
```

A dollar-word wrapper would add no valid standard uses of those six symbols;
it would additionally admit invalid uses such as `p($fof)` or `$let(a,b,c)`
through generic defined-constant/functor productions. See the
[TPTP language documentation](https://tptp.org/UserDocs/TPTPLanguage/TPTPLanguage.shtml)
for interpreted symbols and let expressions.

Therefore, `atomic_defined_word : Dollar_word` remains unchanged. This is an
intentional restriction of the broad `::=` grammar, not full enforcement of
`:==` semantics: unknown dollar words can still parse. Symbols appearing only
in semantic restrictions, such as `$true`, `$sum`, and `$ite`, do not create
implicit tokens and already reach the parser as `Dollar_word`.
