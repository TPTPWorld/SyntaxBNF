parser grammar BNFMetaParser;

options { tokenVocab=BNFMetaLexer; }

// SyntaxBNF definitions and comments should start in column 1;
// an indented line continues the preceding definition (handled by WHITESPACE_PATTERN in lexer rules).
document : ((definition | COMMENT) lineEnd | NEWLINE)* EOF ;

// ::= defines syntax; :== restricts it semantically.
// ::- defines a token; ::: defines a lexer macro.
definition
    : name=NONTERMINAL
      ( separator=(SYNTACTIC_DEFINITION | SEMANTIC_DEFINITION) parserExpression
      | separator=(TOKEN_DEFINITION | LEXER_MACRO_DEFINITION) lexerExpression
      )
    ;

// In ::= and :==, punctuation is literal except for | (alternation) and
// * after a nonterminal (repetition). Thus <input>* means repetition, but ?* is literal.
// Parentheses and brackets are literal, as in tpi(<name>) and [<term>].
// Empty alternatives are allowed, including a definition with no RHS.
parserExpression  : parserAlternative (PIPE parserAlternative)* ;
parserAlternative : parserElement* ;
parserElement     : NONTERMINAL STAR? | parserTerminal ;
parserTerminal    : BARE_WORD | STAR | RAW_CHAR ;

// In ::- and :::, parentheses delimit groups, brackets delimit character sets,
// and *, +, ? quantify the preceding primary. | separates alternatives.
// Literal characters appear in sets: [|], [*], [(], etc.
lexerExpression  : lexerAlternative (PIPE lexerAlternative)* ;
lexerAlternative : lexerElement* ;
lexerElement     : lexerPrimary lexerQuantifier? ;
lexerPrimary     : NONTERMINAL | LPAREN lexerExpression RPAREN | charSet ;
lexerQuantifier  : STAR | PLUS | QUESTION ;

// [^ starts a negated set; later carets are literal.
// The wildcard . is also treated as a set.
charSet
    : (LBRACKET | NEGATED_LBRACKET) charSetContent RBRACKET
    | WILDCARD
    ;

// Character sets are nonempty. Edge hyphens are literal; an interior hyphen forms a range.
// Separate alternatives keep a lone dash in [-] unambiguously leading.
charSetContent
    : leadingDash=DASH charSetElement* trailingDash=DASH?
    | charSetElement+ trailingDash=DASH?
    ;
charSetElement : charSetChar (DASH charSetChar)? ;
charSetChar    : OCTAL_ESCAPE | QUOTED_ESCAPE | CHARSET_CHAR ;

lineEnd : NEWLINE | EOF ;
