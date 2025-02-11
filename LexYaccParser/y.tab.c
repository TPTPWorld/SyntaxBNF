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
    distinct_object = 317,         /* distinct_object  */
    dollar_dollar_word = 318,      /* dollar_dollar_word  */
    dollar_word = 319,             /* dollar_word  */
    hash = 320,                    /* hash  */
    integer = 321,                 /* integer  */
    less_sign = 322,               /* less_sign  */
    lower_word = 323,              /* lower_word  */
    plus = 324,                    /* plus  */
    rational = 325,                /* rational  */
    real = 326,                    /* real  */
    single_quoted = 327,           /* single_quoted  */
    slash = 328,                   /* slash  */
    slosh = 329,                   /* slosh  */
    unrecognized = 330,            /* unrecognized  */
    upper_word = 331               /* upper_word  */
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
#define distinct_object 317
#define dollar_dollar_word 318
#define dollar_word 319
#define hash 320
#define integer 321
#define less_sign 322
#define lower_word 323
#define plus 324
#define rational 325
#define real 326
#define single_quoted 327
#define slash 328
#define slosh 329
#define unrecognized 330
#define upper_word 331

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 152 "SyntaxBNF.y"
int ival; double dval; char* sval; void* pval;

#line 429 "y.tab.c"

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
  YYSYMBOL_distinct_object = 62,           /* distinct_object  */
  YYSYMBOL_dollar_dollar_word = 63,        /* dollar_dollar_word  */
  YYSYMBOL_dollar_word = 64,               /* dollar_word  */
  YYSYMBOL_hash = 65,                      /* hash  */
  YYSYMBOL_integer = 66,                   /* integer  */
  YYSYMBOL_less_sign = 67,                 /* less_sign  */
  YYSYMBOL_lower_word = 68,                /* lower_word  */
  YYSYMBOL_plus = 69,                      /* plus  */
  YYSYMBOL_rational = 70,                  /* rational  */
  YYSYMBOL_real = 71,                      /* real  */
  YYSYMBOL_single_quoted = 72,             /* single_quoted  */
  YYSYMBOL_slash = 73,                     /* slash  */
  YYSYMBOL_slosh = 74,                     /* slosh  */
  YYSYMBOL_unrecognized = 75,              /* unrecognized  */
  YYSYMBOL_upper_word = 76,                /* upper_word  */
  YYSYMBOL_YYACCEPT = 77,                  /* $accept  */
  YYSYMBOL_TPTP_file = 78,                 /* TPTP_file  */
  YYSYMBOL_TPTP_input = 79,                /* TPTP_input  */
  YYSYMBOL_annotated_formula = 80,         /* annotated_formula  */
  YYSYMBOL_tpi_annotated = 81,             /* tpi_annotated  */
  YYSYMBOL_tpi_formula = 82,               /* tpi_formula  */
  YYSYMBOL_thf_annotated = 83,             /* thf_annotated  */
  YYSYMBOL_tff_annotated = 84,             /* tff_annotated  */
  YYSYMBOL_tcf_annotated = 85,             /* tcf_annotated  */
  YYSYMBOL_fof_annotated = 86,             /* fof_annotated  */
  YYSYMBOL_cnf_annotated = 87,             /* cnf_annotated  */
  YYSYMBOL_annotations = 88,               /* annotations  */
  YYSYMBOL_formula_role = 89,              /* formula_role  */
  YYSYMBOL_thf_formula = 90,               /* thf_formula  */
  YYSYMBOL_thf_logic_formula = 91,         /* thf_logic_formula  */
  YYSYMBOL_thf_binary_formula = 92,        /* thf_binary_formula  */
  YYSYMBOL_thf_binary_nonassoc = 93,       /* thf_binary_nonassoc  */
  YYSYMBOL_thf_binary_assoc = 94,          /* thf_binary_assoc  */
  YYSYMBOL_thf_or_formula = 95,            /* thf_or_formula  */
  YYSYMBOL_thf_and_formula = 96,           /* thf_and_formula  */
  YYSYMBOL_thf_apply_formula = 97,         /* thf_apply_formula  */
  YYSYMBOL_thf_unit_formula = 98,          /* thf_unit_formula  */
  YYSYMBOL_thf_preunit_formula = 99,       /* thf_preunit_formula  */
  YYSYMBOL_thf_unitary_formula = 100,      /* thf_unitary_formula  */
  YYSYMBOL_thf_quantified_formula = 101,   /* thf_quantified_formula  */
  YYSYMBOL_thf_quantification = 102,       /* thf_quantification  */
  YYSYMBOL_thf_variable_list = 103,        /* thf_variable_list  */
  YYSYMBOL_thf_typed_variable = 104,       /* thf_typed_variable  */
  YYSYMBOL_thf_unary_formula = 105,        /* thf_unary_formula  */
  YYSYMBOL_thf_prefix_unary = 106,         /* thf_prefix_unary  */
  YYSYMBOL_thf_infix_unary = 107,          /* thf_infix_unary  */
  YYSYMBOL_thf_atomic_formula = 108,       /* thf_atomic_formula  */
  YYSYMBOL_thf_plain_atomic = 109,         /* thf_plain_atomic  */
  YYSYMBOL_thf_defined_atomic = 110,       /* thf_defined_atomic  */
  YYSYMBOL_thf_defined_term = 111,         /* thf_defined_term  */
  YYSYMBOL_thf_defined_infix = 112,        /* thf_defined_infix  */
  YYSYMBOL_thf_system_atomic = 113,        /* thf_system_atomic  */
  YYSYMBOL_thf_let = 114,                  /* thf_let  */
  YYSYMBOL_thf_let_types = 115,            /* thf_let_types  */
  YYSYMBOL_thf_atom_typing_list = 116,     /* thf_atom_typing_list  */
  YYSYMBOL_thf_let_defns = 117,            /* thf_let_defns  */
  YYSYMBOL_thf_let_defn = 118,             /* thf_let_defn  */
  YYSYMBOL_thf_let_defn_list = 119,        /* thf_let_defn_list  */
  YYSYMBOL_thf_unitary_term = 120,         /* thf_unitary_term  */
  YYSYMBOL_thf_conn_term = 121,            /* thf_conn_term  */
  YYSYMBOL_thf_tuple = 122,                /* thf_tuple  */
  YYSYMBOL_thf_fof_function = 123,         /* thf_fof_function  */
  YYSYMBOL_thf_arguments = 124,            /* thf_arguments  */
  YYSYMBOL_thf_formula_list = 125,         /* thf_formula_list  */
  YYSYMBOL_thf_atom_typing = 126,          /* thf_atom_typing  */
  YYSYMBOL_thf_top_level_type = 127,       /* thf_top_level_type  */
  YYSYMBOL_thf_unitary_type = 128,         /* thf_unitary_type  */
  YYSYMBOL_thf_apply_type = 129,           /* thf_apply_type  */
  YYSYMBOL_thf_binary_type = 130,          /* thf_binary_type  */
  YYSYMBOL_thf_mapping_type = 131,         /* thf_mapping_type  */
  YYSYMBOL_thf_xprod_type = 132,           /* thf_xprod_type  */
  YYSYMBOL_thf_union_type = 133,           /* thf_union_type  */
  YYSYMBOL_thf_subtype = 134,              /* thf_subtype  */
  YYSYMBOL_thf_definition = 135,           /* thf_definition  */
  YYSYMBOL_thf_sequent = 136,              /* thf_sequent  */
  YYSYMBOL_tff_formula = 137,              /* tff_formula  */
  YYSYMBOL_tff_logic_formula = 138,        /* tff_logic_formula  */
  YYSYMBOL_tff_binary_formula = 139,       /* tff_binary_formula  */
  YYSYMBOL_tff_binary_nonassoc = 140,      /* tff_binary_nonassoc  */
  YYSYMBOL_tff_binary_assoc = 141,         /* tff_binary_assoc  */
  YYSYMBOL_tff_or_formula = 142,           /* tff_or_formula  */
  YYSYMBOL_tff_and_formula = 143,          /* tff_and_formula  */
  YYSYMBOL_tff_unit_formula = 144,         /* tff_unit_formula  */
  YYSYMBOL_tff_preunit_formula = 145,      /* tff_preunit_formula  */
  YYSYMBOL_tff_unitary_formula = 146,      /* tff_unitary_formula  */
  YYSYMBOL_txf_unitary_formula = 147,      /* txf_unitary_formula  */
  YYSYMBOL_tff_quantified_formula = 148,   /* tff_quantified_formula  */
  YYSYMBOL_tff_variable_list = 149,        /* tff_variable_list  */
  YYSYMBOL_tff_variable = 150,             /* tff_variable  */
  YYSYMBOL_tff_typed_variable = 151,       /* tff_typed_variable  */
  YYSYMBOL_tff_unary_formula = 152,        /* tff_unary_formula  */
  YYSYMBOL_tff_prefix_unary = 153,         /* tff_prefix_unary  */
  YYSYMBOL_tff_infix_unary = 154,          /* tff_infix_unary  */
  YYSYMBOL_tff_atomic_formula = 155,       /* tff_atomic_formula  */
  YYSYMBOL_tff_plain_atomic = 156,         /* tff_plain_atomic  */
  YYSYMBOL_tff_defined_atomic = 157,       /* tff_defined_atomic  */
  YYSYMBOL_tff_defined_plain = 158,        /* tff_defined_plain  */
  YYSYMBOL_tff_defined_infix = 159,        /* tff_defined_infix  */
  YYSYMBOL_tff_system_atomic = 160,        /* tff_system_atomic  */
  YYSYMBOL_txf_let = 161,                  /* txf_let  */
  YYSYMBOL_txf_let_types = 162,            /* txf_let_types  */
  YYSYMBOL_tff_atom_typing_list = 163,     /* tff_atom_typing_list  */
  YYSYMBOL_txf_let_defns = 164,            /* txf_let_defns  */
  YYSYMBOL_txf_let_defn = 165,             /* txf_let_defn  */
  YYSYMBOL_txf_let_LHS = 166,              /* txf_let_LHS  */
  YYSYMBOL_txf_let_defn_list = 167,        /* txf_let_defn_list  */
  YYSYMBOL_nxf_atom = 168,                 /* nxf_atom  */
  YYSYMBOL_tff_term = 169,                 /* tff_term  */
  YYSYMBOL_tff_unitary_term = 170,         /* tff_unitary_term  */
  YYSYMBOL_txf_tuple = 171,                /* txf_tuple  */
  YYSYMBOL_tff_arguments = 172,            /* tff_arguments  */
  YYSYMBOL_tff_atom_typing = 173,          /* tff_atom_typing  */
  YYSYMBOL_tff_top_level_type = 174,       /* tff_top_level_type  */
  YYSYMBOL_tff_non_atomic_type = 175,      /* tff_non_atomic_type  */
  YYSYMBOL_tf1_quantified_type = 176,      /* tf1_quantified_type  */
  YYSYMBOL_tff_monotype = 177,             /* tff_monotype  */
  YYSYMBOL_tff_unitary_type = 178,         /* tff_unitary_type  */
  YYSYMBOL_tff_atomic_type = 179,          /* tff_atomic_type  */
  YYSYMBOL_tff_type_arguments = 180,       /* tff_type_arguments  */
  YYSYMBOL_tff_mapping_type = 181,         /* tff_mapping_type  */
  YYSYMBOL_tff_xprod_type = 182,           /* tff_xprod_type  */
  YYSYMBOL_txf_tuple_type = 183,           /* txf_tuple_type  */
  YYSYMBOL_tff_type_list = 184,            /* tff_type_list  */
  YYSYMBOL_tff_subtype = 185,              /* tff_subtype  */
  YYSYMBOL_txf_definition = 186,           /* txf_definition  */
  YYSYMBOL_txf_sequent = 187,              /* txf_sequent  */
  YYSYMBOL_nhf_long_connective = 188,      /* nhf_long_connective  */
  YYSYMBOL_nhf_parameter_list = 189,       /* nhf_parameter_list  */
  YYSYMBOL_nhf_parameter = 190,            /* nhf_parameter  */
  YYSYMBOL_nhf_key_pair = 191,             /* nhf_key_pair  */
  YYSYMBOL_nxf_long_connective = 192,      /* nxf_long_connective  */
  YYSYMBOL_nxf_parameter_list = 193,       /* nxf_parameter_list  */
  YYSYMBOL_nxf_parameter = 194,            /* nxf_parameter  */
  YYSYMBOL_nxf_key_pair = 195,             /* nxf_key_pair  */
  YYSYMBOL_ntf_connective_name = 196,      /* ntf_connective_name  */
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
  YYSYMBOL_th1_quantifier = 237,           /* th1_quantifier  */
  YYSYMBOL_th0_quantifier = 238,           /* th0_quantifier  */
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
  YYSYMBOL_def_or_sys_constant = 263,      /* def_or_sys_constant  */
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
#define YYLAST   3471

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  77
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  228
/* YYNRULES -- Number of rules.  */
#define YYNRULES  444
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  828

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   331


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
      75,    76
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   230,   230,   231,   234,   235,   238,   239,   240,   241,
     242,   243,   246,   249,   252,   255,   258,   261,   264,   267,
     268,   271,   272,   275,   276,   277,   280,   281,   282,   283,
     284,   285,   288,   289,   290,   293,   296,   297,   298,   301,
     302,   305,   306,   309,   310,   313,   314,   315,   318,   319,
     322,   323,   324,   325,   328,   331,   334,   335,   338,   341,
     342,   345,   348,   351,   352,   353,   354,   357,   358,   361,
     362,   363,   364,   365,   368,   369,   372,   375,   378,   381,
     382,   385,   386,   389,   390,   393,   396,   397,   400,   401,
     402,   405,   406,   407,   408,   409,   412,   413,   416,   417,
     418,   421,   424,   425,   428,   429,   432,   433,   434,   437,
     440,   443,   444,   445,   448,   449,   452,   453,   456,   457,
     460,   463,   466,   469,   470,   471,   474,   475,   476,   477,
     478,   479,   482,   483,   486,   489,   490,   493,   494,   497,
     498,   501,   502,   503,   506,   507,   510,   511,   512,   513,
     516,   519,   522,   523,   526,   527,   530,   533,   534,   537,
     540,   543,   544,   545,   548,   549,   552,   555,   556,   557,
     558,   561,   564,   565,   568,   571,   572,   575,   576,   579,
     580,   583,   586,   587,   590,   591,   594,   597,   598,   599,
     602,   603,   604,   605,   606,   609,   610,   613,   614,   617,
     618,   621,   622,   625,   626,   627,   630,   633,   634,   635,
     638,   639,   642,   643,   644,   645,   646,   647,   650,   651,
     654,   657,   658,   661,   664,   665,   668,   671,   674,   677,
     678,   681,   682,   685,   686,   689,   692,   693,   696,   697,
     700,   701,   704,   707,   710,   713,   714,   715,   716,   719,
     720,   723,   724,   727,   730,   731,   734,   735,   736,   739,
     740,   743,   746,   747,   750,   751,   754,   755,   758,   759,
     762,   765,   766,   769,   770,   771,   774,   777,   778,   781,
     782,   783,   786,   789,   790,   793,   796,   799,   802,   803,
     806,   807,   810,   813,   814,   817,   818,   821,   822,   825,
     826,   829,   830,   831,   834,   835,   838,   839,   842,   843,
     846,   847,   850,   851,   854,   855,   856,   857,   860,   861,
     862,   865,   866,   869,   870,   873,   874,   875,   878,   881,
     882,   885,   886,   889,   890,   893,   894,   895,   896,   897,
     898,   901,   902,   905,   908,   911,   914,   917,   920,   923,
     926,   927,   930,   931,   934,   937,   940,   943,   946,   949,
     952,   955,   958,   961,   962,   965,   966,   967,   968,   969,
     972,   973,   976,   979,   980,   981,   982,   983,   986,   987,
     990,   991,   994,   997,  1000,  1003,  1006,  1007,  1008,  1011,
    1014,  1015,  1018,  1021,  1024,  1027,  1030,  1031,  1034,  1035,
    1038,  1041,  1042,  1045,  1046,  1049,  1052,  1055,  1056,  1057,
    1060,  1061,  1064,  1065,  1068,  1071,  1072,  1073,  1076,  1077,
    1078,  1079,  1080,  1081,  1084,  1087,  1088,  1089,  1090,  1091,
    1094,  1095,  1098,  1099,  1102,  1103,  1106,  1107,  1110,  1113,
    1116,  1117,  1118,  1121,  1124
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
  "distinct_object", "dollar_dollar_word", "dollar_word", "hash",
  "integer", "less_sign", "lower_word", "plus", "rational", "real",
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
  "nothing", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-588)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-354)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -588,   662,  -588,  -588,   119,   138,   157,   160,   189,   191,
     196,  -588,  -588,  -588,  -588,  -588,  -588,  -588,  -588,  -588,
     219,   219,   270,   219,   219,   219,   219,  -588,  -588,  -588,
     103,  -588,   226,  -588,   228,   257,   284,   290,   303,   268,
     268,    89,   305,  -588,   268,   268,   268,   268,   316,   344,
     365,   219,  -588,   368,   335,   374,   398,   403,   404,  2239,
    1883,  2812,   333,   412,   219,  -588,  1555,  3380,  2622,  2812,
    1492,   399,   421,   430,   436,   439,  -588,  -588,  -588,  -588,
    -588,  -588,  -588,   469,  -588,  -588,  -588,   454,  -588,  1883,
    1675,  -588,  -588,  -588,  -588,  -588,  -588,  -588,  -588,  -588,
    -588,   391,  -588,  -588,   482,   511,   542,  -588,   491,   465,
    -588,  -588,   468,  -588,   489,  -588,   509,  -588,  -588,  -588,
    -588,  -588,  -588,  -588,  1042,  2812,  -588,  -588,   491,  -588,
    -588,  -588,  -588,   496,   541,    95,  -588,   986,   131,  -588,
    -588,  -588,   520,   552,  1398,  -588,   219,  -588,  -588,   553,
    1964,  -588,   491,  -588,  -588,  -588,   581,   588,   589,    79,
    1806,  3261,   536,  -588,   571,   491,  -588,  -588,  -588,  -588,
     561,   609,  1747,   177,  -588,  -588,   535,  -588,  -588,   381,
    -588,  -588,  -588,   598,  -588,  -588,  -588,   542,   520,  -588,
    -588,  -588,  -588,   615,  -588,  2543,   622,  -588,  -588,   113,
     147,   625,  -588,   630,   267,   633,  -588,   544,  -588,  -588,
    -588,  -588,  -588,  -588,  -588,  -588,    79,  1690,  1479,  -588,
    -588,   636,   491,  -588,  -588,  -588,  -588,   617,   664,   659,
    2164,   733,  -588,  3036,   418,  -588,  -588,   499,  -588,  -588,
    -588,   476,  -588,  -588,   542,   520,  -588,  -588,   252,  -588,
    -588,   632,   599,  -588,  -588,  -588,  -588,  -588,   648,  3112,
    -588,  -588,  -588,  -588,   307,   147,   644,  -588,   646,   267,
     653,  -588,  -588,   558,   491,  -588,  -588,   673,   655,  1883,
    2812,  1019,  3380,  2622,  2239,  2239,   647,  1019,  -588,   680,
    -588,  -588,  1019,  -588,  1019,  1244,   660,  -588,  1999,  1019,
    1019,  1019,  1398,  -588,   682,   663,   661,   666,   669,  1398,
    1398,  1398,  -588,  -588,  -588,  -588,  -588,  -588,  1398,  1398,
    -588,   685,   639,  -588,  -588,  -588,  -588,   639,   672,   686,
     773,   689,    87,  -588,  -588,  -588,  -588,  -588,  3313,   681,
    -588,  -588,   711,   341,   690,  -588,  -588,   606,   691,   692,
      96,   674,   694,  3395,  3395,  3395,  3395,  3395,  -588,  3395,
     850,   850,   714,   717,   720,  3313,  -588,  -588,  -588,  -588,
    -588,   639,  -588,   670,  3395,  3395,  3395,   183,  2079,  -588,
     740,   719,  -588,  -588,  -588,  -588,   721,   722,   726,  3112,
    -588,  -588,   744,  -588,  -588,   406,   728,  3036,  3036,  3036,
    3036,  3036,  3036,  3036,  -588,  -588,  -588,   612,  -588,  -588,
    3036,   756,   756,   734,  1328,  1328,  1328,  1328,  1328,   639,
    2079,  -588,  -588,  -588,  -588,  -588,  3036,   670,  3036,  3036,
    3036,   737,  2239,  -588,   738,   745,  -588,  -588,  -588,   749,
     750,   753,  -588,   760,  -588,   761,  -588,  -588,  1244,   771,
     772,   777,   780,   781,  -588,   758,  -588,  -588,  -588,  -588,
    -588,  -588,  -588,  -588,   746,  -588,   776,   801,   779,   785,
    1398,  -588,  -588,  -588,   786,  -588,  -588,  -588,  -588,  -588,
    -588,   782,   812,   794,   817,  -588,   820,  -588,   803,   816,
     773,   773,  -588,  -588,  -588,   778,   783,  -588,  -588,  -588,
     813,  -588,  -588,  -588,  -588,  -588,   928,  -588,  -588,  3395,
    -588,  -588,   613,   352,   352,   829,  -588,  -588,  -588,  -588,
    -588,   824,  -588,  -588,  -588,   618,  -588,  -588,  -588,  -588,
    -588,  -588,  -588,   -16,  3328,  3395,  -588,  -588,  -588,  -588,
    -588,  3395,   807,   811,  -588,  -588,  -588,   814,   823,   825,
    1794,  -588,  3036,  -588,   631,  -588,  -588,   355,   355,   834,
    -588,   830,  -588,  -588,  -588,  -588,  -588,  -588,  -588,  -588,
     -16,  2352,  2941,  -588,  -588,  -588,  -588,  -588,  2941,  -588,
    -588,   802,  -588,  -588,  -588,  -588,   838,   862,   865,   844,
     659,   876,   877,  -588,   802,  -588,  -588,  -588,   854,  -588,
     855,   857,   864,  -588,  -588,  -588,  -588,  -588,  -588,  -588,
    -588,   887,   866,   270,   270,   270,   270,   270,   880,  -588,
    -588,  -588,  -588,  1019,  -588,  -588,  -588,  -588,   893,   639,
     897,   639,   483,  -588,   639,   902,   884,   891,    92,   892,
     169,   483,   483,   850,   908,  -588,   894,   916,  -588,  -588,
    -588,   896,   920,    47,  -588,   899,   900,  -588,   927,  -588,
    -588,  -588,  1144,   908,  -588,   903,   932,  -588,  -588,  -588,
     915,   938,  3194,  -588,   917,   943,   639,  3036,  -588,  -588,
    -588,  -588,  -588,  1244,  -588,   942,  -588,   944,   945,  -588,
     946,  -588,   758,  -588,  -588,  -588,  -588,  1398,  -588,  1825,
    -588,   483,  -588,   921,   773,  -588,  -588,   483,  -588,  -588,
     483,  -588,   951,   929,  -588,   933,   928,  -588,   352,  3328,
    -588,   953,  -588,   957,  -588,  -588,  -588,  3395,   940,   941,
    -588,   950,  1794,  -588,   355,  1690,   957,   959,  -588,  -588,
    -588,  -588,  -588,  -588,   880,   219,   949,  -588,   880,   880,
     952,  -588,  -588,   892,   965,  -588,  -588,  -588,   483,  -588,
    -588,  -588,  -588,   966,   977,   960,   432,  3395,  -588,  3395,
    -588,  -588,  -588,  -588,   239,   984,   963,  3036,  3036,   988,
    -588,  -588,   992,   993,  -588,   835,  -588,    77,  -588,   971,
    -588,  3036,  -588,  -588,   975,   991,   991,   991,   501,  -588,
    -588,  -588,  -588,  -588,  -588,  -588,  1185,   979,   987,   996,
     501,  1004,  -588,   968,   964,  1011,  -588,  -588,  -588,  1005,
    -588,   880,  -588,  -588,  -588,  1244,  -588,  -588
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
     360,   362,   370,   333,     0,     0,   334,   343,   444,   254,
     256,   259,   260,   262,   263,   272,   269,     0,   271,   273,
     274,   255,     0,     0,     0,   410,     0,   409,   414,     0,
       0,   250,   444,   249,   251,   252,     0,   288,   295,     0,
       0,     0,     0,   332,     0,   444,   123,   128,   132,   133,
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
    -588,  -588,  -588,  -588,  -588,  -588,  -588,  -588,  -588,  -588,
    -588,   134,   487,   764,    32,  -588,  -588,  -588,  -588,  -588,
    -414,   181,  -588,   735,  -588,  -588,   353,  -588,   188,  -152,
    -588,   619,  -588,  -588,  -588,   240,  -588,  -588,  -588,   294,
    -588,   369,   253,  -151,  -588,    57,  -588,  -107,  -268,  -196,
     366,  -313,  -588,  -588,  -358,  -588,  -588,  -588,  -492,  -588,
     766,   -28,  -588,  -588,  -588,  -588,  -588,  -282,  -588,   -48,
    -588,  -588,  -317,  -588,  -588,  -265,   858,  -588,  -159,  -587,
    -588,  -588,  -259,  -588,  -588,  -588,   331,  -588,   397,  -588,
     269,  -588,  -333,  -300,   137,  -140,   -57,   724,   572,   277,
    -588,  -464,   345,   308,   272,  -588,  -588,   361,  -588,  -463,
    -588,  -588,   336,  -588,  -588,  -588,   351,  -588,  -588,  -203,
    -483,    84,  -588,   372,  -588,   -34,   -87,  -588,  -588,  -588,
    -588,  -588,  -136,     4,  -133,  -130,  -588,   443,   -10,  -588,
    -588,  -588,  -588,  -588,  -216,  -588,  -588,  -144,   -70,  -272,
     -73,  -588,   954,   755,   608,    21,  -588,   788,  -588,   -96,
    -588,  -588,   828,  -588,   165,   -38,   -60,  -588,  2553,   -93,
     371,  -212,  -588,  -588,  -588,   657,   -15,  -124,   -51,   -24,
     587,   914,  1897,  2170,  1297,  1624,  -588,  -588,  2443,   -26,
    -271,   405,  -588,  -588,  -588,  -588,  -588,  -588,  -588,  -588,
    -588,  -588,  -588,  -588,  -399,   273,  -588,  -588,   407,  -454,
    -588,  -588,  -588,   956,  -588,   -29,  -588,  -588,  -588,  -501,
    -223,    -5,   -19,   419,  -588,    69,   493,     0
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
     649,   257,   152,   153,   154,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   481,   140,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   466,
     106,   107,   141,   142,   305,   155,   109,   110,   258,   259,
     260,   261,   373,   195,   262,   197,   390,   391,   263,   362,
     777,   359,   499,   500,   501,   544,   156,   292,   393,   394,
     382,   266,   267,   268,   383,   270,   337,   271,   272,   118,
     611,   612,   456,   457,   688,   458,   690,   459,   460,   746,
     461,   692,   462,   685,   807,   814,   815,   822,   619,   694,
      19,    42,    53,    62,   147,   277,    83,    84,    85,    86,
     278,   463,   119,   120,   121,   122,    34,   297
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       2,    31,    31,    33,    31,    31,    31,    31,   323,   151,
     189,   324,   590,   377,   325,    30,    32,   289,    35,    36,
      37,    38,   388,   143,   455,   410,   532,   638,   468,   469,
      82,   143,    31,    81,    43,   275,   369,   304,   306,   166,
      87,   207,   273,   645,    81,    31,    63,    92,    93,   321,
      95,    87,   199,   264,   543,   293,    95,   582,   664,   148,
     537,   539,   443,   360,    94,   436,   720,   668,   596,   719,
      94,   522,   528,   529,   530,   531,   436,   319,   436,    95,
     288,   108,   294,   436,   436,   436,   143,   143,   524,   524,
     524,   524,   524,    94,   526,   526,   526,   526,   526,   534,
     223,   580,   581,   583,   584,   585,   143,   423,  -257,   331,
     286,    51,   357,   594,   506,    28,    39,   695,   513,    29,
     411,   507,   389,   514,   330,   245,    52,    31,    88,   707,
    -257,  -257,   763,   349,   207,   207,   293,   437,   372,    88,
      95,    63,    92,    93,  -258,    28,    20,   367,   437,    29,
     437,   194,   413,   641,    94,   437,   437,   437,  -352,    92,
     599,   599,   599,   361,    28,    21,  -258,  -258,    29,   370,
     403,   286,  -352,   323,   323,   323,   475,   476,   477,   325,
     325,   325,   323,   323,    22,   478,   479,    23,   325,   325,
    -126,   273,   273,   293,   525,   525,   525,   525,   525,   560,
     720,   536,   536,   392,   188,   709,   710,   273,   439,   603,
     550,   438,  -126,  -126,   289,   306,    24,   551,    25,   446,
     412,   447,   438,    26,   438,   189,   467,   467,   467,   438,
     438,   438,   196,   425,   547,   548,   549,   423,   293,    40,
     664,    41,   143,   695,   194,   194,   435,   695,   695,   668,
     386,   768,   552,   645,   166,   442,   207,   273,    81,    81,
     574,   576,   308,   590,   143,    87,    87,   199,   264,    95,
      44,   143,   143,   143,   245,   245,    31,   445,  -353,   194,
     143,   143,   389,    94,   669,    27,   329,    28,    95,   414,
     779,    29,  -353,   516,   782,   783,   482,    45,   188,   352,
     434,   486,    94,    46,   502,   523,   523,   523,   523,   523,
     349,   503,   207,   415,   700,   223,    47,   703,   426,   596,
     826,   416,   600,   601,   389,   196,   196,   207,   207,   207,
     207,   207,   372,   207,   538,   538,    48,   542,    28,   207,
     245,    54,    29,   714,    59,   486,   819,   644,   207,   207,
     207,   696,   273,    88,    88,  -192,   396,    60,   545,  -192,
     196,   671,   388,   425,   594,    65,   194,   377,   145,   650,
     320,   273,   273,   273,   273,   273,   273,   273,    61,   514,
     392,    64,   558,   304,   273,   575,   575,    66,   425,   425,
     425,   425,   425,   588,   273,  -190,   358,   808,   809,  -190,
     273,   656,   273,   273,   273,  -301,    81,   436,   431,  -301,
     386,    67,   545,    87,   404,    92,    68,    69,    92,   188,
      28,   406,   194,    28,    29,   146,   279,    29,   557,    31,
     -27,   -27,   143,   558,   789,   245,   790,   194,   194,   194,
     194,   194,   569,   194,  -183,   770,  -192,   196,   280,   194,
    -192,   410,   589,   -27,   -27,   620,   652,   281,   194,   194,
     194,   320,   524,   282,   502,   502,   283,   245,   526,    92,
     577,   503,   503,   408,    28,   188,   389,   245,    29,   437,
     284,   285,   389,   207,   536,   245,   245,   245,   -29,   -29,
     527,   527,   527,   527,   527,   299,  -292,   527,   527,   540,
    -292,    88,   188,   196,   295,   490,   298,   655,   207,   207,
     701,   -29,   -29,   -88,   358,   207,   300,   -88,   196,   196,
     196,   196,   196,   490,   196,  -303,   273,    50,   810,  -303,
     196,    55,    56,    57,    58,   813,   301,   309,   671,   196,
     196,   196,   392,   392,   310,   273,   273,    93,  -127,   320,
     467,    28,   273,   438,   813,    29,   290,   644,  -193,    80,
     291,   323,  -193,   350,   751,    93,   730,   325,   525,    28,
    -127,  -127,   -89,    29,   322,   327,   -89,    80,   562,   563,
     564,   565,   566,   567,   568,   406,   406,   406,   406,   406,
     406,   406,   330,   194,   686,    33,   689,   691,   693,  -352,
    -353,   351,   353,   482,   674,   486,   502,   591,   486,   245,
     589,  -129,   354,   503,   406,   502,   502,   538,   194,   194,
    -191,   363,   503,   503,  -191,   194,   -88,  -194,   245,   245,
     -88,  -194,  -190,  -129,  -129,   245,  -190,   408,   408,   408,
     408,   408,   408,   408,   371,   -90,   273,   111,   111,   -90,
     588,   273,   374,   157,   200,   265,   111,   375,   397,   143,
     376,   652,     3,   395,    31,   399,   408,   398,   418,   417,
     419,   428,   188,   429,   196,   502,   111,   111,   502,   523,
     430,   502,   503,   444,   502,   503,   432,   747,   503,    95,
     433,   503,   620,   207,   290,   470,   464,   472,   471,   196,
     196,   207,   473,    94,   736,   474,   196,   124,   487,   273,
       4,   111,   111,     5,     6,    80,   508,     7,     8,   392,
       9,    10,   488,   505,   509,   510,    31,   511,   512,   245,
     521,   111,   502,    92,    93,   520,   534,   157,    28,   503,
     780,   207,    29,   207,   541,   -26,   -26,   345,   200,   504,
     339,   273,   273,   552,   553,   426,   571,   554,   555,   502,
     208,   209,   556,   210,   561,   273,   503,   774,   -26,   -26,
    -109,   618,   502,   602,   604,   214,   621,   570,   571,   503,
     527,   605,   345,   572,   502,   606,   607,    31,   219,   608,
     724,   503,   245,   489,  -109,   490,   609,   610,   613,   614,
     491,   221,  -109,   194,   615,   265,    31,   616,   617,   793,
     794,   194,   622,   823,   623,   624,   627,   628,    91,    92,
      93,   625,    77,   736,    28,   629,    78,    79,    29,   630,
     631,   632,    80,   633,   245,   245,   639,    93,   634,   641,
     642,    28,   653,   657,  -210,    29,   658,   672,   245,    80,
     659,   194,   407,   194,   654,   489,   766,   490,   591,   660,
     673,   661,   798,   415,   527,   406,   111,   111,   111,   200,
     265,   533,   534,   675,   111,   676,   677,   535,   424,   111,
     678,   111,   401,   -45,   196,   111,   111,   111,   111,   111,
     679,   680,   196,   681,   682,   162,   111,   111,   111,    93,
     683,   684,    70,    28,   697,   111,   111,    29,   699,   504,
     504,    80,    91,    92,    93,   704,    77,   408,    28,   705,
      78,    79,    29,   358,   724,   345,    80,   706,   708,   716,
     715,   717,   196,   718,   196,   725,   726,   517,   727,   731,
     345,   345,   345,   345,   345,   732,   345,   345,   345,   533,
     733,   734,   345,   739,   740,   744,   754,   745,   748,   749,
     517,   345,   345,   345,   758,   759,   767,   760,   405,   768,
     331,   348,   778,   162,   112,   112,   785,   702,  -182,   821,
     112,   201,   517,   112,   771,   781,   711,   712,   784,   311,
     787,    92,    93,   643,   422,   788,    28,   791,   792,   824,
      29,   795,   312,   112,   112,   796,   797,   803,   424,   313,
     314,   805,   315,   806,   517,   816,   407,   407,   407,   407,
     407,   407,   407,   817,   825,   316,   317,   318,   773,   741,
     573,   573,   818,   424,   424,   424,   424,   424,   112,   112,
     820,   738,   707,   742,   804,   407,   753,   441,   440,   762,
     722,   504,   756,   368,   492,   757,   802,   111,   112,   123,
     504,   504,   799,   637,   112,   755,   786,   761,   772,   302,
     811,   752,   698,   126,   201,   201,   480,   303,   626,   307,
     127,    91,    92,    93,   597,    77,   465,    28,   743,    78,
      79,    29,   427,   345,   769,    80,   345,     0,   827,   750,
     517,   517,   326,   712,    91,    92,    93,   687,    77,   201,
      28,     0,    78,    79,    29,     0,     0,     0,    80,     0,
     504,   345,   345,   504,   422,     0,   504,     0,   345,   504,
     801,     0,   405,   405,   405,   405,   405,   405,   405,     0,
       0,     0,     0,   639,   517,   517,     0,   384,     0,   579,
     579,   579,   579,   579,     0,   639,     0,     0,   290,     0,
     312,   592,   291,     0,     0,   728,   364,   313,   314,   663,
     315,   729,     0,     0,     0,     0,     0,   504,     0,     0,
       0,     0,   127,   316,   317,   385,     0,     0,     0,     0,
       0,     0,     0,   112,   112,   112,   201,     0,     0,     0,
       0,   112,     0,     0,   504,     0,   112,   448,   112,     0,
     111,   164,   112,   112,   112,   112,   112,   504,     0,     0,
     812,     0,     0,   112,   112,   112,     0,     0,     0,   504,
     345,     0,   112,   112,   449,   450,     0,     0,   451,   452,
     345,     0,   453,     0,     0,   454,     0,     0,     0,     0,
       0,    27,   201,    28,     0,     0,     0,    29,     0,     0,
       0,     0,     0,     0,   518,     0,   448,   201,   201,   201,
     201,   201,     0,   201,   201,   201,     0,     0,     0,   201,
       0,     0,     0,     0,   111,     0,   111,   518,   201,   201,
     201,     0,     0,   449,   450,     0,   407,   451,   452,     0,
       0,   453,     0,   345,   454,   517,   345,     0,     0,   518,
      27,     0,    28,     0,   345,     0,    29,     0,     0,     0,
       0,   517,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   208,   209,     0,   210,   211,   212,   213,     0,
       0,   518,     0,     0,     0,   123,     0,   214,   215,   570,
     571,   663,     0,     0,   345,   578,   345,   115,   115,   126,
     219,   220,     0,   158,   204,   269,   115,     0,     0,     0,
       0,     0,     0,   221,   345,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   112,     0,   115,   115,     0,     0,
      91,    92,    93,   163,    77,     0,    28,     0,    78,    79,
      29,     0,     0,     0,    80,     0,     0,     0,     0,     0,
       0,     0,   592,     0,     0,   123,     0,     0,     0,     0,
     201,   115,   115,   201,     0,   302,     0,   518,   518,   126,
       0,     0,     0,     0,     0,     0,   127,     0,     0,     0,
       0,   115,     0,     0,     0,     0,     0,   158,   201,   201,
       0,     0,     0,     0,     0,   201,   335,   346,   204,     0,
      91,    92,    93,     0,    77,     0,    28,     0,    78,    79,
      29,   518,   518,     0,    80,     0,     0,     0,     0,     0,
       0,     0,   384,   208,   209,     0,   210,   211,   212,   213,
       0,     0,   346,   290,     0,   312,   123,   291,   214,   215,
     216,   217,   313,   314,     0,   315,   218,     0,     0,   348,
     126,   219,   220,   335,    70,   269,     0,   127,   316,   317,
     385,     0,     0,     0,   221,     0,     0,   276,     0,     0,
       0,     0,     0,     0,    71,    72,    73,   112,    74,    75,
       0,    91,    92,    93,   163,    77,   164,    28,     0,    78,
      79,    29,     0,     0,    76,    80,     0,   201,    77,     0,
      28,     0,    78,    79,    29,     0,     0,   201,    80,     0,
       0,     0,   149,     0,     0,     0,   115,   115,   115,   204,
     269,     0,   150,     0,   115,     0,     0,     0,     0,   115,
       0,   115,     0,    90,     0,   115,   115,   115,   115,   115,
       0,     0,     0,     0,     0,     0,   115,   115,   115,     0,
       0,   112,     0,   112,     0,   115,   115,    91,    92,    93,
       0,    77,     0,    28,     0,    78,    79,    29,     0,     0,
     201,    80,   518,   201,     0,   346,     0,     0,     0,     0,
       0,   201,     0,     0,     0,     0,     0,   519,   518,     0,
     346,   346,   346,   346,   346,     0,   346,   346,   346,     0,
       0,     0,   346,     0,     0,     0,     0,     0,     0,     0,
     519,   346,   346,   346,     0,     0,     0,     0,     0,     0,
       0,   201,     0,   201,   116,   116,     0,     0,     0,     0,
     116,   205,   519,   116,   208,   209,     0,   210,   211,   212,
     213,   201,   287,     0,     0,     0,     0,   123,     0,   214,
     215,   216,   217,   116,   116,     0,     0,   378,     0,     0,
     339,   126,   219,   220,   519,   379,     0,     0,   127,     0,
       0,     0,     0,     0,     0,   221,     0,    91,    92,    93,
       0,    77,     0,    28,     0,    78,    79,    29,   116,   116,
     355,    80,    91,    92,    93,   163,    77,   164,    28,     0,
      78,    79,    29,   312,     0,     0,    80,   115,   116,     0,
     313,   314,     0,   315,   116,     0,     0,     0,     0,     0,
       0,     0,     0,   336,   205,   205,   316,   317,   356,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   208,   209,
       0,   210,     0,   346,     0,     0,   346,     0,     0,     0,
     519,   519,     0,   214,     0,   570,   571,     0,     0,   205,
       0,   662,     0,   123,     0,     0,   219,   159,   160,     0,
     335,   346,   346,   338,     0,     0,   339,   126,   346,   221,
     336,   340,   149,     0,   127,     0,     0,     0,     0,     0,
       0,   162,    89,     0,   519,   519,    91,    92,    93,   643,
      77,     0,    28,    90,    78,    79,    29,   335,    91,    92,
      93,   163,    77,   164,    28,     0,    78,    79,    29,     0,
       0,     0,    80,     0,     0,     0,     0,    91,    92,    93,
       0,    77,     0,    28,     0,    78,    79,    29,     0,     0,
       0,    80,     0,   116,   116,   116,   205,     0,     0,     0,
      89,   116,     0,     0,     0,     0,   116,     0,   116,     0,
     115,    90,   116,   116,   116,   116,   116,     0,     0,     0,
       0,     0,     0,   116,   116,   116,     0,     0,     0,     0,
     346,     0,   116,   116,     0,    91,    92,    93,     0,    77,
       0,    28,     0,    78,    79,    29,     0,   113,   113,    80,
       0,     0,   205,   113,   202,     0,   113,     0,     0,     0,
       0,     0,     0,     0,   336,     0,     0,   205,   205,   205,
     205,   205,     0,   205,   205,   205,   113,   113,     0,   205,
       0,   150,     0,     0,   115,     0,   115,   336,   205,   205,
     205,     0,    90,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   346,     0,   519,   346,     0,     0,   336,
       0,   113,   113,     0,   346,     0,    91,    92,    93,     0,
      77,   519,    28,     0,    78,    79,    29,    90,     0,     0,
      80,   113,     0,     0,     0,     0,     0,   113,     0,     0,
       0,   336,     0,     0,     0,     0,   333,   202,   202,     0,
       0,    91,    92,    93,   346,    77,   346,    28,     0,    78,
      79,    29,     0,     0,     0,    80,     0,     0,     0,     0,
       0,     0,   384,   208,   209,     0,   210,   211,   212,   213,
       0,     0,   202,   290,   116,   312,   123,   291,   214,   215,
     216,   217,   313,   314,     0,   315,   378,     0,     0,   348,
     126,   219,   220,   333,     0,     0,     0,   127,   316,   317,
     385,     0,     0,     0,   221,     0,     0,     0,     0,     0,
     205,     0,     0,   205,     0,     0,     0,   336,   336,     0,
       0,    91,    92,    93,   163,    77,   164,    28,     0,    78,
      79,    29,     0,     0,     0,    80,     0,   336,   205,   205,
       0,     0,     0,     0,     0,   205,     0,   400,     0,     0,
     401,     0,     0,     0,     0,     0,   113,   113,   113,   202,
     312,   336,   336,     0,   113,     0,     0,   313,   314,   113,
     315,   113,     0,     0,   336,   113,   113,   113,   113,   113,
       0,     0,     0,   316,   317,   402,   113,   113,   113,     0,
       0,     0,     0,     0,     0,   113,   113,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     114,   114,     0,     0,     0,   202,   114,   203,     0,   114,
       0,     0,     0,     0,     0,     0,     0,   116,     0,     0,
     202,   202,   202,   202,   202,     0,   202,   202,   202,   114,
     114,    70,   202,     0,     0,     0,     0,   205,     0,     0,
     546,   202,   202,   202,     0,     0,     0,     0,     0,     0,
       0,    71,    72,    73,     0,    74,    75,     0,     0,     0,
       0,     0,     0,     0,   114,   114,     0,     0,     0,     0,
       0,    76,     0,     0,     0,    77,     0,    28,     0,    78,
      79,    29,     0,     0,   114,    80,     0,     0,     0,     0,
     114,   116,     0,   116,   546,     0,     0,     0,     0,   334,
     203,   203,     0,     0,     0,     0,     0,     0,     0,     0,
     205,     0,   336,   205,     0,     0,     0,     0,     0,     0,
       0,   205,     0,     0,     0,     0,   208,   209,   336,   210,
     211,   212,   213,     0,     0,   203,     0,   113,     0,   123,
       0,   214,   215,   216,   217,     0,     0,     0,     0,   378,
       0,     0,     0,   126,   219,   220,   334,   379,     0,     0,
     127,   205,     0,   205,     0,     0,     0,   221,     0,     0,
       0,     0,     0,   202,     0,     0,   202,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,   163,    77,   164,
      28,     0,    78,    79,    29,     0,     0,     0,    80,     0,
     333,   202,   202,     0,     0,     0,     0,     0,   202,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   114,
     114,   114,   203,     0,     0,     0,     0,   114,     0,     0,
       0,     0,   114,     0,   114,     0,     0,   333,   114,   114,
     114,   114,   114,     0,     0,     0,     0,     0,     0,   114,
     114,   114,     0,     0,     0,     0,     0,     0,   114,   114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   117,   117,     0,     0,     0,   203,   117,
     206,     0,   117,     0,     0,     0,     0,     0,     0,     0,
     113,     0,     0,   203,   203,   203,   203,   203,     0,   203,
     203,   203,   117,   117,     0,   203,     0,     0,     0,     0,
     202,     0,     0,   334,   203,   203,   203,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     123,     0,     0,     0,   159,   364,     0,   117,   117,     0,
     365,     0,     0,     0,   126,     0,     0,     0,     0,     0,
       0,   127,     0,     0,     0,     0,     0,   117,   162,     0,
       0,     0,     0,   117,   113,     0,   113,   334,     0,     0,
       0,     0,     0,   347,   206,     0,    92,    93,   163,     0,
     164,    28,     0,   202,   144,    29,   202,     0,     0,    80,
     198,     0,   144,     0,   202,     0,   208,   209,     0,   210,
     211,   212,   213,     0,     0,     0,     0,     0,     0,   123,
     114,   214,   215,   216,   217,     0,     0,     0,     0,   218,
       0,     0,     0,   126,   219,   220,     0,     0,     0,     0,
     127,     0,     0,     0,   202,     0,   202,   221,     0,     0,
       0,     0,     0,     0,     0,     0,   203,   144,   144,   203,
       0,     0,     0,     0,    91,    92,    93,   163,    77,   164,
      28,     0,    78,    79,    29,     0,     0,   144,    80,     0,
       0,     0,     0,   334,   203,   203,     0,     0,     0,     0,
       0,   203,     0,   198,   198,     0,     0,     0,     0,     0,
       0,     0,   117,   117,   117,   206,     0,     0,     0,     0,
     117,     0,     0,     0,     0,   117,     0,   117,     0,     0,
     334,   117,   117,   117,   117,   117,     0,     0,   198,     0,
       0,     0,   117,   117,   117,     0,     0,     0,     0,     0,
       0,   117,   117,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   206,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   114,     0,     0,   206,   206,   206,   206,
     206,     0,   347,   206,   206,     0,     0,     0,   206,     0,
       0,     0,     0,   203,     0,     0,     0,   347,   347,   347,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   123,
       0,     0,     0,   144,   124,   198,     0,     0,     0,   125,
       0,     0,     0,   126,     0,     0,     0,     0,     0,     0,
     127,     0,     0,     0,     0,   144,     0,     0,     0,     0,
       0,     0,   144,   144,   144,     0,     0,   114,     0,   114,
       0,   144,   144,     0,    91,    92,    93,     0,    77,     0,
      28,     0,    78,    79,    29,     0,   203,     0,    80,   203,
       0,   198,     0,     0,     0,     0,     0,   203,     0,     0,
       0,     0,     0,     0,     0,     0,   198,   198,   198,   198,
     198,     0,   198,   117,     0,     0,     0,     0,   198,     0,
       0,     0,     0,     0,     0,     0,     0,   198,   198,   198,
       0,     0,     0,     0,     0,     0,     0,   203,     0,   203,
       0,     0,     0,     0,   384,   208,   209,     0,   210,   211,
     212,   213,   347,     0,     0,   290,     0,   312,   123,   291,
     214,   215,   216,   217,   313,   314,     0,   315,   378,     0,
       0,     0,   126,   219,   220,     0,     0,   347,   206,   127,
     316,   317,   385,     0,   347,     0,   221,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,   163,    77,   164,    28,
       0,    78,    79,    29,     0,     0,     0,    80,     0,     0,
       0,     0,     0,   144,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     208,   209,     0,   210,   211,   212,   213,     0,     0,     0,
       0,     0,     0,   123,     0,   214,   215,   216,   217,     0,
       0,     0,   198,   378,     0,     0,   117,   126,   219,   220,
       0,     0,     0,     0,   127,     0,     0,     0,     0,     0,
       0,   221,     0,     0,     0,     0,   206,   198,   198,     0,
       0,     0,     0,     0,   198,     0,     0,     0,    91,    92,
      93,   163,    77,   164,    28,     0,    78,    79,    29,     0,
       0,     0,    80,     0,     0,     0,   208,   209,     0,   210,
     211,   212,   213,     0,     0,     0,     0,     0,     0,   123,
       0,   214,   215,   216,   217,     0,     0,     0,     0,   420,
     117,     0,   117,   126,   219,   220,     0,     0,     0,     0,
     127,     0,     0,     0,     0,     0,     0,   221,     0,     0,
       0,     0,   347,     0,     0,     0,     0,     0,     0,     0,
     206,     0,     0,     0,    91,    92,    93,   163,    77,   164,
      28,     0,    78,    79,    29,     0,     0,     0,    80,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   208,   209,
       0,   210,   211,   212,   213,     0,     0,     0,     0,     0,
     347,   123,   347,   214,   215,   216,   735,     0,     0,     0,
       0,   378,     0,     0,     0,   126,   219,   220,     0,     0,
       0,     0,   127,     0,     0,     0,     0,     0,     0,   221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     144,     0,     0,     0,     0,     0,    91,    92,    93,   163,
      77,   164,    28,     0,    78,    79,    29,     0,     0,     0,
      80,     0,   198,     0,     0,     0,     0,     0,   123,     0,
     198,     0,   159,   160,     0,     0,     0,     0,   161,     0,
       0,   348,   126,     0,     0,     0,     0,     0,     0,   127,
       0,     0,     0,     0,     0,     0,   162,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     198,     0,   198,    91,    92,    93,   163,    77,   164,    28,
     123,    78,    79,    29,   159,   160,     0,    80,     0,     0,
     338,     0,     0,   348,   126,   123,     0,     0,     0,   159,
     160,   127,     0,     0,     0,   338,     0,     0,   162,   126,
       0,     0,     0,   340,     0,     0,   127,     0,     0,     0,
       0,     0,     0,   162,     0,    91,    92,    93,   163,    77,
     164,    28,     0,    78,    79,    29,     0,     0,     0,    80,
      91,    92,    93,   163,    77,   164,    28,   123,    78,    79,
      29,   159,   160,     0,    80,     0,     0,   161,     0,     0,
       0,   126,   123,     0,     0,     0,   159,   160,   127,     0,
       0,     0,   338,     0,     0,   162,   126,     0,     0,     0,
       0,     0,     0,   127,     0,     0,     0,     0,     0,     0,
     162,     0,    91,    92,    93,   163,    77,   164,    28,     0,
      78,    79,    29,     0,     0,     0,    80,    91,    92,    93,
     163,    77,   164,    28,     0,    78,    79,    29,     0,     0,
       0,    80
};

static const yytype_int16 yycheck[] =
{
       0,    20,    21,    22,    23,    24,    25,    26,   144,    66,
      67,   144,   426,   216,   144,    20,    21,    90,    23,    24,
      25,    26,   218,    61,   295,   237,   359,   491,   300,   301,
      59,    69,    51,    59,    34,    69,   195,   124,   125,    67,
      59,    67,    68,   506,    70,    64,    51,    63,    64,   142,
      60,    70,    67,    68,   371,   106,    66,   415,   550,    64,
     360,   361,   285,   187,    60,   281,   653,   550,   426,    22,
      66,   353,   354,   355,   356,   357,   292,   137,   294,    89,
      90,    60,   106,   299,   300,   301,   124,   125,   353,   354,
     355,   356,   357,    89,   353,   354,   355,   356,   357,    22,
      68,   414,   415,   416,   417,   418,   144,   259,    13,    30,
      89,    22,   172,   426,    27,    68,    13,   618,    22,    72,
     244,    34,   218,    27,    11,    68,    37,   146,    59,    37,
      35,    36,   719,   161,   160,   161,   187,   281,    25,    70,
     150,   146,    63,    64,    13,    68,    27,   195,   292,    72,
     294,    67,   245,    61,   150,   299,   300,   301,    11,    63,
     428,   429,   430,   187,    68,    27,    35,    36,    72,   195,
     230,   150,    25,   309,   310,   311,   309,   310,   311,   309,
     310,   311,   318,   319,    27,   318,   319,    27,   318,   319,
      13,   217,   218,   244,   353,   354,   355,   356,   357,   395,
     787,   360,   361,   218,    67,    36,    37,   233,   281,   432,
      27,   281,    35,    36,   287,   302,    27,    34,    27,   292,
     244,   294,   292,    27,   294,   282,   299,   300,   301,   299,
     300,   301,    67,   259,   374,   375,   376,   389,   289,    13,
     732,    13,   280,   744,   160,   161,   280,   748,   749,   732,
     218,    12,    13,   716,   282,   284,   282,   283,   284,   285,
     411,   412,   128,   677,   302,   284,   285,   282,   283,   279,
      13,   309,   310,   311,   217,   218,   295,   287,    11,   195,
     318,   319,   378,   279,   552,    66,   152,    68,   298,    37,
     744,    72,    25,   350,   748,   749,   322,    13,   161,   165,
     279,   327,   298,    13,   330,   353,   354,   355,   356,   357,
     338,   330,   338,    61,   631,   283,    13,   634,    11,   677,
     821,    69,   429,   430,   420,   160,   161,   353,   354,   355,
     356,   357,    25,   359,   360,   361,    68,   365,    68,   365,
     283,    36,    72,   643,    28,   371,   810,   506,   374,   375,
     376,   623,   378,   284,   285,    14,   222,    13,   373,    18,
     195,   557,   558,   389,   677,    30,   282,   570,    35,   509,
      29,   397,   398,   399,   400,   401,   402,   403,    13,    27,
     395,    13,    27,   470,   410,   411,   412,    13,   414,   415,
     416,   417,   418,   419,   420,    14,    15,   796,   797,    18,
     426,   541,   428,   429,   430,    14,   432,   623,   274,    18,
     378,    13,   427,   432,   233,    63,    13,    13,    63,   282,
      68,   233,   338,    68,    72,    13,    27,    72,    22,   448,
      12,    13,   470,    27,   767,   378,   769,   353,   354,   355,
     356,   357,   410,   359,    12,   727,    14,   282,    27,   365,
      18,   663,   420,    35,    36,   455,   513,    27,   374,   375,
     376,    29,   727,    27,   490,   491,    27,   410,   727,    63,
     413,   490,   491,   233,    68,   338,   572,   420,    72,   623,
      11,    27,   578,   509,   643,   428,   429,   430,    12,    13,
     353,   354,   355,   356,   357,    27,    14,   360,   361,   362,
      18,   432,   365,   338,    13,    22,    41,   535,   534,   535,
      27,    35,    36,    14,    15,   541,    27,    18,   353,   354,
     355,   356,   357,    22,   359,    14,   552,    40,    27,    18,
     365,    44,    45,    46,    47,   806,    27,    41,   734,   374,
     375,   376,   557,   558,     3,   571,   572,    64,    13,    29,
     623,    68,   578,   623,   825,    72,    14,   716,    14,    76,
      18,   697,    18,    27,   697,    64,   662,   697,   727,    68,
      35,    36,    14,    72,    22,    22,    18,    76,   397,   398,
     399,   400,   401,   402,   403,   397,   398,   399,   400,   401,
     402,   403,    11,   509,   613,   614,   615,   616,   617,    11,
      11,    30,    41,   629,   572,   631,   632,   426,   634,   552,
     578,    13,     3,   632,   426,   641,   642,   643,   534,   535,
      14,     6,   641,   642,    18,   541,    14,    14,   571,   572,
      18,    18,    14,    35,    36,   578,    18,   397,   398,   399,
     400,   401,   402,   403,    22,    14,   672,    60,    61,    18,
     676,   677,    27,    66,    67,    68,    69,    27,    41,   697,
      27,   718,     0,    27,   683,     6,   426,     3,    69,    37,
      22,    27,   535,    27,   509,   701,    89,    90,   704,   727,
      27,   707,   701,    36,   710,   704,    13,   687,   707,   699,
      35,   710,   692,   719,    14,    13,    36,    36,    35,   534,
     535,   727,    36,   699,   672,    36,   541,    22,    36,   735,
      48,   124,   125,    51,    52,    76,    35,    55,    56,   734,
      58,    59,    36,    34,    13,    35,   745,    36,    36,   672,
      36,   144,   758,    63,    64,    61,    22,   150,    68,   758,
     745,   767,    72,   769,    27,    12,    13,   160,   161,   330,
      30,   777,   778,    13,    35,    11,    22,    36,    36,   785,
       4,     5,    36,     7,    36,   791,   785,   735,    35,    36,
      37,    13,   798,    36,    36,    19,    30,    21,    22,   798,
     643,    36,   195,    27,   810,    36,    36,   806,    32,    36,
     653,   810,   735,    20,    61,    22,    36,    36,    27,    27,
      27,    45,    69,   719,    27,   218,   825,    27,    27,   777,
     778,   727,    36,   813,    13,    36,    30,    35,    62,    63,
      64,    36,    66,   791,    68,    13,    70,    71,    72,    35,
      13,    11,    76,    30,   777,   778,   491,    64,    22,    61,
      27,    68,    13,    36,    61,    72,    35,    13,   791,    76,
      36,   767,   233,   769,    30,    20,   719,    22,   677,    36,
      30,    36,    27,    61,   727,   677,   279,   280,   281,   282,
     283,    21,    22,    35,   287,    13,    11,    27,   259,   292,
      36,   294,     6,     6,   719,   298,   299,   300,   301,   302,
      36,    36,   727,    36,    30,    45,   309,   310,   311,    64,
      13,    35,    22,    68,    11,   318,   319,    72,    11,   490,
     491,    76,    62,    63,    64,    13,    66,   677,    68,    35,
      70,    71,    72,    15,   787,   338,    76,    36,    36,    13,
      36,    35,   767,    13,   769,    36,    36,   350,    11,    36,
     353,   354,   355,   356,   357,    13,   359,   360,   361,    21,
      35,    13,   365,    36,    11,    13,    35,    13,    13,    13,
     373,   374,   375,   376,    13,    36,    13,    34,   233,    12,
      30,    30,    13,    45,    60,    61,    11,   632,    12,    11,
      66,    67,   395,    69,    34,    36,   641,   642,    36,     3,
      13,    63,    64,    65,   259,    35,    68,    13,    35,    35,
      72,    13,    16,    89,    90,    13,    13,    36,   389,    23,
      24,    36,    26,    22,   427,    36,   397,   398,   399,   400,
     401,   402,   403,    36,    13,    39,    40,    41,   734,   676,
     411,   412,    36,   414,   415,   416,   417,   418,   124,   125,
      36,   672,    37,   677,   791,   426,   701,   283,   282,   718,
     653,   632,   707,   195,   330,   710,   787,   470,   144,    17,
     641,   642,   785,   491,   150,   704,   758,   716,   732,    27,
     798,   699,   629,    31,   160,   161,   321,    35,   470,   125,
      38,    62,    63,    64,   427,    66,   298,    68,   683,    70,
      71,    72,   264,   506,   723,    76,   509,    -1,   825,   692,
     513,   514,   146,   758,    62,    63,    64,   614,    66,   195,
      68,    -1,    70,    71,    72,    -1,    -1,    -1,    76,    -1,
     701,   534,   535,   704,   389,    -1,   707,    -1,   541,   710,
     785,    -1,   397,   398,   399,   400,   401,   402,   403,    -1,
      -1,    -1,    -1,   798,   557,   558,    -1,     3,    -1,   414,
     415,   416,   417,   418,    -1,   810,    -1,    -1,    14,    -1,
      16,   426,    18,    -1,    -1,    21,    22,    23,    24,   550,
      26,    27,    -1,    -1,    -1,    -1,    -1,   758,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   279,   280,   281,   282,    -1,    -1,    -1,
      -1,   287,    -1,    -1,   785,    -1,   292,    22,   294,    -1,
     623,    67,   298,   299,   300,   301,   302,   798,    -1,    -1,
      35,    -1,    -1,   309,   310,   311,    -1,    -1,    -1,   810,
     643,    -1,   318,   319,    49,    50,    -1,    -1,    53,    54,
     653,    -1,    57,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    66,   338,    68,    -1,    -1,    -1,    72,    -1,    -1,
      -1,    -1,    -1,    -1,   350,    -1,    22,   353,   354,   355,
     356,   357,    -1,   359,   360,   361,    -1,    -1,    -1,   365,
      -1,    -1,    -1,    -1,   697,    -1,   699,   373,   374,   375,
     376,    -1,    -1,    49,    50,    -1,   677,    53,    54,    -1,
      -1,    57,    -1,   716,    60,   718,   719,    -1,    -1,   395,
      66,    -1,    68,    -1,   727,    -1,    72,    -1,    -1,    -1,
      -1,   734,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     4,     5,    -1,     7,     8,     9,    10,    -1,
      -1,   427,    -1,    -1,    -1,    17,    -1,    19,    20,    21,
      22,   732,    -1,    -1,   767,    27,   769,    60,    61,    31,
      32,    33,    -1,    66,    67,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    45,   787,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   470,    -1,    89,    90,    -1,    -1,
      62,    63,    64,    65,    66,    -1,    68,    -1,    70,    71,
      72,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   677,    -1,    -1,    17,    -1,    -1,    -1,    -1,
     506,   124,   125,   509,    -1,    27,    -1,   513,   514,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,   144,    -1,    -1,    -1,    -1,    -1,   150,   534,   535,
      -1,    -1,    -1,    -1,    -1,   541,   159,   160,   161,    -1,
      62,    63,    64,    -1,    66,    -1,    68,    -1,    70,    71,
      72,   557,   558,    -1,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,    -1,     7,     8,     9,    10,
      -1,    -1,   195,    14,    -1,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    26,    27,    -1,    -1,    30,
      31,    32,    33,   216,    22,   218,    -1,    38,    39,    40,
      41,    -1,    -1,    -1,    45,    -1,    -1,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    44,   623,    46,    47,
      -1,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    -1,    -1,    62,    76,    -1,   643,    66,    -1,
      68,    -1,    70,    71,    72,    -1,    -1,   653,    76,    -1,
      -1,    -1,    17,    -1,    -1,    -1,   279,   280,   281,   282,
     283,    -1,    27,    -1,   287,    -1,    -1,    -1,    -1,   292,
      -1,   294,    -1,    38,    -1,   298,   299,   300,   301,   302,
      -1,    -1,    -1,    -1,    -1,    -1,   309,   310,   311,    -1,
      -1,   697,    -1,   699,    -1,   318,   319,    62,    63,    64,
      -1,    66,    -1,    68,    -1,    70,    71,    72,    -1,    -1,
     716,    76,   718,   719,    -1,   338,    -1,    -1,    -1,    -1,
      -1,   727,    -1,    -1,    -1,    -1,    -1,   350,   734,    -1,
     353,   354,   355,   356,   357,    -1,   359,   360,   361,    -1,
      -1,    -1,   365,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     373,   374,   375,   376,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   767,    -1,   769,    60,    61,    -1,    -1,    -1,    -1,
      66,    67,   395,    69,     4,     5,    -1,     7,     8,     9,
      10,   787,    27,    -1,    -1,    -1,    -1,    17,    -1,    19,
      20,    21,    22,    89,    90,    -1,    -1,    27,    -1,    -1,
      30,    31,    32,    33,   427,    35,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    62,    63,    64,
      -1,    66,    -1,    68,    -1,    70,    71,    72,   124,   125,
       3,    76,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    16,    -1,    -1,    76,   470,   144,    -1,
      23,    24,    -1,    26,   150,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   159,   160,   161,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,
      -1,     7,    -1,   506,    -1,    -1,   509,    -1,    -1,    -1,
     513,   514,    -1,    19,    -1,    21,    22,    -1,    -1,   195,
      -1,    27,    -1,    17,    -1,    -1,    32,    21,    22,    -1,
     533,   534,   535,    27,    -1,    -1,    30,    31,   541,    45,
     216,    35,    17,    -1,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    27,    -1,   557,   558,    62,    63,    64,    65,
      66,    -1,    68,    38,    70,    71,    72,   570,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    62,    63,    64,
      -1,    66,    -1,    68,    -1,    70,    71,    72,    -1,    -1,
      -1,    76,    -1,   279,   280,   281,   282,    -1,    -1,    -1,
      27,   287,    -1,    -1,    -1,    -1,   292,    -1,   294,    -1,
     623,    38,   298,   299,   300,   301,   302,    -1,    -1,    -1,
      -1,    -1,    -1,   309,   310,   311,    -1,    -1,    -1,    -1,
     643,    -1,   318,   319,    -1,    62,    63,    64,    -1,    66,
      -1,    68,    -1,    70,    71,    72,    -1,    60,    61,    76,
      -1,    -1,   338,    66,    67,    -1,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   350,    -1,    -1,   353,   354,   355,
     356,   357,    -1,   359,   360,   361,    89,    90,    -1,   365,
      -1,    27,    -1,    -1,   697,    -1,   699,   373,   374,   375,
     376,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   716,    -1,   718,   719,    -1,    -1,   395,
      -1,   124,   125,    -1,   727,    -1,    62,    63,    64,    -1,
      66,   734,    68,    -1,    70,    71,    72,    38,    -1,    -1,
      76,   144,    -1,    -1,    -1,    -1,    -1,   150,    -1,    -1,
      -1,   427,    -1,    -1,    -1,    -1,   159,   160,   161,    -1,
      -1,    62,    63,    64,   767,    66,   769,    68,    -1,    70,
      71,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,    -1,     7,     8,     9,    10,
      -1,    -1,   195,    14,   470,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    26,    27,    -1,    -1,    30,
      31,    32,    33,   216,    -1,    -1,    -1,    38,    39,    40,
      41,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,
     506,    -1,    -1,   509,    -1,    -1,    -1,   513,   514,    -1,
      -1,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    -1,    -1,    -1,    76,    -1,   533,   534,   535,
      -1,    -1,    -1,    -1,    -1,   541,    -1,     3,    -1,    -1,
       6,    -1,    -1,    -1,    -1,    -1,   279,   280,   281,   282,
      16,   557,   558,    -1,   287,    -1,    -1,    23,    24,   292,
      26,   294,    -1,    -1,   570,   298,   299,   300,   301,   302,
      -1,    -1,    -1,    39,    40,    41,   309,   310,   311,    -1,
      -1,    -1,    -1,    -1,    -1,   318,   319,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    61,    -1,    -1,    -1,   338,    66,    67,    -1,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   623,    -1,    -1,
     353,   354,   355,   356,   357,    -1,   359,   360,   361,    89,
      90,    22,   365,    -1,    -1,    -1,    -1,   643,    -1,    -1,
     373,   374,   375,   376,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    44,    -1,    46,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   124,   125,    -1,    -1,    -1,    -1,
      -1,    62,    -1,    -1,    -1,    66,    -1,    68,    -1,    70,
      71,    72,    -1,    -1,   144,    76,    -1,    -1,    -1,    -1,
     150,   697,    -1,   699,   427,    -1,    -1,    -1,    -1,   159,
     160,   161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     716,    -1,   718,   719,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   727,    -1,    -1,    -1,    -1,     4,     5,   734,     7,
       8,     9,    10,    -1,    -1,   195,    -1,   470,    -1,    17,
      -1,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    27,
      -1,    -1,    -1,    31,    32,    33,   216,    35,    -1,    -1,
      38,   767,    -1,   769,    -1,    -1,    -1,    45,    -1,    -1,
      -1,    -1,    -1,   506,    -1,    -1,   509,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    -1,    -1,    -1,    76,    -1,
     533,   534,   535,    -1,    -1,    -1,    -1,    -1,   541,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   279,
     280,   281,   282,    -1,    -1,    -1,    -1,   287,    -1,    -1,
      -1,    -1,   292,    -1,   294,    -1,    -1,   570,   298,   299,
     300,   301,   302,    -1,    -1,    -1,    -1,    -1,    -1,   309,
     310,   311,    -1,    -1,    -1,    -1,    -1,    -1,   318,   319,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    61,    -1,    -1,    -1,   338,    66,
      67,    -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     623,    -1,    -1,   353,   354,   355,   356,   357,    -1,   359,
     360,   361,    89,    90,    -1,   365,    -1,    -1,    -1,    -1,
     643,    -1,    -1,   373,   374,   375,   376,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    -1,    -1,    -1,    21,    22,    -1,   124,   125,    -1,
      27,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,   144,    45,    -1,
      -1,    -1,    -1,   150,   697,    -1,   699,   427,    -1,    -1,
      -1,    -1,    -1,   160,   161,    -1,    63,    64,    65,    -1,
      67,    68,    -1,   716,    61,    72,   719,    -1,    -1,    76,
      67,    -1,    69,    -1,   727,    -1,     4,     5,    -1,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
     470,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    27,
      -1,    -1,    -1,    31,    32,    33,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    -1,   767,    -1,   769,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   506,   124,   125,   509,
      -1,    -1,    -1,    -1,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    -1,    -1,   144,    76,    -1,
      -1,    -1,    -1,   533,   534,   535,    -1,    -1,    -1,    -1,
      -1,   541,    -1,   160,   161,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   279,   280,   281,   282,    -1,    -1,    -1,    -1,
     287,    -1,    -1,    -1,    -1,   292,    -1,   294,    -1,    -1,
     570,   298,   299,   300,   301,   302,    -1,    -1,   195,    -1,
      -1,    -1,   309,   310,   311,    -1,    -1,    -1,    -1,    -1,
      -1,   318,   319,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   338,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   623,    -1,    -1,   353,   354,   355,   356,
     357,    -1,   359,   360,   361,    -1,    -1,    -1,   365,    -1,
      -1,    -1,    -1,   643,    -1,    -1,    -1,   374,   375,   376,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      -1,    -1,    -1,   280,    22,   282,    -1,    -1,    -1,    27,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    -1,    -1,   302,    -1,    -1,    -1,    -1,
      -1,    -1,   309,   310,   311,    -1,    -1,   697,    -1,   699,
      -1,   318,   319,    -1,    62,    63,    64,    -1,    66,    -1,
      68,    -1,    70,    71,    72,    -1,   716,    -1,    76,   719,
      -1,   338,    -1,    -1,    -1,    -1,    -1,   727,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   353,   354,   355,   356,
     357,    -1,   359,   470,    -1,    -1,    -1,    -1,   365,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   374,   375,   376,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   767,    -1,   769,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,     8,
       9,    10,   509,    -1,    -1,    14,    -1,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,    26,    27,    -1,
      -1,    -1,    31,    32,    33,    -1,    -1,   534,   535,    38,
      39,    40,    41,    -1,   541,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    -1,   470,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       4,     5,    -1,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    -1,    19,    20,    21,    22,    -1,
      -1,    -1,   509,    27,    -1,    -1,   623,    31,    32,    33,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    -1,    -1,    -1,    -1,   643,   534,   535,    -1,
      -1,    -1,    -1,    -1,   541,    -1,    -1,    -1,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    -1,
      -1,    -1,    76,    -1,    -1,    -1,     4,     5,    -1,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      -1,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    27,
     697,    -1,   699,    31,    32,    33,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,
      -1,    -1,   719,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     727,    -1,    -1,    -1,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,
      -1,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
     767,    17,   769,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    27,    -1,    -1,    -1,    31,    32,    33,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     697,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    -1,    -1,    -1,
      76,    -1,   719,    -1,    -1,    -1,    -1,    -1,    17,    -1,
     727,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    -1,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     767,    -1,   769,    62,    63,    64,    65,    66,    67,    68,
      17,    70,    71,    72,    21,    22,    -1,    76,    -1,    -1,
      27,    -1,    -1,    30,    31,    17,    -1,    -1,    -1,    21,
      22,    38,    -1,    -1,    -1,    27,    -1,    -1,    45,    31,
      -1,    -1,    -1,    35,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    -1,    -1,    -1,    76,
      62,    63,    64,    65,    66,    67,    68,    17,    70,    71,
      72,    21,    22,    -1,    76,    -1,    -1,    27,    -1,    -1,
      -1,    31,    17,    -1,    -1,    -1,    21,    22,    38,    -1,
      -1,    -1,    27,    -1,    -1,    45,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    -1,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    -1,    -1,    -1,    76,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    -1,    -1,
      -1,    76
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,    78,   304,     0,    48,    51,    52,    55,    56,    58,
      59,    79,    80,    81,    83,    84,    85,    86,    87,   287,
      27,    27,    27,    27,    27,    27,    27,    66,    68,    72,
     298,   299,   298,   299,   303,   298,   298,   298,   298,    13,
      13,    13,   288,   304,    13,    13,    13,    13,    68,    89,
      89,    22,    37,   289,    36,    89,    89,    89,    89,    28,
      13,    13,   290,   298,    13,    30,    13,    13,    13,    13,
      22,    42,    43,    44,    46,    47,    62,    66,    70,    71,
      76,   266,   292,   293,   294,   295,   296,   299,   302,    27,
      38,    62,    63,    64,   210,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   227,   228,   232,   233,
     234,   257,   258,   259,   260,   261,   262,   265,   266,   299,
     300,   301,   302,    17,    22,    27,    31,    38,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     215,   229,   230,   242,   245,    35,    13,   291,   298,    17,
      27,   173,   199,   200,   201,   232,   253,   257,   261,    21,
      22,    27,    45,    65,    67,   137,   138,   139,   140,   141,
     142,   143,   144,   146,   147,   148,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   168,   170,   171,   173,
     185,   186,   187,   192,   198,   240,   241,   242,   245,   253,
     257,   258,   259,   260,   261,   262,   265,   266,     4,     5,
       7,     8,     9,    10,    19,    20,    21,    22,    27,    32,
      33,    45,    90,    91,    92,    93,    94,    95,    96,    97,
      98,   100,   101,   102,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   120,   122,   123,   126,   128,   130,
     131,   132,   133,   134,   135,   136,   188,   198,   235,   236,
     237,   238,   241,   245,   253,   257,   258,   259,   260,   261,
     262,   264,   265,   266,    82,   202,    35,   292,   297,    27,
      27,    27,    27,    27,    11,    27,   232,    27,   215,   227,
      14,    18,   254,   255,   256,    13,    88,   304,    41,    27,
      27,    27,    27,    35,   203,   231,   203,   229,    88,    41,
       3,     3,    16,    23,    24,    26,    39,    40,    41,   243,
      29,   246,    22,   209,   211,   212,   290,    22,   173,    88,
      11,    30,   196,   259,   260,   261,   262,   263,    27,    30,
      35,   138,   169,   171,   172,   257,   261,   265,    30,   138,
      27,    30,    88,    41,     3,     3,    41,   243,    15,   248,
     254,   256,   246,     6,    22,    27,   145,   146,   153,   155,
     266,    22,    25,   239,    27,    27,    27,   196,    27,    35,
      91,   125,   257,   261,     3,    41,    91,   121,   126,   236,
     243,   244,   253,   255,   256,    27,    88,    41,     3,     6,
       3,     6,    41,   243,    98,   100,   105,   108,   112,   122,
     248,   254,   256,   246,    37,    61,    69,    37,    69,    22,
      27,    99,   100,   106,   108,   266,    11,   239,    27,    27,
      27,    88,    13,    35,   232,   202,   221,   224,   225,   227,
     137,    90,   292,   297,    36,   215,   227,   227,    22,    49,
      50,    53,    54,    57,    60,   267,   269,   270,   272,   274,
     275,   277,   279,   298,    36,   234,   226,   227,   226,   226,
      13,    35,    36,    36,    36,   211,   211,   211,   211,   211,
     230,   214,   266,   149,   150,   151,   266,    36,    36,    20,
      22,    27,   174,   175,   176,   178,   179,   181,   183,   249,
     250,   251,   266,   299,   300,    34,    27,    34,    35,    13,
      35,    36,    36,    22,    27,   162,   173,   257,   258,   261,
      61,    36,   144,   146,   152,   155,   159,   171,   144,   144,
     144,   144,   169,    21,    22,    27,   155,   170,   266,   170,
     171,    27,   138,   149,   252,   253,   259,   172,   172,   172,
      27,    34,    13,    35,    36,    36,    36,    22,    27,   115,
     126,    36,    98,    98,    98,    98,    98,    98,    98,    91,
      21,    22,    27,   108,   120,   266,   120,   122,    27,   100,
     128,   128,   131,   128,   128,   128,   103,   104,   266,    91,
      97,    98,   100,   127,   128,   129,   131,   252,   124,   125,
     124,   124,    36,   297,    36,    36,    36,    36,    36,    36,
      36,   267,   268,    27,    27,    27,    27,    27,    13,   285,
     304,    30,    36,    13,    36,    36,   231,    30,    35,    13,
      35,    13,    11,    30,    22,   174,   184,   175,   178,   179,
     182,    61,    27,    65,   155,   186,   193,   194,   195,   197,
     172,   163,   173,    13,    30,   138,   172,    36,    35,    36,
      36,    36,    27,   108,   135,   189,   190,   191,   197,   125,
     116,   126,    13,    30,    91,    35,    13,    11,    36,    36,
      36,    36,    30,    13,    35,   280,   299,   303,   271,   299,
     273,   299,   278,   299,   286,   296,   226,    11,   214,    11,
     149,    27,   179,   149,    13,    35,    36,    37,    36,    36,
      37,   179,   179,   180,   170,    36,    13,    35,    13,    22,
     156,   164,   165,   166,   171,    36,    36,    11,    21,    27,
     236,    36,    13,    35,    13,    22,    91,   117,   118,    36,
      11,   103,   127,   268,    13,    13,   276,   304,    13,    13,
     285,   211,   200,   179,    35,   184,   179,   179,    13,    36,
      34,   193,   163,   156,   165,   167,   171,    13,    12,   247,
     144,    34,   189,   116,    91,   118,   119,   247,    13,   286,
     298,    36,   286,   286,    36,    11,   180,    13,    35,   169,
     169,    13,    35,    91,    91,    13,    13,    13,    27,   176,
     177,   179,   167,    36,   119,    36,    22,   281,   281,   281,
      27,   181,    35,   267,   282,   283,    36,    36,    36,   178,
      36,    11,   284,   304,    35,    13,   296,   282
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,    77,    78,    78,    79,    79,    80,    80,    80,    80,
      80,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      88,    89,    89,    90,    90,    90,    91,    91,    91,    91,
      91,    91,    92,    92,    92,    93,    94,    94,    94,    95,
      95,    96,    96,    97,    97,    98,    98,    98,    99,    99,
     100,   100,   100,   100,   101,   102,   103,   103,   104,   105,
     105,   106,   107,   108,   108,   108,   108,   109,   109,   110,
     110,   110,   110,   110,   111,   111,   112,   113,   114,   115,
     115,   116,   116,   117,   117,   118,   119,   119,   120,   120,
     120,   121,   121,   121,   121,   121,   122,   122,   123,   123,
     123,   124,   125,   125,   126,   126,   127,   127,   127,   128,
     129,   130,   130,   130,   131,   131,   132,   132,   133,   133,
     134,   135,   136,   137,   137,   137,   138,   138,   138,   138,
     138,   138,   139,   139,   140,   141,   141,   142,   142,   143,
     143,   144,   144,   144,   145,   145,   146,   146,   146,   146,
     147,   148,   149,   149,   150,   150,   151,   152,   152,   153,
     154,   155,   155,   155,   156,   156,   157,   158,   158,   158,
     158,   159,   160,   160,   161,   162,   162,   163,   163,   164,
     164,   165,   166,   166,   167,   167,   168,   169,   169,   169,
     170,   170,   170,   170,   170,   171,   171,   172,   172,   173,
     173,   174,   174,   175,   175,   175,   176,   177,   177,   177,
     178,   178,   179,   179,   179,   179,   179,   179,   180,   180,
     181,   182,   182,   183,   184,   184,   185,   186,   187,   188,
     188,   189,   189,   190,   190,   191,   192,   192,   193,   193,
     194,   194,   195,   196,   197,   198,   198,   198,   198,   199,
     199,   200,   200,   201,   202,   202,   203,   203,   203,   204,
     204,   205,   206,   206,   207,   207,   208,   208,   209,   209,
     210,   211,   211,   212,   212,   212,   213,   214,   214,   215,
     215,   215,   216,   217,   217,   218,   219,   220,   221,   221,
     222,   222,   223,   224,   224,   225,   225,   226,   226,   227,
     227,   228,   228,   228,   229,   229,   230,   230,   231,   231,
     232,   232,   233,   233,   234,   234,   234,   234,   235,   235,
     235,   236,   236,   237,   237,   238,   238,   238,   239,   240,
     240,   241,   241,   242,   242,   243,   243,   243,   243,   243,
     243,   244,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   252,   253,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   263,   264,   264,   264,   264,   264,
     265,   265,   266,   267,   267,   267,   267,   267,   268,   268,
     269,   269,   270,   271,   272,   273,   274,   274,   274,   275,
     276,   276,   277,   278,   279,   280,   281,   281,   282,   282,
     283,   284,   284,   285,   285,   286,   287,   288,   288,   288,
     289,   289,   290,   290,   291,   292,   292,   292,   293,   293,
     293,   293,   293,   293,   294,   295,   295,   295,   295,   295,
     296,   296,   297,   297,   298,   298,   299,   299,   300,   301,
     302,   302,   302,   303,   304
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
  case 2: /* TPTP_file: nothing  */
#line 230 "SyntaxBNF.y"
                    {}
#line 2903 "y.tab.c"
    break;

  case 3: /* TPTP_file: TPTP_file TPTP_input  */
#line 231 "SyntaxBNF.y"
                                           {}
#line 2909 "y.tab.c"
    break;

  case 4: /* TPTP_input: annotated_formula  */
#line 234 "SyntaxBNF.y"
                               {P_PRINT((yyval.pval));}
#line 2915 "y.tab.c"
    break;

  case 5: /* TPTP_input: include  */
#line 235 "SyntaxBNF.y"
                              {P_PRINT((yyval.pval));}
#line 2921 "y.tab.c"
    break;

  case 6: /* annotated_formula: thf_annotated  */
#line 238 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2927 "y.tab.c"
    break;

  case 7: /* annotated_formula: tff_annotated  */
#line 239 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2933 "y.tab.c"
    break;

  case 8: /* annotated_formula: tcf_annotated  */
#line 240 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2939 "y.tab.c"
    break;

  case 9: /* annotated_formula: fof_annotated  */
#line 241 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2945 "y.tab.c"
    break;

  case 10: /* annotated_formula: cnf_annotated  */
#line 242 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2951 "y.tab.c"
    break;

  case 11: /* annotated_formula: tpi_annotated  */
#line 243 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2957 "y.tab.c"
    break;

  case 12: /* tpi_annotated: _LIT_tpi LPAREN name COMMA formula_role COMMA tpi_formula annotations RPAREN PERIOD  */
#line 246 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("tpi_annotated", P_TOKEN("_LIT_tpi ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 2963 "y.tab.c"
    break;

  case 13: /* tpi_formula: fof_formula  */
#line 249 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("tpi_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2969 "y.tab.c"
    break;

  case 14: /* thf_annotated: _LIT_thf LPAREN name COMMA formula_role COMMA thf_formula annotations RPAREN PERIOD  */
#line 252 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("thf_annotated", P_TOKEN("_LIT_thf ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 2975 "y.tab.c"
    break;

  case 15: /* tff_annotated: _LIT_tff LPAREN name COMMA formula_role COMMA tff_formula annotations RPAREN PERIOD  */
#line 255 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("tff_annotated", P_TOKEN("_LIT_tff ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 2981 "y.tab.c"
    break;

  case 16: /* tcf_annotated: _LIT_tcf LPAREN name COMMA formula_role COMMA tcf_formula annotations RPAREN PERIOD  */
#line 258 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("tcf_annotated", P_TOKEN("_LIT_tcf ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 2987 "y.tab.c"
    break;

  case 17: /* fof_annotated: _LIT_fof LPAREN name COMMA formula_role COMMA fof_formula annotations RPAREN PERIOD  */
#line 261 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("fof_annotated", P_TOKEN("_LIT_fof ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 2993 "y.tab.c"
    break;

  case 18: /* cnf_annotated: _LIT_cnf LPAREN name COMMA formula_role COMMA cnf_formula annotations RPAREN PERIOD  */
#line 264 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("cnf_annotated", P_TOKEN("_LIT_cnf ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 2999 "y.tab.c"
    break;

  case 19: /* annotations: COMMA source optional_info  */
#line 267 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("annotations", P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3005 "y.tab.c"
    break;

  case 20: /* annotations: nothing  */
#line 268 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("annotations", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3011 "y.tab.c"
    break;

  case 21: /* formula_role: lower_word  */
#line 271 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("formula_role", P_TOKEN("lower_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3017 "y.tab.c"
    break;

  case 22: /* formula_role: lower_word MINUS general_term  */
#line 272 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("formula_role", P_TOKEN("lower_word ", (yyvsp[-2].ival)), P_TOKEN("MINUS ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3023 "y.tab.c"
    break;

  case 23: /* thf_formula: thf_logic_formula  */
#line 275 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3029 "y.tab.c"
    break;

  case 24: /* thf_formula: thf_atom_typing  */
#line 276 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3035 "y.tab.c"
    break;

  case 25: /* thf_formula: thf_subtype  */
#line 277 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("thf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3041 "y.tab.c"
    break;

  case 26: /* thf_logic_formula: thf_unitary_formula  */
#line 280 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3047 "y.tab.c"
    break;

  case 27: /* thf_logic_formula: thf_unary_formula  */
#line 281 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3053 "y.tab.c"
    break;

  case 28: /* thf_logic_formula: thf_binary_formula  */
#line 282 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3059 "y.tab.c"
    break;

  case 29: /* thf_logic_formula: thf_defined_infix  */
#line 283 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3065 "y.tab.c"
    break;

  case 30: /* thf_logic_formula: thf_definition  */
#line 284 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3071 "y.tab.c"
    break;

  case 31: /* thf_logic_formula: thf_sequent  */
#line 285 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3077 "y.tab.c"
    break;

  case 32: /* thf_binary_formula: thf_binary_nonassoc  */
#line 288 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3083 "y.tab.c"
    break;

  case 33: /* thf_binary_formula: thf_binary_assoc  */
#line 289 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3089 "y.tab.c"
    break;

  case 34: /* thf_binary_formula: thf_binary_type  */
#line 290 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3095 "y.tab.c"
    break;

  case 35: /* thf_binary_nonassoc: thf_unit_formula nonassoc_connective thf_unit_formula  */
#line 293 "SyntaxBNF.y"
                                                                            {(yyval.pval) = P_BUILD("thf_binary_nonassoc", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3101 "y.tab.c"
    break;

  case 36: /* thf_binary_assoc: thf_or_formula  */
#line 296 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("thf_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3107 "y.tab.c"
    break;

  case 37: /* thf_binary_assoc: thf_and_formula  */
#line 297 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3113 "y.tab.c"
    break;

  case 38: /* thf_binary_assoc: thf_apply_formula  */
#line 298 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3119 "y.tab.c"
    break;

  case 39: /* thf_or_formula: thf_unit_formula VLINE thf_unit_formula  */
#line 301 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("thf_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3125 "y.tab.c"
    break;

  case 40: /* thf_or_formula: thf_or_formula VLINE thf_unit_formula  */
#line 302 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("thf_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3131 "y.tab.c"
    break;

  case 41: /* thf_and_formula: thf_unit_formula AMPERSAND thf_unit_formula  */
#line 305 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3137 "y.tab.c"
    break;

  case 42: /* thf_and_formula: thf_and_formula AMPERSAND thf_unit_formula  */
#line 306 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3143 "y.tab.c"
    break;

  case 43: /* thf_apply_formula: thf_unit_formula AT_SIGN thf_unit_formula  */
#line 309 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_apply_formula", (yyvsp[-2].pval), P_TOKEN("AT_SIGN ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3149 "y.tab.c"
    break;

  case 44: /* thf_apply_formula: thf_apply_formula AT_SIGN thf_unit_formula  */
#line 310 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_apply_formula", (yyvsp[-2].pval), P_TOKEN("AT_SIGN ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3155 "y.tab.c"
    break;

  case 45: /* thf_unit_formula: thf_unitary_formula  */
#line 313 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3161 "y.tab.c"
    break;

  case 46: /* thf_unit_formula: thf_unary_formula  */
#line 314 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3167 "y.tab.c"
    break;

  case 47: /* thf_unit_formula: thf_defined_infix  */
#line 315 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3173 "y.tab.c"
    break;

  case 48: /* thf_preunit_formula: thf_unitary_formula  */
#line 318 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("thf_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3179 "y.tab.c"
    break;

  case 49: /* thf_preunit_formula: thf_prefix_unary  */
#line 319 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3185 "y.tab.c"
    break;

  case 50: /* thf_unitary_formula: thf_quantified_formula  */
#line 322 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("thf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3191 "y.tab.c"
    break;

  case 51: /* thf_unitary_formula: thf_atomic_formula  */
#line 323 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3197 "y.tab.c"
    break;

  case 52: /* thf_unitary_formula: variable  */
#line 324 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("thf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3203 "y.tab.c"
    break;

  case 53: /* thf_unitary_formula: LPAREN thf_logic_formula RPAREN  */
#line 325 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("thf_unitary_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3209 "y.tab.c"
    break;

  case 54: /* thf_quantified_formula: thf_quantification thf_unit_formula  */
#line 328 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("thf_quantified_formula", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3215 "y.tab.c"
    break;

  case 55: /* thf_quantification: thf_quantifier LBRKT thf_variable_list RBRKT COLON  */
#line 331 "SyntaxBNF.y"
                                                                        {(yyval.pval) = P_BUILD("thf_quantification", (yyvsp[-4].pval), P_TOKEN("LBRKT ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("RBRKT ", (yyvsp[-1].ival)), P_TOKEN("COLON ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL);}
#line 3221 "y.tab.c"
    break;

  case 56: /* thf_variable_list: thf_typed_variable  */
#line 334 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_variable_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3227 "y.tab.c"
    break;

  case 57: /* thf_variable_list: thf_typed_variable COMMA thf_variable_list  */
#line 335 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_variable_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3233 "y.tab.c"
    break;

  case 58: /* thf_typed_variable: variable COLON thf_top_level_type  */
#line 338 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("thf_typed_variable", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3239 "y.tab.c"
    break;

  case 59: /* thf_unary_formula: thf_prefix_unary  */
#line 341 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3245 "y.tab.c"
    break;

  case 60: /* thf_unary_formula: thf_infix_unary  */
#line 342 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3251 "y.tab.c"
    break;

  case 61: /* thf_prefix_unary: thf_unary_connective thf_preunit_formula  */
#line 345 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("thf_prefix_unary", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3257 "y.tab.c"
    break;

  case 62: /* thf_infix_unary: thf_unitary_term infix_inequality thf_unitary_term  */
#line 348 "SyntaxBNF.y"
                                                                     {(yyval.pval) = P_BUILD("thf_infix_unary", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3263 "y.tab.c"
    break;

  case 63: /* thf_atomic_formula: thf_plain_atomic  */
#line 351 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3269 "y.tab.c"
    break;

  case 64: /* thf_atomic_formula: thf_defined_atomic  */
#line 352 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3275 "y.tab.c"
    break;

  case 65: /* thf_atomic_formula: thf_system_atomic  */
#line 353 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3281 "y.tab.c"
    break;

  case 66: /* thf_atomic_formula: thf_fof_function  */
#line 354 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3287 "y.tab.c"
    break;

  case 67: /* thf_plain_atomic: constant  */
#line 357 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("thf_plain_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3293 "y.tab.c"
    break;

  case 68: /* thf_plain_atomic: thf_tuple  */
#line 358 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_plain_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3299 "y.tab.c"
    break;

  case 69: /* thf_defined_atomic: defined_constant  */
#line 361 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3305 "y.tab.c"
    break;

  case 70: /* thf_defined_atomic: thf_defined_term  */
#line 362 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3311 "y.tab.c"
    break;

  case 71: /* thf_defined_atomic: LPAREN thf_conn_term RPAREN  */
#line 363 "SyntaxBNF.y"
                                                  {(yyval.pval) = P_BUILD("thf_defined_atomic", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3317 "y.tab.c"
    break;

  case 72: /* thf_defined_atomic: nhf_long_connective  */
#line 364 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3323 "y.tab.c"
    break;

  case 73: /* thf_defined_atomic: thf_let  */
#line 365 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3329 "y.tab.c"
    break;

  case 74: /* thf_defined_term: defined_term  */
#line 368 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3335 "y.tab.c"
    break;

  case 75: /* thf_defined_term: th1_defined_term  */
#line 369 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3341 "y.tab.c"
    break;

  case 76: /* thf_defined_infix: thf_unitary_term defined_infix_pred thf_unitary_term  */
#line 372 "SyntaxBNF.y"
                                                                         {(yyval.pval) = P_BUILD("thf_defined_infix", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3347 "y.tab.c"
    break;

  case 77: /* thf_system_atomic: system_constant  */
#line 375 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("thf_system_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3353 "y.tab.c"
    break;

  case 78: /* thf_let: _DLR_let LPAREN thf_let_types COMMA thf_let_defns COMMA thf_logic_formula RPAREN  */
#line 378 "SyntaxBNF.y"
                                                                                           {(yyval.pval) = P_BUILD("thf_let", P_TOKEN("_DLR_let ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 3359 "y.tab.c"
    break;

  case 79: /* thf_let_types: thf_atom_typing  */
#line 381 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_let_types", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3365 "y.tab.c"
    break;

  case 80: /* thf_let_types: LBRKT thf_atom_typing_list RBRKT  */
#line 382 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("thf_let_types", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3371 "y.tab.c"
    break;

  case 81: /* thf_atom_typing_list: thf_atom_typing  */
#line 385 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_atom_typing_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3377 "y.tab.c"
    break;

  case 82: /* thf_atom_typing_list: thf_atom_typing COMMA thf_atom_typing_list  */
#line 386 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_atom_typing_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3383 "y.tab.c"
    break;

  case 83: /* thf_let_defns: thf_let_defn  */
#line 389 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("thf_let_defns", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3389 "y.tab.c"
    break;

  case 84: /* thf_let_defns: LBRKT thf_let_defn_list RBRKT  */
#line 390 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("thf_let_defns", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3395 "y.tab.c"
    break;

  case 85: /* thf_let_defn: thf_logic_formula assignment thf_logic_formula  */
#line 393 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_let_defn", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3401 "y.tab.c"
    break;

  case 86: /* thf_let_defn_list: thf_let_defn  */
#line 396 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("thf_let_defn_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3407 "y.tab.c"
    break;

  case 87: /* thf_let_defn_list: thf_let_defn COMMA thf_let_defn_list  */
#line 397 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_let_defn_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3413 "y.tab.c"
    break;

  case 88: /* thf_unitary_term: thf_atomic_formula  */
#line 400 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3419 "y.tab.c"
    break;

  case 89: /* thf_unitary_term: variable  */
#line 401 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("thf_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3425 "y.tab.c"
    break;

  case 90: /* thf_unitary_term: LPAREN thf_logic_formula RPAREN  */
#line 402 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("thf_unitary_term", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3431 "y.tab.c"
    break;

  case 91: /* thf_conn_term: nonassoc_connective  */
#line 405 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3437 "y.tab.c"
    break;

  case 92: /* thf_conn_term: assoc_connective  */
#line 406 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3443 "y.tab.c"
    break;

  case 93: /* thf_conn_term: infix_equality  */
#line 407 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3449 "y.tab.c"
    break;

  case 94: /* thf_conn_term: infix_inequality  */
#line 408 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3455 "y.tab.c"
    break;

  case 95: /* thf_conn_term: thf_unary_connective  */
#line 409 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3461 "y.tab.c"
    break;

  case 96: /* thf_tuple: LBRKT RBRKT  */
#line 412 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("thf_tuple", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3467 "y.tab.c"
    break;

  case 97: /* thf_tuple: LBRKT thf_formula_list RBRKT  */
#line 413 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("thf_tuple", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3473 "y.tab.c"
    break;

  case 98: /* thf_fof_function: functor LPAREN thf_arguments RPAREN  */
#line 416 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("thf_fof_function", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3479 "y.tab.c"
    break;

  case 99: /* thf_fof_function: defined_functor LPAREN thf_arguments RPAREN  */
#line 417 "SyntaxBNF.y"
                                                                  {(yyval.pval) = P_BUILD("thf_fof_function", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3485 "y.tab.c"
    break;

  case 100: /* thf_fof_function: system_functor LPAREN thf_arguments RPAREN  */
#line 418 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_fof_function", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3491 "y.tab.c"
    break;

  case 101: /* thf_arguments: thf_formula_list  */
#line 421 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("thf_arguments", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3497 "y.tab.c"
    break;

  case 102: /* thf_formula_list: thf_logic_formula  */
#line 424 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_formula_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3503 "y.tab.c"
    break;

  case 103: /* thf_formula_list: thf_logic_formula COMMA thf_formula_list  */
#line 425 "SyntaxBNF.y"
                                                               {(yyval.pval) = P_BUILD("thf_formula_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3509 "y.tab.c"
    break;

  case 104: /* thf_atom_typing: untyped_atom COLON thf_top_level_type  */
#line 428 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("thf_atom_typing", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3515 "y.tab.c"
    break;

  case 105: /* thf_atom_typing: LPAREN thf_atom_typing RPAREN  */
#line 429 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("thf_atom_typing", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3521 "y.tab.c"
    break;

  case 106: /* thf_top_level_type: thf_unitary_type  */
#line 432 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3527 "y.tab.c"
    break;

  case 107: /* thf_top_level_type: thf_mapping_type  */
#line 433 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3533 "y.tab.c"
    break;

  case 108: /* thf_top_level_type: thf_apply_type  */
#line 434 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3539 "y.tab.c"
    break;

  case 109: /* thf_unitary_type: thf_unitary_formula  */
#line 437 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_unitary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3545 "y.tab.c"
    break;

  case 110: /* thf_apply_type: thf_apply_formula  */
#line 440 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("thf_apply_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3551 "y.tab.c"
    break;

  case 111: /* thf_binary_type: thf_mapping_type  */
#line 443 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("thf_binary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3557 "y.tab.c"
    break;

  case 112: /* thf_binary_type: thf_xprod_type  */
#line 444 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_binary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3563 "y.tab.c"
    break;

  case 113: /* thf_binary_type: thf_union_type  */
#line 445 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_binary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3569 "y.tab.c"
    break;

  case 114: /* thf_mapping_type: thf_unitary_type arrow thf_unitary_type  */
#line 448 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_mapping_type", (yyvsp[-2].pval), P_TOKEN("arrow ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3575 "y.tab.c"
    break;

  case 115: /* thf_mapping_type: thf_unitary_type arrow thf_mapping_type  */
#line 449 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_mapping_type", (yyvsp[-2].pval), P_TOKEN("arrow ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3581 "y.tab.c"
    break;

  case 116: /* thf_xprod_type: thf_unitary_type STAR thf_unitary_type  */
#line 452 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("thf_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3587 "y.tab.c"
    break;

  case 117: /* thf_xprod_type: thf_xprod_type STAR thf_unitary_type  */
#line 453 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3593 "y.tab.c"
    break;

  case 118: /* thf_union_type: thf_unitary_type plus thf_unitary_type  */
#line 456 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("thf_union_type", (yyvsp[-2].pval), P_TOKEN("plus ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3599 "y.tab.c"
    break;

  case 119: /* thf_union_type: thf_union_type plus thf_unitary_type  */
#line 457 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_union_type", (yyvsp[-2].pval), P_TOKEN("plus ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3605 "y.tab.c"
    break;

  case 120: /* thf_subtype: untyped_atom subtype_sign atom  */
#line 460 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("thf_subtype", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3611 "y.tab.c"
    break;

  case 121: /* thf_definition: thf_atomic_formula identical thf_logic_formula  */
#line 463 "SyntaxBNF.y"
                                                                {(yyval.pval) = P_BUILD("thf_definition", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3617 "y.tab.c"
    break;

  case 122: /* thf_sequent: thf_tuple gentzen_arrow thf_tuple  */
#line 466 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("thf_sequent", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3623 "y.tab.c"
    break;

  case 123: /* tff_formula: tff_logic_formula  */
#line 469 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3629 "y.tab.c"
    break;

  case 124: /* tff_formula: tff_atom_typing  */
#line 470 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3635 "y.tab.c"
    break;

  case 125: /* tff_formula: tff_subtype  */
#line 471 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tff_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3641 "y.tab.c"
    break;

  case 126: /* tff_logic_formula: tff_unitary_formula  */
#line 474 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3647 "y.tab.c"
    break;

  case 127: /* tff_logic_formula: tff_unary_formula  */
#line 475 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3653 "y.tab.c"
    break;

  case 128: /* tff_logic_formula: tff_binary_formula  */
#line 476 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3659 "y.tab.c"
    break;

  case 129: /* tff_logic_formula: tff_defined_infix  */
#line 477 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3665 "y.tab.c"
    break;

  case 130: /* tff_logic_formula: txf_definition  */
#line 478 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3671 "y.tab.c"
    break;

  case 131: /* tff_logic_formula: txf_sequent  */
#line 479 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3677 "y.tab.c"
    break;

  case 132: /* tff_binary_formula: tff_binary_nonassoc  */
#line 482 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3683 "y.tab.c"
    break;

  case 133: /* tff_binary_formula: tff_binary_assoc  */
#line 483 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3689 "y.tab.c"
    break;

  case 134: /* tff_binary_nonassoc: tff_unit_formula nonassoc_connective tff_unit_formula  */
#line 486 "SyntaxBNF.y"
                                                                            {(yyval.pval) = P_BUILD("tff_binary_nonassoc", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3695 "y.tab.c"
    break;

  case 135: /* tff_binary_assoc: tff_or_formula  */
#line 489 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tff_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3701 "y.tab.c"
    break;

  case 136: /* tff_binary_assoc: tff_and_formula  */
#line 490 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3707 "y.tab.c"
    break;

  case 137: /* tff_or_formula: tff_unit_formula VLINE tff_unit_formula  */
#line 493 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("tff_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3713 "y.tab.c"
    break;

  case 138: /* tff_or_formula: tff_or_formula VLINE tff_unit_formula  */
#line 494 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("tff_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3719 "y.tab.c"
    break;

  case 139: /* tff_and_formula: tff_unit_formula AMPERSAND tff_unit_formula  */
#line 497 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("tff_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3725 "y.tab.c"
    break;

  case 140: /* tff_and_formula: tff_and_formula AMPERSAND tff_unit_formula  */
#line 498 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("tff_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3731 "y.tab.c"
    break;

  case 141: /* tff_unit_formula: tff_unitary_formula  */
#line 501 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3737 "y.tab.c"
    break;

  case 142: /* tff_unit_formula: tff_unary_formula  */
#line 502 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3743 "y.tab.c"
    break;

  case 143: /* tff_unit_formula: tff_defined_infix  */
#line 503 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3749 "y.tab.c"
    break;

  case 144: /* tff_preunit_formula: tff_unitary_formula  */
#line 506 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3755 "y.tab.c"
    break;

  case 145: /* tff_preunit_formula: tff_prefix_unary  */
#line 507 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3761 "y.tab.c"
    break;

  case 146: /* tff_unitary_formula: tff_quantified_formula  */
#line 510 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("tff_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3767 "y.tab.c"
    break;

  case 147: /* tff_unitary_formula: tff_atomic_formula  */
#line 511 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3773 "y.tab.c"
    break;

  case 148: /* tff_unitary_formula: txf_unitary_formula  */
#line 512 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3779 "y.tab.c"
    break;

  case 149: /* tff_unitary_formula: LPAREN tff_logic_formula RPAREN  */
#line 513 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("tff_unitary_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3785 "y.tab.c"
    break;

  case 150: /* txf_unitary_formula: variable  */
#line 516 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("txf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3791 "y.tab.c"
    break;

  case 151: /* tff_quantified_formula: tff_quantifier LBRKT tff_variable_list RBRKT COLON tff_unit_formula  */
#line 519 "SyntaxBNF.y"
                                                                                             {(yyval.pval) = P_BUILD("tff_quantified_formula", (yyvsp[-5].pval), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 3797 "y.tab.c"
    break;

  case 152: /* tff_variable_list: tff_variable  */
#line 522 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("tff_variable_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3803 "y.tab.c"
    break;

  case 153: /* tff_variable_list: tff_variable COMMA tff_variable_list  */
#line 523 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("tff_variable_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3809 "y.tab.c"
    break;

  case 154: /* tff_variable: tff_typed_variable  */
#line 526 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tff_variable", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3815 "y.tab.c"
    break;

  case 155: /* tff_variable: variable  */
#line 527 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_variable", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3821 "y.tab.c"
    break;

  case 156: /* tff_typed_variable: variable COLON tff_atomic_type  */
#line 530 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("tff_typed_variable", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3827 "y.tab.c"
    break;

  case 157: /* tff_unary_formula: tff_prefix_unary  */
#line 533 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3833 "y.tab.c"
    break;

  case 158: /* tff_unary_formula: tff_infix_unary  */
#line 534 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3839 "y.tab.c"
    break;

  case 159: /* tff_prefix_unary: tff_unary_connective tff_preunit_formula  */
#line 537 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("tff_prefix_unary", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3845 "y.tab.c"
    break;

  case 160: /* tff_infix_unary: tff_unitary_term infix_inequality tff_unitary_term  */
#line 540 "SyntaxBNF.y"
                                                                     {(yyval.pval) = P_BUILD("tff_infix_unary", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3851 "y.tab.c"
    break;

  case 161: /* tff_atomic_formula: tff_plain_atomic  */
#line 543 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3857 "y.tab.c"
    break;

  case 162: /* tff_atomic_formula: tff_defined_atomic  */
#line 544 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3863 "y.tab.c"
    break;

  case 163: /* tff_atomic_formula: tff_system_atomic  */
#line 545 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3869 "y.tab.c"
    break;

  case 164: /* tff_plain_atomic: constant  */
#line 548 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("tff_plain_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3875 "y.tab.c"
    break;

  case 165: /* tff_plain_atomic: functor LPAREN tff_arguments RPAREN  */
#line 549 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("tff_plain_atomic", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3881 "y.tab.c"
    break;

  case 166: /* tff_defined_atomic: tff_defined_plain  */
#line 552 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3887 "y.tab.c"
    break;

  case 167: /* tff_defined_plain: defined_constant  */
#line 555 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3893 "y.tab.c"
    break;

  case 168: /* tff_defined_plain: defined_functor LPAREN tff_arguments RPAREN  */
#line 556 "SyntaxBNF.y"
                                                                  {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3899 "y.tab.c"
    break;

  case 169: /* tff_defined_plain: nxf_atom  */
#line 557 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3905 "y.tab.c"
    break;

  case 170: /* tff_defined_plain: txf_let  */
#line 558 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3911 "y.tab.c"
    break;

  case 171: /* tff_defined_infix: tff_unitary_term defined_infix_pred tff_unitary_term  */
#line 561 "SyntaxBNF.y"
                                                                         {(yyval.pval) = P_BUILD("tff_defined_infix", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3917 "y.tab.c"
    break;

  case 172: /* tff_system_atomic: system_constant  */
#line 564 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("tff_system_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3923 "y.tab.c"
    break;

  case 173: /* tff_system_atomic: system_functor LPAREN tff_arguments RPAREN  */
#line 565 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("tff_system_atomic", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3929 "y.tab.c"
    break;

  case 174: /* txf_let: _DLR_let LPAREN txf_let_types COMMA txf_let_defns COMMA tff_term RPAREN  */
#line 568 "SyntaxBNF.y"
                                                                                  {(yyval.pval) = P_BUILD("txf_let", P_TOKEN("_DLR_let ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 3935 "y.tab.c"
    break;

  case 175: /* txf_let_types: tff_atom_typing  */
#line 571 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("txf_let_types", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3941 "y.tab.c"
    break;

  case 176: /* txf_let_types: LBRKT tff_atom_typing_list RBRKT  */
#line 572 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("txf_let_types", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3947 "y.tab.c"
    break;

  case 177: /* tff_atom_typing_list: tff_atom_typing  */
#line 575 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_atom_typing_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3953 "y.tab.c"
    break;

  case 178: /* tff_atom_typing_list: tff_atom_typing COMMA tff_atom_typing_list  */
#line 576 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("tff_atom_typing_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3959 "y.tab.c"
    break;

  case 179: /* txf_let_defns: txf_let_defn  */
#line 579 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("txf_let_defns", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3965 "y.tab.c"
    break;

  case 180: /* txf_let_defns: LBRKT txf_let_defn_list RBRKT  */
#line 580 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("txf_let_defns", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3971 "y.tab.c"
    break;

  case 181: /* txf_let_defn: txf_let_LHS assignment tff_term  */
#line 583 "SyntaxBNF.y"
                                               {(yyval.pval) = P_BUILD("txf_let_defn", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3977 "y.tab.c"
    break;

  case 182: /* txf_let_LHS: tff_plain_atomic  */
#line 586 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("txf_let_LHS", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3983 "y.tab.c"
    break;

  case 183: /* txf_let_LHS: txf_tuple  */
#line 587 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("txf_let_LHS", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3989 "y.tab.c"
    break;

  case 184: /* txf_let_defn_list: txf_let_defn  */
#line 590 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("txf_let_defn_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3995 "y.tab.c"
    break;

  case 185: /* txf_let_defn_list: txf_let_defn COMMA txf_let_defn_list  */
#line 591 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("txf_let_defn_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4001 "y.tab.c"
    break;

  case 186: /* nxf_atom: nxf_long_connective AT_SIGN LPAREN tff_arguments RPAREN  */
#line 594 "SyntaxBNF.y"
                                                                   {(yyval.pval) = P_BUILD("nxf_atom", (yyvsp[-4].pval), P_TOKEN("AT_SIGN ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL);}
#line 4007 "y.tab.c"
    break;

  case 187: /* tff_term: tff_logic_formula  */
#line 597 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("tff_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4013 "y.tab.c"
    break;

  case 188: /* tff_term: defined_term  */
#line 598 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4019 "y.tab.c"
    break;

  case 189: /* tff_term: txf_tuple  */
#line 599 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4025 "y.tab.c"
    break;

  case 190: /* tff_unitary_term: tff_atomic_formula  */
#line 602 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4031 "y.tab.c"
    break;

  case 191: /* tff_unitary_term: defined_term  */
#line 603 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4037 "y.tab.c"
    break;

  case 192: /* tff_unitary_term: txf_tuple  */
#line 604 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4043 "y.tab.c"
    break;

  case 193: /* tff_unitary_term: variable  */
#line 605 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4049 "y.tab.c"
    break;

  case 194: /* tff_unitary_term: LPAREN tff_logic_formula RPAREN  */
#line 606 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("tff_unitary_term", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4055 "y.tab.c"
    break;

  case 195: /* txf_tuple: LBRKT RBRKT  */
#line 609 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("txf_tuple", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4061 "y.tab.c"
    break;

  case 196: /* txf_tuple: LBRKT tff_arguments RBRKT  */
#line 610 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("txf_tuple", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4067 "y.tab.c"
    break;

  case 197: /* tff_arguments: tff_term  */
#line 613 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_arguments", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4073 "y.tab.c"
    break;

  case 198: /* tff_arguments: tff_term COMMA tff_arguments  */
#line 614 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("tff_arguments", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4079 "y.tab.c"
    break;

  case 199: /* tff_atom_typing: untyped_atom COLON tff_top_level_type  */
#line 617 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("tff_atom_typing", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4085 "y.tab.c"
    break;

  case 200: /* tff_atom_typing: LPAREN tff_atom_typing RPAREN  */
#line 618 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("tff_atom_typing", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4091 "y.tab.c"
    break;

  case 201: /* tff_top_level_type: tff_atomic_type  */
#line 621 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4097 "y.tab.c"
    break;

  case 202: /* tff_top_level_type: tff_non_atomic_type  */
#line 622 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4103 "y.tab.c"
    break;

  case 203: /* tff_non_atomic_type: tff_mapping_type  */
#line 625 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_non_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4109 "y.tab.c"
    break;

  case 204: /* tff_non_atomic_type: tf1_quantified_type  */
#line 626 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_non_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4115 "y.tab.c"
    break;

  case 205: /* tff_non_atomic_type: LPAREN tff_non_atomic_type RPAREN  */
#line 627 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("tff_non_atomic_type", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4121 "y.tab.c"
    break;

  case 206: /* tf1_quantified_type: EXCLAMATION_GREATER LBRKT tff_variable_list RBRKT COLON tff_monotype  */
#line 630 "SyntaxBNF.y"
                                                                                           {(yyval.pval) = P_BUILD("tf1_quantified_type", P_TOKEN("EXCLAMATION_GREATER ", (yyvsp[-5].ival)), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 4127 "y.tab.c"
    break;

  case 207: /* tff_monotype: tff_atomic_type  */
#line 633 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_monotype", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4133 "y.tab.c"
    break;

  case 208: /* tff_monotype: LPAREN tff_mapping_type RPAREN  */
#line 634 "SyntaxBNF.y"
                                                     {(yyval.pval) = P_BUILD("tff_monotype", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4139 "y.tab.c"
    break;

  case 209: /* tff_monotype: tf1_quantified_type  */
#line 635 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_monotype", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4145 "y.tab.c"
    break;

  case 210: /* tff_unitary_type: tff_atomic_type  */
#line 638 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_unitary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4151 "y.tab.c"
    break;

  case 211: /* tff_unitary_type: LPAREN tff_xprod_type RPAREN  */
#line 639 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("tff_unitary_type", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4157 "y.tab.c"
    break;

  case 212: /* tff_atomic_type: type_constant  */
#line 642 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4163 "y.tab.c"
    break;

  case 213: /* tff_atomic_type: defined_type  */
#line 643 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4169 "y.tab.c"
    break;

  case 214: /* tff_atomic_type: variable  */
#line 644 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4175 "y.tab.c"
    break;

  case 215: /* tff_atomic_type: type_functor LPAREN tff_type_arguments RPAREN  */
#line 645 "SyntaxBNF.y"
                                                                    {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4181 "y.tab.c"
    break;

  case 216: /* tff_atomic_type: LPAREN tff_atomic_type RPAREN  */
#line 646 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("tff_atomic_type", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4187 "y.tab.c"
    break;

  case 217: /* tff_atomic_type: txf_tuple_type  */
#line 647 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4193 "y.tab.c"
    break;

  case 218: /* tff_type_arguments: tff_atomic_type  */
#line 650 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_type_arguments", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4199 "y.tab.c"
    break;

  case 219: /* tff_type_arguments: tff_atomic_type COMMA tff_type_arguments  */
#line 651 "SyntaxBNF.y"
                                                               {(yyval.pval) = P_BUILD("tff_type_arguments", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4205 "y.tab.c"
    break;

  case 220: /* tff_mapping_type: tff_unitary_type arrow tff_atomic_type  */
#line 654 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("tff_mapping_type", (yyvsp[-2].pval), P_TOKEN("arrow ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4211 "y.tab.c"
    break;

  case 221: /* tff_xprod_type: tff_unitary_type STAR tff_atomic_type  */
#line 657 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("tff_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4217 "y.tab.c"
    break;

  case 222: /* tff_xprod_type: tff_xprod_type STAR tff_atomic_type  */
#line 658 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("tff_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4223 "y.tab.c"
    break;

  case 223: /* txf_tuple_type: LBRKT tff_type_list RBRKT  */
#line 661 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("txf_tuple_type", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4229 "y.tab.c"
    break;

  case 224: /* tff_type_list: tff_top_level_type  */
#line 664 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_type_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4235 "y.tab.c"
    break;

  case 225: /* tff_type_list: tff_top_level_type COMMA tff_type_list  */
#line 665 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("tff_type_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4241 "y.tab.c"
    break;

  case 226: /* tff_subtype: untyped_atom subtype_sign atom  */
#line 668 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("tff_subtype", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4247 "y.tab.c"
    break;

  case 227: /* txf_definition: tff_atomic_formula identical tff_term  */
#line 671 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("txf_definition", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4253 "y.tab.c"
    break;

  case 228: /* txf_sequent: txf_tuple gentzen_arrow txf_tuple  */
#line 674 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("txf_sequent", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4259 "y.tab.c"
    break;

  case 229: /* nhf_long_connective: LBRACE ntf_connective_name RBRACE  */
#line 677 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("nhf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4265 "y.tab.c"
    break;

  case 230: /* nhf_long_connective: LBRACE ntf_connective_name LPAREN nhf_parameter_list RPAREN RBRACE  */
#line 678 "SyntaxBNF.y"
                                                                                         {(yyval.pval) = P_BUILD("nhf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-5].ival)), (yyvsp[-4].pval), P_TOKEN("LPAREN ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL);}
#line 4271 "y.tab.c"
    break;

  case 231: /* nhf_parameter_list: nhf_parameter  */
#line 681 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("nhf_parameter_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4277 "y.tab.c"
    break;

  case 232: /* nhf_parameter_list: nhf_parameter COMMA nhf_parameter_list  */
#line 682 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("nhf_parameter_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4283 "y.tab.c"
    break;

  case 233: /* nhf_parameter: ntf_index  */
#line 685 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("nhf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4289 "y.tab.c"
    break;

  case 234: /* nhf_parameter: nhf_key_pair  */
#line 686 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("nhf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4295 "y.tab.c"
    break;

  case 235: /* nhf_key_pair: thf_definition  */
#line 689 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("nhf_key_pair", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4301 "y.tab.c"
    break;

  case 236: /* nxf_long_connective: LBRACE ntf_connective_name RBRACE  */
#line 692 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("nxf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4307 "y.tab.c"
    break;

  case 237: /* nxf_long_connective: LBRACE ntf_connective_name LPAREN nxf_parameter_list RPAREN RBRACE  */
#line 693 "SyntaxBNF.y"
                                                                                         {(yyval.pval) = P_BUILD("nxf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-5].ival)), (yyvsp[-4].pval), P_TOKEN("LPAREN ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL);}
#line 4313 "y.tab.c"
    break;

  case 238: /* nxf_parameter_list: nxf_parameter  */
#line 696 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("nxf_parameter_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4319 "y.tab.c"
    break;

  case 239: /* nxf_parameter_list: nxf_parameter COMMA nxf_parameter_list  */
#line 697 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("nxf_parameter_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4325 "y.tab.c"
    break;

  case 240: /* nxf_parameter: ntf_index  */
#line 700 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("nxf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4331 "y.tab.c"
    break;

  case 241: /* nxf_parameter: nxf_key_pair  */
#line 701 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("nxf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4337 "y.tab.c"
    break;

  case 242: /* nxf_key_pair: txf_definition  */
#line 704 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("nxf_key_pair", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4343 "y.tab.c"
    break;

  case 243: /* ntf_connective_name: def_or_sys_constant  */
#line 707 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("ntf_connective_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4349 "y.tab.c"
    break;

  case 244: /* ntf_index: hash tff_unitary_term  */
#line 710 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("ntf_index", P_TOKEN("hash ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4355 "y.tab.c"
    break;

  case 245: /* ntf_short_connective: LBRKT PERIOD RBRKT  */
#line 713 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4361 "y.tab.c"
    break;

  case 246: /* ntf_short_connective: less_sign PERIOD arrow  */
#line 714 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("less_sign ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("arrow ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4367 "y.tab.c"
    break;

  case 247: /* ntf_short_connective: LBRACE PERIOD RBRACE  */
#line 715 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("LBRACE ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4373 "y.tab.c"
    break;

  case 248: /* ntf_short_connective: LPAREN PERIOD RPAREN  */
#line 716 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4379 "y.tab.c"
    break;

  case 249: /* tcf_formula: tcf_logic_formula  */
#line 719 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tcf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4385 "y.tab.c"
    break;

  case 250: /* tcf_formula: tff_atom_typing  */
#line 720 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tcf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4391 "y.tab.c"
    break;

  case 251: /* tcf_logic_formula: tcf_quantified_formula  */
#line 723 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("tcf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4397 "y.tab.c"
    break;

  case 252: /* tcf_logic_formula: cnf_formula  */
#line 724 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tcf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4403 "y.tab.c"
    break;

  case 253: /* tcf_quantified_formula: EXCLAMATION LBRKT tff_variable_list RBRKT COLON tcf_logic_formula  */
#line 727 "SyntaxBNF.y"
                                                                                           {(yyval.pval) = P_BUILD("tcf_quantified_formula", P_TOKEN("EXCLAMATION ", (yyvsp[-5].ival)), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 4409 "y.tab.c"
    break;

  case 254: /* fof_formula: fof_logic_formula  */
#line 730 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("fof_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4415 "y.tab.c"
    break;

  case 255: /* fof_formula: fof_sequent  */
#line 731 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("fof_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4421 "y.tab.c"
    break;

  case 256: /* fof_logic_formula: fof_binary_formula  */
#line 734 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("fof_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4427 "y.tab.c"
    break;

  case 257: /* fof_logic_formula: fof_unary_formula  */
#line 735 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("fof_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4433 "y.tab.c"
    break;

  case 258: /* fof_logic_formula: fof_unitary_formula  */
#line 736 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("fof_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4439 "y.tab.c"
    break;

  case 259: /* fof_binary_formula: fof_binary_nonassoc  */
#line 739 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("fof_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4445 "y.tab.c"
    break;

  case 260: /* fof_binary_formula: fof_binary_assoc  */
#line 740 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("fof_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4451 "y.tab.c"
    break;

  case 261: /* fof_binary_nonassoc: fof_unit_formula nonassoc_connective fof_unit_formula  */
#line 743 "SyntaxBNF.y"
                                                                            {(yyval.pval) = P_BUILD("fof_binary_nonassoc", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4457 "y.tab.c"
    break;

  case 262: /* fof_binary_assoc: fof_or_formula  */
#line 746 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("fof_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4463 "y.tab.c"
    break;

  case 263: /* fof_binary_assoc: fof_and_formula  */
#line 747 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("fof_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4469 "y.tab.c"
    break;

  case 264: /* fof_or_formula: fof_unit_formula VLINE fof_unit_formula  */
#line 750 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("fof_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4475 "y.tab.c"
    break;

  case 265: /* fof_or_formula: fof_or_formula VLINE fof_unit_formula  */
#line 751 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("fof_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4481 "y.tab.c"
    break;

  case 266: /* fof_and_formula: fof_unit_formula AMPERSAND fof_unit_formula  */
#line 754 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("fof_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4487 "y.tab.c"
    break;

  case 267: /* fof_and_formula: fof_and_formula AMPERSAND fof_unit_formula  */
#line 755 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("fof_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4493 "y.tab.c"
    break;

  case 268: /* fof_unary_formula: unary_connective fof_unit_formula  */
#line 758 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("fof_unary_formula", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4499 "y.tab.c"
    break;

  case 269: /* fof_unary_formula: fof_infix_unary  */
#line 759 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("fof_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4505 "y.tab.c"
    break;

  case 270: /* fof_infix_unary: fof_term infix_inequality fof_term  */
#line 762 "SyntaxBNF.y"
                                                     {(yyval.pval) = P_BUILD("fof_infix_unary", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4511 "y.tab.c"
    break;

  case 271: /* fof_unit_formula: fof_unitary_formula  */
#line 765 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("fof_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4517 "y.tab.c"
    break;

  case 272: /* fof_unit_formula: fof_unary_formula  */
#line 766 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("fof_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4523 "y.tab.c"
    break;

  case 273: /* fof_unitary_formula: fof_quantified_formula  */
#line 769 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("fof_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4529 "y.tab.c"
    break;

  case 274: /* fof_unitary_formula: fof_atomic_formula  */
#line 770 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("fof_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4535 "y.tab.c"
    break;

  case 275: /* fof_unitary_formula: LPAREN fof_logic_formula RPAREN  */
#line 771 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("fof_unitary_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4541 "y.tab.c"
    break;

  case 276: /* fof_quantified_formula: fof_quantifier LBRKT fof_variable_list RBRKT COLON fof_unit_formula  */
#line 774 "SyntaxBNF.y"
                                                                                             {(yyval.pval) = P_BUILD("fof_quantified_formula", (yyvsp[-5].pval), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 4547 "y.tab.c"
    break;

  case 277: /* fof_variable_list: variable  */
#line 777 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("fof_variable_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4553 "y.tab.c"
    break;

  case 278: /* fof_variable_list: variable COMMA fof_variable_list  */
#line 778 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("fof_variable_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4559 "y.tab.c"
    break;

  case 279: /* fof_atomic_formula: fof_plain_atomic_formula  */
#line 781 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("fof_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4565 "y.tab.c"
    break;

  case 280: /* fof_atomic_formula: fof_defined_atomic_formula  */
#line 782 "SyntaxBNF.y"
                                                 {(yyval.pval) = P_BUILD("fof_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4571 "y.tab.c"
    break;

  case 281: /* fof_atomic_formula: fof_system_atomic_formula  */
#line 783 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("fof_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4577 "y.tab.c"
    break;

  case 282: /* fof_plain_atomic_formula: fof_plain_term  */
#line 786 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("fof_plain_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4583 "y.tab.c"
    break;

  case 283: /* fof_defined_atomic_formula: fof_defined_plain_formula  */
#line 789 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("fof_defined_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4589 "y.tab.c"
    break;

  case 284: /* fof_defined_atomic_formula: fof_defined_infix_formula  */
#line 790 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("fof_defined_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4595 "y.tab.c"
    break;

  case 285: /* fof_defined_plain_formula: fof_defined_plain_term  */
#line 793 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("fof_defined_plain_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4601 "y.tab.c"
    break;

  case 286: /* fof_defined_infix_formula: fof_term defined_infix_pred fof_term  */
#line 796 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("fof_defined_infix_formula", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4607 "y.tab.c"
    break;

  case 287: /* fof_system_atomic_formula: fof_system_term  */
#line 799 "SyntaxBNF.y"
                                            {(yyval.pval) = P_BUILD("fof_system_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4613 "y.tab.c"
    break;

  case 288: /* fof_plain_term: constant  */
#line 802 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("fof_plain_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4619 "y.tab.c"
    break;

  case 289: /* fof_plain_term: functor LPAREN fof_arguments RPAREN  */
#line 803 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("fof_plain_term", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4625 "y.tab.c"
    break;

  case 290: /* fof_defined_term: defined_term  */
#line 806 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("fof_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4631 "y.tab.c"
    break;

  case 291: /* fof_defined_term: fof_defined_atomic_term  */
#line 807 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("fof_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4637 "y.tab.c"
    break;

  case 292: /* fof_defined_atomic_term: fof_defined_plain_term  */
#line 810 "SyntaxBNF.y"
                                                 {(yyval.pval) = P_BUILD("fof_defined_atomic_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4643 "y.tab.c"
    break;

  case 293: /* fof_defined_plain_term: defined_constant  */
#line 813 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("fof_defined_plain_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4649 "y.tab.c"
    break;

  case 294: /* fof_defined_plain_term: defined_functor LPAREN fof_arguments RPAREN  */
#line 814 "SyntaxBNF.y"
                                                                  {(yyval.pval) = P_BUILD("fof_defined_plain_term", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4655 "y.tab.c"
    break;

  case 295: /* fof_system_term: system_constant  */
#line 817 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("fof_system_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4661 "y.tab.c"
    break;

  case 296: /* fof_system_term: system_functor LPAREN fof_arguments RPAREN  */
#line 818 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("fof_system_term", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4667 "y.tab.c"
    break;

  case 297: /* fof_arguments: fof_term  */
#line 821 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("fof_arguments", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4673 "y.tab.c"
    break;

  case 298: /* fof_arguments: fof_term COMMA fof_arguments  */
#line 822 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("fof_arguments", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4679 "y.tab.c"
    break;

  case 299: /* fof_term: fof_function_term  */
#line 825 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("fof_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4685 "y.tab.c"
    break;

  case 300: /* fof_term: variable  */
#line 826 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("fof_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4691 "y.tab.c"
    break;

  case 301: /* fof_function_term: fof_plain_term  */
#line 829 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("fof_function_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4697 "y.tab.c"
    break;

  case 302: /* fof_function_term: fof_defined_term  */
#line 830 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("fof_function_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4703 "y.tab.c"
    break;

  case 303: /* fof_function_term: fof_system_term  */
#line 831 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("fof_function_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4709 "y.tab.c"
    break;

  case 304: /* fof_sequent: fof_formula_tuple gentzen_arrow fof_formula_tuple  */
#line 834 "SyntaxBNF.y"
                                                                {(yyval.pval) = P_BUILD("fof_sequent", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4715 "y.tab.c"
    break;

  case 305: /* fof_sequent: LPAREN fof_sequent RPAREN  */
#line 835 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("fof_sequent", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4721 "y.tab.c"
    break;

  case 306: /* fof_formula_tuple: LBRKT RBRKT  */
#line 838 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("fof_formula_tuple", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4727 "y.tab.c"
    break;

  case 307: /* fof_formula_tuple: LBRKT fof_formula_tuple_list RBRKT  */
#line 839 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("fof_formula_tuple", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4733 "y.tab.c"
    break;

  case 308: /* fof_formula_tuple_list: fof_logic_formula  */
#line 842 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("fof_formula_tuple_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4739 "y.tab.c"
    break;

  case 309: /* fof_formula_tuple_list: fof_logic_formula COMMA fof_formula_tuple_list  */
#line 843 "SyntaxBNF.y"
                                                                     {(yyval.pval) = P_BUILD("fof_formula_tuple_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4745 "y.tab.c"
    break;

  case 310: /* cnf_formula: cnf_disjunction  */
#line 846 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("cnf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4751 "y.tab.c"
    break;

  case 311: /* cnf_formula: LPAREN cnf_formula RPAREN  */
#line 847 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("cnf_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4757 "y.tab.c"
    break;

  case 312: /* cnf_disjunction: cnf_literal  */
#line 850 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("cnf_disjunction", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4763 "y.tab.c"
    break;

  case 313: /* cnf_disjunction: cnf_disjunction VLINE cnf_literal  */
#line 851 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("cnf_disjunction", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4769 "y.tab.c"
    break;

  case 314: /* cnf_literal: fof_atomic_formula  */
#line 854 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("cnf_literal", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4775 "y.tab.c"
    break;

  case 315: /* cnf_literal: TILDE fof_atomic_formula  */
#line 855 "SyntaxBNF.y"
                                               {(yyval.pval) = P_BUILD("cnf_literal", P_TOKEN("TILDE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4781 "y.tab.c"
    break;

  case 316: /* cnf_literal: TILDE LPAREN fof_atomic_formula RPAREN  */
#line 856 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("cnf_literal", P_TOKEN("TILDE ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4787 "y.tab.c"
    break;

  case 317: /* cnf_literal: fof_infix_unary  */
#line 857 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("cnf_literal", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4793 "y.tab.c"
    break;

  case 318: /* thf_quantifier: tff_quantifier  */
#line 860 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4799 "y.tab.c"
    break;

  case 319: /* thf_quantifier: th0_quantifier  */
#line 861 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4805 "y.tab.c"
    break;

  case 320: /* thf_quantifier: th1_quantifier  */
#line 862 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4811 "y.tab.c"
    break;

  case 321: /* thf_unary_connective: unary_connective  */
#line 865 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4817 "y.tab.c"
    break;

  case 322: /* thf_unary_connective: ntf_short_connective  */
#line 866 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("thf_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4823 "y.tab.c"
    break;

  case 323: /* th1_quantifier: EXCLAMATION_GREATER  */
#line 869 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("th1_quantifier", P_TOKEN("EXCLAMATION_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4829 "y.tab.c"
    break;

  case 324: /* th1_quantifier: QUESTION_STAR  */
#line 870 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("th1_quantifier", P_TOKEN("QUESTION_STAR ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4835 "y.tab.c"
    break;

  case 325: /* th0_quantifier: CARET  */
#line 873 "SyntaxBNF.y"
                       {(yyval.pval) = P_BUILD("th0_quantifier", P_TOKEN("CARET ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4841 "y.tab.c"
    break;

  case 326: /* th0_quantifier: AT_SIGN_PLUS  */
#line 874 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("th0_quantifier", P_TOKEN("AT_SIGN_PLUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4847 "y.tab.c"
    break;

  case 327: /* th0_quantifier: AT_SIGN_MINUS  */
#line 875 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("th0_quantifier", P_TOKEN("AT_SIGN_MINUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4853 "y.tab.c"
    break;

  case 328: /* subtype_sign: LESS_LESS  */
#line 878 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("subtype_sign", P_TOKEN("LESS_LESS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4859 "y.tab.c"
    break;

  case 329: /* tff_unary_connective: unary_connective  */
#line 881 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4865 "y.tab.c"
    break;

  case 330: /* tff_unary_connective: ntf_short_connective  */
#line 882 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("tff_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4871 "y.tab.c"
    break;

  case 331: /* tff_quantifier: fof_quantifier  */
#line 885 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4877 "y.tab.c"
    break;

  case 332: /* tff_quantifier: hash  */
#line 886 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("tff_quantifier", P_TOKEN("hash ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4883 "y.tab.c"
    break;

  case 333: /* fof_quantifier: EXCLAMATION  */
#line 889 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("fof_quantifier", P_TOKEN("EXCLAMATION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4889 "y.tab.c"
    break;

  case 334: /* fof_quantifier: QUESTION  */
#line 890 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("fof_quantifier", P_TOKEN("QUESTION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4895 "y.tab.c"
    break;

  case 335: /* nonassoc_connective: LESS_EQUALS_GREATER  */
#line 893 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("LESS_EQUALS_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4901 "y.tab.c"
    break;

  case 336: /* nonassoc_connective: EQUALS_GREATER  */
#line 894 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("EQUALS_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4907 "y.tab.c"
    break;

  case 337: /* nonassoc_connective: LESS_EQUALS  */
#line 895 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("LESS_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4913 "y.tab.c"
    break;

  case 338: /* nonassoc_connective: LESS_TILDE_GREATER  */
#line 896 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("LESS_TILDE_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4919 "y.tab.c"
    break;

  case 339: /* nonassoc_connective: TILDE_VLINE  */
#line 897 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("TILDE_VLINE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4925 "y.tab.c"
    break;

  case 340: /* nonassoc_connective: TILDE_AMPERSAND  */
#line 898 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("TILDE_AMPERSAND ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4931 "y.tab.c"
    break;

  case 341: /* assoc_connective: VLINE  */
#line 901 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("assoc_connective", P_TOKEN("VLINE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4937 "y.tab.c"
    break;

  case 342: /* assoc_connective: AMPERSAND  */
#line 902 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("assoc_connective", P_TOKEN("AMPERSAND ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4943 "y.tab.c"
    break;

  case 343: /* unary_connective: TILDE  */
#line 905 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("unary_connective", P_TOKEN("TILDE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4949 "y.tab.c"
    break;

  case 344: /* gentzen_arrow: MINUS_MINUS_GREATER  */
#line 908 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("gentzen_arrow", P_TOKEN("MINUS_MINUS_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4955 "y.tab.c"
    break;

  case 345: /* assignment: COLON_EQUALS  */
#line 911 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("assignment", P_TOKEN("COLON_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4961 "y.tab.c"
    break;

  case 346: /* identical: EQUALS_EQUALS  */
#line 914 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("identical", P_TOKEN("EQUALS_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4967 "y.tab.c"
    break;

  case 347: /* type_constant: type_functor  */
#line 917 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("type_constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4973 "y.tab.c"
    break;

  case 348: /* type_functor: atomic_word  */
#line 920 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("type_functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4979 "y.tab.c"
    break;

  case 349: /* defined_type: atomic_defined_word  */
#line 923 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("defined_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4985 "y.tab.c"
    break;

  case 350: /* atom: untyped_atom  */
#line 926 "SyntaxBNF.y"
                    {(yyval.pval) = P_BUILD("atom", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4991 "y.tab.c"
    break;

  case 351: /* atom: defined_constant  */
#line 927 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("atom", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4997 "y.tab.c"
    break;

  case 352: /* untyped_atom: constant  */
#line 930 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("untyped_atom", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5003 "y.tab.c"
    break;

  case 353: /* untyped_atom: system_constant  */
#line 931 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("untyped_atom", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5009 "y.tab.c"
    break;

  case 354: /* defined_infix_pred: infix_equality  */
#line 934 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("defined_infix_pred", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5015 "y.tab.c"
    break;

  case 355: /* infix_equality: EQUALS  */
#line 937 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("infix_equality", P_TOKEN("EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5021 "y.tab.c"
    break;

  case 356: /* infix_inequality: EXCLAMATION_EQUALS  */
#line 940 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("infix_inequality", P_TOKEN("EXCLAMATION_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5027 "y.tab.c"
    break;

  case 357: /* constant: functor  */
#line 943 "SyntaxBNF.y"
                   {(yyval.pval) = P_BUILD("constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5033 "y.tab.c"
    break;

  case 358: /* functor: atomic_word  */
#line 946 "SyntaxBNF.y"
                      {(yyval.pval) = P_BUILD("functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5039 "y.tab.c"
    break;

  case 359: /* defined_constant: defined_functor  */
#line 949 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("defined_constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5045 "y.tab.c"
    break;

  case 360: /* defined_functor: atomic_defined_word  */
#line 952 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("defined_functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5051 "y.tab.c"
    break;

  case 361: /* system_constant: system_functor  */
#line 955 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("system_constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5057 "y.tab.c"
    break;

  case 362: /* system_functor: atomic_system_word  */
#line 958 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("system_functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5063 "y.tab.c"
    break;

  case 363: /* def_or_sys_constant: defined_constant  */
#line 961 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("def_or_sys_constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5069 "y.tab.c"
    break;

  case 364: /* def_or_sys_constant: system_constant  */
#line 962 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("def_or_sys_constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5075 "y.tab.c"
    break;

  case 365: /* th1_defined_term: EXCLAMATION_EXCLAMATION  */
#line 965 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("EXCLAMATION_EXCLAMATION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5081 "y.tab.c"
    break;

  case 366: /* th1_defined_term: QUESTION_QUESTION  */
#line 966 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("QUESTION_QUESTION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5087 "y.tab.c"
    break;

  case 367: /* th1_defined_term: AT_AT_SIGN_PLUS  */
#line 967 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("AT_AT_SIGN_PLUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5093 "y.tab.c"
    break;

  case 368: /* th1_defined_term: AT_AT_SIGN_MINUS  */
#line 968 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("AT_AT_SIGN_MINUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5099 "y.tab.c"
    break;

  case 369: /* th1_defined_term: AT_SIGN_EQUALS  */
#line 969 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("AT_SIGN_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5105 "y.tab.c"
    break;

  case 370: /* defined_term: number  */
#line 972 "SyntaxBNF.y"
                      {(yyval.pval) = P_BUILD("defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5111 "y.tab.c"
    break;

  case 371: /* defined_term: distinct_object  */
#line 973 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("defined_term", P_TOKEN("distinct_object ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5117 "y.tab.c"
    break;

  case 372: /* variable: upper_word  */
#line 976 "SyntaxBNF.y"
                      {(yyval.pval) = P_BUILD("variable", P_TOKEN("upper_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5123 "y.tab.c"
    break;

  case 373: /* source: dag_source  */
#line 979 "SyntaxBNF.y"
                    {(yyval.pval) = P_BUILD("source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5129 "y.tab.c"
    break;

  case 374: /* source: internal_source  */
#line 980 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5135 "y.tab.c"
    break;

  case 375: /* source: external_source  */
#line 981 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5141 "y.tab.c"
    break;

  case 376: /* source: _LIT_unknown  */
#line 982 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("source", P_TOKEN("_LIT_unknown ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5147 "y.tab.c"
    break;

  case 377: /* source: LBRKT sources RBRKT  */
#line 983 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("source", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5153 "y.tab.c"
    break;

  case 378: /* sources: source  */
#line 986 "SyntaxBNF.y"
                 {(yyval.pval) = P_BUILD("sources", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5159 "y.tab.c"
    break;

  case 379: /* sources: source COMMA sources  */
#line 987 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("sources", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5165 "y.tab.c"
    break;

  case 380: /* dag_source: name  */
#line 990 "SyntaxBNF.y"
                  {(yyval.pval) = P_BUILD("dag_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5171 "y.tab.c"
    break;

  case 381: /* dag_source: inference_record  */
#line 991 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("dag_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5177 "y.tab.c"
    break;

  case 382: /* inference_record: _LIT_inference LPAREN inference_rule COMMA useful_info COMMA parents RPAREN  */
#line 994 "SyntaxBNF.y"
                                                                                               {(yyval.pval) = P_BUILD("inference_record", P_TOKEN("_LIT_inference ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 5183 "y.tab.c"
    break;

  case 383: /* inference_rule: atomic_word  */
#line 997 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("inference_rule", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5189 "y.tab.c"
    break;

  case 384: /* internal_source: _LIT_introduced LPAREN intro_type COMMA useful_info COMMA parents RPAREN  */
#line 1000 "SyntaxBNF.y"
                                                                                           {(yyval.pval) = P_BUILD("internal_source", P_TOKEN("_LIT_introduced ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 5195 "y.tab.c"
    break;

  case 385: /* intro_type: atomic_word  */
#line 1003 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("intro_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5201 "y.tab.c"
    break;

  case 386: /* external_source: file_source  */
#line 1006 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("external_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5207 "y.tab.c"
    break;

  case 387: /* external_source: theory  */
#line 1007 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("external_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5213 "y.tab.c"
    break;

  case 388: /* external_source: creator_source  */
#line 1008 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("external_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5219 "y.tab.c"
    break;

  case 389: /* file_source: _LIT_file LPAREN file_name file_info RPAREN  */
#line 1011 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("file_source", P_TOKEN("_LIT_file ", (yyvsp[-4].ival)), P_TOKEN("LPAREN ", (yyvsp[-3].ival)), (yyvsp[-2].pval), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL);}
#line 5225 "y.tab.c"
    break;

  case 390: /* file_info: COMMA name  */
#line 1014 "SyntaxBNF.y"
                       {(yyval.pval) = P_BUILD("file_info", P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5231 "y.tab.c"
    break;

  case 391: /* file_info: nothing  */
#line 1015 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("file_info", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5237 "y.tab.c"
    break;

  case 392: /* theory: _LIT_theory LPAREN theory_name optional_info RPAREN  */
#line 1018 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("theory", P_TOKEN("_LIT_theory ", (yyvsp[-4].ival)), P_TOKEN("LPAREN ", (yyvsp[-3].ival)), (yyvsp[-2].pval), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL);}
#line 5243 "y.tab.c"
    break;

  case 393: /* theory_name: atomic_word  */
#line 1021 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("theory_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5249 "y.tab.c"
    break;

  case 394: /* creator_source: _LIT_creator LPAREN creator_name COMMA useful_info COMMA parents RPAREN  */
#line 1024 "SyntaxBNF.y"
                                                                                         {(yyval.pval) = P_BUILD("creator_source", P_TOKEN("_LIT_creator ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 5255 "y.tab.c"
    break;

  case 395: /* creator_name: atomic_word  */
#line 1027 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("creator_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5261 "y.tab.c"
    break;

  case 396: /* parents: LBRKT RBRKT  */
#line 1030 "SyntaxBNF.y"
                      {(yyval.pval) = P_BUILD("parents", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5267 "y.tab.c"
    break;

  case 397: /* parents: LBRKT parent_list RBRKT  */
#line 1031 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("parents", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5273 "y.tab.c"
    break;

  case 398: /* parent_list: parent_info  */
#line 1034 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("parent_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5279 "y.tab.c"
    break;

  case 399: /* parent_list: parent_info COMMA parent_list  */
#line 1035 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("parent_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5285 "y.tab.c"
    break;

  case 400: /* parent_info: source parent_details  */
#line 1038 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("parent_info", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5291 "y.tab.c"
    break;

  case 401: /* parent_details: COLON general_list  */
#line 1041 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("parent_details", P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5297 "y.tab.c"
    break;

  case 402: /* parent_details: nothing  */
#line 1042 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("parent_details", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5303 "y.tab.c"
    break;

  case 403: /* optional_info: COMMA useful_info  */
#line 1045 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("optional_info", P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5309 "y.tab.c"
    break;

  case 404: /* optional_info: nothing  */
#line 1046 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("optional_info", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5315 "y.tab.c"
    break;

  case 405: /* useful_info: general_list  */
#line 1049 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("useful_info", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5321 "y.tab.c"
    break;

  case 406: /* include: _LIT_include LPAREN file_name include_optionals RPAREN PERIOD  */
#line 1052 "SyntaxBNF.y"
                                                                        {(yyval.pval) = P_BUILD("include", P_TOKEN("_LIT_include ", (yyvsp[-5].ival)), P_TOKEN("LPAREN ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL);}
#line 5327 "y.tab.c"
    break;

  case 407: /* include_optionals: nothing  */
#line 1055 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("include_optionals", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5333 "y.tab.c"
    break;

  case 408: /* include_optionals: COMMA formula_selection  */
#line 1056 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("include_optionals", P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5339 "y.tab.c"
    break;

  case 409: /* include_optionals: COMMA formula_selection COMMA space_name  */
#line 1057 "SyntaxBNF.y"
                                                               {(yyval.pval) = P_BUILD("include_optionals", P_TOKEN("COMMA ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5345 "y.tab.c"
    break;

  case 410: /* formula_selection: LBRKT name_list RBRKT  */
#line 1060 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("formula_selection", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5351 "y.tab.c"
    break;

  case 411: /* formula_selection: STAR  */
#line 1061 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("formula_selection", P_TOKEN("STAR ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5357 "y.tab.c"
    break;

  case 412: /* name_list: name  */
#line 1064 "SyntaxBNF.y"
                 {(yyval.pval) = P_BUILD("name_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5363 "y.tab.c"
    break;

  case 413: /* name_list: name COMMA name_list  */
#line 1065 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("name_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5369 "y.tab.c"
    break;

  case 414: /* space_name: name  */
#line 1068 "SyntaxBNF.y"
                  {(yyval.pval) = P_BUILD("space_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5375 "y.tab.c"
    break;

  case 415: /* general_term: general_data  */
#line 1071 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("general_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5381 "y.tab.c"
    break;

  case 416: /* general_term: general_data COLON general_term  */
#line 1072 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("general_term", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5387 "y.tab.c"
    break;

  case 417: /* general_term: general_list  */
#line 1073 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("general_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5393 "y.tab.c"
    break;

  case 418: /* general_data: atomic_word  */
#line 1076 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5399 "y.tab.c"
    break;

  case 419: /* general_data: general_function  */
#line 1077 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5405 "y.tab.c"
    break;

  case 420: /* general_data: variable  */
#line 1078 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5411 "y.tab.c"
    break;

  case 421: /* general_data: number  */
#line 1079 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5417 "y.tab.c"
    break;

  case 422: /* general_data: distinct_object  */
#line 1080 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("general_data", P_TOKEN("distinct_object ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5423 "y.tab.c"
    break;

  case 423: /* general_data: formula_data  */
#line 1081 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5429 "y.tab.c"
    break;

  case 424: /* general_function: atomic_word LPAREN general_terms RPAREN  */
#line 1084 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("general_function", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5435 "y.tab.c"
    break;

  case 425: /* formula_data: _DLR_thf LPAREN thf_formula RPAREN  */
#line 1087 "SyntaxBNF.y"
                                                  {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_thf ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5441 "y.tab.c"
    break;

  case 426: /* formula_data: _DLR_tff LPAREN tff_formula RPAREN  */
#line 1088 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_tff ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5447 "y.tab.c"
    break;

  case 427: /* formula_data: _DLR_fof LPAREN fof_formula RPAREN  */
#line 1089 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_fof ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5453 "y.tab.c"
    break;

  case 428: /* formula_data: _DLR_cnf LPAREN cnf_formula RPAREN  */
#line 1090 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_cnf ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5459 "y.tab.c"
    break;

  case 429: /* formula_data: _DLR_fot LPAREN fof_term RPAREN  */
#line 1091 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_fot ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5465 "y.tab.c"
    break;

  case 430: /* general_list: LBRKT RBRKT  */
#line 1094 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("general_list", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5471 "y.tab.c"
    break;

  case 431: /* general_list: LBRKT general_terms RBRKT  */
#line 1095 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("general_list", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5477 "y.tab.c"
    break;

  case 432: /* general_terms: general_term  */
#line 1098 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("general_terms", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5483 "y.tab.c"
    break;

  case 433: /* general_terms: general_term COMMA general_terms  */
#line 1099 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("general_terms", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5489 "y.tab.c"
    break;

  case 434: /* name: atomic_word  */
#line 1102 "SyntaxBNF.y"
                   {(yyval.pval) = P_BUILD("name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5495 "y.tab.c"
    break;

  case 435: /* name: integer  */
#line 1103 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("name", P_TOKEN("integer ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5501 "y.tab.c"
    break;

  case 436: /* atomic_word: lower_word  */
#line 1106 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("atomic_word", P_TOKEN("lower_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5507 "y.tab.c"
    break;

  case 437: /* atomic_word: single_quoted  */
#line 1107 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("atomic_word", P_TOKEN("single_quoted ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5513 "y.tab.c"
    break;

  case 438: /* atomic_defined_word: dollar_word  */
#line 1110 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("atomic_defined_word", P_TOKEN("dollar_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5519 "y.tab.c"
    break;

  case 439: /* atomic_system_word: dollar_dollar_word  */
#line 1113 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("atomic_system_word", P_TOKEN("dollar_dollar_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5525 "y.tab.c"
    break;

  case 440: /* number: integer  */
#line 1116 "SyntaxBNF.y"
                 {(yyval.pval) = P_BUILD("number", P_TOKEN("integer ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5531 "y.tab.c"
    break;

  case 441: /* number: rational  */
#line 1117 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("number", P_TOKEN("rational ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5537 "y.tab.c"
    break;

  case 442: /* number: real  */
#line 1118 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("number", P_TOKEN("real ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5543 "y.tab.c"
    break;

  case 443: /* file_name: atomic_word  */
#line 1121 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("file_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5549 "y.tab.c"
    break;

  case 444: /* nothing: %empty  */
#line 1124 "SyntaxBNF.y"
          {(yyval.pval) = P_BUILD("nothing",NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5555 "y.tab.c"
    break;


#line 5559 "y.tab.c"

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

