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
#define _LIT_file 304
#define _LIT_fof 305
#define _LIT_include 306
#define _LIT_inference 307
#define _LIT_introduced 308
#define _LIT_tcf 309
#define _LIT_tff 310
#define _LIT_thf 311
#define _LIT_tpi 312
#define arrow 313
#define back_quoted 314
#define distinct_object 315
#define dollar_dollar_word 316
#define dollar_word 317
#define hash 318
#define integer 319
#define less_sign 320
#define lower_word 321
#define plus 322
#define rational 323
#define real 324
#define single_quoted 325
#define slash 326
#define slosh 327
#define unrecognized 328
#define upper_word 329

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 152 "SyntaxBNF.y"
int ival; double dval; char* sval; void* pval;

#line 425 "y.tab.c"

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3586

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  225
/* YYNRULES -- Number of rules.  */
#define YYNRULES  440
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  815

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
       0,   228,   228,   229,   232,   233,   236,   237,   238,   239,
     240,   241,   244,   247,   250,   253,   256,   259,   262,   265,
     266,   269,   270,   273,   274,   275,   278,   279,   280,   281,
     282,   283,   286,   287,   288,   291,   294,   295,   296,   299,
     300,   303,   304,   307,   308,   311,   312,   313,   316,   317,
     320,   321,   322,   323,   326,   329,   332,   333,   336,   339,
     340,   343,   346,   349,   350,   351,   352,   355,   356,   359,
     360,   361,   362,   363,   366,   367,   370,   373,   376,   379,
     380,   383,   384,   387,   388,   391,   394,   395,   398,   399,
     400,   403,   404,   405,   406,   407,   410,   411,   414,   415,
     416,   419,   422,   423,   426,   427,   430,   431,   432,   435,
     438,   441,   442,   443,   446,   447,   450,   451,   454,   455,
     458,   461,   464,   467,   468,   469,   472,   473,   474,   475,
     476,   477,   480,   481,   484,   487,   488,   491,   492,   495,
     496,   499,   500,   501,   504,   505,   508,   509,   510,   511,
     514,   517,   520,   521,   524,   525,   528,   531,   532,   535,
     538,   541,   542,   543,   546,   547,   550,   553,   554,   555,
     556,   559,   562,   563,   566,   569,   570,   573,   574,   577,
     578,   581,   584,   585,   588,   589,   592,   595,   596,   597,
     600,   601,   602,   603,   604,   607,   608,   611,   612,   615,
     616,   619,   620,   623,   624,   625,   628,   631,   632,   633,
     636,   637,   640,   641,   642,   643,   644,   645,   648,   649,
     652,   655,   656,   659,   662,   663,   666,   669,   672,   675,
     676,   679,   680,   683,   684,   687,   690,   691,   694,   695,
     698,   699,   702,   705,   706,   709,   712,   715,   716,   717,
     718,   721,   722,   725,   726,   729,   732,   733,   736,   737,
     738,   741,   742,   745,   748,   749,   752,   753,   756,   757,
     760,   761,   764,   767,   768,   771,   772,   773,   776,   779,
     780,   783,   784,   785,   788,   791,   792,   795,   798,   801,
     804,   805,   808,   809,   812,   815,   816,   819,   820,   823,
     824,   827,   828,   831,   832,   833,   836,   837,   840,   841,
     844,   845,   848,   849,   852,   853,   856,   857,   858,   859,
     862,   863,   864,   867,   868,   871,   872,   873,   876,   877,
     880,   883,   884,   887,   888,   891,   892,   895,   896,   897,
     898,   899,   900,   903,   904,   907,   910,   913,   916,   919,
     920,   923,   924,   925,   928,   931,   934,   937,   940,   943,
     946,   949,   952,   955,   958,   961,   964,   967,   968,   969,
     970,   971,   974,   975,   978,   981,   982,   983,   984,   987,
     988,   991,   992,   995,   998,  1001,  1004,  1007,  1010,  1013,
    1014,  1017,  1018,  1021,  1022,  1025,  1028,  1029,  1032,  1033,
    1036,  1039,  1042,  1043,  1044,  1047,  1048,  1051,  1052,  1055,
    1058,  1059,  1060,  1063,  1064,  1065,  1066,  1067,  1068,  1071,
    1074,  1075,  1076,  1077,  1078,  1081,  1082,  1085,  1086,  1089,
    1090,  1093,  1094,  1095,  1098,  1101,  1104,  1105,  1106,  1109,
    1112
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

#define YYPACT_NINF (-555)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-358)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -555,   464,  -555,  -555,    52,    74,    84,    97,    99,   153,
     155,  -555,  -555,  -555,  -555,  -555,  -555,  -555,  -555,  -555,
     635,   635,   216,   635,   635,   635,   635,  -555,  -555,  -555,
    -555,   214,  -555,   220,  -555,   241,   252,   254,   263,   271,
     232,   232,    54,   264,  -555,   232,   232,   232,   232,   326,
     292,   343,   635,  -555,   354,   355,   360,   377,   398,   400,
    3512,  1260,  1414,   304,   425,   635,  -555,  1430,  1093,  3016,
    1414,  3483,   433,   439,   459,   465,   467,  -555,  -555,  -555,
    -555,  -555,  -555,  -555,   452,  -555,  -555,  -555,   476,  -555,
    1260,  2186,  -555,  -555,  -555,  -555,  -555,  -555,  -555,  -555,
    -555,  -555,   183,  -555,  -555,   201,   230,   311,  -555,   491,
     468,  -555,  -555,   484,  -555,   496,  -555,   498,  -555,  -555,
    -555,  -555,  -555,  -555,  -555,  1315,  1414,  -555,  -555,   491,
    -555,  -555,  -555,  -555,   492,   535,   106,  -555,  1226,   178,
    -555,  -555,  -555,   514,   529,  1771,  -555,   635,  -555,  -555,
     532,  1811,   105,  -555,   491,  -555,  -555,  -555,   548,   555,
     127,  2120,  2711,   550,  -555,   553,   491,  -555,  -555,  -555,
    -555,   528,   582,  1394,   233,  -555,  -555,   309,  -555,  -555,
     384,  -555,  -555,  -555,   334,  -555,  -555,  -555,   311,   514,
    -555,  -555,  -555,  -555,   583,  -555,  3458,   569,  -555,  -555,
     548,   573,  -555,   199,   572,   575,   591,  -555,   595,  -555,
     394,   585,  -555,  -555,  -555,  -555,  -555,  -555,  -555,  -555,
     127,  2646,  2561,  -555,  -555,   597,   491,  -555,  -555,  -555,
    -555,   587,   636,   631,  1021,   504,  -555,  3084,   314,  -555,
    -555,   473,  -555,  -555,  -555,   436,  -555,  -555,   311,   514,
    -555,  -555,   111,  -555,  -555,   601,   576,  -555,  -555,  -555,
    -555,  -555,   624,  3152,  -555,  -555,  -555,  -555,   639,   573,
     199,   620,   575,   625,  -555,   632,  -555,  -555,   440,   491,
    -555,  -555,   638,   628,  1260,  1414,  2255,  1093,  3016,  3512,
    3512,   629,  2255,  -555,   646,  -555,  -555,  2255,  -555,  2255,
     756,   637,  -555,  2070,  2255,  2255,  2255,  1771,  -555,   651,
     640,   644,   649,   655,  1771,  1771,  1771,  -555,  -555,  -555,
    -555,  -555,  -555,  1771,  1771,  -555,   645,   596,  -555,  -555,
    -555,  -555,   596,   656,   661,   833,   648,    93,  -555,  -555,
    -555,  3308,   671,  -555,  -555,   659,   120,   672,  -555,  -555,
     466,   676,   677,   520,   660,   678,  3408,  3408,  3408,  3408,
    3408,  -555,  3408,  2150,  2150,   695,   693,   691,  3308,  -555,
    -555,  -555,  -555,  -555,   596,  -555,   823,  3408,  3408,  3408,
     129,  2784,  -555,   709,   688,  -555,  -555,  -555,  -555,   698,
     700,   701,  3152,  -555,  -555,   639,  -555,  -555,   522,   702,
    3084,  3084,  3084,  3084,  3084,  3084,  3084,  -555,  -555,  -555,
     483,  -555,  -555,  3084,  1568,  1568,   719,  3288,  3288,  3288,
    3288,  3288,   596,  2784,  -555,  -555,  -555,  -555,  -555,  3084,
     823,  3084,  3084,  3084,   710,  3512,  -555,   711,   714,  -555,
    -555,  -555,   715,   717,   718,  -555,   722,  -555,   726,  -555,
    -555,   756,   736,   739,   740,   732,  -555,  -555,  -555,  -555,
    -555,  -555,   697,  -555,   733,   757,   737,   738,  1771,  -555,
    -555,  -555,   747,  -555,  -555,  -555,  -555,  -555,  -555,   750,
     771,   752,   775,  -555,   779,  -555,   764,   833,   833,  -555,
    -555,  -555,   734,   741,  -555,  -555,   774,  -555,   770,  -555,
    -555,  -555,  -555,  -555,   762,  -555,  -555,  3408,  -555,  -555,
     516,   557,   557,  -555,   785,  -555,  -555,  -555,  -555,   772,
    -555,  -555,  -555,   539,  -555,  -555,  -555,  -555,  -555,  -555,
    -555,   142,  3358,  3408,  -555,  -555,  -555,  -555,  -555,  3408,
     776,   765,  -555,  -555,  -555,  -555,  -555,   777,   778,   782,
    1751,  -555,  3084,  -555,   542,  -555,  -555,   705,   705,   793,
    -555,   799,  -555,  -555,  -555,  -555,  -555,  -555,  -555,  -555,
     142,  2948,  2880,  -555,  -555,  -555,  -555,  -555,  2880,  -555,
    -555,   773,  -555,  -555,  -555,  -555,   798,   821,   824,   800,
     631,   835,   836,  -555,   773,  -555,  -555,  -555,   807,  -555,
     808,   818,   827,  -555,  -555,  -555,  -555,  -555,  -555,  -555,
    -555,   845,   829,   216,   216,   216,   837,  -555,  -555,  -555,
    -555,  2255,  -555,  -555,  -555,  -555,   851,   596,   854,   596,
     502,  -555,   859,   838,   840,   136,   850,   277,   502,   596,
     502,  2150,   866,  -555,   855,   877,  -555,  -555,  -555,   861,
     884,   109,  -555,   862,   865,  -555,   891,  -555,  -555,  -555,
     949,   866,  -555,   868,   893,  -555,  -555,  -555,   873,   896,
    3220,  -555,   876,   902,   596,  3084,  -555,  -555,  -555,  -555,
    -555,   756,  -555,   901,   903,  -555,   905,  -555,  -555,  -555,
    -555,  1771,  -555,  1634,  -555,   502,  -555,   833,  -555,  -555,
     502,  -555,  -555,   502,  -555,   880,   906,   889,  -555,   899,
     762,  -555,   557,  3358,  -555,   917,  -555,   922,  -555,  -555,
    -555,  3408,   907,   908,  -555,   910,  1751,  -555,   705,  2646,
     922,   923,  -555,  -555,  -555,  -555,  -555,  -555,   635,   915,
    -555,   837,   837,  -555,  -555,   850,  -555,  -555,  -555,   924,
     502,  -555,  -555,  -555,  -555,   927,   943,   925,   407,  3408,
    -555,  3408,  -555,  -555,  -555,  -555,   307,   944,   926,  3084,
    3084,  -555,  -555,   946,   951,  1071,  -555,   190,  -555,   932,
    -555,  3084,  -555,  -555,   933,   952,   952,   634,  -555,  -555,
    -555,  -555,  -555,  -555,  -555,  1181,   941,   942,   634,   945,
    -555,   968,   947,   967,  -555,  -555,   954,  -555,  3512,  -555,
    -555,  -555,   756,  -555,  -555
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
     438,   374,   415,    22,   410,   414,   418,   412,   413,   416,
       0,     0,   373,   435,   434,   319,   316,   281,   282,   285,
     286,   283,   284,   304,   293,   287,   289,     0,   301,   440,
     312,   314,   290,   361,   295,   363,   297,   365,   292,   302,
     362,   364,   366,   372,   335,     0,     0,   336,   345,   440,
     256,   258,   261,   262,   264,   265,   274,   271,     0,   273,
     275,   276,   257,     0,     0,     0,   405,     0,   404,   409,
       0,     0,   373,   252,   440,   251,   253,   254,     0,   290,
       0,     0,     0,     0,   334,     0,   440,   123,   128,   132,
     133,   135,   136,     0,   141,   148,   146,   142,   157,   158,
     147,   161,   162,   166,   143,   163,   170,   169,     0,   192,
     124,   125,   130,   131,     0,   332,     0,     0,   333,   331,
     351,     0,   353,   164,   361,   167,   363,   172,   365,   191,
     150,   366,   370,   369,   371,   327,   326,   325,   367,   328,
       0,     0,     0,   368,   329,     0,   440,    23,    28,    32,
      33,    36,    37,    38,     0,    45,    50,     0,    46,    59,
      60,    51,    63,    64,    70,    47,    65,    73,     0,    68,
      66,    24,     0,    34,   111,   112,   113,    25,    30,    31,
      72,   324,     0,     0,   321,   322,   320,   323,   351,     0,
      67,   361,    69,   363,    77,   365,    75,    74,    52,   440,
      13,   425,   427,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   317,     0,   359,   360,     0,   358,     0,
       0,     0,    20,     0,     0,     0,     0,     0,   308,   310,
       0,     0,     0,     0,     0,     0,     0,   338,   339,   337,
     340,   342,   341,     0,     0,   346,     0,     0,   274,   270,
     273,   408,     0,     0,     0,     0,     0,     0,   243,   245,
     244,     0,     0,   195,   187,   197,   189,     0,   164,   167,
     188,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   348,     0,     0,     0,     0,     0,     0,     0,   159,
     144,   145,   147,   150,     0,   330,     0,     0,     0,     0,
       0,     0,    96,   102,     0,    67,    69,   344,   343,     0,
       0,     0,    95,    91,    92,     0,    93,    94,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    54,    45,    46,
      51,    47,    68,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    61,    48,    49,    51,    52,     0,
       0,     0,     0,     0,     0,     0,   426,     0,     0,   303,
     294,   305,     0,     0,     0,   411,     0,   313,     0,   288,
     272,     0,     0,     0,     0,   440,   375,   382,   376,   377,
     387,   381,     0,   315,     0,   299,     0,     0,     0,   309,
     277,   307,     0,   267,   269,   268,   266,   263,   306,     0,
     279,     0,   152,   154,   155,   200,     0,     0,     0,   199,
     202,   204,     0,   201,   203,   217,     0,   212,   354,   213,
     214,   355,   356,   249,     0,   236,   247,     0,   196,   250,
     149,     0,     0,   350,     0,   175,   349,   361,   248,     0,
     138,   141,   142,   147,   143,   192,   140,   139,   137,   134,
     227,     0,     0,     0,   190,   171,   193,   160,   228,     0,
       0,     0,   351,   226,   352,   363,   357,     0,     0,     0,
       0,   229,     0,    97,    53,    71,   105,     0,     0,     0,
      79,     0,    40,    42,    44,    41,    43,    39,    35,   121,
       0,     0,     0,    88,    76,    89,    62,   122,     0,   109,
     116,   114,   115,   118,   117,   119,     0,    56,     0,     0,
     110,     0,   109,   104,   106,   108,   107,   120,     0,   101,
       0,     0,     0,   428,   423,   422,   424,   421,   420,   419,
     318,   379,     0,     0,     0,     0,     0,    19,   399,    18,
     291,     0,   296,   298,   311,    17,     0,     0,     0,     0,
       0,    16,   224,     0,     0,     0,   210,     0,     0,     0,
       0,     0,     0,   242,     0,   238,   241,   240,   198,     0,
     177,     0,    15,     0,     0,   149,     0,   165,   168,   173,
       0,     0,   235,     0,   231,   234,   233,   103,     0,    81,
       0,    14,     0,     0,     0,     0,    53,   100,    98,    99,
      12,     0,   378,   440,     0,   384,     0,   386,   398,   400,
     300,     0,   280,     0,   153,     0,   156,     0,   223,   205,
       0,   216,   211,     0,   220,     0,   218,     0,   246,     0,
       0,   176,     0,     0,   182,     0,   179,     0,   183,   194,
     186,     0,     0,     0,    95,     0,     0,    80,     0,     0,
       0,     0,    83,    90,    55,    57,    58,   380,     0,     0,
     390,     0,     0,   278,   255,     0,   225,   221,   222,     0,
       0,   215,   237,   239,   178,   161,   184,     0,   189,     0,
     347,     0,   151,   230,   232,    82,   102,    86,     0,     0,
       0,   389,   388,     0,     0,     0,   219,     0,   180,     0,
     181,     0,    84,    85,     0,     0,     0,     0,   209,   206,
     207,   185,   174,    87,    78,     0,     0,     0,     0,     0,
     391,   440,     0,   393,   383,   385,     0,   208,     0,   395,
     397,   392,     0,   396,   394
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -555,  -555,  -555,  -555,  -555,  -555,  -555,  -555,  -555,  -555,
    -555,     8,   561,   696,   -41,  -555,  -555,  -555,  -555,  -555,
    -367,  -112,  -555,   806,  -555,  -555,   319,  -555,    41,  -164,
    -555,  1883,  -555,  -555,  -555,    73,  -555,  -555,  -555,   267,
    -555,   327,   215,   -50,  -555,   414,  -555,    20,  -278,  -196,
     328,  -312,  -555,  -555,  -354,  -555,  -555,  -555,  -494,  -555,
     720,   -44,  -555,  -555,  -555,  -555,  -555,  -286,  -555,  -173,
    -555,  -555,  -311,  -555,  -555,  -271,   809,  -555,    70,  -554,
    -555,  -555,  -264,  -555,  -555,  -555,   294,  -555,   357,  -555,
     234,  -555,  -322,  -282,   590,  -256,   -46,   674,   524,   238,
    -555,  -463,  -145,   265,   229,  -555,  -555,   320,  -555,  -455,
    -555,  -555,   296,  -555,  -555,  -555,   308,  -555,  -555,  -184,
    -555,  -481,   642,  -555,   330,  -555,   -43,   -48,  -555,  -555,
    -555,  -555,  -555,  -116,   -53,   -98,   -94,  -555,   399,    -7,
    -555,  -555,  -555,  -555,  -555,  -238,  -555,  -555,  -154,  -139,
    -203,   118,  -555,   904,   699,   560,    39,  -555,   728,  -555,
     -82,  -555,  -316,   760,  -555,  2008,   -12,   -58,  -555,  2165,
     -88,   321,  -210,   -30,   -16,  -555,  -555,  -555,  -555,   -84,
     -42,     5,   564,   749,  1247,  1360,  1620,  1733,  -555,  2106,
     -26,  -290,   358,  -555,  -555,  -555,  -555,  -555,  -555,  -555,
    -555,   256,   228,  -555,  -555,  -555,  -206,  -555,  -555,  -555,
     911,  -555,   -49,  -555,  -555,  -555,  -506,  -258,    -8,   -19,
    -130,   211,   -51,   437,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    11,    12,    13,   279,    14,    15,    16,    17,
      18,   301,    50,   226,   383,   228,   229,   230,   231,   232,
     233,   234,   424,   235,   236,   237,   586,   587,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   559,   668,
     731,   767,   768,   248,   390,   412,   250,   598,   384,   251,
     593,   252,   595,   253,   254,   255,   256,   257,   258,   259,
     166,   344,   168,   169,   170,   171,   172,   173,   369,   174,
     175,   176,   481,   482,   483,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   514,   649,   715,   756,   717,
     757,   187,   345,   188,   346,   347,   333,   632,   490,   491,
     789,   492,   493,   707,   494,   637,   495,   633,   191,   192,
     193,   260,   663,   664,   665,   194,   644,   645,   646,   337,
     338,   647,   261,   154,   155,   156,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   479,   141,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     464,   107,   108,   142,   143,   310,   157,   110,   111,   262,
     263,   264,   265,   376,   196,   266,   198,   393,   394,   267,
     365,   769,   362,   158,   201,   497,   498,   499,   202,   297,
     396,   397,   385,   271,   386,   273,   274,   275,   276,   277,
     119,   611,   612,   456,   457,   684,   458,   686,   459,   460,
     739,   796,   802,   803,   809,   617,   688,    19,    43,    54,
      63,   148,   282,    84,    85,    86,    87,   283,   461,   120,
     121,   122,   123,    35,   302
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       2,    32,    32,    34,    32,    32,    32,    32,    95,    89,
     455,    83,    31,    33,    95,    36,    37,    38,    39,   496,
      89,   153,   190,   370,   167,   635,   391,   280,   227,   328,
     339,   413,   446,    32,    82,    44,   380,    95,   200,   268,
     530,    88,   210,   278,    64,    82,    32,   329,   439,   643,
     144,   330,    88,   269,    96,   326,   662,   149,   144,   439,
      96,   439,   590,   541,   582,   298,   439,   439,   439,   666,
     520,   526,   527,   528,   529,   596,    52,   309,   311,    20,
     324,   535,   537,    96,   293,   522,   522,   522,   522,   522,
     339,    53,   524,   524,   524,   524,   524,   714,    95,   426,
     109,    21,   466,   467,   363,   580,   581,   583,   584,   585,
     689,    22,   299,   144,   144,   360,  -350,   594,   352,  -259,
     504,   547,   548,   549,    23,   407,    24,   505,    32,   291,
    -350,   713,   440,   144,  -192,   210,   210,   313,  -192,    64,
     392,  -259,  -259,   440,    96,   440,   298,   441,   417,   325,
     440,   440,   440,   599,   599,   599,   550,   336,   441,   755,
     441,   416,   334,   551,   414,   441,   441,   441,    27,   418,
     373,   496,   496,   700,   355,    29,   406,   603,   419,    30,
      25,   389,    26,   521,   521,   521,   521,   521,    93,    94,
     291,  -260,   395,   364,   638,   278,   278,  -303,   328,   328,
     328,  -303,   560,    93,    94,   502,   298,   328,   328,   294,
    -349,   278,   532,  -260,  -260,  -294,   473,   474,   475,  -294,
     330,   330,   330,   714,  -349,   476,   477,    40,   426,   330,
     330,    95,   662,    41,   399,   689,   689,   428,    89,    89,
     445,   190,   438,   167,  -305,   666,  -126,   227,  -305,    27,
      95,   648,   298,   415,    42,   643,    29,   200,   268,   311,
      30,   210,   278,    82,    82,    45,   372,    46,  -126,  -126,
      88,    88,   269,   144,   667,    27,    47,    96,   409,   211,
     211,    32,    29,   654,    48,   448,    30,   434,   562,   563,
     564,   565,   566,   567,   568,   144,    96,   352,    49,   392,
      55,   480,   144,   144,   144,    61,   484,   515,   590,   500,
     411,   144,   144,   702,   703,   210,   501,   591,   694,   760,
     552,   596,  -127,   437,   540,   295,   -27,   -27,   705,   296,
     210,   210,   210,   210,   210,   806,   210,   536,   536,   146,
     389,   392,   210,   636,  -127,  -127,   542,  -129,   484,   -27,
     -27,   210,   210,   210,    60,   278,    62,   502,   502,   708,
     543,   669,   391,   594,   574,   576,   428,    65,   395,  -129,
    -129,   340,   569,    67,   278,   278,   278,   278,   278,   278,
     278,   496,   589,   439,    89,    66,   380,   278,   575,   575,
      68,   428,   428,   428,   428,   428,   588,   278,  -190,   361,
     542,   339,  -190,   278,   442,   278,   278,   278,  -193,    82,
     294,    69,  -193,    70,   597,   449,    88,   450,   690,  -183,
     309,  -192,   465,   465,   465,  -192,   523,   523,   523,   523,
     523,   340,    32,   534,   534,   762,   325,   779,   147,   780,
     339,   409,   409,   409,   409,   409,   409,   409,   -29,   -29,
     522,   413,   600,   601,   -89,   618,   144,   524,   -89,   496,
     284,   500,   500,   289,     3,   650,   285,   440,   501,   501,
     409,   -29,   -29,   411,   411,   411,   411,   411,   411,   411,
    -191,   210,   441,   249,  -191,   696,   286,   -88,   361,   653,
     392,   -88,   287,   704,   288,   706,   392,   -88,   211,   211,
     502,   -88,   411,   290,   300,   801,   210,   210,   502,   303,
     502,   304,     4,   210,     5,     6,   -26,   -26,     7,     8,
       9,    10,   801,   305,   487,   306,   278,   395,   395,   695,
    -194,   672,   669,   314,  -194,   773,   774,   589,   315,   -26,
     -26,  -109,   511,   325,   557,   278,   278,   512,   521,   558,
     745,   327,   278,  -190,   332,   747,   -90,  -190,   748,   335,
     -90,    27,  -109,   591,    94,   502,  -349,   502,    29,   356,
     502,  -109,    30,   502,   642,   328,    81,   353,   724,    27,
     513,    27,   513,   354,   512,   357,    29,   546,    29,   366,
      30,   374,    30,   743,    34,   685,   687,   330,   375,   377,
    -352,   480,    51,   484,   500,   706,    56,    57,    58,    59,
    -357,   501,   500,   484,   500,   536,    27,   513,   378,   501,
     502,   501,   379,    29,   398,   112,   112,    30,   400,   730,
     790,   159,   203,   270,   112,   249,   249,   402,   420,   401,
      95,   546,   636,   421,   278,   502,   422,   431,   588,   278,
     429,   435,   432,   636,   112,   112,   487,   502,   189,   433,
     295,   798,    32,   436,   468,   447,   650,   125,   502,   500,
      81,   500,   507,   462,   500,   469,   501,   500,   501,   144,
     470,   501,   503,   740,   501,   471,    96,   210,   766,   112,
     112,   472,   485,    27,    27,   210,    94,   486,   395,    28,
      29,    29,   249,   278,    30,    30,   506,   508,    81,   112,
     195,   534,   509,   510,   519,   159,   409,   532,   518,    32,
     539,   342,   552,   553,   500,   348,   203,   619,   783,   784,
     771,   501,   558,   210,   554,   210,   555,   556,   561,   465,
     730,   571,   340,   278,   278,   616,   602,   604,   411,   500,
     605,   606,   189,   607,   608,   278,   501,    89,   609,   813,
     348,   500,   610,   613,    27,   513,   614,   615,   501,   620,
     621,    29,   500,   622,   623,    30,    32,   625,   451,   501,
     642,   340,    82,   531,   627,   626,   270,   628,   629,    88,
     630,   523,   638,    32,   631,   249,   639,   640,   651,  -210,
     656,   810,   652,   195,   195,   452,   670,   163,   453,   454,
     113,   113,   655,   657,   658,    27,   113,   204,   659,   113,
      28,    27,    29,    93,    94,   641,    30,   249,    29,   671,
     577,   418,    30,   673,   674,   675,   676,   249,   195,   113,
     113,   404,   -45,   677,   678,   249,   249,   249,   112,   112,
     112,   203,   270,   219,   679,   487,   112,   680,   681,    71,
     488,   112,   691,   112,   682,   693,   224,   112,   112,   112,
     112,   112,   697,   698,   113,   113,   699,   189,   112,   112,
     112,   361,    27,   513,    93,    94,   701,   112,   112,    29,
     710,   709,    27,    30,   113,    94,   711,   712,   719,    29,
     113,   720,   721,    30,   725,   348,   726,    81,   727,   728,
     204,   204,   733,   734,   738,   749,   741,   516,   742,   750,
     348,   348,   348,   348,   348,   751,   348,   348,   348,   195,
     759,   189,   348,   752,   760,   775,   770,   336,   351,  -182,
     516,   348,   348,   348,   763,   204,   525,   525,   525,   525,
     525,   772,   387,   525,   525,   538,   777,   781,   189,   785,
     778,   782,   516,   295,   786,   317,   249,   296,   792,   794,
     722,   367,   318,   319,   795,   320,   723,   804,   805,   808,
     812,   807,   811,   195,   444,   249,   249,   128,   321,   322,
     388,   700,   249,   735,   516,   765,   793,   732,   195,   195,
     195,   195,   195,   736,   195,   371,   754,   443,   716,   489,
     195,   791,   634,   788,   165,   776,   799,   746,   753,   195,
     195,   195,   764,   744,   403,   478,   692,   404,   624,   430,
     312,   463,   112,   113,   113,   113,   204,   317,   761,   737,
     814,   113,   797,   408,   318,   319,   113,   320,   113,     0,
     683,     0,   113,   113,   113,   113,   113,     0,   331,     0,
     321,   322,   405,   113,   113,   113,     0,     0,   348,   425,
       0,   348,   113,   113,     0,   516,   516,     0,     0,     0,
       0,     0,     0,     0,   249,     0,     0,     0,     0,     0,
     204,   219,     0,   487,     0,     0,   348,   348,   787,     0,
       0,     0,   517,   348,   224,   204,   204,   204,   204,   204,
     124,   204,   204,   204,   160,   161,     0,   204,     0,     0,
     162,   516,   516,   189,   127,   517,   204,   204,   204,     0,
      27,   128,     0,    94,     0,     0,     0,    29,   163,     0,
       0,    30,     0,   249,     0,    81,     0,   517,     0,   195,
       0,     0,    27,   152,    93,    94,   164,    78,   165,    29,
       0,    79,    80,    30,     0,     0,     0,    81,     0,     0,
       0,     0,     0,     0,   195,   195,     0,     0,     0,   517,
       0,   195,     0,   249,   249,   112,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   249,     0,     0,   425,     0,
       0,     0,     0,   451,     0,   348,   408,   408,   408,   408,
     408,   408,   408,     0,     0,   348,   800,   113,     0,     0,
       0,     0,     0,   579,   579,   579,   579,   579,     0,   316,
     452,   525,     0,   453,   454,   592,     0,     0,     0,     0,
      27,   718,   317,     0,     0,    28,     0,    29,     0,   318,
     319,    30,   320,   204,     0,   112,   204,   112,     0,     0,
     517,   517,     0,     0,     0,   321,   322,   323,     0,     0,
       0,     0,     0,     0,   348,     0,   516,   348,     0,     0,
       0,   204,   204,     0,     0,   348,     0,    90,   204,     0,
       0,     0,   516,     0,     0,     0,     0,     0,    91,     0,
       0,     0,     0,   758,     0,     0,   517,   517,   114,   114,
       0,   525,     0,     0,   114,   205,   272,   114,     0,    27,
      92,    93,    94,   348,    78,   348,    29,     0,    79,    80,
      30,     0,   124,     0,    81,     0,     0,   114,   114,     0,
       0,   348,   307,     0,     0,     0,   127,     0,     0,     0,
     308,     0,     0,   128,     0,   195,     0,     0,     0,     0,
       0,     0,     0,   195,     0,     0,     0,   718,     0,     0,
     113,     0,   114,   114,    27,    92,    93,    94,     0,    78,
       0,    29,     0,    79,    80,    30,     0,     0,     0,    81,
     204,     0,   114,     0,     0,     0,     0,   358,   114,     0,
     204,   195,     0,   195,     0,     0,     0,     0,   349,   349,
     317,     0,     0,     0,     0,     0,     0,   318,   319,     0,
     320,   115,   115,     0,     0,     0,     0,   115,   206,     0,
     115,   124,     0,   321,   322,   359,   125,     0,     0,     0,
     113,   126,   113,   349,     0,   127,     0,   150,     0,     0,
     115,   115,   128,     0,     0,     0,     0,   151,     0,   204,
       0,   517,   204,     0,     0,     0,     0,     0,    91,     0,
     204,     0,     0,    27,    92,    93,    94,   517,    78,     0,
      29,   592,    79,    80,    30,   115,   115,     0,    81,    27,
     152,    93,    94,     0,    78,     0,    29,     0,    79,    80,
      30,     0,     0,     0,    81,   115,     0,     0,   204,     0,
     204,   115,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   206,   206,     0,     0,     0,   204,     0,     0,     0,
       0,   114,   114,   114,   205,   272,     0,     0,     0,   114,
       0,     0,     0,     0,   114,     0,   114,     0,     0,     0,
     114,   114,   114,   114,   114,     0,   206,     0,     0,     0,
       0,   114,   114,   114,     0,     0,     0,     0,     0,     0,
     114,   114,   212,   213,     0,   214,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   218,   349,   570,
     571,     0,     0,     0,     0,   572,     0,     0,     0,     0,
     223,     0,     0,   349,   349,   349,   349,   349,     0,   349,
     349,   349,     0,   225,     0,   349,     0,     0,     0,     0,
       0,     0,     0,   544,   349,   349,   349,    27,    92,    93,
      94,     0,    78,     0,    29,     0,    79,    80,    30,     0,
       0,     0,    81,     0,   115,   115,   115,   206,     0,     0,
       0,   150,   115,     0,     0,     0,     0,   115,     0,   115,
       0,    90,     0,   115,   115,   115,   115,   115,     0,     0,
       0,     0,    91,     0,   115,   115,   115,   544,     0,     0,
       0,   116,   116,   115,   115,     0,     0,   116,   207,     0,
     116,     0,     0,    27,    92,    93,    94,     0,    78,     0,
      29,   206,    79,    80,    30,     0,     0,     0,    81,     0,
     116,   116,     0,     0,     0,   114,   206,   206,   206,   206,
     206,     0,   206,   206,   206,     0,     0,     0,   206,     0,
       0,     0,     0,     0,     0,     0,   545,   206,   206,   206,
       0,     0,     0,     0,     0,   116,   116,     0,     0,     0,
       0,   349,     0,     0,   349,   212,   213,     0,   214,     0,
       0,     0,     0,     0,     0,   116,     0,     0,     0,     0,
     218,   116,   570,   571,     0,     0,     0,     0,   660,   349,
     349,   207,   207,   223,     0,     0,   349,     0,   124,     0,
     545,     0,     0,     0,   117,   117,   225,     0,   307,     0,
     117,   208,   127,   117,     0,     0,     0,     0,     0,   128,
      27,    92,    93,    94,   641,    78,   207,    29,     0,    79,
      80,    30,     0,   117,   117,     0,     0,     0,   115,     0,
      27,    92,    93,    94,     0,    78,     0,    29,   151,    79,
      80,    30,     0,     0,     0,    81,     0,     0,     0,    91,
       0,     0,     0,     0,     0,     0,     0,     0,   117,   117,
       0,     0,     0,     0,   206,     0,     0,   206,   114,     0,
      27,   152,    93,    94,     0,    78,     0,    29,   117,    79,
      80,    30,     0,     0,   117,    81,     0,     0,   349,     0,
       0,     0,   206,   206,   208,   208,     0,     0,     0,   206,
       0,     0,     0,     0,   116,   116,   116,   207,     0,     0,
       0,     0,   116,     0,     0,     0,     0,   116,     0,   116,
       0,     0,     0,   116,   116,   116,   116,   116,     0,   208,
       0,     0,     0,     0,   116,   116,   116,     0,   114,     0,
     114,     0,     0,   116,   116,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   349,     0,     0,
     349,   207,     0,     0,     0,     0,     0,     0,   349,     0,
       0,     0,     0,     0,     0,     0,   207,   207,   207,   207,
     207,   115,   207,   207,   207,     0,     0,     0,   207,     0,
       0,     0,     0,     0,     0,     0,     0,   207,   207,   207,
       0,   206,     0,     0,     0,     0,   349,     0,   349,     0,
       0,     0,     0,     0,     0,     0,     0,   117,   117,   117,
     208,     0,     0,     0,     0,   117,     0,     0,     0,     0,
     117,     0,   117,     0,     0,     0,   117,   117,   117,   117,
     117,     0,     0,     0,     0,     0,     0,   117,   117,   117,
       0,   115,     0,   115,     0,     0,   117,   117,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     206,     0,     0,   206,   208,     0,   197,     0,     0,     0,
       0,   206,     0,     0,     0,     0,     0,     0,   116,   208,
     208,   208,   208,   208,     0,   208,   208,   208,     0,     0,
       0,   208,     0,     0,     0,     0,     0,     0,    91,     0,
     208,   208,   208,     0,     0,     0,     0,     0,     0,   206,
     410,   206,     0,     0,   207,     0,     0,   207,     0,    27,
      92,    93,    94,     0,    78,     0,    29,   124,    79,    80,
      30,   160,   161,     0,    81,     0,   427,   341,     0,     0,
     342,   127,   207,   207,     0,   343,     0,     0,   128,   207,
       0,     0,     0,     0,     0,   163,     0,   118,   118,   197,
     197,   531,   532,   118,   209,     0,   118,   533,     0,    27,
      92,    93,    94,   164,    78,   165,    29,     0,    79,    80,
      30,     0,     0,     0,    81,   163,   118,   118,     0,     0,
       0,   117,     0,     0,   197,     0,     0,     0,     0,    27,
      92,    93,    94,   292,    78,     0,    29,     0,    79,    80,
      30,     0,     0,     0,    81,     0,     0,   145,     0,     0,
       0,   118,   118,   199,     0,   145,     0,   208,     0,     0,
     208,   116,     0,     0,     0,    27,    92,    93,    94,     0,
      78,   118,    29,     0,    79,    80,    30,   118,     0,     0,
      81,   207,     0,     0,     0,   208,   208,   350,   209,     0,
       0,     0,   208,     0,     0,   427,     0,     0,     0,     0,
       0,     0,     0,   410,   410,   410,   410,   410,   410,   410,
     145,   145,     0,     0,     0,   197,     0,   573,   573,     0,
     427,   427,   427,   427,   427,     0,     0,     0,     0,     0,
     145,   116,   410,   116,    27,    92,    93,    94,     0,    78,
       0,    29,     0,    79,    80,    30,   199,   199,     0,    81,
     207,     0,     0,   207,     0,     0,     0,     0,     0,     0,
       0,   207,     0,     0,     0,     0,     0,     0,     0,   197,
       0,     0,     0,     0,   117,     0,     0,     0,     0,     0,
       0,   199,     0,     0,   197,   197,   197,   197,   197,     0,
     197,     0,     0,     0,   208,     0,   197,     0,     0,   207,
       0,   207,     0,     0,     0,   197,   197,   197,     0,     0,
     118,   118,   118,   209,     0,     0,     0,     0,   118,     0,
       0,     0,     0,   118,     0,   118,     0,     0,     0,   118,
     118,   118,   118,   118,     0,     0,     0,     0,     0,     0,
     118,   118,   118,     0,   117,     0,   117,     0,     0,   118,
     118,     0,     0,   661,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   208,     0,     0,   208,   209,     0,     0,
     145,     0,   199,     0,   208,     0,     0,     0,     0,     0,
       0,     0,   209,   209,   209,   209,   209,     0,   350,   209,
     209,     0,   145,     0,   209,     0,     0,     0,     0,   145,
     145,   145,     0,   350,   350,   350,     0,     0,   145,   145,
       0,     0,   208,     0,   208,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   199,     0,     0,     0,
       0,     0,     0,     0,     0,   197,     0,     0,     0,     0,
       0,   199,   199,   199,   199,   199,     0,   199,     0,     0,
       0,     0,     0,   199,     0,     0,     0,     0,     0,     0,
     197,   197,   199,   199,   199,     0,     0,   197,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   410,     0,
       0,     0,     0,     0,   387,   212,   213,     0,   214,   215,
     216,   217,     0,     0,   118,   295,     0,   317,   124,   296,
     218,   219,   220,   221,   318,   319,     0,   320,   222,     0,
       0,   351,   127,   223,   224,     0,     0,     0,     0,   128,
     321,   322,   388,     0,     0,     0,   225,     0,     0,   661,
       0,     0,     0,   350,     0,     0,     0,     0,     0,     0,
      27,   152,    93,    94,   164,    78,   165,    29,     0,    79,
      80,    30,     0,   145,     0,    81,     0,     0,   350,   209,
       0,     0,     0,     0,     0,   350,     0,     0,     0,     0,
     212,   213,     0,   214,   215,   216,   217,     0,     0,     0,
       0,     0,     0,   124,     0,   218,   219,   220,   221,     0,
       0,     0,   199,   381,     0,     0,   342,   127,   223,   224,
       0,   382,     0,     0,   128,     0,     0,     0,     0,     0,
       0,   225,     0,     0,     0,     0,     0,   199,   199,     0,
       0,     0,     0,     0,   199,    27,    92,    93,    94,   164,
      78,   165,    29,     0,    79,    80,    30,     0,     0,     0,
      81,   197,     0,     0,     0,     0,     0,   118,   124,   197,
       0,     0,   160,   161,     0,     0,     0,     0,   162,     0,
       0,   351,   127,     0,     0,     0,     0,   209,     0,   128,
       0,     0,     0,     0,     0,     0,   163,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   197,     0,   197,
      27,   152,    93,    94,   164,    78,   165,    29,     0,    79,
      80,    30,     0,     0,     0,    81,     0,   387,   212,   213,
       0,   214,   215,   216,   217,     0,     0,   118,   295,   118,
     317,   124,   296,   218,   219,   220,   221,   318,   319,     0,
     320,   381,     0,     0,   351,   127,   223,   224,     0,   350,
       0,     0,   128,   321,   322,   388,     0,   209,     0,   225,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27,    92,    93,    94,   164,    78,   165,
      29,     0,    79,    80,    30,     0,   145,     0,    81,     0,
       0,     0,     0,     0,     0,   350,     0,   350,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   199,     0,
       0,     0,     0,   387,   212,   213,   199,   214,   215,   216,
     217,     0,     0,     0,   295,     0,   317,   124,   296,   218,
     219,   220,   221,   318,   319,     0,   320,   381,     0,     0,
       0,   127,   223,   224,     0,     0,     0,     0,   128,   321,
     322,   388,     0,     0,   199,   225,   199,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
      92,    93,    94,   164,    78,   165,    29,     0,    79,    80,
      30,     0,   212,   213,    81,   214,   215,   216,   217,     0,
       0,     0,     0,     0,     0,   124,     0,   218,   219,   220,
     221,     0,     0,     0,     0,   381,     0,     0,     0,   127,
     223,   224,     0,   382,     0,     0,   128,     0,     0,     0,
       0,     0,     0,   225,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,    92,    93,
      94,   164,    78,   165,    29,     0,    79,    80,    30,     0,
     212,   213,    81,   214,   215,   216,   217,     0,     0,     0,
       0,     0,     0,   124,     0,   218,   219,   220,   221,     0,
       0,     0,     0,   222,     0,     0,     0,   127,   223,   224,
       0,     0,     0,     0,   128,     0,     0,     0,     0,     0,
       0,   225,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,   152,    93,    94,   164,
      78,   165,    29,     0,    79,    80,    30,     0,   212,   213,
      81,   214,   215,   216,   217,     0,     0,     0,     0,     0,
       0,   124,     0,   218,   219,   220,   221,     0,     0,     0,
       0,   381,     0,     0,     0,   127,   223,   224,     0,     0,
       0,     0,   128,     0,     0,     0,     0,     0,     0,   225,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27,    92,    93,    94,   164,    78,   165,
      29,     0,    79,    80,    30,     0,   212,   213,    81,   214,
     215,   216,   217,     0,     0,     0,     0,     0,     0,   124,
       0,   218,   219,   220,   221,     0,     0,     0,     0,   423,
       0,     0,     0,   127,   223,   224,     0,     0,     0,     0,
     128,     0,     0,     0,     0,     0,     0,   225,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    27,    92,    93,    94,   164,    78,   165,    29,     0,
      79,    80,    30,     0,   212,   213,    81,   214,   215,   216,
     217,     0,     0,     0,     0,     0,     0,   124,     0,   218,
     219,   220,   729,     0,     0,     0,     0,   381,     0,     0,
       0,   127,   223,   224,     0,     0,     0,     0,   128,     0,
       0,     0,     0,     0,     0,   225,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
      92,    93,    94,   164,    78,   165,    29,     0,    79,    80,
      30,     0,   212,   213,    81,   214,   215,   216,   217,     0,
       0,     0,     0,     0,     0,   124,     0,   218,   219,   570,
     571,     0,     0,     0,     0,   578,     0,     0,     0,   127,
     223,   224,     0,     0,     0,   124,     0,     0,     0,   160,
     161,     0,     0,   225,     0,   341,     0,     0,   351,   127,
       0,     0,     0,     0,     0,     0,   128,    27,    92,    93,
      94,   164,    78,   163,    29,     0,    79,    80,    30,     0,
       0,     0,    81,     0,     0,     0,     0,    27,    92,    93,
      94,   164,    78,   165,    29,   124,    79,    80,    30,   160,
     161,     0,    81,     0,     0,   341,     0,     0,     0,   127,
       0,     0,     0,   343,     0,     0,   128,     0,     0,     0,
       0,     0,     0,   163,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,    92,    93,
      94,   164,    78,   165,    29,   124,    79,    80,    30,   160,
     161,     0,    81,     0,     0,   341,     0,     0,     0,   127,
       0,     0,     0,     0,     0,     0,   128,     0,     0,     0,
       0,     0,     0,   163,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,    92,    93,
      94,   164,    78,   165,    29,   124,    79,    80,    30,   160,
     367,     0,    81,     0,     0,   368,     0,     0,     0,   127,
       0,     0,     0,     0,     0,     0,   128,     0,     0,     0,
       0,     0,     0,   163,     0,    71,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,   281,    93,
      94,   164,     0,   165,    29,    72,    73,    74,    30,    75,
      76,     0,    81,     0,    71,     0,     0,     0,     0,     0,
       0,     0,    27,    77,     0,     0,     0,    78,     0,    29,
       0,    79,    80,    30,    72,    73,    74,    81,    75,    76,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    27,    77,     0,     0,     0,    78,     0,    29,     0,
      79,    80,    30,     0,     0,     0,    81
};

static const yytype_int16 yycheck[] =
{
       0,    20,    21,    22,    23,    24,    25,    26,    61,    60,
     300,    60,    20,    21,    67,    23,    24,    25,    26,   335,
      71,    67,    68,   196,    68,   488,   222,    70,    69,   145,
     160,   241,   290,    52,    60,    35,   220,    90,    68,    69,
     362,    60,    68,    69,    52,    71,    65,   145,   286,   504,
      62,   145,    71,    69,    61,   143,   550,    65,    70,   297,
      67,   299,   429,   374,   418,   107,   304,   305,   306,   550,
     356,   357,   358,   359,   360,   429,    22,   125,   126,    27,
     138,   363,   364,    90,    91,   356,   357,   358,   359,   360,
     220,    37,   356,   357,   358,   359,   360,   651,   151,   263,
      61,    27,   305,   306,   188,   417,   418,   419,   420,   421,
     616,    27,   107,   125,   126,   173,    11,   429,   162,    13,
      27,   377,   378,   379,    27,   237,    27,    34,   147,    90,
      25,    22,   286,   145,    14,   161,   162,   129,    18,   147,
     222,    35,    36,   297,   151,   299,   188,   286,    37,    29,
     304,   305,   306,   431,   432,   433,    27,    30,   297,   713,
     299,   249,   154,    34,   248,   304,   305,   306,    59,    58,
     196,   487,   488,    37,   166,    66,   234,   435,    67,    70,
      27,   222,    27,   356,   357,   358,   359,   360,    61,    62,
     151,    13,   222,   188,    58,   221,   222,    14,   314,   315,
     316,    18,   398,    61,    62,   335,   248,   323,   324,    91,
      11,   237,    22,    35,    36,    14,   314,   315,   316,    18,
     314,   315,   316,   777,    25,   323,   324,    13,   392,   323,
     324,   284,   726,    13,   226,   741,   742,   263,   289,   290,
     289,   287,   285,   287,    14,   726,    13,   288,    18,    59,
     303,   507,   294,   248,    13,   710,    66,   287,   288,   307,
      70,   287,   288,   289,   290,    13,   196,    13,    35,    36,
     289,   290,   288,   285,   552,    59,    13,   284,   237,    68,
      69,   300,    66,   539,    13,   292,    70,   279,   400,   401,
     402,   403,   404,   405,   406,   307,   303,   341,    66,   381,
      36,   327,   314,   315,   316,    13,   332,   353,   675,   335,
     237,   323,   324,    36,    37,   341,   335,   429,   629,    12,
      13,   675,    13,   284,   368,    14,    12,    13,   639,    18,
     356,   357,   358,   359,   360,   798,   362,   363,   364,    35,
     381,   423,   368,   488,    35,    36,   376,    13,   374,    35,
      36,   377,   378,   379,    28,   381,    13,   487,   488,   641,
     376,   557,   558,   675,   414,   415,   392,    13,   398,    35,
      36,   160,   413,    13,   400,   401,   402,   403,   404,   405,
     406,   697,   423,   621,   435,    30,   570,   413,   414,   415,
      13,   417,   418,   419,   420,   421,   422,   423,    14,    15,
     430,   531,    18,   429,   286,   431,   432,   433,    14,   435,
     292,    13,    18,    13,   430,   297,   435,   299,   621,    12,
     468,    14,   304,   305,   306,    18,   356,   357,   358,   359,
     360,   220,   451,   363,   364,   721,    29,   759,    13,   761,
     570,   400,   401,   402,   403,   404,   405,   406,    12,    13,
     721,   661,   432,   433,    14,   455,   468,   721,    18,   775,
      27,   487,   488,    11,     0,   511,    27,   621,   487,   488,
     429,    35,    36,   400,   401,   402,   403,   404,   405,   406,
      14,   507,   621,    69,    18,   630,    27,    14,    15,   533,
     572,    18,    27,   638,    27,   640,   578,    14,   287,   288,
     630,    18,   429,    27,    13,   795,   532,   533,   638,    41,
     640,    27,    48,   539,    50,    51,    12,    13,    54,    55,
      56,    57,   812,    27,    22,    27,   552,   557,   558,    27,
      14,   572,   728,    41,    18,   741,   742,   578,     3,    35,
      36,    37,    22,    29,    22,   571,   572,    27,   721,    27,
     695,    22,   578,    14,    22,   700,    14,    18,   703,    11,
      18,    59,    58,   675,    62,   695,    11,   697,    66,    41,
     700,    67,    70,   703,   504,   691,    74,    27,   660,    59,
      60,    59,    60,    30,    27,     3,    66,   376,    66,     6,
      70,    22,    70,   691,   613,   614,   615,   691,    25,    27,
      25,   627,    41,   629,   630,   750,    45,    46,    47,    48,
      25,   630,   638,   639,   640,   641,    59,    60,    27,   638,
     750,   640,    27,    66,    27,    61,    62,    70,    41,   670,
     775,    67,    68,    69,    70,   221,   222,     6,    37,     3,
     693,   430,   787,    67,   670,   775,    22,    27,   674,   675,
      11,    13,    27,   798,    90,    91,    22,   787,    68,    27,
      14,    27,   681,    35,    13,    36,   712,    22,   798,   695,
      74,   697,    13,    36,   700,    35,   695,   703,   697,   691,
      36,   700,    34,   683,   703,    36,   693,   713,   729,   125,
     126,    36,    36,    59,    59,   721,    62,    36,   728,    64,
      66,    66,   288,   729,    70,    70,    35,    35,    74,   145,
      68,   641,    36,    36,    36,   151,   675,    22,    58,   738,
      27,    30,    13,    35,   750,   161,   162,    30,   769,   770,
     738,   750,    27,   759,    36,   761,    36,    36,    36,   621,
     781,    22,   531,   769,   770,    13,    36,    36,   675,   775,
      36,    36,   162,    36,    36,   781,   775,   808,    36,   808,
     196,   787,    36,    27,    59,    60,    27,    27,   787,    36,
      13,    66,   798,    36,    36,    70,   795,    30,    22,   798,
     710,   570,   808,    21,    13,    35,   222,    35,    13,   808,
      11,   721,    58,   812,    30,   381,    22,    27,    13,    58,
      35,   801,    30,   161,   162,    49,    13,    45,    52,    53,
      61,    62,    36,    36,    36,    59,    67,    68,    36,    70,
      64,    59,    66,    61,    62,    63,    70,   413,    66,    30,
     416,    58,    70,    35,    13,    11,    36,   423,   196,    90,
      91,     6,     6,    36,    36,   431,   432,   433,   284,   285,
     286,   287,   288,    20,    36,    22,   292,    30,    13,    22,
      27,   297,    11,   299,    35,    11,    33,   303,   304,   305,
     306,   307,    13,    35,   125,   126,    36,   287,   314,   315,
     316,    15,    59,    60,    61,    62,    36,   323,   324,    66,
      13,    36,    59,    70,   145,    62,    35,    13,    36,    66,
     151,    36,    11,    70,    36,   341,    13,    74,    35,    13,
     161,   162,    36,    11,    13,    35,    13,   353,    13,    13,
     356,   357,   358,   359,   360,    36,   362,   363,   364,   287,
      13,   341,   368,    34,    12,    11,    13,    30,    30,    12,
     376,   377,   378,   379,    34,   196,   356,   357,   358,   359,
     360,    36,     3,   363,   364,   365,    13,    13,   368,    13,
      35,    35,   398,    14,    13,    16,   552,    18,    36,    36,
      21,    22,    23,    24,    22,    26,    27,    36,    36,    11,
      13,    36,    35,   341,   288,   571,   572,    38,    39,    40,
      41,    37,   578,   674,   430,   728,   781,   670,   356,   357,
     358,   359,   360,   675,   362,   196,   712,   287,   651,   335,
     368,   777,   488,   775,    65,   750,   787,   697,   710,   377,
     378,   379,   726,   693,     3,   326,   627,     6,   468,   269,
     126,   303,   468,   284,   285,   286,   287,    16,   717,   681,
     812,   292,   786,   237,    23,    24,   297,    26,   299,    -1,
     613,    -1,   303,   304,   305,   306,   307,    -1,   147,    -1,
      39,    40,    41,   314,   315,   316,    -1,    -1,   504,   263,
      -1,   507,   323,   324,    -1,   511,   512,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   670,    -1,    -1,    -1,    -1,    -1,
     341,    20,    -1,    22,    -1,    -1,   532,   533,    27,    -1,
      -1,    -1,   353,   539,    33,   356,   357,   358,   359,   360,
      17,   362,   363,   364,    21,    22,    -1,   368,    -1,    -1,
      27,   557,   558,   533,    31,   376,   377,   378,   379,    -1,
      59,    38,    -1,    62,    -1,    -1,    -1,    66,    45,    -1,
      -1,    70,    -1,   729,    -1,    74,    -1,   398,    -1,   507,
      -1,    -1,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    -1,    -1,    -1,    74,    -1,    -1,
      -1,    -1,    -1,    -1,   532,   533,    -1,    -1,    -1,   430,
      -1,   539,    -1,   769,   770,   621,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   781,    -1,    -1,   392,    -1,
      -1,    -1,    -1,    22,    -1,   641,   400,   401,   402,   403,
     404,   405,   406,    -1,    -1,   651,    35,   468,    -1,    -1,
      -1,    -1,    -1,   417,   418,   419,   420,   421,    -1,     3,
      49,   641,    -1,    52,    53,   429,    -1,    -1,    -1,    -1,
      59,   651,    16,    -1,    -1,    64,    -1,    66,    -1,    23,
      24,    70,    26,   504,    -1,   691,   507,   693,    -1,    -1,
     511,   512,    -1,    -1,    -1,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,   710,    -1,   712,   713,    -1,    -1,
      -1,   532,   533,    -1,    -1,   721,    -1,    27,   539,    -1,
      -1,    -1,   728,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    -1,   713,    -1,    -1,   557,   558,    61,    62,
      -1,   721,    -1,    -1,    67,    68,    69,    70,    -1,    59,
      60,    61,    62,   759,    64,   761,    66,    -1,    68,    69,
      70,    -1,    17,    -1,    74,    -1,    -1,    90,    91,    -1,
      -1,   777,    27,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      35,    -1,    -1,    38,    -1,   713,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   721,    -1,    -1,    -1,   777,    -1,    -1,
     621,    -1,   125,   126,    59,    60,    61,    62,    -1,    64,
      -1,    66,    -1,    68,    69,    70,    -1,    -1,    -1,    74,
     641,    -1,   145,    -1,    -1,    -1,    -1,     3,   151,    -1,
     651,   759,    -1,   761,    -1,    -1,    -1,    -1,   161,   162,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    -1,
      26,    61,    62,    -1,    -1,    -1,    -1,    67,    68,    -1,
      70,    17,    -1,    39,    40,    41,    22,    -1,    -1,    -1,
     691,    27,   693,   196,    -1,    31,    -1,    17,    -1,    -1,
      90,    91,    38,    -1,    -1,    -1,    -1,    27,    -1,   710,
      -1,   712,   713,    -1,    -1,    -1,    -1,    -1,    38,    -1,
     721,    -1,    -1,    59,    60,    61,    62,   728,    64,    -1,
      66,   675,    68,    69,    70,   125,   126,    -1,    74,    59,
      60,    61,    62,    -1,    64,    -1,    66,    -1,    68,    69,
      70,    -1,    -1,    -1,    74,   145,    -1,    -1,   759,    -1,
     761,   151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   162,    -1,    -1,    -1,   777,    -1,    -1,    -1,
      -1,   284,   285,   286,   287,   288,    -1,    -1,    -1,   292,
      -1,    -1,    -1,    -1,   297,    -1,   299,    -1,    -1,    -1,
     303,   304,   305,   306,   307,    -1,   196,    -1,    -1,    -1,
      -1,   314,   315,   316,    -1,    -1,    -1,    -1,    -1,    -1,
     323,   324,     4,     5,    -1,     7,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,   341,    21,
      22,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,
      32,    -1,    -1,   356,   357,   358,   359,   360,    -1,   362,
     363,   364,    -1,    45,    -1,   368,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   376,   377,   378,   379,    59,    60,    61,
      62,    -1,    64,    -1,    66,    -1,    68,    69,    70,    -1,
      -1,    -1,    74,    -1,   284,   285,   286,   287,    -1,    -1,
      -1,    17,   292,    -1,    -1,    -1,    -1,   297,    -1,   299,
      -1,    27,    -1,   303,   304,   305,   306,   307,    -1,    -1,
      -1,    -1,    38,    -1,   314,   315,   316,   430,    -1,    -1,
      -1,    61,    62,   323,   324,    -1,    -1,    67,    68,    -1,
      70,    -1,    -1,    59,    60,    61,    62,    -1,    64,    -1,
      66,   341,    68,    69,    70,    -1,    -1,    -1,    74,    -1,
      90,    91,    -1,    -1,    -1,   468,   356,   357,   358,   359,
     360,    -1,   362,   363,   364,    -1,    -1,    -1,   368,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   376,   377,   378,   379,
      -1,    -1,    -1,    -1,    -1,   125,   126,    -1,    -1,    -1,
      -1,   504,    -1,    -1,   507,     4,     5,    -1,     7,    -1,
      -1,    -1,    -1,    -1,    -1,   145,    -1,    -1,    -1,    -1,
      19,   151,    21,    22,    -1,    -1,    -1,    -1,    27,   532,
     533,   161,   162,    32,    -1,    -1,   539,    -1,    17,    -1,
     430,    -1,    -1,    -1,    61,    62,    45,    -1,    27,    -1,
      67,    68,    31,    70,    -1,    -1,    -1,    -1,    -1,    38,
      59,    60,    61,    62,    63,    64,   196,    66,    -1,    68,
      69,    70,    -1,    90,    91,    -1,    -1,    -1,   468,    -1,
      59,    60,    61,    62,    -1,    64,    -1,    66,    27,    68,
      69,    70,    -1,    -1,    -1,    74,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,
      -1,    -1,    -1,    -1,   504,    -1,    -1,   507,   621,    -1,
      59,    60,    61,    62,    -1,    64,    -1,    66,   145,    68,
      69,    70,    -1,    -1,   151,    74,    -1,    -1,   641,    -1,
      -1,    -1,   532,   533,   161,   162,    -1,    -1,    -1,   539,
      -1,    -1,    -1,    -1,   284,   285,   286,   287,    -1,    -1,
      -1,    -1,   292,    -1,    -1,    -1,    -1,   297,    -1,   299,
      -1,    -1,    -1,   303,   304,   305,   306,   307,    -1,   196,
      -1,    -1,    -1,    -1,   314,   315,   316,    -1,   691,    -1,
     693,    -1,    -1,   323,   324,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   710,    -1,    -1,
     713,   341,    -1,    -1,    -1,    -1,    -1,    -1,   721,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   356,   357,   358,   359,
     360,   621,   362,   363,   364,    -1,    -1,    -1,   368,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   377,   378,   379,
      -1,   641,    -1,    -1,    -1,    -1,   759,    -1,   761,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,   285,   286,
     287,    -1,    -1,    -1,    -1,   292,    -1,    -1,    -1,    -1,
     297,    -1,   299,    -1,    -1,    -1,   303,   304,   305,   306,
     307,    -1,    -1,    -1,    -1,    -1,    -1,   314,   315,   316,
      -1,   691,    -1,   693,    -1,    -1,   323,   324,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     710,    -1,    -1,   713,   341,    -1,    68,    -1,    -1,    -1,
      -1,   721,    -1,    -1,    -1,    -1,    -1,    -1,   468,   356,
     357,   358,   359,   360,    -1,   362,   363,   364,    -1,    -1,
      -1,   368,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,
     377,   378,   379,    -1,    -1,    -1,    -1,    -1,    -1,   759,
     237,   761,    -1,    -1,   504,    -1,    -1,   507,    -1,    59,
      60,    61,    62,    -1,    64,    -1,    66,    17,    68,    69,
      70,    21,    22,    -1,    74,    -1,   263,    27,    -1,    -1,
      30,    31,   532,   533,    -1,    35,    -1,    -1,    38,   539,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    61,    62,   161,
     162,    21,    22,    67,    68,    -1,    70,    27,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    -1,    -1,    -1,    74,    45,    90,    91,    -1,    -1,
      -1,   468,    -1,    -1,   196,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    27,    64,    -1,    66,    -1,    68,    69,
      70,    -1,    -1,    -1,    74,    -1,    -1,    62,    -1,    -1,
      -1,   125,   126,    68,    -1,    70,    -1,   504,    -1,    -1,
     507,   621,    -1,    -1,    -1,    59,    60,    61,    62,    -1,
      64,   145,    66,    -1,    68,    69,    70,   151,    -1,    -1,
      74,   641,    -1,    -1,    -1,   532,   533,   161,   162,    -1,
      -1,    -1,   539,    -1,    -1,   392,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   400,   401,   402,   403,   404,   405,   406,
     125,   126,    -1,    -1,    -1,   287,    -1,   414,   415,    -1,
     417,   418,   419,   420,   421,    -1,    -1,    -1,    -1,    -1,
     145,   691,   429,   693,    59,    60,    61,    62,    -1,    64,
      -1,    66,    -1,    68,    69,    70,   161,   162,    -1,    74,
     710,    -1,    -1,   713,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   721,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   341,
      -1,    -1,    -1,    -1,   621,    -1,    -1,    -1,    -1,    -1,
      -1,   196,    -1,    -1,   356,   357,   358,   359,   360,    -1,
     362,    -1,    -1,    -1,   641,    -1,   368,    -1,    -1,   759,
      -1,   761,    -1,    -1,    -1,   377,   378,   379,    -1,    -1,
     284,   285,   286,   287,    -1,    -1,    -1,    -1,   292,    -1,
      -1,    -1,    -1,   297,    -1,   299,    -1,    -1,    -1,   303,
     304,   305,   306,   307,    -1,    -1,    -1,    -1,    -1,    -1,
     314,   315,   316,    -1,   691,    -1,   693,    -1,    -1,   323,
     324,    -1,    -1,   550,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   710,    -1,    -1,   713,   341,    -1,    -1,
     285,    -1,   287,    -1,   721,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   356,   357,   358,   359,   360,    -1,   362,   363,
     364,    -1,   307,    -1,   368,    -1,    -1,    -1,    -1,   314,
     315,   316,    -1,   377,   378,   379,    -1,    -1,   323,   324,
      -1,    -1,   759,    -1,   761,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   341,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   507,    -1,    -1,    -1,    -1,
      -1,   356,   357,   358,   359,   360,    -1,   362,    -1,    -1,
      -1,    -1,    -1,   368,    -1,    -1,    -1,    -1,    -1,    -1,
     532,   533,   377,   378,   379,    -1,    -1,   539,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   675,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,     8,
       9,    10,    -1,    -1,   468,    14,    -1,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,    26,    27,    -1,
      -1,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    -1,    -1,    -1,    45,    -1,    -1,   726,
      -1,    -1,    -1,   507,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    -1,   468,    -1,    74,    -1,    -1,   532,   533,
      -1,    -1,    -1,    -1,    -1,   539,    -1,    -1,    -1,    -1,
       4,     5,    -1,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    -1,    19,    20,    21,    22,    -1,
      -1,    -1,   507,    27,    -1,    -1,    30,    31,    32,    33,
      -1,    35,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    -1,    -1,    -1,    -1,    -1,   532,   533,    -1,
      -1,    -1,    -1,    -1,   539,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    69,    70,    -1,    -1,    -1,
      74,   713,    -1,    -1,    -1,    -1,    -1,   621,    17,   721,
      -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    -1,
      -1,    30,    31,    -1,    -1,    -1,    -1,   641,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   759,    -1,   761,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    -1,    -1,    -1,    74,    -1,     3,     4,     5,
      -1,     7,     8,     9,    10,    -1,    -1,   691,    14,   693,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      26,    27,    -1,    -1,    30,    31,    32,    33,    -1,   713,
      -1,    -1,    38,    39,    40,    41,    -1,   721,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    69,    70,    -1,   691,    -1,    74,    -1,
      -1,    -1,    -1,    -1,    -1,   759,    -1,   761,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   713,    -1,
      -1,    -1,    -1,     3,     4,     5,   721,     7,     8,     9,
      10,    -1,    -1,    -1,    14,    -1,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    26,    27,    -1,    -1,
      -1,    31,    32,    33,    -1,    -1,    -1,    -1,    38,    39,
      40,    41,    -1,    -1,   759,    45,   761,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    -1,     4,     5,    74,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    -1,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    31,
      32,    33,    -1,    35,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    70,    -1,
       4,     5,    74,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    -1,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,    33,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    69,    70,    -1,     4,     5,
      74,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    27,    -1,    -1,    -1,    31,    32,    33,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    69,    70,    -1,     4,     5,    74,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      -1,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    27,
      -1,    -1,    -1,    31,    32,    33,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    -1,     4,     5,    74,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    27,    -1,    -1,
      -1,    31,    32,    33,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    -1,     4,     5,    74,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    -1,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    31,
      32,    33,    -1,    -1,    -1,    17,    -1,    -1,    -1,    21,
      22,    -1,    -1,    45,    -1,    27,    -1,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    59,    60,    61,
      62,    63,    64,    45,    66,    -1,    68,    69,    70,    -1,
      -1,    -1,    74,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    17,    68,    69,    70,    21,
      22,    -1,    74,    -1,    -1,    27,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    35,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    17,    68,    69,    70,    21,
      22,    -1,    74,    -1,    -1,    27,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    17,    68,    69,    70,    21,
      22,    -1,    74,    -1,    -1,    27,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    35,    61,
      62,    63,    -1,    65,    66,    42,    43,    44,    70,    46,
      47,    -1,    74,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    -1,    -1,    -1,    64,    -1,    66,
      -1,    68,    69,    70,    42,    43,    44,    74,    46,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    60,    -1,    -1,    -1,    64,    -1,    66,    -1,
      68,    69,    70,    -1,    -1,    -1,    74
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,    76,   299,     0,    48,    50,    51,    54,    55,    56,
      57,    77,    78,    79,    81,    82,    83,    84,    85,   282,
      27,    27,    27,    27,    27,    27,    27,    59,    64,    66,
      70,   293,   294,   293,   294,   298,   293,   293,   293,   293,
      13,    13,    13,   283,   299,    13,    13,    13,    13,    66,
      87,    87,    22,    37,   284,    36,    87,    87,    87,    87,
      28,    13,    13,   285,   293,    13,    30,    13,    13,    13,
      13,    22,    42,    43,    44,    46,    47,    60,    64,    68,
      69,    74,   265,   287,   288,   289,   290,   291,   294,   297,
      27,    38,    60,    61,    62,   209,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   226,   227,   231,
     232,   233,   257,   258,   259,   260,   261,   262,   264,   265,
     294,   295,   296,   297,    17,    22,    27,    31,    38,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   214,   228,   229,   241,   244,    35,    13,   286,   293,
      17,    27,    60,   171,   198,   199,   200,   231,   248,   257,
      21,    22,    27,    45,    63,    65,   135,   136,   137,   138,
     139,   140,   141,   142,   144,   145,   146,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   166,   168,   169,
     171,   183,   184,   185,   190,   197,   239,   240,   241,   244,
     248,   249,   253,   257,   258,   259,   260,   261,   262,   264,
     265,   296,     4,     5,     7,     8,     9,    10,    19,    20,
      21,    22,    27,    32,    33,    45,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    98,    99,   100,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   118,   120,
     121,   124,   126,   128,   129,   130,   131,   132,   133,   134,
     186,   197,   234,   235,   236,   237,   240,   244,   248,   249,
     257,   258,   259,   260,   261,   262,   263,   264,   265,    80,
     201,    35,   287,   292,    27,    27,    27,    27,    27,    11,
      27,   231,    27,   214,   226,    14,    18,   254,   255,   256,
      13,    86,   299,    41,    27,    27,    27,    27,    35,   202,
     230,   202,   228,    86,    41,     3,     3,    16,    23,    24,
      26,    39,    40,    41,   242,    29,   245,    22,   208,   210,
     211,   285,    22,   171,    86,    11,    30,   194,   195,   295,
     296,    27,    30,    35,   136,   167,   169,   170,   257,   259,
     264,    30,   136,    27,    30,    86,    41,     3,     3,    41,
     242,    15,   247,   254,   256,   245,     6,    22,    27,   143,
     144,   151,   153,   265,    22,    25,   238,    27,    27,    27,
     194,    27,    35,    89,   123,   257,   259,     3,    41,    89,
     119,   124,   235,   242,   243,   248,   255,   256,    27,    86,
      41,     3,     6,     3,     6,    41,   242,    96,    98,   103,
     106,   110,   120,   247,   254,   256,   245,    37,    58,    67,
      37,    67,    22,    27,    97,    98,   104,   106,   265,    11,
     238,    27,    27,    27,    86,    13,    35,   231,   201,   220,
     223,   224,   226,   135,    88,   287,   292,    36,   214,   226,
     226,    22,    49,    52,    53,   266,   268,   269,   271,   273,
     274,   293,    36,   233,   225,   226,   225,   225,    13,    35,
      36,    36,    36,   210,   210,   210,   210,   210,   229,   213,
     265,   147,   148,   149,   265,    36,    36,    22,    27,   172,
     173,   174,   176,   177,   179,   181,   237,   250,   251,   252,
     265,   294,   295,    34,    27,    34,    35,    13,    35,    36,
      36,    22,    27,    60,   160,   171,   257,   258,    58,    36,
     142,   144,   150,   153,   157,   169,   142,   142,   142,   142,
     167,    21,    22,    27,   153,   168,   265,   168,   169,    27,
     136,   147,   248,   249,   259,   260,   296,   170,   170,   170,
      27,    34,    13,    35,    36,    36,    36,    22,    27,   113,
     124,    36,    96,    96,    96,    96,    96,    96,    96,    89,
      21,    22,    27,   106,   118,   265,   118,   120,    27,    98,
     126,   126,   129,   126,   126,   126,   101,   102,   265,    89,
      95,    96,    98,   125,   126,   127,   129,   249,   122,   123,
     122,   122,    36,   292,    36,    36,    36,    36,    36,    36,
      36,   266,   267,    27,    27,    27,    13,   280,   299,    30,
      36,    13,    36,    36,   230,    30,    35,    13,    35,    13,
      11,    30,   172,   182,   173,   176,   177,   180,    58,    22,
      27,    63,   153,   184,   191,   192,   193,   196,   170,   161,
     171,    13,    30,   136,   170,    36,    35,    36,    36,    36,
      27,   106,   133,   187,   188,   189,   196,   123,   114,   124,
      13,    30,    89,    35,    13,    11,    36,    36,    36,    36,
      30,    13,    35,   298,   270,   294,   272,   294,   281,   291,
     225,    11,   213,    11,   147,    27,   177,    13,    35,    36,
      37,    36,    36,    37,   177,   147,   177,   178,   168,    36,
      13,    35,    13,    22,   154,   162,   163,   164,   169,    36,
      36,    11,    21,    27,   235,    36,    13,    35,    13,    22,
      89,   115,   116,    36,    11,   101,   125,   267,    13,   275,
     299,    13,    13,   210,   199,   177,   182,   177,   177,    35,
      13,    36,    34,   191,   161,   154,   163,   165,   169,    13,
      12,   246,   142,    34,   187,   114,    89,   116,   117,   246,
      13,   293,    36,   281,   281,    11,   178,    13,    35,   167,
     167,    13,    35,    89,    89,    13,    13,    27,   174,   175,
     177,   165,    36,   117,    36,    22,   276,   276,    27,   179,
      35,   266,   277,   278,    36,    36,   176,    36,    11,   279,
     299,    35,    13,   287,   277
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,    75,    76,    76,    77,    77,    78,    78,    78,    78,
      78,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      86,    87,    87,    88,    88,    88,    89,    89,    89,    89,
      89,    89,    90,    90,    90,    91,    92,    92,    92,    93,
      93,    94,    94,    95,    95,    96,    96,    96,    97,    97,
      98,    98,    98,    98,    99,   100,   101,   101,   102,   103,
     103,   104,   105,   106,   106,   106,   106,   107,   107,   108,
     108,   108,   108,   108,   109,   109,   110,   111,   112,   113,
     113,   114,   114,   115,   115,   116,   117,   117,   118,   118,
     118,   119,   119,   119,   119,   119,   120,   120,   121,   121,
     121,   122,   123,   123,   124,   124,   125,   125,   125,   126,
     127,   128,   128,   128,   129,   129,   130,   130,   131,   131,
     132,   133,   134,   135,   135,   135,   136,   136,   136,   136,
     136,   136,   137,   137,   138,   139,   139,   140,   140,   141,
     141,   142,   142,   142,   143,   143,   144,   144,   144,   144,
     145,   146,   147,   147,   148,   148,   149,   150,   150,   151,
     152,   153,   153,   153,   154,   154,   155,   156,   156,   156,
     156,   157,   158,   158,   159,   160,   160,   161,   161,   162,
     162,   163,   164,   164,   165,   165,   166,   167,   167,   167,
     168,   168,   168,   168,   168,   169,   169,   170,   170,   171,
     171,   172,   172,   173,   173,   173,   174,   175,   175,   175,
     176,   176,   177,   177,   177,   177,   177,   177,   178,   178,
     179,   180,   180,   181,   182,   182,   183,   184,   185,   186,
     186,   187,   187,   188,   188,   189,   190,   190,   191,   191,
     192,   192,   193,   194,   194,   195,   196,   197,   197,   197,
     197,   198,   198,   199,   199,   200,   201,   201,   202,   202,
     202,   203,   203,   204,   205,   205,   206,   206,   207,   207,
     208,   208,   209,   210,   210,   211,   211,   211,   212,   213,
     213,   214,   214,   214,   215,   216,   216,   217,   218,   219,
     220,   220,   221,   221,   222,   223,   223,   224,   224,   225,
     225,   226,   226,   227,   227,   227,   228,   228,   229,   229,
     230,   230,   231,   231,   232,   232,   233,   233,   233,   233,
     234,   234,   234,   235,   235,   236,   236,   236,   237,   237,
     238,   239,   239,   240,   240,   241,   241,   242,   242,   242,
     242,   242,   242,   243,   243,   244,   245,   246,   247,   248,
     248,   249,   249,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   263,   263,
     263,   263,   264,   264,   265,   266,   266,   266,   266,   267,
     267,   268,   268,   269,   270,   271,   272,   273,   274,   275,
     275,   276,   276,   277,   277,   278,   279,   279,   280,   280,
     281,   282,   283,   283,   283,   284,   284,   285,   285,   286,
     287,   287,   287,   288,   288,   288,   288,   288,   288,   289,
     290,   290,   290,   290,   290,   291,   291,   292,   292,   293,
     293,   294,   294,   294,   295,   296,   297,   297,   297,   298,
     299
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
       1,     1,     1,     1,     1,     1,     2,     3,     3,     3,
       3,     1,     1,     1,     1,     6,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     3,     3,     3,     3,
       2,     1,     3,     1,     1,     1,     1,     3,     6,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     4,     1,     1,     1,     1,     4,     1,     4,     1,
       3,     1,     1,     1,     1,     1,     3,     3,     2,     3,
       1,     3,     1,     3,     1,     3,     1,     2,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       3,     1,     1,     8,     1,     8,     1,     1,     5,     2,
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
#line 228 "SyntaxBNF.y"
                    {}
#line 2910 "y.tab.c"
    break;

  case 3: /* TPTP_file: TPTP_file TPTP_input  */
#line 229 "SyntaxBNF.y"
                                           {}
#line 2916 "y.tab.c"
    break;

  case 4: /* TPTP_input: annotated_formula  */
#line 232 "SyntaxBNF.y"
                               {P_PRINT((yyval.pval));}
#line 2922 "y.tab.c"
    break;

  case 5: /* TPTP_input: include  */
#line 233 "SyntaxBNF.y"
                              {P_PRINT((yyval.pval));}
#line 2928 "y.tab.c"
    break;

  case 6: /* annotated_formula: thf_annotated  */
#line 236 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2934 "y.tab.c"
    break;

  case 7: /* annotated_formula: tff_annotated  */
#line 237 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2940 "y.tab.c"
    break;

  case 8: /* annotated_formula: tcf_annotated  */
#line 238 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2946 "y.tab.c"
    break;

  case 9: /* annotated_formula: fof_annotated  */
#line 239 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2952 "y.tab.c"
    break;

  case 10: /* annotated_formula: cnf_annotated  */
#line 240 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2958 "y.tab.c"
    break;

  case 11: /* annotated_formula: tpi_annotated  */
#line 241 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2964 "y.tab.c"
    break;

  case 12: /* tpi_annotated: _LIT_tpi LPAREN name COMMA formula_role COMMA tpi_formula annotations RPAREN PERIOD  */
#line 244 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("tpi_annotated", P_TOKEN("_LIT_tpi ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 2970 "y.tab.c"
    break;

  case 13: /* tpi_formula: fof_formula  */
#line 247 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("tpi_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2976 "y.tab.c"
    break;

  case 14: /* thf_annotated: _LIT_thf LPAREN name COMMA formula_role COMMA thf_formula annotations RPAREN PERIOD  */
#line 250 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("thf_annotated", P_TOKEN("_LIT_thf ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 2982 "y.tab.c"
    break;

  case 15: /* tff_annotated: _LIT_tff LPAREN name COMMA formula_role COMMA tff_formula annotations RPAREN PERIOD  */
#line 253 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("tff_annotated", P_TOKEN("_LIT_tff ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 2988 "y.tab.c"
    break;

  case 16: /* tcf_annotated: _LIT_tcf LPAREN name COMMA formula_role COMMA tcf_formula annotations RPAREN PERIOD  */
#line 256 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("tcf_annotated", P_TOKEN("_LIT_tcf ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 2994 "y.tab.c"
    break;

  case 17: /* fof_annotated: _LIT_fof LPAREN name COMMA formula_role COMMA fof_formula annotations RPAREN PERIOD  */
#line 259 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("fof_annotated", P_TOKEN("_LIT_fof ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 3000 "y.tab.c"
    break;

  case 18: /* cnf_annotated: _LIT_cnf LPAREN name COMMA formula_role COMMA cnf_formula annotations RPAREN PERIOD  */
#line 262 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("cnf_annotated", P_TOKEN("_LIT_cnf ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 3006 "y.tab.c"
    break;

  case 19: /* annotations: COMMA source optional_info  */
#line 265 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("annotations", P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3012 "y.tab.c"
    break;

  case 20: /* annotations: nothing  */
#line 266 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("annotations", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3018 "y.tab.c"
    break;

  case 21: /* formula_role: lower_word  */
#line 269 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("formula_role", P_TOKEN("lower_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3024 "y.tab.c"
    break;

  case 22: /* formula_role: lower_word MINUS general_term  */
#line 270 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("formula_role", P_TOKEN("lower_word ", (yyvsp[-2].ival)), P_TOKEN("MINUS ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3030 "y.tab.c"
    break;

  case 23: /* thf_formula: thf_logic_formula  */
#line 273 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3036 "y.tab.c"
    break;

  case 24: /* thf_formula: thf_atom_typing  */
#line 274 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3042 "y.tab.c"
    break;

  case 25: /* thf_formula: thf_subtype  */
#line 275 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("thf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3048 "y.tab.c"
    break;

  case 26: /* thf_logic_formula: thf_unitary_formula  */
#line 278 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3054 "y.tab.c"
    break;

  case 27: /* thf_logic_formula: thf_unary_formula  */
#line 279 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3060 "y.tab.c"
    break;

  case 28: /* thf_logic_formula: thf_binary_formula  */
#line 280 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3066 "y.tab.c"
    break;

  case 29: /* thf_logic_formula: thf_defined_infix  */
#line 281 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3072 "y.tab.c"
    break;

  case 30: /* thf_logic_formula: thf_definition  */
#line 282 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3078 "y.tab.c"
    break;

  case 31: /* thf_logic_formula: thf_sequent  */
#line 283 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3084 "y.tab.c"
    break;

  case 32: /* thf_binary_formula: thf_binary_pair  */
#line 286 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3090 "y.tab.c"
    break;

  case 33: /* thf_binary_formula: thf_binary_list  */
#line 287 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3096 "y.tab.c"
    break;

  case 34: /* thf_binary_formula: thf_binary_type  */
#line 288 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3102 "y.tab.c"
    break;

  case 35: /* thf_binary_pair: thf_unit_formula nonassoc_connective thf_unit_formula  */
#line 291 "SyntaxBNF.y"
                                                                        {(yyval.pval) = P_BUILD("thf_binary_pair", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3108 "y.tab.c"
    break;

  case 36: /* thf_binary_list: thf_or_formula  */
#line 294 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("thf_binary_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3114 "y.tab.c"
    break;

  case 37: /* thf_binary_list: thf_and_formula  */
#line 295 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_binary_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3120 "y.tab.c"
    break;

  case 38: /* thf_binary_list: thf_apply_formula  */
#line 296 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_binary_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3126 "y.tab.c"
    break;

  case 39: /* thf_or_formula: thf_unit_formula VLINE thf_unit_formula  */
#line 299 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("thf_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3132 "y.tab.c"
    break;

  case 40: /* thf_or_formula: thf_or_formula VLINE thf_unit_formula  */
#line 300 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("thf_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3138 "y.tab.c"
    break;

  case 41: /* thf_and_formula: thf_unit_formula AMPERSAND thf_unit_formula  */
#line 303 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3144 "y.tab.c"
    break;

  case 42: /* thf_and_formula: thf_and_formula AMPERSAND thf_unit_formula  */
#line 304 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3150 "y.tab.c"
    break;

  case 43: /* thf_apply_formula: thf_unit_formula AT_SIGN thf_unit_formula  */
#line 307 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_apply_formula", (yyvsp[-2].pval), P_TOKEN("AT_SIGN ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3156 "y.tab.c"
    break;

  case 44: /* thf_apply_formula: thf_apply_formula AT_SIGN thf_unit_formula  */
#line 308 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_apply_formula", (yyvsp[-2].pval), P_TOKEN("AT_SIGN ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3162 "y.tab.c"
    break;

  case 45: /* thf_unit_formula: thf_unitary_formula  */
#line 311 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3168 "y.tab.c"
    break;

  case 46: /* thf_unit_formula: thf_unary_formula  */
#line 312 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3174 "y.tab.c"
    break;

  case 47: /* thf_unit_formula: thf_defined_infix  */
#line 313 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3180 "y.tab.c"
    break;

  case 48: /* thf_preunit_formula: thf_unitary_formula  */
#line 316 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("thf_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3186 "y.tab.c"
    break;

  case 49: /* thf_preunit_formula: thf_prefix_unary  */
#line 317 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3192 "y.tab.c"
    break;

  case 50: /* thf_unitary_formula: thf_quantified_formula  */
#line 320 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("thf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3198 "y.tab.c"
    break;

  case 51: /* thf_unitary_formula: thf_atomic_formula  */
#line 321 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3204 "y.tab.c"
    break;

  case 52: /* thf_unitary_formula: variable  */
#line 322 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("thf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3210 "y.tab.c"
    break;

  case 53: /* thf_unitary_formula: LPAREN thf_logic_formula RPAREN  */
#line 323 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("thf_unitary_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3216 "y.tab.c"
    break;

  case 54: /* thf_quantified_formula: thf_quantification thf_unit_formula  */
#line 326 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("thf_quantified_formula", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3222 "y.tab.c"
    break;

  case 55: /* thf_quantification: thf_quantifier LBRKT thf_variable_list RBRKT COLON  */
#line 329 "SyntaxBNF.y"
                                                                        {(yyval.pval) = P_BUILD("thf_quantification", (yyvsp[-4].pval), P_TOKEN("LBRKT ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("RBRKT ", (yyvsp[-1].ival)), P_TOKEN("COLON ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL);}
#line 3228 "y.tab.c"
    break;

  case 56: /* thf_variable_list: thf_typed_variable  */
#line 332 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_variable_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3234 "y.tab.c"
    break;

  case 57: /* thf_variable_list: thf_typed_variable COMMA thf_variable_list  */
#line 333 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_variable_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3240 "y.tab.c"
    break;

  case 58: /* thf_typed_variable: variable COLON thf_top_level_type  */
#line 336 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("thf_typed_variable", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3246 "y.tab.c"
    break;

  case 59: /* thf_unary_formula: thf_prefix_unary  */
#line 339 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3252 "y.tab.c"
    break;

  case 60: /* thf_unary_formula: thf_infix_unary  */
#line 340 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3258 "y.tab.c"
    break;

  case 61: /* thf_prefix_unary: thf_unary_connective thf_preunit_formula  */
#line 343 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("thf_prefix_unary", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3264 "y.tab.c"
    break;

  case 62: /* thf_infix_unary: thf_unitary_term infix_inequality thf_unitary_term  */
#line 346 "SyntaxBNF.y"
                                                                     {(yyval.pval) = P_BUILD("thf_infix_unary", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3270 "y.tab.c"
    break;

  case 63: /* thf_atomic_formula: thf_plain_atomic  */
#line 349 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3276 "y.tab.c"
    break;

  case 64: /* thf_atomic_formula: thf_defined_atomic  */
#line 350 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3282 "y.tab.c"
    break;

  case 65: /* thf_atomic_formula: thf_system_atomic  */
#line 351 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3288 "y.tab.c"
    break;

  case 66: /* thf_atomic_formula: thf_fof_function  */
#line 352 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3294 "y.tab.c"
    break;

  case 67: /* thf_plain_atomic: constant  */
#line 355 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("thf_plain_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3300 "y.tab.c"
    break;

  case 68: /* thf_plain_atomic: thf_tuple  */
#line 356 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_plain_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3306 "y.tab.c"
    break;

  case 69: /* thf_defined_atomic: defined_constant  */
#line 359 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3312 "y.tab.c"
    break;

  case 70: /* thf_defined_atomic: thf_defined_term  */
#line 360 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3318 "y.tab.c"
    break;

  case 71: /* thf_defined_atomic: LPAREN thf_conn_term RPAREN  */
#line 361 "SyntaxBNF.y"
                                                  {(yyval.pval) = P_BUILD("thf_defined_atomic", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3324 "y.tab.c"
    break;

  case 72: /* thf_defined_atomic: nhf_long_connective  */
#line 362 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3330 "y.tab.c"
    break;

  case 73: /* thf_defined_atomic: thf_let  */
#line 363 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3336 "y.tab.c"
    break;

  case 74: /* thf_defined_term: defined_term  */
#line 366 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3342 "y.tab.c"
    break;

  case 75: /* thf_defined_term: th1_defined_term  */
#line 367 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3348 "y.tab.c"
    break;

  case 76: /* thf_defined_infix: thf_unitary_term defined_infix_pred thf_unitary_term  */
#line 370 "SyntaxBNF.y"
                                                                         {(yyval.pval) = P_BUILD("thf_defined_infix", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3354 "y.tab.c"
    break;

  case 77: /* thf_system_atomic: system_constant  */
#line 373 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("thf_system_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3360 "y.tab.c"
    break;

  case 78: /* thf_let: _DLR_let LPAREN thf_let_types COMMA thf_let_defns COMMA thf_logic_formula RPAREN  */
#line 376 "SyntaxBNF.y"
                                                                                           {(yyval.pval) = P_BUILD("thf_let", P_TOKEN("_DLR_let ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 3366 "y.tab.c"
    break;

  case 79: /* thf_let_types: thf_atom_typing  */
#line 379 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_let_types", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3372 "y.tab.c"
    break;

  case 80: /* thf_let_types: LBRKT thf_atom_typing_list RBRKT  */
#line 380 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("thf_let_types", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3378 "y.tab.c"
    break;

  case 81: /* thf_atom_typing_list: thf_atom_typing  */
#line 383 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_atom_typing_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3384 "y.tab.c"
    break;

  case 82: /* thf_atom_typing_list: thf_atom_typing COMMA thf_atom_typing_list  */
#line 384 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_atom_typing_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3390 "y.tab.c"
    break;

  case 83: /* thf_let_defns: thf_let_defn  */
#line 387 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("thf_let_defns", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3396 "y.tab.c"
    break;

  case 84: /* thf_let_defns: LBRKT thf_let_defn_list RBRKT  */
#line 388 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("thf_let_defns", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3402 "y.tab.c"
    break;

  case 85: /* thf_let_defn: thf_logic_formula assignment thf_logic_formula  */
#line 391 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_let_defn", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3408 "y.tab.c"
    break;

  case 86: /* thf_let_defn_list: thf_let_defn  */
#line 394 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("thf_let_defn_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3414 "y.tab.c"
    break;

  case 87: /* thf_let_defn_list: thf_let_defn COMMA thf_let_defn_list  */
#line 395 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_let_defn_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3420 "y.tab.c"
    break;

  case 88: /* thf_unitary_term: thf_atomic_formula  */
#line 398 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3426 "y.tab.c"
    break;

  case 89: /* thf_unitary_term: variable  */
#line 399 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("thf_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3432 "y.tab.c"
    break;

  case 90: /* thf_unitary_term: LPAREN thf_logic_formula RPAREN  */
#line 400 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("thf_unitary_term", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3438 "y.tab.c"
    break;

  case 91: /* thf_conn_term: nonassoc_connective  */
#line 403 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3444 "y.tab.c"
    break;

  case 92: /* thf_conn_term: assoc_connective  */
#line 404 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3450 "y.tab.c"
    break;

  case 93: /* thf_conn_term: infix_equality  */
#line 405 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3456 "y.tab.c"
    break;

  case 94: /* thf_conn_term: infix_inequality  */
#line 406 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3462 "y.tab.c"
    break;

  case 95: /* thf_conn_term: thf_unary_connective  */
#line 407 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3468 "y.tab.c"
    break;

  case 96: /* thf_tuple: LBRKT RBRKT  */
#line 410 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("thf_tuple", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3474 "y.tab.c"
    break;

  case 97: /* thf_tuple: LBRKT thf_formula_list RBRKT  */
#line 411 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("thf_tuple", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3480 "y.tab.c"
    break;

  case 98: /* thf_fof_function: defined_functor LPAREN thf_arguments RPAREN  */
#line 414 "SyntaxBNF.y"
                                                               {(yyval.pval) = P_BUILD("thf_fof_function", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3486 "y.tab.c"
    break;

  case 99: /* thf_fof_function: system_functor LPAREN thf_arguments RPAREN  */
#line 415 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_fof_function", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3492 "y.tab.c"
    break;

  case 100: /* thf_fof_function: functor LPAREN thf_arguments RPAREN  */
#line 416 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("thf_fof_function", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3498 "y.tab.c"
    break;

  case 101: /* thf_arguments: thf_formula_list  */
#line 419 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("thf_arguments", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3504 "y.tab.c"
    break;

  case 102: /* thf_formula_list: thf_logic_formula  */
#line 422 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_formula_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3510 "y.tab.c"
    break;

  case 103: /* thf_formula_list: thf_logic_formula COMMA thf_formula_list  */
#line 423 "SyntaxBNF.y"
                                                               {(yyval.pval) = P_BUILD("thf_formula_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3516 "y.tab.c"
    break;

  case 104: /* thf_atom_typing: typeable_atom COLON thf_top_level_type  */
#line 426 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("thf_atom_typing", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3522 "y.tab.c"
    break;

  case 105: /* thf_atom_typing: LPAREN thf_atom_typing RPAREN  */
#line 427 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("thf_atom_typing", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3528 "y.tab.c"
    break;

  case 106: /* thf_top_level_type: thf_unitary_type  */
#line 430 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3534 "y.tab.c"
    break;

  case 107: /* thf_top_level_type: thf_mapping_type  */
#line 431 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3540 "y.tab.c"
    break;

  case 108: /* thf_top_level_type: thf_apply_type  */
#line 432 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3546 "y.tab.c"
    break;

  case 109: /* thf_unitary_type: thf_unitary_formula  */
#line 435 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_unitary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3552 "y.tab.c"
    break;

  case 110: /* thf_apply_type: thf_apply_formula  */
#line 438 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("thf_apply_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3558 "y.tab.c"
    break;

  case 111: /* thf_binary_type: thf_mapping_type  */
#line 441 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("thf_binary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3564 "y.tab.c"
    break;

  case 112: /* thf_binary_type: thf_xprod_type  */
#line 442 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_binary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3570 "y.tab.c"
    break;

  case 113: /* thf_binary_type: thf_union_type  */
#line 443 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_binary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3576 "y.tab.c"
    break;

  case 114: /* thf_mapping_type: thf_unitary_type arrow thf_unitary_type  */
#line 446 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_mapping_type", (yyvsp[-2].pval), P_TOKEN("arrow ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3582 "y.tab.c"
    break;

  case 115: /* thf_mapping_type: thf_unitary_type arrow thf_mapping_type  */
#line 447 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_mapping_type", (yyvsp[-2].pval), P_TOKEN("arrow ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3588 "y.tab.c"
    break;

  case 116: /* thf_xprod_type: thf_unitary_type STAR thf_unitary_type  */
#line 450 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("thf_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3594 "y.tab.c"
    break;

  case 117: /* thf_xprod_type: thf_xprod_type STAR thf_unitary_type  */
#line 451 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3600 "y.tab.c"
    break;

  case 118: /* thf_union_type: thf_unitary_type plus thf_unitary_type  */
#line 454 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("thf_union_type", (yyvsp[-2].pval), P_TOKEN("plus ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3606 "y.tab.c"
    break;

  case 119: /* thf_union_type: thf_union_type plus thf_unitary_type  */
#line 455 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_union_type", (yyvsp[-2].pval), P_TOKEN("plus ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3612 "y.tab.c"
    break;

  case 120: /* thf_subtype: atomic_type subtype_sign atomic_type  */
#line 458 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("thf_subtype", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3618 "y.tab.c"
    break;

  case 121: /* thf_definition: thf_atomic_formula identical thf_logic_formula  */
#line 461 "SyntaxBNF.y"
                                                                {(yyval.pval) = P_BUILD("thf_definition", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3624 "y.tab.c"
    break;

  case 122: /* thf_sequent: thf_tuple gentzen_arrow thf_tuple  */
#line 464 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("thf_sequent", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3630 "y.tab.c"
    break;

  case 123: /* tff_formula: tff_logic_formula  */
#line 467 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3636 "y.tab.c"
    break;

  case 124: /* tff_formula: tff_atom_typing  */
#line 468 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3642 "y.tab.c"
    break;

  case 125: /* tff_formula: tff_subtype  */
#line 469 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tff_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3648 "y.tab.c"
    break;

  case 126: /* tff_logic_formula: tff_unitary_formula  */
#line 472 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3654 "y.tab.c"
    break;

  case 127: /* tff_logic_formula: tff_unary_formula  */
#line 473 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3660 "y.tab.c"
    break;

  case 128: /* tff_logic_formula: tff_binary_formula  */
#line 474 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3666 "y.tab.c"
    break;

  case 129: /* tff_logic_formula: tff_defined_infix  */
#line 475 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3672 "y.tab.c"
    break;

  case 130: /* tff_logic_formula: txf_definition  */
#line 476 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3678 "y.tab.c"
    break;

  case 131: /* tff_logic_formula: txf_sequent  */
#line 477 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3684 "y.tab.c"
    break;

  case 132: /* tff_binary_formula: tff_binary_pair  */
#line 480 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3690 "y.tab.c"
    break;

  case 133: /* tff_binary_formula: tff_binary_list  */
#line 481 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3696 "y.tab.c"
    break;

  case 134: /* tff_binary_pair: tff_unit_formula nonassoc_connective tff_unit_formula  */
#line 484 "SyntaxBNF.y"
                                                                        {(yyval.pval) = P_BUILD("tff_binary_pair", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3702 "y.tab.c"
    break;

  case 135: /* tff_binary_list: tff_or_formula  */
#line 487 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("tff_binary_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3708 "y.tab.c"
    break;

  case 136: /* tff_binary_list: tff_and_formula  */
#line 488 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_binary_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3714 "y.tab.c"
    break;

  case 137: /* tff_or_formula: tff_unit_formula VLINE tff_unit_formula  */
#line 491 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("tff_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3720 "y.tab.c"
    break;

  case 138: /* tff_or_formula: tff_or_formula VLINE tff_unit_formula  */
#line 492 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("tff_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3726 "y.tab.c"
    break;

  case 139: /* tff_and_formula: tff_unit_formula AMPERSAND tff_unit_formula  */
#line 495 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("tff_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3732 "y.tab.c"
    break;

  case 140: /* tff_and_formula: tff_and_formula AMPERSAND tff_unit_formula  */
#line 496 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("tff_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3738 "y.tab.c"
    break;

  case 141: /* tff_unit_formula: tff_unitary_formula  */
#line 499 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3744 "y.tab.c"
    break;

  case 142: /* tff_unit_formula: tff_unary_formula  */
#line 500 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3750 "y.tab.c"
    break;

  case 143: /* tff_unit_formula: tff_defined_infix  */
#line 501 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3756 "y.tab.c"
    break;

  case 144: /* tff_preunit_formula: tff_unitary_formula  */
#line 504 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3762 "y.tab.c"
    break;

  case 145: /* tff_preunit_formula: tff_prefix_unary  */
#line 505 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3768 "y.tab.c"
    break;

  case 146: /* tff_unitary_formula: tff_quantified_formula  */
#line 508 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("tff_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3774 "y.tab.c"
    break;

  case 147: /* tff_unitary_formula: tff_atomic_formula  */
#line 509 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3780 "y.tab.c"
    break;

  case 148: /* tff_unitary_formula: txf_unitary_formula  */
#line 510 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3786 "y.tab.c"
    break;

  case 149: /* tff_unitary_formula: LPAREN tff_logic_formula RPAREN  */
#line 511 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("tff_unitary_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3792 "y.tab.c"
    break;

  case 150: /* txf_unitary_formula: variable  */
#line 514 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("txf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3798 "y.tab.c"
    break;

  case 151: /* tff_quantified_formula: tff_quantifier LBRKT tff_variable_list RBRKT COLON tff_unit_formula  */
#line 517 "SyntaxBNF.y"
                                                                                             {(yyval.pval) = P_BUILD("tff_quantified_formula", (yyvsp[-5].pval), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 3804 "y.tab.c"
    break;

  case 152: /* tff_variable_list: tff_variable  */
#line 520 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("tff_variable_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3810 "y.tab.c"
    break;

  case 153: /* tff_variable_list: tff_variable COMMA tff_variable_list  */
#line 521 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("tff_variable_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3816 "y.tab.c"
    break;

  case 154: /* tff_variable: tff_typed_variable  */
#line 524 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tff_variable", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3822 "y.tab.c"
    break;

  case 155: /* tff_variable: variable  */
#line 525 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_variable", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3828 "y.tab.c"
    break;

  case 156: /* tff_typed_variable: variable COLON tff_atomic_type  */
#line 528 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("tff_typed_variable", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3834 "y.tab.c"
    break;

  case 157: /* tff_unary_formula: tff_prefix_unary  */
#line 531 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3840 "y.tab.c"
    break;

  case 158: /* tff_unary_formula: tff_infix_unary  */
#line 532 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3846 "y.tab.c"
    break;

  case 159: /* tff_prefix_unary: tff_unary_connective tff_preunit_formula  */
#line 535 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("tff_prefix_unary", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3852 "y.tab.c"
    break;

  case 160: /* tff_infix_unary: tff_unitary_term infix_inequality tff_unitary_term  */
#line 538 "SyntaxBNF.y"
                                                                     {(yyval.pval) = P_BUILD("tff_infix_unary", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3858 "y.tab.c"
    break;

  case 161: /* tff_atomic_formula: tff_plain_atomic  */
#line 541 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3864 "y.tab.c"
    break;

  case 162: /* tff_atomic_formula: tff_defined_atomic  */
#line 542 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3870 "y.tab.c"
    break;

  case 163: /* tff_atomic_formula: tff_system_atomic  */
#line 543 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3876 "y.tab.c"
    break;

  case 164: /* tff_plain_atomic: constant  */
#line 546 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("tff_plain_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3882 "y.tab.c"
    break;

  case 165: /* tff_plain_atomic: functor LPAREN tff_arguments RPAREN  */
#line 547 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("tff_plain_atomic", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3888 "y.tab.c"
    break;

  case 166: /* tff_defined_atomic: tff_defined_plain  */
#line 550 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3894 "y.tab.c"
    break;

  case 167: /* tff_defined_plain: defined_constant  */
#line 553 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3900 "y.tab.c"
    break;

  case 168: /* tff_defined_plain: defined_functor LPAREN tff_arguments RPAREN  */
#line 554 "SyntaxBNF.y"
                                                                  {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3906 "y.tab.c"
    break;

  case 169: /* tff_defined_plain: nxf_atom  */
#line 555 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3912 "y.tab.c"
    break;

  case 170: /* tff_defined_plain: txf_let  */
#line 556 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3918 "y.tab.c"
    break;

  case 171: /* tff_defined_infix: tff_unitary_term defined_infix_pred tff_unitary_term  */
#line 559 "SyntaxBNF.y"
                                                                         {(yyval.pval) = P_BUILD("tff_defined_infix", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3924 "y.tab.c"
    break;

  case 172: /* tff_system_atomic: system_constant  */
#line 562 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("tff_system_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3930 "y.tab.c"
    break;

  case 173: /* tff_system_atomic: system_functor LPAREN tff_arguments RPAREN  */
#line 563 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("tff_system_atomic", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3936 "y.tab.c"
    break;

  case 174: /* txf_let: _DLR_let LPAREN txf_let_types COMMA txf_let_defns COMMA tff_term RPAREN  */
#line 566 "SyntaxBNF.y"
                                                                                  {(yyval.pval) = P_BUILD("txf_let", P_TOKEN("_DLR_let ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 3942 "y.tab.c"
    break;

  case 175: /* txf_let_types: tff_atom_typing  */
#line 569 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("txf_let_types", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3948 "y.tab.c"
    break;

  case 176: /* txf_let_types: LBRKT tff_atom_typing_list RBRKT  */
#line 570 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("txf_let_types", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3954 "y.tab.c"
    break;

  case 177: /* tff_atom_typing_list: tff_atom_typing  */
#line 573 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_atom_typing_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3960 "y.tab.c"
    break;

  case 178: /* tff_atom_typing_list: tff_atom_typing COMMA tff_atom_typing_list  */
#line 574 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("tff_atom_typing_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3966 "y.tab.c"
    break;

  case 179: /* txf_let_defns: txf_let_defn  */
#line 577 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("txf_let_defns", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3972 "y.tab.c"
    break;

  case 180: /* txf_let_defns: LBRKT txf_let_defn_list RBRKT  */
#line 578 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("txf_let_defns", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3978 "y.tab.c"
    break;

  case 181: /* txf_let_defn: txf_let_LHS assignment tff_term  */
#line 581 "SyntaxBNF.y"
                                               {(yyval.pval) = P_BUILD("txf_let_defn", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3984 "y.tab.c"
    break;

  case 182: /* txf_let_LHS: tff_plain_atomic  */
#line 584 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("txf_let_LHS", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3990 "y.tab.c"
    break;

  case 183: /* txf_let_LHS: txf_tuple  */
#line 585 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("txf_let_LHS", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3996 "y.tab.c"
    break;

  case 184: /* txf_let_defn_list: txf_let_defn  */
#line 588 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("txf_let_defn_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4002 "y.tab.c"
    break;

  case 185: /* txf_let_defn_list: txf_let_defn COMMA txf_let_defn_list  */
#line 589 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("txf_let_defn_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4008 "y.tab.c"
    break;

  case 186: /* nxf_atom: nxf_long_connective AT_SIGN LPAREN tff_arguments RPAREN  */
#line 592 "SyntaxBNF.y"
                                                                   {(yyval.pval) = P_BUILD("nxf_atom", (yyvsp[-4].pval), P_TOKEN("AT_SIGN ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL);}
#line 4014 "y.tab.c"
    break;

  case 187: /* tff_term: tff_logic_formula  */
#line 595 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("tff_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4020 "y.tab.c"
    break;

  case 188: /* tff_term: defined_term  */
#line 596 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4026 "y.tab.c"
    break;

  case 189: /* tff_term: txf_tuple  */
#line 597 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4032 "y.tab.c"
    break;

  case 190: /* tff_unitary_term: tff_atomic_formula  */
#line 600 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4038 "y.tab.c"
    break;

  case 191: /* tff_unitary_term: defined_term  */
#line 601 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4044 "y.tab.c"
    break;

  case 192: /* tff_unitary_term: txf_tuple  */
#line 602 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4050 "y.tab.c"
    break;

  case 193: /* tff_unitary_term: variable  */
#line 603 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4056 "y.tab.c"
    break;

  case 194: /* tff_unitary_term: LPAREN tff_logic_formula RPAREN  */
#line 604 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("tff_unitary_term", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4062 "y.tab.c"
    break;

  case 195: /* txf_tuple: LBRKT RBRKT  */
#line 607 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("txf_tuple", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4068 "y.tab.c"
    break;

  case 196: /* txf_tuple: LBRKT tff_arguments RBRKT  */
#line 608 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("txf_tuple", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4074 "y.tab.c"
    break;

  case 197: /* tff_arguments: tff_term  */
#line 611 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_arguments", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4080 "y.tab.c"
    break;

  case 198: /* tff_arguments: tff_term COMMA tff_arguments  */
#line 612 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("tff_arguments", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4086 "y.tab.c"
    break;

  case 199: /* tff_atom_typing: typeable_atom COLON tff_top_level_type  */
#line 615 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("tff_atom_typing", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4092 "y.tab.c"
    break;

  case 200: /* tff_atom_typing: LPAREN tff_atom_typing RPAREN  */
#line 616 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("tff_atom_typing", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4098 "y.tab.c"
    break;

  case 201: /* tff_top_level_type: tff_atomic_type  */
#line 619 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4104 "y.tab.c"
    break;

  case 202: /* tff_top_level_type: tff_non_atomic_type  */
#line 620 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4110 "y.tab.c"
    break;

  case 203: /* tff_non_atomic_type: tff_mapping_type  */
#line 623 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_non_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4116 "y.tab.c"
    break;

  case 204: /* tff_non_atomic_type: tf1_quantified_type  */
#line 624 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_non_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4122 "y.tab.c"
    break;

  case 205: /* tff_non_atomic_type: LPAREN tff_non_atomic_type RPAREN  */
#line 625 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("tff_non_atomic_type", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4128 "y.tab.c"
    break;

  case 206: /* tf1_quantified_type: type_quantifier LBRKT tff_variable_list RBRKT COLON tff_monotype  */
#line 628 "SyntaxBNF.y"
                                                                                       {(yyval.pval) = P_BUILD("tf1_quantified_type", (yyvsp[-5].pval), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 4134 "y.tab.c"
    break;

  case 207: /* tff_monotype: tff_atomic_type  */
#line 631 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_monotype", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4140 "y.tab.c"
    break;

  case 208: /* tff_monotype: LPAREN tff_mapping_type RPAREN  */
#line 632 "SyntaxBNF.y"
                                                     {(yyval.pval) = P_BUILD("tff_monotype", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4146 "y.tab.c"
    break;

  case 209: /* tff_monotype: tf1_quantified_type  */
#line 633 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_monotype", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4152 "y.tab.c"
    break;

  case 210: /* tff_unitary_type: tff_atomic_type  */
#line 636 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_unitary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4158 "y.tab.c"
    break;

  case 211: /* tff_unitary_type: LPAREN tff_xprod_type RPAREN  */
#line 637 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("tff_unitary_type", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4164 "y.tab.c"
    break;

  case 212: /* tff_atomic_type: type_constant  */
#line 640 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4170 "y.tab.c"
    break;

  case 213: /* tff_atomic_type: defined_type  */
#line 641 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4176 "y.tab.c"
    break;

  case 214: /* tff_atomic_type: variable  */
#line 642 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4182 "y.tab.c"
    break;

  case 215: /* tff_atomic_type: type_functor LPAREN tff_type_arguments RPAREN  */
#line 643 "SyntaxBNF.y"
                                                                    {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4188 "y.tab.c"
    break;

  case 216: /* tff_atomic_type: LPAREN tff_atomic_type RPAREN  */
#line 644 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("tff_atomic_type", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4194 "y.tab.c"
    break;

  case 217: /* tff_atomic_type: txf_tuple_type  */
#line 645 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4200 "y.tab.c"
    break;

  case 218: /* tff_type_arguments: tff_atomic_type  */
#line 648 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_type_arguments", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4206 "y.tab.c"
    break;

  case 219: /* tff_type_arguments: tff_atomic_type COMMA tff_type_arguments  */
#line 649 "SyntaxBNF.y"
                                                               {(yyval.pval) = P_BUILD("tff_type_arguments", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4212 "y.tab.c"
    break;

  case 220: /* tff_mapping_type: tff_unitary_type arrow tff_atomic_type  */
#line 652 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("tff_mapping_type", (yyvsp[-2].pval), P_TOKEN("arrow ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4218 "y.tab.c"
    break;

  case 221: /* tff_xprod_type: tff_unitary_type STAR tff_atomic_type  */
#line 655 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("tff_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4224 "y.tab.c"
    break;

  case 222: /* tff_xprod_type: tff_xprod_type STAR tff_atomic_type  */
#line 656 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("tff_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4230 "y.tab.c"
    break;

  case 223: /* txf_tuple_type: LBRKT tff_type_list RBRKT  */
#line 659 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("txf_tuple_type", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4236 "y.tab.c"
    break;

  case 224: /* tff_type_list: tff_top_level_type  */
#line 662 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_type_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4242 "y.tab.c"
    break;

  case 225: /* tff_type_list: tff_top_level_type COMMA tff_type_list  */
#line 663 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("tff_type_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4248 "y.tab.c"
    break;

  case 226: /* tff_subtype: atomic_type subtype_sign atomic_type  */
#line 666 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("tff_subtype", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4254 "y.tab.c"
    break;

  case 227: /* txf_definition: tff_atomic_formula identical tff_term  */
#line 669 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("txf_definition", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4260 "y.tab.c"
    break;

  case 228: /* txf_sequent: txf_tuple gentzen_arrow txf_tuple  */
#line 672 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("txf_sequent", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4266 "y.tab.c"
    break;

  case 229: /* nhf_long_connective: LBRACE ntf_connective_name RBRACE  */
#line 675 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("nhf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4272 "y.tab.c"
    break;

  case 230: /* nhf_long_connective: LBRACE ntf_connective_name LPAREN nhf_parameter_list RPAREN RBRACE  */
#line 676 "SyntaxBNF.y"
                                                                                         {(yyval.pval) = P_BUILD("nhf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-5].ival)), (yyvsp[-4].pval), P_TOKEN("LPAREN ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL);}
#line 4278 "y.tab.c"
    break;

  case 231: /* nhf_parameter_list: nhf_parameter  */
#line 679 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("nhf_parameter_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4284 "y.tab.c"
    break;

  case 232: /* nhf_parameter_list: nhf_parameter COMMA nhf_parameter_list  */
#line 680 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("nhf_parameter_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4290 "y.tab.c"
    break;

  case 233: /* nhf_parameter: ntf_index  */
#line 683 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("nhf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4296 "y.tab.c"
    break;

  case 234: /* nhf_parameter: nhf_key_pair  */
#line 684 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("nhf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4302 "y.tab.c"
    break;

  case 235: /* nhf_key_pair: thf_definition  */
#line 687 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("nhf_key_pair", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4308 "y.tab.c"
    break;

  case 236: /* nxf_long_connective: LBRACE ntf_connective_name RBRACE  */
#line 690 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("nxf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4314 "y.tab.c"
    break;

  case 237: /* nxf_long_connective: LBRACE ntf_connective_name LPAREN nxf_parameter_list RPAREN RBRACE  */
#line 691 "SyntaxBNF.y"
                                                                                         {(yyval.pval) = P_BUILD("nxf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-5].ival)), (yyvsp[-4].pval), P_TOKEN("LPAREN ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL);}
#line 4320 "y.tab.c"
    break;

  case 238: /* nxf_parameter_list: nxf_parameter  */
#line 694 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("nxf_parameter_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4326 "y.tab.c"
    break;

  case 239: /* nxf_parameter_list: nxf_parameter COMMA nxf_parameter_list  */
#line 695 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("nxf_parameter_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4332 "y.tab.c"
    break;

  case 240: /* nxf_parameter: ntf_index  */
#line 698 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("nxf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4338 "y.tab.c"
    break;

  case 241: /* nxf_parameter: nxf_key_pair  */
#line 699 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("nxf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4344 "y.tab.c"
    break;

  case 242: /* nxf_key_pair: txf_definition  */
#line 702 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("nxf_key_pair", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4350 "y.tab.c"
    break;

  case 243: /* ntf_connective_name: ntf_defined_connective  */
#line 705 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("ntf_connective_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4356 "y.tab.c"
    break;

  case 244: /* ntf_connective_name: atomic_system_word  */
#line 706 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("ntf_connective_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4362 "y.tab.c"
    break;

  case 245: /* ntf_defined_connective: atomic_defined_word  */
#line 709 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("ntf_defined_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4368 "y.tab.c"
    break;

  case 246: /* ntf_index: hash tff_unitary_term  */
#line 712 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("ntf_index", P_TOKEN("hash ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4374 "y.tab.c"
    break;

  case 247: /* ntf_short_connective: LBRKT PERIOD RBRKT  */
#line 715 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4380 "y.tab.c"
    break;

  case 248: /* ntf_short_connective: less_sign PERIOD arrow  */
#line 716 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("less_sign ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("arrow ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4386 "y.tab.c"
    break;

  case 249: /* ntf_short_connective: LBRACE PERIOD RBRACE  */
#line 717 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("LBRACE ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4392 "y.tab.c"
    break;

  case 250: /* ntf_short_connective: LPAREN PERIOD RPAREN  */
#line 718 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4398 "y.tab.c"
    break;

  case 251: /* tcf_formula: tcf_logic_formula  */
#line 721 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tcf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4404 "y.tab.c"
    break;

  case 252: /* tcf_formula: tff_atom_typing  */
#line 722 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tcf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4410 "y.tab.c"
    break;

  case 253: /* tcf_logic_formula: tcf_quantified_formula  */
#line 725 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("tcf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4416 "y.tab.c"
    break;

  case 254: /* tcf_logic_formula: cnf_formula  */
#line 726 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tcf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4422 "y.tab.c"
    break;

  case 255: /* tcf_quantified_formula: EXCLAMATION LBRKT tff_variable_list RBRKT COLON tcf_logic_formula  */
#line 729 "SyntaxBNF.y"
                                                                                           {(yyval.pval) = P_BUILD("tcf_quantified_formula", P_TOKEN("EXCLAMATION ", (yyvsp[-5].ival)), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 4428 "y.tab.c"
    break;

  case 256: /* fof_formula: fof_logic_formula  */
#line 732 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("fof_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4434 "y.tab.c"
    break;

  case 257: /* fof_formula: fof_sequent  */
#line 733 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("fof_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4440 "y.tab.c"
    break;

  case 258: /* fof_logic_formula: fof_binary_formula  */
#line 736 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("fof_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4446 "y.tab.c"
    break;

  case 259: /* fof_logic_formula: fof_unary_formula  */
#line 737 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("fof_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4452 "y.tab.c"
    break;

  case 260: /* fof_logic_formula: fof_unitary_formula  */
#line 738 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("fof_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4458 "y.tab.c"
    break;

  case 261: /* fof_binary_formula: fof_binary_pair  */
#line 741 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("fof_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4464 "y.tab.c"
    break;

  case 262: /* fof_binary_formula: fof_binary_list  */
#line 742 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("fof_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4470 "y.tab.c"
    break;

  case 263: /* fof_binary_pair: fof_unit_formula nonassoc_connective fof_unit_formula  */
#line 745 "SyntaxBNF.y"
                                                                        {(yyval.pval) = P_BUILD("fof_binary_pair", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4476 "y.tab.c"
    break;

  case 264: /* fof_binary_list: fof_or_formula  */
#line 748 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("fof_binary_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4482 "y.tab.c"
    break;

  case 265: /* fof_binary_list: fof_and_formula  */
#line 749 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("fof_binary_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4488 "y.tab.c"
    break;

  case 266: /* fof_or_formula: fof_unit_formula VLINE fof_unit_formula  */
#line 752 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("fof_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4494 "y.tab.c"
    break;

  case 267: /* fof_or_formula: fof_or_formula VLINE fof_unit_formula  */
#line 753 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("fof_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4500 "y.tab.c"
    break;

  case 268: /* fof_and_formula: fof_unit_formula AMPERSAND fof_unit_formula  */
#line 756 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("fof_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4506 "y.tab.c"
    break;

  case 269: /* fof_and_formula: fof_and_formula AMPERSAND fof_unit_formula  */
#line 757 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("fof_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4512 "y.tab.c"
    break;

  case 270: /* fof_unary_formula: unary_connective fof_unit_formula  */
#line 760 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("fof_unary_formula", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4518 "y.tab.c"
    break;

  case 271: /* fof_unary_formula: fof_infix_unary  */
#line 761 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("fof_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4524 "y.tab.c"
    break;

  case 272: /* fof_infix_unary: fof_term infix_inequality fof_term  */
#line 764 "SyntaxBNF.y"
                                                     {(yyval.pval) = P_BUILD("fof_infix_unary", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4530 "y.tab.c"
    break;

  case 273: /* fof_unit_formula: fof_unitary_formula  */
#line 767 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("fof_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4536 "y.tab.c"
    break;

  case 274: /* fof_unit_formula: fof_unary_formula  */
#line 768 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("fof_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4542 "y.tab.c"
    break;

  case 275: /* fof_unitary_formula: fof_quantified_formula  */
#line 771 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("fof_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4548 "y.tab.c"
    break;

  case 276: /* fof_unitary_formula: fof_atomic_formula  */
#line 772 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("fof_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4554 "y.tab.c"
    break;

  case 277: /* fof_unitary_formula: LPAREN fof_logic_formula RPAREN  */
#line 773 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("fof_unitary_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4560 "y.tab.c"
    break;

  case 278: /* fof_quantified_formula: fof_quantifier LBRKT fof_variable_list RBRKT COLON fof_unit_formula  */
#line 776 "SyntaxBNF.y"
                                                                                             {(yyval.pval) = P_BUILD("fof_quantified_formula", (yyvsp[-5].pval), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 4566 "y.tab.c"
    break;

  case 279: /* fof_variable_list: variable  */
#line 779 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("fof_variable_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4572 "y.tab.c"
    break;

  case 280: /* fof_variable_list: variable COMMA fof_variable_list  */
#line 780 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("fof_variable_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4578 "y.tab.c"
    break;

  case 281: /* fof_atomic_formula: fof_plain_atomic_formula  */
#line 783 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("fof_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4584 "y.tab.c"
    break;

  case 282: /* fof_atomic_formula: fof_defined_atomic_formula  */
#line 784 "SyntaxBNF.y"
                                                 {(yyval.pval) = P_BUILD("fof_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4590 "y.tab.c"
    break;

  case 283: /* fof_atomic_formula: fof_system_atomic_formula  */
#line 785 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("fof_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4596 "y.tab.c"
    break;

  case 284: /* fof_plain_atomic_formula: fof_plain_term  */
#line 788 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("fof_plain_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4602 "y.tab.c"
    break;

  case 285: /* fof_defined_atomic_formula: fof_defined_plain_formula  */
#line 791 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("fof_defined_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4608 "y.tab.c"
    break;

  case 286: /* fof_defined_atomic_formula: fof_defined_infix_formula  */
#line 792 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("fof_defined_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4614 "y.tab.c"
    break;

  case 287: /* fof_defined_plain_formula: fof_defined_plain_term  */
#line 795 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("fof_defined_plain_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4620 "y.tab.c"
    break;

  case 288: /* fof_defined_infix_formula: fof_term defined_infix_pred fof_term  */
#line 798 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("fof_defined_infix_formula", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4626 "y.tab.c"
    break;

  case 289: /* fof_system_atomic_formula: fof_system_term  */
#line 801 "SyntaxBNF.y"
                                            {(yyval.pval) = P_BUILD("fof_system_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4632 "y.tab.c"
    break;

  case 290: /* fof_plain_term: constant  */
#line 804 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("fof_plain_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4638 "y.tab.c"
    break;

  case 291: /* fof_plain_term: functor LPAREN fof_arguments RPAREN  */
#line 805 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("fof_plain_term", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4644 "y.tab.c"
    break;

  case 292: /* fof_defined_term: defined_term  */
#line 808 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("fof_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4650 "y.tab.c"
    break;

  case 293: /* fof_defined_term: fof_defined_atomic_term  */
#line 809 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("fof_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4656 "y.tab.c"
    break;

  case 294: /* fof_defined_atomic_term: fof_defined_plain_term  */
#line 812 "SyntaxBNF.y"
                                                 {(yyval.pval) = P_BUILD("fof_defined_atomic_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4662 "y.tab.c"
    break;

  case 295: /* fof_defined_plain_term: defined_constant  */
#line 815 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("fof_defined_plain_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4668 "y.tab.c"
    break;

  case 296: /* fof_defined_plain_term: defined_functor LPAREN fof_arguments RPAREN  */
#line 816 "SyntaxBNF.y"
                                                                  {(yyval.pval) = P_BUILD("fof_defined_plain_term", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4674 "y.tab.c"
    break;

  case 297: /* fof_system_term: system_constant  */
#line 819 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("fof_system_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4680 "y.tab.c"
    break;

  case 298: /* fof_system_term: system_functor LPAREN fof_arguments RPAREN  */
#line 820 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("fof_system_term", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4686 "y.tab.c"
    break;

  case 299: /* fof_arguments: fof_term  */
#line 823 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("fof_arguments", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4692 "y.tab.c"
    break;

  case 300: /* fof_arguments: fof_term COMMA fof_arguments  */
#line 824 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("fof_arguments", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4698 "y.tab.c"
    break;

  case 301: /* fof_term: fof_function_term  */
#line 827 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("fof_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4704 "y.tab.c"
    break;

  case 302: /* fof_term: variable  */
#line 828 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("fof_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4710 "y.tab.c"
    break;

  case 303: /* fof_function_term: fof_plain_term  */
#line 831 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("fof_function_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4716 "y.tab.c"
    break;

  case 304: /* fof_function_term: fof_defined_term  */
#line 832 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("fof_function_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4722 "y.tab.c"
    break;

  case 305: /* fof_function_term: fof_system_term  */
#line 833 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("fof_function_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4728 "y.tab.c"
    break;

  case 306: /* fof_sequent: fof_formula_tuple gentzen_arrow fof_formula_tuple  */
#line 836 "SyntaxBNF.y"
                                                                {(yyval.pval) = P_BUILD("fof_sequent", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4734 "y.tab.c"
    break;

  case 307: /* fof_sequent: LPAREN fof_sequent RPAREN  */
#line 837 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("fof_sequent", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4740 "y.tab.c"
    break;

  case 308: /* fof_formula_tuple: LBRKT RBRKT  */
#line 840 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("fof_formula_tuple", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4746 "y.tab.c"
    break;

  case 309: /* fof_formula_tuple: LBRKT fof_formula_tuple_list RBRKT  */
#line 841 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("fof_formula_tuple", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4752 "y.tab.c"
    break;

  case 310: /* fof_formula_tuple_list: fof_logic_formula  */
#line 844 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("fof_formula_tuple_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4758 "y.tab.c"
    break;

  case 311: /* fof_formula_tuple_list: fof_logic_formula COMMA fof_formula_tuple_list  */
#line 845 "SyntaxBNF.y"
                                                                     {(yyval.pval) = P_BUILD("fof_formula_tuple_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4764 "y.tab.c"
    break;

  case 312: /* cnf_formula: cnf_disjunction  */
#line 848 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("cnf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4770 "y.tab.c"
    break;

  case 313: /* cnf_formula: LPAREN cnf_formula RPAREN  */
#line 849 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("cnf_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4776 "y.tab.c"
    break;

  case 314: /* cnf_disjunction: cnf_literal  */
#line 852 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("cnf_disjunction", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4782 "y.tab.c"
    break;

  case 315: /* cnf_disjunction: cnf_disjunction VLINE cnf_literal  */
#line 853 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("cnf_disjunction", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4788 "y.tab.c"
    break;

  case 316: /* cnf_literal: fof_atomic_formula  */
#line 856 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("cnf_literal", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4794 "y.tab.c"
    break;

  case 317: /* cnf_literal: TILDE fof_atomic_formula  */
#line 857 "SyntaxBNF.y"
                                               {(yyval.pval) = P_BUILD("cnf_literal", P_TOKEN("TILDE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4800 "y.tab.c"
    break;

  case 318: /* cnf_literal: TILDE LPAREN fof_atomic_formula RPAREN  */
#line 858 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("cnf_literal", P_TOKEN("TILDE ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4806 "y.tab.c"
    break;

  case 319: /* cnf_literal: fof_infix_unary  */
#line 859 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("cnf_literal", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4812 "y.tab.c"
    break;

  case 320: /* thf_quantifier: tff_quantifier  */
#line 862 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4818 "y.tab.c"
    break;

  case 321: /* thf_quantifier: th0_quantifier  */
#line 863 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4824 "y.tab.c"
    break;

  case 322: /* thf_quantifier: type_quantifier  */
#line 864 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4830 "y.tab.c"
    break;

  case 323: /* thf_unary_connective: unary_connective  */
#line 867 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4836 "y.tab.c"
    break;

  case 324: /* thf_unary_connective: ntf_short_connective  */
#line 868 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("thf_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4842 "y.tab.c"
    break;

  case 325: /* th0_quantifier: CARET  */
#line 871 "SyntaxBNF.y"
                       {(yyval.pval) = P_BUILD("th0_quantifier", P_TOKEN("CARET ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4848 "y.tab.c"
    break;

  case 326: /* th0_quantifier: AT_SIGN_PLUS  */
#line 872 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("th0_quantifier", P_TOKEN("AT_SIGN_PLUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4854 "y.tab.c"
    break;

  case 327: /* th0_quantifier: AT_SIGN_MINUS  */
#line 873 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("th0_quantifier", P_TOKEN("AT_SIGN_MINUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4860 "y.tab.c"
    break;

  case 328: /* type_quantifier: EXCLAMATION_GREATER  */
#line 876 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("type_quantifier", P_TOKEN("EXCLAMATION_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4866 "y.tab.c"
    break;

  case 329: /* type_quantifier: QUESTION_STAR  */
#line 877 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("type_quantifier", P_TOKEN("QUESTION_STAR ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4872 "y.tab.c"
    break;

  case 330: /* subtype_sign: LESS_LESS  */
#line 880 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("subtype_sign", P_TOKEN("LESS_LESS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4878 "y.tab.c"
    break;

  case 331: /* tff_unary_connective: unary_connective  */
#line 883 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4884 "y.tab.c"
    break;

  case 332: /* tff_unary_connective: ntf_short_connective  */
#line 884 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("tff_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4890 "y.tab.c"
    break;

  case 333: /* tff_quantifier: fof_quantifier  */
#line 887 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4896 "y.tab.c"
    break;

  case 334: /* tff_quantifier: hash  */
#line 888 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("tff_quantifier", P_TOKEN("hash ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4902 "y.tab.c"
    break;

  case 335: /* fof_quantifier: EXCLAMATION  */
#line 891 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("fof_quantifier", P_TOKEN("EXCLAMATION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4908 "y.tab.c"
    break;

  case 336: /* fof_quantifier: QUESTION  */
#line 892 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("fof_quantifier", P_TOKEN("QUESTION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4914 "y.tab.c"
    break;

  case 337: /* nonassoc_connective: LESS_EQUALS_GREATER  */
#line 895 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("LESS_EQUALS_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4920 "y.tab.c"
    break;

  case 338: /* nonassoc_connective: EQUALS_GREATER  */
#line 896 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("EQUALS_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4926 "y.tab.c"
    break;

  case 339: /* nonassoc_connective: LESS_EQUALS  */
#line 897 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("LESS_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4932 "y.tab.c"
    break;

  case 340: /* nonassoc_connective: LESS_TILDE_GREATER  */
#line 898 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("LESS_TILDE_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4938 "y.tab.c"
    break;

  case 341: /* nonassoc_connective: TILDE_VLINE  */
#line 899 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("TILDE_VLINE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4944 "y.tab.c"
    break;

  case 342: /* nonassoc_connective: TILDE_AMPERSAND  */
#line 900 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("TILDE_AMPERSAND ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4950 "y.tab.c"
    break;

  case 343: /* assoc_connective: VLINE  */
#line 903 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("assoc_connective", P_TOKEN("VLINE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4956 "y.tab.c"
    break;

  case 344: /* assoc_connective: AMPERSAND  */
#line 904 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("assoc_connective", P_TOKEN("AMPERSAND ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4962 "y.tab.c"
    break;

  case 345: /* unary_connective: TILDE  */
#line 907 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("unary_connective", P_TOKEN("TILDE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4968 "y.tab.c"
    break;

  case 346: /* gentzen_arrow: MINUS_MINUS_GREATER  */
#line 910 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("gentzen_arrow", P_TOKEN("MINUS_MINUS_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4974 "y.tab.c"
    break;

  case 347: /* assignment: COLON_EQUALS  */
#line 913 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("assignment", P_TOKEN("COLON_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4980 "y.tab.c"
    break;

  case 348: /* identical: EQUALS_EQUALS  */
#line 916 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("identical", P_TOKEN("EQUALS_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4986 "y.tab.c"
    break;

  case 349: /* typeable_atom: constant  */
#line 919 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("typeable_atom", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4992 "y.tab.c"
    break;

  case 350: /* typeable_atom: distinct_object  */
#line 920 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("typeable_atom", P_TOKEN("distinct_object ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4998 "y.tab.c"
    break;

  case 351: /* atomic_type: typeable_atom  */
#line 923 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5004 "y.tab.c"
    break;

  case 352: /* atomic_type: defined_constant  */
#line 924 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5010 "y.tab.c"
    break;

  case 353: /* atomic_type: system_type  */
#line 925 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5016 "y.tab.c"
    break;

  case 354: /* type_constant: type_functor  */
#line 928 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("type_constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5022 "y.tab.c"
    break;

  case 355: /* type_functor: atomic_word  */
#line 931 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("type_functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5028 "y.tab.c"
    break;

  case 356: /* defined_type: atomic_defined_word  */
#line 934 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("defined_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5034 "y.tab.c"
    break;

  case 357: /* system_type: atomic_system_word  */
#line 937 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("system_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5040 "y.tab.c"
    break;

  case 358: /* defined_infix_pred: infix_equality  */
#line 940 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("defined_infix_pred", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5046 "y.tab.c"
    break;

  case 359: /* infix_equality: EQUALS  */
#line 943 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("infix_equality", P_TOKEN("EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5052 "y.tab.c"
    break;

  case 360: /* infix_inequality: EXCLAMATION_EQUALS  */
#line 946 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("infix_inequality", P_TOKEN("EXCLAMATION_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5058 "y.tab.c"
    break;

  case 361: /* constant: functor  */
#line 949 "SyntaxBNF.y"
                   {(yyval.pval) = P_BUILD("constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5064 "y.tab.c"
    break;

  case 362: /* functor: atomic_word  */
#line 952 "SyntaxBNF.y"
                      {(yyval.pval) = P_BUILD("functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5070 "y.tab.c"
    break;

  case 363: /* defined_constant: defined_functor  */
#line 955 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("defined_constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5076 "y.tab.c"
    break;

  case 364: /* defined_functor: atomic_defined_word  */
#line 958 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("defined_functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5082 "y.tab.c"
    break;

  case 365: /* system_constant: system_functor  */
#line 961 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("system_constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5088 "y.tab.c"
    break;

  case 366: /* system_functor: atomic_system_word  */
#line 964 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("system_functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5094 "y.tab.c"
    break;

  case 367: /* th1_defined_term: EXCLAMATION_EXCLAMATION  */
#line 967 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("EXCLAMATION_EXCLAMATION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5100 "y.tab.c"
    break;

  case 368: /* th1_defined_term: QUESTION_QUESTION  */
#line 968 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("QUESTION_QUESTION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5106 "y.tab.c"
    break;

  case 369: /* th1_defined_term: AT_AT_SIGN_PLUS  */
#line 969 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("AT_AT_SIGN_PLUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5112 "y.tab.c"
    break;

  case 370: /* th1_defined_term: AT_AT_SIGN_MINUS  */
#line 970 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("AT_AT_SIGN_MINUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5118 "y.tab.c"
    break;

  case 371: /* th1_defined_term: AT_SIGN_EQUALS  */
#line 971 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("AT_SIGN_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5124 "y.tab.c"
    break;

  case 372: /* defined_term: number  */
#line 974 "SyntaxBNF.y"
                      {(yyval.pval) = P_BUILD("defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5130 "y.tab.c"
    break;

  case 373: /* defined_term: distinct_object  */
#line 975 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("defined_term", P_TOKEN("distinct_object ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5136 "y.tab.c"
    break;

  case 374: /* variable: upper_word  */
#line 978 "SyntaxBNF.y"
                      {(yyval.pval) = P_BUILD("variable", P_TOKEN("upper_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5142 "y.tab.c"
    break;

  case 375: /* source: dag_source  */
#line 981 "SyntaxBNF.y"
                    {(yyval.pval) = P_BUILD("source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5148 "y.tab.c"
    break;

  case 376: /* source: internal_source  */
#line 982 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5154 "y.tab.c"
    break;

  case 377: /* source: external_source  */
#line 983 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5160 "y.tab.c"
    break;

  case 378: /* source: LBRKT sources RBRKT  */
#line 984 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("source", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5166 "y.tab.c"
    break;

  case 379: /* sources: source  */
#line 987 "SyntaxBNF.y"
                 {(yyval.pval) = P_BUILD("sources", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5172 "y.tab.c"
    break;

  case 380: /* sources: source COMMA sources  */
#line 988 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("sources", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5178 "y.tab.c"
    break;

  case 381: /* dag_source: name  */
#line 991 "SyntaxBNF.y"
                  {(yyval.pval) = P_BUILD("dag_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5184 "y.tab.c"
    break;

  case 382: /* dag_source: inference_record  */
#line 992 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("dag_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5190 "y.tab.c"
    break;

  case 383: /* inference_record: _LIT_inference LPAREN inference_rule COMMA useful_info COMMA parents RPAREN  */
#line 995 "SyntaxBNF.y"
                                                                                               {(yyval.pval) = P_BUILD("inference_record", P_TOKEN("_LIT_inference ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 5196 "y.tab.c"
    break;

  case 384: /* inference_rule: atomic_word  */
#line 998 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("inference_rule", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5202 "y.tab.c"
    break;

  case 385: /* internal_source: _LIT_introduced LPAREN intro_type COMMA useful_info COMMA parents RPAREN  */
#line 1001 "SyntaxBNF.y"
                                                                                           {(yyval.pval) = P_BUILD("internal_source", P_TOKEN("_LIT_introduced ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 5208 "y.tab.c"
    break;

  case 386: /* intro_type: atomic_word  */
#line 1004 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("intro_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5214 "y.tab.c"
    break;

  case 387: /* external_source: file_source  */
#line 1007 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("external_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5220 "y.tab.c"
    break;

  case 388: /* file_source: _LIT_file LPAREN file_name file_info RPAREN  */
#line 1010 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("file_source", P_TOKEN("_LIT_file ", (yyvsp[-4].ival)), P_TOKEN("LPAREN ", (yyvsp[-3].ival)), (yyvsp[-2].pval), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL);}
#line 5226 "y.tab.c"
    break;

  case 389: /* file_info: COMMA name  */
#line 1013 "SyntaxBNF.y"
                       {(yyval.pval) = P_BUILD("file_info", P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5232 "y.tab.c"
    break;

  case 390: /* file_info: nothing  */
#line 1014 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("file_info", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5238 "y.tab.c"
    break;

  case 391: /* parents: LBRKT RBRKT  */
#line 1017 "SyntaxBNF.y"
                      {(yyval.pval) = P_BUILD("parents", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5244 "y.tab.c"
    break;

  case 392: /* parents: LBRKT parent_list RBRKT  */
#line 1018 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("parents", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5250 "y.tab.c"
    break;

  case 393: /* parent_list: parent_info  */
#line 1021 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("parent_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5256 "y.tab.c"
    break;

  case 394: /* parent_list: parent_info COMMA parent_list  */
#line 1022 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("parent_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5262 "y.tab.c"
    break;

  case 395: /* parent_info: source parent_details  */
#line 1025 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("parent_info", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5268 "y.tab.c"
    break;

  case 396: /* parent_details: COLON general_term  */
#line 1028 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("parent_details", P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5274 "y.tab.c"
    break;

  case 397: /* parent_details: nothing  */
#line 1029 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("parent_details", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5280 "y.tab.c"
    break;

  case 398: /* optional_info: COMMA useful_info  */
#line 1032 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("optional_info", P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5286 "y.tab.c"
    break;

  case 399: /* optional_info: nothing  */
#line 1033 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("optional_info", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5292 "y.tab.c"
    break;

  case 400: /* useful_info: general_list  */
#line 1036 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("useful_info", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5298 "y.tab.c"
    break;

  case 401: /* include: _LIT_include LPAREN file_name include_optionals RPAREN PERIOD  */
#line 1039 "SyntaxBNF.y"
                                                                        {(yyval.pval) = P_BUILD("include", P_TOKEN("_LIT_include ", (yyvsp[-5].ival)), P_TOKEN("LPAREN ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL);}
#line 5304 "y.tab.c"
    break;

  case 402: /* include_optionals: nothing  */
#line 1042 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("include_optionals", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5310 "y.tab.c"
    break;

  case 403: /* include_optionals: COMMA formula_selection  */
#line 1043 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("include_optionals", P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5316 "y.tab.c"
    break;

  case 404: /* include_optionals: COMMA formula_selection COMMA space_name  */
#line 1044 "SyntaxBNF.y"
                                                               {(yyval.pval) = P_BUILD("include_optionals", P_TOKEN("COMMA ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5322 "y.tab.c"
    break;

  case 405: /* formula_selection: LBRKT name_list RBRKT  */
#line 1047 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("formula_selection", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5328 "y.tab.c"
    break;

  case 406: /* formula_selection: STAR  */
#line 1048 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("formula_selection", P_TOKEN("STAR ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5334 "y.tab.c"
    break;

  case 407: /* name_list: name  */
#line 1051 "SyntaxBNF.y"
                 {(yyval.pval) = P_BUILD("name_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5340 "y.tab.c"
    break;

  case 408: /* name_list: name COMMA name_list  */
#line 1052 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("name_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5346 "y.tab.c"
    break;

  case 409: /* space_name: name  */
#line 1055 "SyntaxBNF.y"
                  {(yyval.pval) = P_BUILD("space_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5352 "y.tab.c"
    break;

  case 410: /* general_term: general_data  */
#line 1058 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("general_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5358 "y.tab.c"
    break;

  case 411: /* general_term: general_data COLON general_term  */
#line 1059 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("general_term", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5364 "y.tab.c"
    break;

  case 412: /* general_term: general_list  */
#line 1060 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("general_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5370 "y.tab.c"
    break;

  case 413: /* general_data: atomic_word  */
#line 1063 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5376 "y.tab.c"
    break;

  case 414: /* general_data: general_function  */
#line 1064 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5382 "y.tab.c"
    break;

  case 415: /* general_data: variable  */
#line 1065 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5388 "y.tab.c"
    break;

  case 416: /* general_data: number  */
#line 1066 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5394 "y.tab.c"
    break;

  case 417: /* general_data: distinct_object  */
#line 1067 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("general_data", P_TOKEN("distinct_object ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5400 "y.tab.c"
    break;

  case 418: /* general_data: formula_data  */
#line 1068 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5406 "y.tab.c"
    break;

  case 419: /* general_function: atomic_word LPAREN general_terms RPAREN  */
#line 1071 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("general_function", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5412 "y.tab.c"
    break;

  case 420: /* formula_data: _DLR_thf LPAREN thf_formula RPAREN  */
#line 1074 "SyntaxBNF.y"
                                                  {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_thf ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5418 "y.tab.c"
    break;

  case 421: /* formula_data: _DLR_tff LPAREN tff_formula RPAREN  */
#line 1075 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_tff ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5424 "y.tab.c"
    break;

  case 422: /* formula_data: _DLR_fof LPAREN fof_formula RPAREN  */
#line 1076 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_fof ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5430 "y.tab.c"
    break;

  case 423: /* formula_data: _DLR_cnf LPAREN cnf_formula RPAREN  */
#line 1077 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_cnf ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5436 "y.tab.c"
    break;

  case 424: /* formula_data: _DLR_fot LPAREN fof_term RPAREN  */
#line 1078 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_fot ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5442 "y.tab.c"
    break;

  case 425: /* general_list: LBRKT RBRKT  */
#line 1081 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("general_list", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5448 "y.tab.c"
    break;

  case 426: /* general_list: LBRKT general_terms RBRKT  */
#line 1082 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("general_list", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5454 "y.tab.c"
    break;

  case 427: /* general_terms: general_term  */
#line 1085 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("general_terms", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5460 "y.tab.c"
    break;

  case 428: /* general_terms: general_term COMMA general_terms  */
#line 1086 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("general_terms", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5466 "y.tab.c"
    break;

  case 429: /* name: atomic_word  */
#line 1089 "SyntaxBNF.y"
                   {(yyval.pval) = P_BUILD("name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5472 "y.tab.c"
    break;

  case 430: /* name: integer  */
#line 1090 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("name", P_TOKEN("integer ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5478 "y.tab.c"
    break;

  case 431: /* atomic_word: lower_word  */
#line 1093 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("atomic_word", P_TOKEN("lower_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5484 "y.tab.c"
    break;

  case 432: /* atomic_word: single_quoted  */
#line 1094 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("atomic_word", P_TOKEN("single_quoted ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5490 "y.tab.c"
    break;

  case 433: /* atomic_word: back_quoted  */
#line 1095 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("atomic_word", P_TOKEN("back_quoted ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5496 "y.tab.c"
    break;

  case 434: /* atomic_defined_word: dollar_word  */
#line 1098 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("atomic_defined_word", P_TOKEN("dollar_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5502 "y.tab.c"
    break;

  case 435: /* atomic_system_word: dollar_dollar_word  */
#line 1101 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("atomic_system_word", P_TOKEN("dollar_dollar_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5508 "y.tab.c"
    break;

  case 436: /* number: integer  */
#line 1104 "SyntaxBNF.y"
                 {(yyval.pval) = P_BUILD("number", P_TOKEN("integer ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5514 "y.tab.c"
    break;

  case 437: /* number: rational  */
#line 1105 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("number", P_TOKEN("rational ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5520 "y.tab.c"
    break;

  case 438: /* number: real  */
#line 1106 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("number", P_TOKEN("real ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5526 "y.tab.c"
    break;

  case 439: /* file_name: atomic_word  */
#line 1109 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("file_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5532 "y.tab.c"
    break;

  case 440: /* nothing: %empty  */
#line 1112 "SyntaxBNF.y"
          {(yyval.pval) = P_BUILD("nothing",NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5538 "y.tab.c"
    break;


#line 5542 "y.tab.c"

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

