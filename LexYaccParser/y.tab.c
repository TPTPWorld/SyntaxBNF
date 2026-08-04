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
    _LIT_unknown = 313,            /* _LIT_unknown  */
    arrow = 314,                   /* arrow  */
    back_quoted = 315,             /* back_quoted  */
    distinct_object = 316,         /* distinct_object  */
    dollar_dollar_word = 317,      /* dollar_dollar_word  */
    dollar_word = 318,             /* dollar_word  */
    hash = 319,                    /* hash  */
    integer = 320,                 /* integer  */
    less_sign = 321,               /* less_sign  */
    lower_word = 322,              /* lower_word  */
    plus = 323,                    /* plus  */
    rational = 324,                /* rational  */
    real = 325,                    /* real  */
    single_quoted = 326,           /* single_quoted  */
    slash = 327,                   /* slash  */
    slosh = 328,                   /* slosh  */
    unrecognized = 329,            /* unrecognized  */
    upper_word = 330               /* upper_word  */
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
#define _LIT_unknown 313
#define arrow 314
#define back_quoted 315
#define distinct_object 316
#define dollar_dollar_word 317
#define dollar_word 318
#define hash 319
#define integer 320
#define less_sign 321
#define lower_word 322
#define plus 323
#define rational 324
#define real 325
#define single_quoted 326
#define slash 327
#define slosh 328
#define unrecognized 329
#define upper_word 330

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 152 "SyntaxBNF.y"
int ival; double dval; char* sval; void* pval;

#line 427 "y.tab.c"

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
  YYSYMBOL__LIT_unknown = 58,              /* _LIT_unknown  */
  YYSYMBOL_arrow = 59,                     /* arrow  */
  YYSYMBOL_back_quoted = 60,               /* back_quoted  */
  YYSYMBOL_distinct_object = 61,           /* distinct_object  */
  YYSYMBOL_dollar_dollar_word = 62,        /* dollar_dollar_word  */
  YYSYMBOL_dollar_word = 63,               /* dollar_word  */
  YYSYMBOL_hash = 64,                      /* hash  */
  YYSYMBOL_integer = 65,                   /* integer  */
  YYSYMBOL_less_sign = 66,                 /* less_sign  */
  YYSYMBOL_lower_word = 67,                /* lower_word  */
  YYSYMBOL_plus = 68,                      /* plus  */
  YYSYMBOL_rational = 69,                  /* rational  */
  YYSYMBOL_real = 70,                      /* real  */
  YYSYMBOL_single_quoted = 71,             /* single_quoted  */
  YYSYMBOL_slash = 72,                     /* slash  */
  YYSYMBOL_slosh = 73,                     /* slosh  */
  YYSYMBOL_unrecognized = 74,              /* unrecognized  */
  YYSYMBOL_upper_word = 75,                /* upper_word  */
  YYSYMBOL_YYACCEPT = 76,                  /* $accept  */
  YYSYMBOL_TPTP_file = 77,                 /* TPTP_file  */
  YYSYMBOL_TPTP_input = 78,                /* TPTP_input  */
  YYSYMBOL_annotated_formula = 79,         /* annotated_formula  */
  YYSYMBOL_tpi_annotated = 80,             /* tpi_annotated  */
  YYSYMBOL_tpi_formula = 81,               /* tpi_formula  */
  YYSYMBOL_thf_annotated = 82,             /* thf_annotated  */
  YYSYMBOL_tff_annotated = 83,             /* tff_annotated  */
  YYSYMBOL_tcf_annotated = 84,             /* tcf_annotated  */
  YYSYMBOL_fof_annotated = 85,             /* fof_annotated  */
  YYSYMBOL_cnf_annotated = 86,             /* cnf_annotated  */
  YYSYMBOL_annotations = 87,               /* annotations  */
  YYSYMBOL_formula_role = 88,              /* formula_role  */
  YYSYMBOL_thf_formula = 89,               /* thf_formula  */
  YYSYMBOL_thf_logic_formula = 90,         /* thf_logic_formula  */
  YYSYMBOL_thf_binary_formula = 91,        /* thf_binary_formula  */
  YYSYMBOL_thf_binary_nonassoc = 92,       /* thf_binary_nonassoc  */
  YYSYMBOL_thf_binary_assoc = 93,          /* thf_binary_assoc  */
  YYSYMBOL_thf_or_formula = 94,            /* thf_or_formula  */
  YYSYMBOL_thf_and_formula = 95,           /* thf_and_formula  */
  YYSYMBOL_thf_apply_formula = 96,         /* thf_apply_formula  */
  YYSYMBOL_thf_unit_formula = 97,          /* thf_unit_formula  */
  YYSYMBOL_thf_preunit_formula = 98,       /* thf_preunit_formula  */
  YYSYMBOL_thf_unitary_formula = 99,       /* thf_unitary_formula  */
  YYSYMBOL_thf_quantified_formula = 100,   /* thf_quantified_formula  */
  YYSYMBOL_thf_quantification = 101,       /* thf_quantification  */
  YYSYMBOL_thf_variable_list = 102,        /* thf_variable_list  */
  YYSYMBOL_thf_typed_variable = 103,       /* thf_typed_variable  */
  YYSYMBOL_thf_unary_formula = 104,        /* thf_unary_formula  */
  YYSYMBOL_thf_prefix_unary = 105,         /* thf_prefix_unary  */
  YYSYMBOL_thf_infix_unary = 106,          /* thf_infix_unary  */
  YYSYMBOL_thf_atomic_formula = 107,       /* thf_atomic_formula  */
  YYSYMBOL_thf_plain_atomic = 108,         /* thf_plain_atomic  */
  YYSYMBOL_thf_defined_atomic = 109,       /* thf_defined_atomic  */
  YYSYMBOL_thf_defined_term = 110,         /* thf_defined_term  */
  YYSYMBOL_thf_defined_infix = 111,        /* thf_defined_infix  */
  YYSYMBOL_thf_system_atomic = 112,        /* thf_system_atomic  */
  YYSYMBOL_thf_let = 113,                  /* thf_let  */
  YYSYMBOL_thf_let_types = 114,            /* thf_let_types  */
  YYSYMBOL_thf_atom_typing_list = 115,     /* thf_atom_typing_list  */
  YYSYMBOL_thf_let_defns = 116,            /* thf_let_defns  */
  YYSYMBOL_thf_let_defn = 117,             /* thf_let_defn  */
  YYSYMBOL_thf_let_defn_list = 118,        /* thf_let_defn_list  */
  YYSYMBOL_thf_unitary_term = 119,         /* thf_unitary_term  */
  YYSYMBOL_thf_conn_term = 120,            /* thf_conn_term  */
  YYSYMBOL_thf_tuple = 121,                /* thf_tuple  */
  YYSYMBOL_thf_formula_list = 122,         /* thf_formula_list  */
  YYSYMBOL_thf_atom_typing = 123,          /* thf_atom_typing  */
  YYSYMBOL_thf_top_level_type = 124,       /* thf_top_level_type  */
  YYSYMBOL_thf_unitary_type = 125,         /* thf_unitary_type  */
  YYSYMBOL_thf_apply_type = 126,           /* thf_apply_type  */
  YYSYMBOL_thf_binary_type = 127,          /* thf_binary_type  */
  YYSYMBOL_thf_mapping_type = 128,         /* thf_mapping_type  */
  YYSYMBOL_thf_xprod_type = 129,           /* thf_xprod_type  */
  YYSYMBOL_thf_union_type = 130,           /* thf_union_type  */
  YYSYMBOL_thf_subtype = 131,              /* thf_subtype  */
  YYSYMBOL_thf_definition = 132,           /* thf_definition  */
  YYSYMBOL_thf_sequent = 133,              /* thf_sequent  */
  YYSYMBOL_tff_formula = 134,              /* tff_formula  */
  YYSYMBOL_tff_logic_formula = 135,        /* tff_logic_formula  */
  YYSYMBOL_tff_binary_formula = 136,       /* tff_binary_formula  */
  YYSYMBOL_tff_binary_nonassoc = 137,      /* tff_binary_nonassoc  */
  YYSYMBOL_tff_binary_assoc = 138,         /* tff_binary_assoc  */
  YYSYMBOL_tff_or_formula = 139,           /* tff_or_formula  */
  YYSYMBOL_tff_and_formula = 140,          /* tff_and_formula  */
  YYSYMBOL_tff_unit_formula = 141,         /* tff_unit_formula  */
  YYSYMBOL_tff_preunit_formula = 142,      /* tff_preunit_formula  */
  YYSYMBOL_tff_unitary_formula = 143,      /* tff_unitary_formula  */
  YYSYMBOL_txf_unitary_formula = 144,      /* txf_unitary_formula  */
  YYSYMBOL_tff_quantified_formula = 145,   /* tff_quantified_formula  */
  YYSYMBOL_tff_variable_list = 146,        /* tff_variable_list  */
  YYSYMBOL_tff_variable = 147,             /* tff_variable  */
  YYSYMBOL_tff_typed_variable = 148,       /* tff_typed_variable  */
  YYSYMBOL_tff_unary_formula = 149,        /* tff_unary_formula  */
  YYSYMBOL_tff_prefix_unary = 150,         /* tff_prefix_unary  */
  YYSYMBOL_tff_infix_unary = 151,          /* tff_infix_unary  */
  YYSYMBOL_tff_atomic_formula = 152,       /* tff_atomic_formula  */
  YYSYMBOL_tff_plain_atomic = 153,         /* tff_plain_atomic  */
  YYSYMBOL_tff_defined_atomic = 154,       /* tff_defined_atomic  */
  YYSYMBOL_tff_defined_plain = 155,        /* tff_defined_plain  */
  YYSYMBOL_tff_defined_infix = 156,        /* tff_defined_infix  */
  YYSYMBOL_tff_system_atomic = 157,        /* tff_system_atomic  */
  YYSYMBOL_txf_let = 158,                  /* txf_let  */
  YYSYMBOL_txf_let_types = 159,            /* txf_let_types  */
  YYSYMBOL_tff_atom_typing_list = 160,     /* tff_atom_typing_list  */
  YYSYMBOL_txf_let_defns = 161,            /* txf_let_defns  */
  YYSYMBOL_txf_let_defn = 162,             /* txf_let_defn  */
  YYSYMBOL_txf_let_LHS = 163,              /* txf_let_LHS  */
  YYSYMBOL_txf_let_defn_list = 164,        /* txf_let_defn_list  */
  YYSYMBOL_nxf_atom = 165,                 /* nxf_atom  */
  YYSYMBOL_tff_term = 166,                 /* tff_term  */
  YYSYMBOL_tff_unitary_term = 167,         /* tff_unitary_term  */
  YYSYMBOL_txf_tuple = 168,                /* txf_tuple  */
  YYSYMBOL_tff_arguments = 169,            /* tff_arguments  */
  YYSYMBOL_tff_atom_typing = 170,          /* tff_atom_typing  */
  YYSYMBOL_tff_top_level_type = 171,       /* tff_top_level_type  */
  YYSYMBOL_tff_non_atomic_type = 172,      /* tff_non_atomic_type  */
  YYSYMBOL_tf1_quantified_type = 173,      /* tf1_quantified_type  */
  YYSYMBOL_tff_monotype = 174,             /* tff_monotype  */
  YYSYMBOL_tff_unitary_type = 175,         /* tff_unitary_type  */
  YYSYMBOL_tff_atomic_type = 176,          /* tff_atomic_type  */
  YYSYMBOL_tff_type_arguments = 177,       /* tff_type_arguments  */
  YYSYMBOL_tff_mapping_type = 178,         /* tff_mapping_type  */
  YYSYMBOL_tff_xprod_type = 179,           /* tff_xprod_type  */
  YYSYMBOL_txf_tuple_type = 180,           /* txf_tuple_type  */
  YYSYMBOL_tff_type_list = 181,            /* tff_type_list  */
  YYSYMBOL_tff_subtype = 182,              /* tff_subtype  */
  YYSYMBOL_txf_definition = 183,           /* txf_definition  */
  YYSYMBOL_txf_sequent = 184,              /* txf_sequent  */
  YYSYMBOL_nhf_long_connective = 185,      /* nhf_long_connective  */
  YYSYMBOL_nhf_parameter_list = 186,       /* nhf_parameter_list  */
  YYSYMBOL_nhf_parameter = 187,            /* nhf_parameter  */
  YYSYMBOL_nhf_key_pair = 188,             /* nhf_key_pair  */
  YYSYMBOL_nxf_long_connective = 189,      /* nxf_long_connective  */
  YYSYMBOL_nxf_parameter_list = 190,       /* nxf_parameter_list  */
  YYSYMBOL_nxf_parameter = 191,            /* nxf_parameter  */
  YYSYMBOL_nxf_key_pair = 192,             /* nxf_key_pair  */
  YYSYMBOL_ntf_connective_name = 193,      /* ntf_connective_name  */
  YYSYMBOL_ntf_defined_connective = 194,   /* ntf_defined_connective  */
  YYSYMBOL_ntf_index = 195,                /* ntf_index  */
  YYSYMBOL_ntf_short_connective = 196,     /* ntf_short_connective  */
  YYSYMBOL_tcf_formula = 197,              /* tcf_formula  */
  YYSYMBOL_tcf_logic_formula = 198,        /* tcf_logic_formula  */
  YYSYMBOL_tcf_quantified_formula = 199,   /* tcf_quantified_formula  */
  YYSYMBOL_fof_formula = 200,              /* fof_formula  */
  YYSYMBOL_fof_logic_formula = 201,        /* fof_logic_formula  */
  YYSYMBOL_fof_binary_formula = 202,       /* fof_binary_formula  */
  YYSYMBOL_fof_binary_nonassoc = 203,      /* fof_binary_nonassoc  */
  YYSYMBOL_fof_binary_assoc = 204,         /* fof_binary_assoc  */
  YYSYMBOL_fof_or_formula = 205,           /* fof_or_formula  */
  YYSYMBOL_fof_and_formula = 206,          /* fof_and_formula  */
  YYSYMBOL_fof_unary_formula = 207,        /* fof_unary_formula  */
  YYSYMBOL_fof_infix_unary = 208,          /* fof_infix_unary  */
  YYSYMBOL_fof_unit_formula = 209,         /* fof_unit_formula  */
  YYSYMBOL_fof_unitary_formula = 210,      /* fof_unitary_formula  */
  YYSYMBOL_fof_quantified_formula = 211,   /* fof_quantified_formula  */
  YYSYMBOL_fof_variable_list = 212,        /* fof_variable_list  */
  YYSYMBOL_fof_atomic_formula = 213,       /* fof_atomic_formula  */
  YYSYMBOL_fof_plain_atomic_formula = 214, /* fof_plain_atomic_formula  */
  YYSYMBOL_fof_defined_atomic_formula = 215, /* fof_defined_atomic_formula  */
  YYSYMBOL_fof_defined_plain_formula = 216, /* fof_defined_plain_formula  */
  YYSYMBOL_fof_defined_infix_formula = 217, /* fof_defined_infix_formula  */
  YYSYMBOL_fof_system_atomic_formula = 218, /* fof_system_atomic_formula  */
  YYSYMBOL_fof_plain_term = 219,           /* fof_plain_term  */
  YYSYMBOL_fof_defined_term = 220,         /* fof_defined_term  */
  YYSYMBOL_fof_defined_atomic_term = 221,  /* fof_defined_atomic_term  */
  YYSYMBOL_fof_defined_plain_term = 222,   /* fof_defined_plain_term  */
  YYSYMBOL_fof_system_term = 223,          /* fof_system_term  */
  YYSYMBOL_fof_arguments = 224,            /* fof_arguments  */
  YYSYMBOL_fof_term = 225,                 /* fof_term  */
  YYSYMBOL_fof_function_term = 226,        /* fof_function_term  */
  YYSYMBOL_fof_sequent = 227,              /* fof_sequent  */
  YYSYMBOL_fof_formula_tuple = 228,        /* fof_formula_tuple  */
  YYSYMBOL_fof_formula_tuple_list = 229,   /* fof_formula_tuple_list  */
  YYSYMBOL_cnf_formula = 230,              /* cnf_formula  */
  YYSYMBOL_cnf_disjunction = 231,          /* cnf_disjunction  */
  YYSYMBOL_cnf_literal = 232,              /* cnf_literal  */
  YYSYMBOL_thf_quantifier = 233,           /* thf_quantifier  */
  YYSYMBOL_thf_unary_connective = 234,     /* thf_unary_connective  */
  YYSYMBOL_th0_quantifier = 235,           /* th0_quantifier  */
  YYSYMBOL_type_quantifier = 236,          /* type_quantifier  */
  YYSYMBOL_subtype_sign = 237,             /* subtype_sign  */
  YYSYMBOL_tff_unary_connective = 238,     /* tff_unary_connective  */
  YYSYMBOL_tff_quantifier = 239,           /* tff_quantifier  */
  YYSYMBOL_fof_quantifier = 240,           /* fof_quantifier  */
  YYSYMBOL_nonassoc_connective = 241,      /* nonassoc_connective  */
  YYSYMBOL_assoc_connective = 242,         /* assoc_connective  */
  YYSYMBOL_unary_connective = 243,         /* unary_connective  */
  YYSYMBOL_gentzen_arrow = 244,            /* gentzen_arrow  */
  YYSYMBOL_assignment = 245,               /* assignment  */
  YYSYMBOL_identical = 246,                /* identical  */
  YYSYMBOL_typeable_atom = 247,            /* typeable_atom  */
  YYSYMBOL_atomic_type = 248,              /* atomic_type  */
  YYSYMBOL_type_constant = 249,            /* type_constant  */
  YYSYMBOL_type_functor = 250,             /* type_functor  */
  YYSYMBOL_defined_type = 251,             /* defined_type  */
  YYSYMBOL_system_type = 252,              /* system_type  */
  YYSYMBOL_defined_infix_pred = 253,       /* defined_infix_pred  */
  YYSYMBOL_infix_equality = 254,           /* infix_equality  */
  YYSYMBOL_infix_inequality = 255,         /* infix_inequality  */
  YYSYMBOL_constant = 256,                 /* constant  */
  YYSYMBOL_functor = 257,                  /* functor  */
  YYSYMBOL_defined_constant = 258,         /* defined_constant  */
  YYSYMBOL_defined_functor = 259,          /* defined_functor  */
  YYSYMBOL_system_constant = 260,          /* system_constant  */
  YYSYMBOL_system_functor = 261,           /* system_functor  */
  YYSYMBOL_th1_defined_term = 262,         /* th1_defined_term  */
  YYSYMBOL_defined_term = 263,             /* defined_term  */
  YYSYMBOL_variable = 264,                 /* variable  */
  YYSYMBOL_source = 265,                   /* source  */
  YYSYMBOL_sources = 266,                  /* sources  */
  YYSYMBOL_dag_source = 267,               /* dag_source  */
  YYSYMBOL_inference_record = 268,         /* inference_record  */
  YYSYMBOL_inference_rule = 269,           /* inference_rule  */
  YYSYMBOL_internal_source = 270,          /* internal_source  */
  YYSYMBOL_intro_type = 271,               /* intro_type  */
  YYSYMBOL_external_source = 272,          /* external_source  */
  YYSYMBOL_file_source = 273,              /* file_source  */
  YYSYMBOL_file_info = 274,                /* file_info  */
  YYSYMBOL_parents = 275,                  /* parents  */
  YYSYMBOL_parent_list = 276,              /* parent_list  */
  YYSYMBOL_parent_info = 277,              /* parent_info  */
  YYSYMBOL_parent_details = 278,           /* parent_details  */
  YYSYMBOL_optional_info = 279,            /* optional_info  */
  YYSYMBOL_useful_info = 280,              /* useful_info  */
  YYSYMBOL_include = 281,                  /* include  */
  YYSYMBOL_include_optionals = 282,        /* include_optionals  */
  YYSYMBOL_formula_selection = 283,        /* formula_selection  */
  YYSYMBOL_name_list = 284,                /* name_list  */
  YYSYMBOL_space_name = 285,               /* space_name  */
  YYSYMBOL_general_term = 286,             /* general_term  */
  YYSYMBOL_general_data = 287,             /* general_data  */
  YYSYMBOL_general_function = 288,         /* general_function  */
  YYSYMBOL_formula_data = 289,             /* formula_data  */
  YYSYMBOL_general_list = 290,             /* general_list  */
  YYSYMBOL_general_terms = 291,            /* general_terms  */
  YYSYMBOL_name = 292,                     /* name  */
  YYSYMBOL_atomic_word = 293,              /* atomic_word  */
  YYSYMBOL_atomic_defined_word = 294,      /* atomic_defined_word  */
  YYSYMBOL_atomic_system_word = 295,       /* atomic_system_word  */
  YYSYMBOL_number = 296,                   /* number  */
  YYSYMBOL_file_name = 297,                /* file_name  */
  YYSYMBOL_nothing = 298                   /* nothing  */
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
#define YYLAST   3517

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  76
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  223
/* YYNRULES -- Number of rules.  */
#define YYNRULES  436
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  803

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   330


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
      75
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   229,   229,   230,   233,   234,   237,   238,   239,   240,
     241,   242,   245,   248,   251,   254,   257,   260,   263,   266,
     267,   270,   271,   274,   275,   276,   279,   280,   281,   282,
     283,   284,   287,   288,   289,   292,   295,   296,   297,   300,
     301,   304,   305,   308,   309,   312,   313,   314,   317,   318,
     321,   322,   323,   324,   327,   330,   333,   334,   337,   340,
     341,   344,   347,   350,   351,   352,   355,   356,   359,   360,
     361,   362,   363,   366,   367,   370,   373,   376,   379,   380,
     383,   384,   387,   388,   391,   394,   395,   398,   399,   400,
     403,   404,   405,   406,   407,   410,   411,   414,   415,   418,
     419,   422,   423,   424,   427,   430,   433,   434,   435,   438,
     439,   442,   443,   446,   447,   450,   453,   456,   459,   460,
     461,   464,   465,   466,   467,   468,   469,   472,   473,   476,
     479,   480,   483,   484,   487,   488,   491,   492,   493,   496,
     497,   500,   501,   502,   503,   506,   509,   512,   513,   516,
     517,   520,   523,   524,   527,   530,   533,   534,   535,   538,
     539,   542,   545,   546,   547,   548,   551,   554,   555,   558,
     561,   562,   565,   566,   569,   570,   573,   576,   577,   580,
     581,   584,   587,   588,   589,   592,   593,   594,   595,   596,
     599,   600,   603,   604,   607,   608,   611,   612,   615,   616,
     617,   620,   623,   624,   625,   628,   629,   632,   633,   634,
     635,   636,   637,   640,   641,   644,   647,   648,   651,   654,
     655,   658,   661,   664,   667,   668,   671,   672,   675,   676,
     679,   682,   683,   686,   687,   690,   691,   694,   697,   698,
     701,   704,   707,   708,   709,   710,   713,   714,   717,   718,
     721,   724,   725,   728,   729,   730,   733,   734,   737,   740,
     741,   744,   745,   748,   749,   752,   753,   756,   759,   760,
     763,   764,   765,   768,   771,   772,   775,   776,   777,   780,
     783,   784,   787,   790,   793,   796,   797,   800,   801,   804,
     807,   808,   811,   812,   815,   816,   819,   820,   823,   824,
     825,   828,   829,   832,   833,   836,   837,   840,   841,   844,
     845,   848,   849,   850,   851,   854,   855,   856,   859,   860,
     863,   864,   865,   868,   869,   872,   875,   876,   879,   880,
     883,   884,   887,   888,   889,   890,   891,   892,   895,   896,
     899,   902,   905,   908,   911,   912,   915,   916,   917,   920,
     923,   926,   929,   932,   935,   938,   941,   944,   947,   950,
     953,   956,   959,   960,   961,   962,   963,   966,   967,   970,
     973,   974,   975,   976,   977,   980,   981,   984,   985,   988,
     991,   994,   997,  1000,  1003,  1006,  1007,  1010,  1011,  1014,
    1015,  1018,  1021,  1022,  1025,  1026,  1029,  1032,  1035,  1036,
    1037,  1040,  1041,  1044,  1045,  1048,  1051,  1052,  1053,  1056,
    1057,  1058,  1059,  1060,  1061,  1064,  1067,  1068,  1069,  1070,
    1071,  1074,  1075,  1078,  1079,  1082,  1083,  1086,  1087,  1088,
    1091,  1094,  1097,  1098,  1099,  1102,  1105
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
  "_LIT_unknown", "arrow", "back_quoted", "distinct_object",
  "dollar_dollar_word", "dollar_word", "hash", "integer", "less_sign",
  "lower_word", "plus", "rational", "real", "single_quoted", "slash",
  "slosh", "unrecognized", "upper_word", "$accept", "TPTP_file",
  "TPTP_input", "annotated_formula", "tpi_annotated", "tpi_formula",
  "thf_annotated", "tff_annotated", "tcf_annotated", "fof_annotated",
  "cnf_annotated", "annotations", "formula_role", "thf_formula",
  "thf_logic_formula", "thf_binary_formula", "thf_binary_nonassoc",
  "thf_binary_assoc", "thf_or_formula", "thf_and_formula",
  "thf_apply_formula", "thf_unit_formula", "thf_preunit_formula",
  "thf_unitary_formula", "thf_quantified_formula", "thf_quantification",
  "thf_variable_list", "thf_typed_variable", "thf_unary_formula",
  "thf_prefix_unary", "thf_infix_unary", "thf_atomic_formula",
  "thf_plain_atomic", "thf_defined_atomic", "thf_defined_term",
  "thf_defined_infix", "thf_system_atomic", "thf_let", "thf_let_types",
  "thf_atom_typing_list", "thf_let_defns", "thf_let_defn",
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

#define YYPACT_NINF (-548)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-353)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -548,   443,  -548,  -548,    43,    78,    96,   115,   135,   142,
     144,  -548,  -548,  -548,  -548,  -548,  -548,  -548,  -548,  -548,
     506,   506,   498,   506,   506,   506,   506,  -548,  -548,  -548,
    -548,   147,  -548,   174,  -548,   190,   192,   196,   206,   208,
     164,   164,    87,   197,  -548,   164,   164,   164,   164,   214,
     231,   236,   506,  -548,   251,   241,   269,   278,   283,   290,
    1511,  1674,  2002,   276,   307,   506,  -548,  1576,  3336,  2988,
    2002,  2235,   299,   301,   337,   345,   354,  -548,  -548,  -548,
    -548,  -548,  -548,  -548,   323,  -548,  -548,  -548,   382,  -548,
    1674,  1801,  -548,  -548,  -548,  -548,  -548,  -548,  -548,  -548,
    -548,  -548,   129,  -548,  -548,   176,   279,   385,  -548,   397,
     370,  -548,  -548,   402,  -548,   410,  -548,   415,  -548,  -548,
    -548,  -548,  -548,  -548,  -548,  2299,  2002,  -548,  -548,   397,
    -548,  -548,  -548,  -548,   404,   448,   145,  -548,   805,   372,
    -548,  -548,  -548,   421,   460,  3403,  -548,   506,  -548,  -548,
     468,  2556,   134,  -548,   397,  -548,  -548,  -548,   452,   469,
      64,  2441,  2515,   485,  -548,   486,   397,  -548,  -548,  -548,
    -548,   476,   524,  1051,   418,  -548,  -548,   435,  -548,  -548,
     633,  -548,  -548,  -548,   539,  -548,  -548,  -548,   385,   421,
    -548,  -548,  -548,  -548,   540,  -548,   980,   508,  -548,  -548,
     452,   520,  -548,   191,   530,   542,   557,  -548,   561,  -548,
     458,   565,  -548,  -548,  -548,  -548,  -548,  -548,  -548,  -548,
      64,  2919,  2634,  -548,  -548,   569,   397,  -548,  -548,  -548,
    -548,   556,   595,   602,   997,   693,  -548,  3057,   289,  -548,
    -548,   666,  -548,  -548,  -548,   327,  -548,  -548,   385,   421,
    -548,    70,  -548,  -548,   572,   563,  -548,  -548,  -548,  -548,
    -548,   608,  3126,  -548,  -548,  -548,  -548,   622,   520,   191,
    -548,   542,  -548,  -548,  -548,  -548,  -548,   471,   397,  -548,
    -548,   623,   606,  1674,  2002,  1441,  3336,  2988,  1511,  1511,
     613,  1441,  -548,   631,  -548,  -548,  1441,  -548,  1441,   603,
     617,  -548,  3422,  1441,  1441,  1441,  3403,  -548,   645,   625,
     637,   640,   650,  3403,  3403,  3403,  -548,  -548,  -548,  -548,
    -548,  -548,  3403,  3403,  -548,   667,   592,  -548,  -548,  -548,
    -548,   592,   652,   654,   493,   658,    79,  -548,  -548,  -548,
    2693,   659,  -548,  -548,   680,    86,   661,  -548,  -548,   490,
     662,   663,   522,   641,   665,  3387,  3387,  3387,  3387,  3387,
    -548,  3387,  1322,  1322,   686,   675,   681,  2693,  -548,  -548,
    -548,  -548,  -548,   592,  -548,  1085,  3387,  3387,  3387,    98,
    2781,  -548,   697,   682,  -548,  -548,  -548,  -548,   679,   684,
     688,  3126,  -548,  -548,   622,  -548,  -548,   744,   689,  3057,
    3057,  3057,  3057,  3057,  3057,  3057,  -548,  -548,  -548,   511,
    -548,  -548,  3057,  1270,  1270,   704,  3264,  3264,  3264,  3264,
    3264,   592,  2781,  -548,  -548,  -548,  -548,  -548,  3057,  1085,
     699,  1511,  -548,   700,   702,  -548,  -548,  -548,   705,   710,
     714,  -548,   717,  -548,   718,  -548,  -548,   603,   728,   730,
     731,  -548,   746,  -548,  -548,  -548,  -548,  -548,  -548,   735,
    -548,   732,   756,   736,   737,  3403,  -548,  -548,  -548,   749,
    -548,  -548,  -548,  -548,  -548,  -548,   741,   767,   747,   770,
    -548,   773,  -548,   755,   493,   493,  -548,  -548,  -548,   729,
     734,  -548,  -548,   765,  -548,   763,  -548,  -548,  -548,  -548,
    -548,   902,  -548,  -548,  3387,  -548,  -548,   541,   282,   282,
    -548,   781,  -548,  -548,  -548,   766,  -548,  -548,  -548,   562,
    -548,  -548,  -548,  -548,  -548,  -548,  -548,   189,  3285,  3387,
    -548,  -548,  -548,  -548,  -548,  3387,   759,   771,  -548,  -548,
    -548,  -548,   764,   774,   776,  1785,  -548,  3057,  -548,   609,
    -548,  -548,   300,   300,   788,  -548,   772,  -548,  -548,  -548,
    -548,  -548,  -548,  -548,  -548,   189,  1886,  2850,  -548,  -548,
    -548,  -548,  -548,  2850,  -548,  -548,   748,  -548,  -548,  -548,
    -548,   778,   801,   809,   780,   602,   816,   818,  -548,   748,
    -548,  -548,  -548,   795,  -548,  -548,  -548,  -548,  -548,  -548,
    -548,  -548,   813,   792,   498,   498,   498,   810,  -548,  -548,
    -548,  -548,  1441,  -548,  -548,  -548,  -548,   829,   592,   830,
     592,   447,  -548,   834,   807,   817,    75,   823,   240,   447,
     592,   447,  1322,   845,  -548,   825,   836,  -548,  -548,  -548,
     827,   851,   252,  -548,   833,   835,  -548,   859,  -548,  -548,
    -548,  2020,   845,  -548,   837,   863,  -548,  -548,  -548,   842,
     870,  3195,  -548,   848,   861,   592,  3057,  -548,  -548,   603,
    -548,   875,   876,  -548,   878,  -548,  -548,  -548,  -548,  3403,
    -548,  3442,  -548,   447,  -548,   493,  -548,  -548,   447,  -548,
    -548,   447,  -548,   858,   881,   860,  -548,   864,   902,  -548,
     282,  3285,  -548,   882,  -548,   885,  -548,  -548,  -548,  3387,
     872,   873,  -548,   866,  1785,  -548,   300,  2919,   885,   892,
    -548,  -548,  -548,  -548,  -548,  -548,   506,   880,  -548,   810,
     810,  -548,  -548,   823,  -548,  -548,  -548,   906,   447,  -548,
    -548,  -548,  -548,   908,   905,   886,   463,  3387,  -548,  3387,
    -548,  -548,  -548,  -548,   332,   909,   889,  3057,  3057,  -548,
    -548,   912,   918,   879,  -548,   483,  -548,   896,  -548,  3057,
    -548,  -548,   897,   914,   914,  1103,  -548,  -548,  -548,  -548,
    -548,  -548,  -548,  1170,   898,   901,  1103,   904,  -548,   927,
     913,   928,  -548,  -548,   915,  -548,  1511,  -548,  -548,  -548,
     603,  -548,  -548
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     436,     0,     2,     1,     0,     0,     0,     0,     0,     0,
       0,     3,     4,    11,     6,     7,     8,     9,    10,     5,
       0,     0,     0,     0,     0,     0,     0,   429,   426,   427,
     428,     0,   425,     0,   435,   436,     0,     0,     0,     0,
       0,     0,     0,     0,   398,     0,     0,     0,     0,    21,
       0,     0,     0,   402,   399,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   403,     0,   397,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   413,   432,   433,
     434,   369,   411,    22,   406,   410,   414,   408,   409,   412,
       0,     0,   368,   431,   430,   314,   311,   276,   277,   280,
     281,   278,   279,   299,   288,   282,   284,     0,   296,   436,
     307,   309,   285,   356,   290,   358,   292,   360,   287,   297,
     357,   359,   361,   367,   330,     0,     0,   331,   340,   436,
     251,   253,   256,   257,   259,   260,   269,   266,     0,   268,
     270,   271,   252,     0,     0,     0,   401,     0,   400,   405,
       0,     0,   368,   247,   436,   246,   248,   249,     0,   285,
       0,     0,     0,     0,   329,     0,   436,   118,   123,   127,
     128,   130,   131,     0,   136,   143,   141,   137,   152,   153,
     142,   156,   157,   161,   138,   158,   165,   164,     0,   187,
     119,   120,   125,   126,     0,   327,     0,     0,   328,   326,
     346,     0,   348,   159,   356,   162,   358,   167,   360,   186,
     145,   361,   365,   364,   366,   322,   321,   320,   362,   323,
       0,     0,     0,   363,   324,     0,   436,    23,    28,    32,
      33,    36,    37,    38,     0,    45,    50,     0,    46,    59,
      60,    51,    63,    64,    69,    47,    65,    72,     0,    67,
      24,     0,    34,   106,   107,   108,    25,    30,    31,    71,
     319,     0,     0,   316,   317,   315,   318,   346,     0,    66,
     356,    68,   358,    76,   360,    74,    73,    52,   436,    13,
     421,   423,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   312,     0,   354,   355,     0,   353,     0,     0,
       0,    20,     0,     0,     0,     0,     0,   303,   305,     0,
       0,     0,     0,     0,     0,     0,   333,   334,   332,   335,
     337,   336,     0,     0,   341,     0,     0,   269,   265,   268,
     404,     0,     0,     0,     0,     0,     0,   238,   240,   239,
       0,     0,   190,   182,   192,   184,     0,   159,   162,   183,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     343,     0,     0,     0,     0,     0,     0,     0,   154,   139,
     140,   142,   145,     0,   325,     0,     0,     0,     0,     0,
       0,    95,    97,     0,    66,    68,   339,   338,     0,     0,
       0,    94,    90,    91,     0,    92,    93,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    54,    45,    46,    51,
      47,    67,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    61,    48,    49,    51,    52,     0,     0,
       0,     0,   422,     0,     0,   298,   289,   300,     0,     0,
       0,   407,     0,   308,     0,   283,   267,     0,     0,     0,
       0,   373,   436,   370,   378,   371,   372,   383,   377,     0,
     310,     0,   294,     0,     0,     0,   304,   272,   302,     0,
     262,   264,   263,   261,   258,   301,     0,   274,     0,   147,
     149,   150,   195,     0,     0,     0,   194,   197,   199,     0,
     196,   198,   212,     0,   207,   349,   208,   209,   350,   351,
     244,     0,   231,   242,     0,   191,   245,   144,     0,     0,
     345,     0,   170,   344,   243,     0,   133,   136,   137,   142,
     138,   187,   135,   134,   132,   129,   222,     0,     0,     0,
     185,   166,   188,   155,   223,     0,     0,     0,   346,   221,
     347,   352,     0,     0,     0,     0,   224,     0,    96,    53,
      70,   100,     0,     0,     0,    78,     0,    40,    42,    44,
      41,    43,    39,    35,   116,     0,     0,     0,    87,    75,
      88,    62,   117,     0,   104,   111,   109,   110,   113,   112,
     114,     0,    56,     0,     0,   105,     0,   104,    99,   101,
     103,   102,   115,     0,   424,   419,   418,   420,   417,   416,
     415,   313,   375,     0,     0,     0,     0,     0,    19,   395,
      18,   286,     0,   291,   293,   306,    17,     0,     0,     0,
       0,     0,    16,   219,     0,     0,     0,   205,     0,     0,
       0,     0,     0,     0,   237,     0,   233,   236,   235,   193,
       0,   172,     0,    15,     0,     0,   144,     0,   160,   163,
     168,     0,     0,   230,     0,   226,   229,   228,    98,     0,
      80,     0,    14,     0,     0,     0,     0,    53,    12,     0,
     374,   436,     0,   380,     0,   382,   394,   396,   295,     0,
     275,     0,   148,     0,   151,     0,   218,   200,     0,   211,
     206,     0,   215,     0,   213,     0,   241,     0,     0,   171,
       0,     0,   177,     0,   174,     0,   178,   189,   181,     0,
       0,     0,    94,     0,     0,    79,     0,     0,     0,     0,
      82,    89,    55,    57,    58,   376,     0,     0,   386,     0,
       0,   273,   250,     0,   220,   216,   217,     0,     0,   210,
     232,   234,   173,   156,   179,     0,   184,     0,   342,     0,
     146,   225,   227,    81,    97,    85,     0,     0,     0,   385,
     384,     0,     0,     0,   214,     0,   175,     0,   176,     0,
      83,    84,     0,     0,     0,     0,   204,   201,   202,   180,
     169,    86,    77,     0,     0,     0,     0,     0,   387,   436,
       0,   389,   379,   381,     0,   203,     0,   391,   393,   388,
       0,   392,   390
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -548,  -548,  -548,  -548,  -548,  -548,  -548,  -548,  -548,  -548,
    -548,   -58,   570,   656,    61,  -548,  -548,  -548,  -548,  -548,
    -400,  -115,  -548,  1118,  -548,  -548,   286,  -548,    16,  -190,
    -548,   698,  -548,  -548,  -548,   133,  -548,  -548,  -548,   237,
    -548,   298,   198,   -30,  -548,    34,   414,  -197,   305,  -253,
    -548,  -548,  -350,  -548,  -548,  -548,  -484,  -548,   694,   -45,
    -548,  -548,  -548,  -548,  -548,  -308,  -548,  -130,  -548,  -548,
    -313,  -548,  -548,  -282,   786,  -548,    77,  -547,  -548,  -548,
    -271,  -548,  -548,  -548,   272,  -548,   341,  -548,   219,  -548,
    -325,  -294,   523,  -257,   -46,   655,   503,   227,  -548,  -429,
     441,   253,   217,  -548,  -548,   308,  -548,  -439,  -548,  -548,
     284,  -548,  -548,  -548,   306,  -548,  -548,  -183,  -548,  -464,
     783,  -548,   315,  -548,    10,   -61,  -548,  -548,  -548,  -548,
    -548,  -137,   -35,  -131,  -116,  -548,   381,   -37,  -548,  -548,
    -548,  -548,  -548,  -206,  -548,  -548,  -152,  -148,  -246,   -81,
    -548,   883,   683,   545,    21,  -548,   703,  -548,  -112,  -548,
    -296,   738,  -548,  2069,   173,   -55,  -548,  2027,   -41,   309,
    -222,   -29,    -6,  -548,  -548,  -548,  -548,   -99,   -14,    24,
     552,   672,  1120,  1304,  1400,  1819,  -548,  1931,   -26,  -272,
     346,  -548,  -548,  -548,  -548,  -548,  -548,  -548,  -548,   242,
     222,  -548,  -548,  -548,  -332,  -548,  -548,  -548,   877,  -548,
     -49,  -548,  -548,  -548,  -516,  -258,    -8,   -19,   -59,    72,
     -51,   422,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    11,    12,    13,   278,    14,    15,    16,    17,
      18,   300,    50,   226,   382,   228,   229,   230,   231,   232,
     233,   234,   423,   235,   236,   237,   581,   582,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   554,   659,
     719,   755,   756,   248,   389,   411,   383,   250,   588,   251,
     590,   252,   253,   254,   255,   256,   257,   258,   166,   343,
     168,   169,   170,   171,   172,   173,   368,   174,   175,   176,
     478,   479,   480,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   511,   640,   703,   744,   705,   745,   187,
     344,   188,   345,   346,   332,   623,   487,   488,   777,   489,
     490,   695,   491,   628,   492,   624,   191,   192,   193,   259,
     654,   655,   656,   194,   635,   636,   637,   336,   337,   638,
     260,   154,   155,   156,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   476,   141,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   461,   107,
     108,   142,   143,   309,   157,   110,   111,   261,   262,   263,
     264,   375,   196,   265,   198,   392,   393,   266,   364,   757,
     361,   158,   201,   494,   495,   496,   202,   296,   395,   396,
     384,   270,   385,   272,   273,   274,   275,   276,   119,   602,
     603,   453,   454,   672,   455,   674,   456,   457,   727,   784,
     790,   791,   797,   608,   676,    19,    43,    54,    63,   148,
     281,    84,    85,    86,    87,   282,   458,   120,   121,   122,
     123,    35,   301
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       2,    32,    32,    34,    32,    32,    32,    32,   327,    89,
     293,    83,    31,    33,   328,    36,    37,    38,    39,   412,
      89,   153,   190,   167,    96,   390,    95,   452,   585,   329,
      96,   442,    95,    32,    82,    44,   526,   379,   493,   200,
     267,    88,   210,   277,    64,    82,    32,   516,   522,   523,
     524,   525,    88,    96,   292,    95,   626,   149,   463,   464,
     537,   653,   634,   268,   308,   310,   369,   577,   531,   533,
      20,   312,   425,   518,   518,   518,   518,   518,   591,   435,
     279,   657,   109,   323,   520,   520,   520,   520,   520,   362,
     435,   677,   435,   297,   335,   702,   333,   435,   435,   435,
    -187,   338,   325,   249,  -187,    21,   501,   416,   354,    52,
     391,   290,   688,   502,    96,   324,    95,   351,   359,   542,
     543,   544,   406,    22,    53,   545,    93,    94,    32,   417,
     227,   298,   546,   436,   629,   210,   210,   437,   418,    64,
     211,   211,    23,  -298,   436,  -345,   436,  -298,   437,   413,
     437,   436,   436,   436,   743,   437,   437,   437,  -254,  -345,
      40,   338,    24,   575,   576,   578,   579,   580,   398,    25,
     372,    26,   290,   594,   297,   589,   327,   327,   327,   405,
    -254,  -254,   470,   471,   472,   327,   327,    41,   493,   493,
    -289,   473,   474,   394,  -289,   277,   277,   329,   329,   329,
     555,   425,  -344,    42,   438,    45,   329,   329,   415,    46,
     293,   277,   363,   677,   677,   445,  -344,   446,   702,    47,
     430,    48,   462,   462,   462,   517,   517,   517,   517,   517,
     653,    49,   339,    55,   297,   144,   427,    89,    89,   441,
     190,   167,    60,   144,    61,   310,    96,   639,    95,    62,
     657,    93,    94,   408,   444,   249,   249,   200,   267,   634,
     210,   277,    82,    82,    65,    96,   585,    95,   391,    88,
      88,    66,   414,   371,   701,   499,   690,   691,   645,   297,
      32,   268,    67,   388,   557,   558,   559,   560,   561,   562,
     563,    68,   339,  -300,   434,   351,    69,  -300,   144,   144,
     477,   -27,   -27,    70,   433,   481,   512,   682,   497,   509,
     391,   146,    27,   586,   210,   498,   591,   693,   144,    29,
     147,   249,   536,    30,   -27,   -27,   283,   553,   284,   210,
     210,   210,   210,   210,   288,   210,   532,   532,   696,   -29,
     -29,   210,    27,   510,   748,   547,   538,   481,   227,    29,
     210,   210,   210,    30,   277,   660,   390,   794,   211,   211,
      27,   510,   -29,   -29,   285,   427,   678,    29,   394,   539,
     410,    30,   286,   277,   277,   277,   277,   277,   277,   277,
      89,   287,   379,   569,   571,  -255,   277,   570,   570,   493,
     427,   427,   427,   427,   427,   583,   277,   761,   762,   294,
     538,   750,   277,   295,   308,    82,   435,  -255,  -255,   289,
     299,   302,    88,   589,   249,   408,   408,   408,   408,   408,
     408,   408,   767,   592,   768,   499,   499,   518,    32,   303,
     412,  -121,   519,   519,   519,   519,   519,   304,   520,   530,
     530,   388,   305,     3,   408,   313,   249,   541,  -122,   572,
     324,   314,   609,  -121,  -121,   391,   249,   144,   497,   497,
     436,   391,   641,   334,   437,   498,   498,   493,   338,   484,
    -122,  -122,  -188,   564,   683,  -178,  -188,  -187,   210,   144,
    -344,  -187,   326,   584,   644,   -88,   144,   144,   144,   -88,
     331,     4,   324,     5,     6,   144,   144,     7,     8,     9,
      10,   541,   210,   210,  -186,   528,   338,    27,  -186,   210,
      94,   789,   352,   219,    29,   484,   353,   355,    30,   660,
     485,   277,    81,   394,   394,   -87,   224,   356,   789,   -87,
     373,   462,   410,   410,   410,   410,   410,   410,   410,   712,
     277,   277,   327,    27,   508,   374,   365,   277,   731,   509,
      29,   586,  -124,    27,    30,  -189,    94,   376,    27,  -189,
      29,   410,   499,   329,    30,    29,    27,  -347,    81,    30,
     499,    28,   499,    29,  -124,  -124,  -185,    30,   633,   517,
    -185,   249,    27,   510,   377,    34,   673,   675,   378,    29,
    -352,   189,   477,    30,   481,   497,   397,   399,   400,   339,
     249,   249,   498,   497,   481,   497,   532,   249,   401,   419,
     498,    51,   498,   112,   112,    56,    57,    58,    59,   159,
     203,   269,   112,   -89,   499,   447,   499,   -89,   663,   499,
     421,   420,   499,   428,   584,   277,   431,   339,   144,   583,
     277,   432,   112,   112,    96,   294,    95,  -185,   360,   443,
      32,  -185,   448,   459,   641,   449,   450,   497,   465,   497,
     466,   451,   497,    27,   498,   497,   498,    81,    28,   498,
      29,   728,   498,   467,    30,   210,   468,   112,   112,   499,
     -87,   360,   408,   210,   -87,   189,   469,   394,   482,   125,
     483,   277,   500,   504,   503,   249,   505,   112,   506,   507,
     514,   515,   535,   159,   499,   -26,   -26,    32,   528,   530,
     547,   341,   497,   347,   203,   549,   499,   548,   759,   498,
     550,   210,   718,   210,   551,   556,   566,   499,   -26,   -26,
    -104,   277,   277,   113,   113,   593,   595,   497,   596,   113,
     204,   597,   113,   277,   498,    89,   598,   801,   347,   497,
     599,   249,  -104,   600,   601,   604,   498,   605,   606,   607,
     497,  -104,   113,   113,    32,   610,   552,   498,   611,   612,
      82,   553,   613,   614,   269,   633,   617,    88,   754,   616,
     618,    32,   619,   620,   621,   622,   519,   630,   629,   798,
     631,   249,   249,  -205,   642,   646,   643,   113,   113,   410,
     648,   661,   662,   249,    27,   510,   647,   417,   315,   189,
     649,    29,   650,   664,   665,    30,   667,   113,   771,   772,
     666,   316,   403,   113,   -45,   668,   669,   670,   317,   318,
     718,   319,    71,   204,   204,   112,   112,   112,   203,   269,
     679,   681,   686,   112,   320,   321,   322,   685,   112,   698,
     112,   195,   144,   687,   112,   112,   112,   112,   112,   689,
     360,   697,   699,   189,   700,   112,   112,   112,   204,   707,
     709,   708,   722,   713,   112,   112,   714,   715,   521,   521,
     521,   521,   521,   716,   721,   521,   521,   534,   726,   729,
     189,   730,   347,   737,   738,   747,   739,   748,   740,   219,
     751,   484,   335,   350,   513,   758,   775,   347,   347,   347,
     347,   347,   224,   347,   347,   347,   760,   763,   765,   347,
    -177,   766,   769,   527,   770,   773,   627,   513,   347,   347,
     347,   774,   780,   782,   792,   409,   783,   793,   796,    27,
     795,   800,    94,   440,   195,   195,    29,   163,   799,   513,
      30,   723,   688,   753,    81,   113,   113,   113,   204,   720,
     426,   658,    27,   113,    93,    94,   632,   781,   113,    29,
     113,   724,   742,    30,   113,   113,   113,   113,   113,   195,
     439,   513,   370,   704,   779,   113,   113,   113,   625,   486,
     776,   764,   787,   734,   113,   113,   732,   124,   752,   680,
     402,   160,   366,   403,   741,   460,   429,   367,   475,   311,
     615,   127,   204,   316,   749,   725,   785,   112,   128,     0,
     317,   318,   802,   319,   330,   163,   671,   204,   204,   204,
     204,   204,     0,   204,   204,   204,   320,   321,   404,   204,
      27,     0,    93,    94,   164,     0,   165,    29,   204,   204,
     204,    30,   189,   347,   357,    81,   347,     0,     0,     0,
     513,   513,   684,     0,     0,     0,     0,   316,     0,   195,
     692,     0,   694,     0,   317,   318,     0,   319,     0,     0,
     347,   347,     0,     0,     0,     0,     0,   347,     0,   426,
     320,   321,   358,     0,     0,     0,     0,   409,   409,   409,
     409,   409,   409,   409,   513,   513,     0,     0,     0,     0,
       0,   568,   568,     0,   426,   426,   426,   426,   426,     0,
       0,     0,     0,   195,   733,   484,   409,     0,     0,   735,
     786,     0,   736,     0,     0,     0,     0,   113,   195,   195,
     195,   195,   195,     0,   195,    27,   510,    93,    94,     0,
     195,     0,    29,     0,     0,   521,    30,     0,     0,   195,
     195,   195,     0,    27,   112,   706,    94,     0,     0,     0,
      29,     0,     0,   204,    30,     0,   204,     0,    81,   694,
       0,   114,   114,     0,   347,     0,     0,   114,   205,   271,
     114,     0,   447,     0,   347,     0,     0,     0,     0,     0,
     204,   204,     0,     0,   778,   788,     0,   204,     0,     0,
     114,   114,     0,     0,     0,     0,   627,     0,     0,   448,
       0,     0,   449,   450,   746,     0,     0,   627,   451,     0,
      27,   112,   521,   112,     0,    28,     0,    29,     0,     0,
       0,    30,     0,   652,     0,   114,   114,     0,     0,     0,
     347,     0,   513,   347,     0,     0,     0,     0,     0,     0,
       0,   347,     0,     0,     0,   114,     0,     0,   513,     0,
       0,   114,     0,     0,   212,   213,     0,   214,     0,     0,
       0,   348,   348,     0,   113,     0,     0,   195,   706,   218,
       0,   565,   566,     0,     0,     0,     0,   567,     0,   347,
       0,   347,   223,     0,   204,     0,     0,     0,     0,     0,
       0,   195,   195,     0,   204,   225,   348,   347,   195,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,    92,    93,    94,     0,    78,     0,    29,     0,    79,
      80,    30,     0,   527,   528,    81,     0,     0,     0,   529,
       0,   113,     0,   113,     0,   407,     0,     0,     0,     0,
       0,     0,     0,     0,   409,   115,   115,   163,     0,     0,
     204,   115,   206,   204,   115,     0,     0,     0,     0,     0,
     424,   204,    27,    92,    93,    94,     0,    78,     0,    29,
       0,    79,    80,    30,   115,   115,     0,    81,     0,     0,
       0,     0,     0,   114,   114,   114,   205,   271,     0,     0,
       0,   114,   652,     0,     0,     0,   114,     0,   114,   204,
       0,   204,   114,   114,   114,   114,   114,     0,     0,   115,
     115,     0,     0,   114,   114,   114,     0,   204,     0,     0,
       0,     0,   114,   114,     0,     0,     0,     0,     0,   115,
       0,     0,     0,     0,     0,   115,     0,     0,     0,     0,
     348,   116,   116,     0,     0,   206,   206,   116,   207,     0,
     116,     0,     0,     0,     0,   348,   348,   348,   348,   348,
       0,   348,   348,   348,   195,     0,     0,   348,     0,     0,
     116,   116,   195,     0,     0,   540,   348,   348,   348,     0,
     206,    27,    92,    93,    94,     0,    78,     0,    29,   424,
      79,    80,    30,     0,     0,     0,    81,   407,   407,   407,
     407,   407,   407,   407,     0,   116,   116,     0,     0,     0,
     195,     0,   195,    71,   574,   574,   574,   574,   574,     0,
       0,     0,     0,     0,     0,   116,   587,     0,     0,   540,
       0,   116,     0,    72,    73,    74,     0,    75,    76,     0,
       0,   207,   207,     0,     0,     0,     0,     0,     0,     0,
       0,    27,    77,     0,     0,     0,    78,     0,    29,     0,
      79,    80,    30,     0,     0,   114,    81,   115,   115,   115,
     206,     0,     0,   150,     0,   115,   207,     0,     0,     0,
     115,     0,   115,   151,     0,     0,   115,   115,   115,   115,
     115,     0,     0,     0,    91,     0,     0,   115,   115,   115,
       0,   348,     0,     0,   348,     0,   115,   115,     0,     0,
       0,     0,     0,     0,     0,     0,    27,   152,    93,    94,
       0,    78,     0,    29,   206,    79,    80,    30,   348,   348,
       0,    81,     0,     0,     0,   348,     0,     0,     0,   206,
     206,   206,   206,   206,     0,   206,   206,   206,     0,     0,
       0,   206,     0,     0,     0,     0,     0,     0,     0,     0,
     206,   206,   206,   116,   116,   116,   207,     0,     0,     0,
       0,   116,     0,     0,     0,     0,   116,     0,   116,     0,
       0,    90,   116,   116,   116,   116,   116,     0,     0,     0,
       0,     0,    91,   116,   116,   116,     0,     0,     0,     0,
       0,     0,   116,   116,     0,     0,     0,     0,     0,     0,
       0,     0,   114,     0,    27,    92,    93,    94,     0,    78,
     207,    29,     0,    79,    80,    30,     0,     0,     0,    81,
       0,     0,   348,     0,     0,   207,   207,   207,   207,   207,
       0,   207,   207,   207,     0,     0,     0,   207,     0,   115,
       0,     0,     0,     0,     0,     0,   207,   207,   207,     0,
       0,     0,     0,     0,   587,     0,     0,     0,     0,   212,
     213,     0,   214,     0,     0,     0,     0,     0,     0,   114,
       0,   114,     0,     0,   218,   206,   565,   566,   206,     0,
       0,     0,   651,     0,     0,     0,     0,   223,   348,     0,
       0,   348,     0,     0,     0,     0,     0,     0,   291,   348,
     225,     0,   206,   206,     0,     0,     0,     0,     0,   206,
       0,     0,     0,     0,     0,    27,    92,    93,    94,   632,
      78,     0,    29,     0,    79,    80,    30,     0,     0,     0,
       0,    27,    92,    93,    94,   116,    78,   348,    29,   348,
      79,    80,    30,     0,     0,     0,    81,     0,     0,     0,
     117,   117,     0,     0,     0,     0,   117,   208,     0,   117,
     212,   213,     0,   214,   215,   216,   217,     0,     0,     0,
       0,   207,     0,   124,   207,   218,   219,   220,   221,   117,
     117,     0,     0,   380,     0,     0,   115,   127,   223,   224,
       0,   381,     0,     0,   128,     0,     0,     0,   207,   207,
       0,   225,     0,     0,     0,   207,   206,     0,     0,     0,
       0,     0,     0,     0,   117,   117,    27,    92,    93,    94,
     164,    78,   165,    29,     0,    79,    80,    30,     0,     0,
       0,    81,     0,     0,   117,     0,     0,     0,     0,     0,
     117,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     208,   208,     0,   115,     0,   115,     0,     0,     0,     0,
       0,     0,   118,   118,     0,     0,     0,     0,   118,   209,
       0,   118,   206,     0,     0,   206,     0,     0,     0,     0,
       0,     0,   116,   206,     0,   208,     0,     0,     0,   124,
       0,   118,   118,   386,   125,     0,     0,     0,     0,   126,
       0,     0,   207,   127,   294,     0,   316,     0,   295,     0,
     128,   710,   366,   317,   318,     0,   319,   711,     0,     0,
       0,   206,     0,   206,     0,     0,   118,   118,   128,   320,
     321,   387,    27,    92,    93,    94,     0,    78,     0,    29,
       0,    79,    80,    30,     0,     0,   118,    81,     0,   116,
       0,   116,   118,     0,     0,     0,   165,     0,     0,   145,
       0,     0,   349,   209,     0,   199,     0,   145,   207,     0,
       0,   207,   117,   117,   117,   208,     0,     0,     0,   207,
     117,     0,     0,     0,     0,   117,     0,   117,     0,     0,
       0,   117,   117,   117,   117,   117,     0,     0,     0,     0,
       0,     0,   117,   117,   117,     0,     0,   197,     0,     0,
       0,   117,   117,     0,     0,     0,     0,   207,     0,   207,
       0,     0,   145,   145,     0,     0,     0,     0,     0,   208,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   145,     0,   208,   208,   208,   208,   208,     0,
     208,   208,   208,     0,     0,     0,   208,     0,   199,   199,
       0,     0,     0,     0,     0,   208,   208,   208,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   118,   118,   118,   209,     0,     0,
       0,     0,   118,   199,     0,     0,     0,   118,     0,   118,
     197,   197,     0,   118,   118,   118,   118,   118,     0,     0,
       0,     0,     0,     0,   118,   118,   118,     0,     0,     0,
       0,     0,     0,   118,   118,     0,     0,    71,     0,     0,
       0,     0,     0,     0,     0,   197,     0,     0,     0,     0,
     280,   209,     0,     0,     0,     0,     0,    72,    73,    74,
       0,    75,    76,     0,   117,     0,   209,   209,   209,   209,
     209,     0,   349,   209,   209,    27,    77,     0,   209,     0,
      78,     0,    29,     0,    79,    80,    30,   349,   349,   349,
      81,   145,     0,   199,     0,     0,   124,     0,     0,     0,
     208,     0,     0,   208,     0,     0,   306,     0,     0,     0,
     127,     0,     0,   145,   307,     0,     0,   128,     0,     0,
     145,   145,   145,     0,     0,     0,     0,   208,   208,   145,
     145,     0,     0,     0,   208,   197,     0,     0,     0,    27,
      92,    93,    94,     0,    78,     0,    29,   199,    79,    80,
      30,     0,     0,     0,    81,     0,     0,     0,     0,     0,
       0,     0,   199,   199,   199,   199,   199,     0,   199,     0,
       0,     0,     0,     0,   199,     0,   118,     0,     0,     0,
       0,     0,     0,   199,   199,   199,     0,     0,     0,   197,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   197,   197,   197,   197,   197,     0,
     197,   117,     0,     0,     0,   349,   197,     0,     0,     0,
       0,     0,     0,     0,     0,   197,   197,   197,     0,     0,
       0,   208,     0,     0,     0,     0,     0,     0,   124,   349,
     209,     0,   160,   161,     0,     0,   349,     0,   340,     0,
       0,   341,   127,     0,     0,     0,   342,     0,     0,   128,
       0,     0,     0,     0,     0,     0,   163,     0,     0,     0,
       0,     0,   145,     0,     0,     0,     0,     0,   117,     0,
     117,    27,    92,    93,    94,   164,    78,   165,    29,     0,
      79,    80,    30,     0,     0,     0,    81,   208,     0,     0,
     208,     0,     0,     0,     0,     0,     0,     0,   208,     0,
       0,   199,   124,     0,     0,     0,   160,   161,     0,     0,
       0,     0,   162,   118,     0,   350,   127,     0,     0,     0,
       0,     0,     0,   128,     0,   199,   199,     0,     0,     0,
     163,     0,   199,   209,     0,     0,   208,     0,   208,     0,
       0,     0,     0,   197,     0,    27,   152,    93,    94,   164,
      78,   165,    29,   151,    79,    80,    30,     0,     0,     0,
      81,     0,     0,     0,    91,     0,     0,   197,   197,     0,
       0,     0,     0,     0,   197,     0,     0,     0,     0,     0,
     118,     0,   118,     0,     0,     0,    27,   152,    93,    94,
       0,    78,     0,    29,     0,    79,    80,    30,     0,     0,
       0,    81,   349,     0,     0,     0,     0,   386,   212,   213,
     209,   214,   215,   216,   217,     0,     0,     0,   294,     0,
     316,   124,   295,   218,   219,   220,   221,   317,   318,     0,
     319,   222,     0,     0,   350,   127,   223,   224,     0,     0,
       0,     0,   128,   320,   321,   387,     0,     0,   349,   225,
     349,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,   152,    93,    94,   164,    78,
     165,    29,     0,    79,    80,    30,   145,     0,     0,    81,
     124,     0,     0,     0,   160,   161,     0,     0,     0,     0,
     340,     0,     0,   350,   127,     0,     0,     0,   199,     0,
       0,   128,     0,     0,     0,     0,   199,     0,   163,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27,    92,    93,    94,   164,    78,   165,
      29,     0,    79,    80,    30,     0,     0,     0,    81,     0,
     197,     0,     0,     0,   199,     0,   199,     0,   197,     0,
       0,     0,     0,     0,   386,   212,   213,     0,   214,   215,
     216,   217,     0,     0,     0,   294,     0,   316,   124,   295,
     218,   219,   220,   221,   317,   318,     0,   319,   380,     0,
       0,   350,   127,   223,   224,     0,   197,     0,   197,   128,
     320,   321,   387,     0,     0,     0,   225,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    27,    92,    93,    94,   164,    78,   165,    29,     0,
      79,    80,    30,   386,   212,   213,    81,   214,   215,   216,
     217,     0,     0,     0,   294,     0,   316,   124,   295,   218,
     219,   220,   221,   317,   318,     0,   319,   380,     0,     0,
       0,   127,   223,   224,     0,     0,     0,     0,   128,   320,
     321,   387,     0,     0,     0,   225,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,    92,    93,    94,   164,    78,   165,    29,     0,    79,
      80,    30,     0,   212,   213,    81,   214,   215,   216,   217,
       0,     0,     0,     0,     0,     0,   124,     0,   218,   219,
     220,   221,     0,     0,     0,     0,   380,     0,     0,   341,
     127,   223,   224,     0,   381,     0,     0,   128,     0,     0,
       0,     0,     0,     0,   225,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
      92,    93,    94,   164,    78,   165,    29,     0,    79,    80,
      30,     0,   212,   213,    81,   214,   215,   216,   217,     0,
       0,     0,     0,     0,     0,   124,     0,   218,   219,   220,
     221,     0,     0,     0,     0,   222,     0,     0,     0,   127,
     223,   224,     0,     0,     0,     0,   128,     0,     0,     0,
       0,     0,     0,   225,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,   152,
      93,    94,   164,    78,   165,    29,     0,    79,    80,    30,
       0,   212,   213,    81,   214,   215,   216,   217,     0,     0,
       0,     0,     0,     0,   124,     0,   218,   219,   220,   221,
       0,     0,     0,     0,   380,     0,     0,     0,   127,   223,
     224,     0,     0,     0,     0,   128,     0,     0,     0,     0,
       0,     0,   225,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,    92,    93,
      94,   164,    78,   165,    29,     0,    79,    80,    30,     0,
     212,   213,    81,   214,   215,   216,   217,     0,     0,     0,
       0,     0,     0,   124,     0,   218,   219,   220,   221,     0,
       0,     0,     0,   422,     0,     0,     0,   127,   223,   224,
       0,     0,     0,     0,   128,     0,     0,     0,     0,     0,
       0,   225,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    27,    92,    93,    94,
     164,    78,   165,    29,     0,    79,    80,    30,     0,   212,
     213,    81,   214,   215,   216,   217,     0,     0,     0,     0,
       0,     0,   124,     0,   218,   219,   220,   717,     0,     0,
       0,     0,   380,     0,     0,     0,   127,   223,   224,     0,
       0,     0,     0,   128,     0,     0,     0,     0,     0,     0,
     225,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,    92,    93,    94,   164,
      78,   165,    29,     0,    79,    80,    30,     0,   212,   213,
      81,   214,   215,   216,   217,     0,     0,     0,     0,     0,
       0,   124,     0,   218,   219,   565,   566,     0,     0,     0,
       0,   573,     0,     0,     0,   127,   223,   224,     0,     0,
       0,     0,   124,     0,     0,     0,   160,   161,     0,   225,
       0,     0,   340,     0,     0,     0,   127,     0,     0,     0,
     342,     0,     0,   128,    27,    92,    93,    94,   164,    78,
     163,    29,     0,    79,    80,    30,     0,     0,     0,    81,
       0,     0,     0,     0,     0,    27,    92,    93,    94,   164,
      78,   165,    29,   124,    79,    80,    30,   160,   161,     0,
      81,     0,     0,   162,     0,     0,     0,   127,     0,     0,
       0,     0,     0,     0,   128,     0,     0,     0,     0,     0,
       0,   163,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    27,   152,    93,    94,
     164,    78,   165,    29,   124,    79,    80,    30,   160,   161,
       0,    81,     0,     0,   340,     0,     0,     0,   127,     0,
     124,     0,     0,     0,     0,   128,     0,     0,     0,     0,
     306,     0,   163,     0,   127,     0,     0,     0,     0,     0,
       0,   128,     0,     0,     0,     0,     0,    27,    92,    93,
      94,   164,    78,   165,    29,     0,    79,    80,    30,   150,
      91,     0,    81,    27,    92,    93,    94,     0,    78,    90,
      29,     0,    79,    80,    30,     0,     0,     0,    81,     0,
      91,     0,    27,    92,    93,    94,     0,    78,     0,    29,
       0,    79,    80,    30,     0,     0,     0,    81,     0,     0,
       0,     0,    27,    92,    93,    94,     0,    78,     0,    29,
       0,    79,    80,    30,     0,     0,     0,    81
};

static const yytype_int16 yycheck[] =
{
       0,    20,    21,    22,    23,    24,    25,    26,   145,    60,
      91,    60,    20,    21,   145,    23,    24,    25,    26,   241,
      71,    67,    68,    68,    61,   222,    61,   299,   428,   145,
      67,   289,    67,    52,    60,    35,   361,   220,   334,    68,
      69,    60,    68,    69,    52,    71,    65,   355,   356,   357,
     358,   359,    71,    90,    91,    90,   485,    65,   304,   305,
     373,   545,   501,    69,   125,   126,   196,   417,   362,   363,
      27,   129,   262,   355,   356,   357,   358,   359,   428,   285,
      70,   545,    61,   138,   355,   356,   357,   358,   359,   188,
     296,   607,   298,   107,    30,   642,   154,   303,   304,   305,
      14,   160,   143,    69,    18,    27,    27,    37,   166,    22,
     222,    90,    37,    34,   151,    29,   151,   162,   173,   376,
     377,   378,   237,    27,    37,    27,    62,    63,   147,    59,
      69,   107,    34,   285,    59,   161,   162,   285,    68,   147,
      68,    69,    27,    14,   296,    11,   298,    18,   296,   248,
     298,   303,   304,   305,   701,   303,   304,   305,    13,    25,
      13,   220,    27,   416,   417,   418,   419,   420,   226,    27,
     196,    27,   151,   431,   188,   428,   313,   314,   315,   234,
      35,    36,   313,   314,   315,   322,   323,    13,   484,   485,
      14,   322,   323,   222,    18,   221,   222,   313,   314,   315,
     397,   391,    11,    13,   285,    13,   322,   323,   249,    13,
     291,   237,   188,   729,   730,   296,    25,   298,   765,    13,
     278,    13,   303,   304,   305,   355,   356,   357,   358,   359,
     714,    67,   160,    36,   248,    62,   262,   288,   289,   288,
     286,   286,    28,    70,    13,   306,   283,   504,   283,    13,
     714,    62,    63,   237,   291,   221,   222,   286,   287,   698,
     286,   287,   288,   289,    13,   302,   666,   302,   380,   288,
     289,    30,   248,   196,    22,   334,    36,    37,   535,   293,
     299,   287,    13,   222,   399,   400,   401,   402,   403,   404,
     405,    13,   220,    14,   284,   340,    13,    18,   125,   126,
     326,    12,    13,    13,   283,   331,   352,   620,   334,    27,
     422,    35,    60,   428,   340,   334,   666,   630,   145,    67,
      13,   287,   367,    71,    35,    36,    27,    27,    27,   355,
     356,   357,   358,   359,    11,   361,   362,   363,   632,    12,
      13,   367,    60,    61,    12,    13,   375,   373,   287,    67,
     376,   377,   378,    71,   380,   552,   553,   786,   286,   287,
      60,    61,    35,    36,    27,   391,   612,    67,   397,   375,
     237,    71,    27,   399,   400,   401,   402,   403,   404,   405,
     431,    27,   565,   413,   414,    13,   412,   413,   414,   685,
     416,   417,   418,   419,   420,   421,   422,   729,   730,    14,
     429,   709,   428,    18,   465,   431,   612,    35,    36,    27,
      13,    41,   431,   666,   380,   399,   400,   401,   402,   403,
     404,   405,   747,   429,   749,   484,   485,   709,   447,    27,
     652,    13,   355,   356,   357,   358,   359,    27,   709,   362,
     363,   380,    27,     0,   428,    41,   412,   375,    13,   415,
      29,     3,   452,    35,    36,   567,   422,   284,   484,   485,
     612,   573,   508,    11,   612,   484,   485,   763,   527,    22,
      35,    36,    14,   412,    27,    12,    18,    14,   504,   306,
      11,    18,    22,   422,   529,    14,   313,   314,   315,    18,
      22,    48,    29,    50,    51,   322,   323,    54,    55,    56,
      57,   429,   528,   529,    14,    22,   565,    60,    18,   535,
      63,   783,    27,    20,    67,    22,    30,    41,    71,   716,
      27,   547,    75,   552,   553,    14,    33,     3,   800,    18,
      22,   612,   399,   400,   401,   402,   403,   404,   405,   651,
     566,   567,   679,    60,    22,    25,     6,   573,   679,    27,
      67,   666,    13,    60,    71,    14,    63,    27,    60,    18,
      67,   428,   621,   679,    71,    67,    60,    25,    75,    71,
     629,    65,   631,    67,    35,    36,    14,    71,   501,   709,
      18,   547,    60,    61,    27,   604,   605,   606,    27,    67,
      25,    68,   618,    71,   620,   621,    27,    41,     3,   527,
     566,   567,   621,   629,   630,   631,   632,   573,     6,    37,
     629,    41,   631,    61,    62,    45,    46,    47,    48,    67,
      68,    69,    70,    14,   683,    22,   685,    18,   567,   688,
      22,    68,   691,    11,   573,   661,    13,   565,   465,   665,
     666,    35,    90,    91,   681,    14,   681,    14,    15,    36,
     669,    18,    49,    36,   700,    52,    53,   683,    13,   685,
      35,    58,   688,    60,   683,   691,   685,    75,    65,   688,
      67,   671,   691,    36,    71,   701,    36,   125,   126,   738,
      14,    15,   666,   709,    18,   162,    36,   716,    36,    22,
      36,   717,    34,    13,    35,   661,    35,   145,    36,    36,
      59,    36,    27,   151,   763,    12,    13,   726,    22,   632,
      13,    30,   738,   161,   162,    36,   775,    35,   726,   738,
      36,   747,   661,   749,    36,    36,    22,   786,    35,    36,
      37,   757,   758,    61,    62,    36,    36,   763,    36,    67,
      68,    36,    70,   769,   763,   796,    36,   796,   196,   775,
      36,   717,    59,    36,    36,    27,   775,    27,    27,    13,
     786,    68,    90,    91,   783,    30,    22,   786,    36,    13,
     796,    27,    36,    36,   222,   698,    35,   796,   717,    30,
      13,   800,    35,    13,    11,    30,   709,    22,    59,   789,
      27,   757,   758,    59,    13,    36,    30,   125,   126,   666,
      36,    13,    30,   769,    60,    61,    35,    59,     3,   286,
      36,    67,    36,    35,    13,    71,    36,   145,   757,   758,
      11,    16,     6,   151,     6,    30,    13,    35,    23,    24,
     769,    26,    22,   161,   162,   283,   284,   285,   286,   287,
      11,    11,    35,   291,    39,    40,    41,    13,   296,    13,
     298,    68,   679,    36,   302,   303,   304,   305,   306,    36,
      15,    36,    35,   340,    13,   313,   314,   315,   196,    36,
      11,    36,    11,    36,   322,   323,    13,    35,   355,   356,
     357,   358,   359,    13,    36,   362,   363,   364,    13,    13,
     367,    13,   340,    35,    13,    13,    36,    12,    34,    20,
      34,    22,    30,    30,   352,    13,    27,   355,   356,   357,
     358,   359,    33,   361,   362,   363,    36,    11,    13,   367,
      12,    35,    13,    21,    35,    13,   485,   375,   376,   377,
     378,    13,    36,    36,    36,   237,    22,    36,    11,    60,
      36,    13,    63,   287,   161,   162,    67,    45,    35,   397,
      71,   665,    37,   716,    75,   283,   284,   285,   286,   661,
     262,   547,    60,   291,    62,    63,    64,   769,   296,    67,
     298,   666,   700,    71,   302,   303,   304,   305,   306,   196,
     286,   429,   196,   642,   765,   313,   314,   315,   485,   334,
     763,   738,   775,   685,   322,   323,   681,    17,   714,   618,
       3,    21,    22,     6,   698,   302,   268,    27,   325,   126,
     465,    31,   340,    16,   705,   669,   774,   465,    38,    -1,
      23,    24,   800,    26,   147,    45,   604,   355,   356,   357,
     358,   359,    -1,   361,   362,   363,    39,    40,    41,   367,
      60,    -1,    62,    63,    64,    -1,    66,    67,   376,   377,
     378,    71,   529,   501,     3,    75,   504,    -1,    -1,    -1,
     508,   509,   621,    -1,    -1,    -1,    -1,    16,    -1,   286,
     629,    -1,   631,    -1,    23,    24,    -1,    26,    -1,    -1,
     528,   529,    -1,    -1,    -1,    -1,    -1,   535,    -1,   391,
      39,    40,    41,    -1,    -1,    -1,    -1,   399,   400,   401,
     402,   403,   404,   405,   552,   553,    -1,    -1,    -1,    -1,
      -1,   413,   414,    -1,   416,   417,   418,   419,   420,    -1,
      -1,    -1,    -1,   340,   683,    22,   428,    -1,    -1,   688,
      27,    -1,   691,    -1,    -1,    -1,    -1,   465,   355,   356,
     357,   358,   359,    -1,   361,    60,    61,    62,    63,    -1,
     367,    -1,    67,    -1,    -1,   632,    71,    -1,    -1,   376,
     377,   378,    -1,    60,   612,   642,    63,    -1,    -1,    -1,
      67,    -1,    -1,   501,    71,    -1,   504,    -1,    75,   738,
      -1,    61,    62,    -1,   632,    -1,    -1,    67,    68,    69,
      70,    -1,    22,    -1,   642,    -1,    -1,    -1,    -1,    -1,
     528,   529,    -1,    -1,   763,    35,    -1,   535,    -1,    -1,
      90,    91,    -1,    -1,    -1,    -1,   775,    -1,    -1,    49,
      -1,    -1,    52,    53,   701,    -1,    -1,   786,    58,    -1,
      60,   679,   709,   681,    -1,    65,    -1,    67,    -1,    -1,
      -1,    71,    -1,   545,    -1,   125,   126,    -1,    -1,    -1,
     698,    -1,   700,   701,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   709,    -1,    -1,    -1,   145,    -1,    -1,   716,    -1,
      -1,   151,    -1,    -1,     4,     5,    -1,     7,    -1,    -1,
      -1,   161,   162,    -1,   612,    -1,    -1,   504,   765,    19,
      -1,    21,    22,    -1,    -1,    -1,    -1,    27,    -1,   747,
      -1,   749,    32,    -1,   632,    -1,    -1,    -1,    -1,    -1,
      -1,   528,   529,    -1,   642,    45,   196,   765,   535,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    61,    62,    63,    -1,    65,    -1,    67,    -1,    69,
      70,    71,    -1,    21,    22,    75,    -1,    -1,    -1,    27,
      -1,   679,    -1,   681,    -1,   237,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   666,    61,    62,    45,    -1,    -1,
     698,    67,    68,   701,    70,    -1,    -1,    -1,    -1,    -1,
     262,   709,    60,    61,    62,    63,    -1,    65,    -1,    67,
      -1,    69,    70,    71,    90,    91,    -1,    75,    -1,    -1,
      -1,    -1,    -1,   283,   284,   285,   286,   287,    -1,    -1,
      -1,   291,   714,    -1,    -1,    -1,   296,    -1,   298,   747,
      -1,   749,   302,   303,   304,   305,   306,    -1,    -1,   125,
     126,    -1,    -1,   313,   314,   315,    -1,   765,    -1,    -1,
      -1,    -1,   322,   323,    -1,    -1,    -1,    -1,    -1,   145,
      -1,    -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,    -1,
     340,    61,    62,    -1,    -1,   161,   162,    67,    68,    -1,
      70,    -1,    -1,    -1,    -1,   355,   356,   357,   358,   359,
      -1,   361,   362,   363,   701,    -1,    -1,   367,    -1,    -1,
      90,    91,   709,    -1,    -1,   375,   376,   377,   378,    -1,
     196,    60,    61,    62,    63,    -1,    65,    -1,    67,   391,
      69,    70,    71,    -1,    -1,    -1,    75,   399,   400,   401,
     402,   403,   404,   405,    -1,   125,   126,    -1,    -1,    -1,
     747,    -1,   749,    22,   416,   417,   418,   419,   420,    -1,
      -1,    -1,    -1,    -1,    -1,   145,   428,    -1,    -1,   429,
      -1,   151,    -1,    42,    43,    44,    -1,    46,    47,    -1,
      -1,   161,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    61,    -1,    -1,    -1,    65,    -1,    67,    -1,
      69,    70,    71,    -1,    -1,   465,    75,   283,   284,   285,
     286,    -1,    -1,    17,    -1,   291,   196,    -1,    -1,    -1,
     296,    -1,   298,    27,    -1,    -1,   302,   303,   304,   305,
     306,    -1,    -1,    -1,    38,    -1,    -1,   313,   314,   315,
      -1,   501,    -1,    -1,   504,    -1,   322,   323,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,    63,
      -1,    65,    -1,    67,   340,    69,    70,    71,   528,   529,
      -1,    75,    -1,    -1,    -1,   535,    -1,    -1,    -1,   355,
     356,   357,   358,   359,    -1,   361,   362,   363,    -1,    -1,
      -1,   367,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     376,   377,   378,   283,   284,   285,   286,    -1,    -1,    -1,
      -1,   291,    -1,    -1,    -1,    -1,   296,    -1,   298,    -1,
      -1,    27,   302,   303,   304,   305,   306,    -1,    -1,    -1,
      -1,    -1,    38,   313,   314,   315,    -1,    -1,    -1,    -1,
      -1,    -1,   322,   323,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   612,    -1,    60,    61,    62,    63,    -1,    65,
     340,    67,    -1,    69,    70,    71,    -1,    -1,    -1,    75,
      -1,    -1,   632,    -1,    -1,   355,   356,   357,   358,   359,
      -1,   361,   362,   363,    -1,    -1,    -1,   367,    -1,   465,
      -1,    -1,    -1,    -1,    -1,    -1,   376,   377,   378,    -1,
      -1,    -1,    -1,    -1,   666,    -1,    -1,    -1,    -1,     4,
       5,    -1,     7,    -1,    -1,    -1,    -1,    -1,    -1,   679,
      -1,   681,    -1,    -1,    19,   501,    21,    22,   504,    -1,
      -1,    -1,    27,    -1,    -1,    -1,    -1,    32,   698,    -1,
      -1,   701,    -1,    -1,    -1,    -1,    -1,    -1,    27,   709,
      45,    -1,   528,   529,    -1,    -1,    -1,    -1,    -1,   535,
      -1,    -1,    -1,    -1,    -1,    60,    61,    62,    63,    64,
      65,    -1,    67,    -1,    69,    70,    71,    -1,    -1,    -1,
      -1,    60,    61,    62,    63,   465,    65,   747,    67,   749,
      69,    70,    71,    -1,    -1,    -1,    75,    -1,    -1,    -1,
      61,    62,    -1,    -1,    -1,    -1,    67,    68,    -1,    70,
       4,     5,    -1,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,   501,    -1,    17,   504,    19,    20,    21,    22,    90,
      91,    -1,    -1,    27,    -1,    -1,   612,    31,    32,    33,
      -1,    35,    -1,    -1,    38,    -1,    -1,    -1,   528,   529,
      -1,    45,    -1,    -1,    -1,   535,   632,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   125,   126,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    -1,    -1,
      -1,    75,    -1,    -1,   145,    -1,    -1,    -1,    -1,    -1,
     151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     161,   162,    -1,   679,    -1,   681,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    62,    -1,    -1,    -1,    -1,    67,    68,
      -1,    70,   698,    -1,    -1,   701,    -1,    -1,    -1,    -1,
      -1,    -1,   612,   709,    -1,   196,    -1,    -1,    -1,    17,
      -1,    90,    91,     3,    22,    -1,    -1,    -1,    -1,    27,
      -1,    -1,   632,    31,    14,    -1,    16,    -1,    18,    -1,
      38,    21,    22,    23,    24,    -1,    26,    27,    -1,    -1,
      -1,   747,    -1,   749,    -1,    -1,   125,   126,    38,    39,
      40,    41,    60,    61,    62,    63,    -1,    65,    -1,    67,
      -1,    69,    70,    71,    -1,    -1,   145,    75,    -1,   679,
      -1,   681,   151,    -1,    -1,    -1,    66,    -1,    -1,    62,
      -1,    -1,   161,   162,    -1,    68,    -1,    70,   698,    -1,
      -1,   701,   283,   284,   285,   286,    -1,    -1,    -1,   709,
     291,    -1,    -1,    -1,    -1,   296,    -1,   298,    -1,    -1,
      -1,   302,   303,   304,   305,   306,    -1,    -1,    -1,    -1,
      -1,    -1,   313,   314,   315,    -1,    -1,    68,    -1,    -1,
      -1,   322,   323,    -1,    -1,    -1,    -1,   747,    -1,   749,
      -1,    -1,   125,   126,    -1,    -1,    -1,    -1,    -1,   340,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   145,    -1,   355,   356,   357,   358,   359,    -1,
     361,   362,   363,    -1,    -1,    -1,   367,    -1,   161,   162,
      -1,    -1,    -1,    -1,    -1,   376,   377,   378,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   283,   284,   285,   286,    -1,    -1,
      -1,    -1,   291,   196,    -1,    -1,    -1,   296,    -1,   298,
     161,   162,    -1,   302,   303,   304,   305,   306,    -1,    -1,
      -1,    -1,    -1,    -1,   313,   314,   315,    -1,    -1,    -1,
      -1,    -1,    -1,   322,   323,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,
      35,   340,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,
      -1,    46,    47,    -1,   465,    -1,   355,   356,   357,   358,
     359,    -1,   361,   362,   363,    60,    61,    -1,   367,    -1,
      65,    -1,    67,    -1,    69,    70,    71,   376,   377,   378,
      75,   284,    -1,   286,    -1,    -1,    17,    -1,    -1,    -1,
     501,    -1,    -1,   504,    -1,    -1,    27,    -1,    -1,    -1,
      31,    -1,    -1,   306,    35,    -1,    -1,    38,    -1,    -1,
     313,   314,   315,    -1,    -1,    -1,    -1,   528,   529,   322,
     323,    -1,    -1,    -1,   535,   286,    -1,    -1,    -1,    60,
      61,    62,    63,    -1,    65,    -1,    67,   340,    69,    70,
      71,    -1,    -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   355,   356,   357,   358,   359,    -1,   361,    -1,
      -1,    -1,    -1,    -1,   367,    -1,   465,    -1,    -1,    -1,
      -1,    -1,    -1,   376,   377,   378,    -1,    -1,    -1,   340,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   355,   356,   357,   358,   359,    -1,
     361,   612,    -1,    -1,    -1,   504,   367,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   376,   377,   378,    -1,    -1,
      -1,   632,    -1,    -1,    -1,    -1,    -1,    -1,    17,   528,
     529,    -1,    21,    22,    -1,    -1,   535,    -1,    27,    -1,
      -1,    30,    31,    -1,    -1,    -1,    35,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,
      -1,    -1,   465,    -1,    -1,    -1,    -1,    -1,   679,    -1,
     681,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    -1,    -1,    -1,    75,   698,    -1,    -1,
     701,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   709,    -1,
      -1,   504,    17,    -1,    -1,    -1,    21,    22,    -1,    -1,
      -1,    -1,    27,   612,    -1,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,   528,   529,    -1,    -1,    -1,
      45,    -1,   535,   632,    -1,    -1,   747,    -1,   749,    -1,
      -1,    -1,    -1,   504,    -1,    60,    61,    62,    63,    64,
      65,    66,    67,    27,    69,    70,    71,    -1,    -1,    -1,
      75,    -1,    -1,    -1,    38,    -1,    -1,   528,   529,    -1,
      -1,    -1,    -1,    -1,   535,    -1,    -1,    -1,    -1,    -1,
     679,    -1,   681,    -1,    -1,    -1,    60,    61,    62,    63,
      -1,    65,    -1,    67,    -1,    69,    70,    71,    -1,    -1,
      -1,    75,   701,    -1,    -1,    -1,    -1,     3,     4,     5,
     709,     7,     8,     9,    10,    -1,    -1,    -1,    14,    -1,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      26,    27,    -1,    -1,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    -1,    -1,   747,    45,
     749,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,   679,    -1,    -1,    75,
      17,    -1,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    -1,    -1,    30,    31,    -1,    -1,    -1,   701,    -1,
      -1,    38,    -1,    -1,    -1,    -1,   709,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    -1,    -1,    -1,    75,    -1,
     701,    -1,    -1,    -1,   747,    -1,   749,    -1,   709,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,     8,
       9,    10,    -1,    -1,    -1,    14,    -1,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,    26,    27,    -1,
      -1,    30,    31,    32,    33,    -1,   747,    -1,   749,    38,
      39,    40,    41,    -1,    -1,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,     3,     4,     5,    75,     7,     8,     9,
      10,    -1,    -1,    -1,    14,    -1,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    26,    27,    -1,    -1,
      -1,    31,    32,    33,    -1,    -1,    -1,    -1,    38,    39,
      40,    41,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    -1,     4,     5,    75,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    27,    -1,    -1,    30,
      31,    32,    33,    -1,    35,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    -1,     4,     5,    75,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    -1,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    31,
      32,    33,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      -1,     4,     5,    75,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    -1,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,
      33,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    -1,
       4,     5,    75,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    -1,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,    33,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    -1,     4,
       5,    75,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    -1,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    27,    -1,    -1,    -1,    31,    32,    33,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    -1,     4,     5,
      75,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    27,    -1,    -1,    -1,    31,    32,    33,    -1,    -1,
      -1,    -1,    17,    -1,    -1,    -1,    21,    22,    -1,    45,
      -1,    -1,    27,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      35,    -1,    -1,    38,    60,    61,    62,    63,    64,    65,
      45,    67,    -1,    69,    70,    71,    -1,    -1,    -1,    75,
      -1,    -1,    -1,    -1,    -1,    60,    61,    62,    63,    64,
      65,    66,    67,    17,    69,    70,    71,    21,    22,    -1,
      75,    -1,    -1,    27,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,    63,
      64,    65,    66,    67,    17,    69,    70,    71,    21,    22,
      -1,    75,    -1,    -1,    27,    -1,    -1,    -1,    31,    -1,
      17,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      27,    -1,    45,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    17,
      38,    -1,    75,    60,    61,    62,    63,    -1,    65,    27,
      67,    -1,    69,    70,    71,    -1,    -1,    -1,    75,    -1,
      38,    -1,    60,    61,    62,    63,    -1,    65,    -1,    67,
      -1,    69,    70,    71,    -1,    -1,    -1,    75,    -1,    -1,
      -1,    -1,    60,    61,    62,    63,    -1,    65,    -1,    67,
      -1,    69,    70,    71,    -1,    -1,    -1,    75
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,    77,   298,     0,    48,    50,    51,    54,    55,    56,
      57,    78,    79,    80,    82,    83,    84,    85,    86,   281,
      27,    27,    27,    27,    27,    27,    27,    60,    65,    67,
      71,   292,   293,   292,   293,   297,   292,   292,   292,   292,
      13,    13,    13,   282,   298,    13,    13,    13,    13,    67,
      88,    88,    22,    37,   283,    36,    88,    88,    88,    88,
      28,    13,    13,   284,   292,    13,    30,    13,    13,    13,
      13,    22,    42,    43,    44,    46,    47,    61,    65,    69,
      70,    75,   264,   286,   287,   288,   289,   290,   293,   296,
      27,    38,    61,    62,    63,   208,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   225,   226,   230,
     231,   232,   256,   257,   258,   259,   260,   261,   263,   264,
     293,   294,   295,   296,    17,    22,    27,    31,    38,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   213,   227,   228,   240,   243,    35,    13,   285,   292,
      17,    27,    61,   170,   197,   198,   199,   230,   247,   256,
      21,    22,    27,    45,    64,    66,   134,   135,   136,   137,
     138,   139,   140,   141,   143,   144,   145,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   165,   167,   168,
     170,   182,   183,   184,   189,   196,   238,   239,   240,   243,
     247,   248,   252,   256,   257,   258,   259,   260,   261,   263,
     264,   295,     4,     5,     7,     8,     9,    10,    19,    20,
      21,    22,    27,    32,    33,    45,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    99,   100,   101,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   119,   121,
     123,   125,   127,   128,   129,   130,   131,   132,   133,   185,
     196,   233,   234,   235,   236,   239,   243,   247,   248,   256,
     257,   258,   259,   260,   261,   262,   263,   264,    81,   200,
      35,   286,   291,    27,    27,    27,    27,    27,    11,    27,
     230,    27,   213,   225,    14,    18,   253,   254,   255,    13,
      87,   298,    41,    27,    27,    27,    27,    35,   201,   229,
     201,   227,    87,    41,     3,     3,    16,    23,    24,    26,
      39,    40,    41,   241,    29,   244,    22,   207,   209,   210,
     284,    22,   170,    87,    11,    30,   193,   194,   294,   295,
      27,    30,    35,   135,   166,   168,   169,   256,   258,   263,
      30,   135,    27,    30,    87,    41,     3,     3,    41,   241,
      15,   246,   253,   255,   244,     6,    22,    27,   142,   143,
     150,   152,   264,    22,    25,   237,    27,    27,    27,   193,
      27,    35,    90,   122,   256,   258,     3,    41,    90,   120,
     123,   234,   241,   242,   247,   254,   255,    27,    87,    41,
       3,     6,     3,     6,    41,   241,    97,    99,   104,   107,
     111,   121,   246,   253,   255,   244,    37,    59,    68,    37,
      68,    22,    27,    98,    99,   105,   107,   264,    11,   237,
      87,    13,    35,   230,   200,   219,   222,   223,   225,   134,
      89,   286,   291,    36,   213,   225,   225,    22,    49,    52,
      53,    58,   265,   267,   268,   270,   272,   273,   292,    36,
     232,   224,   225,   224,   224,    13,    35,    36,    36,    36,
     209,   209,   209,   209,   209,   228,   212,   264,   146,   147,
     148,   264,    36,    36,    22,    27,   171,   172,   173,   175,
     176,   178,   180,   236,   249,   250,   251,   264,   293,   294,
      34,    27,    34,    35,    13,    35,    36,    36,    22,    27,
      61,   159,   170,   256,    59,    36,   141,   143,   149,   152,
     156,   168,   141,   141,   141,   141,   166,    21,    22,    27,
     152,   167,   264,   167,   168,    27,   135,   146,   247,   248,
     258,   295,   169,   169,   169,    27,    34,    13,    35,    36,
      36,    36,    22,    27,   114,   123,    36,    97,    97,    97,
      97,    97,    97,    97,    90,    21,    22,    27,   107,   119,
     264,   119,   121,    27,    99,   125,   125,   128,   125,   125,
     125,   102,   103,   264,    90,    96,    97,    99,   124,   125,
     126,   128,   248,    36,   291,    36,    36,    36,    36,    36,
      36,    36,   265,   266,    27,    27,    27,    13,   279,   298,
      30,    36,    13,    36,    36,   229,    30,    35,    13,    35,
      13,    11,    30,   171,   181,   172,   175,   176,   179,    59,
      22,    27,    64,   152,   183,   190,   191,   192,   195,   169,
     160,   170,    13,    30,   135,   169,    36,    35,    36,    36,
      36,    27,   107,   132,   186,   187,   188,   195,   122,   115,
     123,    13,    30,    90,    35,    13,    11,    36,    30,    13,
      35,   297,   269,   293,   271,   293,   280,   290,   224,    11,
     212,    11,   146,    27,   176,    13,    35,    36,    37,    36,
      36,    37,   176,   146,   176,   177,   167,    36,    13,    35,
      13,    22,   153,   161,   162,   163,   168,    36,    36,    11,
      21,    27,   234,    36,    13,    35,    13,    22,    90,   116,
     117,    36,    11,   102,   124,   266,    13,   274,   298,    13,
      13,   209,   198,   176,   181,   176,   176,    35,    13,    36,
      34,   190,   160,   153,   162,   164,   168,    13,    12,   245,
     141,    34,   186,   115,    90,   117,   118,   245,    13,   292,
      36,   280,   280,    11,   177,    13,    35,   166,   166,    13,
      35,    90,    90,    13,    13,    27,   173,   174,   176,   164,
      36,   118,    36,    22,   275,   275,    27,   178,    35,   265,
     276,   277,    36,    36,   175,    36,    11,   278,   298,    35,
      13,   286,   276
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,    76,    77,    77,    78,    78,    79,    79,    79,    79,
      79,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      87,    88,    88,    89,    89,    89,    90,    90,    90,    90,
      90,    90,    91,    91,    91,    92,    93,    93,    93,    94,
      94,    95,    95,    96,    96,    97,    97,    97,    98,    98,
      99,    99,    99,    99,   100,   101,   102,   102,   103,   104,
     104,   105,   106,   107,   107,   107,   108,   108,   109,   109,
     109,   109,   109,   110,   110,   111,   112,   113,   114,   114,
     115,   115,   116,   116,   117,   118,   118,   119,   119,   119,
     120,   120,   120,   120,   120,   121,   121,   122,   122,   123,
     123,   124,   124,   124,   125,   126,   127,   127,   127,   128,
     128,   129,   129,   130,   130,   131,   132,   133,   134,   134,
     134,   135,   135,   135,   135,   135,   135,   136,   136,   137,
     138,   138,   139,   139,   140,   140,   141,   141,   141,   142,
     142,   143,   143,   143,   143,   144,   145,   146,   146,   147,
     147,   148,   149,   149,   150,   151,   152,   152,   152,   153,
     153,   154,   155,   155,   155,   155,   156,   157,   157,   158,
     159,   159,   160,   160,   161,   161,   162,   163,   163,   164,
     164,   165,   166,   166,   166,   167,   167,   167,   167,   167,
     168,   168,   169,   169,   170,   170,   171,   171,   172,   172,
     172,   173,   174,   174,   174,   175,   175,   176,   176,   176,
     176,   176,   176,   177,   177,   178,   179,   179,   180,   181,
     181,   182,   183,   184,   185,   185,   186,   186,   187,   187,
     188,   189,   189,   190,   190,   191,   191,   192,   193,   193,
     194,   195,   196,   196,   196,   196,   197,   197,   198,   198,
     199,   200,   200,   201,   201,   201,   202,   202,   203,   204,
     204,   205,   205,   206,   206,   207,   207,   208,   209,   209,
     210,   210,   210,   211,   212,   212,   213,   213,   213,   214,
     215,   215,   216,   217,   218,   219,   219,   220,   220,   221,
     222,   222,   223,   223,   224,   224,   225,   225,   226,   226,
     226,   227,   227,   228,   228,   229,   229,   230,   230,   231,
     231,   232,   232,   232,   232,   233,   233,   233,   234,   234,
     235,   235,   235,   236,   236,   237,   238,   238,   239,   239,
     240,   240,   241,   241,   241,   241,   241,   241,   242,   242,
     243,   244,   245,   246,   247,   247,   248,   248,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   262,   262,   262,   262,   263,   263,   264,
     265,   265,   265,   265,   265,   266,   266,   267,   267,   268,
     269,   270,   271,   272,   273,   274,   274,   275,   275,   276,
     276,   277,   278,   278,   279,   279,   280,   281,   282,   282,
     282,   283,   283,   284,   284,   285,   286,   286,   286,   287,
     287,   287,   287,   287,   287,   288,   289,   289,   289,   289,
     289,   290,   290,   291,   291,   292,   292,   293,   293,   293,
     294,   295,   296,   296,   296,   297,   298
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
       1,     8,     1,     1,     5,     2,     1,     2,     3,     1,
       3,     2,     2,     1,     2,     1,     1,     6,     1,     2,
       4,     3,     1,     1,     3,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     4,     4,
       4,     2,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0
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
#line 229 "SyntaxBNF.y"
                    {}
#line 2892 "y.tab.c"
    break;

  case 3: /* TPTP_file: TPTP_file TPTP_input  */
#line 230 "SyntaxBNF.y"
                                           {}
#line 2898 "y.tab.c"
    break;

  case 4: /* TPTP_input: annotated_formula  */
#line 233 "SyntaxBNF.y"
                               {P_PRINT((yyval.pval));}
#line 2904 "y.tab.c"
    break;

  case 5: /* TPTP_input: include  */
#line 234 "SyntaxBNF.y"
                              {P_PRINT((yyval.pval));}
#line 2910 "y.tab.c"
    break;

  case 6: /* annotated_formula: thf_annotated  */
#line 237 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2916 "y.tab.c"
    break;

  case 7: /* annotated_formula: tff_annotated  */
#line 238 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2922 "y.tab.c"
    break;

  case 8: /* annotated_formula: tcf_annotated  */
#line 239 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2928 "y.tab.c"
    break;

  case 9: /* annotated_formula: fof_annotated  */
#line 240 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2934 "y.tab.c"
    break;

  case 10: /* annotated_formula: cnf_annotated  */
#line 241 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2940 "y.tab.c"
    break;

  case 11: /* annotated_formula: tpi_annotated  */
#line 242 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2946 "y.tab.c"
    break;

  case 12: /* tpi_annotated: _LIT_tpi LPAREN name COMMA formula_role COMMA tpi_formula annotations RPAREN PERIOD  */
#line 245 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("tpi_annotated", P_TOKEN("_LIT_tpi ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 2952 "y.tab.c"
    break;

  case 13: /* tpi_formula: fof_formula  */
#line 248 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("tpi_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2958 "y.tab.c"
    break;

  case 14: /* thf_annotated: _LIT_thf LPAREN name COMMA formula_role COMMA thf_formula annotations RPAREN PERIOD  */
#line 251 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("thf_annotated", P_TOKEN("_LIT_thf ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 2964 "y.tab.c"
    break;

  case 15: /* tff_annotated: _LIT_tff LPAREN name COMMA formula_role COMMA tff_formula annotations RPAREN PERIOD  */
#line 254 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("tff_annotated", P_TOKEN("_LIT_tff ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 2970 "y.tab.c"
    break;

  case 16: /* tcf_annotated: _LIT_tcf LPAREN name COMMA formula_role COMMA tcf_formula annotations RPAREN PERIOD  */
#line 257 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("tcf_annotated", P_TOKEN("_LIT_tcf ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 2976 "y.tab.c"
    break;

  case 17: /* fof_annotated: _LIT_fof LPAREN name COMMA formula_role COMMA fof_formula annotations RPAREN PERIOD  */
#line 260 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("fof_annotated", P_TOKEN("_LIT_fof ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 2982 "y.tab.c"
    break;

  case 18: /* cnf_annotated: _LIT_cnf LPAREN name COMMA formula_role COMMA cnf_formula annotations RPAREN PERIOD  */
#line 263 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("cnf_annotated", P_TOKEN("_LIT_cnf ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 2988 "y.tab.c"
    break;

  case 19: /* annotations: COMMA source optional_info  */
#line 266 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("annotations", P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2994 "y.tab.c"
    break;

  case 20: /* annotations: nothing  */
#line 267 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("annotations", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3000 "y.tab.c"
    break;

  case 21: /* formula_role: lower_word  */
#line 270 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("formula_role", P_TOKEN("lower_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3006 "y.tab.c"
    break;

  case 22: /* formula_role: lower_word MINUS general_term  */
#line 271 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("formula_role", P_TOKEN("lower_word ", (yyvsp[-2].ival)), P_TOKEN("MINUS ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3012 "y.tab.c"
    break;

  case 23: /* thf_formula: thf_logic_formula  */
#line 274 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3018 "y.tab.c"
    break;

  case 24: /* thf_formula: thf_atom_typing  */
#line 275 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3024 "y.tab.c"
    break;

  case 25: /* thf_formula: thf_subtype  */
#line 276 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("thf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3030 "y.tab.c"
    break;

  case 26: /* thf_logic_formula: thf_unitary_formula  */
#line 279 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3036 "y.tab.c"
    break;

  case 27: /* thf_logic_formula: thf_unary_formula  */
#line 280 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3042 "y.tab.c"
    break;

  case 28: /* thf_logic_formula: thf_binary_formula  */
#line 281 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3048 "y.tab.c"
    break;

  case 29: /* thf_logic_formula: thf_defined_infix  */
#line 282 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3054 "y.tab.c"
    break;

  case 30: /* thf_logic_formula: thf_definition  */
#line 283 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3060 "y.tab.c"
    break;

  case 31: /* thf_logic_formula: thf_sequent  */
#line 284 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3066 "y.tab.c"
    break;

  case 32: /* thf_binary_formula: thf_binary_nonassoc  */
#line 287 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3072 "y.tab.c"
    break;

  case 33: /* thf_binary_formula: thf_binary_assoc  */
#line 288 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3078 "y.tab.c"
    break;

  case 34: /* thf_binary_formula: thf_binary_type  */
#line 289 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3084 "y.tab.c"
    break;

  case 35: /* thf_binary_nonassoc: thf_unit_formula nonassoc_connective thf_unit_formula  */
#line 292 "SyntaxBNF.y"
                                                                            {(yyval.pval) = P_BUILD("thf_binary_nonassoc", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3090 "y.tab.c"
    break;

  case 36: /* thf_binary_assoc: thf_or_formula  */
#line 295 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("thf_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3096 "y.tab.c"
    break;

  case 37: /* thf_binary_assoc: thf_and_formula  */
#line 296 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3102 "y.tab.c"
    break;

  case 38: /* thf_binary_assoc: thf_apply_formula  */
#line 297 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3108 "y.tab.c"
    break;

  case 39: /* thf_or_formula: thf_unit_formula VLINE thf_unit_formula  */
#line 300 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("thf_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3114 "y.tab.c"
    break;

  case 40: /* thf_or_formula: thf_or_formula VLINE thf_unit_formula  */
#line 301 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("thf_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3120 "y.tab.c"
    break;

  case 41: /* thf_and_formula: thf_unit_formula AMPERSAND thf_unit_formula  */
#line 304 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3126 "y.tab.c"
    break;

  case 42: /* thf_and_formula: thf_and_formula AMPERSAND thf_unit_formula  */
#line 305 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3132 "y.tab.c"
    break;

  case 43: /* thf_apply_formula: thf_unit_formula AT_SIGN thf_unit_formula  */
#line 308 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_apply_formula", (yyvsp[-2].pval), P_TOKEN("AT_SIGN ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3138 "y.tab.c"
    break;

  case 44: /* thf_apply_formula: thf_apply_formula AT_SIGN thf_unit_formula  */
#line 309 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_apply_formula", (yyvsp[-2].pval), P_TOKEN("AT_SIGN ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3144 "y.tab.c"
    break;

  case 45: /* thf_unit_formula: thf_unitary_formula  */
#line 312 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3150 "y.tab.c"
    break;

  case 46: /* thf_unit_formula: thf_unary_formula  */
#line 313 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3156 "y.tab.c"
    break;

  case 47: /* thf_unit_formula: thf_defined_infix  */
#line 314 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3162 "y.tab.c"
    break;

  case 48: /* thf_preunit_formula: thf_unitary_formula  */
#line 317 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("thf_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3168 "y.tab.c"
    break;

  case 49: /* thf_preunit_formula: thf_prefix_unary  */
#line 318 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3174 "y.tab.c"
    break;

  case 50: /* thf_unitary_formula: thf_quantified_formula  */
#line 321 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("thf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3180 "y.tab.c"
    break;

  case 51: /* thf_unitary_formula: thf_atomic_formula  */
#line 322 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3186 "y.tab.c"
    break;

  case 52: /* thf_unitary_formula: variable  */
#line 323 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("thf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3192 "y.tab.c"
    break;

  case 53: /* thf_unitary_formula: LPAREN thf_logic_formula RPAREN  */
#line 324 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("thf_unitary_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3198 "y.tab.c"
    break;

  case 54: /* thf_quantified_formula: thf_quantification thf_unit_formula  */
#line 327 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("thf_quantified_formula", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3204 "y.tab.c"
    break;

  case 55: /* thf_quantification: thf_quantifier LBRKT thf_variable_list RBRKT COLON  */
#line 330 "SyntaxBNF.y"
                                                                        {(yyval.pval) = P_BUILD("thf_quantification", (yyvsp[-4].pval), P_TOKEN("LBRKT ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("RBRKT ", (yyvsp[-1].ival)), P_TOKEN("COLON ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL);}
#line 3210 "y.tab.c"
    break;

  case 56: /* thf_variable_list: thf_typed_variable  */
#line 333 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_variable_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3216 "y.tab.c"
    break;

  case 57: /* thf_variable_list: thf_typed_variable COMMA thf_variable_list  */
#line 334 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_variable_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3222 "y.tab.c"
    break;

  case 58: /* thf_typed_variable: variable COLON thf_top_level_type  */
#line 337 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("thf_typed_variable", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3228 "y.tab.c"
    break;

  case 59: /* thf_unary_formula: thf_prefix_unary  */
#line 340 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3234 "y.tab.c"
    break;

  case 60: /* thf_unary_formula: thf_infix_unary  */
#line 341 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3240 "y.tab.c"
    break;

  case 61: /* thf_prefix_unary: thf_unary_connective thf_preunit_formula  */
#line 344 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("thf_prefix_unary", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3246 "y.tab.c"
    break;

  case 62: /* thf_infix_unary: thf_unitary_term infix_inequality thf_unitary_term  */
#line 347 "SyntaxBNF.y"
                                                                     {(yyval.pval) = P_BUILD("thf_infix_unary", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3252 "y.tab.c"
    break;

  case 63: /* thf_atomic_formula: thf_plain_atomic  */
#line 350 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3258 "y.tab.c"
    break;

  case 64: /* thf_atomic_formula: thf_defined_atomic  */
#line 351 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3264 "y.tab.c"
    break;

  case 65: /* thf_atomic_formula: thf_system_atomic  */
#line 352 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3270 "y.tab.c"
    break;

  case 66: /* thf_plain_atomic: constant  */
#line 355 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("thf_plain_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3276 "y.tab.c"
    break;

  case 67: /* thf_plain_atomic: thf_tuple  */
#line 356 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_plain_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3282 "y.tab.c"
    break;

  case 68: /* thf_defined_atomic: defined_constant  */
#line 359 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3288 "y.tab.c"
    break;

  case 69: /* thf_defined_atomic: thf_defined_term  */
#line 360 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3294 "y.tab.c"
    break;

  case 70: /* thf_defined_atomic: LPAREN thf_conn_term RPAREN  */
#line 361 "SyntaxBNF.y"
                                                  {(yyval.pval) = P_BUILD("thf_defined_atomic", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3300 "y.tab.c"
    break;

  case 71: /* thf_defined_atomic: nhf_long_connective  */
#line 362 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3306 "y.tab.c"
    break;

  case 72: /* thf_defined_atomic: thf_let  */
#line 363 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3312 "y.tab.c"
    break;

  case 73: /* thf_defined_term: defined_term  */
#line 366 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3318 "y.tab.c"
    break;

  case 74: /* thf_defined_term: th1_defined_term  */
#line 367 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3324 "y.tab.c"
    break;

  case 75: /* thf_defined_infix: thf_unitary_term defined_infix_pred thf_unitary_term  */
#line 370 "SyntaxBNF.y"
                                                                         {(yyval.pval) = P_BUILD("thf_defined_infix", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3330 "y.tab.c"
    break;

  case 76: /* thf_system_atomic: system_constant  */
#line 373 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("thf_system_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3336 "y.tab.c"
    break;

  case 77: /* thf_let: _DLR_let LPAREN thf_let_types COMMA thf_let_defns COMMA thf_logic_formula RPAREN  */
#line 376 "SyntaxBNF.y"
                                                                                           {(yyval.pval) = P_BUILD("thf_let", P_TOKEN("_DLR_let ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 3342 "y.tab.c"
    break;

  case 78: /* thf_let_types: thf_atom_typing  */
#line 379 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_let_types", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3348 "y.tab.c"
    break;

  case 79: /* thf_let_types: LBRKT thf_atom_typing_list RBRKT  */
#line 380 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("thf_let_types", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3354 "y.tab.c"
    break;

  case 80: /* thf_atom_typing_list: thf_atom_typing  */
#line 383 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_atom_typing_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3360 "y.tab.c"
    break;

  case 81: /* thf_atom_typing_list: thf_atom_typing COMMA thf_atom_typing_list  */
#line 384 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_atom_typing_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3366 "y.tab.c"
    break;

  case 82: /* thf_let_defns: thf_let_defn  */
#line 387 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("thf_let_defns", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3372 "y.tab.c"
    break;

  case 83: /* thf_let_defns: LBRKT thf_let_defn_list RBRKT  */
#line 388 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("thf_let_defns", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3378 "y.tab.c"
    break;

  case 84: /* thf_let_defn: thf_logic_formula assignment thf_logic_formula  */
#line 391 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_let_defn", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3384 "y.tab.c"
    break;

  case 85: /* thf_let_defn_list: thf_let_defn  */
#line 394 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("thf_let_defn_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3390 "y.tab.c"
    break;

  case 86: /* thf_let_defn_list: thf_let_defn COMMA thf_let_defn_list  */
#line 395 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_let_defn_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3396 "y.tab.c"
    break;

  case 87: /* thf_unitary_term: thf_atomic_formula  */
#line 398 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3402 "y.tab.c"
    break;

  case 88: /* thf_unitary_term: variable  */
#line 399 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("thf_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3408 "y.tab.c"
    break;

  case 89: /* thf_unitary_term: LPAREN thf_logic_formula RPAREN  */
#line 400 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("thf_unitary_term", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3414 "y.tab.c"
    break;

  case 90: /* thf_conn_term: nonassoc_connective  */
#line 403 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3420 "y.tab.c"
    break;

  case 91: /* thf_conn_term: assoc_connective  */
#line 404 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3426 "y.tab.c"
    break;

  case 92: /* thf_conn_term: infix_equality  */
#line 405 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3432 "y.tab.c"
    break;

  case 93: /* thf_conn_term: infix_inequality  */
#line 406 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3438 "y.tab.c"
    break;

  case 94: /* thf_conn_term: thf_unary_connective  */
#line 407 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3444 "y.tab.c"
    break;

  case 95: /* thf_tuple: LBRKT RBRKT  */
#line 410 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("thf_tuple", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3450 "y.tab.c"
    break;

  case 96: /* thf_tuple: LBRKT thf_formula_list RBRKT  */
#line 411 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("thf_tuple", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3456 "y.tab.c"
    break;

  case 97: /* thf_formula_list: thf_logic_formula  */
#line 414 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_formula_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3462 "y.tab.c"
    break;

  case 98: /* thf_formula_list: thf_logic_formula COMMA thf_formula_list  */
#line 415 "SyntaxBNF.y"
                                                               {(yyval.pval) = P_BUILD("thf_formula_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3468 "y.tab.c"
    break;

  case 99: /* thf_atom_typing: typeable_atom COLON thf_top_level_type  */
#line 418 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("thf_atom_typing", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3474 "y.tab.c"
    break;

  case 100: /* thf_atom_typing: LPAREN thf_atom_typing RPAREN  */
#line 419 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("thf_atom_typing", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3480 "y.tab.c"
    break;

  case 101: /* thf_top_level_type: thf_unitary_type  */
#line 422 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3486 "y.tab.c"
    break;

  case 102: /* thf_top_level_type: thf_mapping_type  */
#line 423 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3492 "y.tab.c"
    break;

  case 103: /* thf_top_level_type: thf_apply_type  */
#line 424 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3498 "y.tab.c"
    break;

  case 104: /* thf_unitary_type: thf_unitary_formula  */
#line 427 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_unitary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3504 "y.tab.c"
    break;

  case 105: /* thf_apply_type: thf_apply_formula  */
#line 430 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("thf_apply_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3510 "y.tab.c"
    break;

  case 106: /* thf_binary_type: thf_mapping_type  */
#line 433 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("thf_binary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3516 "y.tab.c"
    break;

  case 107: /* thf_binary_type: thf_xprod_type  */
#line 434 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_binary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3522 "y.tab.c"
    break;

  case 108: /* thf_binary_type: thf_union_type  */
#line 435 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_binary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3528 "y.tab.c"
    break;

  case 109: /* thf_mapping_type: thf_unitary_type arrow thf_unitary_type  */
#line 438 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_mapping_type", (yyvsp[-2].pval), P_TOKEN("arrow ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3534 "y.tab.c"
    break;

  case 110: /* thf_mapping_type: thf_unitary_type arrow thf_mapping_type  */
#line 439 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_mapping_type", (yyvsp[-2].pval), P_TOKEN("arrow ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3540 "y.tab.c"
    break;

  case 111: /* thf_xprod_type: thf_unitary_type STAR thf_unitary_type  */
#line 442 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("thf_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3546 "y.tab.c"
    break;

  case 112: /* thf_xprod_type: thf_xprod_type STAR thf_unitary_type  */
#line 443 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3552 "y.tab.c"
    break;

  case 113: /* thf_union_type: thf_unitary_type plus thf_unitary_type  */
#line 446 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("thf_union_type", (yyvsp[-2].pval), P_TOKEN("plus ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3558 "y.tab.c"
    break;

  case 114: /* thf_union_type: thf_union_type plus thf_unitary_type  */
#line 447 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_union_type", (yyvsp[-2].pval), P_TOKEN("plus ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3564 "y.tab.c"
    break;

  case 115: /* thf_subtype: atomic_type subtype_sign atomic_type  */
#line 450 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("thf_subtype", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3570 "y.tab.c"
    break;

  case 116: /* thf_definition: thf_atomic_formula identical thf_logic_formula  */
#line 453 "SyntaxBNF.y"
                                                                {(yyval.pval) = P_BUILD("thf_definition", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3576 "y.tab.c"
    break;

  case 117: /* thf_sequent: thf_tuple gentzen_arrow thf_tuple  */
#line 456 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("thf_sequent", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3582 "y.tab.c"
    break;

  case 118: /* tff_formula: tff_logic_formula  */
#line 459 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3588 "y.tab.c"
    break;

  case 119: /* tff_formula: tff_atom_typing  */
#line 460 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3594 "y.tab.c"
    break;

  case 120: /* tff_formula: tff_subtype  */
#line 461 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tff_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3600 "y.tab.c"
    break;

  case 121: /* tff_logic_formula: tff_unitary_formula  */
#line 464 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3606 "y.tab.c"
    break;

  case 122: /* tff_logic_formula: tff_unary_formula  */
#line 465 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3612 "y.tab.c"
    break;

  case 123: /* tff_logic_formula: tff_binary_formula  */
#line 466 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3618 "y.tab.c"
    break;

  case 124: /* tff_logic_formula: tff_defined_infix  */
#line 467 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3624 "y.tab.c"
    break;

  case 125: /* tff_logic_formula: txf_definition  */
#line 468 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3630 "y.tab.c"
    break;

  case 126: /* tff_logic_formula: txf_sequent  */
#line 469 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3636 "y.tab.c"
    break;

  case 127: /* tff_binary_formula: tff_binary_nonassoc  */
#line 472 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3642 "y.tab.c"
    break;

  case 128: /* tff_binary_formula: tff_binary_assoc  */
#line 473 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3648 "y.tab.c"
    break;

  case 129: /* tff_binary_nonassoc: tff_unit_formula nonassoc_connective tff_unit_formula  */
#line 476 "SyntaxBNF.y"
                                                                            {(yyval.pval) = P_BUILD("tff_binary_nonassoc", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3654 "y.tab.c"
    break;

  case 130: /* tff_binary_assoc: tff_or_formula  */
#line 479 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tff_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3660 "y.tab.c"
    break;

  case 131: /* tff_binary_assoc: tff_and_formula  */
#line 480 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3666 "y.tab.c"
    break;

  case 132: /* tff_or_formula: tff_unit_formula VLINE tff_unit_formula  */
#line 483 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("tff_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3672 "y.tab.c"
    break;

  case 133: /* tff_or_formula: tff_or_formula VLINE tff_unit_formula  */
#line 484 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("tff_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3678 "y.tab.c"
    break;

  case 134: /* tff_and_formula: tff_unit_formula AMPERSAND tff_unit_formula  */
#line 487 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("tff_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3684 "y.tab.c"
    break;

  case 135: /* tff_and_formula: tff_and_formula AMPERSAND tff_unit_formula  */
#line 488 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("tff_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3690 "y.tab.c"
    break;

  case 136: /* tff_unit_formula: tff_unitary_formula  */
#line 491 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3696 "y.tab.c"
    break;

  case 137: /* tff_unit_formula: tff_unary_formula  */
#line 492 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3702 "y.tab.c"
    break;

  case 138: /* tff_unit_formula: tff_defined_infix  */
#line 493 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3708 "y.tab.c"
    break;

  case 139: /* tff_preunit_formula: tff_unitary_formula  */
#line 496 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3714 "y.tab.c"
    break;

  case 140: /* tff_preunit_formula: tff_prefix_unary  */
#line 497 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3720 "y.tab.c"
    break;

  case 141: /* tff_unitary_formula: tff_quantified_formula  */
#line 500 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("tff_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3726 "y.tab.c"
    break;

  case 142: /* tff_unitary_formula: tff_atomic_formula  */
#line 501 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3732 "y.tab.c"
    break;

  case 143: /* tff_unitary_formula: txf_unitary_formula  */
#line 502 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3738 "y.tab.c"
    break;

  case 144: /* tff_unitary_formula: LPAREN tff_logic_formula RPAREN  */
#line 503 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("tff_unitary_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3744 "y.tab.c"
    break;

  case 145: /* txf_unitary_formula: variable  */
#line 506 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("txf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3750 "y.tab.c"
    break;

  case 146: /* tff_quantified_formula: tff_quantifier LBRKT tff_variable_list RBRKT COLON tff_unit_formula  */
#line 509 "SyntaxBNF.y"
                                                                                             {(yyval.pval) = P_BUILD("tff_quantified_formula", (yyvsp[-5].pval), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 3756 "y.tab.c"
    break;

  case 147: /* tff_variable_list: tff_variable  */
#line 512 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("tff_variable_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3762 "y.tab.c"
    break;

  case 148: /* tff_variable_list: tff_variable COMMA tff_variable_list  */
#line 513 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("tff_variable_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3768 "y.tab.c"
    break;

  case 149: /* tff_variable: tff_typed_variable  */
#line 516 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tff_variable", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3774 "y.tab.c"
    break;

  case 150: /* tff_variable: variable  */
#line 517 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_variable", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3780 "y.tab.c"
    break;

  case 151: /* tff_typed_variable: variable COLON tff_atomic_type  */
#line 520 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("tff_typed_variable", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3786 "y.tab.c"
    break;

  case 152: /* tff_unary_formula: tff_prefix_unary  */
#line 523 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3792 "y.tab.c"
    break;

  case 153: /* tff_unary_formula: tff_infix_unary  */
#line 524 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3798 "y.tab.c"
    break;

  case 154: /* tff_prefix_unary: tff_unary_connective tff_preunit_formula  */
#line 527 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("tff_prefix_unary", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3804 "y.tab.c"
    break;

  case 155: /* tff_infix_unary: tff_unitary_term infix_inequality tff_unitary_term  */
#line 530 "SyntaxBNF.y"
                                                                     {(yyval.pval) = P_BUILD("tff_infix_unary", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3810 "y.tab.c"
    break;

  case 156: /* tff_atomic_formula: tff_plain_atomic  */
#line 533 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3816 "y.tab.c"
    break;

  case 157: /* tff_atomic_formula: tff_defined_atomic  */
#line 534 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3822 "y.tab.c"
    break;

  case 158: /* tff_atomic_formula: tff_system_atomic  */
#line 535 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3828 "y.tab.c"
    break;

  case 159: /* tff_plain_atomic: constant  */
#line 538 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("tff_plain_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3834 "y.tab.c"
    break;

  case 160: /* tff_plain_atomic: functor LPAREN tff_arguments RPAREN  */
#line 539 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("tff_plain_atomic", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3840 "y.tab.c"
    break;

  case 161: /* tff_defined_atomic: tff_defined_plain  */
#line 542 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3846 "y.tab.c"
    break;

  case 162: /* tff_defined_plain: defined_constant  */
#line 545 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3852 "y.tab.c"
    break;

  case 163: /* tff_defined_plain: defined_functor LPAREN tff_arguments RPAREN  */
#line 546 "SyntaxBNF.y"
                                                                  {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3858 "y.tab.c"
    break;

  case 164: /* tff_defined_plain: nxf_atom  */
#line 547 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3864 "y.tab.c"
    break;

  case 165: /* tff_defined_plain: txf_let  */
#line 548 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3870 "y.tab.c"
    break;

  case 166: /* tff_defined_infix: tff_unitary_term defined_infix_pred tff_unitary_term  */
#line 551 "SyntaxBNF.y"
                                                                         {(yyval.pval) = P_BUILD("tff_defined_infix", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3876 "y.tab.c"
    break;

  case 167: /* tff_system_atomic: system_constant  */
#line 554 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("tff_system_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3882 "y.tab.c"
    break;

  case 168: /* tff_system_atomic: system_functor LPAREN tff_arguments RPAREN  */
#line 555 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("tff_system_atomic", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3888 "y.tab.c"
    break;

  case 169: /* txf_let: _DLR_let LPAREN txf_let_types COMMA txf_let_defns COMMA tff_term RPAREN  */
#line 558 "SyntaxBNF.y"
                                                                                  {(yyval.pval) = P_BUILD("txf_let", P_TOKEN("_DLR_let ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 3894 "y.tab.c"
    break;

  case 170: /* txf_let_types: tff_atom_typing  */
#line 561 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("txf_let_types", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3900 "y.tab.c"
    break;

  case 171: /* txf_let_types: LBRKT tff_atom_typing_list RBRKT  */
#line 562 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("txf_let_types", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3906 "y.tab.c"
    break;

  case 172: /* tff_atom_typing_list: tff_atom_typing  */
#line 565 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_atom_typing_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3912 "y.tab.c"
    break;

  case 173: /* tff_atom_typing_list: tff_atom_typing COMMA tff_atom_typing_list  */
#line 566 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("tff_atom_typing_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3918 "y.tab.c"
    break;

  case 174: /* txf_let_defns: txf_let_defn  */
#line 569 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("txf_let_defns", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3924 "y.tab.c"
    break;

  case 175: /* txf_let_defns: LBRKT txf_let_defn_list RBRKT  */
#line 570 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("txf_let_defns", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3930 "y.tab.c"
    break;

  case 176: /* txf_let_defn: txf_let_LHS assignment tff_term  */
#line 573 "SyntaxBNF.y"
                                               {(yyval.pval) = P_BUILD("txf_let_defn", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3936 "y.tab.c"
    break;

  case 177: /* txf_let_LHS: tff_plain_atomic  */
#line 576 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("txf_let_LHS", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3942 "y.tab.c"
    break;

  case 178: /* txf_let_LHS: txf_tuple  */
#line 577 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("txf_let_LHS", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3948 "y.tab.c"
    break;

  case 179: /* txf_let_defn_list: txf_let_defn  */
#line 580 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("txf_let_defn_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3954 "y.tab.c"
    break;

  case 180: /* txf_let_defn_list: txf_let_defn COMMA txf_let_defn_list  */
#line 581 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("txf_let_defn_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3960 "y.tab.c"
    break;

  case 181: /* nxf_atom: nxf_long_connective AT_SIGN LPAREN tff_arguments RPAREN  */
#line 584 "SyntaxBNF.y"
                                                                   {(yyval.pval) = P_BUILD("nxf_atom", (yyvsp[-4].pval), P_TOKEN("AT_SIGN ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL);}
#line 3966 "y.tab.c"
    break;

  case 182: /* tff_term: tff_logic_formula  */
#line 587 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("tff_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3972 "y.tab.c"
    break;

  case 183: /* tff_term: defined_term  */
#line 588 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3978 "y.tab.c"
    break;

  case 184: /* tff_term: txf_tuple  */
#line 589 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3984 "y.tab.c"
    break;

  case 185: /* tff_unitary_term: tff_atomic_formula  */
#line 592 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3990 "y.tab.c"
    break;

  case 186: /* tff_unitary_term: defined_term  */
#line 593 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3996 "y.tab.c"
    break;

  case 187: /* tff_unitary_term: txf_tuple  */
#line 594 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4002 "y.tab.c"
    break;

  case 188: /* tff_unitary_term: variable  */
#line 595 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4008 "y.tab.c"
    break;

  case 189: /* tff_unitary_term: LPAREN tff_logic_formula RPAREN  */
#line 596 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("tff_unitary_term", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4014 "y.tab.c"
    break;

  case 190: /* txf_tuple: LBRKT RBRKT  */
#line 599 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("txf_tuple", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4020 "y.tab.c"
    break;

  case 191: /* txf_tuple: LBRKT tff_arguments RBRKT  */
#line 600 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("txf_tuple", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4026 "y.tab.c"
    break;

  case 192: /* tff_arguments: tff_term  */
#line 603 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_arguments", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4032 "y.tab.c"
    break;

  case 193: /* tff_arguments: tff_term COMMA tff_arguments  */
#line 604 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("tff_arguments", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4038 "y.tab.c"
    break;

  case 194: /* tff_atom_typing: typeable_atom COLON tff_top_level_type  */
#line 607 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("tff_atom_typing", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4044 "y.tab.c"
    break;

  case 195: /* tff_atom_typing: LPAREN tff_atom_typing RPAREN  */
#line 608 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("tff_atom_typing", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4050 "y.tab.c"
    break;

  case 196: /* tff_top_level_type: tff_atomic_type  */
#line 611 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4056 "y.tab.c"
    break;

  case 197: /* tff_top_level_type: tff_non_atomic_type  */
#line 612 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4062 "y.tab.c"
    break;

  case 198: /* tff_non_atomic_type: tff_mapping_type  */
#line 615 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_non_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4068 "y.tab.c"
    break;

  case 199: /* tff_non_atomic_type: tf1_quantified_type  */
#line 616 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_non_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4074 "y.tab.c"
    break;

  case 200: /* tff_non_atomic_type: LPAREN tff_non_atomic_type RPAREN  */
#line 617 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("tff_non_atomic_type", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4080 "y.tab.c"
    break;

  case 201: /* tf1_quantified_type: type_quantifier LBRKT tff_variable_list RBRKT COLON tff_monotype  */
#line 620 "SyntaxBNF.y"
                                                                                       {(yyval.pval) = P_BUILD("tf1_quantified_type", (yyvsp[-5].pval), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 4086 "y.tab.c"
    break;

  case 202: /* tff_monotype: tff_atomic_type  */
#line 623 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_monotype", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4092 "y.tab.c"
    break;

  case 203: /* tff_monotype: LPAREN tff_mapping_type RPAREN  */
#line 624 "SyntaxBNF.y"
                                                     {(yyval.pval) = P_BUILD("tff_monotype", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4098 "y.tab.c"
    break;

  case 204: /* tff_monotype: tf1_quantified_type  */
#line 625 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_monotype", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4104 "y.tab.c"
    break;

  case 205: /* tff_unitary_type: tff_atomic_type  */
#line 628 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_unitary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4110 "y.tab.c"
    break;

  case 206: /* tff_unitary_type: LPAREN tff_xprod_type RPAREN  */
#line 629 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("tff_unitary_type", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4116 "y.tab.c"
    break;

  case 207: /* tff_atomic_type: type_constant  */
#line 632 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4122 "y.tab.c"
    break;

  case 208: /* tff_atomic_type: defined_type  */
#line 633 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4128 "y.tab.c"
    break;

  case 209: /* tff_atomic_type: variable  */
#line 634 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4134 "y.tab.c"
    break;

  case 210: /* tff_atomic_type: type_functor LPAREN tff_type_arguments RPAREN  */
#line 635 "SyntaxBNF.y"
                                                                    {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4140 "y.tab.c"
    break;

  case 211: /* tff_atomic_type: LPAREN tff_atomic_type RPAREN  */
#line 636 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("tff_atomic_type", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4146 "y.tab.c"
    break;

  case 212: /* tff_atomic_type: txf_tuple_type  */
#line 637 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4152 "y.tab.c"
    break;

  case 213: /* tff_type_arguments: tff_atomic_type  */
#line 640 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_type_arguments", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4158 "y.tab.c"
    break;

  case 214: /* tff_type_arguments: tff_atomic_type COMMA tff_type_arguments  */
#line 641 "SyntaxBNF.y"
                                                               {(yyval.pval) = P_BUILD("tff_type_arguments", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4164 "y.tab.c"
    break;

  case 215: /* tff_mapping_type: tff_unitary_type arrow tff_atomic_type  */
#line 644 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("tff_mapping_type", (yyvsp[-2].pval), P_TOKEN("arrow ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4170 "y.tab.c"
    break;

  case 216: /* tff_xprod_type: tff_unitary_type STAR tff_atomic_type  */
#line 647 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("tff_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4176 "y.tab.c"
    break;

  case 217: /* tff_xprod_type: tff_xprod_type STAR tff_atomic_type  */
#line 648 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("tff_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4182 "y.tab.c"
    break;

  case 218: /* txf_tuple_type: LBRKT tff_type_list RBRKT  */
#line 651 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("txf_tuple_type", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4188 "y.tab.c"
    break;

  case 219: /* tff_type_list: tff_top_level_type  */
#line 654 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_type_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4194 "y.tab.c"
    break;

  case 220: /* tff_type_list: tff_top_level_type COMMA tff_type_list  */
#line 655 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("tff_type_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4200 "y.tab.c"
    break;

  case 221: /* tff_subtype: atomic_type subtype_sign atomic_type  */
#line 658 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("tff_subtype", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4206 "y.tab.c"
    break;

  case 222: /* txf_definition: tff_atomic_formula identical tff_term  */
#line 661 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("txf_definition", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4212 "y.tab.c"
    break;

  case 223: /* txf_sequent: txf_tuple gentzen_arrow txf_tuple  */
#line 664 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("txf_sequent", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4218 "y.tab.c"
    break;

  case 224: /* nhf_long_connective: LBRACE ntf_connective_name RBRACE  */
#line 667 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("nhf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4224 "y.tab.c"
    break;

  case 225: /* nhf_long_connective: LBRACE ntf_connective_name LPAREN nhf_parameter_list RPAREN RBRACE  */
#line 668 "SyntaxBNF.y"
                                                                                         {(yyval.pval) = P_BUILD("nhf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-5].ival)), (yyvsp[-4].pval), P_TOKEN("LPAREN ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL);}
#line 4230 "y.tab.c"
    break;

  case 226: /* nhf_parameter_list: nhf_parameter  */
#line 671 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("nhf_parameter_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4236 "y.tab.c"
    break;

  case 227: /* nhf_parameter_list: nhf_parameter COMMA nhf_parameter_list  */
#line 672 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("nhf_parameter_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4242 "y.tab.c"
    break;

  case 228: /* nhf_parameter: ntf_index  */
#line 675 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("nhf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4248 "y.tab.c"
    break;

  case 229: /* nhf_parameter: nhf_key_pair  */
#line 676 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("nhf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4254 "y.tab.c"
    break;

  case 230: /* nhf_key_pair: thf_definition  */
#line 679 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("nhf_key_pair", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4260 "y.tab.c"
    break;

  case 231: /* nxf_long_connective: LBRACE ntf_connective_name RBRACE  */
#line 682 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("nxf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4266 "y.tab.c"
    break;

  case 232: /* nxf_long_connective: LBRACE ntf_connective_name LPAREN nxf_parameter_list RPAREN RBRACE  */
#line 683 "SyntaxBNF.y"
                                                                                         {(yyval.pval) = P_BUILD("nxf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-5].ival)), (yyvsp[-4].pval), P_TOKEN("LPAREN ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL);}
#line 4272 "y.tab.c"
    break;

  case 233: /* nxf_parameter_list: nxf_parameter  */
#line 686 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("nxf_parameter_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4278 "y.tab.c"
    break;

  case 234: /* nxf_parameter_list: nxf_parameter COMMA nxf_parameter_list  */
#line 687 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("nxf_parameter_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4284 "y.tab.c"
    break;

  case 235: /* nxf_parameter: ntf_index  */
#line 690 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("nxf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4290 "y.tab.c"
    break;

  case 236: /* nxf_parameter: nxf_key_pair  */
#line 691 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("nxf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4296 "y.tab.c"
    break;

  case 237: /* nxf_key_pair: txf_definition  */
#line 694 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("nxf_key_pair", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4302 "y.tab.c"
    break;

  case 238: /* ntf_connective_name: ntf_defined_connective  */
#line 697 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("ntf_connective_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4308 "y.tab.c"
    break;

  case 239: /* ntf_connective_name: atomic_system_word  */
#line 698 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("ntf_connective_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4314 "y.tab.c"
    break;

  case 240: /* ntf_defined_connective: atomic_defined_word  */
#line 701 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("ntf_defined_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4320 "y.tab.c"
    break;

  case 241: /* ntf_index: hash tff_unitary_term  */
#line 704 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("ntf_index", P_TOKEN("hash ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4326 "y.tab.c"
    break;

  case 242: /* ntf_short_connective: LBRKT PERIOD RBRKT  */
#line 707 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4332 "y.tab.c"
    break;

  case 243: /* ntf_short_connective: less_sign PERIOD arrow  */
#line 708 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("less_sign ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("arrow ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4338 "y.tab.c"
    break;

  case 244: /* ntf_short_connective: LBRACE PERIOD RBRACE  */
#line 709 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("LBRACE ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4344 "y.tab.c"
    break;

  case 245: /* ntf_short_connective: LPAREN PERIOD RPAREN  */
#line 710 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4350 "y.tab.c"
    break;

  case 246: /* tcf_formula: tcf_logic_formula  */
#line 713 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tcf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4356 "y.tab.c"
    break;

  case 247: /* tcf_formula: tff_atom_typing  */
#line 714 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tcf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4362 "y.tab.c"
    break;

  case 248: /* tcf_logic_formula: tcf_quantified_formula  */
#line 717 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("tcf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4368 "y.tab.c"
    break;

  case 249: /* tcf_logic_formula: cnf_formula  */
#line 718 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tcf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4374 "y.tab.c"
    break;

  case 250: /* tcf_quantified_formula: EXCLAMATION LBRKT tff_variable_list RBRKT COLON tcf_logic_formula  */
#line 721 "SyntaxBNF.y"
                                                                                           {(yyval.pval) = P_BUILD("tcf_quantified_formula", P_TOKEN("EXCLAMATION ", (yyvsp[-5].ival)), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 4380 "y.tab.c"
    break;

  case 251: /* fof_formula: fof_logic_formula  */
#line 724 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("fof_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4386 "y.tab.c"
    break;

  case 252: /* fof_formula: fof_sequent  */
#line 725 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("fof_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4392 "y.tab.c"
    break;

  case 253: /* fof_logic_formula: fof_binary_formula  */
#line 728 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("fof_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4398 "y.tab.c"
    break;

  case 254: /* fof_logic_formula: fof_unary_formula  */
#line 729 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("fof_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4404 "y.tab.c"
    break;

  case 255: /* fof_logic_formula: fof_unitary_formula  */
#line 730 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("fof_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4410 "y.tab.c"
    break;

  case 256: /* fof_binary_formula: fof_binary_nonassoc  */
#line 733 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("fof_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4416 "y.tab.c"
    break;

  case 257: /* fof_binary_formula: fof_binary_assoc  */
#line 734 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("fof_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4422 "y.tab.c"
    break;

  case 258: /* fof_binary_nonassoc: fof_unit_formula nonassoc_connective fof_unit_formula  */
#line 737 "SyntaxBNF.y"
                                                                            {(yyval.pval) = P_BUILD("fof_binary_nonassoc", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4428 "y.tab.c"
    break;

  case 259: /* fof_binary_assoc: fof_or_formula  */
#line 740 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("fof_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4434 "y.tab.c"
    break;

  case 260: /* fof_binary_assoc: fof_and_formula  */
#line 741 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("fof_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4440 "y.tab.c"
    break;

  case 261: /* fof_or_formula: fof_unit_formula VLINE fof_unit_formula  */
#line 744 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("fof_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4446 "y.tab.c"
    break;

  case 262: /* fof_or_formula: fof_or_formula VLINE fof_unit_formula  */
#line 745 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("fof_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4452 "y.tab.c"
    break;

  case 263: /* fof_and_formula: fof_unit_formula AMPERSAND fof_unit_formula  */
#line 748 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("fof_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4458 "y.tab.c"
    break;

  case 264: /* fof_and_formula: fof_and_formula AMPERSAND fof_unit_formula  */
#line 749 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("fof_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4464 "y.tab.c"
    break;

  case 265: /* fof_unary_formula: unary_connective fof_unit_formula  */
#line 752 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("fof_unary_formula", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4470 "y.tab.c"
    break;

  case 266: /* fof_unary_formula: fof_infix_unary  */
#line 753 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("fof_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4476 "y.tab.c"
    break;

  case 267: /* fof_infix_unary: fof_term infix_inequality fof_term  */
#line 756 "SyntaxBNF.y"
                                                     {(yyval.pval) = P_BUILD("fof_infix_unary", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4482 "y.tab.c"
    break;

  case 268: /* fof_unit_formula: fof_unitary_formula  */
#line 759 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("fof_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4488 "y.tab.c"
    break;

  case 269: /* fof_unit_formula: fof_unary_formula  */
#line 760 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("fof_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4494 "y.tab.c"
    break;

  case 270: /* fof_unitary_formula: fof_quantified_formula  */
#line 763 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("fof_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4500 "y.tab.c"
    break;

  case 271: /* fof_unitary_formula: fof_atomic_formula  */
#line 764 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("fof_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4506 "y.tab.c"
    break;

  case 272: /* fof_unitary_formula: LPAREN fof_logic_formula RPAREN  */
#line 765 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("fof_unitary_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4512 "y.tab.c"
    break;

  case 273: /* fof_quantified_formula: fof_quantifier LBRKT fof_variable_list RBRKT COLON fof_unit_formula  */
#line 768 "SyntaxBNF.y"
                                                                                             {(yyval.pval) = P_BUILD("fof_quantified_formula", (yyvsp[-5].pval), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 4518 "y.tab.c"
    break;

  case 274: /* fof_variable_list: variable  */
#line 771 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("fof_variable_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4524 "y.tab.c"
    break;

  case 275: /* fof_variable_list: variable COMMA fof_variable_list  */
#line 772 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("fof_variable_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4530 "y.tab.c"
    break;

  case 276: /* fof_atomic_formula: fof_plain_atomic_formula  */
#line 775 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("fof_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4536 "y.tab.c"
    break;

  case 277: /* fof_atomic_formula: fof_defined_atomic_formula  */
#line 776 "SyntaxBNF.y"
                                                 {(yyval.pval) = P_BUILD("fof_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4542 "y.tab.c"
    break;

  case 278: /* fof_atomic_formula: fof_system_atomic_formula  */
#line 777 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("fof_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4548 "y.tab.c"
    break;

  case 279: /* fof_plain_atomic_formula: fof_plain_term  */
#line 780 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("fof_plain_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4554 "y.tab.c"
    break;

  case 280: /* fof_defined_atomic_formula: fof_defined_plain_formula  */
#line 783 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("fof_defined_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4560 "y.tab.c"
    break;

  case 281: /* fof_defined_atomic_formula: fof_defined_infix_formula  */
#line 784 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("fof_defined_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4566 "y.tab.c"
    break;

  case 282: /* fof_defined_plain_formula: fof_defined_plain_term  */
#line 787 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("fof_defined_plain_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4572 "y.tab.c"
    break;

  case 283: /* fof_defined_infix_formula: fof_term defined_infix_pred fof_term  */
#line 790 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("fof_defined_infix_formula", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4578 "y.tab.c"
    break;

  case 284: /* fof_system_atomic_formula: fof_system_term  */
#line 793 "SyntaxBNF.y"
                                            {(yyval.pval) = P_BUILD("fof_system_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4584 "y.tab.c"
    break;

  case 285: /* fof_plain_term: constant  */
#line 796 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("fof_plain_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4590 "y.tab.c"
    break;

  case 286: /* fof_plain_term: functor LPAREN fof_arguments RPAREN  */
#line 797 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("fof_plain_term", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4596 "y.tab.c"
    break;

  case 287: /* fof_defined_term: defined_term  */
#line 800 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("fof_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4602 "y.tab.c"
    break;

  case 288: /* fof_defined_term: fof_defined_atomic_term  */
#line 801 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("fof_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4608 "y.tab.c"
    break;

  case 289: /* fof_defined_atomic_term: fof_defined_plain_term  */
#line 804 "SyntaxBNF.y"
                                                 {(yyval.pval) = P_BUILD("fof_defined_atomic_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4614 "y.tab.c"
    break;

  case 290: /* fof_defined_plain_term: defined_constant  */
#line 807 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("fof_defined_plain_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4620 "y.tab.c"
    break;

  case 291: /* fof_defined_plain_term: defined_functor LPAREN fof_arguments RPAREN  */
#line 808 "SyntaxBNF.y"
                                                                  {(yyval.pval) = P_BUILD("fof_defined_plain_term", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4626 "y.tab.c"
    break;

  case 292: /* fof_system_term: system_constant  */
#line 811 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("fof_system_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4632 "y.tab.c"
    break;

  case 293: /* fof_system_term: system_functor LPAREN fof_arguments RPAREN  */
#line 812 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("fof_system_term", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4638 "y.tab.c"
    break;

  case 294: /* fof_arguments: fof_term  */
#line 815 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("fof_arguments", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4644 "y.tab.c"
    break;

  case 295: /* fof_arguments: fof_term COMMA fof_arguments  */
#line 816 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("fof_arguments", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4650 "y.tab.c"
    break;

  case 296: /* fof_term: fof_function_term  */
#line 819 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("fof_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4656 "y.tab.c"
    break;

  case 297: /* fof_term: variable  */
#line 820 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("fof_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4662 "y.tab.c"
    break;

  case 298: /* fof_function_term: fof_plain_term  */
#line 823 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("fof_function_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4668 "y.tab.c"
    break;

  case 299: /* fof_function_term: fof_defined_term  */
#line 824 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("fof_function_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4674 "y.tab.c"
    break;

  case 300: /* fof_function_term: fof_system_term  */
#line 825 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("fof_function_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4680 "y.tab.c"
    break;

  case 301: /* fof_sequent: fof_formula_tuple gentzen_arrow fof_formula_tuple  */
#line 828 "SyntaxBNF.y"
                                                                {(yyval.pval) = P_BUILD("fof_sequent", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4686 "y.tab.c"
    break;

  case 302: /* fof_sequent: LPAREN fof_sequent RPAREN  */
#line 829 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("fof_sequent", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4692 "y.tab.c"
    break;

  case 303: /* fof_formula_tuple: LBRKT RBRKT  */
#line 832 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("fof_formula_tuple", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4698 "y.tab.c"
    break;

  case 304: /* fof_formula_tuple: LBRKT fof_formula_tuple_list RBRKT  */
#line 833 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("fof_formula_tuple", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4704 "y.tab.c"
    break;

  case 305: /* fof_formula_tuple_list: fof_logic_formula  */
#line 836 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("fof_formula_tuple_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4710 "y.tab.c"
    break;

  case 306: /* fof_formula_tuple_list: fof_logic_formula COMMA fof_formula_tuple_list  */
#line 837 "SyntaxBNF.y"
                                                                     {(yyval.pval) = P_BUILD("fof_formula_tuple_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4716 "y.tab.c"
    break;

  case 307: /* cnf_formula: cnf_disjunction  */
#line 840 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("cnf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4722 "y.tab.c"
    break;

  case 308: /* cnf_formula: LPAREN cnf_formula RPAREN  */
#line 841 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("cnf_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4728 "y.tab.c"
    break;

  case 309: /* cnf_disjunction: cnf_literal  */
#line 844 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("cnf_disjunction", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4734 "y.tab.c"
    break;

  case 310: /* cnf_disjunction: cnf_disjunction VLINE cnf_literal  */
#line 845 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("cnf_disjunction", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4740 "y.tab.c"
    break;

  case 311: /* cnf_literal: fof_atomic_formula  */
#line 848 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("cnf_literal", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4746 "y.tab.c"
    break;

  case 312: /* cnf_literal: TILDE fof_atomic_formula  */
#line 849 "SyntaxBNF.y"
                                               {(yyval.pval) = P_BUILD("cnf_literal", P_TOKEN("TILDE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4752 "y.tab.c"
    break;

  case 313: /* cnf_literal: TILDE LPAREN fof_atomic_formula RPAREN  */
#line 850 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("cnf_literal", P_TOKEN("TILDE ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4758 "y.tab.c"
    break;

  case 314: /* cnf_literal: fof_infix_unary  */
#line 851 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("cnf_literal", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4764 "y.tab.c"
    break;

  case 315: /* thf_quantifier: tff_quantifier  */
#line 854 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4770 "y.tab.c"
    break;

  case 316: /* thf_quantifier: th0_quantifier  */
#line 855 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4776 "y.tab.c"
    break;

  case 317: /* thf_quantifier: type_quantifier  */
#line 856 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4782 "y.tab.c"
    break;

  case 318: /* thf_unary_connective: unary_connective  */
#line 859 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4788 "y.tab.c"
    break;

  case 319: /* thf_unary_connective: ntf_short_connective  */
#line 860 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("thf_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4794 "y.tab.c"
    break;

  case 320: /* th0_quantifier: CARET  */
#line 863 "SyntaxBNF.y"
                       {(yyval.pval) = P_BUILD("th0_quantifier", P_TOKEN("CARET ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4800 "y.tab.c"
    break;

  case 321: /* th0_quantifier: AT_SIGN_PLUS  */
#line 864 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("th0_quantifier", P_TOKEN("AT_SIGN_PLUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4806 "y.tab.c"
    break;

  case 322: /* th0_quantifier: AT_SIGN_MINUS  */
#line 865 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("th0_quantifier", P_TOKEN("AT_SIGN_MINUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4812 "y.tab.c"
    break;

  case 323: /* type_quantifier: EXCLAMATION_GREATER  */
#line 868 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("type_quantifier", P_TOKEN("EXCLAMATION_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4818 "y.tab.c"
    break;

  case 324: /* type_quantifier: QUESTION_STAR  */
#line 869 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("type_quantifier", P_TOKEN("QUESTION_STAR ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4824 "y.tab.c"
    break;

  case 325: /* subtype_sign: LESS_LESS  */
#line 872 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("subtype_sign", P_TOKEN("LESS_LESS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4830 "y.tab.c"
    break;

  case 326: /* tff_unary_connective: unary_connective  */
#line 875 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4836 "y.tab.c"
    break;

  case 327: /* tff_unary_connective: ntf_short_connective  */
#line 876 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("tff_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4842 "y.tab.c"
    break;

  case 328: /* tff_quantifier: fof_quantifier  */
#line 879 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4848 "y.tab.c"
    break;

  case 329: /* tff_quantifier: hash  */
#line 880 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("tff_quantifier", P_TOKEN("hash ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4854 "y.tab.c"
    break;

  case 330: /* fof_quantifier: EXCLAMATION  */
#line 883 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("fof_quantifier", P_TOKEN("EXCLAMATION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4860 "y.tab.c"
    break;

  case 331: /* fof_quantifier: QUESTION  */
#line 884 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("fof_quantifier", P_TOKEN("QUESTION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4866 "y.tab.c"
    break;

  case 332: /* nonassoc_connective: LESS_EQUALS_GREATER  */
#line 887 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("LESS_EQUALS_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4872 "y.tab.c"
    break;

  case 333: /* nonassoc_connective: EQUALS_GREATER  */
#line 888 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("EQUALS_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4878 "y.tab.c"
    break;

  case 334: /* nonassoc_connective: LESS_EQUALS  */
#line 889 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("LESS_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4884 "y.tab.c"
    break;

  case 335: /* nonassoc_connective: LESS_TILDE_GREATER  */
#line 890 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("LESS_TILDE_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4890 "y.tab.c"
    break;

  case 336: /* nonassoc_connective: TILDE_VLINE  */
#line 891 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("TILDE_VLINE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4896 "y.tab.c"
    break;

  case 337: /* nonassoc_connective: TILDE_AMPERSAND  */
#line 892 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("TILDE_AMPERSAND ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4902 "y.tab.c"
    break;

  case 338: /* assoc_connective: VLINE  */
#line 895 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("assoc_connective", P_TOKEN("VLINE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4908 "y.tab.c"
    break;

  case 339: /* assoc_connective: AMPERSAND  */
#line 896 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("assoc_connective", P_TOKEN("AMPERSAND ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4914 "y.tab.c"
    break;

  case 340: /* unary_connective: TILDE  */
#line 899 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("unary_connective", P_TOKEN("TILDE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4920 "y.tab.c"
    break;

  case 341: /* gentzen_arrow: MINUS_MINUS_GREATER  */
#line 902 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("gentzen_arrow", P_TOKEN("MINUS_MINUS_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4926 "y.tab.c"
    break;

  case 342: /* assignment: COLON_EQUALS  */
#line 905 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("assignment", P_TOKEN("COLON_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4932 "y.tab.c"
    break;

  case 343: /* identical: EQUALS_EQUALS  */
#line 908 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("identical", P_TOKEN("EQUALS_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4938 "y.tab.c"
    break;

  case 344: /* typeable_atom: constant  */
#line 911 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("typeable_atom", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4944 "y.tab.c"
    break;

  case 345: /* typeable_atom: distinct_object  */
#line 912 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("typeable_atom", P_TOKEN("distinct_object ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4950 "y.tab.c"
    break;

  case 346: /* atomic_type: typeable_atom  */
#line 915 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4956 "y.tab.c"
    break;

  case 347: /* atomic_type: defined_constant  */
#line 916 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4962 "y.tab.c"
    break;

  case 348: /* atomic_type: system_type  */
#line 917 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4968 "y.tab.c"
    break;

  case 349: /* type_constant: type_functor  */
#line 920 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("type_constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4974 "y.tab.c"
    break;

  case 350: /* type_functor: atomic_word  */
#line 923 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("type_functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4980 "y.tab.c"
    break;

  case 351: /* defined_type: atomic_defined_word  */
#line 926 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("defined_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4986 "y.tab.c"
    break;

  case 352: /* system_type: atomic_system_word  */
#line 929 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("system_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4992 "y.tab.c"
    break;

  case 353: /* defined_infix_pred: infix_equality  */
#line 932 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("defined_infix_pred", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4998 "y.tab.c"
    break;

  case 354: /* infix_equality: EQUALS  */
#line 935 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("infix_equality", P_TOKEN("EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5004 "y.tab.c"
    break;

  case 355: /* infix_inequality: EXCLAMATION_EQUALS  */
#line 938 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("infix_inequality", P_TOKEN("EXCLAMATION_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5010 "y.tab.c"
    break;

  case 356: /* constant: functor  */
#line 941 "SyntaxBNF.y"
                   {(yyval.pval) = P_BUILD("constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5016 "y.tab.c"
    break;

  case 357: /* functor: atomic_word  */
#line 944 "SyntaxBNF.y"
                      {(yyval.pval) = P_BUILD("functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5022 "y.tab.c"
    break;

  case 358: /* defined_constant: defined_functor  */
#line 947 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("defined_constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5028 "y.tab.c"
    break;

  case 359: /* defined_functor: atomic_defined_word  */
#line 950 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("defined_functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5034 "y.tab.c"
    break;

  case 360: /* system_constant: system_functor  */
#line 953 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("system_constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5040 "y.tab.c"
    break;

  case 361: /* system_functor: atomic_system_word  */
#line 956 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("system_functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5046 "y.tab.c"
    break;

  case 362: /* th1_defined_term: EXCLAMATION_EXCLAMATION  */
#line 959 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("EXCLAMATION_EXCLAMATION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5052 "y.tab.c"
    break;

  case 363: /* th1_defined_term: QUESTION_QUESTION  */
#line 960 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("QUESTION_QUESTION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5058 "y.tab.c"
    break;

  case 364: /* th1_defined_term: AT_AT_SIGN_PLUS  */
#line 961 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("AT_AT_SIGN_PLUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5064 "y.tab.c"
    break;

  case 365: /* th1_defined_term: AT_AT_SIGN_MINUS  */
#line 962 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("AT_AT_SIGN_MINUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5070 "y.tab.c"
    break;

  case 366: /* th1_defined_term: AT_SIGN_EQUALS  */
#line 963 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("AT_SIGN_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5076 "y.tab.c"
    break;

  case 367: /* defined_term: number  */
#line 966 "SyntaxBNF.y"
                      {(yyval.pval) = P_BUILD("defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5082 "y.tab.c"
    break;

  case 368: /* defined_term: distinct_object  */
#line 967 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("defined_term", P_TOKEN("distinct_object ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5088 "y.tab.c"
    break;

  case 369: /* variable: upper_word  */
#line 970 "SyntaxBNF.y"
                      {(yyval.pval) = P_BUILD("variable", P_TOKEN("upper_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5094 "y.tab.c"
    break;

  case 370: /* source: dag_source  */
#line 973 "SyntaxBNF.y"
                    {(yyval.pval) = P_BUILD("source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5100 "y.tab.c"
    break;

  case 371: /* source: internal_source  */
#line 974 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5106 "y.tab.c"
    break;

  case 372: /* source: external_source  */
#line 975 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5112 "y.tab.c"
    break;

  case 373: /* source: _LIT_unknown  */
#line 976 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("source", P_TOKEN("_LIT_unknown ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5118 "y.tab.c"
    break;

  case 374: /* source: LBRKT sources RBRKT  */
#line 977 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("source", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5124 "y.tab.c"
    break;

  case 375: /* sources: source  */
#line 980 "SyntaxBNF.y"
                 {(yyval.pval) = P_BUILD("sources", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5130 "y.tab.c"
    break;

  case 376: /* sources: source COMMA sources  */
#line 981 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("sources", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5136 "y.tab.c"
    break;

  case 377: /* dag_source: name  */
#line 984 "SyntaxBNF.y"
                  {(yyval.pval) = P_BUILD("dag_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5142 "y.tab.c"
    break;

  case 378: /* dag_source: inference_record  */
#line 985 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("dag_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5148 "y.tab.c"
    break;

  case 379: /* inference_record: _LIT_inference LPAREN inference_rule COMMA useful_info COMMA parents RPAREN  */
#line 988 "SyntaxBNF.y"
                                                                                               {(yyval.pval) = P_BUILD("inference_record", P_TOKEN("_LIT_inference ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 5154 "y.tab.c"
    break;

  case 380: /* inference_rule: atomic_word  */
#line 991 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("inference_rule", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5160 "y.tab.c"
    break;

  case 381: /* internal_source: _LIT_introduced LPAREN intro_type COMMA useful_info COMMA parents RPAREN  */
#line 994 "SyntaxBNF.y"
                                                                                           {(yyval.pval) = P_BUILD("internal_source", P_TOKEN("_LIT_introduced ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 5166 "y.tab.c"
    break;

  case 382: /* intro_type: atomic_word  */
#line 997 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("intro_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5172 "y.tab.c"
    break;

  case 383: /* external_source: file_source  */
#line 1000 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("external_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5178 "y.tab.c"
    break;

  case 384: /* file_source: _LIT_file LPAREN file_name file_info RPAREN  */
#line 1003 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("file_source", P_TOKEN("_LIT_file ", (yyvsp[-4].ival)), P_TOKEN("LPAREN ", (yyvsp[-3].ival)), (yyvsp[-2].pval), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL);}
#line 5184 "y.tab.c"
    break;

  case 385: /* file_info: COMMA name  */
#line 1006 "SyntaxBNF.y"
                       {(yyval.pval) = P_BUILD("file_info", P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5190 "y.tab.c"
    break;

  case 386: /* file_info: nothing  */
#line 1007 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("file_info", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5196 "y.tab.c"
    break;

  case 387: /* parents: LBRKT RBRKT  */
#line 1010 "SyntaxBNF.y"
                      {(yyval.pval) = P_BUILD("parents", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5202 "y.tab.c"
    break;

  case 388: /* parents: LBRKT parent_list RBRKT  */
#line 1011 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("parents", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5208 "y.tab.c"
    break;

  case 389: /* parent_list: parent_info  */
#line 1014 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("parent_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5214 "y.tab.c"
    break;

  case 390: /* parent_list: parent_info COMMA parent_list  */
#line 1015 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("parent_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5220 "y.tab.c"
    break;

  case 391: /* parent_info: source parent_details  */
#line 1018 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("parent_info", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5226 "y.tab.c"
    break;

  case 392: /* parent_details: COLON general_term  */
#line 1021 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("parent_details", P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5232 "y.tab.c"
    break;

  case 393: /* parent_details: nothing  */
#line 1022 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("parent_details", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5238 "y.tab.c"
    break;

  case 394: /* optional_info: COMMA useful_info  */
#line 1025 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("optional_info", P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5244 "y.tab.c"
    break;

  case 395: /* optional_info: nothing  */
#line 1026 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("optional_info", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5250 "y.tab.c"
    break;

  case 396: /* useful_info: general_list  */
#line 1029 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("useful_info", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5256 "y.tab.c"
    break;

  case 397: /* include: _LIT_include LPAREN file_name include_optionals RPAREN PERIOD  */
#line 1032 "SyntaxBNF.y"
                                                                        {(yyval.pval) = P_BUILD("include", P_TOKEN("_LIT_include ", (yyvsp[-5].ival)), P_TOKEN("LPAREN ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL);}
#line 5262 "y.tab.c"
    break;

  case 398: /* include_optionals: nothing  */
#line 1035 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("include_optionals", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5268 "y.tab.c"
    break;

  case 399: /* include_optionals: COMMA formula_selection  */
#line 1036 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("include_optionals", P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5274 "y.tab.c"
    break;

  case 400: /* include_optionals: COMMA formula_selection COMMA space_name  */
#line 1037 "SyntaxBNF.y"
                                                               {(yyval.pval) = P_BUILD("include_optionals", P_TOKEN("COMMA ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5280 "y.tab.c"
    break;

  case 401: /* formula_selection: LBRKT name_list RBRKT  */
#line 1040 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("formula_selection", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5286 "y.tab.c"
    break;

  case 402: /* formula_selection: STAR  */
#line 1041 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("formula_selection", P_TOKEN("STAR ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5292 "y.tab.c"
    break;

  case 403: /* name_list: name  */
#line 1044 "SyntaxBNF.y"
                 {(yyval.pval) = P_BUILD("name_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5298 "y.tab.c"
    break;

  case 404: /* name_list: name COMMA name_list  */
#line 1045 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("name_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5304 "y.tab.c"
    break;

  case 405: /* space_name: name  */
#line 1048 "SyntaxBNF.y"
                  {(yyval.pval) = P_BUILD("space_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5310 "y.tab.c"
    break;

  case 406: /* general_term: general_data  */
#line 1051 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("general_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5316 "y.tab.c"
    break;

  case 407: /* general_term: general_data COLON general_term  */
#line 1052 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("general_term", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5322 "y.tab.c"
    break;

  case 408: /* general_term: general_list  */
#line 1053 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("general_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5328 "y.tab.c"
    break;

  case 409: /* general_data: atomic_word  */
#line 1056 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5334 "y.tab.c"
    break;

  case 410: /* general_data: general_function  */
#line 1057 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5340 "y.tab.c"
    break;

  case 411: /* general_data: variable  */
#line 1058 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5346 "y.tab.c"
    break;

  case 412: /* general_data: number  */
#line 1059 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5352 "y.tab.c"
    break;

  case 413: /* general_data: distinct_object  */
#line 1060 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("general_data", P_TOKEN("distinct_object ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5358 "y.tab.c"
    break;

  case 414: /* general_data: formula_data  */
#line 1061 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5364 "y.tab.c"
    break;

  case 415: /* general_function: atomic_word LPAREN general_terms RPAREN  */
#line 1064 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("general_function", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5370 "y.tab.c"
    break;

  case 416: /* formula_data: _DLR_thf LPAREN thf_formula RPAREN  */
#line 1067 "SyntaxBNF.y"
                                                  {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_thf ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5376 "y.tab.c"
    break;

  case 417: /* formula_data: _DLR_tff LPAREN tff_formula RPAREN  */
#line 1068 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_tff ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5382 "y.tab.c"
    break;

  case 418: /* formula_data: _DLR_fof LPAREN fof_formula RPAREN  */
#line 1069 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_fof ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5388 "y.tab.c"
    break;

  case 419: /* formula_data: _DLR_cnf LPAREN cnf_formula RPAREN  */
#line 1070 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_cnf ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5394 "y.tab.c"
    break;

  case 420: /* formula_data: _DLR_fot LPAREN fof_term RPAREN  */
#line 1071 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_fot ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5400 "y.tab.c"
    break;

  case 421: /* general_list: LBRKT RBRKT  */
#line 1074 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("general_list", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5406 "y.tab.c"
    break;

  case 422: /* general_list: LBRKT general_terms RBRKT  */
#line 1075 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("general_list", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5412 "y.tab.c"
    break;

  case 423: /* general_terms: general_term  */
#line 1078 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("general_terms", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5418 "y.tab.c"
    break;

  case 424: /* general_terms: general_term COMMA general_terms  */
#line 1079 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("general_terms", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5424 "y.tab.c"
    break;

  case 425: /* name: atomic_word  */
#line 1082 "SyntaxBNF.y"
                   {(yyval.pval) = P_BUILD("name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5430 "y.tab.c"
    break;

  case 426: /* name: integer  */
#line 1083 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("name", P_TOKEN("integer ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5436 "y.tab.c"
    break;

  case 427: /* atomic_word: lower_word  */
#line 1086 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("atomic_word", P_TOKEN("lower_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5442 "y.tab.c"
    break;

  case 428: /* atomic_word: single_quoted  */
#line 1087 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("atomic_word", P_TOKEN("single_quoted ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5448 "y.tab.c"
    break;

  case 429: /* atomic_word: back_quoted  */
#line 1088 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("atomic_word", P_TOKEN("back_quoted ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5454 "y.tab.c"
    break;

  case 430: /* atomic_defined_word: dollar_word  */
#line 1091 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("atomic_defined_word", P_TOKEN("dollar_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5460 "y.tab.c"
    break;

  case 431: /* atomic_system_word: dollar_dollar_word  */
#line 1094 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("atomic_system_word", P_TOKEN("dollar_dollar_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5466 "y.tab.c"
    break;

  case 432: /* number: integer  */
#line 1097 "SyntaxBNF.y"
                 {(yyval.pval) = P_BUILD("number", P_TOKEN("integer ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5472 "y.tab.c"
    break;

  case 433: /* number: rational  */
#line 1098 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("number", P_TOKEN("rational ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5478 "y.tab.c"
    break;

  case 434: /* number: real  */
#line 1099 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("number", P_TOKEN("real ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5484 "y.tab.c"
    break;

  case 435: /* file_name: atomic_word  */
#line 1102 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("file_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5490 "y.tab.c"
    break;

  case 436: /* nothing: %empty  */
#line 1105 "SyntaxBNF.y"
          {(yyval.pval) = P_BUILD("nothing",NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5496 "y.tab.c"
    break;


#line 5500 "y.tab.c"

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

