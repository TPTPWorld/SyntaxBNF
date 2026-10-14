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

### Fix: Lower_word literals and the CSR003+2.ax parsing failure

Before this fix, the metagrammar-generated ANTLR grammar failed to parse
[CSR003+2.ax, line 275538](/home/xiaji/_TPTP/TPTP-v9.2.1/Axioms/CSR003+2.ax:275538)
in the local TPTP-v9.2.1 distribution. The failing formula was:

```tptp
fof(kb_SUMO_52578,axiom,
    s__lexicon(s__ComputerFile,s__LexNoun,file) ).
```

The first error pointed to the unquoted constant `file` (column 42, zero-based):

```text
line 275538:42 no viable alternative at input 's__lexicon(s__ComputerFile,s__LexNoun,file'
```

The converted rule `file_source : 'file' '(' file_name file_info ')'` creates an
implicit lexer token for `'file'`. Although `file` matches the `Lower_word`
character pattern, ANTLR emits that literal token instead. Previously,
`atomic_word` accepted only `Lower_word`, `Single_quoted`, and `Back_quoted`, so
it rejected the literal token inside the formula. The older line-oriented
converter's `'file('` token avoided this constant case, but still rejected an
ordinary functor application such as `file(z)`.

#### Implemented parser wrapper

The converter now emits a parser rule `lower_word_token` accepting `Lower_word`
and the syntactic literals whose complete spellings match the source
`<lower_word>` lexical definition. It follows referenced lexical macros and
collects literals from `::=` productions, excluding `:==` restrictions and
comments. Every parser reference to `<lower_word>` uses this wrapper, including
`atomic_word` and the direct references in `formula_role`. The lexer rule itself
is unchanged. If the wrapper name already exists as a parser rule, the converter
chooses an available numbered suffix.

For the checked-in `SyntaxBNF-v9.3.1.6`, the wrapper includes these ten literals:

```antlr
lower_word_token
    : Lower_word
    | 'cnf'
    | 'file'
    | 'fof'
    | 'include'
    | 'inference'
    | 'introduced'
    | 'tcf'
    | 'tff'
    | 'thf'
    | 'tpi'
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

This is a deliberate adaptation of SyntaxBNF to ANTLR's lexer/parser model,
rather than a one-to-one transcription of productions. It restores valid
ordinary-symbol uses that would otherwise be shadowed by implicit literal
tokens. The ten strings already occur elsewhere in the grammar; the fix adds
parser alternatives, not new spellings or lexer token types. The converter
derives the list from the BNF instead of hard-coding it. No target-language
predicates or lexer modes are needed.

ANTLR's [lexer priority documentation](https://github.com/antlr/antlr4/blob/4.13.2/doc/predicates.md#predicates-in-lexer-rules)
explains the tie-breaking rule, and its
[implicit-lexer construction](https://github.com/antlr/antlr4/blob/4.13.2/tool/src/org/antlr/v4/tool/GrammarTransformPipeline.java#L433-L459)
places generated literal rules before explicit lexer rules.

#### Correctly parsed uses of file

Each of the following is correctly parsed, with a distinct intended role for
`file`:

```tptp
fof(a,axiom,p(file)).            % constant
fof(a,axiom,p(file(z))).         % functor
fof(a,axiom,p,file).             % formula-name reference
fof(a,axiom,p,file('y.p',x)).     % file_source
```

Inside a formula, `file` can be a constant or functor. In the source field,
`file` alone is a name reference, while `file(...)` is a file-source record.
The following `(` distinguishes the latter two cases. In general data, the
same lookahead distinguishes a general function from an atomic word. Spaces
between `file` and `(` are also supported.

All ten included literals can occur as ordinary constants or functors, formula
names, and general data. The fix still requires the exact keyword in special
productions: `other('y.p',x)` is rejected in a file-source position. The examples
above demonstrate parsing; a name reference must refer to an appropriate
formula in a complete derivation.

#### Why Dollar_word is excluded

**The fix is restricted to `Lower_word`.** The audit also found six syntactic
literals matching `Dollar_word`, but they are excluded:

| Lexical category | Overlapping literals | Fix scope |
| --- | --- | --- |
| `Lower_word` | `cnf`, `file`, `fof`, `include`, `inference`, `introduced`, `tcf`, `tff`, `thf`, `tpi` | Included |
| `Dollar_word` | `$cnf`, `$fof`, `$fot`, `$let`, `$tff`, `$thf` | Excluded |

There are no overlaps with the other emitted lexical categories in this BNF
version. The six dollar-prefixed literals already have dedicated productions
for their standard semantically valid uses: `$thf`, `$tff`, `$fof`, `$cnf`, and
`$fot` occur in `formula_data`; `$let` occurs in structured `thf_let` and
`txf_let` expressions. Their generic character pattern needs no change, and
adding them to a parser wrapper would not enable additional semantically valid
inputs for those standard uses. For example, these already parse correctly:

```tptp
fof(a,axiom,p,file('y.p',x),[$fof(q)]).
tff(a,axiom,$let(p:$o,p:=$true,p)).
```

A dollar-word wrapper would additionally admit uses such as `p($fof)`,
`p($fof(z))`, or `$let(a,b,c)` through generic defined-constant/functor
productions. Those uses have invalid standard TPTP semantics; the last lacks
proper let-expression types and definitions. Broadening the parser to admit
them is outside this fix's scope. See the
[TPTP language documentation](https://tptp.org/UserDocs/TPTPLanguage/TPTPLanguage.shtml)
for interpreted symbols and let expressions. Quoting `'$fof'` instead denotes
an ordinary quoted symbol with different meaning.

Thus `atomic_defined_word : Dollar_word` remains unchanged. This exclusion is
an intentional restriction of the broad `::=` grammar, not enforcement of all
`:==` restrictions. Other unknown dollar words can still parse. Literals
appearing only in semantic restrictions, such as `$true`, `$sum`, and `$ite`,
do not create implicit tokens and already reach the parser as `Dollar_word`.
Future BNF revisions should be reviewed if legitimate dollar-literal uses change.

#### Parse-tree compatibility, ambiguity, and performance

The wrapper adds a parser context and tree level wherever it is used. Consumers
of generated getters or listener/visitor methods must account for that structure
and for literal tokens representing ordinary words. Use token text when the
spelling matters. The wrapper also adds a rule call and context allocation.
Semantic validation of roles, types, arities, and interpreted symbols remains
a separate responsibility.

The wrapper itself is unambiguous: its alternatives are distinct token types,
and the lexer has already selected one. ANTLR compiles them into a token-set
membership check rather than eleven sequential parsing attempts. An earlier
wrapper prototype, checked with ANTLR 4.13.2's `LL_EXACT_AMBIG_DETECTION`, parsed
the complete original `CSR003+2.ax` (1,917,234 tokens) with zero ambiguities,
zero full-context prediction fallbacks, and zero syntax errors. This is evidence
for that input, not proof that the entire TPTP grammar has no unrelated ambiguity.
The regression tests also check the four examples' actual parse-tree roles.

An earlier local Java benchmark used identical, pre-tokenized input for both
grammars, quoting the original failing constant as `'file'` so the grammar before
the fix could parse it. Medians of seven measured parses after warmup were:

| Parse-tree construction | Before the fix | Named wrapper prototype |
| --- | --- | --- |
| Disabled | 0.179 s | 0.180 s |
| Enabled | 0.616 s | 0.718 s |

File reading and lexing were excluded. Tree construction showed about 16%
overhead in that experiment, with substantial timing variation between runs.
These are illustrative measurements, not a performance guarantee. The fix does
not resolve unrelated lexer overlaps or grammar ambiguities.

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
