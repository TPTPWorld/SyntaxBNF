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
//-----------------------------------------------------------------------------
int yylex();
//-----------------------------------------------------------------------------
//----Compile with -DP_VERBOSE=1 for verbose output.
#ifndef P_VERBOSE
#  define P_VERBOSE 0
#endif
int verbose = P_VERBOSE;

#define YYMAXDEPTH 32768

//----Compile with -DP_USERPROC=1 to #include p_user_proc.c. p_user_proc.c 
//----should #define P_ACT, P_BUILD, P_TOKEN, P_PRINT to different procedures 
//----from those below, and supply code.
#ifdef P_USERPROC
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

extern int tptp_store_size;
extern char* tptp_lval[];

#define MAX_CHILDREN 1200
typedef struct pTreeNode * pTree;
struct pTreeNode {
    char* symbol; 
    int symbolIndex; 
    pTree children[MAX_CHILDREN+1];
};
//-----------------------------------------------------------------------------
int yyerror( char *s ) { 

    fprintf( stderr, "%s in line %d at item \"%s\".\n", s, yylineno, yytext); 
    return(0);
}
//-----------------------------------------------------------------------------
pTree pBuildTree(char* symbol,pTree A,pTree B,pTree C,pTree D,pTree E,pTree F, 
pTree G, pTree H, pTree I, pTree J) { 

    pTree ss = (pTree)calloc(1,sizeof(struct pTreeNode));

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

    char pTokenBuf[8240];
    pTree ss;
    char* symbol = tptp_lval[symbolIndex];
    char* safeSym;

    strncpy(pTokenBuf, token, 39);
    strncat(pTokenBuf, symbol, 8193);
    safeSym = strdup(pTokenBuf);
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

#line 221 "y.tab.c"

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
    _LIT_creator = 304,            /* _LIT_creator  */
    _LIT_file = 305,               /* _LIT_file  */
    _LIT_fof = 306,                /* _LIT_fof  */
    _LIT_include = 307,            /* _LIT_include  */
    _LIT_inference = 308,          /* _LIT_inference  */
    _LIT_introduced = 309,         /* _LIT_introduced  */
    _LIT_tcf = 310,                /* _LIT_tcf  */
    _LIT_tff = 311,                /* _LIT_tff  */
    _LIT_theory = 312,             /* _LIT_theory  */
    _LIT_thf = 313,                /* _LIT_thf  */
    _LIT_tpi = 314,                /* _LIT_tpi  */
    _LIT_unknown = 315,            /* _LIT_unknown  */
    arrow = 316,                   /* arrow  */
    decimal = 317,                 /* decimal  */
    decimal_exponent = 318,        /* decimal_exponent  */
    decimal_fraction = 319,        /* decimal_fraction  */
    distinct_object = 320,         /* distinct_object  */
    dollar_dollar_word = 321,      /* dollar_dollar_word  */
    dollar_word = 322,             /* dollar_word  */
    dot_decimal = 323,             /* dot_decimal  */
    exp_integer = 324,             /* exp_integer  */
    hash = 325,                    /* hash  */
    integer = 326,                 /* integer  */
    less_sign = 327,               /* less_sign  */
    lower_word = 328,              /* lower_word  */
    plus = 329,                    /* plus  */
    positive_decimal = 330,        /* positive_decimal  */
    rational = 331,                /* rational  */
    real = 332,                    /* real  */
    signed_exp_integer = 333,      /* signed_exp_integer  */
    signed_integer = 334,          /* signed_integer  */
    signed_rational = 335,         /* signed_rational  */
    signed_real = 336,             /* signed_real  */
    single_quoted = 337,           /* single_quoted  */
    slash = 338,                   /* slash  */
    slosh = 339,                   /* slosh  */
    star = 340,                    /* star  */
    unrecognized = 341,            /* unrecognized  */
    unsigned_exp_integer = 342,    /* unsigned_exp_integer  */
    unsigned_integer = 343,        /* unsigned_integer  */
    unsigned_rational = 344,       /* unsigned_rational  */
    unsigned_real = 345,           /* unsigned_real  */
    upper_word = 346,              /* upper_word  */
    vline = 347                    /* vline  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define AMPERSAND 258
#define AT_AT_SIGN_MINUS 259
#define AT_AT_SIGN_PLUS 260
#define AT_SIGN 261
#define AT_SIGN_EQUALS 262
#define AT_SIGN_MINUS 263
#define AT_SIGN_PLUS 264
#define CARET 265
#define COLON 266
#define COLON_EQUALS 267
#define COMMA 268
#define EQUALS 269
#define EQUALS_EQUALS 270
#define EQUALS_GREATER 271
#define EXCLAMATION 272
#define EXCLAMATION_EQUALS 273
#define EXCLAMATION_EXCLAMATION 274
#define EXCLAMATION_GREATER 275
#define LBRACE 276
#define LBRKT 277
#define LESS_EQUALS 278
#define LESS_EQUALS_GREATER 279
#define LESS_LESS 280
#define LESS_TILDE_GREATER 281
#define LPAREN 282
#define MINUS 283
#define MINUS_MINUS_GREATER 284
#define PERIOD 285
#define QUESTION 286
#define QUESTION_QUESTION 287
#define QUESTION_STAR 288
#define RBRACE 289
#define RBRKT 290
#define RPAREN 291
#define STAR 292
#define TILDE 293
#define TILDE_AMPERSAND 294
#define TILDE_VLINE 295
#define VLINE 296
#define _DLR_cnf 297
#define _DLR_fof 298
#define _DLR_fot 299
#define _DLR_let 300
#define _DLR_tff 301
#define _DLR_thf 302
#define _LIT_cnf 303
#define _LIT_creator 304
#define _LIT_file 305
#define _LIT_fof 306
#define _LIT_include 307
#define _LIT_inference 308
#define _LIT_introduced 309
#define _LIT_tcf 310
#define _LIT_tff 311
#define _LIT_theory 312
#define _LIT_thf 313
#define _LIT_tpi 314
#define _LIT_unknown 315
#define arrow 316
#define decimal 317
#define decimal_exponent 318
#define decimal_fraction 319
#define distinct_object 320
#define dollar_dollar_word 321
#define dollar_word 322
#define dot_decimal 323
#define exp_integer 324
#define hash 325
#define integer 326
#define less_sign 327
#define lower_word 328
#define plus 329
#define positive_decimal 330
#define rational 331
#define real 332
#define signed_exp_integer 333
#define signed_integer 334
#define signed_rational 335
#define signed_real 336
#define single_quoted 337
#define slash 338
#define slosh 339
#define star 340
#define unrecognized 341
#define unsigned_exp_integer 342
#define unsigned_integer 343
#define unsigned_rational 344
#define unsigned_real 345
#define upper_word 346
#define vline 347

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 152 "SyntaxBNF.y"
int ival; double dval; char* sval; void* pval;

#line 461 "y.tab.c"

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
  YYSYMBOL__LIT_creator = 49,              /* _LIT_creator  */
  YYSYMBOL__LIT_file = 50,                 /* _LIT_file  */
  YYSYMBOL__LIT_fof = 51,                  /* _LIT_fof  */
  YYSYMBOL__LIT_include = 52,              /* _LIT_include  */
  YYSYMBOL__LIT_inference = 53,            /* _LIT_inference  */
  YYSYMBOL__LIT_introduced = 54,           /* _LIT_introduced  */
  YYSYMBOL__LIT_tcf = 55,                  /* _LIT_tcf  */
  YYSYMBOL__LIT_tff = 56,                  /* _LIT_tff  */
  YYSYMBOL__LIT_theory = 57,               /* _LIT_theory  */
  YYSYMBOL__LIT_thf = 58,                  /* _LIT_thf  */
  YYSYMBOL__LIT_tpi = 59,                  /* _LIT_tpi  */
  YYSYMBOL__LIT_unknown = 60,              /* _LIT_unknown  */
  YYSYMBOL_arrow = 61,                     /* arrow  */
  YYSYMBOL_decimal = 62,                   /* decimal  */
  YYSYMBOL_decimal_exponent = 63,          /* decimal_exponent  */
  YYSYMBOL_decimal_fraction = 64,          /* decimal_fraction  */
  YYSYMBOL_distinct_object = 65,           /* distinct_object  */
  YYSYMBOL_dollar_dollar_word = 66,        /* dollar_dollar_word  */
  YYSYMBOL_dollar_word = 67,               /* dollar_word  */
  YYSYMBOL_dot_decimal = 68,               /* dot_decimal  */
  YYSYMBOL_exp_integer = 69,               /* exp_integer  */
  YYSYMBOL_hash = 70,                      /* hash  */
  YYSYMBOL_integer = 71,                   /* integer  */
  YYSYMBOL_less_sign = 72,                 /* less_sign  */
  YYSYMBOL_lower_word = 73,                /* lower_word  */
  YYSYMBOL_plus = 74,                      /* plus  */
  YYSYMBOL_positive_decimal = 75,          /* positive_decimal  */
  YYSYMBOL_rational = 76,                  /* rational  */
  YYSYMBOL_real = 77,                      /* real  */
  YYSYMBOL_signed_exp_integer = 78,        /* signed_exp_integer  */
  YYSYMBOL_signed_integer = 79,            /* signed_integer  */
  YYSYMBOL_signed_rational = 80,           /* signed_rational  */
  YYSYMBOL_signed_real = 81,               /* signed_real  */
  YYSYMBOL_single_quoted = 82,             /* single_quoted  */
  YYSYMBOL_slash = 83,                     /* slash  */
  YYSYMBOL_slosh = 84,                     /* slosh  */
  YYSYMBOL_star = 85,                      /* star  */
  YYSYMBOL_unrecognized = 86,              /* unrecognized  */
  YYSYMBOL_unsigned_exp_integer = 87,      /* unsigned_exp_integer  */
  YYSYMBOL_unsigned_integer = 88,          /* unsigned_integer  */
  YYSYMBOL_unsigned_rational = 89,         /* unsigned_rational  */
  YYSYMBOL_unsigned_real = 90,             /* unsigned_real  */
  YYSYMBOL_upper_word = 91,                /* upper_word  */
  YYSYMBOL_vline = 92,                     /* vline  */
  YYSYMBOL_YYACCEPT = 93,                  /* $accept  */
  YYSYMBOL_TPTP_file = 94,                 /* TPTP_file  */
  YYSYMBOL_TPTP_input = 95,                /* TPTP_input  */
  YYSYMBOL_annotated_formula = 96,         /* annotated_formula  */
  YYSYMBOL_tpi_annotated = 97,             /* tpi_annotated  */
  YYSYMBOL_tpi_formula = 98,               /* tpi_formula  */
  YYSYMBOL_thf_annotated = 99,             /* thf_annotated  */
  YYSYMBOL_tff_annotated = 100,            /* tff_annotated  */
  YYSYMBOL_tcf_annotated = 101,            /* tcf_annotated  */
  YYSYMBOL_fof_annotated = 102,            /* fof_annotated  */
  YYSYMBOL_cnf_annotated = 103,            /* cnf_annotated  */
  YYSYMBOL_annotations = 104,              /* annotations  */
  YYSYMBOL_formula_role = 105,             /* formula_role  */
  YYSYMBOL_thf_formula = 106,              /* thf_formula  */
  YYSYMBOL_thf_logic_formula = 107,        /* thf_logic_formula  */
  YYSYMBOL_thf_binary_formula = 108,       /* thf_binary_formula  */
  YYSYMBOL_thf_binary_nonassoc = 109,      /* thf_binary_nonassoc  */
  YYSYMBOL_thf_binary_assoc = 110,         /* thf_binary_assoc  */
  YYSYMBOL_thf_or_formula = 111,           /* thf_or_formula  */
  YYSYMBOL_thf_and_formula = 112,          /* thf_and_formula  */
  YYSYMBOL_thf_apply_formula = 113,        /* thf_apply_formula  */
  YYSYMBOL_thf_unit_formula = 114,         /* thf_unit_formula  */
  YYSYMBOL_thf_preunit_formula = 115,      /* thf_preunit_formula  */
  YYSYMBOL_thf_unitary_formula = 116,      /* thf_unitary_formula  */
  YYSYMBOL_thf_quantified_formula = 117,   /* thf_quantified_formula  */
  YYSYMBOL_thf_quantification = 118,       /* thf_quantification  */
  YYSYMBOL_thf_variable_list = 119,        /* thf_variable_list  */
  YYSYMBOL_thf_typed_variable = 120,       /* thf_typed_variable  */
  YYSYMBOL_thf_unary_formula = 121,        /* thf_unary_formula  */
  YYSYMBOL_thf_prefix_unary = 122,         /* thf_prefix_unary  */
  YYSYMBOL_thf_infix_unary = 123,          /* thf_infix_unary  */
  YYSYMBOL_thf_atomic_formula = 124,       /* thf_atomic_formula  */
  YYSYMBOL_thf_plain_atomic = 125,         /* thf_plain_atomic  */
  YYSYMBOL_thf_defined_atomic = 126,       /* thf_defined_atomic  */
  YYSYMBOL_thf_defined_term = 127,         /* thf_defined_term  */
  YYSYMBOL_thf_defined_infix = 128,        /* thf_defined_infix  */
  YYSYMBOL_thf_system_atomic = 129,        /* thf_system_atomic  */
  YYSYMBOL_thf_let = 130,                  /* thf_let  */
  YYSYMBOL_thf_let_types = 131,            /* thf_let_types  */
  YYSYMBOL_thf_atom_typing_list = 132,     /* thf_atom_typing_list  */
  YYSYMBOL_thf_let_defns = 133,            /* thf_let_defns  */
  YYSYMBOL_thf_let_defn = 134,             /* thf_let_defn  */
  YYSYMBOL_thf_let_defn_list = 135,        /* thf_let_defn_list  */
  YYSYMBOL_thf_unitary_term = 136,         /* thf_unitary_term  */
  YYSYMBOL_thf_conn_term = 137,            /* thf_conn_term  */
  YYSYMBOL_thf_tuple = 138,                /* thf_tuple  */
  YYSYMBOL_thf_fof_function = 139,         /* thf_fof_function  */
  YYSYMBOL_thf_arguments = 140,            /* thf_arguments  */
  YYSYMBOL_thf_formula_list = 141,         /* thf_formula_list  */
  YYSYMBOL_thf_atom_typing = 142,          /* thf_atom_typing  */
  YYSYMBOL_thf_top_level_type = 143,       /* thf_top_level_type  */
  YYSYMBOL_thf_unitary_type = 144,         /* thf_unitary_type  */
  YYSYMBOL_thf_apply_type = 145,           /* thf_apply_type  */
  YYSYMBOL_thf_binary_type = 146,          /* thf_binary_type  */
  YYSYMBOL_thf_mapping_type = 147,         /* thf_mapping_type  */
  YYSYMBOL_thf_xprod_type = 148,           /* thf_xprod_type  */
  YYSYMBOL_thf_union_type = 149,           /* thf_union_type  */
  YYSYMBOL_thf_subtype = 150,              /* thf_subtype  */
  YYSYMBOL_thf_definition = 151,           /* thf_definition  */
  YYSYMBOL_thf_sequent = 152,              /* thf_sequent  */
  YYSYMBOL_tff_formula = 153,              /* tff_formula  */
  YYSYMBOL_tff_logic_formula = 154,        /* tff_logic_formula  */
  YYSYMBOL_tff_binary_formula = 155,       /* tff_binary_formula  */
  YYSYMBOL_tff_binary_nonassoc = 156,      /* tff_binary_nonassoc  */
  YYSYMBOL_tff_binary_assoc = 157,         /* tff_binary_assoc  */
  YYSYMBOL_tff_or_formula = 158,           /* tff_or_formula  */
  YYSYMBOL_tff_and_formula = 159,          /* tff_and_formula  */
  YYSYMBOL_tff_unit_formula = 160,         /* tff_unit_formula  */
  YYSYMBOL_tff_preunit_formula = 161,      /* tff_preunit_formula  */
  YYSYMBOL_tff_unitary_formula = 162,      /* tff_unitary_formula  */
  YYSYMBOL_txf_unitary_formula = 163,      /* txf_unitary_formula  */
  YYSYMBOL_tff_quantified_formula = 164,   /* tff_quantified_formula  */
  YYSYMBOL_tff_variable_list = 165,        /* tff_variable_list  */
  YYSYMBOL_tff_variable = 166,             /* tff_variable  */
  YYSYMBOL_tff_typed_variable = 167,       /* tff_typed_variable  */
  YYSYMBOL_tff_unary_formula = 168,        /* tff_unary_formula  */
  YYSYMBOL_tff_prefix_unary = 169,         /* tff_prefix_unary  */
  YYSYMBOL_tff_infix_unary = 170,          /* tff_infix_unary  */
  YYSYMBOL_tff_atomic_formula = 171,       /* tff_atomic_formula  */
  YYSYMBOL_tff_plain_atomic = 172,         /* tff_plain_atomic  */
  YYSYMBOL_tff_defined_atomic = 173,       /* tff_defined_atomic  */
  YYSYMBOL_tff_defined_plain = 174,        /* tff_defined_plain  */
  YYSYMBOL_tff_defined_infix = 175,        /* tff_defined_infix  */
  YYSYMBOL_tff_system_atomic = 176,        /* tff_system_atomic  */
  YYSYMBOL_txf_let = 177,                  /* txf_let  */
  YYSYMBOL_txf_let_types = 178,            /* txf_let_types  */
  YYSYMBOL_tff_atom_typing_list = 179,     /* tff_atom_typing_list  */
  YYSYMBOL_txf_let_defns = 180,            /* txf_let_defns  */
  YYSYMBOL_txf_let_defn = 181,             /* txf_let_defn  */
  YYSYMBOL_txf_let_LHS = 182,              /* txf_let_LHS  */
  YYSYMBOL_txf_let_defn_list = 183,        /* txf_let_defn_list  */
  YYSYMBOL_nxf_atom = 184,                 /* nxf_atom  */
  YYSYMBOL_tff_term = 185,                 /* tff_term  */
  YYSYMBOL_tff_unitary_term = 186,         /* tff_unitary_term  */
  YYSYMBOL_txf_tuple = 187,                /* txf_tuple  */
  YYSYMBOL_tff_arguments = 188,            /* tff_arguments  */
  YYSYMBOL_tff_atom_typing = 189,          /* tff_atom_typing  */
  YYSYMBOL_tff_top_level_type = 190,       /* tff_top_level_type  */
  YYSYMBOL_tff_non_atomic_type = 191,      /* tff_non_atomic_type  */
  YYSYMBOL_tf1_quantified_type = 192,      /* tf1_quantified_type  */
  YYSYMBOL_tff_monotype = 193,             /* tff_monotype  */
  YYSYMBOL_tff_unitary_type = 194,         /* tff_unitary_type  */
  YYSYMBOL_tff_atomic_type = 195,          /* tff_atomic_type  */
  YYSYMBOL_tff_type_arguments = 196,       /* tff_type_arguments  */
  YYSYMBOL_tff_mapping_type = 197,         /* tff_mapping_type  */
  YYSYMBOL_tff_xprod_type = 198,           /* tff_xprod_type  */
  YYSYMBOL_txf_tuple_type = 199,           /* txf_tuple_type  */
  YYSYMBOL_tff_type_list = 200,            /* tff_type_list  */
  YYSYMBOL_tff_subtype = 201,              /* tff_subtype  */
  YYSYMBOL_txf_definition = 202,           /* txf_definition  */
  YYSYMBOL_txf_sequent = 203,              /* txf_sequent  */
  YYSYMBOL_nhf_long_connective = 204,      /* nhf_long_connective  */
  YYSYMBOL_nhf_parameter_list = 205,       /* nhf_parameter_list  */
  YYSYMBOL_nhf_parameter = 206,            /* nhf_parameter  */
  YYSYMBOL_nhf_key_pair = 207,             /* nhf_key_pair  */
  YYSYMBOL_nxf_long_connective = 208,      /* nxf_long_connective  */
  YYSYMBOL_nxf_parameter_list = 209,       /* nxf_parameter_list  */
  YYSYMBOL_nxf_parameter = 210,            /* nxf_parameter  */
  YYSYMBOL_nxf_key_pair = 211,             /* nxf_key_pair  */
  YYSYMBOL_ntf_connective_name = 212,      /* ntf_connective_name  */
  YYSYMBOL_ntf_index = 213,                /* ntf_index  */
  YYSYMBOL_ntf_short_connective = 214,     /* ntf_short_connective  */
  YYSYMBOL_tcf_formula = 215,              /* tcf_formula  */
  YYSYMBOL_tcf_logic_formula = 216,        /* tcf_logic_formula  */
  YYSYMBOL_tcf_quantified_formula = 217,   /* tcf_quantified_formula  */
  YYSYMBOL_fof_formula = 218,              /* fof_formula  */
  YYSYMBOL_fof_logic_formula = 219,        /* fof_logic_formula  */
  YYSYMBOL_fof_binary_formula = 220,       /* fof_binary_formula  */
  YYSYMBOL_fof_binary_nonassoc = 221,      /* fof_binary_nonassoc  */
  YYSYMBOL_fof_binary_assoc = 222,         /* fof_binary_assoc  */
  YYSYMBOL_fof_or_formula = 223,           /* fof_or_formula  */
  YYSYMBOL_fof_and_formula = 224,          /* fof_and_formula  */
  YYSYMBOL_fof_unary_formula = 225,        /* fof_unary_formula  */
  YYSYMBOL_fof_infix_unary = 226,          /* fof_infix_unary  */
  YYSYMBOL_fof_unit_formula = 227,         /* fof_unit_formula  */
  YYSYMBOL_fof_unitary_formula = 228,      /* fof_unitary_formula  */
  YYSYMBOL_fof_quantified_formula = 229,   /* fof_quantified_formula  */
  YYSYMBOL_fof_variable_list = 230,        /* fof_variable_list  */
  YYSYMBOL_fof_atomic_formula = 231,       /* fof_atomic_formula  */
  YYSYMBOL_fof_plain_atomic_formula = 232, /* fof_plain_atomic_formula  */
  YYSYMBOL_fof_defined_atomic_formula = 233, /* fof_defined_atomic_formula  */
  YYSYMBOL_fof_defined_plain_formula = 234, /* fof_defined_plain_formula  */
  YYSYMBOL_fof_defined_infix_formula = 235, /* fof_defined_infix_formula  */
  YYSYMBOL_fof_system_atomic_formula = 236, /* fof_system_atomic_formula  */
  YYSYMBOL_fof_plain_term = 237,           /* fof_plain_term  */
  YYSYMBOL_fof_defined_term = 238,         /* fof_defined_term  */
  YYSYMBOL_fof_defined_atomic_term = 239,  /* fof_defined_atomic_term  */
  YYSYMBOL_fof_defined_plain_term = 240,   /* fof_defined_plain_term  */
  YYSYMBOL_fof_system_term = 241,          /* fof_system_term  */
  YYSYMBOL_fof_arguments = 242,            /* fof_arguments  */
  YYSYMBOL_fof_term = 243,                 /* fof_term  */
  YYSYMBOL_fof_function_term = 244,        /* fof_function_term  */
  YYSYMBOL_fof_sequent = 245,              /* fof_sequent  */
  YYSYMBOL_fof_formula_tuple = 246,        /* fof_formula_tuple  */
  YYSYMBOL_fof_formula_tuple_list = 247,   /* fof_formula_tuple_list  */
  YYSYMBOL_cnf_formula = 248,              /* cnf_formula  */
  YYSYMBOL_cnf_disjunction = 249,          /* cnf_disjunction  */
  YYSYMBOL_cnf_literal = 250,              /* cnf_literal  */
  YYSYMBOL_thf_quantifier = 251,           /* thf_quantifier  */
  YYSYMBOL_thf_unary_connective = 252,     /* thf_unary_connective  */
  YYSYMBOL_th1_quantifier = 253,           /* th1_quantifier  */
  YYSYMBOL_th0_quantifier = 254,           /* th0_quantifier  */
  YYSYMBOL_subtype_sign = 255,             /* subtype_sign  */
  YYSYMBOL_tff_unary_connective = 256,     /* tff_unary_connective  */
  YYSYMBOL_tff_quantifier = 257,           /* tff_quantifier  */
  YYSYMBOL_fof_quantifier = 258,           /* fof_quantifier  */
  YYSYMBOL_nonassoc_connective = 259,      /* nonassoc_connective  */
  YYSYMBOL_assoc_connective = 260,         /* assoc_connective  */
  YYSYMBOL_unary_connective = 261,         /* unary_connective  */
  YYSYMBOL_gentzen_arrow = 262,            /* gentzen_arrow  */
  YYSYMBOL_assignment = 263,               /* assignment  */
  YYSYMBOL_identical = 264,                /* identical  */
  YYSYMBOL_type_constant = 265,            /* type_constant  */
  YYSYMBOL_type_functor = 266,             /* type_functor  */
  YYSYMBOL_defined_type = 267,             /* defined_type  */
  YYSYMBOL_atom = 268,                     /* atom  */
  YYSYMBOL_untyped_atom = 269,             /* untyped_atom  */
  YYSYMBOL_defined_infix_pred = 270,       /* defined_infix_pred  */
  YYSYMBOL_infix_equality = 271,           /* infix_equality  */
  YYSYMBOL_infix_inequality = 272,         /* infix_inequality  */
  YYSYMBOL_constant = 273,                 /* constant  */
  YYSYMBOL_functor = 274,                  /* functor  */
  YYSYMBOL_defined_constant = 275,         /* defined_constant  */
  YYSYMBOL_defined_functor = 276,          /* defined_functor  */
  YYSYMBOL_system_constant = 277,          /* system_constant  */
  YYSYMBOL_system_functor = 278,           /* system_functor  */
  YYSYMBOL_def_or_sys_constant = 279,      /* def_or_sys_constant  */
  YYSYMBOL_th1_defined_term = 280,         /* th1_defined_term  */
  YYSYMBOL_defined_term = 281,             /* defined_term  */
  YYSYMBOL_variable = 282,                 /* variable  */
  YYSYMBOL_source = 283,                   /* source  */
  YYSYMBOL_sources = 284,                  /* sources  */
  YYSYMBOL_dag_source = 285,               /* dag_source  */
  YYSYMBOL_inference_record = 286,         /* inference_record  */
  YYSYMBOL_inference_rule = 287,           /* inference_rule  */
  YYSYMBOL_internal_source = 288,          /* internal_source  */
  YYSYMBOL_intro_type = 289,               /* intro_type  */
  YYSYMBOL_external_source = 290,          /* external_source  */
  YYSYMBOL_file_source = 291,              /* file_source  */
  YYSYMBOL_file_info = 292,                /* file_info  */
  YYSYMBOL_theory = 293,                   /* theory  */
  YYSYMBOL_theory_name = 294,              /* theory_name  */
  YYSYMBOL_creator_source = 295,           /* creator_source  */
  YYSYMBOL_creator_name = 296,             /* creator_name  */
  YYSYMBOL_parents = 297,                  /* parents  */
  YYSYMBOL_parent_list = 298,              /* parent_list  */
  YYSYMBOL_parent_info = 299,              /* parent_info  */
  YYSYMBOL_parent_details = 300,           /* parent_details  */
  YYSYMBOL_optional_info = 301,            /* optional_info  */
  YYSYMBOL_useful_info = 302,              /* useful_info  */
  YYSYMBOL_include = 303,                  /* include  */
  YYSYMBOL_include_optionals = 304,        /* include_optionals  */
  YYSYMBOL_formula_selection = 305,        /* formula_selection  */
  YYSYMBOL_name_list = 306,                /* name_list  */
  YYSYMBOL_space_name = 307,               /* space_name  */
  YYSYMBOL_general_term = 308,             /* general_term  */
  YYSYMBOL_general_data = 309,             /* general_data  */
  YYSYMBOL_general_function = 310,         /* general_function  */
  YYSYMBOL_formula_data = 311,             /* formula_data  */
  YYSYMBOL_general_list = 312,             /* general_list  */
  YYSYMBOL_general_terms = 313,            /* general_terms  */
  YYSYMBOL_name = 314,                     /* name  */
  YYSYMBOL_atomic_word = 315,              /* atomic_word  */
  YYSYMBOL_atomic_defined_word = 316,      /* atomic_defined_word  */
  YYSYMBOL_atomic_system_word = 317,       /* atomic_system_word  */
  YYSYMBOL_number = 318,                   /* number  */
  YYSYMBOL_file_name = 319,                /* file_name  */
  YYSYMBOL_null = 320                      /* null  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3667

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  93
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  228
/* YYNRULES -- Number of rules.  */
#define YYNRULES  444
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  828

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   347


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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   246,   246,   247,   250,   251,   254,   255,   256,   257,
     258,   259,   262,   265,   268,   271,   274,   277,   280,   283,
     284,   287,   288,   291,   292,   293,   296,   297,   298,   299,
     300,   301,   304,   305,   306,   309,   312,   313,   314,   317,
     318,   321,   322,   325,   326,   329,   330,   331,   334,   335,
     338,   339,   340,   341,   344,   347,   350,   351,   354,   357,
     358,   361,   364,   367,   368,   369,   370,   373,   374,   377,
     378,   379,   380,   381,   384,   385,   388,   391,   394,   397,
     398,   401,   402,   405,   406,   409,   412,   413,   416,   417,
     418,   421,   422,   423,   424,   425,   428,   429,   432,   433,
     434,   437,   440,   441,   444,   445,   448,   449,   450,   453,
     456,   459,   460,   461,   464,   465,   468,   469,   472,   473,
     476,   479,   482,   485,   486,   487,   490,   491,   492,   493,
     494,   495,   498,   499,   502,   505,   506,   509,   510,   513,
     514,   517,   518,   519,   522,   523,   526,   527,   528,   529,
     532,   535,   538,   539,   542,   543,   546,   549,   550,   553,
     556,   559,   560,   561,   564,   565,   568,   571,   572,   573,
     574,   577,   580,   581,   584,   587,   588,   591,   592,   595,
     596,   599,   602,   603,   606,   607,   610,   613,   614,   615,
     618,   619,   620,   621,   622,   625,   626,   629,   630,   633,
     634,   637,   638,   641,   642,   643,   646,   649,   650,   651,
     654,   655,   658,   659,   660,   661,   662,   663,   666,   667,
     670,   673,   674,   677,   680,   681,   684,   687,   690,   693,
     694,   697,   698,   701,   702,   705,   708,   709,   712,   713,
     716,   717,   720,   723,   726,   729,   730,   731,   732,   735,
     736,   739,   740,   743,   746,   747,   750,   751,   752,   755,
     756,   759,   762,   763,   766,   767,   770,   771,   774,   775,
     778,   781,   782,   785,   786,   787,   790,   793,   794,   797,
     798,   799,   802,   805,   806,   809,   812,   815,   818,   819,
     822,   823,   826,   829,   830,   833,   834,   837,   838,   841,
     842,   845,   846,   847,   850,   851,   854,   855,   858,   859,
     862,   863,   866,   867,   870,   871,   872,   873,   876,   877,
     878,   881,   882,   885,   886,   889,   890,   891,   894,   897,
     898,   901,   904,   905,   906,   909,   910,   911,   912,   913,
     914,   917,   918,   921,   924,   927,   930,   933,   936,   939,
     942,   943,   946,   947,   950,   953,   956,   959,   962,   965,
     968,   971,   974,   977,   978,   981,   982,   983,   984,   985,
     988,   989,   992,   995,   996,   997,   998,   999,  1002,  1003,
    1006,  1007,  1010,  1013,  1016,  1019,  1022,  1023,  1024,  1027,
    1030,  1031,  1034,  1037,  1040,  1043,  1046,  1047,  1050,  1051,
    1054,  1057,  1058,  1061,  1062,  1065,  1068,  1071,  1072,  1073,
    1076,  1077,  1080,  1081,  1084,  1087,  1088,  1089,  1092,  1093,
    1094,  1095,  1096,  1097,  1100,  1103,  1104,  1105,  1106,  1107,
    1110,  1111,  1114,  1115,  1118,  1119,  1122,  1123,  1126,  1129,
    1132,  1133,  1134,  1137,  1140
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
  "_LIT_cnf", "_LIT_creator", "_LIT_file", "_LIT_fof", "_LIT_include",
  "_LIT_inference", "_LIT_introduced", "_LIT_tcf", "_LIT_tff",
  "_LIT_theory", "_LIT_thf", "_LIT_tpi", "_LIT_unknown", "arrow",
  "decimal", "decimal_exponent", "decimal_fraction", "distinct_object",
  "dollar_dollar_word", "dollar_word", "dot_decimal", "exp_integer",
  "hash", "integer", "less_sign", "lower_word", "plus", "positive_decimal",
  "rational", "real", "signed_exp_integer", "signed_integer",
  "signed_rational", "signed_real", "single_quoted", "slash", "slosh",
  "star", "unrecognized", "unsigned_exp_integer", "unsigned_integer",
  "unsigned_rational", "unsigned_real", "upper_word", "vline", "$accept",
  "TPTP_file", "TPTP_input", "annotated_formula", "tpi_annotated",
  "tpi_formula", "thf_annotated", "tff_annotated", "tcf_annotated",
  "fof_annotated", "cnf_annotated", "annotations", "formula_role",
  "thf_formula", "thf_logic_formula", "thf_binary_formula",
  "thf_binary_nonassoc", "thf_binary_assoc", "thf_or_formula",
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
  "tff_binary_nonassoc", "tff_binary_assoc", "tff_or_formula",
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
  "ntf_connective_name", "ntf_index", "ntf_short_connective",
  "tcf_formula", "tcf_logic_formula", "tcf_quantified_formula",
  "fof_formula", "fof_logic_formula", "fof_binary_formula",
  "fof_binary_nonassoc", "fof_binary_assoc", "fof_or_formula",
  "fof_and_formula", "fof_unary_formula", "fof_infix_unary",
  "fof_unit_formula", "fof_unitary_formula", "fof_quantified_formula",
  "fof_variable_list", "fof_atomic_formula", "fof_plain_atomic_formula",
  "fof_defined_atomic_formula", "fof_defined_plain_formula",
  "fof_defined_infix_formula", "fof_system_atomic_formula",
  "fof_plain_term", "fof_defined_term", "fof_defined_atomic_term",
  "fof_defined_plain_term", "fof_system_term", "fof_arguments", "fof_term",
  "fof_function_term", "fof_sequent", "fof_formula_tuple",
  "fof_formula_tuple_list", "cnf_formula", "cnf_disjunction",
  "cnf_literal", "thf_quantifier", "thf_unary_connective",
  "th1_quantifier", "th0_quantifier", "subtype_sign",
  "tff_unary_connective", "tff_quantifier", "fof_quantifier",
  "nonassoc_connective", "assoc_connective", "unary_connective",
  "gentzen_arrow", "assignment", "identical", "type_constant",
  "type_functor", "defined_type", "atom", "untyped_atom",
  "defined_infix_pred", "infix_equality", "infix_inequality", "constant",
  "functor", "defined_constant", "defined_functor", "system_constant",
  "system_functor", "def_or_sys_constant", "th1_defined_term",
  "defined_term", "variable", "source", "sources", "dag_source",
  "inference_record", "inference_rule", "internal_source", "intro_type",
  "external_source", "file_source", "file_info", "theory", "theory_name",
  "creator_source", "creator_name", "parents", "parent_list",
  "parent_info", "parent_details", "optional_info", "useful_info",
  "include", "include_optionals", "formula_selection", "name_list",
  "space_name", "general_term", "general_data", "general_function",
  "formula_data", "general_list", "general_terms", "name", "atomic_word",
  "atomic_defined_word", "atomic_system_word", "number", "file_name",
  "null", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-582)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-354)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -582,   698,  -582,  -582,    94,   136,   154,   236,   253,   258,
     262,  -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,
     227,   227,   120,   227,   227,   227,   227,  -582,  -582,  -582,
     240,  -582,   286,  -582,   289,   292,   307,   327,   330,   273,
     273,   111,   315,  -582,   273,   273,   273,   273,   328,   356,
     366,   227,  -582,   369,   380,   411,   443,   462,   472,  1105,
    1749,  2372,   423,   491,   227,  -582,   592,  2895,  3259,  2372,
    1397,   460,   469,   479,   489,   500,  -582,  -582,  -582,  -582,
    -582,  -582,  -582,   522,  -582,  -582,  -582,   512,  -582,  1749,
     734,  -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,
    -582,    74,  -582,  -582,   226,   308,   352,  -582,   546,   525,
    -582,  -582,   526,  -582,   536,  -582,   544,  -582,  -582,  -582,
    -582,  -582,  -582,  -582,  2816,  2372,  -582,  -582,  -582,   546,
    -582,  -582,  -582,  -582,   547,   582,   142,  -582,   458,   219,
    -582,  -582,  -582,   563,   577,  1604,  -582,   227,  -582,  -582,
     578,  1898,  -582,   546,  -582,  -582,  -582,   590,   591,   593,
      60,  1877,  1965,   580,   594,   546,  -582,  -582,  -582,  -582,
     569,   609,   895,   271,  -582,  -582,   319,  -582,  -582,   533,
    -582,  -582,  -582,   325,  -582,  -582,  -582,   352,   563,  -582,
    -582,  -582,  -582,   620,  -582,  1073,   603,  -582,  -582,    56,
      90,   601,  -582,   604,   165,   607,  -582,   381,  -582,  -582,
    -582,  -582,  -582,  -582,  -582,  -582,    60,  1684,  2994,  -582,
    -582,   610,   546,  -582,  -582,  -582,  -582,   595,   639,   637,
     806,   488,  -582,  3335,   131,  -582,  -582,   540,  -582,  -582,
    -582,   259,  -582,  -582,   352,   563,  -582,  -582,    76,  -582,
    -582,   611,   571,  -582,  -582,  -582,  -582,  -582,   627,  3411,
    -582,  -582,  -582,  -582,   186,    90,   625,  -582,   628,   165,
     629,  -582,  -582,   393,   546,  -582,  -582,   641,   635,  1749,
    2372,  1527,  2895,  3259,  1105,  1105,   624,  1527,  -582,   658,
    -582,  -582,  1527,  -582,  1527,   835,   643,  -582,  1147,  1527,
    1527,  1527,  1604,  -582,   660,   664,   644,   659,   666,  1604,
    1604,  1604,  -582,  -582,  -582,  -582,  -582,  -582,  1604,  1604,
    -582,   654,   612,  -582,  -582,  -582,  -582,   612,   668,   669,
     483,   673,    95,  -582,  -582,  -582,  -582,  -582,  2157,   665,
    -582,  -582,   695,   216,   681,  -582,  -582,   445,   684,   688,
     335,   667,   689,  3576,  3576,  3576,  3576,  3576,  -582,  3576,
    2581,  2581,   707,   703,   701,  2157,  -582,  -582,  -582,  -582,
    -582,   612,  -582,   413,  3576,  3576,  3576,   183,  3098,  -582,
     722,   709,  -582,  -582,  -582,  -582,   700,   702,   706,  3411,
    -582,  -582,   736,  -582,  -582,   545,   712,  3335,  3335,  3335,
    3335,  3335,  3335,  3335,  -582,  -582,  -582,   459,  -582,  -582,
    3335,  1043,  1043,   723,  3563,  3563,  3563,  3563,  3563,   612,
    3098,  -582,  -582,  -582,  -582,  -582,  3335,   413,  3335,  3335,
    3335,   719,  1105,  -582,   724,   726,  -582,  -582,  -582,   727,
     728,   733,  -582,   735,  -582,   738,  -582,  -582,   835,   731,
     743,   748,   749,   751,  -582,   772,  -582,  -582,  -582,  -582,
    -582,  -582,  -582,  -582,   756,  -582,   752,   776,   757,   758,
    1604,  -582,  -582,  -582,   762,  -582,  -582,  -582,  -582,  -582,
    -582,   760,   784,   763,   789,  -582,   792,  -582,   774,   786,
     483,   483,  -582,  -582,  -582,   754,   765,  -582,  -582,  -582,
     790,  -582,  -582,  -582,  -582,  -582,   645,  -582,  -582,  3576,
    -582,  -582,   493,   387,   387,   808,  -582,  -582,  -582,  -582,
    -582,   793,  -582,  -582,  -582,   520,  -582,  -582,  -582,  -582,
    -582,  -582,  -582,   331,  2245,  3576,  -582,  -582,  -582,  -582,
    -582,  3576,   788,   796,  -582,  -582,  -582,   791,   798,   799,
    1390,  -582,  3335,  -582,   550,  -582,  -582,   640,   640,   823,
    -582,   807,  -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,
     331,  2803,  3183,  -582,  -582,  -582,  -582,  -582,  3183,  -582,
    -582,   777,  -582,  -582,  -582,  -582,   804,   827,   831,   812,
     637,   837,   838,  -582,   777,  -582,  -582,  -582,   820,  -582,
     822,   824,   832,  -582,  -582,  -582,  -582,  -582,  -582,  -582,
    -582,   848,   828,   120,   120,   120,   120,   120,   843,  -582,
    -582,  -582,  -582,  1527,  -582,  -582,  -582,  -582,   857,   612,
     858,   612,    97,  -582,   612,   862,   841,   842,   128,   844,
     414,    97,    97,  2581,   864,  -582,   850,   874,  -582,  -582,
    -582,   861,   880,    69,  -582,   863,   867,  -582,   866,  -582,
    -582,  -582,  1289,   864,  -582,   868,   884,  -582,  -582,  -582,
     865,   894,  3487,  -582,   869,   898,   612,  3335,  -582,  -582,
    -582,  -582,  -582,   835,  -582,   899,  -582,   900,   902,  -582,
     903,  -582,   772,  -582,  -582,  -582,  -582,  1604,  -582,  2084,
    -582,    97,  -582,   885,   483,  -582,  -582,    97,  -582,  -582,
      97,  -582,   917,   904,  -582,   905,   645,  -582,   387,  2245,
    -582,   925,  -582,   929,  -582,  -582,  -582,  3576,   912,   913,
    -582,   910,  1390,  -582,   640,  1684,   929,   936,  -582,  -582,
    -582,  -582,  -582,  -582,   843,   227,   914,  -582,   843,   843,
     915,  -582,  -582,   844,   943,  -582,  -582,  -582,    97,  -582,
    -582,  -582,  -582,   944,   942,   928,   409,  3576,  -582,  3576,
    -582,  -582,  -582,  -582,   557,   947,   930,  3335,  3335,   951,
    -582,  -582,   953,   955,  -582,   562,  -582,    98,  -582,   933,
    -582,  3335,  -582,  -582,   934,   949,   949,   949,   314,  -582,
    -582,  -582,  -582,  -582,  -582,  -582,  2467,   941,   950,   952,
     314,   954,  -582,   968,   945,   972,  -582,  -582,  -582,   959,
    -582,   843,  -582,  -582,  -582,   835,  -582,  -582
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     444,     0,     2,     1,     0,     0,     0,     0,     0,     0,
       0,     3,     4,    11,     6,     7,     8,     9,    10,     5,
       0,     0,     0,     0,     0,     0,     0,   435,   436,   437,
       0,   434,     0,   443,   444,     0,     0,     0,     0,     0,
       0,     0,     0,   407,     0,     0,     0,     0,    21,     0,
       0,     0,   411,   408,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   412,     0,   406,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   422,   440,   441,   442,
     372,   420,    22,   415,   419,   423,   417,   418,   421,     0,
       0,   371,   439,   438,   317,   314,   279,   280,   283,   284,
     281,   282,   302,   291,   285,   287,     0,   299,   444,   310,
     312,   288,   357,   293,   359,   295,   361,   290,   300,   358,
     360,   362,   370,   332,     0,     0,   333,   343,   334,   444,
     254,   256,   259,   260,   262,   263,   272,   269,     0,   271,
     273,   274,   255,     0,     0,     0,   410,     0,   409,   414,
       0,     0,   250,   444,   249,   251,   252,     0,   288,   295,
       0,     0,     0,     0,     0,   444,   123,   128,   132,   133,
     135,   136,     0,   141,   148,   146,   142,   157,   158,   147,
     161,   162,   166,   143,   163,   170,   169,     0,   192,   124,
     125,   130,   131,     0,   330,     0,     0,   331,   329,     0,
     164,   357,   167,   359,   172,   361,   191,   150,   368,   367,
     369,   327,   326,   325,   365,   323,     0,     0,     0,   366,
     324,     0,   444,    23,    28,    32,    33,    36,    37,    38,
       0,    45,    50,     0,    46,    59,    60,    51,    63,    64,
      70,    47,    65,    73,     0,    68,    66,    24,     0,    34,
     111,   112,   113,    25,    30,    31,    72,   322,     0,     0,
     320,   319,   318,   321,     0,    67,   357,    69,   359,    77,
     361,    75,    74,    52,   444,    13,   430,   432,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   315,     0,
     355,   356,     0,   354,     0,     0,     0,    20,     0,     0,
       0,     0,     0,   306,   308,     0,     0,     0,     0,     0,
       0,     0,   336,   337,   335,   338,   340,   339,     0,     0,
     344,     0,     0,   272,   268,   271,   413,     0,     0,     0,
       0,     0,     0,   363,   359,   364,   361,   243,     0,     0,
     195,   187,   197,   189,     0,   164,   172,   188,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   346,     0,
       0,     0,     0,     0,     0,     0,   159,   144,   145,   147,
     150,     0,   328,     0,     0,     0,     0,     0,     0,    96,
     102,     0,    67,    77,   342,   341,     0,     0,     0,    95,
      91,    92,     0,    93,    94,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    54,    45,    46,    51,    47,    68,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    61,    48,    49,    51,    52,     0,     0,     0,     0,
       0,     0,     0,   431,     0,     0,   301,   292,   303,     0,
       0,     0,   416,     0,   311,     0,   286,   270,     0,     0,
       0,     0,     0,     0,   376,   444,   373,   381,   374,   375,
     386,   387,   388,   380,     0,   313,     0,   297,     0,     0,
       0,   307,   275,   305,     0,   265,   267,   266,   264,   261,
     304,     0,   277,     0,   152,   154,   155,   200,     0,     0,
       0,     0,   199,   202,   204,     0,   201,   203,   217,   212,
     347,   213,   214,   348,   349,   247,     0,   236,   245,     0,
     196,   248,   149,     0,     0,     0,   175,   352,   357,   353,
     246,     0,   138,   141,   142,   147,   143,   192,   140,   139,
     137,   134,   227,     0,     0,     0,   190,   171,   193,   160,
     228,     0,     0,     0,   226,   350,   351,     0,     0,     0,
       0,   229,     0,    97,    53,    71,   105,     0,     0,     0,
      79,     0,    40,    42,    44,    41,    43,    39,    35,   121,
       0,     0,     0,    88,    76,    89,    62,   122,     0,   109,
     116,   114,   115,   118,   117,   119,     0,    56,     0,     0,
     110,     0,   109,   104,   106,   108,   107,   120,     0,   101,
       0,     0,     0,   433,   428,   427,   429,   426,   425,   424,
     316,   378,     0,     0,     0,     0,     0,     0,     0,    19,
     404,    18,   289,     0,   294,   296,   309,    17,     0,     0,
       0,     0,     0,    16,     0,   224,     0,     0,     0,   210,
       0,     0,     0,     0,     0,   242,     0,   238,   241,   240,
     198,     0,   177,     0,    15,     0,     0,   149,     0,   165,
     168,   173,     0,     0,   235,     0,   231,   234,   233,   103,
       0,    81,     0,    14,     0,     0,     0,     0,    53,    98,
      99,   100,    12,     0,   377,     0,   395,   444,     0,   383,
       0,   385,   444,   393,   403,   405,   298,     0,   278,     0,
     153,     0,   156,     0,     0,   223,   205,     0,   216,   211,
       0,   220,   218,     0,   244,     0,     0,   176,     0,     0,
     182,     0,   179,     0,   183,   194,   186,     0,     0,     0,
      95,     0,     0,    80,     0,     0,     0,     0,    83,    90,
      55,    57,    58,   379,     0,     0,     0,   391,     0,     0,
       0,   276,   253,     0,     0,   225,   221,   222,     0,   215,
     237,   239,   178,   161,   184,     0,   189,     0,   345,     0,
     151,   230,   232,    82,   102,    86,     0,     0,     0,     0,
     390,   389,     0,     0,   392,     0,   219,     0,   180,     0,
     181,     0,    84,    85,     0,     0,     0,     0,     0,   209,
     206,   207,   185,   174,    87,    78,     0,     0,     0,     0,
       0,     0,   396,   444,     0,   398,   394,   382,   384,     0,
     208,     0,   400,   402,   397,     0,   401,   399
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,
    -582,   194,   474,   704,    42,  -582,  -582,  -582,  -582,  -582,
    -380,   -84,  -582,   967,  -582,  -582,   322,  -582,    44,  -185,
    -582,   608,  -582,  -582,  -582,    91,  -582,  -582,  -582,   268,
    -582,   332,   212,   167,  -582,     5,  -582,   151,  -326,  -190,
     336,  -258,  -582,  -582,  -367,  -582,  -582,  -582,  -493,  -582,
     730,   -57,  -582,  -582,  -582,  -582,  -582,  -291,  -582,  -106,
    -582,  -582,  -348,  -582,  -582,  -278,   819,  -582,  -141,  -581,
    -582,  -582,  -260,  -582,  -582,  -582,   297,  -582,   365,  -582,
     234,  -582,  -330,  -322,   175,  -268,   -47,   697,   537,   244,
    -582,  -466,   282,   272,   233,  -582,  -582,   329,  -582,  -437,
    -582,  -582,   300,  -582,  -582,  -582,   320,  -582,  -582,  -192,
    -480,   619,  -582,   339,  -582,   -11,   -38,  -582,  -582,  -582,
    -582,  -582,  -136,   -52,  -124,  -110,  -582,   406,    -5,  -582,
    -582,  -582,  -582,  -582,  -183,  -582,  -582,  -169,  -147,  -270,
     -63,  -582,   916,   718,   574,    11,  -582,   747,  -582,  -150,
    -582,  -582,   782,  -582,  -582,  2224,   -58,  -582,  2429,   -61,
     326,  -215,  -582,  -582,  -582,   630,   -15,  -161,   -46,    34,
     572,   892,  1772,  2052,  1212,  1492,  -582,  -582,  2331,   -26,
    -284,   368,  -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,
    -582,  -582,  -582,  -582,  -206,   230,  -582,  -582,   360,  -318,
    -582,  -582,  -582,   909,  -582,    -9,  -582,  -582,  -582,  -457,
    -236,    -8,   -19,   359,  -582,   -23,   444,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    11,    12,    13,   274,    14,    15,    16,    17,
      18,   296,    49,   222,   380,   224,   225,   226,   227,   228,
     229,   230,   421,   231,   232,   233,   586,   587,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   559,   670,
     737,   775,   776,   244,   387,   409,   246,   598,   381,   247,
     593,   248,   595,   249,   250,   251,   252,   253,   254,   255,
     165,   341,   167,   168,   169,   170,   171,   172,   366,   173,
     174,   175,   483,   484,   485,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   515,   651,   721,   764,   723,
     765,   186,   342,   187,   343,   344,   328,   635,   493,   494,
     800,   495,   496,   713,   497,   640,   498,   636,   190,   191,
     192,   256,   665,   666,   667,   193,   646,   647,   648,   332,
     649,   257,   153,   154,   155,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   481,   141,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   466,
     106,   107,   142,   143,   305,   156,   109,   110,   258,   259,
     260,   261,   373,   195,   196,   262,   390,   391,   263,   362,
     777,   359,   499,   500,   501,   544,   157,   292,   393,   394,
     382,   266,   267,   268,   383,   270,   337,   271,   272,   118,
     611,   612,   456,   457,   688,   458,   690,   459,   460,   746,
     461,   692,   462,   685,   807,   814,   815,   822,   619,   694,
      19,    42,    53,    62,   148,   277,    83,    84,    85,    86,
     278,   463,   119,   120,   121,   122,    34,   297
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       2,    31,    31,    33,    31,    31,    31,    31,    94,   323,
     166,   455,    30,    32,    94,    35,    36,    37,    38,   152,
     189,   324,   410,   543,   377,   638,   360,   289,   388,   532,
     468,   469,    31,    81,    43,   325,    88,    94,   537,   539,
      87,   207,   273,    63,    81,    31,   590,    88,   582,   443,
      82,    87,   199,   264,   369,    95,   149,   664,   275,   596,
     293,    95,   522,   528,   529,   530,   531,   330,   389,   645,
     668,   108,   720,   245,   423,   524,   524,   524,   524,   524,
     319,   372,   321,   411,    95,   288,   304,   306,  -301,   367,
     331,   719,  -301,   526,   526,   526,   526,   526,   436,    94,
     286,  -352,   599,   599,   599,   349,   547,   548,   549,   436,
     223,   436,   437,   414,   357,  -352,   436,   436,   436,   490,
     534,    20,   506,   437,   701,   437,    92,    93,    31,   507,
     437,   437,   437,    51,   438,   207,   207,   415,   763,    63,
     294,   293,    28,   -27,   -27,   438,    95,   438,    52,   404,
     416,    29,   438,   438,   438,  -257,   580,   581,   583,   584,
     585,   695,   286,    21,    93,   707,   -27,   -27,   594,   370,
      28,    28,   403,   323,   323,   323,  -353,  -257,  -257,    29,
      29,    22,   323,   323,   413,   475,   476,   477,    80,   641,
    -353,   273,   273,    28,   478,   479,   603,   426,   293,   325,
     325,   325,    29,   392,   423,   560,   720,   273,   325,   325,
     550,   372,   525,   525,   525,   525,   525,   551,   439,   536,
     536,   361,   245,   245,   289,   166,   669,    94,   389,   446,
    -192,   447,  -258,   425,  -192,   189,   467,   467,   467,   664,
    -292,   650,   188,   293,  -292,   320,    94,   523,   523,   523,
     523,   523,   668,    39,  -258,  -258,   207,   273,    81,    81,
     386,    88,    88,    23,   306,    87,    87,   199,   264,   435,
     389,   -29,   -29,   656,    95,   442,    31,   406,   412,   645,
      24,   349,   445,   700,  -126,    25,   703,   695,   245,    26,
     434,   695,   695,    95,   -29,   -29,   482,   590,    27,    40,
      28,   486,    41,   516,   502,    44,  -126,  -126,   542,    29,
     596,   503,   207,   562,   563,   564,   565,   566,   567,   568,
      45,   714,  -303,   308,   408,   223,  -303,   207,   207,   207,
     207,   207,  -127,   207,   538,   538,   490,   188,  -129,   207,
      46,   810,   591,    47,   819,   486,    48,   329,   207,   207,
     207,    54,   273,   696,  -127,  -127,    59,   513,   545,   352,
    -129,  -129,   514,   425,   826,   644,   290,   671,   388,    60,
     291,   273,   273,   273,   273,   273,   273,   273,   377,    61,
     392,    93,    64,   245,   273,   575,   575,    28,   425,   425,
     425,   425,   425,   588,   273,  -193,    29,    92,    93,  -193,
     273,    92,   273,   273,   273,    80,    81,   -89,    28,    88,
      65,   -89,   545,    87,   514,   245,   396,    29,   577,   594,
     386,  -183,   389,  -192,    66,   245,   779,  -192,   389,    31,
     782,   783,   304,   245,   245,   245,   770,   789,   320,   790,
     436,   406,   406,   406,   406,   406,   406,   406,   410,   524,
     709,   710,   569,    92,   437,   620,    67,   188,   146,  -191,
      28,   311,   589,  -191,   502,   502,   652,   526,   431,    29,
     406,   503,   503,   -88,   312,    68,   438,   -88,   655,    92,
      93,   313,   314,   207,   315,    69,    28,   279,   408,   408,
     408,   408,   408,   408,   408,    29,   280,   316,   317,   318,
     -26,   -26,   536,   489,   147,   490,   281,  -194,   207,   207,
     491,  -194,   730,   188,    50,   207,   282,   408,    55,    56,
      57,    58,   813,   -26,   -26,  -109,   273,   283,   527,   527,
     527,   527,   527,   284,  -190,   527,   527,   540,  -190,   285,
     188,   813,   392,   392,   671,   273,   273,  -190,   358,  -109,
      93,  -190,   273,   299,   -88,   358,    28,   245,   -88,   295,
     467,   323,  -109,   300,   -90,    29,   298,   557,   -90,   768,
     552,   301,   558,   751,    80,   644,   245,   245,   574,   576,
     600,   601,   489,   245,   490,   310,   525,   325,   309,   798,
     808,   809,   320,   591,   686,    33,   689,   691,   693,   322,
     327,   330,  -352,   482,  -353,   486,   502,   350,   486,   150,
     353,    92,   354,   503,   674,   502,   502,   538,    28,   151,
     589,   523,   503,   503,   351,   371,   363,    29,   374,    93,
      90,   375,   111,   111,   376,    28,   397,   395,   158,   200,
     265,   111,   398,   399,    29,   418,   273,    94,   417,   419,
     588,   273,   428,    80,   432,   429,   430,    91,    92,    93,
     444,   111,   111,    77,    31,    28,   533,   558,    78,    79,
     433,   652,   290,   470,    29,   502,   124,   245,   502,   464,
     472,   502,   503,    80,   502,   503,   194,   747,   503,   504,
     163,   503,   620,   207,    95,   473,   111,   111,     3,   471,
     508,   207,   474,    80,   487,   488,    92,   505,   509,   273,
     188,    92,    93,    28,   736,   643,   510,   111,    28,   392,
     511,   406,    29,   158,   512,   521,    31,    29,   520,   534,
     541,   339,   502,   345,   200,   552,   554,   780,   555,   503,
     245,   207,   556,   207,   553,   571,     4,   426,   561,     5,
       6,   273,   273,     7,     8,   602,     9,    10,   613,   502,
     604,   287,   605,   606,   607,   273,   503,   345,   408,   608,
     614,   609,   502,   639,   610,   615,   616,   774,   617,   503,
     194,   194,   245,   245,   502,   618,   621,    31,   622,   623,
     265,   503,   627,   624,   625,   628,   245,   629,   630,    91,
      92,    93,   631,   632,   633,    77,    31,    28,   634,   400,
      78,    79,   401,   823,   194,   641,    29,   642,   527,   793,
     794,   653,   312,   654,   657,    80,  -210,   659,   724,   313,
     314,   658,   315,   736,   660,   661,   672,   673,   415,   675,
     676,   407,   677,   401,   -45,   316,   317,   402,   678,   504,
     504,   111,   111,   111,   200,   265,   679,   448,   680,   111,
     681,   683,   682,   684,   111,    70,   111,   424,   697,   699,
     111,   111,   111,   111,   111,   704,   705,   727,   706,   358,
     708,   111,   111,   111,   449,   450,   715,   716,   451,   452,
     111,   111,   453,   718,   766,   454,   717,   732,   355,   725,
     733,   194,   527,   726,   731,   739,    27,   734,    28,   740,
     345,   312,   744,   745,   702,   748,   749,    29,   313,   314,
     754,   315,   517,   711,   712,   345,   345,   345,   345,   345,
     758,   345,   345,   345,   316,   317,   356,   345,   767,   760,
     759,   768,   331,   348,   771,   517,   345,   345,   345,   778,
     781,   784,   112,   112,   785,   787,  -182,   194,   112,   201,
     791,   112,   724,   788,   795,   792,   796,   517,   797,   803,
     805,   806,   194,   194,   194,   194,   194,   816,   194,   821,
     824,   112,   112,   753,   194,   825,   817,   441,   818,   756,
     820,   504,   757,   194,   194,   194,   707,   424,   741,   517,
     504,   504,   773,   804,   738,   407,   407,   407,   407,   407,
     407,   407,   440,   742,   368,   762,   112,   112,   722,   573,
     573,   802,   424,   424,   424,   424,   424,   492,   637,   799,
     786,   811,   772,   755,   407,   698,   761,   112,   752,   480,
     712,   307,   111,   112,   626,   465,   427,   208,   209,   769,
     210,   743,   750,   201,   201,   827,   326,   597,   687,     0,
     504,     0,   214,   504,   570,   571,   504,   801,     0,   504,
     572,     0,     0,     0,     0,   219,     0,     0,   345,     0,
     639,   345,     0,     0,     0,   517,   517,   201,   221,     0,
     123,     0,   639,     0,   160,   364,     0,     0,     0,     0,
     365,     0,     0,     0,   126,     0,   345,   345,    91,    92,
      93,   127,     0,   345,    77,     0,    28,   504,   163,    78,
      79,     0,     0,     0,     0,    29,     0,    70,   194,   517,
     517,     0,     0,     0,    80,     0,     0,     0,     0,    92,
      93,     0,     0,   128,   504,   164,    28,    71,    72,    73,
       0,    74,    75,   194,   194,    29,     0,   504,   663,     0,
     194,     0,     0,     0,    80,     0,     0,     0,     0,   504,
      76,   112,   112,   112,   201,     0,    77,     0,    28,   112,
       0,    78,    79,     0,   112,    90,   112,    29,     0,     0,
     112,   112,   112,   112,   112,   111,    80,     0,     0,     0,
     405,   112,   112,   112,     0,     0,     0,     0,     0,     0,
     112,   112,    91,    92,    93,   345,     0,     0,    77,     0,
      28,     0,     0,    78,    79,   345,   422,     0,     0,    29,
     201,     0,     0,     0,     0,     0,     0,     0,    80,     0,
       0,     0,   518,     0,     0,   201,   201,   201,   201,   201,
       0,   201,   201,   201,     0,     0,     0,   201,     0,     0,
       0,     0,     0,     0,     0,   518,   201,   201,   201,   111,
       0,   111,   115,   115,     0,     0,     0,     0,   159,   204,
     269,   115,     0,     0,     0,   407,     0,   518,   345,     0,
     517,   345,   384,     0,     0,     0,     0,     0,     0,   345,
       0,   115,   115,   290,     0,   312,   517,   291,     0,     0,
     728,   364,   313,   314,     0,   315,   729,     0,     0,   518,
       0,     0,     0,     0,     0,     0,     0,   127,   316,   317,
     385,     0,     0,     0,     0,     0,   115,   115,   194,   345,
     663,   345,     0,     0,     0,     0,   194,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   422,   115,     0,   345,
       0,   164,   112,   159,   405,   405,   405,   405,   405,   405,
     405,     0,   335,   346,   204,     0,     0,     0,     0,     0,
       0,   579,   579,   579,   579,   579,   194,     0,   194,     0,
       0,     0,     0,   592,   208,   209,     0,   210,   201,     0,
       0,   201,     0,     0,     0,   518,   518,   346,     0,   214,
       0,   570,   571,     0,     0,     0,     0,   662,     0,    70,
       0,     0,   219,     0,     0,     0,   201,   201,   335,     0,
     269,     0,   276,   201,     0,   221,     0,     0,     0,    71,
      72,    73,     0,    74,    75,     0,     0,     0,     0,   518,
     518,     0,     0,     0,     0,    91,    92,    93,     0,     0,
     643,    77,    76,    28,     0,     0,    78,    79,    77,     0,
      28,     0,    29,    78,    79,     0,     0,     0,     0,    29,
       0,     0,     0,     0,     0,     0,     0,     0,    80,     0,
       0,   115,   115,   115,   204,   269,     0,     0,     0,   115,
       0,     0,     0,     0,   115,     0,   115,     0,     0,     0,
     115,   115,   115,   115,   115,   112,     0,     0,     0,     0,
       0,   115,   115,   115,     0,     0,     0,     0,     0,     0,
     115,   115,     0,     0,     0,   201,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   201,     0,     0,     0,     0,
     346,     0,   116,   116,     0,     0,     0,     0,   116,   205,
       0,   116,   519,     0,     0,   346,   346,   346,   346,   346,
       0,   346,   346,   346,     0,     0,     0,   346,     0,     0,
       0,   116,   116,     0,     0,   519,   346,   346,   346,   112,
       0,   112,    91,    92,    93,     0,     0,     0,    77,     0,
      28,     0,     0,    78,    79,     0,     0,   519,   201,    29,
     518,   201,     0,     0,     0,     0,   116,   116,    80,   201,
       0,   123,     0,     0,     0,     0,   518,     0,     0,     0,
       0,   302,     0,     0,     0,   126,     0,   116,     0,   519,
       0,     0,   127,   116,   592,     0,     0,     0,     0,     0,
       0,     0,   336,   205,   205,     0,     0,     0,     0,   201,
       0,   201,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,     0,     0,   128,    77,     0,    28,     0,   201,
      78,    79,   115,     0,     0,     0,    29,   205,   208,   209,
       0,   210,   211,   212,   213,    80,     0,     0,     0,     0,
       0,   123,     0,   214,   215,   216,   217,     0,   336,     0,
       0,   378,     0,     0,   339,   126,   219,   220,   346,   379,
       0,   346,   127,     0,     0,   519,   519,     0,     0,   221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   335,   346,   346,     0,    91,
      92,    93,     0,   346,   128,    77,   164,    28,     0,     0,
      78,    79,     0,     0,     0,     0,    29,     0,     0,   519,
     519,   116,   116,   116,   205,    80,    89,     0,     0,   116,
       0,     0,   335,     0,   116,     0,   116,    90,     0,     0,
     116,   116,   116,   116,   116,     0,     0,     0,     0,     0,
       0,   116,   116,   116,     0,     0,     0,     0,     0,     0,
     116,   116,     0,     0,    91,    92,    93,     0,     0,     0,
      77,     0,    28,     0,     0,    78,    79,     0,     0,     0,
     205,    29,   113,   113,     0,   115,     0,     0,   113,   202,
      80,   113,   336,     0,     0,   205,   205,   205,   205,   205,
       0,   205,   205,   205,     0,   346,     0,   205,     0,     0,
       0,   113,   113,     0,     0,   336,   205,   205,   205,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   336,     0,     0,
       0,     0,     0,     0,   123,     0,   113,   113,   160,   161,
       0,     0,     0,     0,   338,     0,     0,   339,   126,   115,
       0,   115,   340,     0,     0,   127,     0,   113,     0,   336,
       0,     0,   163,   113,     0,   151,     0,     0,   346,     0,
     519,   346,   333,   202,   202,     0,    90,     0,     0,   346,
       0,     0,    91,    92,    93,     0,   519,   128,    77,   164,
      28,     0,     0,    78,    79,     0,     0,     0,     0,    29,
       0,     0,   116,    91,    92,    93,     0,   202,    80,    77,
       0,    28,     0,     0,    78,    79,     0,     0,     0,   346,
      29,   346,   123,     0,     0,     0,   160,   161,   333,    80,
       0,     0,   162,     0,     0,   348,   126,     0,   205,     0,
       0,   205,     0,   127,     0,   336,   336,     0,     0,     0,
     163,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   336,   205,   205,     0,     0,
      91,    92,    93,   205,     0,   128,    77,   164,    28,     0,
       0,    78,    79,     0,     0,     0,     0,    29,     0,   336,
     336,   113,   113,   113,   202,     0,    80,     0,     0,   113,
       0,     0,   336,     0,   113,     0,   113,     0,     0,     0,
     113,   113,   113,   113,   113,     0,     0,     0,     0,     0,
       0,   113,   113,   113,     0,     0,     0,     0,     0,     0,
     113,   113,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   150,     0,     0,     0,     0,     0,     0,     0,     0,
     202,    89,   114,   114,     0,   116,     0,     0,   114,   203,
       0,   114,    90,     0,     0,   202,   202,   202,   202,   202,
       0,   202,   202,   202,     0,   205,     0,   202,     0,     0,
       0,   114,   114,     0,     0,   546,   202,   202,   202,    91,
      92,    93,     0,     0,     0,    77,     0,    28,     0,     0,
      78,    79,     0,     0,     0,     0,    29,     0,     0,     0,
       0,     0,     0,     0,   123,    80,   114,   114,   160,   161,
       0,     0,     0,     0,   338,     0,     0,   348,   126,   116,
       0,   116,     0,     0,     0,   127,     0,   114,     0,   546,
       0,     0,   163,   114,     0,     0,     0,     0,   205,     0,
     336,   205,   334,   203,   203,     0,     0,     0,     0,   205,
       0,     0,    91,    92,    93,     0,   336,   128,    77,   164,
      28,     0,     0,    78,    79,     0,     0,     0,     0,    29,
       0,     0,   113,     0,     0,     0,     0,   203,    80,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   205,
       0,   205,   123,     0,     0,     0,   160,   161,   334,     0,
       0,     0,   338,     0,     0,     0,   126,     0,   202,     0,
     340,   202,     0,   127,     0,   144,     0,     0,     0,     0,
     163,   197,     0,   144,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   333,   202,   202,     0,     0,
      91,    92,    93,   202,     0,   128,    77,   164,    28,     0,
       0,    78,    79,     0,     0,     0,     0,    29,     0,     0,
       0,   114,   114,   114,   203,     0,    80,     0,     0,   114,
       0,     0,   333,     0,   114,     0,   114,     0,   144,   144,
     114,   114,   114,   114,   114,     0,     0,     0,     0,     0,
       0,   114,   114,   114,     0,     0,     0,     0,     0,   144,
     114,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   197,   197,     0,     0,   123,
     203,   117,   117,     0,   124,   113,     0,   117,   206,   125,
     117,     0,     0,   126,     0,   203,   203,   203,   203,   203,
     127,   203,   203,   203,     0,   202,     0,   203,     0,   197,
     117,   117,     0,     0,     0,   334,   203,   203,   203,     0,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
       0,     0,   128,    77,     0,    28,     0,     0,    78,    79,
       0,     0,     0,     0,    29,   117,   117,     0,     0,     0,
       0,     0,     0,    80,     0,     0,     0,     0,     0,   113,
       0,   113,     0,     0,     0,     0,   117,     0,     0,   334,
       0,     0,   117,     0,     0,     0,     0,     0,   202,   448,
     145,   202,   347,   206,     0,     0,   198,     0,   145,   202,
       0,     0,   812,     0,   144,     0,   197,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   449,   450,     0,     0,
     451,   452,   114,     0,   453,     0,   144,   454,     0,     0,
       0,     0,     0,   144,   144,   144,     0,     0,    27,   202,
      28,   202,   144,   144,     0,     0,     0,     0,     0,    29,
       0,     0,     0,   145,   145,     0,     0,     0,   203,     0,
       0,   203,   197,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   145,     0,     0,   197,   197,   197,
     197,   197,     0,   197,     0,   334,   203,   203,     0,   197,
     198,   198,     0,   203,     0,     0,     0,     0,   197,   197,
     197,     0,   533,   534,     0,     0,     0,     0,   535,     0,
     117,   117,   117,   206,     0,     0,     0,     0,   117,     0,
       0,     0,   334,   117,   198,   117,   163,     0,     0,   117,
     117,   117,   117,   117,     0,     0,     0,     0,     0,     0,
     117,   117,   117,     0,     0,     0,    91,    92,    93,   117,
     117,     0,    77,     0,    28,     0,     0,    78,    79,     0,
       0,     0,     0,    29,     0,     0,     0,     0,     0,   206,
       0,     0,    80,     0,     0,   114,     0,     0,     0,     0,
       0,     0,     0,     0,   206,   206,   206,   206,   206,     0,
     347,   206,   206,     0,   144,   203,   206,     0,     0,     0,
       0,     0,     0,     0,     0,   347,   347,   347,     0,   145,
       0,   198,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   145,     0,   197,     0,     0,     0,     0,   145,   145,
     145,     0,     0,     0,     0,     0,     0,   145,   145,   114,
       0,   114,     0,     0,     0,     0,     0,     0,   197,   197,
       0,     0,     0,     0,     0,   197,     0,   198,   203,     0,
       0,   203,     0,     0,     0,     0,     0,     0,     0,   203,
       0,     0,   198,   198,   198,   198,   198,     0,   198,     0,
       0,     0,     0,     0,   198,     0,     0,     0,     0,     0,
       0,   117,     0,   198,   198,   198,     0,   208,   209,     0,
     210,   211,   212,   213,     0,     0,     0,     0,     0,   203,
     123,   203,   214,   215,   216,   217,     0,     0,     0,     0,
     378,     0,     0,   123,   126,   219,   220,     0,   379,     0,
     347,   127,     0,   302,     0,     0,     0,   126,   221,     0,
       0,   303,     0,     0,   127,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   347,   206,     0,    91,    92,
      93,     0,   347,   128,    77,   164,    28,     0,     0,    78,
      79,    91,    92,    93,     0,    29,   128,    77,     0,    28,
       0,     0,    78,    79,    80,     0,     0,     0,    29,   145,
       0,     0,     0,     0,     0,     0,     0,    80,     0,     0,
       0,     0,   123,     0,     0,     0,   160,   161,     0,     0,
       0,   144,   162,     0,     0,     0,   126,     0,     0,     0,
       0,     0,     0,   127,     0,     0,     0,     0,   198,     0,
     163,     0,     0,   197,     0,     0,     0,     0,     0,     0,
       0,   197,     0,     0,   117,     0,     0,     0,     0,     0,
      91,    92,    93,   198,   198,   128,    77,   164,    28,     0,
     198,    78,    79,     0,   206,     0,     0,    29,     0,     0,
       0,     0,     0,     0,     0,     0,    80,     0,     0,     0,
       0,   197,     0,   197,     0,     0,     0,   384,   208,   209,
       0,   210,   211,   212,   213,     0,     0,     0,   290,     0,
     312,   123,   291,   214,   215,   216,   217,   313,   314,     0,
     315,   218,     0,     0,   348,   126,   219,   220,   117,     0,
     117,     0,   127,   316,   317,   385,     0,     0,     0,   221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     347,     0,     0,     0,     0,     0,     0,     0,   206,    91,
      92,    93,     0,     0,   128,    77,   164,    28,     0,     0,
      78,    79,     0,     0,     0,     0,    29,     0,     0,     0,
       0,     0,     0,     0,     0,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   347,     0,
     347,   384,   208,   209,     0,   210,   211,   212,   213,     0,
       0,     0,   290,     0,   312,   123,   291,   214,   215,   216,
     217,   313,   314,     0,   315,   378,   145,     0,   348,   126,
     219,   220,     0,     0,     0,     0,   127,   316,   317,   385,
       0,     0,     0,   221,     0,     0,     0,     0,   198,     0,
       0,     0,     0,     0,     0,     0,   198,     0,     0,     0,
       0,     0,     0,    91,    92,    93,     0,     0,   128,    77,
     164,    28,     0,     0,    78,    79,     0,     0,     0,     0,
      29,     0,     0,     0,     0,     0,   384,   208,   209,    80,
     210,   211,   212,   213,     0,     0,   198,   290,   198,   312,
     123,   291,   214,   215,   216,   217,   313,   314,     0,   315,
     378,     0,     0,     0,   126,   219,   220,     0,     0,     0,
       0,   127,   316,   317,   385,     0,     0,     0,   221,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,     0,     0,   128,    77,   164,    28,     0,     0,    78,
      79,     0,     0,   208,   209,    29,   210,   211,   212,   213,
       0,     0,     0,     0,    80,     0,   123,     0,   214,   215,
     216,   217,     0,     0,     0,     0,   218,     0,     0,     0,
     126,   219,   220,     0,     0,     0,     0,   127,     0,     0,
       0,     0,     0,     0,   221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,     0,     0,   128,
      77,   164,    28,     0,     0,    78,    79,     0,     0,   208,
     209,    29,   210,   211,   212,   213,     0,     0,     0,     0,
      80,     0,   123,     0,   214,   215,   216,   217,     0,     0,
       0,     0,   378,     0,     0,     0,   126,   219,   220,     0,
       0,     0,     0,   127,     0,     0,     0,     0,     0,     0,
     221,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      91,    92,    93,     0,     0,   128,    77,   164,    28,     0,
       0,    78,    79,     0,     0,   208,   209,    29,   210,   211,
     212,   213,     0,     0,     0,     0,    80,     0,   123,     0,
     214,   215,   216,   217,     0,     0,     0,     0,   420,     0,
       0,     0,   126,   219,   220,     0,     0,     0,     0,   127,
       0,     0,     0,     0,     0,     0,   221,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    93,     0,
       0,   128,    77,   164,    28,     0,     0,    78,    79,     0,
       0,   208,   209,    29,   210,   211,   212,   213,     0,     0,
       0,     0,    80,     0,   123,     0,   214,   215,   216,   735,
       0,     0,     0,     0,   378,     0,     0,     0,   126,   219,
     220,     0,     0,     0,     0,   127,     0,     0,     0,     0,
       0,     0,   221,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,     0,     0,   128,    77,   164,
      28,     0,     0,    78,    79,     0,     0,   208,   209,    29,
     210,   211,   212,   213,     0,     0,     0,     0,    80,     0,
     123,     0,   214,   215,   570,   571,     0,     0,     0,     0,
     578,     0,     0,   123,   126,   219,   220,   160,   161,     0,
       0,     0,     0,   338,     0,     0,     0,   126,   221,     0,
       0,     0,     0,     0,   127,     0,     0,     0,     0,     0,
       0,   163,     0,     0,     0,     0,     0,     0,    91,    92,
      93,     0,     0,   128,    77,     0,    28,     0,     0,    78,
      79,    91,    92,    93,     0,    29,   128,    77,   164,    28,
       0,     0,    78,    79,    80,     0,     0,     0,    29,     0,
       0,     0,     0,     0,     0,     0,     0,    80
};

static const yytype_int16 yycheck[] =
{
       0,    20,    21,    22,    23,    24,    25,    26,    60,   145,
      67,   295,    20,    21,    66,    23,    24,    25,    26,    66,
      67,   145,   237,   371,   216,   491,   187,    90,   218,   359,
     300,   301,    51,    59,    34,   145,    59,    89,   360,   361,
      59,    67,    68,    51,    70,    64,   426,    70,   415,   285,
      59,    70,    67,    68,   195,    60,    64,   550,    69,   426,
     106,    66,   353,   354,   355,   356,   357,    11,   218,   506,
     550,    60,   653,    68,   259,   353,   354,   355,   356,   357,
     138,    25,   143,   244,    89,    90,   124,   125,    14,   195,
      30,    22,    18,   353,   354,   355,   356,   357,   281,   151,
      89,    11,   428,   429,   430,   162,   374,   375,   376,   292,
      68,   294,   281,    37,   172,    25,   299,   300,   301,    22,
      22,    27,    27,   292,    27,   294,    66,    67,   147,    34,
     299,   300,   301,    22,   281,   161,   162,    61,   719,   147,
     106,   187,    73,    12,    13,   292,   151,   294,    37,   233,
      74,    82,   299,   300,   301,    13,   414,   415,   416,   417,
     418,   618,   151,    27,    67,    37,    35,    36,   426,   195,
      73,    73,   230,   309,   310,   311,    11,    35,    36,    82,
      82,    27,   318,   319,   245,   309,   310,   311,    91,    61,
      25,   217,   218,    73,   318,   319,   432,    11,   244,   309,
     310,   311,    82,   218,   389,   395,   787,   233,   318,   319,
      27,    25,   353,   354,   355,   356,   357,    34,   281,   360,
     361,   187,   217,   218,   287,   282,   552,   279,   378,   292,
      14,   294,    13,   259,    18,   282,   299,   300,   301,   732,
      14,   509,    67,   289,    18,    29,   298,   353,   354,   355,
     356,   357,   732,    13,    35,    36,   282,   283,   284,   285,
     218,   284,   285,    27,   302,   284,   285,   282,   283,   280,
     420,    12,    13,   541,   279,   284,   295,   233,   244,   716,
      27,   338,   287,   631,    13,    27,   634,   744,   283,    27,
     279,   748,   749,   298,    35,    36,   322,   677,    71,    13,
      73,   327,    13,   350,   330,    13,    35,    36,   365,    82,
     677,   330,   338,   397,   398,   399,   400,   401,   402,   403,
      13,   643,    14,   129,   233,   283,    18,   353,   354,   355,
     356,   357,    13,   359,   360,   361,    22,   162,    13,   365,
      13,    27,   426,    13,   810,   371,    73,   153,   374,   375,
     376,    36,   378,   623,    35,    36,    28,    22,   373,   165,
      35,    36,    27,   389,   821,   506,    14,   557,   558,    13,
      18,   397,   398,   399,   400,   401,   402,   403,   570,    13,
     395,    67,    13,   378,   410,   411,   412,    73,   414,   415,
     416,   417,   418,   419,   420,    14,    82,    66,    67,    18,
     426,    66,   428,   429,   430,    91,   432,    14,    73,   432,
      30,    18,   427,   432,    27,   410,   222,    82,   413,   677,
     378,    12,   572,    14,    13,   420,   744,    18,   578,   448,
     748,   749,   470,   428,   429,   430,   727,   767,    29,   769,
     623,   397,   398,   399,   400,   401,   402,   403,   663,   727,
      36,    37,   410,    66,   623,   455,    13,   282,    35,    14,
      73,     3,   420,    18,   490,   491,   513,   727,   274,    82,
     426,   490,   491,    14,    16,    13,   623,    18,   535,    66,
      67,    23,    24,   509,    26,    13,    73,    27,   397,   398,
     399,   400,   401,   402,   403,    82,    27,    39,    40,    41,
      12,    13,   643,    20,    13,    22,    27,    14,   534,   535,
      27,    18,   662,   338,    40,   541,    27,   426,    44,    45,
      46,    47,   806,    35,    36,    37,   552,    27,   353,   354,
     355,   356,   357,    11,    14,   360,   361,   362,    18,    27,
     365,   825,   557,   558,   734,   571,   572,    14,    15,    61,
      67,    18,   578,    27,    14,    15,    73,   552,    18,    13,
     623,   697,    74,    27,    14,    82,    41,    22,    18,    12,
      13,    27,    27,   697,    91,   716,   571,   572,   411,   412,
     429,   430,    20,   578,    22,     3,   727,   697,    41,    27,
     796,   797,    29,   677,   613,   614,   615,   616,   617,    22,
      22,    11,    11,   629,    11,   631,   632,    27,   634,    17,
      41,    66,     3,   632,   572,   641,   642,   643,    73,    27,
     578,   727,   641,   642,    30,    22,     6,    82,    27,    67,
      38,    27,    60,    61,    27,    73,    41,    27,    66,    67,
      68,    69,     3,     6,    82,    74,   672,   699,    37,    22,
     676,   677,    27,    91,    13,    27,    27,    65,    66,    67,
      36,    89,    90,    71,   683,    73,    21,    27,    76,    77,
      35,   718,    14,    13,    82,   701,    22,   672,   704,    36,
      36,   707,   701,    91,   710,   704,    67,   687,   707,   330,
      45,   710,   692,   719,   699,    36,   124,   125,     0,    35,
      35,   727,    36,    91,    36,    36,    66,    34,    13,   735,
     535,    66,    67,    73,   672,    70,    35,   145,    73,   734,
      36,   677,    82,   151,    36,    36,   745,    82,    61,    22,
      27,    30,   758,   161,   162,    13,    36,   745,    36,   758,
     735,   767,    36,   769,    35,    22,    48,    11,    36,    51,
      52,   777,   778,    55,    56,    36,    58,    59,    27,   785,
      36,    27,    36,    36,    36,   791,   785,   195,   677,    36,
      27,    36,   798,   491,    36,    27,    27,   735,    27,   798,
     161,   162,   777,   778,   810,    13,    30,   806,    36,    13,
     218,   810,    30,    36,    36,    35,   791,    13,    35,    65,
      66,    67,    13,    11,    30,    71,   825,    73,    22,     3,
      76,    77,     6,   813,   195,    61,    82,    27,   643,   777,
     778,    13,    16,    30,    36,    91,    61,    36,   653,    23,
      24,    35,    26,   791,    36,    36,    13,    30,    61,    35,
      13,   233,    11,     6,     6,    39,    40,    41,    36,   490,
     491,   279,   280,   281,   282,   283,    36,    22,    36,   287,
      36,    13,    30,    35,   292,    22,   294,   259,    11,    11,
     298,   299,   300,   301,   302,    13,    35,    11,    36,    15,
      36,   309,   310,   311,    49,    50,    36,    13,    53,    54,
     318,   319,    57,    13,   719,    60,    35,    13,     3,    36,
      35,   282,   727,    36,    36,    36,    71,    13,    73,    11,
     338,    16,    13,    13,   632,    13,    13,    82,    23,    24,
      35,    26,   350,   641,   642,   353,   354,   355,   356,   357,
      13,   359,   360,   361,    39,    40,    41,   365,    13,    34,
      36,    12,    30,    30,    34,   373,   374,   375,   376,    13,
      36,    36,    60,    61,    11,    13,    12,   338,    66,    67,
      13,    69,   787,    35,    13,    35,    13,   395,    13,    36,
      36,    22,   353,   354,   355,   356,   357,    36,   359,    11,
      35,    89,    90,   701,   365,    13,    36,   283,    36,   707,
      36,   632,   710,   374,   375,   376,    37,   389,   676,   427,
     641,   642,   734,   791,   672,   397,   398,   399,   400,   401,
     402,   403,   282,   677,   195,   718,   124,   125,   653,   411,
     412,   787,   414,   415,   416,   417,   418,   330,   491,   785,
     758,   798,   732,   704,   426,   629,   716,   145,   699,   321,
     758,   125,   470,   151,   470,   298,   264,     4,     5,   723,
       7,   683,   692,   161,   162,   825,   147,   427,   614,    -1,
     701,    -1,    19,   704,    21,    22,   707,   785,    -1,   710,
      27,    -1,    -1,    -1,    -1,    32,    -1,    -1,   506,    -1,
     798,   509,    -1,    -1,    -1,   513,   514,   195,    45,    -1,
      17,    -1,   810,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    -1,    -1,    -1,    31,    -1,   534,   535,    65,    66,
      67,    38,    -1,   541,    71,    -1,    73,   758,    45,    76,
      77,    -1,    -1,    -1,    -1,    82,    -1,    22,   509,   557,
     558,    -1,    -1,    -1,    91,    -1,    -1,    -1,    -1,    66,
      67,    -1,    -1,    70,   785,    72,    73,    42,    43,    44,
      -1,    46,    47,   534,   535,    82,    -1,   798,   550,    -1,
     541,    -1,    -1,    -1,    91,    -1,    -1,    -1,    -1,   810,
      65,   279,   280,   281,   282,    -1,    71,    -1,    73,   287,
      -1,    76,    77,    -1,   292,    38,   294,    82,    -1,    -1,
     298,   299,   300,   301,   302,   623,    91,    -1,    -1,    -1,
     233,   309,   310,   311,    -1,    -1,    -1,    -1,    -1,    -1,
     318,   319,    65,    66,    67,   643,    -1,    -1,    71,    -1,
      73,    -1,    -1,    76,    77,   653,   259,    -1,    -1,    82,
     338,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,
      -1,    -1,   350,    -1,    -1,   353,   354,   355,   356,   357,
      -1,   359,   360,   361,    -1,    -1,    -1,   365,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   373,   374,   375,   376,   697,
      -1,   699,    60,    61,    -1,    -1,    -1,    -1,    66,    67,
      68,    69,    -1,    -1,    -1,   677,    -1,   395,   716,    -1,
     718,   719,     3,    -1,    -1,    -1,    -1,    -1,    -1,   727,
      -1,    89,    90,    14,    -1,    16,   734,    18,    -1,    -1,
      21,    22,    23,    24,    -1,    26,    27,    -1,    -1,   427,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,   124,   125,   719,   767,
     732,   769,    -1,    -1,    -1,    -1,   727,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   389,   145,    -1,   787,
      -1,    72,   470,   151,   397,   398,   399,   400,   401,   402,
     403,    -1,   160,   161,   162,    -1,    -1,    -1,    -1,    -1,
      -1,   414,   415,   416,   417,   418,   767,    -1,   769,    -1,
      -1,    -1,    -1,   426,     4,     5,    -1,     7,   506,    -1,
      -1,   509,    -1,    -1,    -1,   513,   514,   195,    -1,    19,
      -1,    21,    22,    -1,    -1,    -1,    -1,    27,    -1,    22,
      -1,    -1,    32,    -1,    -1,    -1,   534,   535,   216,    -1,
     218,    -1,    35,   541,    -1,    45,    -1,    -1,    -1,    42,
      43,    44,    -1,    46,    47,    -1,    -1,    -1,    -1,   557,
     558,    -1,    -1,    -1,    -1,    65,    66,    67,    -1,    -1,
      70,    71,    65,    73,    -1,    -1,    76,    77,    71,    -1,
      73,    -1,    82,    76,    77,    -1,    -1,    -1,    -1,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,
      -1,   279,   280,   281,   282,   283,    -1,    -1,    -1,   287,
      -1,    -1,    -1,    -1,   292,    -1,   294,    -1,    -1,    -1,
     298,   299,   300,   301,   302,   623,    -1,    -1,    -1,    -1,
      -1,   309,   310,   311,    -1,    -1,    -1,    -1,    -1,    -1,
     318,   319,    -1,    -1,    -1,   643,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   653,    -1,    -1,    -1,    -1,
     338,    -1,    60,    61,    -1,    -1,    -1,    -1,    66,    67,
      -1,    69,   350,    -1,    -1,   353,   354,   355,   356,   357,
      -1,   359,   360,   361,    -1,    -1,    -1,   365,    -1,    -1,
      -1,    89,    90,    -1,    -1,   373,   374,   375,   376,   697,
      -1,   699,    65,    66,    67,    -1,    -1,    -1,    71,    -1,
      73,    -1,    -1,    76,    77,    -1,    -1,   395,   716,    82,
     718,   719,    -1,    -1,    -1,    -1,   124,   125,    91,   727,
      -1,    17,    -1,    -1,    -1,    -1,   734,    -1,    -1,    -1,
      -1,    27,    -1,    -1,    -1,    31,    -1,   145,    -1,   427,
      -1,    -1,    38,   151,   677,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   160,   161,   162,    -1,    -1,    -1,    -1,   767,
      -1,   769,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      66,    67,    -1,    -1,    70,    71,    -1,    73,    -1,   787,
      76,    77,   470,    -1,    -1,    -1,    82,   195,     4,     5,
      -1,     7,     8,     9,    10,    91,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    19,    20,    21,    22,    -1,   216,    -1,
      -1,    27,    -1,    -1,    30,    31,    32,    33,   506,    35,
      -1,   509,    38,    -1,    -1,   513,   514,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   533,   534,   535,    -1,    65,
      66,    67,    -1,   541,    70,    71,    72,    73,    -1,    -1,
      76,    77,    -1,    -1,    -1,    -1,    82,    -1,    -1,   557,
     558,   279,   280,   281,   282,    91,    27,    -1,    -1,   287,
      -1,    -1,   570,    -1,   292,    -1,   294,    38,    -1,    -1,
     298,   299,   300,   301,   302,    -1,    -1,    -1,    -1,    -1,
      -1,   309,   310,   311,    -1,    -1,    -1,    -1,    -1,    -1,
     318,   319,    -1,    -1,    65,    66,    67,    -1,    -1,    -1,
      71,    -1,    73,    -1,    -1,    76,    77,    -1,    -1,    -1,
     338,    82,    60,    61,    -1,   623,    -1,    -1,    66,    67,
      91,    69,   350,    -1,    -1,   353,   354,   355,   356,   357,
      -1,   359,   360,   361,    -1,   643,    -1,   365,    -1,    -1,
      -1,    89,    90,    -1,    -1,   373,   374,   375,   376,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   395,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    -1,   124,   125,    21,    22,
      -1,    -1,    -1,    -1,    27,    -1,    -1,    30,    31,   697,
      -1,   699,    35,    -1,    -1,    38,    -1,   145,    -1,   427,
      -1,    -1,    45,   151,    -1,    27,    -1,    -1,   716,    -1,
     718,   719,   160,   161,   162,    -1,    38,    -1,    -1,   727,
      -1,    -1,    65,    66,    67,    -1,   734,    70,    71,    72,
      73,    -1,    -1,    76,    77,    -1,    -1,    -1,    -1,    82,
      -1,    -1,   470,    65,    66,    67,    -1,   195,    91,    71,
      -1,    73,    -1,    -1,    76,    77,    -1,    -1,    -1,   767,
      82,   769,    17,    -1,    -1,    -1,    21,    22,   216,    91,
      -1,    -1,    27,    -1,    -1,    30,    31,    -1,   506,    -1,
      -1,   509,    -1,    38,    -1,   513,   514,    -1,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   533,   534,   535,    -1,    -1,
      65,    66,    67,   541,    -1,    70,    71,    72,    73,    -1,
      -1,    76,    77,    -1,    -1,    -1,    -1,    82,    -1,   557,
     558,   279,   280,   281,   282,    -1,    91,    -1,    -1,   287,
      -1,    -1,   570,    -1,   292,    -1,   294,    -1,    -1,    -1,
     298,   299,   300,   301,   302,    -1,    -1,    -1,    -1,    -1,
      -1,   309,   310,   311,    -1,    -1,    -1,    -1,    -1,    -1,
     318,   319,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     338,    27,    60,    61,    -1,   623,    -1,    -1,    66,    67,
      -1,    69,    38,    -1,    -1,   353,   354,   355,   356,   357,
      -1,   359,   360,   361,    -1,   643,    -1,   365,    -1,    -1,
      -1,    89,    90,    -1,    -1,   373,   374,   375,   376,    65,
      66,    67,    -1,    -1,    -1,    71,    -1,    73,    -1,    -1,
      76,    77,    -1,    -1,    -1,    -1,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    91,   124,   125,    21,    22,
      -1,    -1,    -1,    -1,    27,    -1,    -1,    30,    31,   697,
      -1,   699,    -1,    -1,    -1,    38,    -1,   145,    -1,   427,
      -1,    -1,    45,   151,    -1,    -1,    -1,    -1,   716,    -1,
     718,   719,   160,   161,   162,    -1,    -1,    -1,    -1,   727,
      -1,    -1,    65,    66,    67,    -1,   734,    70,    71,    72,
      73,    -1,    -1,    76,    77,    -1,    -1,    -1,    -1,    82,
      -1,    -1,   470,    -1,    -1,    -1,    -1,   195,    91,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   767,
      -1,   769,    17,    -1,    -1,    -1,    21,    22,   216,    -1,
      -1,    -1,    27,    -1,    -1,    -1,    31,    -1,   506,    -1,
      35,   509,    -1,    38,    -1,    61,    -1,    -1,    -1,    -1,
      45,    67,    -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   533,   534,   535,    -1,    -1,
      65,    66,    67,   541,    -1,    70,    71,    72,    73,    -1,
      -1,    76,    77,    -1,    -1,    -1,    -1,    82,    -1,    -1,
      -1,   279,   280,   281,   282,    -1,    91,    -1,    -1,   287,
      -1,    -1,   570,    -1,   292,    -1,   294,    -1,   124,   125,
     298,   299,   300,   301,   302,    -1,    -1,    -1,    -1,    -1,
      -1,   309,   310,   311,    -1,    -1,    -1,    -1,    -1,   145,
     318,   319,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   161,   162,    -1,    -1,    17,
     338,    60,    61,    -1,    22,   623,    -1,    66,    67,    27,
      69,    -1,    -1,    31,    -1,   353,   354,   355,   356,   357,
      38,   359,   360,   361,    -1,   643,    -1,   365,    -1,   195,
      89,    90,    -1,    -1,    -1,   373,   374,   375,   376,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    67,
      -1,    -1,    70,    71,    -1,    73,    -1,    -1,    76,    77,
      -1,    -1,    -1,    -1,    82,   124,   125,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,   697,
      -1,   699,    -1,    -1,    -1,    -1,   145,    -1,    -1,   427,
      -1,    -1,   151,    -1,    -1,    -1,    -1,    -1,   716,    22,
      61,   719,   161,   162,    -1,    -1,    67,    -1,    69,   727,
      -1,    -1,    35,    -1,   280,    -1,   282,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    -1,
      53,    54,   470,    -1,    57,    -1,   302,    60,    -1,    -1,
      -1,    -1,    -1,   309,   310,   311,    -1,    -1,    71,   767,
      73,   769,   318,   319,    -1,    -1,    -1,    -1,    -1,    82,
      -1,    -1,    -1,   124,   125,    -1,    -1,    -1,   506,    -1,
      -1,   509,   338,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   145,    -1,    -1,   353,   354,   355,
     356,   357,    -1,   359,    -1,   533,   534,   535,    -1,   365,
     161,   162,    -1,   541,    -1,    -1,    -1,    -1,   374,   375,
     376,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    -1,
     279,   280,   281,   282,    -1,    -1,    -1,    -1,   287,    -1,
      -1,    -1,   570,   292,   195,   294,    45,    -1,    -1,   298,
     299,   300,   301,   302,    -1,    -1,    -1,    -1,    -1,    -1,
     309,   310,   311,    -1,    -1,    -1,    65,    66,    67,   318,
     319,    -1,    71,    -1,    73,    -1,    -1,    76,    77,    -1,
      -1,    -1,    -1,    82,    -1,    -1,    -1,    -1,    -1,   338,
      -1,    -1,    91,    -1,    -1,   623,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   353,   354,   355,   356,   357,    -1,
     359,   360,   361,    -1,   470,   643,   365,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   374,   375,   376,    -1,   280,
      -1,   282,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   302,    -1,   509,    -1,    -1,    -1,    -1,   309,   310,
     311,    -1,    -1,    -1,    -1,    -1,    -1,   318,   319,   697,
      -1,   699,    -1,    -1,    -1,    -1,    -1,    -1,   534,   535,
      -1,    -1,    -1,    -1,    -1,   541,    -1,   338,   716,    -1,
      -1,   719,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   727,
      -1,    -1,   353,   354,   355,   356,   357,    -1,   359,    -1,
      -1,    -1,    -1,    -1,   365,    -1,    -1,    -1,    -1,    -1,
      -1,   470,    -1,   374,   375,   376,    -1,     4,     5,    -1,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,   767,
      17,   769,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      27,    -1,    -1,    17,    31,    32,    33,    -1,    35,    -1,
     509,    38,    -1,    27,    -1,    -1,    -1,    31,    45,    -1,
      -1,    35,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   534,   535,    -1,    65,    66,
      67,    -1,   541,    70,    71,    72,    73,    -1,    -1,    76,
      77,    65,    66,    67,    -1,    82,    70,    71,    -1,    73,
      -1,    -1,    76,    77,    91,    -1,    -1,    -1,    82,   470,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,
      -1,    -1,    17,    -1,    -1,    -1,    21,    22,    -1,    -1,
      -1,   697,    27,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,   509,    -1,
      45,    -1,    -1,   719,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   727,    -1,    -1,   623,    -1,    -1,    -1,    -1,    -1,
      65,    66,    67,   534,   535,    70,    71,    72,    73,    -1,
     541,    76,    77,    -1,   643,    -1,    -1,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,    -1,
      -1,   767,    -1,   769,    -1,    -1,    -1,     3,     4,     5,
      -1,     7,     8,     9,    10,    -1,    -1,    -1,    14,    -1,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      26,    27,    -1,    -1,    30,    31,    32,    33,   697,    -1,
     699,    -1,    38,    39,    40,    41,    -1,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     719,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   727,    65,
      66,    67,    -1,    -1,    70,    71,    72,    73,    -1,    -1,
      76,    77,    -1,    -1,    -1,    -1,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   767,    -1,
     769,     3,     4,     5,    -1,     7,     8,     9,    10,    -1,
      -1,    -1,    14,    -1,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    26,    27,   697,    -1,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,   719,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   727,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    66,    67,    -1,    -1,    70,    71,
      72,    73,    -1,    -1,    76,    77,    -1,    -1,    -1,    -1,
      82,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    91,
       7,     8,     9,    10,    -1,    -1,   767,    14,   769,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    26,
      27,    -1,    -1,    -1,    31,    32,    33,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    -1,    -1,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,
      67,    -1,    -1,    70,    71,    72,    73,    -1,    -1,    76,
      77,    -1,    -1,     4,     5,    82,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    91,    -1,    17,    -1,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,
      31,    32,    33,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    66,    67,    -1,    -1,    70,
      71,    72,    73,    -1,    -1,    76,    77,    -1,    -1,     4,
       5,    82,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      91,    -1,    17,    -1,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    27,    -1,    -1,    -1,    31,    32,    33,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    66,    67,    -1,    -1,    70,    71,    72,    73,    -1,
      -1,    76,    77,    -1,    -1,     4,     5,    82,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    91,    -1,    17,    -1,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    27,    -1,
      -1,    -1,    31,    32,    33,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    67,    -1,
      -1,    70,    71,    72,    73,    -1,    -1,    76,    77,    -1,
      -1,     4,     5,    82,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    91,    -1,    17,    -1,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,
      33,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    66,    67,    -1,    -1,    70,    71,    72,
      73,    -1,    -1,    76,    77,    -1,    -1,     4,     5,    82,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    91,    -1,
      17,    -1,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      27,    -1,    -1,    17,    31,    32,    33,    21,    22,    -1,
      -1,    -1,    -1,    27,    -1,    -1,    -1,    31,    45,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,
      67,    -1,    -1,    70,    71,    -1,    73,    -1,    -1,    76,
      77,    65,    66,    67,    -1,    82,    70,    71,    72,    73,
      -1,    -1,    76,    77,    91,    -1,    -1,    -1,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    91
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,    94,   320,     0,    48,    51,    52,    55,    56,    58,
      59,    95,    96,    97,    99,   100,   101,   102,   103,   303,
      27,    27,    27,    27,    27,    27,    27,    71,    73,    82,
     314,   315,   314,   315,   319,   314,   314,   314,   314,    13,
      13,    13,   304,   320,    13,    13,    13,    13,    73,   105,
     105,    22,    37,   305,    36,   105,   105,   105,   105,    28,
      13,    13,   306,   314,    13,    30,    13,    13,    13,    13,
      22,    42,    43,    44,    46,    47,    65,    71,    76,    77,
      91,   282,   308,   309,   310,   311,   312,   315,   318,    27,
      38,    65,    66,    67,   226,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   243,   244,   248,   249,
     250,   273,   274,   275,   276,   277,   278,   281,   282,   315,
     316,   317,   318,    17,    22,    27,    31,    38,    70,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   231,   245,   246,   258,   261,    35,    13,   307,   314,
      17,    27,   189,   215,   216,   217,   248,   269,   273,   277,
      21,    22,    27,    45,    72,   153,   154,   155,   156,   157,
     158,   159,   160,   162,   163,   164,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   184,   186,   187,   189,
     201,   202,   203,   208,   214,   256,   257,   258,   261,   269,
     273,   274,   275,   276,   277,   278,   281,   282,     4,     5,
       7,     8,     9,    10,    19,    20,    21,    22,    27,    32,
      33,    45,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   116,   117,   118,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   136,   138,   139,   142,   144,   146,
     147,   148,   149,   150,   151,   152,   204,   214,   251,   252,
     253,   254,   258,   261,   269,   273,   274,   275,   276,   277,
     278,   280,   281,   282,    98,   218,    35,   308,   313,    27,
      27,    27,    27,    27,    11,    27,   248,    27,   231,   243,
      14,    18,   270,   271,   272,    13,   104,   320,    41,    27,
      27,    27,    27,    35,   219,   247,   219,   245,   104,    41,
       3,     3,    16,    23,    24,    26,    39,    40,    41,   259,
      29,   262,    22,   225,   227,   228,   306,    22,   189,   104,
      11,    30,   212,   275,   276,   277,   278,   279,    27,    30,
      35,   154,   185,   187,   188,   273,   277,   281,    30,   154,
      27,    30,   104,    41,     3,     3,    41,   259,    15,   264,
     270,   272,   262,     6,    22,    27,   161,   162,   169,   171,
     282,    22,    25,   255,    27,    27,    27,   212,    27,    35,
     107,   141,   273,   277,     3,    41,   107,   137,   142,   252,
     259,   260,   269,   271,   272,    27,   104,    41,     3,     6,
       3,     6,    41,   259,   114,   116,   121,   124,   128,   138,
     264,   270,   272,   262,    37,    61,    74,    37,    74,    22,
      27,   115,   116,   122,   124,   282,    11,   255,    27,    27,
      27,   104,    13,    35,   248,   218,   237,   240,   241,   243,
     153,   106,   308,   313,    36,   231,   243,   243,    22,    49,
      50,    53,    54,    57,    60,   283,   285,   286,   288,   290,
     291,   293,   295,   314,    36,   250,   242,   243,   242,   242,
      13,    35,    36,    36,    36,   227,   227,   227,   227,   227,
     246,   230,   282,   165,   166,   167,   282,    36,    36,    20,
      22,    27,   190,   191,   192,   194,   195,   197,   199,   265,
     266,   267,   282,   315,   316,    34,    27,    34,    35,    13,
      35,    36,    36,    22,    27,   178,   189,   273,   274,   277,
      61,    36,   160,   162,   168,   171,   175,   187,   160,   160,
     160,   160,   185,    21,    22,    27,   171,   186,   282,   186,
     187,    27,   154,   165,   268,   269,   275,   188,   188,   188,
      27,    34,    13,    35,    36,    36,    36,    22,    27,   131,
     142,    36,   114,   114,   114,   114,   114,   114,   114,   107,
      21,    22,    27,   124,   136,   282,   136,   138,    27,   116,
     144,   144,   147,   144,   144,   144,   119,   120,   282,   107,
     113,   114,   116,   143,   144,   145,   147,   268,   140,   141,
     140,   140,    36,   313,    36,    36,    36,    36,    36,    36,
      36,   283,   284,    27,    27,    27,    27,    27,    13,   301,
     320,    30,    36,    13,    36,    36,   247,    30,    35,    13,
      35,    13,    11,    30,    22,   190,   200,   191,   194,   195,
     198,    61,    27,    70,   171,   202,   209,   210,   211,   213,
     188,   179,   189,    13,    30,   154,   188,    36,    35,    36,
      36,    36,    27,   124,   151,   205,   206,   207,   213,   141,
     132,   142,    13,    30,   107,    35,    13,    11,    36,    36,
      36,    36,    30,    13,    35,   296,   315,   319,   287,   315,
     289,   315,   294,   315,   302,   312,   242,    11,   230,    11,
     165,    27,   195,   165,    13,    35,    36,    37,    36,    36,
      37,   195,   195,   196,   186,    36,    13,    35,    13,    22,
     172,   180,   181,   182,   187,    36,    36,    11,    21,    27,
     252,    36,    13,    35,    13,    22,   107,   133,   134,    36,
      11,   119,   143,   284,    13,    13,   292,   320,    13,    13,
     301,   227,   216,   195,    35,   200,   195,   195,    13,    36,
      34,   209,   179,   172,   181,   183,   187,    13,    12,   263,
     160,    34,   205,   132,   107,   134,   135,   263,    13,   302,
     314,    36,   302,   302,    36,    11,   196,    13,    35,   185,
     185,    13,    35,   107,   107,    13,    13,    13,    27,   192,
     193,   195,   183,    36,   135,    36,    22,   297,   297,   297,
      27,   197,    35,   283,   298,   299,    36,    36,    36,   194,
      36,    11,   300,   320,    35,    13,   312,   298
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,    93,    94,    94,    95,    95,    96,    96,    96,    96,
      96,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     104,   105,   105,   106,   106,   106,   107,   107,   107,   107,
     107,   107,   108,   108,   108,   109,   110,   110,   110,   111,
     111,   112,   112,   113,   113,   114,   114,   114,   115,   115,
     116,   116,   116,   116,   117,   118,   119,   119,   120,   121,
     121,   122,   123,   124,   124,   124,   124,   125,   125,   126,
     126,   126,   126,   126,   127,   127,   128,   129,   130,   131,
     131,   132,   132,   133,   133,   134,   135,   135,   136,   136,
     136,   137,   137,   137,   137,   137,   138,   138,   139,   139,
     139,   140,   141,   141,   142,   142,   143,   143,   143,   144,
     145,   146,   146,   146,   147,   147,   148,   148,   149,   149,
     150,   151,   152,   153,   153,   153,   154,   154,   154,   154,
     154,   154,   155,   155,   156,   157,   157,   158,   158,   159,
     159,   160,   160,   160,   161,   161,   162,   162,   162,   162,
     163,   164,   165,   165,   166,   166,   167,   168,   168,   169,
     170,   171,   171,   171,   172,   172,   173,   174,   174,   174,
     174,   175,   176,   176,   177,   178,   178,   179,   179,   180,
     180,   181,   182,   182,   183,   183,   184,   185,   185,   185,
     186,   186,   186,   186,   186,   187,   187,   188,   188,   189,
     189,   190,   190,   191,   191,   191,   192,   193,   193,   193,
     194,   194,   195,   195,   195,   195,   195,   195,   196,   196,
     197,   198,   198,   199,   200,   200,   201,   202,   203,   204,
     204,   205,   205,   206,   206,   207,   208,   208,   209,   209,
     210,   210,   211,   212,   213,   214,   214,   214,   214,   215,
     215,   216,   216,   217,   218,   218,   219,   219,   219,   220,
     220,   221,   222,   222,   223,   223,   224,   224,   225,   225,
     226,   227,   227,   228,   228,   228,   229,   230,   230,   231,
     231,   231,   232,   233,   233,   234,   235,   236,   237,   237,
     238,   238,   239,   240,   240,   241,   241,   242,   242,   243,
     243,   244,   244,   244,   245,   245,   246,   246,   247,   247,
     248,   248,   249,   249,   250,   250,   250,   250,   251,   251,
     251,   252,   252,   253,   253,   254,   254,   254,   255,   256,
     256,   257,   258,   258,   258,   259,   259,   259,   259,   259,
     259,   260,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   268,   269,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   279,   280,   280,   280,   280,   280,
     281,   281,   282,   283,   283,   283,   283,   283,   284,   284,
     285,   285,   286,   287,   288,   289,   290,   290,   290,   291,
     292,   292,   293,   294,   295,   296,   297,   297,   298,   298,
     299,   300,   300,   301,   301,   302,   303,   304,   304,   304,
     305,   305,   306,   306,   307,   308,   308,   308,   309,   309,
     309,   309,   309,   309,   310,   311,   311,   311,   311,   311,
     312,   312,   313,   313,   314,   314,   315,   315,   316,   317,
     318,   318,   318,   319,   320
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,    10,     1,    10,    10,    10,    10,    10,     3,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     5,     1,     3,     3,     1,
       1,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     3,     1,     8,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     1,     1,
       3,     1,     1,     1,     1,     1,     2,     3,     4,     4,
       4,     1,     1,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     6,     1,     3,     1,     1,     3,     1,     1,     2,
       3,     1,     1,     1,     1,     4,     1,     1,     4,     1,
       1,     3,     1,     4,     8,     1,     3,     1,     3,     1,
       3,     3,     1,     1,     1,     3,     5,     1,     1,     1,
       1,     1,     1,     1,     3,     2,     3,     1,     3,     3,
       3,     1,     1,     1,     1,     3,     6,     1,     3,     1,
       1,     3,     1,     1,     1,     4,     3,     1,     1,     3,
       3,     3,     3,     3,     1,     3,     3,     3,     3,     3,
       6,     1,     3,     1,     1,     1,     3,     6,     1,     3,
       1,     1,     1,     1,     2,     3,     3,     3,     3,     1,
       1,     1,     1,     6,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     3,     3,     3,     3,     2,     1,
       3,     1,     1,     1,     1,     3,     6,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     4,
       1,     1,     1,     1,     4,     1,     4,     1,     3,     1,
       1,     1,     1,     1,     3,     3,     2,     3,     1,     3,
       1,     3,     1,     3,     1,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     3,
       1,     1,     8,     1,     8,     1,     1,     1,     1,     5,
       2,     1,     5,     1,     8,     1,     2,     3,     1,     3,
       2,     2,     1,     2,     1,     1,     6,     1,     2,     4,
       3,     1,     1,     3,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       2,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0
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
  case 2: /* TPTP_file: null  */
#line 246 "SyntaxBNF.y"
                 {}
#line 2994 "y.tab.c"
    break;

  case 3: /* TPTP_file: TPTP_file TPTP_input  */
#line 247 "SyntaxBNF.y"
                                           {}
#line 3000 "y.tab.c"
    break;

  case 4: /* TPTP_input: annotated_formula  */
#line 250 "SyntaxBNF.y"
                               {P_PRINT((yyval.pval));}
#line 3006 "y.tab.c"
    break;

  case 5: /* TPTP_input: include  */
#line 251 "SyntaxBNF.y"
                              {P_PRINT((yyval.pval));}
#line 3012 "y.tab.c"
    break;

  case 6: /* annotated_formula: thf_annotated  */
#line 254 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3018 "y.tab.c"
    break;

  case 7: /* annotated_formula: tff_annotated  */
#line 255 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3024 "y.tab.c"
    break;

  case 8: /* annotated_formula: tcf_annotated  */
#line 256 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3030 "y.tab.c"
    break;

  case 9: /* annotated_formula: fof_annotated  */
#line 257 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3036 "y.tab.c"
    break;

  case 10: /* annotated_formula: cnf_annotated  */
#line 258 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3042 "y.tab.c"
    break;

  case 11: /* annotated_formula: tpi_annotated  */
#line 259 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3048 "y.tab.c"
    break;

  case 12: /* tpi_annotated: _LIT_tpi LPAREN name COMMA formula_role COMMA tpi_formula annotations RPAREN PERIOD  */
#line 262 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("tpi_annotated", P_TOKEN("_LIT_tpi ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 3054 "y.tab.c"
    break;

  case 13: /* tpi_formula: fof_formula  */
#line 265 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("tpi_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3060 "y.tab.c"
    break;

  case 14: /* thf_annotated: _LIT_thf LPAREN name COMMA formula_role COMMA thf_formula annotations RPAREN PERIOD  */
#line 268 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("thf_annotated", P_TOKEN("_LIT_thf ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 3066 "y.tab.c"
    break;

  case 15: /* tff_annotated: _LIT_tff LPAREN name COMMA formula_role COMMA tff_formula annotations RPAREN PERIOD  */
#line 271 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("tff_annotated", P_TOKEN("_LIT_tff ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 3072 "y.tab.c"
    break;

  case 16: /* tcf_annotated: _LIT_tcf LPAREN name COMMA formula_role COMMA tcf_formula annotations RPAREN PERIOD  */
#line 274 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("tcf_annotated", P_TOKEN("_LIT_tcf ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 3078 "y.tab.c"
    break;

  case 17: /* fof_annotated: _LIT_fof LPAREN name COMMA formula_role COMMA fof_formula annotations RPAREN PERIOD  */
#line 277 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("fof_annotated", P_TOKEN("_LIT_fof ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 3084 "y.tab.c"
    break;

  case 18: /* cnf_annotated: _LIT_cnf LPAREN name COMMA formula_role COMMA cnf_formula annotations RPAREN PERIOD  */
#line 280 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("cnf_annotated", P_TOKEN("_LIT_cnf ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 3090 "y.tab.c"
    break;

  case 19: /* annotations: COMMA source optional_info  */
#line 283 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("annotations", P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3096 "y.tab.c"
    break;

  case 20: /* annotations: null  */
#line 284 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("annotations", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3102 "y.tab.c"
    break;

  case 21: /* formula_role: lower_word  */
#line 287 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("formula_role", P_TOKEN("lower_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3108 "y.tab.c"
    break;

  case 22: /* formula_role: lower_word MINUS general_term  */
#line 288 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("formula_role", P_TOKEN("lower_word ", (yyvsp[-2].ival)), P_TOKEN("MINUS ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3114 "y.tab.c"
    break;

  case 23: /* thf_formula: thf_logic_formula  */
#line 291 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3120 "y.tab.c"
    break;

  case 24: /* thf_formula: thf_atom_typing  */
#line 292 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3126 "y.tab.c"
    break;

  case 25: /* thf_formula: thf_subtype  */
#line 293 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("thf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3132 "y.tab.c"
    break;

  case 26: /* thf_logic_formula: thf_unitary_formula  */
#line 296 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3138 "y.tab.c"
    break;

  case 27: /* thf_logic_formula: thf_unary_formula  */
#line 297 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3144 "y.tab.c"
    break;

  case 28: /* thf_logic_formula: thf_binary_formula  */
#line 298 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3150 "y.tab.c"
    break;

  case 29: /* thf_logic_formula: thf_defined_infix  */
#line 299 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3156 "y.tab.c"
    break;

  case 30: /* thf_logic_formula: thf_definition  */
#line 300 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3162 "y.tab.c"
    break;

  case 31: /* thf_logic_formula: thf_sequent  */
#line 301 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3168 "y.tab.c"
    break;

  case 32: /* thf_binary_formula: thf_binary_nonassoc  */
#line 304 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3174 "y.tab.c"
    break;

  case 33: /* thf_binary_formula: thf_binary_assoc  */
#line 305 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3180 "y.tab.c"
    break;

  case 34: /* thf_binary_formula: thf_binary_type  */
#line 306 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3186 "y.tab.c"
    break;

  case 35: /* thf_binary_nonassoc: thf_unit_formula nonassoc_connective thf_unit_formula  */
#line 309 "SyntaxBNF.y"
                                                                            {(yyval.pval) = P_BUILD("thf_binary_nonassoc", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3192 "y.tab.c"
    break;

  case 36: /* thf_binary_assoc: thf_or_formula  */
#line 312 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("thf_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3198 "y.tab.c"
    break;

  case 37: /* thf_binary_assoc: thf_and_formula  */
#line 313 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3204 "y.tab.c"
    break;

  case 38: /* thf_binary_assoc: thf_apply_formula  */
#line 314 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3210 "y.tab.c"
    break;

  case 39: /* thf_or_formula: thf_unit_formula VLINE thf_unit_formula  */
#line 317 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("thf_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3216 "y.tab.c"
    break;

  case 40: /* thf_or_formula: thf_or_formula VLINE thf_unit_formula  */
#line 318 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("thf_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3222 "y.tab.c"
    break;

  case 41: /* thf_and_formula: thf_unit_formula AMPERSAND thf_unit_formula  */
#line 321 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3228 "y.tab.c"
    break;

  case 42: /* thf_and_formula: thf_and_formula AMPERSAND thf_unit_formula  */
#line 322 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3234 "y.tab.c"
    break;

  case 43: /* thf_apply_formula: thf_unit_formula AT_SIGN thf_unit_formula  */
#line 325 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_apply_formula", (yyvsp[-2].pval), P_TOKEN("AT_SIGN ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3240 "y.tab.c"
    break;

  case 44: /* thf_apply_formula: thf_apply_formula AT_SIGN thf_unit_formula  */
#line 326 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_apply_formula", (yyvsp[-2].pval), P_TOKEN("AT_SIGN ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3246 "y.tab.c"
    break;

  case 45: /* thf_unit_formula: thf_unitary_formula  */
#line 329 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3252 "y.tab.c"
    break;

  case 46: /* thf_unit_formula: thf_unary_formula  */
#line 330 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3258 "y.tab.c"
    break;

  case 47: /* thf_unit_formula: thf_defined_infix  */
#line 331 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3264 "y.tab.c"
    break;

  case 48: /* thf_preunit_formula: thf_unitary_formula  */
#line 334 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("thf_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3270 "y.tab.c"
    break;

  case 49: /* thf_preunit_formula: thf_prefix_unary  */
#line 335 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3276 "y.tab.c"
    break;

  case 50: /* thf_unitary_formula: thf_quantified_formula  */
#line 338 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("thf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3282 "y.tab.c"
    break;

  case 51: /* thf_unitary_formula: thf_atomic_formula  */
#line 339 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3288 "y.tab.c"
    break;

  case 52: /* thf_unitary_formula: variable  */
#line 340 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("thf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3294 "y.tab.c"
    break;

  case 53: /* thf_unitary_formula: LPAREN thf_logic_formula RPAREN  */
#line 341 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("thf_unitary_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3300 "y.tab.c"
    break;

  case 54: /* thf_quantified_formula: thf_quantification thf_unit_formula  */
#line 344 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("thf_quantified_formula", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3306 "y.tab.c"
    break;

  case 55: /* thf_quantification: thf_quantifier LBRKT thf_variable_list RBRKT COLON  */
#line 347 "SyntaxBNF.y"
                                                                        {(yyval.pval) = P_BUILD("thf_quantification", (yyvsp[-4].pval), P_TOKEN("LBRKT ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("RBRKT ", (yyvsp[-1].ival)), P_TOKEN("COLON ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL);}
#line 3312 "y.tab.c"
    break;

  case 56: /* thf_variable_list: thf_typed_variable  */
#line 350 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_variable_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3318 "y.tab.c"
    break;

  case 57: /* thf_variable_list: thf_typed_variable COMMA thf_variable_list  */
#line 351 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_variable_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3324 "y.tab.c"
    break;

  case 58: /* thf_typed_variable: variable COLON thf_top_level_type  */
#line 354 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("thf_typed_variable", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3330 "y.tab.c"
    break;

  case 59: /* thf_unary_formula: thf_prefix_unary  */
#line 357 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3336 "y.tab.c"
    break;

  case 60: /* thf_unary_formula: thf_infix_unary  */
#line 358 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3342 "y.tab.c"
    break;

  case 61: /* thf_prefix_unary: thf_unary_connective thf_preunit_formula  */
#line 361 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("thf_prefix_unary", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3348 "y.tab.c"
    break;

  case 62: /* thf_infix_unary: thf_unitary_term infix_inequality thf_unitary_term  */
#line 364 "SyntaxBNF.y"
                                                                     {(yyval.pval) = P_BUILD("thf_infix_unary", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3354 "y.tab.c"
    break;

  case 63: /* thf_atomic_formula: thf_plain_atomic  */
#line 367 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3360 "y.tab.c"
    break;

  case 64: /* thf_atomic_formula: thf_defined_atomic  */
#line 368 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3366 "y.tab.c"
    break;

  case 65: /* thf_atomic_formula: thf_system_atomic  */
#line 369 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3372 "y.tab.c"
    break;

  case 66: /* thf_atomic_formula: thf_fof_function  */
#line 370 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3378 "y.tab.c"
    break;

  case 67: /* thf_plain_atomic: constant  */
#line 373 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("thf_plain_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3384 "y.tab.c"
    break;

  case 68: /* thf_plain_atomic: thf_tuple  */
#line 374 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_plain_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3390 "y.tab.c"
    break;

  case 69: /* thf_defined_atomic: defined_constant  */
#line 377 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3396 "y.tab.c"
    break;

  case 70: /* thf_defined_atomic: thf_defined_term  */
#line 378 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3402 "y.tab.c"
    break;

  case 71: /* thf_defined_atomic: LPAREN thf_conn_term RPAREN  */
#line 379 "SyntaxBNF.y"
                                                  {(yyval.pval) = P_BUILD("thf_defined_atomic", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3408 "y.tab.c"
    break;

  case 72: /* thf_defined_atomic: nhf_long_connective  */
#line 380 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3414 "y.tab.c"
    break;

  case 73: /* thf_defined_atomic: thf_let  */
#line 381 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3420 "y.tab.c"
    break;

  case 74: /* thf_defined_term: defined_term  */
#line 384 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3426 "y.tab.c"
    break;

  case 75: /* thf_defined_term: th1_defined_term  */
#line 385 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3432 "y.tab.c"
    break;

  case 76: /* thf_defined_infix: thf_unitary_term defined_infix_pred thf_unitary_term  */
#line 388 "SyntaxBNF.y"
                                                                         {(yyval.pval) = P_BUILD("thf_defined_infix", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3438 "y.tab.c"
    break;

  case 77: /* thf_system_atomic: system_constant  */
#line 391 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("thf_system_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3444 "y.tab.c"
    break;

  case 78: /* thf_let: _DLR_let LPAREN thf_let_types COMMA thf_let_defns COMMA thf_logic_formula RPAREN  */
#line 394 "SyntaxBNF.y"
                                                                                           {(yyval.pval) = P_BUILD("thf_let", P_TOKEN("_DLR_let ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 3450 "y.tab.c"
    break;

  case 79: /* thf_let_types: thf_atom_typing  */
#line 397 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_let_types", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3456 "y.tab.c"
    break;

  case 80: /* thf_let_types: LBRKT thf_atom_typing_list RBRKT  */
#line 398 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("thf_let_types", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3462 "y.tab.c"
    break;

  case 81: /* thf_atom_typing_list: thf_atom_typing  */
#line 401 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_atom_typing_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3468 "y.tab.c"
    break;

  case 82: /* thf_atom_typing_list: thf_atom_typing COMMA thf_atom_typing_list  */
#line 402 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_atom_typing_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3474 "y.tab.c"
    break;

  case 83: /* thf_let_defns: thf_let_defn  */
#line 405 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("thf_let_defns", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3480 "y.tab.c"
    break;

  case 84: /* thf_let_defns: LBRKT thf_let_defn_list RBRKT  */
#line 406 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("thf_let_defns", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3486 "y.tab.c"
    break;

  case 85: /* thf_let_defn: thf_logic_formula assignment thf_logic_formula  */
#line 409 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_let_defn", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3492 "y.tab.c"
    break;

  case 86: /* thf_let_defn_list: thf_let_defn  */
#line 412 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("thf_let_defn_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3498 "y.tab.c"
    break;

  case 87: /* thf_let_defn_list: thf_let_defn COMMA thf_let_defn_list  */
#line 413 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_let_defn_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3504 "y.tab.c"
    break;

  case 88: /* thf_unitary_term: thf_atomic_formula  */
#line 416 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3510 "y.tab.c"
    break;

  case 89: /* thf_unitary_term: variable  */
#line 417 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("thf_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3516 "y.tab.c"
    break;

  case 90: /* thf_unitary_term: LPAREN thf_logic_formula RPAREN  */
#line 418 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("thf_unitary_term", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3522 "y.tab.c"
    break;

  case 91: /* thf_conn_term: nonassoc_connective  */
#line 421 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3528 "y.tab.c"
    break;

  case 92: /* thf_conn_term: assoc_connective  */
#line 422 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3534 "y.tab.c"
    break;

  case 93: /* thf_conn_term: infix_equality  */
#line 423 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3540 "y.tab.c"
    break;

  case 94: /* thf_conn_term: infix_inequality  */
#line 424 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3546 "y.tab.c"
    break;

  case 95: /* thf_conn_term: thf_unary_connective  */
#line 425 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3552 "y.tab.c"
    break;

  case 96: /* thf_tuple: LBRKT RBRKT  */
#line 428 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("thf_tuple", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3558 "y.tab.c"
    break;

  case 97: /* thf_tuple: LBRKT thf_formula_list RBRKT  */
#line 429 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("thf_tuple", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3564 "y.tab.c"
    break;

  case 98: /* thf_fof_function: functor LPAREN thf_arguments RPAREN  */
#line 432 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("thf_fof_function", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3570 "y.tab.c"
    break;

  case 99: /* thf_fof_function: defined_functor LPAREN thf_arguments RPAREN  */
#line 433 "SyntaxBNF.y"
                                                                  {(yyval.pval) = P_BUILD("thf_fof_function", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3576 "y.tab.c"
    break;

  case 100: /* thf_fof_function: system_functor LPAREN thf_arguments RPAREN  */
#line 434 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_fof_function", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3582 "y.tab.c"
    break;

  case 101: /* thf_arguments: thf_formula_list  */
#line 437 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("thf_arguments", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3588 "y.tab.c"
    break;

  case 102: /* thf_formula_list: thf_logic_formula  */
#line 440 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_formula_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3594 "y.tab.c"
    break;

  case 103: /* thf_formula_list: thf_logic_formula COMMA thf_formula_list  */
#line 441 "SyntaxBNF.y"
                                                               {(yyval.pval) = P_BUILD("thf_formula_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3600 "y.tab.c"
    break;

  case 104: /* thf_atom_typing: untyped_atom COLON thf_top_level_type  */
#line 444 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("thf_atom_typing", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3606 "y.tab.c"
    break;

  case 105: /* thf_atom_typing: LPAREN thf_atom_typing RPAREN  */
#line 445 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("thf_atom_typing", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3612 "y.tab.c"
    break;

  case 106: /* thf_top_level_type: thf_unitary_type  */
#line 448 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3618 "y.tab.c"
    break;

  case 107: /* thf_top_level_type: thf_mapping_type  */
#line 449 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3624 "y.tab.c"
    break;

  case 108: /* thf_top_level_type: thf_apply_type  */
#line 450 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3630 "y.tab.c"
    break;

  case 109: /* thf_unitary_type: thf_unitary_formula  */
#line 453 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_unitary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3636 "y.tab.c"
    break;

  case 110: /* thf_apply_type: thf_apply_formula  */
#line 456 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("thf_apply_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3642 "y.tab.c"
    break;

  case 111: /* thf_binary_type: thf_mapping_type  */
#line 459 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("thf_binary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3648 "y.tab.c"
    break;

  case 112: /* thf_binary_type: thf_xprod_type  */
#line 460 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_binary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3654 "y.tab.c"
    break;

  case 113: /* thf_binary_type: thf_union_type  */
#line 461 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_binary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3660 "y.tab.c"
    break;

  case 114: /* thf_mapping_type: thf_unitary_type arrow thf_unitary_type  */
#line 464 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_mapping_type", (yyvsp[-2].pval), P_TOKEN("arrow ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3666 "y.tab.c"
    break;

  case 115: /* thf_mapping_type: thf_unitary_type arrow thf_mapping_type  */
#line 465 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_mapping_type", (yyvsp[-2].pval), P_TOKEN("arrow ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3672 "y.tab.c"
    break;

  case 116: /* thf_xprod_type: thf_unitary_type STAR thf_unitary_type  */
#line 468 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("thf_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3678 "y.tab.c"
    break;

  case 117: /* thf_xprod_type: thf_xprod_type STAR thf_unitary_type  */
#line 469 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3684 "y.tab.c"
    break;

  case 118: /* thf_union_type: thf_unitary_type plus thf_unitary_type  */
#line 472 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("thf_union_type", (yyvsp[-2].pval), P_TOKEN("plus ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3690 "y.tab.c"
    break;

  case 119: /* thf_union_type: thf_union_type plus thf_unitary_type  */
#line 473 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_union_type", (yyvsp[-2].pval), P_TOKEN("plus ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3696 "y.tab.c"
    break;

  case 120: /* thf_subtype: untyped_atom subtype_sign atom  */
#line 476 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("thf_subtype", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3702 "y.tab.c"
    break;

  case 121: /* thf_definition: thf_atomic_formula identical thf_logic_formula  */
#line 479 "SyntaxBNF.y"
                                                                {(yyval.pval) = P_BUILD("thf_definition", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3708 "y.tab.c"
    break;

  case 122: /* thf_sequent: thf_tuple gentzen_arrow thf_tuple  */
#line 482 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("thf_sequent", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3714 "y.tab.c"
    break;

  case 123: /* tff_formula: tff_logic_formula  */
#line 485 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3720 "y.tab.c"
    break;

  case 124: /* tff_formula: tff_atom_typing  */
#line 486 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3726 "y.tab.c"
    break;

  case 125: /* tff_formula: tff_subtype  */
#line 487 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tff_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3732 "y.tab.c"
    break;

  case 126: /* tff_logic_formula: tff_unitary_formula  */
#line 490 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3738 "y.tab.c"
    break;

  case 127: /* tff_logic_formula: tff_unary_formula  */
#line 491 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3744 "y.tab.c"
    break;

  case 128: /* tff_logic_formula: tff_binary_formula  */
#line 492 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3750 "y.tab.c"
    break;

  case 129: /* tff_logic_formula: tff_defined_infix  */
#line 493 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3756 "y.tab.c"
    break;

  case 130: /* tff_logic_formula: txf_definition  */
#line 494 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3762 "y.tab.c"
    break;

  case 131: /* tff_logic_formula: txf_sequent  */
#line 495 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3768 "y.tab.c"
    break;

  case 132: /* tff_binary_formula: tff_binary_nonassoc  */
#line 498 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3774 "y.tab.c"
    break;

  case 133: /* tff_binary_formula: tff_binary_assoc  */
#line 499 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3780 "y.tab.c"
    break;

  case 134: /* tff_binary_nonassoc: tff_unit_formula nonassoc_connective tff_unit_formula  */
#line 502 "SyntaxBNF.y"
                                                                            {(yyval.pval) = P_BUILD("tff_binary_nonassoc", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3786 "y.tab.c"
    break;

  case 135: /* tff_binary_assoc: tff_or_formula  */
#line 505 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tff_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3792 "y.tab.c"
    break;

  case 136: /* tff_binary_assoc: tff_and_formula  */
#line 506 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3798 "y.tab.c"
    break;

  case 137: /* tff_or_formula: tff_unit_formula VLINE tff_unit_formula  */
#line 509 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("tff_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3804 "y.tab.c"
    break;

  case 138: /* tff_or_formula: tff_or_formula VLINE tff_unit_formula  */
#line 510 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("tff_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3810 "y.tab.c"
    break;

  case 139: /* tff_and_formula: tff_unit_formula AMPERSAND tff_unit_formula  */
#line 513 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("tff_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3816 "y.tab.c"
    break;

  case 140: /* tff_and_formula: tff_and_formula AMPERSAND tff_unit_formula  */
#line 514 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("tff_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3822 "y.tab.c"
    break;

  case 141: /* tff_unit_formula: tff_unitary_formula  */
#line 517 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3828 "y.tab.c"
    break;

  case 142: /* tff_unit_formula: tff_unary_formula  */
#line 518 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3834 "y.tab.c"
    break;

  case 143: /* tff_unit_formula: tff_defined_infix  */
#line 519 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3840 "y.tab.c"
    break;

  case 144: /* tff_preunit_formula: tff_unitary_formula  */
#line 522 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3846 "y.tab.c"
    break;

  case 145: /* tff_preunit_formula: tff_prefix_unary  */
#line 523 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3852 "y.tab.c"
    break;

  case 146: /* tff_unitary_formula: tff_quantified_formula  */
#line 526 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("tff_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3858 "y.tab.c"
    break;

  case 147: /* tff_unitary_formula: tff_atomic_formula  */
#line 527 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3864 "y.tab.c"
    break;

  case 148: /* tff_unitary_formula: txf_unitary_formula  */
#line 528 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3870 "y.tab.c"
    break;

  case 149: /* tff_unitary_formula: LPAREN tff_logic_formula RPAREN  */
#line 529 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("tff_unitary_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3876 "y.tab.c"
    break;

  case 150: /* txf_unitary_formula: variable  */
#line 532 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("txf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3882 "y.tab.c"
    break;

  case 151: /* tff_quantified_formula: tff_quantifier LBRKT tff_variable_list RBRKT COLON tff_unit_formula  */
#line 535 "SyntaxBNF.y"
                                                                                             {(yyval.pval) = P_BUILD("tff_quantified_formula", (yyvsp[-5].pval), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 3888 "y.tab.c"
    break;

  case 152: /* tff_variable_list: tff_variable  */
#line 538 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("tff_variable_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3894 "y.tab.c"
    break;

  case 153: /* tff_variable_list: tff_variable COMMA tff_variable_list  */
#line 539 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("tff_variable_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3900 "y.tab.c"
    break;

  case 154: /* tff_variable: tff_typed_variable  */
#line 542 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tff_variable", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3906 "y.tab.c"
    break;

  case 155: /* tff_variable: variable  */
#line 543 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_variable", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3912 "y.tab.c"
    break;

  case 156: /* tff_typed_variable: variable COLON tff_atomic_type  */
#line 546 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("tff_typed_variable", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3918 "y.tab.c"
    break;

  case 157: /* tff_unary_formula: tff_prefix_unary  */
#line 549 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3924 "y.tab.c"
    break;

  case 158: /* tff_unary_formula: tff_infix_unary  */
#line 550 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3930 "y.tab.c"
    break;

  case 159: /* tff_prefix_unary: tff_unary_connective tff_preunit_formula  */
#line 553 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("tff_prefix_unary", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3936 "y.tab.c"
    break;

  case 160: /* tff_infix_unary: tff_unitary_term infix_inequality tff_unitary_term  */
#line 556 "SyntaxBNF.y"
                                                                     {(yyval.pval) = P_BUILD("tff_infix_unary", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3942 "y.tab.c"
    break;

  case 161: /* tff_atomic_formula: tff_plain_atomic  */
#line 559 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3948 "y.tab.c"
    break;

  case 162: /* tff_atomic_formula: tff_defined_atomic  */
#line 560 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3954 "y.tab.c"
    break;

  case 163: /* tff_atomic_formula: tff_system_atomic  */
#line 561 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3960 "y.tab.c"
    break;

  case 164: /* tff_plain_atomic: constant  */
#line 564 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("tff_plain_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3966 "y.tab.c"
    break;

  case 165: /* tff_plain_atomic: functor LPAREN tff_arguments RPAREN  */
#line 565 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("tff_plain_atomic", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3972 "y.tab.c"
    break;

  case 166: /* tff_defined_atomic: tff_defined_plain  */
#line 568 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3978 "y.tab.c"
    break;

  case 167: /* tff_defined_plain: defined_constant  */
#line 571 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3984 "y.tab.c"
    break;

  case 168: /* tff_defined_plain: defined_functor LPAREN tff_arguments RPAREN  */
#line 572 "SyntaxBNF.y"
                                                                  {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3990 "y.tab.c"
    break;

  case 169: /* tff_defined_plain: nxf_atom  */
#line 573 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3996 "y.tab.c"
    break;

  case 170: /* tff_defined_plain: txf_let  */
#line 574 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4002 "y.tab.c"
    break;

  case 171: /* tff_defined_infix: tff_unitary_term defined_infix_pred tff_unitary_term  */
#line 577 "SyntaxBNF.y"
                                                                         {(yyval.pval) = P_BUILD("tff_defined_infix", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4008 "y.tab.c"
    break;

  case 172: /* tff_system_atomic: system_constant  */
#line 580 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("tff_system_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4014 "y.tab.c"
    break;

  case 173: /* tff_system_atomic: system_functor LPAREN tff_arguments RPAREN  */
#line 581 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("tff_system_atomic", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4020 "y.tab.c"
    break;

  case 174: /* txf_let: _DLR_let LPAREN txf_let_types COMMA txf_let_defns COMMA tff_term RPAREN  */
#line 584 "SyntaxBNF.y"
                                                                                  {(yyval.pval) = P_BUILD("txf_let", P_TOKEN("_DLR_let ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 4026 "y.tab.c"
    break;

  case 175: /* txf_let_types: tff_atom_typing  */
#line 587 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("txf_let_types", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4032 "y.tab.c"
    break;

  case 176: /* txf_let_types: LBRKT tff_atom_typing_list RBRKT  */
#line 588 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("txf_let_types", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4038 "y.tab.c"
    break;

  case 177: /* tff_atom_typing_list: tff_atom_typing  */
#line 591 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_atom_typing_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4044 "y.tab.c"
    break;

  case 178: /* tff_atom_typing_list: tff_atom_typing COMMA tff_atom_typing_list  */
#line 592 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("tff_atom_typing_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4050 "y.tab.c"
    break;

  case 179: /* txf_let_defns: txf_let_defn  */
#line 595 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("txf_let_defns", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4056 "y.tab.c"
    break;

  case 180: /* txf_let_defns: LBRKT txf_let_defn_list RBRKT  */
#line 596 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("txf_let_defns", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4062 "y.tab.c"
    break;

  case 181: /* txf_let_defn: txf_let_LHS assignment tff_term  */
#line 599 "SyntaxBNF.y"
                                               {(yyval.pval) = P_BUILD("txf_let_defn", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4068 "y.tab.c"
    break;

  case 182: /* txf_let_LHS: tff_plain_atomic  */
#line 602 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("txf_let_LHS", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4074 "y.tab.c"
    break;

  case 183: /* txf_let_LHS: txf_tuple  */
#line 603 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("txf_let_LHS", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4080 "y.tab.c"
    break;

  case 184: /* txf_let_defn_list: txf_let_defn  */
#line 606 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("txf_let_defn_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4086 "y.tab.c"
    break;

  case 185: /* txf_let_defn_list: txf_let_defn COMMA txf_let_defn_list  */
#line 607 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("txf_let_defn_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4092 "y.tab.c"
    break;

  case 186: /* nxf_atom: nxf_long_connective AT_SIGN LPAREN tff_arguments RPAREN  */
#line 610 "SyntaxBNF.y"
                                                                   {(yyval.pval) = P_BUILD("nxf_atom", (yyvsp[-4].pval), P_TOKEN("AT_SIGN ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL);}
#line 4098 "y.tab.c"
    break;

  case 187: /* tff_term: tff_logic_formula  */
#line 613 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("tff_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4104 "y.tab.c"
    break;

  case 188: /* tff_term: defined_term  */
#line 614 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4110 "y.tab.c"
    break;

  case 189: /* tff_term: txf_tuple  */
#line 615 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4116 "y.tab.c"
    break;

  case 190: /* tff_unitary_term: tff_atomic_formula  */
#line 618 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4122 "y.tab.c"
    break;

  case 191: /* tff_unitary_term: defined_term  */
#line 619 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4128 "y.tab.c"
    break;

  case 192: /* tff_unitary_term: txf_tuple  */
#line 620 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4134 "y.tab.c"
    break;

  case 193: /* tff_unitary_term: variable  */
#line 621 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4140 "y.tab.c"
    break;

  case 194: /* tff_unitary_term: LPAREN tff_logic_formula RPAREN  */
#line 622 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("tff_unitary_term", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4146 "y.tab.c"
    break;

  case 195: /* txf_tuple: LBRKT RBRKT  */
#line 625 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("txf_tuple", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4152 "y.tab.c"
    break;

  case 196: /* txf_tuple: LBRKT tff_arguments RBRKT  */
#line 626 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("txf_tuple", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4158 "y.tab.c"
    break;

  case 197: /* tff_arguments: tff_term  */
#line 629 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_arguments", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4164 "y.tab.c"
    break;

  case 198: /* tff_arguments: tff_term COMMA tff_arguments  */
#line 630 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("tff_arguments", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4170 "y.tab.c"
    break;

  case 199: /* tff_atom_typing: untyped_atom COLON tff_top_level_type  */
#line 633 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("tff_atom_typing", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4176 "y.tab.c"
    break;

  case 200: /* tff_atom_typing: LPAREN tff_atom_typing RPAREN  */
#line 634 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("tff_atom_typing", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4182 "y.tab.c"
    break;

  case 201: /* tff_top_level_type: tff_atomic_type  */
#line 637 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4188 "y.tab.c"
    break;

  case 202: /* tff_top_level_type: tff_non_atomic_type  */
#line 638 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4194 "y.tab.c"
    break;

  case 203: /* tff_non_atomic_type: tff_mapping_type  */
#line 641 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_non_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4200 "y.tab.c"
    break;

  case 204: /* tff_non_atomic_type: tf1_quantified_type  */
#line 642 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_non_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4206 "y.tab.c"
    break;

  case 205: /* tff_non_atomic_type: LPAREN tff_non_atomic_type RPAREN  */
#line 643 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("tff_non_atomic_type", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4212 "y.tab.c"
    break;

  case 206: /* tf1_quantified_type: EXCLAMATION_GREATER LBRKT tff_variable_list RBRKT COLON tff_monotype  */
#line 646 "SyntaxBNF.y"
                                                                                           {(yyval.pval) = P_BUILD("tf1_quantified_type", P_TOKEN("EXCLAMATION_GREATER ", (yyvsp[-5].ival)), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 4218 "y.tab.c"
    break;

  case 207: /* tff_monotype: tff_atomic_type  */
#line 649 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_monotype", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4224 "y.tab.c"
    break;

  case 208: /* tff_monotype: LPAREN tff_mapping_type RPAREN  */
#line 650 "SyntaxBNF.y"
                                                     {(yyval.pval) = P_BUILD("tff_monotype", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4230 "y.tab.c"
    break;

  case 209: /* tff_monotype: tf1_quantified_type  */
#line 651 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_monotype", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4236 "y.tab.c"
    break;

  case 210: /* tff_unitary_type: tff_atomic_type  */
#line 654 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_unitary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4242 "y.tab.c"
    break;

  case 211: /* tff_unitary_type: LPAREN tff_xprod_type RPAREN  */
#line 655 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("tff_unitary_type", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4248 "y.tab.c"
    break;

  case 212: /* tff_atomic_type: type_constant  */
#line 658 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4254 "y.tab.c"
    break;

  case 213: /* tff_atomic_type: defined_type  */
#line 659 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4260 "y.tab.c"
    break;

  case 214: /* tff_atomic_type: variable  */
#line 660 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4266 "y.tab.c"
    break;

  case 215: /* tff_atomic_type: type_functor LPAREN tff_type_arguments RPAREN  */
#line 661 "SyntaxBNF.y"
                                                                    {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4272 "y.tab.c"
    break;

  case 216: /* tff_atomic_type: LPAREN tff_atomic_type RPAREN  */
#line 662 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("tff_atomic_type", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4278 "y.tab.c"
    break;

  case 217: /* tff_atomic_type: txf_tuple_type  */
#line 663 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4284 "y.tab.c"
    break;

  case 218: /* tff_type_arguments: tff_atomic_type  */
#line 666 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_type_arguments", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4290 "y.tab.c"
    break;

  case 219: /* tff_type_arguments: tff_atomic_type COMMA tff_type_arguments  */
#line 667 "SyntaxBNF.y"
                                                               {(yyval.pval) = P_BUILD("tff_type_arguments", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4296 "y.tab.c"
    break;

  case 220: /* tff_mapping_type: tff_unitary_type arrow tff_atomic_type  */
#line 670 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("tff_mapping_type", (yyvsp[-2].pval), P_TOKEN("arrow ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4302 "y.tab.c"
    break;

  case 221: /* tff_xprod_type: tff_unitary_type STAR tff_atomic_type  */
#line 673 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("tff_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4308 "y.tab.c"
    break;

  case 222: /* tff_xprod_type: tff_xprod_type STAR tff_atomic_type  */
#line 674 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("tff_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4314 "y.tab.c"
    break;

  case 223: /* txf_tuple_type: LBRKT tff_type_list RBRKT  */
#line 677 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("txf_tuple_type", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4320 "y.tab.c"
    break;

  case 224: /* tff_type_list: tff_top_level_type  */
#line 680 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_type_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4326 "y.tab.c"
    break;

  case 225: /* tff_type_list: tff_top_level_type COMMA tff_type_list  */
#line 681 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("tff_type_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4332 "y.tab.c"
    break;

  case 226: /* tff_subtype: untyped_atom subtype_sign atom  */
#line 684 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("tff_subtype", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4338 "y.tab.c"
    break;

  case 227: /* txf_definition: tff_atomic_formula identical tff_term  */
#line 687 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("txf_definition", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4344 "y.tab.c"
    break;

  case 228: /* txf_sequent: txf_tuple gentzen_arrow txf_tuple  */
#line 690 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("txf_sequent", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4350 "y.tab.c"
    break;

  case 229: /* nhf_long_connective: LBRACE ntf_connective_name RBRACE  */
#line 693 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("nhf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4356 "y.tab.c"
    break;

  case 230: /* nhf_long_connective: LBRACE ntf_connective_name LPAREN nhf_parameter_list RPAREN RBRACE  */
#line 694 "SyntaxBNF.y"
                                                                                         {(yyval.pval) = P_BUILD("nhf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-5].ival)), (yyvsp[-4].pval), P_TOKEN("LPAREN ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL);}
#line 4362 "y.tab.c"
    break;

  case 231: /* nhf_parameter_list: nhf_parameter  */
#line 697 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("nhf_parameter_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4368 "y.tab.c"
    break;

  case 232: /* nhf_parameter_list: nhf_parameter COMMA nhf_parameter_list  */
#line 698 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("nhf_parameter_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4374 "y.tab.c"
    break;

  case 233: /* nhf_parameter: ntf_index  */
#line 701 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("nhf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4380 "y.tab.c"
    break;

  case 234: /* nhf_parameter: nhf_key_pair  */
#line 702 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("nhf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4386 "y.tab.c"
    break;

  case 235: /* nhf_key_pair: thf_definition  */
#line 705 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("nhf_key_pair", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4392 "y.tab.c"
    break;

  case 236: /* nxf_long_connective: LBRACE ntf_connective_name RBRACE  */
#line 708 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("nxf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4398 "y.tab.c"
    break;

  case 237: /* nxf_long_connective: LBRACE ntf_connective_name LPAREN nxf_parameter_list RPAREN RBRACE  */
#line 709 "SyntaxBNF.y"
                                                                                         {(yyval.pval) = P_BUILD("nxf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-5].ival)), (yyvsp[-4].pval), P_TOKEN("LPAREN ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL);}
#line 4404 "y.tab.c"
    break;

  case 238: /* nxf_parameter_list: nxf_parameter  */
#line 712 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("nxf_parameter_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4410 "y.tab.c"
    break;

  case 239: /* nxf_parameter_list: nxf_parameter COMMA nxf_parameter_list  */
#line 713 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("nxf_parameter_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4416 "y.tab.c"
    break;

  case 240: /* nxf_parameter: ntf_index  */
#line 716 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("nxf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4422 "y.tab.c"
    break;

  case 241: /* nxf_parameter: nxf_key_pair  */
#line 717 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("nxf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4428 "y.tab.c"
    break;

  case 242: /* nxf_key_pair: txf_definition  */
#line 720 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("nxf_key_pair", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4434 "y.tab.c"
    break;

  case 243: /* ntf_connective_name: def_or_sys_constant  */
#line 723 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("ntf_connective_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4440 "y.tab.c"
    break;

  case 244: /* ntf_index: hash tff_unitary_term  */
#line 726 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("ntf_index", P_TOKEN("hash ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4446 "y.tab.c"
    break;

  case 245: /* ntf_short_connective: LBRKT PERIOD RBRKT  */
#line 729 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4452 "y.tab.c"
    break;

  case 246: /* ntf_short_connective: less_sign PERIOD arrow  */
#line 730 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("less_sign ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("arrow ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4458 "y.tab.c"
    break;

  case 247: /* ntf_short_connective: LBRACE PERIOD RBRACE  */
#line 731 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("LBRACE ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4464 "y.tab.c"
    break;

  case 248: /* ntf_short_connective: LPAREN PERIOD RPAREN  */
#line 732 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4470 "y.tab.c"
    break;

  case 249: /* tcf_formula: tcf_logic_formula  */
#line 735 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tcf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4476 "y.tab.c"
    break;

  case 250: /* tcf_formula: tff_atom_typing  */
#line 736 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tcf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4482 "y.tab.c"
    break;

  case 251: /* tcf_logic_formula: tcf_quantified_formula  */
#line 739 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("tcf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4488 "y.tab.c"
    break;

  case 252: /* tcf_logic_formula: cnf_formula  */
#line 740 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tcf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4494 "y.tab.c"
    break;

  case 253: /* tcf_quantified_formula: EXCLAMATION LBRKT tff_variable_list RBRKT COLON tcf_logic_formula  */
#line 743 "SyntaxBNF.y"
                                                                                           {(yyval.pval) = P_BUILD("tcf_quantified_formula", P_TOKEN("EXCLAMATION ", (yyvsp[-5].ival)), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 4500 "y.tab.c"
    break;

  case 254: /* fof_formula: fof_logic_formula  */
#line 746 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("fof_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4506 "y.tab.c"
    break;

  case 255: /* fof_formula: fof_sequent  */
#line 747 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("fof_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4512 "y.tab.c"
    break;

  case 256: /* fof_logic_formula: fof_binary_formula  */
#line 750 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("fof_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4518 "y.tab.c"
    break;

  case 257: /* fof_logic_formula: fof_unary_formula  */
#line 751 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("fof_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4524 "y.tab.c"
    break;

  case 258: /* fof_logic_formula: fof_unitary_formula  */
#line 752 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("fof_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4530 "y.tab.c"
    break;

  case 259: /* fof_binary_formula: fof_binary_nonassoc  */
#line 755 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("fof_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4536 "y.tab.c"
    break;

  case 260: /* fof_binary_formula: fof_binary_assoc  */
#line 756 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("fof_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4542 "y.tab.c"
    break;

  case 261: /* fof_binary_nonassoc: fof_unit_formula nonassoc_connective fof_unit_formula  */
#line 759 "SyntaxBNF.y"
                                                                            {(yyval.pval) = P_BUILD("fof_binary_nonassoc", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4548 "y.tab.c"
    break;

  case 262: /* fof_binary_assoc: fof_or_formula  */
#line 762 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("fof_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4554 "y.tab.c"
    break;

  case 263: /* fof_binary_assoc: fof_and_formula  */
#line 763 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("fof_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4560 "y.tab.c"
    break;

  case 264: /* fof_or_formula: fof_unit_formula VLINE fof_unit_formula  */
#line 766 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("fof_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4566 "y.tab.c"
    break;

  case 265: /* fof_or_formula: fof_or_formula VLINE fof_unit_formula  */
#line 767 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("fof_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4572 "y.tab.c"
    break;

  case 266: /* fof_and_formula: fof_unit_formula AMPERSAND fof_unit_formula  */
#line 770 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("fof_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4578 "y.tab.c"
    break;

  case 267: /* fof_and_formula: fof_and_formula AMPERSAND fof_unit_formula  */
#line 771 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("fof_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4584 "y.tab.c"
    break;

  case 268: /* fof_unary_formula: unary_connective fof_unit_formula  */
#line 774 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("fof_unary_formula", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4590 "y.tab.c"
    break;

  case 269: /* fof_unary_formula: fof_infix_unary  */
#line 775 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("fof_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4596 "y.tab.c"
    break;

  case 270: /* fof_infix_unary: fof_term infix_inequality fof_term  */
#line 778 "SyntaxBNF.y"
                                                     {(yyval.pval) = P_BUILD("fof_infix_unary", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4602 "y.tab.c"
    break;

  case 271: /* fof_unit_formula: fof_unitary_formula  */
#line 781 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("fof_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4608 "y.tab.c"
    break;

  case 272: /* fof_unit_formula: fof_unary_formula  */
#line 782 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("fof_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4614 "y.tab.c"
    break;

  case 273: /* fof_unitary_formula: fof_quantified_formula  */
#line 785 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("fof_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4620 "y.tab.c"
    break;

  case 274: /* fof_unitary_formula: fof_atomic_formula  */
#line 786 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("fof_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4626 "y.tab.c"
    break;

  case 275: /* fof_unitary_formula: LPAREN fof_logic_formula RPAREN  */
#line 787 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("fof_unitary_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4632 "y.tab.c"
    break;

  case 276: /* fof_quantified_formula: fof_quantifier LBRKT fof_variable_list RBRKT COLON fof_unit_formula  */
#line 790 "SyntaxBNF.y"
                                                                                             {(yyval.pval) = P_BUILD("fof_quantified_formula", (yyvsp[-5].pval), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 4638 "y.tab.c"
    break;

  case 277: /* fof_variable_list: variable  */
#line 793 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("fof_variable_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4644 "y.tab.c"
    break;

  case 278: /* fof_variable_list: variable COMMA fof_variable_list  */
#line 794 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("fof_variable_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4650 "y.tab.c"
    break;

  case 279: /* fof_atomic_formula: fof_plain_atomic_formula  */
#line 797 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("fof_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4656 "y.tab.c"
    break;

  case 280: /* fof_atomic_formula: fof_defined_atomic_formula  */
#line 798 "SyntaxBNF.y"
                                                 {(yyval.pval) = P_BUILD("fof_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4662 "y.tab.c"
    break;

  case 281: /* fof_atomic_formula: fof_system_atomic_formula  */
#line 799 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("fof_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4668 "y.tab.c"
    break;

  case 282: /* fof_plain_atomic_formula: fof_plain_term  */
#line 802 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("fof_plain_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4674 "y.tab.c"
    break;

  case 283: /* fof_defined_atomic_formula: fof_defined_plain_formula  */
#line 805 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("fof_defined_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4680 "y.tab.c"
    break;

  case 284: /* fof_defined_atomic_formula: fof_defined_infix_formula  */
#line 806 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("fof_defined_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4686 "y.tab.c"
    break;

  case 285: /* fof_defined_plain_formula: fof_defined_plain_term  */
#line 809 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("fof_defined_plain_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4692 "y.tab.c"
    break;

  case 286: /* fof_defined_infix_formula: fof_term defined_infix_pred fof_term  */
#line 812 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("fof_defined_infix_formula", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4698 "y.tab.c"
    break;

  case 287: /* fof_system_atomic_formula: fof_system_term  */
#line 815 "SyntaxBNF.y"
                                            {(yyval.pval) = P_BUILD("fof_system_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4704 "y.tab.c"
    break;

  case 288: /* fof_plain_term: constant  */
#line 818 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("fof_plain_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4710 "y.tab.c"
    break;

  case 289: /* fof_plain_term: functor LPAREN fof_arguments RPAREN  */
#line 819 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("fof_plain_term", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4716 "y.tab.c"
    break;

  case 290: /* fof_defined_term: defined_term  */
#line 822 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("fof_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4722 "y.tab.c"
    break;

  case 291: /* fof_defined_term: fof_defined_atomic_term  */
#line 823 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("fof_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4728 "y.tab.c"
    break;

  case 292: /* fof_defined_atomic_term: fof_defined_plain_term  */
#line 826 "SyntaxBNF.y"
                                                 {(yyval.pval) = P_BUILD("fof_defined_atomic_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4734 "y.tab.c"
    break;

  case 293: /* fof_defined_plain_term: defined_constant  */
#line 829 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("fof_defined_plain_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4740 "y.tab.c"
    break;

  case 294: /* fof_defined_plain_term: defined_functor LPAREN fof_arguments RPAREN  */
#line 830 "SyntaxBNF.y"
                                                                  {(yyval.pval) = P_BUILD("fof_defined_plain_term", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4746 "y.tab.c"
    break;

  case 295: /* fof_system_term: system_constant  */
#line 833 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("fof_system_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4752 "y.tab.c"
    break;

  case 296: /* fof_system_term: system_functor LPAREN fof_arguments RPAREN  */
#line 834 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("fof_system_term", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4758 "y.tab.c"
    break;

  case 297: /* fof_arguments: fof_term  */
#line 837 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("fof_arguments", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4764 "y.tab.c"
    break;

  case 298: /* fof_arguments: fof_term COMMA fof_arguments  */
#line 838 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("fof_arguments", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4770 "y.tab.c"
    break;

  case 299: /* fof_term: fof_function_term  */
#line 841 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("fof_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4776 "y.tab.c"
    break;

  case 300: /* fof_term: variable  */
#line 842 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("fof_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4782 "y.tab.c"
    break;

  case 301: /* fof_function_term: fof_plain_term  */
#line 845 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("fof_function_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4788 "y.tab.c"
    break;

  case 302: /* fof_function_term: fof_defined_term  */
#line 846 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("fof_function_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4794 "y.tab.c"
    break;

  case 303: /* fof_function_term: fof_system_term  */
#line 847 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("fof_function_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4800 "y.tab.c"
    break;

  case 304: /* fof_sequent: fof_formula_tuple gentzen_arrow fof_formula_tuple  */
#line 850 "SyntaxBNF.y"
                                                                {(yyval.pval) = P_BUILD("fof_sequent", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4806 "y.tab.c"
    break;

  case 305: /* fof_sequent: LPAREN fof_sequent RPAREN  */
#line 851 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("fof_sequent", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4812 "y.tab.c"
    break;

  case 306: /* fof_formula_tuple: LBRKT RBRKT  */
#line 854 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("fof_formula_tuple", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4818 "y.tab.c"
    break;

  case 307: /* fof_formula_tuple: LBRKT fof_formula_tuple_list RBRKT  */
#line 855 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("fof_formula_tuple", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4824 "y.tab.c"
    break;

  case 308: /* fof_formula_tuple_list: fof_logic_formula  */
#line 858 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("fof_formula_tuple_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4830 "y.tab.c"
    break;

  case 309: /* fof_formula_tuple_list: fof_logic_formula COMMA fof_formula_tuple_list  */
#line 859 "SyntaxBNF.y"
                                                                     {(yyval.pval) = P_BUILD("fof_formula_tuple_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4836 "y.tab.c"
    break;

  case 310: /* cnf_formula: cnf_disjunction  */
#line 862 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("cnf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4842 "y.tab.c"
    break;

  case 311: /* cnf_formula: LPAREN cnf_formula RPAREN  */
#line 863 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("cnf_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4848 "y.tab.c"
    break;

  case 312: /* cnf_disjunction: cnf_literal  */
#line 866 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("cnf_disjunction", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4854 "y.tab.c"
    break;

  case 313: /* cnf_disjunction: cnf_disjunction VLINE cnf_literal  */
#line 867 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("cnf_disjunction", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4860 "y.tab.c"
    break;

  case 314: /* cnf_literal: fof_atomic_formula  */
#line 870 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("cnf_literal", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4866 "y.tab.c"
    break;

  case 315: /* cnf_literal: TILDE fof_atomic_formula  */
#line 871 "SyntaxBNF.y"
                                               {(yyval.pval) = P_BUILD("cnf_literal", P_TOKEN("TILDE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4872 "y.tab.c"
    break;

  case 316: /* cnf_literal: TILDE LPAREN fof_atomic_formula RPAREN  */
#line 872 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("cnf_literal", P_TOKEN("TILDE ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4878 "y.tab.c"
    break;

  case 317: /* cnf_literal: fof_infix_unary  */
#line 873 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("cnf_literal", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4884 "y.tab.c"
    break;

  case 318: /* thf_quantifier: fof_quantifier  */
#line 876 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4890 "y.tab.c"
    break;

  case 319: /* thf_quantifier: th0_quantifier  */
#line 877 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4896 "y.tab.c"
    break;

  case 320: /* thf_quantifier: th1_quantifier  */
#line 878 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4902 "y.tab.c"
    break;

  case 321: /* thf_unary_connective: unary_connective  */
#line 881 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4908 "y.tab.c"
    break;

  case 322: /* thf_unary_connective: ntf_short_connective  */
#line 882 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("thf_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4914 "y.tab.c"
    break;

  case 323: /* th1_quantifier: EXCLAMATION_GREATER  */
#line 885 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("th1_quantifier", P_TOKEN("EXCLAMATION_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4920 "y.tab.c"
    break;

  case 324: /* th1_quantifier: QUESTION_STAR  */
#line 886 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("th1_quantifier", P_TOKEN("QUESTION_STAR ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4926 "y.tab.c"
    break;

  case 325: /* th0_quantifier: CARET  */
#line 889 "SyntaxBNF.y"
                       {(yyval.pval) = P_BUILD("th0_quantifier", P_TOKEN("CARET ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4932 "y.tab.c"
    break;

  case 326: /* th0_quantifier: AT_SIGN_PLUS  */
#line 890 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("th0_quantifier", P_TOKEN("AT_SIGN_PLUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4938 "y.tab.c"
    break;

  case 327: /* th0_quantifier: AT_SIGN_MINUS  */
#line 891 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("th0_quantifier", P_TOKEN("AT_SIGN_MINUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4944 "y.tab.c"
    break;

  case 328: /* subtype_sign: LESS_LESS  */
#line 894 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("subtype_sign", P_TOKEN("LESS_LESS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4950 "y.tab.c"
    break;

  case 329: /* tff_unary_connective: unary_connective  */
#line 897 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4956 "y.tab.c"
    break;

  case 330: /* tff_unary_connective: ntf_short_connective  */
#line 898 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("tff_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4962 "y.tab.c"
    break;

  case 331: /* tff_quantifier: fof_quantifier  */
#line 901 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4968 "y.tab.c"
    break;

  case 332: /* fof_quantifier: EXCLAMATION  */
#line 904 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("fof_quantifier", P_TOKEN("EXCLAMATION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4974 "y.tab.c"
    break;

  case 333: /* fof_quantifier: QUESTION  */
#line 905 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("fof_quantifier", P_TOKEN("QUESTION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4980 "y.tab.c"
    break;

  case 334: /* fof_quantifier: hash  */
#line 906 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("fof_quantifier", P_TOKEN("hash ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4986 "y.tab.c"
    break;

  case 335: /* nonassoc_connective: LESS_EQUALS_GREATER  */
#line 909 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("LESS_EQUALS_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4992 "y.tab.c"
    break;

  case 336: /* nonassoc_connective: EQUALS_GREATER  */
#line 910 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("EQUALS_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4998 "y.tab.c"
    break;

  case 337: /* nonassoc_connective: LESS_EQUALS  */
#line 911 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("LESS_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5004 "y.tab.c"
    break;

  case 338: /* nonassoc_connective: LESS_TILDE_GREATER  */
#line 912 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("LESS_TILDE_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5010 "y.tab.c"
    break;

  case 339: /* nonassoc_connective: TILDE_VLINE  */
#line 913 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("TILDE_VLINE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5016 "y.tab.c"
    break;

  case 340: /* nonassoc_connective: TILDE_AMPERSAND  */
#line 914 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("TILDE_AMPERSAND ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5022 "y.tab.c"
    break;

  case 341: /* assoc_connective: VLINE  */
#line 917 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("assoc_connective", P_TOKEN("VLINE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5028 "y.tab.c"
    break;

  case 342: /* assoc_connective: AMPERSAND  */
#line 918 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("assoc_connective", P_TOKEN("AMPERSAND ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5034 "y.tab.c"
    break;

  case 343: /* unary_connective: TILDE  */
#line 921 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("unary_connective", P_TOKEN("TILDE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5040 "y.tab.c"
    break;

  case 344: /* gentzen_arrow: MINUS_MINUS_GREATER  */
#line 924 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("gentzen_arrow", P_TOKEN("MINUS_MINUS_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5046 "y.tab.c"
    break;

  case 345: /* assignment: COLON_EQUALS  */
#line 927 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("assignment", P_TOKEN("COLON_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5052 "y.tab.c"
    break;

  case 346: /* identical: EQUALS_EQUALS  */
#line 930 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("identical", P_TOKEN("EQUALS_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5058 "y.tab.c"
    break;

  case 347: /* type_constant: type_functor  */
#line 933 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("type_constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5064 "y.tab.c"
    break;

  case 348: /* type_functor: atomic_word  */
#line 936 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("type_functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5070 "y.tab.c"
    break;

  case 349: /* defined_type: atomic_defined_word  */
#line 939 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("defined_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5076 "y.tab.c"
    break;

  case 350: /* atom: untyped_atom  */
#line 942 "SyntaxBNF.y"
                    {(yyval.pval) = P_BUILD("atom", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5082 "y.tab.c"
    break;

  case 351: /* atom: defined_constant  */
#line 943 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("atom", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5088 "y.tab.c"
    break;

  case 352: /* untyped_atom: constant  */
#line 946 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("untyped_atom", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5094 "y.tab.c"
    break;

  case 353: /* untyped_atom: system_constant  */
#line 947 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("untyped_atom", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5100 "y.tab.c"
    break;

  case 354: /* defined_infix_pred: infix_equality  */
#line 950 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("defined_infix_pred", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5106 "y.tab.c"
    break;

  case 355: /* infix_equality: EQUALS  */
#line 953 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("infix_equality", P_TOKEN("EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5112 "y.tab.c"
    break;

  case 356: /* infix_inequality: EXCLAMATION_EQUALS  */
#line 956 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("infix_inequality", P_TOKEN("EXCLAMATION_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5118 "y.tab.c"
    break;

  case 357: /* constant: functor  */
#line 959 "SyntaxBNF.y"
                   {(yyval.pval) = P_BUILD("constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5124 "y.tab.c"
    break;

  case 358: /* functor: atomic_word  */
#line 962 "SyntaxBNF.y"
                      {(yyval.pval) = P_BUILD("functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5130 "y.tab.c"
    break;

  case 359: /* defined_constant: defined_functor  */
#line 965 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("defined_constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5136 "y.tab.c"
    break;

  case 360: /* defined_functor: atomic_defined_word  */
#line 968 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("defined_functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5142 "y.tab.c"
    break;

  case 361: /* system_constant: system_functor  */
#line 971 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("system_constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5148 "y.tab.c"
    break;

  case 362: /* system_functor: atomic_system_word  */
#line 974 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("system_functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5154 "y.tab.c"
    break;

  case 363: /* def_or_sys_constant: defined_constant  */
#line 977 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("def_or_sys_constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5160 "y.tab.c"
    break;

  case 364: /* def_or_sys_constant: system_constant  */
#line 978 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("def_or_sys_constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5166 "y.tab.c"
    break;

  case 365: /* th1_defined_term: EXCLAMATION_EXCLAMATION  */
#line 981 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("EXCLAMATION_EXCLAMATION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5172 "y.tab.c"
    break;

  case 366: /* th1_defined_term: QUESTION_QUESTION  */
#line 982 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("QUESTION_QUESTION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5178 "y.tab.c"
    break;

  case 367: /* th1_defined_term: AT_AT_SIGN_PLUS  */
#line 983 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("AT_AT_SIGN_PLUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5184 "y.tab.c"
    break;

  case 368: /* th1_defined_term: AT_AT_SIGN_MINUS  */
#line 984 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("AT_AT_SIGN_MINUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5190 "y.tab.c"
    break;

  case 369: /* th1_defined_term: AT_SIGN_EQUALS  */
#line 985 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("AT_SIGN_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5196 "y.tab.c"
    break;

  case 370: /* defined_term: number  */
#line 988 "SyntaxBNF.y"
                      {(yyval.pval) = P_BUILD("defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5202 "y.tab.c"
    break;

  case 371: /* defined_term: distinct_object  */
#line 989 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("defined_term", P_TOKEN("distinct_object ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5208 "y.tab.c"
    break;

  case 372: /* variable: upper_word  */
#line 992 "SyntaxBNF.y"
                      {(yyval.pval) = P_BUILD("variable", P_TOKEN("upper_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5214 "y.tab.c"
    break;

  case 373: /* source: dag_source  */
#line 995 "SyntaxBNF.y"
                    {(yyval.pval) = P_BUILD("source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5220 "y.tab.c"
    break;

  case 374: /* source: internal_source  */
#line 996 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5226 "y.tab.c"
    break;

  case 375: /* source: external_source  */
#line 997 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5232 "y.tab.c"
    break;

  case 376: /* source: _LIT_unknown  */
#line 998 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("source", P_TOKEN("_LIT_unknown ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5238 "y.tab.c"
    break;

  case 377: /* source: LBRKT sources RBRKT  */
#line 999 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("source", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5244 "y.tab.c"
    break;

  case 378: /* sources: source  */
#line 1002 "SyntaxBNF.y"
                 {(yyval.pval) = P_BUILD("sources", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5250 "y.tab.c"
    break;

  case 379: /* sources: source COMMA sources  */
#line 1003 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("sources", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5256 "y.tab.c"
    break;

  case 380: /* dag_source: name  */
#line 1006 "SyntaxBNF.y"
                  {(yyval.pval) = P_BUILD("dag_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5262 "y.tab.c"
    break;

  case 381: /* dag_source: inference_record  */
#line 1007 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("dag_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5268 "y.tab.c"
    break;

  case 382: /* inference_record: _LIT_inference LPAREN inference_rule COMMA useful_info COMMA parents RPAREN  */
#line 1010 "SyntaxBNF.y"
                                                                                               {(yyval.pval) = P_BUILD("inference_record", P_TOKEN("_LIT_inference ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 5274 "y.tab.c"
    break;

  case 383: /* inference_rule: atomic_word  */
#line 1013 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("inference_rule", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5280 "y.tab.c"
    break;

  case 384: /* internal_source: _LIT_introduced LPAREN intro_type COMMA useful_info COMMA parents RPAREN  */
#line 1016 "SyntaxBNF.y"
                                                                                           {(yyval.pval) = P_BUILD("internal_source", P_TOKEN("_LIT_introduced ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 5286 "y.tab.c"
    break;

  case 385: /* intro_type: atomic_word  */
#line 1019 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("intro_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5292 "y.tab.c"
    break;

  case 386: /* external_source: file_source  */
#line 1022 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("external_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5298 "y.tab.c"
    break;

  case 387: /* external_source: theory  */
#line 1023 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("external_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5304 "y.tab.c"
    break;

  case 388: /* external_source: creator_source  */
#line 1024 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("external_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5310 "y.tab.c"
    break;

  case 389: /* file_source: _LIT_file LPAREN file_name file_info RPAREN  */
#line 1027 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("file_source", P_TOKEN("_LIT_file ", (yyvsp[-4].ival)), P_TOKEN("LPAREN ", (yyvsp[-3].ival)), (yyvsp[-2].pval), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL);}
#line 5316 "y.tab.c"
    break;

  case 390: /* file_info: COMMA name  */
#line 1030 "SyntaxBNF.y"
                       {(yyval.pval) = P_BUILD("file_info", P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5322 "y.tab.c"
    break;

  case 391: /* file_info: null  */
#line 1031 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("file_info", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5328 "y.tab.c"
    break;

  case 392: /* theory: _LIT_theory LPAREN theory_name optional_info RPAREN  */
#line 1034 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("theory", P_TOKEN("_LIT_theory ", (yyvsp[-4].ival)), P_TOKEN("LPAREN ", (yyvsp[-3].ival)), (yyvsp[-2].pval), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL);}
#line 5334 "y.tab.c"
    break;

  case 393: /* theory_name: atomic_word  */
#line 1037 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("theory_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5340 "y.tab.c"
    break;

  case 394: /* creator_source: _LIT_creator LPAREN creator_name COMMA useful_info COMMA parents RPAREN  */
#line 1040 "SyntaxBNF.y"
                                                                                         {(yyval.pval) = P_BUILD("creator_source", P_TOKEN("_LIT_creator ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 5346 "y.tab.c"
    break;

  case 395: /* creator_name: atomic_word  */
#line 1043 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("creator_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5352 "y.tab.c"
    break;

  case 396: /* parents: LBRKT RBRKT  */
#line 1046 "SyntaxBNF.y"
                      {(yyval.pval) = P_BUILD("parents", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5358 "y.tab.c"
    break;

  case 397: /* parents: LBRKT parent_list RBRKT  */
#line 1047 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("parents", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5364 "y.tab.c"
    break;

  case 398: /* parent_list: parent_info  */
#line 1050 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("parent_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5370 "y.tab.c"
    break;

  case 399: /* parent_list: parent_info COMMA parent_list  */
#line 1051 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("parent_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5376 "y.tab.c"
    break;

  case 400: /* parent_info: source parent_details  */
#line 1054 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("parent_info", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5382 "y.tab.c"
    break;

  case 401: /* parent_details: COLON general_list  */
#line 1057 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("parent_details", P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5388 "y.tab.c"
    break;

  case 402: /* parent_details: null  */
#line 1058 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("parent_details", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5394 "y.tab.c"
    break;

  case 403: /* optional_info: COMMA useful_info  */
#line 1061 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("optional_info", P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5400 "y.tab.c"
    break;

  case 404: /* optional_info: null  */
#line 1062 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("optional_info", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5406 "y.tab.c"
    break;

  case 405: /* useful_info: general_list  */
#line 1065 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("useful_info", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5412 "y.tab.c"
    break;

  case 406: /* include: _LIT_include LPAREN file_name include_optionals RPAREN PERIOD  */
#line 1068 "SyntaxBNF.y"
                                                                        {(yyval.pval) = P_BUILD("include", P_TOKEN("_LIT_include ", (yyvsp[-5].ival)), P_TOKEN("LPAREN ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL);}
#line 5418 "y.tab.c"
    break;

  case 407: /* include_optionals: null  */
#line 1071 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("include_optionals", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5424 "y.tab.c"
    break;

  case 408: /* include_optionals: COMMA formula_selection  */
#line 1072 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("include_optionals", P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5430 "y.tab.c"
    break;

  case 409: /* include_optionals: COMMA formula_selection COMMA space_name  */
#line 1073 "SyntaxBNF.y"
                                                               {(yyval.pval) = P_BUILD("include_optionals", P_TOKEN("COMMA ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5436 "y.tab.c"
    break;

  case 410: /* formula_selection: LBRKT name_list RBRKT  */
#line 1076 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("formula_selection", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5442 "y.tab.c"
    break;

  case 411: /* formula_selection: STAR  */
#line 1077 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("formula_selection", P_TOKEN("STAR ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5448 "y.tab.c"
    break;

  case 412: /* name_list: name  */
#line 1080 "SyntaxBNF.y"
                 {(yyval.pval) = P_BUILD("name_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5454 "y.tab.c"
    break;

  case 413: /* name_list: name COMMA name_list  */
#line 1081 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("name_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5460 "y.tab.c"
    break;

  case 414: /* space_name: name  */
#line 1084 "SyntaxBNF.y"
                  {(yyval.pval) = P_BUILD("space_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5466 "y.tab.c"
    break;

  case 415: /* general_term: general_data  */
#line 1087 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("general_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5472 "y.tab.c"
    break;

  case 416: /* general_term: general_data COLON general_term  */
#line 1088 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("general_term", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5478 "y.tab.c"
    break;

  case 417: /* general_term: general_list  */
#line 1089 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("general_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5484 "y.tab.c"
    break;

  case 418: /* general_data: atomic_word  */
#line 1092 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5490 "y.tab.c"
    break;

  case 419: /* general_data: general_function  */
#line 1093 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5496 "y.tab.c"
    break;

  case 420: /* general_data: variable  */
#line 1094 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5502 "y.tab.c"
    break;

  case 421: /* general_data: number  */
#line 1095 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5508 "y.tab.c"
    break;

  case 422: /* general_data: distinct_object  */
#line 1096 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("general_data", P_TOKEN("distinct_object ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5514 "y.tab.c"
    break;

  case 423: /* general_data: formula_data  */
#line 1097 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5520 "y.tab.c"
    break;

  case 424: /* general_function: atomic_word LPAREN general_terms RPAREN  */
#line 1100 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("general_function", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5526 "y.tab.c"
    break;

  case 425: /* formula_data: _DLR_thf LPAREN thf_formula RPAREN  */
#line 1103 "SyntaxBNF.y"
                                                  {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_thf ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5532 "y.tab.c"
    break;

  case 426: /* formula_data: _DLR_tff LPAREN tff_formula RPAREN  */
#line 1104 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_tff ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5538 "y.tab.c"
    break;

  case 427: /* formula_data: _DLR_fof LPAREN fof_formula RPAREN  */
#line 1105 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_fof ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5544 "y.tab.c"
    break;

  case 428: /* formula_data: _DLR_cnf LPAREN cnf_formula RPAREN  */
#line 1106 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_cnf ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5550 "y.tab.c"
    break;

  case 429: /* formula_data: _DLR_fot LPAREN fof_term RPAREN  */
#line 1107 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_fot ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5556 "y.tab.c"
    break;

  case 430: /* general_list: LBRKT RBRKT  */
#line 1110 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("general_list", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5562 "y.tab.c"
    break;

  case 431: /* general_list: LBRKT general_terms RBRKT  */
#line 1111 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("general_list", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5568 "y.tab.c"
    break;

  case 432: /* general_terms: general_term  */
#line 1114 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("general_terms", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5574 "y.tab.c"
    break;

  case 433: /* general_terms: general_term COMMA general_terms  */
#line 1115 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("general_terms", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5580 "y.tab.c"
    break;

  case 434: /* name: atomic_word  */
#line 1118 "SyntaxBNF.y"
                   {(yyval.pval) = P_BUILD("name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5586 "y.tab.c"
    break;

  case 435: /* name: integer  */
#line 1119 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("name", P_TOKEN("integer ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5592 "y.tab.c"
    break;

  case 436: /* atomic_word: lower_word  */
#line 1122 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("atomic_word", P_TOKEN("lower_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5598 "y.tab.c"
    break;

  case 437: /* atomic_word: single_quoted  */
#line 1123 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("atomic_word", P_TOKEN("single_quoted ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5604 "y.tab.c"
    break;

  case 438: /* atomic_defined_word: dollar_word  */
#line 1126 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("atomic_defined_word", P_TOKEN("dollar_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5610 "y.tab.c"
    break;

  case 439: /* atomic_system_word: dollar_dollar_word  */
#line 1129 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("atomic_system_word", P_TOKEN("dollar_dollar_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5616 "y.tab.c"
    break;

  case 440: /* number: integer  */
#line 1132 "SyntaxBNF.y"
                 {(yyval.pval) = P_BUILD("number", P_TOKEN("integer ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5622 "y.tab.c"
    break;

  case 441: /* number: rational  */
#line 1133 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("number", P_TOKEN("rational ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5628 "y.tab.c"
    break;

  case 442: /* number: real  */
#line 1134 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("number", P_TOKEN("real ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5634 "y.tab.c"
    break;

  case 443: /* file_name: atomic_word  */
#line 1137 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("file_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5640 "y.tab.c"
    break;

  case 444: /* null: %empty  */
#line 1140 "SyntaxBNF.y"
       {(yyval.pval) = P_BUILD("null",NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5646 "y.tab.c"
    break;


#line 5650 "y.tab.c"

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

