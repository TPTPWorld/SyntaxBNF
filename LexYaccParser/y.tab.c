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
    back_quoted = 317,             /* back_quoted  */
    distinct_object = 318,         /* distinct_object  */
    dollar_dollar_word = 319,      /* dollar_dollar_word  */
    dollar_word = 320,             /* dollar_word  */
    hash = 321,                    /* hash  */
    integer = 322,                 /* integer  */
    less_sign = 323,               /* less_sign  */
    lower_word = 324,              /* lower_word  */
    plus = 325,                    /* plus  */
    rational = 326,                /* rational  */
    real = 327,                    /* real  */
    single_quoted = 328,           /* single_quoted  */
    slash = 329,                   /* slash  */
    slosh = 330,                   /* slosh  */
    unrecognized = 331,            /* unrecognized  */
    upper_word = 332               /* upper_word  */
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
#define back_quoted 317
#define distinct_object 318
#define dollar_dollar_word 319
#define dollar_word 320
#define hash 321
#define integer 322
#define less_sign 323
#define lower_word 324
#define plus 325
#define rational 326
#define real 327
#define single_quoted 328
#define slash 329
#define slosh 330
#define unrecognized 331
#define upper_word 332

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 152 "SyntaxBNF.y"
int ival; double dval; char* sval; void* pval;

#line 431 "y.tab.c"

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
  YYSYMBOL_back_quoted = 62,               /* back_quoted  */
  YYSYMBOL_distinct_object = 63,           /* distinct_object  */
  YYSYMBOL_dollar_dollar_word = 64,        /* dollar_dollar_word  */
  YYSYMBOL_dollar_word = 65,               /* dollar_word  */
  YYSYMBOL_hash = 66,                      /* hash  */
  YYSYMBOL_integer = 67,                   /* integer  */
  YYSYMBOL_less_sign = 68,                 /* less_sign  */
  YYSYMBOL_lower_word = 69,                /* lower_word  */
  YYSYMBOL_plus = 70,                      /* plus  */
  YYSYMBOL_rational = 71,                  /* rational  */
  YYSYMBOL_real = 72,                      /* real  */
  YYSYMBOL_single_quoted = 73,             /* single_quoted  */
  YYSYMBOL_slash = 74,                     /* slash  */
  YYSYMBOL_slosh = 75,                     /* slosh  */
  YYSYMBOL_unrecognized = 76,              /* unrecognized  */
  YYSYMBOL_upper_word = 77,                /* upper_word  */
  YYSYMBOL_YYACCEPT = 78,                  /* $accept  */
  YYSYMBOL_TPTP_file = 79,                 /* TPTP_file  */
  YYSYMBOL_TPTP_input = 80,                /* TPTP_input  */
  YYSYMBOL_annotated_formula = 81,         /* annotated_formula  */
  YYSYMBOL_tpi_annotated = 82,             /* tpi_annotated  */
  YYSYMBOL_tpi_formula = 83,               /* tpi_formula  */
  YYSYMBOL_thf_annotated = 84,             /* thf_annotated  */
  YYSYMBOL_tff_annotated = 85,             /* tff_annotated  */
  YYSYMBOL_tcf_annotated = 86,             /* tcf_annotated  */
  YYSYMBOL_fof_annotated = 87,             /* fof_annotated  */
  YYSYMBOL_cnf_annotated = 88,             /* cnf_annotated  */
  YYSYMBOL_annotations = 89,               /* annotations  */
  YYSYMBOL_formula_role = 90,              /* formula_role  */
  YYSYMBOL_thf_formula = 91,               /* thf_formula  */
  YYSYMBOL_thf_logic_formula = 92,         /* thf_logic_formula  */
  YYSYMBOL_thf_binary_formula = 93,        /* thf_binary_formula  */
  YYSYMBOL_thf_binary_nonassoc = 94,       /* thf_binary_nonassoc  */
  YYSYMBOL_thf_binary_assoc = 95,          /* thf_binary_assoc  */
  YYSYMBOL_thf_or_formula = 96,            /* thf_or_formula  */
  YYSYMBOL_thf_and_formula = 97,           /* thf_and_formula  */
  YYSYMBOL_thf_apply_formula = 98,         /* thf_apply_formula  */
  YYSYMBOL_thf_unit_formula = 99,          /* thf_unit_formula  */
  YYSYMBOL_thf_preunit_formula = 100,      /* thf_preunit_formula  */
  YYSYMBOL_thf_unitary_formula = 101,      /* thf_unitary_formula  */
  YYSYMBOL_thf_quantified_formula = 102,   /* thf_quantified_formula  */
  YYSYMBOL_thf_quantification = 103,       /* thf_quantification  */
  YYSYMBOL_thf_variable_list = 104,        /* thf_variable_list  */
  YYSYMBOL_thf_typed_variable = 105,       /* thf_typed_variable  */
  YYSYMBOL_thf_unary_formula = 106,        /* thf_unary_formula  */
  YYSYMBOL_thf_prefix_unary = 107,         /* thf_prefix_unary  */
  YYSYMBOL_thf_infix_unary = 108,          /* thf_infix_unary  */
  YYSYMBOL_thf_atomic_formula = 109,       /* thf_atomic_formula  */
  YYSYMBOL_thf_plain_atomic = 110,         /* thf_plain_atomic  */
  YYSYMBOL_thf_defined_atomic = 111,       /* thf_defined_atomic  */
  YYSYMBOL_thf_defined_term = 112,         /* thf_defined_term  */
  YYSYMBOL_thf_defined_infix = 113,        /* thf_defined_infix  */
  YYSYMBOL_thf_system_atomic = 114,        /* thf_system_atomic  */
  YYSYMBOL_thf_let = 115,                  /* thf_let  */
  YYSYMBOL_thf_let_types = 116,            /* thf_let_types  */
  YYSYMBOL_thf_atom_typing_list = 117,     /* thf_atom_typing_list  */
  YYSYMBOL_thf_let_defns = 118,            /* thf_let_defns  */
  YYSYMBOL_thf_let_defn = 119,             /* thf_let_defn  */
  YYSYMBOL_thf_let_defn_list = 120,        /* thf_let_defn_list  */
  YYSYMBOL_thf_unitary_term = 121,         /* thf_unitary_term  */
  YYSYMBOL_thf_conn_term = 122,            /* thf_conn_term  */
  YYSYMBOL_thf_tuple = 123,                /* thf_tuple  */
  YYSYMBOL_thf_formula_list = 124,         /* thf_formula_list  */
  YYSYMBOL_thf_atom_typing = 125,          /* thf_atom_typing  */
  YYSYMBOL_thf_top_level_type = 126,       /* thf_top_level_type  */
  YYSYMBOL_thf_unitary_type = 127,         /* thf_unitary_type  */
  YYSYMBOL_thf_apply_type = 128,           /* thf_apply_type  */
  YYSYMBOL_thf_binary_type = 129,          /* thf_binary_type  */
  YYSYMBOL_thf_mapping_type = 130,         /* thf_mapping_type  */
  YYSYMBOL_thf_xprod_type = 131,           /* thf_xprod_type  */
  YYSYMBOL_thf_union_type = 132,           /* thf_union_type  */
  YYSYMBOL_thf_subtype = 133,              /* thf_subtype  */
  YYSYMBOL_thf_definition = 134,           /* thf_definition  */
  YYSYMBOL_thf_sequent = 135,              /* thf_sequent  */
  YYSYMBOL_tff_formula = 136,              /* tff_formula  */
  YYSYMBOL_tff_logic_formula = 137,        /* tff_logic_formula  */
  YYSYMBOL_tff_binary_formula = 138,       /* tff_binary_formula  */
  YYSYMBOL_tff_binary_nonassoc = 139,      /* tff_binary_nonassoc  */
  YYSYMBOL_tff_binary_assoc = 140,         /* tff_binary_assoc  */
  YYSYMBOL_tff_or_formula = 141,           /* tff_or_formula  */
  YYSYMBOL_tff_and_formula = 142,          /* tff_and_formula  */
  YYSYMBOL_tff_unit_formula = 143,         /* tff_unit_formula  */
  YYSYMBOL_tff_preunit_formula = 144,      /* tff_preunit_formula  */
  YYSYMBOL_tff_unitary_formula = 145,      /* tff_unitary_formula  */
  YYSYMBOL_txf_unitary_formula = 146,      /* txf_unitary_formula  */
  YYSYMBOL_tff_quantified_formula = 147,   /* tff_quantified_formula  */
  YYSYMBOL_tff_variable_list = 148,        /* tff_variable_list  */
  YYSYMBOL_tff_variable = 149,             /* tff_variable  */
  YYSYMBOL_tff_typed_variable = 150,       /* tff_typed_variable  */
  YYSYMBOL_tff_unary_formula = 151,        /* tff_unary_formula  */
  YYSYMBOL_tff_prefix_unary = 152,         /* tff_prefix_unary  */
  YYSYMBOL_tff_infix_unary = 153,          /* tff_infix_unary  */
  YYSYMBOL_tff_atomic_formula = 154,       /* tff_atomic_formula  */
  YYSYMBOL_tff_plain_atomic = 155,         /* tff_plain_atomic  */
  YYSYMBOL_tff_defined_atomic = 156,       /* tff_defined_atomic  */
  YYSYMBOL_tff_defined_plain = 157,        /* tff_defined_plain  */
  YYSYMBOL_tff_defined_infix = 158,        /* tff_defined_infix  */
  YYSYMBOL_tff_system_atomic = 159,        /* tff_system_atomic  */
  YYSYMBOL_txf_let = 160,                  /* txf_let  */
  YYSYMBOL_txf_let_types = 161,            /* txf_let_types  */
  YYSYMBOL_tff_atom_typing_list = 162,     /* tff_atom_typing_list  */
  YYSYMBOL_txf_let_defns = 163,            /* txf_let_defns  */
  YYSYMBOL_txf_let_defn = 164,             /* txf_let_defn  */
  YYSYMBOL_txf_let_LHS = 165,              /* txf_let_LHS  */
  YYSYMBOL_txf_let_defn_list = 166,        /* txf_let_defn_list  */
  YYSYMBOL_nxf_atom = 167,                 /* nxf_atom  */
  YYSYMBOL_tff_term = 168,                 /* tff_term  */
  YYSYMBOL_tff_unitary_term = 169,         /* tff_unitary_term  */
  YYSYMBOL_txf_tuple = 170,                /* txf_tuple  */
  YYSYMBOL_tff_arguments = 171,            /* tff_arguments  */
  YYSYMBOL_tff_atom_typing = 172,          /* tff_atom_typing  */
  YYSYMBOL_tff_top_level_type = 173,       /* tff_top_level_type  */
  YYSYMBOL_tff_non_atomic_type = 174,      /* tff_non_atomic_type  */
  YYSYMBOL_tf1_quantified_type = 175,      /* tf1_quantified_type  */
  YYSYMBOL_tff_monotype = 176,             /* tff_monotype  */
  YYSYMBOL_tff_unitary_type = 177,         /* tff_unitary_type  */
  YYSYMBOL_tff_atomic_type = 178,          /* tff_atomic_type  */
  YYSYMBOL_tff_type_arguments = 179,       /* tff_type_arguments  */
  YYSYMBOL_tff_mapping_type = 180,         /* tff_mapping_type  */
  YYSYMBOL_tff_xprod_type = 181,           /* tff_xprod_type  */
  YYSYMBOL_txf_tuple_type = 182,           /* txf_tuple_type  */
  YYSYMBOL_tff_type_list = 183,            /* tff_type_list  */
  YYSYMBOL_tff_subtype = 184,              /* tff_subtype  */
  YYSYMBOL_txf_definition = 185,           /* txf_definition  */
  YYSYMBOL_txf_sequent = 186,              /* txf_sequent  */
  YYSYMBOL_nhf_long_connective = 187,      /* nhf_long_connective  */
  YYSYMBOL_nhf_parameter_list = 188,       /* nhf_parameter_list  */
  YYSYMBOL_nhf_parameter = 189,            /* nhf_parameter  */
  YYSYMBOL_nhf_key_pair = 190,             /* nhf_key_pair  */
  YYSYMBOL_nxf_long_connective = 191,      /* nxf_long_connective  */
  YYSYMBOL_nxf_parameter_list = 192,       /* nxf_parameter_list  */
  YYSYMBOL_nxf_parameter = 193,            /* nxf_parameter  */
  YYSYMBOL_nxf_key_pair = 194,             /* nxf_key_pair  */
  YYSYMBOL_ntf_connective_name = 195,      /* ntf_connective_name  */
  YYSYMBOL_ntf_defined_connective = 196,   /* ntf_defined_connective  */
  YYSYMBOL_ntf_index = 197,                /* ntf_index  */
  YYSYMBOL_ntf_short_connective = 198,     /* ntf_short_connective  */
  YYSYMBOL_tcf_formula = 199,              /* tcf_formula  */
  YYSYMBOL_tcf_logic_formula = 200,        /* tcf_logic_formula  */
  YYSYMBOL_tcf_quantified_formula = 201,   /* tcf_quantified_formula  */
  YYSYMBOL_fof_formula = 202,              /* fof_formula  */
  YYSYMBOL_fof_logic_formula = 203,        /* fof_logic_formula  */
  YYSYMBOL_fof_binary_formula = 204,       /* fof_binary_formula  */
  YYSYMBOL_fof_binary_nonassoc = 205,      /* fof_binary_nonassoc  */
  YYSYMBOL_fof_binary_assoc = 206,         /* fof_binary_assoc  */
  YYSYMBOL_fof_or_formula = 207,           /* fof_or_formula  */
  YYSYMBOL_fof_and_formula = 208,          /* fof_and_formula  */
  YYSYMBOL_fof_unary_formula = 209,        /* fof_unary_formula  */
  YYSYMBOL_fof_infix_unary = 210,          /* fof_infix_unary  */
  YYSYMBOL_fof_unit_formula = 211,         /* fof_unit_formula  */
  YYSYMBOL_fof_unitary_formula = 212,      /* fof_unitary_formula  */
  YYSYMBOL_fof_quantified_formula = 213,   /* fof_quantified_formula  */
  YYSYMBOL_fof_variable_list = 214,        /* fof_variable_list  */
  YYSYMBOL_fof_atomic_formula = 215,       /* fof_atomic_formula  */
  YYSYMBOL_fof_plain_atomic_formula = 216, /* fof_plain_atomic_formula  */
  YYSYMBOL_fof_defined_atomic_formula = 217, /* fof_defined_atomic_formula  */
  YYSYMBOL_fof_defined_plain_formula = 218, /* fof_defined_plain_formula  */
  YYSYMBOL_fof_defined_infix_formula = 219, /* fof_defined_infix_formula  */
  YYSYMBOL_fof_system_atomic_formula = 220, /* fof_system_atomic_formula  */
  YYSYMBOL_fof_plain_term = 221,           /* fof_plain_term  */
  YYSYMBOL_fof_defined_term = 222,         /* fof_defined_term  */
  YYSYMBOL_fof_defined_atomic_term = 223,  /* fof_defined_atomic_term  */
  YYSYMBOL_fof_defined_plain_term = 224,   /* fof_defined_plain_term  */
  YYSYMBOL_fof_system_term = 225,          /* fof_system_term  */
  YYSYMBOL_fof_arguments = 226,            /* fof_arguments  */
  YYSYMBOL_fof_term = 227,                 /* fof_term  */
  YYSYMBOL_fof_function_term = 228,        /* fof_function_term  */
  YYSYMBOL_fof_sequent = 229,              /* fof_sequent  */
  YYSYMBOL_fof_formula_tuple = 230,        /* fof_formula_tuple  */
  YYSYMBOL_fof_formula_tuple_list = 231,   /* fof_formula_tuple_list  */
  YYSYMBOL_cnf_formula = 232,              /* cnf_formula  */
  YYSYMBOL_cnf_disjunction = 233,          /* cnf_disjunction  */
  YYSYMBOL_cnf_literal = 234,              /* cnf_literal  */
  YYSYMBOL_thf_quantifier = 235,           /* thf_quantifier  */
  YYSYMBOL_thf_unary_connective = 236,     /* thf_unary_connective  */
  YYSYMBOL_th0_quantifier = 237,           /* th0_quantifier  */
  YYSYMBOL_type_quantifier = 238,          /* type_quantifier  */
  YYSYMBOL_subtype_sign = 239,             /* subtype_sign  */
  YYSYMBOL_tff_unary_connective = 240,     /* tff_unary_connective  */
  YYSYMBOL_tff_quantifier = 241,           /* tff_quantifier  */
  YYSYMBOL_fof_quantifier = 242,           /* fof_quantifier  */
  YYSYMBOL_nonassoc_connective = 243,      /* nonassoc_connective  */
  YYSYMBOL_assoc_connective = 244,         /* assoc_connective  */
  YYSYMBOL_unary_connective = 245,         /* unary_connective  */
  YYSYMBOL_gentzen_arrow = 246,            /* gentzen_arrow  */
  YYSYMBOL_assignment = 247,               /* assignment  */
  YYSYMBOL_identical = 248,                /* identical  */
  YYSYMBOL_typeable_atom = 249,            /* typeable_atom  */
  YYSYMBOL_atomic_type = 250,              /* atomic_type  */
  YYSYMBOL_type_constant = 251,            /* type_constant  */
  YYSYMBOL_type_functor = 252,             /* type_functor  */
  YYSYMBOL_defined_type = 253,             /* defined_type  */
  YYSYMBOL_system_type = 254,              /* system_type  */
  YYSYMBOL_defined_infix_pred = 255,       /* defined_infix_pred  */
  YYSYMBOL_infix_equality = 256,           /* infix_equality  */
  YYSYMBOL_infix_inequality = 257,         /* infix_inequality  */
  YYSYMBOL_constant = 258,                 /* constant  */
  YYSYMBOL_functor = 259,                  /* functor  */
  YYSYMBOL_defined_constant = 260,         /* defined_constant  */
  YYSYMBOL_defined_functor = 261,          /* defined_functor  */
  YYSYMBOL_system_constant = 262,          /* system_constant  */
  YYSYMBOL_system_functor = 263,           /* system_functor  */
  YYSYMBOL_th1_defined_term = 264,         /* th1_defined_term  */
  YYSYMBOL_defined_term = 265,             /* defined_term  */
  YYSYMBOL_variable = 266,                 /* variable  */
  YYSYMBOL_source = 267,                   /* source  */
  YYSYMBOL_sources = 268,                  /* sources  */
  YYSYMBOL_dag_source = 269,               /* dag_source  */
  YYSYMBOL_inference_record = 270,         /* inference_record  */
  YYSYMBOL_inference_rule = 271,           /* inference_rule  */
  YYSYMBOL_internal_source = 272,          /* internal_source  */
  YYSYMBOL_intro_type = 273,               /* intro_type  */
  YYSYMBOL_external_source = 274,          /* external_source  */
  YYSYMBOL_file_source = 275,              /* file_source  */
  YYSYMBOL_file_info = 276,                /* file_info  */
  YYSYMBOL_theory = 277,                   /* theory  */
  YYSYMBOL_theory_name = 278,              /* theory_name  */
  YYSYMBOL_creator_source = 279,           /* creator_source  */
  YYSYMBOL_creator_name = 280,             /* creator_name  */
  YYSYMBOL_parents = 281,                  /* parents  */
  YYSYMBOL_parent_list = 282,              /* parent_list  */
  YYSYMBOL_parent_info = 283,              /* parent_info  */
  YYSYMBOL_parent_details = 284,           /* parent_details  */
  YYSYMBOL_optional_info = 285,            /* optional_info  */
  YYSYMBOL_useful_info = 286,              /* useful_info  */
  YYSYMBOL_include = 287,                  /* include  */
  YYSYMBOL_include_optionals = 288,        /* include_optionals  */
  YYSYMBOL_formula_selection = 289,        /* formula_selection  */
  YYSYMBOL_name_list = 290,                /* name_list  */
  YYSYMBOL_space_name = 291,               /* space_name  */
  YYSYMBOL_general_term = 292,             /* general_term  */
  YYSYMBOL_general_data = 293,             /* general_data  */
  YYSYMBOL_general_function = 294,         /* general_function  */
  YYSYMBOL_formula_data = 295,             /* formula_data  */
  YYSYMBOL_general_list = 296,             /* general_list  */
  YYSYMBOL_general_terms = 297,            /* general_terms  */
  YYSYMBOL_name = 298,                     /* name  */
  YYSYMBOL_atomic_word = 299,              /* atomic_word  */
  YYSYMBOL_atomic_defined_word = 300,      /* atomic_defined_word  */
  YYSYMBOL_atomic_system_word = 301,       /* atomic_system_word  */
  YYSYMBOL_number = 302,                   /* number  */
  YYSYMBOL_file_name = 303,                /* file_name  */
  YYSYMBOL_nothing = 304                   /* nothing  */
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
#define YYLAST   3502

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  78
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  227
/* YYNRULES -- Number of rules.  */
#define YYNRULES  442
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  820

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   332


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
      75,    76,    77
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   231,   231,   232,   235,   236,   239,   240,   241,   242,
     243,   244,   247,   250,   253,   256,   259,   262,   265,   268,
     269,   272,   273,   276,   277,   278,   281,   282,   283,   284,
     285,   286,   289,   290,   291,   294,   297,   298,   299,   302,
     303,   306,   307,   310,   311,   314,   315,   316,   319,   320,
     323,   324,   325,   326,   329,   332,   335,   336,   339,   342,
     343,   346,   349,   352,   353,   354,   357,   358,   361,   362,
     363,   364,   365,   368,   369,   372,   375,   378,   381,   382,
     385,   386,   389,   390,   393,   396,   397,   400,   401,   402,
     405,   406,   407,   408,   409,   412,   413,   416,   417,   420,
     421,   424,   425,   426,   429,   432,   435,   436,   437,   440,
     441,   444,   445,   448,   449,   452,   455,   458,   461,   462,
     463,   466,   467,   468,   469,   470,   471,   474,   475,   478,
     481,   482,   485,   486,   489,   490,   493,   494,   495,   498,
     499,   502,   503,   504,   505,   508,   511,   514,   515,   518,
     519,   522,   525,   526,   529,   532,   535,   536,   537,   540,
     541,   544,   547,   548,   549,   550,   553,   556,   557,   560,
     563,   564,   567,   568,   571,   572,   575,   578,   579,   582,
     583,   586,   589,   590,   591,   594,   595,   596,   597,   598,
     601,   602,   605,   606,   609,   610,   613,   614,   617,   618,
     619,   622,   625,   626,   627,   630,   631,   634,   635,   636,
     637,   638,   639,   642,   643,   646,   649,   650,   653,   656,
     657,   660,   663,   666,   669,   670,   673,   674,   677,   678,
     681,   684,   685,   688,   689,   692,   693,   696,   699,   700,
     703,   706,   709,   710,   711,   712,   715,   716,   719,   720,
     723,   726,   727,   730,   731,   732,   735,   736,   739,   742,
     743,   746,   747,   750,   751,   754,   755,   758,   761,   762,
     765,   766,   767,   770,   773,   774,   777,   778,   779,   782,
     785,   786,   789,   792,   795,   798,   799,   802,   803,   806,
     809,   810,   813,   814,   817,   818,   821,   822,   825,   826,
     827,   830,   831,   834,   835,   838,   839,   842,   843,   846,
     847,   850,   851,   852,   853,   856,   857,   858,   861,   862,
     865,   866,   867,   870,   871,   874,   877,   878,   881,   882,
     885,   886,   889,   890,   891,   892,   893,   894,   897,   898,
     901,   904,   907,   910,   913,   914,   917,   918,   919,   922,
     925,   928,   931,   934,   937,   940,   943,   946,   949,   952,
     955,   958,   961,   962,   963,   964,   965,   968,   969,   972,
     975,   976,   977,   978,   979,   982,   983,   986,   987,   990,
     993,   996,   999,  1002,  1003,  1004,  1007,  1010,  1011,  1014,
    1017,  1020,  1023,  1026,  1027,  1030,  1031,  1034,  1037,  1038,
    1041,  1042,  1045,  1048,  1051,  1052,  1053,  1056,  1057,  1060,
    1061,  1064,  1067,  1068,  1069,  1072,  1073,  1074,  1075,  1076,
    1077,  1080,  1083,  1084,  1085,  1086,  1087,  1090,  1091,  1094,
    1095,  1098,  1099,  1102,  1103,  1104,  1107,  1110,  1113,  1114,
    1115,  1118,  1121
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
  "back_quoted", "distinct_object", "dollar_dollar_word", "dollar_word",
  "hash", "integer", "less_sign", "lower_word", "plus", "rational", "real",
  "single_quoted", "slash", "slosh", "unrecognized", "upper_word",
  "$accept", "TPTP_file", "TPTP_input", "annotated_formula",
  "tpi_annotated", "tpi_formula", "thf_annotated", "tff_annotated",
  "tcf_annotated", "fof_annotated", "cnf_annotated", "annotations",
  "formula_role", "thf_formula", "thf_logic_formula", "thf_binary_formula",
  "thf_binary_nonassoc", "thf_binary_assoc", "thf_or_formula",
  "thf_and_formula", "thf_apply_formula", "thf_unit_formula",
  "thf_preunit_formula", "thf_unitary_formula", "thf_quantified_formula",
  "thf_quantification", "thf_variable_list", "thf_typed_variable",
  "thf_unary_formula", "thf_prefix_unary", "thf_infix_unary",
  "thf_atomic_formula", "thf_plain_atomic", "thf_defined_atomic",
  "thf_defined_term", "thf_defined_infix", "thf_system_atomic", "thf_let",
  "thf_let_types", "thf_atom_typing_list", "thf_let_defns", "thf_let_defn",
  "thf_let_defn_list", "thf_unitary_term", "thf_conn_term", "thf_tuple",
  "thf_formula_list", "thf_atom_typing", "thf_top_level_type",
  "thf_unitary_type", "thf_apply_type", "thf_binary_type",
  "thf_mapping_type", "thf_xprod_type", "thf_union_type", "thf_subtype",
  "thf_definition", "thf_sequent", "tff_formula", "tff_logic_formula",
  "tff_binary_formula", "tff_binary_nonassoc", "tff_binary_assoc",
  "tff_or_formula", "tff_and_formula", "tff_unit_formula",
  "tff_preunit_formula", "tff_unitary_formula", "txf_unitary_formula",
  "tff_quantified_formula", "tff_variable_list", "tff_variable",
  "tff_typed_variable", "tff_unary_formula", "tff_prefix_unary",
  "tff_infix_unary", "tff_atomic_formula", "tff_plain_atomic",
  "tff_defined_atomic", "tff_defined_plain", "tff_defined_infix",
  "tff_system_atomic", "txf_let", "txf_let_types", "tff_atom_typing_list",
  "txf_let_defns", "txf_let_defn", "txf_let_LHS", "txf_let_defn_list",
  "nxf_atom", "tff_term", "tff_unitary_term", "txf_tuple", "tff_arguments",
  "tff_atom_typing", "tff_top_level_type", "tff_non_atomic_type",
  "tf1_quantified_type", "tff_monotype", "tff_unitary_type",
  "tff_atomic_type", "tff_type_arguments", "tff_mapping_type",
  "tff_xprod_type", "txf_tuple_type", "tff_type_list", "tff_subtype",
  "txf_definition", "txf_sequent", "nhf_long_connective",
  "nhf_parameter_list", "nhf_parameter", "nhf_key_pair",
  "nxf_long_connective", "nxf_parameter_list", "nxf_parameter",
  "nxf_key_pair", "ntf_connective_name", "ntf_defined_connective",
  "ntf_index", "ntf_short_connective", "tcf_formula", "tcf_logic_formula",
  "tcf_quantified_formula", "fof_formula", "fof_logic_formula",
  "fof_binary_formula", "fof_binary_nonassoc", "fof_binary_assoc",
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
  "intro_type", "external_source", "file_source", "file_info", "theory",
  "theory_name", "creator_source", "creator_name", "parents",
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

#define YYPACT_NINF (-552)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-353)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -552,   723,  -552,  -552,    46,    75,    83,   103,   113,   115,
     124,  -552,  -552,  -552,  -552,  -552,  -552,  -552,  -552,  -552,
     649,   649,   500,   649,   649,   649,   649,  -552,  -552,  -552,
    -552,   146,  -552,   151,  -552,   154,   172,   206,   217,   234,
     194,   194,   121,   230,  -552,   194,   194,   194,   194,   256,
     273,   291,   649,  -552,   307,   295,   317,   328,   348,   349,
    2484,  1132,  1824,   298,   361,   649,  -552,  1924,  3351,  2878,
    1824,  2715,   362,   377,   390,   392,   393,  -552,  -552,  -552,
    -552,  -552,  -552,  -552,   364,  -552,  -552,  -552,   398,  -552,
    1132,  1674,  -552,  -552,  -552,  -552,  -552,  -552,  -552,  -552,
    -552,  -552,   303,  -552,  -552,   322,   428,   444,  -552,   363,
     347,  -552,  -552,   401,  -552,   410,  -552,   417,  -552,  -552,
    -552,  -552,  -552,  -552,  -552,  1351,  1824,  -552,  -552,   363,
    -552,  -552,  -552,  -552,   406,   458,    69,  -552,   952,   395,
    -552,  -552,  -552,   448,   465,  1852,  -552,   649,  -552,  -552,
     472,  1420,   169,  -552,   363,  -552,  -552,  -552,   484,   490,
      97,  2452,  3192,   469,  -552,   480,   363,  -552,  -552,  -552,
    -552,   477,   521,  1219,   507,  -552,  -552,   513,  -552,  -552,
     246,  -552,  -552,  -552,   519,  -552,  -552,  -552,   444,   448,
    -552,  -552,  -552,  -552,   529,  -552,  1752,   524,  -552,  -552,
     484,   504,  -552,   184,   536,   539,   544,  -552,   547,  -552,
     523,   556,  -552,  -552,  -552,  -552,  -552,  -552,  -552,  -552,
      97,  1597,  2573,  -552,  -552,   572,   363,  -552,  -552,  -552,
    -552,   542,   597,   595,   847,   439,  -552,  2949,   421,  -552,
    -552,   320,  -552,  -552,  -552,   437,  -552,  -552,   444,   448,
    -552,    39,  -552,  -552,   569,   538,  -552,  -552,  -552,  -552,
    -552,   592,  3020,  -552,  -552,  -552,  -552,   604,   504,   184,
    -552,   539,  -552,  -552,  -552,  -552,  -552,   584,   363,  -552,
    -552,   603,   586,  1132,  1824,  1729,  3351,  2878,  2484,  2484,
     593,  1729,  -552,   626,  -552,  -552,  1729,  -552,  1729,  1530,
     609,  -552,  2366,  1729,  1729,  1729,  1852,  -552,   635,   628,
     631,   637,   638,  1852,  1852,  1852,  -552,  -552,  -552,  -552,
    -552,  -552,  1852,  1852,  -552,   659,   612,  -552,  -552,  -552,
    -552,   612,   654,   657,   503,   663,   114,  -552,  -552,  -552,
    3245,   664,  -552,  -552,   685,   236,   665,  -552,  -552,   618,
     666,   667,   471,   645,   672,  3404,  3404,  3404,  3404,  3404,
    -552,  3404,  1000,  1000,   691,   688,   694,  3245,  -552,  -552,
    -552,  -552,  -552,   612,  -552,   591,  3404,  3404,  3404,   141,
    2667,  -552,   713,   695,  -552,  -552,  -552,  -552,   697,   699,
     704,  3020,  -552,  -552,   604,  -552,  -552,   534,   707,  2949,
    2949,  2949,  2949,  2949,  2949,  2949,  -552,  -552,  -552,   624,
    -552,  -552,  2949,  1025,  1025,   709,  3162,  3162,  3162,  3162,
    3162,   612,  2667,  -552,  -552,  -552,  -552,  -552,  2949,   591,
     708,  2484,  -552,   710,   711,  -552,  -552,  -552,   719,   720,
     721,  -552,   722,  -552,   724,  -552,  -552,  1530,   718,   735,
     740,   742,   743,  -552,   763,  -552,  -552,  -552,  -552,  -552,
    -552,  -552,  -552,   747,  -552,   749,   773,   753,   756,  1852,
    -552,  -552,  -552,   764,  -552,  -552,  -552,  -552,  -552,  -552,
     758,   783,   765,   785,  -552,   737,  -552,   771,   503,   503,
    -552,  -552,  -552,   745,   748,  -552,  -552,   782,  -552,   780,
    -552,  -552,  -552,  -552,  -552,   969,  -552,  -552,  3404,  -552,
    -552,   625,   568,   568,  -552,   799,  -552,  -552,  -552,   784,
    -552,  -552,  -552,   647,  -552,  -552,  -552,  -552,  -552,  -552,
    -552,   105,  3298,  3404,  -552,  -552,  -552,  -552,  -552,  3404,
     777,   781,  -552,  -552,  -552,  -552,   786,   788,   789,  1261,
    -552,  2949,  -552,   673,  -552,  -552,   623,   623,   804,  -552,
     791,  -552,  -552,  -552,  -552,  -552,  -552,  -552,  -552,   105,
    2195,  2807,  -552,  -552,  -552,  -552,  -552,  2807,  -552,  -552,
     772,  -552,  -552,  -552,  -552,   797,   822,   825,   802,   595,
     837,   838,  -552,   772,  -552,  -552,  -552,   821,  -552,  -552,
    -552,  -552,  -552,  -552,  -552,  -552,   839,   819,   500,   500,
     500,   500,   500,   833,  -552,  -552,  -552,  -552,  1729,  -552,
    -552,  -552,  -552,   848,   612,   850,   612,   746,  -552,   849,
     829,   836,    59,   841,   160,   746,   612,   746,  1000,   854,
    -552,   843,   861,  -552,  -552,  -552,   840,   872,    76,  -552,
     846,   853,  -552,   879,  -552,  -552,  -552,  1335,   854,  -552,
     857,   881,  -552,  -552,  -552,   868,   884,  3091,  -552,   871,
     897,   612,  2949,  -552,  -552,  1530,  -552,   899,  -552,   900,
     901,  -552,   902,  -552,   763,  -552,  -552,  -552,  -552,  1852,
    -552,  2110,  -552,   746,  -552,   503,  -552,  -552,   746,  -552,
    -552,   746,  -552,   882,   912,   890,  -552,   903,   969,  -552,
     568,  3298,  -552,   922,  -552,   924,  -552,  -552,  -552,  3404,
     909,   911,  -552,   910,  1261,  -552,   623,  1597,   924,   930,
    -552,  -552,  -552,  -552,  -552,  -552,   833,   649,   914,  -552,
     833,   833,   920,  -552,  -552,   841,  -552,  -552,  -552,   934,
     746,  -552,  -552,  -552,  -552,   935,   944,   913,   485,  3404,
    -552,  3404,  -552,  -552,  -552,  -552,   192,   946,   926,  2949,
    2949,   950,  -552,  -552,   951,   954,  -552,   889,  -552,   210,
    -552,   929,  -552,  2949,  -552,  -552,   933,   948,   948,   948,
     869,  -552,  -552,  -552,  -552,  -552,  -552,  -552,  3429,   941,
     943,   947,   869,   953,  -552,   960,   945,   971,  -552,  -552,
    -552,   949,  -552,  2484,  -552,  -552,  -552,  1530,  -552,  -552
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     442,     0,     2,     1,     0,     0,     0,     0,     0,     0,
       0,     3,     4,    11,     6,     7,     8,     9,    10,     5,
       0,     0,     0,     0,     0,     0,     0,   435,   432,   433,
     434,     0,   431,     0,   441,   442,     0,     0,     0,     0,
       0,     0,     0,     0,   404,     0,     0,     0,     0,    21,
       0,     0,     0,   408,   405,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   409,     0,   403,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   419,   438,   439,
     440,   369,   417,    22,   412,   416,   420,   414,   415,   418,
       0,     0,   368,   437,   436,   314,   311,   276,   277,   280,
     281,   278,   279,   299,   288,   282,   284,     0,   296,   442,
     307,   309,   285,   356,   290,   358,   292,   360,   287,   297,
     357,   359,   361,   367,   330,     0,     0,   331,   340,   442,
     251,   253,   256,   257,   259,   260,   269,   266,     0,   268,
     270,   271,   252,     0,     0,     0,   407,     0,   406,   411,
       0,     0,   368,   247,   442,   246,   248,   249,     0,   285,
       0,     0,     0,     0,   329,     0,   442,   118,   123,   127,
     128,   130,   131,     0,   136,   143,   141,   137,   152,   153,
     142,   156,   157,   161,   138,   158,   165,   164,     0,   187,
     119,   120,   125,   126,     0,   327,     0,     0,   328,   326,
     346,     0,   348,   159,   356,   162,   358,   167,   360,   186,
     145,   361,   365,   364,   366,   322,   321,   320,   362,   323,
       0,     0,     0,   363,   324,     0,   442,    23,    28,    32,
      33,    36,    37,    38,     0,    45,    50,     0,    46,    59,
      60,    51,    63,    64,    69,    47,    65,    72,     0,    67,
      24,     0,    34,   106,   107,   108,    25,    30,    31,    71,
     319,     0,     0,   316,   317,   315,   318,   346,     0,    66,
     356,    68,   358,    76,   360,    74,    73,    52,   442,    13,
     427,   429,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   312,     0,   354,   355,     0,   353,     0,     0,
       0,    20,     0,     0,     0,     0,     0,   303,   305,     0,
       0,     0,     0,     0,     0,     0,   333,   334,   332,   335,
     337,   336,     0,     0,   341,     0,     0,   269,   265,   268,
     410,     0,     0,     0,     0,     0,     0,   238,   240,   239,
       0,     0,   190,   182,   192,   184,     0,   159,   162,   183,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     343,     0,     0,     0,     0,     0,     0,     0,   154,   139,
     140,   142,   145,     0,   325,     0,     0,     0,     0,     0,
       0,    95,    97,     0,    66,    68,   339,   338,     0,     0,
       0,    94,    90,    91,     0,    92,    93,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    54,    45,    46,    51,
      47,    67,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    61,    48,    49,    51,    52,     0,     0,
       0,     0,   428,     0,     0,   298,   289,   300,     0,     0,
       0,   413,     0,   308,     0,   283,   267,     0,     0,     0,
       0,     0,     0,   373,   442,   370,   378,   371,   372,   383,
     384,   385,   377,     0,   310,     0,   294,     0,     0,     0,
     304,   272,   302,     0,   262,   264,   263,   261,   258,   301,
       0,   274,     0,   147,   149,   150,   195,     0,     0,     0,
     194,   197,   199,     0,   196,   198,   212,     0,   207,   349,
     208,   209,   350,   351,   244,     0,   231,   242,     0,   191,
     245,   144,     0,     0,   345,     0,   170,   344,   243,     0,
     133,   136,   137,   142,   138,   187,   135,   134,   132,   129,
     222,     0,     0,     0,   185,   166,   188,   155,   223,     0,
       0,     0,   346,   221,   347,   352,     0,     0,     0,     0,
     224,     0,    96,    53,    70,   100,     0,     0,     0,    78,
       0,    40,    42,    44,    41,    43,    39,    35,   116,     0,
       0,     0,    87,    75,    88,    62,   117,     0,   104,   111,
     109,   110,   113,   112,   114,     0,    56,     0,     0,   105,
       0,   104,    99,   101,   103,   102,   115,     0,   430,   425,
     424,   426,   423,   422,   421,   313,   375,     0,     0,     0,
       0,     0,     0,     0,    19,   401,    18,   286,     0,   291,
     293,   306,    17,     0,     0,     0,     0,     0,    16,   219,
       0,     0,     0,   205,     0,     0,     0,     0,     0,     0,
     237,     0,   233,   236,   235,   193,     0,   172,     0,    15,
       0,     0,   144,     0,   160,   163,   168,     0,     0,   230,
       0,   226,   229,   228,    98,     0,    80,     0,    14,     0,
       0,     0,     0,    53,    12,     0,   374,     0,   392,   442,
       0,   380,     0,   382,   442,   390,   400,   402,   295,     0,
     275,     0,   148,     0,   151,     0,   218,   200,     0,   211,
     206,     0,   215,     0,   213,     0,   241,     0,     0,   171,
       0,     0,   177,     0,   174,     0,   178,   189,   181,     0,
       0,     0,    94,     0,     0,    79,     0,     0,     0,     0,
      82,    89,    55,    57,    58,   376,     0,     0,     0,   388,
       0,     0,     0,   273,   250,     0,   220,   216,   217,     0,
       0,   210,   232,   234,   173,   156,   179,     0,   184,     0,
     342,     0,   146,   225,   227,    81,    97,    85,     0,     0,
       0,     0,   387,   386,     0,     0,   389,     0,   214,     0,
     175,     0,   176,     0,    83,    84,     0,     0,     0,     0,
       0,   204,   201,   202,   180,   169,    86,    77,     0,     0,
       0,     0,     0,     0,   393,   442,     0,   395,   391,   379,
     381,     0,   203,     0,   397,   399,   394,     0,   398,   396
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -552,  -552,  -552,  -552,  -552,  -552,  -552,  -552,  -552,  -552,
    -552,   289,   579,   714,   -20,  -552,  -552,  -552,  -552,  -552,
    -380,  -106,  -552,  1143,  -552,  -552,   311,  -552,    -6,  -188,
    -552,   712,  -552,  -552,  -552,    64,  -552,  -552,  -552,   268,
    -552,   336,   212,  -202,  -552,   -32,   453,  -199,   333,  -263,
    -552,  -552,  -384,  -552,  -552,  -552,  -531,  -552,   725,    19,
    -552,  -552,  -552,  -552,  -552,  -293,  -552,  -135,  -552,  -552,
    -249,  -552,  -552,  -278,   810,  -552,   123,  -551,  -552,  -552,
    -266,  -552,  -552,  -552,   299,  -552,   367,  -552,   231,  -552,
    -349,  -323,   149,  -259,   -52,   682,   531,   248,  -552,  -453,
      90,   276,   238,  -552,  -552,   341,  -552,  -450,  -552,  -552,
     313,  -552,  -552,  -552,   331,  -552,  -552,  -203,  -552,  -491,
     641,  -552,   350,  -552,   -27,   -31,  -552,  -552,  -552,  -552,
    -552,  -136,   -15,  -131,  -107,  -552,   416,   -40,  -552,  -552,
    -552,  -552,  -552,  -197,  -552,  -552,  -182,  -170,  -237,    41,
    -552,   917,   728,   580,    -7,  -552,   752,  -552,  -166,  -552,
    -289,   792,  -552,  1159,   101,     1,  -552,  2094,   -83,   335,
    -231,     3,   -28,  -552,  -552,  -552,  -552,  -102,    30,   -38,
     543,   862,  1146,  1404,  1662,  1777,  -552,  2035,   -49,  -267,
     384,  -552,  -552,  -552,  -552,  -552,  -552,  -552,  -552,  -552,
    -552,  -552,  -552,  -544,   244,  -552,  -552,   382,  -467,  -552,
    -552,  -552,   921,  -552,   -59,  -552,  -552,  -552,  -488,  -230,
       5,   -18,   183,    16,   -47,   470,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    11,    12,    13,   278,    14,    15,    16,    17,
      18,   300,    50,   226,   382,   228,   229,   230,   231,   232,
     233,   234,   423,   235,   236,   237,   585,   586,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   558,   665,
     729,   767,   768,   248,   389,   411,   383,   250,   592,   251,
     594,   252,   253,   254,   255,   256,   257,   258,   166,   343,
     168,   169,   170,   171,   172,   173,   368,   174,   175,   176,
     482,   483,   484,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   515,   646,   713,   756,   715,   757,   187,
     344,   188,   345,   346,   332,   629,   491,   492,   792,   493,
     494,   705,   495,   634,   496,   630,   191,   192,   193,   259,
     660,   661,   662,   194,   641,   642,   643,   336,   337,   644,
     260,   154,   155,   156,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   480,   141,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   465,   107,
     108,   142,   143,   309,   157,   110,   111,   261,   262,   263,
     264,   375,   196,   265,   198,   392,   393,   266,   364,   769,
     361,   158,   201,   498,   499,   500,   202,   296,   395,   396,
     384,   270,   385,   272,   273,   274,   275,   276,   119,   606,
     607,   455,   456,   680,   457,   682,   458,   459,   738,   460,
     684,   461,   677,   799,   806,   807,   814,   614,   686,    19,
      43,    54,    63,   148,   281,    84,    85,    86,    87,   282,
     462,   120,   121,   122,   123,    35,   301
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       2,    83,    32,    32,    34,    32,    32,    32,    32,   327,
     412,    82,   530,    89,   328,   153,   190,   379,   659,   210,
     277,    96,    82,   390,    89,    31,    33,    96,    36,    37,
      38,    39,   454,   581,    32,    44,   632,   249,   329,   535,
     537,   268,    88,   279,   595,   497,    95,    32,   589,   227,
      96,   292,    95,    88,   109,   640,   391,    64,   663,   442,
     325,   369,   520,   526,   527,   528,   529,   467,   468,   298,
     149,   200,   267,    20,   425,    95,   416,   522,   522,   522,
     522,   522,  -254,   290,   211,   211,   362,   167,   435,   524,
     524,   524,   524,   524,   308,   310,   698,   712,   711,   435,
     417,   435,    21,   436,  -254,  -254,   435,   435,   435,   418,
      22,    96,   210,   210,   436,   437,   436,   546,   547,   548,
     635,   436,   436,   436,   541,   687,   437,   335,   437,    32,
      23,   406,   293,   437,   437,   437,    95,   297,    27,   323,
      24,   505,    25,    52,   290,    29,   413,   372,   506,    30,
     363,    26,    64,   579,   580,   582,   583,   584,    53,    40,
     755,    93,    94,   144,    41,   593,   415,    42,   549,    93,
      94,   144,   277,   277,   359,   550,   339,   327,   327,   327,
    -345,   351,   474,   475,   476,    45,   327,   327,   277,   249,
     249,   477,   478,   659,  -345,  -344,   700,   701,   559,   497,
     497,   598,   388,   425,   760,   551,   329,   329,   329,  -344,
     414,   573,   575,   427,   391,   329,   329,   189,   297,    46,
     521,   521,   521,   521,   521,   394,   144,   144,   712,   441,
      47,   408,   532,   663,   190,   405,   339,   210,   277,    82,
      82,    89,    89,    96,   800,   801,   144,    48,   687,   645,
    -187,   444,   687,   687,  -187,   249,   391,   434,   640,   268,
    -185,   360,    96,    49,  -185,   324,    55,   227,    95,   771,
      88,    88,    27,   774,   775,   310,   433,   481,   297,    29,
     651,    32,   485,    30,    60,   501,    61,    95,   595,   200,
     267,   210,   589,   561,   562,   563,   564,   565,   566,   567,
     516,   410,   211,   211,    62,   167,   210,   210,   210,   210,
     210,   189,   210,   536,   536,   706,   502,  -298,   210,   371,
      65,  -298,   590,   297,   485,    66,   438,   210,   210,   210,
      67,   277,   293,   146,   -87,   360,  -289,   445,   -87,   446,
    -289,    68,   427,   338,   466,   466,   466,   543,   249,   811,
     277,   277,   277,   277,   277,   277,   277,   666,   390,   351,
     388,    69,    70,   277,   574,   574,   379,   427,   427,   427,
     427,   427,   587,   277,   147,   288,   299,   692,   542,   277,
     249,   688,    82,   576,    89,   144,   540,   703,   302,   283,
     249,   545,   568,   408,   408,   408,   408,   408,   408,   408,
     394,   596,   588,   338,   284,   391,   497,   144,  -255,   593,
     781,   391,   782,    88,   144,   144,   144,   285,   312,   286,
     287,   435,   408,   144,   144,   289,   762,   412,   303,    32,
    -255,  -255,   542,   -27,   -27,   189,   436,   304,   308,   501,
     501,   522,  -300,   333,   305,   545,  -300,   313,   437,   -29,
     -29,   -26,   -26,   524,   615,   354,   -27,   -27,   294,   210,
     647,   314,   295,   410,   410,   410,   410,   410,   410,   410,
     502,   502,   -29,   -29,   -26,   -26,  -104,   324,   523,   523,
     523,   523,   523,   210,   210,   534,   534,   326,   497,   189,
     210,   722,   410,   512,   331,   334,   352,  -178,   513,  -187,
    -104,  -344,   277,  -187,   525,   525,   525,   525,   525,  -104,
     353,   525,   525,   538,   324,   398,   189,   503,   355,   249,
    -121,   277,   277,   219,   356,   488,  -122,   666,   277,   374,
     489,   805,  -124,    27,   514,   365,   224,  -188,   249,   249,
      29,  -188,  -121,  -121,    30,   249,   373,   339,  -122,  -122,
     805,   669,   650,   327,  -124,  -124,   556,   588,   743,   394,
     394,   557,    27,   376,  -347,    27,   590,   430,    94,    29,
     144,   377,    29,    30,   378,   481,    30,   485,   501,   633,
      81,  -352,   329,   399,   521,   339,   501,   485,   501,   536,
     678,    34,   681,   683,   685,   513,    27,   514,   -88,   397,
     400,   401,   -88,    29,   112,   112,   419,    30,   420,   502,
     159,   203,   269,   112,   421,   428,   431,   502,   277,   502,
      51,   432,   587,   277,    56,    57,    58,    59,   639,   443,
      27,   514,  -186,   112,   112,   249,  -186,    29,   -87,  -189,
     294,    30,   -87,  -189,   501,   463,   501,   728,   469,   501,
     557,    96,   501,    27,   514,    93,    94,    32,   647,   466,
      29,  -185,   210,   470,    30,  -185,   408,   471,   112,   112,
     210,   503,   503,   472,   473,   502,    95,   502,   277,   739,
     502,   125,   189,   502,   615,    27,   514,   -89,   112,    81,
     486,   -89,    29,   487,   159,   249,    30,   504,   508,   507,
     509,   501,   510,   511,   347,   203,   518,   766,   519,   195,
     210,    27,   210,   532,   338,   539,    28,   694,    29,    32,
     277,   277,    30,     3,   341,   702,   551,   704,   501,   394,
     552,   570,   502,   553,   277,   554,   410,   249,   249,   347,
     555,   501,   772,   560,   597,   608,   599,   600,   627,   785,
     786,   249,   338,   501,   818,   601,   602,   603,   604,   502,
     605,   534,   609,   728,    82,   269,    89,   610,   488,   611,
     612,     4,   502,   693,     5,     6,   613,   616,     7,     8,
      32,     9,    10,   745,   502,   617,   618,   525,   747,   619,
     144,   748,   620,   623,   622,    88,   624,   716,   626,    32,
     625,   628,   195,   195,   636,   815,   635,   637,    27,  -205,
     503,    94,   648,   652,   649,    29,   653,   667,   503,    30,
     503,   668,   654,    81,   655,   656,   112,   112,   112,   203,
     269,   639,   670,   417,   112,   671,   672,   195,   673,   112,
     704,   112,   523,   403,   -45,   112,   112,   112,   112,   112,
     402,   674,   675,   403,   676,    71,   112,   112,   112,   689,
     758,   691,   695,   316,   696,   112,   112,   793,   525,   360,
     317,   318,   697,   319,   708,   709,   503,   699,   503,   707,
     633,   503,   717,   347,   503,   710,   320,   321,   404,   718,
     719,   488,   633,   723,   724,   517,   802,   726,   347,   347,
     347,   347,   347,   725,   347,   347,   347,   731,   732,   219,
     347,   488,   736,   737,   740,   741,   790,   749,   517,   347,
     347,   347,   224,   113,   113,   750,   751,   195,   716,   113,
     204,    27,   113,   503,    94,   759,   760,   752,    29,   335,
     517,   350,    30,   770,   763,   777,    81,  -177,   780,   409,
     773,    27,   113,   113,    94,   315,   776,   779,    29,   783,
     503,   784,    30,   787,   788,   795,    81,   789,   316,   797,
     798,   813,   517,   503,   426,   317,   318,   808,   319,   809,
     816,   195,   733,   810,   817,   503,   698,   113,   113,   812,
     531,   320,   321,   322,   765,   796,   195,   195,   195,   195,
     195,   440,   195,   730,   664,   734,   370,   113,   195,   754,
     794,   439,   112,   113,   163,   714,   490,   195,   195,   195,
     631,   531,   532,   204,   204,   791,   778,   533,   803,   212,
     213,    27,   214,    93,    94,   638,   746,   764,    29,   753,
     690,   744,    30,   311,   218,   163,   569,   570,   347,   621,
     761,   347,   571,   479,   464,   517,   517,   223,   204,   735,
     429,   819,    27,    92,    93,    94,   742,    78,   330,    29,
     225,    79,    80,    30,     0,   347,   347,    81,     0,   679,
       0,     0,   347,     0,     0,     0,     0,    27,    92,    93,
      94,     0,    78,     0,    29,     0,    79,    80,    30,   517,
     517,     0,    81,   426,     0,     0,     0,     0,     0,     0,
       0,   409,   409,   409,   409,   409,   409,   409,     0,     0,
       0,     0,     0,     0,     0,   572,   572,     0,   426,   426,
     426,   426,   426,     0,     0,     0,     0,     0,     0,     0,
     409,     0,     0,     0,     0,   113,   113,   113,   204,   195,
       0,     0,     0,   113,     0,     0,     0,     0,   113,    90,
     113,   112,     0,     0,   113,   113,   113,   113,   113,     0,
      91,     0,     0,   195,   195,   113,   113,   113,     0,     0,
     195,   347,     0,     0,   113,   113,     0,     0,     0,     0,
       0,   347,     0,     0,    27,    92,    93,    94,     0,    78,
       0,    29,   204,    79,    80,    30,     0,   114,   114,    81,
       0,     0,     0,   114,   205,   271,   114,   204,   204,   204,
     204,   204,   357,   204,   204,   204,     0,   197,     0,   204,
       0,     0,   112,     0,   112,   316,   114,   114,   204,   204,
     204,     0,   317,   318,     0,   319,     0,     0,     0,     0,
       0,   347,     0,   517,   347,     0,     0,     0,   320,   321,
     358,   658,   347,     0,     0,   212,   213,     0,   214,   517,
       0,   114,   114,     0,     0,     0,     0,     0,     0,     0,
     218,     0,   569,   570,     0,     0,     0,     0,   657,     0,
       0,   114,     0,   223,     0,     0,     0,   114,     0,     0,
       0,     0,   347,     0,   347,     0,   225,   348,   348,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     197,   197,   347,    27,    92,    93,    94,   638,    78,     0,
      29,   113,    79,    80,    30,     0,     0,     0,   386,     0,
       0,     0,   348,     0,     0,     0,     0,     0,     0,   294,
       0,   316,   195,   295,     0,   197,   720,   366,   317,   318,
     195,   319,   721,     0,     0,     0,     0,   204,   124,     0,
     204,     0,     0,   128,   320,   321,   387,     0,   306,     0,
     407,     0,   127,     0,   409,     0,   307,     0,     0,   128,
       0,     0,     0,     0,   204,   204,     0,     0,     0,     0,
     195,   204,   195,   165,     0,   424,     0,     0,     0,     0,
       0,     0,     0,    27,    92,    93,    94,     0,    78,     0,
      29,     0,    79,    80,    30,     0,     0,     0,    81,   114,
     114,   114,   205,   271,     0,     0,   658,   114,     0,     0,
       0,     0,   114,     0,   114,   197,     0,   151,   114,   114,
     114,   114,   114,     0,     0,     0,     0,     0,    91,   114,
     114,   114,     0,     0,     0,   115,   115,     0,   114,   114,
       0,   115,   206,     0,   115,     0,     0,     0,     0,     0,
     113,     0,    27,   152,    93,    94,   348,    78,     0,    29,
       0,    79,    80,    30,   115,   115,     0,    81,     0,   197,
     204,   348,   348,   348,   348,   348,     0,   348,   348,   348,
     204,     0,     0,   348,   197,   197,   197,   197,   197,     0,
     197,   544,   348,   348,   348,     0,   197,     0,     0,   115,
     115,     0,     0,     0,   424,   197,   197,   197,     0,     0,
       0,     0,   407,   407,   407,   407,   407,   407,   407,   115,
       0,   113,   447,   113,     0,   115,     0,     0,     0,   578,
     578,   578,   578,   578,     0,   206,   206,     0,     0,     0,
     204,   591,     0,   204,     0,   544,     0,     0,     0,   448,
     449,   204,     0,   450,   451,     0,     0,   452,     0,     0,
     453,     0,    27,     0,     0,     0,     0,    28,     0,    29,
     206,   212,   213,    30,   214,   215,   216,   217,     0,     0,
       0,     0,     0,     0,   124,   114,   218,   219,   220,   221,
       0,   204,     0,   204,   380,     0,     0,   341,   127,   223,
     224,     0,   381,     0,     0,   128,     0,     0,     0,     0,
       0,   204,   225,     0,     0,     0,     0,     0,     0,     0,
       0,   348,     0,     0,   348,     0,     0,     0,     0,    27,
      92,    93,    94,   164,    78,   165,    29,   197,    79,    80,
      30,     0,     0,     0,    81,     0,     0,     0,   348,   348,
       0,     0,     0,     0,     0,   348,     0,   115,   115,   115,
     206,   197,   197,     0,     0,   115,     0,     0,   197,     0,
     115,   291,   115,     0,     0,     0,   115,   115,   115,   115,
     115,     0,     0,     0,     0,     0,     0,   115,   115,   115,
       0,     0,     0,   116,   116,     0,   115,   115,     0,   116,
     207,     0,   116,     0,     0,     0,    27,    92,    93,    94,
       0,    78,     0,    29,   206,    79,    80,    30,     0,     0,
       0,    81,   116,   116,     0,     0,     0,     0,     0,   206,
     206,   206,   206,   206,   114,   206,   206,   206,     0,   124,
       0,   206,     0,   160,   366,     0,     0,     0,     0,   367,
     206,   206,   206,   127,   348,     0,     0,   116,   116,     0,
     128,    27,    92,    93,    94,     0,    78,   163,    29,     0,
      79,    80,    30,     0,     0,     0,    81,   116,     0,     0,
       0,     0,     0,   116,    27,   591,    93,    94,   164,     0,
     165,    29,     0,   207,   207,    30,     0,     0,     0,    81,
       0,     0,     0,     0,     0,   114,     0,   114,   117,   117,
       0,   124,     0,     0,   117,   208,   125,   117,     0,     0,
       0,   126,     0,     0,   348,   127,     0,   348,   207,     0,
       0,     0,   128,     0,     0,   348,     0,   117,   117,   124,
     197,     0,     0,   115,     0,     0,     0,     0,   197,   306,
       0,     0,     0,   127,     0,     0,    27,    92,    93,    94,
     128,    78,     0,    29,     0,    79,    80,    30,     0,     0,
       0,    81,   117,   117,     0,   348,     0,   348,     0,   206,
       0,     0,   206,     0,    27,    92,    93,    94,   197,    78,
     197,    29,   117,    79,    80,    30,     0,     0,   117,    81,
       0,     0,     0,     0,     0,     0,   206,   206,   208,   208,
       0,   150,     0,   206,     0,   116,   116,   116,   207,     0,
       0,   151,     0,   116,     0,     0,     0,     0,   116,     0,
     116,     0,    91,     0,   116,   116,   116,   116,   116,     0,
       0,     0,     0,   208,     0,   116,   116,   116,     0,     0,
       0,     0,     0,     0,   116,   116,    27,   152,    93,    94,
       0,    78,     0,    29,     0,    79,    80,    30,     0,     0,
       0,    81,   207,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   207,   207,   207,
     207,   207,   115,   207,   207,   207,     0,     0,     0,   207,
       0,     0,     0,     0,     0,     0,     0,     0,   207,   207,
     207,     0,   206,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     117,   117,   117,   208,     0,     0,     0,     0,   117,     0,
       0,     0,     0,   117,     0,   117,     0,     0,     0,   117,
     117,   117,   117,   117,     0,     0,     0,     0,     0,     0,
     117,   117,   117,   115,     0,   115,   118,   118,     0,   117,
     117,     0,   118,   209,     0,   118,     0,     0,     0,     0,
       0,     0,   206,     0,     0,   206,     0,   208,     0,     0,
       0,     0,     0,   206,     0,   118,   118,   150,     0,     0,
       0,   116,   208,   208,   208,   208,   208,    90,   208,   208,
     208,     0,     0,     0,   208,     0,     0,     0,    91,     0,
       0,     0,     0,   208,   208,   208,   145,     0,     0,     0,
     118,   118,   199,   206,   145,   206,     0,   207,     0,     0,
     207,     0,    27,    92,    93,    94,     0,    78,     0,    29,
     118,    79,    80,    30,     0,     0,   118,    81,     0,     0,
       0,     0,     0,     0,   207,   207,   349,   209,     0,   212,
     213,   207,   214,   215,   216,   217,     0,     0,     0,     0,
       0,     0,   124,     0,   218,   219,   220,   221,     0,   145,
     145,     0,   380,     0,     0,     0,   127,   223,   224,     0,
     381,     0,     0,   128,     0,     0,     0,     0,     0,   145,
     225,     0,     0,     0,     0,     0,   117,     0,     0,     0,
       0,     0,     0,     0,     0,   199,   199,    27,    92,    93,
      94,   164,    78,   165,    29,     0,    79,    80,    30,     0,
       0,     0,    81,     0,     0,     0,     0,     0,     0,     0,
     116,     0,   208,     0,     0,   208,     0,     0,     0,     0,
     199,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     207,     0,     0,     0,     0,     0,     0,     0,     0,   208,
     208,     0,     0,     0,     0,     0,   208,     0,   118,   118,
     118,   209,     0,     0,     0,     0,   118,     0,     0,     0,
       0,   118,     0,   118,     0,     0,     0,   118,   118,   118,
     118,   118,     0,     0,     0,     0,     0,     0,   118,   118,
     118,   116,     0,   116,     0,     0,     0,   118,   118,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     207,     0,     0,   207,     0,   209,     0,     0,   145,     0,
     199,   207,     0,     0,     0,     0,     0,     0,     0,     0,
     209,   209,   209,   209,   209,   117,   349,   209,   209,     0,
     145,     0,   209,     0,    91,     0,     0,   145,   145,   145,
       0,   349,   349,   349,     0,   208,   145,   145,     0,     0,
       0,   207,     0,   207,     0,     0,     0,     0,    27,    92,
      93,    94,     0,    78,   199,    29,     0,    79,    80,    30,
       0,     0,     0,    81,     0,     0,     0,     0,     0,   199,
     199,   199,   199,   199,     0,   199,     0,     0,     0,     0,
       0,   199,     0,     0,     0,     0,   117,     0,   117,   124,
     199,   199,   199,   160,   161,     0,     0,     0,     0,   340,
       0,     0,   341,   127,     0,   208,     0,   342,   208,     0,
     128,     0,     0,     0,     0,     0,   208,   163,     0,     0,
       0,     0,     0,     0,   118,     0,    71,     0,     0,     0,
       0,     0,     0,     0,    27,    92,    93,    94,   164,    78,
     165,    29,     0,    79,    80,    30,    72,    73,    74,    81,
      75,    76,     0,     0,     0,     0,   208,     0,   208,     0,
       0,     0,     0,   349,     0,     0,    27,    77,     0,     0,
       0,    78,     0,    29,     0,    79,    80,    30,     0,     0,
       0,    81,     0,   145,     0,     0,     0,   349,   209,     0,
       0,     0,     0,     0,   349,     0,   386,   212,   213,     0,
     214,   215,   216,   217,     0,     0,     0,   294,     0,   316,
     124,   295,   218,   219,   220,   221,   317,   318,     0,   319,
     222,     0,   199,   350,   127,   223,   224,     0,     0,     0,
       0,   128,   320,   321,   387,     0,     0,     0,   225,     0,
       0,     0,     0,     0,     0,     0,   199,   199,     0,     0,
       0,     0,     0,   199,     0,    27,   152,    93,    94,   164,
      78,   165,    29,     0,    79,    80,    30,     0,     0,     0,
      81,     0,     0,   118,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     386,   212,   213,   209,   214,   215,   216,   217,     0,     0,
       0,   294,     0,   316,   124,   295,   218,   219,   220,   221,
     317,   318,     0,   319,   380,     0,     0,   350,   127,   223,
     224,     0,     0,     0,     0,   128,   320,   321,   387,     0,
       0,     0,   225,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   118,     0,   118,     0,     0,    27,
      92,    93,    94,   164,    78,   165,    29,    71,    79,    80,
      30,     0,     0,     0,    81,     0,   349,     0,     0,     0,
     280,     0,     0,     0,   209,     0,     0,    72,    73,    74,
       0,    75,    76,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,    77,     0,
       0,     0,    78,   145,    29,     0,    79,    80,    30,     0,
       0,     0,    81,     0,   349,     0,   349,     0,     0,     0,
       0,     0,     0,     0,     0,   199,     0,     0,     0,     0,
     386,   212,   213,   199,   214,   215,   216,   217,     0,     0,
       0,   294,     0,   316,   124,   295,   218,   219,   220,   221,
     317,   318,     0,   319,   380,     0,     0,     0,   127,   223,
     224,     0,     0,     0,     0,   128,   320,   321,   387,     0,
       0,     0,   225,   199,     0,   199,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
      92,    93,    94,   164,    78,   165,    29,     0,    79,    80,
      30,     0,   212,   213,    81,   214,   215,   216,   217,     0,
       0,     0,     0,     0,     0,   124,     0,   218,   219,   220,
     221,     0,     0,     0,     0,   222,     0,     0,     0,   127,
     223,   224,     0,     0,     0,     0,   128,     0,     0,     0,
       0,     0,     0,   225,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,   152,    93,    94,   164,    78,   165,    29,     0,    79,
      80,    30,     0,   212,   213,    81,   214,   215,   216,   217,
       0,     0,     0,     0,     0,     0,   124,     0,   218,   219,
     220,   221,     0,     0,     0,     0,   380,     0,     0,     0,
     127,   223,   224,     0,     0,     0,     0,   128,     0,     0,
       0,     0,     0,     0,   225,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    27,    92,    93,    94,   164,    78,   165,    29,     0,
      79,    80,    30,     0,   212,   213,    81,   214,   215,   216,
     217,     0,     0,     0,     0,     0,     0,   124,     0,   218,
     219,   220,   221,     0,     0,     0,     0,   422,     0,     0,
       0,   127,   223,   224,     0,     0,     0,     0,   128,     0,
       0,     0,     0,     0,     0,   225,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,    92,    93,    94,   164,    78,   165,    29,
       0,    79,    80,    30,     0,   212,   213,    81,   214,   215,
     216,   217,     0,     0,     0,     0,     0,     0,   124,     0,
     218,   219,   220,   727,     0,     0,     0,     0,   380,     0,
       0,     0,   127,   223,   224,     0,     0,     0,     0,   128,
       0,     0,     0,     0,     0,     0,   225,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27,    92,    93,    94,   164,    78,   165,
      29,     0,    79,    80,    30,     0,   212,   213,    81,   214,
     215,   216,   217,     0,     0,     0,     0,     0,     0,   124,
       0,   218,   219,   569,   570,     0,     0,     0,     0,   577,
       0,     0,     0,   127,   223,   224,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   225,     0,   124,
       0,     0,     0,   160,   161,     0,     0,     0,     0,   162,
       0,     0,   350,   127,    27,    92,    93,    94,   164,    78,
     128,    29,     0,    79,    80,    30,     0,   163,     0,    81,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,   152,    93,    94,   164,    78,
     165,    29,   124,    79,    80,    30,   160,   161,     0,    81,
       0,     0,   340,     0,     0,   350,   127,     0,     0,     0,
       0,     0,     0,   128,     0,     0,     0,     0,     0,     0,
     163,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,    92,    93,
      94,   164,    78,   165,    29,   124,    79,    80,    30,   160,
     161,     0,    81,     0,     0,   340,     0,     0,     0,   127,
       0,     0,     0,   342,     0,     0,   128,     0,     0,     0,
       0,     0,     0,   163,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,    92,    93,    94,   164,    78,   165,    29,   124,    79,
      80,    30,   160,   161,     0,    81,     0,     0,   162,     0,
       0,     0,   127,     0,     0,     0,     0,     0,     0,   128,
       0,     0,     0,     0,     0,     0,   163,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27,   152,    93,    94,   164,    78,   165,
      29,   124,    79,    80,    30,   160,   161,     0,    81,     0,
       0,   340,     0,     0,     0,   127,     0,     0,     0,     0,
       0,     0,   128,     0,     0,     0,     0,     0,     0,   163,
       0,   447,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   804,     0,    27,    92,    93,    94,
     164,    78,   165,    29,     0,    79,    80,    30,   448,   449,
       0,    81,   450,   451,     0,     0,   452,     0,     0,   453,
       0,    27,     0,     0,     0,     0,    28,     0,    29,     0,
       0,     0,    30
};

static const yytype_int16 yycheck[] =
{
       0,    60,    20,    21,    22,    23,    24,    25,    26,   145,
     241,    60,   361,    60,   145,    67,    68,   220,   549,    68,
      69,    61,    71,   222,    71,    20,    21,    67,    23,    24,
      25,    26,   299,   417,    52,    35,   489,    69,   145,   362,
     363,    69,    60,    70,   428,   334,    61,    65,   428,    69,
      90,    91,    67,    71,    61,   505,   222,    52,   549,   289,
     143,   196,   355,   356,   357,   358,   359,   304,   305,   107,
      65,    68,    69,    27,   262,    90,    37,   355,   356,   357,
     358,   359,    13,    90,    68,    69,   188,    68,   285,   355,
     356,   357,   358,   359,   125,   126,    37,   648,    22,   296,
      61,   298,    27,   285,    35,    36,   303,   304,   305,    70,
      27,   151,   161,   162,   296,   285,   298,   376,   377,   378,
      61,   303,   304,   305,   373,   613,   296,    30,   298,   147,
      27,   237,    91,   303,   304,   305,   151,   107,    62,   138,
      27,    27,    27,    22,   151,    69,   248,   196,    34,    73,
     188,    27,   147,   416,   417,   418,   419,   420,    37,    13,
     711,    64,    65,    62,    13,   428,   249,    13,    27,    64,
      65,    70,   221,   222,   173,    34,   160,   313,   314,   315,
      11,   162,   313,   314,   315,    13,   322,   323,   237,   221,
     222,   322,   323,   724,    25,    11,    36,    37,   397,   488,
     489,   431,   222,   391,    12,    13,   313,   314,   315,    25,
     248,   413,   414,   262,   380,   322,   323,    68,   188,    13,
     355,   356,   357,   358,   359,   222,   125,   126,   779,   288,
      13,   237,    22,   724,   286,   234,   220,   286,   287,   288,
     289,   288,   289,   283,   788,   789,   145,    13,   736,   508,
      14,   291,   740,   741,    18,   287,   422,   284,   708,   287,
      14,    15,   302,    69,    18,    29,    36,   287,   283,   736,
     288,   289,    62,   740,   741,   306,   283,   326,   248,    69,
     539,   299,   331,    73,    28,   334,    13,   302,   672,   286,
     287,   340,   672,   399,   400,   401,   402,   403,   404,   405,
     352,   237,   286,   287,    13,   286,   355,   356,   357,   358,
     359,   162,   361,   362,   363,   638,   334,    14,   367,   196,
      13,    18,   428,   293,   373,    30,   285,   376,   377,   378,
      13,   380,   291,    35,    14,    15,    14,   296,    18,   298,
      18,    13,   391,   160,   303,   304,   305,   375,   380,   802,
     399,   400,   401,   402,   403,   404,   405,   556,   557,   340,
     380,    13,    13,   412,   413,   414,   569,   416,   417,   418,
     419,   420,   421,   422,    13,    11,    13,   626,   375,   428,
     412,   618,   431,   415,   431,   284,   367,   636,    41,    27,
     422,   375,   412,   399,   400,   401,   402,   403,   404,   405,
     397,   429,   422,   220,    27,   571,   695,   306,    13,   672,
     759,   577,   761,   431,   313,   314,   315,    27,   129,    27,
      27,   618,   428,   322,   323,    27,   719,   658,    27,   447,
      35,    36,   429,    12,    13,   286,   618,    27,   469,   488,
     489,   719,    14,   154,    27,   429,    18,    41,   618,    12,
      13,    12,    13,   719,   454,   166,    35,    36,    14,   508,
     512,     3,    18,   399,   400,   401,   402,   403,   404,   405,
     488,   489,    35,    36,    35,    36,    37,    29,   355,   356,
     357,   358,   359,   532,   533,   362,   363,    22,   777,   340,
     539,   657,   428,    22,    22,    11,    27,    12,    27,    14,
      61,    11,   551,    18,   355,   356,   357,   358,   359,    70,
      30,   362,   363,   364,    29,   226,   367,   334,    41,   551,
      13,   570,   571,    20,     3,    22,    13,   726,   577,    25,
      27,   798,    13,    62,    63,     6,    33,    14,   570,   571,
      69,    18,    35,    36,    73,   577,    22,   531,    35,    36,
     817,   571,   533,   689,    35,    36,    22,   577,   689,   556,
     557,    27,    62,    27,    25,    62,   672,   278,    65,    69,
     469,    27,    69,    73,    27,   624,    73,   626,   627,   489,
      77,    25,   689,    41,   719,   569,   635,   636,   637,   638,
     608,   609,   610,   611,   612,    27,    62,    63,    14,    27,
       3,     6,    18,    69,    61,    62,    37,    73,    70,   627,
      67,    68,    69,    70,    22,    11,    13,   635,   667,   637,
      41,    35,   671,   672,    45,    46,    47,    48,   505,    36,
      62,    63,    14,    90,    91,   667,    18,    69,    14,    14,
      14,    73,    18,    18,   693,    36,   695,   667,    13,   698,
      27,   691,   701,    62,    63,    64,    65,   675,   710,   618,
      69,    14,   711,    35,    73,    18,   672,    36,   125,   126,
     719,   488,   489,    36,    36,   693,   691,   695,   727,   679,
     698,    22,   533,   701,   684,    62,    63,    14,   145,    77,
      36,    18,    69,    36,   151,   727,    73,    34,    13,    35,
      35,   750,    36,    36,   161,   162,    61,   727,    36,    68,
     759,    62,   761,    22,   531,    27,    67,   627,    69,   737,
     769,   770,    73,     0,    30,   635,    13,   637,   777,   726,
      35,    22,   750,    36,   783,    36,   672,   769,   770,   196,
      36,   790,   737,    36,    36,    27,    36,    36,    11,   769,
     770,   783,   569,   802,   813,    36,    36,    36,    36,   777,
      36,   638,    27,   783,   813,   222,   813,    27,    22,    27,
      27,    48,   790,    27,    51,    52,    13,    30,    55,    56,
     798,    58,    59,   693,   802,    36,    13,   638,   698,    36,
     689,   701,    36,    35,    30,   813,    13,   648,    13,   817,
      35,    30,   161,   162,    22,   805,    61,    27,    62,    61,
     627,    65,    13,    36,    30,    69,    35,    13,   635,    73,
     637,    30,    36,    77,    36,    36,   283,   284,   285,   286,
     287,   708,    35,    61,   291,    13,    11,   196,    36,   296,
     750,   298,   719,     6,     6,   302,   303,   304,   305,   306,
       3,    30,    13,     6,    35,    22,   313,   314,   315,    11,
     711,    11,    13,    16,    35,   322,   323,   777,   719,    15,
      23,    24,    36,    26,    13,    35,   693,    36,   695,    36,
     790,   698,    36,   340,   701,    13,    39,    40,    41,    36,
      11,    22,   802,    36,    13,   352,    27,    13,   355,   356,
     357,   358,   359,    35,   361,   362,   363,    36,    11,    20,
     367,    22,    13,    13,    13,    13,    27,    35,   375,   376,
     377,   378,    33,    61,    62,    13,    36,   286,   779,    67,
      68,    62,    70,   750,    65,    13,    12,    34,    69,    30,
     397,    30,    73,    13,    34,    11,    77,    12,    35,   237,
      36,    62,    90,    91,    65,     3,    36,    13,    69,    13,
     777,    35,    73,    13,    13,    36,    77,    13,    16,    36,
      22,    11,   429,   790,   262,    23,    24,    36,    26,    36,
      35,   340,   671,    36,    13,   802,    37,   125,   126,    36,
      21,    39,    40,    41,   726,   783,   355,   356,   357,   358,
     359,   287,   361,   667,   551,   672,   196,   145,   367,   710,
     779,   286,   469,   151,    45,   648,   334,   376,   377,   378,
     489,    21,    22,   161,   162,   777,   750,    27,   790,     4,
       5,    62,     7,    64,    65,    66,   695,   724,    69,   708,
     624,   691,    73,   126,    19,    45,    21,    22,   505,   469,
     715,   508,    27,   325,   302,   512,   513,    32,   196,   675,
     268,   817,    62,    63,    64,    65,   684,    67,   147,    69,
      45,    71,    72,    73,    -1,   532,   533,    77,    -1,   609,
      -1,    -1,   539,    -1,    -1,    -1,    -1,    62,    63,    64,
      65,    -1,    67,    -1,    69,    -1,    71,    72,    73,   556,
     557,    -1,    77,   391,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   399,   400,   401,   402,   403,   404,   405,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   413,   414,    -1,   416,   417,
     418,   419,   420,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     428,    -1,    -1,    -1,    -1,   283,   284,   285,   286,   508,
      -1,    -1,    -1,   291,    -1,    -1,    -1,    -1,   296,    27,
     298,   618,    -1,    -1,   302,   303,   304,   305,   306,    -1,
      38,    -1,    -1,   532,   533,   313,   314,   315,    -1,    -1,
     539,   638,    -1,    -1,   322,   323,    -1,    -1,    -1,    -1,
      -1,   648,    -1,    -1,    62,    63,    64,    65,    -1,    67,
      -1,    69,   340,    71,    72,    73,    -1,    61,    62,    77,
      -1,    -1,    -1,    67,    68,    69,    70,   355,   356,   357,
     358,   359,     3,   361,   362,   363,    -1,    68,    -1,   367,
      -1,    -1,   689,    -1,   691,    16,    90,    91,   376,   377,
     378,    -1,    23,    24,    -1,    26,    -1,    -1,    -1,    -1,
      -1,   708,    -1,   710,   711,    -1,    -1,    -1,    39,    40,
      41,   549,   719,    -1,    -1,     4,     5,    -1,     7,   726,
      -1,   125,   126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    -1,
      -1,   145,    -1,    32,    -1,    -1,    -1,   151,    -1,    -1,
      -1,    -1,   759,    -1,   761,    -1,    45,   161,   162,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     161,   162,   779,    62,    63,    64,    65,    66,    67,    -1,
      69,   469,    71,    72,    73,    -1,    -1,    -1,     3,    -1,
      -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    14,
      -1,    16,   711,    18,    -1,   196,    21,    22,    23,    24,
     719,    26,    27,    -1,    -1,    -1,    -1,   505,    17,    -1,
     508,    -1,    -1,    38,    39,    40,    41,    -1,    27,    -1,
     237,    -1,    31,    -1,   672,    -1,    35,    -1,    -1,    38,
      -1,    -1,    -1,    -1,   532,   533,    -1,    -1,    -1,    -1,
     759,   539,   761,    68,    -1,   262,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    63,    64,    65,    -1,    67,    -1,
      69,    -1,    71,    72,    73,    -1,    -1,    -1,    77,   283,
     284,   285,   286,   287,    -1,    -1,   724,   291,    -1,    -1,
      -1,    -1,   296,    -1,   298,   286,    -1,    27,   302,   303,
     304,   305,   306,    -1,    -1,    -1,    -1,    -1,    38,   313,
     314,   315,    -1,    -1,    -1,    61,    62,    -1,   322,   323,
      -1,    67,    68,    -1,    70,    -1,    -1,    -1,    -1,    -1,
     618,    -1,    62,    63,    64,    65,   340,    67,    -1,    69,
      -1,    71,    72,    73,    90,    91,    -1,    77,    -1,   340,
     638,   355,   356,   357,   358,   359,    -1,   361,   362,   363,
     648,    -1,    -1,   367,   355,   356,   357,   358,   359,    -1,
     361,   375,   376,   377,   378,    -1,   367,    -1,    -1,   125,
     126,    -1,    -1,    -1,   391,   376,   377,   378,    -1,    -1,
      -1,    -1,   399,   400,   401,   402,   403,   404,   405,   145,
      -1,   689,    22,   691,    -1,   151,    -1,    -1,    -1,   416,
     417,   418,   419,   420,    -1,   161,   162,    -1,    -1,    -1,
     708,   428,    -1,   711,    -1,   429,    -1,    -1,    -1,    49,
      50,   719,    -1,    53,    54,    -1,    -1,    57,    -1,    -1,
      60,    -1,    62,    -1,    -1,    -1,    -1,    67,    -1,    69,
     196,     4,     5,    73,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,   469,    19,    20,    21,    22,
      -1,   759,    -1,   761,    27,    -1,    -1,    30,    31,    32,
      33,    -1,    35,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,   779,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   505,    -1,    -1,   508,    -1,    -1,    -1,    -1,    62,
      63,    64,    65,    66,    67,    68,    69,   508,    71,    72,
      73,    -1,    -1,    -1,    77,    -1,    -1,    -1,   532,   533,
      -1,    -1,    -1,    -1,    -1,   539,    -1,   283,   284,   285,
     286,   532,   533,    -1,    -1,   291,    -1,    -1,   539,    -1,
     296,    27,   298,    -1,    -1,    -1,   302,   303,   304,   305,
     306,    -1,    -1,    -1,    -1,    -1,    -1,   313,   314,   315,
      -1,    -1,    -1,    61,    62,    -1,   322,   323,    -1,    67,
      68,    -1,    70,    -1,    -1,    -1,    62,    63,    64,    65,
      -1,    67,    -1,    69,   340,    71,    72,    73,    -1,    -1,
      -1,    77,    90,    91,    -1,    -1,    -1,    -1,    -1,   355,
     356,   357,   358,   359,   618,   361,   362,   363,    -1,    17,
      -1,   367,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
     376,   377,   378,    31,   638,    -1,    -1,   125,   126,    -1,
      38,    62,    63,    64,    65,    -1,    67,    45,    69,    -1,
      71,    72,    73,    -1,    -1,    -1,    77,   145,    -1,    -1,
      -1,    -1,    -1,   151,    62,   672,    64,    65,    66,    -1,
      68,    69,    -1,   161,   162,    73,    -1,    -1,    -1,    77,
      -1,    -1,    -1,    -1,    -1,   689,    -1,   691,    61,    62,
      -1,    17,    -1,    -1,    67,    68,    22,    70,    -1,    -1,
      -1,    27,    -1,    -1,   708,    31,    -1,   711,   196,    -1,
      -1,    -1,    38,    -1,    -1,   719,    -1,    90,    91,    17,
     711,    -1,    -1,   469,    -1,    -1,    -1,    -1,   719,    27,
      -1,    -1,    -1,    31,    -1,    -1,    62,    63,    64,    65,
      38,    67,    -1,    69,    -1,    71,    72,    73,    -1,    -1,
      -1,    77,   125,   126,    -1,   759,    -1,   761,    -1,   505,
      -1,    -1,   508,    -1,    62,    63,    64,    65,   759,    67,
     761,    69,   145,    71,    72,    73,    -1,    -1,   151,    77,
      -1,    -1,    -1,    -1,    -1,    -1,   532,   533,   161,   162,
      -1,    17,    -1,   539,    -1,   283,   284,   285,   286,    -1,
      -1,    27,    -1,   291,    -1,    -1,    -1,    -1,   296,    -1,
     298,    -1,    38,    -1,   302,   303,   304,   305,   306,    -1,
      -1,    -1,    -1,   196,    -1,   313,   314,   315,    -1,    -1,
      -1,    -1,    -1,    -1,   322,   323,    62,    63,    64,    65,
      -1,    67,    -1,    69,    -1,    71,    72,    73,    -1,    -1,
      -1,    77,   340,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   355,   356,   357,
     358,   359,   618,   361,   362,   363,    -1,    -1,    -1,   367,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   376,   377,
     378,    -1,   638,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     283,   284,   285,   286,    -1,    -1,    -1,    -1,   291,    -1,
      -1,    -1,    -1,   296,    -1,   298,    -1,    -1,    -1,   302,
     303,   304,   305,   306,    -1,    -1,    -1,    -1,    -1,    -1,
     313,   314,   315,   689,    -1,   691,    61,    62,    -1,   322,
     323,    -1,    67,    68,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    -1,   708,    -1,    -1,   711,    -1,   340,    -1,    -1,
      -1,    -1,    -1,   719,    -1,    90,    91,    17,    -1,    -1,
      -1,   469,   355,   356,   357,   358,   359,    27,   361,   362,
     363,    -1,    -1,    -1,   367,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    -1,   376,   377,   378,    62,    -1,    -1,    -1,
     125,   126,    68,   759,    70,   761,    -1,   505,    -1,    -1,
     508,    -1,    62,    63,    64,    65,    -1,    67,    -1,    69,
     145,    71,    72,    73,    -1,    -1,   151,    77,    -1,    -1,
      -1,    -1,    -1,    -1,   532,   533,   161,   162,    -1,     4,
       5,   539,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    -1,    19,    20,    21,    22,    -1,   125,
     126,    -1,    27,    -1,    -1,    -1,    31,    32,    33,    -1,
      35,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,   145,
      45,    -1,    -1,    -1,    -1,    -1,   469,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   161,   162,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    71,    72,    73,    -1,
      -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     618,    -1,   505,    -1,    -1,   508,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     638,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   532,
     533,    -1,    -1,    -1,    -1,    -1,   539,    -1,   283,   284,
     285,   286,    -1,    -1,    -1,    -1,   291,    -1,    -1,    -1,
      -1,   296,    -1,   298,    -1,    -1,    -1,   302,   303,   304,
     305,   306,    -1,    -1,    -1,    -1,    -1,    -1,   313,   314,
     315,   689,    -1,   691,    -1,    -1,    -1,   322,   323,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     708,    -1,    -1,   711,    -1,   340,    -1,    -1,   284,    -1,
     286,   719,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     355,   356,   357,   358,   359,   618,   361,   362,   363,    -1,
     306,    -1,   367,    -1,    38,    -1,    -1,   313,   314,   315,
      -1,   376,   377,   378,    -1,   638,   322,   323,    -1,    -1,
      -1,   759,    -1,   761,    -1,    -1,    -1,    -1,    62,    63,
      64,    65,    -1,    67,   340,    69,    -1,    71,    72,    73,
      -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,   355,
     356,   357,   358,   359,    -1,   361,    -1,    -1,    -1,    -1,
      -1,   367,    -1,    -1,    -1,    -1,   689,    -1,   691,    17,
     376,   377,   378,    21,    22,    -1,    -1,    -1,    -1,    27,
      -1,    -1,    30,    31,    -1,   708,    -1,    35,   711,    -1,
      38,    -1,    -1,    -1,    -1,    -1,   719,    45,    -1,    -1,
      -1,    -1,    -1,    -1,   469,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    42,    43,    44,    77,
      46,    47,    -1,    -1,    -1,    -1,   759,    -1,   761,    -1,
      -1,    -1,    -1,   508,    -1,    -1,    62,    63,    -1,    -1,
      -1,    67,    -1,    69,    -1,    71,    72,    73,    -1,    -1,
      -1,    77,    -1,   469,    -1,    -1,    -1,   532,   533,    -1,
      -1,    -1,    -1,    -1,   539,    -1,     3,     4,     5,    -1,
       7,     8,     9,    10,    -1,    -1,    -1,    14,    -1,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    26,
      27,    -1,   508,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    -1,    -1,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   532,   533,    -1,    -1,
      -1,    -1,    -1,   539,    -1,    62,    63,    64,    65,    66,
      67,    68,    69,    -1,    71,    72,    73,    -1,    -1,    -1,
      77,    -1,    -1,   618,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,   638,     7,     8,     9,    10,    -1,    -1,
      -1,    14,    -1,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    26,    27,    -1,    -1,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    -1,
      -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   689,    -1,   691,    -1,    -1,    62,
      63,    64,    65,    66,    67,    68,    69,    22,    71,    72,
      73,    -1,    -1,    -1,    77,    -1,   711,    -1,    -1,    -1,
      35,    -1,    -1,    -1,   719,    -1,    -1,    42,    43,    44,
      -1,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    -1,
      -1,    -1,    67,   689,    69,    -1,    71,    72,    73,    -1,
      -1,    -1,    77,    -1,   759,    -1,   761,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   711,    -1,    -1,    -1,    -1,
       3,     4,     5,   719,     7,     8,     9,    10,    -1,    -1,
      -1,    14,    -1,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    26,    27,    -1,    -1,    -1,    31,    32,
      33,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    -1,
      -1,    -1,    45,   759,    -1,   761,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    71,    72,
      73,    -1,     4,     5,    77,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    -1,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    31,
      32,    33,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    71,
      72,    73,    -1,     4,     5,    77,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,
      31,    32,    33,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    63,    64,    65,    66,    67,    68,    69,    -1,
      71,    72,    73,    -1,     4,     5,    77,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    27,    -1,    -1,
      -1,    31,    32,    33,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    72,    73,    -1,     4,     5,    77,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    27,    -1,
      -1,    -1,    31,    32,    33,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    72,    73,    -1,     4,     5,    77,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      -1,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    27,
      -1,    -1,    -1,    31,    32,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    17,
      -1,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      -1,    -1,    30,    31,    62,    63,    64,    65,    66,    67,
      38,    69,    -1,    71,    72,    73,    -1,    45,    -1,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    63,    64,    65,    66,    67,
      68,    69,    17,    71,    72,    73,    21,    22,    -1,    77,
      -1,    -1,    27,    -1,    -1,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,
      65,    66,    67,    68,    69,    17,    71,    72,    73,    21,
      22,    -1,    77,    -1,    -1,    27,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    35,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    63,    64,    65,    66,    67,    68,    69,    17,    71,
      72,    73,    21,    22,    -1,    77,    -1,    -1,    27,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    63,    64,    65,    66,    67,    68,
      69,    17,    71,    72,    73,    21,    22,    -1,    77,    -1,
      -1,    27,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    -1,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    49,    50,
      -1,    77,    53,    54,    -1,    -1,    57,    -1,    -1,    60,
      -1,    62,    -1,    -1,    -1,    -1,    67,    -1,    69,    -1,
      -1,    -1,    73
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,    79,   304,     0,    48,    51,    52,    55,    56,    58,
      59,    80,    81,    82,    84,    85,    86,    87,    88,   287,
      27,    27,    27,    27,    27,    27,    27,    62,    67,    69,
      73,   298,   299,   298,   299,   303,   298,   298,   298,   298,
      13,    13,    13,   288,   304,    13,    13,    13,    13,    69,
      90,    90,    22,    37,   289,    36,    90,    90,    90,    90,
      28,    13,    13,   290,   298,    13,    30,    13,    13,    13,
      13,    22,    42,    43,    44,    46,    47,    63,    67,    71,
      72,    77,   266,   292,   293,   294,   295,   296,   299,   302,
      27,    38,    63,    64,    65,   210,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   227,   228,   232,
     233,   234,   258,   259,   260,   261,   262,   263,   265,   266,
     299,   300,   301,   302,    17,    22,    27,    31,    38,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   215,   229,   230,   242,   245,    35,    13,   291,   298,
      17,    27,    63,   172,   199,   200,   201,   232,   249,   258,
      21,    22,    27,    45,    66,    68,   136,   137,   138,   139,
     140,   141,   142,   143,   145,   146,   147,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   167,   169,   170,
     172,   184,   185,   186,   191,   198,   240,   241,   242,   245,
     249,   250,   254,   258,   259,   260,   261,   262,   263,   265,
     266,   301,     4,     5,     7,     8,     9,    10,    19,    20,
      21,    22,    27,    32,    33,    45,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   101,   102,   103,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   121,   123,
     125,   127,   129,   130,   131,   132,   133,   134,   135,   187,
     198,   235,   236,   237,   238,   241,   245,   249,   250,   258,
     259,   260,   261,   262,   263,   264,   265,   266,    83,   202,
      35,   292,   297,    27,    27,    27,    27,    27,    11,    27,
     232,    27,   215,   227,    14,    18,   255,   256,   257,    13,
      89,   304,    41,    27,    27,    27,    27,    35,   203,   231,
     203,   229,    89,    41,     3,     3,    16,    23,    24,    26,
      39,    40,    41,   243,    29,   246,    22,   209,   211,   212,
     290,    22,   172,    89,    11,    30,   195,   196,   300,   301,
      27,    30,    35,   137,   168,   170,   171,   258,   260,   265,
      30,   137,    27,    30,    89,    41,     3,     3,    41,   243,
      15,   248,   255,   257,   246,     6,    22,    27,   144,   145,
     152,   154,   266,    22,    25,   239,    27,    27,    27,   195,
      27,    35,    92,   124,   258,   260,     3,    41,    92,   122,
     125,   236,   243,   244,   249,   256,   257,    27,    89,    41,
       3,     6,     3,     6,    41,   243,    99,   101,   106,   109,
     113,   123,   248,   255,   257,   246,    37,    61,    70,    37,
      70,    22,    27,   100,   101,   107,   109,   266,    11,   239,
      89,    13,    35,   232,   202,   221,   224,   225,   227,   136,
      91,   292,   297,    36,   215,   227,   227,    22,    49,    50,
      53,    54,    57,    60,   267,   269,   270,   272,   274,   275,
     277,   279,   298,    36,   234,   226,   227,   226,   226,    13,
      35,    36,    36,    36,   211,   211,   211,   211,   211,   230,
     214,   266,   148,   149,   150,   266,    36,    36,    22,    27,
     173,   174,   175,   177,   178,   180,   182,   238,   251,   252,
     253,   266,   299,   300,    34,    27,    34,    35,    13,    35,
      36,    36,    22,    27,    63,   161,   172,   258,    61,    36,
     143,   145,   151,   154,   158,   170,   143,   143,   143,   143,
     168,    21,    22,    27,   154,   169,   266,   169,   170,    27,
     137,   148,   249,   250,   260,   301,   171,   171,   171,    27,
      34,    13,    35,    36,    36,    36,    22,    27,   116,   125,
      36,    99,    99,    99,    99,    99,    99,    99,    92,    21,
      22,    27,   109,   121,   266,   121,   123,    27,   101,   127,
     127,   130,   127,   127,   127,   104,   105,   266,    92,    98,
      99,   101,   126,   127,   128,   130,   250,    36,   297,    36,
      36,    36,    36,    36,    36,    36,   267,   268,    27,    27,
      27,    27,    27,    13,   285,   304,    30,    36,    13,    36,
      36,   231,    30,    35,    13,    35,    13,    11,    30,   173,
     183,   174,   177,   178,   181,    61,    22,    27,    66,   154,
     185,   192,   193,   194,   197,   171,   162,   172,    13,    30,
     137,   171,    36,    35,    36,    36,    36,    27,   109,   134,
     188,   189,   190,   197,   124,   117,   125,    13,    30,    92,
      35,    13,    11,    36,    30,    13,    35,   280,   299,   303,
     271,   299,   273,   299,   278,   299,   286,   296,   226,    11,
     214,    11,   148,    27,   178,    13,    35,    36,    37,    36,
      36,    37,   178,   148,   178,   179,   169,    36,    13,    35,
      13,    22,   155,   163,   164,   165,   170,    36,    36,    11,
      21,    27,   236,    36,    13,    35,    13,    22,    92,   118,
     119,    36,    11,   104,   126,   268,    13,    13,   276,   304,
      13,    13,   285,   211,   200,   178,   183,   178,   178,    35,
      13,    36,    34,   192,   162,   155,   164,   166,   170,    13,
      12,   247,   143,    34,   188,   117,    92,   119,   120,   247,
      13,   286,   298,    36,   286,   286,    36,    11,   179,    13,
      35,   168,   168,    13,    35,    92,    92,    13,    13,    13,
      27,   175,   176,   178,   166,    36,   120,    36,    22,   281,
     281,   281,    27,   180,    35,   267,   282,   283,    36,    36,
      36,   177,    36,    11,   284,   304,    35,    13,   292,   282
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,    78,    79,    79,    80,    80,    81,    81,    81,    81,
      81,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      89,    90,    90,    91,    91,    91,    92,    92,    92,    92,
      92,    92,    93,    93,    93,    94,    95,    95,    95,    96,
      96,    97,    97,    98,    98,    99,    99,    99,   100,   100,
     101,   101,   101,   101,   102,   103,   104,   104,   105,   106,
     106,   107,   108,   109,   109,   109,   110,   110,   111,   111,
     111,   111,   111,   112,   112,   113,   114,   115,   116,   116,
     117,   117,   118,   118,   119,   120,   120,   121,   121,   121,
     122,   122,   122,   122,   122,   123,   123,   124,   124,   125,
     125,   126,   126,   126,   127,   128,   129,   129,   129,   130,
     130,   131,   131,   132,   132,   133,   134,   135,   136,   136,
     136,   137,   137,   137,   137,   137,   137,   138,   138,   139,
     140,   140,   141,   141,   142,   142,   143,   143,   143,   144,
     144,   145,   145,   145,   145,   146,   147,   148,   148,   149,
     149,   150,   151,   151,   152,   153,   154,   154,   154,   155,
     155,   156,   157,   157,   157,   157,   158,   159,   159,   160,
     161,   161,   162,   162,   163,   163,   164,   165,   165,   166,
     166,   167,   168,   168,   168,   169,   169,   169,   169,   169,
     170,   170,   171,   171,   172,   172,   173,   173,   174,   174,
     174,   175,   176,   176,   176,   177,   177,   178,   178,   178,
     178,   178,   178,   179,   179,   180,   181,   181,   182,   183,
     183,   184,   185,   186,   187,   187,   188,   188,   189,   189,
     190,   191,   191,   192,   192,   193,   193,   194,   195,   195,
     196,   197,   198,   198,   198,   198,   199,   199,   200,   200,
     201,   202,   202,   203,   203,   203,   204,   204,   205,   206,
     206,   207,   207,   208,   208,   209,   209,   210,   211,   211,
     212,   212,   212,   213,   214,   214,   215,   215,   215,   216,
     217,   217,   218,   219,   220,   221,   221,   222,   222,   223,
     224,   224,   225,   225,   226,   226,   227,   227,   228,   228,
     228,   229,   229,   230,   230,   231,   231,   232,   232,   233,
     233,   234,   234,   234,   234,   235,   235,   235,   236,   236,
     237,   237,   237,   238,   238,   239,   240,   240,   241,   241,
     242,   242,   243,   243,   243,   243,   243,   243,   244,   244,
     245,   246,   247,   248,   249,   249,   250,   250,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   264,   264,   264,   264,   265,   265,   266,
     267,   267,   267,   267,   267,   268,   268,   269,   269,   270,
     271,   272,   273,   274,   274,   274,   275,   276,   276,   277,
     278,   279,   280,   281,   281,   282,   282,   283,   284,   284,
     285,   285,   286,   287,   288,   288,   288,   289,   289,   290,
     290,   291,   292,   292,   292,   293,   293,   293,   293,   293,
     293,   294,   295,   295,   295,   295,   295,   296,   296,   297,
     297,   298,   298,   299,   299,   299,   300,   301,   302,   302,
     302,   303,   304
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
       3,     1,     1,     1,     1,     3,     1,     8,     1,     3,
       1,     3,     1,     3,     3,     1,     3,     1,     1,     3,
       1,     1,     1,     1,     1,     2,     3,     1,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     6,     1,     3,     1,
       1,     3,     1,     1,     2,     3,     1,     1,     1,     1,
       4,     1,     1,     4,     1,     1,     3,     1,     4,     8,
       1,     3,     1,     3,     1,     3,     3,     1,     1,     1,
       3,     5,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     3,     1,     3,     3,     3,     1,     1,     1,     1,
       3,     6,     1,     3,     1,     1,     3,     1,     1,     1,
       4,     3,     1,     1,     3,     3,     3,     3,     3,     1,
       3,     3,     3,     3,     3,     6,     1,     3,     1,     1,
       1,     3,     6,     1,     3,     1,     1,     1,     1,     1,
       1,     2,     3,     3,     3,     3,     1,     1,     1,     1,
       6,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     3,     3,     3,     3,     2,     1,     3,     1,     1,
       1,     1,     3,     6,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     4,     1,     1,     1,
       1,     4,     1,     4,     1,     3,     1,     1,     1,     1,
       1,     3,     3,     2,     3,     1,     3,     1,     3,     1,
       3,     1,     2,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     3,     1,     1,     8,
       1,     8,     1,     1,     1,     1,     5,     2,     1,     5,
       1,     8,     1,     2,     3,     1,     3,     2,     2,     1,
       2,     1,     1,     6,     1,     2,     4,     3,     1,     1,
       3,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     2,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0
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
  case 2: /* TPTP_file: nothing  */
#line 231 "SyntaxBNF.y"
                    {}
#line 2907 "y.tab.c"
    break;

  case 3: /* TPTP_file: TPTP_file TPTP_input  */
#line 232 "SyntaxBNF.y"
                                           {}
#line 2913 "y.tab.c"
    break;

  case 4: /* TPTP_input: annotated_formula  */
#line 235 "SyntaxBNF.y"
                               {P_PRINT((yyval.pval));}
#line 2919 "y.tab.c"
    break;

  case 5: /* TPTP_input: include  */
#line 236 "SyntaxBNF.y"
                              {P_PRINT((yyval.pval));}
#line 2925 "y.tab.c"
    break;

  case 6: /* annotated_formula: thf_annotated  */
#line 239 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2931 "y.tab.c"
    break;

  case 7: /* annotated_formula: tff_annotated  */
#line 240 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2937 "y.tab.c"
    break;

  case 8: /* annotated_formula: tcf_annotated  */
#line 241 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2943 "y.tab.c"
    break;

  case 9: /* annotated_formula: fof_annotated  */
#line 242 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2949 "y.tab.c"
    break;

  case 10: /* annotated_formula: cnf_annotated  */
#line 243 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2955 "y.tab.c"
    break;

  case 11: /* annotated_formula: tpi_annotated  */
#line 244 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2961 "y.tab.c"
    break;

  case 12: /* tpi_annotated: _LIT_tpi LPAREN name COMMA formula_role COMMA tpi_formula annotations RPAREN PERIOD  */
#line 247 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("tpi_annotated", P_TOKEN("_LIT_tpi ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 2967 "y.tab.c"
    break;

  case 13: /* tpi_formula: fof_formula  */
#line 250 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("tpi_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2973 "y.tab.c"
    break;

  case 14: /* thf_annotated: _LIT_thf LPAREN name COMMA formula_role COMMA thf_formula annotations RPAREN PERIOD  */
#line 253 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("thf_annotated", P_TOKEN("_LIT_thf ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 2979 "y.tab.c"
    break;

  case 15: /* tff_annotated: _LIT_tff LPAREN name COMMA formula_role COMMA tff_formula annotations RPAREN PERIOD  */
#line 256 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("tff_annotated", P_TOKEN("_LIT_tff ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 2985 "y.tab.c"
    break;

  case 16: /* tcf_annotated: _LIT_tcf LPAREN name COMMA formula_role COMMA tcf_formula annotations RPAREN PERIOD  */
#line 259 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("tcf_annotated", P_TOKEN("_LIT_tcf ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 2991 "y.tab.c"
    break;

  case 17: /* fof_annotated: _LIT_fof LPAREN name COMMA formula_role COMMA fof_formula annotations RPAREN PERIOD  */
#line 262 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("fof_annotated", P_TOKEN("_LIT_fof ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 2997 "y.tab.c"
    break;

  case 18: /* cnf_annotated: _LIT_cnf LPAREN name COMMA formula_role COMMA cnf_formula annotations RPAREN PERIOD  */
#line 265 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("cnf_annotated", P_TOKEN("_LIT_cnf ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 3003 "y.tab.c"
    break;

  case 19: /* annotations: COMMA source optional_info  */
#line 268 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("annotations", P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3009 "y.tab.c"
    break;

  case 20: /* annotations: nothing  */
#line 269 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("annotations", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3015 "y.tab.c"
    break;

  case 21: /* formula_role: lower_word  */
#line 272 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("formula_role", P_TOKEN("lower_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3021 "y.tab.c"
    break;

  case 22: /* formula_role: lower_word MINUS general_term  */
#line 273 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("formula_role", P_TOKEN("lower_word ", (yyvsp[-2].ival)), P_TOKEN("MINUS ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3027 "y.tab.c"
    break;

  case 23: /* thf_formula: thf_logic_formula  */
#line 276 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3033 "y.tab.c"
    break;

  case 24: /* thf_formula: thf_atom_typing  */
#line 277 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3039 "y.tab.c"
    break;

  case 25: /* thf_formula: thf_subtype  */
#line 278 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("thf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3045 "y.tab.c"
    break;

  case 26: /* thf_logic_formula: thf_unitary_formula  */
#line 281 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3051 "y.tab.c"
    break;

  case 27: /* thf_logic_formula: thf_unary_formula  */
#line 282 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3057 "y.tab.c"
    break;

  case 28: /* thf_logic_formula: thf_binary_formula  */
#line 283 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3063 "y.tab.c"
    break;

  case 29: /* thf_logic_formula: thf_defined_infix  */
#line 284 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3069 "y.tab.c"
    break;

  case 30: /* thf_logic_formula: thf_definition  */
#line 285 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3075 "y.tab.c"
    break;

  case 31: /* thf_logic_formula: thf_sequent  */
#line 286 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3081 "y.tab.c"
    break;

  case 32: /* thf_binary_formula: thf_binary_nonassoc  */
#line 289 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3087 "y.tab.c"
    break;

  case 33: /* thf_binary_formula: thf_binary_assoc  */
#line 290 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3093 "y.tab.c"
    break;

  case 34: /* thf_binary_formula: thf_binary_type  */
#line 291 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3099 "y.tab.c"
    break;

  case 35: /* thf_binary_nonassoc: thf_unit_formula nonassoc_connective thf_unit_formula  */
#line 294 "SyntaxBNF.y"
                                                                            {(yyval.pval) = P_BUILD("thf_binary_nonassoc", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3105 "y.tab.c"
    break;

  case 36: /* thf_binary_assoc: thf_or_formula  */
#line 297 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("thf_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3111 "y.tab.c"
    break;

  case 37: /* thf_binary_assoc: thf_and_formula  */
#line 298 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3117 "y.tab.c"
    break;

  case 38: /* thf_binary_assoc: thf_apply_formula  */
#line 299 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3123 "y.tab.c"
    break;

  case 39: /* thf_or_formula: thf_unit_formula VLINE thf_unit_formula  */
#line 302 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("thf_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3129 "y.tab.c"
    break;

  case 40: /* thf_or_formula: thf_or_formula VLINE thf_unit_formula  */
#line 303 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("thf_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3135 "y.tab.c"
    break;

  case 41: /* thf_and_formula: thf_unit_formula AMPERSAND thf_unit_formula  */
#line 306 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3141 "y.tab.c"
    break;

  case 42: /* thf_and_formula: thf_and_formula AMPERSAND thf_unit_formula  */
#line 307 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3147 "y.tab.c"
    break;

  case 43: /* thf_apply_formula: thf_unit_formula AT_SIGN thf_unit_formula  */
#line 310 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_apply_formula", (yyvsp[-2].pval), P_TOKEN("AT_SIGN ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3153 "y.tab.c"
    break;

  case 44: /* thf_apply_formula: thf_apply_formula AT_SIGN thf_unit_formula  */
#line 311 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_apply_formula", (yyvsp[-2].pval), P_TOKEN("AT_SIGN ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3159 "y.tab.c"
    break;

  case 45: /* thf_unit_formula: thf_unitary_formula  */
#line 314 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3165 "y.tab.c"
    break;

  case 46: /* thf_unit_formula: thf_unary_formula  */
#line 315 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3171 "y.tab.c"
    break;

  case 47: /* thf_unit_formula: thf_defined_infix  */
#line 316 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3177 "y.tab.c"
    break;

  case 48: /* thf_preunit_formula: thf_unitary_formula  */
#line 319 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("thf_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3183 "y.tab.c"
    break;

  case 49: /* thf_preunit_formula: thf_prefix_unary  */
#line 320 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3189 "y.tab.c"
    break;

  case 50: /* thf_unitary_formula: thf_quantified_formula  */
#line 323 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("thf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3195 "y.tab.c"
    break;

  case 51: /* thf_unitary_formula: thf_atomic_formula  */
#line 324 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3201 "y.tab.c"
    break;

  case 52: /* thf_unitary_formula: variable  */
#line 325 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("thf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3207 "y.tab.c"
    break;

  case 53: /* thf_unitary_formula: LPAREN thf_logic_formula RPAREN  */
#line 326 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("thf_unitary_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3213 "y.tab.c"
    break;

  case 54: /* thf_quantified_formula: thf_quantification thf_unit_formula  */
#line 329 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("thf_quantified_formula", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3219 "y.tab.c"
    break;

  case 55: /* thf_quantification: thf_quantifier LBRKT thf_variable_list RBRKT COLON  */
#line 332 "SyntaxBNF.y"
                                                                        {(yyval.pval) = P_BUILD("thf_quantification", (yyvsp[-4].pval), P_TOKEN("LBRKT ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("RBRKT ", (yyvsp[-1].ival)), P_TOKEN("COLON ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL);}
#line 3225 "y.tab.c"
    break;

  case 56: /* thf_variable_list: thf_typed_variable  */
#line 335 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_variable_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3231 "y.tab.c"
    break;

  case 57: /* thf_variable_list: thf_typed_variable COMMA thf_variable_list  */
#line 336 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_variable_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3237 "y.tab.c"
    break;

  case 58: /* thf_typed_variable: variable COLON thf_top_level_type  */
#line 339 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("thf_typed_variable", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3243 "y.tab.c"
    break;

  case 59: /* thf_unary_formula: thf_prefix_unary  */
#line 342 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3249 "y.tab.c"
    break;

  case 60: /* thf_unary_formula: thf_infix_unary  */
#line 343 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3255 "y.tab.c"
    break;

  case 61: /* thf_prefix_unary: thf_unary_connective thf_preunit_formula  */
#line 346 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("thf_prefix_unary", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3261 "y.tab.c"
    break;

  case 62: /* thf_infix_unary: thf_unitary_term infix_inequality thf_unitary_term  */
#line 349 "SyntaxBNF.y"
                                                                     {(yyval.pval) = P_BUILD("thf_infix_unary", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3267 "y.tab.c"
    break;

  case 63: /* thf_atomic_formula: thf_plain_atomic  */
#line 352 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3273 "y.tab.c"
    break;

  case 64: /* thf_atomic_formula: thf_defined_atomic  */
#line 353 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3279 "y.tab.c"
    break;

  case 65: /* thf_atomic_formula: thf_system_atomic  */
#line 354 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3285 "y.tab.c"
    break;

  case 66: /* thf_plain_atomic: constant  */
#line 357 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("thf_plain_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3291 "y.tab.c"
    break;

  case 67: /* thf_plain_atomic: thf_tuple  */
#line 358 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_plain_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3297 "y.tab.c"
    break;

  case 68: /* thf_defined_atomic: defined_constant  */
#line 361 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3303 "y.tab.c"
    break;

  case 69: /* thf_defined_atomic: thf_defined_term  */
#line 362 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3309 "y.tab.c"
    break;

  case 70: /* thf_defined_atomic: LPAREN thf_conn_term RPAREN  */
#line 363 "SyntaxBNF.y"
                                                  {(yyval.pval) = P_BUILD("thf_defined_atomic", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3315 "y.tab.c"
    break;

  case 71: /* thf_defined_atomic: nhf_long_connective  */
#line 364 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3321 "y.tab.c"
    break;

  case 72: /* thf_defined_atomic: thf_let  */
#line 365 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3327 "y.tab.c"
    break;

  case 73: /* thf_defined_term: defined_term  */
#line 368 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3333 "y.tab.c"
    break;

  case 74: /* thf_defined_term: th1_defined_term  */
#line 369 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3339 "y.tab.c"
    break;

  case 75: /* thf_defined_infix: thf_unitary_term defined_infix_pred thf_unitary_term  */
#line 372 "SyntaxBNF.y"
                                                                         {(yyval.pval) = P_BUILD("thf_defined_infix", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3345 "y.tab.c"
    break;

  case 76: /* thf_system_atomic: system_constant  */
#line 375 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("thf_system_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3351 "y.tab.c"
    break;

  case 77: /* thf_let: _DLR_let LPAREN thf_let_types COMMA thf_let_defns COMMA thf_logic_formula RPAREN  */
#line 378 "SyntaxBNF.y"
                                                                                           {(yyval.pval) = P_BUILD("thf_let", P_TOKEN("_DLR_let ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 3357 "y.tab.c"
    break;

  case 78: /* thf_let_types: thf_atom_typing  */
#line 381 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_let_types", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3363 "y.tab.c"
    break;

  case 79: /* thf_let_types: LBRKT thf_atom_typing_list RBRKT  */
#line 382 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("thf_let_types", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3369 "y.tab.c"
    break;

  case 80: /* thf_atom_typing_list: thf_atom_typing  */
#line 385 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_atom_typing_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3375 "y.tab.c"
    break;

  case 81: /* thf_atom_typing_list: thf_atom_typing COMMA thf_atom_typing_list  */
#line 386 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_atom_typing_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3381 "y.tab.c"
    break;

  case 82: /* thf_let_defns: thf_let_defn  */
#line 389 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("thf_let_defns", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3387 "y.tab.c"
    break;

  case 83: /* thf_let_defns: LBRKT thf_let_defn_list RBRKT  */
#line 390 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("thf_let_defns", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3393 "y.tab.c"
    break;

  case 84: /* thf_let_defn: thf_logic_formula assignment thf_logic_formula  */
#line 393 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_let_defn", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3399 "y.tab.c"
    break;

  case 85: /* thf_let_defn_list: thf_let_defn  */
#line 396 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("thf_let_defn_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3405 "y.tab.c"
    break;

  case 86: /* thf_let_defn_list: thf_let_defn COMMA thf_let_defn_list  */
#line 397 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_let_defn_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3411 "y.tab.c"
    break;

  case 87: /* thf_unitary_term: thf_atomic_formula  */
#line 400 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3417 "y.tab.c"
    break;

  case 88: /* thf_unitary_term: variable  */
#line 401 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("thf_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3423 "y.tab.c"
    break;

  case 89: /* thf_unitary_term: LPAREN thf_logic_formula RPAREN  */
#line 402 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("thf_unitary_term", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3429 "y.tab.c"
    break;

  case 90: /* thf_conn_term: nonassoc_connective  */
#line 405 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3435 "y.tab.c"
    break;

  case 91: /* thf_conn_term: assoc_connective  */
#line 406 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3441 "y.tab.c"
    break;

  case 92: /* thf_conn_term: infix_equality  */
#line 407 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3447 "y.tab.c"
    break;

  case 93: /* thf_conn_term: infix_inequality  */
#line 408 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3453 "y.tab.c"
    break;

  case 94: /* thf_conn_term: thf_unary_connective  */
#line 409 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3459 "y.tab.c"
    break;

  case 95: /* thf_tuple: LBRKT RBRKT  */
#line 412 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("thf_tuple", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3465 "y.tab.c"
    break;

  case 96: /* thf_tuple: LBRKT thf_formula_list RBRKT  */
#line 413 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("thf_tuple", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3471 "y.tab.c"
    break;

  case 97: /* thf_formula_list: thf_logic_formula  */
#line 416 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_formula_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3477 "y.tab.c"
    break;

  case 98: /* thf_formula_list: thf_logic_formula COMMA thf_formula_list  */
#line 417 "SyntaxBNF.y"
                                                               {(yyval.pval) = P_BUILD("thf_formula_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3483 "y.tab.c"
    break;

  case 99: /* thf_atom_typing: typeable_atom COLON thf_top_level_type  */
#line 420 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("thf_atom_typing", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3489 "y.tab.c"
    break;

  case 100: /* thf_atom_typing: LPAREN thf_atom_typing RPAREN  */
#line 421 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("thf_atom_typing", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3495 "y.tab.c"
    break;

  case 101: /* thf_top_level_type: thf_unitary_type  */
#line 424 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3501 "y.tab.c"
    break;

  case 102: /* thf_top_level_type: thf_mapping_type  */
#line 425 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3507 "y.tab.c"
    break;

  case 103: /* thf_top_level_type: thf_apply_type  */
#line 426 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3513 "y.tab.c"
    break;

  case 104: /* thf_unitary_type: thf_unitary_formula  */
#line 429 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_unitary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3519 "y.tab.c"
    break;

  case 105: /* thf_apply_type: thf_apply_formula  */
#line 432 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("thf_apply_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3525 "y.tab.c"
    break;

  case 106: /* thf_binary_type: thf_mapping_type  */
#line 435 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("thf_binary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3531 "y.tab.c"
    break;

  case 107: /* thf_binary_type: thf_xprod_type  */
#line 436 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_binary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3537 "y.tab.c"
    break;

  case 108: /* thf_binary_type: thf_union_type  */
#line 437 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_binary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3543 "y.tab.c"
    break;

  case 109: /* thf_mapping_type: thf_unitary_type arrow thf_unitary_type  */
#line 440 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_mapping_type", (yyvsp[-2].pval), P_TOKEN("arrow ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3549 "y.tab.c"
    break;

  case 110: /* thf_mapping_type: thf_unitary_type arrow thf_mapping_type  */
#line 441 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_mapping_type", (yyvsp[-2].pval), P_TOKEN("arrow ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3555 "y.tab.c"
    break;

  case 111: /* thf_xprod_type: thf_unitary_type STAR thf_unitary_type  */
#line 444 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("thf_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3561 "y.tab.c"
    break;

  case 112: /* thf_xprod_type: thf_xprod_type STAR thf_unitary_type  */
#line 445 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3567 "y.tab.c"
    break;

  case 113: /* thf_union_type: thf_unitary_type plus thf_unitary_type  */
#line 448 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("thf_union_type", (yyvsp[-2].pval), P_TOKEN("plus ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3573 "y.tab.c"
    break;

  case 114: /* thf_union_type: thf_union_type plus thf_unitary_type  */
#line 449 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_union_type", (yyvsp[-2].pval), P_TOKEN("plus ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3579 "y.tab.c"
    break;

  case 115: /* thf_subtype: atomic_type subtype_sign atomic_type  */
#line 452 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("thf_subtype", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3585 "y.tab.c"
    break;

  case 116: /* thf_definition: thf_atomic_formula identical thf_logic_formula  */
#line 455 "SyntaxBNF.y"
                                                                {(yyval.pval) = P_BUILD("thf_definition", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3591 "y.tab.c"
    break;

  case 117: /* thf_sequent: thf_tuple gentzen_arrow thf_tuple  */
#line 458 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("thf_sequent", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3597 "y.tab.c"
    break;

  case 118: /* tff_formula: tff_logic_formula  */
#line 461 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3603 "y.tab.c"
    break;

  case 119: /* tff_formula: tff_atom_typing  */
#line 462 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3609 "y.tab.c"
    break;

  case 120: /* tff_formula: tff_subtype  */
#line 463 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tff_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3615 "y.tab.c"
    break;

  case 121: /* tff_logic_formula: tff_unitary_formula  */
#line 466 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3621 "y.tab.c"
    break;

  case 122: /* tff_logic_formula: tff_unary_formula  */
#line 467 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3627 "y.tab.c"
    break;

  case 123: /* tff_logic_formula: tff_binary_formula  */
#line 468 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3633 "y.tab.c"
    break;

  case 124: /* tff_logic_formula: tff_defined_infix  */
#line 469 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3639 "y.tab.c"
    break;

  case 125: /* tff_logic_formula: txf_definition  */
#line 470 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3645 "y.tab.c"
    break;

  case 126: /* tff_logic_formula: txf_sequent  */
#line 471 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3651 "y.tab.c"
    break;

  case 127: /* tff_binary_formula: tff_binary_nonassoc  */
#line 474 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3657 "y.tab.c"
    break;

  case 128: /* tff_binary_formula: tff_binary_assoc  */
#line 475 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3663 "y.tab.c"
    break;

  case 129: /* tff_binary_nonassoc: tff_unit_formula nonassoc_connective tff_unit_formula  */
#line 478 "SyntaxBNF.y"
                                                                            {(yyval.pval) = P_BUILD("tff_binary_nonassoc", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3669 "y.tab.c"
    break;

  case 130: /* tff_binary_assoc: tff_or_formula  */
#line 481 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tff_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3675 "y.tab.c"
    break;

  case 131: /* tff_binary_assoc: tff_and_formula  */
#line 482 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3681 "y.tab.c"
    break;

  case 132: /* tff_or_formula: tff_unit_formula VLINE tff_unit_formula  */
#line 485 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("tff_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3687 "y.tab.c"
    break;

  case 133: /* tff_or_formula: tff_or_formula VLINE tff_unit_formula  */
#line 486 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("tff_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3693 "y.tab.c"
    break;

  case 134: /* tff_and_formula: tff_unit_formula AMPERSAND tff_unit_formula  */
#line 489 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("tff_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3699 "y.tab.c"
    break;

  case 135: /* tff_and_formula: tff_and_formula AMPERSAND tff_unit_formula  */
#line 490 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("tff_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3705 "y.tab.c"
    break;

  case 136: /* tff_unit_formula: tff_unitary_formula  */
#line 493 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3711 "y.tab.c"
    break;

  case 137: /* tff_unit_formula: tff_unary_formula  */
#line 494 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3717 "y.tab.c"
    break;

  case 138: /* tff_unit_formula: tff_defined_infix  */
#line 495 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3723 "y.tab.c"
    break;

  case 139: /* tff_preunit_formula: tff_unitary_formula  */
#line 498 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3729 "y.tab.c"
    break;

  case 140: /* tff_preunit_formula: tff_prefix_unary  */
#line 499 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3735 "y.tab.c"
    break;

  case 141: /* tff_unitary_formula: tff_quantified_formula  */
#line 502 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("tff_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3741 "y.tab.c"
    break;

  case 142: /* tff_unitary_formula: tff_atomic_formula  */
#line 503 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3747 "y.tab.c"
    break;

  case 143: /* tff_unitary_formula: txf_unitary_formula  */
#line 504 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3753 "y.tab.c"
    break;

  case 144: /* tff_unitary_formula: LPAREN tff_logic_formula RPAREN  */
#line 505 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("tff_unitary_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3759 "y.tab.c"
    break;

  case 145: /* txf_unitary_formula: variable  */
#line 508 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("txf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3765 "y.tab.c"
    break;

  case 146: /* tff_quantified_formula: tff_quantifier LBRKT tff_variable_list RBRKT COLON tff_unit_formula  */
#line 511 "SyntaxBNF.y"
                                                                                             {(yyval.pval) = P_BUILD("tff_quantified_formula", (yyvsp[-5].pval), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 3771 "y.tab.c"
    break;

  case 147: /* tff_variable_list: tff_variable  */
#line 514 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("tff_variable_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3777 "y.tab.c"
    break;

  case 148: /* tff_variable_list: tff_variable COMMA tff_variable_list  */
#line 515 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("tff_variable_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3783 "y.tab.c"
    break;

  case 149: /* tff_variable: tff_typed_variable  */
#line 518 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tff_variable", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3789 "y.tab.c"
    break;

  case 150: /* tff_variable: variable  */
#line 519 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_variable", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3795 "y.tab.c"
    break;

  case 151: /* tff_typed_variable: variable COLON tff_atomic_type  */
#line 522 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("tff_typed_variable", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3801 "y.tab.c"
    break;

  case 152: /* tff_unary_formula: tff_prefix_unary  */
#line 525 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3807 "y.tab.c"
    break;

  case 153: /* tff_unary_formula: tff_infix_unary  */
#line 526 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3813 "y.tab.c"
    break;

  case 154: /* tff_prefix_unary: tff_unary_connective tff_preunit_formula  */
#line 529 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("tff_prefix_unary", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3819 "y.tab.c"
    break;

  case 155: /* tff_infix_unary: tff_unitary_term infix_inequality tff_unitary_term  */
#line 532 "SyntaxBNF.y"
                                                                     {(yyval.pval) = P_BUILD("tff_infix_unary", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3825 "y.tab.c"
    break;

  case 156: /* tff_atomic_formula: tff_plain_atomic  */
#line 535 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3831 "y.tab.c"
    break;

  case 157: /* tff_atomic_formula: tff_defined_atomic  */
#line 536 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3837 "y.tab.c"
    break;

  case 158: /* tff_atomic_formula: tff_system_atomic  */
#line 537 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3843 "y.tab.c"
    break;

  case 159: /* tff_plain_atomic: constant  */
#line 540 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("tff_plain_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3849 "y.tab.c"
    break;

  case 160: /* tff_plain_atomic: functor LPAREN tff_arguments RPAREN  */
#line 541 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("tff_plain_atomic", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3855 "y.tab.c"
    break;

  case 161: /* tff_defined_atomic: tff_defined_plain  */
#line 544 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3861 "y.tab.c"
    break;

  case 162: /* tff_defined_plain: defined_constant  */
#line 547 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3867 "y.tab.c"
    break;

  case 163: /* tff_defined_plain: defined_functor LPAREN tff_arguments RPAREN  */
#line 548 "SyntaxBNF.y"
                                                                  {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3873 "y.tab.c"
    break;

  case 164: /* tff_defined_plain: nxf_atom  */
#line 549 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3879 "y.tab.c"
    break;

  case 165: /* tff_defined_plain: txf_let  */
#line 550 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3885 "y.tab.c"
    break;

  case 166: /* tff_defined_infix: tff_unitary_term defined_infix_pred tff_unitary_term  */
#line 553 "SyntaxBNF.y"
                                                                         {(yyval.pval) = P_BUILD("tff_defined_infix", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3891 "y.tab.c"
    break;

  case 167: /* tff_system_atomic: system_constant  */
#line 556 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("tff_system_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3897 "y.tab.c"
    break;

  case 168: /* tff_system_atomic: system_functor LPAREN tff_arguments RPAREN  */
#line 557 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("tff_system_atomic", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3903 "y.tab.c"
    break;

  case 169: /* txf_let: _DLR_let LPAREN txf_let_types COMMA txf_let_defns COMMA tff_term RPAREN  */
#line 560 "SyntaxBNF.y"
                                                                                  {(yyval.pval) = P_BUILD("txf_let", P_TOKEN("_DLR_let ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 3909 "y.tab.c"
    break;

  case 170: /* txf_let_types: tff_atom_typing  */
#line 563 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("txf_let_types", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3915 "y.tab.c"
    break;

  case 171: /* txf_let_types: LBRKT tff_atom_typing_list RBRKT  */
#line 564 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("txf_let_types", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3921 "y.tab.c"
    break;

  case 172: /* tff_atom_typing_list: tff_atom_typing  */
#line 567 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_atom_typing_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3927 "y.tab.c"
    break;

  case 173: /* tff_atom_typing_list: tff_atom_typing COMMA tff_atom_typing_list  */
#line 568 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("tff_atom_typing_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3933 "y.tab.c"
    break;

  case 174: /* txf_let_defns: txf_let_defn  */
#line 571 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("txf_let_defns", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3939 "y.tab.c"
    break;

  case 175: /* txf_let_defns: LBRKT txf_let_defn_list RBRKT  */
#line 572 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("txf_let_defns", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3945 "y.tab.c"
    break;

  case 176: /* txf_let_defn: txf_let_LHS assignment tff_term  */
#line 575 "SyntaxBNF.y"
                                               {(yyval.pval) = P_BUILD("txf_let_defn", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3951 "y.tab.c"
    break;

  case 177: /* txf_let_LHS: tff_plain_atomic  */
#line 578 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("txf_let_LHS", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3957 "y.tab.c"
    break;

  case 178: /* txf_let_LHS: txf_tuple  */
#line 579 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("txf_let_LHS", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3963 "y.tab.c"
    break;

  case 179: /* txf_let_defn_list: txf_let_defn  */
#line 582 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("txf_let_defn_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3969 "y.tab.c"
    break;

  case 180: /* txf_let_defn_list: txf_let_defn COMMA txf_let_defn_list  */
#line 583 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("txf_let_defn_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3975 "y.tab.c"
    break;

  case 181: /* nxf_atom: nxf_long_connective AT_SIGN LPAREN tff_arguments RPAREN  */
#line 586 "SyntaxBNF.y"
                                                                   {(yyval.pval) = P_BUILD("nxf_atom", (yyvsp[-4].pval), P_TOKEN("AT_SIGN ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL);}
#line 3981 "y.tab.c"
    break;

  case 182: /* tff_term: tff_logic_formula  */
#line 589 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("tff_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3987 "y.tab.c"
    break;

  case 183: /* tff_term: defined_term  */
#line 590 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3993 "y.tab.c"
    break;

  case 184: /* tff_term: txf_tuple  */
#line 591 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3999 "y.tab.c"
    break;

  case 185: /* tff_unitary_term: tff_atomic_formula  */
#line 594 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4005 "y.tab.c"
    break;

  case 186: /* tff_unitary_term: defined_term  */
#line 595 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4011 "y.tab.c"
    break;

  case 187: /* tff_unitary_term: txf_tuple  */
#line 596 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4017 "y.tab.c"
    break;

  case 188: /* tff_unitary_term: variable  */
#line 597 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4023 "y.tab.c"
    break;

  case 189: /* tff_unitary_term: LPAREN tff_logic_formula RPAREN  */
#line 598 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("tff_unitary_term", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4029 "y.tab.c"
    break;

  case 190: /* txf_tuple: LBRKT RBRKT  */
#line 601 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("txf_tuple", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4035 "y.tab.c"
    break;

  case 191: /* txf_tuple: LBRKT tff_arguments RBRKT  */
#line 602 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("txf_tuple", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4041 "y.tab.c"
    break;

  case 192: /* tff_arguments: tff_term  */
#line 605 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_arguments", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4047 "y.tab.c"
    break;

  case 193: /* tff_arguments: tff_term COMMA tff_arguments  */
#line 606 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("tff_arguments", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4053 "y.tab.c"
    break;

  case 194: /* tff_atom_typing: typeable_atom COLON tff_top_level_type  */
#line 609 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("tff_atom_typing", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4059 "y.tab.c"
    break;

  case 195: /* tff_atom_typing: LPAREN tff_atom_typing RPAREN  */
#line 610 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("tff_atom_typing", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4065 "y.tab.c"
    break;

  case 196: /* tff_top_level_type: tff_atomic_type  */
#line 613 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4071 "y.tab.c"
    break;

  case 197: /* tff_top_level_type: tff_non_atomic_type  */
#line 614 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4077 "y.tab.c"
    break;

  case 198: /* tff_non_atomic_type: tff_mapping_type  */
#line 617 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_non_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4083 "y.tab.c"
    break;

  case 199: /* tff_non_atomic_type: tf1_quantified_type  */
#line 618 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_non_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4089 "y.tab.c"
    break;

  case 200: /* tff_non_atomic_type: LPAREN tff_non_atomic_type RPAREN  */
#line 619 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("tff_non_atomic_type", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4095 "y.tab.c"
    break;

  case 201: /* tf1_quantified_type: type_quantifier LBRKT tff_variable_list RBRKT COLON tff_monotype  */
#line 622 "SyntaxBNF.y"
                                                                                       {(yyval.pval) = P_BUILD("tf1_quantified_type", (yyvsp[-5].pval), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 4101 "y.tab.c"
    break;

  case 202: /* tff_monotype: tff_atomic_type  */
#line 625 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_monotype", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4107 "y.tab.c"
    break;

  case 203: /* tff_monotype: LPAREN tff_mapping_type RPAREN  */
#line 626 "SyntaxBNF.y"
                                                     {(yyval.pval) = P_BUILD("tff_monotype", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4113 "y.tab.c"
    break;

  case 204: /* tff_monotype: tf1_quantified_type  */
#line 627 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_monotype", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4119 "y.tab.c"
    break;

  case 205: /* tff_unitary_type: tff_atomic_type  */
#line 630 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_unitary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4125 "y.tab.c"
    break;

  case 206: /* tff_unitary_type: LPAREN tff_xprod_type RPAREN  */
#line 631 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("tff_unitary_type", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4131 "y.tab.c"
    break;

  case 207: /* tff_atomic_type: type_constant  */
#line 634 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4137 "y.tab.c"
    break;

  case 208: /* tff_atomic_type: defined_type  */
#line 635 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4143 "y.tab.c"
    break;

  case 209: /* tff_atomic_type: variable  */
#line 636 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4149 "y.tab.c"
    break;

  case 210: /* tff_atomic_type: type_functor LPAREN tff_type_arguments RPAREN  */
#line 637 "SyntaxBNF.y"
                                                                    {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4155 "y.tab.c"
    break;

  case 211: /* tff_atomic_type: LPAREN tff_atomic_type RPAREN  */
#line 638 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("tff_atomic_type", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4161 "y.tab.c"
    break;

  case 212: /* tff_atomic_type: txf_tuple_type  */
#line 639 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4167 "y.tab.c"
    break;

  case 213: /* tff_type_arguments: tff_atomic_type  */
#line 642 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_type_arguments", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4173 "y.tab.c"
    break;

  case 214: /* tff_type_arguments: tff_atomic_type COMMA tff_type_arguments  */
#line 643 "SyntaxBNF.y"
                                                               {(yyval.pval) = P_BUILD("tff_type_arguments", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4179 "y.tab.c"
    break;

  case 215: /* tff_mapping_type: tff_unitary_type arrow tff_atomic_type  */
#line 646 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("tff_mapping_type", (yyvsp[-2].pval), P_TOKEN("arrow ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4185 "y.tab.c"
    break;

  case 216: /* tff_xprod_type: tff_unitary_type STAR tff_atomic_type  */
#line 649 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("tff_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4191 "y.tab.c"
    break;

  case 217: /* tff_xprod_type: tff_xprod_type STAR tff_atomic_type  */
#line 650 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("tff_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4197 "y.tab.c"
    break;

  case 218: /* txf_tuple_type: LBRKT tff_type_list RBRKT  */
#line 653 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("txf_tuple_type", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4203 "y.tab.c"
    break;

  case 219: /* tff_type_list: tff_top_level_type  */
#line 656 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_type_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4209 "y.tab.c"
    break;

  case 220: /* tff_type_list: tff_top_level_type COMMA tff_type_list  */
#line 657 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("tff_type_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4215 "y.tab.c"
    break;

  case 221: /* tff_subtype: atomic_type subtype_sign atomic_type  */
#line 660 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("tff_subtype", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4221 "y.tab.c"
    break;

  case 222: /* txf_definition: tff_atomic_formula identical tff_term  */
#line 663 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("txf_definition", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4227 "y.tab.c"
    break;

  case 223: /* txf_sequent: txf_tuple gentzen_arrow txf_tuple  */
#line 666 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("txf_sequent", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4233 "y.tab.c"
    break;

  case 224: /* nhf_long_connective: LBRACE ntf_connective_name RBRACE  */
#line 669 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("nhf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4239 "y.tab.c"
    break;

  case 225: /* nhf_long_connective: LBRACE ntf_connective_name LPAREN nhf_parameter_list RPAREN RBRACE  */
#line 670 "SyntaxBNF.y"
                                                                                         {(yyval.pval) = P_BUILD("nhf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-5].ival)), (yyvsp[-4].pval), P_TOKEN("LPAREN ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL);}
#line 4245 "y.tab.c"
    break;

  case 226: /* nhf_parameter_list: nhf_parameter  */
#line 673 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("nhf_parameter_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4251 "y.tab.c"
    break;

  case 227: /* nhf_parameter_list: nhf_parameter COMMA nhf_parameter_list  */
#line 674 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("nhf_parameter_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4257 "y.tab.c"
    break;

  case 228: /* nhf_parameter: ntf_index  */
#line 677 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("nhf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4263 "y.tab.c"
    break;

  case 229: /* nhf_parameter: nhf_key_pair  */
#line 678 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("nhf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4269 "y.tab.c"
    break;

  case 230: /* nhf_key_pair: thf_definition  */
#line 681 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("nhf_key_pair", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4275 "y.tab.c"
    break;

  case 231: /* nxf_long_connective: LBRACE ntf_connective_name RBRACE  */
#line 684 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("nxf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4281 "y.tab.c"
    break;

  case 232: /* nxf_long_connective: LBRACE ntf_connective_name LPAREN nxf_parameter_list RPAREN RBRACE  */
#line 685 "SyntaxBNF.y"
                                                                                         {(yyval.pval) = P_BUILD("nxf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-5].ival)), (yyvsp[-4].pval), P_TOKEN("LPAREN ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL);}
#line 4287 "y.tab.c"
    break;

  case 233: /* nxf_parameter_list: nxf_parameter  */
#line 688 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("nxf_parameter_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4293 "y.tab.c"
    break;

  case 234: /* nxf_parameter_list: nxf_parameter COMMA nxf_parameter_list  */
#line 689 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("nxf_parameter_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4299 "y.tab.c"
    break;

  case 235: /* nxf_parameter: ntf_index  */
#line 692 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("nxf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4305 "y.tab.c"
    break;

  case 236: /* nxf_parameter: nxf_key_pair  */
#line 693 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("nxf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4311 "y.tab.c"
    break;

  case 237: /* nxf_key_pair: txf_definition  */
#line 696 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("nxf_key_pair", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4317 "y.tab.c"
    break;

  case 238: /* ntf_connective_name: ntf_defined_connective  */
#line 699 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("ntf_connective_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4323 "y.tab.c"
    break;

  case 239: /* ntf_connective_name: atomic_system_word  */
#line 700 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("ntf_connective_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4329 "y.tab.c"
    break;

  case 240: /* ntf_defined_connective: atomic_defined_word  */
#line 703 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("ntf_defined_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4335 "y.tab.c"
    break;

  case 241: /* ntf_index: hash tff_unitary_term  */
#line 706 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("ntf_index", P_TOKEN("hash ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4341 "y.tab.c"
    break;

  case 242: /* ntf_short_connective: LBRKT PERIOD RBRKT  */
#line 709 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4347 "y.tab.c"
    break;

  case 243: /* ntf_short_connective: less_sign PERIOD arrow  */
#line 710 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("less_sign ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("arrow ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4353 "y.tab.c"
    break;

  case 244: /* ntf_short_connective: LBRACE PERIOD RBRACE  */
#line 711 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("LBRACE ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4359 "y.tab.c"
    break;

  case 245: /* ntf_short_connective: LPAREN PERIOD RPAREN  */
#line 712 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4365 "y.tab.c"
    break;

  case 246: /* tcf_formula: tcf_logic_formula  */
#line 715 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tcf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4371 "y.tab.c"
    break;

  case 247: /* tcf_formula: tff_atom_typing  */
#line 716 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tcf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4377 "y.tab.c"
    break;

  case 248: /* tcf_logic_formula: tcf_quantified_formula  */
#line 719 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("tcf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4383 "y.tab.c"
    break;

  case 249: /* tcf_logic_formula: cnf_formula  */
#line 720 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tcf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4389 "y.tab.c"
    break;

  case 250: /* tcf_quantified_formula: EXCLAMATION LBRKT tff_variable_list RBRKT COLON tcf_logic_formula  */
#line 723 "SyntaxBNF.y"
                                                                                           {(yyval.pval) = P_BUILD("tcf_quantified_formula", P_TOKEN("EXCLAMATION ", (yyvsp[-5].ival)), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 4395 "y.tab.c"
    break;

  case 251: /* fof_formula: fof_logic_formula  */
#line 726 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("fof_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4401 "y.tab.c"
    break;

  case 252: /* fof_formula: fof_sequent  */
#line 727 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("fof_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4407 "y.tab.c"
    break;

  case 253: /* fof_logic_formula: fof_binary_formula  */
#line 730 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("fof_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4413 "y.tab.c"
    break;

  case 254: /* fof_logic_formula: fof_unary_formula  */
#line 731 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("fof_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4419 "y.tab.c"
    break;

  case 255: /* fof_logic_formula: fof_unitary_formula  */
#line 732 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("fof_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4425 "y.tab.c"
    break;

  case 256: /* fof_binary_formula: fof_binary_nonassoc  */
#line 735 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("fof_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4431 "y.tab.c"
    break;

  case 257: /* fof_binary_formula: fof_binary_assoc  */
#line 736 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("fof_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4437 "y.tab.c"
    break;

  case 258: /* fof_binary_nonassoc: fof_unit_formula nonassoc_connective fof_unit_formula  */
#line 739 "SyntaxBNF.y"
                                                                            {(yyval.pval) = P_BUILD("fof_binary_nonassoc", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4443 "y.tab.c"
    break;

  case 259: /* fof_binary_assoc: fof_or_formula  */
#line 742 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("fof_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4449 "y.tab.c"
    break;

  case 260: /* fof_binary_assoc: fof_and_formula  */
#line 743 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("fof_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4455 "y.tab.c"
    break;

  case 261: /* fof_or_formula: fof_unit_formula VLINE fof_unit_formula  */
#line 746 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("fof_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4461 "y.tab.c"
    break;

  case 262: /* fof_or_formula: fof_or_formula VLINE fof_unit_formula  */
#line 747 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("fof_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4467 "y.tab.c"
    break;

  case 263: /* fof_and_formula: fof_unit_formula AMPERSAND fof_unit_formula  */
#line 750 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("fof_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4473 "y.tab.c"
    break;

  case 264: /* fof_and_formula: fof_and_formula AMPERSAND fof_unit_formula  */
#line 751 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("fof_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4479 "y.tab.c"
    break;

  case 265: /* fof_unary_formula: unary_connective fof_unit_formula  */
#line 754 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("fof_unary_formula", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4485 "y.tab.c"
    break;

  case 266: /* fof_unary_formula: fof_infix_unary  */
#line 755 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("fof_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4491 "y.tab.c"
    break;

  case 267: /* fof_infix_unary: fof_term infix_inequality fof_term  */
#line 758 "SyntaxBNF.y"
                                                     {(yyval.pval) = P_BUILD("fof_infix_unary", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4497 "y.tab.c"
    break;

  case 268: /* fof_unit_formula: fof_unitary_formula  */
#line 761 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("fof_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4503 "y.tab.c"
    break;

  case 269: /* fof_unit_formula: fof_unary_formula  */
#line 762 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("fof_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4509 "y.tab.c"
    break;

  case 270: /* fof_unitary_formula: fof_quantified_formula  */
#line 765 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("fof_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4515 "y.tab.c"
    break;

  case 271: /* fof_unitary_formula: fof_atomic_formula  */
#line 766 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("fof_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4521 "y.tab.c"
    break;

  case 272: /* fof_unitary_formula: LPAREN fof_logic_formula RPAREN  */
#line 767 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("fof_unitary_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4527 "y.tab.c"
    break;

  case 273: /* fof_quantified_formula: fof_quantifier LBRKT fof_variable_list RBRKT COLON fof_unit_formula  */
#line 770 "SyntaxBNF.y"
                                                                                             {(yyval.pval) = P_BUILD("fof_quantified_formula", (yyvsp[-5].pval), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 4533 "y.tab.c"
    break;

  case 274: /* fof_variable_list: variable  */
#line 773 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("fof_variable_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4539 "y.tab.c"
    break;

  case 275: /* fof_variable_list: variable COMMA fof_variable_list  */
#line 774 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("fof_variable_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4545 "y.tab.c"
    break;

  case 276: /* fof_atomic_formula: fof_plain_atomic_formula  */
#line 777 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("fof_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4551 "y.tab.c"
    break;

  case 277: /* fof_atomic_formula: fof_defined_atomic_formula  */
#line 778 "SyntaxBNF.y"
                                                 {(yyval.pval) = P_BUILD("fof_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4557 "y.tab.c"
    break;

  case 278: /* fof_atomic_formula: fof_system_atomic_formula  */
#line 779 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("fof_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4563 "y.tab.c"
    break;

  case 279: /* fof_plain_atomic_formula: fof_plain_term  */
#line 782 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("fof_plain_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4569 "y.tab.c"
    break;

  case 280: /* fof_defined_atomic_formula: fof_defined_plain_formula  */
#line 785 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("fof_defined_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4575 "y.tab.c"
    break;

  case 281: /* fof_defined_atomic_formula: fof_defined_infix_formula  */
#line 786 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("fof_defined_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4581 "y.tab.c"
    break;

  case 282: /* fof_defined_plain_formula: fof_defined_plain_term  */
#line 789 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("fof_defined_plain_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4587 "y.tab.c"
    break;

  case 283: /* fof_defined_infix_formula: fof_term defined_infix_pred fof_term  */
#line 792 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("fof_defined_infix_formula", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4593 "y.tab.c"
    break;

  case 284: /* fof_system_atomic_formula: fof_system_term  */
#line 795 "SyntaxBNF.y"
                                            {(yyval.pval) = P_BUILD("fof_system_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4599 "y.tab.c"
    break;

  case 285: /* fof_plain_term: constant  */
#line 798 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("fof_plain_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4605 "y.tab.c"
    break;

  case 286: /* fof_plain_term: functor LPAREN fof_arguments RPAREN  */
#line 799 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("fof_plain_term", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4611 "y.tab.c"
    break;

  case 287: /* fof_defined_term: defined_term  */
#line 802 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("fof_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4617 "y.tab.c"
    break;

  case 288: /* fof_defined_term: fof_defined_atomic_term  */
#line 803 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("fof_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4623 "y.tab.c"
    break;

  case 289: /* fof_defined_atomic_term: fof_defined_plain_term  */
#line 806 "SyntaxBNF.y"
                                                 {(yyval.pval) = P_BUILD("fof_defined_atomic_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4629 "y.tab.c"
    break;

  case 290: /* fof_defined_plain_term: defined_constant  */
#line 809 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("fof_defined_plain_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4635 "y.tab.c"
    break;

  case 291: /* fof_defined_plain_term: defined_functor LPAREN fof_arguments RPAREN  */
#line 810 "SyntaxBNF.y"
                                                                  {(yyval.pval) = P_BUILD("fof_defined_plain_term", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4641 "y.tab.c"
    break;

  case 292: /* fof_system_term: system_constant  */
#line 813 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("fof_system_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4647 "y.tab.c"
    break;

  case 293: /* fof_system_term: system_functor LPAREN fof_arguments RPAREN  */
#line 814 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("fof_system_term", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4653 "y.tab.c"
    break;

  case 294: /* fof_arguments: fof_term  */
#line 817 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("fof_arguments", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4659 "y.tab.c"
    break;

  case 295: /* fof_arguments: fof_term COMMA fof_arguments  */
#line 818 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("fof_arguments", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4665 "y.tab.c"
    break;

  case 296: /* fof_term: fof_function_term  */
#line 821 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("fof_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4671 "y.tab.c"
    break;

  case 297: /* fof_term: variable  */
#line 822 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("fof_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4677 "y.tab.c"
    break;

  case 298: /* fof_function_term: fof_plain_term  */
#line 825 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("fof_function_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4683 "y.tab.c"
    break;

  case 299: /* fof_function_term: fof_defined_term  */
#line 826 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("fof_function_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4689 "y.tab.c"
    break;

  case 300: /* fof_function_term: fof_system_term  */
#line 827 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("fof_function_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4695 "y.tab.c"
    break;

  case 301: /* fof_sequent: fof_formula_tuple gentzen_arrow fof_formula_tuple  */
#line 830 "SyntaxBNF.y"
                                                                {(yyval.pval) = P_BUILD("fof_sequent", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4701 "y.tab.c"
    break;

  case 302: /* fof_sequent: LPAREN fof_sequent RPAREN  */
#line 831 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("fof_sequent", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4707 "y.tab.c"
    break;

  case 303: /* fof_formula_tuple: LBRKT RBRKT  */
#line 834 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("fof_formula_tuple", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4713 "y.tab.c"
    break;

  case 304: /* fof_formula_tuple: LBRKT fof_formula_tuple_list RBRKT  */
#line 835 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("fof_formula_tuple", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4719 "y.tab.c"
    break;

  case 305: /* fof_formula_tuple_list: fof_logic_formula  */
#line 838 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("fof_formula_tuple_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4725 "y.tab.c"
    break;

  case 306: /* fof_formula_tuple_list: fof_logic_formula COMMA fof_formula_tuple_list  */
#line 839 "SyntaxBNF.y"
                                                                     {(yyval.pval) = P_BUILD("fof_formula_tuple_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4731 "y.tab.c"
    break;

  case 307: /* cnf_formula: cnf_disjunction  */
#line 842 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("cnf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4737 "y.tab.c"
    break;

  case 308: /* cnf_formula: LPAREN cnf_formula RPAREN  */
#line 843 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("cnf_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4743 "y.tab.c"
    break;

  case 309: /* cnf_disjunction: cnf_literal  */
#line 846 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("cnf_disjunction", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4749 "y.tab.c"
    break;

  case 310: /* cnf_disjunction: cnf_disjunction VLINE cnf_literal  */
#line 847 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("cnf_disjunction", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4755 "y.tab.c"
    break;

  case 311: /* cnf_literal: fof_atomic_formula  */
#line 850 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("cnf_literal", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4761 "y.tab.c"
    break;

  case 312: /* cnf_literal: TILDE fof_atomic_formula  */
#line 851 "SyntaxBNF.y"
                                               {(yyval.pval) = P_BUILD("cnf_literal", P_TOKEN("TILDE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4767 "y.tab.c"
    break;

  case 313: /* cnf_literal: TILDE LPAREN fof_atomic_formula RPAREN  */
#line 852 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("cnf_literal", P_TOKEN("TILDE ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4773 "y.tab.c"
    break;

  case 314: /* cnf_literal: fof_infix_unary  */
#line 853 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("cnf_literal", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4779 "y.tab.c"
    break;

  case 315: /* thf_quantifier: tff_quantifier  */
#line 856 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4785 "y.tab.c"
    break;

  case 316: /* thf_quantifier: th0_quantifier  */
#line 857 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4791 "y.tab.c"
    break;

  case 317: /* thf_quantifier: type_quantifier  */
#line 858 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4797 "y.tab.c"
    break;

  case 318: /* thf_unary_connective: unary_connective  */
#line 861 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4803 "y.tab.c"
    break;

  case 319: /* thf_unary_connective: ntf_short_connective  */
#line 862 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("thf_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4809 "y.tab.c"
    break;

  case 320: /* th0_quantifier: CARET  */
#line 865 "SyntaxBNF.y"
                       {(yyval.pval) = P_BUILD("th0_quantifier", P_TOKEN("CARET ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4815 "y.tab.c"
    break;

  case 321: /* th0_quantifier: AT_SIGN_PLUS  */
#line 866 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("th0_quantifier", P_TOKEN("AT_SIGN_PLUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4821 "y.tab.c"
    break;

  case 322: /* th0_quantifier: AT_SIGN_MINUS  */
#line 867 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("th0_quantifier", P_TOKEN("AT_SIGN_MINUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4827 "y.tab.c"
    break;

  case 323: /* type_quantifier: EXCLAMATION_GREATER  */
#line 870 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("type_quantifier", P_TOKEN("EXCLAMATION_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4833 "y.tab.c"
    break;

  case 324: /* type_quantifier: QUESTION_STAR  */
#line 871 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("type_quantifier", P_TOKEN("QUESTION_STAR ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4839 "y.tab.c"
    break;

  case 325: /* subtype_sign: LESS_LESS  */
#line 874 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("subtype_sign", P_TOKEN("LESS_LESS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4845 "y.tab.c"
    break;

  case 326: /* tff_unary_connective: unary_connective  */
#line 877 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4851 "y.tab.c"
    break;

  case 327: /* tff_unary_connective: ntf_short_connective  */
#line 878 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("tff_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4857 "y.tab.c"
    break;

  case 328: /* tff_quantifier: fof_quantifier  */
#line 881 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4863 "y.tab.c"
    break;

  case 329: /* tff_quantifier: hash  */
#line 882 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("tff_quantifier", P_TOKEN("hash ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4869 "y.tab.c"
    break;

  case 330: /* fof_quantifier: EXCLAMATION  */
#line 885 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("fof_quantifier", P_TOKEN("EXCLAMATION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4875 "y.tab.c"
    break;

  case 331: /* fof_quantifier: QUESTION  */
#line 886 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("fof_quantifier", P_TOKEN("QUESTION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4881 "y.tab.c"
    break;

  case 332: /* nonassoc_connective: LESS_EQUALS_GREATER  */
#line 889 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("LESS_EQUALS_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4887 "y.tab.c"
    break;

  case 333: /* nonassoc_connective: EQUALS_GREATER  */
#line 890 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("EQUALS_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4893 "y.tab.c"
    break;

  case 334: /* nonassoc_connective: LESS_EQUALS  */
#line 891 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("LESS_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4899 "y.tab.c"
    break;

  case 335: /* nonassoc_connective: LESS_TILDE_GREATER  */
#line 892 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("LESS_TILDE_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4905 "y.tab.c"
    break;

  case 336: /* nonassoc_connective: TILDE_VLINE  */
#line 893 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("TILDE_VLINE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4911 "y.tab.c"
    break;

  case 337: /* nonassoc_connective: TILDE_AMPERSAND  */
#line 894 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("TILDE_AMPERSAND ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4917 "y.tab.c"
    break;

  case 338: /* assoc_connective: VLINE  */
#line 897 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("assoc_connective", P_TOKEN("VLINE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4923 "y.tab.c"
    break;

  case 339: /* assoc_connective: AMPERSAND  */
#line 898 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("assoc_connective", P_TOKEN("AMPERSAND ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4929 "y.tab.c"
    break;

  case 340: /* unary_connective: TILDE  */
#line 901 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("unary_connective", P_TOKEN("TILDE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4935 "y.tab.c"
    break;

  case 341: /* gentzen_arrow: MINUS_MINUS_GREATER  */
#line 904 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("gentzen_arrow", P_TOKEN("MINUS_MINUS_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4941 "y.tab.c"
    break;

  case 342: /* assignment: COLON_EQUALS  */
#line 907 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("assignment", P_TOKEN("COLON_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4947 "y.tab.c"
    break;

  case 343: /* identical: EQUALS_EQUALS  */
#line 910 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("identical", P_TOKEN("EQUALS_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4953 "y.tab.c"
    break;

  case 344: /* typeable_atom: constant  */
#line 913 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("typeable_atom", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4959 "y.tab.c"
    break;

  case 345: /* typeable_atom: distinct_object  */
#line 914 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("typeable_atom", P_TOKEN("distinct_object ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4965 "y.tab.c"
    break;

  case 346: /* atomic_type: typeable_atom  */
#line 917 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4971 "y.tab.c"
    break;

  case 347: /* atomic_type: defined_constant  */
#line 918 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4977 "y.tab.c"
    break;

  case 348: /* atomic_type: system_type  */
#line 919 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4983 "y.tab.c"
    break;

  case 349: /* type_constant: type_functor  */
#line 922 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("type_constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4989 "y.tab.c"
    break;

  case 350: /* type_functor: atomic_word  */
#line 925 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("type_functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4995 "y.tab.c"
    break;

  case 351: /* defined_type: atomic_defined_word  */
#line 928 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("defined_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5001 "y.tab.c"
    break;

  case 352: /* system_type: atomic_system_word  */
#line 931 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("system_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5007 "y.tab.c"
    break;

  case 353: /* defined_infix_pred: infix_equality  */
#line 934 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("defined_infix_pred", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5013 "y.tab.c"
    break;

  case 354: /* infix_equality: EQUALS  */
#line 937 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("infix_equality", P_TOKEN("EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5019 "y.tab.c"
    break;

  case 355: /* infix_inequality: EXCLAMATION_EQUALS  */
#line 940 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("infix_inequality", P_TOKEN("EXCLAMATION_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5025 "y.tab.c"
    break;

  case 356: /* constant: functor  */
#line 943 "SyntaxBNF.y"
                   {(yyval.pval) = P_BUILD("constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5031 "y.tab.c"
    break;

  case 357: /* functor: atomic_word  */
#line 946 "SyntaxBNF.y"
                      {(yyval.pval) = P_BUILD("functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5037 "y.tab.c"
    break;

  case 358: /* defined_constant: defined_functor  */
#line 949 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("defined_constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5043 "y.tab.c"
    break;

  case 359: /* defined_functor: atomic_defined_word  */
#line 952 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("defined_functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5049 "y.tab.c"
    break;

  case 360: /* system_constant: system_functor  */
#line 955 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("system_constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5055 "y.tab.c"
    break;

  case 361: /* system_functor: atomic_system_word  */
#line 958 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("system_functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5061 "y.tab.c"
    break;

  case 362: /* th1_defined_term: EXCLAMATION_EXCLAMATION  */
#line 961 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("EXCLAMATION_EXCLAMATION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5067 "y.tab.c"
    break;

  case 363: /* th1_defined_term: QUESTION_QUESTION  */
#line 962 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("QUESTION_QUESTION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5073 "y.tab.c"
    break;

  case 364: /* th1_defined_term: AT_AT_SIGN_PLUS  */
#line 963 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("AT_AT_SIGN_PLUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5079 "y.tab.c"
    break;

  case 365: /* th1_defined_term: AT_AT_SIGN_MINUS  */
#line 964 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("AT_AT_SIGN_MINUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5085 "y.tab.c"
    break;

  case 366: /* th1_defined_term: AT_SIGN_EQUALS  */
#line 965 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("AT_SIGN_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5091 "y.tab.c"
    break;

  case 367: /* defined_term: number  */
#line 968 "SyntaxBNF.y"
                      {(yyval.pval) = P_BUILD("defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5097 "y.tab.c"
    break;

  case 368: /* defined_term: distinct_object  */
#line 969 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("defined_term", P_TOKEN("distinct_object ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5103 "y.tab.c"
    break;

  case 369: /* variable: upper_word  */
#line 972 "SyntaxBNF.y"
                      {(yyval.pval) = P_BUILD("variable", P_TOKEN("upper_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5109 "y.tab.c"
    break;

  case 370: /* source: dag_source  */
#line 975 "SyntaxBNF.y"
                    {(yyval.pval) = P_BUILD("source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5115 "y.tab.c"
    break;

  case 371: /* source: internal_source  */
#line 976 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5121 "y.tab.c"
    break;

  case 372: /* source: external_source  */
#line 977 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5127 "y.tab.c"
    break;

  case 373: /* source: _LIT_unknown  */
#line 978 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("source", P_TOKEN("_LIT_unknown ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5133 "y.tab.c"
    break;

  case 374: /* source: LBRKT sources RBRKT  */
#line 979 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("source", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5139 "y.tab.c"
    break;

  case 375: /* sources: source  */
#line 982 "SyntaxBNF.y"
                 {(yyval.pval) = P_BUILD("sources", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5145 "y.tab.c"
    break;

  case 376: /* sources: source COMMA sources  */
#line 983 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("sources", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5151 "y.tab.c"
    break;

  case 377: /* dag_source: name  */
#line 986 "SyntaxBNF.y"
                  {(yyval.pval) = P_BUILD("dag_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5157 "y.tab.c"
    break;

  case 378: /* dag_source: inference_record  */
#line 987 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("dag_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5163 "y.tab.c"
    break;

  case 379: /* inference_record: _LIT_inference LPAREN inference_rule COMMA useful_info COMMA parents RPAREN  */
#line 990 "SyntaxBNF.y"
                                                                                               {(yyval.pval) = P_BUILD("inference_record", P_TOKEN("_LIT_inference ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 5169 "y.tab.c"
    break;

  case 380: /* inference_rule: atomic_word  */
#line 993 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("inference_rule", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5175 "y.tab.c"
    break;

  case 381: /* internal_source: _LIT_introduced LPAREN intro_type COMMA useful_info COMMA parents RPAREN  */
#line 996 "SyntaxBNF.y"
                                                                                           {(yyval.pval) = P_BUILD("internal_source", P_TOKEN("_LIT_introduced ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 5181 "y.tab.c"
    break;

  case 382: /* intro_type: atomic_word  */
#line 999 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("intro_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5187 "y.tab.c"
    break;

  case 383: /* external_source: file_source  */
#line 1002 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("external_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5193 "y.tab.c"
    break;

  case 384: /* external_source: theory  */
#line 1003 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("external_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5199 "y.tab.c"
    break;

  case 385: /* external_source: creator_source  */
#line 1004 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("external_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5205 "y.tab.c"
    break;

  case 386: /* file_source: _LIT_file LPAREN file_name file_info RPAREN  */
#line 1007 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("file_source", P_TOKEN("_LIT_file ", (yyvsp[-4].ival)), P_TOKEN("LPAREN ", (yyvsp[-3].ival)), (yyvsp[-2].pval), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL);}
#line 5211 "y.tab.c"
    break;

  case 387: /* file_info: COMMA name  */
#line 1010 "SyntaxBNF.y"
                       {(yyval.pval) = P_BUILD("file_info", P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5217 "y.tab.c"
    break;

  case 388: /* file_info: nothing  */
#line 1011 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("file_info", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5223 "y.tab.c"
    break;

  case 389: /* theory: _LIT_theory LPAREN theory_name optional_info RPAREN  */
#line 1014 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("theory", P_TOKEN("_LIT_theory ", (yyvsp[-4].ival)), P_TOKEN("LPAREN ", (yyvsp[-3].ival)), (yyvsp[-2].pval), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL);}
#line 5229 "y.tab.c"
    break;

  case 390: /* theory_name: atomic_word  */
#line 1017 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("theory_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5235 "y.tab.c"
    break;

  case 391: /* creator_source: _LIT_creator LPAREN creator_name COMMA useful_info COMMA parents RPAREN  */
#line 1020 "SyntaxBNF.y"
                                                                                         {(yyval.pval) = P_BUILD("creator_source", P_TOKEN("_LIT_creator ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 5241 "y.tab.c"
    break;

  case 392: /* creator_name: atomic_word  */
#line 1023 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("creator_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5247 "y.tab.c"
    break;

  case 393: /* parents: LBRKT RBRKT  */
#line 1026 "SyntaxBNF.y"
                      {(yyval.pval) = P_BUILD("parents", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5253 "y.tab.c"
    break;

  case 394: /* parents: LBRKT parent_list RBRKT  */
#line 1027 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("parents", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5259 "y.tab.c"
    break;

  case 395: /* parent_list: parent_info  */
#line 1030 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("parent_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5265 "y.tab.c"
    break;

  case 396: /* parent_list: parent_info COMMA parent_list  */
#line 1031 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("parent_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5271 "y.tab.c"
    break;

  case 397: /* parent_info: source parent_details  */
#line 1034 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("parent_info", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5277 "y.tab.c"
    break;

  case 398: /* parent_details: COLON general_term  */
#line 1037 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("parent_details", P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5283 "y.tab.c"
    break;

  case 399: /* parent_details: nothing  */
#line 1038 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("parent_details", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5289 "y.tab.c"
    break;

  case 400: /* optional_info: COMMA useful_info  */
#line 1041 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("optional_info", P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5295 "y.tab.c"
    break;

  case 401: /* optional_info: nothing  */
#line 1042 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("optional_info", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5301 "y.tab.c"
    break;

  case 402: /* useful_info: general_list  */
#line 1045 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("useful_info", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5307 "y.tab.c"
    break;

  case 403: /* include: _LIT_include LPAREN file_name include_optionals RPAREN PERIOD  */
#line 1048 "SyntaxBNF.y"
                                                                        {(yyval.pval) = P_BUILD("include", P_TOKEN("_LIT_include ", (yyvsp[-5].ival)), P_TOKEN("LPAREN ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL);}
#line 5313 "y.tab.c"
    break;

  case 404: /* include_optionals: nothing  */
#line 1051 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("include_optionals", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5319 "y.tab.c"
    break;

  case 405: /* include_optionals: COMMA formula_selection  */
#line 1052 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("include_optionals", P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5325 "y.tab.c"
    break;

  case 406: /* include_optionals: COMMA formula_selection COMMA space_name  */
#line 1053 "SyntaxBNF.y"
                                                               {(yyval.pval) = P_BUILD("include_optionals", P_TOKEN("COMMA ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5331 "y.tab.c"
    break;

  case 407: /* formula_selection: LBRKT name_list RBRKT  */
#line 1056 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("formula_selection", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5337 "y.tab.c"
    break;

  case 408: /* formula_selection: STAR  */
#line 1057 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("formula_selection", P_TOKEN("STAR ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5343 "y.tab.c"
    break;

  case 409: /* name_list: name  */
#line 1060 "SyntaxBNF.y"
                 {(yyval.pval) = P_BUILD("name_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5349 "y.tab.c"
    break;

  case 410: /* name_list: name COMMA name_list  */
#line 1061 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("name_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5355 "y.tab.c"
    break;

  case 411: /* space_name: name  */
#line 1064 "SyntaxBNF.y"
                  {(yyval.pval) = P_BUILD("space_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5361 "y.tab.c"
    break;

  case 412: /* general_term: general_data  */
#line 1067 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("general_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5367 "y.tab.c"
    break;

  case 413: /* general_term: general_data COLON general_term  */
#line 1068 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("general_term", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5373 "y.tab.c"
    break;

  case 414: /* general_term: general_list  */
#line 1069 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("general_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5379 "y.tab.c"
    break;

  case 415: /* general_data: atomic_word  */
#line 1072 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5385 "y.tab.c"
    break;

  case 416: /* general_data: general_function  */
#line 1073 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5391 "y.tab.c"
    break;

  case 417: /* general_data: variable  */
#line 1074 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5397 "y.tab.c"
    break;

  case 418: /* general_data: number  */
#line 1075 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5403 "y.tab.c"
    break;

  case 419: /* general_data: distinct_object  */
#line 1076 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("general_data", P_TOKEN("distinct_object ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5409 "y.tab.c"
    break;

  case 420: /* general_data: formula_data  */
#line 1077 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5415 "y.tab.c"
    break;

  case 421: /* general_function: atomic_word LPAREN general_terms RPAREN  */
#line 1080 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("general_function", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5421 "y.tab.c"
    break;

  case 422: /* formula_data: _DLR_thf LPAREN thf_formula RPAREN  */
#line 1083 "SyntaxBNF.y"
                                                  {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_thf ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5427 "y.tab.c"
    break;

  case 423: /* formula_data: _DLR_tff LPAREN tff_formula RPAREN  */
#line 1084 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_tff ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5433 "y.tab.c"
    break;

  case 424: /* formula_data: _DLR_fof LPAREN fof_formula RPAREN  */
#line 1085 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_fof ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5439 "y.tab.c"
    break;

  case 425: /* formula_data: _DLR_cnf LPAREN cnf_formula RPAREN  */
#line 1086 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_cnf ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5445 "y.tab.c"
    break;

  case 426: /* formula_data: _DLR_fot LPAREN fof_term RPAREN  */
#line 1087 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_fot ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5451 "y.tab.c"
    break;

  case 427: /* general_list: LBRKT RBRKT  */
#line 1090 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("general_list", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5457 "y.tab.c"
    break;

  case 428: /* general_list: LBRKT general_terms RBRKT  */
#line 1091 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("general_list", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5463 "y.tab.c"
    break;

  case 429: /* general_terms: general_term  */
#line 1094 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("general_terms", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5469 "y.tab.c"
    break;

  case 430: /* general_terms: general_term COMMA general_terms  */
#line 1095 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("general_terms", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5475 "y.tab.c"
    break;

  case 431: /* name: atomic_word  */
#line 1098 "SyntaxBNF.y"
                   {(yyval.pval) = P_BUILD("name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5481 "y.tab.c"
    break;

  case 432: /* name: integer  */
#line 1099 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("name", P_TOKEN("integer ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5487 "y.tab.c"
    break;

  case 433: /* atomic_word: lower_word  */
#line 1102 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("atomic_word", P_TOKEN("lower_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5493 "y.tab.c"
    break;

  case 434: /* atomic_word: single_quoted  */
#line 1103 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("atomic_word", P_TOKEN("single_quoted ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5499 "y.tab.c"
    break;

  case 435: /* atomic_word: back_quoted  */
#line 1104 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("atomic_word", P_TOKEN("back_quoted ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5505 "y.tab.c"
    break;

  case 436: /* atomic_defined_word: dollar_word  */
#line 1107 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("atomic_defined_word", P_TOKEN("dollar_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5511 "y.tab.c"
    break;

  case 437: /* atomic_system_word: dollar_dollar_word  */
#line 1110 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("atomic_system_word", P_TOKEN("dollar_dollar_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5517 "y.tab.c"
    break;

  case 438: /* number: integer  */
#line 1113 "SyntaxBNF.y"
                 {(yyval.pval) = P_BUILD("number", P_TOKEN("integer ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5523 "y.tab.c"
    break;

  case 439: /* number: rational  */
#line 1114 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("number", P_TOKEN("rational ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5529 "y.tab.c"
    break;

  case 440: /* number: real  */
#line 1115 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("number", P_TOKEN("real ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5535 "y.tab.c"
    break;

  case 441: /* file_name: atomic_word  */
#line 1118 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("file_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5541 "y.tab.c"
    break;

  case 442: /* nothing: %empty  */
#line 1121 "SyntaxBNF.y"
          {(yyval.pval) = P_BUILD("nothing",NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5547 "y.tab.c"
    break;


#line 5551 "y.tab.c"

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

