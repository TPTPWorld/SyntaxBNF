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
#define YYLAST   3668

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
     882,   885,   888,   889,   890,   893,   894,   895,   896,   897,
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
    -582,   507,  -582,  -582,    54,    63,    65,    86,    92,   136,
     151,  -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,
     254,   254,   162,   254,   254,   254,   254,  -582,  -582,  -582,
     204,  -582,   227,  -582,   232,   240,   250,   287,   319,   122,
     122,   105,   302,  -582,   122,   122,   122,   122,   315,   338,
     341,   254,  -582,   356,   316,   366,   374,   411,   413,  2033,
    1470,  1407,   415,   443,   254,  -582,   636,  3540,  3238,  1407,
    1080,   431,   436,   442,   452,   459,  -582,  -582,  -582,  -582,
    -582,  -582,  -582,   476,  -582,  -582,  -582,   471,  -582,  1470,
    1807,  -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,
    -582,   291,  -582,  -582,   381,   403,   409,  -582,   498,   486,
    -582,  -582,   512,  -582,   521,  -582,   523,  -582,  -582,  -582,
    -582,  -582,  -582,  -582,  1750,  1407,  -582,  -582,  -582,   498,
    -582,  -582,  -582,  -582,   510,   530,   219,  -582,  1624,   271,
    -582,  -582,  -582,   525,   545,  1604,  -582,   254,  -582,  -582,
     546,  1686,  -582,   498,  -582,  -582,  -582,   558,   559,   560,
     113,   772,  1667,   529,   542,   498,  -582,  -582,  -582,  -582,
     541,   581,  1932,   425,  -582,  -582,   438,  -582,  -582,   284,
    -582,  -582,  -582,   446,  -582,  -582,  -582,   409,   525,  -582,
    -582,  -582,  -582,   579,  -582,  1877,   566,  -582,  -582,    90,
     139,   562,  -582,   563,   168,   564,  -582,   485,  -582,  -582,
    -582,  -582,  -582,  -582,  -582,  -582,   113,  2822,  3015,  -582,
    -582,   565,   498,  -582,  -582,  -582,  -582,   568,   596,   595,
    1441,   599,  -582,  3308,   259,  -582,  -582,   396,  -582,  -582,
    -582,   395,  -582,  -582,   409,   525,  -582,  -582,   128,  -582,
    -582,   567,   549,  -582,  -582,  -582,  -582,  -582,   588,  3378,
    -582,  -582,  -582,  -582,   177,   139,   592,  -582,   597,   168,
     598,  -582,  -582,   487,   498,  -582,  -582,   613,   593,  1470,
    1407,  2099,  3540,  3238,  2033,  2033,   591,  2099,  -582,   615,
    -582,  -582,  2099,  -582,  2099,  2100,   594,  -582,  1966,  2099,
    2099,  2099,  1604,  -582,   618,   602,   606,   607,   609,  1604,
    1604,  1604,  -582,  -582,  -582,  -582,  -582,  -582,  1604,  1604,
    -582,   627,   578,  -582,  -582,  -582,  -582,   578,   621,   622,
     580,   625,   117,  -582,  -582,  -582,  -582,  -582,  1947,   620,
    -582,  -582,   652,   108,   631,  -582,  -582,   492,   633,   634,
     333,   611,   637,  3592,  3592,  3592,  3592,  3592,  -582,  3592,
    1533,  1533,   645,   649,   650,  1947,  -582,  -582,  -582,  -582,
    -582,   578,  -582,   298,  3592,  3592,  3592,   121,  3098,  -582,
     666,   648,  -582,  -582,  -582,  -582,   654,   659,   667,  3378,
    -582,  -582,   694,  -582,  -582,   453,   675,  3308,  3308,  3308,
    3308,  3308,  3308,  3308,  -582,  -582,  -582,   500,  -582,  -582,
    3308,  1069,  1069,   691,  3518,  3518,  3518,  3518,  3518,   578,
    3098,  -582,  -582,  -582,  -582,  -582,  3308,   298,  3308,  3308,
    3308,   679,  2033,  -582,   680,   682,  -582,  -582,  -582,   684,
     686,   688,  -582,   689,  -582,   692,  -582,  -582,  2100,   700,
     702,   703,   704,   708,  -582,   723,  -582,  -582,  -582,  -582,
    -582,  -582,  -582,  -582,   712,  -582,   709,   725,   710,   711,
    1604,  -582,  -582,  -582,   714,  -582,  -582,  -582,  -582,  -582,
    -582,   713,   737,   719,   743,  -582,   738,  -582,   727,   739,
     580,   580,  -582,  -582,  -582,   701,   715,  -582,  -582,  -582,
     742,  -582,  -582,  -582,  -582,  -582,   432,  -582,  -582,  3592,
    -582,  -582,   505,    61,    61,   751,  -582,  -582,  -582,  -582,
    -582,   740,  -582,  -582,  -582,   506,  -582,  -582,  -582,  -582,
    -582,  -582,  -582,   147,  2252,  3592,  -582,  -582,  -582,  -582,
    -582,  3592,   735,   750,  -582,  -582,  -582,   752,   756,   759,
    1390,  -582,  3308,  -582,   520,  -582,  -582,   217,   217,   761,
    -582,   745,  -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,
     147,  2940,  3168,  -582,  -582,  -582,  -582,  -582,  3168,  -582,
    -582,   717,  -582,  -582,  -582,  -582,   763,   773,   800,   779,
     595,   810,   815,  -582,   717,  -582,  -582,  -582,   786,  -582,
     787,   788,   795,  -582,  -582,  -582,  -582,  -582,  -582,  -582,
    -582,   813,   792,   162,   162,   162,   162,   162,   807,  -582,
    -582,  -582,  -582,  2099,  -582,  -582,  -582,  -582,   819,   578,
     820,   578,   736,  -582,   578,   832,   797,   811,    30,   821,
     144,   736,   736,  1533,   831,  -582,   824,   843,  -582,  -582,
    -582,   826,   849,    98,  -582,   827,   829,  -582,   858,  -582,
    -582,  -582,  1291,   831,  -582,   839,   863,  -582,  -582,  -582,
     842,   865,  3448,  -582,   844,   873,   578,  3308,  -582,  -582,
    -582,  -582,  -582,  2100,  -582,   872,  -582,   874,   876,  -582,
     879,  -582,   723,  -582,  -582,  -582,  -582,  1604,  -582,   841,
    -582,   736,  -582,   851,   580,  -582,  -582,   736,  -582,  -582,
     736,  -582,   882,   860,  -582,   864,   432,  -582,    61,  2252,
    -582,   884,  -582,   887,  -582,  -582,  -582,  3592,   870,   878,
    -582,   881,  1390,  -582,   217,  2822,   887,   893,  -582,  -582,
    -582,  -582,  -582,  -582,   807,   254,   880,  -582,   807,   807,
     883,  -582,  -582,   821,   907,  -582,  -582,  -582,   736,  -582,
    -582,  -582,  -582,   908,   922,   886,   535,  3592,  -582,  3592,
    -582,  -582,  -582,  -582,   344,   923,   904,  3308,  3308,   927,
    -582,  -582,   928,   930,  -582,   733,  -582,    99,  -582,   913,
    -582,  3308,  -582,  -582,   914,   929,   929,   929,   866,  -582,
    -582,  -582,  -582,  -582,  -582,  -582,  1163,   918,   919,   920,
     866,   924,  -582,   933,   931,   950,  -582,  -582,  -582,   932,
    -582,   807,  -582,  -582,  -582,  2100,  -582,  -582
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
    -582,   194,   534,   681,    42,  -582,  -582,  -582,  -582,  -582,
    -380,   -84,  -582,   967,  -582,  -582,   289,  -582,    44,  -185,
    -582,   608,  -582,  -582,  -582,    91,  -582,  -582,  -582,   234,
    -582,   299,   179,   -30,  -582,     5,  -582,   -32,  -326,  -190,
     300,  -258,  -582,  -582,  -367,  -582,  -582,  -582,  -493,  -582,
     697,   -57,  -582,  -582,  -582,  -582,  -582,  -291,  -582,  -106,
    -582,  -582,  -348,  -582,  -582,  -278,   785,  -582,  -141,  -581,
    -582,  -582,  -260,  -582,  -582,  -582,   267,  -582,   334,  -582,
     199,  -582,  -330,  -322,   175,  -268,   -47,   658,   499,   211,
    -582,  -466,   282,   244,   200,  -582,  -582,   308,  -582,  -437,
    -582,  -582,   272,  -582,  -582,  -582,   297,  -582,  -582,  -192,
    -480,   619,  -582,   304,  -582,   -11,   -38,  -582,  -582,  -582,
    -582,  -582,  -136,   -52,  -124,  -110,  -582,   385,    -5,  -582,
    -582,  -582,  -582,  -582,  -183,  -582,  -582,  -169,  -147,  -270,
     -63,  -582,   890,   706,   548,    11,  -582,   730,  -582,  -150,
    -582,  -582,   757,  -582,  -582,  2224,   -58,  -582,  2429,   -61,
     306,  -215,  -582,  -582,  -582,   603,   -15,  -161,   -46,    34,
     572,   892,  1772,  2052,  1212,  1492,  -582,  -582,  2331,   -26,
    -284,   348,  -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,
    -582,  -582,  -582,  -582,  -312,   207,  -582,  -582,   343,  -408,
    -582,  -582,  -582,   889,  -582,    -9,  -582,  -582,  -582,  -457,
    -236,    -8,   -19,   359,  -582,   -23,   419,     0
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
     293,    95,   522,   528,   529,   530,   531,   707,   389,   645,
     668,   108,   720,   245,   423,   524,   524,   524,   524,   524,
     319,    20,   321,   411,    95,   288,   304,   306,   514,   367,
      21,   641,    22,   526,   526,   526,   526,   526,   436,    94,
     286,   330,   599,   599,   599,   349,   547,   548,   549,   436,
     223,   436,   437,    23,   357,   372,   436,   436,   436,    24,
     719,   534,  -192,   437,    92,   437,  -192,    51,    31,    28,
     437,   437,   437,    29,   438,   207,   207,   320,   763,    63,
     294,   293,    52,   331,   506,   438,    95,   438,   550,   404,
    -352,   507,   438,   438,   438,   551,   580,   581,   583,   584,
     585,   695,   286,    25,  -352,   414,    28,    28,   594,   370,
      29,    29,   403,   323,   323,   323,    92,    93,    26,  -353,
     709,   710,   323,   323,   413,   475,   476,   477,   426,   415,
      48,   273,   273,  -353,   478,   479,   603,   416,   293,   325,
     325,   325,   372,   392,   423,   560,   720,   273,   325,   325,
      92,    93,   525,   525,   525,   525,   525,    39,   439,   536,
     536,   361,   245,   245,   289,   166,   669,    94,   389,   446,
      28,   447,  -257,   425,    29,   189,   467,   467,   467,   664,
      40,   650,   188,   293,   558,    41,    94,   523,   523,   523,
     523,   523,   668,    44,  -257,  -257,   207,   273,    81,    81,
     386,    88,    88,    45,   306,    87,    87,   199,   264,   435,
     389,   -27,   -27,   656,    95,   442,    31,   406,   412,   645,
      92,   349,   445,   700,  -258,    28,   703,   695,   245,    29,
     434,   695,   695,    95,   -27,   -27,   482,   590,  -190,   358,
      46,   486,  -190,   516,   502,  -301,  -258,  -258,   542,  -301,
     596,   503,   207,   562,   563,   564,   565,   566,   567,   568,
      27,   714,    28,   308,   408,   223,    29,   207,   207,   207,
     207,   207,    47,   207,   538,   538,   779,   188,    54,   207,
     782,   783,   591,    59,   819,   486,    65,   329,   207,   207,
     207,    60,   273,   696,    61,   513,   768,   552,   545,   352,
     514,    92,    93,   425,   826,   644,    28,   671,   388,    64,
      29,   273,   273,   273,   273,   273,   273,   273,   377,    66,
     392,   574,   576,   245,   273,   575,   575,    67,   425,   425,
     425,   425,   425,   588,   273,  -292,    92,   600,   601,  -292,
     273,    28,   273,   273,   273,    29,    81,   -29,   -29,    88,
     -88,   358,   545,    87,   -88,   245,   396,  -303,   577,   594,
     386,  -303,   389,   290,    68,   245,    69,   291,   389,    31,
     -29,   -29,   304,   245,   245,   245,   770,   789,  -126,   790,
     436,   406,   406,   406,   406,   406,   406,   406,   410,   524,
     146,  -127,   569,   533,   437,   620,   147,   188,   279,  -129,
    -126,  -126,   589,   280,   502,   502,   652,   526,   431,   281,
     406,   503,   503,  -127,  -127,   557,   438,   163,   655,   282,
     558,  -129,  -129,   207,   808,   809,   283,   284,   408,   408,
     408,   408,   408,   408,   408,    92,    93,   643,   285,  -193,
      28,   -89,   536,  -193,    29,   -89,  -191,     3,   207,   207,
    -191,   295,   730,   188,   -88,   207,    92,   408,   -88,  -194,
    -190,    28,   813,  -194,  -190,    29,   273,   298,   527,   527,
     527,   527,   527,   310,   -90,   527,   527,   540,   -90,   299,
     188,   813,   392,   392,   671,   273,   273,  -183,   300,  -192,
     301,   309,   273,  -192,   320,     4,   350,   245,     5,     6,
     467,   323,     7,     8,   320,     9,    10,   322,   327,   330,
    -352,  -353,   351,   751,    50,   644,   245,   245,    55,    56,
      57,    58,   353,   245,   354,   363,   525,   325,   371,   374,
     375,   376,   395,   591,   686,    33,   689,   691,   693,   398,
     489,   399,   490,   482,   417,   486,   502,   491,   486,   397,
     419,   -26,   -26,   503,   674,   502,   502,   538,   418,   428,
     589,   523,   503,   503,   429,   430,   432,   444,   433,   290,
     464,   470,   111,   111,   -26,   -26,  -109,   471,   158,   200,
     265,   111,   472,   473,    93,   474,   273,    94,    28,   124,
     588,   273,    29,   150,    80,   508,    80,   487,   488,   505,
    -109,   111,   111,   151,    31,   509,   510,   534,  -109,   511,
     512,   652,   520,   521,    90,   502,   541,   245,   502,   552,
     339,   502,   503,   553,   502,   503,   194,   747,   503,   504,
     554,   503,   620,   207,    95,   555,   111,   111,    91,    92,
      93,   207,    77,   556,    28,   426,    78,    79,    29,   273,
     188,   561,    80,   571,   736,   602,   604,   111,   605,   392,
     606,   406,   607,   158,   608,   609,    31,   613,   610,   614,
     615,   616,   502,   345,   200,   617,   618,   780,   623,   503,
     245,   207,   621,   207,   627,   622,   624,   625,   628,   632,
     629,   273,   273,   489,   630,   490,   631,   633,   490,   502,
     798,   634,   641,   701,   653,   273,   503,   345,   408,   642,
     654,   657,   502,   639,   672,   673,  -210,   774,   415,   503,
     194,   194,   245,   245,   502,   658,   676,    31,   659,   123,
     265,   503,   660,   160,   161,   661,   245,    93,   675,   338,
      93,    28,   339,   126,    28,    29,    31,   340,    29,    80,
     127,   677,    80,   823,   194,   678,   401,   163,   527,   793,
     794,   -45,   679,   680,   681,   682,   683,   684,   724,    70,
     697,   699,   705,   736,    91,    92,    93,   128,    77,   164,
      28,   407,    78,    79,    29,   704,   358,   706,    80,   504,
     504,   111,   111,   111,   200,   265,   716,   708,   150,   111,
     715,   717,   718,   725,   111,   726,   111,   424,    89,   727,
     111,   111,   111,   111,   111,   731,   732,   733,   734,    90,
     739,   111,   111,   111,   740,   744,   754,   745,   490,   748,
     111,   111,   749,   810,   766,   758,   759,   767,   760,   768,
     331,   194,   527,    91,    92,    93,   778,    77,   348,    28,
     345,    78,    79,    29,   702,   771,   781,    80,   785,   784,
    -182,   788,   517,   711,   712,   345,   345,   345,   345,   345,
      93,   345,   345,   345,    28,   787,   791,   345,    29,   792,
     795,   796,    80,   797,   821,   517,   345,   345,   345,   803,
     805,   806,   112,   112,   816,   817,   818,   194,   112,   201,
     820,   112,   724,   825,   441,   741,   824,   517,   773,   707,
     804,   738,   194,   194,   194,   194,   194,   742,   194,   440,
     368,   112,   112,   753,   194,   762,   802,   722,   492,   756,
     637,   504,   757,   194,   194,   194,   799,   424,   811,   517,
     504,   504,   786,   752,   772,   407,   407,   407,   407,   407,
     407,   407,   755,   761,   698,   307,   112,   112,   626,   573,
     573,   427,   424,   424,   424,   424,   424,   480,   465,   769,
     597,   743,   827,   687,   407,   750,   326,   112,     0,     0,
     712,     0,   111,   112,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   201,   201,     0,     0,     0,     0,     0,
     504,     0,     0,   504,     0,     0,   504,   801,     0,   504,
       0,     0,     0,   208,   209,     0,   210,     0,   345,     0,
     639,   345,     0,     0,     0,   517,   517,   201,   214,     0,
     570,   571,   639,     0,     0,     0,   572,     0,     0,     0,
       0,   219,    70,     0,     0,     0,   345,   345,     0,     0,
       0,     0,     0,   345,   221,   276,     0,   504,     0,     0,
       0,     0,    71,    72,    73,     0,    74,    75,   194,   517,
     517,    91,    92,    93,     0,    77,     0,    28,     0,    78,
      79,    29,    76,     0,   504,    80,    77,     0,    28,     0,
      78,    79,    29,   194,   194,     0,    80,   504,   663,     0,
     194,     0,     0,     0,     0,     0,     0,     0,     0,   504,
       0,   112,   112,   112,   201,     0,     0,     0,     0,   112,
       0,     0,     0,     0,   112,   448,   112,     0,     0,     0,
     112,   112,   112,   112,   112,   111,     0,     0,   812,     0,
     405,   112,   112,   112,     0,     0,     0,     0,     0,     0,
     112,   112,   449,   450,     0,   345,   451,   452,     0,     0,
     453,     0,     0,   454,     0,   345,   422,     0,     0,    27,
     201,    28,     0,     0,     0,    29,     0,     0,     0,     0,
       0,     0,   518,     0,     0,   201,   201,   201,   201,   201,
       0,   201,   201,   201,     0,     0,     0,   201,     0,     0,
       0,     0,     0,     0,     0,   518,   201,   201,   201,   111,
       0,   111,   115,   115,     0,     0,     0,     0,   159,   204,
     269,   115,     0,     0,     0,   407,     0,   518,   345,     0,
     517,   345,     0,     0,   384,     0,     0,     0,     0,   345,
       0,   115,   115,     0,     0,   290,   517,   312,     0,   291,
       0,     0,   728,   364,   313,   314,     0,   315,   729,   518,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   127,
     316,   317,   385,     0,     0,     0,   115,   115,   194,   345,
     663,   345,     0,     0,     0,     0,   194,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   422,   115,   164,   345,
       0,     0,   112,   159,   405,   405,   405,   405,   405,   405,
     405,     0,   335,   346,   204,     0,     0,     0,     0,     0,
       0,   579,   579,   579,   579,   579,   194,     0,   194,     0,
       0,     0,     0,   592,   208,   209,     0,   210,   201,     0,
       0,   201,     0,     0,     0,   518,   518,   346,     0,   214,
       0,   570,   571,     0,     0,     0,     0,   662,     0,     0,
       0,     0,   219,     0,   123,     0,   201,   201,   335,   124,
     269,     0,     0,   201,   125,   221,     0,     0,   126,     0,
       0,     0,     0,     0,   400,   127,     0,   401,     0,   518,
     518,     0,    91,    92,    93,   643,    77,   312,    28,     0,
      78,    79,    29,     0,   313,   314,     0,   315,     0,    91,
      92,    93,   128,    77,     0,    28,     0,    78,    79,    29,
     316,   317,   402,    80,     0,     0,     0,     0,     0,     0,
       0,   115,   115,   115,   204,   269,     0,    89,     0,   115,
       0,     0,     0,     0,   115,     0,   115,     0,    90,     0,
     115,   115,   115,   115,   115,   112,     0,     0,     0,     0,
       0,   115,   115,   115,     0,     0,     0,     0,     0,     0,
     115,   115,    91,    92,    93,   201,    77,     0,    28,     0,
      78,    79,    29,     0,     0,   201,    80,     0,     0,     0,
     346,     0,   116,   116,   533,   534,     0,     0,   116,   205,
     535,   116,   519,     0,     0,   346,   346,   346,   346,   346,
       0,   346,   346,   346,     0,     0,     0,   346,   163,     0,
       0,   116,   116,     0,     0,   519,   346,   346,   346,   112,
       0,   112,     0,     0,     0,    91,    92,    93,     0,    77,
       0,    28,     0,    78,    79,    29,     0,   519,   201,    80,
     518,   201,     0,     0,     0,     0,   116,   116,     0,   201,
       0,   123,     0,     0,     0,     0,   518,   311,     0,     0,
       0,   302,     0,     0,     0,   126,     0,   116,     0,   519,
     312,     0,   127,   116,   592,     0,     0,   313,   314,     0,
     315,     0,   336,   205,   205,     0,     0,     0,     0,   201,
       0,   201,     0,   316,   317,   318,    91,    92,    93,   128,
      77,     0,    28,     0,    78,    79,    29,     0,     0,   201,
      80,     0,   115,     0,   123,     0,     0,   205,   160,   161,
       0,     0,     0,     0,   162,     0,     0,   348,   126,     0,
       0,     0,     0,     0,     0,   127,     0,     0,   336,     0,
       0,     0,   163,   151,     0,     0,     0,     0,   346,     0,
       0,   346,     0,     0,    90,   519,   519,     0,     0,    91,
      92,    93,   128,    77,   164,    28,     0,    78,    79,    29,
       0,     0,     0,    80,     0,   335,   346,   346,    91,    92,
      93,     0,    77,   346,    28,     0,    78,    79,    29,     0,
       0,     0,    80,     0,     0,     0,     0,   123,     0,   519,
     519,   116,   116,   116,   205,     0,     0,   302,     0,   116,
       0,   126,   335,     0,   116,   303,   116,     0,   127,     0,
     116,   116,   116,   116,   116,     0,     0,     0,     0,     0,
       0,   116,   116,   116,     0,     0,     0,     0,     0,     0,
     116,   116,    91,    92,    93,   128,    77,     0,    28,     0,
      78,    79,    29,     0,     0,     0,    80,     0,     0,     0,
     205,     0,   113,   113,   287,   115,     0,     0,   113,   202,
       0,   113,   336,     0,     0,   205,   205,   205,   205,   205,
       0,   205,   205,   205,     0,   346,     0,   205,     0,     0,
       0,   113,   113,     0,     0,   336,   205,   205,   205,    91,
      92,    93,     0,    77,     0,    28,     0,    78,    79,    29,
       0,     0,     0,    80,     0,     0,     0,   336,     0,     0,
       0,     0,     0,     0,   123,     0,   113,   113,   160,   364,
       0,     0,     0,     0,   365,     0,     0,     0,   126,   115,
       0,   115,     0,     0,     0,   127,     0,   113,     0,   336,
       0,     0,   163,   113,     0,     0,     0,     0,   346,     0,
     519,   346,   333,   202,   202,   355,     0,     0,     0,   346,
      92,    93,   128,     0,   164,    28,   519,     0,   312,    29,
       0,     0,     0,    80,     0,   313,   314,     0,   315,     0,
       0,     0,   116,     0,   123,     0,     0,   202,   160,   161,
       0,   316,   317,   356,   338,     0,     0,   348,   126,   346,
       0,   346,     0,     0,     0,   127,     0,     0,   333,     0,
       0,     0,   163,     0,     0,     0,     0,     0,   205,     0,
       0,   205,     0,     0,    90,   336,   336,     0,     0,    91,
      92,    93,   128,    77,   164,    28,     0,    78,    79,    29,
       0,     0,     0,    80,     0,   336,   205,   205,    91,    92,
      93,     0,    77,   205,    28,     0,    78,    79,    29,     0,
       0,     0,    80,     0,     0,     0,     0,     0,     0,   336,
     336,   113,   113,   113,   202,    70,     0,     0,     0,   113,
       0,     0,   336,     0,   113,     0,   113,     0,     0,     0,
     113,   113,   113,   113,   113,    71,    72,    73,     0,    74,
      75,   113,   113,   113,     0,     0,     0,     0,     0,     0,
     113,   113,     0,     0,     0,    76,     0,     0,     0,    77,
       0,    28,     0,    78,    79,    29,     0,     0,     0,    80,
     202,     0,   114,   114,     0,   116,     0,     0,   114,   203,
       0,   114,   448,     0,     0,   202,   202,   202,   202,   202,
       0,   202,   202,   202,     0,   205,     0,   202,     0,     0,
       0,   114,   114,     0,     0,   546,   202,   202,   202,   449,
     450,     0,     0,   451,   452,     0,     0,   453,     0,     0,
     454,    91,    92,    93,     0,    77,    27,    28,    28,    78,
      79,    29,    29,     0,     0,    80,   114,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   116,
       0,   116,     0,     0,     0,     0,     0,   114,     0,   546,
       0,     0,     0,   114,     0,     0,     0,     0,   205,     0,
     336,   205,   334,   203,   203,     0,     0,     0,     0,   205,
       0,     0,     0,     0,     0,     0,   336,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   113,     0,     0,     0,     0,   203,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   205,
       0,   205,     0,     0,     0,     0,     0,     0,   334,   123,
       0,     0,     0,   160,   161,     0,     0,     0,   202,   338,
       0,   202,     0,   126,     0,   144,     0,   340,     0,     0,
     127,   197,     0,   144,     0,     0,     0,   163,     0,     0,
       0,     0,     0,     0,     0,   333,   202,   202,     0,     0,
       0,     0,     0,   202,    91,    92,    93,   128,    77,   164,
      28,     0,    78,    79,    29,     0,     0,     0,    80,     0,
       0,   114,   114,   114,   203,     0,     0,     0,     0,   114,
       0,     0,   333,     0,   114,     0,   114,     0,   144,   144,
     114,   114,   114,   114,   114,     0,     0,     0,     0,     0,
       0,   114,   114,   114,     0,     0,     0,     0,     0,   144,
     114,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   197,   197,     0,     0,     0,
     203,   117,   117,     0,     0,   113,     0,   117,   206,     0,
     117,     0,     0,     0,     0,   203,   203,   203,   203,   203,
       0,   203,   203,   203,     0,   202,     0,   203,     0,   197,
     117,   117,     0,     0,     0,   334,   203,   203,   203,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   117,   117,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   113,
       0,   113,     0,     0,     0,     0,   117,     0,     0,   334,
       0,     0,   117,     0,     0,     0,     0,     0,   202,     0,
     145,   202,   347,   206,     0,     0,   198,     0,   145,   202,
       0,     0,     0,     0,   144,     0,   197,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   114,     0,     0,     0,   144,     0,     0,     0,
       0,     0,     0,   144,   144,   144,     0,     0,     0,   202,
       0,   202,   144,   144,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   145,   145,     0,     0,     0,   203,     0,
       0,   203,   197,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   145,     0,     0,   197,   197,   197,
     197,   197,     0,   197,     0,   334,   203,   203,     0,   197,
     198,   198,     0,   203,     0,     0,     0,     0,   197,   197,
     197,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     117,   117,   117,   206,     0,     0,     0,     0,   117,     0,
       0,     0,   334,   117,   198,   117,     0,     0,     0,   117,
     117,   117,   117,   117,     0,     0,     0,     0,     0,     0,
     117,   117,   117,     0,     0,     0,     0,     0,     0,   117,
     117,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   206,
       0,     0,     0,     0,     0,   114,     0,     0,     0,     0,
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
       0,   117,     0,   198,   198,   198,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   203,
       0,   203,     0,     0,     0,     0,   208,   209,     0,   210,
     211,   212,   213,     0,     0,     0,     0,     0,     0,   123,
     347,   214,   215,   216,   217,     0,     0,     0,     0,   378,
       0,     0,   339,   126,   219,   220,     0,   379,     0,     0,
     127,     0,     0,     0,     0,   347,   206,   221,     0,     0,
       0,     0,   347,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,   128,    77,   164,
      28,     0,    78,    79,    29,     0,     0,     0,    80,   145,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   144,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   198,     0,
       0,     0,     0,   197,   208,   209,     0,   210,   211,   212,
     213,   197,     0,     0,   117,     0,     0,   123,     0,   214,
     215,   216,   217,   198,   198,     0,     0,   378,     0,     0,
     198,   126,   219,   220,   206,   379,     0,     0,   127,     0,
       0,     0,     0,     0,     0,   221,     0,     0,     0,     0,
       0,   197,     0,   197,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,   128,    77,   164,    28,     0,
      78,    79,    29,     0,     0,     0,    80,     0,   384,   208,
     209,     0,   210,   211,   212,   213,     0,     0,   117,   290,
     117,   312,   123,   291,   214,   215,   216,   217,   313,   314,
       0,   315,   218,     0,     0,   348,   126,   219,   220,     0,
     347,     0,     0,   127,   316,   317,   385,     0,   206,     0,
     221,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
     128,    77,   164,    28,     0,    78,    79,    29,     0,     0,
       0,    80,     0,     0,     0,     0,     0,     0,   347,     0,
     347,   384,   208,   209,     0,   210,   211,   212,   213,     0,
       0,     0,   290,     0,   312,   123,   291,   214,   215,   216,
     217,   313,   314,     0,   315,   378,   145,     0,   348,   126,
     219,   220,     0,     0,     0,     0,   127,   316,   317,   385,
       0,     0,     0,   221,     0,     0,     0,     0,   198,     0,
       0,     0,     0,     0,     0,     0,   198,     0,     0,     0,
      91,    92,    93,   128,    77,   164,    28,     0,    78,    79,
      29,   384,   208,   209,    80,   210,   211,   212,   213,     0,
       0,     0,   290,     0,   312,   123,   291,   214,   215,   216,
     217,   313,   314,     0,   315,   378,   198,     0,   198,   126,
     219,   220,     0,     0,     0,     0,   127,   316,   317,   385,
       0,     0,     0,   221,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      91,    92,    93,   128,    77,   164,    28,     0,    78,    79,
      29,     0,   208,   209,    80,   210,   211,   212,   213,     0,
       0,     0,     0,     0,     0,   123,     0,   214,   215,   216,
     217,     0,     0,     0,     0,   218,     0,     0,     0,   126,
     219,   220,     0,     0,     0,     0,   127,     0,     0,     0,
       0,     0,     0,   221,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      91,    92,    93,   128,    77,   164,    28,     0,    78,    79,
      29,     0,   208,   209,    80,   210,   211,   212,   213,     0,
       0,     0,     0,     0,     0,   123,     0,   214,   215,   216,
     217,     0,     0,     0,     0,   378,     0,     0,     0,   126,
     219,   220,     0,     0,     0,     0,   127,     0,     0,     0,
       0,     0,     0,   221,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      91,    92,    93,   128,    77,   164,    28,     0,    78,    79,
      29,     0,   208,   209,    80,   210,   211,   212,   213,     0,
       0,     0,     0,     0,     0,   123,     0,   214,   215,   216,
     217,     0,     0,     0,     0,   420,     0,     0,     0,   126,
     219,   220,     0,     0,     0,     0,   127,     0,     0,     0,
       0,     0,     0,   221,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      91,    92,    93,   128,    77,   164,    28,     0,    78,    79,
      29,     0,   208,   209,    80,   210,   211,   212,   213,     0,
       0,     0,     0,     0,     0,   123,     0,   214,   215,   216,
     735,     0,     0,     0,     0,   378,     0,     0,     0,   126,
     219,   220,     0,     0,     0,     0,   127,     0,     0,     0,
       0,     0,     0,   221,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      91,    92,    93,   128,    77,   164,    28,     0,    78,    79,
      29,     0,   208,   209,    80,   210,   211,   212,   213,     0,
       0,     0,     0,     0,     0,   123,     0,   214,   215,   570,
     571,     0,     0,     0,     0,   578,     0,     0,     0,   126,
     219,   220,     0,     0,     0,     0,     0,   123,     0,     0,
       0,   160,   161,   221,     0,     0,     0,   162,     0,     0,
       0,   126,     0,     0,     0,     0,     0,     0,   127,     0,
      91,    92,    93,   128,    77,   163,    28,     0,    78,    79,
      29,     0,     0,     0,    80,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,   128,    77,   164,    28,   123,
      78,    79,    29,   160,   161,     0,    80,     0,     0,   338,
       0,     0,     0,   126,     0,     0,     0,     0,     0,     0,
     127,     0,     0,     0,     0,     0,     0,   163,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,   128,    77,   164,
      28,     0,    78,    79,    29,     0,     0,     0,    80
};

static const yytype_int16 yycheck[] =
{
       0,    20,    21,    22,    23,    24,    25,    26,    60,   145,
      67,   295,    20,    21,    66,    23,    24,    25,    26,    66,
      67,   145,   237,   371,   216,   491,   187,    90,   218,   359,
     300,   301,    51,    59,    34,   145,    59,    89,   360,   361,
      59,    67,    68,    51,    70,    64,   426,    70,   415,   285,
      59,    70,    67,    68,   195,    60,    64,   550,    69,   426,
     106,    66,   353,   354,   355,   356,   357,    37,   218,   506,
     550,    60,   653,    68,   259,   353,   354,   355,   356,   357,
     138,    27,   143,   244,    89,    90,   124,   125,    27,   195,
      27,    61,    27,   353,   354,   355,   356,   357,   281,   151,
      89,    11,   428,   429,   430,   162,   374,   375,   376,   292,
      68,   294,   281,    27,   172,    25,   299,   300,   301,    27,
      22,    22,    14,   292,    63,   294,    18,    22,   147,    68,
     299,   300,   301,    72,   281,   161,   162,    29,   719,   147,
     106,   187,    37,    30,    27,   292,   151,   294,    27,   233,
      11,    34,   299,   300,   301,    34,   414,   415,   416,   417,
     418,   618,   151,    27,    25,    37,    68,    68,   426,   195,
      72,    72,   230,   309,   310,   311,    63,    64,    27,    11,
      36,    37,   318,   319,   245,   309,   310,   311,    11,    61,
      68,   217,   218,    25,   318,   319,   432,    69,   244,   309,
     310,   311,    25,   218,   389,   395,   787,   233,   318,   319,
      63,    64,   353,   354,   355,   356,   357,    13,   281,   360,
     361,   187,   217,   218,   287,   282,   552,   279,   378,   292,
      68,   294,    13,   259,    72,   282,   299,   300,   301,   732,
      13,   509,    67,   289,    27,    13,   298,   353,   354,   355,
     356,   357,   732,    13,    35,    36,   282,   283,   284,   285,
     218,   284,   285,    13,   302,   284,   285,   282,   283,   280,
     420,    12,    13,   541,   279,   284,   295,   233,   244,   716,
      63,   338,   287,   631,    13,    68,   634,   744,   283,    72,
     279,   748,   749,   298,    35,    36,   322,   677,    14,    15,
      13,   327,    18,   350,   330,    14,    35,    36,   365,    18,
     677,   330,   338,   397,   398,   399,   400,   401,   402,   403,
      66,   643,    68,   129,   233,   283,    72,   353,   354,   355,
     356,   357,    13,   359,   360,   361,   744,   162,    36,   365,
     748,   749,   426,    28,   810,   371,    30,   153,   374,   375,
     376,    13,   378,   623,    13,    22,    12,    13,   373,   165,
      27,    63,    64,   389,   821,   506,    68,   557,   558,    13,
      72,   397,   398,   399,   400,   401,   402,   403,   570,    13,
     395,   411,   412,   378,   410,   411,   412,    13,   414,   415,
     416,   417,   418,   419,   420,    14,    63,   429,   430,    18,
     426,    68,   428,   429,   430,    72,   432,    12,    13,   432,
      14,    15,   427,   432,    18,   410,   222,    14,   413,   677,
     378,    18,   572,    14,    13,   420,    13,    18,   578,   448,
      35,    36,   470,   428,   429,   430,   727,   767,    13,   769,
     623,   397,   398,   399,   400,   401,   402,   403,   663,   727,
      35,    13,   410,    21,   623,   455,    13,   282,    27,    13,
      35,    36,   420,    27,   490,   491,   513,   727,   274,    27,
     426,   490,   491,    35,    36,    22,   623,    45,   535,    27,
      27,    35,    36,   509,   796,   797,    27,    11,   397,   398,
     399,   400,   401,   402,   403,    63,    64,    65,    27,    14,
      68,    14,   643,    18,    72,    18,    14,     0,   534,   535,
      18,    13,   662,   338,    14,   541,    63,   426,    18,    14,
      14,    68,   806,    18,    18,    72,   552,    41,   353,   354,
     355,   356,   357,     3,    14,   360,   361,   362,    18,    27,
     365,   825,   557,   558,   734,   571,   572,    12,    27,    14,
      27,    41,   578,    18,    29,    48,    27,   552,    51,    52,
     623,   697,    55,    56,    29,    58,    59,    22,    22,    11,
      11,    11,    30,   697,    40,   716,   571,   572,    44,    45,
      46,    47,    41,   578,     3,     6,   727,   697,    22,    27,
      27,    27,    27,   677,   613,   614,   615,   616,   617,     3,
      20,     6,    22,   629,    37,   631,   632,    27,   634,    41,
      22,    12,    13,   632,   572,   641,   642,   643,    69,    27,
     578,   727,   641,   642,    27,    27,    13,    36,    35,    14,
      36,    13,    60,    61,    35,    36,    37,    35,    66,    67,
      68,    69,    36,    36,    64,    36,   672,   699,    68,    22,
     676,   677,    72,    17,    76,    35,    76,    36,    36,    34,
      61,    89,    90,    27,   683,    13,    35,    22,    69,    36,
      36,   718,    61,    36,    38,   701,    27,   672,   704,    13,
      30,   707,   701,    35,   710,   704,    67,   687,   707,   330,
      36,   710,   692,   719,   699,    36,   124,   125,    62,    63,
      64,   727,    66,    36,    68,    11,    70,    71,    72,   735,
     535,    36,    76,    22,   672,    36,    36,   145,    36,   734,
      36,   677,    36,   151,    36,    36,   745,    27,    36,    27,
      27,    27,   758,   161,   162,    27,    13,   745,    13,   758,
     735,   767,    30,   769,    30,    36,    36,    36,    35,    11,
      13,   777,   778,    20,    35,    22,    13,    30,    22,   785,
      27,    22,    61,    27,    13,   791,   785,   195,   677,    27,
      30,    36,   798,   491,    13,    30,    61,   735,    61,   798,
     161,   162,   777,   778,   810,    35,    13,   806,    36,    17,
     218,   810,    36,    21,    22,    36,   791,    64,    35,    27,
      64,    68,    30,    31,    68,    72,   825,    35,    72,    76,
      38,    11,    76,   813,   195,    36,     6,    45,   643,   777,
     778,     6,    36,    36,    36,    30,    13,    35,   653,    22,
      11,    11,    35,   791,    62,    63,    64,    65,    66,    67,
      68,   233,    70,    71,    72,    13,    15,    36,    76,   490,
     491,   279,   280,   281,   282,   283,    13,    36,    17,   287,
      36,    35,    13,    36,   292,    36,   294,   259,    27,    11,
     298,   299,   300,   301,   302,    36,    13,    35,    13,    38,
      36,   309,   310,   311,    11,    13,    35,    13,    22,    13,
     318,   319,    13,    27,   719,    13,    36,    13,    34,    12,
      30,   282,   727,    62,    63,    64,    13,    66,    30,    68,
     338,    70,    71,    72,   632,    34,    36,    76,    11,    36,
      12,    35,   350,   641,   642,   353,   354,   355,   356,   357,
      64,   359,   360,   361,    68,    13,    13,   365,    72,    35,
      13,    13,    76,    13,    11,   373,   374,   375,   376,    36,
      36,    22,    60,    61,    36,    36,    36,   338,    66,    67,
      36,    69,   787,    13,   283,   676,    35,   395,   734,    37,
     791,   672,   353,   354,   355,   356,   357,   677,   359,   282,
     195,    89,    90,   701,   365,   718,   787,   653,   330,   707,
     491,   632,   710,   374,   375,   376,   785,   389,   798,   427,
     641,   642,   758,   699,   732,   397,   398,   399,   400,   401,
     402,   403,   704,   716,   629,   125,   124,   125,   470,   411,
     412,   264,   414,   415,   416,   417,   418,   321,   298,   723,
     427,   683,   825,   614,   426,   692,   147,   145,    -1,    -1,
     758,    -1,   470,   151,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   162,    -1,    -1,    -1,    -1,    -1,
     701,    -1,    -1,   704,    -1,    -1,   707,   785,    -1,   710,
      -1,    -1,    -1,     4,     5,    -1,     7,    -1,   506,    -1,
     798,   509,    -1,    -1,    -1,   513,   514,   195,    19,    -1,
      21,    22,   810,    -1,    -1,    -1,    27,    -1,    -1,    -1,
      -1,    32,    22,    -1,    -1,    -1,   534,   535,    -1,    -1,
      -1,    -1,    -1,   541,    45,    35,    -1,   758,    -1,    -1,
      -1,    -1,    42,    43,    44,    -1,    46,    47,   509,   557,
     558,    62,    63,    64,    -1,    66,    -1,    68,    -1,    70,
      71,    72,    62,    -1,   785,    76,    66,    -1,    68,    -1,
      70,    71,    72,   534,   535,    -1,    76,   798,   550,    -1,
     541,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   810,
      -1,   279,   280,   281,   282,    -1,    -1,    -1,    -1,   287,
      -1,    -1,    -1,    -1,   292,    22,   294,    -1,    -1,    -1,
     298,   299,   300,   301,   302,   623,    -1,    -1,    35,    -1,
     233,   309,   310,   311,    -1,    -1,    -1,    -1,    -1,    -1,
     318,   319,    49,    50,    -1,   643,    53,    54,    -1,    -1,
      57,    -1,    -1,    60,    -1,   653,   259,    -1,    -1,    66,
     338,    68,    -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,
      -1,    -1,   350,    -1,    -1,   353,   354,   355,   356,   357,
      -1,   359,   360,   361,    -1,    -1,    -1,   365,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   373,   374,   375,   376,   697,
      -1,   699,    60,    61,    -1,    -1,    -1,    -1,    66,    67,
      68,    69,    -1,    -1,    -1,   677,    -1,   395,   716,    -1,
     718,   719,    -1,    -1,     3,    -1,    -1,    -1,    -1,   727,
      -1,    89,    90,    -1,    -1,    14,   734,    16,    -1,    18,
      -1,    -1,    21,    22,    23,    24,    -1,    26,    27,   427,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    -1,    -1,    -1,   124,   125,   719,   767,
     732,   769,    -1,    -1,    -1,    -1,   727,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   389,   145,    67,   787,
      -1,    -1,   470,   151,   397,   398,   399,   400,   401,   402,
     403,    -1,   160,   161,   162,    -1,    -1,    -1,    -1,    -1,
      -1,   414,   415,   416,   417,   418,   767,    -1,   769,    -1,
      -1,    -1,    -1,   426,     4,     5,    -1,     7,   506,    -1,
      -1,   509,    -1,    -1,    -1,   513,   514,   195,    -1,    19,
      -1,    21,    22,    -1,    -1,    -1,    -1,    27,    -1,    -1,
      -1,    -1,    32,    -1,    17,    -1,   534,   535,   216,    22,
     218,    -1,    -1,   541,    27,    45,    -1,    -1,    31,    -1,
      -1,    -1,    -1,    -1,     3,    38,    -1,     6,    -1,   557,
     558,    -1,    62,    63,    64,    65,    66,    16,    68,    -1,
      70,    71,    72,    -1,    23,    24,    -1,    26,    -1,    62,
      63,    64,    65,    66,    -1,    68,    -1,    70,    71,    72,
      39,    40,    41,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   279,   280,   281,   282,   283,    -1,    27,    -1,   287,
      -1,    -1,    -1,    -1,   292,    -1,   294,    -1,    38,    -1,
     298,   299,   300,   301,   302,   623,    -1,    -1,    -1,    -1,
      -1,   309,   310,   311,    -1,    -1,    -1,    -1,    -1,    -1,
     318,   319,    62,    63,    64,   643,    66,    -1,    68,    -1,
      70,    71,    72,    -1,    -1,   653,    76,    -1,    -1,    -1,
     338,    -1,    60,    61,    21,    22,    -1,    -1,    66,    67,
      27,    69,   350,    -1,    -1,   353,   354,   355,   356,   357,
      -1,   359,   360,   361,    -1,    -1,    -1,   365,    45,    -1,
      -1,    89,    90,    -1,    -1,   373,   374,   375,   376,   697,
      -1,   699,    -1,    -1,    -1,    62,    63,    64,    -1,    66,
      -1,    68,    -1,    70,    71,    72,    -1,   395,   716,    76,
     718,   719,    -1,    -1,    -1,    -1,   124,   125,    -1,   727,
      -1,    17,    -1,    -1,    -1,    -1,   734,     3,    -1,    -1,
      -1,    27,    -1,    -1,    -1,    31,    -1,   145,    -1,   427,
      16,    -1,    38,   151,   677,    -1,    -1,    23,    24,    -1,
      26,    -1,   160,   161,   162,    -1,    -1,    -1,    -1,   767,
      -1,   769,    -1,    39,    40,    41,    62,    63,    64,    65,
      66,    -1,    68,    -1,    70,    71,    72,    -1,    -1,   787,
      76,    -1,   470,    -1,    17,    -1,    -1,   195,    21,    22,
      -1,    -1,    -1,    -1,    27,    -1,    -1,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,   216,    -1,
      -1,    -1,    45,    27,    -1,    -1,    -1,    -1,   506,    -1,
      -1,   509,    -1,    -1,    38,   513,   514,    -1,    -1,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      -1,    -1,    -1,    76,    -1,   533,   534,   535,    62,    63,
      64,    -1,    66,   541,    68,    -1,    70,    71,    72,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    17,    -1,   557,
     558,   279,   280,   281,   282,    -1,    -1,    27,    -1,   287,
      -1,    31,   570,    -1,   292,    35,   294,    -1,    38,    -1,
     298,   299,   300,   301,   302,    -1,    -1,    -1,    -1,    -1,
      -1,   309,   310,   311,    -1,    -1,    -1,    -1,    -1,    -1,
     318,   319,    62,    63,    64,    65,    66,    -1,    68,    -1,
      70,    71,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,
     338,    -1,    60,    61,    27,   623,    -1,    -1,    66,    67,
      -1,    69,   350,    -1,    -1,   353,   354,   355,   356,   357,
      -1,   359,   360,   361,    -1,   643,    -1,   365,    -1,    -1,
      -1,    89,    90,    -1,    -1,   373,   374,   375,   376,    62,
      63,    64,    -1,    66,    -1,    68,    -1,    70,    71,    72,
      -1,    -1,    -1,    76,    -1,    -1,    -1,   395,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    -1,   124,   125,    21,    22,
      -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    31,   697,
      -1,   699,    -1,    -1,    -1,    38,    -1,   145,    -1,   427,
      -1,    -1,    45,   151,    -1,    -1,    -1,    -1,   716,    -1,
     718,   719,   160,   161,   162,     3,    -1,    -1,    -1,   727,
      63,    64,    65,    -1,    67,    68,   734,    -1,    16,    72,
      -1,    -1,    -1,    76,    -1,    23,    24,    -1,    26,    -1,
      -1,    -1,   470,    -1,    17,    -1,    -1,   195,    21,    22,
      -1,    39,    40,    41,    27,    -1,    -1,    30,    31,   767,
      -1,   769,    -1,    -1,    -1,    38,    -1,    -1,   216,    -1,
      -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,   506,    -1,
      -1,   509,    -1,    -1,    38,   513,   514,    -1,    -1,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      -1,    -1,    -1,    76,    -1,   533,   534,   535,    62,    63,
      64,    -1,    66,   541,    68,    -1,    70,    71,    72,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,   557,
     558,   279,   280,   281,   282,    22,    -1,    -1,    -1,   287,
      -1,    -1,   570,    -1,   292,    -1,   294,    -1,    -1,    -1,
     298,   299,   300,   301,   302,    42,    43,    44,    -1,    46,
      47,   309,   310,   311,    -1,    -1,    -1,    -1,    -1,    -1,
     318,   319,    -1,    -1,    -1,    62,    -1,    -1,    -1,    66,
      -1,    68,    -1,    70,    71,    72,    -1,    -1,    -1,    76,
     338,    -1,    60,    61,    -1,   623,    -1,    -1,    66,    67,
      -1,    69,    22,    -1,    -1,   353,   354,   355,   356,   357,
      -1,   359,   360,   361,    -1,   643,    -1,   365,    -1,    -1,
      -1,    89,    90,    -1,    -1,   373,   374,   375,   376,    49,
      50,    -1,    -1,    53,    54,    -1,    -1,    57,    -1,    -1,
      60,    62,    63,    64,    -1,    66,    66,    68,    68,    70,
      71,    72,    72,    -1,    -1,    76,   124,   125,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   697,
      -1,   699,    -1,    -1,    -1,    -1,    -1,   145,    -1,   427,
      -1,    -1,    -1,   151,    -1,    -1,    -1,    -1,   716,    -1,
     718,   719,   160,   161,   162,    -1,    -1,    -1,    -1,   727,
      -1,    -1,    -1,    -1,    -1,    -1,   734,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   470,    -1,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   767,
      -1,   769,    -1,    -1,    -1,    -1,    -1,    -1,   216,    17,
      -1,    -1,    -1,    21,    22,    -1,    -1,    -1,   506,    27,
      -1,   509,    -1,    31,    -1,    61,    -1,    35,    -1,    -1,
      38,    67,    -1,    69,    -1,    -1,    -1,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   533,   534,   535,    -1,    -1,
      -1,    -1,    -1,   541,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    -1,    -1,    -1,    76,    -1,
      -1,   279,   280,   281,   282,    -1,    -1,    -1,    -1,   287,
      -1,    -1,   570,    -1,   292,    -1,   294,    -1,   124,   125,
     298,   299,   300,   301,   302,    -1,    -1,    -1,    -1,    -1,
      -1,   309,   310,   311,    -1,    -1,    -1,    -1,    -1,   145,
     318,   319,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   161,   162,    -1,    -1,    -1,
     338,    60,    61,    -1,    -1,   623,    -1,    66,    67,    -1,
      69,    -1,    -1,    -1,    -1,   353,   354,   355,   356,   357,
      -1,   359,   360,   361,    -1,   643,    -1,   365,    -1,   195,
      89,    90,    -1,    -1,    -1,   373,   374,   375,   376,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   124,   125,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   697,
      -1,   699,    -1,    -1,    -1,    -1,   145,    -1,    -1,   427,
      -1,    -1,   151,    -1,    -1,    -1,    -1,    -1,   716,    -1,
      61,   719,   161,   162,    -1,    -1,    67,    -1,    69,   727,
      -1,    -1,    -1,    -1,   280,    -1,   282,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   470,    -1,    -1,    -1,   302,    -1,    -1,    -1,
      -1,    -1,    -1,   309,   310,   311,    -1,    -1,    -1,   767,
      -1,   769,   318,   319,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   124,   125,    -1,    -1,    -1,   506,    -1,
      -1,   509,   338,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   145,    -1,    -1,   353,   354,   355,
     356,   357,    -1,   359,    -1,   533,   534,   535,    -1,   365,
     161,   162,    -1,   541,    -1,    -1,    -1,    -1,   374,   375,
     376,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     279,   280,   281,   282,    -1,    -1,    -1,    -1,   287,    -1,
      -1,    -1,   570,   292,   195,   294,    -1,    -1,    -1,   298,
     299,   300,   301,   302,    -1,    -1,    -1,    -1,    -1,    -1,
     309,   310,   311,    -1,    -1,    -1,    -1,    -1,    -1,   318,
     319,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   338,
      -1,    -1,    -1,    -1,    -1,   623,    -1,    -1,    -1,    -1,
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
      -1,   470,    -1,   374,   375,   376,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   767,
      -1,   769,    -1,    -1,    -1,    -1,     4,     5,    -1,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
     509,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    27,
      -1,    -1,    30,    31,    32,    33,    -1,    35,    -1,    -1,
      38,    -1,    -1,    -1,    -1,   534,   535,    45,    -1,    -1,
      -1,    -1,   541,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    -1,    -1,    -1,    76,   470,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   697,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   509,    -1,
      -1,    -1,    -1,   719,     4,     5,    -1,     7,     8,     9,
      10,   727,    -1,    -1,   623,    -1,    -1,    17,    -1,    19,
      20,    21,    22,   534,   535,    -1,    -1,    27,    -1,    -1,
     541,    31,    32,    33,   643,    35,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,
      -1,   767,    -1,   769,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    -1,    -1,    -1,    76,    -1,     3,     4,
       5,    -1,     7,     8,     9,    10,    -1,    -1,   697,    14,
     699,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,    26,    27,    -1,    -1,    30,    31,    32,    33,    -1,
     719,    -1,    -1,    38,    39,    40,    41,    -1,   727,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,   767,    -1,
     769,     3,     4,     5,    -1,     7,     8,     9,    10,    -1,
      -1,    -1,    14,    -1,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    26,    27,   697,    -1,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,   719,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   727,    -1,    -1,    -1,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,     3,     4,     5,    76,     7,     8,     9,    10,    -1,
      -1,    -1,    14,    -1,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    26,    27,   767,    -1,   769,    31,
      32,    33,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    -1,     4,     5,    76,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    -1,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    31,
      32,    33,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    -1,     4,     5,    76,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    -1,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    31,
      32,    33,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    -1,     4,     5,    76,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    -1,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    31,
      32,    33,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    -1,     4,     5,    76,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    -1,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    31,
      32,    33,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    -1,     4,     5,    76,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    -1,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,
      -1,    21,    22,    45,    -1,    -1,    -1,    27,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      62,    63,    64,    65,    66,    45,    68,    -1,    70,    71,
      72,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    63,    64,    65,    66,    67,    68,    17,
      70,    71,    72,    21,    22,    -1,    76,    -1,    -1,    27,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    -1,    -1,    -1,    76
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
     300,   301,   302,    17,    22,    27,    31,    38,    65,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   215,   229,   230,   242,   245,    35,    13,   291,   298,
      17,    27,   173,   199,   200,   201,   232,   253,   257,   261,
      21,    22,    27,    45,    67,   137,   138,   139,   140,   141,
     142,   143,   144,   146,   147,   148,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   168,   170,   171,   173,
     185,   186,   187,   192,   198,   240,   241,   242,   245,   253,
     257,   258,   259,   260,   261,   262,   265,   266,     4,     5,
       7,     8,     9,    10,    19,    20,    21,    22,    27,    32,
      33,    45,    90,    91,    92,    93,    94,    95,    96,    97,
      98,   100,   101,   102,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   120,   122,   123,   126,   128,   130,
     131,   132,   133,   134,   135,   136,   188,   198,   235,   236,
     237,   238,   242,   245,   253,   257,   258,   259,   260,   261,
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
     240,   241,   242,   242,   242,   243,   243,   243,   243,   243,
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
#line 2941 "y.tab.c"
    break;

  case 3: /* TPTP_file: TPTP_file TPTP_input  */
#line 231 "SyntaxBNF.y"
                                           {}
#line 2947 "y.tab.c"
    break;

  case 4: /* TPTP_input: annotated_formula  */
#line 234 "SyntaxBNF.y"
                               {P_PRINT((yyval.pval));}
#line 2953 "y.tab.c"
    break;

  case 5: /* TPTP_input: include  */
#line 235 "SyntaxBNF.y"
                              {P_PRINT((yyval.pval));}
#line 2959 "y.tab.c"
    break;

  case 6: /* annotated_formula: thf_annotated  */
#line 238 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2965 "y.tab.c"
    break;

  case 7: /* annotated_formula: tff_annotated  */
#line 239 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2971 "y.tab.c"
    break;

  case 8: /* annotated_formula: tcf_annotated  */
#line 240 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2977 "y.tab.c"
    break;

  case 9: /* annotated_formula: fof_annotated  */
#line 241 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2983 "y.tab.c"
    break;

  case 10: /* annotated_formula: cnf_annotated  */
#line 242 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2989 "y.tab.c"
    break;

  case 11: /* annotated_formula: tpi_annotated  */
#line 243 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2995 "y.tab.c"
    break;

  case 12: /* tpi_annotated: _LIT_tpi LPAREN name COMMA formula_role COMMA tpi_formula annotations RPAREN PERIOD  */
#line 246 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("tpi_annotated", P_TOKEN("_LIT_tpi ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 3001 "y.tab.c"
    break;

  case 13: /* tpi_formula: fof_formula  */
#line 249 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("tpi_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3007 "y.tab.c"
    break;

  case 14: /* thf_annotated: _LIT_thf LPAREN name COMMA formula_role COMMA thf_formula annotations RPAREN PERIOD  */
#line 252 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("thf_annotated", P_TOKEN("_LIT_thf ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 3013 "y.tab.c"
    break;

  case 15: /* tff_annotated: _LIT_tff LPAREN name COMMA formula_role COMMA tff_formula annotations RPAREN PERIOD  */
#line 255 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("tff_annotated", P_TOKEN("_LIT_tff ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 3019 "y.tab.c"
    break;

  case 16: /* tcf_annotated: _LIT_tcf LPAREN name COMMA formula_role COMMA tcf_formula annotations RPAREN PERIOD  */
#line 258 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("tcf_annotated", P_TOKEN("_LIT_tcf ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 3025 "y.tab.c"
    break;

  case 17: /* fof_annotated: _LIT_fof LPAREN name COMMA formula_role COMMA fof_formula annotations RPAREN PERIOD  */
#line 261 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("fof_annotated", P_TOKEN("_LIT_fof ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 3031 "y.tab.c"
    break;

  case 18: /* cnf_annotated: _LIT_cnf LPAREN name COMMA formula_role COMMA cnf_formula annotations RPAREN PERIOD  */
#line 264 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("cnf_annotated", P_TOKEN("_LIT_cnf ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 3037 "y.tab.c"
    break;

  case 19: /* annotations: COMMA source optional_info  */
#line 267 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("annotations", P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3043 "y.tab.c"
    break;

  case 20: /* annotations: nothing  */
#line 268 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("annotations", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3049 "y.tab.c"
    break;

  case 21: /* formula_role: lower_word  */
#line 271 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("formula_role", P_TOKEN("lower_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3055 "y.tab.c"
    break;

  case 22: /* formula_role: lower_word MINUS general_term  */
#line 272 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("formula_role", P_TOKEN("lower_word ", (yyvsp[-2].ival)), P_TOKEN("MINUS ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3061 "y.tab.c"
    break;

  case 23: /* thf_formula: thf_logic_formula  */
#line 275 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3067 "y.tab.c"
    break;

  case 24: /* thf_formula: thf_atom_typing  */
#line 276 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3073 "y.tab.c"
    break;

  case 25: /* thf_formula: thf_subtype  */
#line 277 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("thf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3079 "y.tab.c"
    break;

  case 26: /* thf_logic_formula: thf_unitary_formula  */
#line 280 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3085 "y.tab.c"
    break;

  case 27: /* thf_logic_formula: thf_unary_formula  */
#line 281 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3091 "y.tab.c"
    break;

  case 28: /* thf_logic_formula: thf_binary_formula  */
#line 282 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3097 "y.tab.c"
    break;

  case 29: /* thf_logic_formula: thf_defined_infix  */
#line 283 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3103 "y.tab.c"
    break;

  case 30: /* thf_logic_formula: thf_definition  */
#line 284 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3109 "y.tab.c"
    break;

  case 31: /* thf_logic_formula: thf_sequent  */
#line 285 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3115 "y.tab.c"
    break;

  case 32: /* thf_binary_formula: thf_binary_nonassoc  */
#line 288 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3121 "y.tab.c"
    break;

  case 33: /* thf_binary_formula: thf_binary_assoc  */
#line 289 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3127 "y.tab.c"
    break;

  case 34: /* thf_binary_formula: thf_binary_type  */
#line 290 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3133 "y.tab.c"
    break;

  case 35: /* thf_binary_nonassoc: thf_unit_formula nonassoc_connective thf_unit_formula  */
#line 293 "SyntaxBNF.y"
                                                                            {(yyval.pval) = P_BUILD("thf_binary_nonassoc", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3139 "y.tab.c"
    break;

  case 36: /* thf_binary_assoc: thf_or_formula  */
#line 296 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("thf_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3145 "y.tab.c"
    break;

  case 37: /* thf_binary_assoc: thf_and_formula  */
#line 297 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3151 "y.tab.c"
    break;

  case 38: /* thf_binary_assoc: thf_apply_formula  */
#line 298 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3157 "y.tab.c"
    break;

  case 39: /* thf_or_formula: thf_unit_formula VLINE thf_unit_formula  */
#line 301 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("thf_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3163 "y.tab.c"
    break;

  case 40: /* thf_or_formula: thf_or_formula VLINE thf_unit_formula  */
#line 302 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("thf_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3169 "y.tab.c"
    break;

  case 41: /* thf_and_formula: thf_unit_formula AMPERSAND thf_unit_formula  */
#line 305 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3175 "y.tab.c"
    break;

  case 42: /* thf_and_formula: thf_and_formula AMPERSAND thf_unit_formula  */
#line 306 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3181 "y.tab.c"
    break;

  case 43: /* thf_apply_formula: thf_unit_formula AT_SIGN thf_unit_formula  */
#line 309 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_apply_formula", (yyvsp[-2].pval), P_TOKEN("AT_SIGN ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3187 "y.tab.c"
    break;

  case 44: /* thf_apply_formula: thf_apply_formula AT_SIGN thf_unit_formula  */
#line 310 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_apply_formula", (yyvsp[-2].pval), P_TOKEN("AT_SIGN ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3193 "y.tab.c"
    break;

  case 45: /* thf_unit_formula: thf_unitary_formula  */
#line 313 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3199 "y.tab.c"
    break;

  case 46: /* thf_unit_formula: thf_unary_formula  */
#line 314 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3205 "y.tab.c"
    break;

  case 47: /* thf_unit_formula: thf_defined_infix  */
#line 315 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3211 "y.tab.c"
    break;

  case 48: /* thf_preunit_formula: thf_unitary_formula  */
#line 318 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("thf_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3217 "y.tab.c"
    break;

  case 49: /* thf_preunit_formula: thf_prefix_unary  */
#line 319 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3223 "y.tab.c"
    break;

  case 50: /* thf_unitary_formula: thf_quantified_formula  */
#line 322 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("thf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3229 "y.tab.c"
    break;

  case 51: /* thf_unitary_formula: thf_atomic_formula  */
#line 323 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3235 "y.tab.c"
    break;

  case 52: /* thf_unitary_formula: variable  */
#line 324 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("thf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3241 "y.tab.c"
    break;

  case 53: /* thf_unitary_formula: LPAREN thf_logic_formula RPAREN  */
#line 325 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("thf_unitary_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3247 "y.tab.c"
    break;

  case 54: /* thf_quantified_formula: thf_quantification thf_unit_formula  */
#line 328 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("thf_quantified_formula", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3253 "y.tab.c"
    break;

  case 55: /* thf_quantification: thf_quantifier LBRKT thf_variable_list RBRKT COLON  */
#line 331 "SyntaxBNF.y"
                                                                        {(yyval.pval) = P_BUILD("thf_quantification", (yyvsp[-4].pval), P_TOKEN("LBRKT ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("RBRKT ", (yyvsp[-1].ival)), P_TOKEN("COLON ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL);}
#line 3259 "y.tab.c"
    break;

  case 56: /* thf_variable_list: thf_typed_variable  */
#line 334 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_variable_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3265 "y.tab.c"
    break;

  case 57: /* thf_variable_list: thf_typed_variable COMMA thf_variable_list  */
#line 335 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_variable_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3271 "y.tab.c"
    break;

  case 58: /* thf_typed_variable: variable COLON thf_top_level_type  */
#line 338 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("thf_typed_variable", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3277 "y.tab.c"
    break;

  case 59: /* thf_unary_formula: thf_prefix_unary  */
#line 341 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3283 "y.tab.c"
    break;

  case 60: /* thf_unary_formula: thf_infix_unary  */
#line 342 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3289 "y.tab.c"
    break;

  case 61: /* thf_prefix_unary: thf_unary_connective thf_preunit_formula  */
#line 345 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("thf_prefix_unary", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3295 "y.tab.c"
    break;

  case 62: /* thf_infix_unary: thf_unitary_term infix_inequality thf_unitary_term  */
#line 348 "SyntaxBNF.y"
                                                                     {(yyval.pval) = P_BUILD("thf_infix_unary", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3301 "y.tab.c"
    break;

  case 63: /* thf_atomic_formula: thf_plain_atomic  */
#line 351 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3307 "y.tab.c"
    break;

  case 64: /* thf_atomic_formula: thf_defined_atomic  */
#line 352 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3313 "y.tab.c"
    break;

  case 65: /* thf_atomic_formula: thf_system_atomic  */
#line 353 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3319 "y.tab.c"
    break;

  case 66: /* thf_atomic_formula: thf_fof_function  */
#line 354 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3325 "y.tab.c"
    break;

  case 67: /* thf_plain_atomic: constant  */
#line 357 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("thf_plain_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3331 "y.tab.c"
    break;

  case 68: /* thf_plain_atomic: thf_tuple  */
#line 358 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_plain_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3337 "y.tab.c"
    break;

  case 69: /* thf_defined_atomic: defined_constant  */
#line 361 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3343 "y.tab.c"
    break;

  case 70: /* thf_defined_atomic: thf_defined_term  */
#line 362 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3349 "y.tab.c"
    break;

  case 71: /* thf_defined_atomic: LPAREN thf_conn_term RPAREN  */
#line 363 "SyntaxBNF.y"
                                                  {(yyval.pval) = P_BUILD("thf_defined_atomic", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3355 "y.tab.c"
    break;

  case 72: /* thf_defined_atomic: nhf_long_connective  */
#line 364 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3361 "y.tab.c"
    break;

  case 73: /* thf_defined_atomic: thf_let  */
#line 365 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3367 "y.tab.c"
    break;

  case 74: /* thf_defined_term: defined_term  */
#line 368 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3373 "y.tab.c"
    break;

  case 75: /* thf_defined_term: th1_defined_term  */
#line 369 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3379 "y.tab.c"
    break;

  case 76: /* thf_defined_infix: thf_unitary_term defined_infix_pred thf_unitary_term  */
#line 372 "SyntaxBNF.y"
                                                                         {(yyval.pval) = P_BUILD("thf_defined_infix", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3385 "y.tab.c"
    break;

  case 77: /* thf_system_atomic: system_constant  */
#line 375 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("thf_system_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3391 "y.tab.c"
    break;

  case 78: /* thf_let: _DLR_let LPAREN thf_let_types COMMA thf_let_defns COMMA thf_logic_formula RPAREN  */
#line 378 "SyntaxBNF.y"
                                                                                           {(yyval.pval) = P_BUILD("thf_let", P_TOKEN("_DLR_let ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 3397 "y.tab.c"
    break;

  case 79: /* thf_let_types: thf_atom_typing  */
#line 381 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_let_types", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3403 "y.tab.c"
    break;

  case 80: /* thf_let_types: LBRKT thf_atom_typing_list RBRKT  */
#line 382 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("thf_let_types", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3409 "y.tab.c"
    break;

  case 81: /* thf_atom_typing_list: thf_atom_typing  */
#line 385 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_atom_typing_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3415 "y.tab.c"
    break;

  case 82: /* thf_atom_typing_list: thf_atom_typing COMMA thf_atom_typing_list  */
#line 386 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_atom_typing_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3421 "y.tab.c"
    break;

  case 83: /* thf_let_defns: thf_let_defn  */
#line 389 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("thf_let_defns", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3427 "y.tab.c"
    break;

  case 84: /* thf_let_defns: LBRKT thf_let_defn_list RBRKT  */
#line 390 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("thf_let_defns", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3433 "y.tab.c"
    break;

  case 85: /* thf_let_defn: thf_logic_formula assignment thf_logic_formula  */
#line 393 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_let_defn", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3439 "y.tab.c"
    break;

  case 86: /* thf_let_defn_list: thf_let_defn  */
#line 396 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("thf_let_defn_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3445 "y.tab.c"
    break;

  case 87: /* thf_let_defn_list: thf_let_defn COMMA thf_let_defn_list  */
#line 397 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_let_defn_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3451 "y.tab.c"
    break;

  case 88: /* thf_unitary_term: thf_atomic_formula  */
#line 400 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3457 "y.tab.c"
    break;

  case 89: /* thf_unitary_term: variable  */
#line 401 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("thf_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3463 "y.tab.c"
    break;

  case 90: /* thf_unitary_term: LPAREN thf_logic_formula RPAREN  */
#line 402 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("thf_unitary_term", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3469 "y.tab.c"
    break;

  case 91: /* thf_conn_term: nonassoc_connective  */
#line 405 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3475 "y.tab.c"
    break;

  case 92: /* thf_conn_term: assoc_connective  */
#line 406 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3481 "y.tab.c"
    break;

  case 93: /* thf_conn_term: infix_equality  */
#line 407 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3487 "y.tab.c"
    break;

  case 94: /* thf_conn_term: infix_inequality  */
#line 408 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3493 "y.tab.c"
    break;

  case 95: /* thf_conn_term: thf_unary_connective  */
#line 409 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3499 "y.tab.c"
    break;

  case 96: /* thf_tuple: LBRKT RBRKT  */
#line 412 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("thf_tuple", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3505 "y.tab.c"
    break;

  case 97: /* thf_tuple: LBRKT thf_formula_list RBRKT  */
#line 413 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("thf_tuple", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3511 "y.tab.c"
    break;

  case 98: /* thf_fof_function: functor LPAREN thf_arguments RPAREN  */
#line 416 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("thf_fof_function", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3517 "y.tab.c"
    break;

  case 99: /* thf_fof_function: defined_functor LPAREN thf_arguments RPAREN  */
#line 417 "SyntaxBNF.y"
                                                                  {(yyval.pval) = P_BUILD("thf_fof_function", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3523 "y.tab.c"
    break;

  case 100: /* thf_fof_function: system_functor LPAREN thf_arguments RPAREN  */
#line 418 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_fof_function", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3529 "y.tab.c"
    break;

  case 101: /* thf_arguments: thf_formula_list  */
#line 421 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("thf_arguments", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3535 "y.tab.c"
    break;

  case 102: /* thf_formula_list: thf_logic_formula  */
#line 424 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_formula_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3541 "y.tab.c"
    break;

  case 103: /* thf_formula_list: thf_logic_formula COMMA thf_formula_list  */
#line 425 "SyntaxBNF.y"
                                                               {(yyval.pval) = P_BUILD("thf_formula_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3547 "y.tab.c"
    break;

  case 104: /* thf_atom_typing: untyped_atom COLON thf_top_level_type  */
#line 428 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("thf_atom_typing", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3553 "y.tab.c"
    break;

  case 105: /* thf_atom_typing: LPAREN thf_atom_typing RPAREN  */
#line 429 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("thf_atom_typing", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3559 "y.tab.c"
    break;

  case 106: /* thf_top_level_type: thf_unitary_type  */
#line 432 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3565 "y.tab.c"
    break;

  case 107: /* thf_top_level_type: thf_mapping_type  */
#line 433 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3571 "y.tab.c"
    break;

  case 108: /* thf_top_level_type: thf_apply_type  */
#line 434 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3577 "y.tab.c"
    break;

  case 109: /* thf_unitary_type: thf_unitary_formula  */
#line 437 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_unitary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3583 "y.tab.c"
    break;

  case 110: /* thf_apply_type: thf_apply_formula  */
#line 440 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("thf_apply_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3589 "y.tab.c"
    break;

  case 111: /* thf_binary_type: thf_mapping_type  */
#line 443 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("thf_binary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3595 "y.tab.c"
    break;

  case 112: /* thf_binary_type: thf_xprod_type  */
#line 444 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_binary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3601 "y.tab.c"
    break;

  case 113: /* thf_binary_type: thf_union_type  */
#line 445 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_binary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3607 "y.tab.c"
    break;

  case 114: /* thf_mapping_type: thf_unitary_type arrow thf_unitary_type  */
#line 448 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_mapping_type", (yyvsp[-2].pval), P_TOKEN("arrow ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3613 "y.tab.c"
    break;

  case 115: /* thf_mapping_type: thf_unitary_type arrow thf_mapping_type  */
#line 449 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_mapping_type", (yyvsp[-2].pval), P_TOKEN("arrow ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3619 "y.tab.c"
    break;

  case 116: /* thf_xprod_type: thf_unitary_type STAR thf_unitary_type  */
#line 452 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("thf_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3625 "y.tab.c"
    break;

  case 117: /* thf_xprod_type: thf_xprod_type STAR thf_unitary_type  */
#line 453 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3631 "y.tab.c"
    break;

  case 118: /* thf_union_type: thf_unitary_type plus thf_unitary_type  */
#line 456 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("thf_union_type", (yyvsp[-2].pval), P_TOKEN("plus ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3637 "y.tab.c"
    break;

  case 119: /* thf_union_type: thf_union_type plus thf_unitary_type  */
#line 457 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_union_type", (yyvsp[-2].pval), P_TOKEN("plus ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3643 "y.tab.c"
    break;

  case 120: /* thf_subtype: untyped_atom subtype_sign atom  */
#line 460 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("thf_subtype", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3649 "y.tab.c"
    break;

  case 121: /* thf_definition: thf_atomic_formula identical thf_logic_formula  */
#line 463 "SyntaxBNF.y"
                                                                {(yyval.pval) = P_BUILD("thf_definition", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3655 "y.tab.c"
    break;

  case 122: /* thf_sequent: thf_tuple gentzen_arrow thf_tuple  */
#line 466 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("thf_sequent", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3661 "y.tab.c"
    break;

  case 123: /* tff_formula: tff_logic_formula  */
#line 469 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3667 "y.tab.c"
    break;

  case 124: /* tff_formula: tff_atom_typing  */
#line 470 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3673 "y.tab.c"
    break;

  case 125: /* tff_formula: tff_subtype  */
#line 471 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tff_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3679 "y.tab.c"
    break;

  case 126: /* tff_logic_formula: tff_unitary_formula  */
#line 474 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3685 "y.tab.c"
    break;

  case 127: /* tff_logic_formula: tff_unary_formula  */
#line 475 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3691 "y.tab.c"
    break;

  case 128: /* tff_logic_formula: tff_binary_formula  */
#line 476 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3697 "y.tab.c"
    break;

  case 129: /* tff_logic_formula: tff_defined_infix  */
#line 477 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3703 "y.tab.c"
    break;

  case 130: /* tff_logic_formula: txf_definition  */
#line 478 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3709 "y.tab.c"
    break;

  case 131: /* tff_logic_formula: txf_sequent  */
#line 479 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3715 "y.tab.c"
    break;

  case 132: /* tff_binary_formula: tff_binary_nonassoc  */
#line 482 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3721 "y.tab.c"
    break;

  case 133: /* tff_binary_formula: tff_binary_assoc  */
#line 483 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3727 "y.tab.c"
    break;

  case 134: /* tff_binary_nonassoc: tff_unit_formula nonassoc_connective tff_unit_formula  */
#line 486 "SyntaxBNF.y"
                                                                            {(yyval.pval) = P_BUILD("tff_binary_nonassoc", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3733 "y.tab.c"
    break;

  case 135: /* tff_binary_assoc: tff_or_formula  */
#line 489 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tff_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3739 "y.tab.c"
    break;

  case 136: /* tff_binary_assoc: tff_and_formula  */
#line 490 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3745 "y.tab.c"
    break;

  case 137: /* tff_or_formula: tff_unit_formula VLINE tff_unit_formula  */
#line 493 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("tff_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3751 "y.tab.c"
    break;

  case 138: /* tff_or_formula: tff_or_formula VLINE tff_unit_formula  */
#line 494 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("tff_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3757 "y.tab.c"
    break;

  case 139: /* tff_and_formula: tff_unit_formula AMPERSAND tff_unit_formula  */
#line 497 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("tff_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3763 "y.tab.c"
    break;

  case 140: /* tff_and_formula: tff_and_formula AMPERSAND tff_unit_formula  */
#line 498 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("tff_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3769 "y.tab.c"
    break;

  case 141: /* tff_unit_formula: tff_unitary_formula  */
#line 501 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3775 "y.tab.c"
    break;

  case 142: /* tff_unit_formula: tff_unary_formula  */
#line 502 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3781 "y.tab.c"
    break;

  case 143: /* tff_unit_formula: tff_defined_infix  */
#line 503 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3787 "y.tab.c"
    break;

  case 144: /* tff_preunit_formula: tff_unitary_formula  */
#line 506 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3793 "y.tab.c"
    break;

  case 145: /* tff_preunit_formula: tff_prefix_unary  */
#line 507 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3799 "y.tab.c"
    break;

  case 146: /* tff_unitary_formula: tff_quantified_formula  */
#line 510 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("tff_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3805 "y.tab.c"
    break;

  case 147: /* tff_unitary_formula: tff_atomic_formula  */
#line 511 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3811 "y.tab.c"
    break;

  case 148: /* tff_unitary_formula: txf_unitary_formula  */
#line 512 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3817 "y.tab.c"
    break;

  case 149: /* tff_unitary_formula: LPAREN tff_logic_formula RPAREN  */
#line 513 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("tff_unitary_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3823 "y.tab.c"
    break;

  case 150: /* txf_unitary_formula: variable  */
#line 516 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("txf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3829 "y.tab.c"
    break;

  case 151: /* tff_quantified_formula: tff_quantifier LBRKT tff_variable_list RBRKT COLON tff_unit_formula  */
#line 519 "SyntaxBNF.y"
                                                                                             {(yyval.pval) = P_BUILD("tff_quantified_formula", (yyvsp[-5].pval), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 3835 "y.tab.c"
    break;

  case 152: /* tff_variable_list: tff_variable  */
#line 522 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("tff_variable_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3841 "y.tab.c"
    break;

  case 153: /* tff_variable_list: tff_variable COMMA tff_variable_list  */
#line 523 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("tff_variable_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3847 "y.tab.c"
    break;

  case 154: /* tff_variable: tff_typed_variable  */
#line 526 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tff_variable", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3853 "y.tab.c"
    break;

  case 155: /* tff_variable: variable  */
#line 527 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_variable", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3859 "y.tab.c"
    break;

  case 156: /* tff_typed_variable: variable COLON tff_atomic_type  */
#line 530 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("tff_typed_variable", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3865 "y.tab.c"
    break;

  case 157: /* tff_unary_formula: tff_prefix_unary  */
#line 533 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3871 "y.tab.c"
    break;

  case 158: /* tff_unary_formula: tff_infix_unary  */
#line 534 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3877 "y.tab.c"
    break;

  case 159: /* tff_prefix_unary: tff_unary_connective tff_preunit_formula  */
#line 537 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("tff_prefix_unary", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3883 "y.tab.c"
    break;

  case 160: /* tff_infix_unary: tff_unitary_term infix_inequality tff_unitary_term  */
#line 540 "SyntaxBNF.y"
                                                                     {(yyval.pval) = P_BUILD("tff_infix_unary", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3889 "y.tab.c"
    break;

  case 161: /* tff_atomic_formula: tff_plain_atomic  */
#line 543 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3895 "y.tab.c"
    break;

  case 162: /* tff_atomic_formula: tff_defined_atomic  */
#line 544 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3901 "y.tab.c"
    break;

  case 163: /* tff_atomic_formula: tff_system_atomic  */
#line 545 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3907 "y.tab.c"
    break;

  case 164: /* tff_plain_atomic: constant  */
#line 548 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("tff_plain_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3913 "y.tab.c"
    break;

  case 165: /* tff_plain_atomic: functor LPAREN tff_arguments RPAREN  */
#line 549 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("tff_plain_atomic", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3919 "y.tab.c"
    break;

  case 166: /* tff_defined_atomic: tff_defined_plain  */
#line 552 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3925 "y.tab.c"
    break;

  case 167: /* tff_defined_plain: defined_constant  */
#line 555 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3931 "y.tab.c"
    break;

  case 168: /* tff_defined_plain: defined_functor LPAREN tff_arguments RPAREN  */
#line 556 "SyntaxBNF.y"
                                                                  {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3937 "y.tab.c"
    break;

  case 169: /* tff_defined_plain: nxf_atom  */
#line 557 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3943 "y.tab.c"
    break;

  case 170: /* tff_defined_plain: txf_let  */
#line 558 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3949 "y.tab.c"
    break;

  case 171: /* tff_defined_infix: tff_unitary_term defined_infix_pred tff_unitary_term  */
#line 561 "SyntaxBNF.y"
                                                                         {(yyval.pval) = P_BUILD("tff_defined_infix", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3955 "y.tab.c"
    break;

  case 172: /* tff_system_atomic: system_constant  */
#line 564 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("tff_system_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3961 "y.tab.c"
    break;

  case 173: /* tff_system_atomic: system_functor LPAREN tff_arguments RPAREN  */
#line 565 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("tff_system_atomic", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3967 "y.tab.c"
    break;

  case 174: /* txf_let: _DLR_let LPAREN txf_let_types COMMA txf_let_defns COMMA tff_term RPAREN  */
#line 568 "SyntaxBNF.y"
                                                                                  {(yyval.pval) = P_BUILD("txf_let", P_TOKEN("_DLR_let ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 3973 "y.tab.c"
    break;

  case 175: /* txf_let_types: tff_atom_typing  */
#line 571 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("txf_let_types", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3979 "y.tab.c"
    break;

  case 176: /* txf_let_types: LBRKT tff_atom_typing_list RBRKT  */
#line 572 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("txf_let_types", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3985 "y.tab.c"
    break;

  case 177: /* tff_atom_typing_list: tff_atom_typing  */
#line 575 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_atom_typing_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3991 "y.tab.c"
    break;

  case 178: /* tff_atom_typing_list: tff_atom_typing COMMA tff_atom_typing_list  */
#line 576 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("tff_atom_typing_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3997 "y.tab.c"
    break;

  case 179: /* txf_let_defns: txf_let_defn  */
#line 579 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("txf_let_defns", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4003 "y.tab.c"
    break;

  case 180: /* txf_let_defns: LBRKT txf_let_defn_list RBRKT  */
#line 580 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("txf_let_defns", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4009 "y.tab.c"
    break;

  case 181: /* txf_let_defn: txf_let_LHS assignment tff_term  */
#line 583 "SyntaxBNF.y"
                                               {(yyval.pval) = P_BUILD("txf_let_defn", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4015 "y.tab.c"
    break;

  case 182: /* txf_let_LHS: tff_plain_atomic  */
#line 586 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("txf_let_LHS", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4021 "y.tab.c"
    break;

  case 183: /* txf_let_LHS: txf_tuple  */
#line 587 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("txf_let_LHS", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4027 "y.tab.c"
    break;

  case 184: /* txf_let_defn_list: txf_let_defn  */
#line 590 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("txf_let_defn_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4033 "y.tab.c"
    break;

  case 185: /* txf_let_defn_list: txf_let_defn COMMA txf_let_defn_list  */
#line 591 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("txf_let_defn_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4039 "y.tab.c"
    break;

  case 186: /* nxf_atom: nxf_long_connective AT_SIGN LPAREN tff_arguments RPAREN  */
#line 594 "SyntaxBNF.y"
                                                                   {(yyval.pval) = P_BUILD("nxf_atom", (yyvsp[-4].pval), P_TOKEN("AT_SIGN ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL);}
#line 4045 "y.tab.c"
    break;

  case 187: /* tff_term: tff_logic_formula  */
#line 597 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("tff_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4051 "y.tab.c"
    break;

  case 188: /* tff_term: defined_term  */
#line 598 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4057 "y.tab.c"
    break;

  case 189: /* tff_term: txf_tuple  */
#line 599 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4063 "y.tab.c"
    break;

  case 190: /* tff_unitary_term: tff_atomic_formula  */
#line 602 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4069 "y.tab.c"
    break;

  case 191: /* tff_unitary_term: defined_term  */
#line 603 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4075 "y.tab.c"
    break;

  case 192: /* tff_unitary_term: txf_tuple  */
#line 604 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4081 "y.tab.c"
    break;

  case 193: /* tff_unitary_term: variable  */
#line 605 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4087 "y.tab.c"
    break;

  case 194: /* tff_unitary_term: LPAREN tff_logic_formula RPAREN  */
#line 606 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("tff_unitary_term", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4093 "y.tab.c"
    break;

  case 195: /* txf_tuple: LBRKT RBRKT  */
#line 609 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("txf_tuple", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4099 "y.tab.c"
    break;

  case 196: /* txf_tuple: LBRKT tff_arguments RBRKT  */
#line 610 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("txf_tuple", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4105 "y.tab.c"
    break;

  case 197: /* tff_arguments: tff_term  */
#line 613 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_arguments", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4111 "y.tab.c"
    break;

  case 198: /* tff_arguments: tff_term COMMA tff_arguments  */
#line 614 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("tff_arguments", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4117 "y.tab.c"
    break;

  case 199: /* tff_atom_typing: untyped_atom COLON tff_top_level_type  */
#line 617 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("tff_atom_typing", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4123 "y.tab.c"
    break;

  case 200: /* tff_atom_typing: LPAREN tff_atom_typing RPAREN  */
#line 618 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("tff_atom_typing", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4129 "y.tab.c"
    break;

  case 201: /* tff_top_level_type: tff_atomic_type  */
#line 621 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4135 "y.tab.c"
    break;

  case 202: /* tff_top_level_type: tff_non_atomic_type  */
#line 622 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4141 "y.tab.c"
    break;

  case 203: /* tff_non_atomic_type: tff_mapping_type  */
#line 625 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_non_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4147 "y.tab.c"
    break;

  case 204: /* tff_non_atomic_type: tf1_quantified_type  */
#line 626 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_non_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4153 "y.tab.c"
    break;

  case 205: /* tff_non_atomic_type: LPAREN tff_non_atomic_type RPAREN  */
#line 627 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("tff_non_atomic_type", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4159 "y.tab.c"
    break;

  case 206: /* tf1_quantified_type: EXCLAMATION_GREATER LBRKT tff_variable_list RBRKT COLON tff_monotype  */
#line 630 "SyntaxBNF.y"
                                                                                           {(yyval.pval) = P_BUILD("tf1_quantified_type", P_TOKEN("EXCLAMATION_GREATER ", (yyvsp[-5].ival)), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 4165 "y.tab.c"
    break;

  case 207: /* tff_monotype: tff_atomic_type  */
#line 633 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_monotype", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4171 "y.tab.c"
    break;

  case 208: /* tff_monotype: LPAREN tff_mapping_type RPAREN  */
#line 634 "SyntaxBNF.y"
                                                     {(yyval.pval) = P_BUILD("tff_monotype", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4177 "y.tab.c"
    break;

  case 209: /* tff_monotype: tf1_quantified_type  */
#line 635 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_monotype", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4183 "y.tab.c"
    break;

  case 210: /* tff_unitary_type: tff_atomic_type  */
#line 638 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_unitary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4189 "y.tab.c"
    break;

  case 211: /* tff_unitary_type: LPAREN tff_xprod_type RPAREN  */
#line 639 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("tff_unitary_type", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4195 "y.tab.c"
    break;

  case 212: /* tff_atomic_type: type_constant  */
#line 642 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4201 "y.tab.c"
    break;

  case 213: /* tff_atomic_type: defined_type  */
#line 643 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4207 "y.tab.c"
    break;

  case 214: /* tff_atomic_type: variable  */
#line 644 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4213 "y.tab.c"
    break;

  case 215: /* tff_atomic_type: type_functor LPAREN tff_type_arguments RPAREN  */
#line 645 "SyntaxBNF.y"
                                                                    {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4219 "y.tab.c"
    break;

  case 216: /* tff_atomic_type: LPAREN tff_atomic_type RPAREN  */
#line 646 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("tff_atomic_type", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4225 "y.tab.c"
    break;

  case 217: /* tff_atomic_type: txf_tuple_type  */
#line 647 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4231 "y.tab.c"
    break;

  case 218: /* tff_type_arguments: tff_atomic_type  */
#line 650 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_type_arguments", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4237 "y.tab.c"
    break;

  case 219: /* tff_type_arguments: tff_atomic_type COMMA tff_type_arguments  */
#line 651 "SyntaxBNF.y"
                                                               {(yyval.pval) = P_BUILD("tff_type_arguments", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4243 "y.tab.c"
    break;

  case 220: /* tff_mapping_type: tff_unitary_type arrow tff_atomic_type  */
#line 654 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("tff_mapping_type", (yyvsp[-2].pval), P_TOKEN("arrow ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4249 "y.tab.c"
    break;

  case 221: /* tff_xprod_type: tff_unitary_type STAR tff_atomic_type  */
#line 657 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("tff_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4255 "y.tab.c"
    break;

  case 222: /* tff_xprod_type: tff_xprod_type STAR tff_atomic_type  */
#line 658 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("tff_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4261 "y.tab.c"
    break;

  case 223: /* txf_tuple_type: LBRKT tff_type_list RBRKT  */
#line 661 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("txf_tuple_type", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4267 "y.tab.c"
    break;

  case 224: /* tff_type_list: tff_top_level_type  */
#line 664 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_type_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4273 "y.tab.c"
    break;

  case 225: /* tff_type_list: tff_top_level_type COMMA tff_type_list  */
#line 665 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("tff_type_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4279 "y.tab.c"
    break;

  case 226: /* tff_subtype: untyped_atom subtype_sign atom  */
#line 668 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("tff_subtype", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4285 "y.tab.c"
    break;

  case 227: /* txf_definition: tff_atomic_formula identical tff_term  */
#line 671 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("txf_definition", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4291 "y.tab.c"
    break;

  case 228: /* txf_sequent: txf_tuple gentzen_arrow txf_tuple  */
#line 674 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("txf_sequent", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4297 "y.tab.c"
    break;

  case 229: /* nhf_long_connective: LBRACE ntf_connective_name RBRACE  */
#line 677 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("nhf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4303 "y.tab.c"
    break;

  case 230: /* nhf_long_connective: LBRACE ntf_connective_name LPAREN nhf_parameter_list RPAREN RBRACE  */
#line 678 "SyntaxBNF.y"
                                                                                         {(yyval.pval) = P_BUILD("nhf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-5].ival)), (yyvsp[-4].pval), P_TOKEN("LPAREN ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL);}
#line 4309 "y.tab.c"
    break;

  case 231: /* nhf_parameter_list: nhf_parameter  */
#line 681 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("nhf_parameter_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4315 "y.tab.c"
    break;

  case 232: /* nhf_parameter_list: nhf_parameter COMMA nhf_parameter_list  */
#line 682 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("nhf_parameter_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4321 "y.tab.c"
    break;

  case 233: /* nhf_parameter: ntf_index  */
#line 685 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("nhf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4327 "y.tab.c"
    break;

  case 234: /* nhf_parameter: nhf_key_pair  */
#line 686 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("nhf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4333 "y.tab.c"
    break;

  case 235: /* nhf_key_pair: thf_definition  */
#line 689 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("nhf_key_pair", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4339 "y.tab.c"
    break;

  case 236: /* nxf_long_connective: LBRACE ntf_connective_name RBRACE  */
#line 692 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("nxf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4345 "y.tab.c"
    break;

  case 237: /* nxf_long_connective: LBRACE ntf_connective_name LPAREN nxf_parameter_list RPAREN RBRACE  */
#line 693 "SyntaxBNF.y"
                                                                                         {(yyval.pval) = P_BUILD("nxf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-5].ival)), (yyvsp[-4].pval), P_TOKEN("LPAREN ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL);}
#line 4351 "y.tab.c"
    break;

  case 238: /* nxf_parameter_list: nxf_parameter  */
#line 696 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("nxf_parameter_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4357 "y.tab.c"
    break;

  case 239: /* nxf_parameter_list: nxf_parameter COMMA nxf_parameter_list  */
#line 697 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("nxf_parameter_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4363 "y.tab.c"
    break;

  case 240: /* nxf_parameter: ntf_index  */
#line 700 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("nxf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4369 "y.tab.c"
    break;

  case 241: /* nxf_parameter: nxf_key_pair  */
#line 701 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("nxf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4375 "y.tab.c"
    break;

  case 242: /* nxf_key_pair: txf_definition  */
#line 704 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("nxf_key_pair", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4381 "y.tab.c"
    break;

  case 243: /* ntf_connective_name: def_or_sys_constant  */
#line 707 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("ntf_connective_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4387 "y.tab.c"
    break;

  case 244: /* ntf_index: hash tff_unitary_term  */
#line 710 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("ntf_index", P_TOKEN("hash ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4393 "y.tab.c"
    break;

  case 245: /* ntf_short_connective: LBRKT PERIOD RBRKT  */
#line 713 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4399 "y.tab.c"
    break;

  case 246: /* ntf_short_connective: less_sign PERIOD arrow  */
#line 714 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("less_sign ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("arrow ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4405 "y.tab.c"
    break;

  case 247: /* ntf_short_connective: LBRACE PERIOD RBRACE  */
#line 715 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("LBRACE ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4411 "y.tab.c"
    break;

  case 248: /* ntf_short_connective: LPAREN PERIOD RPAREN  */
#line 716 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4417 "y.tab.c"
    break;

  case 249: /* tcf_formula: tcf_logic_formula  */
#line 719 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tcf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4423 "y.tab.c"
    break;

  case 250: /* tcf_formula: tff_atom_typing  */
#line 720 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tcf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4429 "y.tab.c"
    break;

  case 251: /* tcf_logic_formula: tcf_quantified_formula  */
#line 723 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("tcf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4435 "y.tab.c"
    break;

  case 252: /* tcf_logic_formula: cnf_formula  */
#line 724 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tcf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4441 "y.tab.c"
    break;

  case 253: /* tcf_quantified_formula: EXCLAMATION LBRKT tff_variable_list RBRKT COLON tcf_logic_formula  */
#line 727 "SyntaxBNF.y"
                                                                                           {(yyval.pval) = P_BUILD("tcf_quantified_formula", P_TOKEN("EXCLAMATION ", (yyvsp[-5].ival)), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 4447 "y.tab.c"
    break;

  case 254: /* fof_formula: fof_logic_formula  */
#line 730 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("fof_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4453 "y.tab.c"
    break;

  case 255: /* fof_formula: fof_sequent  */
#line 731 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("fof_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4459 "y.tab.c"
    break;

  case 256: /* fof_logic_formula: fof_binary_formula  */
#line 734 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("fof_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4465 "y.tab.c"
    break;

  case 257: /* fof_logic_formula: fof_unary_formula  */
#line 735 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("fof_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4471 "y.tab.c"
    break;

  case 258: /* fof_logic_formula: fof_unitary_formula  */
#line 736 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("fof_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4477 "y.tab.c"
    break;

  case 259: /* fof_binary_formula: fof_binary_nonassoc  */
#line 739 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("fof_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4483 "y.tab.c"
    break;

  case 260: /* fof_binary_formula: fof_binary_assoc  */
#line 740 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("fof_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4489 "y.tab.c"
    break;

  case 261: /* fof_binary_nonassoc: fof_unit_formula nonassoc_connective fof_unit_formula  */
#line 743 "SyntaxBNF.y"
                                                                            {(yyval.pval) = P_BUILD("fof_binary_nonassoc", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4495 "y.tab.c"
    break;

  case 262: /* fof_binary_assoc: fof_or_formula  */
#line 746 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("fof_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4501 "y.tab.c"
    break;

  case 263: /* fof_binary_assoc: fof_and_formula  */
#line 747 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("fof_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4507 "y.tab.c"
    break;

  case 264: /* fof_or_formula: fof_unit_formula VLINE fof_unit_formula  */
#line 750 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("fof_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4513 "y.tab.c"
    break;

  case 265: /* fof_or_formula: fof_or_formula VLINE fof_unit_formula  */
#line 751 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("fof_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4519 "y.tab.c"
    break;

  case 266: /* fof_and_formula: fof_unit_formula AMPERSAND fof_unit_formula  */
#line 754 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("fof_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4525 "y.tab.c"
    break;

  case 267: /* fof_and_formula: fof_and_formula AMPERSAND fof_unit_formula  */
#line 755 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("fof_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4531 "y.tab.c"
    break;

  case 268: /* fof_unary_formula: unary_connective fof_unit_formula  */
#line 758 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("fof_unary_formula", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4537 "y.tab.c"
    break;

  case 269: /* fof_unary_formula: fof_infix_unary  */
#line 759 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("fof_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4543 "y.tab.c"
    break;

  case 270: /* fof_infix_unary: fof_term infix_inequality fof_term  */
#line 762 "SyntaxBNF.y"
                                                     {(yyval.pval) = P_BUILD("fof_infix_unary", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4549 "y.tab.c"
    break;

  case 271: /* fof_unit_formula: fof_unitary_formula  */
#line 765 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("fof_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4555 "y.tab.c"
    break;

  case 272: /* fof_unit_formula: fof_unary_formula  */
#line 766 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("fof_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4561 "y.tab.c"
    break;

  case 273: /* fof_unitary_formula: fof_quantified_formula  */
#line 769 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("fof_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4567 "y.tab.c"
    break;

  case 274: /* fof_unitary_formula: fof_atomic_formula  */
#line 770 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("fof_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4573 "y.tab.c"
    break;

  case 275: /* fof_unitary_formula: LPAREN fof_logic_formula RPAREN  */
#line 771 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("fof_unitary_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4579 "y.tab.c"
    break;

  case 276: /* fof_quantified_formula: fof_quantifier LBRKT fof_variable_list RBRKT COLON fof_unit_formula  */
#line 774 "SyntaxBNF.y"
                                                                                             {(yyval.pval) = P_BUILD("fof_quantified_formula", (yyvsp[-5].pval), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 4585 "y.tab.c"
    break;

  case 277: /* fof_variable_list: variable  */
#line 777 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("fof_variable_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4591 "y.tab.c"
    break;

  case 278: /* fof_variable_list: variable COMMA fof_variable_list  */
#line 778 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("fof_variable_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4597 "y.tab.c"
    break;

  case 279: /* fof_atomic_formula: fof_plain_atomic_formula  */
#line 781 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("fof_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4603 "y.tab.c"
    break;

  case 280: /* fof_atomic_formula: fof_defined_atomic_formula  */
#line 782 "SyntaxBNF.y"
                                                 {(yyval.pval) = P_BUILD("fof_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4609 "y.tab.c"
    break;

  case 281: /* fof_atomic_formula: fof_system_atomic_formula  */
#line 783 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("fof_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4615 "y.tab.c"
    break;

  case 282: /* fof_plain_atomic_formula: fof_plain_term  */
#line 786 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("fof_plain_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4621 "y.tab.c"
    break;

  case 283: /* fof_defined_atomic_formula: fof_defined_plain_formula  */
#line 789 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("fof_defined_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4627 "y.tab.c"
    break;

  case 284: /* fof_defined_atomic_formula: fof_defined_infix_formula  */
#line 790 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("fof_defined_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4633 "y.tab.c"
    break;

  case 285: /* fof_defined_plain_formula: fof_defined_plain_term  */
#line 793 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("fof_defined_plain_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4639 "y.tab.c"
    break;

  case 286: /* fof_defined_infix_formula: fof_term defined_infix_pred fof_term  */
#line 796 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("fof_defined_infix_formula", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4645 "y.tab.c"
    break;

  case 287: /* fof_system_atomic_formula: fof_system_term  */
#line 799 "SyntaxBNF.y"
                                            {(yyval.pval) = P_BUILD("fof_system_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4651 "y.tab.c"
    break;

  case 288: /* fof_plain_term: constant  */
#line 802 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("fof_plain_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4657 "y.tab.c"
    break;

  case 289: /* fof_plain_term: functor LPAREN fof_arguments RPAREN  */
#line 803 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("fof_plain_term", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4663 "y.tab.c"
    break;

  case 290: /* fof_defined_term: defined_term  */
#line 806 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("fof_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4669 "y.tab.c"
    break;

  case 291: /* fof_defined_term: fof_defined_atomic_term  */
#line 807 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("fof_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4675 "y.tab.c"
    break;

  case 292: /* fof_defined_atomic_term: fof_defined_plain_term  */
#line 810 "SyntaxBNF.y"
                                                 {(yyval.pval) = P_BUILD("fof_defined_atomic_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4681 "y.tab.c"
    break;

  case 293: /* fof_defined_plain_term: defined_constant  */
#line 813 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("fof_defined_plain_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4687 "y.tab.c"
    break;

  case 294: /* fof_defined_plain_term: defined_functor LPAREN fof_arguments RPAREN  */
#line 814 "SyntaxBNF.y"
                                                                  {(yyval.pval) = P_BUILD("fof_defined_plain_term", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4693 "y.tab.c"
    break;

  case 295: /* fof_system_term: system_constant  */
#line 817 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("fof_system_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4699 "y.tab.c"
    break;

  case 296: /* fof_system_term: system_functor LPAREN fof_arguments RPAREN  */
#line 818 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("fof_system_term", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4705 "y.tab.c"
    break;

  case 297: /* fof_arguments: fof_term  */
#line 821 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("fof_arguments", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4711 "y.tab.c"
    break;

  case 298: /* fof_arguments: fof_term COMMA fof_arguments  */
#line 822 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("fof_arguments", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4717 "y.tab.c"
    break;

  case 299: /* fof_term: fof_function_term  */
#line 825 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("fof_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4723 "y.tab.c"
    break;

  case 300: /* fof_term: variable  */
#line 826 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("fof_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4729 "y.tab.c"
    break;

  case 301: /* fof_function_term: fof_plain_term  */
#line 829 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("fof_function_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4735 "y.tab.c"
    break;

  case 302: /* fof_function_term: fof_defined_term  */
#line 830 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("fof_function_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4741 "y.tab.c"
    break;

  case 303: /* fof_function_term: fof_system_term  */
#line 831 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("fof_function_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4747 "y.tab.c"
    break;

  case 304: /* fof_sequent: fof_formula_tuple gentzen_arrow fof_formula_tuple  */
#line 834 "SyntaxBNF.y"
                                                                {(yyval.pval) = P_BUILD("fof_sequent", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4753 "y.tab.c"
    break;

  case 305: /* fof_sequent: LPAREN fof_sequent RPAREN  */
#line 835 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("fof_sequent", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4759 "y.tab.c"
    break;

  case 306: /* fof_formula_tuple: LBRKT RBRKT  */
#line 838 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("fof_formula_tuple", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4765 "y.tab.c"
    break;

  case 307: /* fof_formula_tuple: LBRKT fof_formula_tuple_list RBRKT  */
#line 839 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("fof_formula_tuple", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4771 "y.tab.c"
    break;

  case 308: /* fof_formula_tuple_list: fof_logic_formula  */
#line 842 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("fof_formula_tuple_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4777 "y.tab.c"
    break;

  case 309: /* fof_formula_tuple_list: fof_logic_formula COMMA fof_formula_tuple_list  */
#line 843 "SyntaxBNF.y"
                                                                     {(yyval.pval) = P_BUILD("fof_formula_tuple_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4783 "y.tab.c"
    break;

  case 310: /* cnf_formula: cnf_disjunction  */
#line 846 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("cnf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4789 "y.tab.c"
    break;

  case 311: /* cnf_formula: LPAREN cnf_formula RPAREN  */
#line 847 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("cnf_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4795 "y.tab.c"
    break;

  case 312: /* cnf_disjunction: cnf_literal  */
#line 850 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("cnf_disjunction", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4801 "y.tab.c"
    break;

  case 313: /* cnf_disjunction: cnf_disjunction VLINE cnf_literal  */
#line 851 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("cnf_disjunction", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4807 "y.tab.c"
    break;

  case 314: /* cnf_literal: fof_atomic_formula  */
#line 854 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("cnf_literal", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4813 "y.tab.c"
    break;

  case 315: /* cnf_literal: TILDE fof_atomic_formula  */
#line 855 "SyntaxBNF.y"
                                               {(yyval.pval) = P_BUILD("cnf_literal", P_TOKEN("TILDE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4819 "y.tab.c"
    break;

  case 316: /* cnf_literal: TILDE LPAREN fof_atomic_formula RPAREN  */
#line 856 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("cnf_literal", P_TOKEN("TILDE ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4825 "y.tab.c"
    break;

  case 317: /* cnf_literal: fof_infix_unary  */
#line 857 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("cnf_literal", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4831 "y.tab.c"
    break;

  case 318: /* thf_quantifier: fof_quantifier  */
#line 860 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4837 "y.tab.c"
    break;

  case 319: /* thf_quantifier: th0_quantifier  */
#line 861 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4843 "y.tab.c"
    break;

  case 320: /* thf_quantifier: th1_quantifier  */
#line 862 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4849 "y.tab.c"
    break;

  case 321: /* thf_unary_connective: unary_connective  */
#line 865 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4855 "y.tab.c"
    break;

  case 322: /* thf_unary_connective: ntf_short_connective  */
#line 866 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("thf_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4861 "y.tab.c"
    break;

  case 323: /* th1_quantifier: EXCLAMATION_GREATER  */
#line 869 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("th1_quantifier", P_TOKEN("EXCLAMATION_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4867 "y.tab.c"
    break;

  case 324: /* th1_quantifier: QUESTION_STAR  */
#line 870 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("th1_quantifier", P_TOKEN("QUESTION_STAR ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4873 "y.tab.c"
    break;

  case 325: /* th0_quantifier: CARET  */
#line 873 "SyntaxBNF.y"
                       {(yyval.pval) = P_BUILD("th0_quantifier", P_TOKEN("CARET ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4879 "y.tab.c"
    break;

  case 326: /* th0_quantifier: AT_SIGN_PLUS  */
#line 874 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("th0_quantifier", P_TOKEN("AT_SIGN_PLUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4885 "y.tab.c"
    break;

  case 327: /* th0_quantifier: AT_SIGN_MINUS  */
#line 875 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("th0_quantifier", P_TOKEN("AT_SIGN_MINUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4891 "y.tab.c"
    break;

  case 328: /* subtype_sign: LESS_LESS  */
#line 878 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("subtype_sign", P_TOKEN("LESS_LESS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4897 "y.tab.c"
    break;

  case 329: /* tff_unary_connective: unary_connective  */
#line 881 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4903 "y.tab.c"
    break;

  case 330: /* tff_unary_connective: ntf_short_connective  */
#line 882 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("tff_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4909 "y.tab.c"
    break;

  case 331: /* tff_quantifier: fof_quantifier  */
#line 885 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4915 "y.tab.c"
    break;

  case 332: /* fof_quantifier: EXCLAMATION  */
#line 888 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("fof_quantifier", P_TOKEN("EXCLAMATION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4921 "y.tab.c"
    break;

  case 333: /* fof_quantifier: QUESTION  */
#line 889 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("fof_quantifier", P_TOKEN("QUESTION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4927 "y.tab.c"
    break;

  case 334: /* fof_quantifier: hash  */
#line 890 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("fof_quantifier", P_TOKEN("hash ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4933 "y.tab.c"
    break;

  case 335: /* nonassoc_connective: LESS_EQUALS_GREATER  */
#line 893 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("LESS_EQUALS_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4939 "y.tab.c"
    break;

  case 336: /* nonassoc_connective: EQUALS_GREATER  */
#line 894 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("EQUALS_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4945 "y.tab.c"
    break;

  case 337: /* nonassoc_connective: LESS_EQUALS  */
#line 895 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("LESS_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4951 "y.tab.c"
    break;

  case 338: /* nonassoc_connective: LESS_TILDE_GREATER  */
#line 896 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("LESS_TILDE_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4957 "y.tab.c"
    break;

  case 339: /* nonassoc_connective: TILDE_VLINE  */
#line 897 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("TILDE_VLINE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4963 "y.tab.c"
    break;

  case 340: /* nonassoc_connective: TILDE_AMPERSAND  */
#line 898 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("TILDE_AMPERSAND ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4969 "y.tab.c"
    break;

  case 341: /* assoc_connective: VLINE  */
#line 901 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("assoc_connective", P_TOKEN("VLINE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4975 "y.tab.c"
    break;

  case 342: /* assoc_connective: AMPERSAND  */
#line 902 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("assoc_connective", P_TOKEN("AMPERSAND ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4981 "y.tab.c"
    break;

  case 343: /* unary_connective: TILDE  */
#line 905 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("unary_connective", P_TOKEN("TILDE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4987 "y.tab.c"
    break;

  case 344: /* gentzen_arrow: MINUS_MINUS_GREATER  */
#line 908 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("gentzen_arrow", P_TOKEN("MINUS_MINUS_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4993 "y.tab.c"
    break;

  case 345: /* assignment: COLON_EQUALS  */
#line 911 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("assignment", P_TOKEN("COLON_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4999 "y.tab.c"
    break;

  case 346: /* identical: EQUALS_EQUALS  */
#line 914 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("identical", P_TOKEN("EQUALS_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5005 "y.tab.c"
    break;

  case 347: /* type_constant: type_functor  */
#line 917 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("type_constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5011 "y.tab.c"
    break;

  case 348: /* type_functor: atomic_word  */
#line 920 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("type_functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5017 "y.tab.c"
    break;

  case 349: /* defined_type: atomic_defined_word  */
#line 923 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("defined_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5023 "y.tab.c"
    break;

  case 350: /* atom: untyped_atom  */
#line 926 "SyntaxBNF.y"
                    {(yyval.pval) = P_BUILD("atom", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5029 "y.tab.c"
    break;

  case 351: /* atom: defined_constant  */
#line 927 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("atom", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5035 "y.tab.c"
    break;

  case 352: /* untyped_atom: constant  */
#line 930 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("untyped_atom", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5041 "y.tab.c"
    break;

  case 353: /* untyped_atom: system_constant  */
#line 931 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("untyped_atom", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5047 "y.tab.c"
    break;

  case 354: /* defined_infix_pred: infix_equality  */
#line 934 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("defined_infix_pred", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5053 "y.tab.c"
    break;

  case 355: /* infix_equality: EQUALS  */
#line 937 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("infix_equality", P_TOKEN("EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5059 "y.tab.c"
    break;

  case 356: /* infix_inequality: EXCLAMATION_EQUALS  */
#line 940 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("infix_inequality", P_TOKEN("EXCLAMATION_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5065 "y.tab.c"
    break;

  case 357: /* constant: functor  */
#line 943 "SyntaxBNF.y"
                   {(yyval.pval) = P_BUILD("constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5071 "y.tab.c"
    break;

  case 358: /* functor: atomic_word  */
#line 946 "SyntaxBNF.y"
                      {(yyval.pval) = P_BUILD("functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5077 "y.tab.c"
    break;

  case 359: /* defined_constant: defined_functor  */
#line 949 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("defined_constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5083 "y.tab.c"
    break;

  case 360: /* defined_functor: atomic_defined_word  */
#line 952 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("defined_functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5089 "y.tab.c"
    break;

  case 361: /* system_constant: system_functor  */
#line 955 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("system_constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5095 "y.tab.c"
    break;

  case 362: /* system_functor: atomic_system_word  */
#line 958 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("system_functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5101 "y.tab.c"
    break;

  case 363: /* def_or_sys_constant: defined_constant  */
#line 961 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("def_or_sys_constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5107 "y.tab.c"
    break;

  case 364: /* def_or_sys_constant: system_constant  */
#line 962 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("def_or_sys_constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5113 "y.tab.c"
    break;

  case 365: /* th1_defined_term: EXCLAMATION_EXCLAMATION  */
#line 965 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("EXCLAMATION_EXCLAMATION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5119 "y.tab.c"
    break;

  case 366: /* th1_defined_term: QUESTION_QUESTION  */
#line 966 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("QUESTION_QUESTION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5125 "y.tab.c"
    break;

  case 367: /* th1_defined_term: AT_AT_SIGN_PLUS  */
#line 967 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("AT_AT_SIGN_PLUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5131 "y.tab.c"
    break;

  case 368: /* th1_defined_term: AT_AT_SIGN_MINUS  */
#line 968 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("AT_AT_SIGN_MINUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5137 "y.tab.c"
    break;

  case 369: /* th1_defined_term: AT_SIGN_EQUALS  */
#line 969 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("AT_SIGN_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5143 "y.tab.c"
    break;

  case 370: /* defined_term: number  */
#line 972 "SyntaxBNF.y"
                      {(yyval.pval) = P_BUILD("defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5149 "y.tab.c"
    break;

  case 371: /* defined_term: distinct_object  */
#line 973 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("defined_term", P_TOKEN("distinct_object ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5155 "y.tab.c"
    break;

  case 372: /* variable: upper_word  */
#line 976 "SyntaxBNF.y"
                      {(yyval.pval) = P_BUILD("variable", P_TOKEN("upper_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5161 "y.tab.c"
    break;

  case 373: /* source: dag_source  */
#line 979 "SyntaxBNF.y"
                    {(yyval.pval) = P_BUILD("source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5167 "y.tab.c"
    break;

  case 374: /* source: internal_source  */
#line 980 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5173 "y.tab.c"
    break;

  case 375: /* source: external_source  */
#line 981 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5179 "y.tab.c"
    break;

  case 376: /* source: _LIT_unknown  */
#line 982 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("source", P_TOKEN("_LIT_unknown ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5185 "y.tab.c"
    break;

  case 377: /* source: LBRKT sources RBRKT  */
#line 983 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("source", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5191 "y.tab.c"
    break;

  case 378: /* sources: source  */
#line 986 "SyntaxBNF.y"
                 {(yyval.pval) = P_BUILD("sources", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5197 "y.tab.c"
    break;

  case 379: /* sources: source COMMA sources  */
#line 987 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("sources", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5203 "y.tab.c"
    break;

  case 380: /* dag_source: name  */
#line 990 "SyntaxBNF.y"
                  {(yyval.pval) = P_BUILD("dag_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5209 "y.tab.c"
    break;

  case 381: /* dag_source: inference_record  */
#line 991 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("dag_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5215 "y.tab.c"
    break;

  case 382: /* inference_record: _LIT_inference LPAREN inference_rule COMMA useful_info COMMA parents RPAREN  */
#line 994 "SyntaxBNF.y"
                                                                                               {(yyval.pval) = P_BUILD("inference_record", P_TOKEN("_LIT_inference ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 5221 "y.tab.c"
    break;

  case 383: /* inference_rule: atomic_word  */
#line 997 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("inference_rule", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5227 "y.tab.c"
    break;

  case 384: /* internal_source: _LIT_introduced LPAREN intro_type COMMA useful_info COMMA parents RPAREN  */
#line 1000 "SyntaxBNF.y"
                                                                                           {(yyval.pval) = P_BUILD("internal_source", P_TOKEN("_LIT_introduced ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 5233 "y.tab.c"
    break;

  case 385: /* intro_type: atomic_word  */
#line 1003 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("intro_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5239 "y.tab.c"
    break;

  case 386: /* external_source: file_source  */
#line 1006 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("external_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5245 "y.tab.c"
    break;

  case 387: /* external_source: theory  */
#line 1007 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("external_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5251 "y.tab.c"
    break;

  case 388: /* external_source: creator_source  */
#line 1008 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("external_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5257 "y.tab.c"
    break;

  case 389: /* file_source: _LIT_file LPAREN file_name file_info RPAREN  */
#line 1011 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("file_source", P_TOKEN("_LIT_file ", (yyvsp[-4].ival)), P_TOKEN("LPAREN ", (yyvsp[-3].ival)), (yyvsp[-2].pval), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL);}
#line 5263 "y.tab.c"
    break;

  case 390: /* file_info: COMMA name  */
#line 1014 "SyntaxBNF.y"
                       {(yyval.pval) = P_BUILD("file_info", P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5269 "y.tab.c"
    break;

  case 391: /* file_info: nothing  */
#line 1015 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("file_info", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5275 "y.tab.c"
    break;

  case 392: /* theory: _LIT_theory LPAREN theory_name optional_info RPAREN  */
#line 1018 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("theory", P_TOKEN("_LIT_theory ", (yyvsp[-4].ival)), P_TOKEN("LPAREN ", (yyvsp[-3].ival)), (yyvsp[-2].pval), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL);}
#line 5281 "y.tab.c"
    break;

  case 393: /* theory_name: atomic_word  */
#line 1021 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("theory_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5287 "y.tab.c"
    break;

  case 394: /* creator_source: _LIT_creator LPAREN creator_name COMMA useful_info COMMA parents RPAREN  */
#line 1024 "SyntaxBNF.y"
                                                                                         {(yyval.pval) = P_BUILD("creator_source", P_TOKEN("_LIT_creator ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 5293 "y.tab.c"
    break;

  case 395: /* creator_name: atomic_word  */
#line 1027 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("creator_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5299 "y.tab.c"
    break;

  case 396: /* parents: LBRKT RBRKT  */
#line 1030 "SyntaxBNF.y"
                      {(yyval.pval) = P_BUILD("parents", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5305 "y.tab.c"
    break;

  case 397: /* parents: LBRKT parent_list RBRKT  */
#line 1031 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("parents", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5311 "y.tab.c"
    break;

  case 398: /* parent_list: parent_info  */
#line 1034 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("parent_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5317 "y.tab.c"
    break;

  case 399: /* parent_list: parent_info COMMA parent_list  */
#line 1035 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("parent_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5323 "y.tab.c"
    break;

  case 400: /* parent_info: source parent_details  */
#line 1038 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("parent_info", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5329 "y.tab.c"
    break;

  case 401: /* parent_details: COLON general_list  */
#line 1041 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("parent_details", P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5335 "y.tab.c"
    break;

  case 402: /* parent_details: nothing  */
#line 1042 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("parent_details", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5341 "y.tab.c"
    break;

  case 403: /* optional_info: COMMA useful_info  */
#line 1045 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("optional_info", P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5347 "y.tab.c"
    break;

  case 404: /* optional_info: nothing  */
#line 1046 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("optional_info", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5353 "y.tab.c"
    break;

  case 405: /* useful_info: general_list  */
#line 1049 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("useful_info", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5359 "y.tab.c"
    break;

  case 406: /* include: _LIT_include LPAREN file_name include_optionals RPAREN PERIOD  */
#line 1052 "SyntaxBNF.y"
                                                                        {(yyval.pval) = P_BUILD("include", P_TOKEN("_LIT_include ", (yyvsp[-5].ival)), P_TOKEN("LPAREN ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL);}
#line 5365 "y.tab.c"
    break;

  case 407: /* include_optionals: nothing  */
#line 1055 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("include_optionals", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5371 "y.tab.c"
    break;

  case 408: /* include_optionals: COMMA formula_selection  */
#line 1056 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("include_optionals", P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5377 "y.tab.c"
    break;

  case 409: /* include_optionals: COMMA formula_selection COMMA space_name  */
#line 1057 "SyntaxBNF.y"
                                                               {(yyval.pval) = P_BUILD("include_optionals", P_TOKEN("COMMA ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5383 "y.tab.c"
    break;

  case 410: /* formula_selection: LBRKT name_list RBRKT  */
#line 1060 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("formula_selection", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5389 "y.tab.c"
    break;

  case 411: /* formula_selection: STAR  */
#line 1061 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("formula_selection", P_TOKEN("STAR ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5395 "y.tab.c"
    break;

  case 412: /* name_list: name  */
#line 1064 "SyntaxBNF.y"
                 {(yyval.pval) = P_BUILD("name_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5401 "y.tab.c"
    break;

  case 413: /* name_list: name COMMA name_list  */
#line 1065 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("name_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5407 "y.tab.c"
    break;

  case 414: /* space_name: name  */
#line 1068 "SyntaxBNF.y"
                  {(yyval.pval) = P_BUILD("space_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5413 "y.tab.c"
    break;

  case 415: /* general_term: general_data  */
#line 1071 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("general_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5419 "y.tab.c"
    break;

  case 416: /* general_term: general_data COLON general_term  */
#line 1072 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("general_term", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5425 "y.tab.c"
    break;

  case 417: /* general_term: general_list  */
#line 1073 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("general_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5431 "y.tab.c"
    break;

  case 418: /* general_data: atomic_word  */
#line 1076 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5437 "y.tab.c"
    break;

  case 419: /* general_data: general_function  */
#line 1077 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5443 "y.tab.c"
    break;

  case 420: /* general_data: variable  */
#line 1078 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5449 "y.tab.c"
    break;

  case 421: /* general_data: number  */
#line 1079 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5455 "y.tab.c"
    break;

  case 422: /* general_data: distinct_object  */
#line 1080 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("general_data", P_TOKEN("distinct_object ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5461 "y.tab.c"
    break;

  case 423: /* general_data: formula_data  */
#line 1081 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5467 "y.tab.c"
    break;

  case 424: /* general_function: atomic_word LPAREN general_terms RPAREN  */
#line 1084 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("general_function", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5473 "y.tab.c"
    break;

  case 425: /* formula_data: _DLR_thf LPAREN thf_formula RPAREN  */
#line 1087 "SyntaxBNF.y"
                                                  {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_thf ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5479 "y.tab.c"
    break;

  case 426: /* formula_data: _DLR_tff LPAREN tff_formula RPAREN  */
#line 1088 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_tff ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5485 "y.tab.c"
    break;

  case 427: /* formula_data: _DLR_fof LPAREN fof_formula RPAREN  */
#line 1089 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_fof ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5491 "y.tab.c"
    break;

  case 428: /* formula_data: _DLR_cnf LPAREN cnf_formula RPAREN  */
#line 1090 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_cnf ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5497 "y.tab.c"
    break;

  case 429: /* formula_data: _DLR_fot LPAREN fof_term RPAREN  */
#line 1091 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_fot ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5503 "y.tab.c"
    break;

  case 430: /* general_list: LBRKT RBRKT  */
#line 1094 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("general_list", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5509 "y.tab.c"
    break;

  case 431: /* general_list: LBRKT general_terms RBRKT  */
#line 1095 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("general_list", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5515 "y.tab.c"
    break;

  case 432: /* general_terms: general_term  */
#line 1098 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("general_terms", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5521 "y.tab.c"
    break;

  case 433: /* general_terms: general_term COMMA general_terms  */
#line 1099 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("general_terms", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5527 "y.tab.c"
    break;

  case 434: /* name: atomic_word  */
#line 1102 "SyntaxBNF.y"
                   {(yyval.pval) = P_BUILD("name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5533 "y.tab.c"
    break;

  case 435: /* name: integer  */
#line 1103 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("name", P_TOKEN("integer ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5539 "y.tab.c"
    break;

  case 436: /* atomic_word: lower_word  */
#line 1106 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("atomic_word", P_TOKEN("lower_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5545 "y.tab.c"
    break;

  case 437: /* atomic_word: single_quoted  */
#line 1107 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("atomic_word", P_TOKEN("single_quoted ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5551 "y.tab.c"
    break;

  case 438: /* atomic_defined_word: dollar_word  */
#line 1110 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("atomic_defined_word", P_TOKEN("dollar_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5557 "y.tab.c"
    break;

  case 439: /* atomic_system_word: dollar_dollar_word  */
#line 1113 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("atomic_system_word", P_TOKEN("dollar_dollar_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5563 "y.tab.c"
    break;

  case 440: /* number: integer  */
#line 1116 "SyntaxBNF.y"
                 {(yyval.pval) = P_BUILD("number", P_TOKEN("integer ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5569 "y.tab.c"
    break;

  case 441: /* number: rational  */
#line 1117 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("number", P_TOKEN("rational ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5575 "y.tab.c"
    break;

  case 442: /* number: real  */
#line 1118 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("number", P_TOKEN("real ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5581 "y.tab.c"
    break;

  case 443: /* file_name: atomic_word  */
#line 1121 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("file_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5587 "y.tab.c"
    break;

  case 444: /* nothing: %empty  */
#line 1124 "SyntaxBNF.y"
          {(yyval.pval) = P_BUILD("nothing",NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5593 "y.tab.c"
    break;


#line 5597 "y.tab.c"

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

