/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "SyntaxBNF.y"

//-----------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
//-----------------------------------------------------------------------------
int yylex(void);
int yyparse(void);
void yyerror(const char *s);
#if defined(__GNUC__)
void tptp_fatal(const char *message) __attribute__((noreturn));
#else
void tptp_fatal(const char *message);
#endif
//-----------------------------------------------------------------------------
//----Compile with -DP_VERBOSE=1 for verbose output.
#ifndef P_VERBOSE
#  define P_VERBOSE 0
#endif
int verbose = P_VERBOSE;

#define YYMAXDEPTH 32768

//----Compile with -DP_SZS=1, 2, or 3 for output in the SZS style of SystemOnTPTP,
//----as the BNFParser, BNFParserTree, and BNFParserDrill scripts used to make:
//----a status line (% SZS status Success, or SyntaxError with the message),
//----then on success the parse tree, then "% BNFParser exiting".
//----    1  status only
//----    2  the tree between SZS NonLogicalData lines; use with P_VERBOSE=1
//----    3  the tree between <HTML> and </HTML>; use with the clickable UserProcs
#ifndef P_SZS
#  define P_SZS 0
#endif
#define P_SZS_STATUS 1
#define P_SZS_TREE   2
#define P_SZS_HTML   3

//----The first error message from yacc, e.g., "syntax error in line 3 at ...".
static char* pErrorMessage = NULL;
//----The input file name, for messages.
static const char* pInputName = "standard input";

//----To use your own tree procedures, compile with -DP_USERPROC_FILE='"file.c"'
//----(or, as before, with -DP_USERPROC=1 to #include p_user_proc.c). The file
//----should #define P_ACT, P_BUILD, P_TOKEN, P_PRINT to different procedures
//----from those below, and supply code.
#if defined(P_USERPROC_FILE)
#  include P_USERPROC_FILE
#elif defined(P_USERPROC)
#  include "p_user_proc.c"
#else
#  define P_ACT(ss) if(verbose)printf("%7d %s\n",yylineno,ss);
#  define P_BUILD(sym,A,B,C,D,E,F,G,H,I,J) pBuildTree(sym,A,B,C,D,E,F,G,H,I,J)
#  define P_TOKEN(tok,symbolIndex) pToken(tok,symbolIndex)
#  define P_PRINT(ss) if(verbose){printf("\n\n");pPrintTree(ss,0);}
#endif

extern int yylineno;
extern int yychar;
extern char yytext[];
extern FILE *yyin;

extern int tptp_store_size;
extern char* tptp_lval[];

//----P_BUILD gives a node at most 10 children, plus the NULL terminator.
#define MAX_CHILDREN 10
typedef struct pTreeNode * pTree;
struct pTreeNode {
    char* symbol;
    int symbolIndex;
    pTree children[MAX_CHILDREN+1];
};
//-----------------------------------------------------------------------------
void yyerror(const char *s) {

    size_t length;

    if (P_SZS == 0) {
        fprintf( stderr, "%s in line %d at item \"%s\".\n", s, yylineno, yytext);
    }
    if (pErrorMessage == NULL) {
        length = strlen(s) + strlen(yytext) + 64;
        if ((pErrorMessage = (char*)malloc(length)) != NULL) {
            snprintf(pErrorMessage, length, "%s in line %d at item \"%s\".", s,
yylineno, yytext);
        }
    }
}
//-----------------------------------------------------------------------------
pTree pBuildTree(char* symbol,pTree A,pTree B,pTree C,pTree D,pTree E,pTree F,
pTree G, pTree H, pTree I, pTree J) {

    pTree ss = (pTree)calloc(1,sizeof(struct pTreeNode));

    if (ss == NULL) {
        tptp_fatal("Out of memory building the parse tree.");
    }
    ss->symbol = symbol;
    ss->symbolIndex = -1;
    ss->children[0] = A;
    ss->children[1] = B;
    ss->children[2] = C;
    ss->children[3] = D;
    ss->children[4] = E;
    ss->children[5] = F;
    ss->children[6] = G;
    ss->children[7] = H;
    ss->children[8] = I;
    ss->children[9] = J;
    ss->children[10] = NULL;

    return ss;
}
//-----------------------------------------------------------------------------
pTree pToken(char* token, int symbolIndex) {

    pTree ss;
    char* symbol = tptp_lval[symbolIndex];
    size_t length = strlen(token) + strlen(symbol) + 1;
    char* safeSym = (char*)malloc(length);

    if (safeSym == NULL) {
        tptp_fatal("Out of memory building the parse tree.");
    }
    snprintf(safeSym, length, "%s%s", token, symbol);
    ss = pBuildTree(safeSym,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
    ss->symbolIndex = symbolIndex;

    return ss;
}
//-----------------------------------------------------------------------------
void pPrintComments(int start, int depth) {

    int d, j;
    char c1[4] = "%", c2[4] = "/*";

    j = start;
    while (tptp_lval[j] != NULL && (tptp_lval[j][0]==c1[0] ||
(tptp_lval[j][0]==c2[0] && tptp_lval[j][1]==c2[1]))) {
        for (d=0; d<depth-1; d++) {
            printf("| ");
        }
        printf("%1d ",depth % 10);
        printf("%s\n",tptp_lval[j]);
        j = (j+1)%tptp_store_size;
    }
    return;
}
//-----------------------------------------------------------------------------
void pPrintTree(pTree ss, int depth) {

//----pPrintIdx is where to find top-level comments to print before a sentence.
//----yywrap() gets those after last sentence.
    static int pPrintIdx = 0;
    int i, d;

    if (pPrintIdx >= 0) {
        pPrintComments(pPrintIdx, 0);
        pPrintIdx = -1;
    }
    if (ss == NULL) {
        return;
    }
    for (d = 0; d < depth-1; d++) {
        printf("| ");
    }
    printf("%1d ",depth % 10);
    if (ss->children[0] == NULL) {
        printf("%s\n", ss->symbol);
    } else {
        printf("<%s>\n", ss->symbol);
    }
    if (strcmp(ss->symbol, "PERIOD .") == 0) {
        pPrintIdx = (ss->symbolIndex+1) % tptp_store_size;
    }
    if (ss->symbolIndex >= 0) {
        pPrintComments((ss->symbolIndex+1) % tptp_store_size, depth);
    }
    i = 0;
    while(ss->children[i] != NULL) {
        pPrintTree(ss->children[i],depth+1);
        i++;
    }
    return;
}
//-----------------------------------------------------------------------------
int yywrap(void) {

    P_PRINT(NULL);
    return 1;
}
//-----------------------------------------------------------------------------
#if P_SZS
//-----------------------------------------------------------------------------
//----SZS mode. Output made while parsing (the tree) goes to a temporary file,
//----so that the status line can come first. pRealStdout is the real stdout
//----while that is happening, and -1 otherwise.
static FILE* pCapture = NULL;
static volatile int pRealStdout = -1;
static volatile sig_atomic_t pStatusDone = 0;
static const char* const pExitLine = "% BNFParser exiting\n";
//-----------------------------------------------------------------------------
static void pRestoreStdout(void) {

    if (pRealStdout >= 0) {
        fflush(stdout);
        dup2(pRealStdout, STDOUT_FILENO);
        close(pRealStdout);
        pRealStdout = -1;
    }
}
//-----------------------------------------------------------------------------
//----Print the status line, e.g., "% SZS status SyntaxError : message".
static void pPrintSZSStatus(const char* status, const char* message) {

    pRestoreStdout();
    printf("%% SZS status %s", status);
    if (message != NULL) {
        fputs(" : ", stdout);
        fputs(message, stdout);
    }
    putchar('\n');
    fflush(stdout);
    pStatusDone = 1;
}
//-----------------------------------------------------------------------------
//----Report a failure that stops the parse, and exit.
static void pStopSZS(const char* status, const char* message, int exitStatus) {

    pPrintSZSStatus(status, message);
    fputs(pExitLine, stdout);
    exit(exitStatus);
}
//-----------------------------------------------------------------------------
//----Only async-signal-safe calls here.
static void pWriteAll(int fd, const char* text) {

    size_t length = strlen(text);
    ssize_t written;

    while (length > 0 && (written = write(fd, text, length)) > 0) {
        text += written;
        length -= (size_t)written;
    }
}
//-----------------------------------------------------------------------------
//----On a crash report an Error; on an interrupt or a time limit just say
//----that the parser is exiting, as the scripts did. Then die of the signal.
static void pSignalHandler(int signalNumber) {

    int fd = pRealStdout >= 0 ? pRealStdout : STDOUT_FILENO;
    char message[80] = "% SZS status Error : The parser crashed with signal ";
    char digits[12];
    int n = 0, i, end;

    if (!pStatusDone && signalNumber != SIGINT && signalNumber != SIGTERM &&
signalNumber != SIGHUP && signalNumber != SIGXCPU) {
        do {
            digits[n++] = '0' + signalNumber % 10;
            signalNumber /= 10;
        } while (signalNumber > 0 && n < 10);
        end = strlen(message);
        for (i = n-1; i >= 0; i--) {
            message[end++] = digits[i];
        }
        message[end++] = '.';
        message[end++] = '\n';
        message[end] = '\0';
        pWriteAll(fd, message);
    }
    pWriteAll(fd, pExitLine);
    pStatusDone = 1;
}
//-----------------------------------------------------------------------------
static void pSignalAndDie(int signalNumber) {

    pSignalHandler(signalNumber);
    signal(signalNumber, SIG_DFL);
    raise(signalNumber);
}
//-----------------------------------------------------------------------------
static void pInstallSignalHandlers(void) {

    int signals[] = {SIGINT, SIGTERM, SIGHUP, SIGXCPU, SIGSEGV, SIGBUS, SIGFPE,
SIGILL, SIGABRT};
    size_t i;

    for (i = 0; i < sizeof(signals)/sizeof(signals[0]); i++) {
        signal(signals[i], pSignalAndDie);
    }
}
#endif
//-----------------------------------------------------------------------------
//----Lexer and memory failures, e.g., a token longer than YYLMAX.
void tptp_fatal(const char *message) {

    const char* status = "ResourceOut";
    char buffer[1024];

//----A read error, e.g., the input is a directory
    if (strstr(message, "input in flex scanner failed") != NULL) {
        status = "OSError";
        snprintf(buffer, sizeof(buffer), "%s: %s", pInputName, strerror(errno));
        message = buffer;
    } else if (strstr(message, "internal error") != NULL) {
        status = "Error";
    }
#if P_SZS
    pStopSZS(status, message, 2);
#else
    (void)status;
    fprintf(stderr, "%s\n", message);
#endif
    exit(2);
}
//-----------------------------------------------------------------------------
//----Parse the file named on the command line, or stdin if none (or "-").
//----Exit status: 0 the input parsed, 1 it did not, 2 a usage or I/O error.
//----In SZS mode, as the scripts did, other arguments are ignored, and the
//----exit status is 0 when the status is Success or SyntaxError.
//----Compile with -DP_NO_MAIN to supply your own main().
#ifndef P_NO_MAIN
int main(int argc, char *argv[]) {

#if P_SZS
    int result;
    char buffer[65536];
    size_t length;
    int capture;

    if (argc >= 2 && strcmp(argv[1], "-") != 0 &&
(yyin = fopen(pInputName = argv[1], "r")) == NULL) {
        snprintf(buffer, sizeof(buffer), "%s: %s", argv[1], strerror(errno));
        pStopSZS("OSError", buffer, 2);
    }
    pInstallSignalHandlers();
//----The tree goes to a temporary file until the parse is finished.
    fflush(stdout);
    if ((pCapture = tmpfile()) == NULL ||
(capture = dup(STDOUT_FILENO)) < 0 ||
dup2(fileno(pCapture), STDOUT_FILENO) < 0) {
        snprintf(buffer, sizeof(buffer), "Cannot make a temporary file: %s",
strerror(errno));
        pStopSZS("OSError", buffer, 2);
    }
    pRealStdout = capture;
    result = yyparse();
    pRestoreStdout();

    if (result != 0) {
        if (pErrorMessage != NULL && strstr(pErrorMessage, "syntax error") != NULL) {
            pStopSZS("SyntaxError", pErrorMessage, 0);
        }
        pStopSZS("ResourceOut", pErrorMessage != NULL ? pErrorMessage :
"The parser stopped.", 2);
    }
    pPrintSZSStatus("Success", NULL);
    if (P_SZS == P_SZS_TREE) {
        puts("% SZS output start NonLogicalData");
    } else if (P_SZS == P_SZS_HTML) {
        puts("<HTML>");
    }
    if (P_SZS != P_SZS_STATUS) {
        rewind(pCapture);
        while ((length = fread(buffer, 1, sizeof(buffer), pCapture)) > 0) {
            fwrite(buffer, 1, length, stdout);
        }
    }
    if (P_SZS == P_SZS_TREE) {
        puts("% SZS output end NonLogicalData");
    } else if (P_SZS == P_SZS_HTML) {
        puts("</HTML>");
    }
    fputs(pExitLine, stdout);
    return 0;
#else
    if (argc > 2) {
        fprintf(stderr, "Usage: %s [file]\n", argv[0]);
        return 2;
    }
    if (argc == 2 && strcmp(argv[1], "-") != 0) {
        if ((yyin = fopen(pInputName = argv[1], "r")) == NULL) {
            perror(argv[1]);
            return 2;
        }
    }
    return yyparse() == 0 ? 0 : 1;
#endif
}
#endif
//-----------------------------------------------------------------------------

#line 468 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    AMPERSAND = 258,               /* AMPERSAND  */
    AT_AT_SIGN_MINUS = 259,        /* AT_AT_SIGN_MINUS  */
    AT_AT_SIGN_PLUS = 260,         /* AT_AT_SIGN_PLUS  */
    AT_SIGN = 261,                 /* AT_SIGN  */
    AT_SIGN_EQUALS = 262,          /* AT_SIGN_EQUALS  */
    AT_SIGN_MINUS = 263,           /* AT_SIGN_MINUS  */
    AT_SIGN_PLUS = 264,            /* AT_SIGN_PLUS  */
    CARET = 265,                   /* CARET  */
    COLON = 266,                   /* COLON  */
    COLON_EQUALS = 267,            /* COLON_EQUALS  */
    COMMA = 268,                   /* COMMA  */
    EQUALS = 269,                  /* EQUALS  */
    EQUALS_EQUALS = 270,           /* EQUALS_EQUALS  */
    EQUALS_GREATER = 271,          /* EQUALS_GREATER  */
    EXCLAMATION = 272,             /* EXCLAMATION  */
    EXCLAMATION_EQUALS = 273,      /* EXCLAMATION_EQUALS  */
    EXCLAMATION_EXCLAMATION = 274, /* EXCLAMATION_EXCLAMATION  */
    EXCLAMATION_GREATER = 275,     /* EXCLAMATION_GREATER  */
    LBRACE = 276,                  /* LBRACE  */
    LBRKT = 277,                   /* LBRKT  */
    LESS_EQUALS = 278,             /* LESS_EQUALS  */
    LESS_EQUALS_GREATER = 279,     /* LESS_EQUALS_GREATER  */
    LESS_LESS = 280,               /* LESS_LESS  */
    LESS_TILDE_GREATER = 281,      /* LESS_TILDE_GREATER  */
    LPAREN = 282,                  /* LPAREN  */
    MINUS = 283,                   /* MINUS  */
    MINUS_MINUS_GREATER = 284,     /* MINUS_MINUS_GREATER  */
    PERIOD = 285,                  /* PERIOD  */
    QUESTION = 286,                /* QUESTION  */
    QUESTION_QUESTION = 287,       /* QUESTION_QUESTION  */
    QUESTION_STAR = 288,           /* QUESTION_STAR  */
    RBRACE = 289,                  /* RBRACE  */
    RBRKT = 290,                   /* RBRKT  */
    RPAREN = 291,                  /* RPAREN  */
    STAR = 292,                    /* STAR  */
    TILDE = 293,                   /* TILDE  */
    TILDE_AMPERSAND = 294,         /* TILDE_AMPERSAND  */
    TILDE_VLINE = 295,             /* TILDE_VLINE  */
    VLINE = 296,                   /* VLINE  */
    _DLR_cnf = 297,                /* _DLR_cnf  */
    _DLR_fof = 298,                /* _DLR_fof  */
    _DLR_fot = 299,                /* _DLR_fot  */
    _DLR_let = 300,                /* _DLR_let  */
    _DLR_tff = 301,                /* _DLR_tff  */
    _DLR_thf = 302,                /* _DLR_thf  */
    _LIT_cnf = 303,                /* _LIT_cnf  */
    _LIT_file = 304,               /* _LIT_file  */
    _LIT_fof = 305,                /* _LIT_fof  */
    _LIT_include = 306,            /* _LIT_include  */
    _LIT_inference = 307,          /* _LIT_inference  */
    _LIT_introduced = 308,         /* _LIT_introduced  */
    _LIT_tcf = 309,                /* _LIT_tcf  */
    _LIT_tff = 310,                /* _LIT_tff  */
    _LIT_thf = 311,                /* _LIT_thf  */
    _LIT_tpi = 312,                /* _LIT_tpi  */
    arrow = 313,                   /* arrow  */
    back_quoted = 314,             /* back_quoted  */
    distinct_object = 315,         /* distinct_object  */
    dollar_dollar_word = 316,      /* dollar_dollar_word  */
    dollar_word = 317,             /* dollar_word  */
    hash = 318,                    /* hash  */
    integer = 319,                 /* integer  */
    less_sign = 320,               /* less_sign  */
    lower_word = 321,              /* lower_word  */
    plus = 322,                    /* plus  */
    rational = 323,                /* rational  */
    real = 324,                    /* real  */
    single_quoted = 325,           /* single_quoted  */
    slash = 326,                   /* slash  */
    slosh = 327,                   /* slosh  */
    unrecognized = 328,            /* unrecognized  */
    upper_word = 329               /* upper_word  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 399 "SyntaxBNF.y"
int ival; double dval; char* sval; void* pval;

#line 595 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_AMPERSAND = 3,                  /* AMPERSAND  */
  YYSYMBOL_AT_AT_SIGN_MINUS = 4,           /* AT_AT_SIGN_MINUS  */
  YYSYMBOL_AT_AT_SIGN_PLUS = 5,            /* AT_AT_SIGN_PLUS  */
  YYSYMBOL_AT_SIGN = 6,                    /* AT_SIGN  */
  YYSYMBOL_AT_SIGN_EQUALS = 7,             /* AT_SIGN_EQUALS  */
  YYSYMBOL_AT_SIGN_MINUS = 8,              /* AT_SIGN_MINUS  */
  YYSYMBOL_AT_SIGN_PLUS = 9,               /* AT_SIGN_PLUS  */
  YYSYMBOL_CARET = 10,                     /* CARET  */
  YYSYMBOL_COLON = 11,                     /* COLON  */
  YYSYMBOL_COLON_EQUALS = 12,              /* COLON_EQUALS  */
  YYSYMBOL_COMMA = 13,                     /* COMMA  */
  YYSYMBOL_EQUALS = 14,                    /* EQUALS  */
  YYSYMBOL_EQUALS_EQUALS = 15,             /* EQUALS_EQUALS  */
  YYSYMBOL_EQUALS_GREATER = 16,            /* EQUALS_GREATER  */
  YYSYMBOL_EXCLAMATION = 17,               /* EXCLAMATION  */
  YYSYMBOL_EXCLAMATION_EQUALS = 18,        /* EXCLAMATION_EQUALS  */
  YYSYMBOL_EXCLAMATION_EXCLAMATION = 19,   /* EXCLAMATION_EXCLAMATION  */
  YYSYMBOL_EXCLAMATION_GREATER = 20,       /* EXCLAMATION_GREATER  */
  YYSYMBOL_LBRACE = 21,                    /* LBRACE  */
  YYSYMBOL_LBRKT = 22,                     /* LBRKT  */
  YYSYMBOL_LESS_EQUALS = 23,               /* LESS_EQUALS  */
  YYSYMBOL_LESS_EQUALS_GREATER = 24,       /* LESS_EQUALS_GREATER  */
  YYSYMBOL_LESS_LESS = 25,                 /* LESS_LESS  */
  YYSYMBOL_LESS_TILDE_GREATER = 26,        /* LESS_TILDE_GREATER  */
  YYSYMBOL_LPAREN = 27,                    /* LPAREN  */
  YYSYMBOL_MINUS = 28,                     /* MINUS  */
  YYSYMBOL_MINUS_MINUS_GREATER = 29,       /* MINUS_MINUS_GREATER  */
  YYSYMBOL_PERIOD = 30,                    /* PERIOD  */
  YYSYMBOL_QUESTION = 31,                  /* QUESTION  */
  YYSYMBOL_QUESTION_QUESTION = 32,         /* QUESTION_QUESTION  */
  YYSYMBOL_QUESTION_STAR = 33,             /* QUESTION_STAR  */
  YYSYMBOL_RBRACE = 34,                    /* RBRACE  */
  YYSYMBOL_RBRKT = 35,                     /* RBRKT  */
  YYSYMBOL_RPAREN = 36,                    /* RPAREN  */
  YYSYMBOL_STAR = 37,                      /* STAR  */
  YYSYMBOL_TILDE = 38,                     /* TILDE  */
  YYSYMBOL_TILDE_AMPERSAND = 39,           /* TILDE_AMPERSAND  */
  YYSYMBOL_TILDE_VLINE = 40,               /* TILDE_VLINE  */
  YYSYMBOL_VLINE = 41,                     /* VLINE  */
  YYSYMBOL__DLR_cnf = 42,                  /* _DLR_cnf  */
  YYSYMBOL__DLR_fof = 43,                  /* _DLR_fof  */
  YYSYMBOL__DLR_fot = 44,                  /* _DLR_fot  */
  YYSYMBOL__DLR_let = 45,                  /* _DLR_let  */
  YYSYMBOL__DLR_tff = 46,                  /* _DLR_tff  */
  YYSYMBOL__DLR_thf = 47,                  /* _DLR_thf  */
  YYSYMBOL__LIT_cnf = 48,                  /* _LIT_cnf  */
  YYSYMBOL__LIT_file = 49,                 /* _LIT_file  */
  YYSYMBOL__LIT_fof = 50,                  /* _LIT_fof  */
  YYSYMBOL__LIT_include = 51,              /* _LIT_include  */
  YYSYMBOL__LIT_inference = 52,            /* _LIT_inference  */
  YYSYMBOL__LIT_introduced = 53,           /* _LIT_introduced  */
  YYSYMBOL__LIT_tcf = 54,                  /* _LIT_tcf  */
  YYSYMBOL__LIT_tff = 55,                  /* _LIT_tff  */
  YYSYMBOL__LIT_thf = 56,                  /* _LIT_thf  */
  YYSYMBOL__LIT_tpi = 57,                  /* _LIT_tpi  */
  YYSYMBOL_arrow = 58,                     /* arrow  */
  YYSYMBOL_back_quoted = 59,               /* back_quoted  */
  YYSYMBOL_distinct_object = 60,           /* distinct_object  */
  YYSYMBOL_dollar_dollar_word = 61,        /* dollar_dollar_word  */
  YYSYMBOL_dollar_word = 62,               /* dollar_word  */
  YYSYMBOL_hash = 63,                      /* hash  */
  YYSYMBOL_integer = 64,                   /* integer  */
  YYSYMBOL_less_sign = 65,                 /* less_sign  */
  YYSYMBOL_lower_word = 66,                /* lower_word  */
  YYSYMBOL_plus = 67,                      /* plus  */
  YYSYMBOL_rational = 68,                  /* rational  */
  YYSYMBOL_real = 69,                      /* real  */
  YYSYMBOL_single_quoted = 70,             /* single_quoted  */
  YYSYMBOL_slash = 71,                     /* slash  */
  YYSYMBOL_slosh = 72,                     /* slosh  */
  YYSYMBOL_unrecognized = 73,              /* unrecognized  */
  YYSYMBOL_upper_word = 74,                /* upper_word  */
  YYSYMBOL_YYACCEPT = 75,                  /* $accept  */
  YYSYMBOL_TPTP_file = 76,                 /* TPTP_file  */
  YYSYMBOL_TPTP_input = 77,                /* TPTP_input  */
  YYSYMBOL_annotated_formula = 78,         /* annotated_formula  */
  YYSYMBOL_tpi_annotated = 79,             /* tpi_annotated  */
  YYSYMBOL_tpi_formula = 80,               /* tpi_formula  */
  YYSYMBOL_thf_annotated = 81,             /* thf_annotated  */
  YYSYMBOL_tff_annotated = 82,             /* tff_annotated  */
  YYSYMBOL_tcf_annotated = 83,             /* tcf_annotated  */
  YYSYMBOL_fof_annotated = 84,             /* fof_annotated  */
  YYSYMBOL_cnf_annotated = 85,             /* cnf_annotated  */
  YYSYMBOL_annotations = 86,               /* annotations  */
  YYSYMBOL_formula_role = 87,              /* formula_role  */
  YYSYMBOL_thf_formula = 88,               /* thf_formula  */
  YYSYMBOL_thf_logic_formula = 89,         /* thf_logic_formula  */
  YYSYMBOL_thf_binary_formula = 90,        /* thf_binary_formula  */
  YYSYMBOL_thf_binary_pair = 91,           /* thf_binary_pair  */
  YYSYMBOL_thf_binary_list = 92,           /* thf_binary_list  */
  YYSYMBOL_thf_or_formula = 93,            /* thf_or_formula  */
  YYSYMBOL_thf_and_formula = 94,           /* thf_and_formula  */
  YYSYMBOL_thf_apply_formula = 95,         /* thf_apply_formula  */
  YYSYMBOL_thf_unit_formula = 96,          /* thf_unit_formula  */
  YYSYMBOL_thf_preunit_formula = 97,       /* thf_preunit_formula  */
  YYSYMBOL_thf_unitary_formula = 98,       /* thf_unitary_formula  */
  YYSYMBOL_thf_quantified_formula = 99,    /* thf_quantified_formula  */
  YYSYMBOL_thf_quantification = 100,       /* thf_quantification  */
  YYSYMBOL_thf_variable_list = 101,        /* thf_variable_list  */
  YYSYMBOL_thf_typed_variable = 102,       /* thf_typed_variable  */
  YYSYMBOL_thf_unary_formula = 103,        /* thf_unary_formula  */
  YYSYMBOL_thf_prefix_unary = 104,         /* thf_prefix_unary  */
  YYSYMBOL_thf_infix_unary = 105,          /* thf_infix_unary  */
  YYSYMBOL_thf_atomic_formula = 106,       /* thf_atomic_formula  */
  YYSYMBOL_thf_plain_atomic = 107,         /* thf_plain_atomic  */
  YYSYMBOL_thf_defined_atomic = 108,       /* thf_defined_atomic  */
  YYSYMBOL_thf_defined_term = 109,         /* thf_defined_term  */
  YYSYMBOL_thf_defined_infix = 110,        /* thf_defined_infix  */
  YYSYMBOL_thf_system_atomic = 111,        /* thf_system_atomic  */
  YYSYMBOL_thf_let = 112,                  /* thf_let  */
  YYSYMBOL_thf_let_types = 113,            /* thf_let_types  */
  YYSYMBOL_thf_atom_typing_list = 114,     /* thf_atom_typing_list  */
  YYSYMBOL_thf_let_defns = 115,            /* thf_let_defns  */
  YYSYMBOL_thf_let_defn = 116,             /* thf_let_defn  */
  YYSYMBOL_thf_let_defn_list = 117,        /* thf_let_defn_list  */
  YYSYMBOL_thf_unitary_term = 118,         /* thf_unitary_term  */
  YYSYMBOL_thf_conn_term = 119,            /* thf_conn_term  */
  YYSYMBOL_thf_tuple = 120,                /* thf_tuple  */
  YYSYMBOL_thf_fof_function = 121,         /* thf_fof_function  */
  YYSYMBOL_thf_arguments = 122,            /* thf_arguments  */
  YYSYMBOL_thf_formula_list = 123,         /* thf_formula_list  */
  YYSYMBOL_thf_atom_typing = 124,          /* thf_atom_typing  */
  YYSYMBOL_thf_top_level_type = 125,       /* thf_top_level_type  */
  YYSYMBOL_thf_unitary_type = 126,         /* thf_unitary_type  */
  YYSYMBOL_thf_apply_type = 127,           /* thf_apply_type  */
  YYSYMBOL_thf_binary_type = 128,          /* thf_binary_type  */
  YYSYMBOL_thf_mapping_type = 129,         /* thf_mapping_type  */
  YYSYMBOL_thf_xprod_type = 130,           /* thf_xprod_type  */
  YYSYMBOL_thf_union_type = 131,           /* thf_union_type  */
  YYSYMBOL_thf_subtype = 132,              /* thf_subtype  */
  YYSYMBOL_thf_definition = 133,           /* thf_definition  */
  YYSYMBOL_thf_sequent = 134,              /* thf_sequent  */
  YYSYMBOL_tff_formula = 135,              /* tff_formula  */
  YYSYMBOL_tff_logic_formula = 136,        /* tff_logic_formula  */
  YYSYMBOL_tff_binary_formula = 137,       /* tff_binary_formula  */
  YYSYMBOL_tff_binary_pair = 138,          /* tff_binary_pair  */
  YYSYMBOL_tff_binary_list = 139,          /* tff_binary_list  */
  YYSYMBOL_tff_or_formula = 140,           /* tff_or_formula  */
  YYSYMBOL_tff_and_formula = 141,          /* tff_and_formula  */
  YYSYMBOL_tff_unit_formula = 142,         /* tff_unit_formula  */
  YYSYMBOL_tff_preunit_formula = 143,      /* tff_preunit_formula  */
  YYSYMBOL_tff_unitary_formula = 144,      /* tff_unitary_formula  */
  YYSYMBOL_txf_unitary_formula = 145,      /* txf_unitary_formula  */
  YYSYMBOL_tff_quantified_formula = 146,   /* tff_quantified_formula  */
  YYSYMBOL_tff_variable_list = 147,        /* tff_variable_list  */
  YYSYMBOL_tff_variable = 148,             /* tff_variable  */
  YYSYMBOL_tff_typed_variable = 149,       /* tff_typed_variable  */
  YYSYMBOL_tff_unary_formula = 150,        /* tff_unary_formula  */
  YYSYMBOL_tff_prefix_unary = 151,         /* tff_prefix_unary  */
  YYSYMBOL_tff_infix_unary = 152,          /* tff_infix_unary  */
  YYSYMBOL_tff_atomic_formula = 153,       /* tff_atomic_formula  */
  YYSYMBOL_tff_plain_atomic = 154,         /* tff_plain_atomic  */
  YYSYMBOL_tff_defined_atomic = 155,       /* tff_defined_atomic  */
  YYSYMBOL_tff_defined_plain = 156,        /* tff_defined_plain  */
  YYSYMBOL_tff_defined_infix = 157,        /* tff_defined_infix  */
  YYSYMBOL_tff_system_atomic = 158,        /* tff_system_atomic  */
  YYSYMBOL_txf_let = 159,                  /* txf_let  */
  YYSYMBOL_txf_let_types = 160,            /* txf_let_types  */
  YYSYMBOL_tff_atom_typing_list = 161,     /* tff_atom_typing_list  */
  YYSYMBOL_txf_let_defns = 162,            /* txf_let_defns  */
  YYSYMBOL_txf_let_defn = 163,             /* txf_let_defn  */
  YYSYMBOL_txf_let_LHS = 164,              /* txf_let_LHS  */
  YYSYMBOL_txf_let_defn_list = 165,        /* txf_let_defn_list  */
  YYSYMBOL_nxf_atom = 166,                 /* nxf_atom  */
  YYSYMBOL_tff_term = 167,                 /* tff_term  */
  YYSYMBOL_tff_unitary_term = 168,         /* tff_unitary_term  */
  YYSYMBOL_txf_tuple = 169,                /* txf_tuple  */
  YYSYMBOL_tff_arguments = 170,            /* tff_arguments  */
  YYSYMBOL_tff_atom_typing = 171,          /* tff_atom_typing  */
  YYSYMBOL_tff_top_level_type = 172,       /* tff_top_level_type  */
  YYSYMBOL_tff_non_atomic_type = 173,      /* tff_non_atomic_type  */
  YYSYMBOL_tf1_quantified_type = 174,      /* tf1_quantified_type  */
  YYSYMBOL_tff_monotype = 175,             /* tff_monotype  */
  YYSYMBOL_tff_unitary_type = 176,         /* tff_unitary_type  */
  YYSYMBOL_tff_atomic_type = 177,          /* tff_atomic_type  */
  YYSYMBOL_tff_type_arguments = 178,       /* tff_type_arguments  */
  YYSYMBOL_tff_mapping_type = 179,         /* tff_mapping_type  */
  YYSYMBOL_tff_xprod_type = 180,           /* tff_xprod_type  */
  YYSYMBOL_txf_tuple_type = 181,           /* txf_tuple_type  */
  YYSYMBOL_tff_type_list = 182,            /* tff_type_list  */
  YYSYMBOL_tff_subtype = 183,              /* tff_subtype  */
  YYSYMBOL_txf_definition = 184,           /* txf_definition  */
  YYSYMBOL_txf_sequent = 185,              /* txf_sequent  */
  YYSYMBOL_nhf_long_connective = 186,      /* nhf_long_connective  */
  YYSYMBOL_nhf_parameter_list = 187,       /* nhf_parameter_list  */
  YYSYMBOL_nhf_parameter = 188,            /* nhf_parameter  */
  YYSYMBOL_nhf_key_pair = 189,             /* nhf_key_pair  */
  YYSYMBOL_nxf_long_connective = 190,      /* nxf_long_connective  */
  YYSYMBOL_nxf_parameter_list = 191,       /* nxf_parameter_list  */
  YYSYMBOL_nxf_parameter = 192,            /* nxf_parameter  */
  YYSYMBOL_nxf_key_pair = 193,             /* nxf_key_pair  */
  YYSYMBOL_ntf_connective_name = 194,      /* ntf_connective_name  */
  YYSYMBOL_ntf_defined_connective = 195,   /* ntf_defined_connective  */
  YYSYMBOL_ntf_index = 196,                /* ntf_index  */
  YYSYMBOL_ntf_short_connective = 197,     /* ntf_short_connective  */
  YYSYMBOL_tcf_formula = 198,              /* tcf_formula  */
  YYSYMBOL_tcf_logic_formula = 199,        /* tcf_logic_formula  */
  YYSYMBOL_tcf_quantified_formula = 200,   /* tcf_quantified_formula  */
  YYSYMBOL_fof_formula = 201,              /* fof_formula  */
  YYSYMBOL_fof_logic_formula = 202,        /* fof_logic_formula  */
  YYSYMBOL_fof_binary_formula = 203,       /* fof_binary_formula  */
  YYSYMBOL_fof_binary_pair = 204,          /* fof_binary_pair  */
  YYSYMBOL_fof_binary_list = 205,          /* fof_binary_list  */
  YYSYMBOL_fof_or_formula = 206,           /* fof_or_formula  */
  YYSYMBOL_fof_and_formula = 207,          /* fof_and_formula  */
  YYSYMBOL_fof_unary_formula = 208,        /* fof_unary_formula  */
  YYSYMBOL_fof_infix_unary = 209,          /* fof_infix_unary  */
  YYSYMBOL_fof_unit_formula = 210,         /* fof_unit_formula  */
  YYSYMBOL_fof_unitary_formula = 211,      /* fof_unitary_formula  */
  YYSYMBOL_fof_quantified_formula = 212,   /* fof_quantified_formula  */
  YYSYMBOL_fof_variable_list = 213,        /* fof_variable_list  */
  YYSYMBOL_fof_atomic_formula = 214,       /* fof_atomic_formula  */
  YYSYMBOL_fof_plain_atomic_formula = 215, /* fof_plain_atomic_formula  */
  YYSYMBOL_fof_defined_atomic_formula = 216, /* fof_defined_atomic_formula  */
  YYSYMBOL_fof_defined_plain_formula = 217, /* fof_defined_plain_formula  */
  YYSYMBOL_fof_defined_infix_formula = 218, /* fof_defined_infix_formula  */
  YYSYMBOL_fof_system_atomic_formula = 219, /* fof_system_atomic_formula  */
  YYSYMBOL_fof_plain_term = 220,           /* fof_plain_term  */
  YYSYMBOL_fof_defined_term = 221,         /* fof_defined_term  */
  YYSYMBOL_fof_defined_atomic_term = 222,  /* fof_defined_atomic_term  */
  YYSYMBOL_fof_defined_plain_term = 223,   /* fof_defined_plain_term  */
  YYSYMBOL_fof_system_term = 224,          /* fof_system_term  */
  YYSYMBOL_fof_arguments = 225,            /* fof_arguments  */
  YYSYMBOL_fof_term = 226,                 /* fof_term  */
  YYSYMBOL_fof_function_term = 227,        /* fof_function_term  */
  YYSYMBOL_fof_sequent = 228,              /* fof_sequent  */
  YYSYMBOL_fof_formula_tuple = 229,        /* fof_formula_tuple  */
  YYSYMBOL_fof_formula_tuple_list = 230,   /* fof_formula_tuple_list  */
  YYSYMBOL_cnf_formula = 231,              /* cnf_formula  */
  YYSYMBOL_cnf_disjunction = 232,          /* cnf_disjunction  */
  YYSYMBOL_cnf_literal = 233,              /* cnf_literal  */
  YYSYMBOL_thf_quantifier = 234,           /* thf_quantifier  */
  YYSYMBOL_thf_unary_connective = 235,     /* thf_unary_connective  */
  YYSYMBOL_th0_quantifier = 236,           /* th0_quantifier  */
  YYSYMBOL_type_quantifier = 237,          /* type_quantifier  */
  YYSYMBOL_subtype_sign = 238,             /* subtype_sign  */
  YYSYMBOL_tff_unary_connective = 239,     /* tff_unary_connective  */
  YYSYMBOL_tff_quantifier = 240,           /* tff_quantifier  */
  YYSYMBOL_fof_quantifier = 241,           /* fof_quantifier  */
  YYSYMBOL_nonassoc_connective = 242,      /* nonassoc_connective  */
  YYSYMBOL_assoc_connective = 243,         /* assoc_connective  */
  YYSYMBOL_unary_connective = 244,         /* unary_connective  */
  YYSYMBOL_gentzen_arrow = 245,            /* gentzen_arrow  */
  YYSYMBOL_assignment = 246,               /* assignment  */
  YYSYMBOL_identical = 247,                /* identical  */
  YYSYMBOL_typeable_atom = 248,            /* typeable_atom  */
  YYSYMBOL_atomic_type = 249,              /* atomic_type  */
  YYSYMBOL_type_constant = 250,            /* type_constant  */
  YYSYMBOL_type_functor = 251,             /* type_functor  */
  YYSYMBOL_defined_type = 252,             /* defined_type  */
  YYSYMBOL_system_type = 253,              /* system_type  */
  YYSYMBOL_defined_infix_pred = 254,       /* defined_infix_pred  */
  YYSYMBOL_infix_equality = 255,           /* infix_equality  */
  YYSYMBOL_infix_inequality = 256,         /* infix_inequality  */
  YYSYMBOL_constant = 257,                 /* constant  */
  YYSYMBOL_functor = 258,                  /* functor  */
  YYSYMBOL_defined_constant = 259,         /* defined_constant  */
  YYSYMBOL_defined_functor = 260,          /* defined_functor  */
  YYSYMBOL_system_constant = 261,          /* system_constant  */
  YYSYMBOL_system_functor = 262,           /* system_functor  */
  YYSYMBOL_th1_defined_term = 263,         /* th1_defined_term  */
  YYSYMBOL_defined_term = 264,             /* defined_term  */
  YYSYMBOL_variable = 265,                 /* variable  */
  YYSYMBOL_source = 266,                   /* source  */
  YYSYMBOL_sources = 267,                  /* sources  */
  YYSYMBOL_dag_source = 268,               /* dag_source  */
  YYSYMBOL_inference_record = 269,         /* inference_record  */
  YYSYMBOL_inference_rule = 270,           /* inference_rule  */
  YYSYMBOL_internal_source = 271,          /* internal_source  */
  YYSYMBOL_intro_type = 272,               /* intro_type  */
  YYSYMBOL_external_source = 273,          /* external_source  */
  YYSYMBOL_file_source = 274,              /* file_source  */
  YYSYMBOL_file_info = 275,                /* file_info  */
  YYSYMBOL_parents = 276,                  /* parents  */
  YYSYMBOL_parent_list = 277,              /* parent_list  */
  YYSYMBOL_parent_info = 278,              /* parent_info  */
  YYSYMBOL_parent_details = 279,           /* parent_details  */
  YYSYMBOL_optional_info = 280,            /* optional_info  */
  YYSYMBOL_useful_info = 281,              /* useful_info  */
  YYSYMBOL_include = 282,                  /* include  */
  YYSYMBOL_include_optionals = 283,        /* include_optionals  */
  YYSYMBOL_formula_selection = 284,        /* formula_selection  */
  YYSYMBOL_name_list = 285,                /* name_list  */
  YYSYMBOL_space_name = 286,               /* space_name  */
  YYSYMBOL_general_term = 287,             /* general_term  */
  YYSYMBOL_general_data = 288,             /* general_data  */
  YYSYMBOL_general_function = 289,         /* general_function  */
  YYSYMBOL_formula_data = 290,             /* formula_data  */
  YYSYMBOL_general_list = 291,             /* general_list  */
  YYSYMBOL_general_terms = 292,            /* general_terms  */
  YYSYMBOL_name = 293,                     /* name  */
  YYSYMBOL_atomic_word = 294,              /* atomic_word  */
  YYSYMBOL_atomic_defined_word = 295,      /* atomic_defined_word  */
  YYSYMBOL_atomic_system_word = 296,       /* atomic_system_word  */
  YYSYMBOL_number = 297,                   /* number  */
  YYSYMBOL_file_name = 298,                /* file_name  */
  YYSYMBOL_nothing = 299                   /* nothing  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3762

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  225
/* YYNRULES -- Number of rules.  */
#define YYNRULES  449
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  826

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   329


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   475,   475,   476,   479,   480,   483,   484,   485,   486,
     487,   488,   491,   494,   497,   500,   503,   506,   509,   512,
     513,   516,   517,   518,   519,   520,   521,   522,   523,   526,
     527,   528,   531,   532,   533,   534,   535,   536,   539,   540,
     541,   544,   547,   548,   549,   552,   553,   556,   557,   560,
     561,   564,   565,   566,   569,   570,   573,   574,   575,   576,
     579,   582,   585,   586,   589,   592,   593,   596,   599,   602,
     603,   604,   605,   608,   609,   612,   613,   614,   615,   616,
     619,   620,   623,   626,   629,   632,   633,   636,   637,   640,
     641,   644,   647,   648,   651,   652,   653,   656,   657,   658,
     659,   660,   663,   664,   667,   668,   669,   672,   675,   676,
     679,   680,   683,   684,   685,   688,   691,   694,   695,   696,
     699,   700,   703,   704,   707,   708,   711,   714,   717,   720,
     721,   722,   725,   726,   727,   728,   729,   730,   733,   734,
     737,   740,   741,   744,   745,   748,   749,   752,   753,   754,
     757,   758,   761,   762,   763,   764,   767,   770,   773,   774,
     777,   778,   781,   784,   785,   788,   791,   794,   795,   796,
     799,   800,   803,   806,   807,   808,   809,   812,   815,   816,
     819,   822,   823,   826,   827,   830,   831,   834,   837,   838,
     841,   842,   845,   848,   849,   850,   853,   854,   855,   856,
     857,   860,   861,   864,   865,   868,   869,   872,   873,   876,
     877,   878,   881,   884,   885,   886,   889,   890,   893,   894,
     895,   896,   897,   898,   901,   902,   905,   908,   909,   912,
     915,   916,   919,   922,   925,   928,   929,   932,   933,   936,
     937,   940,   943,   944,   947,   948,   951,   952,   955,   958,
     959,   962,   965,   968,   969,   970,   971,   974,   975,   978,
     979,   982,   985,   986,   989,   990,   991,   994,   995,   998,
    1001,  1002,  1005,  1006,  1009,  1010,  1013,  1014,  1017,  1020,
    1021,  1024,  1025,  1026,  1029,  1032,  1033,  1036,  1037,  1038,
    1041,  1044,  1045,  1048,  1051,  1054,  1057,  1058,  1061,  1062,
    1065,  1068,  1069,  1072,  1073,  1076,  1077,  1080,  1081,  1084,
    1085,  1086,  1089,  1090,  1093,  1094,  1097,  1098,  1101,  1102,
    1105,  1106,  1109,  1110,  1111,  1112,  1115,  1116,  1117,  1120,
    1121,  1124,  1125,  1126,  1129,  1130,  1133,  1136,  1137,  1140,
    1141,  1144,  1145,  1148,  1149,  1150,  1151,  1152,  1153,  1156,
    1157,  1160,  1163,  1166,  1169,  1172,  1173,  1176,  1177,  1178,
    1181,  1184,  1187,  1190,  1193,  1196,  1199,  1202,  1205,  1208,
    1211,  1214,  1217,  1220,  1221,  1222,  1223,  1224,  1227,  1228,
    1231,  1234,  1235,  1236,  1237,  1240,  1241,  1244,  1245,  1248,
    1251,  1254,  1257,  1260,  1263,  1266,  1267,  1270,  1271,  1274,
    1275,  1278,  1281,  1282,  1285,  1286,  1289,  1292,  1295,  1296,
    1297,  1300,  1301,  1304,  1305,  1308,  1311,  1312,  1313,  1316,
    1317,  1318,  1319,  1320,  1321,  1324,  1327,  1328,  1329,  1330,
    1331,  1334,  1335,  1338,  1339,  1342,  1343,  1346,  1347,  1348,
    1349,  1350,  1351,  1354,  1357,  1360,  1361,  1362,  1365,  1368
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "AMPERSAND",
  "AT_AT_SIGN_MINUS", "AT_AT_SIGN_PLUS", "AT_SIGN", "AT_SIGN_EQUALS",
  "AT_SIGN_MINUS", "AT_SIGN_PLUS", "CARET", "COLON", "COLON_EQUALS",
  "COMMA", "EQUALS", "EQUALS_EQUALS", "EQUALS_GREATER", "EXCLAMATION",
  "EXCLAMATION_EQUALS", "EXCLAMATION_EXCLAMATION", "EXCLAMATION_GREATER",
  "LBRACE", "LBRKT", "LESS_EQUALS", "LESS_EQUALS_GREATER", "LESS_LESS",
  "LESS_TILDE_GREATER", "LPAREN", "MINUS", "MINUS_MINUS_GREATER", "PERIOD",
  "QUESTION", "QUESTION_QUESTION", "QUESTION_STAR", "RBRACE", "RBRKT",
  "RPAREN", "STAR", "TILDE", "TILDE_AMPERSAND", "TILDE_VLINE", "VLINE",
  "_DLR_cnf", "_DLR_fof", "_DLR_fot", "_DLR_let", "_DLR_tff", "_DLR_thf",
  "_LIT_cnf", "_LIT_file", "_LIT_fof", "_LIT_include", "_LIT_inference",
  "_LIT_introduced", "_LIT_tcf", "_LIT_tff", "_LIT_thf", "_LIT_tpi",
  "arrow", "back_quoted", "distinct_object", "dollar_dollar_word",
  "dollar_word", "hash", "integer", "less_sign", "lower_word", "plus",
  "rational", "real", "single_quoted", "slash", "slosh", "unrecognized",
  "upper_word", "$accept", "TPTP_file", "TPTP_input", "annotated_formula",
  "tpi_annotated", "tpi_formula", "thf_annotated", "tff_annotated",
  "tcf_annotated", "fof_annotated", "cnf_annotated", "annotations",
  "formula_role", "thf_formula", "thf_logic_formula", "thf_binary_formula",
  "thf_binary_pair", "thf_binary_list", "thf_or_formula",
  "thf_and_formula", "thf_apply_formula", "thf_unit_formula",
  "thf_preunit_formula", "thf_unitary_formula", "thf_quantified_formula",
  "thf_quantification", "thf_variable_list", "thf_typed_variable",
  "thf_unary_formula", "thf_prefix_unary", "thf_infix_unary",
  "thf_atomic_formula", "thf_plain_atomic", "thf_defined_atomic",
  "thf_defined_term", "thf_defined_infix", "thf_system_atomic", "thf_let",
  "thf_let_types", "thf_atom_typing_list", "thf_let_defns", "thf_let_defn",
  "thf_let_defn_list", "thf_unitary_term", "thf_conn_term", "thf_tuple",
  "thf_fof_function", "thf_arguments", "thf_formula_list",
  "thf_atom_typing", "thf_top_level_type", "thf_unitary_type",
  "thf_apply_type", "thf_binary_type", "thf_mapping_type",
  "thf_xprod_type", "thf_union_type", "thf_subtype", "thf_definition",
  "thf_sequent", "tff_formula", "tff_logic_formula", "tff_binary_formula",
  "tff_binary_pair", "tff_binary_list", "tff_or_formula",
  "tff_and_formula", "tff_unit_formula", "tff_preunit_formula",
  "tff_unitary_formula", "txf_unitary_formula", "tff_quantified_formula",
  "tff_variable_list", "tff_variable", "tff_typed_variable",
  "tff_unary_formula", "tff_prefix_unary", "tff_infix_unary",
  "tff_atomic_formula", "tff_plain_atomic", "tff_defined_atomic",
  "tff_defined_plain", "tff_defined_infix", "tff_system_atomic", "txf_let",
  "txf_let_types", "tff_atom_typing_list", "txf_let_defns", "txf_let_defn",
  "txf_let_LHS", "txf_let_defn_list", "nxf_atom", "tff_term",
  "tff_unitary_term", "txf_tuple", "tff_arguments", "tff_atom_typing",
  "tff_top_level_type", "tff_non_atomic_type", "tf1_quantified_type",
  "tff_monotype", "tff_unitary_type", "tff_atomic_type",
  "tff_type_arguments", "tff_mapping_type", "tff_xprod_type",
  "txf_tuple_type", "tff_type_list", "tff_subtype", "txf_definition",
  "txf_sequent", "nhf_long_connective", "nhf_parameter_list",
  "nhf_parameter", "nhf_key_pair", "nxf_long_connective",
  "nxf_parameter_list", "nxf_parameter", "nxf_key_pair",
  "ntf_connective_name", "ntf_defined_connective", "ntf_index",
  "ntf_short_connective", "tcf_formula", "tcf_logic_formula",
  "tcf_quantified_formula", "fof_formula", "fof_logic_formula",
  "fof_binary_formula", "fof_binary_pair", "fof_binary_list",
  "fof_or_formula", "fof_and_formula", "fof_unary_formula",
  "fof_infix_unary", "fof_unit_formula", "fof_unitary_formula",
  "fof_quantified_formula", "fof_variable_list", "fof_atomic_formula",
  "fof_plain_atomic_formula", "fof_defined_atomic_formula",
  "fof_defined_plain_formula", "fof_defined_infix_formula",
  "fof_system_atomic_formula", "fof_plain_term", "fof_defined_term",
  "fof_defined_atomic_term", "fof_defined_plain_term", "fof_system_term",
  "fof_arguments", "fof_term", "fof_function_term", "fof_sequent",
  "fof_formula_tuple", "fof_formula_tuple_list", "cnf_formula",
  "cnf_disjunction", "cnf_literal", "thf_quantifier",
  "thf_unary_connective", "th0_quantifier", "type_quantifier",
  "subtype_sign", "tff_unary_connective", "tff_quantifier",
  "fof_quantifier", "nonassoc_connective", "assoc_connective",
  "unary_connective", "gentzen_arrow", "assignment", "identical",
  "typeable_atom", "atomic_type", "type_constant", "type_functor",
  "defined_type", "system_type", "defined_infix_pred", "infix_equality",
  "infix_inequality", "constant", "functor", "defined_constant",
  "defined_functor", "system_constant", "system_functor",
  "th1_defined_term", "defined_term", "variable", "source", "sources",
  "dag_source", "inference_record", "inference_rule", "internal_source",
  "intro_type", "external_source", "file_source", "file_info", "parents",
  "parent_list", "parent_info", "parent_details", "optional_info",
  "useful_info", "include", "include_optionals", "formula_selection",
  "name_list", "space_name", "general_term", "general_data",
  "general_function", "formula_data", "general_list", "general_terms",
  "name", "atomic_word", "atomic_defined_word", "atomic_system_word",
  "number", "file_name", "nothing", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-571)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-364)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -571,   484,  -571,    61,    88,    95,   113,   118,   126,   152,
    -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,   698,
     698,   732,   698,   698,   698,   698,  -571,  -571,  -571,  -571,
    -571,  -571,  -571,   181,  -571,   183,  -571,   200,   214,   230,
     246,   248,   111,   111,   156,   251,  -571,   111,   111,   111,
     111,   238,   266,   272,   280,   263,   321,   698,  -571,   327,
     316,   343,   348,   359,   360,  2403,  2403,  2403,  2403,  3588,
    3408,   345,   365,   698,  -571,  3502,  3308,  1353,  3408,  3565,
     354,   357,   367,   368,   384,  -571,  -571,  -571,  -571,  -571,
    -571,  -571,   401,  -571,  -571,  -571,   396,  -571,  -571,  -571,
    -571,  3588,  3638,  -571,  -571,  -571,  -571,  -571,  -571,  -571,
    -571,  -571,  -571,   275,  -571,  -571,   432,   493,   532,  -571,
     412,   398,  -571,  -571,   426,  -571,   429,  -571,   436,  -571,
    -571,  -571,  -571,  -571,  -571,  -571,  3448,  3408,  -571,  -571,
     412,  -571,  -571,  -571,  -571,   427,   468,   190,  -571,   901,
     219,  -571,  -571,  -571,   445,   454,  3475,  -571,   698,  -571,
    -571,   455,  3615,   147,  -571,   412,  -571,  -571,  -571,   474,
     475,    76,  2132,  2374,   460,  -571,   469,   412,  -571,  -571,
    -571,  -571,   473,   498,  1473,   267,  -571,  -571,   303,  -571,
    -571,   395,  -571,  -571,  -571,   315,  -571,  -571,  -571,   532,
     445,  -571,  -571,  -571,  -571,   503,  -571,  2638,   494,  -571,
    -571,   474,   490,  -571,   186,   504,   495,   506,  -571,   509,
    -571,   546,   496,  -571,  -571,  -571,  -571,  -571,  -571,  -571,
    -571,    76,  2311,  2737,  -571,  -571,   516,   412,  -571,  -571,
    -571,  -571,   489,   542,   553,   699,   491,  -571,  3072,   425,
    -571,  -571,   451,  -571,  -571,  -571,   477,  -571,  -571,   532,
     445,  -571,  -571,   182,  -571,  -571,   511,   486,  -571,  -571,
    -571,  -571,  -571,   549,  3140,  -571,  -571,  -571,  -571,   558,
     490,   186,   555,   495,   560,  -571,   562,  -571,  -571,   567,
     412,  -571,  -571,   583,   573,  3588,  3408,  3688,  3308,  1353,
    2403,  2403,   580,  3688,  -571,   595,  -571,  -571,  3688,  -571,
    3688,  1036,   591,  -571,  3665,  3688,  3688,  3688,  3475,  -571,
     615,   594,   612,   625,   627,  3475,  3475,  3475,  -571,  -571,
    -571,  -571,  -571,  -571,  3475,  3475,  -571,   645,   596,  -571,
    -571,  -571,  -571,   596,   636,   638,  1695,   637,    59,  -571,
    -571,  -571,  3258,   634,  -571,  -571,   662,   151,   641,  -571,
    -571,   584,   642,   643,  1108,   619,   647,  3358,  3358,  3358,
    3358,  3358,  -571,  3358,  2036,  2036,   659,   657,   656,  3258,
    -571,  -571,  -571,  -571,  -571,   596,  -571,  1384,  3358,  3358,
    3358,    78,  2915,  -571,   678,   658,  -571,  -571,  -571,  -571,
     660,   668,   671,  3140,  -571,  -571,   558,  -571,  -571,  1289,
     672,  3072,  3072,  3072,  3072,  3072,  3072,  3072,  -571,  -571,
    -571,   632,  -571,  -571,  3072,  1634,  1634,   687,  1178,  1178,
    1178,  1178,  1178,   596,  2915,  -571,  -571,  -571,  -571,  -571,
    3072,  1384,  3072,  3072,  3072,   676,  2403,  -571,   677,   680,
    -571,  -571,  -571,   681,   682,   683,  -571,   685,  -571,   691,
    -571,  -571,  1036,   667,   701,   702,   718,  -571,  -571,  -571,
    -571,  -571,  -571,   703,  -571,   705,   721,   707,   712,  3475,
    -571,  -571,  -571,   719,  -571,  -571,  -571,  -571,  -571,  -571,
     723,   743,   724,   748,  -571,   752,  -571,   744,  1695,  1695,
    -571,  -571,  -571,   715,   717,  -571,  -571,   754,  -571,   750,
    -571,  -571,  -571,  -571,  -571,   531,  -571,  -571,  3358,  -571,
    -571,   633,   502,   502,  -571,   765,  -571,  -571,  -571,  -571,
     756,  -571,  -571,  -571,   635,  -571,  -571,  -571,  -571,  -571,
    -571,  -571,    71,  1960,  3358,  -571,  -571,  -571,  -571,  -571,
    3358,   753,   745,  -571,  -571,  -571,  -571,  -571,   758,   760,
     769,  2808,  -571,  3072,  -571,   640,  -571,  -571,   551,   551,
     779,  -571,   771,  -571,  -571,  -571,  -571,  -571,  -571,  -571,
    -571,    71,  2990,  2588,  -571,  -571,  -571,  -571,  -571,  2588,
    -571,  -571,   751,  -571,  -571,  -571,  -571,   772,   793,   797,
     778,   553,   807,   809,  -571,   751,  -571,  -571,  -571,   780,
    -571,   784,   787,   798,  -571,  -571,  -571,  -571,  -571,  -571,
    -571,  -571,   818,   799,   732,   732,   732,   810,  -571,  -571,
    -571,  -571,  3688,  -571,  -571,  -571,  -571,   822,   596,   826,
     596,   844,  -571,   827,   804,   806,    50,   808,   184,   844,
     596,   844,  2036,   831,  -571,   812,   836,  -571,  -571,  -571,
     817,   843,  1155,  -571,   832,   833,  -571,   847,  -571,  -571,
    -571,  1826,   831,  -571,   834,   860,  -571,  -571,  -571,   840,
     863,  3208,  -571,   841,   873,   596,  3072,  -571,  -571,  -571,
    -571,  -571,  1036,  -571,   874,   875,  -571,   879,  -571,  -571,
    -571,  -571,  3475,  -571,  3529,  -571,   844,  -571,  1695,  -571,
    -571,   844,  -571,  -571,   844,  -571,   859,   882,   864,  -571,
     867,   531,  -571,   502,  1960,  -571,   889,  -571,   895,  -571,
    -571,  -571,  3358,   878,   883,  -571,   881,  2808,  -571,   551,
    2311,   895,   896,  -571,  -571,  -571,  -571,  -571,  -571,   698,
     876,  -571,   810,   810,  -571,  -571,   808,  -571,  -571,  -571,
     908,   844,  -571,  -571,  -571,  -571,   911,   907,   891,   430,
    3358,  -571,  3358,  -571,  -571,  -571,  -571,   240,   916,   909,
    3072,  3072,  -571,  -571,   917,   923,  1848,  -571,  1261,  -571,
     910,  -571,  3072,  -571,  -571,   912,   925,   925,  1850,  -571,
    -571,  -571,  -571,  -571,  -571,  -571,   777,   913,   919,  1850,
     921,  -571,   934,   930,   953,  -571,  -571,   931,  -571,  2403,
    -571,  -571,  -571,  1036,  -571,  -571
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       3,     4,    11,     6,     7,     8,     9,    10,     5,     0,
       0,     0,     0,     0,     0,     0,   438,   439,   440,   442,
     436,   437,   441,     0,   435,     0,   448,   449,     0,     0,
       0,     0,     0,     0,     0,     0,   408,     0,     0,     0,
       0,    22,    23,    24,    21,     0,     0,     0,   412,   409,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   413,     0,   407,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   423,   445,   446,   447,   380,
     421,    26,   416,   420,   424,   418,   419,   422,    27,    28,
      25,     0,     0,   379,   444,   443,   325,   322,   287,   288,
     291,   292,   289,   290,   310,   299,   293,   295,     0,   307,
     449,   318,   320,   296,   367,   301,   369,   303,   371,   298,
     308,   368,   370,   372,   378,   341,     0,     0,   342,   351,
     449,   262,   264,   267,   268,   270,   271,   280,   277,     0,
     279,   281,   282,   263,     0,     0,     0,   411,     0,   410,
     415,     0,     0,   379,   258,   449,   257,   259,   260,     0,
     296,     0,     0,     0,     0,   340,     0,   449,   129,   134,
     138,   139,   141,   142,     0,   147,   154,   152,   148,   163,
     164,   153,   167,   168,   172,   149,   169,   176,   175,     0,
     198,   130,   131,   136,   137,     0,   338,     0,     0,   339,
     337,   357,     0,   359,   170,   367,   173,   369,   178,   371,
     197,   156,   372,   376,   375,   377,   333,   332,   331,   373,
     334,     0,     0,     0,   374,   335,     0,   449,    29,    34,
      38,    39,    42,    43,    44,     0,    51,    56,     0,    52,
      65,    66,    57,    69,    70,    76,    53,    71,    79,     0,
      74,    72,    30,     0,    40,   117,   118,   119,    31,    36,
      37,    78,   330,     0,     0,   327,   328,   326,   329,   357,
       0,    73,   367,    75,   369,    83,   371,    81,    80,    58,
     449,    13,   431,   433,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   323,     0,   365,   366,     0,   364,
       0,     0,     0,    20,     0,     0,     0,     0,     0,   314,
     316,     0,     0,     0,     0,     0,     0,     0,   344,   345,
     343,   346,   348,   347,     0,     0,   352,     0,     0,   280,
     276,   279,   414,     0,     0,     0,     0,     0,     0,   249,
     251,   250,     0,     0,   201,   193,   203,   195,     0,   170,
     173,   194,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   354,     0,     0,     0,     0,     0,     0,     0,
     165,   150,   151,   153,   156,     0,   336,     0,     0,     0,
       0,     0,     0,   102,   108,     0,    73,    75,   350,   349,
       0,     0,     0,   101,    97,    98,     0,    99,   100,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    60,    51,
      52,    57,    53,    74,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    67,    54,    55,    57,    58,
       0,     0,     0,     0,     0,     0,     0,   432,     0,     0,
     309,   300,   311,     0,     0,     0,   417,     0,   319,     0,
     294,   278,     0,   438,   439,   440,   449,   381,   388,   382,
     383,   393,   387,     0,   321,     0,   305,     0,     0,     0,
     315,   283,   313,     0,   273,   275,   274,   272,   269,   312,
       0,   285,     0,   158,   160,   161,   206,     0,     0,     0,
     205,   208,   210,     0,   207,   209,   223,     0,   218,   360,
     219,   220,   361,   362,   255,     0,   242,   253,     0,   202,
     256,   155,     0,     0,   356,     0,   181,   355,   367,   254,
       0,   144,   147,   148,   153,   149,   198,   146,   145,   143,
     140,   233,     0,     0,     0,   196,   177,   199,   166,   234,
       0,     0,     0,   357,   232,   358,   369,   363,     0,     0,
       0,     0,   235,     0,   103,    59,    77,   111,     0,     0,
       0,    85,     0,    46,    48,    50,    47,    49,    45,    41,
     127,     0,     0,     0,    94,    82,    95,    68,   128,     0,
     115,   122,   120,   121,   124,   123,   125,     0,    62,     0,
       0,   116,     0,   115,   110,   112,   114,   113,   126,     0,
     107,     0,     0,     0,   434,   429,   428,   430,   427,   426,
     425,   324,   385,     0,     0,     0,     0,     0,    19,   405,
      18,   297,     0,   302,   304,   317,    17,     0,     0,     0,
       0,     0,    16,   230,     0,     0,     0,   216,     0,     0,
       0,     0,     0,     0,   248,     0,   244,   247,   246,   204,
       0,   183,     0,    15,     0,     0,   155,     0,   171,   174,
     179,     0,     0,   241,     0,   237,   240,   239,   109,     0,
      87,     0,    14,     0,     0,     0,     0,    59,   106,   104,
     105,    12,     0,   384,   449,     0,   390,     0,   392,   404,
     406,   306,     0,   286,     0,   159,     0,   162,     0,   229,
     211,     0,   222,   217,     0,   226,     0,   224,     0,   252,
       0,     0,   182,     0,     0,   188,     0,   185,     0,   189,
     200,   192,     0,     0,     0,   101,     0,     0,    86,     0,
       0,     0,     0,    89,    96,    61,    63,    64,   386,     0,
       0,   396,     0,     0,   284,   261,     0,   231,   227,   228,
       0,     0,   221,   243,   245,   184,   167,   190,     0,   195,
       0,   353,     0,   157,   236,   238,    88,   108,    92,     0,
       0,     0,   395,   394,     0,     0,     0,   225,     0,   186,
       0,   187,     0,    90,    91,     0,     0,     0,     0,   215,
     212,   213,   191,   180,    93,    84,     0,     0,     0,     0,
       0,   397,   449,     0,   399,   389,   391,     0,   214,     0,
     401,   403,   398,     0,   402,   400
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,
    -571,   305,   588,   670,    30,  -571,  -571,  -571,  -571,  -571,
    -403,    17,  -571,   547,  -571,  -571,   282,  -571,   569,  -211,
    -571,   609,  -571,  -571,  -571,   616,  -571,  -571,  -571,   231,
    -571,   290,   180,  -107,  -571,   411,  -571,  -119,  -268,  -214,
     302,    66,  -571,  -571,  -356,  -571,  -571,  -571,  -504,  -571,
     692,   -42,  -571,  -571,  -571,  -571,  -571,  -270,  -571,  -185,
    -571,  -571,  -349,  -571,  -571,  -251,   782,  -571,  -133,  -570,
    -571,  -571,  -241,  -571,  -571,  -571,   268,  -571,   330,  -571,
     207,  -571,  -321,  -331,     0,  -239,   -67,   650,   499,   211,
    -571,  -478,   366,   241,   201,  -571,  -571,   293,  -571,  -443,
    -571,  -571,   269,  -571,  -571,  -571,   283,  -571,  -571,  -198,
    -571,  -492,  1090,  -571,   299,  -571,   -11,   -58,  -571,  -571,
    -571,  -571,  -571,  -136,    -5,  -125,  -111,  -571,   370,    -7,
    -571,  -571,  -571,  -571,  -571,  -206,  -571,  -571,  -174,  -149,
    -236,   -46,  -571,   877,   673,   534,   198,  -571,   697,  -571,
    -148,  -571,  -311,   736,  -571,  1275,   -12,   -28,  -571,  2346,
     -89,   291,  -220,     6,   -22,  -571,  -571,  -571,  -571,  -124,
     -47,   -29,   564,   749,  1231,  1416,  1757,  1914,  -571,  2189,
     -26,  -301,   326,  -571,  -571,  -571,  -571,  -571,  -571,  -571,
    -571,   239,   225,  -571,  -571,  -571,  -420,  -571,  -571,  -571,
     884,  -571,   -50,  -571,  -571,  -571,  -524,  -242,     4,   -19,
    -141,    37,   -54,   431,   -30
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    10,    11,    12,   290,    13,    14,    15,    16,
      17,   312,    55,   237,   394,   239,   240,   241,   242,   243,
     244,   245,   435,   246,   247,   248,   597,   598,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   570,   679,
     742,   778,   779,   259,   401,   423,   261,   609,   395,   262,
     604,   263,   606,   264,   265,   266,   267,   268,   269,   270,
     177,   355,   179,   180,   181,   182,   183,   184,   380,   185,
     186,   187,   492,   493,   494,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   525,   660,   726,   767,   728,
     768,   198,   356,   199,   357,   358,   344,   643,   501,   502,
     800,   503,   504,   718,   505,   648,   506,   644,   202,   203,
     204,   271,   674,   675,   676,   205,   655,   656,   657,   348,
     349,   658,   272,   165,   166,   167,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   490,   152,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     475,   118,   119,   153,   154,   321,   168,   121,   122,   273,
     274,   275,   276,   387,   207,   277,   209,   404,   405,   278,
     376,   780,   373,   169,   212,   508,   509,   510,   213,   308,
     407,   408,   396,   282,   397,   284,   285,   286,   287,   288,
     130,   622,   623,   467,   468,   695,   469,   697,   470,   471,
     750,   807,   813,   814,   820,   628,   699,    18,    45,    59,
      71,   159,   293,    92,    93,    94,    95,   294,   472,   131,
     132,   133,   134,    37,   313
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      34,    34,    36,    34,    34,    34,    34,    46,   164,   201,
     466,    97,    97,    97,    97,    91,    98,    99,   100,   402,
     339,   646,   381,    33,    35,    97,    38,    39,    40,    41,
     350,   340,   424,   391,   178,   507,   552,   601,    34,    90,
      90,    90,    90,   546,   548,   341,    96,    96,    96,    96,
     221,   289,   541,    90,    34,   280,   305,   673,   155,   457,
      96,    72,   107,   437,   106,   337,   155,   291,   107,   677,
     106,   309,   654,   593,   383,   374,   200,   160,   320,   322,
     477,   478,   211,   279,   607,   403,   515,   711,    19,   310,
     350,   450,   725,   516,   107,   304,   106,   531,   537,   538,
     539,   540,   450,   700,   450,   561,   347,   238,   649,   450,
     450,   450,   562,   222,   222,    20,   533,   533,   533,   533,
     533,   335,    21,   451,   155,   155,   535,   535,   535,   535,
     535,   363,   104,   105,   451,   425,   451,   104,   105,    34,
      22,   451,   451,   451,   155,    23,   221,   221,   452,   558,
     559,   560,   309,    24,   766,   107,   371,   106,  -356,   452,
      51,   452,    72,    52,    53,  -198,   452,   452,   452,  -198,
     375,   427,  -356,   200,   610,   610,   610,    54,    57,    25,
     336,   384,   532,   532,   532,   532,   532,   507,   507,   339,
     339,   339,   437,    58,    42,   571,    43,  -355,   339,   339,
     484,   485,   486,  -265,   614,   513,   289,   289,   351,   487,
     488,  -355,   309,    44,   341,   341,   341,   417,   725,   428,
     713,   714,   289,   341,   341,  -265,  -265,    47,   700,   700,
     426,   201,  -266,   673,   534,   534,   534,   534,   534,   406,
     429,   545,   545,    48,   403,   677,    97,    97,   439,   430,
     456,   453,   771,   563,  -266,  -266,   178,   305,   309,    49,
     322,    50,   460,   400,   461,   418,    65,   120,   351,   476,
     476,   476,   221,   289,    90,    90,    69,   280,   654,   659,
    -132,    96,    96,   601,   155,   449,   403,    60,   107,  -309,
     106,   705,    34,  -309,    66,   678,   459,   526,   200,   302,
      67,   716,  -132,  -132,   211,   279,   155,   107,    68,   106,
     363,   665,   491,   155,   155,   155,  -133,   495,   585,   587,
     511,   719,   155,   155,   611,   612,   221,   512,  -135,   238,
     607,   817,   784,   785,    70,   222,   222,   551,  -133,  -133,
      73,   221,   221,   221,   221,   221,    74,   221,   547,   547,
    -135,  -135,   200,   221,   680,   402,    75,   513,   513,   495,
     302,    76,   221,   221,   221,   554,   289,   536,   536,   536,
     536,   536,    77,    78,   536,   536,   549,   439,   158,   200,
     157,   295,   653,   391,   296,   289,   289,   289,   289,   289,
     289,   289,    97,   553,   297,   298,   701,   507,   289,   586,
     586,   350,   439,   439,   439,   439,   439,   599,   289,  -196,
     372,   299,   300,  -196,   289,   406,   289,   289,   289,   608,
      90,   320,   400,   301,   557,   311,   450,    96,   573,   574,
     575,   576,   577,   578,   579,   403,   629,   -33,   -33,   314,
     350,   403,  -189,    34,  -198,   324,  -300,   553,  -198,   790,
    -300,   791,   424,   315,   580,   661,   316,   602,   451,   336,
     -33,   -33,   773,   317,   600,   -94,   372,   155,   325,   -94,
     345,   326,   511,   511,   336,   507,   338,   343,   557,   512,
     512,   533,   366,   452,     2,   346,  -355,   364,   260,   -35,
     -35,   535,   221,   448,   591,   592,   594,   595,   596,   365,
     513,   368,   664,   -32,   -32,   812,   605,  -311,   513,   377,
     513,  -311,   -35,   -35,   367,   386,   385,   221,   221,   545,
    -358,  -363,   812,   735,   221,   680,   -32,   -32,  -115,   523,
     411,   388,     3,   389,     4,     5,   390,   289,     6,     7,
       8,     9,   410,   409,   200,   412,   306,   532,   431,  -115,
     307,    26,   542,   432,    27,    28,   289,   289,  -115,   413,
    -199,    29,   524,   289,  -199,   513,   339,   513,    31,   440,
     513,   433,    32,   513,   406,   406,   174,   754,   569,   351,
      26,   -95,   442,    27,    28,   -95,   476,   443,   653,   444,
      29,   341,   104,   105,   652,   445,   446,    31,  -197,   534,
      26,    32,  -197,    27,    28,    36,   696,   698,   447,   306,
      29,   524,   491,   683,   495,   511,   458,    31,   351,   600,
     513,    32,   512,   511,   495,   511,   547,   473,   479,   480,
     512,    56,   512,   123,   123,    61,    62,    63,    64,   170,
     214,   281,   123,   260,   260,   513,   -94,  -200,   481,  -196,
     -94,  -200,   536,  -196,   -96,   289,   661,   513,   -96,   599,
     289,   482,   729,   483,   751,   123,   123,   136,   513,   517,
      89,   514,   496,    34,   497,   518,   519,   529,   520,   521,
     511,   543,   511,   530,   550,   511,   353,   512,   511,   512,
     155,   563,   512,   564,   624,   512,   565,   107,   221,   106,
     123,   123,   414,   602,   566,   415,   221,   567,   572,   582,
     260,   741,   613,   615,   289,   328,   616,   617,   618,   619,
     123,   620,   329,   330,   769,   331,   170,   621,   625,   626,
      34,   627,   536,   630,   632,   511,   359,   214,   332,   333,
     416,   631,   512,   633,   221,   406,   221,    26,   634,   636,
      27,    28,   605,   782,   289,   289,   638,    29,   637,   639,
     511,   640,    30,   641,    31,    97,   289,   512,    32,   824,
     777,   359,   511,   649,   642,  -216,   650,   651,   662,   512,
     667,    26,   821,   511,    27,    28,   663,    34,   729,   666,
     512,    29,   681,    90,   668,   419,   669,   281,    31,   462,
      96,   682,    32,   260,    34,   670,   685,   684,   686,   429,
     794,   795,   811,   415,   687,   -51,   688,   420,   124,   124,
     689,   436,   741,   690,   124,   215,   463,   124,   691,   464,
     465,   692,    79,   702,   693,   260,    29,   704,   588,   709,
     708,    30,   710,    31,   712,   260,   372,    32,   720,   721,
     124,   124,   722,   260,   260,   260,   723,   421,   732,   123,
     123,   123,   214,   281,   422,   647,   498,   123,   730,   731,
     736,   706,   123,   737,   123,   738,   739,   744,   123,   123,
     123,   123,   123,   438,   745,   124,   124,   749,   752,   123,
     123,   123,   753,    26,   760,   761,    27,    28,   123,   123,
     762,   763,   770,    29,   327,   124,   105,   771,   347,   781,
      31,   124,   783,   362,    32,   774,   359,   328,    89,   786,
     788,   215,   215,  -188,   329,   330,   789,   331,   527,   792,
     796,   359,   359,   359,   359,   359,   797,   359,   359,   359,
     332,   333,   334,   359,   793,   819,   803,   806,   805,   815,
     436,   527,   359,   359,   359,   816,   215,   818,   419,   419,
     419,   419,   419,   419,   419,   822,   823,   746,   711,   455,
     776,   743,   804,   527,   260,   590,   590,   590,   590,   590,
     420,   420,   420,   420,   420,   420,   420,   603,   747,   382,
     454,   765,   727,   260,   260,   802,   500,   799,   645,   810,
     260,   757,   787,   755,   764,   527,   775,   707,   703,   420,
     489,   474,   438,   635,   323,   715,   441,   717,   748,   772,
     421,   421,   421,   421,   421,   421,   421,   422,   422,   422,
     422,   422,   422,   422,   584,   584,   808,   438,   438,   438,
     438,   438,   342,   123,   124,   124,   124,   215,   825,   421,
       0,     0,   124,     0,     0,   694,   422,   124,   462,   124,
       0,     0,     0,   124,   124,   124,   124,   124,     0,     0,
       0,     0,   756,     0,   124,   124,   124,   758,     0,   359,
     759,     0,   359,   124,   124,   463,   527,   527,   464,   465,
       0,     0,   260,     0,     0,    29,     0,     0,     0,     0,
      30,   215,    31,     0,     0,     0,    32,   359,   359,     0,
       0,     0,     0,   528,   359,     0,   215,   215,   215,   215,
     215,     0,   215,   215,   215,     0,     0,   717,   215,     0,
     522,     0,   527,   527,     0,   523,   528,   215,   215,   215,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   260,   801,     0,     0,     0,     0,    26,   528,     0,
      27,    28,     0,     0,   647,     0,   206,    29,   524,     0,
     672,     0,     0,     0,    31,   647,     0,   724,    32,     0,
       0,     0,   223,   224,     0,   225,   226,   227,   228,     0,
     528,   260,   260,     0,     0,   135,   123,   229,   230,   581,
     582,     0,     0,   260,    26,   589,     0,    27,    28,   138,
     234,   235,     0,     0,    29,     0,   359,     0,     0,     0,
       0,    31,     0,   236,     0,    32,   359,    26,   124,     0,
      27,    28,     0,   603,     0,     0,     0,    29,   103,   104,
     105,   175,    86,     0,    31,     0,    87,    88,    32,     0,
       0,     0,    89,     0,     0,   420,     0,     0,     0,     0,
       0,     0,   206,   206,   215,     0,   123,   215,   123,     0,
       0,   528,   528,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   543,     0,   359,     0,   527,   359,     0,
       0,     0,   215,   215,     0,   421,   359,   206,     0,   215,
     125,   125,   422,   527,     0,     0,   125,   216,   283,   125,
      26,   568,     0,    27,    28,     0,   569,   528,   528,     0,
      29,     0,     0,     0,     0,     0,     0,    31,     0,     0,
       0,    32,   125,   125,   359,     0,   359,     0,    26,     0,
       0,    27,    28,     0,     0,     0,   672,     0,    29,   524,
       0,   208,   359,     0,     0,    31,     0,   223,   224,    32,
     225,   226,   227,   228,     0,     0,     0,   125,   125,     0,
     135,     0,   229,   230,   231,   232,     0,     0,     0,     0,
     233,   124,     0,     0,   138,   234,   235,   125,   206,     0,
       0,   139,     0,   125,     0,     0,     0,     0,   236,     0,
       0,   215,    26,   360,   360,    27,    28,     0,     0,     0,
       0,   215,    29,   163,   104,   105,   175,    86,   176,    31,
       0,    87,    88,    32,     0,     0,     0,    89,     0,     0,
       0,     0,     0,    26,     0,     0,    27,    28,   360,     0,
       0,     0,   206,    29,   524,   104,   105,   208,   208,     0,
      31,   124,     0,   124,    32,     0,     0,   206,   206,   206,
     206,   206,     0,   206,     0,     0,     0,     0,     0,   206,
     215,     0,   528,   215,     0,     0,   369,     0,   206,   206,
     206,   215,   208,     0,     0,   126,   126,     0,   528,   328,
       0,   126,   217,     0,   126,     0,   329,   330,     0,   331,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   332,   333,   370,     0,     0,   126,   126,   215,
       0,   215,     0,     0,     0,     0,   125,   125,   125,   216,
     283,     0,     0,     0,   125,     0,     0,   215,     0,   125,
       0,   125,     0,     0,     0,   125,   125,   125,   125,   125,
       0,     0,   126,   126,     0,     0,   125,   125,   125,     0,
       0,     0,     0,     0,     0,   125,   125,     0,     0,     0,
       0,     0,   126,   208,     0,     0,     0,     0,   126,     0,
       0,     0,     0,   360,     0,     0,     0,     0,   217,   217,
       0,     0,     0,     0,     0,     0,     0,     0,   360,   360,
     360,   360,   360,     0,   360,   360,   360,     0,   206,     0,
     360,     0,     0,     0,     0,     0,     0,     0,   555,   360,
     360,   360,     0,   217,     0,     0,     0,   208,     0,     0,
       0,     0,     0,   206,   206,     0,     0,     0,   223,   224,
     206,   225,   208,   208,   208,   208,   208,     0,   208,     0,
       0,     0,     0,   229,   208,   581,   582,     0,     0,     0,
       0,   583,     0,   208,   208,   208,   234,     0,     0,     0,
       0,     0,   555,     0,     0,     0,     0,     0,     0,   236,
       0,     0,     0,    26,     0,     0,    27,    28,     0,     0,
       0,     0,     0,    29,   103,   104,   105,     0,    86,     0,
      31,     0,    87,    88,    32,     0,     0,     0,    89,     0,
     125,   126,   126,   126,   217,   230,     0,   498,     0,   126,
       0,     0,   499,     0,   126,     0,   126,     0,   235,     0,
     126,   126,   126,   126,   126,     0,     0,     0,     0,     0,
       0,   126,   126,   126,    26,     0,   360,    27,    28,   360,
     126,   126,     0,     0,    29,     0,     0,   105,     0,     0,
       0,    31,     0,     0,     0,    32,     0,     0,   217,    89,
       0,     0,     0,     0,   360,   360,     0,     0,     0,     0,
       0,   360,     0,   217,   217,   217,   217,   217,     0,   217,
     217,   217,     0,   208,     0,   217,     0,     0,     0,     0,
       0,     0,     0,   556,   217,   217,   217,     0,     0,     0,
       0,     0,     0,     0,   206,     0,     0,     0,   208,   208,
       0,     0,   206,     0,     0,   208,   127,   127,     0,   398,
       0,     0,   127,   218,     0,   127,     0,     0,     0,     0,
     306,     0,   328,     0,   307,     0,     0,   733,   378,   329,
     330,     0,   331,   734,     0,     0,     0,   556,   127,   127,
     206,     0,   206,   125,   139,   332,   333,   399,   230,     0,
     498,     0,   498,     0,     0,   798,     0,   809,     0,     0,
       0,   235,     0,   360,     0,     0,     0,     0,     0,     0,
       0,   176,     0,   127,   127,   126,     0,    26,     0,    26,
      27,    28,    27,    28,     0,     0,     0,    29,     0,    29,
     105,     0,   105,   127,    31,     0,    31,     0,    32,   127,
      32,     0,    89,     0,    89,     0,     0,     0,     0,   218,
     218,   217,     0,   125,   217,   125,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   360,     0,     0,   360,     0,     0,     0,   217,
     217,     0,     0,   360,   218,     0,   217,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   135,     0,     0,
       0,   171,   172,   128,   128,     0,     0,   352,     0,   128,
     219,   138,   128,     0,     0,   354,     0,     0,   139,   208,
       0,   360,     0,   360,     0,   174,     0,   208,     0,    26,
       0,     0,    27,    28,     0,   128,   128,     0,     0,    29,
     103,   104,   105,   175,    86,   176,    31,     0,    87,    88,
      32,     0,     0,     0,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   208,     0,   208,   126,     0,
     128,   128,   127,   127,   127,   218,     0,   542,   543,     0,
     127,     0,     0,   544,     0,   127,     0,   127,   217,     0,
     128,   127,   127,   127,   127,   127,   128,     0,     0,     0,
       0,   174,   127,   127,   127,    26,   219,   219,    27,    28,
       0,   127,   127,     0,     0,    29,   103,   104,   105,     0,
      86,     0,    31,     0,    87,    88,    32,     0,     0,   218,
      89,     0,     0,     0,     0,     0,     0,     0,   126,     0,
     126,   219,     0,     0,   218,   218,   218,   218,   218,     0,
     218,   218,   218,     0,     0,     0,   218,   217,     0,     0,
     217,     0,     0,     0,     0,   218,   218,   218,   217,   135,
       0,     0,     0,   171,   172,     0,     0,     0,     0,   352,
       0,     0,   353,   138,     0,     0,     0,   354,     0,     0,
     139,     0,     0,     0,     0,     0,     0,   174,     0,     0,
       0,    26,     0,     0,    27,    28,   217,     0,   217,     0,
       0,    29,   103,   104,   105,   175,    86,   176,    31,     0,
      87,    88,    32,     0,     0,     0,    89,     0,     0,   128,
     128,   128,   219,     0,     0,     0,     0,   128,     0,     0,
       0,     0,   128,     0,   128,     0,     0,     0,   128,   128,
     128,   128,   128,     0,     0,     0,   127,     0,     0,   128,
     128,   128,     0,     0,     0,     0,     0,     0,   128,   128,
       0,     0,     0,     0,     0,     0,     0,     0,   129,   129,
       0,     0,     0,     0,   129,   220,   219,   129,     0,     0,
       0,     0,   218,     0,     0,   218,     0,     0,     0,     0,
       0,   219,   219,   219,   219,   219,     0,   219,   219,   219,
     129,   129,     0,   219,     0,     0,     0,     0,     0,     0,
     218,   218,   219,   219,   219,     0,     0,   218,     0,     0,
       0,     0,     0,     0,     0,   223,   224,     0,   225,   226,
     227,   228,     0,     0,     0,   129,   129,     0,   135,     0,
     229,   230,   231,   232,     0,     0,     0,     0,   392,     0,
       0,   353,   138,   234,   235,   129,   393,     0,     0,   139,
       0,   129,     0,     0,     0,     0,   236,     0,     0,     0,
      26,   361,   220,    27,    28,     0,     0,     0,     0,     0,
      29,   103,   104,   105,   175,    86,   176,    31,     0,    87,
      88,    32,     0,     0,     0,    89,     0,     0,     0,   127,
       0,   135,     0,   128,     0,   171,   172,     0,     0,     0,
       0,   173,     0,     0,   362,   138,     0,     0,     0,   218,
       0,     0,   139,     0,     0,     0,   156,     0,     0,   174,
       0,     0,   210,    26,   156,    79,    27,    28,     0,   219,
       0,     0,   219,    29,   163,   104,   105,   175,    86,   176,
      31,     0,    87,    88,    32,    80,    81,    82,    89,    83,
      84,     0,    26,     0,     0,    27,    28,   219,   219,   127,
       0,   127,    29,    85,   219,     0,     0,    86,     0,    31,
       0,    87,    88,    32,     0,     0,     0,    89,   218,     0,
       0,   218,   156,   156,   129,   129,   129,   220,     0,   218,
       0,     0,   129,     0,     0,     0,     0,   129,     0,   129,
       0,     0,   156,   129,   129,   129,   129,   129,     0,     0,
       0,     0,     0,     0,   129,   129,   129,     0,   210,   210,
       0,     0,     0,   129,   129,     0,     0,   218,     0,   218,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   220,     0,     0,     0,     0,   128,     0,     0,     0,
       0,     0,     0,   210,     0,     0,   220,   220,   220,   220,
     220,     0,   361,   220,   220,     0,   219,     0,   220,     0,
       0,     0,     0,     0,     0,     0,     0,   361,   361,   361,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   398,   223,   224,     0,   225,   226,   227,   228,     0,
       0,     0,   306,     0,   328,   135,   307,   229,   230,   231,
     232,   329,   330,     0,   331,   392,   128,     0,   128,   138,
     234,   235,     0,     0,     0,     0,   139,   332,   333,   399,
       0,     0,     0,   236,     0,   219,     0,    26,   219,     0,
      27,    28,   156,     0,   210,     0,   219,    29,   103,   104,
     105,   175,    86,   176,    31,   135,    87,    88,    32,   171,
     378,     0,    89,     0,   156,   379,     0,     0,   129,   138,
       0,   156,   156,   156,     0,     0,   139,     0,     0,     0,
     156,   156,     0,   174,   219,     0,   219,    26,     0,     0,
      27,    28,     0,     0,     0,     0,     0,    29,   210,   104,
     105,   175,     0,   176,    31,     0,     0,   361,    32,     0,
       0,     0,    89,   210,   210,   210,   210,   210,     0,   210,
       0,     0,     0,     0,     0,   210,     0,     0,     0,     0,
       0,     0,   361,   220,   210,   210,   210,     0,     0,   361,
     398,   223,   224,     0,   225,   226,   227,   228,     0,     0,
       0,   306,     0,   328,   135,   307,   229,   230,   231,   232,
     329,   330,     0,   331,   233,     0,     0,   362,   138,   234,
     235,     0,     0,     0,     0,   139,   332,   333,   399,     0,
       0,     0,   236,     0,     0,     0,    26,     0,     0,    27,
      28,     0,     0,     0,     0,     0,    29,   163,   104,   105,
     175,    86,   176,    31,     0,    87,    88,    32,     0,     0,
       0,    89,   223,   224,     0,   225,     0,     0,     0,     0,
       0,   129,     0,     0,     0,   156,     0,   229,     0,   581,
     582,     0,     0,     0,     0,   671,     0,     0,     0,     0,
     234,   220,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   236,     0,     0,     0,    26,     0,     0,
      27,    28,     0,     0,   210,     0,     0,    29,   103,   104,
     105,   652,    86,     0,    31,     0,    87,    88,    32,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   210,
     210,   129,     0,   129,     0,     0,   210,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   361,     0,     0,     0,     0,   398,   223,
     224,   220,   225,   226,   227,   228,     0,     0,     0,   306,
       0,   328,   135,   307,   229,   230,   231,   232,   329,   330,
       0,   331,   392,     0,     0,   362,   138,   234,   235,     0,
       0,     0,     0,   139,   332,   333,   399,     0,     0,   361,
     236,   361,     0,     0,    26,     0,     0,    27,    28,     0,
       0,     0,     0,     0,    29,   103,   104,   105,   175,    86,
     176,    31,     0,    87,    88,    32,     0,     0,     0,    89,
       0,     0,     0,     0,   223,   224,     0,   225,   226,   227,
     228,     0,     0,     0,     0,     0,     0,   135,     0,   229,
     230,   231,   232,     0,     0,     0,     0,   392,     0,     0,
       0,   138,   234,   235,     0,   393,     0,     0,   139,     0,
       0,     0,     0,     0,     0,   236,     0,     0,     0,    26,
       0,     0,    27,    28,     0,     0,     0,     0,   156,    29,
     103,   104,   105,   175,    86,   176,    31,     0,    87,    88,
      32,     0,     0,     0,    89,     0,     0,     0,     0,     0,
     210,     0,     0,     0,     0,     0,   223,   224,   210,   225,
     226,   227,   228,     0,     0,     0,     0,     0,     0,   135,
       0,   229,   230,   231,   232,     0,     0,     0,     0,   392,
       0,     0,     0,   138,   234,   235,     0,     0,     0,     0,
     139,     0,     0,     0,     0,     0,   210,   236,   210,     0,
       0,    26,     0,     0,    27,    28,     0,     0,     0,     0,
       0,    29,   103,   104,   105,   175,    86,   176,    31,     0,
      87,    88,    32,     0,   223,   224,    89,   225,   226,   227,
     228,     0,     0,     0,     0,     0,     0,   135,     0,   229,
     230,   231,   232,     0,     0,     0,     0,   434,     0,     0,
       0,   138,   234,   235,     0,     0,     0,     0,   139,     0,
       0,     0,     0,     0,     0,   236,     0,     0,     0,    26,
       0,     0,    27,    28,     0,     0,     0,     0,     0,    29,
     103,   104,   105,   175,    86,   176,    31,     0,    87,    88,
      32,     0,   223,   224,    89,   225,   226,   227,   228,     0,
       0,     0,     0,     0,     0,   135,     0,   229,   230,   231,
     740,     0,     0,     0,     0,   392,     0,     0,     0,   138,
     234,   235,     0,     0,     0,     0,   139,     0,     0,     0,
       0,     0,     0,   236,     0,     0,     0,    26,     0,     0,
      27,    28,     0,     0,     0,     0,     0,    29,   103,   104,
     105,   175,    86,   176,    31,   135,    87,    88,    32,   171,
     172,     0,    89,     0,     0,   352,     0,     0,   362,   138,
       0,     0,     0,     0,     0,     0,   139,     0,     0,     0,
       0,     0,     0,   174,     0,     0,     0,    26,     0,     0,
      27,    28,     0,     0,     0,     0,     0,    29,   103,   104,
     105,   175,    86,   176,    31,   135,    87,    88,    32,   171,
     172,     0,    89,     0,     0,   173,     0,     0,     0,   138,
       0,     0,     0,     0,     0,     0,   139,     0,     0,     0,
       0,     0,     0,   174,     0,     0,     0,    26,     0,     0,
      27,    28,     0,     0,     0,     0,     0,    29,   163,   104,
     105,   175,    86,   176,    31,   135,    87,    88,    32,   171,
     172,     0,    89,     0,     0,   352,     0,     0,     0,   138,
       0,     0,     0,     0,     0,     0,   139,     0,     0,     0,
       0,     0,     0,   174,     0,     0,     0,    26,     0,     0,
      27,    28,     0,     0,     0,     0,     0,    29,   103,   104,
     105,   175,    86,   176,    31,   135,    87,    88,    32,     0,
     136,     0,    89,     0,     0,   137,     0,     0,     0,   138,
       0,     0,     0,     0,     0,     0,   139,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    26,     0,     0,
      27,    28,     0,     0,     0,   135,     0,    29,   103,   104,
     105,     0,    86,     0,    31,   318,    87,    88,    32,   138,
       0,     0,    89,   319,     0,     0,   139,     0,     0,     0,
       0,     0,   135,     0,     0,     0,     0,    26,     0,     0,
      27,    28,   318,     0,     0,     0,   138,    29,   103,   104,
     105,     0,    86,   139,    31,     0,    87,    88,    32,   161,
       0,     0,    89,     0,    26,     0,     0,    27,    28,   162,
       0,     0,     0,     0,    29,   103,   104,   105,     0,    86,
     102,    31,     0,    87,    88,    32,   161,     0,     0,    89,
       0,    26,     0,     0,    27,    28,   101,     0,     0,     0,
       0,    29,   163,   104,   105,     0,    86,   102,    31,     0,
      87,    88,    32,     0,     0,     0,    89,     0,    26,     0,
       0,    27,    28,     0,     0,     0,     0,    79,    29,   103,
     104,   105,     0,    86,     0,    31,     0,    87,    88,    32,
     292,     0,     0,    89,     0,     0,     0,    80,    81,    82,
       0,    83,    84,     0,    26,   101,     0,    27,    28,     0,
       0,     0,     0,     0,    29,    85,   102,     0,     0,    86,
       0,    31,     0,    87,    88,    32,     0,    26,     0,    89,
      27,    28,   162,     0,     0,     0,     0,    29,   103,   104,
     105,     0,    86,   102,    31,     0,    87,    88,    32,     0,
       0,     0,    89,     0,    26,   303,     0,    27,    28,     0,
       0,     0,     0,     0,    29,   163,   104,   105,     0,    86,
       0,    31,     0,    87,    88,    32,     0,    26,     0,    89,
      27,    28,     0,     0,     0,     0,     0,    29,   103,   104,
     105,     0,    86,   102,    31,     0,    87,    88,    32,     0,
       0,     0,    89,     0,    26,     0,     0,    27,    28,     0,
       0,     0,     0,     0,    29,   103,   104,   105,     0,    86,
       0,    31,     0,    87,    88,    32,     0,    26,     0,    89,
      27,    28,     0,     0,     0,     0,     0,    29,   103,   104,
     105,     0,    86,     0,    31,     0,    87,    88,    32,     0,
       0,     0,    89
};

static const yytype_int16 yycheck[] =
{
      19,    20,    21,    22,    23,    24,    25,    37,    75,    76,
     311,    65,    66,    67,    68,    65,    66,    67,    68,   233,
     156,   499,   207,    19,    20,    79,    22,    23,    24,    25,
     171,   156,   252,   231,    76,   346,   385,   440,    57,    65,
      66,    67,    68,   374,   375,   156,    65,    66,    67,    68,
      76,    77,   373,    79,    73,    77,   102,   561,    70,   301,
      79,    57,    69,   274,    69,   154,    78,    78,    75,   561,
      75,   118,   515,   429,   207,   199,    76,    73,   136,   137,
     316,   317,    76,    77,   440,   233,    27,    37,    27,   118,
     231,   297,   662,    34,   101,   102,   101,   367,   368,   369,
     370,   371,   308,   627,   310,    27,    30,    77,    58,   315,
     316,   317,    34,    76,    77,    27,   367,   368,   369,   370,
     371,   149,    27,   297,   136,   137,   367,   368,   369,   370,
     371,   173,    61,    62,   308,   259,   310,    61,    62,   158,
      27,   315,   316,   317,   156,    27,   172,   173,   297,   388,
     389,   390,   199,    27,   724,   162,   184,   162,    11,   308,
      49,   310,   158,    52,    53,    14,   315,   316,   317,    18,
     199,   260,    25,   173,   442,   443,   444,    66,    22,    27,
      29,   207,   367,   368,   369,   370,   371,   498,   499,   325,
     326,   327,   403,    37,    13,   409,    13,    11,   334,   335,
     325,   326,   327,    13,   446,   346,   232,   233,   171,   334,
     335,    25,   259,    13,   325,   326,   327,   245,   788,    37,
      36,    37,   248,   334,   335,    35,    36,    13,   752,   753,
     259,   298,    13,   737,   367,   368,   369,   370,   371,   233,
      58,   374,   375,    13,   392,   737,   300,   301,   274,    67,
     300,   297,    12,    13,    35,    36,   298,   303,   305,    13,
     318,    13,   308,   233,   310,   248,    28,    69,   231,   315,
     316,   317,   298,   299,   300,   301,    13,   299,   721,   518,
      13,   300,   301,   686,   296,   296,   434,    36,   295,    14,
     295,   640,   311,    18,    28,   563,   303,   364,   298,   101,
      28,   650,    35,    36,   298,   299,   318,   314,    28,   314,
     352,   550,   338,   325,   326,   327,    13,   343,   425,   426,
     346,   652,   334,   335,   443,   444,   352,   346,    13,   299,
     686,   809,   752,   753,    13,   298,   299,   379,    35,    36,
      13,   367,   368,   369,   370,   371,    30,   373,   374,   375,
      35,    36,   352,   379,   568,   569,    13,   498,   499,   385,
     162,    13,   388,   389,   390,   387,   392,   367,   368,   369,
     370,   371,    13,    13,   374,   375,   376,   403,    13,   379,
      35,    27,   515,   581,    27,   411,   412,   413,   414,   415,
     416,   417,   446,   387,    27,    27,   632,   708,   424,   425,
     426,   542,   428,   429,   430,   431,   432,   433,   434,    14,
      15,    27,    11,    18,   440,   409,   442,   443,   444,   441,
     446,   479,   392,    27,   387,    13,   632,   446,   411,   412,
     413,   414,   415,   416,   417,   583,   466,    12,    13,    41,
     581,   589,    12,   462,    14,   140,    14,   441,    18,   770,
      18,   772,   672,    27,   424,   522,    27,   440,   632,    29,
      35,    36,   732,    27,   434,    14,    15,   479,    41,    18,
     165,     3,   498,   499,    29,   786,    22,    22,   441,   498,
     499,   732,   177,   632,     0,    11,    11,    27,    77,    12,
      13,   732,   518,   295,   428,   429,   430,   431,   432,    30,
     641,     3,   544,    12,    13,   806,   440,    14,   649,     6,
     651,    18,    35,    36,    41,    25,    22,   543,   544,   652,
      25,    25,   823,   671,   550,   739,    35,    36,    37,    27,
      41,    27,    48,    27,    50,    51,    27,   563,    54,    55,
      56,    57,   237,    27,   544,     3,    14,   732,    37,    58,
      18,    49,    21,    67,    52,    53,   582,   583,    67,     6,
      14,    59,    60,   589,    18,   706,   702,   708,    66,    11,
     711,    22,    70,   714,   568,   569,    45,   702,    27,   542,
      49,    14,    27,    52,    53,    18,   632,    27,   721,    27,
      59,   702,    61,    62,    63,   290,    13,    66,    14,   732,
      49,    70,    18,    52,    53,   624,   625,   626,    35,    14,
      59,    60,   638,   583,   640,   641,    36,    66,   581,   589,
     761,    70,   641,   649,   650,   651,   652,    36,    13,    35,
     649,    43,   651,    69,    70,    47,    48,    49,    50,    75,
      76,    77,    78,   232,   233,   786,    14,    14,    36,    14,
      18,    18,   652,    18,    14,   681,   723,   798,    18,   685,
     686,    36,   662,    36,   694,   101,   102,    22,   809,    35,
      74,    34,    36,   692,    36,    13,    35,    58,    36,    36,
     706,    22,   708,    36,    27,   711,    30,   706,   714,   708,
     702,    13,   711,    35,    27,   714,    36,   704,   724,   704,
     136,   137,     3,   686,    36,     6,   732,    36,    36,    22,
     299,   681,    36,    36,   740,    16,    36,    36,    36,    36,
     156,    36,    23,    24,   724,    26,   162,    36,    27,    27,
     749,    13,   732,    30,    13,   761,   172,   173,    39,    40,
      41,    36,   761,    36,   770,   739,   772,    49,    36,    30,
      52,    53,   686,   749,   780,   781,    13,    59,    35,    35,
     786,    13,    64,    11,    66,   819,   792,   786,    70,   819,
     740,   207,   798,    58,    30,    58,    22,    27,    13,   798,
      35,    49,   812,   809,    52,    53,    30,   806,   788,    36,
     809,    59,    13,   819,    36,   248,    36,   233,    66,    22,
     819,    30,    70,   392,   823,    36,    13,    35,    11,    58,
     780,   781,    35,     6,    36,     6,    36,   248,    69,    70,
      36,   274,   792,    36,    75,    76,    49,    78,    30,    52,
      53,    13,    22,    11,    35,   424,    59,    11,   427,    35,
      13,    64,    36,    66,    36,   434,    15,    70,    36,    13,
     101,   102,    35,   442,   443,   444,    13,   248,    11,   295,
     296,   297,   298,   299,   248,   499,    22,   303,    36,    36,
      36,    27,   308,    13,   310,    35,    13,    36,   314,   315,
     316,   317,   318,   274,    11,   136,   137,    13,    13,   325,
     326,   327,    13,    49,    35,    13,    52,    53,   334,   335,
      36,    34,    13,    59,     3,   156,    62,    12,    30,    13,
      66,   162,    36,    30,    70,    34,   352,    16,    74,    11,
      13,   172,   173,    12,    23,    24,    35,    26,   364,    13,
      13,   367,   368,   369,   370,   371,    13,   373,   374,   375,
      39,    40,    41,   379,    35,    11,    36,    22,    36,    36,
     403,   387,   388,   389,   390,    36,   207,    36,   411,   412,
     413,   414,   415,   416,   417,    35,    13,   685,    37,   299,
     739,   681,   792,   409,   563,   428,   429,   430,   431,   432,
     411,   412,   413,   414,   415,   416,   417,   440,   686,   207,
     298,   723,   662,   582,   583,   788,   346,   786,   499,   798,
     589,   708,   761,   704,   721,   441,   737,   641,   638,   440,
     337,   314,   403,   479,   137,   649,   280,   651,   692,   728,
     411,   412,   413,   414,   415,   416,   417,   411,   412,   413,
     414,   415,   416,   417,   425,   426,   797,   428,   429,   430,
     431,   432,   158,   479,   295,   296,   297,   298,   823,   440,
      -1,    -1,   303,    -1,    -1,   624,   440,   308,    22,   310,
      -1,    -1,    -1,   314,   315,   316,   317,   318,    -1,    -1,
      -1,    -1,   706,    -1,   325,   326,   327,   711,    -1,   515,
     714,    -1,   518,   334,   335,    49,   522,   523,    52,    53,
      -1,    -1,   681,    -1,    -1,    59,    -1,    -1,    -1,    -1,
      64,   352,    66,    -1,    -1,    -1,    70,   543,   544,    -1,
      -1,    -1,    -1,   364,   550,    -1,   367,   368,   369,   370,
     371,    -1,   373,   374,   375,    -1,    -1,   761,   379,    -1,
      22,    -1,   568,   569,    -1,    27,   387,   388,   389,   390,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   740,   786,    -1,    -1,    -1,    -1,    49,   409,    -1,
      52,    53,    -1,    -1,   798,    -1,    76,    59,    60,    -1,
     561,    -1,    -1,    -1,    66,   809,    -1,    22,    70,    -1,
      -1,    -1,     4,     5,    -1,     7,     8,     9,    10,    -1,
     441,   780,   781,    -1,    -1,    17,   632,    19,    20,    21,
      22,    -1,    -1,   792,    49,    27,    -1,    52,    53,    31,
      32,    33,    -1,    -1,    59,    -1,   652,    -1,    -1,    -1,
      -1,    66,    -1,    45,    -1,    70,   662,    49,   479,    -1,
      52,    53,    -1,   686,    -1,    -1,    -1,    59,    60,    61,
      62,    63,    64,    -1,    66,    -1,    68,    69,    70,    -1,
      -1,    -1,    74,    -1,    -1,   686,    -1,    -1,    -1,    -1,
      -1,    -1,   172,   173,   515,    -1,   702,   518,   704,    -1,
      -1,   522,   523,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    -1,   721,    -1,   723,   724,    -1,
      -1,    -1,   543,   544,    -1,   686,   732,   207,    -1,   550,
      69,    70,   686,   739,    -1,    -1,    75,    76,    77,    78,
      49,    22,    -1,    52,    53,    -1,    27,   568,   569,    -1,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,
      -1,    70,   101,   102,   770,    -1,   772,    -1,    49,    -1,
      -1,    52,    53,    -1,    -1,    -1,   737,    -1,    59,    60,
      -1,    76,   788,    -1,    -1,    66,    -1,     4,     5,    70,
       7,     8,     9,    10,    -1,    -1,    -1,   136,   137,    -1,
      17,    -1,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      27,   632,    -1,    -1,    31,    32,    33,   156,   298,    -1,
      -1,    38,    -1,   162,    -1,    -1,    -1,    -1,    45,    -1,
      -1,   652,    49,   172,   173,    52,    53,    -1,    -1,    -1,
      -1,   662,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    -1,    -1,    -1,    74,    -1,    -1,
      -1,    -1,    -1,    49,    -1,    -1,    52,    53,   207,    -1,
      -1,    -1,   352,    59,    60,    61,    62,   172,   173,    -1,
      66,   702,    -1,   704,    70,    -1,    -1,   367,   368,   369,
     370,   371,    -1,   373,    -1,    -1,    -1,    -1,    -1,   379,
     721,    -1,   723,   724,    -1,    -1,     3,    -1,   388,   389,
     390,   732,   207,    -1,    -1,    69,    70,    -1,   739,    16,
      -1,    75,    76,    -1,    78,    -1,    23,    24,    -1,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    40,    41,    -1,    -1,   101,   102,   770,
      -1,   772,    -1,    -1,    -1,    -1,   295,   296,   297,   298,
     299,    -1,    -1,    -1,   303,    -1,    -1,   788,    -1,   308,
      -1,   310,    -1,    -1,    -1,   314,   315,   316,   317,   318,
      -1,    -1,   136,   137,    -1,    -1,   325,   326,   327,    -1,
      -1,    -1,    -1,    -1,    -1,   334,   335,    -1,    -1,    -1,
      -1,    -1,   156,   298,    -1,    -1,    -1,    -1,   162,    -1,
      -1,    -1,    -1,   352,    -1,    -1,    -1,    -1,   172,   173,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   367,   368,
     369,   370,   371,    -1,   373,   374,   375,    -1,   518,    -1,
     379,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   387,   388,
     389,   390,    -1,   207,    -1,    -1,    -1,   352,    -1,    -1,
      -1,    -1,    -1,   543,   544,    -1,    -1,    -1,     4,     5,
     550,     7,   367,   368,   369,   370,   371,    -1,   373,    -1,
      -1,    -1,    -1,    19,   379,    21,    22,    -1,    -1,    -1,
      -1,    27,    -1,   388,   389,   390,    32,    -1,    -1,    -1,
      -1,    -1,   441,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    -1,    49,    -1,    -1,    52,    53,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    -1,    64,    -1,
      66,    -1,    68,    69,    70,    -1,    -1,    -1,    74,    -1,
     479,   295,   296,   297,   298,    20,    -1,    22,    -1,   303,
      -1,    -1,    27,    -1,   308,    -1,   310,    -1,    33,    -1,
     314,   315,   316,   317,   318,    -1,    -1,    -1,    -1,    -1,
      -1,   325,   326,   327,    49,    -1,   515,    52,    53,   518,
     334,   335,    -1,    -1,    59,    -1,    -1,    62,    -1,    -1,
      -1,    66,    -1,    -1,    -1,    70,    -1,    -1,   352,    74,
      -1,    -1,    -1,    -1,   543,   544,    -1,    -1,    -1,    -1,
      -1,   550,    -1,   367,   368,   369,   370,   371,    -1,   373,
     374,   375,    -1,   518,    -1,   379,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   387,   388,   389,   390,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   724,    -1,    -1,    -1,   543,   544,
      -1,    -1,   732,    -1,    -1,   550,    69,    70,    -1,     3,
      -1,    -1,    75,    76,    -1,    78,    -1,    -1,    -1,    -1,
      14,    -1,    16,    -1,    18,    -1,    -1,    21,    22,    23,
      24,    -1,    26,    27,    -1,    -1,    -1,   441,   101,   102,
     770,    -1,   772,   632,    38,    39,    40,    41,    20,    -1,
      22,    -1,    22,    -1,    -1,    27,    -1,    27,    -1,    -1,
      -1,    33,    -1,   652,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    -1,   136,   137,   479,    -1,    49,    -1,    49,
      52,    53,    52,    53,    -1,    -1,    -1,    59,    -1,    59,
      62,    -1,    62,   156,    66,    -1,    66,    -1,    70,   162,
      70,    -1,    74,    -1,    74,    -1,    -1,    -1,    -1,   172,
     173,   515,    -1,   702,   518,   704,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   721,    -1,    -1,   724,    -1,    -1,    -1,   543,
     544,    -1,    -1,   732,   207,    -1,   550,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,
      -1,    21,    22,    69,    70,    -1,    -1,    27,    -1,    75,
      76,    31,    78,    -1,    -1,    35,    -1,    -1,    38,   724,
      -1,   770,    -1,   772,    -1,    45,    -1,   732,    -1,    49,
      -1,    -1,    52,    53,    -1,   101,   102,    -1,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   770,    -1,   772,   632,    -1,
     136,   137,   295,   296,   297,   298,    -1,    21,    22,    -1,
     303,    -1,    -1,    27,    -1,   308,    -1,   310,   652,    -1,
     156,   314,   315,   316,   317,   318,   162,    -1,    -1,    -1,
      -1,    45,   325,   326,   327,    49,   172,   173,    52,    53,
      -1,   334,   335,    -1,    -1,    59,    60,    61,    62,    -1,
      64,    -1,    66,    -1,    68,    69,    70,    -1,    -1,   352,
      74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   702,    -1,
     704,   207,    -1,    -1,   367,   368,   369,   370,   371,    -1,
     373,   374,   375,    -1,    -1,    -1,   379,   721,    -1,    -1,
     724,    -1,    -1,    -1,    -1,   388,   389,   390,   732,    17,
      -1,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      -1,    -1,    30,    31,    -1,    -1,    -1,    35,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,
      -1,    49,    -1,    -1,    52,    53,   770,    -1,   772,    -1,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    -1,    -1,    -1,    74,    -1,    -1,   295,
     296,   297,   298,    -1,    -1,    -1,    -1,   303,    -1,    -1,
      -1,    -1,   308,    -1,   310,    -1,    -1,    -1,   314,   315,
     316,   317,   318,    -1,    -1,    -1,   479,    -1,    -1,   325,
     326,   327,    -1,    -1,    -1,    -1,    -1,    -1,   334,   335,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,
      -1,    -1,    -1,    -1,    75,    76,   352,    78,    -1,    -1,
      -1,    -1,   515,    -1,    -1,   518,    -1,    -1,    -1,    -1,
      -1,   367,   368,   369,   370,   371,    -1,   373,   374,   375,
     101,   102,    -1,   379,    -1,    -1,    -1,    -1,    -1,    -1,
     543,   544,   388,   389,   390,    -1,    -1,   550,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     4,     5,    -1,     7,     8,
       9,    10,    -1,    -1,    -1,   136,   137,    -1,    17,    -1,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    27,    -1,
      -1,    30,    31,    32,    33,   156,    35,    -1,    -1,    38,
      -1,   162,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,
      49,   172,   173,    52,    53,    -1,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    -1,    -1,    -1,    74,    -1,    -1,    -1,   632,
      -1,    17,    -1,   479,    -1,    21,    22,    -1,    -1,    -1,
      -1,    27,    -1,    -1,    30,    31,    -1,    -1,    -1,   652,
      -1,    -1,    38,    -1,    -1,    -1,    70,    -1,    -1,    45,
      -1,    -1,    76,    49,    78,    22,    52,    53,    -1,   515,
      -1,    -1,   518,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    69,    70,    42,    43,    44,    74,    46,
      47,    -1,    49,    -1,    -1,    52,    53,   543,   544,   702,
      -1,   704,    59,    60,   550,    -1,    -1,    64,    -1,    66,
      -1,    68,    69,    70,    -1,    -1,    -1,    74,   721,    -1,
      -1,   724,   136,   137,   295,   296,   297,   298,    -1,   732,
      -1,    -1,   303,    -1,    -1,    -1,    -1,   308,    -1,   310,
      -1,    -1,   156,   314,   315,   316,   317,   318,    -1,    -1,
      -1,    -1,    -1,    -1,   325,   326,   327,    -1,   172,   173,
      -1,    -1,    -1,   334,   335,    -1,    -1,   770,    -1,   772,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   352,    -1,    -1,    -1,    -1,   632,    -1,    -1,    -1,
      -1,    -1,    -1,   207,    -1,    -1,   367,   368,   369,   370,
     371,    -1,   373,   374,   375,    -1,   652,    -1,   379,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   388,   389,   390,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,    -1,     7,     8,     9,    10,    -1,
      -1,    -1,    14,    -1,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    26,    27,   702,    -1,   704,    31,
      32,    33,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      -1,    -1,    -1,    45,    -1,   721,    -1,    49,   724,    -1,
      52,    53,   296,    -1,   298,    -1,   732,    59,    60,    61,
      62,    63,    64,    65,    66,    17,    68,    69,    70,    21,
      22,    -1,    74,    -1,   318,    27,    -1,    -1,   479,    31,
      -1,   325,   326,   327,    -1,    -1,    38,    -1,    -1,    -1,
     334,   335,    -1,    45,   770,    -1,   772,    49,    -1,    -1,
      52,    53,    -1,    -1,    -1,    -1,    -1,    59,   352,    61,
      62,    63,    -1,    65,    66,    -1,    -1,   518,    70,    -1,
      -1,    -1,    74,   367,   368,   369,   370,   371,    -1,   373,
      -1,    -1,    -1,    -1,    -1,   379,    -1,    -1,    -1,    -1,
      -1,    -1,   543,   544,   388,   389,   390,    -1,    -1,   550,
       3,     4,     5,    -1,     7,     8,     9,    10,    -1,    -1,
      -1,    14,    -1,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    26,    27,    -1,    -1,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    -1,
      -1,    -1,    45,    -1,    -1,    -1,    49,    -1,    -1,    52,
      53,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    -1,    -1,
      -1,    74,     4,     5,    -1,     7,    -1,    -1,    -1,    -1,
      -1,   632,    -1,    -1,    -1,   479,    -1,    19,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,
      32,   652,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    49,    -1,    -1,
      52,    53,    -1,    -1,   518,    -1,    -1,    59,    60,    61,
      62,    63,    64,    -1,    66,    -1,    68,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   543,
     544,   702,    -1,   704,    -1,    -1,   550,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   724,    -1,    -1,    -1,    -1,     3,     4,
       5,   732,     7,     8,     9,    10,    -1,    -1,    -1,    14,
      -1,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,    26,    27,    -1,    -1,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    -1,    -1,   770,
      45,   772,    -1,    -1,    49,    -1,    -1,    52,    53,    -1,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    -1,    -1,    -1,    74,
      -1,    -1,    -1,    -1,     4,     5,    -1,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    27,    -1,    -1,
      -1,    31,    32,    33,    -1,    35,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    49,
      -1,    -1,    52,    53,    -1,    -1,    -1,    -1,   702,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,
     724,    -1,    -1,    -1,    -1,    -1,     4,     5,   732,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      -1,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    27,
      -1,    -1,    -1,    31,    32,    33,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,   770,    45,   772,    -1,
      -1,    49,    -1,    -1,    52,    53,    -1,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    -1,     4,     5,    74,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    27,    -1,    -1,
      -1,    31,    32,    33,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    49,
      -1,    -1,    52,    53,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    -1,     4,     5,    74,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    -1,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    31,
      32,    33,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    49,    -1,    -1,
      52,    53,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    17,    68,    69,    70,    21,
      22,    -1,    74,    -1,    -1,    27,    -1,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    49,    -1,    -1,
      52,    53,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    17,    68,    69,    70,    21,
      22,    -1,    74,    -1,    -1,    27,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    49,    -1,    -1,
      52,    53,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    17,    68,    69,    70,    21,
      22,    -1,    74,    -1,    -1,    27,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    49,    -1,    -1,
      52,    53,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    17,    68,    69,    70,    -1,
      22,    -1,    74,    -1,    -1,    27,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,
      52,    53,    -1,    -1,    -1,    17,    -1,    59,    60,    61,
      62,    -1,    64,    -1,    66,    27,    68,    69,    70,    31,
      -1,    -1,    74,    35,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    17,    -1,    -1,    -1,    -1,    49,    -1,    -1,
      52,    53,    27,    -1,    -1,    -1,    31,    59,    60,    61,
      62,    -1,    64,    38,    66,    -1,    68,    69,    70,    17,
      -1,    -1,    74,    -1,    49,    -1,    -1,    52,    53,    27,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,    64,
      38,    66,    -1,    68,    69,    70,    17,    -1,    -1,    74,
      -1,    49,    -1,    -1,    52,    53,    27,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    -1,    64,    38,    66,    -1,
      68,    69,    70,    -1,    -1,    -1,    74,    -1,    49,    -1,
      -1,    52,    53,    -1,    -1,    -1,    -1,    22,    59,    60,
      61,    62,    -1,    64,    -1,    66,    -1,    68,    69,    70,
      35,    -1,    -1,    74,    -1,    -1,    -1,    42,    43,    44,
      -1,    46,    47,    -1,    49,    27,    -1,    52,    53,    -1,
      -1,    -1,    -1,    -1,    59,    60,    38,    -1,    -1,    64,
      -1,    66,    -1,    68,    69,    70,    -1,    49,    -1,    74,
      52,    53,    27,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    -1,    64,    38,    66,    -1,    68,    69,    70,    -1,
      -1,    -1,    74,    -1,    49,    27,    -1,    52,    53,    -1,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,    64,
      -1,    66,    -1,    68,    69,    70,    -1,    49,    -1,    74,
      52,    53,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    -1,    64,    38,    66,    -1,    68,    69,    70,    -1,
      -1,    -1,    74,    -1,    49,    -1,    -1,    52,    53,    -1,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,    64,
      -1,    66,    -1,    68,    69,    70,    -1,    49,    -1,    74,
      52,    53,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    -1,    64,    -1,    66,    -1,    68,    69,    70,    -1,
      -1,    -1,    74
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,    76,     0,    48,    50,    51,    54,    55,    56,    57,
      77,    78,    79,    81,    82,    83,    84,    85,   282,    27,
      27,    27,    27,    27,    27,    27,    49,    52,    53,    59,
      64,    66,    70,   293,   294,   293,   294,   298,   293,   293,
     293,   293,    13,    13,    13,   283,   299,    13,    13,    13,
      13,    49,    52,    53,    66,    87,    87,    22,    37,   284,
      36,    87,    87,    87,    87,    28,    28,    28,    28,    13,
      13,   285,   293,    13,    30,    13,    13,    13,    13,    22,
      42,    43,    44,    46,    47,    60,    64,    68,    69,    74,
     265,   287,   288,   289,   290,   291,   294,   297,   287,   287,
     287,    27,    38,    60,    61,    62,   209,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   226,   227,
     231,   232,   233,   257,   258,   259,   260,   261,   262,   264,
     265,   294,   295,   296,   297,    17,    22,    27,    31,    38,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   214,   228,   229,   241,   244,    35,    13,   286,
     293,    17,    27,    60,   171,   198,   199,   200,   231,   248,
     257,    21,    22,    27,    45,    63,    65,   135,   136,   137,
     138,   139,   140,   141,   142,   144,   145,   146,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   166,   168,
     169,   171,   183,   184,   185,   190,   197,   239,   240,   241,
     244,   248,   249,   253,   257,   258,   259,   260,   261,   262,
     264,   265,   296,     4,     5,     7,     8,     9,    10,    19,
      20,    21,    22,    27,    32,    33,    45,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    98,    99,   100,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   118,
     120,   121,   124,   126,   128,   129,   130,   131,   132,   133,
     134,   186,   197,   234,   235,   236,   237,   240,   244,   248,
     249,   257,   258,   259,   260,   261,   262,   263,   264,   265,
      80,   201,    35,   287,   292,    27,    27,    27,    27,    27,
      11,    27,   231,    27,   214,   226,    14,    18,   254,   255,
     256,    13,    86,   299,    41,    27,    27,    27,    27,    35,
     202,   230,   202,   228,    86,    41,     3,     3,    16,    23,
      24,    26,    39,    40,    41,   242,    29,   245,    22,   208,
     210,   211,   285,    22,   171,    86,    11,    30,   194,   195,
     295,   296,    27,    30,    35,   136,   167,   169,   170,   257,
     259,   264,    30,   136,    27,    30,    86,    41,     3,     3,
      41,   242,    15,   247,   254,   256,   245,     6,    22,    27,
     143,   144,   151,   153,   265,    22,    25,   238,    27,    27,
      27,   194,    27,    35,    89,   123,   257,   259,     3,    41,
      89,   119,   124,   235,   242,   243,   248,   255,   256,    27,
      86,    41,     3,     6,     3,     6,    41,   242,    96,    98,
     103,   106,   110,   120,   247,   254,   256,   245,    37,    58,
      67,    37,    67,    22,    27,    97,    98,   104,   106,   265,
      11,   238,    27,    27,    27,    86,    13,    35,   231,   201,
     220,   223,   224,   226,   135,    88,   287,   292,    36,   214,
     226,   226,    22,    49,    52,    53,   266,   268,   269,   271,
     273,   274,   293,    36,   233,   225,   226,   225,   225,    13,
      35,    36,    36,    36,   210,   210,   210,   210,   210,   229,
     213,   265,   147,   148,   149,   265,    36,    36,    22,    27,
     172,   173,   174,   176,   177,   179,   181,   237,   250,   251,
     252,   265,   294,   295,    34,    27,    34,    35,    13,    35,
      36,    36,    22,    27,    60,   160,   171,   257,   258,    58,
      36,   142,   144,   150,   153,   157,   169,   142,   142,   142,
     142,   167,    21,    22,    27,   153,   168,   265,   168,   169,
      27,   136,   147,   248,   249,   259,   260,   296,   170,   170,
     170,    27,    34,    13,    35,    36,    36,    36,    22,    27,
     113,   124,    36,    96,    96,    96,    96,    96,    96,    96,
      89,    21,    22,    27,   106,   118,   265,   118,   120,    27,
      98,   126,   126,   129,   126,   126,   126,   101,   102,   265,
      89,    95,    96,    98,   125,   126,   127,   129,   249,   122,
     123,   122,   122,    36,   292,    36,    36,    36,    36,    36,
      36,    36,   266,   267,    27,    27,    27,    13,   280,   299,
      30,    36,    13,    36,    36,   230,    30,    35,    13,    35,
      13,    11,    30,   172,   182,   173,   176,   177,   180,    58,
      22,    27,    63,   153,   184,   191,   192,   193,   196,   170,
     161,   171,    13,    30,   136,   170,    36,    35,    36,    36,
      36,    27,   106,   133,   187,   188,   189,   196,   123,   114,
     124,    13,    30,    89,    35,    13,    11,    36,    36,    36,
      36,    30,    13,    35,   298,   270,   294,   272,   294,   281,
     291,   225,    11,   213,    11,   147,    27,   177,    13,    35,
      36,    37,    36,    36,    37,   177,   147,   177,   178,   168,
      36,    13,    35,    13,    22,   154,   162,   163,   164,   169,
      36,    36,    11,    21,    27,   235,    36,    13,    35,    13,
      22,    89,   115,   116,    36,    11,   101,   125,   267,    13,
     275,   299,    13,    13,   210,   199,   177,   182,   177,   177,
      35,    13,    36,    34,   191,   161,   154,   163,   165,   169,
      13,    12,   246,   142,    34,   187,   114,    89,   116,   117,
     246,    13,   293,    36,   281,   281,    11,   178,    13,    35,
     167,   167,    13,    35,    89,    89,    13,    13,    27,   174,
     175,   177,   165,    36,   117,    36,    22,   276,   276,    27,
     179,    35,   266,   277,   278,    36,    36,   176,    36,    11,
     279,   299,    35,    13,   287,   277
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,    75,    76,    76,    77,    77,    78,    78,    78,    78,
      78,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      86,    87,    87,    87,    87,    87,    87,    87,    87,    88,
      88,    88,    89,    89,    89,    89,    89,    89,    90,    90,
      90,    91,    92,    92,    92,    93,    93,    94,    94,    95,
      95,    96,    96,    96,    97,    97,    98,    98,    98,    98,
      99,   100,   101,   101,   102,   103,   103,   104,   105,   106,
     106,   106,   106,   107,   107,   108,   108,   108,   108,   108,
     109,   109,   110,   111,   112,   113,   113,   114,   114,   115,
     115,   116,   117,   117,   118,   118,   118,   119,   119,   119,
     119,   119,   120,   120,   121,   121,   121,   122,   123,   123,
     124,   124,   125,   125,   125,   126,   127,   128,   128,   128,
     129,   129,   130,   130,   131,   131,   132,   133,   134,   135,
     135,   135,   136,   136,   136,   136,   136,   136,   137,   137,
     138,   139,   139,   140,   140,   141,   141,   142,   142,   142,
     143,   143,   144,   144,   144,   144,   145,   146,   147,   147,
     148,   148,   149,   150,   150,   151,   152,   153,   153,   153,
     154,   154,   155,   156,   156,   156,   156,   157,   158,   158,
     159,   160,   160,   161,   161,   162,   162,   163,   164,   164,
     165,   165,   166,   167,   167,   167,   168,   168,   168,   168,
     168,   169,   169,   170,   170,   171,   171,   172,   172,   173,
     173,   173,   174,   175,   175,   175,   176,   176,   177,   177,
     177,   177,   177,   177,   178,   178,   179,   180,   180,   181,
     182,   182,   183,   184,   185,   186,   186,   187,   187,   188,
     188,   189,   190,   190,   191,   191,   192,   192,   193,   194,
     194,   195,   196,   197,   197,   197,   197,   198,   198,   199,
     199,   200,   201,   201,   202,   202,   202,   203,   203,   204,
     205,   205,   206,   206,   207,   207,   208,   208,   209,   210,
     210,   211,   211,   211,   212,   213,   213,   214,   214,   214,
     215,   216,   216,   217,   218,   219,   220,   220,   221,   221,
     222,   223,   223,   224,   224,   225,   225,   226,   226,   227,
     227,   227,   228,   228,   229,   229,   230,   230,   231,   231,
     232,   232,   233,   233,   233,   233,   234,   234,   234,   235,
     235,   236,   236,   236,   237,   237,   238,   239,   239,   240,
     240,   241,   241,   242,   242,   242,   242,   242,   242,   243,
     243,   244,   245,   246,   247,   248,   248,   249,   249,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   263,   263,   263,   263,   264,   264,
     265,   266,   266,   266,   266,   267,   267,   268,   268,   269,
     270,   271,   272,   273,   274,   275,   275,   276,   276,   277,
     277,   278,   279,   279,   280,   280,   281,   282,   283,   283,
     283,   284,   284,   285,   285,   286,   287,   287,   287,   288,
     288,   288,   288,   288,   288,   289,   290,   290,   290,   290,
     290,   291,   291,   292,   292,   293,   293,   294,   294,   294,
     294,   294,   294,   295,   296,   297,   297,   297,   298,   299
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,    10,     1,    10,    10,    10,    10,    10,     3,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     5,     1,     3,     3,     1,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     3,     1,     8,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     1,     1,     3,     1,     1,     1,
       1,     1,     2,     3,     4,     4,     4,     1,     1,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     3,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     6,     1,     3,
       1,     1,     3,     1,     1,     2,     3,     1,     1,     1,
       1,     4,     1,     1,     4,     1,     1,     3,     1,     4,
       8,     1,     3,     1,     3,     1,     3,     3,     1,     1,
       1,     3,     5,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     3,     1,     3,     3,     3,     1,     1,     1,
       1,     3,     6,     1,     3,     1,     1,     3,     1,     1,
       1,     4,     3,     1,     1,     3,     3,     3,     3,     3,
       1,     3,     3,     3,     3,     3,     6,     1,     3,     1,
       1,     1,     3,     6,     1,     3,     1,     1,     1,     1,
       1,     1,     2,     3,     3,     3,     3,     1,     1,     1,
       1,     6,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     3,     3,     3,     3,     2,     1,     3,     1,
       1,     1,     1,     3,     6,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     4,     1,     1,
       1,     1,     4,     1,     4,     1,     3,     1,     1,     1,
       1,     1,     3,     3,     2,     3,     1,     3,     1,     3,
       1,     3,     1,     2,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     3,     1,     1,     8,
       1,     8,     1,     1,     5,     2,     1,     2,     3,     1,
       3,     2,     2,     1,     2,     1,     1,     6,     1,     2,
       4,     3,     1,     1,     3,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     4,     4,
       4,     2,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* TPTP_file: %empty  */
#line 475 "SyntaxBNF.y"
                                  {}
#line 3119 "y.tab.c"
    break;

  case 3: /* TPTP_file: TPTP_file TPTP_input  */
#line 476 "SyntaxBNF.y"
                                           {}
#line 3125 "y.tab.c"
    break;

  case 4: /* TPTP_input: annotated_formula  */
#line 479 "SyntaxBNF.y"
                                        {P_PRINT((yyval.pval));}
#line 3131 "y.tab.c"
    break;

  case 5: /* TPTP_input: include  */
#line 480 "SyntaxBNF.y"
                              {P_PRINT((yyval.pval));}
#line 3137 "y.tab.c"
    break;

  case 6: /* annotated_formula: thf_annotated  */
#line 483 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3143 "y.tab.c"
    break;

  case 7: /* annotated_formula: tff_annotated  */
#line 484 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3149 "y.tab.c"
    break;

  case 8: /* annotated_formula: tcf_annotated  */
#line 485 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3155 "y.tab.c"
    break;

  case 9: /* annotated_formula: fof_annotated  */
#line 486 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3161 "y.tab.c"
    break;

  case 10: /* annotated_formula: cnf_annotated  */
#line 487 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3167 "y.tab.c"
    break;

  case 11: /* annotated_formula: tpi_annotated  */
#line 488 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3173 "y.tab.c"
    break;

  case 12: /* tpi_annotated: _LIT_tpi LPAREN name COMMA formula_role COMMA tpi_formula annotations RPAREN PERIOD  */
#line 491 "SyntaxBNF.y"
                                                                                                          {(yyval.pval) = P_BUILD("tpi_annotated", P_TOKEN("_LIT_tpi ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 3179 "y.tab.c"
    break;

  case 13: /* tpi_formula: fof_formula  */
#line 494 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tpi_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3185 "y.tab.c"
    break;

  case 14: /* thf_annotated: _LIT_thf LPAREN name COMMA formula_role COMMA thf_formula annotations RPAREN PERIOD  */
#line 497 "SyntaxBNF.y"
                                                                                                          {(yyval.pval) = P_BUILD("thf_annotated", P_TOKEN("_LIT_thf ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 3191 "y.tab.c"
    break;

  case 15: /* tff_annotated: _LIT_tff LPAREN name COMMA formula_role COMMA tff_formula annotations RPAREN PERIOD  */
#line 500 "SyntaxBNF.y"
                                                                                                          {(yyval.pval) = P_BUILD("tff_annotated", P_TOKEN("_LIT_tff ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 3197 "y.tab.c"
    break;

  case 16: /* tcf_annotated: _LIT_tcf LPAREN name COMMA formula_role COMMA tcf_formula annotations RPAREN PERIOD  */
#line 503 "SyntaxBNF.y"
                                                                                                          {(yyval.pval) = P_BUILD("tcf_annotated", P_TOKEN("_LIT_tcf ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 3203 "y.tab.c"
    break;

  case 17: /* fof_annotated: _LIT_fof LPAREN name COMMA formula_role COMMA fof_formula annotations RPAREN PERIOD  */
#line 506 "SyntaxBNF.y"
                                                                                                          {(yyval.pval) = P_BUILD("fof_annotated", P_TOKEN("_LIT_fof ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 3209 "y.tab.c"
    break;

  case 18: /* cnf_annotated: _LIT_cnf LPAREN name COMMA formula_role COMMA cnf_formula annotations RPAREN PERIOD  */
#line 509 "SyntaxBNF.y"
                                                                                                          {(yyval.pval) = P_BUILD("cnf_annotated", P_TOKEN("_LIT_cnf ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 3215 "y.tab.c"
    break;

  case 19: /* annotations: COMMA source optional_info  */
#line 512 "SyntaxBNF.y"
                                                 {(yyval.pval) = P_BUILD("annotations", P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3221 "y.tab.c"
    break;

  case 20: /* annotations: nothing  */
#line 513 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("annotations", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3227 "y.tab.c"
    break;

  case 21: /* formula_role: lower_word  */
#line 516 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("formula_role", P_TOKEN("lower_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3233 "y.tab.c"
    break;

  case 22: /* formula_role: _LIT_file  */
#line 517 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("formula_role", P_TOKEN("lower_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3239 "y.tab.c"
    break;

  case 23: /* formula_role: _LIT_inference  */
#line 518 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("formula_role", P_TOKEN("lower_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3245 "y.tab.c"
    break;

  case 24: /* formula_role: _LIT_introduced  */
#line 519 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("formula_role", P_TOKEN("lower_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3251 "y.tab.c"
    break;

  case 25: /* formula_role: lower_word MINUS general_term  */
#line 520 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("formula_role", P_TOKEN("lower_word ", (yyvsp[-2].ival)), P_TOKEN("MINUS ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3257 "y.tab.c"
    break;

  case 26: /* formula_role: _LIT_file MINUS general_term  */
#line 521 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("formula_role", P_TOKEN("lower_word ", (yyvsp[-2].ival)), P_TOKEN("MINUS ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3263 "y.tab.c"
    break;

  case 27: /* formula_role: _LIT_inference MINUS general_term  */
#line 522 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("formula_role", P_TOKEN("lower_word ", (yyvsp[-2].ival)), P_TOKEN("MINUS ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3269 "y.tab.c"
    break;

  case 28: /* formula_role: _LIT_introduced MINUS general_term  */
#line 523 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("formula_role", P_TOKEN("lower_word ", (yyvsp[-2].ival)), P_TOKEN("MINUS ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3275 "y.tab.c"
    break;

  case 29: /* thf_formula: thf_logic_formula  */
#line 526 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3281 "y.tab.c"
    break;

  case 30: /* thf_formula: thf_atom_typing  */
#line 527 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3287 "y.tab.c"
    break;

  case 31: /* thf_formula: thf_subtype  */
#line 528 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("thf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3293 "y.tab.c"
    break;

  case 32: /* thf_logic_formula: thf_unitary_formula  */
#line 531 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3299 "y.tab.c"
    break;

  case 33: /* thf_logic_formula: thf_unary_formula  */
#line 532 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3305 "y.tab.c"
    break;

  case 34: /* thf_logic_formula: thf_binary_formula  */
#line 533 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3311 "y.tab.c"
    break;

  case 35: /* thf_logic_formula: thf_defined_infix  */
#line 534 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3317 "y.tab.c"
    break;

  case 36: /* thf_logic_formula: thf_definition  */
#line 535 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3323 "y.tab.c"
    break;

  case 37: /* thf_logic_formula: thf_sequent  */
#line 536 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3329 "y.tab.c"
    break;

  case 38: /* thf_binary_formula: thf_binary_pair  */
#line 539 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3335 "y.tab.c"
    break;

  case 39: /* thf_binary_formula: thf_binary_list  */
#line 540 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3341 "y.tab.c"
    break;

  case 40: /* thf_binary_formula: thf_binary_type  */
#line 541 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3347 "y.tab.c"
    break;

  case 41: /* thf_binary_pair: thf_unit_formula nonassoc_connective thf_unit_formula  */
#line 544 "SyntaxBNF.y"
                                                                            {(yyval.pval) = P_BUILD("thf_binary_pair", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3353 "y.tab.c"
    break;

  case 42: /* thf_binary_list: thf_or_formula  */
#line 547 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_binary_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3359 "y.tab.c"
    break;

  case 43: /* thf_binary_list: thf_and_formula  */
#line 548 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_binary_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3365 "y.tab.c"
    break;

  case 44: /* thf_binary_list: thf_apply_formula  */
#line 549 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_binary_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3371 "y.tab.c"
    break;

  case 45: /* thf_or_formula: thf_unit_formula VLINE thf_unit_formula  */
#line 552 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3377 "y.tab.c"
    break;

  case 46: /* thf_or_formula: thf_or_formula VLINE thf_unit_formula  */
#line 553 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("thf_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3383 "y.tab.c"
    break;

  case 47: /* thf_and_formula: thf_unit_formula AMPERSAND thf_unit_formula  */
#line 556 "SyntaxBNF.y"
                                                                  {(yyval.pval) = P_BUILD("thf_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3389 "y.tab.c"
    break;

  case 48: /* thf_and_formula: thf_and_formula AMPERSAND thf_unit_formula  */
#line 557 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3395 "y.tab.c"
    break;

  case 49: /* thf_apply_formula: thf_unit_formula AT_SIGN thf_unit_formula  */
#line 560 "SyntaxBNF.y"
                                                                {(yyval.pval) = P_BUILD("thf_apply_formula", (yyvsp[-2].pval), P_TOKEN("AT_SIGN ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3401 "y.tab.c"
    break;

  case 50: /* thf_apply_formula: thf_apply_formula AT_SIGN thf_unit_formula  */
#line 561 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_apply_formula", (yyvsp[-2].pval), P_TOKEN("AT_SIGN ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3407 "y.tab.c"
    break;

  case 51: /* thf_unit_formula: thf_unitary_formula  */
#line 564 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("thf_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3413 "y.tab.c"
    break;

  case 52: /* thf_unit_formula: thf_unary_formula  */
#line 565 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3419 "y.tab.c"
    break;

  case 53: /* thf_unit_formula: thf_defined_infix  */
#line 566 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3425 "y.tab.c"
    break;

  case 54: /* thf_preunit_formula: thf_unitary_formula  */
#line 569 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("thf_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3431 "y.tab.c"
    break;

  case 55: /* thf_preunit_formula: thf_prefix_unary  */
#line 570 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3437 "y.tab.c"
    break;

  case 56: /* thf_unitary_formula: thf_quantified_formula  */
#line 573 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("thf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3443 "y.tab.c"
    break;

  case 57: /* thf_unitary_formula: thf_atomic_formula  */
#line 574 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3449 "y.tab.c"
    break;

  case 58: /* thf_unitary_formula: variable  */
#line 575 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("thf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3455 "y.tab.c"
    break;

  case 59: /* thf_unitary_formula: LPAREN thf_logic_formula RPAREN  */
#line 576 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("thf_unitary_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3461 "y.tab.c"
    break;

  case 60: /* thf_quantified_formula: thf_quantification thf_unit_formula  */
#line 579 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("thf_quantified_formula", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3467 "y.tab.c"
    break;

  case 61: /* thf_quantification: thf_quantifier LBRKT thf_variable_list RBRKT COLON  */
#line 582 "SyntaxBNF.y"
                                                                         {(yyval.pval) = P_BUILD("thf_quantification", (yyvsp[-4].pval), P_TOKEN("LBRKT ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("RBRKT ", (yyvsp[-1].ival)), P_TOKEN("COLON ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL);}
#line 3473 "y.tab.c"
    break;

  case 62: /* thf_variable_list: thf_typed_variable  */
#line 585 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_variable_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3479 "y.tab.c"
    break;

  case 63: /* thf_variable_list: thf_typed_variable COMMA thf_variable_list  */
#line 586 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_variable_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3485 "y.tab.c"
    break;

  case 64: /* thf_typed_variable: variable COLON thf_top_level_type  */
#line 589 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("thf_typed_variable", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3491 "y.tab.c"
    break;

  case 65: /* thf_unary_formula: thf_prefix_unary  */
#line 592 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3497 "y.tab.c"
    break;

  case 66: /* thf_unary_formula: thf_infix_unary  */
#line 593 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3503 "y.tab.c"
    break;

  case 67: /* thf_prefix_unary: thf_unary_connective thf_preunit_formula  */
#line 596 "SyntaxBNF.y"
                                                               {(yyval.pval) = P_BUILD("thf_prefix_unary", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3509 "y.tab.c"
    break;

  case 68: /* thf_infix_unary: thf_unitary_term infix_inequality thf_unitary_term  */
#line 599 "SyntaxBNF.y"
                                                                         {(yyval.pval) = P_BUILD("thf_infix_unary", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3515 "y.tab.c"
    break;

  case 69: /* thf_atomic_formula: thf_plain_atomic  */
#line 602 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3521 "y.tab.c"
    break;

  case 70: /* thf_atomic_formula: thf_defined_atomic  */
#line 603 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3527 "y.tab.c"
    break;

  case 71: /* thf_atomic_formula: thf_system_atomic  */
#line 604 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3533 "y.tab.c"
    break;

  case 72: /* thf_atomic_formula: thf_fof_function  */
#line 605 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3539 "y.tab.c"
    break;

  case 73: /* thf_plain_atomic: constant  */
#line 608 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("thf_plain_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3545 "y.tab.c"
    break;

  case 74: /* thf_plain_atomic: thf_tuple  */
#line 609 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_plain_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3551 "y.tab.c"
    break;

  case 75: /* thf_defined_atomic: defined_constant  */
#line 612 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3557 "y.tab.c"
    break;

  case 76: /* thf_defined_atomic: thf_defined_term  */
#line 613 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3563 "y.tab.c"
    break;

  case 77: /* thf_defined_atomic: LPAREN thf_conn_term RPAREN  */
#line 614 "SyntaxBNF.y"
                                                  {(yyval.pval) = P_BUILD("thf_defined_atomic", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3569 "y.tab.c"
    break;

  case 78: /* thf_defined_atomic: nhf_long_connective  */
#line 615 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3575 "y.tab.c"
    break;

  case 79: /* thf_defined_atomic: thf_let  */
#line 616 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3581 "y.tab.c"
    break;

  case 80: /* thf_defined_term: defined_term  */
#line 619 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("thf_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3587 "y.tab.c"
    break;

  case 81: /* thf_defined_term: th1_defined_term  */
#line 620 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3593 "y.tab.c"
    break;

  case 82: /* thf_defined_infix: thf_unitary_term defined_infix_pred thf_unitary_term  */
#line 623 "SyntaxBNF.y"
                                                                           {(yyval.pval) = P_BUILD("thf_defined_infix", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3599 "y.tab.c"
    break;

  case 83: /* thf_system_atomic: system_constant  */
#line 626 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_system_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3605 "y.tab.c"
    break;

  case 84: /* thf_let: _DLR_let LPAREN thf_let_types COMMA thf_let_defns COMMA thf_logic_formula RPAREN  */
#line 629 "SyntaxBNF.y"
                                                                                                       {(yyval.pval) = P_BUILD("thf_let", P_TOKEN("_DLR_let ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 3611 "y.tab.c"
    break;

  case 85: /* thf_let_types: thf_atom_typing  */
#line 632 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_let_types", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3617 "y.tab.c"
    break;

  case 86: /* thf_let_types: LBRKT thf_atom_typing_list RBRKT  */
#line 633 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("thf_let_types", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3623 "y.tab.c"
    break;

  case 87: /* thf_atom_typing_list: thf_atom_typing  */
#line 636 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_atom_typing_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3629 "y.tab.c"
    break;

  case 88: /* thf_atom_typing_list: thf_atom_typing COMMA thf_atom_typing_list  */
#line 637 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_atom_typing_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3635 "y.tab.c"
    break;

  case 89: /* thf_let_defns: thf_let_defn  */
#line 640 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("thf_let_defns", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3641 "y.tab.c"
    break;

  case 90: /* thf_let_defns: LBRKT thf_let_defn_list RBRKT  */
#line 641 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("thf_let_defns", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3647 "y.tab.c"
    break;

  case 91: /* thf_let_defn: thf_logic_formula assignment thf_logic_formula  */
#line 644 "SyntaxBNF.y"
                                                                     {(yyval.pval) = P_BUILD("thf_let_defn", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3653 "y.tab.c"
    break;

  case 92: /* thf_let_defn_list: thf_let_defn  */
#line 647 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("thf_let_defn_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3659 "y.tab.c"
    break;

  case 93: /* thf_let_defn_list: thf_let_defn COMMA thf_let_defn_list  */
#line 648 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_let_defn_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3665 "y.tab.c"
    break;

  case 94: /* thf_unitary_term: thf_atomic_formula  */
#line 651 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3671 "y.tab.c"
    break;

  case 95: /* thf_unitary_term: variable  */
#line 652 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("thf_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3677 "y.tab.c"
    break;

  case 96: /* thf_unitary_term: LPAREN thf_logic_formula RPAREN  */
#line 653 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("thf_unitary_term", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3683 "y.tab.c"
    break;

  case 97: /* thf_conn_term: nonassoc_connective  */
#line 656 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3689 "y.tab.c"
    break;

  case 98: /* thf_conn_term: assoc_connective  */
#line 657 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3695 "y.tab.c"
    break;

  case 99: /* thf_conn_term: infix_equality  */
#line 658 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3701 "y.tab.c"
    break;

  case 100: /* thf_conn_term: infix_inequality  */
#line 659 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3707 "y.tab.c"
    break;

  case 101: /* thf_conn_term: thf_unary_connective  */
#line 660 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3713 "y.tab.c"
    break;

  case 102: /* thf_tuple: LBRKT RBRKT  */
#line 663 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("thf_tuple", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3719 "y.tab.c"
    break;

  case 103: /* thf_tuple: LBRKT thf_formula_list RBRKT  */
#line 664 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("thf_tuple", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3725 "y.tab.c"
    break;

  case 104: /* thf_fof_function: defined_functor LPAREN thf_arguments RPAREN  */
#line 667 "SyntaxBNF.y"
                                                                  {(yyval.pval) = P_BUILD("thf_fof_function", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3731 "y.tab.c"
    break;

  case 105: /* thf_fof_function: system_functor LPAREN thf_arguments RPAREN  */
#line 668 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_fof_function", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3737 "y.tab.c"
    break;

  case 106: /* thf_fof_function: functor LPAREN thf_arguments RPAREN  */
#line 669 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("thf_fof_function", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3743 "y.tab.c"
    break;

  case 107: /* thf_arguments: thf_formula_list  */
#line 672 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_arguments", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3749 "y.tab.c"
    break;

  case 108: /* thf_formula_list: thf_logic_formula  */
#line 675 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_formula_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3755 "y.tab.c"
    break;

  case 109: /* thf_formula_list: thf_logic_formula COMMA thf_formula_list  */
#line 676 "SyntaxBNF.y"
                                                               {(yyval.pval) = P_BUILD("thf_formula_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3761 "y.tab.c"
    break;

  case 110: /* thf_atom_typing: typeable_atom COLON thf_top_level_type  */
#line 679 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("thf_atom_typing", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3767 "y.tab.c"
    break;

  case 111: /* thf_atom_typing: LPAREN thf_atom_typing RPAREN  */
#line 680 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("thf_atom_typing", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3773 "y.tab.c"
    break;

  case 112: /* thf_top_level_type: thf_unitary_type  */
#line 683 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3779 "y.tab.c"
    break;

  case 113: /* thf_top_level_type: thf_mapping_type  */
#line 684 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3785 "y.tab.c"
    break;

  case 114: /* thf_top_level_type: thf_apply_type  */
#line 685 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3791 "y.tab.c"
    break;

  case 115: /* thf_unitary_type: thf_unitary_formula  */
#line 688 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("thf_unitary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3797 "y.tab.c"
    break;

  case 116: /* thf_apply_type: thf_apply_formula  */
#line 691 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_apply_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3803 "y.tab.c"
    break;

  case 117: /* thf_binary_type: thf_mapping_type  */
#line 694 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_binary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3809 "y.tab.c"
    break;

  case 118: /* thf_binary_type: thf_xprod_type  */
#line 695 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_binary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3815 "y.tab.c"
    break;

  case 119: /* thf_binary_type: thf_union_type  */
#line 696 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_binary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3821 "y.tab.c"
    break;

  case 120: /* thf_mapping_type: thf_unitary_type arrow thf_unitary_type  */
#line 699 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_mapping_type", (yyvsp[-2].pval), P_TOKEN("arrow ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3827 "y.tab.c"
    break;

  case 121: /* thf_mapping_type: thf_unitary_type arrow thf_mapping_type  */
#line 700 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_mapping_type", (yyvsp[-2].pval), P_TOKEN("arrow ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3833 "y.tab.c"
    break;

  case 122: /* thf_xprod_type: thf_unitary_type STAR thf_unitary_type  */
#line 703 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("thf_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3839 "y.tab.c"
    break;

  case 123: /* thf_xprod_type: thf_xprod_type STAR thf_unitary_type  */
#line 704 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3845 "y.tab.c"
    break;

  case 124: /* thf_union_type: thf_unitary_type plus thf_unitary_type  */
#line 707 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("thf_union_type", (yyvsp[-2].pval), P_TOKEN("plus ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3851 "y.tab.c"
    break;

  case 125: /* thf_union_type: thf_union_type plus thf_unitary_type  */
#line 708 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_union_type", (yyvsp[-2].pval), P_TOKEN("plus ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3857 "y.tab.c"
    break;

  case 126: /* thf_subtype: atomic_type subtype_sign atomic_type  */
#line 711 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_subtype", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3863 "y.tab.c"
    break;

  case 127: /* thf_definition: thf_atomic_formula identical thf_logic_formula  */
#line 714 "SyntaxBNF.y"
                                                                     {(yyval.pval) = P_BUILD("thf_definition", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3869 "y.tab.c"
    break;

  case 128: /* thf_sequent: thf_tuple gentzen_arrow thf_tuple  */
#line 717 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("thf_sequent", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3875 "y.tab.c"
    break;

  case 129: /* tff_formula: tff_logic_formula  */
#line 720 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3881 "y.tab.c"
    break;

  case 130: /* tff_formula: tff_atom_typing  */
#line 721 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3887 "y.tab.c"
    break;

  case 131: /* tff_formula: tff_subtype  */
#line 722 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tff_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3893 "y.tab.c"
    break;

  case 132: /* tff_logic_formula: tff_unitary_formula  */
#line 725 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3899 "y.tab.c"
    break;

  case 133: /* tff_logic_formula: tff_unary_formula  */
#line 726 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3905 "y.tab.c"
    break;

  case 134: /* tff_logic_formula: tff_binary_formula  */
#line 727 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3911 "y.tab.c"
    break;

  case 135: /* tff_logic_formula: tff_defined_infix  */
#line 728 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3917 "y.tab.c"
    break;

  case 136: /* tff_logic_formula: txf_definition  */
#line 729 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3923 "y.tab.c"
    break;

  case 137: /* tff_logic_formula: txf_sequent  */
#line 730 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3929 "y.tab.c"
    break;

  case 138: /* tff_binary_formula: tff_binary_pair  */
#line 733 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3935 "y.tab.c"
    break;

  case 139: /* tff_binary_formula: tff_binary_list  */
#line 734 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3941 "y.tab.c"
    break;

  case 140: /* tff_binary_pair: tff_unit_formula nonassoc_connective tff_unit_formula  */
#line 737 "SyntaxBNF.y"
                                                                            {(yyval.pval) = P_BUILD("tff_binary_pair", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3947 "y.tab.c"
    break;

  case 141: /* tff_binary_list: tff_or_formula  */
#line 740 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_binary_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3953 "y.tab.c"
    break;

  case 142: /* tff_binary_list: tff_and_formula  */
#line 741 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_binary_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3959 "y.tab.c"
    break;

  case 143: /* tff_or_formula: tff_unit_formula VLINE tff_unit_formula  */
#line 744 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("tff_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3965 "y.tab.c"
    break;

  case 144: /* tff_or_formula: tff_or_formula VLINE tff_unit_formula  */
#line 745 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("tff_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3971 "y.tab.c"
    break;

  case 145: /* tff_and_formula: tff_unit_formula AMPERSAND tff_unit_formula  */
#line 748 "SyntaxBNF.y"
                                                                  {(yyval.pval) = P_BUILD("tff_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3977 "y.tab.c"
    break;

  case 146: /* tff_and_formula: tff_and_formula AMPERSAND tff_unit_formula  */
#line 749 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("tff_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3983 "y.tab.c"
    break;

  case 147: /* tff_unit_formula: tff_unitary_formula  */
#line 752 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3989 "y.tab.c"
    break;

  case 148: /* tff_unit_formula: tff_unary_formula  */
#line 753 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3995 "y.tab.c"
    break;

  case 149: /* tff_unit_formula: tff_defined_infix  */
#line 754 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4001 "y.tab.c"
    break;

  case 150: /* tff_preunit_formula: tff_unitary_formula  */
#line 757 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4007 "y.tab.c"
    break;

  case 151: /* tff_preunit_formula: tff_prefix_unary  */
#line 758 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4013 "y.tab.c"
    break;

  case 152: /* tff_unitary_formula: tff_quantified_formula  */
#line 761 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("tff_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4019 "y.tab.c"
    break;

  case 153: /* tff_unitary_formula: tff_atomic_formula  */
#line 762 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4025 "y.tab.c"
    break;

  case 154: /* tff_unitary_formula: txf_unitary_formula  */
#line 763 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4031 "y.tab.c"
    break;

  case 155: /* tff_unitary_formula: LPAREN tff_logic_formula RPAREN  */
#line 764 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("tff_unitary_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4037 "y.tab.c"
    break;

  case 156: /* txf_unitary_formula: variable  */
#line 767 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("txf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4043 "y.tab.c"
    break;

  case 157: /* tff_quantified_formula: tff_quantifier LBRKT tff_variable_list RBRKT COLON tff_unit_formula  */
#line 770 "SyntaxBNF.y"
                                                                                             {(yyval.pval) = P_BUILD("tff_quantified_formula", (yyvsp[-5].pval), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 4049 "y.tab.c"
    break;

  case 158: /* tff_variable_list: tff_variable  */
#line 773 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_variable_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4055 "y.tab.c"
    break;

  case 159: /* tff_variable_list: tff_variable COMMA tff_variable_list  */
#line 774 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("tff_variable_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4061 "y.tab.c"
    break;

  case 160: /* tff_variable: tff_typed_variable  */
#line 777 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_variable", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4067 "y.tab.c"
    break;

  case 161: /* tff_variable: variable  */
#line 778 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_variable", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4073 "y.tab.c"
    break;

  case 162: /* tff_typed_variable: variable COLON tff_atomic_type  */
#line 781 "SyntaxBNF.y"
                                                     {(yyval.pval) = P_BUILD("tff_typed_variable", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4079 "y.tab.c"
    break;

  case 163: /* tff_unary_formula: tff_prefix_unary  */
#line 784 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4085 "y.tab.c"
    break;

  case 164: /* tff_unary_formula: tff_infix_unary  */
#line 785 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4091 "y.tab.c"
    break;

  case 165: /* tff_prefix_unary: tff_unary_connective tff_preunit_formula  */
#line 788 "SyntaxBNF.y"
                                                               {(yyval.pval) = P_BUILD("tff_prefix_unary", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4097 "y.tab.c"
    break;

  case 166: /* tff_infix_unary: tff_unitary_term infix_inequality tff_unitary_term  */
#line 791 "SyntaxBNF.y"
                                                                         {(yyval.pval) = P_BUILD("tff_infix_unary", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4103 "y.tab.c"
    break;

  case 167: /* tff_atomic_formula: tff_plain_atomic  */
#line 794 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4109 "y.tab.c"
    break;

  case 168: /* tff_atomic_formula: tff_defined_atomic  */
#line 795 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4115 "y.tab.c"
    break;

  case 169: /* tff_atomic_formula: tff_system_atomic  */
#line 796 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4121 "y.tab.c"
    break;

  case 170: /* tff_plain_atomic: constant  */
#line 799 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_plain_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4127 "y.tab.c"
    break;

  case 171: /* tff_plain_atomic: functor LPAREN tff_arguments RPAREN  */
#line 800 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("tff_plain_atomic", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4133 "y.tab.c"
    break;

  case 172: /* tff_defined_atomic: tff_defined_plain  */
#line 803 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4139 "y.tab.c"
    break;

  case 173: /* tff_defined_plain: defined_constant  */
#line 806 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4145 "y.tab.c"
    break;

  case 174: /* tff_defined_plain: defined_functor LPAREN tff_arguments RPAREN  */
#line 807 "SyntaxBNF.y"
                                                                  {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4151 "y.tab.c"
    break;

  case 175: /* tff_defined_plain: nxf_atom  */
#line 808 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4157 "y.tab.c"
    break;

  case 176: /* tff_defined_plain: txf_let  */
#line 809 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4163 "y.tab.c"
    break;

  case 177: /* tff_defined_infix: tff_unitary_term defined_infix_pred tff_unitary_term  */
#line 812 "SyntaxBNF.y"
                                                                           {(yyval.pval) = P_BUILD("tff_defined_infix", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4169 "y.tab.c"
    break;

  case 178: /* tff_system_atomic: system_constant  */
#line 815 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_system_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4175 "y.tab.c"
    break;

  case 179: /* tff_system_atomic: system_functor LPAREN tff_arguments RPAREN  */
#line 816 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("tff_system_atomic", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4181 "y.tab.c"
    break;

  case 180: /* txf_let: _DLR_let LPAREN txf_let_types COMMA txf_let_defns COMMA tff_term RPAREN  */
#line 819 "SyntaxBNF.y"
                                                                                              {(yyval.pval) = P_BUILD("txf_let", P_TOKEN("_DLR_let ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 4187 "y.tab.c"
    break;

  case 181: /* txf_let_types: tff_atom_typing  */
#line 822 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("txf_let_types", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4193 "y.tab.c"
    break;

  case 182: /* txf_let_types: LBRKT tff_atom_typing_list RBRKT  */
#line 823 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("txf_let_types", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4199 "y.tab.c"
    break;

  case 183: /* tff_atom_typing_list: tff_atom_typing  */
#line 826 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_atom_typing_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4205 "y.tab.c"
    break;

  case 184: /* tff_atom_typing_list: tff_atom_typing COMMA tff_atom_typing_list  */
#line 827 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("tff_atom_typing_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4211 "y.tab.c"
    break;

  case 185: /* txf_let_defns: txf_let_defn  */
#line 830 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("txf_let_defns", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4217 "y.tab.c"
    break;

  case 186: /* txf_let_defns: LBRKT txf_let_defn_list RBRKT  */
#line 831 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("txf_let_defns", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4223 "y.tab.c"
    break;

  case 187: /* txf_let_defn: txf_let_LHS assignment tff_term  */
#line 834 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("txf_let_defn", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4229 "y.tab.c"
    break;

  case 188: /* txf_let_LHS: tff_plain_atomic  */
#line 837 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("txf_let_LHS", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4235 "y.tab.c"
    break;

  case 189: /* txf_let_LHS: txf_tuple  */
#line 838 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("txf_let_LHS", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4241 "y.tab.c"
    break;

  case 190: /* txf_let_defn_list: txf_let_defn  */
#line 841 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("txf_let_defn_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4247 "y.tab.c"
    break;

  case 191: /* txf_let_defn_list: txf_let_defn COMMA txf_let_defn_list  */
#line 842 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("txf_let_defn_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4253 "y.tab.c"
    break;

  case 192: /* nxf_atom: nxf_long_connective AT_SIGN LPAREN tff_arguments RPAREN  */
#line 845 "SyntaxBNF.y"
                                                                              {(yyval.pval) = P_BUILD("nxf_atom", (yyvsp[-4].pval), P_TOKEN("AT_SIGN ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL);}
#line 4259 "y.tab.c"
    break;

  case 193: /* tff_term: tff_logic_formula  */
#line 848 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4265 "y.tab.c"
    break;

  case 194: /* tff_term: defined_term  */
#line 849 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4271 "y.tab.c"
    break;

  case 195: /* tff_term: txf_tuple  */
#line 850 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4277 "y.tab.c"
    break;

  case 196: /* tff_unitary_term: tff_atomic_formula  */
#line 853 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4283 "y.tab.c"
    break;

  case 197: /* tff_unitary_term: defined_term  */
#line 854 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4289 "y.tab.c"
    break;

  case 198: /* tff_unitary_term: txf_tuple  */
#line 855 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4295 "y.tab.c"
    break;

  case 199: /* tff_unitary_term: variable  */
#line 856 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4301 "y.tab.c"
    break;

  case 200: /* tff_unitary_term: LPAREN tff_logic_formula RPAREN  */
#line 857 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("tff_unitary_term", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4307 "y.tab.c"
    break;

  case 201: /* txf_tuple: LBRKT RBRKT  */
#line 860 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("txf_tuple", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4313 "y.tab.c"
    break;

  case 202: /* txf_tuple: LBRKT tff_arguments RBRKT  */
#line 861 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("txf_tuple", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4319 "y.tab.c"
    break;

  case 203: /* tff_arguments: tff_term  */
#line 864 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_arguments", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4325 "y.tab.c"
    break;

  case 204: /* tff_arguments: tff_term COMMA tff_arguments  */
#line 865 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("tff_arguments", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4331 "y.tab.c"
    break;

  case 205: /* tff_atom_typing: typeable_atom COLON tff_top_level_type  */
#line 868 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("tff_atom_typing", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4337 "y.tab.c"
    break;

  case 206: /* tff_atom_typing: LPAREN tff_atom_typing RPAREN  */
#line 869 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("tff_atom_typing", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4343 "y.tab.c"
    break;

  case 207: /* tff_top_level_type: tff_atomic_type  */
#line 872 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4349 "y.tab.c"
    break;

  case 208: /* tff_top_level_type: tff_non_atomic_type  */
#line 873 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4355 "y.tab.c"
    break;

  case 209: /* tff_non_atomic_type: tff_mapping_type  */
#line 876 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_non_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4361 "y.tab.c"
    break;

  case 210: /* tff_non_atomic_type: tf1_quantified_type  */
#line 877 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_non_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4367 "y.tab.c"
    break;

  case 211: /* tff_non_atomic_type: LPAREN tff_non_atomic_type RPAREN  */
#line 878 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("tff_non_atomic_type", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4373 "y.tab.c"
    break;

  case 212: /* tf1_quantified_type: type_quantifier LBRKT tff_variable_list RBRKT COLON tff_monotype  */
#line 881 "SyntaxBNF.y"
                                                                                       {(yyval.pval) = P_BUILD("tf1_quantified_type", (yyvsp[-5].pval), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 4379 "y.tab.c"
    break;

  case 213: /* tff_monotype: tff_atomic_type  */
#line 884 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_monotype", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4385 "y.tab.c"
    break;

  case 214: /* tff_monotype: LPAREN tff_mapping_type RPAREN  */
#line 885 "SyntaxBNF.y"
                                                     {(yyval.pval) = P_BUILD("tff_monotype", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4391 "y.tab.c"
    break;

  case 215: /* tff_monotype: tf1_quantified_type  */
#line 886 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_monotype", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4397 "y.tab.c"
    break;

  case 216: /* tff_unitary_type: tff_atomic_type  */
#line 889 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_unitary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4403 "y.tab.c"
    break;

  case 217: /* tff_unitary_type: LPAREN tff_xprod_type RPAREN  */
#line 890 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("tff_unitary_type", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4409 "y.tab.c"
    break;

  case 218: /* tff_atomic_type: type_constant  */
#line 893 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4415 "y.tab.c"
    break;

  case 219: /* tff_atomic_type: defined_type  */
#line 894 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4421 "y.tab.c"
    break;

  case 220: /* tff_atomic_type: variable  */
#line 895 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4427 "y.tab.c"
    break;

  case 221: /* tff_atomic_type: type_functor LPAREN tff_type_arguments RPAREN  */
#line 896 "SyntaxBNF.y"
                                                                    {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4433 "y.tab.c"
    break;

  case 222: /* tff_atomic_type: LPAREN tff_atomic_type RPAREN  */
#line 897 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("tff_atomic_type", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4439 "y.tab.c"
    break;

  case 223: /* tff_atomic_type: txf_tuple_type  */
#line 898 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4445 "y.tab.c"
    break;

  case 224: /* tff_type_arguments: tff_atomic_type  */
#line 901 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_type_arguments", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4451 "y.tab.c"
    break;

  case 225: /* tff_type_arguments: tff_atomic_type COMMA tff_type_arguments  */
#line 902 "SyntaxBNF.y"
                                                               {(yyval.pval) = P_BUILD("tff_type_arguments", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4457 "y.tab.c"
    break;

  case 226: /* tff_mapping_type: tff_unitary_type arrow tff_atomic_type  */
#line 905 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("tff_mapping_type", (yyvsp[-2].pval), P_TOKEN("arrow ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4463 "y.tab.c"
    break;

  case 227: /* tff_xprod_type: tff_unitary_type STAR tff_atomic_type  */
#line 908 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("tff_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4469 "y.tab.c"
    break;

  case 228: /* tff_xprod_type: tff_xprod_type STAR tff_atomic_type  */
#line 909 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("tff_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4475 "y.tab.c"
    break;

  case 229: /* txf_tuple_type: LBRKT tff_type_list RBRKT  */
#line 912 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("txf_tuple_type", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4481 "y.tab.c"
    break;

  case 230: /* tff_type_list: tff_top_level_type  */
#line 915 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_type_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4487 "y.tab.c"
    break;

  case 231: /* tff_type_list: tff_top_level_type COMMA tff_type_list  */
#line 916 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("tff_type_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4493 "y.tab.c"
    break;

  case 232: /* tff_subtype: atomic_type subtype_sign atomic_type  */
#line 919 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("tff_subtype", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4499 "y.tab.c"
    break;

  case 233: /* txf_definition: tff_atomic_formula identical tff_term  */
#line 922 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("txf_definition", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4505 "y.tab.c"
    break;

  case 234: /* txf_sequent: txf_tuple gentzen_arrow txf_tuple  */
#line 925 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("txf_sequent", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4511 "y.tab.c"
    break;

  case 235: /* nhf_long_connective: LBRACE ntf_connective_name RBRACE  */
#line 928 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("nhf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4517 "y.tab.c"
    break;

  case 236: /* nhf_long_connective: LBRACE ntf_connective_name LPAREN nhf_parameter_list RPAREN RBRACE  */
#line 929 "SyntaxBNF.y"
                                                                                         {(yyval.pval) = P_BUILD("nhf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-5].ival)), (yyvsp[-4].pval), P_TOKEN("LPAREN ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL);}
#line 4523 "y.tab.c"
    break;

  case 237: /* nhf_parameter_list: nhf_parameter  */
#line 932 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("nhf_parameter_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4529 "y.tab.c"
    break;

  case 238: /* nhf_parameter_list: nhf_parameter COMMA nhf_parameter_list  */
#line 933 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("nhf_parameter_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4535 "y.tab.c"
    break;

  case 239: /* nhf_parameter: ntf_index  */
#line 936 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("nhf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4541 "y.tab.c"
    break;

  case 240: /* nhf_parameter: nhf_key_pair  */
#line 937 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("nhf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4547 "y.tab.c"
    break;

  case 241: /* nhf_key_pair: thf_definition  */
#line 940 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("nhf_key_pair", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4553 "y.tab.c"
    break;

  case 242: /* nxf_long_connective: LBRACE ntf_connective_name RBRACE  */
#line 943 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("nxf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4559 "y.tab.c"
    break;

  case 243: /* nxf_long_connective: LBRACE ntf_connective_name LPAREN nxf_parameter_list RPAREN RBRACE  */
#line 944 "SyntaxBNF.y"
                                                                                         {(yyval.pval) = P_BUILD("nxf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-5].ival)), (yyvsp[-4].pval), P_TOKEN("LPAREN ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL);}
#line 4565 "y.tab.c"
    break;

  case 244: /* nxf_parameter_list: nxf_parameter  */
#line 947 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("nxf_parameter_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4571 "y.tab.c"
    break;

  case 245: /* nxf_parameter_list: nxf_parameter COMMA nxf_parameter_list  */
#line 948 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("nxf_parameter_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4577 "y.tab.c"
    break;

  case 246: /* nxf_parameter: ntf_index  */
#line 951 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("nxf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4583 "y.tab.c"
    break;

  case 247: /* nxf_parameter: nxf_key_pair  */
#line 952 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("nxf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4589 "y.tab.c"
    break;

  case 248: /* nxf_key_pair: txf_definition  */
#line 955 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("nxf_key_pair", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4595 "y.tab.c"
    break;

  case 249: /* ntf_connective_name: ntf_defined_connective  */
#line 958 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("ntf_connective_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4601 "y.tab.c"
    break;

  case 250: /* ntf_connective_name: atomic_system_word  */
#line 959 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("ntf_connective_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4607 "y.tab.c"
    break;

  case 251: /* ntf_defined_connective: atomic_defined_word  */
#line 962 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("ntf_defined_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4613 "y.tab.c"
    break;

  case 252: /* ntf_index: hash tff_unitary_term  */
#line 965 "SyntaxBNF.y"
                                            {(yyval.pval) = P_BUILD("ntf_index", P_TOKEN("hash ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4619 "y.tab.c"
    break;

  case 253: /* ntf_short_connective: LBRKT PERIOD RBRKT  */
#line 968 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4625 "y.tab.c"
    break;

  case 254: /* ntf_short_connective: less_sign PERIOD arrow  */
#line 969 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("less_sign ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("arrow ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4631 "y.tab.c"
    break;

  case 255: /* ntf_short_connective: LBRACE PERIOD RBRACE  */
#line 970 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("LBRACE ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4637 "y.tab.c"
    break;

  case 256: /* ntf_short_connective: LPAREN PERIOD RPAREN  */
#line 971 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4643 "y.tab.c"
    break;

  case 257: /* tcf_formula: tcf_logic_formula  */
#line 974 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tcf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4649 "y.tab.c"
    break;

  case 258: /* tcf_formula: tff_atom_typing  */
#line 975 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tcf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4655 "y.tab.c"
    break;

  case 259: /* tcf_logic_formula: tcf_quantified_formula  */
#line 978 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("tcf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4661 "y.tab.c"
    break;

  case 260: /* tcf_logic_formula: cnf_formula  */
#line 979 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tcf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4667 "y.tab.c"
    break;

  case 261: /* tcf_quantified_formula: EXCLAMATION LBRKT tff_variable_list RBRKT COLON tcf_logic_formula  */
#line 982 "SyntaxBNF.y"
                                                                                           {(yyval.pval) = P_BUILD("tcf_quantified_formula", P_TOKEN("EXCLAMATION ", (yyvsp[-5].ival)), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 4673 "y.tab.c"
    break;

  case 262: /* fof_formula: fof_logic_formula  */
#line 985 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("fof_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4679 "y.tab.c"
    break;

  case 263: /* fof_formula: fof_sequent  */
#line 986 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("fof_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4685 "y.tab.c"
    break;

  case 264: /* fof_logic_formula: fof_binary_formula  */
#line 989 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("fof_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4691 "y.tab.c"
    break;

  case 265: /* fof_logic_formula: fof_unary_formula  */
#line 990 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("fof_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4697 "y.tab.c"
    break;

  case 266: /* fof_logic_formula: fof_unitary_formula  */
#line 991 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("fof_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4703 "y.tab.c"
    break;

  case 267: /* fof_binary_formula: fof_binary_pair  */
#line 994 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("fof_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4709 "y.tab.c"
    break;

  case 268: /* fof_binary_formula: fof_binary_list  */
#line 995 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("fof_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4715 "y.tab.c"
    break;

  case 269: /* fof_binary_pair: fof_unit_formula nonassoc_connective fof_unit_formula  */
#line 998 "SyntaxBNF.y"
                                                                            {(yyval.pval) = P_BUILD("fof_binary_pair", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4721 "y.tab.c"
    break;

  case 270: /* fof_binary_list: fof_or_formula  */
#line 1001 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("fof_binary_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4727 "y.tab.c"
    break;

  case 271: /* fof_binary_list: fof_and_formula  */
#line 1002 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("fof_binary_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4733 "y.tab.c"
    break;

  case 272: /* fof_or_formula: fof_unit_formula VLINE fof_unit_formula  */
#line 1005 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("fof_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4739 "y.tab.c"
    break;

  case 273: /* fof_or_formula: fof_or_formula VLINE fof_unit_formula  */
#line 1006 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("fof_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4745 "y.tab.c"
    break;

  case 274: /* fof_and_formula: fof_unit_formula AMPERSAND fof_unit_formula  */
#line 1009 "SyntaxBNF.y"
                                                                  {(yyval.pval) = P_BUILD("fof_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4751 "y.tab.c"
    break;

  case 275: /* fof_and_formula: fof_and_formula AMPERSAND fof_unit_formula  */
#line 1010 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("fof_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4757 "y.tab.c"
    break;

  case 276: /* fof_unary_formula: unary_connective fof_unit_formula  */
#line 1013 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("fof_unary_formula", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4763 "y.tab.c"
    break;

  case 277: /* fof_unary_formula: fof_infix_unary  */
#line 1014 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("fof_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4769 "y.tab.c"
    break;

  case 278: /* fof_infix_unary: fof_term infix_inequality fof_term  */
#line 1017 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("fof_infix_unary", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4775 "y.tab.c"
    break;

  case 279: /* fof_unit_formula: fof_unitary_formula  */
#line 1020 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("fof_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4781 "y.tab.c"
    break;

  case 280: /* fof_unit_formula: fof_unary_formula  */
#line 1021 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("fof_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4787 "y.tab.c"
    break;

  case 281: /* fof_unitary_formula: fof_quantified_formula  */
#line 1024 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("fof_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4793 "y.tab.c"
    break;

  case 282: /* fof_unitary_formula: fof_atomic_formula  */
#line 1025 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("fof_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4799 "y.tab.c"
    break;

  case 283: /* fof_unitary_formula: LPAREN fof_logic_formula RPAREN  */
#line 1026 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("fof_unitary_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4805 "y.tab.c"
    break;

  case 284: /* fof_quantified_formula: fof_quantifier LBRKT fof_variable_list RBRKT COLON fof_unit_formula  */
#line 1029 "SyntaxBNF.y"
                                                                                             {(yyval.pval) = P_BUILD("fof_quantified_formula", (yyvsp[-5].pval), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 4811 "y.tab.c"
    break;

  case 285: /* fof_variable_list: variable  */
#line 1032 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("fof_variable_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4817 "y.tab.c"
    break;

  case 286: /* fof_variable_list: variable COMMA fof_variable_list  */
#line 1033 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("fof_variable_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4823 "y.tab.c"
    break;

  case 287: /* fof_atomic_formula: fof_plain_atomic_formula  */
#line 1036 "SyntaxBNF.y"
                                               {(yyval.pval) = P_BUILD("fof_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4829 "y.tab.c"
    break;

  case 288: /* fof_atomic_formula: fof_defined_atomic_formula  */
#line 1037 "SyntaxBNF.y"
                                                 {(yyval.pval) = P_BUILD("fof_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4835 "y.tab.c"
    break;

  case 289: /* fof_atomic_formula: fof_system_atomic_formula  */
#line 1038 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("fof_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4841 "y.tab.c"
    break;

  case 290: /* fof_plain_atomic_formula: fof_plain_term  */
#line 1041 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("fof_plain_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4847 "y.tab.c"
    break;

  case 291: /* fof_defined_atomic_formula: fof_defined_plain_formula  */
#line 1044 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("fof_defined_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4853 "y.tab.c"
    break;

  case 292: /* fof_defined_atomic_formula: fof_defined_infix_formula  */
#line 1045 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("fof_defined_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4859 "y.tab.c"
    break;

  case 293: /* fof_defined_plain_formula: fof_defined_plain_term  */
#line 1048 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("fof_defined_plain_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4865 "y.tab.c"
    break;

  case 294: /* fof_defined_infix_formula: fof_term defined_infix_pred fof_term  */
#line 1051 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("fof_defined_infix_formula", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4871 "y.tab.c"
    break;

  case 295: /* fof_system_atomic_formula: fof_system_term  */
#line 1054 "SyntaxBNF.y"
                                            {(yyval.pval) = P_BUILD("fof_system_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4877 "y.tab.c"
    break;

  case 296: /* fof_plain_term: constant  */
#line 1057 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("fof_plain_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4883 "y.tab.c"
    break;

  case 297: /* fof_plain_term: functor LPAREN fof_arguments RPAREN  */
#line 1058 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("fof_plain_term", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4889 "y.tab.c"
    break;

  case 298: /* fof_defined_term: defined_term  */
#line 1061 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("fof_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4895 "y.tab.c"
    break;

  case 299: /* fof_defined_term: fof_defined_atomic_term  */
#line 1062 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("fof_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4901 "y.tab.c"
    break;

  case 300: /* fof_defined_atomic_term: fof_defined_plain_term  */
#line 1065 "SyntaxBNF.y"
                                                 {(yyval.pval) = P_BUILD("fof_defined_atomic_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4907 "y.tab.c"
    break;

  case 301: /* fof_defined_plain_term: defined_constant  */
#line 1068 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("fof_defined_plain_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4913 "y.tab.c"
    break;

  case 302: /* fof_defined_plain_term: defined_functor LPAREN fof_arguments RPAREN  */
#line 1069 "SyntaxBNF.y"
                                                                  {(yyval.pval) = P_BUILD("fof_defined_plain_term", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4919 "y.tab.c"
    break;

  case 303: /* fof_system_term: system_constant  */
#line 1072 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("fof_system_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4925 "y.tab.c"
    break;

  case 304: /* fof_system_term: system_functor LPAREN fof_arguments RPAREN  */
#line 1073 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("fof_system_term", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4931 "y.tab.c"
    break;

  case 305: /* fof_arguments: fof_term  */
#line 1076 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("fof_arguments", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4937 "y.tab.c"
    break;

  case 306: /* fof_arguments: fof_term COMMA fof_arguments  */
#line 1077 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("fof_arguments", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4943 "y.tab.c"
    break;

  case 307: /* fof_term: fof_function_term  */
#line 1080 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("fof_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4949 "y.tab.c"
    break;

  case 308: /* fof_term: variable  */
#line 1081 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("fof_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4955 "y.tab.c"
    break;

  case 309: /* fof_function_term: fof_plain_term  */
#line 1084 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("fof_function_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4961 "y.tab.c"
    break;

  case 310: /* fof_function_term: fof_defined_term  */
#line 1085 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("fof_function_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4967 "y.tab.c"
    break;

  case 311: /* fof_function_term: fof_system_term  */
#line 1086 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("fof_function_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4973 "y.tab.c"
    break;

  case 312: /* fof_sequent: fof_formula_tuple gentzen_arrow fof_formula_tuple  */
#line 1089 "SyntaxBNF.y"
                                                                        {(yyval.pval) = P_BUILD("fof_sequent", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4979 "y.tab.c"
    break;

  case 313: /* fof_sequent: LPAREN fof_sequent RPAREN  */
#line 1090 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("fof_sequent", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4985 "y.tab.c"
    break;

  case 314: /* fof_formula_tuple: LBRKT RBRKT  */
#line 1093 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("fof_formula_tuple", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4991 "y.tab.c"
    break;

  case 315: /* fof_formula_tuple: LBRKT fof_formula_tuple_list RBRKT  */
#line 1094 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("fof_formula_tuple", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4997 "y.tab.c"
    break;

  case 316: /* fof_formula_tuple_list: fof_logic_formula  */
#line 1097 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("fof_formula_tuple_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5003 "y.tab.c"
    break;

  case 317: /* fof_formula_tuple_list: fof_logic_formula COMMA fof_formula_tuple_list  */
#line 1098 "SyntaxBNF.y"
                                                                     {(yyval.pval) = P_BUILD("fof_formula_tuple_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5009 "y.tab.c"
    break;

  case 318: /* cnf_formula: cnf_disjunction  */
#line 1101 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("cnf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5015 "y.tab.c"
    break;

  case 319: /* cnf_formula: LPAREN cnf_formula RPAREN  */
#line 1102 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("cnf_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5021 "y.tab.c"
    break;

  case 320: /* cnf_disjunction: cnf_literal  */
#line 1105 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("cnf_disjunction", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5027 "y.tab.c"
    break;

  case 321: /* cnf_disjunction: cnf_disjunction VLINE cnf_literal  */
#line 1106 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("cnf_disjunction", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5033 "y.tab.c"
    break;

  case 322: /* cnf_literal: fof_atomic_formula  */
#line 1109 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("cnf_literal", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5039 "y.tab.c"
    break;

  case 323: /* cnf_literal: TILDE fof_atomic_formula  */
#line 1110 "SyntaxBNF.y"
                                               {(yyval.pval) = P_BUILD("cnf_literal", P_TOKEN("TILDE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5045 "y.tab.c"
    break;

  case 324: /* cnf_literal: TILDE LPAREN fof_atomic_formula RPAREN  */
#line 1111 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("cnf_literal", P_TOKEN("TILDE ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5051 "y.tab.c"
    break;

  case 325: /* cnf_literal: fof_infix_unary  */
#line 1112 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("cnf_literal", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5057 "y.tab.c"
    break;

  case 326: /* thf_quantifier: tff_quantifier  */
#line 1115 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5063 "y.tab.c"
    break;

  case 327: /* thf_quantifier: th0_quantifier  */
#line 1116 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5069 "y.tab.c"
    break;

  case 328: /* thf_quantifier: type_quantifier  */
#line 1117 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5075 "y.tab.c"
    break;

  case 329: /* thf_unary_connective: unary_connective  */
#line 1120 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5081 "y.tab.c"
    break;

  case 330: /* thf_unary_connective: ntf_short_connective  */
#line 1121 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("thf_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5087 "y.tab.c"
    break;

  case 331: /* th0_quantifier: CARET  */
#line 1124 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("th0_quantifier", P_TOKEN("CARET ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5093 "y.tab.c"
    break;

  case 332: /* th0_quantifier: AT_SIGN_PLUS  */
#line 1125 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("th0_quantifier", P_TOKEN("AT_SIGN_PLUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5099 "y.tab.c"
    break;

  case 333: /* th0_quantifier: AT_SIGN_MINUS  */
#line 1126 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("th0_quantifier", P_TOKEN("AT_SIGN_MINUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5105 "y.tab.c"
    break;

  case 334: /* type_quantifier: EXCLAMATION_GREATER  */
#line 1129 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("type_quantifier", P_TOKEN("EXCLAMATION_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5111 "y.tab.c"
    break;

  case 335: /* type_quantifier: QUESTION_STAR  */
#line 1130 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("type_quantifier", P_TOKEN("QUESTION_STAR ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5117 "y.tab.c"
    break;

  case 336: /* subtype_sign: LESS_LESS  */
#line 1133 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("subtype_sign", P_TOKEN("LESS_LESS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5123 "y.tab.c"
    break;

  case 337: /* tff_unary_connective: unary_connective  */
#line 1136 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5129 "y.tab.c"
    break;

  case 338: /* tff_unary_connective: ntf_short_connective  */
#line 1137 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("tff_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5135 "y.tab.c"
    break;

  case 339: /* tff_quantifier: fof_quantifier  */
#line 1140 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5141 "y.tab.c"
    break;

  case 340: /* tff_quantifier: hash  */
#line 1141 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("tff_quantifier", P_TOKEN("hash ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5147 "y.tab.c"
    break;

  case 341: /* fof_quantifier: EXCLAMATION  */
#line 1144 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("fof_quantifier", P_TOKEN("EXCLAMATION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5153 "y.tab.c"
    break;

  case 342: /* fof_quantifier: QUESTION  */
#line 1145 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("fof_quantifier", P_TOKEN("QUESTION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5159 "y.tab.c"
    break;

  case 343: /* nonassoc_connective: LESS_EQUALS_GREATER  */
#line 1148 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("LESS_EQUALS_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5165 "y.tab.c"
    break;

  case 344: /* nonassoc_connective: EQUALS_GREATER  */
#line 1149 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("EQUALS_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5171 "y.tab.c"
    break;

  case 345: /* nonassoc_connective: LESS_EQUALS  */
#line 1150 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("LESS_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5177 "y.tab.c"
    break;

  case 346: /* nonassoc_connective: LESS_TILDE_GREATER  */
#line 1151 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("LESS_TILDE_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5183 "y.tab.c"
    break;

  case 347: /* nonassoc_connective: TILDE_VLINE  */
#line 1152 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("TILDE_VLINE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5189 "y.tab.c"
    break;

  case 348: /* nonassoc_connective: TILDE_AMPERSAND  */
#line 1153 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("TILDE_AMPERSAND ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5195 "y.tab.c"
    break;

  case 349: /* assoc_connective: VLINE  */
#line 1156 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("assoc_connective", P_TOKEN("VLINE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5201 "y.tab.c"
    break;

  case 350: /* assoc_connective: AMPERSAND  */
#line 1157 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("assoc_connective", P_TOKEN("AMPERSAND ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5207 "y.tab.c"
    break;

  case 351: /* unary_connective: TILDE  */
#line 1160 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("unary_connective", P_TOKEN("TILDE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5213 "y.tab.c"
    break;

  case 352: /* gentzen_arrow: MINUS_MINUS_GREATER  */
#line 1163 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("gentzen_arrow", P_TOKEN("MINUS_MINUS_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5219 "y.tab.c"
    break;

  case 353: /* assignment: COLON_EQUALS  */
#line 1166 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("assignment", P_TOKEN("COLON_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5225 "y.tab.c"
    break;

  case 354: /* identical: EQUALS_EQUALS  */
#line 1169 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("identical", P_TOKEN("EQUALS_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5231 "y.tab.c"
    break;

  case 355: /* typeable_atom: constant  */
#line 1172 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("typeable_atom", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5237 "y.tab.c"
    break;

  case 356: /* typeable_atom: distinct_object  */
#line 1173 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("typeable_atom", P_TOKEN("distinct_object ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5243 "y.tab.c"
    break;

  case 357: /* atomic_type: typeable_atom  */
#line 1176 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5249 "y.tab.c"
    break;

  case 358: /* atomic_type: defined_constant  */
#line 1177 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5255 "y.tab.c"
    break;

  case 359: /* atomic_type: system_type  */
#line 1178 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5261 "y.tab.c"
    break;

  case 360: /* type_constant: type_functor  */
#line 1181 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("type_constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5267 "y.tab.c"
    break;

  case 361: /* type_functor: atomic_word  */
#line 1184 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("type_functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5273 "y.tab.c"
    break;

  case 362: /* defined_type: atomic_defined_word  */
#line 1187 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("defined_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5279 "y.tab.c"
    break;

  case 363: /* system_type: atomic_system_word  */
#line 1190 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("system_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5285 "y.tab.c"
    break;

  case 364: /* defined_infix_pred: infix_equality  */
#line 1193 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("defined_infix_pred", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5291 "y.tab.c"
    break;

  case 365: /* infix_equality: EQUALS  */
#line 1196 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("infix_equality", P_TOKEN("EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5297 "y.tab.c"
    break;

  case 366: /* infix_inequality: EXCLAMATION_EQUALS  */
#line 1199 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("infix_inequality", P_TOKEN("EXCLAMATION_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5303 "y.tab.c"
    break;

  case 367: /* constant: functor  */
#line 1202 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5309 "y.tab.c"
    break;

  case 368: /* functor: atomic_word  */
#line 1205 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5315 "y.tab.c"
    break;

  case 369: /* defined_constant: defined_functor  */
#line 1208 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("defined_constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5321 "y.tab.c"
    break;

  case 370: /* defined_functor: atomic_defined_word  */
#line 1211 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("defined_functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5327 "y.tab.c"
    break;

  case 371: /* system_constant: system_functor  */
#line 1214 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("system_constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5333 "y.tab.c"
    break;

  case 372: /* system_functor: atomic_system_word  */
#line 1217 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("system_functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5339 "y.tab.c"
    break;

  case 373: /* th1_defined_term: EXCLAMATION_EXCLAMATION  */
#line 1220 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("EXCLAMATION_EXCLAMATION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5345 "y.tab.c"
    break;

  case 374: /* th1_defined_term: QUESTION_QUESTION  */
#line 1221 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("QUESTION_QUESTION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5351 "y.tab.c"
    break;

  case 375: /* th1_defined_term: AT_AT_SIGN_PLUS  */
#line 1222 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("AT_AT_SIGN_PLUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5357 "y.tab.c"
    break;

  case 376: /* th1_defined_term: AT_AT_SIGN_MINUS  */
#line 1223 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("AT_AT_SIGN_MINUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5363 "y.tab.c"
    break;

  case 377: /* th1_defined_term: AT_SIGN_EQUALS  */
#line 1224 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("AT_SIGN_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5369 "y.tab.c"
    break;

  case 378: /* defined_term: number  */
#line 1227 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5375 "y.tab.c"
    break;

  case 379: /* defined_term: distinct_object  */
#line 1228 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("defined_term", P_TOKEN("distinct_object ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5381 "y.tab.c"
    break;

  case 380: /* variable: upper_word  */
#line 1231 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("variable", P_TOKEN("upper_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5387 "y.tab.c"
    break;

  case 381: /* source: dag_source  */
#line 1234 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5393 "y.tab.c"
    break;

  case 382: /* source: internal_source  */
#line 1235 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5399 "y.tab.c"
    break;

  case 383: /* source: external_source  */
#line 1236 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5405 "y.tab.c"
    break;

  case 384: /* source: LBRKT sources RBRKT  */
#line 1237 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("source", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5411 "y.tab.c"
    break;

  case 385: /* sources: source  */
#line 1240 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("sources", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5417 "y.tab.c"
    break;

  case 386: /* sources: source COMMA sources  */
#line 1241 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("sources", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5423 "y.tab.c"
    break;

  case 387: /* dag_source: name  */
#line 1244 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("dag_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5429 "y.tab.c"
    break;

  case 388: /* dag_source: inference_record  */
#line 1245 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("dag_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5435 "y.tab.c"
    break;

  case 389: /* inference_record: _LIT_inference LPAREN inference_rule COMMA useful_info COMMA parents RPAREN  */
#line 1248 "SyntaxBNF.y"
                                                                                                  {(yyval.pval) = P_BUILD("inference_record", P_TOKEN("_LIT_inference ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 5441 "y.tab.c"
    break;

  case 390: /* inference_rule: atomic_word  */
#line 1251 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("inference_rule", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5447 "y.tab.c"
    break;

  case 391: /* internal_source: _LIT_introduced LPAREN intro_type COMMA useful_info COMMA parents RPAREN  */
#line 1254 "SyntaxBNF.y"
                                                                                               {(yyval.pval) = P_BUILD("internal_source", P_TOKEN("_LIT_introduced ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 5453 "y.tab.c"
    break;

  case 392: /* intro_type: atomic_word  */
#line 1257 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("intro_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5459 "y.tab.c"
    break;

  case 393: /* external_source: file_source  */
#line 1260 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("external_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5465 "y.tab.c"
    break;

  case 394: /* file_source: _LIT_file LPAREN file_name file_info RPAREN  */
#line 1263 "SyntaxBNF.y"
                                                                  {(yyval.pval) = P_BUILD("file_source", P_TOKEN("_LIT_file ", (yyvsp[-4].ival)), P_TOKEN("LPAREN ", (yyvsp[-3].ival)), (yyvsp[-2].pval), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL);}
#line 5471 "y.tab.c"
    break;

  case 395: /* file_info: COMMA name  */
#line 1266 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("file_info", P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5477 "y.tab.c"
    break;

  case 396: /* file_info: nothing  */
#line 1267 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("file_info", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5483 "y.tab.c"
    break;

  case 397: /* parents: LBRKT RBRKT  */
#line 1270 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("parents", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5489 "y.tab.c"
    break;

  case 398: /* parents: LBRKT parent_list RBRKT  */
#line 1271 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("parents", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5495 "y.tab.c"
    break;

  case 399: /* parent_list: parent_info  */
#line 1274 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("parent_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5501 "y.tab.c"
    break;

  case 400: /* parent_list: parent_info COMMA parent_list  */
#line 1275 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("parent_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5507 "y.tab.c"
    break;

  case 401: /* parent_info: source parent_details  */
#line 1278 "SyntaxBNF.y"
                                            {(yyval.pval) = P_BUILD("parent_info", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5513 "y.tab.c"
    break;

  case 402: /* parent_details: COLON general_term  */
#line 1281 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("parent_details", P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5519 "y.tab.c"
    break;

  case 403: /* parent_details: nothing  */
#line 1282 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("parent_details", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5525 "y.tab.c"
    break;

  case 404: /* optional_info: COMMA useful_info  */
#line 1285 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("optional_info", P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5531 "y.tab.c"
    break;

  case 405: /* optional_info: nothing  */
#line 1286 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("optional_info", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5537 "y.tab.c"
    break;

  case 406: /* useful_info: general_list  */
#line 1289 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("useful_info", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5543 "y.tab.c"
    break;

  case 407: /* include: _LIT_include LPAREN file_name include_optionals RPAREN PERIOD  */
#line 1292 "SyntaxBNF.y"
                                                                                    {(yyval.pval) = P_BUILD("include", P_TOKEN("_LIT_include ", (yyvsp[-5].ival)), P_TOKEN("LPAREN ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL);}
#line 5549 "y.tab.c"
    break;

  case 408: /* include_optionals: nothing  */
#line 1295 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("include_optionals", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5555 "y.tab.c"
    break;

  case 409: /* include_optionals: COMMA formula_selection  */
#line 1296 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("include_optionals", P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5561 "y.tab.c"
    break;

  case 410: /* include_optionals: COMMA formula_selection COMMA space_name  */
#line 1297 "SyntaxBNF.y"
                                                               {(yyval.pval) = P_BUILD("include_optionals", P_TOKEN("COMMA ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5567 "y.tab.c"
    break;

  case 411: /* formula_selection: LBRKT name_list RBRKT  */
#line 1300 "SyntaxBNF.y"
                                            {(yyval.pval) = P_BUILD("formula_selection", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5573 "y.tab.c"
    break;

  case 412: /* formula_selection: STAR  */
#line 1301 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("formula_selection", P_TOKEN("STAR ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5579 "y.tab.c"
    break;

  case 413: /* name_list: name  */
#line 1304 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("name_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5585 "y.tab.c"
    break;

  case 414: /* name_list: name COMMA name_list  */
#line 1305 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("name_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5591 "y.tab.c"
    break;

  case 415: /* space_name: name  */
#line 1308 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("space_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5597 "y.tab.c"
    break;

  case 416: /* general_term: general_data  */
#line 1311 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("general_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5603 "y.tab.c"
    break;

  case 417: /* general_term: general_data COLON general_term  */
#line 1312 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("general_term", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5609 "y.tab.c"
    break;

  case 418: /* general_term: general_list  */
#line 1313 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("general_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5615 "y.tab.c"
    break;

  case 419: /* general_data: atomic_word  */
#line 1316 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5621 "y.tab.c"
    break;

  case 420: /* general_data: general_function  */
#line 1317 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5627 "y.tab.c"
    break;

  case 421: /* general_data: variable  */
#line 1318 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5633 "y.tab.c"
    break;

  case 422: /* general_data: number  */
#line 1319 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5639 "y.tab.c"
    break;

  case 423: /* general_data: distinct_object  */
#line 1320 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("general_data", P_TOKEN("distinct_object ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5645 "y.tab.c"
    break;

  case 424: /* general_data: formula_data  */
#line 1321 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5651 "y.tab.c"
    break;

  case 425: /* general_function: atomic_word LPAREN general_terms RPAREN  */
#line 1324 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("general_function", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5657 "y.tab.c"
    break;

  case 426: /* formula_data: _DLR_thf LPAREN thf_formula RPAREN  */
#line 1327 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_thf ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5663 "y.tab.c"
    break;

  case 427: /* formula_data: _DLR_tff LPAREN tff_formula RPAREN  */
#line 1328 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_tff ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5669 "y.tab.c"
    break;

  case 428: /* formula_data: _DLR_fof LPAREN fof_formula RPAREN  */
#line 1329 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_fof ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5675 "y.tab.c"
    break;

  case 429: /* formula_data: _DLR_cnf LPAREN cnf_formula RPAREN  */
#line 1330 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_cnf ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5681 "y.tab.c"
    break;

  case 430: /* formula_data: _DLR_fot LPAREN fof_term RPAREN  */
#line 1331 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_fot ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5687 "y.tab.c"
    break;

  case 431: /* general_list: LBRKT RBRKT  */
#line 1334 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("general_list", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5693 "y.tab.c"
    break;

  case 432: /* general_list: LBRKT general_terms RBRKT  */
#line 1335 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("general_list", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5699 "y.tab.c"
    break;

  case 433: /* general_terms: general_term  */
#line 1338 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("general_terms", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5705 "y.tab.c"
    break;

  case 434: /* general_terms: general_term COMMA general_terms  */
#line 1339 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("general_terms", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5711 "y.tab.c"
    break;

  case 435: /* name: atomic_word  */
#line 1342 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5717 "y.tab.c"
    break;

  case 436: /* name: integer  */
#line 1343 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("name", P_TOKEN("integer ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5723 "y.tab.c"
    break;

  case 437: /* atomic_word: lower_word  */
#line 1346 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("atomic_word", P_TOKEN("lower_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5729 "y.tab.c"
    break;

  case 438: /* atomic_word: _LIT_file  */
#line 1347 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("atomic_word", P_TOKEN("lower_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5735 "y.tab.c"
    break;

  case 439: /* atomic_word: _LIT_inference  */
#line 1348 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("atomic_word", P_TOKEN("lower_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5741 "y.tab.c"
    break;

  case 440: /* atomic_word: _LIT_introduced  */
#line 1349 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("atomic_word", P_TOKEN("lower_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5747 "y.tab.c"
    break;

  case 441: /* atomic_word: single_quoted  */
#line 1350 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("atomic_word", P_TOKEN("single_quoted ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5753 "y.tab.c"
    break;

  case 442: /* atomic_word: back_quoted  */
#line 1351 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("atomic_word", P_TOKEN("back_quoted ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5759 "y.tab.c"
    break;

  case 443: /* atomic_defined_word: dollar_word  */
#line 1354 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("atomic_defined_word", P_TOKEN("dollar_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5765 "y.tab.c"
    break;

  case 444: /* atomic_system_word: dollar_dollar_word  */
#line 1357 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("atomic_system_word", P_TOKEN("dollar_dollar_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5771 "y.tab.c"
    break;

  case 445: /* number: integer  */
#line 1360 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("number", P_TOKEN("integer ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5777 "y.tab.c"
    break;

  case 446: /* number: rational  */
#line 1361 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("number", P_TOKEN("rational ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5783 "y.tab.c"
    break;

  case 447: /* number: real  */
#line 1362 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("number", P_TOKEN("real ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5789 "y.tab.c"
    break;

  case 448: /* file_name: atomic_word  */
#line 1365 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("file_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5795 "y.tab.c"
    break;

  case 449: /* nothing: %empty  */
#line 1368 "SyntaxBNF.y"
                      {(yyval.pval) = P_BUILD("nothing",NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5801 "y.tab.c"
    break;


#line 5805 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

