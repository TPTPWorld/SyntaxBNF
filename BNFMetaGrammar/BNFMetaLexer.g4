lexer grammar BNFMetaLexer;

// Shared token types emitted by rules in both SYNTAX and REGEX modes.
tokens { PIPE, STAR }

// Modes describe where characters occur; BNFMetaParser.g4 gives them meaning.
// Only ::- and ::: enter REGEX, and only REGEX's [ enters CHARSET.
// Thus brackets and backslashes in syntactic rules stay literal punctuation.
// A physical newline ends a definition unless the next line is indented.

SYNTAX_DEFINITION      : '::=' -> mode(SYNTAX) ;
SEMANTIC_DEFINITION    : ':==' -> mode(SYNTAX) ;
TOKEN_DEFINITION       : '::-' -> mode(REGEX) ;
LEXER_MACRO_DEFINITION : ':::' -> mode(REGEX) ;
NONTERMINAL            : NONTERMINAL_PATTERN ;
COMMENT                : '%' ~[\r\n]* ;
WHITESPACE             : WHITESPACE_PATTERN -> skip ;
NEWLINE                : NEWLINE_PATTERN ;
RAW_CHAR               : . ;

fragment NONTERMINAL_PATTERN : '<' [A-Za-z_] [A-Za-z0-9_]* '>' ;
fragment NEWLINE_PATTERN     : '\r'? '\n' ;
// A newline followed by indentation is whitespace, not a definition boundary.
fragment WHITESPACE_PATTERN  : NEWLINE_PATTERN? [ \t]+ ;

mode SYNTAX;
SYNTAX_NONTERMINAL : NONTERMINAL_PATTERN -> type(NONTERMINAL) ;
BARE_WORD          : [A-Za-z0-9_$]+ ;
SYNTAX_PIPE        : '|' -> type(PIPE) ;
SYNTAX_STAR        : '*' -> type(STAR) ;
SYNTAX_WHITESPACE  : WHITESPACE_PATTERN -> skip ;
SYNTAX_NEWLINE     : NEWLINE_PATTERN -> type(NEWLINE), mode(DEFAULT_MODE) ;
SYNTAX_RAW_CHAR    : . -> type(RAW_CHAR) ;

mode REGEX;
REGEX_NONTERMINAL : NONTERMINAL_PATTERN -> type(NONTERMINAL) ;
REGEX_PIPE        : '|' -> type(PIPE) ;
REGEX_STAR        : '*' -> type(STAR) ;
PLUS              : '+' ;
QUESTION          : '?' ;
WILDCARD          : '.' ;
LPAREN            : '(' ;
RPAREN            : ')' ;
NEGATED_LBRACKET  : '[^' -> pushMode(CHARSET) ;
LBRACKET          : '['  -> pushMode(CHARSET) ;
REGEX_WHITESPACE  : WHITESPACE_PATTERN -> skip ;
REGEX_NEWLINE     : NEWLINE_PATTERN -> type(NEWLINE), mode(DEFAULT_MODE) ;
REGEX_RAW_CHAR    : . -> type(RAW_CHAR) ;

mode CHARSET;
RBRACKET          : ']' -> popMode ;
OCTAL_ESCAPE      : '\\' [0-7]+ ;      // character code in base 8
QUOTED_ESCAPE     : '\\' [\\nr] ;      // escaped backslash, newline, or carriage return
DASH              : '-' ;
CHARSET_CHAR      : [\u0020-\u007E] ;  // printable ASCII, including space
