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
  YYSYMBOL_type_constant = 249,            /* type_constant  */
  YYSYMBOL_type_functor = 250,             /* type_functor  */
  YYSYMBOL_defined_type = 251,             /* defined_type  */
  YYSYMBOL_atom = 252,                     /* atom  */
  YYSYMBOL_untyped_atom = 253,             /* untyped_atom  */
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
  YYSYMBOL_theory = 276,                   /* theory  */
  YYSYMBOL_theory_name = 277,              /* theory_name  */
  YYSYMBOL_creator_source = 278,           /* creator_source  */
  YYSYMBOL_creator_name = 279,             /* creator_name  */
  YYSYMBOL_parents = 280,                  /* parents  */
  YYSYMBOL_parent_list = 281,              /* parent_list  */
  YYSYMBOL_parent_info = 282,              /* parent_info  */
  YYSYMBOL_parent_details = 283,           /* parent_details  */
  YYSYMBOL_optional_info = 284,            /* optional_info  */
  YYSYMBOL_useful_info = 285,              /* useful_info  */
  YYSYMBOL_include = 286,                  /* include  */
  YYSYMBOL_include_optionals = 287,        /* include_optionals  */
  YYSYMBOL_formula_selection = 288,        /* formula_selection  */
  YYSYMBOL_name_list = 289,                /* name_list  */
  YYSYMBOL_space_name = 290,               /* space_name  */
  YYSYMBOL_general_term = 291,             /* general_term  */
  YYSYMBOL_general_data = 292,             /* general_data  */
  YYSYMBOL_general_function = 293,         /* general_function  */
  YYSYMBOL_formula_data = 294,             /* formula_data  */
  YYSYMBOL_general_list = 295,             /* general_list  */
  YYSYMBOL_general_terms = 296,            /* general_terms  */
  YYSYMBOL_name = 297,                     /* name  */
  YYSYMBOL_atomic_word = 298,              /* atomic_word  */
  YYSYMBOL_atomic_defined_word = 299,      /* atomic_defined_word  */
  YYSYMBOL_atomic_system_word = 300,       /* atomic_system_word  */
  YYSYMBOL_number = 301,                   /* number  */
  YYSYMBOL_file_name = 302,                /* file_name  */
  YYSYMBOL_nothing = 303                   /* nothing  */
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
#define YYLAST   3432

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  78
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  226
/* YYNRULES -- Number of rules.  */
#define YYNRULES  440
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  815

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
     901,   904,   907,   910,   913,   916,   919,   922,   923,   926,
     927,   930,   933,   936,   939,   942,   945,   948,   951,   954,
     957,   958,   959,   960,   961,   964,   965,   968,   971,   972,
     973,   974,   975,   978,   979,   982,   983,   986,   989,   992,
     995,   998,   999,  1000,  1003,  1006,  1007,  1010,  1013,  1016,
    1019,  1022,  1023,  1026,  1027,  1030,  1033,  1034,  1037,  1038,
    1041,  1044,  1047,  1048,  1049,  1052,  1053,  1056,  1057,  1060,
    1063,  1064,  1065,  1068,  1069,  1070,  1071,  1072,  1073,  1076,
    1079,  1080,  1081,  1082,  1083,  1086,  1087,  1090,  1091,  1094,
    1095,  1098,  1099,  1100,  1103,  1106,  1109,  1110,  1111,  1114,
    1117
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
  "type_constant", "type_functor", "defined_type", "atom", "untyped_atom",
  "defined_infix_pred", "infix_equality", "infix_inequality", "constant",
  "functor", "defined_constant", "defined_functor", "system_constant",
  "system_functor", "th1_defined_term", "defined_term", "variable",
  "source", "sources", "dag_source", "inference_record", "inference_rule",
  "internal_source", "intro_type", "external_source", "file_source",
  "file_info", "theory", "theory_name", "creator_source", "creator_name",
  "parents", "parent_list", "parent_info", "parent_details",
  "optional_info", "useful_info", "include", "include_optionals",
  "formula_selection", "name_list", "space_name", "general_term",
  "general_data", "general_function", "formula_data", "general_list",
  "general_terms", "name", "atomic_word", "atomic_defined_word",
  "atomic_system_word", "number", "file_name", "nothing", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-513)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-351)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -513,   405,  -513,  -513,    50,    77,    80,   116,   153,   200,
     219,  -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,
     359,   359,   226,   359,   359,   359,   359,  -513,  -513,  -513,
    -513,   196,  -513,   252,  -513,   298,   300,   308,   315,   332,
     293,   293,    95,   334,  -513,   293,   293,   293,   293,   368,
     391,   398,   359,  -513,   420,   416,   435,   457,   468,   474,
    2119,  2609,  2051,   480,   497,   359,  -513,   492,  3302,   964,
    2051,  2382,   491,   499,   512,   515,   517,  -513,  -513,  -513,
    -513,  -513,  -513,  -513,   536,  -513,  -513,  -513,   523,  -513,
    2609,  1224,  -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,
    -513,  -513,   268,  -513,  -513,   282,   339,   367,  -513,   540,
     519,  -513,  -513,   539,  -513,   541,  -513,   549,  -513,  -513,
    -513,  -513,  -513,  -513,  -513,  1856,  2051,  -513,  -513,   540,
    -513,  -513,  -513,  -513,   526,   575,   281,  -513,   788,   306,
    -513,  -513,  -513,   551,   569,  2529,  -513,   359,  -513,  -513,
     571,  2680,  -513,   540,  -513,  -513,  -513,   584,   585,   586,
     149,  1735,  1797,   583,  -513,   572,   540,  -513,  -513,  -513,
    -513,   574,   616,   911,   441,  -513,  -513,   449,  -513,  -513,
     379,  -513,  -513,  -513,   477,  -513,  -513,  -513,   367,   551,
    -513,  -513,  -513,  -513,   615,  -513,  2278,   600,  -513,  -513,
     125,   129,   596,  -513,   597,   151,   599,  -513,   406,  -513,
    -513,  -513,  -513,  -513,  -513,  -513,  -513,   149,  1673,  2804,
    -513,  -513,   604,   540,  -513,  -513,  -513,  -513,   592,   631,
     629,   902,   459,  -513,  3054,   439,  -513,  -513,   507,  -513,
    -513,  -513,   456,  -513,  -513,   367,   551,  -513,   102,  -513,
    -513,   606,   567,  -513,  -513,  -513,  -513,  -513,   626,  3125,
    -513,  -513,  -513,  -513,   182,   129,  -513,  -513,  -513,   151,
    -513,  -513,  -513,   464,   540,  -513,  -513,   637,   619,  2609,
    2051,  2401,  3302,   964,  2119,  2119,   617,  2401,  -513,   642,
    -513,  -513,  2401,  -513,  2401,   644,   623,  -513,  1962,  2401,
    2401,  2401,  2529,  -513,   638,   625,   633,   640,   646,  2529,
    2529,  2529,  -513,  -513,  -513,  -513,  -513,  -513,  2529,  2529,
    -513,   639,   590,  -513,  -513,  -513,  -513,   590,   648,   651,
     992,   628,   197,  -513,  -513,  -513,  2463,   645,  -513,  -513,
     675,   135,   656,  -513,  -513,   475,   659,   672,   576,   649,
     673,  3355,  3355,  3355,  3355,  3355,  -513,  3355,  1472,  1472,
     670,   685,   688,  2463,  -513,  -513,  -513,  -513,  -513,   590,
    -513,   707,  3355,  3355,  3355,   215,  2898,  -513,   706,   686,
    -513,  -513,  -513,  -513,   684,   689,   690,  3125,  -513,  -513,
     711,  -513,  -513,   720,   692,  3054,  3054,  3054,  3054,  3054,
    3054,  3054,  -513,  -513,  -513,   514,  -513,  -513,  3054,  1349,
    1349,   702,  1985,  1985,  1985,  1985,  1985,   590,  2898,  -513,
    -513,  -513,  -513,  -513,  3054,   707,   704,  2119,  -513,   714,
     716,  -513,  -513,  -513,   717,   719,   724,  -513,   727,  -513,
     730,  -513,  -513,   644,   729,   741,   747,   756,   759,  -513,
     725,  -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,   713,
    -513,   751,   775,   760,   762,  2529,  -513,  -513,  -513,   765,
    -513,  -513,  -513,  -513,  -513,  -513,   757,   790,   766,   794,
    -513,   797,  -513,   783,   992,   992,  -513,  -513,  -513,   748,
     754,  -513,  -513,   800,  -513,   789,  -513,  -513,  -513,  -513,
    -513,   438,  -513,  -513,  3355,  -513,  -513,   527,   547,   547,
     810,  -513,  -513,  -513,  -513,   796,  -513,  -513,  -513,   544,
    -513,  -513,  -513,  -513,  -513,  -513,  -513,    96,  3249,  3355,
    -513,  -513,  -513,  -513,  -513,  3355,   795,   798,  -513,  -513,
    -513,   805,   806,   807,  1447,  -513,  3054,  -513,   561,  -513,
    -513,   563,   563,   811,  -513,   804,  -513,  -513,  -513,  -513,
    -513,  -513,  -513,  -513,    96,  2195,  2979,  -513,  -513,  -513,
    -513,  -513,  2979,  -513,  -513,   784,  -513,  -513,  -513,  -513,
     809,   833,   839,   815,   629,   846,   847,  -513,   784,  -513,
    -513,  -513,   825,  -513,  -513,  -513,  -513,  -513,  -513,  -513,
    -513,   845,   824,   226,   226,   226,   226,   226,   840,  -513,
    -513,  -513,  -513,  2401,  -513,  -513,  -513,  -513,   850,   590,
     852,   590,   708,  -513,   851,   830,   831,    61,   832,   164,
     708,   590,   708,  1472,   855,  -513,   835,   853,  -513,  -513,
    -513,   834,   859,    75,  -513,   837,   844,  -513,   877,  -513,
    -513,  -513,  1307,   855,  -513,   862,   886,  -513,  -513,  -513,
     865,   889,  3196,  -513,   871,   906,   590,  3054,  -513,  -513,
     644,  -513,   900,  -513,   907,   910,  -513,   916,  -513,   725,
    -513,  -513,  -513,  -513,  2529,  -513,  1550,  -513,   708,  -513,
     992,  -513,  -513,   708,  -513,  -513,   708,  -513,   884,   917,
     896,  -513,   899,   438,  -513,   547,  3249,  -513,   923,  -513,
     928,  -513,  -513,  -513,  3355,   919,   929,  -513,   912,  1447,
    -513,   563,  1673,   928,   934,  -513,  -513,  -513,  -513,  -513,
    -513,   840,   359,   925,  -513,   840,   840,   926,  -513,  -513,
     832,  -513,  -513,  -513,   942,   708,  -513,  -513,  -513,  -513,
     952,   954,   930,   325,  3355,  -513,  3355,  -513,  -513,  -513,
    -513,   244,   957,   943,  3054,  3054,   969,  -513,  -513,   974,
     975,  -513,  1408,  -513,   253,  -513,   953,  -513,  3054,  -513,
    -513,   956,   968,   968,   968,  1315,  -513,  -513,  -513,  -513,
    -513,  -513,  -513,  2221,   958,   962,   965,  1315,   970,  -513,
     982,   972,   987,  -513,  -513,  -513,   967,  -513,  2119,  -513,
    -513,  -513,   644,  -513,  -513
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     440,     0,     2,     1,     0,     0,     0,     0,     0,     0,
       0,     3,     4,    11,     6,     7,     8,     9,    10,     5,
       0,     0,     0,     0,     0,     0,     0,   433,   430,   431,
     432,     0,   429,     0,   439,   440,     0,     0,     0,     0,
       0,     0,     0,     0,   402,     0,     0,     0,     0,    21,
       0,     0,     0,   406,   403,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   407,     0,   401,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   417,   436,   437,
     438,   367,   415,    22,   410,   414,   418,   412,   413,   416,
       0,     0,   366,   435,   434,   314,   311,   276,   277,   280,
     281,   278,   279,   299,   288,   282,   284,     0,   296,   440,
     307,   309,   285,   354,   290,   356,   292,   358,   287,   297,
     355,   357,   359,   365,   330,     0,     0,   331,   340,   440,
     251,   253,   256,   257,   259,   260,   269,   266,     0,   268,
     270,   271,   252,     0,     0,     0,   405,     0,   404,   409,
       0,     0,   247,   440,   246,   248,   249,     0,   285,   292,
       0,     0,     0,     0,   329,     0,   440,   118,   123,   127,
     128,   130,   131,     0,   136,   143,   141,   137,   152,   153,
     142,   156,   157,   161,   138,   158,   165,   164,     0,   187,
     119,   120,   125,   126,     0,   327,     0,     0,   328,   326,
       0,   159,   354,   162,   356,   167,   358,   186,   145,   363,
     362,   364,   322,   321,   320,   360,   323,     0,     0,     0,
     361,   324,     0,   440,    23,    28,    32,    33,    36,    37,
      38,     0,    45,    50,     0,    46,    59,    60,    51,    63,
      64,    69,    47,    65,    72,     0,    67,    24,     0,    34,
     106,   107,   108,    25,    30,    31,    71,   319,     0,     0,
     316,   317,   315,   318,     0,    66,   354,    68,   356,    76,
     358,    74,    73,    52,   440,    13,   425,   427,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   312,     0,
     352,   353,     0,   351,     0,     0,     0,    20,     0,     0,
       0,     0,     0,   303,   305,     0,     0,     0,     0,     0,
       0,     0,   333,   334,   332,   335,   337,   336,     0,     0,
     341,     0,     0,   269,   265,   268,   408,     0,     0,     0,
       0,     0,     0,   238,   240,   239,     0,     0,   190,   182,
     192,   184,     0,   159,   167,   183,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   343,     0,     0,     0,
       0,     0,     0,     0,   154,   139,   140,   142,   145,     0,
     325,     0,     0,     0,     0,     0,     0,    95,    97,     0,
      66,    76,   339,   338,     0,     0,     0,    94,    90,    91,
       0,    92,    93,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    54,    45,    46,    51,    47,    67,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    61,
      48,    49,    51,    52,     0,     0,     0,     0,   426,     0,
       0,   298,   289,   300,     0,     0,     0,   411,     0,   308,
       0,   283,   267,     0,     0,     0,     0,     0,     0,   371,
     440,   368,   376,   369,   370,   381,   382,   383,   375,     0,
     310,     0,   294,     0,     0,     0,   304,   272,   302,     0,
     262,   264,   263,   261,   258,   301,     0,   274,     0,   147,
     149,   150,   195,     0,     0,     0,   194,   197,   199,     0,
     196,   198,   212,     0,   207,   344,   208,   209,   345,   346,
     244,     0,   231,   242,     0,   191,   245,   144,     0,     0,
       0,   170,   349,   350,   243,     0,   133,   136,   137,   142,
     138,   187,   135,   134,   132,   129,   222,     0,     0,     0,
     185,   166,   188,   155,   223,     0,     0,     0,   221,   347,
     348,     0,     0,     0,     0,   224,     0,    96,    53,    70,
     100,     0,     0,     0,    78,     0,    40,    42,    44,    41,
      43,    39,    35,   116,     0,     0,     0,    87,    75,    88,
      62,   117,     0,   104,   111,   109,   110,   113,   112,   114,
       0,    56,     0,     0,   105,     0,   104,    99,   101,   103,
     102,   115,     0,   428,   423,   422,   424,   421,   420,   419,
     313,   373,     0,     0,     0,     0,     0,     0,     0,    19,
     399,    18,   286,     0,   291,   293,   306,    17,     0,     0,
       0,     0,     0,    16,   219,     0,     0,     0,   205,     0,
       0,     0,     0,     0,     0,   237,     0,   233,   236,   235,
     193,     0,   172,     0,    15,     0,     0,   144,     0,   160,
     163,   168,     0,     0,   230,     0,   226,   229,   228,    98,
       0,    80,     0,    14,     0,     0,     0,     0,    53,    12,
       0,   372,     0,   390,   440,     0,   378,     0,   380,   440,
     388,   398,   400,   295,     0,   275,     0,   148,     0,   151,
       0,   218,   200,     0,   211,   206,     0,   215,     0,   213,
       0,   241,     0,     0,   171,     0,     0,   177,     0,   174,
       0,   178,   189,   181,     0,     0,     0,    94,     0,     0,
      79,     0,     0,     0,     0,    82,    89,    55,    57,    58,
     374,     0,     0,     0,   386,     0,     0,     0,   273,   250,
       0,   220,   216,   217,     0,     0,   210,   232,   234,   173,
     156,   179,     0,   184,     0,   342,     0,   146,   225,   227,
      81,    97,    85,     0,     0,     0,     0,   385,   384,     0,
       0,   387,     0,   214,     0,   175,     0,   176,     0,    83,
      84,     0,     0,     0,     0,     0,   204,   201,   202,   180,
     169,    86,    77,     0,     0,     0,     0,     0,     0,   391,
     440,     0,   393,   389,   377,   379,     0,   203,     0,   395,
     397,   392,     0,   396,   394
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,
    -513,   -15,   490,   728,   -20,  -513,  -513,  -513,  -513,  -513,
    -370,  -179,  -513,   779,  -513,  -513,   342,  -513,   -66,  -132,
    -513,   866,  -513,  -513,  -513,    18,  -513,  -513,  -513,   289,
    -513,   355,   240,    21,  -513,   -32,   476,  -178,   353,  -257,
    -513,  -513,  -331,  -513,  -513,  -513,  -466,  -513,   739,   -56,
    -513,  -513,  -513,  -513,  -513,  -292,  -513,  -163,  -513,  -513,
    -330,  -513,  -513,  -287,   827,  -513,    48,  -512,  -513,  -513,
    -280,  -513,  -513,  -513,   329,  -513,   397,  -513,   269,  -513,
    -311,  -238,   524,  -264,   -50,   715,   559,   276,  -513,  -442,
     109,   304,   266,  -513,  -513,   362,  -513,  -453,  -513,  -513,
     336,  -513,  -513,  -513,   356,  -513,  -513,  -177,  -513,  -458,
     603,  -513,   370,  -513,    -1,   -42,  -513,  -513,  -513,  -513,
    -513,  -136,    -9,  -113,  -107,  -513,   443,   -40,  -513,  -513,
    -513,  -513,  -513,  -205,  -513,  -513,  -176,  -166,  -221,    90,
    -513,   932,   743,   595,    -5,  -513,   770,  -513,  -128,  -513,
    -307,   799,  -513,   742,   -26,    -8,  -513,  2351,   -51,   360,
    -224,  -513,  -513,  -513,   647,   -53,  -100,   -17,    -4,   538,
     854,  1598,  1785,  1282,  2084,  -513,  2271,   -49,  -285,   401,
    -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,
    -513,  -513,  -343,   262,  -513,  -513,   396,  -230,  -513,  -513,
    -513,   933,  -513,   -59,  -513,  -513,  -513,  -467,  -184,     5,
     -18,   618,  -115,   -47,   472,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    11,    12,    13,   274,    14,    15,    16,    17,
      18,   296,    50,   223,   378,   225,   226,   227,   228,   229,
     230,   231,   419,   232,   233,   234,   580,   581,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   553,   660,
     724,   762,   763,   245,   385,   407,   379,   247,   587,   248,
     589,   249,   250,   251,   252,   253,   254,   255,   166,   339,
     168,   169,   170,   171,   172,   173,   364,   174,   175,   176,
     478,   479,   480,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   510,   641,   708,   751,   710,   752,   187,
     340,   188,   341,   342,   328,   624,   487,   488,   787,   489,
     490,   700,   491,   629,   492,   625,   191,   192,   193,   256,
     655,   656,   657,   194,   636,   637,   638,   332,   333,   639,
     257,   153,   154,   155,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   476,   141,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   461,   107,
     108,   142,   143,   305,   156,   110,   111,   258,   259,   260,
     261,   371,   196,   262,   198,   388,   389,   263,   360,   764,
     357,   494,   495,   496,   538,   157,   292,   391,   392,   380,
     266,   267,   268,   381,   270,   271,   272,   119,   601,   602,
     451,   452,   675,   453,   677,   454,   455,   733,   456,   679,
     457,   672,   794,   801,   802,   809,   609,   681,    19,    43,
      54,    63,   148,   277,    84,    85,    86,    87,   278,   458,
     120,   121,   122,   123,    35,   297
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       2,    83,    32,    32,    34,    32,    32,    32,    32,   323,
     450,    82,   167,    89,   408,   200,   264,   152,   190,   208,
     273,    96,    82,   493,    89,    31,    33,    96,    36,    37,
      38,    39,   324,   365,    32,    44,   144,   246,   325,   537,
     375,   386,    88,   627,   144,   335,   526,    32,   635,   224,
      96,   288,    95,    88,   584,   402,   109,    64,    95,   516,
     522,   523,   524,   525,   518,   518,   518,   518,   518,   275,
     149,   520,   520,   520,   520,   520,   431,    20,   654,   463,
     464,    95,   576,   304,   306,   286,   658,   431,   358,   431,
     293,   387,   321,   590,   431,   431,   431,   706,   693,   144,
     144,   438,   335,   294,    21,   432,   347,    22,   541,   542,
     543,    96,   208,   208,   308,   433,   432,    52,   432,   144,
     531,   533,   630,   432,   432,   432,   433,   421,   433,    32,
     319,   707,    53,   433,   433,   433,   330,    27,   329,   412,
    -349,   682,    95,    23,    29,   409,   286,   368,    30,  -187,
     370,   350,    64,  -187,  -349,   574,   575,   577,   578,   579,
      93,    94,  -350,   413,   320,   355,   390,   588,   404,   273,
     273,   293,   414,   323,   323,   323,  -350,   493,   493,   331,
      24,   289,   323,   323,   359,   273,   246,   246,   517,   517,
     517,   517,   517,   424,   750,   411,   470,   471,   472,   384,
     695,   696,   325,   325,   325,   473,   474,   370,   394,    40,
     423,   325,   325,    93,    94,   554,   556,   557,   558,   559,
     560,   561,   562,   401,   501,   437,   167,    25,   293,   200,
     264,   502,   190,   208,   273,    82,    82,    89,    89,    96,
     640,   410,   544,   593,   367,   585,    26,   440,   387,   545,
     635,   246,   406,   654,   144,   421,   755,   546,    96,   426,
     306,   658,   707,   224,   682,    41,    88,    88,   682,   682,
      95,   646,   293,   477,   429,   528,   144,    32,   481,   430,
     347,   497,  -298,   144,   144,   144,  -298,   208,    27,    95,
     387,   687,   144,   144,  -254,    29,  -289,   584,   511,    30,
    -289,   698,   208,   208,   208,   208,   208,   536,   208,   532,
     532,    42,   498,    45,   208,    27,  -254,  -254,   539,  -255,
     481,    46,    29,   208,   208,   208,    30,   273,    47,   404,
     404,   404,   404,   404,   404,   404,   590,  -178,   423,  -187,
     390,  -255,  -255,  -187,   246,    48,   273,   273,   273,   273,
     273,   273,   273,  -300,   320,   806,   384,  -300,   404,   273,
     569,   569,    49,   423,   423,   423,   423,   423,   582,   273,
      55,   434,   539,   661,   386,   273,   246,   289,    82,   571,
      89,   290,   441,   493,   442,   291,   246,   375,   563,   462,
     462,   462,   683,  -185,   356,   701,    60,  -185,   583,   519,
     519,   519,   519,   519,    61,     3,   530,   530,   431,    88,
     588,    62,   335,   406,   406,   406,   406,   406,   406,   406,
    -188,    27,   757,   304,  -188,    32,    28,   518,    29,   408,
     568,   570,    30,    65,   520,   497,   497,   432,   387,   144,
     795,   796,   406,   776,   387,   777,    66,   433,    67,   335,
     610,   -27,   -27,     4,  -121,   208,     5,     6,   642,   527,
       7,     8,  -122,     9,    10,   493,   498,   498,   -29,   -29,
      68,   -26,   -26,   645,   -27,   -27,  -121,  -121,   -88,   208,
     208,    69,   -88,   163,  -122,  -122,   208,    70,   585,  -186,
    -124,   -29,   -29,  -186,   -26,   -26,  -104,   273,   390,   390,
      27,   766,    93,    94,   633,   769,   770,    29,   800,   150,
     147,    30,  -124,  -124,   246,   146,   273,   273,   279,   151,
    -104,   -87,   356,   273,   717,   -87,   280,   800,   -87,  -104,
      91,    51,   -87,   246,   246,    56,    57,    58,    59,   281,
     246,  -189,   282,   661,   283,  -189,   664,   284,   323,   634,
     285,   517,   583,   295,    27,    92,    93,    94,  -185,    78,
     298,    29,  -185,    79,    80,    30,   299,   309,   300,    81,
     477,   738,   481,   497,   509,   -89,   301,   325,   310,   -89,
     320,   497,   481,   497,   532,   673,    34,   676,   678,   680,
     552,   322,   189,   327,   628,   330,  -349,  -350,   508,   112,
     112,   404,   349,   509,   498,   158,   201,   265,   112,    27,
     348,    93,   498,   273,   498,   351,    29,   582,   273,   352,
      30,   361,   369,   372,   373,    27,   374,    93,   112,   112,
     246,   393,    29,   395,   396,   397,    30,   416,    27,   497,
      93,   497,   723,   415,   497,    29,    96,   497,   417,    30,
     427,   465,    32,   439,   428,   642,   290,   208,   144,   459,
     466,   125,   500,   112,   112,   208,   443,    81,   390,   467,
     498,   195,   498,   273,   734,   498,   468,    95,   498,   610,
     503,   530,   469,   112,   482,   406,   189,   483,   504,   158,
     246,   505,   528,   444,   445,   506,   497,   446,   447,   343,
     201,   448,   761,   462,   449,   208,    27,   208,   507,   515,
     514,    28,   535,    29,    32,   273,   273,    30,   337,   546,
     548,   547,   424,   497,   565,   549,   550,   498,   555,   273,
     484,   689,   246,   246,   343,   688,   497,   767,   608,   697,
     592,   699,   551,   611,   780,   781,   246,   552,   497,   813,
     594,   634,   595,   596,   498,   597,   603,   265,   723,    82,
     598,    89,   519,   599,   195,   195,   600,   498,   604,    27,
      27,    93,    94,    94,   605,    32,    29,    29,   334,   498,
      30,    30,    27,   606,    93,    81,   607,   612,   613,    29,
      88,   311,   618,    30,    32,   617,   614,   740,   615,   195,
     810,   620,   742,   619,   312,   743,   189,   621,   622,   630,
     197,   313,   314,   623,   315,  -205,   632,   112,   112,   112,
     201,   265,   631,   643,   662,   112,   644,   316,   317,   318,
     112,   647,   112,   648,   663,   334,   112,   112,   112,   112,
     112,   649,   650,   651,   665,   413,   666,   112,   112,   112,
     667,   668,   399,   -45,   699,   669,   112,   112,   670,   671,
     189,   684,    71,   686,   690,   691,   703,   692,   694,   704,
     356,   702,   705,   712,   343,   521,   521,   521,   521,   521,
     713,   788,   521,   521,   534,   195,   512,   189,   714,   343,
     343,   343,   343,   343,   628,   343,   343,   343,   718,   719,
     720,   343,   721,   197,   197,   398,   628,   726,   399,   512,
     343,   343,   343,   731,   353,   113,   113,   727,   312,   744,
     732,   113,   202,   735,   113,   313,   314,   312,   315,   736,
     745,   512,   746,   747,   313,   314,   754,   315,   197,   195,
     755,   316,   317,   400,   113,   113,   758,   765,   499,   331,
     316,   317,   354,   772,   195,   195,   195,   195,   195,   346,
     195,   768,   771,   512,  -177,   775,   195,   774,   209,   210,
     778,   211,   212,   213,   214,   195,   195,   195,   779,   113,
     113,   124,   782,   215,   216,   217,   218,   783,   784,   790,
     793,   219,   792,   808,   803,   127,   220,   221,   804,   113,
     812,   805,   128,   112,   693,   113,   807,   811,   728,   222,
     760,   436,   216,   403,   484,   202,   202,   725,   791,   485,
     729,   435,   659,   366,   197,   221,    27,    92,    93,    94,
     164,    78,   165,    29,   749,    79,    80,    30,   420,   343,
     709,    81,   343,   789,   626,   486,   512,   512,   786,   773,
     202,   798,   741,   189,    27,   759,   739,    94,   307,   748,
     616,    29,   685,   425,   475,    30,   343,   343,   460,    81,
     756,   730,   591,   343,   814,   737,   674,     0,   197,     0,
     326,     0,     0,     0,     0,     0,     0,     0,     0,   512,
     512,     0,     0,   197,   197,   197,   197,   197,     0,   197,
     405,     0,   499,   499,     0,   197,     0,   195,     0,     0,
       0,     0,     0,     0,   197,   197,   197,     0,     0,     0,
       0,     0,     0,     0,     0,   422,     0,     0,     0,     0,
       0,   195,   195,   113,   113,   113,   202,     0,   195,     0,
       0,   113,     0,     0,     0,   334,   113,     0,   113,     0,
       0,   112,   113,   113,   113,   113,   113,   521,     0,     0,
       0,     0,     0,   113,   113,   113,   420,   711,     0,     0,
       0,   343,   113,   113,   403,   403,   403,   403,   403,   403,
     403,   343,   334,     0,     0,     0,     0,     0,     0,     0,
     202,   573,   573,   573,   573,   573,     0,     0,     0,     0,
       0,     0,     0,   586,     0,   202,   202,   202,   202,   202,
       0,   202,   202,   202,     0,     0,     0,   202,     0,     0,
       0,     0,   112,     0,   112,     0,   202,   202,   202,     0,
     753,     0,     0,     0,     0,     0,     0,     0,   521,     0,
     499,   343,     0,   512,   343,     0,   197,     0,   499,     0,
     499,   287,   343,   422,     0,     0,     0,     0,     0,   512,
       0,   405,   405,   405,   405,   405,   405,   405,     0,     0,
     197,   197,     0,     0,     0,   567,   567,   197,   422,   422,
     422,   422,   422,     0,     0,     0,    27,    92,    93,    94,
     405,    78,   343,    29,   343,    79,    80,    30,   711,     0,
       0,    81,     0,     0,     0,     0,   499,     0,   499,   195,
     382,   499,   343,     0,   499,     0,     0,   195,     0,   113,
       0,   290,     0,   312,     0,   291,     0,     0,   715,   362,
     313,   314,     0,   315,   716,     0,     0,   484,     0,     0,
       0,     0,   797,   116,   116,   128,   316,   317,   383,   159,
     205,   269,   116,   209,   210,   202,   211,   195,   202,   195,
       0,     0,     0,   499,     0,     0,     0,     0,   215,     0,
     564,   565,   116,   116,     0,   165,   566,    27,     0,     0,
      94,   220,   202,   202,    29,     0,     0,     0,    30,   202,
     499,     0,    81,     0,   222,     0,     0,     0,     0,     0,
       0,     0,     0,   499,     0,     0,     0,   116,   116,     0,
     653,    27,    92,    93,    94,   499,    78,     0,    29,     0,
      79,    80,    30,     0,     0,     0,    81,   116,   216,     0,
     484,     0,     0,   159,     0,   785,     0,     0,     0,     0,
       0,   221,     0,   344,   205,     0,   586,     0,   197,     0,
       0,   209,   210,     0,   211,     0,   197,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   215,   113,   564,   565,
      27,     0,     0,    94,   652,     0,     0,    29,   344,   220,
       0,    30,     0,     0,     0,    81,     0,   202,     0,     0,
       0,     0,   222,   527,   528,     0,   197,   202,   197,   529,
       0,   269,     0,     0,     0,     0,     0,     0,     0,    27,
      92,    93,    94,   633,    78,     0,    29,   163,    79,    80,
      30,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   405,    27,    92,    93,    94,   113,    78,
     113,    29,     0,    79,    80,    30,     0,     0,     0,    81,
       0,     0,     0,     0,     0,     0,     0,   202,     0,     0,
     202,   116,   116,   116,   205,   269,     0,   150,   202,   116,
       0,     0,     0,     0,   116,     0,   116,    90,     0,     0,
     116,   116,   116,   116,   116,   653,     0,     0,    91,     0,
       0,   116,   116,   116,     0,     0,     0,     0,     0,     0,
     116,   116,     0,     0,     0,     0,     0,     0,   202,     0,
     202,     0,    27,    92,    93,    94,     0,    78,   344,    29,
       0,    79,    80,    30,     0,     0,     0,    81,   202,     0,
     513,     0,     0,   344,   344,   344,   344,   344,     0,   344,
     344,   344,     0,     0,     0,   344,     0,     0,     0,     0,
       0,     0,     0,   513,   344,   344,   344,     0,     0,   114,
     114,     0,     0,     0,     0,   114,   203,     0,   114,     0,
       0,     0,     0,     0,     0,   513,     0,   209,   210,     0,
     211,   212,   213,   214,     0,     0,     0,     0,   114,   114,
     124,     0,   215,   216,   217,   218,     0,     0,     0,     0,
     376,     0,     0,   337,   127,   220,   221,   513,   377,     0,
       0,   128,     0,     0,     0,     0,     0,     0,   222,     0,
       0,     0,     0,   114,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,    92,    93,    94,   164,
      78,   165,    29,   114,    79,    80,    30,   116,     0,   114,
      81,     0,   124,     0,     0,     0,   160,   161,     0,   203,
     203,     0,   336,     0,     0,   337,   127,     0,     0,     0,
     338,     0,     0,   128,     0,     0,     0,     0,     0,     0,
     163,     0,     0,   344,     0,     0,   344,     0,     0,     0,
     513,   513,     0,     0,   203,     0,     0,    27,    92,    93,
      94,   164,    78,   165,    29,     0,    79,    80,    30,     0,
     344,   344,    81,     0,   124,     0,     0,   344,   160,   161,
       0,     0,     0,     0,   162,     0,     0,   346,   127,     0,
       0,     0,     0,   513,   513,   128,     0,     0,     0,     0,
       0,     0,   163,     0,     0,     0,   115,   115,     0,     0,
       0,     0,   115,   204,     0,   115,     0,     0,     0,    27,
      92,    93,    94,   164,    78,   165,    29,     0,    79,    80,
      30,     0,     0,   124,    81,   115,   115,   114,   114,   114,
     203,     0,     0,   302,     0,   114,     0,   127,     0,     0,
     114,   303,   114,     0,   128,   116,   114,   114,   114,   114,
     114,     0,     0,     0,     0,     0,     0,   114,   114,   114,
     115,   115,     0,     0,     0,   344,   114,   114,    27,    92,
      93,    94,     0,    78,     0,    29,     0,    79,    80,    30,
     115,     0,     0,    81,   203,     0,   115,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   204,   204,     0,   203,
     203,   203,   203,   203,     0,   203,   203,   203,     0,     0,
       0,   203,     0,     0,     0,     0,   116,     0,   116,   540,
     203,   203,   203,     0,     0,     0,     0,     0,     0,     0,
       0,   204,     0,     0,     0,   344,     0,   513,   344,   209,
     210,     0,   211,   212,   213,   214,   344,     0,     0,     0,
      91,     0,   124,   513,   215,   216,   564,   565,     0,     0,
       0,     0,   572,     0,     0,     0,   127,   220,   221,     0,
       0,     0,     0,   540,    27,    92,    93,    94,     0,    78,
     222,    29,     0,    79,    80,    30,   344,     0,   344,    81,
       0,     0,     0,     0,     0,     0,     0,    27,    92,    93,
      94,   164,    78,     0,    29,     0,    79,    80,    30,     0,
       0,     0,    81,   114,   115,   115,   115,   204,   124,     0,
       0,     0,   115,   125,     0,     0,     0,   115,   126,   115,
       0,     0,   127,   115,   115,   115,   115,   115,     0,   128,
       0,     0,     0,     0,   115,   115,   115,     0,     0,   203,
       0,     0,   203,   115,   115,     0,     0,     0,     0,     0,
       0,     0,     0,    27,    92,    93,    94,     0,    78,     0,
      29,   204,    79,    80,    30,     0,   203,   203,    81,     0,
       0,     0,     0,   203,     0,     0,   204,   204,   204,   204,
     204,    71,   204,   204,   204,   117,   117,     0,   204,     0,
       0,   117,   206,     0,   117,     0,     0,   204,   204,   204,
       0,    72,    73,    74,     0,    75,    76,     0,     0,     0,
       0,     0,     0,     0,   117,   117,     0,     0,     0,     0,
       0,    27,    77,     0,     0,     0,    78,     0,    29,     0,
      79,    80,    30,     0,     0,     0,    81,     0,     0,   209,
     210,     0,   211,   212,   213,   214,     0,     0,     0,   117,
     117,   114,   124,     0,   215,   216,   217,   218,     0,     0,
       0,     0,   376,     0,     0,     0,   127,   220,   221,   117,
     377,   203,     0,   128,     0,   117,     0,     0,     0,     0,
     222,     0,     0,   443,     0,   206,   206,     0,     0,     0,
     115,     0,     0,     0,     0,     0,   799,    27,    92,    93,
      94,   164,    78,   165,    29,     0,    79,    80,    30,     0,
     444,   445,    81,     0,   446,   447,     0,     0,   448,     0,
     206,   449,   114,    27,   114,     0,   204,     0,    28,   204,
      29,     0,     0,     0,    30,   124,     0,     0,     0,   160,
     362,   203,     0,     0,   203,   363,     0,     0,     0,   127,
       0,     0,   203,   204,   204,     0,   128,     0,     0,     0,
     204,     0,     0,   163,     0,     0,     0,     0,     0,     0,
       0,     0,   118,   118,     0,     0,     0,     0,   118,   207,
      27,   118,    93,    94,   164,     0,   165,    29,     0,     0,
       0,    30,   203,     0,   203,    81,     0,     0,     0,     0,
       0,   118,   118,   117,   117,   117,   206,     0,     0,     0,
       0,   117,     0,     0,     0,     0,   117,     0,   117,     0,
       0,     0,   117,   117,   117,   117,   117,     0,     0,     0,
       0,     0,     0,   117,   117,   117,   118,   118,   115,     0,
       0,     0,   117,   117,    71,     0,     0,     0,     0,     0,
       0,     0,     0,   145,     0,     0,   118,   276,   204,   199,
     206,   145,   118,     0,    72,    73,    74,     0,    75,    76,
       0,     0,   345,   207,     0,   206,   206,   206,   206,   206,
       0,   206,   206,   206,    27,    77,     0,   206,     0,    78,
       0,    29,     0,    79,    80,    30,   206,   206,   206,    81,
       0,     0,     0,    27,    92,    93,    94,     0,    78,   115,
      29,   115,    79,    80,    30,     0,   145,   145,    81,     0,
     124,     0,     0,     0,   160,   161,     0,     0,   204,     0,
     336,   204,     0,   346,   127,     0,   145,     0,     0,   204,
       0,   128,     0,     0,     0,     0,     0,     0,   163,     0,
       0,     0,   199,   199,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,    92,    93,    94,   164,
      78,   165,    29,     0,    79,    80,    30,     0,     0,   204,
      81,   204,     0,     0,     0,     0,   124,   199,     0,   117,
     118,   118,   118,   207,     0,     0,   302,     0,   118,     0,
     127,     0,     0,   118,     0,   118,     0,   128,     0,   118,
     118,   118,   118,   118,     0,     0,     0,     0,     0,     0,
     118,   118,   118,     0,     0,   206,     0,     0,   206,   118,
     118,    27,    92,    93,    94,     0,    78,     0,    29,     0,
      79,    80,    30,     0,     0,     0,    81,   207,     0,     0,
       0,     0,   206,   206,     0,     0,     0,     0,     0,   206,
       0,     0,   207,   207,   207,   207,   207,     0,   345,   207,
     207,   145,     0,   199,   207,     0,    90,     0,     0,     0,
       0,     0,     0,   345,   345,   345,     0,    91,     0,     0,
       0,     0,     0,   145,     0,     0,     0,     0,     0,     0,
     145,   145,   145,     0,     0,     0,     0,     0,     0,   145,
     145,    27,    92,    93,    94,     0,    78,     0,    29,     0,
      79,    80,    30,     0,     0,     0,    81,   199,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   117,     0,     0,
       0,     0,   199,   199,   199,   199,   199,   151,   199,     0,
       0,     0,     0,     0,   199,     0,     0,   206,    91,     0,
       0,     0,     0,   199,   199,   199,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   118,     0,     0,     0,
       0,     0,    27,    92,    93,    94,     0,    78,     0,    29,
       0,    79,    80,    30,     0,     0,     0,    81,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   117,     0,
     117,     0,     0,     0,     0,   345,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   206,     0,     0,
     206,     0,     0,     0,     0,     0,     0,     0,   206,   345,
     207,     0,     0,     0,     0,     0,   345,   382,   209,   210,
       0,   211,   212,   213,   214,     0,   145,     0,   290,     0,
     312,   124,   291,   215,   216,   217,   218,   313,   314,     0,
     315,   219,     0,     0,   346,   127,   220,   221,   206,     0,
     206,     0,   128,   316,   317,   383,     0,     0,     0,   222,
       0,     0,     0,     0,     0,   199,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    27,    92,    93,    94,
     164,    78,   165,    29,     0,    79,    80,    30,     0,   199,
     199,    81,     0,     0,   118,     0,   199,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   382,   209,   210,   207,   211,   212,   213,   214,     0,
       0,     0,   290,     0,   312,   124,   291,   215,   216,   217,
     218,   313,   314,     0,   315,   376,     0,     0,   346,   127,
     220,   221,     0,     0,     0,     0,   128,   316,   317,   383,
       0,     0,     0,   222,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   118,     0,   118,     0,     0,
      27,    92,    93,    94,   164,    78,   165,    29,     0,    79,
      80,    30,     0,     0,     0,    81,     0,   345,     0,     0,
       0,     0,   382,   209,   210,   207,   211,   212,   213,   214,
       0,     0,     0,   290,     0,   312,   124,   291,   215,   216,
     217,   218,   313,   314,     0,   315,   376,     0,     0,     0,
     127,   220,   221,     0,     0,     0,     0,   128,   316,   317,
     383,     0,     0,     0,   222,   345,     0,   345,     0,     0,
       0,     0,     0,     0,     0,   145,     0,     0,     0,     0,
       0,    27,    92,    93,    94,   164,    78,   165,    29,     0,
      79,    80,    30,     0,     0,     0,    81,   199,   209,   210,
       0,   211,   212,   213,   214,   199,     0,     0,     0,     0,
       0,   124,     0,   215,   216,   217,   218,     0,     0,     0,
       0,   376,     0,     0,     0,   127,   220,   221,     0,     0,
       0,     0,   128,     0,     0,     0,     0,     0,     0,   222,
       0,     0,     0,     0,     0,   199,     0,   199,     0,     0,
       0,     0,     0,     0,     0,     0,    27,    92,    93,    94,
     164,    78,   165,    29,     0,    79,    80,    30,     0,   209,
     210,    81,   211,   212,   213,   214,     0,     0,     0,     0,
       0,     0,   124,     0,   215,   216,   217,   218,     0,     0,
       0,     0,   418,     0,     0,     0,   127,   220,   221,     0,
       0,     0,     0,   128,     0,     0,     0,     0,     0,     0,
     222,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,    92,    93,
      94,   164,    78,   165,    29,     0,    79,    80,    30,     0,
     209,   210,    81,   211,   212,   213,   214,     0,     0,     0,
       0,     0,     0,   124,     0,   215,   216,   217,   722,     0,
       0,     0,     0,   376,     0,     0,     0,   127,   220,   221,
       0,     0,     0,     0,   128,     0,     0,     0,     0,     0,
       0,   222,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,    92,
      93,    94,   164,    78,   165,    29,   124,    79,    80,    30,
     160,   161,     0,    81,     0,     0,   336,     0,     0,     0,
     127,     0,     0,     0,   338,     0,     0,   128,     0,     0,
       0,     0,     0,     0,   163,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    27,    92,    93,    94,   164,    78,   165,    29,   124,
      79,    80,    30,   160,   161,     0,    81,     0,     0,   162,
       0,     0,     0,   127,     0,     0,     0,     0,     0,     0,
     128,     0,     0,     0,     0,     0,     0,   163,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,    92,    93,    94,   164,    78,
     165,    29,   124,    79,    80,    30,   160,   161,     0,    81,
       0,     0,   336,     0,     0,     0,   127,     0,     0,     0,
       0,     0,     0,   128,     0,     0,     0,     0,     0,     0,
     163,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,    92,    93,
      94,   164,    78,   165,    29,     0,    79,    80,    30,     0,
       0,     0,    81
};

static const yytype_int16 yycheck[] =
{
       0,    60,    20,    21,    22,    23,    24,    25,    26,   145,
     295,    60,    68,    60,   238,    68,    69,    67,    68,    68,
      69,    61,    71,   330,    71,    20,    21,    67,    23,    24,
      25,    26,   145,   196,    52,    35,    62,    69,   145,   369,
     217,   219,    60,   485,    70,   160,   357,    65,   501,    69,
      90,    91,    61,    71,   424,   234,    61,    52,    67,   351,
     352,   353,   354,   355,   351,   352,   353,   354,   355,    70,
      65,   351,   352,   353,   354,   355,   281,    27,   544,   300,
     301,    90,   413,   125,   126,    90,   544,   292,   188,   294,
     107,   219,   143,   424,   299,   300,   301,    22,    37,   125,
     126,   285,   217,   107,    27,   281,   162,    27,   372,   373,
     374,   151,   161,   162,   129,   281,   292,    22,   294,   145,
     358,   359,    61,   299,   300,   301,   292,   259,   294,   147,
     138,   643,    37,   299,   300,   301,    11,    62,   153,    37,
      11,   608,   151,    27,    69,   245,   151,   196,    73,    14,
      25,   166,   147,    18,    25,   412,   413,   414,   415,   416,
      64,    65,    11,    61,    29,   173,   219,   424,   234,   218,
     219,   188,    70,   309,   310,   311,    25,   484,   485,    30,
      27,    91,   318,   319,   188,   234,   218,   219,   351,   352,
     353,   354,   355,    11,   706,   246,   309,   310,   311,   219,
      36,    37,   309,   310,   311,   318,   319,    25,   223,    13,
     259,   318,   319,    64,    65,   393,   395,   396,   397,   398,
     399,   400,   401,   231,    27,   284,   282,    27,   245,   282,
     283,    34,   282,   282,   283,   284,   285,   284,   285,   279,
     504,   245,    27,   427,   196,   424,    27,   287,   376,    34,
     703,   283,   234,   719,   280,   387,    12,    13,   298,   274,
     302,   719,   774,   283,   731,    13,   284,   285,   735,   736,
     279,   535,   289,   322,   279,    22,   302,   295,   327,   280,
     336,   330,    14,   309,   310,   311,    18,   336,    62,   298,
     418,   621,   318,   319,    13,    69,    14,   667,   348,    73,
      18,   631,   351,   352,   353,   354,   355,   363,   357,   358,
     359,    13,   330,    13,   363,    62,    35,    36,   371,    13,
     369,    13,    69,   372,   373,   374,    73,   376,    13,   395,
     396,   397,   398,   399,   400,   401,   667,    12,   387,    14,
     393,    35,    36,    18,   376,    13,   395,   396,   397,   398,
     399,   400,   401,    14,    29,   797,   376,    18,   424,   408,
     409,   410,    69,   412,   413,   414,   415,   416,   417,   418,
      36,   281,   425,   551,   552,   424,   408,   287,   427,   411,
     427,    14,   292,   690,   294,    18,   418,   564,   408,   299,
     300,   301,   613,    14,    15,   633,    28,    18,   418,   351,
     352,   353,   354,   355,    13,     0,   358,   359,   613,   427,
     667,    13,   527,   395,   396,   397,   398,   399,   400,   401,
      14,    62,   714,   465,    18,   443,    67,   714,    69,   653,
     409,   410,    73,    13,   714,   484,   485,   613,   566,   465,
     783,   784,   424,   754,   572,   756,    30,   613,    13,   564,
     450,    12,    13,    48,    13,   504,    51,    52,   508,    21,
      55,    56,    13,    58,    59,   772,   484,   485,    12,    13,
      13,    12,    13,   529,    35,    36,    35,    36,    14,   528,
     529,    13,    18,    45,    35,    36,   535,    13,   667,    14,
      13,    35,    36,    18,    35,    36,    37,   546,   551,   552,
      62,   731,    64,    65,    66,   735,   736,    69,   793,    17,
      13,    73,    35,    36,   546,    35,   565,   566,    27,    27,
      61,    14,    15,   572,   652,    18,    27,   812,    14,    70,
      38,    41,    18,   565,   566,    45,    46,    47,    48,    27,
     572,    14,    27,   721,    27,    18,   566,    11,   684,   501,
      27,   714,   572,    13,    62,    63,    64,    65,    14,    67,
      41,    69,    18,    71,    72,    73,    27,    41,    27,    77,
     619,   684,   621,   622,    27,    14,    27,   684,     3,    18,
      29,   630,   631,   632,   633,   603,   604,   605,   606,   607,
      27,    22,    68,    22,   485,    11,    11,    11,    22,    61,
      62,   667,    30,    27,   622,    67,    68,    69,    70,    62,
      27,    64,   630,   662,   632,    41,    69,   666,   667,     3,
      73,     6,    22,    27,    27,    62,    27,    64,    90,    91,
     662,    27,    69,    41,     3,     6,    73,    70,    62,   688,
      64,   690,   662,    37,   693,    69,   686,   696,    22,    73,
      13,    13,   670,    36,    35,   705,    14,   706,   684,    36,
      35,    22,    34,   125,   126,   714,    22,    77,   721,    36,
     688,    68,   690,   722,   674,   693,    36,   686,   696,   679,
      35,   633,    36,   145,    36,   667,   162,    36,    13,   151,
     722,    35,    22,    49,    50,    36,   745,    53,    54,   161,
     162,    57,   722,   613,    60,   754,    62,   756,    36,    36,
      61,    67,    27,    69,   732,   764,   765,    73,    30,    13,
      36,    35,    11,   772,    22,    36,    36,   745,    36,   778,
      22,   622,   764,   765,   196,    27,   785,   732,    13,   630,
      36,   632,    22,    30,   764,   765,   778,    27,   797,   808,
      36,   703,    36,    36,   772,    36,    27,   219,   778,   808,
      36,   808,   714,    36,   161,   162,    36,   785,    27,    62,
      62,    64,    65,    65,    27,   793,    69,    69,   160,   797,
      73,    73,    62,    27,    64,    77,    27,    36,    13,    69,
     808,     3,    35,    73,   812,    30,    36,   688,    36,   196,
     800,    35,   693,    13,    16,   696,   282,    13,    11,    61,
      68,    23,    24,    30,    26,    61,    27,   279,   280,   281,
     282,   283,    22,    13,    13,   287,    30,    39,    40,    41,
     292,    36,   294,    35,    30,   217,   298,   299,   300,   301,
     302,    36,    36,    36,    35,    61,    13,   309,   310,   311,
      11,    36,     6,     6,   745,    30,   318,   319,    13,    35,
     336,    11,    22,    11,    13,    35,    13,    36,    36,    35,
      15,    36,    13,    36,   336,   351,   352,   353,   354,   355,
      36,   772,   358,   359,   360,   282,   348,   363,    11,   351,
     352,   353,   354,   355,   785,   357,   358,   359,    36,    13,
      35,   363,    13,   161,   162,     3,   797,    36,     6,   371,
     372,   373,   374,    13,     3,    61,    62,    11,    16,    35,
      13,    67,    68,    13,    70,    23,    24,    16,    26,    13,
      13,   393,    36,    34,    23,    24,    13,    26,   196,   336,
      12,    39,    40,    41,    90,    91,    34,    13,   330,    30,
      39,    40,    41,    11,   351,   352,   353,   354,   355,    30,
     357,    36,    36,   425,    12,    35,   363,    13,     4,     5,
      13,     7,     8,     9,    10,   372,   373,   374,    35,   125,
     126,    17,    13,    19,    20,    21,    22,    13,    13,    36,
      22,    27,    36,    11,    36,    31,    32,    33,    36,   145,
      13,    36,    38,   465,    37,   151,    36,    35,   666,    45,
     721,   283,    20,   234,    22,   161,   162,   662,   778,    27,
     667,   282,   546,   196,   282,    33,    62,    63,    64,    65,
      66,    67,    68,    69,   705,    71,    72,    73,   259,   501,
     643,    77,   504,   774,   485,   330,   508,   509,   772,   745,
     196,   785,   690,   529,    62,   719,   686,    65,   126,   703,
     465,    69,   619,   264,   321,    73,   528,   529,   298,    77,
     710,   670,   425,   535,   812,   679,   604,    -1,   336,    -1,
     147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   551,
     552,    -1,    -1,   351,   352,   353,   354,   355,    -1,   357,
     234,    -1,   484,   485,    -1,   363,    -1,   504,    -1,    -1,
      -1,    -1,    -1,    -1,   372,   373,   374,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,
      -1,   528,   529,   279,   280,   281,   282,    -1,   535,    -1,
      -1,   287,    -1,    -1,    -1,   527,   292,    -1,   294,    -1,
      -1,   613,   298,   299,   300,   301,   302,   633,    -1,    -1,
      -1,    -1,    -1,   309,   310,   311,   387,   643,    -1,    -1,
      -1,   633,   318,   319,   395,   396,   397,   398,   399,   400,
     401,   643,   564,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     336,   412,   413,   414,   415,   416,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   424,    -1,   351,   352,   353,   354,   355,
      -1,   357,   358,   359,    -1,    -1,    -1,   363,    -1,    -1,
      -1,    -1,   684,    -1,   686,    -1,   372,   373,   374,    -1,
     706,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   714,    -1,
     622,   703,    -1,   705,   706,    -1,   504,    -1,   630,    -1,
     632,    27,   714,   387,    -1,    -1,    -1,    -1,    -1,   721,
      -1,   395,   396,   397,   398,   399,   400,   401,    -1,    -1,
     528,   529,    -1,    -1,    -1,   409,   410,   535,   412,   413,
     414,   415,   416,    -1,    -1,    -1,    62,    63,    64,    65,
     424,    67,   754,    69,   756,    71,    72,    73,   774,    -1,
      -1,    77,    -1,    -1,    -1,    -1,   688,    -1,   690,   706,
       3,   693,   774,    -1,   696,    -1,    -1,   714,    -1,   465,
      -1,    14,    -1,    16,    -1,    18,    -1,    -1,    21,    22,
      23,    24,    -1,    26,    27,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    27,    61,    62,    38,    39,    40,    41,    67,
      68,    69,    70,     4,     5,   501,     7,   754,   504,   756,
      -1,    -1,    -1,   745,    -1,    -1,    -1,    -1,    19,    -1,
      21,    22,    90,    91,    -1,    68,    27,    62,    -1,    -1,
      65,    32,   528,   529,    69,    -1,    -1,    -1,    73,   535,
     772,    -1,    77,    -1,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   785,    -1,    -1,    -1,   125,   126,    -1,
     544,    62,    63,    64,    65,   797,    67,    -1,    69,    -1,
      71,    72,    73,    -1,    -1,    -1,    77,   145,    20,    -1,
      22,    -1,    -1,   151,    -1,    27,    -1,    -1,    -1,    -1,
      -1,    33,    -1,   161,   162,    -1,   667,    -1,   706,    -1,
      -1,     4,     5,    -1,     7,    -1,   714,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,   613,    21,    22,
      62,    -1,    -1,    65,    27,    -1,    -1,    69,   196,    32,
      -1,    73,    -1,    -1,    -1,    77,    -1,   633,    -1,    -1,
      -1,    -1,    45,    21,    22,    -1,   754,   643,   756,    27,
      -1,   219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      63,    64,    65,    66,    67,    -1,    69,    45,    71,    72,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   667,    62,    63,    64,    65,   684,    67,
     686,    69,    -1,    71,    72,    73,    -1,    -1,    -1,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   703,    -1,    -1,
     706,   279,   280,   281,   282,   283,    -1,    17,   714,   287,
      -1,    -1,    -1,    -1,   292,    -1,   294,    27,    -1,    -1,
     298,   299,   300,   301,   302,   719,    -1,    -1,    38,    -1,
      -1,   309,   310,   311,    -1,    -1,    -1,    -1,    -1,    -1,
     318,   319,    -1,    -1,    -1,    -1,    -1,    -1,   754,    -1,
     756,    -1,    62,    63,    64,    65,    -1,    67,   336,    69,
      -1,    71,    72,    73,    -1,    -1,    -1,    77,   774,    -1,
     348,    -1,    -1,   351,   352,   353,   354,   355,    -1,   357,
     358,   359,    -1,    -1,    -1,   363,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   371,   372,   373,   374,    -1,    -1,    61,
      62,    -1,    -1,    -1,    -1,    67,    68,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    -1,   393,    -1,     4,     5,    -1,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    90,    91,
      17,    -1,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      27,    -1,    -1,    30,    31,    32,    33,   425,    35,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,
      -1,    -1,    -1,   125,   126,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    64,    65,    66,
      67,    68,    69,   145,    71,    72,    73,   465,    -1,   151,
      77,    -1,    17,    -1,    -1,    -1,    21,    22,    -1,   161,
     162,    -1,    27,    -1,    -1,    30,    31,    -1,    -1,    -1,
      35,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    -1,    -1,   501,    -1,    -1,   504,    -1,    -1,    -1,
     508,   509,    -1,    -1,   196,    -1,    -1,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    71,    72,    73,    -1,
     528,   529,    77,    -1,    17,    -1,    -1,   535,    21,    22,
      -1,    -1,    -1,    -1,    27,    -1,    -1,    30,    31,    -1,
      -1,    -1,    -1,   551,   552,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    -1,    -1,    -1,    61,    62,    -1,    -1,
      -1,    -1,    67,    68,    -1,    70,    -1,    -1,    -1,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    71,    72,
      73,    -1,    -1,    17,    77,    90,    91,   279,   280,   281,
     282,    -1,    -1,    27,    -1,   287,    -1,    31,    -1,    -1,
     292,    35,   294,    -1,    38,   613,   298,   299,   300,   301,
     302,    -1,    -1,    -1,    -1,    -1,    -1,   309,   310,   311,
     125,   126,    -1,    -1,    -1,   633,   318,   319,    62,    63,
      64,    65,    -1,    67,    -1,    69,    -1,    71,    72,    73,
     145,    -1,    -1,    77,   336,    -1,   151,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   161,   162,    -1,   351,
     352,   353,   354,   355,    -1,   357,   358,   359,    -1,    -1,
      -1,   363,    -1,    -1,    -1,    -1,   684,    -1,   686,   371,
     372,   373,   374,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,   703,    -1,   705,   706,     4,
       5,    -1,     7,     8,     9,    10,   714,    -1,    -1,    -1,
      38,    -1,    17,   721,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    27,    -1,    -1,    -1,    31,    32,    33,    -1,
      -1,    -1,    -1,   425,    62,    63,    64,    65,    -1,    67,
      45,    69,    -1,    71,    72,    73,   754,    -1,   756,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,
      65,    66,    67,    -1,    69,    -1,    71,    72,    73,    -1,
      -1,    -1,    77,   465,   279,   280,   281,   282,    17,    -1,
      -1,    -1,   287,    22,    -1,    -1,    -1,   292,    27,   294,
      -1,    -1,    31,   298,   299,   300,   301,   302,    -1,    38,
      -1,    -1,    -1,    -1,   309,   310,   311,    -1,    -1,   501,
      -1,    -1,   504,   318,   319,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    63,    64,    65,    -1,    67,    -1,
      69,   336,    71,    72,    73,    -1,   528,   529,    77,    -1,
      -1,    -1,    -1,   535,    -1,    -1,   351,   352,   353,   354,
     355,    22,   357,   358,   359,    61,    62,    -1,   363,    -1,
      -1,    67,    68,    -1,    70,    -1,    -1,   372,   373,   374,
      -1,    42,    43,    44,    -1,    46,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    91,    -1,    -1,    -1,    -1,
      -1,    62,    63,    -1,    -1,    -1,    67,    -1,    69,    -1,
      71,    72,    73,    -1,    -1,    -1,    77,    -1,    -1,     4,
       5,    -1,     7,     8,     9,    10,    -1,    -1,    -1,   125,
     126,   613,    17,    -1,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    27,    -1,    -1,    -1,    31,    32,    33,   145,
      35,   633,    -1,    38,    -1,   151,    -1,    -1,    -1,    -1,
      45,    -1,    -1,    22,    -1,   161,   162,    -1,    -1,    -1,
     465,    -1,    -1,    -1,    -1,    -1,    35,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    71,    72,    73,    -1,
      49,    50,    77,    -1,    53,    54,    -1,    -1,    57,    -1,
     196,    60,   684,    62,   686,    -1,   501,    -1,    67,   504,
      69,    -1,    -1,    -1,    73,    17,    -1,    -1,    -1,    21,
      22,   703,    -1,    -1,   706,    27,    -1,    -1,    -1,    31,
      -1,    -1,   714,   528,   529,    -1,    38,    -1,    -1,    -1,
     535,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    62,    -1,    -1,    -1,    -1,    67,    68,
      62,    70,    64,    65,    66,    -1,    68,    69,    -1,    -1,
      -1,    73,   754,    -1,   756,    77,    -1,    -1,    -1,    -1,
      -1,    90,    91,   279,   280,   281,   282,    -1,    -1,    -1,
      -1,   287,    -1,    -1,    -1,    -1,   292,    -1,   294,    -1,
      -1,    -1,   298,   299,   300,   301,   302,    -1,    -1,    -1,
      -1,    -1,    -1,   309,   310,   311,   125,   126,   613,    -1,
      -1,    -1,   318,   319,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    -1,    -1,   145,    35,   633,    68,
     336,    70,   151,    -1,    42,    43,    44,    -1,    46,    47,
      -1,    -1,   161,   162,    -1,   351,   352,   353,   354,   355,
      -1,   357,   358,   359,    62,    63,    -1,   363,    -1,    67,
      -1,    69,    -1,    71,    72,    73,   372,   373,   374,    77,
      -1,    -1,    -1,    62,    63,    64,    65,    -1,    67,   684,
      69,   686,    71,    72,    73,    -1,   125,   126,    77,    -1,
      17,    -1,    -1,    -1,    21,    22,    -1,    -1,   703,    -1,
      27,   706,    -1,    30,    31,    -1,   145,    -1,    -1,   714,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,
      -1,    -1,   161,   162,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    64,    65,    66,
      67,    68,    69,    -1,    71,    72,    73,    -1,    -1,   754,
      77,   756,    -1,    -1,    -1,    -1,    17,   196,    -1,   465,
     279,   280,   281,   282,    -1,    -1,    27,    -1,   287,    -1,
      31,    -1,    -1,   292,    -1,   294,    -1,    38,    -1,   298,
     299,   300,   301,   302,    -1,    -1,    -1,    -1,    -1,    -1,
     309,   310,   311,    -1,    -1,   501,    -1,    -1,   504,   318,
     319,    62,    63,    64,    65,    -1,    67,    -1,    69,    -1,
      71,    72,    73,    -1,    -1,    -1,    77,   336,    -1,    -1,
      -1,    -1,   528,   529,    -1,    -1,    -1,    -1,    -1,   535,
      -1,    -1,   351,   352,   353,   354,   355,    -1,   357,   358,
     359,   280,    -1,   282,   363,    -1,    27,    -1,    -1,    -1,
      -1,    -1,    -1,   372,   373,   374,    -1,    38,    -1,    -1,
      -1,    -1,    -1,   302,    -1,    -1,    -1,    -1,    -1,    -1,
     309,   310,   311,    -1,    -1,    -1,    -1,    -1,    -1,   318,
     319,    62,    63,    64,    65,    -1,    67,    -1,    69,    -1,
      71,    72,    73,    -1,    -1,    -1,    77,   336,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   613,    -1,    -1,
      -1,    -1,   351,   352,   353,   354,   355,    27,   357,    -1,
      -1,    -1,    -1,    -1,   363,    -1,    -1,   633,    38,    -1,
      -1,    -1,    -1,   372,   373,   374,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   465,    -1,    -1,    -1,
      -1,    -1,    62,    63,    64,    65,    -1,    67,    -1,    69,
      -1,    71,    72,    73,    -1,    -1,    -1,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   684,    -1,
     686,    -1,    -1,    -1,    -1,   504,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   703,    -1,    -1,
     706,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   714,   528,
     529,    -1,    -1,    -1,    -1,    -1,   535,     3,     4,     5,
      -1,     7,     8,     9,    10,    -1,   465,    -1,    14,    -1,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      26,    27,    -1,    -1,    30,    31,    32,    33,   754,    -1,
     756,    -1,    38,    39,    40,    41,    -1,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    -1,   504,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    -1,   528,
     529,    77,    -1,    -1,   613,    -1,   535,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,   633,     7,     8,     9,    10,    -1,
      -1,    -1,    14,    -1,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    26,    27,    -1,    -1,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   684,    -1,   686,    -1,    -1,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    71,
      72,    73,    -1,    -1,    -1,    77,    -1,   706,    -1,    -1,
      -1,    -1,     3,     4,     5,   714,     7,     8,     9,    10,
      -1,    -1,    -1,    14,    -1,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    26,    27,    -1,    -1,    -1,
      31,    32,    33,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    -1,    -1,    -1,    45,   754,    -1,   756,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   684,    -1,    -1,    -1,    -1,
      -1,    62,    63,    64,    65,    66,    67,    68,    69,    -1,
      71,    72,    73,    -1,    -1,    -1,    77,   706,     4,     5,
      -1,     7,     8,     9,    10,   714,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    27,    -1,    -1,    -1,    31,    32,    33,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    -1,   754,    -1,   756,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    -1,     4,
       5,    77,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    -1,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    27,    -1,    -1,    -1,    31,    32,    33,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    71,    72,    73,    -1,
       4,     5,    77,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    -1,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,    33,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,
      64,    65,    66,    67,    68,    69,    17,    71,    72,    73,
      21,    22,    -1,    77,    -1,    -1,    27,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    35,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    63,    64,    65,    66,    67,    68,    69,    17,
      71,    72,    73,    21,    22,    -1,    77,    -1,    -1,    27,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    63,    64,    65,    66,    67,
      68,    69,    17,    71,    72,    73,    21,    22,    -1,    77,
      -1,    -1,    27,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    71,    72,    73,    -1,
      -1,    -1,    77
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,    79,   303,     0,    48,    51,    52,    55,    56,    58,
      59,    80,    81,    82,    84,    85,    86,    87,    88,   286,
      27,    27,    27,    27,    27,    27,    27,    62,    67,    69,
      73,   297,   298,   297,   298,   302,   297,   297,   297,   297,
      13,    13,    13,   287,   303,    13,    13,    13,    13,    69,
      90,    90,    22,    37,   288,    36,    90,    90,    90,    90,
      28,    13,    13,   289,   297,    13,    30,    13,    13,    13,
      13,    22,    42,    43,    44,    46,    47,    63,    67,    71,
      72,    77,   265,   291,   292,   293,   294,   295,   298,   301,
      27,    38,    63,    64,    65,   210,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   227,   228,   232,
     233,   234,   257,   258,   259,   260,   261,   262,   264,   265,
     298,   299,   300,   301,    17,    22,    27,    31,    38,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   215,   229,   230,   242,   245,    35,    13,   290,   297,
      17,    27,   172,   199,   200,   201,   232,   253,   257,   261,
      21,    22,    27,    45,    66,    68,   136,   137,   138,   139,
     140,   141,   142,   143,   145,   146,   147,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   167,   169,   170,
     172,   184,   185,   186,   191,   198,   240,   241,   242,   245,
     253,   257,   258,   259,   260,   261,   262,   264,   265,     4,
       5,     7,     8,     9,    10,    19,    20,    21,    22,    27,
      32,    33,    45,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   101,   102,   103,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   121,   123,   125,   127,   129,
     130,   131,   132,   133,   134,   135,   187,   198,   235,   236,
     237,   238,   241,   245,   253,   257,   258,   259,   260,   261,
     262,   263,   264,   265,    83,   202,    35,   291,   296,    27,
      27,    27,    27,    27,    11,    27,   232,    27,   215,   227,
      14,    18,   254,   255,   256,    13,    89,   303,    41,    27,
      27,    27,    27,    35,   203,   231,   203,   229,    89,    41,
       3,     3,    16,    23,    24,    26,    39,    40,    41,   243,
      29,   246,    22,   209,   211,   212,   289,    22,   172,    89,
      11,    30,   195,   196,   299,   300,    27,    30,    35,   137,
     168,   170,   171,   257,   261,   264,    30,   137,    27,    30,
      89,    41,     3,     3,    41,   243,    15,   248,   254,   256,
     246,     6,    22,    27,   144,   145,   152,   154,   265,    22,
      25,   239,    27,    27,    27,   195,    27,    35,    92,   124,
     257,   261,     3,    41,    92,   122,   125,   236,   243,   244,
     253,   255,   256,    27,    89,    41,     3,     6,     3,     6,
      41,   243,    99,   101,   106,   109,   113,   123,   248,   254,
     256,   246,    37,    61,    70,    37,    70,    22,    27,   100,
     101,   107,   109,   265,    11,   239,    89,    13,    35,   232,
     202,   221,   224,   225,   227,   136,    91,   291,   296,    36,
     215,   227,   227,    22,    49,    50,    53,    54,    57,    60,
     266,   268,   269,   271,   273,   274,   276,   278,   297,    36,
     234,   226,   227,   226,   226,    13,    35,    36,    36,    36,
     211,   211,   211,   211,   211,   230,   214,   265,   148,   149,
     150,   265,    36,    36,    22,    27,   173,   174,   175,   177,
     178,   180,   182,   238,   249,   250,   251,   265,   298,   299,
      34,    27,    34,    35,    13,    35,    36,    36,    22,    27,
     161,   172,   257,   261,    61,    36,   143,   145,   151,   154,
     158,   170,   143,   143,   143,   143,   168,    21,    22,    27,
     154,   169,   265,   169,   170,    27,   137,   148,   252,   253,
     259,   171,   171,   171,    27,    34,    13,    35,    36,    36,
      36,    22,    27,   116,   125,    36,    99,    99,    99,    99,
      99,    99,    99,    92,    21,    22,    27,   109,   121,   265,
     121,   123,    27,   101,   127,   127,   130,   127,   127,   127,
     104,   105,   265,    92,    98,    99,   101,   126,   127,   128,
     130,   252,    36,   296,    36,    36,    36,    36,    36,    36,
      36,   266,   267,    27,    27,    27,    27,    27,    13,   284,
     303,    30,    36,    13,    36,    36,   231,    30,    35,    13,
      35,    13,    11,    30,   173,   183,   174,   177,   178,   181,
      61,    22,    27,    66,   154,   185,   192,   193,   194,   197,
     171,   162,   172,    13,    30,   137,   171,    36,    35,    36,
      36,    36,    27,   109,   134,   188,   189,   190,   197,   124,
     117,   125,    13,    30,    92,    35,    13,    11,    36,    30,
      13,    35,   279,   298,   302,   270,   298,   272,   298,   277,
     298,   285,   295,   226,    11,   214,    11,   148,    27,   178,
      13,    35,    36,    37,    36,    36,    37,   178,   148,   178,
     179,   169,    36,    13,    35,    13,    22,   155,   163,   164,
     165,   170,    36,    36,    11,    21,    27,   236,    36,    13,
      35,    13,    22,    92,   118,   119,    36,    11,   104,   126,
     267,    13,    13,   275,   303,    13,    13,   284,   211,   200,
     178,   183,   178,   178,    35,    13,    36,    34,   192,   162,
     155,   164,   166,   170,    13,    12,   247,   143,    34,   188,
     117,    92,   119,   120,   247,    13,   285,   297,    36,   285,
     285,    36,    11,   179,    13,    35,   168,   168,    13,    35,
      92,    92,    13,    13,    13,    27,   175,   176,   178,   166,
      36,   120,    36,    22,   280,   280,   280,    27,   180,    35,
     266,   281,   282,    36,    36,    36,   177,    36,    11,   283,
     303,    35,    13,   291,   281
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
     245,   246,   247,   248,   249,   250,   251,   252,   252,   253,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   263,   263,   263,   263,   264,   264,   265,   266,   266,
     266,   266,   266,   267,   267,   268,   268,   269,   270,   271,
     272,   273,   273,   273,   274,   275,   275,   276,   277,   278,
     279,   280,   280,   281,   281,   282,   283,   283,   284,   284,
     285,   286,   287,   287,   287,   288,   288,   289,   289,   290,
     291,   291,   291,   292,   292,   292,   292,   292,   292,   293,
     294,   294,   294,   294,   294,   295,   295,   296,   296,   297,
     297,   298,   298,   298,   299,   300,   301,   301,   301,   302,
     303
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
       1,     1,     3,     1,     3,     1,     1,     8,     1,     8,
       1,     1,     1,     1,     5,     2,     1,     5,     1,     8,
       1,     2,     3,     1,     3,     2,     2,     1,     2,     1,
       1,     6,     1,     2,     4,     3,     1,     1,     3,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     4,     2,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0
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
#line 2891 "y.tab.c"
    break;

  case 3: /* TPTP_file: TPTP_file TPTP_input  */
#line 232 "SyntaxBNF.y"
                                           {}
#line 2897 "y.tab.c"
    break;

  case 4: /* TPTP_input: annotated_formula  */
#line 235 "SyntaxBNF.y"
                               {P_PRINT((yyval.pval));}
#line 2903 "y.tab.c"
    break;

  case 5: /* TPTP_input: include  */
#line 236 "SyntaxBNF.y"
                              {P_PRINT((yyval.pval));}
#line 2909 "y.tab.c"
    break;

  case 6: /* annotated_formula: thf_annotated  */
#line 239 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2915 "y.tab.c"
    break;

  case 7: /* annotated_formula: tff_annotated  */
#line 240 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2921 "y.tab.c"
    break;

  case 8: /* annotated_formula: tcf_annotated  */
#line 241 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2927 "y.tab.c"
    break;

  case 9: /* annotated_formula: fof_annotated  */
#line 242 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2933 "y.tab.c"
    break;

  case 10: /* annotated_formula: cnf_annotated  */
#line 243 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2939 "y.tab.c"
    break;

  case 11: /* annotated_formula: tpi_annotated  */
#line 244 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2945 "y.tab.c"
    break;

  case 12: /* tpi_annotated: _LIT_tpi LPAREN name COMMA formula_role COMMA tpi_formula annotations RPAREN PERIOD  */
#line 247 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("tpi_annotated", P_TOKEN("_LIT_tpi ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 2951 "y.tab.c"
    break;

  case 13: /* tpi_formula: fof_formula  */
#line 250 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("tpi_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2957 "y.tab.c"
    break;

  case 14: /* thf_annotated: _LIT_thf LPAREN name COMMA formula_role COMMA thf_formula annotations RPAREN PERIOD  */
#line 253 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("thf_annotated", P_TOKEN("_LIT_thf ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 2963 "y.tab.c"
    break;

  case 15: /* tff_annotated: _LIT_tff LPAREN name COMMA formula_role COMMA tff_formula annotations RPAREN PERIOD  */
#line 256 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("tff_annotated", P_TOKEN("_LIT_tff ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 2969 "y.tab.c"
    break;

  case 16: /* tcf_annotated: _LIT_tcf LPAREN name COMMA formula_role COMMA tcf_formula annotations RPAREN PERIOD  */
#line 259 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("tcf_annotated", P_TOKEN("_LIT_tcf ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 2975 "y.tab.c"
    break;

  case 17: /* fof_annotated: _LIT_fof LPAREN name COMMA formula_role COMMA fof_formula annotations RPAREN PERIOD  */
#line 262 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("fof_annotated", P_TOKEN("_LIT_fof ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 2981 "y.tab.c"
    break;

  case 18: /* cnf_annotated: _LIT_cnf LPAREN name COMMA formula_role COMMA cnf_formula annotations RPAREN PERIOD  */
#line 265 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("cnf_annotated", P_TOKEN("_LIT_cnf ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 2987 "y.tab.c"
    break;

  case 19: /* annotations: COMMA source optional_info  */
#line 268 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("annotations", P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2993 "y.tab.c"
    break;

  case 20: /* annotations: nothing  */
#line 269 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("annotations", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2999 "y.tab.c"
    break;

  case 21: /* formula_role: lower_word  */
#line 272 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("formula_role", P_TOKEN("lower_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3005 "y.tab.c"
    break;

  case 22: /* formula_role: lower_word MINUS general_term  */
#line 273 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("formula_role", P_TOKEN("lower_word ", (yyvsp[-2].ival)), P_TOKEN("MINUS ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3011 "y.tab.c"
    break;

  case 23: /* thf_formula: thf_logic_formula  */
#line 276 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3017 "y.tab.c"
    break;

  case 24: /* thf_formula: thf_atom_typing  */
#line 277 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3023 "y.tab.c"
    break;

  case 25: /* thf_formula: thf_subtype  */
#line 278 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("thf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3029 "y.tab.c"
    break;

  case 26: /* thf_logic_formula: thf_unitary_formula  */
#line 281 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3035 "y.tab.c"
    break;

  case 27: /* thf_logic_formula: thf_unary_formula  */
#line 282 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3041 "y.tab.c"
    break;

  case 28: /* thf_logic_formula: thf_binary_formula  */
#line 283 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3047 "y.tab.c"
    break;

  case 29: /* thf_logic_formula: thf_defined_infix  */
#line 284 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3053 "y.tab.c"
    break;

  case 30: /* thf_logic_formula: thf_definition  */
#line 285 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3059 "y.tab.c"
    break;

  case 31: /* thf_logic_formula: thf_sequent  */
#line 286 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3065 "y.tab.c"
    break;

  case 32: /* thf_binary_formula: thf_binary_nonassoc  */
#line 289 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3071 "y.tab.c"
    break;

  case 33: /* thf_binary_formula: thf_binary_assoc  */
#line 290 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3077 "y.tab.c"
    break;

  case 34: /* thf_binary_formula: thf_binary_type  */
#line 291 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3083 "y.tab.c"
    break;

  case 35: /* thf_binary_nonassoc: thf_unit_formula nonassoc_connective thf_unit_formula  */
#line 294 "SyntaxBNF.y"
                                                                            {(yyval.pval) = P_BUILD("thf_binary_nonassoc", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3089 "y.tab.c"
    break;

  case 36: /* thf_binary_assoc: thf_or_formula  */
#line 297 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("thf_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3095 "y.tab.c"
    break;

  case 37: /* thf_binary_assoc: thf_and_formula  */
#line 298 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3101 "y.tab.c"
    break;

  case 38: /* thf_binary_assoc: thf_apply_formula  */
#line 299 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3107 "y.tab.c"
    break;

  case 39: /* thf_or_formula: thf_unit_formula VLINE thf_unit_formula  */
#line 302 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("thf_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3113 "y.tab.c"
    break;

  case 40: /* thf_or_formula: thf_or_formula VLINE thf_unit_formula  */
#line 303 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("thf_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3119 "y.tab.c"
    break;

  case 41: /* thf_and_formula: thf_unit_formula AMPERSAND thf_unit_formula  */
#line 306 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3125 "y.tab.c"
    break;

  case 42: /* thf_and_formula: thf_and_formula AMPERSAND thf_unit_formula  */
#line 307 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3131 "y.tab.c"
    break;

  case 43: /* thf_apply_formula: thf_unit_formula AT_SIGN thf_unit_formula  */
#line 310 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_apply_formula", (yyvsp[-2].pval), P_TOKEN("AT_SIGN ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3137 "y.tab.c"
    break;

  case 44: /* thf_apply_formula: thf_apply_formula AT_SIGN thf_unit_formula  */
#line 311 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_apply_formula", (yyvsp[-2].pval), P_TOKEN("AT_SIGN ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3143 "y.tab.c"
    break;

  case 45: /* thf_unit_formula: thf_unitary_formula  */
#line 314 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3149 "y.tab.c"
    break;

  case 46: /* thf_unit_formula: thf_unary_formula  */
#line 315 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3155 "y.tab.c"
    break;

  case 47: /* thf_unit_formula: thf_defined_infix  */
#line 316 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3161 "y.tab.c"
    break;

  case 48: /* thf_preunit_formula: thf_unitary_formula  */
#line 319 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("thf_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3167 "y.tab.c"
    break;

  case 49: /* thf_preunit_formula: thf_prefix_unary  */
#line 320 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3173 "y.tab.c"
    break;

  case 50: /* thf_unitary_formula: thf_quantified_formula  */
#line 323 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("thf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3179 "y.tab.c"
    break;

  case 51: /* thf_unitary_formula: thf_atomic_formula  */
#line 324 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3185 "y.tab.c"
    break;

  case 52: /* thf_unitary_formula: variable  */
#line 325 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("thf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3191 "y.tab.c"
    break;

  case 53: /* thf_unitary_formula: LPAREN thf_logic_formula RPAREN  */
#line 326 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("thf_unitary_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3197 "y.tab.c"
    break;

  case 54: /* thf_quantified_formula: thf_quantification thf_unit_formula  */
#line 329 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("thf_quantified_formula", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3203 "y.tab.c"
    break;

  case 55: /* thf_quantification: thf_quantifier LBRKT thf_variable_list RBRKT COLON  */
#line 332 "SyntaxBNF.y"
                                                                        {(yyval.pval) = P_BUILD("thf_quantification", (yyvsp[-4].pval), P_TOKEN("LBRKT ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("RBRKT ", (yyvsp[-1].ival)), P_TOKEN("COLON ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL);}
#line 3209 "y.tab.c"
    break;

  case 56: /* thf_variable_list: thf_typed_variable  */
#line 335 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_variable_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3215 "y.tab.c"
    break;

  case 57: /* thf_variable_list: thf_typed_variable COMMA thf_variable_list  */
#line 336 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_variable_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3221 "y.tab.c"
    break;

  case 58: /* thf_typed_variable: variable COLON thf_top_level_type  */
#line 339 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("thf_typed_variable", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3227 "y.tab.c"
    break;

  case 59: /* thf_unary_formula: thf_prefix_unary  */
#line 342 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3233 "y.tab.c"
    break;

  case 60: /* thf_unary_formula: thf_infix_unary  */
#line 343 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3239 "y.tab.c"
    break;

  case 61: /* thf_prefix_unary: thf_unary_connective thf_preunit_formula  */
#line 346 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("thf_prefix_unary", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3245 "y.tab.c"
    break;

  case 62: /* thf_infix_unary: thf_unitary_term infix_inequality thf_unitary_term  */
#line 349 "SyntaxBNF.y"
                                                                     {(yyval.pval) = P_BUILD("thf_infix_unary", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3251 "y.tab.c"
    break;

  case 63: /* thf_atomic_formula: thf_plain_atomic  */
#line 352 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3257 "y.tab.c"
    break;

  case 64: /* thf_atomic_formula: thf_defined_atomic  */
#line 353 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3263 "y.tab.c"
    break;

  case 65: /* thf_atomic_formula: thf_system_atomic  */
#line 354 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3269 "y.tab.c"
    break;

  case 66: /* thf_plain_atomic: constant  */
#line 357 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("thf_plain_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3275 "y.tab.c"
    break;

  case 67: /* thf_plain_atomic: thf_tuple  */
#line 358 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_plain_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3281 "y.tab.c"
    break;

  case 68: /* thf_defined_atomic: defined_constant  */
#line 361 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3287 "y.tab.c"
    break;

  case 69: /* thf_defined_atomic: thf_defined_term  */
#line 362 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3293 "y.tab.c"
    break;

  case 70: /* thf_defined_atomic: LPAREN thf_conn_term RPAREN  */
#line 363 "SyntaxBNF.y"
                                                  {(yyval.pval) = P_BUILD("thf_defined_atomic", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3299 "y.tab.c"
    break;

  case 71: /* thf_defined_atomic: nhf_long_connective  */
#line 364 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3305 "y.tab.c"
    break;

  case 72: /* thf_defined_atomic: thf_let  */
#line 365 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3311 "y.tab.c"
    break;

  case 73: /* thf_defined_term: defined_term  */
#line 368 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3317 "y.tab.c"
    break;

  case 74: /* thf_defined_term: th1_defined_term  */
#line 369 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3323 "y.tab.c"
    break;

  case 75: /* thf_defined_infix: thf_unitary_term defined_infix_pred thf_unitary_term  */
#line 372 "SyntaxBNF.y"
                                                                         {(yyval.pval) = P_BUILD("thf_defined_infix", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3329 "y.tab.c"
    break;

  case 76: /* thf_system_atomic: system_constant  */
#line 375 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("thf_system_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3335 "y.tab.c"
    break;

  case 77: /* thf_let: _DLR_let LPAREN thf_let_types COMMA thf_let_defns COMMA thf_logic_formula RPAREN  */
#line 378 "SyntaxBNF.y"
                                                                                           {(yyval.pval) = P_BUILD("thf_let", P_TOKEN("_DLR_let ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 3341 "y.tab.c"
    break;

  case 78: /* thf_let_types: thf_atom_typing  */
#line 381 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_let_types", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3347 "y.tab.c"
    break;

  case 79: /* thf_let_types: LBRKT thf_atom_typing_list RBRKT  */
#line 382 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("thf_let_types", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3353 "y.tab.c"
    break;

  case 80: /* thf_atom_typing_list: thf_atom_typing  */
#line 385 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_atom_typing_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3359 "y.tab.c"
    break;

  case 81: /* thf_atom_typing_list: thf_atom_typing COMMA thf_atom_typing_list  */
#line 386 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_atom_typing_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3365 "y.tab.c"
    break;

  case 82: /* thf_let_defns: thf_let_defn  */
#line 389 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("thf_let_defns", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3371 "y.tab.c"
    break;

  case 83: /* thf_let_defns: LBRKT thf_let_defn_list RBRKT  */
#line 390 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("thf_let_defns", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3377 "y.tab.c"
    break;

  case 84: /* thf_let_defn: thf_logic_formula assignment thf_logic_formula  */
#line 393 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_let_defn", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3383 "y.tab.c"
    break;

  case 85: /* thf_let_defn_list: thf_let_defn  */
#line 396 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("thf_let_defn_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3389 "y.tab.c"
    break;

  case 86: /* thf_let_defn_list: thf_let_defn COMMA thf_let_defn_list  */
#line 397 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_let_defn_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3395 "y.tab.c"
    break;

  case 87: /* thf_unitary_term: thf_atomic_formula  */
#line 400 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3401 "y.tab.c"
    break;

  case 88: /* thf_unitary_term: variable  */
#line 401 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("thf_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3407 "y.tab.c"
    break;

  case 89: /* thf_unitary_term: LPAREN thf_logic_formula RPAREN  */
#line 402 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("thf_unitary_term", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3413 "y.tab.c"
    break;

  case 90: /* thf_conn_term: nonassoc_connective  */
#line 405 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3419 "y.tab.c"
    break;

  case 91: /* thf_conn_term: assoc_connective  */
#line 406 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3425 "y.tab.c"
    break;

  case 92: /* thf_conn_term: infix_equality  */
#line 407 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3431 "y.tab.c"
    break;

  case 93: /* thf_conn_term: infix_inequality  */
#line 408 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3437 "y.tab.c"
    break;

  case 94: /* thf_conn_term: thf_unary_connective  */
#line 409 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3443 "y.tab.c"
    break;

  case 95: /* thf_tuple: LBRKT RBRKT  */
#line 412 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("thf_tuple", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3449 "y.tab.c"
    break;

  case 96: /* thf_tuple: LBRKT thf_formula_list RBRKT  */
#line 413 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("thf_tuple", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3455 "y.tab.c"
    break;

  case 97: /* thf_formula_list: thf_logic_formula  */
#line 416 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_formula_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3461 "y.tab.c"
    break;

  case 98: /* thf_formula_list: thf_logic_formula COMMA thf_formula_list  */
#line 417 "SyntaxBNF.y"
                                                               {(yyval.pval) = P_BUILD("thf_formula_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3467 "y.tab.c"
    break;

  case 99: /* thf_atom_typing: untyped_atom COLON thf_top_level_type  */
#line 420 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("thf_atom_typing", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3473 "y.tab.c"
    break;

  case 100: /* thf_atom_typing: LPAREN thf_atom_typing RPAREN  */
#line 421 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("thf_atom_typing", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3479 "y.tab.c"
    break;

  case 101: /* thf_top_level_type: thf_unitary_type  */
#line 424 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3485 "y.tab.c"
    break;

  case 102: /* thf_top_level_type: thf_mapping_type  */
#line 425 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3491 "y.tab.c"
    break;

  case 103: /* thf_top_level_type: thf_apply_type  */
#line 426 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3497 "y.tab.c"
    break;

  case 104: /* thf_unitary_type: thf_unitary_formula  */
#line 429 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_unitary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3503 "y.tab.c"
    break;

  case 105: /* thf_apply_type: thf_apply_formula  */
#line 432 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("thf_apply_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3509 "y.tab.c"
    break;

  case 106: /* thf_binary_type: thf_mapping_type  */
#line 435 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("thf_binary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3515 "y.tab.c"
    break;

  case 107: /* thf_binary_type: thf_xprod_type  */
#line 436 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_binary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3521 "y.tab.c"
    break;

  case 108: /* thf_binary_type: thf_union_type  */
#line 437 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_binary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3527 "y.tab.c"
    break;

  case 109: /* thf_mapping_type: thf_unitary_type arrow thf_unitary_type  */
#line 440 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_mapping_type", (yyvsp[-2].pval), P_TOKEN("arrow ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3533 "y.tab.c"
    break;

  case 110: /* thf_mapping_type: thf_unitary_type arrow thf_mapping_type  */
#line 441 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_mapping_type", (yyvsp[-2].pval), P_TOKEN("arrow ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3539 "y.tab.c"
    break;

  case 111: /* thf_xprod_type: thf_unitary_type STAR thf_unitary_type  */
#line 444 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("thf_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3545 "y.tab.c"
    break;

  case 112: /* thf_xprod_type: thf_xprod_type STAR thf_unitary_type  */
#line 445 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3551 "y.tab.c"
    break;

  case 113: /* thf_union_type: thf_unitary_type plus thf_unitary_type  */
#line 448 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("thf_union_type", (yyvsp[-2].pval), P_TOKEN("plus ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3557 "y.tab.c"
    break;

  case 114: /* thf_union_type: thf_union_type plus thf_unitary_type  */
#line 449 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_union_type", (yyvsp[-2].pval), P_TOKEN("plus ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3563 "y.tab.c"
    break;

  case 115: /* thf_subtype: untyped_atom subtype_sign atom  */
#line 452 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("thf_subtype", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3569 "y.tab.c"
    break;

  case 116: /* thf_definition: thf_atomic_formula identical thf_logic_formula  */
#line 455 "SyntaxBNF.y"
                                                                {(yyval.pval) = P_BUILD("thf_definition", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3575 "y.tab.c"
    break;

  case 117: /* thf_sequent: thf_tuple gentzen_arrow thf_tuple  */
#line 458 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("thf_sequent", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3581 "y.tab.c"
    break;

  case 118: /* tff_formula: tff_logic_formula  */
#line 461 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3587 "y.tab.c"
    break;

  case 119: /* tff_formula: tff_atom_typing  */
#line 462 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3593 "y.tab.c"
    break;

  case 120: /* tff_formula: tff_subtype  */
#line 463 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tff_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3599 "y.tab.c"
    break;

  case 121: /* tff_logic_formula: tff_unitary_formula  */
#line 466 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3605 "y.tab.c"
    break;

  case 122: /* tff_logic_formula: tff_unary_formula  */
#line 467 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3611 "y.tab.c"
    break;

  case 123: /* tff_logic_formula: tff_binary_formula  */
#line 468 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3617 "y.tab.c"
    break;

  case 124: /* tff_logic_formula: tff_defined_infix  */
#line 469 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3623 "y.tab.c"
    break;

  case 125: /* tff_logic_formula: txf_definition  */
#line 470 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3629 "y.tab.c"
    break;

  case 126: /* tff_logic_formula: txf_sequent  */
#line 471 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3635 "y.tab.c"
    break;

  case 127: /* tff_binary_formula: tff_binary_nonassoc  */
#line 474 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3641 "y.tab.c"
    break;

  case 128: /* tff_binary_formula: tff_binary_assoc  */
#line 475 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3647 "y.tab.c"
    break;

  case 129: /* tff_binary_nonassoc: tff_unit_formula nonassoc_connective tff_unit_formula  */
#line 478 "SyntaxBNF.y"
                                                                            {(yyval.pval) = P_BUILD("tff_binary_nonassoc", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3653 "y.tab.c"
    break;

  case 130: /* tff_binary_assoc: tff_or_formula  */
#line 481 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tff_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3659 "y.tab.c"
    break;

  case 131: /* tff_binary_assoc: tff_and_formula  */
#line 482 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3665 "y.tab.c"
    break;

  case 132: /* tff_or_formula: tff_unit_formula VLINE tff_unit_formula  */
#line 485 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("tff_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3671 "y.tab.c"
    break;

  case 133: /* tff_or_formula: tff_or_formula VLINE tff_unit_formula  */
#line 486 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("tff_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3677 "y.tab.c"
    break;

  case 134: /* tff_and_formula: tff_unit_formula AMPERSAND tff_unit_formula  */
#line 489 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("tff_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3683 "y.tab.c"
    break;

  case 135: /* tff_and_formula: tff_and_formula AMPERSAND tff_unit_formula  */
#line 490 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("tff_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3689 "y.tab.c"
    break;

  case 136: /* tff_unit_formula: tff_unitary_formula  */
#line 493 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3695 "y.tab.c"
    break;

  case 137: /* tff_unit_formula: tff_unary_formula  */
#line 494 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3701 "y.tab.c"
    break;

  case 138: /* tff_unit_formula: tff_defined_infix  */
#line 495 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3707 "y.tab.c"
    break;

  case 139: /* tff_preunit_formula: tff_unitary_formula  */
#line 498 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3713 "y.tab.c"
    break;

  case 140: /* tff_preunit_formula: tff_prefix_unary  */
#line 499 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3719 "y.tab.c"
    break;

  case 141: /* tff_unitary_formula: tff_quantified_formula  */
#line 502 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("tff_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3725 "y.tab.c"
    break;

  case 142: /* tff_unitary_formula: tff_atomic_formula  */
#line 503 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3731 "y.tab.c"
    break;

  case 143: /* tff_unitary_formula: txf_unitary_formula  */
#line 504 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3737 "y.tab.c"
    break;

  case 144: /* tff_unitary_formula: LPAREN tff_logic_formula RPAREN  */
#line 505 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("tff_unitary_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3743 "y.tab.c"
    break;

  case 145: /* txf_unitary_formula: variable  */
#line 508 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("txf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3749 "y.tab.c"
    break;

  case 146: /* tff_quantified_formula: tff_quantifier LBRKT tff_variable_list RBRKT COLON tff_unit_formula  */
#line 511 "SyntaxBNF.y"
                                                                                             {(yyval.pval) = P_BUILD("tff_quantified_formula", (yyvsp[-5].pval), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 3755 "y.tab.c"
    break;

  case 147: /* tff_variable_list: tff_variable  */
#line 514 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("tff_variable_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3761 "y.tab.c"
    break;

  case 148: /* tff_variable_list: tff_variable COMMA tff_variable_list  */
#line 515 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("tff_variable_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3767 "y.tab.c"
    break;

  case 149: /* tff_variable: tff_typed_variable  */
#line 518 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tff_variable", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3773 "y.tab.c"
    break;

  case 150: /* tff_variable: variable  */
#line 519 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_variable", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3779 "y.tab.c"
    break;

  case 151: /* tff_typed_variable: variable COLON tff_atomic_type  */
#line 522 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("tff_typed_variable", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3785 "y.tab.c"
    break;

  case 152: /* tff_unary_formula: tff_prefix_unary  */
#line 525 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3791 "y.tab.c"
    break;

  case 153: /* tff_unary_formula: tff_infix_unary  */
#line 526 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3797 "y.tab.c"
    break;

  case 154: /* tff_prefix_unary: tff_unary_connective tff_preunit_formula  */
#line 529 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("tff_prefix_unary", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3803 "y.tab.c"
    break;

  case 155: /* tff_infix_unary: tff_unitary_term infix_inequality tff_unitary_term  */
#line 532 "SyntaxBNF.y"
                                                                     {(yyval.pval) = P_BUILD("tff_infix_unary", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3809 "y.tab.c"
    break;

  case 156: /* tff_atomic_formula: tff_plain_atomic  */
#line 535 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3815 "y.tab.c"
    break;

  case 157: /* tff_atomic_formula: tff_defined_atomic  */
#line 536 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3821 "y.tab.c"
    break;

  case 158: /* tff_atomic_formula: tff_system_atomic  */
#line 537 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3827 "y.tab.c"
    break;

  case 159: /* tff_plain_atomic: constant  */
#line 540 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("tff_plain_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3833 "y.tab.c"
    break;

  case 160: /* tff_plain_atomic: functor LPAREN tff_arguments RPAREN  */
#line 541 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("tff_plain_atomic", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3839 "y.tab.c"
    break;

  case 161: /* tff_defined_atomic: tff_defined_plain  */
#line 544 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3845 "y.tab.c"
    break;

  case 162: /* tff_defined_plain: defined_constant  */
#line 547 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3851 "y.tab.c"
    break;

  case 163: /* tff_defined_plain: defined_functor LPAREN tff_arguments RPAREN  */
#line 548 "SyntaxBNF.y"
                                                                  {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3857 "y.tab.c"
    break;

  case 164: /* tff_defined_plain: nxf_atom  */
#line 549 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3863 "y.tab.c"
    break;

  case 165: /* tff_defined_plain: txf_let  */
#line 550 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3869 "y.tab.c"
    break;

  case 166: /* tff_defined_infix: tff_unitary_term defined_infix_pred tff_unitary_term  */
#line 553 "SyntaxBNF.y"
                                                                         {(yyval.pval) = P_BUILD("tff_defined_infix", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3875 "y.tab.c"
    break;

  case 167: /* tff_system_atomic: system_constant  */
#line 556 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("tff_system_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3881 "y.tab.c"
    break;

  case 168: /* tff_system_atomic: system_functor LPAREN tff_arguments RPAREN  */
#line 557 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("tff_system_atomic", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3887 "y.tab.c"
    break;

  case 169: /* txf_let: _DLR_let LPAREN txf_let_types COMMA txf_let_defns COMMA tff_term RPAREN  */
#line 560 "SyntaxBNF.y"
                                                                                  {(yyval.pval) = P_BUILD("txf_let", P_TOKEN("_DLR_let ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 3893 "y.tab.c"
    break;

  case 170: /* txf_let_types: tff_atom_typing  */
#line 563 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("txf_let_types", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3899 "y.tab.c"
    break;

  case 171: /* txf_let_types: LBRKT tff_atom_typing_list RBRKT  */
#line 564 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("txf_let_types", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3905 "y.tab.c"
    break;

  case 172: /* tff_atom_typing_list: tff_atom_typing  */
#line 567 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_atom_typing_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3911 "y.tab.c"
    break;

  case 173: /* tff_atom_typing_list: tff_atom_typing COMMA tff_atom_typing_list  */
#line 568 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("tff_atom_typing_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3917 "y.tab.c"
    break;

  case 174: /* txf_let_defns: txf_let_defn  */
#line 571 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("txf_let_defns", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3923 "y.tab.c"
    break;

  case 175: /* txf_let_defns: LBRKT txf_let_defn_list RBRKT  */
#line 572 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("txf_let_defns", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3929 "y.tab.c"
    break;

  case 176: /* txf_let_defn: txf_let_LHS assignment tff_term  */
#line 575 "SyntaxBNF.y"
                                               {(yyval.pval) = P_BUILD("txf_let_defn", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3935 "y.tab.c"
    break;

  case 177: /* txf_let_LHS: tff_plain_atomic  */
#line 578 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("txf_let_LHS", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3941 "y.tab.c"
    break;

  case 178: /* txf_let_LHS: txf_tuple  */
#line 579 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("txf_let_LHS", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3947 "y.tab.c"
    break;

  case 179: /* txf_let_defn_list: txf_let_defn  */
#line 582 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("txf_let_defn_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3953 "y.tab.c"
    break;

  case 180: /* txf_let_defn_list: txf_let_defn COMMA txf_let_defn_list  */
#line 583 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("txf_let_defn_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3959 "y.tab.c"
    break;

  case 181: /* nxf_atom: nxf_long_connective AT_SIGN LPAREN tff_arguments RPAREN  */
#line 586 "SyntaxBNF.y"
                                                                   {(yyval.pval) = P_BUILD("nxf_atom", (yyvsp[-4].pval), P_TOKEN("AT_SIGN ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL);}
#line 3965 "y.tab.c"
    break;

  case 182: /* tff_term: tff_logic_formula  */
#line 589 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("tff_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3971 "y.tab.c"
    break;

  case 183: /* tff_term: defined_term  */
#line 590 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3977 "y.tab.c"
    break;

  case 184: /* tff_term: txf_tuple  */
#line 591 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3983 "y.tab.c"
    break;

  case 185: /* tff_unitary_term: tff_atomic_formula  */
#line 594 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3989 "y.tab.c"
    break;

  case 186: /* tff_unitary_term: defined_term  */
#line 595 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3995 "y.tab.c"
    break;

  case 187: /* tff_unitary_term: txf_tuple  */
#line 596 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4001 "y.tab.c"
    break;

  case 188: /* tff_unitary_term: variable  */
#line 597 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4007 "y.tab.c"
    break;

  case 189: /* tff_unitary_term: LPAREN tff_logic_formula RPAREN  */
#line 598 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("tff_unitary_term", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4013 "y.tab.c"
    break;

  case 190: /* txf_tuple: LBRKT RBRKT  */
#line 601 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("txf_tuple", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4019 "y.tab.c"
    break;

  case 191: /* txf_tuple: LBRKT tff_arguments RBRKT  */
#line 602 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("txf_tuple", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4025 "y.tab.c"
    break;

  case 192: /* tff_arguments: tff_term  */
#line 605 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_arguments", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4031 "y.tab.c"
    break;

  case 193: /* tff_arguments: tff_term COMMA tff_arguments  */
#line 606 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("tff_arguments", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4037 "y.tab.c"
    break;

  case 194: /* tff_atom_typing: untyped_atom COLON tff_top_level_type  */
#line 609 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("tff_atom_typing", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4043 "y.tab.c"
    break;

  case 195: /* tff_atom_typing: LPAREN tff_atom_typing RPAREN  */
#line 610 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("tff_atom_typing", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4049 "y.tab.c"
    break;

  case 196: /* tff_top_level_type: tff_atomic_type  */
#line 613 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4055 "y.tab.c"
    break;

  case 197: /* tff_top_level_type: tff_non_atomic_type  */
#line 614 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4061 "y.tab.c"
    break;

  case 198: /* tff_non_atomic_type: tff_mapping_type  */
#line 617 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_non_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4067 "y.tab.c"
    break;

  case 199: /* tff_non_atomic_type: tf1_quantified_type  */
#line 618 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_non_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4073 "y.tab.c"
    break;

  case 200: /* tff_non_atomic_type: LPAREN tff_non_atomic_type RPAREN  */
#line 619 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("tff_non_atomic_type", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4079 "y.tab.c"
    break;

  case 201: /* tf1_quantified_type: type_quantifier LBRKT tff_variable_list RBRKT COLON tff_monotype  */
#line 622 "SyntaxBNF.y"
                                                                                       {(yyval.pval) = P_BUILD("tf1_quantified_type", (yyvsp[-5].pval), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 4085 "y.tab.c"
    break;

  case 202: /* tff_monotype: tff_atomic_type  */
#line 625 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_monotype", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4091 "y.tab.c"
    break;

  case 203: /* tff_monotype: LPAREN tff_mapping_type RPAREN  */
#line 626 "SyntaxBNF.y"
                                                     {(yyval.pval) = P_BUILD("tff_monotype", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4097 "y.tab.c"
    break;

  case 204: /* tff_monotype: tf1_quantified_type  */
#line 627 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_monotype", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4103 "y.tab.c"
    break;

  case 205: /* tff_unitary_type: tff_atomic_type  */
#line 630 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_unitary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4109 "y.tab.c"
    break;

  case 206: /* tff_unitary_type: LPAREN tff_xprod_type RPAREN  */
#line 631 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("tff_unitary_type", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4115 "y.tab.c"
    break;

  case 207: /* tff_atomic_type: type_constant  */
#line 634 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4121 "y.tab.c"
    break;

  case 208: /* tff_atomic_type: defined_type  */
#line 635 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4127 "y.tab.c"
    break;

  case 209: /* tff_atomic_type: variable  */
#line 636 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4133 "y.tab.c"
    break;

  case 210: /* tff_atomic_type: type_functor LPAREN tff_type_arguments RPAREN  */
#line 637 "SyntaxBNF.y"
                                                                    {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4139 "y.tab.c"
    break;

  case 211: /* tff_atomic_type: LPAREN tff_atomic_type RPAREN  */
#line 638 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("tff_atomic_type", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4145 "y.tab.c"
    break;

  case 212: /* tff_atomic_type: txf_tuple_type  */
#line 639 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4151 "y.tab.c"
    break;

  case 213: /* tff_type_arguments: tff_atomic_type  */
#line 642 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_type_arguments", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4157 "y.tab.c"
    break;

  case 214: /* tff_type_arguments: tff_atomic_type COMMA tff_type_arguments  */
#line 643 "SyntaxBNF.y"
                                                               {(yyval.pval) = P_BUILD("tff_type_arguments", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4163 "y.tab.c"
    break;

  case 215: /* tff_mapping_type: tff_unitary_type arrow tff_atomic_type  */
#line 646 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("tff_mapping_type", (yyvsp[-2].pval), P_TOKEN("arrow ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4169 "y.tab.c"
    break;

  case 216: /* tff_xprod_type: tff_unitary_type STAR tff_atomic_type  */
#line 649 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("tff_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4175 "y.tab.c"
    break;

  case 217: /* tff_xprod_type: tff_xprod_type STAR tff_atomic_type  */
#line 650 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("tff_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4181 "y.tab.c"
    break;

  case 218: /* txf_tuple_type: LBRKT tff_type_list RBRKT  */
#line 653 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("txf_tuple_type", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4187 "y.tab.c"
    break;

  case 219: /* tff_type_list: tff_top_level_type  */
#line 656 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_type_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4193 "y.tab.c"
    break;

  case 220: /* tff_type_list: tff_top_level_type COMMA tff_type_list  */
#line 657 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("tff_type_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4199 "y.tab.c"
    break;

  case 221: /* tff_subtype: untyped_atom subtype_sign atom  */
#line 660 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("tff_subtype", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4205 "y.tab.c"
    break;

  case 222: /* txf_definition: tff_atomic_formula identical tff_term  */
#line 663 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("txf_definition", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4211 "y.tab.c"
    break;

  case 223: /* txf_sequent: txf_tuple gentzen_arrow txf_tuple  */
#line 666 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("txf_sequent", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4217 "y.tab.c"
    break;

  case 224: /* nhf_long_connective: LBRACE ntf_connective_name RBRACE  */
#line 669 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("nhf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4223 "y.tab.c"
    break;

  case 225: /* nhf_long_connective: LBRACE ntf_connective_name LPAREN nhf_parameter_list RPAREN RBRACE  */
#line 670 "SyntaxBNF.y"
                                                                                         {(yyval.pval) = P_BUILD("nhf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-5].ival)), (yyvsp[-4].pval), P_TOKEN("LPAREN ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL);}
#line 4229 "y.tab.c"
    break;

  case 226: /* nhf_parameter_list: nhf_parameter  */
#line 673 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("nhf_parameter_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4235 "y.tab.c"
    break;

  case 227: /* nhf_parameter_list: nhf_parameter COMMA nhf_parameter_list  */
#line 674 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("nhf_parameter_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4241 "y.tab.c"
    break;

  case 228: /* nhf_parameter: ntf_index  */
#line 677 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("nhf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4247 "y.tab.c"
    break;

  case 229: /* nhf_parameter: nhf_key_pair  */
#line 678 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("nhf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4253 "y.tab.c"
    break;

  case 230: /* nhf_key_pair: thf_definition  */
#line 681 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("nhf_key_pair", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4259 "y.tab.c"
    break;

  case 231: /* nxf_long_connective: LBRACE ntf_connective_name RBRACE  */
#line 684 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("nxf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4265 "y.tab.c"
    break;

  case 232: /* nxf_long_connective: LBRACE ntf_connective_name LPAREN nxf_parameter_list RPAREN RBRACE  */
#line 685 "SyntaxBNF.y"
                                                                                         {(yyval.pval) = P_BUILD("nxf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-5].ival)), (yyvsp[-4].pval), P_TOKEN("LPAREN ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL);}
#line 4271 "y.tab.c"
    break;

  case 233: /* nxf_parameter_list: nxf_parameter  */
#line 688 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("nxf_parameter_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4277 "y.tab.c"
    break;

  case 234: /* nxf_parameter_list: nxf_parameter COMMA nxf_parameter_list  */
#line 689 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("nxf_parameter_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4283 "y.tab.c"
    break;

  case 235: /* nxf_parameter: ntf_index  */
#line 692 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("nxf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4289 "y.tab.c"
    break;

  case 236: /* nxf_parameter: nxf_key_pair  */
#line 693 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("nxf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4295 "y.tab.c"
    break;

  case 237: /* nxf_key_pair: txf_definition  */
#line 696 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("nxf_key_pair", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4301 "y.tab.c"
    break;

  case 238: /* ntf_connective_name: ntf_defined_connective  */
#line 699 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("ntf_connective_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4307 "y.tab.c"
    break;

  case 239: /* ntf_connective_name: atomic_system_word  */
#line 700 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("ntf_connective_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4313 "y.tab.c"
    break;

  case 240: /* ntf_defined_connective: atomic_defined_word  */
#line 703 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("ntf_defined_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4319 "y.tab.c"
    break;

  case 241: /* ntf_index: hash tff_unitary_term  */
#line 706 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("ntf_index", P_TOKEN("hash ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4325 "y.tab.c"
    break;

  case 242: /* ntf_short_connective: LBRKT PERIOD RBRKT  */
#line 709 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4331 "y.tab.c"
    break;

  case 243: /* ntf_short_connective: less_sign PERIOD arrow  */
#line 710 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("less_sign ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("arrow ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4337 "y.tab.c"
    break;

  case 244: /* ntf_short_connective: LBRACE PERIOD RBRACE  */
#line 711 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("LBRACE ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4343 "y.tab.c"
    break;

  case 245: /* ntf_short_connective: LPAREN PERIOD RPAREN  */
#line 712 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4349 "y.tab.c"
    break;

  case 246: /* tcf_formula: tcf_logic_formula  */
#line 715 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tcf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4355 "y.tab.c"
    break;

  case 247: /* tcf_formula: tff_atom_typing  */
#line 716 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tcf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4361 "y.tab.c"
    break;

  case 248: /* tcf_logic_formula: tcf_quantified_formula  */
#line 719 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("tcf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4367 "y.tab.c"
    break;

  case 249: /* tcf_logic_formula: cnf_formula  */
#line 720 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tcf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4373 "y.tab.c"
    break;

  case 250: /* tcf_quantified_formula: EXCLAMATION LBRKT tff_variable_list RBRKT COLON tcf_logic_formula  */
#line 723 "SyntaxBNF.y"
                                                                                           {(yyval.pval) = P_BUILD("tcf_quantified_formula", P_TOKEN("EXCLAMATION ", (yyvsp[-5].ival)), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 4379 "y.tab.c"
    break;

  case 251: /* fof_formula: fof_logic_formula  */
#line 726 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("fof_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4385 "y.tab.c"
    break;

  case 252: /* fof_formula: fof_sequent  */
#line 727 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("fof_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4391 "y.tab.c"
    break;

  case 253: /* fof_logic_formula: fof_binary_formula  */
#line 730 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("fof_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4397 "y.tab.c"
    break;

  case 254: /* fof_logic_formula: fof_unary_formula  */
#line 731 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("fof_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4403 "y.tab.c"
    break;

  case 255: /* fof_logic_formula: fof_unitary_formula  */
#line 732 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("fof_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4409 "y.tab.c"
    break;

  case 256: /* fof_binary_formula: fof_binary_nonassoc  */
#line 735 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("fof_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4415 "y.tab.c"
    break;

  case 257: /* fof_binary_formula: fof_binary_assoc  */
#line 736 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("fof_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4421 "y.tab.c"
    break;

  case 258: /* fof_binary_nonassoc: fof_unit_formula nonassoc_connective fof_unit_formula  */
#line 739 "SyntaxBNF.y"
                                                                            {(yyval.pval) = P_BUILD("fof_binary_nonassoc", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4427 "y.tab.c"
    break;

  case 259: /* fof_binary_assoc: fof_or_formula  */
#line 742 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("fof_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4433 "y.tab.c"
    break;

  case 260: /* fof_binary_assoc: fof_and_formula  */
#line 743 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("fof_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4439 "y.tab.c"
    break;

  case 261: /* fof_or_formula: fof_unit_formula VLINE fof_unit_formula  */
#line 746 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("fof_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4445 "y.tab.c"
    break;

  case 262: /* fof_or_formula: fof_or_formula VLINE fof_unit_formula  */
#line 747 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("fof_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4451 "y.tab.c"
    break;

  case 263: /* fof_and_formula: fof_unit_formula AMPERSAND fof_unit_formula  */
#line 750 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("fof_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4457 "y.tab.c"
    break;

  case 264: /* fof_and_formula: fof_and_formula AMPERSAND fof_unit_formula  */
#line 751 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("fof_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4463 "y.tab.c"
    break;

  case 265: /* fof_unary_formula: unary_connective fof_unit_formula  */
#line 754 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("fof_unary_formula", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4469 "y.tab.c"
    break;

  case 266: /* fof_unary_formula: fof_infix_unary  */
#line 755 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("fof_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4475 "y.tab.c"
    break;

  case 267: /* fof_infix_unary: fof_term infix_inequality fof_term  */
#line 758 "SyntaxBNF.y"
                                                     {(yyval.pval) = P_BUILD("fof_infix_unary", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4481 "y.tab.c"
    break;

  case 268: /* fof_unit_formula: fof_unitary_formula  */
#line 761 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("fof_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4487 "y.tab.c"
    break;

  case 269: /* fof_unit_formula: fof_unary_formula  */
#line 762 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("fof_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4493 "y.tab.c"
    break;

  case 270: /* fof_unitary_formula: fof_quantified_formula  */
#line 765 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("fof_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4499 "y.tab.c"
    break;

  case 271: /* fof_unitary_formula: fof_atomic_formula  */
#line 766 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("fof_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4505 "y.tab.c"
    break;

  case 272: /* fof_unitary_formula: LPAREN fof_logic_formula RPAREN  */
#line 767 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("fof_unitary_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4511 "y.tab.c"
    break;

  case 273: /* fof_quantified_formula: fof_quantifier LBRKT fof_variable_list RBRKT COLON fof_unit_formula  */
#line 770 "SyntaxBNF.y"
                                                                                             {(yyval.pval) = P_BUILD("fof_quantified_formula", (yyvsp[-5].pval), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 4517 "y.tab.c"
    break;

  case 274: /* fof_variable_list: variable  */
#line 773 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("fof_variable_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4523 "y.tab.c"
    break;

  case 275: /* fof_variable_list: variable COMMA fof_variable_list  */
#line 774 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("fof_variable_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4529 "y.tab.c"
    break;

  case 276: /* fof_atomic_formula: fof_plain_atomic_formula  */
#line 777 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("fof_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4535 "y.tab.c"
    break;

  case 277: /* fof_atomic_formula: fof_defined_atomic_formula  */
#line 778 "SyntaxBNF.y"
                                                 {(yyval.pval) = P_BUILD("fof_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4541 "y.tab.c"
    break;

  case 278: /* fof_atomic_formula: fof_system_atomic_formula  */
#line 779 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("fof_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4547 "y.tab.c"
    break;

  case 279: /* fof_plain_atomic_formula: fof_plain_term  */
#line 782 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("fof_plain_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4553 "y.tab.c"
    break;

  case 280: /* fof_defined_atomic_formula: fof_defined_plain_formula  */
#line 785 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("fof_defined_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4559 "y.tab.c"
    break;

  case 281: /* fof_defined_atomic_formula: fof_defined_infix_formula  */
#line 786 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("fof_defined_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4565 "y.tab.c"
    break;

  case 282: /* fof_defined_plain_formula: fof_defined_plain_term  */
#line 789 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("fof_defined_plain_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4571 "y.tab.c"
    break;

  case 283: /* fof_defined_infix_formula: fof_term defined_infix_pred fof_term  */
#line 792 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("fof_defined_infix_formula", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4577 "y.tab.c"
    break;

  case 284: /* fof_system_atomic_formula: fof_system_term  */
#line 795 "SyntaxBNF.y"
                                            {(yyval.pval) = P_BUILD("fof_system_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4583 "y.tab.c"
    break;

  case 285: /* fof_plain_term: constant  */
#line 798 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("fof_plain_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4589 "y.tab.c"
    break;

  case 286: /* fof_plain_term: functor LPAREN fof_arguments RPAREN  */
#line 799 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("fof_plain_term", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4595 "y.tab.c"
    break;

  case 287: /* fof_defined_term: defined_term  */
#line 802 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("fof_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4601 "y.tab.c"
    break;

  case 288: /* fof_defined_term: fof_defined_atomic_term  */
#line 803 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("fof_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4607 "y.tab.c"
    break;

  case 289: /* fof_defined_atomic_term: fof_defined_plain_term  */
#line 806 "SyntaxBNF.y"
                                                 {(yyval.pval) = P_BUILD("fof_defined_atomic_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4613 "y.tab.c"
    break;

  case 290: /* fof_defined_plain_term: defined_constant  */
#line 809 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("fof_defined_plain_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4619 "y.tab.c"
    break;

  case 291: /* fof_defined_plain_term: defined_functor LPAREN fof_arguments RPAREN  */
#line 810 "SyntaxBNF.y"
                                                                  {(yyval.pval) = P_BUILD("fof_defined_plain_term", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4625 "y.tab.c"
    break;

  case 292: /* fof_system_term: system_constant  */
#line 813 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("fof_system_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4631 "y.tab.c"
    break;

  case 293: /* fof_system_term: system_functor LPAREN fof_arguments RPAREN  */
#line 814 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("fof_system_term", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4637 "y.tab.c"
    break;

  case 294: /* fof_arguments: fof_term  */
#line 817 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("fof_arguments", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4643 "y.tab.c"
    break;

  case 295: /* fof_arguments: fof_term COMMA fof_arguments  */
#line 818 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("fof_arguments", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4649 "y.tab.c"
    break;

  case 296: /* fof_term: fof_function_term  */
#line 821 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("fof_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4655 "y.tab.c"
    break;

  case 297: /* fof_term: variable  */
#line 822 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("fof_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4661 "y.tab.c"
    break;

  case 298: /* fof_function_term: fof_plain_term  */
#line 825 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("fof_function_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4667 "y.tab.c"
    break;

  case 299: /* fof_function_term: fof_defined_term  */
#line 826 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("fof_function_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4673 "y.tab.c"
    break;

  case 300: /* fof_function_term: fof_system_term  */
#line 827 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("fof_function_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4679 "y.tab.c"
    break;

  case 301: /* fof_sequent: fof_formula_tuple gentzen_arrow fof_formula_tuple  */
#line 830 "SyntaxBNF.y"
                                                                {(yyval.pval) = P_BUILD("fof_sequent", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4685 "y.tab.c"
    break;

  case 302: /* fof_sequent: LPAREN fof_sequent RPAREN  */
#line 831 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("fof_sequent", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4691 "y.tab.c"
    break;

  case 303: /* fof_formula_tuple: LBRKT RBRKT  */
#line 834 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("fof_formula_tuple", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4697 "y.tab.c"
    break;

  case 304: /* fof_formula_tuple: LBRKT fof_formula_tuple_list RBRKT  */
#line 835 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("fof_formula_tuple", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4703 "y.tab.c"
    break;

  case 305: /* fof_formula_tuple_list: fof_logic_formula  */
#line 838 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("fof_formula_tuple_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4709 "y.tab.c"
    break;

  case 306: /* fof_formula_tuple_list: fof_logic_formula COMMA fof_formula_tuple_list  */
#line 839 "SyntaxBNF.y"
                                                                     {(yyval.pval) = P_BUILD("fof_formula_tuple_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4715 "y.tab.c"
    break;

  case 307: /* cnf_formula: cnf_disjunction  */
#line 842 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("cnf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4721 "y.tab.c"
    break;

  case 308: /* cnf_formula: LPAREN cnf_formula RPAREN  */
#line 843 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("cnf_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4727 "y.tab.c"
    break;

  case 309: /* cnf_disjunction: cnf_literal  */
#line 846 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("cnf_disjunction", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4733 "y.tab.c"
    break;

  case 310: /* cnf_disjunction: cnf_disjunction VLINE cnf_literal  */
#line 847 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("cnf_disjunction", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4739 "y.tab.c"
    break;

  case 311: /* cnf_literal: fof_atomic_formula  */
#line 850 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("cnf_literal", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4745 "y.tab.c"
    break;

  case 312: /* cnf_literal: TILDE fof_atomic_formula  */
#line 851 "SyntaxBNF.y"
                                               {(yyval.pval) = P_BUILD("cnf_literal", P_TOKEN("TILDE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4751 "y.tab.c"
    break;

  case 313: /* cnf_literal: TILDE LPAREN fof_atomic_formula RPAREN  */
#line 852 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("cnf_literal", P_TOKEN("TILDE ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4757 "y.tab.c"
    break;

  case 314: /* cnf_literal: fof_infix_unary  */
#line 853 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("cnf_literal", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4763 "y.tab.c"
    break;

  case 315: /* thf_quantifier: tff_quantifier  */
#line 856 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4769 "y.tab.c"
    break;

  case 316: /* thf_quantifier: th0_quantifier  */
#line 857 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4775 "y.tab.c"
    break;

  case 317: /* thf_quantifier: type_quantifier  */
#line 858 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4781 "y.tab.c"
    break;

  case 318: /* thf_unary_connective: unary_connective  */
#line 861 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4787 "y.tab.c"
    break;

  case 319: /* thf_unary_connective: ntf_short_connective  */
#line 862 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("thf_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4793 "y.tab.c"
    break;

  case 320: /* th0_quantifier: CARET  */
#line 865 "SyntaxBNF.y"
                       {(yyval.pval) = P_BUILD("th0_quantifier", P_TOKEN("CARET ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4799 "y.tab.c"
    break;

  case 321: /* th0_quantifier: AT_SIGN_PLUS  */
#line 866 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("th0_quantifier", P_TOKEN("AT_SIGN_PLUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4805 "y.tab.c"
    break;

  case 322: /* th0_quantifier: AT_SIGN_MINUS  */
#line 867 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("th0_quantifier", P_TOKEN("AT_SIGN_MINUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4811 "y.tab.c"
    break;

  case 323: /* type_quantifier: EXCLAMATION_GREATER  */
#line 870 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("type_quantifier", P_TOKEN("EXCLAMATION_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4817 "y.tab.c"
    break;

  case 324: /* type_quantifier: QUESTION_STAR  */
#line 871 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("type_quantifier", P_TOKEN("QUESTION_STAR ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4823 "y.tab.c"
    break;

  case 325: /* subtype_sign: LESS_LESS  */
#line 874 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("subtype_sign", P_TOKEN("LESS_LESS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4829 "y.tab.c"
    break;

  case 326: /* tff_unary_connective: unary_connective  */
#line 877 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4835 "y.tab.c"
    break;

  case 327: /* tff_unary_connective: ntf_short_connective  */
#line 878 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("tff_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4841 "y.tab.c"
    break;

  case 328: /* tff_quantifier: fof_quantifier  */
#line 881 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4847 "y.tab.c"
    break;

  case 329: /* tff_quantifier: hash  */
#line 882 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("tff_quantifier", P_TOKEN("hash ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4853 "y.tab.c"
    break;

  case 330: /* fof_quantifier: EXCLAMATION  */
#line 885 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("fof_quantifier", P_TOKEN("EXCLAMATION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4859 "y.tab.c"
    break;

  case 331: /* fof_quantifier: QUESTION  */
#line 886 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("fof_quantifier", P_TOKEN("QUESTION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4865 "y.tab.c"
    break;

  case 332: /* nonassoc_connective: LESS_EQUALS_GREATER  */
#line 889 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("LESS_EQUALS_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4871 "y.tab.c"
    break;

  case 333: /* nonassoc_connective: EQUALS_GREATER  */
#line 890 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("EQUALS_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4877 "y.tab.c"
    break;

  case 334: /* nonassoc_connective: LESS_EQUALS  */
#line 891 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("LESS_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4883 "y.tab.c"
    break;

  case 335: /* nonassoc_connective: LESS_TILDE_GREATER  */
#line 892 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("LESS_TILDE_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4889 "y.tab.c"
    break;

  case 336: /* nonassoc_connective: TILDE_VLINE  */
#line 893 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("TILDE_VLINE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4895 "y.tab.c"
    break;

  case 337: /* nonassoc_connective: TILDE_AMPERSAND  */
#line 894 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("TILDE_AMPERSAND ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4901 "y.tab.c"
    break;

  case 338: /* assoc_connective: VLINE  */
#line 897 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("assoc_connective", P_TOKEN("VLINE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4907 "y.tab.c"
    break;

  case 339: /* assoc_connective: AMPERSAND  */
#line 898 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("assoc_connective", P_TOKEN("AMPERSAND ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4913 "y.tab.c"
    break;

  case 340: /* unary_connective: TILDE  */
#line 901 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("unary_connective", P_TOKEN("TILDE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4919 "y.tab.c"
    break;

  case 341: /* gentzen_arrow: MINUS_MINUS_GREATER  */
#line 904 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("gentzen_arrow", P_TOKEN("MINUS_MINUS_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4925 "y.tab.c"
    break;

  case 342: /* assignment: COLON_EQUALS  */
#line 907 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("assignment", P_TOKEN("COLON_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4931 "y.tab.c"
    break;

  case 343: /* identical: EQUALS_EQUALS  */
#line 910 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("identical", P_TOKEN("EQUALS_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4937 "y.tab.c"
    break;

  case 344: /* type_constant: type_functor  */
#line 913 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("type_constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4943 "y.tab.c"
    break;

  case 345: /* type_functor: atomic_word  */
#line 916 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("type_functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4949 "y.tab.c"
    break;

  case 346: /* defined_type: atomic_defined_word  */
#line 919 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("defined_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4955 "y.tab.c"
    break;

  case 347: /* atom: untyped_atom  */
#line 922 "SyntaxBNF.y"
                    {(yyval.pval) = P_BUILD("atom", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4961 "y.tab.c"
    break;

  case 348: /* atom: defined_constant  */
#line 923 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("atom", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4967 "y.tab.c"
    break;

  case 349: /* untyped_atom: constant  */
#line 926 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("untyped_atom", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4973 "y.tab.c"
    break;

  case 350: /* untyped_atom: system_constant  */
#line 927 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("untyped_atom", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4979 "y.tab.c"
    break;

  case 351: /* defined_infix_pred: infix_equality  */
#line 930 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("defined_infix_pred", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4985 "y.tab.c"
    break;

  case 352: /* infix_equality: EQUALS  */
#line 933 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("infix_equality", P_TOKEN("EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4991 "y.tab.c"
    break;

  case 353: /* infix_inequality: EXCLAMATION_EQUALS  */
#line 936 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("infix_inequality", P_TOKEN("EXCLAMATION_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4997 "y.tab.c"
    break;

  case 354: /* constant: functor  */
#line 939 "SyntaxBNF.y"
                   {(yyval.pval) = P_BUILD("constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5003 "y.tab.c"
    break;

  case 355: /* functor: atomic_word  */
#line 942 "SyntaxBNF.y"
                      {(yyval.pval) = P_BUILD("functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5009 "y.tab.c"
    break;

  case 356: /* defined_constant: defined_functor  */
#line 945 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("defined_constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5015 "y.tab.c"
    break;

  case 357: /* defined_functor: atomic_defined_word  */
#line 948 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("defined_functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5021 "y.tab.c"
    break;

  case 358: /* system_constant: system_functor  */
#line 951 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("system_constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5027 "y.tab.c"
    break;

  case 359: /* system_functor: atomic_system_word  */
#line 954 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("system_functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5033 "y.tab.c"
    break;

  case 360: /* th1_defined_term: EXCLAMATION_EXCLAMATION  */
#line 957 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("EXCLAMATION_EXCLAMATION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5039 "y.tab.c"
    break;

  case 361: /* th1_defined_term: QUESTION_QUESTION  */
#line 958 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("QUESTION_QUESTION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5045 "y.tab.c"
    break;

  case 362: /* th1_defined_term: AT_AT_SIGN_PLUS  */
#line 959 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("AT_AT_SIGN_PLUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5051 "y.tab.c"
    break;

  case 363: /* th1_defined_term: AT_AT_SIGN_MINUS  */
#line 960 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("AT_AT_SIGN_MINUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5057 "y.tab.c"
    break;

  case 364: /* th1_defined_term: AT_SIGN_EQUALS  */
#line 961 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("AT_SIGN_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5063 "y.tab.c"
    break;

  case 365: /* defined_term: number  */
#line 964 "SyntaxBNF.y"
                      {(yyval.pval) = P_BUILD("defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5069 "y.tab.c"
    break;

  case 366: /* defined_term: distinct_object  */
#line 965 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("defined_term", P_TOKEN("distinct_object ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5075 "y.tab.c"
    break;

  case 367: /* variable: upper_word  */
#line 968 "SyntaxBNF.y"
                      {(yyval.pval) = P_BUILD("variable", P_TOKEN("upper_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5081 "y.tab.c"
    break;

  case 368: /* source: dag_source  */
#line 971 "SyntaxBNF.y"
                    {(yyval.pval) = P_BUILD("source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5087 "y.tab.c"
    break;

  case 369: /* source: internal_source  */
#line 972 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5093 "y.tab.c"
    break;

  case 370: /* source: external_source  */
#line 973 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5099 "y.tab.c"
    break;

  case 371: /* source: _LIT_unknown  */
#line 974 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("source", P_TOKEN("_LIT_unknown ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5105 "y.tab.c"
    break;

  case 372: /* source: LBRKT sources RBRKT  */
#line 975 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("source", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5111 "y.tab.c"
    break;

  case 373: /* sources: source  */
#line 978 "SyntaxBNF.y"
                 {(yyval.pval) = P_BUILD("sources", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5117 "y.tab.c"
    break;

  case 374: /* sources: source COMMA sources  */
#line 979 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("sources", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5123 "y.tab.c"
    break;

  case 375: /* dag_source: name  */
#line 982 "SyntaxBNF.y"
                  {(yyval.pval) = P_BUILD("dag_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5129 "y.tab.c"
    break;

  case 376: /* dag_source: inference_record  */
#line 983 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("dag_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5135 "y.tab.c"
    break;

  case 377: /* inference_record: _LIT_inference LPAREN inference_rule COMMA useful_info COMMA parents RPAREN  */
#line 986 "SyntaxBNF.y"
                                                                                               {(yyval.pval) = P_BUILD("inference_record", P_TOKEN("_LIT_inference ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 5141 "y.tab.c"
    break;

  case 378: /* inference_rule: atomic_word  */
#line 989 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("inference_rule", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5147 "y.tab.c"
    break;

  case 379: /* internal_source: _LIT_introduced LPAREN intro_type COMMA useful_info COMMA parents RPAREN  */
#line 992 "SyntaxBNF.y"
                                                                                           {(yyval.pval) = P_BUILD("internal_source", P_TOKEN("_LIT_introduced ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 5153 "y.tab.c"
    break;

  case 380: /* intro_type: atomic_word  */
#line 995 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("intro_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5159 "y.tab.c"
    break;

  case 381: /* external_source: file_source  */
#line 998 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("external_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5165 "y.tab.c"
    break;

  case 382: /* external_source: theory  */
#line 999 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("external_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5171 "y.tab.c"
    break;

  case 383: /* external_source: creator_source  */
#line 1000 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("external_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5177 "y.tab.c"
    break;

  case 384: /* file_source: _LIT_file LPAREN file_name file_info RPAREN  */
#line 1003 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("file_source", P_TOKEN("_LIT_file ", (yyvsp[-4].ival)), P_TOKEN("LPAREN ", (yyvsp[-3].ival)), (yyvsp[-2].pval), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL);}
#line 5183 "y.tab.c"
    break;

  case 385: /* file_info: COMMA name  */
#line 1006 "SyntaxBNF.y"
                       {(yyval.pval) = P_BUILD("file_info", P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5189 "y.tab.c"
    break;

  case 386: /* file_info: nothing  */
#line 1007 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("file_info", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5195 "y.tab.c"
    break;

  case 387: /* theory: _LIT_theory LPAREN theory_name optional_info RPAREN  */
#line 1010 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("theory", P_TOKEN("_LIT_theory ", (yyvsp[-4].ival)), P_TOKEN("LPAREN ", (yyvsp[-3].ival)), (yyvsp[-2].pval), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL);}
#line 5201 "y.tab.c"
    break;

  case 388: /* theory_name: atomic_word  */
#line 1013 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("theory_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5207 "y.tab.c"
    break;

  case 389: /* creator_source: _LIT_creator LPAREN creator_name COMMA useful_info COMMA parents RPAREN  */
#line 1016 "SyntaxBNF.y"
                                                                                         {(yyval.pval) = P_BUILD("creator_source", P_TOKEN("_LIT_creator ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 5213 "y.tab.c"
    break;

  case 390: /* creator_name: atomic_word  */
#line 1019 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("creator_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5219 "y.tab.c"
    break;

  case 391: /* parents: LBRKT RBRKT  */
#line 1022 "SyntaxBNF.y"
                      {(yyval.pval) = P_BUILD("parents", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5225 "y.tab.c"
    break;

  case 392: /* parents: LBRKT parent_list RBRKT  */
#line 1023 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("parents", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5231 "y.tab.c"
    break;

  case 393: /* parent_list: parent_info  */
#line 1026 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("parent_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5237 "y.tab.c"
    break;

  case 394: /* parent_list: parent_info COMMA parent_list  */
#line 1027 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("parent_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5243 "y.tab.c"
    break;

  case 395: /* parent_info: source parent_details  */
#line 1030 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("parent_info", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5249 "y.tab.c"
    break;

  case 396: /* parent_details: COLON general_term  */
#line 1033 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("parent_details", P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5255 "y.tab.c"
    break;

  case 397: /* parent_details: nothing  */
#line 1034 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("parent_details", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5261 "y.tab.c"
    break;

  case 398: /* optional_info: COMMA useful_info  */
#line 1037 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("optional_info", P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5267 "y.tab.c"
    break;

  case 399: /* optional_info: nothing  */
#line 1038 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("optional_info", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5273 "y.tab.c"
    break;

  case 400: /* useful_info: general_list  */
#line 1041 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("useful_info", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5279 "y.tab.c"
    break;

  case 401: /* include: _LIT_include LPAREN file_name include_optionals RPAREN PERIOD  */
#line 1044 "SyntaxBNF.y"
                                                                        {(yyval.pval) = P_BUILD("include", P_TOKEN("_LIT_include ", (yyvsp[-5].ival)), P_TOKEN("LPAREN ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL);}
#line 5285 "y.tab.c"
    break;

  case 402: /* include_optionals: nothing  */
#line 1047 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("include_optionals", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5291 "y.tab.c"
    break;

  case 403: /* include_optionals: COMMA formula_selection  */
#line 1048 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("include_optionals", P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5297 "y.tab.c"
    break;

  case 404: /* include_optionals: COMMA formula_selection COMMA space_name  */
#line 1049 "SyntaxBNF.y"
                                                               {(yyval.pval) = P_BUILD("include_optionals", P_TOKEN("COMMA ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5303 "y.tab.c"
    break;

  case 405: /* formula_selection: LBRKT name_list RBRKT  */
#line 1052 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("formula_selection", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5309 "y.tab.c"
    break;

  case 406: /* formula_selection: STAR  */
#line 1053 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("formula_selection", P_TOKEN("STAR ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5315 "y.tab.c"
    break;

  case 407: /* name_list: name  */
#line 1056 "SyntaxBNF.y"
                 {(yyval.pval) = P_BUILD("name_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5321 "y.tab.c"
    break;

  case 408: /* name_list: name COMMA name_list  */
#line 1057 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("name_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5327 "y.tab.c"
    break;

  case 409: /* space_name: name  */
#line 1060 "SyntaxBNF.y"
                  {(yyval.pval) = P_BUILD("space_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5333 "y.tab.c"
    break;

  case 410: /* general_term: general_data  */
#line 1063 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("general_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5339 "y.tab.c"
    break;

  case 411: /* general_term: general_data COLON general_term  */
#line 1064 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("general_term", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5345 "y.tab.c"
    break;

  case 412: /* general_term: general_list  */
#line 1065 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("general_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5351 "y.tab.c"
    break;

  case 413: /* general_data: atomic_word  */
#line 1068 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5357 "y.tab.c"
    break;

  case 414: /* general_data: general_function  */
#line 1069 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5363 "y.tab.c"
    break;

  case 415: /* general_data: variable  */
#line 1070 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5369 "y.tab.c"
    break;

  case 416: /* general_data: number  */
#line 1071 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5375 "y.tab.c"
    break;

  case 417: /* general_data: distinct_object  */
#line 1072 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("general_data", P_TOKEN("distinct_object ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5381 "y.tab.c"
    break;

  case 418: /* general_data: formula_data  */
#line 1073 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5387 "y.tab.c"
    break;

  case 419: /* general_function: atomic_word LPAREN general_terms RPAREN  */
#line 1076 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("general_function", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5393 "y.tab.c"
    break;

  case 420: /* formula_data: _DLR_thf LPAREN thf_formula RPAREN  */
#line 1079 "SyntaxBNF.y"
                                                  {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_thf ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5399 "y.tab.c"
    break;

  case 421: /* formula_data: _DLR_tff LPAREN tff_formula RPAREN  */
#line 1080 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_tff ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5405 "y.tab.c"
    break;

  case 422: /* formula_data: _DLR_fof LPAREN fof_formula RPAREN  */
#line 1081 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_fof ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5411 "y.tab.c"
    break;

  case 423: /* formula_data: _DLR_cnf LPAREN cnf_formula RPAREN  */
#line 1082 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_cnf ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5417 "y.tab.c"
    break;

  case 424: /* formula_data: _DLR_fot LPAREN fof_term RPAREN  */
#line 1083 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_fot ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5423 "y.tab.c"
    break;

  case 425: /* general_list: LBRKT RBRKT  */
#line 1086 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("general_list", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5429 "y.tab.c"
    break;

  case 426: /* general_list: LBRKT general_terms RBRKT  */
#line 1087 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("general_list", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5435 "y.tab.c"
    break;

  case 427: /* general_terms: general_term  */
#line 1090 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("general_terms", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5441 "y.tab.c"
    break;

  case 428: /* general_terms: general_term COMMA general_terms  */
#line 1091 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("general_terms", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5447 "y.tab.c"
    break;

  case 429: /* name: atomic_word  */
#line 1094 "SyntaxBNF.y"
                   {(yyval.pval) = P_BUILD("name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5453 "y.tab.c"
    break;

  case 430: /* name: integer  */
#line 1095 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("name", P_TOKEN("integer ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5459 "y.tab.c"
    break;

  case 431: /* atomic_word: lower_word  */
#line 1098 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("atomic_word", P_TOKEN("lower_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5465 "y.tab.c"
    break;

  case 432: /* atomic_word: single_quoted  */
#line 1099 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("atomic_word", P_TOKEN("single_quoted ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5471 "y.tab.c"
    break;

  case 433: /* atomic_word: back_quoted  */
#line 1100 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("atomic_word", P_TOKEN("back_quoted ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5477 "y.tab.c"
    break;

  case 434: /* atomic_defined_word: dollar_word  */
#line 1103 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("atomic_defined_word", P_TOKEN("dollar_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5483 "y.tab.c"
    break;

  case 435: /* atomic_system_word: dollar_dollar_word  */
#line 1106 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("atomic_system_word", P_TOKEN("dollar_dollar_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5489 "y.tab.c"
    break;

  case 436: /* number: integer  */
#line 1109 "SyntaxBNF.y"
                 {(yyval.pval) = P_BUILD("number", P_TOKEN("integer ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5495 "y.tab.c"
    break;

  case 437: /* number: rational  */
#line 1110 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("number", P_TOKEN("rational ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5501 "y.tab.c"
    break;

  case 438: /* number: real  */
#line 1111 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("number", P_TOKEN("real ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5507 "y.tab.c"
    break;

  case 439: /* file_name: atomic_word  */
#line 1114 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("file_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5513 "y.tab.c"
    break;

  case 440: /* nothing: %empty  */
#line 1117 "SyntaxBNF.y"
          {(yyval.pval) = P_BUILD("nothing",NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5519 "y.tab.c"
    break;


#line 5523 "y.tab.c"

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

