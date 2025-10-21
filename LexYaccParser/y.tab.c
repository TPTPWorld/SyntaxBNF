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
  YYSYMBOL_thf_fof_function = 124,         /* thf_fof_function  */
  YYSYMBOL_thf_arguments = 125,            /* thf_arguments  */
  YYSYMBOL_thf_formula_list = 126,         /* thf_formula_list  */
  YYSYMBOL_thf_atom_typing = 127,          /* thf_atom_typing  */
  YYSYMBOL_thf_top_level_type = 128,       /* thf_top_level_type  */
  YYSYMBOL_thf_unitary_type = 129,         /* thf_unitary_type  */
  YYSYMBOL_thf_apply_type = 130,           /* thf_apply_type  */
  YYSYMBOL_thf_binary_type = 131,          /* thf_binary_type  */
  YYSYMBOL_thf_mapping_type = 132,         /* thf_mapping_type  */
  YYSYMBOL_thf_xprod_type = 133,           /* thf_xprod_type  */
  YYSYMBOL_thf_union_type = 134,           /* thf_union_type  */
  YYSYMBOL_thf_subtype = 135,              /* thf_subtype  */
  YYSYMBOL_thf_definition = 136,           /* thf_definition  */
  YYSYMBOL_thf_sequent = 137,              /* thf_sequent  */
  YYSYMBOL_tff_formula = 138,              /* tff_formula  */
  YYSYMBOL_tff_logic_formula = 139,        /* tff_logic_formula  */
  YYSYMBOL_tff_binary_formula = 140,       /* tff_binary_formula  */
  YYSYMBOL_tff_binary_nonassoc = 141,      /* tff_binary_nonassoc  */
  YYSYMBOL_tff_binary_assoc = 142,         /* tff_binary_assoc  */
  YYSYMBOL_tff_or_formula = 143,           /* tff_or_formula  */
  YYSYMBOL_tff_and_formula = 144,          /* tff_and_formula  */
  YYSYMBOL_tff_unit_formula = 145,         /* tff_unit_formula  */
  YYSYMBOL_tff_preunit_formula = 146,      /* tff_preunit_formula  */
  YYSYMBOL_tff_unitary_formula = 147,      /* tff_unitary_formula  */
  YYSYMBOL_txf_unitary_formula = 148,      /* txf_unitary_formula  */
  YYSYMBOL_tff_quantified_formula = 149,   /* tff_quantified_formula  */
  YYSYMBOL_tff_variable_list = 150,        /* tff_variable_list  */
  YYSYMBOL_tff_variable = 151,             /* tff_variable  */
  YYSYMBOL_tff_typed_variable = 152,       /* tff_typed_variable  */
  YYSYMBOL_tff_unary_formula = 153,        /* tff_unary_formula  */
  YYSYMBOL_tff_prefix_unary = 154,         /* tff_prefix_unary  */
  YYSYMBOL_tff_infix_unary = 155,          /* tff_infix_unary  */
  YYSYMBOL_tff_atomic_formula = 156,       /* tff_atomic_formula  */
  YYSYMBOL_tff_plain_atomic = 157,         /* tff_plain_atomic  */
  YYSYMBOL_tff_defined_atomic = 158,       /* tff_defined_atomic  */
  YYSYMBOL_tff_defined_plain = 159,        /* tff_defined_plain  */
  YYSYMBOL_tff_defined_infix = 160,        /* tff_defined_infix  */
  YYSYMBOL_tff_system_atomic = 161,        /* tff_system_atomic  */
  YYSYMBOL_txf_let = 162,                  /* txf_let  */
  YYSYMBOL_txf_let_types = 163,            /* txf_let_types  */
  YYSYMBOL_tff_atom_typing_list = 164,     /* tff_atom_typing_list  */
  YYSYMBOL_txf_let_defns = 165,            /* txf_let_defns  */
  YYSYMBOL_txf_let_defn = 166,             /* txf_let_defn  */
  YYSYMBOL_txf_let_LHS = 167,              /* txf_let_LHS  */
  YYSYMBOL_txf_let_defn_list = 168,        /* txf_let_defn_list  */
  YYSYMBOL_nxf_atom = 169,                 /* nxf_atom  */
  YYSYMBOL_tff_term = 170,                 /* tff_term  */
  YYSYMBOL_tff_unitary_term = 171,         /* tff_unitary_term  */
  YYSYMBOL_txf_tuple = 172,                /* txf_tuple  */
  YYSYMBOL_tff_arguments = 173,            /* tff_arguments  */
  YYSYMBOL_tff_atom_typing = 174,          /* tff_atom_typing  */
  YYSYMBOL_tff_top_level_type = 175,       /* tff_top_level_type  */
  YYSYMBOL_tff_non_atomic_type = 176,      /* tff_non_atomic_type  */
  YYSYMBOL_tf1_quantified_type = 177,      /* tf1_quantified_type  */
  YYSYMBOL_tff_monotype = 178,             /* tff_monotype  */
  YYSYMBOL_tff_unitary_type = 179,         /* tff_unitary_type  */
  YYSYMBOL_tff_atomic_type = 180,          /* tff_atomic_type  */
  YYSYMBOL_tff_type_arguments = 181,       /* tff_type_arguments  */
  YYSYMBOL_tff_mapping_type = 182,         /* tff_mapping_type  */
  YYSYMBOL_tff_xprod_type = 183,           /* tff_xprod_type  */
  YYSYMBOL_txf_tuple_type = 184,           /* txf_tuple_type  */
  YYSYMBOL_tff_type_list = 185,            /* tff_type_list  */
  YYSYMBOL_tff_subtype = 186,              /* tff_subtype  */
  YYSYMBOL_txf_definition = 187,           /* txf_definition  */
  YYSYMBOL_txf_sequent = 188,              /* txf_sequent  */
  YYSYMBOL_nhf_long_connective = 189,      /* nhf_long_connective  */
  YYSYMBOL_nhf_parameter_list = 190,       /* nhf_parameter_list  */
  YYSYMBOL_nhf_parameter = 191,            /* nhf_parameter  */
  YYSYMBOL_nhf_key_pair = 192,             /* nhf_key_pair  */
  YYSYMBOL_nxf_long_connective = 193,      /* nxf_long_connective  */
  YYSYMBOL_nxf_parameter_list = 194,       /* nxf_parameter_list  */
  YYSYMBOL_nxf_parameter = 195,            /* nxf_parameter  */
  YYSYMBOL_nxf_key_pair = 196,             /* nxf_key_pair  */
  YYSYMBOL_ntf_connective_name = 197,      /* ntf_connective_name  */
  YYSYMBOL_ntf_index = 198,                /* ntf_index  */
  YYSYMBOL_ntf_short_connective = 199,     /* ntf_short_connective  */
  YYSYMBOL_tcf_formula = 200,              /* tcf_formula  */
  YYSYMBOL_tcf_logic_formula = 201,        /* tcf_logic_formula  */
  YYSYMBOL_tcf_quantified_formula = 202,   /* tcf_quantified_formula  */
  YYSYMBOL_fof_formula = 203,              /* fof_formula  */
  YYSYMBOL_fof_logic_formula = 204,        /* fof_logic_formula  */
  YYSYMBOL_fof_binary_formula = 205,       /* fof_binary_formula  */
  YYSYMBOL_fof_binary_nonassoc = 206,      /* fof_binary_nonassoc  */
  YYSYMBOL_fof_binary_assoc = 207,         /* fof_binary_assoc  */
  YYSYMBOL_fof_or_formula = 208,           /* fof_or_formula  */
  YYSYMBOL_fof_and_formula = 209,          /* fof_and_formula  */
  YYSYMBOL_fof_unary_formula = 210,        /* fof_unary_formula  */
  YYSYMBOL_fof_infix_unary = 211,          /* fof_infix_unary  */
  YYSYMBOL_fof_unit_formula = 212,         /* fof_unit_formula  */
  YYSYMBOL_fof_unitary_formula = 213,      /* fof_unitary_formula  */
  YYSYMBOL_fof_quantified_formula = 214,   /* fof_quantified_formula  */
  YYSYMBOL_fof_variable_list = 215,        /* fof_variable_list  */
  YYSYMBOL_fof_atomic_formula = 216,       /* fof_atomic_formula  */
  YYSYMBOL_fof_plain_atomic_formula = 217, /* fof_plain_atomic_formula  */
  YYSYMBOL_fof_defined_atomic_formula = 218, /* fof_defined_atomic_formula  */
  YYSYMBOL_fof_defined_plain_formula = 219, /* fof_defined_plain_formula  */
  YYSYMBOL_fof_defined_infix_formula = 220, /* fof_defined_infix_formula  */
  YYSYMBOL_fof_system_atomic_formula = 221, /* fof_system_atomic_formula  */
  YYSYMBOL_fof_plain_term = 222,           /* fof_plain_term  */
  YYSYMBOL_fof_defined_term = 223,         /* fof_defined_term  */
  YYSYMBOL_fof_defined_atomic_term = 224,  /* fof_defined_atomic_term  */
  YYSYMBOL_fof_defined_plain_term = 225,   /* fof_defined_plain_term  */
  YYSYMBOL_fof_system_term = 226,          /* fof_system_term  */
  YYSYMBOL_fof_arguments = 227,            /* fof_arguments  */
  YYSYMBOL_fof_term = 228,                 /* fof_term  */
  YYSYMBOL_fof_function_term = 229,        /* fof_function_term  */
  YYSYMBOL_fof_sequent = 230,              /* fof_sequent  */
  YYSYMBOL_fof_formula_tuple = 231,        /* fof_formula_tuple  */
  YYSYMBOL_fof_formula_tuple_list = 232,   /* fof_formula_tuple_list  */
  YYSYMBOL_cnf_formula = 233,              /* cnf_formula  */
  YYSYMBOL_cnf_disjunction = 234,          /* cnf_disjunction  */
  YYSYMBOL_cnf_literal = 235,              /* cnf_literal  */
  YYSYMBOL_thf_quantifier = 236,           /* thf_quantifier  */
  YYSYMBOL_thf_unary_connective = 237,     /* thf_unary_connective  */
  YYSYMBOL_th0_quantifier = 238,           /* th0_quantifier  */
  YYSYMBOL_type_quantifier = 239,          /* type_quantifier  */
  YYSYMBOL_subtype_sign = 240,             /* subtype_sign  */
  YYSYMBOL_tff_unary_connective = 241,     /* tff_unary_connective  */
  YYSYMBOL_tff_quantifier = 242,           /* tff_quantifier  */
  YYSYMBOL_fof_quantifier = 243,           /* fof_quantifier  */
  YYSYMBOL_nonassoc_connective = 244,      /* nonassoc_connective  */
  YYSYMBOL_assoc_connective = 245,         /* assoc_connective  */
  YYSYMBOL_unary_connective = 246,         /* unary_connective  */
  YYSYMBOL_gentzen_arrow = 247,            /* gentzen_arrow  */
  YYSYMBOL_assignment = 248,               /* assignment  */
  YYSYMBOL_identical = 249,                /* identical  */
  YYSYMBOL_type_constant = 250,            /* type_constant  */
  YYSYMBOL_type_functor = 251,             /* type_functor  */
  YYSYMBOL_defined_type = 252,             /* defined_type  */
  YYSYMBOL_atom = 253,                     /* atom  */
  YYSYMBOL_untyped_atom = 254,             /* untyped_atom  */
  YYSYMBOL_defined_infix_pred = 255,       /* defined_infix_pred  */
  YYSYMBOL_infix_equality = 256,           /* infix_equality  */
  YYSYMBOL_infix_inequality = 257,         /* infix_inequality  */
  YYSYMBOL_constant = 258,                 /* constant  */
  YYSYMBOL_functor = 259,                  /* functor  */
  YYSYMBOL_defined_constant = 260,         /* defined_constant  */
  YYSYMBOL_defined_functor = 261,          /* defined_functor  */
  YYSYMBOL_system_constant = 262,          /* system_constant  */
  YYSYMBOL_system_functor = 263,           /* system_functor  */
  YYSYMBOL_def_or_sys_constant = 264,      /* def_or_sys_constant  */
  YYSYMBOL_th1_defined_term = 265,         /* th1_defined_term  */
  YYSYMBOL_defined_term = 266,             /* defined_term  */
  YYSYMBOL_variable = 267,                 /* variable  */
  YYSYMBOL_source = 268,                   /* source  */
  YYSYMBOL_sources = 269,                  /* sources  */
  YYSYMBOL_dag_source = 270,               /* dag_source  */
  YYSYMBOL_inference_record = 271,         /* inference_record  */
  YYSYMBOL_inference_rule = 272,           /* inference_rule  */
  YYSYMBOL_internal_source = 273,          /* internal_source  */
  YYSYMBOL_intro_type = 274,               /* intro_type  */
  YYSYMBOL_external_source = 275,          /* external_source  */
  YYSYMBOL_file_source = 276,              /* file_source  */
  YYSYMBOL_file_info = 277,                /* file_info  */
  YYSYMBOL_theory = 278,                   /* theory  */
  YYSYMBOL_theory_name = 279,              /* theory_name  */
  YYSYMBOL_creator_source = 280,           /* creator_source  */
  YYSYMBOL_creator_name = 281,             /* creator_name  */
  YYSYMBOL_parents = 282,                  /* parents  */
  YYSYMBOL_parent_list = 283,              /* parent_list  */
  YYSYMBOL_parent_info = 284,              /* parent_info  */
  YYSYMBOL_parent_details = 285,           /* parent_details  */
  YYSYMBOL_optional_info = 286,            /* optional_info  */
  YYSYMBOL_useful_info = 287,              /* useful_info  */
  YYSYMBOL_include = 288,                  /* include  */
  YYSYMBOL_include_optionals = 289,        /* include_optionals  */
  YYSYMBOL_formula_selection = 290,        /* formula_selection  */
  YYSYMBOL_name_list = 291,                /* name_list  */
  YYSYMBOL_space_name = 292,               /* space_name  */
  YYSYMBOL_general_term = 293,             /* general_term  */
  YYSYMBOL_general_data = 294,             /* general_data  */
  YYSYMBOL_general_function = 295,         /* general_function  */
  YYSYMBOL_formula_data = 296,             /* formula_data  */
  YYSYMBOL_general_list = 297,             /* general_list  */
  YYSYMBOL_general_terms = 298,            /* general_terms  */
  YYSYMBOL_name = 299,                     /* name  */
  YYSYMBOL_atomic_word = 300,              /* atomic_word  */
  YYSYMBOL_atomic_defined_word = 301,      /* atomic_defined_word  */
  YYSYMBOL_atomic_system_word = 302,       /* atomic_system_word  */
  YYSYMBOL_number = 303,                   /* number  */
  YYSYMBOL_file_name = 304,                /* file_name  */
  YYSYMBOL_nothing = 305                   /* nothing  */
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
#define YYLAST   3644

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  78
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  228
/* YYNRULES -- Number of rules.  */
#define YYNRULES  445
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  829

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
     343,   346,   349,   352,   353,   354,   355,   358,   359,   362,
     363,   364,   365,   366,   369,   370,   373,   376,   379,   382,
     383,   386,   387,   390,   391,   394,   397,   398,   401,   402,
     403,   406,   407,   408,   409,   410,   413,   414,   417,   418,
     419,   422,   425,   426,   429,   430,   433,   434,   435,   438,
     441,   444,   445,   446,   449,   450,   453,   454,   457,   458,
     461,   464,   467,   470,   471,   472,   475,   476,   477,   478,
     479,   480,   483,   484,   487,   490,   491,   494,   495,   498,
     499,   502,   503,   504,   507,   508,   511,   512,   513,   514,
     517,   520,   523,   524,   527,   528,   531,   534,   535,   538,
     541,   544,   545,   546,   549,   550,   553,   556,   557,   558,
     559,   562,   565,   566,   569,   572,   573,   576,   577,   580,
     581,   584,   587,   588,   591,   592,   595,   598,   599,   600,
     603,   604,   605,   606,   607,   610,   611,   614,   615,   618,
     619,   622,   623,   626,   627,   628,   631,   634,   635,   636,
     639,   640,   643,   644,   645,   646,   647,   648,   651,   652,
     655,   658,   659,   662,   665,   666,   669,   672,   675,   678,
     679,   682,   683,   686,   687,   690,   693,   694,   697,   698,
     701,   702,   705,   708,   711,   714,   715,   716,   717,   720,
     721,   724,   725,   728,   731,   732,   735,   736,   737,   740,
     741,   744,   747,   748,   751,   752,   755,   756,   759,   760,
     763,   766,   767,   770,   771,   772,   775,   778,   779,   782,
     783,   784,   787,   790,   791,   794,   797,   800,   803,   804,
     807,   808,   811,   814,   815,   818,   819,   822,   823,   826,
     827,   830,   831,   832,   835,   836,   839,   840,   843,   844,
     847,   848,   851,   852,   855,   856,   857,   858,   861,   862,
     863,   866,   867,   870,   871,   872,   875,   876,   879,   882,
     883,   886,   887,   890,   891,   894,   895,   896,   897,   898,
     899,   902,   903,   906,   909,   912,   915,   918,   921,   924,
     927,   928,   931,   932,   935,   938,   941,   944,   947,   950,
     953,   956,   959,   962,   963,   966,   967,   968,   969,   970,
     973,   974,   977,   980,   981,   982,   983,   984,   987,   988,
     991,   992,   995,   998,  1001,  1004,  1007,  1008,  1009,  1012,
    1015,  1016,  1019,  1022,  1025,  1028,  1031,  1032,  1035,  1036,
    1039,  1042,  1043,  1046,  1047,  1050,  1053,  1056,  1057,  1058,
    1061,  1062,  1065,  1066,  1069,  1072,  1073,  1074,  1077,  1078,
    1079,  1080,  1081,  1082,  1085,  1088,  1089,  1090,  1091,  1092,
    1095,  1096,  1099,  1100,  1103,  1104,  1107,  1108,  1109,  1112,
    1115,  1118,  1119,  1120,  1123,  1126
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
  "th0_quantifier", "type_quantifier", "subtype_sign",
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
  "nothing", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-570)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-354)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -570,   458,  -570,  -570,   105,   110,   125,   150,   177,   180,
     220,  -570,  -570,  -570,  -570,  -570,  -570,  -570,  -570,  -570,
     259,   259,   430,   259,   259,   259,   259,  -570,  -570,  -570,
    -570,    35,  -570,   245,  -570,   251,   281,   287,   310,   312,
     203,   203,   108,   321,  -570,   203,   203,   203,   203,   341,
     369,   374,   259,  -570,   376,   364,   386,   388,   421,   422,
    2245,  1805,  1121,   401,   435,   259,  -570,  1261,  3514,  2628,
    1121,  1369,   424,   432,   434,   447,   464,  -570,  -570,  -570,
    -570,  -570,  -570,  -570,   493,  -570,  -570,  -570,   484,  -570,
    1805,  2162,  -570,  -570,  -570,  -570,  -570,  -570,  -570,  -570,
    -570,  -570,   102,  -570,  -570,   227,   255,   269,  -570,   502,
     479,  -570,  -570,   495,  -570,   498,  -570,   501,  -570,  -570,
    -570,  -570,  -570,  -570,  -570,  1023,  1121,  -570,  -570,   502,
    -570,  -570,  -570,  -570,   480,   526,   226,  -570,   967,   323,
    -570,  -570,  -570,   505,   508,  1889,  -570,   259,  -570,  -570,
     509,  2707,  -570,   502,  -570,  -570,  -570,   530,   537,   539,
      91,  3302,  3355,   510,  -570,   531,   502,  -570,  -570,  -570,
    -570,   519,   568,  1221,   335,  -570,  -570,   427,  -570,  -570,
     278,  -570,  -570,  -570,   440,  -570,  -570,  -570,   269,   505,
    -570,  -570,  -570,  -570,   566,  -570,  2790,   552,  -570,  -570,
      82,   114,   548,  -570,   549,   146,   553,  -570,   378,  -570,
    -570,  -570,  -570,  -570,  -570,  -570,  -570,    91,  1730,  1485,
    -570,  -570,   559,   502,  -570,  -570,  -570,  -570,   538,   584,
     582,  1036,   342,  -570,  3018,   325,  -570,  -570,   358,  -570,
    -570,  -570,   511,  -570,  -570,   269,   505,  -570,  -570,   179,
    -570,  -570,   570,   520,  -570,  -570,  -570,  -570,  -570,   567,
    3094,  -570,  -570,  -570,  -570,   171,   114,   578,  -570,   581,
     146,   590,  -570,  -570,   396,   502,  -570,  -570,   605,   586,
    1805,  1121,  1641,  3514,  2628,  2245,  2245,   583,  1641,  -570,
     610,  -570,  -570,  1641,  -570,  1641,  2392,   602,  -570,  2434,
    1641,  1641,  1641,  1889,  -570,   613,   593,   606,   609,   611,
    1889,  1889,  1889,  -570,  -570,  -570,  -570,  -570,  -570,  1889,
    1889,  -570,   627,   573,  -570,  -570,  -570,  -570,   573,   615,
     619,   658,   623,    60,  -570,  -570,  -570,  -570,  -570,  3408,
     628,  -570,  -570,   645,   196,   632,  -570,  -570,   431,   633,
     634,    96,   603,   636,  3567,  3567,  3567,  3567,  3567,  -570,
    3567,  1403,  1403,   646,   648,   643,  3408,  -570,  -570,  -570,
    -570,  -570,   573,  -570,   490,  3567,  3567,  3567,   154,  2085,
    -570,   668,   659,  -570,  -570,  -570,  -570,   651,   662,   665,
    3094,  -570,  -570,   691,  -570,  -570,   652,   667,  3018,  3018,
    3018,  3018,  3018,  3018,  3018,  -570,  -570,  -570,   446,  -570,
    -570,  3018,  1826,  1826,   690,  3240,  3240,  3240,  3240,  3240,
     573,  2085,  -570,  -570,  -570,  -570,  -570,  3018,   490,  3018,
    3018,  3018,   677,  2245,  -570,   679,   683,  -570,  -570,  -570,
     686,   688,   693,  -570,   694,  -570,   698,  -570,  -570,  2392,
     699,   709,   711,   715,   720,  -570,   738,  -570,  -570,  -570,
    -570,  -570,  -570,  -570,  -570,   722,  -570,   728,   752,   731,
     737,  1889,  -570,  -570,  -570,   745,  -570,  -570,  -570,  -570,
    -570,  -570,   741,   765,   744,   767,  -570,   771,  -570,   755,
     658,   658,  -570,  -570,  -570,   725,   729,  -570,  -570,   772,
    -570,   769,  -570,  -570,  -570,  -570,  -570,   796,  -570,  -570,
    3567,  -570,  -570,   463,   340,   340,   784,  -570,  -570,  -570,
    -570,  -570,   770,  -570,  -570,  -570,   475,  -570,  -570,  -570,
    -570,  -570,  -570,  -570,   133,  3461,  3567,  -570,  -570,  -570,
    -570,  -570,  3567,   763,   766,  -570,  -570,  -570,   773,   774,
     777,  2013,  -570,  3018,  -570,   494,  -570,  -570,   743,   743,
     789,  -570,   785,  -570,  -570,  -570,  -570,  -570,  -570,  -570,
    -570,   133,  2358,  2947,  -570,  -570,  -570,  -570,  -570,  2947,
    -570,  -570,   757,  -570,  -570,  -570,  -570,   792,   806,   809,
     795,   582,   826,   828,  -570,   757,  -570,  -570,  -570,   802,
    -570,   803,   804,   812,  -570,  -570,  -570,  -570,  -570,  -570,
    -570,  -570,   823,   808,   430,   430,   430,   430,   430,   827,
    -570,  -570,  -570,  -570,  1641,  -570,  -570,  -570,  -570,   837,
     573,   839,   573,   579,  -570,   838,   817,   818,    73,   820,
     181,   579,   573,   579,  1403,   849,  -570,   831,   858,  -570,
    -570,  -570,   835,   868,   215,  -570,   846,   847,  -570,   875,
    -570,  -570,  -570,  2028,   849,  -570,   852,   883,  -570,  -570,
    -570,   862,   885,  3165,  -570,   863,   889,   573,  3018,  -570,
    -570,  -570,  -570,  -570,  2392,  -570,   888,  -570,   892,   893,
    -570,   894,  -570,   738,  -570,  -570,  -570,  -570,  1889,  -570,
    1281,  -570,   579,  -570,   658,  -570,  -570,   579,  -570,  -570,
     579,  -570,   873,   896,   874,  -570,   879,   796,  -570,   340,
    3461,  -570,   901,  -570,   903,  -570,  -570,  -570,  3567,   887,
     890,  -570,   895,  2013,  -570,   743,  1730,   903,   910,  -570,
    -570,  -570,  -570,  -570,  -570,   827,   259,   891,  -570,   827,
     827,   900,  -570,  -570,   820,  -570,  -570,  -570,   917,   579,
    -570,  -570,  -570,  -570,   920,   924,   904,   524,  3567,  -570,
    3567,  -570,  -570,  -570,  -570,   211,   925,   905,  3018,  3018,
     928,  -570,  -570,   929,   931,  -570,   857,  -570,   324,  -570,
     909,  -570,  3018,  -570,  -570,   915,   933,   933,   933,  1047,
    -570,  -570,  -570,  -570,  -570,  -570,  -570,  2518,   921,   923,
     927,  1047,   935,  -570,   945,   930,   947,  -570,  -570,  -570,
     937,  -570,  2245,  -570,  -570,  -570,  2392,  -570,  -570
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     445,     0,     2,     1,     0,     0,     0,     0,     0,     0,
       0,     3,     4,    11,     6,     7,     8,     9,    10,     5,
       0,     0,     0,     0,     0,     0,     0,   438,   435,   436,
     437,     0,   434,     0,   444,   445,     0,     0,     0,     0,
       0,     0,     0,     0,   407,     0,     0,     0,     0,    21,
       0,     0,     0,   411,   408,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   412,     0,   406,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   422,   441,   442,
     443,   372,   420,    22,   415,   419,   423,   417,   418,   421,
       0,     0,   371,   440,   439,   317,   314,   279,   280,   283,
     284,   281,   282,   302,   291,   285,   287,     0,   299,   445,
     310,   312,   288,   357,   293,   359,   295,   361,   290,   300,
     358,   360,   362,   370,   333,     0,     0,   334,   343,   445,
     254,   256,   259,   260,   262,   263,   272,   269,     0,   271,
     273,   274,   255,     0,     0,     0,   410,     0,   409,   414,
       0,     0,   250,   445,   249,   251,   252,     0,   288,   295,
       0,     0,     0,     0,   332,     0,   445,   123,   128,   132,
     133,   135,   136,     0,   141,   148,   146,   142,   157,   158,
     147,   161,   162,   166,   143,   163,   170,   169,     0,   192,
     124,   125,   130,   131,     0,   330,     0,     0,   331,   329,
       0,   164,   357,   167,   359,   172,   361,   191,   150,   368,
     367,   369,   325,   324,   323,   365,   326,     0,     0,     0,
     366,   327,     0,   445,    23,    28,    32,    33,    36,    37,
      38,     0,    45,    50,     0,    46,    59,    60,    51,    63,
      64,    70,    47,    65,    73,     0,    68,    66,    24,     0,
      34,   111,   112,   113,    25,    30,    31,    72,   322,     0,
       0,   319,   320,   318,   321,     0,    67,   357,    69,   359,
      77,   361,    75,    74,    52,   445,    13,   430,   432,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   315,
       0,   355,   356,     0,   354,     0,     0,     0,    20,     0,
       0,     0,     0,     0,   306,   308,     0,     0,     0,     0,
       0,     0,     0,   336,   337,   335,   338,   340,   339,     0,
       0,   344,     0,     0,   272,   268,   271,   413,     0,     0,
       0,     0,     0,     0,   363,   359,   364,   361,   243,     0,
       0,   195,   187,   197,   189,     0,   164,   172,   188,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   346,
       0,     0,     0,     0,     0,     0,     0,   159,   144,   145,
     147,   150,     0,   328,     0,     0,     0,     0,     0,     0,
      96,   102,     0,    67,    77,   342,   341,     0,     0,     0,
      95,    91,    92,     0,    93,    94,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    54,    45,    46,    51,    47,
      68,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    61,    48,    49,    51,    52,     0,     0,     0,
       0,     0,     0,     0,   431,     0,     0,   301,   292,   303,
       0,     0,     0,   416,     0,   311,     0,   286,   270,     0,
       0,     0,     0,     0,     0,   376,   445,   373,   381,   374,
     375,   386,   387,   388,   380,     0,   313,     0,   297,     0,
       0,     0,   307,   275,   305,     0,   265,   267,   266,   264,
     261,   304,     0,   277,     0,   152,   154,   155,   200,     0,
       0,     0,   199,   202,   204,     0,   201,   203,   217,     0,
     212,   347,   213,   214,   348,   349,   247,     0,   236,   245,
       0,   196,   248,   149,     0,     0,     0,   175,   352,   357,
     353,   246,     0,   138,   141,   142,   147,   143,   192,   140,
     139,   137,   134,   227,     0,     0,     0,   190,   171,   193,
     160,   228,     0,     0,     0,   226,   350,   351,     0,     0,
       0,     0,   229,     0,    97,    53,    71,   105,     0,     0,
       0,    79,     0,    40,    42,    44,    41,    43,    39,    35,
     121,     0,     0,     0,    88,    76,    89,    62,   122,     0,
     109,   116,   114,   115,   118,   117,   119,     0,    56,     0,
       0,   110,     0,   109,   104,   106,   108,   107,   120,     0,
     101,     0,     0,     0,   433,   428,   427,   429,   426,   425,
     424,   316,   378,     0,     0,     0,     0,     0,     0,     0,
      19,   404,    18,   289,     0,   294,   296,   309,    17,     0,
       0,     0,     0,     0,    16,   224,     0,     0,     0,   210,
       0,     0,     0,     0,     0,     0,   242,     0,   238,   241,
     240,   198,     0,   177,     0,    15,     0,     0,   149,     0,
     165,   168,   173,     0,     0,   235,     0,   231,   234,   233,
     103,     0,    81,     0,    14,     0,     0,     0,     0,    53,
      98,    99,   100,    12,     0,   377,     0,   395,   445,     0,
     383,     0,   385,   445,   393,   403,   405,   298,     0,   278,
       0,   153,     0,   156,     0,   223,   205,     0,   216,   211,
       0,   220,     0,   218,     0,   244,     0,     0,   176,     0,
       0,   182,     0,   179,     0,   183,   194,   186,     0,     0,
       0,    95,     0,     0,    80,     0,     0,     0,     0,    83,
      90,    55,    57,    58,   379,     0,     0,     0,   391,     0,
       0,     0,   276,   253,     0,   225,   221,   222,     0,     0,
     215,   237,   239,   178,   161,   184,     0,   189,     0,   345,
       0,   151,   230,   232,    82,   102,    86,     0,     0,     0,
       0,   390,   389,     0,     0,   392,     0,   219,     0,   180,
       0,   181,     0,    84,    85,     0,     0,     0,     0,     0,
     209,   206,   207,   185,   174,    87,    78,     0,     0,     0,
       0,     0,     0,   396,   445,     0,   398,   394,   382,   384,
       0,   208,     0,   400,   402,   397,     0,   401,   399
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -570,  -570,  -570,  -570,  -570,  -570,  -570,  -570,  -570,  -570,
    -570,   -20,   589,   680,   -30,  -570,  -570,  -570,  -570,  -570,
    -397,   -84,  -570,   166,  -570,  -570,   295,  -570,   357,  -220,
    -570,   983,  -570,  -570,  -570,   629,  -570,  -570,  -570,   240,
    -570,   304,   186,  -156,  -570,   -46,  -570,  -100,  -288,  -195,
     301,  -316,  -570,  -570,  -337,  -570,  -570,  -570,  -497,  -570,
     702,   -31,  -570,  -570,  -570,  -570,  -570,  -290,  -570,  -124,
    -570,  -570,  -320,  -570,  -570,  -281,   786,  -570,   -52,  -569,
    -570,  -570,  -274,  -570,  -570,  -570,   273,  -570,   343,  -570,
     207,  -570,  -338,  -302,   467,  -213,   -12,   670,   507,   218,
    -570,  -464,   292,   246,   212,  -570,  -570,   308,  -570,  -471,
    -570,  -570,   282,  -570,  -570,  -570,   297,  -570,  -570,  -191,
    -459,   256,  -570,   316,  -570,   -39,   -55,  -570,  -570,  -570,
    -570,  -570,  -136,    -4,  -125,  -120,  -570,   387,   -29,  -570,
    -570,  -570,  -570,  -570,  -204,  -570,  -570,  -187,  -134,  -258,
     -80,  -570,   897,   696,   550,    27,  -570,   723,  -570,  -168,
    -570,  -285,   754,  -570,   800,   -21,   -19,  -570,  2558,   -93,
     313,  -223,  -570,  -570,  -570,   608,   -40,  -119,    21,     5,
     592,   919,  1902,  2175,  1302,  1629,  -570,  -570,  2448,    67,
    -275,   350,  -570,  -570,  -570,  -570,  -570,  -570,  -570,  -570,
    -570,  -570,  -570,  -570,  -390,   217,  -570,  -570,   345,  -405,
    -570,  -570,  -570,   899,  -570,   -50,  -570,  -570,  -570,  -470,
    -253,    -7,   -18,   214,  -570,   -59,   426,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    11,    12,    13,   275,    14,    15,    16,    17,
      18,   297,    50,   223,   381,   225,   226,   227,   228,   229,
     230,   231,   422,   232,   233,   234,   587,   588,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   560,   671,
     738,   776,   777,   245,   388,   410,   247,   599,   382,   248,
     594,   249,   596,   250,   251,   252,   253,   254,   255,   256,
     166,   342,   168,   169,   170,   171,   172,   173,   367,   174,
     175,   176,   484,   485,   486,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   516,   652,   722,   765,   724,
     766,   187,   343,   188,   344,   345,   329,   635,   493,   494,
     801,   495,   496,   714,   497,   640,   498,   636,   191,   192,
     193,   257,   666,   667,   668,   194,   647,   648,   649,   333,
     650,   258,   153,   154,   155,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   482,   141,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   467,
     107,   108,   142,   143,   306,   156,   110,   111,   259,   260,
     261,   262,   374,   196,   263,   198,   391,   392,   264,   363,
     778,   360,   500,   501,   502,   545,   157,   293,   394,   395,
     383,   267,   268,   269,   384,   271,   338,   272,   273,   119,
     612,   613,   457,   458,   689,   459,   691,   460,   461,   747,
     462,   693,   463,   686,   808,   815,   816,   823,   620,   695,
      19,    43,    54,    63,   148,   278,    84,    85,    86,    87,
     279,   464,   120,   121,   122,   123,    35,   298
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       2,    89,    32,    32,    34,    32,    32,    32,    32,   324,
      83,   290,    89,    31,    33,   411,    36,    37,    38,    39,
     325,   456,   533,   246,   389,   326,   378,   638,   200,   265,
     591,   276,    96,   444,    32,    44,   646,   167,    96,   224,
     424,   144,    88,   469,   470,    64,   499,    32,    40,   144,
     322,   390,   544,    88,   665,   152,   190,    95,   149,   538,
     540,    96,   289,    95,   523,   529,   530,   531,   532,   361,
     305,   307,   368,   525,   525,   525,   525,   525,   437,   583,
     527,   527,   527,   527,   527,   721,    95,   507,   109,   437,
     597,   437,   669,   331,   508,   438,   437,   437,   437,   581,
     582,   584,   585,   586,   144,   144,   438,   373,   438,   309,
     707,   595,   295,   438,   438,   438,  -301,   287,   514,   320,
    -301,   332,    96,   515,   144,  -352,   412,    82,   294,    32,
      52,   350,    20,   330,   641,   208,   274,    21,    82,  -352,
      64,   600,   600,   600,   370,    53,   353,    95,   439,   696,
     405,   764,    22,   414,   358,    93,    94,  -353,    27,   439,
      93,   439,   548,   549,   550,    29,   439,   439,   439,    30,
     424,  -353,   246,   246,   324,   324,   324,    23,   287,   393,
     604,   551,   427,   324,   324,   476,   477,   478,   552,   387,
     326,   326,   326,   362,   479,   480,   373,    93,    94,   326,
     326,   561,   440,   397,    24,   499,   499,    25,   290,   294,
    -192,   390,   404,   447,  -192,   448,   415,   709,   710,   721,
     468,   468,   468,   769,   553,   321,    89,    89,   208,   208,
     524,   524,   524,   524,   524,   443,   665,   720,   246,  -257,
     416,  -292,   436,   200,   265,  -292,   646,    26,   307,   417,
     413,    96,   167,   390,   224,   432,   575,   577,    41,   446,
     144,  -257,  -257,   371,    42,   670,   294,    88,    88,  -303,
      96,   190,    49,  -303,   669,   696,    95,    27,    32,   696,
     696,   591,   144,   291,    29,   274,   274,   292,    30,   144,
     144,   144,  -190,   359,    45,    95,  -190,   651,   144,   144,
      46,   274,   526,   526,   526,   526,   526,   435,   350,   537,
     537,   294,   701,   504,   563,   564,   565,   566,   567,   568,
     569,    27,   712,    47,   195,    48,    28,   426,    29,   657,
     601,   602,    30,   246,   546,   543,  -258,   -27,   -27,   517,
     780,   597,   715,   592,   783,   784,   535,   820,  -126,   387,
     208,   274,    82,    82,   -26,   -26,   393,    55,  -258,  -258,
     -27,   -27,   595,   672,   389,   246,   697,   515,   578,    60,
    -126,  -126,   -88,   359,    89,   246,   -88,   -26,   -26,  -109,
     378,   570,    61,   246,   246,   246,    27,    62,   546,    65,
     483,   590,  -193,    29,    66,   487,  -193,    30,   503,    67,
     406,    68,    27,  -109,    93,   390,   208,   809,   810,    29,
     -89,   390,  -109,    30,   -89,    88,   305,   195,   195,   499,
     437,   208,   208,   208,   208,   208,   423,   208,   539,   539,
     790,    32,   791,   208,    69,    70,   146,   438,   771,   487,
    -127,   411,   208,   208,   208,  -191,   274,   525,   147,  -191,
     144,   280,   195,  -129,   527,   645,   621,   426,     3,   281,
     -88,   282,  -127,  -127,   -88,   274,   274,   274,   274,   274,
     274,   274,   504,   504,   283,  -129,  -129,  -194,   274,   576,
     576,  -194,   426,   426,   426,   426,   426,   589,   274,  -190,
     439,   284,    27,  -190,   274,   731,   274,   274,   274,    29,
      82,   499,   653,    30,   285,   656,     4,   246,   -90,     5,
       6,   286,   -90,     7,     8,   296,     9,    10,   393,   393,
     299,   310,   300,   -29,   -29,   301,   246,   246,   302,   311,
     323,   328,   814,   246,   321,   189,  -183,   351,  -192,   195,
     672,   331,  -192,   675,   468,   505,   -29,   -29,  -352,   590,
    -353,   814,    27,   321,    93,    94,   423,   503,   503,    29,
     354,   352,   324,    30,   406,   406,   406,   406,   406,   406,
     406,   355,   364,   752,   372,   375,   376,   208,   326,   398,
     377,   580,   580,   580,   580,   580,   396,   399,   400,   420,
     419,   407,   537,   593,   592,   195,   687,    34,   690,   692,
     694,   490,   208,   208,   524,   429,   702,   418,   430,   208,
     195,   195,   195,   195,   195,   504,   195,   431,   433,   445,
     274,   434,   195,   504,   291,   504,   471,   246,   472,   189,
      51,   195,   195,   195,    56,    57,    58,    59,   465,   274,
     274,    27,   473,   737,    94,   474,   274,   475,    29,   125,
      81,   488,    30,   112,   112,   489,    81,   506,   510,   158,
     201,   266,   112,   509,   521,   645,    32,   511,   535,   512,
     513,    96,   522,   340,   558,   542,   526,   144,   216,   559,
     490,   553,   112,   112,   504,   491,   504,   555,   748,   504,
     246,   221,   504,   621,   554,   393,    95,   483,   556,   487,
     503,   557,   427,   562,   505,   505,   775,   653,   503,   487,
     503,   539,   572,   603,    27,   605,    93,   112,   112,   606,
      27,    29,   607,    94,   608,    30,   614,    29,    32,   609,
     610,    30,   246,   246,   611,    81,   615,   112,   616,   781,
     274,   504,   617,   158,   589,   274,   246,   618,   794,   795,
     189,   619,   622,   346,   201,   407,   407,   407,   407,   407,
     407,   407,   737,    89,   623,   624,   195,   625,   504,   503,
     559,   503,   827,   626,   503,   628,   629,   503,   630,   631,
     632,   504,   633,   639,   407,   634,   641,   208,   346,    32,
    -210,   195,   195,   504,   642,   208,   643,   654,   195,   658,
     655,   659,   673,   274,    88,    27,   189,    93,    32,   660,
     661,   266,    29,   662,   824,   674,    30,   534,   416,   677,
     678,   528,   528,   528,   528,   528,   503,   676,   528,   528,
     541,   679,   402,   189,   -45,   208,   684,   208,   680,   681,
     682,   163,   683,   685,   593,   274,   274,   505,   698,    71,
     700,   704,   705,   503,   706,   505,   708,   505,    27,   274,
      93,    94,   644,   409,   359,    29,   503,   716,   197,    30,
     718,   717,   112,   112,   112,   201,   266,   216,   503,   490,
     112,   719,   726,   727,   799,   112,   728,   112,   732,    82,
     221,   112,   112,   112,   112,   112,   733,   734,   735,   740,
     741,   745,   112,   112,   112,   746,   749,   750,   758,   759,
     760,   112,   112,   761,   768,   769,   505,   332,   505,    27,
     349,   505,    94,   779,   505,   703,    29,   782,   786,   772,
      30,   346,  -182,   711,    81,   713,   785,   788,   792,   789,
     793,   796,   797,   518,   798,   804,   346,   346,   346,   346,
     346,   806,   346,   346,   346,   807,   822,   817,   346,   818,
     826,   197,   197,   819,   442,   825,   518,   346,   346,   346,
     312,   821,   742,   505,   707,   774,   195,   739,   805,   743,
     113,   113,   369,   313,   195,   441,   113,   202,   518,   113,
     314,   315,   763,   316,   754,   803,   197,   723,   637,   756,
     505,   492,   757,   189,   800,   787,   317,   318,   319,   113,
     113,   812,   755,   505,   762,   773,   753,   699,   481,   428,
     518,   627,   466,   308,   195,   505,   195,   409,   409,   409,
     409,   409,   409,   409,   744,   407,   598,   770,   751,   401,
     124,   688,   402,   828,   113,   113,   327,     0,     0,     0,
     303,   713,   313,     0,   127,     0,   409,     0,   304,   314,
     315,   128,   316,   112,   113,     0,     0,     0,     0,   490,
     113,     0,     0,     0,   811,   317,   318,   403,   802,     0,
     202,   202,     0,   197,     0,    27,    92,    93,    94,     0,
      78,   639,    29,     0,    79,    80,    30,     0,     0,   346,
      81,     0,   346,   639,     0,     0,   518,   518,     0,    27,
       0,   528,    94,     0,     0,   202,    29,     0,     0,     0,
      30,   725,     0,     0,    81,     0,     0,   346,   346,     0,
       0,     0,     0,     0,   346,     0,     0,     0,   124,   197,
       0,     0,     0,   125,     0,     0,     0,     0,   126,     0,
     518,   518,   127,     0,   197,   197,   197,   197,   197,   128,
     197,     0,     0,     0,     0,     0,   197,     0,     0,     0,
       0,     0,     0,     0,     0,   197,   197,   197,     0,     0,
       0,     0,     0,    27,    92,    93,    94,   767,    78,     0,
      29,     0,    79,    80,    30,   528,     0,     0,    81,   113,
     113,   113,   202,     0,     0,     0,     0,   113,     0,     0,
       0,     0,   113,     0,   113,     0,   112,   408,   113,   113,
     113,   113,   113,     0,   356,     0,     0,     0,     0,   113,
     113,   113,     0,     0,     0,     0,   346,   313,   113,   113,
       0,     0,     0,   425,   314,   315,   346,   316,     0,     0,
       0,     0,     0,     0,     0,   725,     0,     0,   202,     0,
     317,   318,   357,     0,     0,     0,     0,     0,     0,     0,
     519,     0,     0,   202,   202,   202,   202,   202,   150,   202,
     202,   202,     0,     0,     0,   202,     0,     0,   151,     0,
     112,     0,   112,   519,   202,   202,   202,     0,   150,    91,
       0,     0,     0,     0,     0,     0,     0,   409,    90,   346,
     197,   518,   346,     0,     0,   519,     0,     0,     0,    91,
     346,     0,     0,    27,    92,    93,    94,   518,    78,     0,
      29,     0,    79,    80,    30,   197,   197,     0,    81,     0,
       0,     0,   197,    27,    92,    93,    94,   519,    78,     0,
      29,     0,    79,    80,    30,     0,     0,     0,    81,     0,
     346,     0,   346,   116,   116,     0,     0,     0,     0,   159,
     205,   270,   116,   425,     0,     0,     0,     0,     0,     0,
     346,   408,   408,   408,   408,   408,   408,   408,     0,     0,
     113,    71,   116,   116,     0,   574,   574,     0,   425,   425,
     425,   425,   425,     0,   277,     0,     0,     0,     0,     0,
     408,    72,    73,    74,     0,    75,    76,     0,     0,     0,
       0,     0,     0,     0,   534,   535,   202,   116,   116,   202,
     536,    27,    77,   519,   519,     0,    78,     0,    29,     0,
      79,    80,    30,     0,     0,     0,    81,   116,   163,     0,
       0,     0,     0,   159,   202,   202,     0,     0,     0,     0,
       0,   202,   336,   347,   205,    27,    92,    93,    94,     0,
      78,     0,    29,     0,    79,    80,    30,   519,   519,     0,
      81,     0,     0,     0,     0,     0,     0,     0,   385,   209,
     210,     0,   211,   212,   213,   214,     0,     0,   347,   291,
       0,   313,   124,   292,   215,   216,   217,   218,   314,   315,
       0,   316,   219,     0,     0,   349,   127,   220,   221,   336,
     197,   270,     0,   128,   317,   318,   386,     0,   197,     0,
     222,     0,     0,     0,   664,     0,     0,     0,     0,     0,
       0,     0,     0,   113,     0,     0,     0,    27,    92,    93,
      94,   164,    78,   165,    29,     0,    79,    80,    30,     0,
       0,     0,    81,   202,     0,     0,     0,     0,   197,     0,
     197,     0,     0,   202,     0,     0,     0,     0,     0,     0,
       0,     0,   116,   116,   116,   205,   270,     0,     0,     0,
     116,     0,     0,     0,     0,   116,     0,   116,     0,     0,
       0,   116,   116,   116,   116,   116,     0,     0,     0,     0,
       0,     0,   116,   116,   116,     0,     0,   113,     0,   113,
       0,   116,   116,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   202,     0,   519,   202,
       0,   347,     0,     0,     0,     0,     0,   202,     0,     0,
       0,     0,     0,   520,   519,     0,   347,   347,   347,   347,
     347,   408,   347,   347,   347,     0,     0,     0,   347,     0,
       0,     0,     0,     0,     0,     0,   520,   347,   347,   347,
       0,     0,     0,     0,     0,     0,     0,   202,     0,   202,
     117,   117,     0,     0,     0,     0,   117,   206,   520,   117,
       0,     0,     0,    27,    92,    93,    94,   202,    78,     0,
      29,     0,    79,    80,    30,     0,   664,     0,    81,   117,
     117,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     520,     0,     0,     0,   209,   210,     0,   211,   212,   213,
     214,     0,     0,     0,     0,     0,     0,   124,     0,   215,
     216,   217,   218,     0,   117,   117,     0,   379,     0,     0,
     340,   127,   220,   221,     0,   380,     0,     0,   128,     0,
       0,     0,     0,   116,   117,   222,     0,     0,     0,     0,
     117,     0,     0,     0,     0,     0,     0,     0,     0,   337,
     206,   206,    27,    92,    93,    94,   164,    78,   165,    29,
       0,    79,    80,    30,     0,     0,     0,    81,     0,   347,
       0,     0,   347,     0,     0,     0,   520,   520,     0,     0,
       0,     0,     0,     0,     0,   206,     0,     0,     0,     0,
     209,   210,    90,   211,     0,     0,   336,   347,   347,     0,
       0,     0,     0,    91,   347,   215,   337,   571,   572,     0,
       0,     0,     0,   573,     0,     0,     0,     0,   220,     0,
     520,   520,     0,     0,     0,     0,     0,    27,    92,    93,
      94,   222,    78,   336,    29,     0,    79,    80,    30,     0,
       0,     0,    81,     0,     0,     0,     0,     0,    27,    92,
      93,    94,     0,    78,     0,    29,     0,    79,    80,    30,
       0,     0,     0,    81,     0,     0,   124,     0,     0,   117,
     117,   117,   206,     0,     0,     0,   303,   117,     0,     0,
     127,     0,   117,     0,   117,     0,   116,   128,   117,   117,
     117,   117,   117,     0,     0,     0,     0,     0,     0,   117,
     117,   117,     0,     0,     0,     0,   347,     0,   117,   117,
       0,    27,    92,    93,    94,     0,    78,     0,    29,     0,
      79,    80,    30,   114,   114,     0,    81,     0,   206,   114,
     203,     0,   114,     0,     0,     0,     0,     0,     0,     0,
     337,     0,     0,   206,   206,   206,   206,   206,     0,   206,
     206,   206,   114,   114,     0,   206,     0,     0,     0,     0,
     116,     0,   116,   337,   206,   206,   206,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   209,   210,   347,
     211,   520,   347,     0,     0,   337,     0,   114,   114,     0,
     347,   385,   215,     0,   571,   572,     0,   520,     0,     0,
     663,     0,   291,     0,   313,   220,   292,   114,     0,   729,
     365,   314,   315,   114,   316,   730,     0,   337,   222,     0,
       0,     0,   334,   203,   203,     0,   128,   317,   318,   386,
     347,     0,   347,     0,     0,    27,    92,    93,    94,   644,
      78,     0,    29,     0,    79,    80,    30,     0,   385,   209,
     210,     0,   211,   212,   213,   214,   165,     0,   203,   291,
     117,   313,   124,   292,   215,   216,   217,   218,   314,   315,
       0,   316,   379,     0,     0,   349,   127,   220,   221,   334,
       0,     0,     0,   128,   317,   318,   386,     0,     0,     0,
     222,     0,     0,     0,     0,     0,   206,     0,     0,   206,
       0,     0,     0,   337,   337,     0,     0,    27,    92,    93,
      94,   164,    78,   165,    29,     0,    79,    80,    30,     0,
       0,     0,    81,   337,   206,   206,     0,     0,     0,     0,
       0,   206,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   114,   114,   114,   203,     0,   337,   337,   288,
     114,     0,     0,     0,     0,   114,     0,   114,     0,     0,
     337,   114,   114,   114,   114,   114,     0,     0,     0,     0,
       0,     0,   114,   114,   114,     0,     0,     0,     0,     0,
       0,   114,   114,     0,    27,    92,    93,    94,     0,    78,
       0,    29,     0,    79,    80,    30,   115,   115,     0,    81,
       0,   203,   115,   204,     0,   115,     0,     0,     0,     0,
       0,     0,     0,   117,     0,     0,   203,   203,   203,   203,
     203,     0,   203,   203,   203,   115,   115,    71,   203,     0,
       0,     0,     0,   206,     0,     0,   547,   203,   203,   203,
       0,     0,     0,     0,     0,     0,     0,    72,    73,    74,
       0,    75,    76,     0,     0,     0,     0,     0,     0,     0,
     115,   115,     0,     0,     0,     0,     0,    27,    77,     0,
       0,     0,    78,     0,    29,     0,    79,    80,    30,     0,
     115,     0,    81,     0,     0,     0,   115,   117,     0,   117,
     547,     0,     0,     0,     0,   335,   204,   204,     0,     0,
       0,     0,     0,     0,     0,     0,   206,     0,   337,   206,
       0,     0,     0,     0,     0,     0,     0,   206,     0,     0,
       0,     0,   209,   210,   337,   211,   212,   213,   214,     0,
       0,   204,     0,   114,     0,   124,     0,   215,   216,   217,
     218,     0,     0,     0,     0,   379,     0,     0,     0,   127,
     220,   221,   335,   380,     0,     0,   128,   206,     0,   206,
       0,     0,     0,   222,     0,     0,     0,     0,     0,   203,
       0,     0,   203,     0,   449,     0,     0,     0,     0,     0,
      27,    92,    93,    94,   164,    78,   165,    29,     0,    79,
      80,    30,     0,     0,     0,    81,   334,   203,   203,     0,
       0,   450,   451,     0,   203,   452,   453,     0,     0,   454,
       0,     0,   455,     0,    27,   115,   115,   115,   204,    28,
       0,    29,     0,   115,     0,    30,     0,     0,   115,     0,
     115,     0,    91,   334,   115,   115,   115,   115,   115,     0,
       0,     0,     0,     0,     0,   115,   115,   115,     0,     0,
       0,     0,     0,     0,   115,   115,    27,    92,    93,    94,
       0,    78,     0,    29,     0,    79,    80,    30,     0,   118,
     118,    81,     0,     0,   204,   118,   207,     0,   118,     0,
       0,     0,     0,     0,     0,     0,   114,     0,     0,   204,
     204,   204,   204,   204,     0,   204,   204,   204,   118,   118,
     449,   204,     0,     0,     0,     0,   203,     0,     0,   335,
     204,   204,   204,   813,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   450,   451,     0,
       0,   452,   453,   118,   118,   454,     0,     0,   455,     0,
      27,     0,     0,     0,     0,    28,     0,    29,     0,     0,
       0,    30,     0,   118,     0,     0,     0,     0,     0,   118,
     114,     0,   114,   335,     0,     0,     0,     0,     0,   348,
     207,     0,     0,     0,     0,     0,     0,     0,     0,   203,
     145,     0,   203,     0,     0,     0,   199,     0,   145,     0,
     203,     0,   209,   210,     0,   211,   212,   213,   214,     0,
       0,     0,     0,     0,     0,   124,   115,   215,   216,   217,
     218,     0,     0,     0,     0,   219,     0,     0,     0,   127,
     220,   221,     0,     0,     0,     0,   128,     0,     0,     0,
     203,     0,   203,   222,     0,     0,     0,     0,     0,     0,
       0,     0,   204,   145,   145,   204,     0,     0,     0,     0,
      27,    92,    93,    94,   164,    78,   165,    29,     0,    79,
      80,    30,     0,   145,     0,    81,     0,     0,     0,   335,
     204,   204,     0,     0,     0,     0,     0,   204,     0,   199,
     199,     0,     0,     0,     0,     0,     0,     0,   118,   118,
     118,   207,     0,     0,   151,     0,   118,     0,     0,     0,
       0,   118,     0,   118,     0,    91,   335,   118,   118,   118,
     118,   118,     0,     0,   199,     0,     0,     0,   118,   118,
     118,     0,     0,     0,     0,     0,     0,   118,   118,    27,
      92,    93,    94,     0,    78,     0,    29,     0,    79,    80,
      30,     0,     0,     0,    81,     0,     0,   207,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   115,
       0,     0,   207,   207,   207,   207,   207,   124,   348,   207,
     207,   160,   365,     0,   207,     0,     0,   366,     0,   204,
       0,   127,     0,   348,   348,   348,     0,     0,   128,     0,
       0,     0,     0,     0,     0,   163,     0,     0,     0,   145,
       0,   199,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,     0,    93,    94,   164,     0,   165,    29,
       0,   145,     0,    30,     0,     0,     0,    81,   145,   145,
     145,     0,     0,   115,     0,   115,     0,   145,   145,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   204,     0,     0,   204,     0,   199,     0,     0,
       0,     0,     0,   204,     0,     0,     0,     0,     0,     0,
       0,     0,   199,   199,   199,   199,   199,     0,   199,   118,
       0,     0,     0,     0,   199,     0,     0,     0,     0,     0,
       0,     0,     0,   199,   199,   199,     0,     0,     0,     0,
       0,     0,     0,   204,     0,   204,     0,     0,     0,     0,
     385,   209,   210,     0,   211,   212,   213,   214,   348,     0,
       0,   291,     0,   313,   124,   292,   215,   216,   217,   218,
     314,   315,     0,   316,   379,     0,     0,     0,   127,   220,
     221,     0,     0,   348,   207,   128,   317,   318,   386,     0,
     348,     0,   222,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
      92,    93,    94,   164,    78,   165,    29,     0,    79,    80,
      30,     0,   209,   210,    81,   211,   212,   213,   214,   145,
       0,     0,     0,     0,     0,   124,     0,   215,   216,   217,
     218,     0,     0,     0,     0,   379,     0,     0,     0,   127,
     220,   221,     0,     0,     0,     0,   128,     0,     0,     0,
       0,     0,     0,   222,     0,     0,     0,     0,   199,     0,
       0,     0,   118,     0,     0,     0,     0,     0,     0,     0,
      27,    92,    93,    94,   164,    78,   165,    29,     0,    79,
      80,    30,   207,   199,   199,    81,     0,     0,   209,   210,
     199,   211,   212,   213,   214,     0,     0,     0,     0,     0,
       0,   124,     0,   215,   216,   217,   218,     0,     0,     0,
       0,   421,     0,     0,     0,   127,   220,   221,     0,     0,
       0,     0,   128,     0,     0,     0,     0,     0,     0,   222,
       0,     0,     0,     0,     0,     0,   118,     0,   118,     0,
       0,     0,     0,     0,     0,     0,    27,    92,    93,    94,
     164,    78,   165,    29,     0,    79,    80,    30,   348,   209,
     210,    81,   211,   212,   213,   214,   207,     0,     0,     0,
       0,     0,   124,     0,   215,   216,   217,   736,     0,     0,
       0,     0,   379,     0,     0,     0,   127,   220,   221,     0,
       0,     0,     0,   128,     0,     0,     0,     0,     0,     0,
     222,     0,     0,     0,     0,     0,   348,     0,   348,     0,
       0,     0,     0,     0,     0,     0,     0,    27,    92,    93,
      94,   164,    78,   165,    29,     0,    79,    80,    30,     0,
       0,     0,    81,     0,   209,   210,     0,   211,   212,   213,
     214,     0,     0,     0,     0,     0,   145,   124,     0,   215,
     216,   571,   572,     0,     0,     0,     0,   579,     0,     0,
       0,   127,   220,   221,     0,     0,     0,     0,   199,     0,
       0,     0,     0,     0,     0,   222,   199,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,    92,    93,    94,   164,    78,     0,    29,
       0,    79,    80,    30,     0,     0,     0,    81,     0,   124,
       0,     0,     0,   160,   161,     0,   199,     0,   199,   339,
       0,     0,   340,   127,     0,     0,     0,   341,     0,     0,
     128,     0,     0,     0,     0,     0,     0,   163,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,    92,    93,    94,   164,    78,
     165,    29,   124,    79,    80,    30,   160,   161,     0,    81,
       0,     0,   162,     0,     0,   349,   127,     0,     0,     0,
       0,     0,     0,   128,     0,     0,     0,     0,     0,     0,
     163,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,    92,    93,
      94,   164,    78,   165,    29,   124,    79,    80,    30,   160,
     161,     0,    81,     0,     0,   339,     0,     0,   349,   127,
       0,     0,     0,     0,     0,     0,   128,     0,     0,     0,
       0,     0,     0,   163,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,    92,    93,    94,   164,    78,   165,    29,   124,    79,
      80,    30,   160,   161,     0,    81,     0,     0,   339,     0,
       0,     0,   127,     0,     0,     0,   341,     0,     0,   128,
       0,     0,     0,     0,     0,     0,   163,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27,    92,    93,    94,   164,    78,   165,
      29,   124,    79,    80,    30,   160,   161,     0,    81,     0,
       0,   162,     0,     0,     0,   127,     0,     0,     0,     0,
       0,     0,   128,     0,     0,     0,     0,     0,     0,   163,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    27,    92,    93,    94,
     164,    78,   165,    29,   124,    79,    80,    30,   160,   161,
       0,    81,     0,     0,   339,     0,     0,     0,   127,     0,
       0,     0,     0,     0,     0,   128,     0,     0,     0,     0,
       0,     0,   163,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
      92,    93,    94,   164,    78,   165,    29,     0,    79,    80,
      30,     0,     0,     0,    81
};

static const yytype_int16 yycheck[] =
{
       0,    60,    20,    21,    22,    23,    24,    25,    26,   145,
      60,    91,    71,    20,    21,   238,    23,    24,    25,    26,
     145,   296,   360,    69,   219,   145,   217,   491,    68,    69,
     427,    70,    61,   286,    52,    35,   507,    68,    67,    69,
     260,    62,    60,   301,   302,    52,   331,    65,    13,    70,
     143,   219,   372,    71,   551,    67,    68,    61,    65,   361,
     362,    90,    91,    67,   354,   355,   356,   357,   358,   188,
     125,   126,   196,   354,   355,   356,   357,   358,   282,   416,
     354,   355,   356,   357,   358,   654,    90,    27,    61,   293,
     427,   295,   551,    11,    34,   282,   300,   301,   302,   415,
     416,   417,   418,   419,   125,   126,   293,    25,   295,   129,
      37,   427,   107,   300,   301,   302,    14,    90,    22,   138,
      18,    30,   151,    27,   145,    11,   245,    60,   107,   147,
      22,   162,    27,   153,    61,    68,    69,    27,    71,    25,
     147,   429,   430,   431,   196,    37,   166,   151,   282,   619,
     234,   720,    27,   246,   173,    64,    65,    11,    62,   293,
      64,   295,   375,   376,   377,    69,   300,   301,   302,    73,
     390,    25,   218,   219,   310,   311,   312,    27,   151,   219,
     433,    27,    11,   319,   320,   310,   311,   312,    34,   219,
     310,   311,   312,   188,   319,   320,    25,    64,    65,   319,
     320,   396,   282,   223,    27,   490,   491,    27,   288,   188,
      14,   379,   231,   293,    18,   295,    37,    36,    37,   788,
     300,   301,   302,    12,    13,    29,   285,   286,   161,   162,
     354,   355,   356,   357,   358,   285,   733,    22,   284,    13,
      61,    14,   281,   283,   284,    18,   717,    27,   303,    70,
     245,   280,   283,   421,   284,   275,   412,   413,    13,   288,
     281,    35,    36,   196,    13,   553,   245,   285,   286,    14,
     299,   283,    69,    18,   733,   745,   280,    62,   296,   749,
     750,   678,   303,    14,    69,   218,   219,    18,    73,   310,
     311,   312,    14,    15,    13,   299,    18,   510,   319,   320,
      13,   234,   354,   355,   356,   357,   358,   280,   339,   361,
     362,   290,   632,   331,   398,   399,   400,   401,   402,   403,
     404,    62,   642,    13,    68,    13,    67,   260,    69,   542,
     430,   431,    73,   379,   374,   366,    13,    12,    13,   351,
     745,   678,   644,   427,   749,   750,    22,   811,    13,   379,
     283,   284,   285,   286,    12,    13,   396,    36,    35,    36,
      35,    36,   678,   558,   559,   411,   624,    27,   414,    28,
      35,    36,    14,    15,   433,   421,    18,    35,    36,    37,
     571,   411,    13,   429,   430,   431,    62,    13,   428,    13,
     323,   421,    14,    69,    30,   328,    18,    73,   331,    13,
     234,    13,    62,    61,    64,   573,   339,   797,   798,    69,
      14,   579,    70,    73,    18,   433,   471,   161,   162,   704,
     624,   354,   355,   356,   357,   358,   260,   360,   361,   362,
     768,   449,   770,   366,    13,    13,    35,   624,   728,   372,
      13,   664,   375,   376,   377,    14,   379,   728,    13,    18,
     471,    27,   196,    13,   728,   507,   456,   390,     0,    27,
      14,    27,    35,    36,    18,   398,   399,   400,   401,   402,
     403,   404,   490,   491,    27,    35,    36,    14,   411,   412,
     413,    18,   415,   416,   417,   418,   419,   420,   421,    14,
     624,    27,    62,    18,   427,   663,   429,   430,   431,    69,
     433,   786,   514,    73,    11,   536,    48,   553,    14,    51,
      52,    27,    18,    55,    56,    13,    58,    59,   558,   559,
      41,    41,    27,    12,    13,    27,   572,   573,    27,     3,
      22,    22,   807,   579,    29,    68,    12,    27,    14,   283,
     735,    11,    18,   573,   624,   331,    35,    36,    11,   579,
      11,   826,    62,    29,    64,    65,   390,   490,   491,    69,
      41,    30,   698,    73,   398,   399,   400,   401,   402,   403,
     404,     3,     6,   698,    22,    27,    27,   510,   698,    41,
      27,   415,   416,   417,   418,   419,    27,     3,     6,    22,
      70,   234,   644,   427,   678,   339,   614,   615,   616,   617,
     618,    22,   535,   536,   728,    27,    27,    37,    27,   542,
     354,   355,   356,   357,   358,   633,   360,    27,    13,    36,
     553,    35,   366,   641,    14,   643,    13,   673,    35,   162,
      41,   375,   376,   377,    45,    46,    47,    48,    36,   572,
     573,    62,    36,   673,    65,    36,   579,    36,    69,    22,
      77,    36,    73,    61,    62,    36,    77,    34,    13,    67,
      68,    69,    70,    35,    61,   717,   684,    35,    22,    36,
      36,   700,    36,    30,    22,    27,   728,   698,    20,    27,
      22,    13,    90,    91,   702,    27,   704,    36,   688,   707,
     736,    33,   710,   693,    35,   735,   700,   630,    36,   632,
     633,    36,    11,    36,   490,   491,   736,   719,   641,   642,
     643,   644,    22,    36,    62,    36,    64,   125,   126,    36,
      62,    69,    36,    65,    36,    73,    27,    69,   746,    36,
      36,    73,   778,   779,    36,    77,    27,   145,    27,   746,
     673,   759,    27,   151,   677,   678,   792,    27,   778,   779,
     283,    13,    30,   161,   162,   398,   399,   400,   401,   402,
     403,   404,   792,   822,    36,    13,   510,    36,   786,   702,
      27,   704,   822,    36,   707,    30,    35,   710,    13,    35,
      13,   799,    11,   491,   427,    30,    61,   720,   196,   807,
      61,   535,   536,   811,    22,   728,    27,    13,   542,    36,
      30,    35,    13,   736,   822,    62,   339,    64,   826,    36,
      36,   219,    69,    36,   814,    30,    73,    21,    61,    13,
      11,   354,   355,   356,   357,   358,   759,    35,   361,   362,
     363,    36,     6,   366,     6,   768,    13,   770,    36,    36,
      36,    45,    30,    35,   678,   778,   779,   633,    11,    22,
      11,    13,    35,   786,    36,   641,    36,   643,    62,   792,
      64,    65,    66,   234,    15,    69,   799,    36,    68,    73,
      35,    13,   280,   281,   282,   283,   284,    20,   811,    22,
     288,    13,    36,    36,    27,   293,    11,   295,    36,   822,
      33,   299,   300,   301,   302,   303,    13,    35,    13,    36,
      11,    13,   310,   311,   312,    13,    13,    13,    35,    13,
      36,   319,   320,    34,    13,    12,   702,    30,   704,    62,
      30,   707,    65,    13,   710,   633,    69,    36,    11,    34,
      73,   339,    12,   641,    77,   643,    36,    13,    13,    35,
      35,    13,    13,   351,    13,    36,   354,   355,   356,   357,
     358,    36,   360,   361,   362,    22,    11,    36,   366,    36,
      13,   161,   162,    36,   284,    35,   374,   375,   376,   377,
       3,    36,   677,   759,    37,   735,   720,   673,   792,   678,
      61,    62,   196,    16,   728,   283,    67,    68,   396,    70,
      23,    24,   719,    26,   702,   788,   196,   654,   491,   707,
     786,   331,   710,   536,   786,   759,    39,    40,    41,    90,
      91,   799,   704,   799,   717,   733,   700,   630,   322,   265,
     428,   471,   299,   126,   768,   811,   770,   398,   399,   400,
     401,   402,   403,   404,   684,   678,   428,   724,   693,     3,
      17,   615,     6,   826,   125,   126,   147,    -1,    -1,    -1,
      27,   759,    16,    -1,    31,    -1,   427,    -1,    35,    23,
      24,    38,    26,   471,   145,    -1,    -1,    -1,    -1,    22,
     151,    -1,    -1,    -1,    27,    39,    40,    41,   786,    -1,
     161,   162,    -1,   283,    -1,    62,    63,    64,    65,    -1,
      67,   799,    69,    -1,    71,    72,    73,    -1,    -1,   507,
      77,    -1,   510,   811,    -1,    -1,   514,   515,    -1,    62,
      -1,   644,    65,    -1,    -1,   196,    69,    -1,    -1,    -1,
      73,   654,    -1,    -1,    77,    -1,    -1,   535,   536,    -1,
      -1,    -1,    -1,    -1,   542,    -1,    -1,    -1,    17,   339,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    27,    -1,
     558,   559,    31,    -1,   354,   355,   356,   357,   358,    38,
     360,    -1,    -1,    -1,    -1,    -1,   366,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   375,   376,   377,    -1,    -1,
      -1,    -1,    -1,    62,    63,    64,    65,   720,    67,    -1,
      69,    -1,    71,    72,    73,   728,    -1,    -1,    77,   280,
     281,   282,   283,    -1,    -1,    -1,    -1,   288,    -1,    -1,
      -1,    -1,   293,    -1,   295,    -1,   624,   234,   299,   300,
     301,   302,   303,    -1,     3,    -1,    -1,    -1,    -1,   310,
     311,   312,    -1,    -1,    -1,    -1,   644,    16,   319,   320,
      -1,    -1,    -1,   260,    23,    24,   654,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   788,    -1,    -1,   339,    -1,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     351,    -1,    -1,   354,   355,   356,   357,   358,    17,   360,
     361,   362,    -1,    -1,    -1,   366,    -1,    -1,    27,    -1,
     698,    -1,   700,   374,   375,   376,   377,    -1,    17,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   678,    27,   717,
     510,   719,   720,    -1,    -1,   396,    -1,    -1,    -1,    38,
     728,    -1,    -1,    62,    63,    64,    65,   735,    67,    -1,
      69,    -1,    71,    72,    73,   535,   536,    -1,    77,    -1,
      -1,    -1,   542,    62,    63,    64,    65,   428,    67,    -1,
      69,    -1,    71,    72,    73,    -1,    -1,    -1,    77,    -1,
     768,    -1,   770,    61,    62,    -1,    -1,    -1,    -1,    67,
      68,    69,    70,   390,    -1,    -1,    -1,    -1,    -1,    -1,
     788,   398,   399,   400,   401,   402,   403,   404,    -1,    -1,
     471,    22,    90,    91,    -1,   412,   413,    -1,   415,   416,
     417,   418,   419,    -1,    35,    -1,    -1,    -1,    -1,    -1,
     427,    42,    43,    44,    -1,    46,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    22,   507,   125,   126,   510,
      27,    62,    63,   514,   515,    -1,    67,    -1,    69,    -1,
      71,    72,    73,    -1,    -1,    -1,    77,   145,    45,    -1,
      -1,    -1,    -1,   151,   535,   536,    -1,    -1,    -1,    -1,
      -1,   542,   160,   161,   162,    62,    63,    64,    65,    -1,
      67,    -1,    69,    -1,    71,    72,    73,   558,   559,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,    -1,     7,     8,     9,    10,    -1,    -1,   196,    14,
      -1,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,    26,    27,    -1,    -1,    30,    31,    32,    33,   217,
     720,   219,    -1,    38,    39,    40,    41,    -1,   728,    -1,
      45,    -1,    -1,    -1,   551,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   624,    -1,    -1,    -1,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    71,    72,    73,    -1,
      -1,    -1,    77,   644,    -1,    -1,    -1,    -1,   768,    -1,
     770,    -1,    -1,   654,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   280,   281,   282,   283,   284,    -1,    -1,    -1,
     288,    -1,    -1,    -1,    -1,   293,    -1,   295,    -1,    -1,
      -1,   299,   300,   301,   302,   303,    -1,    -1,    -1,    -1,
      -1,    -1,   310,   311,   312,    -1,    -1,   698,    -1,   700,
      -1,   319,   320,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   717,    -1,   719,   720,
      -1,   339,    -1,    -1,    -1,    -1,    -1,   728,    -1,    -1,
      -1,    -1,    -1,   351,   735,    -1,   354,   355,   356,   357,
     358,   678,   360,   361,   362,    -1,    -1,    -1,   366,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   374,   375,   376,   377,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   768,    -1,   770,
      61,    62,    -1,    -1,    -1,    -1,    67,    68,   396,    70,
      -1,    -1,    -1,    62,    63,    64,    65,   788,    67,    -1,
      69,    -1,    71,    72,    73,    -1,   733,    -1,    77,    90,
      91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     428,    -1,    -1,    -1,     4,     5,    -1,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    19,
      20,    21,    22,    -1,   125,   126,    -1,    27,    -1,    -1,
      30,    31,    32,    33,    -1,    35,    -1,    -1,    38,    -1,
      -1,    -1,    -1,   471,   145,    45,    -1,    -1,    -1,    -1,
     151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,
     161,   162,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    72,    73,    -1,    -1,    -1,    77,    -1,   507,
      -1,    -1,   510,    -1,    -1,    -1,   514,   515,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,
       4,     5,    27,     7,    -1,    -1,   534,   535,   536,    -1,
      -1,    -1,    -1,    38,   542,    19,   217,    21,    22,    -1,
      -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,    32,    -1,
     558,   559,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,
      65,    45,    67,   571,    69,    -1,    71,    72,    73,    -1,
      -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    62,    63,
      64,    65,    -1,    67,    -1,    69,    -1,    71,    72,    73,
      -1,    -1,    -1,    77,    -1,    -1,    17,    -1,    -1,   280,
     281,   282,   283,    -1,    -1,    -1,    27,   288,    -1,    -1,
      31,    -1,   293,    -1,   295,    -1,   624,    38,   299,   300,
     301,   302,   303,    -1,    -1,    -1,    -1,    -1,    -1,   310,
     311,   312,    -1,    -1,    -1,    -1,   644,    -1,   319,   320,
      -1,    62,    63,    64,    65,    -1,    67,    -1,    69,    -1,
      71,    72,    73,    61,    62,    -1,    77,    -1,   339,    67,
      68,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     351,    -1,    -1,   354,   355,   356,   357,   358,    -1,   360,
     361,   362,    90,    91,    -1,   366,    -1,    -1,    -1,    -1,
     698,    -1,   700,   374,   375,   376,   377,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,   717,
       7,   719,   720,    -1,    -1,   396,    -1,   125,   126,    -1,
     728,     3,    19,    -1,    21,    22,    -1,   735,    -1,    -1,
      27,    -1,    14,    -1,    16,    32,    18,   145,    -1,    21,
      22,    23,    24,   151,    26,    27,    -1,   428,    45,    -1,
      -1,    -1,   160,   161,   162,    -1,    38,    39,    40,    41,
     768,    -1,   770,    -1,    -1,    62,    63,    64,    65,    66,
      67,    -1,    69,    -1,    71,    72,    73,    -1,     3,     4,
       5,    -1,     7,     8,     9,    10,    68,    -1,   196,    14,
     471,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,    26,    27,    -1,    -1,    30,    31,    32,    33,   217,
      -1,    -1,    -1,    38,    39,    40,    41,    -1,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    -1,   507,    -1,    -1,   510,
      -1,    -1,    -1,   514,   515,    -1,    -1,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    71,    72,    73,    -1,
      -1,    -1,    77,   534,   535,   536,    -1,    -1,    -1,    -1,
      -1,   542,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   280,   281,   282,   283,    -1,   558,   559,    27,
     288,    -1,    -1,    -1,    -1,   293,    -1,   295,    -1,    -1,
     571,   299,   300,   301,   302,   303,    -1,    -1,    -1,    -1,
      -1,    -1,   310,   311,   312,    -1,    -1,    -1,    -1,    -1,
      -1,   319,   320,    -1,    62,    63,    64,    65,    -1,    67,
      -1,    69,    -1,    71,    72,    73,    61,    62,    -1,    77,
      -1,   339,    67,    68,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   624,    -1,    -1,   354,   355,   356,   357,
     358,    -1,   360,   361,   362,    90,    91,    22,   366,    -1,
      -1,    -1,    -1,   644,    -1,    -1,   374,   375,   376,   377,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,
      -1,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     125,   126,    -1,    -1,    -1,    -1,    -1,    62,    63,    -1,
      -1,    -1,    67,    -1,    69,    -1,    71,    72,    73,    -1,
     145,    -1,    77,    -1,    -1,    -1,   151,   698,    -1,   700,
     428,    -1,    -1,    -1,    -1,   160,   161,   162,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   717,    -1,   719,   720,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   728,    -1,    -1,
      -1,    -1,     4,     5,   735,     7,     8,     9,    10,    -1,
      -1,   196,    -1,   471,    -1,    17,    -1,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    31,
      32,    33,   217,    35,    -1,    -1,    38,   768,    -1,   770,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,   507,
      -1,    -1,   510,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    71,
      72,    73,    -1,    -1,    -1,    77,   534,   535,   536,    -1,
      -1,    49,    50,    -1,   542,    53,    54,    -1,    -1,    57,
      -1,    -1,    60,    -1,    62,   280,   281,   282,   283,    67,
      -1,    69,    -1,   288,    -1,    73,    -1,    -1,   293,    -1,
     295,    -1,    38,   571,   299,   300,   301,   302,   303,    -1,
      -1,    -1,    -1,    -1,    -1,   310,   311,   312,    -1,    -1,
      -1,    -1,    -1,    -1,   319,   320,    62,    63,    64,    65,
      -1,    67,    -1,    69,    -1,    71,    72,    73,    -1,    61,
      62,    77,    -1,    -1,   339,    67,    68,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   624,    -1,    -1,   354,
     355,   356,   357,   358,    -1,   360,   361,   362,    90,    91,
      22,   366,    -1,    -1,    -1,    -1,   644,    -1,    -1,   374,
     375,   376,   377,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,
      -1,    53,    54,   125,   126,    57,    -1,    -1,    60,    -1,
      62,    -1,    -1,    -1,    -1,    67,    -1,    69,    -1,    -1,
      -1,    73,    -1,   145,    -1,    -1,    -1,    -1,    -1,   151,
     698,    -1,   700,   428,    -1,    -1,    -1,    -1,    -1,   161,
     162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   717,
      62,    -1,   720,    -1,    -1,    -1,    68,    -1,    70,    -1,
     728,    -1,     4,     5,    -1,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,   471,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    31,
      32,    33,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
     768,    -1,   770,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   507,   125,   126,   510,    -1,    -1,    -1,    -1,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    71,
      72,    73,    -1,   145,    -1,    77,    -1,    -1,    -1,   534,
     535,   536,    -1,    -1,    -1,    -1,    -1,   542,    -1,   161,
     162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   280,   281,
     282,   283,    -1,    -1,    27,    -1,   288,    -1,    -1,    -1,
      -1,   293,    -1,   295,    -1,    38,   571,   299,   300,   301,
     302,   303,    -1,    -1,   196,    -1,    -1,    -1,   310,   311,
     312,    -1,    -1,    -1,    -1,    -1,    -1,   319,   320,    62,
      63,    64,    65,    -1,    67,    -1,    69,    -1,    71,    72,
      73,    -1,    -1,    -1,    77,    -1,    -1,   339,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   624,
      -1,    -1,   354,   355,   356,   357,   358,    17,   360,   361,
     362,    21,    22,    -1,   366,    -1,    -1,    27,    -1,   644,
      -1,    31,    -1,   375,   376,   377,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,   281,
      -1,   283,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    -1,    64,    65,    66,    -1,    68,    69,
      -1,   303,    -1,    73,    -1,    -1,    -1,    77,   310,   311,
     312,    -1,    -1,   698,    -1,   700,    -1,   319,   320,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   717,    -1,    -1,   720,    -1,   339,    -1,    -1,
      -1,    -1,    -1,   728,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   354,   355,   356,   357,   358,    -1,   360,   471,
      -1,    -1,    -1,    -1,   366,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   375,   376,   377,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   768,    -1,   770,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,     7,     8,     9,    10,   510,    -1,
      -1,    14,    -1,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    26,    27,    -1,    -1,    -1,    31,    32,
      33,    -1,    -1,   535,   536,    38,    39,    40,    41,    -1,
     542,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    71,    72,
      73,    -1,     4,     5,    77,     7,     8,     9,    10,   471,
      -1,    -1,    -1,    -1,    -1,    17,    -1,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    31,
      32,    33,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,   510,    -1,
      -1,    -1,   624,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    71,
      72,    73,   644,   535,   536,    77,    -1,    -1,     4,     5,
     542,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    27,    -1,    -1,    -1,    31,    32,    33,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    -1,   698,    -1,   700,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,   720,     4,
       5,    77,     7,     8,     9,    10,   728,    -1,    -1,    -1,
      -1,    -1,    17,    -1,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    27,    -1,    -1,    -1,    31,    32,    33,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    -1,   768,    -1,   770,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    71,    72,    73,    -1,
      -1,    -1,    77,    -1,     4,     5,    -1,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,   698,    17,    -1,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    27,    -1,    -1,
      -1,    31,    32,    33,    -1,    -1,    -1,    -1,   720,    -1,
      -1,    -1,    -1,    -1,    -1,    45,   728,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    63,    64,    65,    66,    67,    -1,    69,
      -1,    71,    72,    73,    -1,    -1,    -1,    77,    -1,    17,
      -1,    -1,    -1,    21,    22,    -1,   768,    -1,   770,    27,
      -1,    -1,    30,    31,    -1,    -1,    -1,    35,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    63,    64,    65,    66,    67,
      68,    69,    17,    71,    72,    73,    21,    22,    -1,    77,
      -1,    -1,    27,    -1,    -1,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,
      65,    66,    67,    68,    69,    17,    71,    72,    73,    21,
      22,    -1,    77,    -1,    -1,    27,    -1,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    63,    64,    65,    66,    67,    68,    69,    17,    71,
      72,    73,    21,    22,    -1,    77,    -1,    -1,    27,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    63,    64,    65,    66,    67,    68,
      69,    17,    71,    72,    73,    21,    22,    -1,    77,    -1,
      -1,    27,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,    65,
      66,    67,    68,    69,    17,    71,    72,    73,    21,    22,
      -1,    77,    -1,    -1,    27,    -1,    -1,    -1,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    71,    72,
      73,    -1,    -1,    -1,    77
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,    79,   305,     0,    48,    51,    52,    55,    56,    58,
      59,    80,    81,    82,    84,    85,    86,    87,    88,   288,
      27,    27,    27,    27,    27,    27,    27,    62,    67,    69,
      73,   299,   300,   299,   300,   304,   299,   299,   299,   299,
      13,    13,    13,   289,   305,    13,    13,    13,    13,    69,
      90,    90,    22,    37,   290,    36,    90,    90,    90,    90,
      28,    13,    13,   291,   299,    13,    30,    13,    13,    13,
      13,    22,    42,    43,    44,    46,    47,    63,    67,    71,
      72,    77,   267,   293,   294,   295,   296,   297,   300,   303,
      27,    38,    63,    64,    65,   211,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   228,   229,   233,
     234,   235,   258,   259,   260,   261,   262,   263,   266,   267,
     300,   301,   302,   303,    17,    22,    27,    31,    38,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   216,   230,   231,   243,   246,    35,    13,   292,   299,
      17,    27,   174,   200,   201,   202,   233,   254,   258,   262,
      21,    22,    27,    45,    66,    68,   138,   139,   140,   141,
     142,   143,   144,   145,   147,   148,   149,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   169,   171,   172,
     174,   186,   187,   188,   193,   199,   241,   242,   243,   246,
     254,   258,   259,   260,   261,   262,   263,   266,   267,     4,
       5,     7,     8,     9,    10,    19,    20,    21,    22,    27,
      32,    33,    45,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   101,   102,   103,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   121,   123,   124,   127,   129,
     131,   132,   133,   134,   135,   136,   137,   189,   199,   236,
     237,   238,   239,   242,   246,   254,   258,   259,   260,   261,
     262,   263,   265,   266,   267,    83,   203,    35,   293,   298,
      27,    27,    27,    27,    27,    11,    27,   233,    27,   216,
     228,    14,    18,   255,   256,   257,    13,    89,   305,    41,
      27,    27,    27,    27,    35,   204,   232,   204,   230,    89,
      41,     3,     3,    16,    23,    24,    26,    39,    40,    41,
     244,    29,   247,    22,   210,   212,   213,   291,    22,   174,
      89,    11,    30,   197,   260,   261,   262,   263,   264,    27,
      30,    35,   139,   170,   172,   173,   258,   262,   266,    30,
     139,    27,    30,    89,    41,     3,     3,    41,   244,    15,
     249,   255,   257,   247,     6,    22,    27,   146,   147,   154,
     156,   267,    22,    25,   240,    27,    27,    27,   197,    27,
      35,    92,   126,   258,   262,     3,    41,    92,   122,   127,
     237,   244,   245,   254,   256,   257,    27,    89,    41,     3,
       6,     3,     6,    41,   244,    99,   101,   106,   109,   113,
     123,   249,   255,   257,   247,    37,    61,    70,    37,    70,
      22,    27,   100,   101,   107,   109,   267,    11,   240,    27,
      27,    27,    89,    13,    35,   233,   203,   222,   225,   226,
     228,   138,    91,   293,   298,    36,   216,   228,   228,    22,
      49,    50,    53,    54,    57,    60,   268,   270,   271,   273,
     275,   276,   278,   280,   299,    36,   235,   227,   228,   227,
     227,    13,    35,    36,    36,    36,   212,   212,   212,   212,
     212,   231,   215,   267,   150,   151,   152,   267,    36,    36,
      22,    27,   175,   176,   177,   179,   180,   182,   184,   239,
     250,   251,   252,   267,   300,   301,    34,    27,    34,    35,
      13,    35,    36,    36,    22,    27,   163,   174,   258,   259,
     262,    61,    36,   145,   147,   153,   156,   160,   172,   145,
     145,   145,   145,   170,    21,    22,    27,   156,   171,   267,
     171,   172,    27,   139,   150,   253,   254,   260,   173,   173,
     173,    27,    34,    13,    35,    36,    36,    36,    22,    27,
     116,   127,    36,    99,    99,    99,    99,    99,    99,    99,
      92,    21,    22,    27,   109,   121,   267,   121,   123,    27,
     101,   129,   129,   132,   129,   129,   129,   104,   105,   267,
      92,    98,    99,   101,   128,   129,   130,   132,   253,   125,
     126,   125,   125,    36,   298,    36,    36,    36,    36,    36,
      36,    36,   268,   269,    27,    27,    27,    27,    27,    13,
     286,   305,    30,    36,    13,    36,    36,   232,    30,    35,
      13,    35,    13,    11,    30,   175,   185,   176,   179,   180,
     183,    61,    22,    27,    66,   156,   187,   194,   195,   196,
     198,   173,   164,   174,    13,    30,   139,   173,    36,    35,
      36,    36,    36,    27,   109,   136,   190,   191,   192,   198,
     126,   117,   127,    13,    30,    92,    35,    13,    11,    36,
      36,    36,    36,    30,    13,    35,   281,   300,   304,   272,
     300,   274,   300,   279,   300,   287,   297,   227,    11,   215,
      11,   150,    27,   180,    13,    35,    36,    37,    36,    36,
      37,   180,   150,   180,   181,   171,    36,    13,    35,    13,
      22,   157,   165,   166,   167,   172,    36,    36,    11,    21,
      27,   237,    36,    13,    35,    13,    22,    92,   118,   119,
      36,    11,   104,   128,   269,    13,    13,   277,   305,    13,
      13,   286,   212,   201,   180,   185,   180,   180,    35,    13,
      36,    34,   194,   164,   157,   166,   168,   172,    13,    12,
     248,   145,    34,   190,   117,    92,   119,   120,   248,    13,
     287,   299,    36,   287,   287,    36,    11,   181,    13,    35,
     170,   170,    13,    35,    92,    92,    13,    13,    13,    27,
     177,   178,   180,   168,    36,   120,    36,    22,   282,   282,
     282,    27,   182,    35,   268,   283,   284,    36,    36,    36,
     179,    36,    11,   285,   305,    35,    13,   293,   283
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
     106,   107,   108,   109,   109,   109,   109,   110,   110,   111,
     111,   111,   111,   111,   112,   112,   113,   114,   115,   116,
     116,   117,   117,   118,   118,   119,   120,   120,   121,   121,
     121,   122,   122,   122,   122,   122,   123,   123,   124,   124,
     124,   125,   126,   126,   127,   127,   128,   128,   128,   129,
     130,   131,   131,   131,   132,   132,   133,   133,   134,   134,
     135,   136,   137,   138,   138,   138,   139,   139,   139,   139,
     139,   139,   140,   140,   141,   142,   142,   143,   143,   144,
     144,   145,   145,   145,   146,   146,   147,   147,   147,   147,
     148,   149,   150,   150,   151,   151,   152,   153,   153,   154,
     155,   156,   156,   156,   157,   157,   158,   159,   159,   159,
     159,   160,   161,   161,   162,   163,   163,   164,   164,   165,
     165,   166,   167,   167,   168,   168,   169,   170,   170,   170,
     171,   171,   171,   171,   171,   172,   172,   173,   173,   174,
     174,   175,   175,   176,   176,   176,   177,   178,   178,   178,
     179,   179,   180,   180,   180,   180,   180,   180,   181,   181,
     182,   183,   183,   184,   185,   185,   186,   187,   188,   189,
     189,   190,   190,   191,   191,   192,   193,   193,   194,   194,
     195,   195,   196,   197,   198,   199,   199,   199,   199,   200,
     200,   201,   201,   202,   203,   203,   204,   204,   204,   205,
     205,   206,   207,   207,   208,   208,   209,   209,   210,   210,
     211,   212,   212,   213,   213,   213,   214,   215,   215,   216,
     216,   216,   217,   218,   218,   219,   220,   221,   222,   222,
     223,   223,   224,   225,   225,   226,   226,   227,   227,   228,
     228,   229,   229,   229,   230,   230,   231,   231,   232,   232,
     233,   233,   234,   234,   235,   235,   235,   235,   236,   236,
     236,   237,   237,   238,   238,   238,   239,   239,   240,   241,
     241,   242,   242,   243,   243,   244,   244,   244,   244,   244,
     244,   245,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   253,   254,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   264,   265,   265,   265,   265,   265,
     266,   266,   267,   268,   268,   268,   268,   268,   269,   269,
     270,   270,   271,   272,   273,   274,   275,   275,   275,   276,
     277,   277,   278,   279,   280,   281,   282,   282,   283,   283,
     284,   285,   285,   286,   286,   287,   288,   289,   289,   289,
     290,   290,   291,   291,   292,   293,   293,   293,   294,   294,
     294,   294,   294,   294,   295,   296,   296,   296,   296,   296,
     297,   297,   298,   298,   299,   299,   300,   300,   300,   301,
     302,   303,   303,   303,   304,   305
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
       1,     1,     1,     1,     1,     0
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
#line 2940 "y.tab.c"
    break;

  case 3: /* TPTP_file: TPTP_file TPTP_input  */
#line 232 "SyntaxBNF.y"
                                           {}
#line 2946 "y.tab.c"
    break;

  case 4: /* TPTP_input: annotated_formula  */
#line 235 "SyntaxBNF.y"
                               {P_PRINT((yyval.pval));}
#line 2952 "y.tab.c"
    break;

  case 5: /* TPTP_input: include  */
#line 236 "SyntaxBNF.y"
                              {P_PRINT((yyval.pval));}
#line 2958 "y.tab.c"
    break;

  case 6: /* annotated_formula: thf_annotated  */
#line 239 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2964 "y.tab.c"
    break;

  case 7: /* annotated_formula: tff_annotated  */
#line 240 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2970 "y.tab.c"
    break;

  case 8: /* annotated_formula: tcf_annotated  */
#line 241 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2976 "y.tab.c"
    break;

  case 9: /* annotated_formula: fof_annotated  */
#line 242 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2982 "y.tab.c"
    break;

  case 10: /* annotated_formula: cnf_annotated  */
#line 243 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2988 "y.tab.c"
    break;

  case 11: /* annotated_formula: tpi_annotated  */
#line 244 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2994 "y.tab.c"
    break;

  case 12: /* tpi_annotated: _LIT_tpi LPAREN name COMMA formula_role COMMA tpi_formula annotations RPAREN PERIOD  */
#line 247 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("tpi_annotated", P_TOKEN("_LIT_tpi ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 3000 "y.tab.c"
    break;

  case 13: /* tpi_formula: fof_formula  */
#line 250 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("tpi_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3006 "y.tab.c"
    break;

  case 14: /* thf_annotated: _LIT_thf LPAREN name COMMA formula_role COMMA thf_formula annotations RPAREN PERIOD  */
#line 253 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("thf_annotated", P_TOKEN("_LIT_thf ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 3012 "y.tab.c"
    break;

  case 15: /* tff_annotated: _LIT_tff LPAREN name COMMA formula_role COMMA tff_formula annotations RPAREN PERIOD  */
#line 256 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("tff_annotated", P_TOKEN("_LIT_tff ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 3018 "y.tab.c"
    break;

  case 16: /* tcf_annotated: _LIT_tcf LPAREN name COMMA formula_role COMMA tcf_formula annotations RPAREN PERIOD  */
#line 259 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("tcf_annotated", P_TOKEN("_LIT_tcf ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 3024 "y.tab.c"
    break;

  case 17: /* fof_annotated: _LIT_fof LPAREN name COMMA formula_role COMMA fof_formula annotations RPAREN PERIOD  */
#line 262 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("fof_annotated", P_TOKEN("_LIT_fof ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 3030 "y.tab.c"
    break;

  case 18: /* cnf_annotated: _LIT_cnf LPAREN name COMMA formula_role COMMA cnf_formula annotations RPAREN PERIOD  */
#line 265 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("cnf_annotated", P_TOKEN("_LIT_cnf ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 3036 "y.tab.c"
    break;

  case 19: /* annotations: COMMA source optional_info  */
#line 268 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("annotations", P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3042 "y.tab.c"
    break;

  case 20: /* annotations: nothing  */
#line 269 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("annotations", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3048 "y.tab.c"
    break;

  case 21: /* formula_role: lower_word  */
#line 272 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("formula_role", P_TOKEN("lower_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3054 "y.tab.c"
    break;

  case 22: /* formula_role: lower_word MINUS general_term  */
#line 273 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("formula_role", P_TOKEN("lower_word ", (yyvsp[-2].ival)), P_TOKEN("MINUS ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3060 "y.tab.c"
    break;

  case 23: /* thf_formula: thf_logic_formula  */
#line 276 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3066 "y.tab.c"
    break;

  case 24: /* thf_formula: thf_atom_typing  */
#line 277 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3072 "y.tab.c"
    break;

  case 25: /* thf_formula: thf_subtype  */
#line 278 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("thf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3078 "y.tab.c"
    break;

  case 26: /* thf_logic_formula: thf_unitary_formula  */
#line 281 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3084 "y.tab.c"
    break;

  case 27: /* thf_logic_formula: thf_unary_formula  */
#line 282 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3090 "y.tab.c"
    break;

  case 28: /* thf_logic_formula: thf_binary_formula  */
#line 283 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3096 "y.tab.c"
    break;

  case 29: /* thf_logic_formula: thf_defined_infix  */
#line 284 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3102 "y.tab.c"
    break;

  case 30: /* thf_logic_formula: thf_definition  */
#line 285 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3108 "y.tab.c"
    break;

  case 31: /* thf_logic_formula: thf_sequent  */
#line 286 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3114 "y.tab.c"
    break;

  case 32: /* thf_binary_formula: thf_binary_nonassoc  */
#line 289 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3120 "y.tab.c"
    break;

  case 33: /* thf_binary_formula: thf_binary_assoc  */
#line 290 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3126 "y.tab.c"
    break;

  case 34: /* thf_binary_formula: thf_binary_type  */
#line 291 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3132 "y.tab.c"
    break;

  case 35: /* thf_binary_nonassoc: thf_unit_formula nonassoc_connective thf_unit_formula  */
#line 294 "SyntaxBNF.y"
                                                                            {(yyval.pval) = P_BUILD("thf_binary_nonassoc", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3138 "y.tab.c"
    break;

  case 36: /* thf_binary_assoc: thf_or_formula  */
#line 297 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("thf_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3144 "y.tab.c"
    break;

  case 37: /* thf_binary_assoc: thf_and_formula  */
#line 298 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3150 "y.tab.c"
    break;

  case 38: /* thf_binary_assoc: thf_apply_formula  */
#line 299 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3156 "y.tab.c"
    break;

  case 39: /* thf_or_formula: thf_unit_formula VLINE thf_unit_formula  */
#line 302 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("thf_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3162 "y.tab.c"
    break;

  case 40: /* thf_or_formula: thf_or_formula VLINE thf_unit_formula  */
#line 303 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("thf_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3168 "y.tab.c"
    break;

  case 41: /* thf_and_formula: thf_unit_formula AMPERSAND thf_unit_formula  */
#line 306 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3174 "y.tab.c"
    break;

  case 42: /* thf_and_formula: thf_and_formula AMPERSAND thf_unit_formula  */
#line 307 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3180 "y.tab.c"
    break;

  case 43: /* thf_apply_formula: thf_unit_formula AT_SIGN thf_unit_formula  */
#line 310 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_apply_formula", (yyvsp[-2].pval), P_TOKEN("AT_SIGN ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3186 "y.tab.c"
    break;

  case 44: /* thf_apply_formula: thf_apply_formula AT_SIGN thf_unit_formula  */
#line 311 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_apply_formula", (yyvsp[-2].pval), P_TOKEN("AT_SIGN ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3192 "y.tab.c"
    break;

  case 45: /* thf_unit_formula: thf_unitary_formula  */
#line 314 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3198 "y.tab.c"
    break;

  case 46: /* thf_unit_formula: thf_unary_formula  */
#line 315 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3204 "y.tab.c"
    break;

  case 47: /* thf_unit_formula: thf_defined_infix  */
#line 316 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3210 "y.tab.c"
    break;

  case 48: /* thf_preunit_formula: thf_unitary_formula  */
#line 319 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("thf_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3216 "y.tab.c"
    break;

  case 49: /* thf_preunit_formula: thf_prefix_unary  */
#line 320 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3222 "y.tab.c"
    break;

  case 50: /* thf_unitary_formula: thf_quantified_formula  */
#line 323 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("thf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3228 "y.tab.c"
    break;

  case 51: /* thf_unitary_formula: thf_atomic_formula  */
#line 324 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3234 "y.tab.c"
    break;

  case 52: /* thf_unitary_formula: variable  */
#line 325 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("thf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3240 "y.tab.c"
    break;

  case 53: /* thf_unitary_formula: LPAREN thf_logic_formula RPAREN  */
#line 326 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("thf_unitary_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3246 "y.tab.c"
    break;

  case 54: /* thf_quantified_formula: thf_quantification thf_unit_formula  */
#line 329 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("thf_quantified_formula", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3252 "y.tab.c"
    break;

  case 55: /* thf_quantification: thf_quantifier LBRKT thf_variable_list RBRKT COLON  */
#line 332 "SyntaxBNF.y"
                                                                        {(yyval.pval) = P_BUILD("thf_quantification", (yyvsp[-4].pval), P_TOKEN("LBRKT ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("RBRKT ", (yyvsp[-1].ival)), P_TOKEN("COLON ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL);}
#line 3258 "y.tab.c"
    break;

  case 56: /* thf_variable_list: thf_typed_variable  */
#line 335 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_variable_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3264 "y.tab.c"
    break;

  case 57: /* thf_variable_list: thf_typed_variable COMMA thf_variable_list  */
#line 336 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_variable_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3270 "y.tab.c"
    break;

  case 58: /* thf_typed_variable: variable COLON thf_top_level_type  */
#line 339 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("thf_typed_variable", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3276 "y.tab.c"
    break;

  case 59: /* thf_unary_formula: thf_prefix_unary  */
#line 342 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3282 "y.tab.c"
    break;

  case 60: /* thf_unary_formula: thf_infix_unary  */
#line 343 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3288 "y.tab.c"
    break;

  case 61: /* thf_prefix_unary: thf_unary_connective thf_preunit_formula  */
#line 346 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("thf_prefix_unary", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3294 "y.tab.c"
    break;

  case 62: /* thf_infix_unary: thf_unitary_term infix_inequality thf_unitary_term  */
#line 349 "SyntaxBNF.y"
                                                                     {(yyval.pval) = P_BUILD("thf_infix_unary", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3300 "y.tab.c"
    break;

  case 63: /* thf_atomic_formula: thf_plain_atomic  */
#line 352 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3306 "y.tab.c"
    break;

  case 64: /* thf_atomic_formula: thf_defined_atomic  */
#line 353 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3312 "y.tab.c"
    break;

  case 65: /* thf_atomic_formula: thf_system_atomic  */
#line 354 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3318 "y.tab.c"
    break;

  case 66: /* thf_atomic_formula: thf_fof_function  */
#line 355 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3324 "y.tab.c"
    break;

  case 67: /* thf_plain_atomic: constant  */
#line 358 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("thf_plain_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3330 "y.tab.c"
    break;

  case 68: /* thf_plain_atomic: thf_tuple  */
#line 359 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_plain_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3336 "y.tab.c"
    break;

  case 69: /* thf_defined_atomic: defined_constant  */
#line 362 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3342 "y.tab.c"
    break;

  case 70: /* thf_defined_atomic: thf_defined_term  */
#line 363 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3348 "y.tab.c"
    break;

  case 71: /* thf_defined_atomic: LPAREN thf_conn_term RPAREN  */
#line 364 "SyntaxBNF.y"
                                                  {(yyval.pval) = P_BUILD("thf_defined_atomic", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3354 "y.tab.c"
    break;

  case 72: /* thf_defined_atomic: nhf_long_connective  */
#line 365 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3360 "y.tab.c"
    break;

  case 73: /* thf_defined_atomic: thf_let  */
#line 366 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3366 "y.tab.c"
    break;

  case 74: /* thf_defined_term: defined_term  */
#line 369 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3372 "y.tab.c"
    break;

  case 75: /* thf_defined_term: th1_defined_term  */
#line 370 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3378 "y.tab.c"
    break;

  case 76: /* thf_defined_infix: thf_unitary_term defined_infix_pred thf_unitary_term  */
#line 373 "SyntaxBNF.y"
                                                                         {(yyval.pval) = P_BUILD("thf_defined_infix", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3384 "y.tab.c"
    break;

  case 77: /* thf_system_atomic: system_constant  */
#line 376 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("thf_system_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3390 "y.tab.c"
    break;

  case 78: /* thf_let: _DLR_let LPAREN thf_let_types COMMA thf_let_defns COMMA thf_logic_formula RPAREN  */
#line 379 "SyntaxBNF.y"
                                                                                           {(yyval.pval) = P_BUILD("thf_let", P_TOKEN("_DLR_let ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 3396 "y.tab.c"
    break;

  case 79: /* thf_let_types: thf_atom_typing  */
#line 382 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_let_types", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3402 "y.tab.c"
    break;

  case 80: /* thf_let_types: LBRKT thf_atom_typing_list RBRKT  */
#line 383 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("thf_let_types", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3408 "y.tab.c"
    break;

  case 81: /* thf_atom_typing_list: thf_atom_typing  */
#line 386 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_atom_typing_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3414 "y.tab.c"
    break;

  case 82: /* thf_atom_typing_list: thf_atom_typing COMMA thf_atom_typing_list  */
#line 387 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_atom_typing_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3420 "y.tab.c"
    break;

  case 83: /* thf_let_defns: thf_let_defn  */
#line 390 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("thf_let_defns", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3426 "y.tab.c"
    break;

  case 84: /* thf_let_defns: LBRKT thf_let_defn_list RBRKT  */
#line 391 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("thf_let_defns", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3432 "y.tab.c"
    break;

  case 85: /* thf_let_defn: thf_logic_formula assignment thf_logic_formula  */
#line 394 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_let_defn", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3438 "y.tab.c"
    break;

  case 86: /* thf_let_defn_list: thf_let_defn  */
#line 397 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("thf_let_defn_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3444 "y.tab.c"
    break;

  case 87: /* thf_let_defn_list: thf_let_defn COMMA thf_let_defn_list  */
#line 398 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_let_defn_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3450 "y.tab.c"
    break;

  case 88: /* thf_unitary_term: thf_atomic_formula  */
#line 401 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3456 "y.tab.c"
    break;

  case 89: /* thf_unitary_term: variable  */
#line 402 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("thf_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3462 "y.tab.c"
    break;

  case 90: /* thf_unitary_term: LPAREN thf_logic_formula RPAREN  */
#line 403 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("thf_unitary_term", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3468 "y.tab.c"
    break;

  case 91: /* thf_conn_term: nonassoc_connective  */
#line 406 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3474 "y.tab.c"
    break;

  case 92: /* thf_conn_term: assoc_connective  */
#line 407 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3480 "y.tab.c"
    break;

  case 93: /* thf_conn_term: infix_equality  */
#line 408 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3486 "y.tab.c"
    break;

  case 94: /* thf_conn_term: infix_inequality  */
#line 409 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3492 "y.tab.c"
    break;

  case 95: /* thf_conn_term: thf_unary_connective  */
#line 410 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3498 "y.tab.c"
    break;

  case 96: /* thf_tuple: LBRKT RBRKT  */
#line 413 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("thf_tuple", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3504 "y.tab.c"
    break;

  case 97: /* thf_tuple: LBRKT thf_formula_list RBRKT  */
#line 414 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("thf_tuple", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3510 "y.tab.c"
    break;

  case 98: /* thf_fof_function: functor LPAREN thf_arguments RPAREN  */
#line 417 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("thf_fof_function", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3516 "y.tab.c"
    break;

  case 99: /* thf_fof_function: defined_functor LPAREN thf_arguments RPAREN  */
#line 418 "SyntaxBNF.y"
                                                                  {(yyval.pval) = P_BUILD("thf_fof_function", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3522 "y.tab.c"
    break;

  case 100: /* thf_fof_function: system_functor LPAREN thf_arguments RPAREN  */
#line 419 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_fof_function", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3528 "y.tab.c"
    break;

  case 101: /* thf_arguments: thf_formula_list  */
#line 422 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("thf_arguments", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3534 "y.tab.c"
    break;

  case 102: /* thf_formula_list: thf_logic_formula  */
#line 425 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_formula_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3540 "y.tab.c"
    break;

  case 103: /* thf_formula_list: thf_logic_formula COMMA thf_formula_list  */
#line 426 "SyntaxBNF.y"
                                                               {(yyval.pval) = P_BUILD("thf_formula_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3546 "y.tab.c"
    break;

  case 104: /* thf_atom_typing: untyped_atom COLON thf_top_level_type  */
#line 429 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("thf_atom_typing", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3552 "y.tab.c"
    break;

  case 105: /* thf_atom_typing: LPAREN thf_atom_typing RPAREN  */
#line 430 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("thf_atom_typing", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3558 "y.tab.c"
    break;

  case 106: /* thf_top_level_type: thf_unitary_type  */
#line 433 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3564 "y.tab.c"
    break;

  case 107: /* thf_top_level_type: thf_mapping_type  */
#line 434 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3570 "y.tab.c"
    break;

  case 108: /* thf_top_level_type: thf_apply_type  */
#line 435 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3576 "y.tab.c"
    break;

  case 109: /* thf_unitary_type: thf_unitary_formula  */
#line 438 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_unitary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3582 "y.tab.c"
    break;

  case 110: /* thf_apply_type: thf_apply_formula  */
#line 441 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("thf_apply_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3588 "y.tab.c"
    break;

  case 111: /* thf_binary_type: thf_mapping_type  */
#line 444 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("thf_binary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3594 "y.tab.c"
    break;

  case 112: /* thf_binary_type: thf_xprod_type  */
#line 445 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_binary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3600 "y.tab.c"
    break;

  case 113: /* thf_binary_type: thf_union_type  */
#line 446 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_binary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3606 "y.tab.c"
    break;

  case 114: /* thf_mapping_type: thf_unitary_type arrow thf_unitary_type  */
#line 449 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_mapping_type", (yyvsp[-2].pval), P_TOKEN("arrow ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3612 "y.tab.c"
    break;

  case 115: /* thf_mapping_type: thf_unitary_type arrow thf_mapping_type  */
#line 450 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_mapping_type", (yyvsp[-2].pval), P_TOKEN("arrow ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3618 "y.tab.c"
    break;

  case 116: /* thf_xprod_type: thf_unitary_type STAR thf_unitary_type  */
#line 453 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("thf_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3624 "y.tab.c"
    break;

  case 117: /* thf_xprod_type: thf_xprod_type STAR thf_unitary_type  */
#line 454 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3630 "y.tab.c"
    break;

  case 118: /* thf_union_type: thf_unitary_type plus thf_unitary_type  */
#line 457 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("thf_union_type", (yyvsp[-2].pval), P_TOKEN("plus ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3636 "y.tab.c"
    break;

  case 119: /* thf_union_type: thf_union_type plus thf_unitary_type  */
#line 458 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_union_type", (yyvsp[-2].pval), P_TOKEN("plus ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3642 "y.tab.c"
    break;

  case 120: /* thf_subtype: untyped_atom subtype_sign atom  */
#line 461 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("thf_subtype", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3648 "y.tab.c"
    break;

  case 121: /* thf_definition: thf_atomic_formula identical thf_logic_formula  */
#line 464 "SyntaxBNF.y"
                                                                {(yyval.pval) = P_BUILD("thf_definition", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3654 "y.tab.c"
    break;

  case 122: /* thf_sequent: thf_tuple gentzen_arrow thf_tuple  */
#line 467 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("thf_sequent", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3660 "y.tab.c"
    break;

  case 123: /* tff_formula: tff_logic_formula  */
#line 470 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3666 "y.tab.c"
    break;

  case 124: /* tff_formula: tff_atom_typing  */
#line 471 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3672 "y.tab.c"
    break;

  case 125: /* tff_formula: tff_subtype  */
#line 472 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tff_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3678 "y.tab.c"
    break;

  case 126: /* tff_logic_formula: tff_unitary_formula  */
#line 475 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3684 "y.tab.c"
    break;

  case 127: /* tff_logic_formula: tff_unary_formula  */
#line 476 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3690 "y.tab.c"
    break;

  case 128: /* tff_logic_formula: tff_binary_formula  */
#line 477 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3696 "y.tab.c"
    break;

  case 129: /* tff_logic_formula: tff_defined_infix  */
#line 478 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3702 "y.tab.c"
    break;

  case 130: /* tff_logic_formula: txf_definition  */
#line 479 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3708 "y.tab.c"
    break;

  case 131: /* tff_logic_formula: txf_sequent  */
#line 480 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3714 "y.tab.c"
    break;

  case 132: /* tff_binary_formula: tff_binary_nonassoc  */
#line 483 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3720 "y.tab.c"
    break;

  case 133: /* tff_binary_formula: tff_binary_assoc  */
#line 484 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3726 "y.tab.c"
    break;

  case 134: /* tff_binary_nonassoc: tff_unit_formula nonassoc_connective tff_unit_formula  */
#line 487 "SyntaxBNF.y"
                                                                            {(yyval.pval) = P_BUILD("tff_binary_nonassoc", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3732 "y.tab.c"
    break;

  case 135: /* tff_binary_assoc: tff_or_formula  */
#line 490 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tff_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3738 "y.tab.c"
    break;

  case 136: /* tff_binary_assoc: tff_and_formula  */
#line 491 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3744 "y.tab.c"
    break;

  case 137: /* tff_or_formula: tff_unit_formula VLINE tff_unit_formula  */
#line 494 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("tff_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3750 "y.tab.c"
    break;

  case 138: /* tff_or_formula: tff_or_formula VLINE tff_unit_formula  */
#line 495 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("tff_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3756 "y.tab.c"
    break;

  case 139: /* tff_and_formula: tff_unit_formula AMPERSAND tff_unit_formula  */
#line 498 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("tff_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3762 "y.tab.c"
    break;

  case 140: /* tff_and_formula: tff_and_formula AMPERSAND tff_unit_formula  */
#line 499 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("tff_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3768 "y.tab.c"
    break;

  case 141: /* tff_unit_formula: tff_unitary_formula  */
#line 502 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3774 "y.tab.c"
    break;

  case 142: /* tff_unit_formula: tff_unary_formula  */
#line 503 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3780 "y.tab.c"
    break;

  case 143: /* tff_unit_formula: tff_defined_infix  */
#line 504 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3786 "y.tab.c"
    break;

  case 144: /* tff_preunit_formula: tff_unitary_formula  */
#line 507 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3792 "y.tab.c"
    break;

  case 145: /* tff_preunit_formula: tff_prefix_unary  */
#line 508 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3798 "y.tab.c"
    break;

  case 146: /* tff_unitary_formula: tff_quantified_formula  */
#line 511 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("tff_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3804 "y.tab.c"
    break;

  case 147: /* tff_unitary_formula: tff_atomic_formula  */
#line 512 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3810 "y.tab.c"
    break;

  case 148: /* tff_unitary_formula: txf_unitary_formula  */
#line 513 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3816 "y.tab.c"
    break;

  case 149: /* tff_unitary_formula: LPAREN tff_logic_formula RPAREN  */
#line 514 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("tff_unitary_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3822 "y.tab.c"
    break;

  case 150: /* txf_unitary_formula: variable  */
#line 517 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("txf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3828 "y.tab.c"
    break;

  case 151: /* tff_quantified_formula: tff_quantifier LBRKT tff_variable_list RBRKT COLON tff_unit_formula  */
#line 520 "SyntaxBNF.y"
                                                                                             {(yyval.pval) = P_BUILD("tff_quantified_formula", (yyvsp[-5].pval), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 3834 "y.tab.c"
    break;

  case 152: /* tff_variable_list: tff_variable  */
#line 523 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("tff_variable_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3840 "y.tab.c"
    break;

  case 153: /* tff_variable_list: tff_variable COMMA tff_variable_list  */
#line 524 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("tff_variable_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3846 "y.tab.c"
    break;

  case 154: /* tff_variable: tff_typed_variable  */
#line 527 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tff_variable", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3852 "y.tab.c"
    break;

  case 155: /* tff_variable: variable  */
#line 528 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_variable", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3858 "y.tab.c"
    break;

  case 156: /* tff_typed_variable: variable COLON tff_atomic_type  */
#line 531 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("tff_typed_variable", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3864 "y.tab.c"
    break;

  case 157: /* tff_unary_formula: tff_prefix_unary  */
#line 534 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3870 "y.tab.c"
    break;

  case 158: /* tff_unary_formula: tff_infix_unary  */
#line 535 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3876 "y.tab.c"
    break;

  case 159: /* tff_prefix_unary: tff_unary_connective tff_preunit_formula  */
#line 538 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("tff_prefix_unary", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3882 "y.tab.c"
    break;

  case 160: /* tff_infix_unary: tff_unitary_term infix_inequality tff_unitary_term  */
#line 541 "SyntaxBNF.y"
                                                                     {(yyval.pval) = P_BUILD("tff_infix_unary", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3888 "y.tab.c"
    break;

  case 161: /* tff_atomic_formula: tff_plain_atomic  */
#line 544 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3894 "y.tab.c"
    break;

  case 162: /* tff_atomic_formula: tff_defined_atomic  */
#line 545 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3900 "y.tab.c"
    break;

  case 163: /* tff_atomic_formula: tff_system_atomic  */
#line 546 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3906 "y.tab.c"
    break;

  case 164: /* tff_plain_atomic: constant  */
#line 549 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("tff_plain_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3912 "y.tab.c"
    break;

  case 165: /* tff_plain_atomic: functor LPAREN tff_arguments RPAREN  */
#line 550 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("tff_plain_atomic", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3918 "y.tab.c"
    break;

  case 166: /* tff_defined_atomic: tff_defined_plain  */
#line 553 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3924 "y.tab.c"
    break;

  case 167: /* tff_defined_plain: defined_constant  */
#line 556 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3930 "y.tab.c"
    break;

  case 168: /* tff_defined_plain: defined_functor LPAREN tff_arguments RPAREN  */
#line 557 "SyntaxBNF.y"
                                                                  {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3936 "y.tab.c"
    break;

  case 169: /* tff_defined_plain: nxf_atom  */
#line 558 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3942 "y.tab.c"
    break;

  case 170: /* tff_defined_plain: txf_let  */
#line 559 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3948 "y.tab.c"
    break;

  case 171: /* tff_defined_infix: tff_unitary_term defined_infix_pred tff_unitary_term  */
#line 562 "SyntaxBNF.y"
                                                                         {(yyval.pval) = P_BUILD("tff_defined_infix", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3954 "y.tab.c"
    break;

  case 172: /* tff_system_atomic: system_constant  */
#line 565 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("tff_system_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3960 "y.tab.c"
    break;

  case 173: /* tff_system_atomic: system_functor LPAREN tff_arguments RPAREN  */
#line 566 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("tff_system_atomic", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3966 "y.tab.c"
    break;

  case 174: /* txf_let: _DLR_let LPAREN txf_let_types COMMA txf_let_defns COMMA tff_term RPAREN  */
#line 569 "SyntaxBNF.y"
                                                                                  {(yyval.pval) = P_BUILD("txf_let", P_TOKEN("_DLR_let ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 3972 "y.tab.c"
    break;

  case 175: /* txf_let_types: tff_atom_typing  */
#line 572 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("txf_let_types", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3978 "y.tab.c"
    break;

  case 176: /* txf_let_types: LBRKT tff_atom_typing_list RBRKT  */
#line 573 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("txf_let_types", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3984 "y.tab.c"
    break;

  case 177: /* tff_atom_typing_list: tff_atom_typing  */
#line 576 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_atom_typing_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3990 "y.tab.c"
    break;

  case 178: /* tff_atom_typing_list: tff_atom_typing COMMA tff_atom_typing_list  */
#line 577 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("tff_atom_typing_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3996 "y.tab.c"
    break;

  case 179: /* txf_let_defns: txf_let_defn  */
#line 580 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("txf_let_defns", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4002 "y.tab.c"
    break;

  case 180: /* txf_let_defns: LBRKT txf_let_defn_list RBRKT  */
#line 581 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("txf_let_defns", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4008 "y.tab.c"
    break;

  case 181: /* txf_let_defn: txf_let_LHS assignment tff_term  */
#line 584 "SyntaxBNF.y"
                                               {(yyval.pval) = P_BUILD("txf_let_defn", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4014 "y.tab.c"
    break;

  case 182: /* txf_let_LHS: tff_plain_atomic  */
#line 587 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("txf_let_LHS", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4020 "y.tab.c"
    break;

  case 183: /* txf_let_LHS: txf_tuple  */
#line 588 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("txf_let_LHS", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4026 "y.tab.c"
    break;

  case 184: /* txf_let_defn_list: txf_let_defn  */
#line 591 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("txf_let_defn_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4032 "y.tab.c"
    break;

  case 185: /* txf_let_defn_list: txf_let_defn COMMA txf_let_defn_list  */
#line 592 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("txf_let_defn_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4038 "y.tab.c"
    break;

  case 186: /* nxf_atom: nxf_long_connective AT_SIGN LPAREN tff_arguments RPAREN  */
#line 595 "SyntaxBNF.y"
                                                                   {(yyval.pval) = P_BUILD("nxf_atom", (yyvsp[-4].pval), P_TOKEN("AT_SIGN ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL);}
#line 4044 "y.tab.c"
    break;

  case 187: /* tff_term: tff_logic_formula  */
#line 598 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("tff_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4050 "y.tab.c"
    break;

  case 188: /* tff_term: defined_term  */
#line 599 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4056 "y.tab.c"
    break;

  case 189: /* tff_term: txf_tuple  */
#line 600 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4062 "y.tab.c"
    break;

  case 190: /* tff_unitary_term: tff_atomic_formula  */
#line 603 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4068 "y.tab.c"
    break;

  case 191: /* tff_unitary_term: defined_term  */
#line 604 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4074 "y.tab.c"
    break;

  case 192: /* tff_unitary_term: txf_tuple  */
#line 605 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4080 "y.tab.c"
    break;

  case 193: /* tff_unitary_term: variable  */
#line 606 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4086 "y.tab.c"
    break;

  case 194: /* tff_unitary_term: LPAREN tff_logic_formula RPAREN  */
#line 607 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("tff_unitary_term", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4092 "y.tab.c"
    break;

  case 195: /* txf_tuple: LBRKT RBRKT  */
#line 610 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("txf_tuple", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4098 "y.tab.c"
    break;

  case 196: /* txf_tuple: LBRKT tff_arguments RBRKT  */
#line 611 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("txf_tuple", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4104 "y.tab.c"
    break;

  case 197: /* tff_arguments: tff_term  */
#line 614 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_arguments", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4110 "y.tab.c"
    break;

  case 198: /* tff_arguments: tff_term COMMA tff_arguments  */
#line 615 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("tff_arguments", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4116 "y.tab.c"
    break;

  case 199: /* tff_atom_typing: untyped_atom COLON tff_top_level_type  */
#line 618 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("tff_atom_typing", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4122 "y.tab.c"
    break;

  case 200: /* tff_atom_typing: LPAREN tff_atom_typing RPAREN  */
#line 619 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("tff_atom_typing", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4128 "y.tab.c"
    break;

  case 201: /* tff_top_level_type: tff_atomic_type  */
#line 622 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4134 "y.tab.c"
    break;

  case 202: /* tff_top_level_type: tff_non_atomic_type  */
#line 623 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4140 "y.tab.c"
    break;

  case 203: /* tff_non_atomic_type: tff_mapping_type  */
#line 626 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_non_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4146 "y.tab.c"
    break;

  case 204: /* tff_non_atomic_type: tf1_quantified_type  */
#line 627 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_non_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4152 "y.tab.c"
    break;

  case 205: /* tff_non_atomic_type: LPAREN tff_non_atomic_type RPAREN  */
#line 628 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("tff_non_atomic_type", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4158 "y.tab.c"
    break;

  case 206: /* tf1_quantified_type: type_quantifier LBRKT tff_variable_list RBRKT COLON tff_monotype  */
#line 631 "SyntaxBNF.y"
                                                                                       {(yyval.pval) = P_BUILD("tf1_quantified_type", (yyvsp[-5].pval), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 4164 "y.tab.c"
    break;

  case 207: /* tff_monotype: tff_atomic_type  */
#line 634 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_monotype", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4170 "y.tab.c"
    break;

  case 208: /* tff_monotype: LPAREN tff_mapping_type RPAREN  */
#line 635 "SyntaxBNF.y"
                                                     {(yyval.pval) = P_BUILD("tff_monotype", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4176 "y.tab.c"
    break;

  case 209: /* tff_monotype: tf1_quantified_type  */
#line 636 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_monotype", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4182 "y.tab.c"
    break;

  case 210: /* tff_unitary_type: tff_atomic_type  */
#line 639 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_unitary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4188 "y.tab.c"
    break;

  case 211: /* tff_unitary_type: LPAREN tff_xprod_type RPAREN  */
#line 640 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("tff_unitary_type", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4194 "y.tab.c"
    break;

  case 212: /* tff_atomic_type: type_constant  */
#line 643 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4200 "y.tab.c"
    break;

  case 213: /* tff_atomic_type: defined_type  */
#line 644 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4206 "y.tab.c"
    break;

  case 214: /* tff_atomic_type: variable  */
#line 645 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4212 "y.tab.c"
    break;

  case 215: /* tff_atomic_type: type_functor LPAREN tff_type_arguments RPAREN  */
#line 646 "SyntaxBNF.y"
                                                                    {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4218 "y.tab.c"
    break;

  case 216: /* tff_atomic_type: LPAREN tff_atomic_type RPAREN  */
#line 647 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("tff_atomic_type", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4224 "y.tab.c"
    break;

  case 217: /* tff_atomic_type: txf_tuple_type  */
#line 648 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4230 "y.tab.c"
    break;

  case 218: /* tff_type_arguments: tff_atomic_type  */
#line 651 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_type_arguments", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4236 "y.tab.c"
    break;

  case 219: /* tff_type_arguments: tff_atomic_type COMMA tff_type_arguments  */
#line 652 "SyntaxBNF.y"
                                                               {(yyval.pval) = P_BUILD("tff_type_arguments", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4242 "y.tab.c"
    break;

  case 220: /* tff_mapping_type: tff_unitary_type arrow tff_atomic_type  */
#line 655 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("tff_mapping_type", (yyvsp[-2].pval), P_TOKEN("arrow ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4248 "y.tab.c"
    break;

  case 221: /* tff_xprod_type: tff_unitary_type STAR tff_atomic_type  */
#line 658 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("tff_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4254 "y.tab.c"
    break;

  case 222: /* tff_xprod_type: tff_xprod_type STAR tff_atomic_type  */
#line 659 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("tff_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4260 "y.tab.c"
    break;

  case 223: /* txf_tuple_type: LBRKT tff_type_list RBRKT  */
#line 662 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("txf_tuple_type", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4266 "y.tab.c"
    break;

  case 224: /* tff_type_list: tff_top_level_type  */
#line 665 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_type_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4272 "y.tab.c"
    break;

  case 225: /* tff_type_list: tff_top_level_type COMMA tff_type_list  */
#line 666 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("tff_type_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4278 "y.tab.c"
    break;

  case 226: /* tff_subtype: untyped_atom subtype_sign atom  */
#line 669 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("tff_subtype", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4284 "y.tab.c"
    break;

  case 227: /* txf_definition: tff_atomic_formula identical tff_term  */
#line 672 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("txf_definition", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4290 "y.tab.c"
    break;

  case 228: /* txf_sequent: txf_tuple gentzen_arrow txf_tuple  */
#line 675 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("txf_sequent", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4296 "y.tab.c"
    break;

  case 229: /* nhf_long_connective: LBRACE ntf_connective_name RBRACE  */
#line 678 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("nhf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4302 "y.tab.c"
    break;

  case 230: /* nhf_long_connective: LBRACE ntf_connective_name LPAREN nhf_parameter_list RPAREN RBRACE  */
#line 679 "SyntaxBNF.y"
                                                                                         {(yyval.pval) = P_BUILD("nhf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-5].ival)), (yyvsp[-4].pval), P_TOKEN("LPAREN ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL);}
#line 4308 "y.tab.c"
    break;

  case 231: /* nhf_parameter_list: nhf_parameter  */
#line 682 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("nhf_parameter_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4314 "y.tab.c"
    break;

  case 232: /* nhf_parameter_list: nhf_parameter COMMA nhf_parameter_list  */
#line 683 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("nhf_parameter_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4320 "y.tab.c"
    break;

  case 233: /* nhf_parameter: ntf_index  */
#line 686 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("nhf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4326 "y.tab.c"
    break;

  case 234: /* nhf_parameter: nhf_key_pair  */
#line 687 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("nhf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4332 "y.tab.c"
    break;

  case 235: /* nhf_key_pair: thf_definition  */
#line 690 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("nhf_key_pair", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4338 "y.tab.c"
    break;

  case 236: /* nxf_long_connective: LBRACE ntf_connective_name RBRACE  */
#line 693 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("nxf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4344 "y.tab.c"
    break;

  case 237: /* nxf_long_connective: LBRACE ntf_connective_name LPAREN nxf_parameter_list RPAREN RBRACE  */
#line 694 "SyntaxBNF.y"
                                                                                         {(yyval.pval) = P_BUILD("nxf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-5].ival)), (yyvsp[-4].pval), P_TOKEN("LPAREN ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL);}
#line 4350 "y.tab.c"
    break;

  case 238: /* nxf_parameter_list: nxf_parameter  */
#line 697 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("nxf_parameter_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4356 "y.tab.c"
    break;

  case 239: /* nxf_parameter_list: nxf_parameter COMMA nxf_parameter_list  */
#line 698 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("nxf_parameter_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4362 "y.tab.c"
    break;

  case 240: /* nxf_parameter: ntf_index  */
#line 701 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("nxf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4368 "y.tab.c"
    break;

  case 241: /* nxf_parameter: nxf_key_pair  */
#line 702 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("nxf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4374 "y.tab.c"
    break;

  case 242: /* nxf_key_pair: txf_definition  */
#line 705 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("nxf_key_pair", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4380 "y.tab.c"
    break;

  case 243: /* ntf_connective_name: def_or_sys_constant  */
#line 708 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("ntf_connective_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4386 "y.tab.c"
    break;

  case 244: /* ntf_index: hash tff_unitary_term  */
#line 711 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("ntf_index", P_TOKEN("hash ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4392 "y.tab.c"
    break;

  case 245: /* ntf_short_connective: LBRKT PERIOD RBRKT  */
#line 714 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4398 "y.tab.c"
    break;

  case 246: /* ntf_short_connective: less_sign PERIOD arrow  */
#line 715 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("less_sign ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("arrow ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4404 "y.tab.c"
    break;

  case 247: /* ntf_short_connective: LBRACE PERIOD RBRACE  */
#line 716 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("LBRACE ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4410 "y.tab.c"
    break;

  case 248: /* ntf_short_connective: LPAREN PERIOD RPAREN  */
#line 717 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4416 "y.tab.c"
    break;

  case 249: /* tcf_formula: tcf_logic_formula  */
#line 720 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tcf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4422 "y.tab.c"
    break;

  case 250: /* tcf_formula: tff_atom_typing  */
#line 721 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tcf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4428 "y.tab.c"
    break;

  case 251: /* tcf_logic_formula: tcf_quantified_formula  */
#line 724 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("tcf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4434 "y.tab.c"
    break;

  case 252: /* tcf_logic_formula: cnf_formula  */
#line 725 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tcf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4440 "y.tab.c"
    break;

  case 253: /* tcf_quantified_formula: EXCLAMATION LBRKT tff_variable_list RBRKT COLON tcf_logic_formula  */
#line 728 "SyntaxBNF.y"
                                                                                           {(yyval.pval) = P_BUILD("tcf_quantified_formula", P_TOKEN("EXCLAMATION ", (yyvsp[-5].ival)), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 4446 "y.tab.c"
    break;

  case 254: /* fof_formula: fof_logic_formula  */
#line 731 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("fof_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4452 "y.tab.c"
    break;

  case 255: /* fof_formula: fof_sequent  */
#line 732 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("fof_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4458 "y.tab.c"
    break;

  case 256: /* fof_logic_formula: fof_binary_formula  */
#line 735 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("fof_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4464 "y.tab.c"
    break;

  case 257: /* fof_logic_formula: fof_unary_formula  */
#line 736 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("fof_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4470 "y.tab.c"
    break;

  case 258: /* fof_logic_formula: fof_unitary_formula  */
#line 737 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("fof_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4476 "y.tab.c"
    break;

  case 259: /* fof_binary_formula: fof_binary_nonassoc  */
#line 740 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("fof_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4482 "y.tab.c"
    break;

  case 260: /* fof_binary_formula: fof_binary_assoc  */
#line 741 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("fof_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4488 "y.tab.c"
    break;

  case 261: /* fof_binary_nonassoc: fof_unit_formula nonassoc_connective fof_unit_formula  */
#line 744 "SyntaxBNF.y"
                                                                            {(yyval.pval) = P_BUILD("fof_binary_nonassoc", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4494 "y.tab.c"
    break;

  case 262: /* fof_binary_assoc: fof_or_formula  */
#line 747 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("fof_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4500 "y.tab.c"
    break;

  case 263: /* fof_binary_assoc: fof_and_formula  */
#line 748 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("fof_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4506 "y.tab.c"
    break;

  case 264: /* fof_or_formula: fof_unit_formula VLINE fof_unit_formula  */
#line 751 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("fof_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4512 "y.tab.c"
    break;

  case 265: /* fof_or_formula: fof_or_formula VLINE fof_unit_formula  */
#line 752 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("fof_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4518 "y.tab.c"
    break;

  case 266: /* fof_and_formula: fof_unit_formula AMPERSAND fof_unit_formula  */
#line 755 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("fof_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4524 "y.tab.c"
    break;

  case 267: /* fof_and_formula: fof_and_formula AMPERSAND fof_unit_formula  */
#line 756 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("fof_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4530 "y.tab.c"
    break;

  case 268: /* fof_unary_formula: unary_connective fof_unit_formula  */
#line 759 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("fof_unary_formula", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4536 "y.tab.c"
    break;

  case 269: /* fof_unary_formula: fof_infix_unary  */
#line 760 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("fof_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4542 "y.tab.c"
    break;

  case 270: /* fof_infix_unary: fof_term infix_inequality fof_term  */
#line 763 "SyntaxBNF.y"
                                                     {(yyval.pval) = P_BUILD("fof_infix_unary", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4548 "y.tab.c"
    break;

  case 271: /* fof_unit_formula: fof_unitary_formula  */
#line 766 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("fof_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4554 "y.tab.c"
    break;

  case 272: /* fof_unit_formula: fof_unary_formula  */
#line 767 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("fof_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4560 "y.tab.c"
    break;

  case 273: /* fof_unitary_formula: fof_quantified_formula  */
#line 770 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("fof_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4566 "y.tab.c"
    break;

  case 274: /* fof_unitary_formula: fof_atomic_formula  */
#line 771 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("fof_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4572 "y.tab.c"
    break;

  case 275: /* fof_unitary_formula: LPAREN fof_logic_formula RPAREN  */
#line 772 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("fof_unitary_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4578 "y.tab.c"
    break;

  case 276: /* fof_quantified_formula: fof_quantifier LBRKT fof_variable_list RBRKT COLON fof_unit_formula  */
#line 775 "SyntaxBNF.y"
                                                                                             {(yyval.pval) = P_BUILD("fof_quantified_formula", (yyvsp[-5].pval), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 4584 "y.tab.c"
    break;

  case 277: /* fof_variable_list: variable  */
#line 778 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("fof_variable_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4590 "y.tab.c"
    break;

  case 278: /* fof_variable_list: variable COMMA fof_variable_list  */
#line 779 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("fof_variable_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4596 "y.tab.c"
    break;

  case 279: /* fof_atomic_formula: fof_plain_atomic_formula  */
#line 782 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("fof_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4602 "y.tab.c"
    break;

  case 280: /* fof_atomic_formula: fof_defined_atomic_formula  */
#line 783 "SyntaxBNF.y"
                                                 {(yyval.pval) = P_BUILD("fof_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4608 "y.tab.c"
    break;

  case 281: /* fof_atomic_formula: fof_system_atomic_formula  */
#line 784 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("fof_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4614 "y.tab.c"
    break;

  case 282: /* fof_plain_atomic_formula: fof_plain_term  */
#line 787 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("fof_plain_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4620 "y.tab.c"
    break;

  case 283: /* fof_defined_atomic_formula: fof_defined_plain_formula  */
#line 790 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("fof_defined_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4626 "y.tab.c"
    break;

  case 284: /* fof_defined_atomic_formula: fof_defined_infix_formula  */
#line 791 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("fof_defined_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4632 "y.tab.c"
    break;

  case 285: /* fof_defined_plain_formula: fof_defined_plain_term  */
#line 794 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("fof_defined_plain_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4638 "y.tab.c"
    break;

  case 286: /* fof_defined_infix_formula: fof_term defined_infix_pred fof_term  */
#line 797 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("fof_defined_infix_formula", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4644 "y.tab.c"
    break;

  case 287: /* fof_system_atomic_formula: fof_system_term  */
#line 800 "SyntaxBNF.y"
                                            {(yyval.pval) = P_BUILD("fof_system_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4650 "y.tab.c"
    break;

  case 288: /* fof_plain_term: constant  */
#line 803 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("fof_plain_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4656 "y.tab.c"
    break;

  case 289: /* fof_plain_term: functor LPAREN fof_arguments RPAREN  */
#line 804 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("fof_plain_term", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4662 "y.tab.c"
    break;

  case 290: /* fof_defined_term: defined_term  */
#line 807 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("fof_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4668 "y.tab.c"
    break;

  case 291: /* fof_defined_term: fof_defined_atomic_term  */
#line 808 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("fof_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4674 "y.tab.c"
    break;

  case 292: /* fof_defined_atomic_term: fof_defined_plain_term  */
#line 811 "SyntaxBNF.y"
                                                 {(yyval.pval) = P_BUILD("fof_defined_atomic_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4680 "y.tab.c"
    break;

  case 293: /* fof_defined_plain_term: defined_constant  */
#line 814 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("fof_defined_plain_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4686 "y.tab.c"
    break;

  case 294: /* fof_defined_plain_term: defined_functor LPAREN fof_arguments RPAREN  */
#line 815 "SyntaxBNF.y"
                                                                  {(yyval.pval) = P_BUILD("fof_defined_plain_term", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4692 "y.tab.c"
    break;

  case 295: /* fof_system_term: system_constant  */
#line 818 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("fof_system_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4698 "y.tab.c"
    break;

  case 296: /* fof_system_term: system_functor LPAREN fof_arguments RPAREN  */
#line 819 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("fof_system_term", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4704 "y.tab.c"
    break;

  case 297: /* fof_arguments: fof_term  */
#line 822 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("fof_arguments", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4710 "y.tab.c"
    break;

  case 298: /* fof_arguments: fof_term COMMA fof_arguments  */
#line 823 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("fof_arguments", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4716 "y.tab.c"
    break;

  case 299: /* fof_term: fof_function_term  */
#line 826 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("fof_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4722 "y.tab.c"
    break;

  case 300: /* fof_term: variable  */
#line 827 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("fof_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4728 "y.tab.c"
    break;

  case 301: /* fof_function_term: fof_plain_term  */
#line 830 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("fof_function_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4734 "y.tab.c"
    break;

  case 302: /* fof_function_term: fof_defined_term  */
#line 831 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("fof_function_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4740 "y.tab.c"
    break;

  case 303: /* fof_function_term: fof_system_term  */
#line 832 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("fof_function_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4746 "y.tab.c"
    break;

  case 304: /* fof_sequent: fof_formula_tuple gentzen_arrow fof_formula_tuple  */
#line 835 "SyntaxBNF.y"
                                                                {(yyval.pval) = P_BUILD("fof_sequent", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4752 "y.tab.c"
    break;

  case 305: /* fof_sequent: LPAREN fof_sequent RPAREN  */
#line 836 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("fof_sequent", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4758 "y.tab.c"
    break;

  case 306: /* fof_formula_tuple: LBRKT RBRKT  */
#line 839 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("fof_formula_tuple", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4764 "y.tab.c"
    break;

  case 307: /* fof_formula_tuple: LBRKT fof_formula_tuple_list RBRKT  */
#line 840 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("fof_formula_tuple", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4770 "y.tab.c"
    break;

  case 308: /* fof_formula_tuple_list: fof_logic_formula  */
#line 843 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("fof_formula_tuple_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4776 "y.tab.c"
    break;

  case 309: /* fof_formula_tuple_list: fof_logic_formula COMMA fof_formula_tuple_list  */
#line 844 "SyntaxBNF.y"
                                                                     {(yyval.pval) = P_BUILD("fof_formula_tuple_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4782 "y.tab.c"
    break;

  case 310: /* cnf_formula: cnf_disjunction  */
#line 847 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("cnf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4788 "y.tab.c"
    break;

  case 311: /* cnf_formula: LPAREN cnf_formula RPAREN  */
#line 848 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("cnf_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4794 "y.tab.c"
    break;

  case 312: /* cnf_disjunction: cnf_literal  */
#line 851 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("cnf_disjunction", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4800 "y.tab.c"
    break;

  case 313: /* cnf_disjunction: cnf_disjunction VLINE cnf_literal  */
#line 852 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("cnf_disjunction", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4806 "y.tab.c"
    break;

  case 314: /* cnf_literal: fof_atomic_formula  */
#line 855 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("cnf_literal", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4812 "y.tab.c"
    break;

  case 315: /* cnf_literal: TILDE fof_atomic_formula  */
#line 856 "SyntaxBNF.y"
                                               {(yyval.pval) = P_BUILD("cnf_literal", P_TOKEN("TILDE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4818 "y.tab.c"
    break;

  case 316: /* cnf_literal: TILDE LPAREN fof_atomic_formula RPAREN  */
#line 857 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("cnf_literal", P_TOKEN("TILDE ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4824 "y.tab.c"
    break;

  case 317: /* cnf_literal: fof_infix_unary  */
#line 858 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("cnf_literal", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4830 "y.tab.c"
    break;

  case 318: /* thf_quantifier: tff_quantifier  */
#line 861 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4836 "y.tab.c"
    break;

  case 319: /* thf_quantifier: th0_quantifier  */
#line 862 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4842 "y.tab.c"
    break;

  case 320: /* thf_quantifier: type_quantifier  */
#line 863 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4848 "y.tab.c"
    break;

  case 321: /* thf_unary_connective: unary_connective  */
#line 866 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4854 "y.tab.c"
    break;

  case 322: /* thf_unary_connective: ntf_short_connective  */
#line 867 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("thf_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4860 "y.tab.c"
    break;

  case 323: /* th0_quantifier: CARET  */
#line 870 "SyntaxBNF.y"
                       {(yyval.pval) = P_BUILD("th0_quantifier", P_TOKEN("CARET ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4866 "y.tab.c"
    break;

  case 324: /* th0_quantifier: AT_SIGN_PLUS  */
#line 871 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("th0_quantifier", P_TOKEN("AT_SIGN_PLUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4872 "y.tab.c"
    break;

  case 325: /* th0_quantifier: AT_SIGN_MINUS  */
#line 872 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("th0_quantifier", P_TOKEN("AT_SIGN_MINUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4878 "y.tab.c"
    break;

  case 326: /* type_quantifier: EXCLAMATION_GREATER  */
#line 875 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("type_quantifier", P_TOKEN("EXCLAMATION_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4884 "y.tab.c"
    break;

  case 327: /* type_quantifier: QUESTION_STAR  */
#line 876 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("type_quantifier", P_TOKEN("QUESTION_STAR ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4890 "y.tab.c"
    break;

  case 328: /* subtype_sign: LESS_LESS  */
#line 879 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("subtype_sign", P_TOKEN("LESS_LESS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4896 "y.tab.c"
    break;

  case 329: /* tff_unary_connective: unary_connective  */
#line 882 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4902 "y.tab.c"
    break;

  case 330: /* tff_unary_connective: ntf_short_connective  */
#line 883 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("tff_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4908 "y.tab.c"
    break;

  case 331: /* tff_quantifier: fof_quantifier  */
#line 886 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4914 "y.tab.c"
    break;

  case 332: /* tff_quantifier: hash  */
#line 887 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("tff_quantifier", P_TOKEN("hash ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4920 "y.tab.c"
    break;

  case 333: /* fof_quantifier: EXCLAMATION  */
#line 890 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("fof_quantifier", P_TOKEN("EXCLAMATION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4926 "y.tab.c"
    break;

  case 334: /* fof_quantifier: QUESTION  */
#line 891 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("fof_quantifier", P_TOKEN("QUESTION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4932 "y.tab.c"
    break;

  case 335: /* nonassoc_connective: LESS_EQUALS_GREATER  */
#line 894 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("LESS_EQUALS_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4938 "y.tab.c"
    break;

  case 336: /* nonassoc_connective: EQUALS_GREATER  */
#line 895 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("EQUALS_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4944 "y.tab.c"
    break;

  case 337: /* nonassoc_connective: LESS_EQUALS  */
#line 896 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("LESS_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4950 "y.tab.c"
    break;

  case 338: /* nonassoc_connective: LESS_TILDE_GREATER  */
#line 897 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("LESS_TILDE_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4956 "y.tab.c"
    break;

  case 339: /* nonassoc_connective: TILDE_VLINE  */
#line 898 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("TILDE_VLINE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4962 "y.tab.c"
    break;

  case 340: /* nonassoc_connective: TILDE_AMPERSAND  */
#line 899 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("TILDE_AMPERSAND ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4968 "y.tab.c"
    break;

  case 341: /* assoc_connective: VLINE  */
#line 902 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("assoc_connective", P_TOKEN("VLINE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4974 "y.tab.c"
    break;

  case 342: /* assoc_connective: AMPERSAND  */
#line 903 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("assoc_connective", P_TOKEN("AMPERSAND ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4980 "y.tab.c"
    break;

  case 343: /* unary_connective: TILDE  */
#line 906 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("unary_connective", P_TOKEN("TILDE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4986 "y.tab.c"
    break;

  case 344: /* gentzen_arrow: MINUS_MINUS_GREATER  */
#line 909 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("gentzen_arrow", P_TOKEN("MINUS_MINUS_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4992 "y.tab.c"
    break;

  case 345: /* assignment: COLON_EQUALS  */
#line 912 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("assignment", P_TOKEN("COLON_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4998 "y.tab.c"
    break;

  case 346: /* identical: EQUALS_EQUALS  */
#line 915 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("identical", P_TOKEN("EQUALS_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5004 "y.tab.c"
    break;

  case 347: /* type_constant: type_functor  */
#line 918 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("type_constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5010 "y.tab.c"
    break;

  case 348: /* type_functor: atomic_word  */
#line 921 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("type_functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5016 "y.tab.c"
    break;

  case 349: /* defined_type: atomic_defined_word  */
#line 924 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("defined_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5022 "y.tab.c"
    break;

  case 350: /* atom: untyped_atom  */
#line 927 "SyntaxBNF.y"
                    {(yyval.pval) = P_BUILD("atom", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5028 "y.tab.c"
    break;

  case 351: /* atom: defined_constant  */
#line 928 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("atom", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5034 "y.tab.c"
    break;

  case 352: /* untyped_atom: constant  */
#line 931 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("untyped_atom", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5040 "y.tab.c"
    break;

  case 353: /* untyped_atom: system_constant  */
#line 932 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("untyped_atom", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5046 "y.tab.c"
    break;

  case 354: /* defined_infix_pred: infix_equality  */
#line 935 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("defined_infix_pred", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5052 "y.tab.c"
    break;

  case 355: /* infix_equality: EQUALS  */
#line 938 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("infix_equality", P_TOKEN("EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5058 "y.tab.c"
    break;

  case 356: /* infix_inequality: EXCLAMATION_EQUALS  */
#line 941 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("infix_inequality", P_TOKEN("EXCLAMATION_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5064 "y.tab.c"
    break;

  case 357: /* constant: functor  */
#line 944 "SyntaxBNF.y"
                   {(yyval.pval) = P_BUILD("constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5070 "y.tab.c"
    break;

  case 358: /* functor: atomic_word  */
#line 947 "SyntaxBNF.y"
                      {(yyval.pval) = P_BUILD("functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5076 "y.tab.c"
    break;

  case 359: /* defined_constant: defined_functor  */
#line 950 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("defined_constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5082 "y.tab.c"
    break;

  case 360: /* defined_functor: atomic_defined_word  */
#line 953 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("defined_functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5088 "y.tab.c"
    break;

  case 361: /* system_constant: system_functor  */
#line 956 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("system_constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5094 "y.tab.c"
    break;

  case 362: /* system_functor: atomic_system_word  */
#line 959 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("system_functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5100 "y.tab.c"
    break;

  case 363: /* def_or_sys_constant: defined_constant  */
#line 962 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("def_or_sys_constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5106 "y.tab.c"
    break;

  case 364: /* def_or_sys_constant: system_constant  */
#line 963 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("def_or_sys_constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5112 "y.tab.c"
    break;

  case 365: /* th1_defined_term: EXCLAMATION_EXCLAMATION  */
#line 966 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("EXCLAMATION_EXCLAMATION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5118 "y.tab.c"
    break;

  case 366: /* th1_defined_term: QUESTION_QUESTION  */
#line 967 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("QUESTION_QUESTION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5124 "y.tab.c"
    break;

  case 367: /* th1_defined_term: AT_AT_SIGN_PLUS  */
#line 968 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("AT_AT_SIGN_PLUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5130 "y.tab.c"
    break;

  case 368: /* th1_defined_term: AT_AT_SIGN_MINUS  */
#line 969 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("AT_AT_SIGN_MINUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5136 "y.tab.c"
    break;

  case 369: /* th1_defined_term: AT_SIGN_EQUALS  */
#line 970 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("AT_SIGN_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5142 "y.tab.c"
    break;

  case 370: /* defined_term: number  */
#line 973 "SyntaxBNF.y"
                      {(yyval.pval) = P_BUILD("defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5148 "y.tab.c"
    break;

  case 371: /* defined_term: distinct_object  */
#line 974 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("defined_term", P_TOKEN("distinct_object ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5154 "y.tab.c"
    break;

  case 372: /* variable: upper_word  */
#line 977 "SyntaxBNF.y"
                      {(yyval.pval) = P_BUILD("variable", P_TOKEN("upper_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5160 "y.tab.c"
    break;

  case 373: /* source: dag_source  */
#line 980 "SyntaxBNF.y"
                    {(yyval.pval) = P_BUILD("source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5166 "y.tab.c"
    break;

  case 374: /* source: internal_source  */
#line 981 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5172 "y.tab.c"
    break;

  case 375: /* source: external_source  */
#line 982 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5178 "y.tab.c"
    break;

  case 376: /* source: _LIT_unknown  */
#line 983 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("source", P_TOKEN("_LIT_unknown ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5184 "y.tab.c"
    break;

  case 377: /* source: LBRKT sources RBRKT  */
#line 984 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("source", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5190 "y.tab.c"
    break;

  case 378: /* sources: source  */
#line 987 "SyntaxBNF.y"
                 {(yyval.pval) = P_BUILD("sources", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5196 "y.tab.c"
    break;

  case 379: /* sources: source COMMA sources  */
#line 988 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("sources", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5202 "y.tab.c"
    break;

  case 380: /* dag_source: name  */
#line 991 "SyntaxBNF.y"
                  {(yyval.pval) = P_BUILD("dag_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5208 "y.tab.c"
    break;

  case 381: /* dag_source: inference_record  */
#line 992 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("dag_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5214 "y.tab.c"
    break;

  case 382: /* inference_record: _LIT_inference LPAREN inference_rule COMMA useful_info COMMA parents RPAREN  */
#line 995 "SyntaxBNF.y"
                                                                                               {(yyval.pval) = P_BUILD("inference_record", P_TOKEN("_LIT_inference ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 5220 "y.tab.c"
    break;

  case 383: /* inference_rule: atomic_word  */
#line 998 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("inference_rule", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5226 "y.tab.c"
    break;

  case 384: /* internal_source: _LIT_introduced LPAREN intro_type COMMA useful_info COMMA parents RPAREN  */
#line 1001 "SyntaxBNF.y"
                                                                                           {(yyval.pval) = P_BUILD("internal_source", P_TOKEN("_LIT_introduced ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 5232 "y.tab.c"
    break;

  case 385: /* intro_type: atomic_word  */
#line 1004 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("intro_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5238 "y.tab.c"
    break;

  case 386: /* external_source: file_source  */
#line 1007 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("external_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5244 "y.tab.c"
    break;

  case 387: /* external_source: theory  */
#line 1008 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("external_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5250 "y.tab.c"
    break;

  case 388: /* external_source: creator_source  */
#line 1009 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("external_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5256 "y.tab.c"
    break;

  case 389: /* file_source: _LIT_file LPAREN file_name file_info RPAREN  */
#line 1012 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("file_source", P_TOKEN("_LIT_file ", (yyvsp[-4].ival)), P_TOKEN("LPAREN ", (yyvsp[-3].ival)), (yyvsp[-2].pval), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL);}
#line 5262 "y.tab.c"
    break;

  case 390: /* file_info: COMMA name  */
#line 1015 "SyntaxBNF.y"
                       {(yyval.pval) = P_BUILD("file_info", P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5268 "y.tab.c"
    break;

  case 391: /* file_info: nothing  */
#line 1016 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("file_info", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5274 "y.tab.c"
    break;

  case 392: /* theory: _LIT_theory LPAREN theory_name optional_info RPAREN  */
#line 1019 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("theory", P_TOKEN("_LIT_theory ", (yyvsp[-4].ival)), P_TOKEN("LPAREN ", (yyvsp[-3].ival)), (yyvsp[-2].pval), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL);}
#line 5280 "y.tab.c"
    break;

  case 393: /* theory_name: atomic_word  */
#line 1022 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("theory_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5286 "y.tab.c"
    break;

  case 394: /* creator_source: _LIT_creator LPAREN creator_name COMMA useful_info COMMA parents RPAREN  */
#line 1025 "SyntaxBNF.y"
                                                                                         {(yyval.pval) = P_BUILD("creator_source", P_TOKEN("_LIT_creator ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 5292 "y.tab.c"
    break;

  case 395: /* creator_name: atomic_word  */
#line 1028 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("creator_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5298 "y.tab.c"
    break;

  case 396: /* parents: LBRKT RBRKT  */
#line 1031 "SyntaxBNF.y"
                      {(yyval.pval) = P_BUILD("parents", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5304 "y.tab.c"
    break;

  case 397: /* parents: LBRKT parent_list RBRKT  */
#line 1032 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("parents", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5310 "y.tab.c"
    break;

  case 398: /* parent_list: parent_info  */
#line 1035 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("parent_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5316 "y.tab.c"
    break;

  case 399: /* parent_list: parent_info COMMA parent_list  */
#line 1036 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("parent_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5322 "y.tab.c"
    break;

  case 400: /* parent_info: source parent_details  */
#line 1039 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("parent_info", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5328 "y.tab.c"
    break;

  case 401: /* parent_details: COLON general_term  */
#line 1042 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("parent_details", P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5334 "y.tab.c"
    break;

  case 402: /* parent_details: nothing  */
#line 1043 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("parent_details", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5340 "y.tab.c"
    break;

  case 403: /* optional_info: COMMA useful_info  */
#line 1046 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("optional_info", P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5346 "y.tab.c"
    break;

  case 404: /* optional_info: nothing  */
#line 1047 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("optional_info", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5352 "y.tab.c"
    break;

  case 405: /* useful_info: general_list  */
#line 1050 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("useful_info", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5358 "y.tab.c"
    break;

  case 406: /* include: _LIT_include LPAREN file_name include_optionals RPAREN PERIOD  */
#line 1053 "SyntaxBNF.y"
                                                                        {(yyval.pval) = P_BUILD("include", P_TOKEN("_LIT_include ", (yyvsp[-5].ival)), P_TOKEN("LPAREN ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL);}
#line 5364 "y.tab.c"
    break;

  case 407: /* include_optionals: nothing  */
#line 1056 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("include_optionals", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5370 "y.tab.c"
    break;

  case 408: /* include_optionals: COMMA formula_selection  */
#line 1057 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("include_optionals", P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5376 "y.tab.c"
    break;

  case 409: /* include_optionals: COMMA formula_selection COMMA space_name  */
#line 1058 "SyntaxBNF.y"
                                                               {(yyval.pval) = P_BUILD("include_optionals", P_TOKEN("COMMA ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5382 "y.tab.c"
    break;

  case 410: /* formula_selection: LBRKT name_list RBRKT  */
#line 1061 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("formula_selection", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5388 "y.tab.c"
    break;

  case 411: /* formula_selection: STAR  */
#line 1062 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("formula_selection", P_TOKEN("STAR ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5394 "y.tab.c"
    break;

  case 412: /* name_list: name  */
#line 1065 "SyntaxBNF.y"
                 {(yyval.pval) = P_BUILD("name_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5400 "y.tab.c"
    break;

  case 413: /* name_list: name COMMA name_list  */
#line 1066 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("name_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5406 "y.tab.c"
    break;

  case 414: /* space_name: name  */
#line 1069 "SyntaxBNF.y"
                  {(yyval.pval) = P_BUILD("space_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5412 "y.tab.c"
    break;

  case 415: /* general_term: general_data  */
#line 1072 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("general_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5418 "y.tab.c"
    break;

  case 416: /* general_term: general_data COLON general_term  */
#line 1073 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("general_term", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5424 "y.tab.c"
    break;

  case 417: /* general_term: general_list  */
#line 1074 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("general_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5430 "y.tab.c"
    break;

  case 418: /* general_data: atomic_word  */
#line 1077 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5436 "y.tab.c"
    break;

  case 419: /* general_data: general_function  */
#line 1078 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5442 "y.tab.c"
    break;

  case 420: /* general_data: variable  */
#line 1079 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5448 "y.tab.c"
    break;

  case 421: /* general_data: number  */
#line 1080 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5454 "y.tab.c"
    break;

  case 422: /* general_data: distinct_object  */
#line 1081 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("general_data", P_TOKEN("distinct_object ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5460 "y.tab.c"
    break;

  case 423: /* general_data: formula_data  */
#line 1082 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5466 "y.tab.c"
    break;

  case 424: /* general_function: atomic_word LPAREN general_terms RPAREN  */
#line 1085 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("general_function", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5472 "y.tab.c"
    break;

  case 425: /* formula_data: _DLR_thf LPAREN thf_formula RPAREN  */
#line 1088 "SyntaxBNF.y"
                                                  {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_thf ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5478 "y.tab.c"
    break;

  case 426: /* formula_data: _DLR_tff LPAREN tff_formula RPAREN  */
#line 1089 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_tff ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5484 "y.tab.c"
    break;

  case 427: /* formula_data: _DLR_fof LPAREN fof_formula RPAREN  */
#line 1090 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_fof ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5490 "y.tab.c"
    break;

  case 428: /* formula_data: _DLR_cnf LPAREN cnf_formula RPAREN  */
#line 1091 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_cnf ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5496 "y.tab.c"
    break;

  case 429: /* formula_data: _DLR_fot LPAREN fof_term RPAREN  */
#line 1092 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_fot ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5502 "y.tab.c"
    break;

  case 430: /* general_list: LBRKT RBRKT  */
#line 1095 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("general_list", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5508 "y.tab.c"
    break;

  case 431: /* general_list: LBRKT general_terms RBRKT  */
#line 1096 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("general_list", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5514 "y.tab.c"
    break;

  case 432: /* general_terms: general_term  */
#line 1099 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("general_terms", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5520 "y.tab.c"
    break;

  case 433: /* general_terms: general_term COMMA general_terms  */
#line 1100 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("general_terms", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5526 "y.tab.c"
    break;

  case 434: /* name: atomic_word  */
#line 1103 "SyntaxBNF.y"
                   {(yyval.pval) = P_BUILD("name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5532 "y.tab.c"
    break;

  case 435: /* name: integer  */
#line 1104 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("name", P_TOKEN("integer ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5538 "y.tab.c"
    break;

  case 436: /* atomic_word: lower_word  */
#line 1107 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("atomic_word", P_TOKEN("lower_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5544 "y.tab.c"
    break;

  case 437: /* atomic_word: single_quoted  */
#line 1108 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("atomic_word", P_TOKEN("single_quoted ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5550 "y.tab.c"
    break;

  case 438: /* atomic_word: back_quoted  */
#line 1109 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("atomic_word", P_TOKEN("back_quoted ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5556 "y.tab.c"
    break;

  case 439: /* atomic_defined_word: dollar_word  */
#line 1112 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("atomic_defined_word", P_TOKEN("dollar_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5562 "y.tab.c"
    break;

  case 440: /* atomic_system_word: dollar_dollar_word  */
#line 1115 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("atomic_system_word", P_TOKEN("dollar_dollar_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5568 "y.tab.c"
    break;

  case 441: /* number: integer  */
#line 1118 "SyntaxBNF.y"
                 {(yyval.pval) = P_BUILD("number", P_TOKEN("integer ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5574 "y.tab.c"
    break;

  case 442: /* number: rational  */
#line 1119 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("number", P_TOKEN("rational ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5580 "y.tab.c"
    break;

  case 443: /* number: real  */
#line 1120 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("number", P_TOKEN("real ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5586 "y.tab.c"
    break;

  case 444: /* file_name: atomic_word  */
#line 1123 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("file_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5592 "y.tab.c"
    break;

  case 445: /* nothing: %empty  */
#line 1126 "SyntaxBNF.y"
          {(yyval.pval) = P_BUILD("nothing",NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5598 "y.tab.c"
    break;


#line 5602 "y.tab.c"

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

