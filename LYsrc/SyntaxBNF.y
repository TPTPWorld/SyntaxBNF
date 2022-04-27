
%{
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
%}

%union {int ival; double dval; char* sval; void* pval;}
%start  TPTP_file
%token <ival> AMPERSAND
%token <ival> AT_AT_SIGN_MINUS
%token <ival> AT_AT_SIGN_PLUS
%token <ival> AT_SIGN
%token <ival> AT_SIGN_EQUALS
%token <ival> AT_SIGN_MINUS
%token <ival> AT_SIGN_PLUS
%token <ival> CARET
%token <ival> COLON
%token <ival> COLON_EQUALS
%token <ival> COMMA
%token <ival> EQUALS
%token <ival> EQUALS_EQUALS
%token <ival> EQUALS_GREATER
%token <ival> EXCLAMATION
%token <ival> EXCLAMATION_EQUALS
%token <ival> EXCLAMATION_EXCLAMATION
%token <ival> EXCLAMATION_GREATER
%token <ival> LBRACE
%token <ival> LBRKT
%token <ival> LESS_EQUALS
%token <ival> LESS_EQUALS_GREATER
%token <ival> LESS_LESS
%token <ival> LESS_TILDE_GREATER
%token <ival> LPAREN
%token <ival> MINUS
%token <ival> MINUS_MINUS_GREATER
%token <ival> PERIOD
%token <ival> QUESTION
%token <ival> QUESTION_QUESTION
%token <ival> QUESTION_STAR
%token <ival> RBRACE
%token <ival> RBRKT
%token <ival> RPAREN
%token <ival> STAR
%token <ival> TILDE
%token <ival> TILDE_AMPERSAND
%token <ival> TILDE_VLINE
%token <ival> VLINE
%token <ival> _DLR_cnf
%token <ival> _DLR_fof
%token <ival> _DLR_fot
%token <ival> _DLR_let
%token <ival> _DLR_tff
%token <ival> _DLR_thf
%token <ival> _LIT_cnf
%token <ival> _LIT_fof
%token <ival> _LIT_include
%token <ival> _LIT_tcf
%token <ival> _LIT_tff
%token <ival> _LIT_thf
%token <ival> _LIT_tpi
%token <ival> arrow
%token <ival> decimal
%token <ival> decimal_exponent
%token <ival> decimal_fraction
%token <ival> distinct_object
%token <ival> dollar_dollar_word
%token <ival> dollar_word
%token <ival> dot_decimal
%token <ival> exp_integer
%token <ival> hash
%token <ival> integer
%token <ival> less_sign
%token <ival> lower_word
%token <ival> plus
%token <ival> positive_decimal
%token <ival> rational
%token <ival> real
%token <ival> signed_exp_integer
%token <ival> signed_integer
%token <ival> signed_rational
%token <ival> signed_real
%token <ival> single_quoted
%token <ival> slash
%token <ival> slosh
%token <ival> star
%token <ival> unrecognized
%token <ival> unsigned_exp_integer
%token <ival> unsigned_integer
%token <ival> unsigned_rational
%token <ival> unsigned_real
%token <ival> upper_word
%token <ival> vline
%%

TPTP_file : null {}
                    | TPTP_file TPTP_input {}
                    ;

TPTP_input : annotated_formula {P_PRINT($<pval>$);}
                    | include {P_PRINT($<pval>$);}
                    ;

annotated_formula : thf_annotated {$<pval>$ = P_BUILD("annotated_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tff_annotated {$<pval>$ = P_BUILD("annotated_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tcf_annotated {$<pval>$ = P_BUILD("annotated_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | fof_annotated {$<pval>$ = P_BUILD("annotated_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | cnf_annotated {$<pval>$ = P_BUILD("annotated_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tpi_annotated {$<pval>$ = P_BUILD("annotated_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tpi_annotated : _LIT_tpi LPAREN name COMMA formula_role COMMA tpi_formula annotations RPAREN PERIOD {$<pval>$ = P_BUILD("tpi_annotated", P_TOKEN("_LIT_tpi ", $<ival>1), P_TOKEN("LPAREN ", $<ival>2), $<pval>3, P_TOKEN("COMMA ", $<ival>4), $<pval>5, P_TOKEN("COMMA ", $<ival>6), $<pval>7, $<pval>8, P_TOKEN("RPAREN ", $<ival>9), P_TOKEN("PERIOD ", $<ival>10));}
                    ;

tpi_formula : fof_formula {$<pval>$ = P_BUILD("tpi_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_annotated : _LIT_thf LPAREN name COMMA formula_role COMMA thf_formula annotations RPAREN PERIOD {$<pval>$ = P_BUILD("thf_annotated", P_TOKEN("_LIT_thf ", $<ival>1), P_TOKEN("LPAREN ", $<ival>2), $<pval>3, P_TOKEN("COMMA ", $<ival>4), $<pval>5, P_TOKEN("COMMA ", $<ival>6), $<pval>7, $<pval>8, P_TOKEN("RPAREN ", $<ival>9), P_TOKEN("PERIOD ", $<ival>10));}
                    ;

tff_annotated : _LIT_tff LPAREN name COMMA formula_role COMMA tff_formula annotations RPAREN PERIOD {$<pval>$ = P_BUILD("tff_annotated", P_TOKEN("_LIT_tff ", $<ival>1), P_TOKEN("LPAREN ", $<ival>2), $<pval>3, P_TOKEN("COMMA ", $<ival>4), $<pval>5, P_TOKEN("COMMA ", $<ival>6), $<pval>7, $<pval>8, P_TOKEN("RPAREN ", $<ival>9), P_TOKEN("PERIOD ", $<ival>10));}
                    ;

tcf_annotated : _LIT_tcf LPAREN name COMMA formula_role COMMA tcf_formula annotations RPAREN PERIOD {$<pval>$ = P_BUILD("tcf_annotated", P_TOKEN("_LIT_tcf ", $<ival>1), P_TOKEN("LPAREN ", $<ival>2), $<pval>3, P_TOKEN("COMMA ", $<ival>4), $<pval>5, P_TOKEN("COMMA ", $<ival>6), $<pval>7, $<pval>8, P_TOKEN("RPAREN ", $<ival>9), P_TOKEN("PERIOD ", $<ival>10));}
                    ;

fof_annotated : _LIT_fof LPAREN name COMMA formula_role COMMA fof_formula annotations RPAREN PERIOD {$<pval>$ = P_BUILD("fof_annotated", P_TOKEN("_LIT_fof ", $<ival>1), P_TOKEN("LPAREN ", $<ival>2), $<pval>3, P_TOKEN("COMMA ", $<ival>4), $<pval>5, P_TOKEN("COMMA ", $<ival>6), $<pval>7, $<pval>8, P_TOKEN("RPAREN ", $<ival>9), P_TOKEN("PERIOD ", $<ival>10));}
                    ;

cnf_annotated : _LIT_cnf LPAREN name COMMA formula_role COMMA cnf_formula annotations RPAREN PERIOD {$<pval>$ = P_BUILD("cnf_annotated", P_TOKEN("_LIT_cnf ", $<ival>1), P_TOKEN("LPAREN ", $<ival>2), $<pval>3, P_TOKEN("COMMA ", $<ival>4), $<pval>5, P_TOKEN("COMMA ", $<ival>6), $<pval>7, $<pval>8, P_TOKEN("RPAREN ", $<ival>9), P_TOKEN("PERIOD ", $<ival>10));}
                    ;

annotations : COMMA source optional_info {$<pval>$ = P_BUILD("annotations", P_TOKEN("COMMA ", $<ival>1), $<pval>2, $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | null {$<pval>$ = P_BUILD("annotations", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

formula_role : lower_word {$<pval>$ = P_BUILD("formula_role", P_TOKEN("lower_word ", $<ival>1),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | lower_word MINUS general_term {$<pval>$ = P_BUILD("formula_role", P_TOKEN("lower_word ", $<ival>1), P_TOKEN("MINUS ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_formula : thf_logic_formula {$<pval>$ = P_BUILD("thf_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | thf_atom_typing {$<pval>$ = P_BUILD("thf_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | thf_subtype {$<pval>$ = P_BUILD("thf_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_logic_formula : thf_unitary_formula {$<pval>$ = P_BUILD("thf_logic_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | thf_unary_formula {$<pval>$ = P_BUILD("thf_logic_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | thf_binary_formula {$<pval>$ = P_BUILD("thf_logic_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | thf_defined_infix {$<pval>$ = P_BUILD("thf_logic_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | thf_definition {$<pval>$ = P_BUILD("thf_logic_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | thf_sequent {$<pval>$ = P_BUILD("thf_logic_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_binary_formula : thf_binary_nonassoc {$<pval>$ = P_BUILD("thf_binary_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | thf_binary_assoc {$<pval>$ = P_BUILD("thf_binary_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | thf_binary_type {$<pval>$ = P_BUILD("thf_binary_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_binary_nonassoc : thf_unit_formula nonassoc_connective thf_unit_formula {$<pval>$ = P_BUILD("thf_binary_nonassoc", $<pval>1, $<pval>2, $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_binary_assoc : thf_or_formula {$<pval>$ = P_BUILD("thf_binary_assoc", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | thf_and_formula {$<pval>$ = P_BUILD("thf_binary_assoc", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | thf_apply_formula {$<pval>$ = P_BUILD("thf_binary_assoc", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_or_formula : thf_unit_formula VLINE thf_unit_formula {$<pval>$ = P_BUILD("thf_or_formula", $<pval>1, P_TOKEN("VLINE ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | thf_or_formula VLINE thf_unit_formula {$<pval>$ = P_BUILD("thf_or_formula", $<pval>1, P_TOKEN("VLINE ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_and_formula : thf_unit_formula AMPERSAND thf_unit_formula {$<pval>$ = P_BUILD("thf_and_formula", $<pval>1, P_TOKEN("AMPERSAND ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | thf_and_formula AMPERSAND thf_unit_formula {$<pval>$ = P_BUILD("thf_and_formula", $<pval>1, P_TOKEN("AMPERSAND ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_apply_formula : thf_unit_formula AT_SIGN thf_unit_formula {$<pval>$ = P_BUILD("thf_apply_formula", $<pval>1, P_TOKEN("AT_SIGN ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | thf_apply_formula AT_SIGN thf_unit_formula {$<pval>$ = P_BUILD("thf_apply_formula", $<pval>1, P_TOKEN("AT_SIGN ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_unit_formula : thf_unitary_formula {$<pval>$ = P_BUILD("thf_unit_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | thf_unary_formula {$<pval>$ = P_BUILD("thf_unit_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | thf_defined_infix {$<pval>$ = P_BUILD("thf_unit_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_preunit_formula : thf_unitary_formula {$<pval>$ = P_BUILD("thf_preunit_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | thf_prefix_unary {$<pval>$ = P_BUILD("thf_preunit_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_unitary_formula : thf_quantified_formula {$<pval>$ = P_BUILD("thf_unitary_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | thf_atomic_formula {$<pval>$ = P_BUILD("thf_unitary_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | variable {$<pval>$ = P_BUILD("thf_unitary_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | LPAREN thf_logic_formula RPAREN {$<pval>$ = P_BUILD("thf_unitary_formula", P_TOKEN("LPAREN ", $<ival>1), $<pval>2, P_TOKEN("RPAREN ", $<ival>3),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_quantified_formula : thf_quantification thf_unit_formula {$<pval>$ = P_BUILD("thf_quantified_formula", $<pval>1, $<pval>2,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_quantification : thf_quantifier LBRKT thf_variable_list RBRKT COLON {$<pval>$ = P_BUILD("thf_quantification", $<pval>1, P_TOKEN("LBRKT ", $<ival>2), $<pval>3, P_TOKEN("RBRKT ", $<ival>4), P_TOKEN("COLON ", $<ival>5),NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_variable_list : thf_typed_variable {$<pval>$ = P_BUILD("thf_variable_list", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | thf_typed_variable COMMA thf_variable_list {$<pval>$ = P_BUILD("thf_variable_list", $<pval>1, P_TOKEN("COMMA ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_typed_variable : variable COLON thf_top_level_type {$<pval>$ = P_BUILD("thf_typed_variable", $<pval>1, P_TOKEN("COLON ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_unary_formula : thf_prefix_unary {$<pval>$ = P_BUILD("thf_unary_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | thf_infix_unary {$<pval>$ = P_BUILD("thf_unary_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_prefix_unary : unary_connective thf_preunit_formula {$<pval>$ = P_BUILD("thf_prefix_unary", $<pval>1, $<pval>2,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_infix_unary : thf_unitary_term infix_inequality thf_unitary_term {$<pval>$ = P_BUILD("thf_infix_unary", $<pval>1, $<pval>2, $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_atomic_formula : thf_plain_atomic {$<pval>$ = P_BUILD("thf_atomic_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | thf_defined_atomic {$<pval>$ = P_BUILD("thf_atomic_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | thf_system_atomic {$<pval>$ = P_BUILD("thf_atomic_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | thf_fof_function {$<pval>$ = P_BUILD("thf_atomic_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_plain_atomic : constant {$<pval>$ = P_BUILD("thf_plain_atomic", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | thf_tuple {$<pval>$ = P_BUILD("thf_plain_atomic", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_defined_atomic : defined_constant {$<pval>$ = P_BUILD("thf_defined_atomic", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | thf_defined_term {$<pval>$ = P_BUILD("thf_defined_atomic", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | LPAREN thf_conn_term RPAREN {$<pval>$ = P_BUILD("thf_defined_atomic", P_TOKEN("LPAREN ", $<ival>1), $<pval>2, P_TOKEN("RPAREN ", $<ival>3),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tnc_connective {$<pval>$ = P_BUILD("thf_defined_atomic", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | thf_let {$<pval>$ = P_BUILD("thf_defined_atomic", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_defined_term : defined_term {$<pval>$ = P_BUILD("thf_defined_term", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | th1_defined_term {$<pval>$ = P_BUILD("thf_defined_term", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_defined_infix : thf_unitary_term defined_infix_pred thf_unitary_term {$<pval>$ = P_BUILD("thf_defined_infix", $<pval>1, $<pval>2, $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_system_atomic : system_constant {$<pval>$ = P_BUILD("thf_system_atomic", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_let : _DLR_let LPAREN thf_let_types COMMA thf_let_defns COMMA thf_logic_formula RPAREN {$<pval>$ = P_BUILD("thf_let", P_TOKEN("_DLR_let ", $<ival>1), P_TOKEN("LPAREN ", $<ival>2), $<pval>3, P_TOKEN("COMMA ", $<ival>4), $<pval>5, P_TOKEN("COMMA ", $<ival>6), $<pval>7, P_TOKEN("RPAREN ", $<ival>8),NULL,NULL);}
                    ;

thf_let_types : thf_atom_typing {$<pval>$ = P_BUILD("thf_let_types", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | LBRKT thf_atom_typing_list RBRKT {$<pval>$ = P_BUILD("thf_let_types", P_TOKEN("LBRKT ", $<ival>1), $<pval>2, P_TOKEN("RBRKT ", $<ival>3),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_atom_typing_list : thf_atom_typing {$<pval>$ = P_BUILD("thf_atom_typing_list", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | thf_atom_typing COMMA thf_atom_typing_list {$<pval>$ = P_BUILD("thf_atom_typing_list", $<pval>1, P_TOKEN("COMMA ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_let_defns : thf_let_defn {$<pval>$ = P_BUILD("thf_let_defns", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | LBRKT thf_let_defn_list RBRKT {$<pval>$ = P_BUILD("thf_let_defns", P_TOKEN("LBRKT ", $<ival>1), $<pval>2, P_TOKEN("RBRKT ", $<ival>3),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_let_defn : thf_logic_formula assignment thf_logic_formula {$<pval>$ = P_BUILD("thf_let_defn", $<pval>1, $<pval>2, $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_let_defn_list : thf_let_defn {$<pval>$ = P_BUILD("thf_let_defn_list", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | thf_let_defn COMMA thf_let_defn_list {$<pval>$ = P_BUILD("thf_let_defn_list", $<pval>1, P_TOKEN("COMMA ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_unitary_term : thf_atomic_formula {$<pval>$ = P_BUILD("thf_unitary_term", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | variable {$<pval>$ = P_BUILD("thf_unitary_term", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | LPAREN thf_logic_formula RPAREN {$<pval>$ = P_BUILD("thf_unitary_term", P_TOKEN("LPAREN ", $<ival>1), $<pval>2, P_TOKEN("RPAREN ", $<ival>3),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_conn_term : nonassoc_connective {$<pval>$ = P_BUILD("thf_conn_term", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | assoc_connective {$<pval>$ = P_BUILD("thf_conn_term", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | infix_equality {$<pval>$ = P_BUILD("thf_conn_term", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | infix_inequality {$<pval>$ = P_BUILD("thf_conn_term", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | unary_connective {$<pval>$ = P_BUILD("thf_conn_term", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_tuple : LBRKT RBRKT {$<pval>$ = P_BUILD("thf_tuple", P_TOKEN("LBRKT ", $<ival>1), P_TOKEN("RBRKT ", $<ival>2),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | LBRKT thf_formula_list RBRKT {$<pval>$ = P_BUILD("thf_tuple", P_TOKEN("LBRKT ", $<ival>1), $<pval>2, P_TOKEN("RBRKT ", $<ival>3),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_fof_function : functor LPAREN thf_arguments RPAREN {$<pval>$ = P_BUILD("thf_fof_function", $<pval>1, P_TOKEN("LPAREN ", $<ival>2), $<pval>3, P_TOKEN("RPAREN ", $<ival>4),NULL,NULL,NULL,NULL,NULL,NULL);}
                    | defined_functor LPAREN thf_arguments RPAREN {$<pval>$ = P_BUILD("thf_fof_function", $<pval>1, P_TOKEN("LPAREN ", $<ival>2), $<pval>3, P_TOKEN("RPAREN ", $<ival>4),NULL,NULL,NULL,NULL,NULL,NULL);}
                    | system_functor LPAREN thf_arguments RPAREN {$<pval>$ = P_BUILD("thf_fof_function", $<pval>1, P_TOKEN("LPAREN ", $<ival>2), $<pval>3, P_TOKEN("RPAREN ", $<ival>4),NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_arguments : thf_formula_list {$<pval>$ = P_BUILD("thf_arguments", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_formula_list : thf_logic_formula {$<pval>$ = P_BUILD("thf_formula_list", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | thf_logic_formula COMMA thf_formula_list {$<pval>$ = P_BUILD("thf_formula_list", $<pval>1, P_TOKEN("COMMA ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_atom_typing : untyped_atom COLON thf_top_level_type {$<pval>$ = P_BUILD("thf_atom_typing", $<pval>1, P_TOKEN("COLON ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | LPAREN thf_atom_typing RPAREN {$<pval>$ = P_BUILD("thf_atom_typing", P_TOKEN("LPAREN ", $<ival>1), $<pval>2, P_TOKEN("RPAREN ", $<ival>3),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_top_level_type : thf_unitary_type {$<pval>$ = P_BUILD("thf_top_level_type", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | thf_mapping_type {$<pval>$ = P_BUILD("thf_top_level_type", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | thf_apply_type {$<pval>$ = P_BUILD("thf_top_level_type", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_unitary_type : thf_unitary_formula {$<pval>$ = P_BUILD("thf_unitary_type", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_apply_type : thf_apply_formula {$<pval>$ = P_BUILD("thf_apply_type", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_binary_type : thf_mapping_type {$<pval>$ = P_BUILD("thf_binary_type", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | thf_xprod_type {$<pval>$ = P_BUILD("thf_binary_type", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | thf_union_type {$<pval>$ = P_BUILD("thf_binary_type", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_mapping_type : thf_unitary_type arrow thf_unitary_type {$<pval>$ = P_BUILD("thf_mapping_type", $<pval>1, P_TOKEN("arrow ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | thf_unitary_type arrow thf_mapping_type {$<pval>$ = P_BUILD("thf_mapping_type", $<pval>1, P_TOKEN("arrow ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_xprod_type : thf_unitary_type STAR thf_unitary_type {$<pval>$ = P_BUILD("thf_xprod_type", $<pval>1, P_TOKEN("STAR ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | thf_xprod_type STAR thf_unitary_type {$<pval>$ = P_BUILD("thf_xprod_type", $<pval>1, P_TOKEN("STAR ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_union_type : thf_unitary_type plus thf_unitary_type {$<pval>$ = P_BUILD("thf_union_type", $<pval>1, P_TOKEN("plus ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | thf_union_type plus thf_unitary_type {$<pval>$ = P_BUILD("thf_union_type", $<pval>1, P_TOKEN("plus ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_subtype : untyped_atom subtype_sign atom {$<pval>$ = P_BUILD("thf_subtype", $<pval>1, $<pval>2, $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_definition : thf_atomic_formula identical thf_logic_formula {$<pval>$ = P_BUILD("thf_definition", $<pval>1, $<pval>2, $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_sequent : thf_tuple gentzen_arrow thf_tuple {$<pval>$ = P_BUILD("thf_sequent", $<pval>1, $<pval>2, $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tff_formula : tff_logic_formula {$<pval>$ = P_BUILD("tff_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tff_atom_typing {$<pval>$ = P_BUILD("tff_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tff_subtype {$<pval>$ = P_BUILD("tff_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tff_logic_formula : tff_unitary_formula {$<pval>$ = P_BUILD("tff_logic_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tff_unary_formula {$<pval>$ = P_BUILD("tff_logic_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tff_binary_formula {$<pval>$ = P_BUILD("tff_logic_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tff_defined_infix {$<pval>$ = P_BUILD("tff_logic_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tfx_definition {$<pval>$ = P_BUILD("tff_logic_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tfx_sequent {$<pval>$ = P_BUILD("tff_logic_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tff_binary_formula : tff_binary_nonassoc {$<pval>$ = P_BUILD("tff_binary_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tff_binary_assoc {$<pval>$ = P_BUILD("tff_binary_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tff_binary_nonassoc : tff_unit_formula nonassoc_connective tff_unit_formula {$<pval>$ = P_BUILD("tff_binary_nonassoc", $<pval>1, $<pval>2, $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tff_binary_assoc : tff_or_formula {$<pval>$ = P_BUILD("tff_binary_assoc", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tff_and_formula {$<pval>$ = P_BUILD("tff_binary_assoc", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tff_or_formula : tff_unit_formula VLINE tff_unit_formula {$<pval>$ = P_BUILD("tff_or_formula", $<pval>1, P_TOKEN("VLINE ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tff_or_formula VLINE tff_unit_formula {$<pval>$ = P_BUILD("tff_or_formula", $<pval>1, P_TOKEN("VLINE ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tff_and_formula : tff_unit_formula AMPERSAND tff_unit_formula {$<pval>$ = P_BUILD("tff_and_formula", $<pval>1, P_TOKEN("AMPERSAND ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tff_and_formula AMPERSAND tff_unit_formula {$<pval>$ = P_BUILD("tff_and_formula", $<pval>1, P_TOKEN("AMPERSAND ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tff_unit_formula : tff_unitary_formula {$<pval>$ = P_BUILD("tff_unit_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tff_unary_formula {$<pval>$ = P_BUILD("tff_unit_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tff_defined_infix {$<pval>$ = P_BUILD("tff_unit_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tff_preunit_formula : tff_unitary_formula {$<pval>$ = P_BUILD("tff_preunit_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tff_prefix_unary {$<pval>$ = P_BUILD("tff_preunit_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tff_unitary_formula : tff_quantified_formula {$<pval>$ = P_BUILD("tff_unitary_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tff_atomic_formula {$<pval>$ = P_BUILD("tff_unitary_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tfx_unitary_formula {$<pval>$ = P_BUILD("tff_unitary_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | LPAREN tff_logic_formula RPAREN {$<pval>$ = P_BUILD("tff_unitary_formula", P_TOKEN("LPAREN ", $<ival>1), $<pval>2, P_TOKEN("RPAREN ", $<ival>3),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tfx_unitary_formula : variable {$<pval>$ = P_BUILD("tfx_unitary_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tff_quantified_formula : fof_quantifier LBRKT tff_variable_list RBRKT COLON tff_unit_formula {$<pval>$ = P_BUILD("tff_quantified_formula", $<pval>1, P_TOKEN("LBRKT ", $<ival>2), $<pval>3, P_TOKEN("RBRKT ", $<ival>4), P_TOKEN("COLON ", $<ival>5), $<pval>6,NULL,NULL,NULL,NULL);}
                    ;

tff_variable_list : tff_variable {$<pval>$ = P_BUILD("tff_variable_list", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tff_variable COMMA tff_variable_list {$<pval>$ = P_BUILD("tff_variable_list", $<pval>1, P_TOKEN("COMMA ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tff_variable : tff_typed_variable {$<pval>$ = P_BUILD("tff_variable", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | variable {$<pval>$ = P_BUILD("tff_variable", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tff_typed_variable : variable COLON tff_atomic_type {$<pval>$ = P_BUILD("tff_typed_variable", $<pval>1, P_TOKEN("COLON ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tff_unary_formula : tff_prefix_unary {$<pval>$ = P_BUILD("tff_unary_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tff_infix_unary {$<pval>$ = P_BUILD("tff_unary_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tff_prefix_unary : unary_connective tff_preunit_formula {$<pval>$ = P_BUILD("tff_prefix_unary", $<pval>1, $<pval>2,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tff_infix_unary : tff_unitary_term infix_inequality tff_unitary_term {$<pval>$ = P_BUILD("tff_infix_unary", $<pval>1, $<pval>2, $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tff_atomic_formula : tff_plain_atomic {$<pval>$ = P_BUILD("tff_atomic_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tff_defined_atomic {$<pval>$ = P_BUILD("tff_atomic_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tff_system_atomic {$<pval>$ = P_BUILD("tff_atomic_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tff_plain_atomic : constant {$<pval>$ = P_BUILD("tff_plain_atomic", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | functor LPAREN tff_arguments RPAREN {$<pval>$ = P_BUILD("tff_plain_atomic", $<pval>1, P_TOKEN("LPAREN ", $<ival>2), $<pval>3, P_TOKEN("RPAREN ", $<ival>4),NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tff_defined_atomic : tff_defined_plain {$<pval>$ = P_BUILD("tff_defined_atomic", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tnc_connective {$<pval>$ = P_BUILD("tff_defined_atomic", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tff_defined_plain : defined_constant {$<pval>$ = P_BUILD("tff_defined_plain", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | defined_functor LPAREN tff_arguments RPAREN {$<pval>$ = P_BUILD("tff_defined_plain", $<pval>1, P_TOKEN("LPAREN ", $<ival>2), $<pval>3, P_TOKEN("RPAREN ", $<ival>4),NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tfx_tnc_atom {$<pval>$ = P_BUILD("tff_defined_plain", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tfx_let {$<pval>$ = P_BUILD("tff_defined_plain", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tff_defined_infix : tff_unitary_term defined_infix_pred tff_unitary_term {$<pval>$ = P_BUILD("tff_defined_infix", $<pval>1, $<pval>2, $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tff_system_atomic : system_constant {$<pval>$ = P_BUILD("tff_system_atomic", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | system_functor LPAREN tff_arguments RPAREN {$<pval>$ = P_BUILD("tff_system_atomic", $<pval>1, P_TOKEN("LPAREN ", $<ival>2), $<pval>3, P_TOKEN("RPAREN ", $<ival>4),NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tfx_let : _DLR_let LPAREN tfx_let_types COMMA tfx_let_defns COMMA tff_term RPAREN {$<pval>$ = P_BUILD("tfx_let", P_TOKEN("_DLR_let ", $<ival>1), P_TOKEN("LPAREN ", $<ival>2), $<pval>3, P_TOKEN("COMMA ", $<ival>4), $<pval>5, P_TOKEN("COMMA ", $<ival>6), $<pval>7, P_TOKEN("RPAREN ", $<ival>8),NULL,NULL);}
                    ;

tfx_let_types : tff_atom_typing {$<pval>$ = P_BUILD("tfx_let_types", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | LBRKT tff_atom_typing_list RBRKT {$<pval>$ = P_BUILD("tfx_let_types", P_TOKEN("LBRKT ", $<ival>1), $<pval>2, P_TOKEN("RBRKT ", $<ival>3),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tff_atom_typing_list : tff_atom_typing {$<pval>$ = P_BUILD("tff_atom_typing_list", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tff_atom_typing COMMA tff_atom_typing_list {$<pval>$ = P_BUILD("tff_atom_typing_list", $<pval>1, P_TOKEN("COMMA ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tfx_let_defns : tfx_let_defn {$<pval>$ = P_BUILD("tfx_let_defns", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | LBRKT tfx_let_defn_list RBRKT {$<pval>$ = P_BUILD("tfx_let_defns", P_TOKEN("LBRKT ", $<ival>1), $<pval>2, P_TOKEN("RBRKT ", $<ival>3),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tfx_let_defn : tfx_let_LHS assignment tff_term {$<pval>$ = P_BUILD("tfx_let_defn", $<pval>1, $<pval>2, $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tfx_let_LHS : tff_plain_atomic {$<pval>$ = P_BUILD("tfx_let_LHS", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tfx_tuple {$<pval>$ = P_BUILD("tfx_let_LHS", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tfx_let_defn_list : tfx_let_defn {$<pval>$ = P_BUILD("tfx_let_defn_list", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tfx_let_defn COMMA tfx_let_defn_list {$<pval>$ = P_BUILD("tfx_let_defn_list", $<pval>1, P_TOKEN("COMMA ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tfx_tnc_atom : tnc_connective LPAREN tff_arguments RPAREN {$<pval>$ = P_BUILD("tfx_tnc_atom", $<pval>1, P_TOKEN("LPAREN ", $<ival>2), $<pval>3, P_TOKEN("RPAREN ", $<ival>4),NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tff_term : tff_logic_formula {$<pval>$ = P_BUILD("tff_term", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | defined_term {$<pval>$ = P_BUILD("tff_term", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tfx_tuple {$<pval>$ = P_BUILD("tff_term", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tnc_key_pair {$<pval>$ = P_BUILD("tff_term", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tff_unitary_term : tff_atomic_formula {$<pval>$ = P_BUILD("tff_unitary_term", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | defined_term {$<pval>$ = P_BUILD("tff_unitary_term", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tfx_tuple {$<pval>$ = P_BUILD("tff_unitary_term", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | variable {$<pval>$ = P_BUILD("tff_unitary_term", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | LPAREN tff_logic_formula RPAREN {$<pval>$ = P_BUILD("tff_unitary_term", P_TOKEN("LPAREN ", $<ival>1), $<pval>2, P_TOKEN("RPAREN ", $<ival>3),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tfx_tuple : LBRKT RBRKT {$<pval>$ = P_BUILD("tfx_tuple", P_TOKEN("LBRKT ", $<ival>1), P_TOKEN("RBRKT ", $<ival>2),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | LBRKT tff_arguments RBRKT {$<pval>$ = P_BUILD("tfx_tuple", P_TOKEN("LBRKT ", $<ival>1), $<pval>2, P_TOKEN("RBRKT ", $<ival>3),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tff_arguments : tff_term {$<pval>$ = P_BUILD("tff_arguments", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tff_term COMMA tff_arguments {$<pval>$ = P_BUILD("tff_arguments", $<pval>1, P_TOKEN("COMMA ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tff_atom_typing : untyped_atom COLON tff_top_level_type {$<pval>$ = P_BUILD("tff_atom_typing", $<pval>1, P_TOKEN("COLON ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | LPAREN tff_atom_typing RPAREN {$<pval>$ = P_BUILD("tff_atom_typing", P_TOKEN("LPAREN ", $<ival>1), $<pval>2, P_TOKEN("RPAREN ", $<ival>3),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tff_top_level_type : tff_atomic_type {$<pval>$ = P_BUILD("tff_top_level_type", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tff_non_atomic_type {$<pval>$ = P_BUILD("tff_top_level_type", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tff_non_atomic_type : tff_mapping_type {$<pval>$ = P_BUILD("tff_non_atomic_type", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tf1_quantified_type {$<pval>$ = P_BUILD("tff_non_atomic_type", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | LPAREN tff_non_atomic_type RPAREN {$<pval>$ = P_BUILD("tff_non_atomic_type", P_TOKEN("LPAREN ", $<ival>1), $<pval>2, P_TOKEN("RPAREN ", $<ival>3),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tf1_quantified_type : EXCLAMATION_GREATER LBRKT tff_variable_list RBRKT COLON tff_monotype {$<pval>$ = P_BUILD("tf1_quantified_type", P_TOKEN("EXCLAMATION_GREATER ", $<ival>1), P_TOKEN("LBRKT ", $<ival>2), $<pval>3, P_TOKEN("RBRKT ", $<ival>4), P_TOKEN("COLON ", $<ival>5), $<pval>6,NULL,NULL,NULL,NULL);}
                    ;

tff_monotype : tff_atomic_type {$<pval>$ = P_BUILD("tff_monotype", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | LPAREN tff_mapping_type RPAREN {$<pval>$ = P_BUILD("tff_monotype", P_TOKEN("LPAREN ", $<ival>1), $<pval>2, P_TOKEN("RPAREN ", $<ival>3),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tf1_quantified_type {$<pval>$ = P_BUILD("tff_monotype", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tff_unitary_type : tff_atomic_type {$<pval>$ = P_BUILD("tff_unitary_type", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | LPAREN tff_xprod_type RPAREN {$<pval>$ = P_BUILD("tff_unitary_type", P_TOKEN("LPAREN ", $<ival>1), $<pval>2, P_TOKEN("RPAREN ", $<ival>3),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tff_atomic_type : type_constant {$<pval>$ = P_BUILD("tff_atomic_type", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | defined_type {$<pval>$ = P_BUILD("tff_atomic_type", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | variable {$<pval>$ = P_BUILD("tff_atomic_type", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | type_functor LPAREN tff_type_arguments RPAREN {$<pval>$ = P_BUILD("tff_atomic_type", $<pval>1, P_TOKEN("LPAREN ", $<ival>2), $<pval>3, P_TOKEN("RPAREN ", $<ival>4),NULL,NULL,NULL,NULL,NULL,NULL);}
                    | LPAREN tff_atomic_type RPAREN {$<pval>$ = P_BUILD("tff_atomic_type", P_TOKEN("LPAREN ", $<ival>1), $<pval>2, P_TOKEN("RPAREN ", $<ival>3),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tfx_tuple_type {$<pval>$ = P_BUILD("tff_atomic_type", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tff_type_arguments : tff_atomic_type {$<pval>$ = P_BUILD("tff_type_arguments", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tff_atomic_type COMMA tff_type_arguments {$<pval>$ = P_BUILD("tff_type_arguments", $<pval>1, P_TOKEN("COMMA ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tff_mapping_type : tff_unitary_type arrow tff_atomic_type {$<pval>$ = P_BUILD("tff_mapping_type", $<pval>1, P_TOKEN("arrow ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tff_xprod_type : tff_unitary_type STAR tff_atomic_type {$<pval>$ = P_BUILD("tff_xprod_type", $<pval>1, P_TOKEN("STAR ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tff_xprod_type STAR tff_atomic_type {$<pval>$ = P_BUILD("tff_xprod_type", $<pval>1, P_TOKEN("STAR ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tfx_tuple_type : LBRKT tff_type_list RBRKT {$<pval>$ = P_BUILD("tfx_tuple_type", P_TOKEN("LBRKT ", $<ival>1), $<pval>2, P_TOKEN("RBRKT ", $<ival>3),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tff_type_list : tff_top_level_type {$<pval>$ = P_BUILD("tff_type_list", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tff_top_level_type COMMA tff_type_list {$<pval>$ = P_BUILD("tff_type_list", $<pval>1, P_TOKEN("COMMA ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tff_subtype : untyped_atom subtype_sign atom {$<pval>$ = P_BUILD("tff_subtype", $<pval>1, $<pval>2, $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tfx_definition : tff_atomic_formula identical tff_term {$<pval>$ = P_BUILD("tfx_definition", $<pval>1, $<pval>2, $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tfx_sequent : tfx_tuple gentzen_arrow tfx_tuple {$<pval>$ = P_BUILD("tfx_sequent", $<pval>1, $<pval>2, $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tnc_connective : tnc_short_connective {$<pval>$ = P_BUILD("tnc_connective", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tnc_long_connective {$<pval>$ = P_BUILD("tnc_connective", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tnc_short_connective : LBRKT PERIOD RBRKT {$<pval>$ = P_BUILD("tnc_short_connective", P_TOKEN("LBRKT ", $<ival>1), P_TOKEN("PERIOD ", $<ival>2), P_TOKEN("RBRKT ", $<ival>3),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | less_sign PERIOD arrow {$<pval>$ = P_BUILD("tnc_short_connective", P_TOKEN("less_sign ", $<ival>1), P_TOKEN("PERIOD ", $<ival>2), P_TOKEN("arrow ", $<ival>3),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | LBRACE PERIOD RBRACE {$<pval>$ = P_BUILD("tnc_short_connective", P_TOKEN("LBRACE ", $<ival>1), P_TOKEN("PERIOD ", $<ival>2), P_TOKEN("RBRACE ", $<ival>3),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | LBRKT tnc_index RBRKT {$<pval>$ = P_BUILD("tnc_short_connective", P_TOKEN("LBRKT ", $<ival>1), $<pval>2, P_TOKEN("RBRKT ", $<ival>3),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | less_sign tnc_index arrow {$<pval>$ = P_BUILD("tnc_short_connective", P_TOKEN("less_sign ", $<ival>1), $<pval>2, P_TOKEN("arrow ", $<ival>3),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | LBRACE tnc_index RBRACE {$<pval>$ = P_BUILD("tnc_short_connective", P_TOKEN("LBRACE ", $<ival>1), $<pval>2, P_TOKEN("RBRACE ", $<ival>3),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tnc_long_connective : LBRACE tnc_connective_name RBRACE {$<pval>$ = P_BUILD("tnc_long_connective", P_TOKEN("LBRACE ", $<ival>1), $<pval>2, P_TOKEN("RBRACE ", $<ival>3),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | LBRACE tnc_connective_name LPAREN tnc_parameter_list RPAREN RBRACE {$<pval>$ = P_BUILD("tnc_long_connective", P_TOKEN("LBRACE ", $<ival>1), $<pval>2, P_TOKEN("LPAREN ", $<ival>3), $<pval>4, P_TOKEN("RPAREN ", $<ival>5), P_TOKEN("RBRACE ", $<ival>6),NULL,NULL,NULL,NULL);}
                    ;

tnc_connective_name : def_or_sys_constant {$<pval>$ = P_BUILD("tnc_connective_name", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tnc_parameter_list : tnc_parameter {$<pval>$ = P_BUILD("tnc_parameter_list", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tnc_parameter COMMA tnc_parameter_list {$<pval>$ = P_BUILD("tnc_parameter_list", $<pval>1, P_TOKEN("COMMA ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tnc_parameter : tnc_index {$<pval>$ = P_BUILD("tnc_parameter", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tnc_key_pair {$<pval>$ = P_BUILD("tnc_parameter", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tnc_index : hash tff_unitary_term {$<pval>$ = P_BUILD("tnc_index", P_TOKEN("hash ", $<ival>1), $<pval>2,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tnc_key_pair : def_or_sys_constant assignment tff_unitary_term {$<pval>$ = P_BUILD("tnc_key_pair", $<pval>1, $<pval>2, $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

logic_defn_rule : logic_defn_LHS identical logic_defn_RHS {$<pval>$ = P_BUILD("logic_defn_rule", $<pval>1, $<pval>2, $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

logic_defn_LHS : defined_constant {$<pval>$ = P_BUILD("logic_defn_LHS", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

logic_defn_RHS : defined_constant {$<pval>$ = P_BUILD("logic_defn_RHS", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tfx_tuple {$<pval>$ = P_BUILD("logic_defn_RHS", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tcf_formula : tcf_logic_formula {$<pval>$ = P_BUILD("tcf_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | tff_atom_typing {$<pval>$ = P_BUILD("tcf_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tcf_logic_formula : tcf_quantified_formula {$<pval>$ = P_BUILD("tcf_logic_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | cnf_formula {$<pval>$ = P_BUILD("tcf_logic_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

tcf_quantified_formula : EXCLAMATION LBRKT tff_variable_list RBRKT COLON cnf_formula {$<pval>$ = P_BUILD("tcf_quantified_formula", P_TOKEN("EXCLAMATION ", $<ival>1), P_TOKEN("LBRKT ", $<ival>2), $<pval>3, P_TOKEN("RBRKT ", $<ival>4), P_TOKEN("COLON ", $<ival>5), $<pval>6,NULL,NULL,NULL,NULL);}
                    ;

fof_formula : fof_logic_formula {$<pval>$ = P_BUILD("fof_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | fof_sequent {$<pval>$ = P_BUILD("fof_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

fof_logic_formula : fof_binary_formula {$<pval>$ = P_BUILD("fof_logic_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | fof_unary_formula {$<pval>$ = P_BUILD("fof_logic_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | fof_unitary_formula {$<pval>$ = P_BUILD("fof_logic_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

fof_binary_formula : fof_binary_nonassoc {$<pval>$ = P_BUILD("fof_binary_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | fof_binary_assoc {$<pval>$ = P_BUILD("fof_binary_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

fof_binary_nonassoc : fof_unit_formula nonassoc_connective fof_unit_formula {$<pval>$ = P_BUILD("fof_binary_nonassoc", $<pval>1, $<pval>2, $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

fof_binary_assoc : fof_or_formula {$<pval>$ = P_BUILD("fof_binary_assoc", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | fof_and_formula {$<pval>$ = P_BUILD("fof_binary_assoc", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

fof_or_formula : fof_unit_formula VLINE fof_unit_formula {$<pval>$ = P_BUILD("fof_or_formula", $<pval>1, P_TOKEN("VLINE ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | fof_or_formula VLINE fof_unit_formula {$<pval>$ = P_BUILD("fof_or_formula", $<pval>1, P_TOKEN("VLINE ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

fof_and_formula : fof_unit_formula AMPERSAND fof_unit_formula {$<pval>$ = P_BUILD("fof_and_formula", $<pval>1, P_TOKEN("AMPERSAND ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | fof_and_formula AMPERSAND fof_unit_formula {$<pval>$ = P_BUILD("fof_and_formula", $<pval>1, P_TOKEN("AMPERSAND ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

fof_unary_formula : unary_connective fof_unit_formula {$<pval>$ = P_BUILD("fof_unary_formula", $<pval>1, $<pval>2,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | fof_infix_unary {$<pval>$ = P_BUILD("fof_unary_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

fof_infix_unary : fof_term infix_inequality fof_term {$<pval>$ = P_BUILD("fof_infix_unary", $<pval>1, $<pval>2, $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

fof_unit_formula : fof_unitary_formula {$<pval>$ = P_BUILD("fof_unit_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | fof_unary_formula {$<pval>$ = P_BUILD("fof_unit_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

fof_unitary_formula : fof_quantified_formula {$<pval>$ = P_BUILD("fof_unitary_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | fof_atomic_formula {$<pval>$ = P_BUILD("fof_unitary_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | LPAREN fof_logic_formula RPAREN {$<pval>$ = P_BUILD("fof_unitary_formula", P_TOKEN("LPAREN ", $<ival>1), $<pval>2, P_TOKEN("RPAREN ", $<ival>3),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

fof_quantified_formula : fof_quantifier LBRKT fof_variable_list RBRKT COLON fof_unit_formula {$<pval>$ = P_BUILD("fof_quantified_formula", $<pval>1, P_TOKEN("LBRKT ", $<ival>2), $<pval>3, P_TOKEN("RBRKT ", $<ival>4), P_TOKEN("COLON ", $<ival>5), $<pval>6,NULL,NULL,NULL,NULL);}
                    ;

fof_variable_list : variable {$<pval>$ = P_BUILD("fof_variable_list", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | variable COMMA fof_variable_list {$<pval>$ = P_BUILD("fof_variable_list", $<pval>1, P_TOKEN("COMMA ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

fof_atomic_formula : fof_plain_atomic_formula {$<pval>$ = P_BUILD("fof_atomic_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | fof_defined_atomic_formula {$<pval>$ = P_BUILD("fof_atomic_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | fof_system_atomic_formula {$<pval>$ = P_BUILD("fof_atomic_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

fof_plain_atomic_formula : fof_plain_term {$<pval>$ = P_BUILD("fof_plain_atomic_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

fof_defined_atomic_formula : fof_defined_plain_formula {$<pval>$ = P_BUILD("fof_defined_atomic_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | fof_defined_infix_formula {$<pval>$ = P_BUILD("fof_defined_atomic_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

fof_defined_plain_formula : fof_defined_plain_term {$<pval>$ = P_BUILD("fof_defined_plain_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

fof_defined_infix_formula : fof_term defined_infix_pred fof_term {$<pval>$ = P_BUILD("fof_defined_infix_formula", $<pval>1, $<pval>2, $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

fof_system_atomic_formula : fof_system_term {$<pval>$ = P_BUILD("fof_system_atomic_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

fof_plain_term : constant {$<pval>$ = P_BUILD("fof_plain_term", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | functor LPAREN fof_arguments RPAREN {$<pval>$ = P_BUILD("fof_plain_term", $<pval>1, P_TOKEN("LPAREN ", $<ival>2), $<pval>3, P_TOKEN("RPAREN ", $<ival>4),NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

fof_defined_term : defined_term {$<pval>$ = P_BUILD("fof_defined_term", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | fof_defined_atomic_term {$<pval>$ = P_BUILD("fof_defined_term", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

fof_defined_atomic_term : fof_defined_plain_term {$<pval>$ = P_BUILD("fof_defined_atomic_term", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

fof_defined_plain_term : defined_constant {$<pval>$ = P_BUILD("fof_defined_plain_term", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | defined_functor LPAREN fof_arguments RPAREN {$<pval>$ = P_BUILD("fof_defined_plain_term", $<pval>1, P_TOKEN("LPAREN ", $<ival>2), $<pval>3, P_TOKEN("RPAREN ", $<ival>4),NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

fof_system_term : system_constant {$<pval>$ = P_BUILD("fof_system_term", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | system_functor LPAREN fof_arguments RPAREN {$<pval>$ = P_BUILD("fof_system_term", $<pval>1, P_TOKEN("LPAREN ", $<ival>2), $<pval>3, P_TOKEN("RPAREN ", $<ival>4),NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

fof_arguments : fof_term {$<pval>$ = P_BUILD("fof_arguments", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | fof_term COMMA fof_arguments {$<pval>$ = P_BUILD("fof_arguments", $<pval>1, P_TOKEN("COMMA ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

fof_term : fof_function_term {$<pval>$ = P_BUILD("fof_term", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | variable {$<pval>$ = P_BUILD("fof_term", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

fof_function_term : fof_plain_term {$<pval>$ = P_BUILD("fof_function_term", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | fof_defined_term {$<pval>$ = P_BUILD("fof_function_term", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | fof_system_term {$<pval>$ = P_BUILD("fof_function_term", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

fof_sequent : fof_formula_tuple gentzen_arrow fof_formula_tuple {$<pval>$ = P_BUILD("fof_sequent", $<pval>1, $<pval>2, $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | LPAREN fof_sequent RPAREN {$<pval>$ = P_BUILD("fof_sequent", P_TOKEN("LPAREN ", $<ival>1), $<pval>2, P_TOKEN("RPAREN ", $<ival>3),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

fof_formula_tuple : LBRACE RBRACE {$<pval>$ = P_BUILD("fof_formula_tuple", P_TOKEN("LBRACE ", $<ival>1), P_TOKEN("RBRACE ", $<ival>2),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | LBRACE fof_formula_tuple_list RBRACE {$<pval>$ = P_BUILD("fof_formula_tuple", P_TOKEN("LBRACE ", $<ival>1), $<pval>2, P_TOKEN("RBRACE ", $<ival>3),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

fof_formula_tuple_list : fof_logic_formula {$<pval>$ = P_BUILD("fof_formula_tuple_list", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | fof_logic_formula COMMA fof_formula_tuple_list {$<pval>$ = P_BUILD("fof_formula_tuple_list", $<pval>1, P_TOKEN("COMMA ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

cnf_formula : disjunction {$<pval>$ = P_BUILD("cnf_formula", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | LPAREN disjunction RPAREN {$<pval>$ = P_BUILD("cnf_formula", P_TOKEN("LPAREN ", $<ival>1), $<pval>2, P_TOKEN("RPAREN ", $<ival>3),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

disjunction : literal {$<pval>$ = P_BUILD("disjunction", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | disjunction VLINE literal {$<pval>$ = P_BUILD("disjunction", $<pval>1, P_TOKEN("VLINE ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

literal : fof_atomic_formula {$<pval>$ = P_BUILD("literal", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | TILDE fof_atomic_formula {$<pval>$ = P_BUILD("literal", P_TOKEN("TILDE ", $<ival>1), $<pval>2,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | fof_infix_unary {$<pval>$ = P_BUILD("literal", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

thf_quantifier : fof_quantifier {$<pval>$ = P_BUILD("thf_quantifier", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | th0_quantifier {$<pval>$ = P_BUILD("thf_quantifier", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | th1_quantifier {$<pval>$ = P_BUILD("thf_quantifier", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

th1_quantifier : EXCLAMATION_GREATER {$<pval>$ = P_BUILD("th1_quantifier", P_TOKEN("EXCLAMATION_GREATER ", $<ival>1),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | QUESTION_STAR {$<pval>$ = P_BUILD("th1_quantifier", P_TOKEN("QUESTION_STAR ", $<ival>1),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

th0_quantifier : CARET {$<pval>$ = P_BUILD("th0_quantifier", P_TOKEN("CARET ", $<ival>1),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | AT_SIGN_PLUS {$<pval>$ = P_BUILD("th0_quantifier", P_TOKEN("AT_SIGN_PLUS ", $<ival>1),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | AT_SIGN_MINUS {$<pval>$ = P_BUILD("th0_quantifier", P_TOKEN("AT_SIGN_MINUS ", $<ival>1),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

subtype_sign : LESS_LESS {$<pval>$ = P_BUILD("subtype_sign", P_TOKEN("LESS_LESS ", $<ival>1),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

fof_quantifier : EXCLAMATION {$<pval>$ = P_BUILD("fof_quantifier", P_TOKEN("EXCLAMATION ", $<ival>1),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | QUESTION {$<pval>$ = P_BUILD("fof_quantifier", P_TOKEN("QUESTION ", $<ival>1),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

nonassoc_connective : LESS_EQUALS_GREATER {$<pval>$ = P_BUILD("nonassoc_connective", P_TOKEN("LESS_EQUALS_GREATER ", $<ival>1),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | EQUALS_GREATER {$<pval>$ = P_BUILD("nonassoc_connective", P_TOKEN("EQUALS_GREATER ", $<ival>1),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | LESS_EQUALS {$<pval>$ = P_BUILD("nonassoc_connective", P_TOKEN("LESS_EQUALS ", $<ival>1),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | LESS_TILDE_GREATER {$<pval>$ = P_BUILD("nonassoc_connective", P_TOKEN("LESS_TILDE_GREATER ", $<ival>1),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | TILDE_VLINE {$<pval>$ = P_BUILD("nonassoc_connective", P_TOKEN("TILDE_VLINE ", $<ival>1),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | TILDE_AMPERSAND {$<pval>$ = P_BUILD("nonassoc_connective", P_TOKEN("TILDE_AMPERSAND ", $<ival>1),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

assoc_connective : VLINE {$<pval>$ = P_BUILD("assoc_connective", P_TOKEN("VLINE ", $<ival>1),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | AMPERSAND {$<pval>$ = P_BUILD("assoc_connective", P_TOKEN("AMPERSAND ", $<ival>1),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

unary_connective : TILDE {$<pval>$ = P_BUILD("unary_connective", P_TOKEN("TILDE ", $<ival>1),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

gentzen_arrow : MINUS_MINUS_GREATER {$<pval>$ = P_BUILD("gentzen_arrow", P_TOKEN("MINUS_MINUS_GREATER ", $<ival>1),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

assignment : COLON_EQUALS {$<pval>$ = P_BUILD("assignment", P_TOKEN("COLON_EQUALS ", $<ival>1),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

identical : EQUALS_EQUALS {$<pval>$ = P_BUILD("identical", P_TOKEN("EQUALS_EQUALS ", $<ival>1),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

type_constant : type_functor {$<pval>$ = P_BUILD("type_constant", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

type_functor : atomic_word {$<pval>$ = P_BUILD("type_functor", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

defined_type : atomic_defined_word {$<pval>$ = P_BUILD("defined_type", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

atom : untyped_atom {$<pval>$ = P_BUILD("atom", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | defined_constant {$<pval>$ = P_BUILD("atom", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

untyped_atom : constant {$<pval>$ = P_BUILD("untyped_atom", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | system_constant {$<pval>$ = P_BUILD("untyped_atom", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

defined_infix_pred : infix_equality {$<pval>$ = P_BUILD("defined_infix_pred", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

infix_equality : EQUALS {$<pval>$ = P_BUILD("infix_equality", P_TOKEN("EQUALS ", $<ival>1),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

infix_inequality : EXCLAMATION_EQUALS {$<pval>$ = P_BUILD("infix_inequality", P_TOKEN("EXCLAMATION_EQUALS ", $<ival>1),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

constant : functor {$<pval>$ = P_BUILD("constant", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

functor : atomic_word {$<pval>$ = P_BUILD("functor", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

defined_constant : defined_functor {$<pval>$ = P_BUILD("defined_constant", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

defined_functor : atomic_defined_word {$<pval>$ = P_BUILD("defined_functor", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

system_constant : system_functor {$<pval>$ = P_BUILD("system_constant", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

system_functor : atomic_system_word {$<pval>$ = P_BUILD("system_functor", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

def_or_sys_constant : defined_constant {$<pval>$ = P_BUILD("def_or_sys_constant", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | system_constant {$<pval>$ = P_BUILD("def_or_sys_constant", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

th1_defined_term : EXCLAMATION_EXCLAMATION {$<pval>$ = P_BUILD("th1_defined_term", P_TOKEN("EXCLAMATION_EXCLAMATION ", $<ival>1),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | QUESTION_QUESTION {$<pval>$ = P_BUILD("th1_defined_term", P_TOKEN("QUESTION_QUESTION ", $<ival>1),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | AT_AT_SIGN_PLUS {$<pval>$ = P_BUILD("th1_defined_term", P_TOKEN("AT_AT_SIGN_PLUS ", $<ival>1),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | AT_AT_SIGN_MINUS {$<pval>$ = P_BUILD("th1_defined_term", P_TOKEN("AT_AT_SIGN_MINUS ", $<ival>1),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | AT_SIGN_EQUALS {$<pval>$ = P_BUILD("th1_defined_term", P_TOKEN("AT_SIGN_EQUALS ", $<ival>1),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

defined_term : number {$<pval>$ = P_BUILD("defined_term", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | distinct_object {$<pval>$ = P_BUILD("defined_term", P_TOKEN("distinct_object ", $<ival>1),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

variable : upper_word {$<pval>$ = P_BUILD("variable", P_TOKEN("upper_word ", $<ival>1),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

source : general_term {$<pval>$ = P_BUILD("source", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

optional_info : COMMA useful_info {$<pval>$ = P_BUILD("optional_info", P_TOKEN("COMMA ", $<ival>1), $<pval>2,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | null {$<pval>$ = P_BUILD("optional_info", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

useful_info : general_list {$<pval>$ = P_BUILD("useful_info", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

include : _LIT_include LPAREN file_name formula_selection RPAREN PERIOD {$<pval>$ = P_BUILD("include", P_TOKEN("_LIT_include ", $<ival>1), P_TOKEN("LPAREN ", $<ival>2), $<pval>3, $<pval>4, P_TOKEN("RPAREN ", $<ival>5), P_TOKEN("PERIOD ", $<ival>6),NULL,NULL,NULL,NULL);}
                    ;

formula_selection : COMMA LBRKT name_list RBRKT {$<pval>$ = P_BUILD("formula_selection", P_TOKEN("COMMA ", $<ival>1), P_TOKEN("LBRKT ", $<ival>2), $<pval>3, P_TOKEN("RBRKT ", $<ival>4),NULL,NULL,NULL,NULL,NULL,NULL);}
                    | null {$<pval>$ = P_BUILD("formula_selection", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

name_list : name {$<pval>$ = P_BUILD("name_list", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | name COMMA name_list {$<pval>$ = P_BUILD("name_list", $<pval>1, P_TOKEN("COMMA ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

general_term : general_data {$<pval>$ = P_BUILD("general_term", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | general_data COLON general_term {$<pval>$ = P_BUILD("general_term", $<pval>1, P_TOKEN("COLON ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | general_list {$<pval>$ = P_BUILD("general_term", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

general_data : atomic_word {$<pval>$ = P_BUILD("general_data", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | general_function {$<pval>$ = P_BUILD("general_data", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | variable {$<pval>$ = P_BUILD("general_data", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | number {$<pval>$ = P_BUILD("general_data", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | distinct_object {$<pval>$ = P_BUILD("general_data", P_TOKEN("distinct_object ", $<ival>1),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | formula_data {$<pval>$ = P_BUILD("general_data", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

general_function : atomic_word LPAREN general_terms RPAREN {$<pval>$ = P_BUILD("general_function", $<pval>1, P_TOKEN("LPAREN ", $<ival>2), $<pval>3, P_TOKEN("RPAREN ", $<ival>4),NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

formula_data : _DLR_thf LPAREN thf_formula RPAREN {$<pval>$ = P_BUILD("formula_data", P_TOKEN("_DLR_thf ", $<ival>1), P_TOKEN("LPAREN ", $<ival>2), $<pval>3, P_TOKEN("RPAREN ", $<ival>4),NULL,NULL,NULL,NULL,NULL,NULL);}
                    | _DLR_tff LPAREN tff_formula RPAREN {$<pval>$ = P_BUILD("formula_data", P_TOKEN("_DLR_tff ", $<ival>1), P_TOKEN("LPAREN ", $<ival>2), $<pval>3, P_TOKEN("RPAREN ", $<ival>4),NULL,NULL,NULL,NULL,NULL,NULL);}
                    | _DLR_fof LPAREN fof_formula RPAREN {$<pval>$ = P_BUILD("formula_data", P_TOKEN("_DLR_fof ", $<ival>1), P_TOKEN("LPAREN ", $<ival>2), $<pval>3, P_TOKEN("RPAREN ", $<ival>4),NULL,NULL,NULL,NULL,NULL,NULL);}
                    | _DLR_cnf LPAREN cnf_formula RPAREN {$<pval>$ = P_BUILD("formula_data", P_TOKEN("_DLR_cnf ", $<ival>1), P_TOKEN("LPAREN ", $<ival>2), $<pval>3, P_TOKEN("RPAREN ", $<ival>4),NULL,NULL,NULL,NULL,NULL,NULL);}
                    | _DLR_fot LPAREN fof_term RPAREN {$<pval>$ = P_BUILD("formula_data", P_TOKEN("_DLR_fot ", $<ival>1), P_TOKEN("LPAREN ", $<ival>2), $<pval>3, P_TOKEN("RPAREN ", $<ival>4),NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

general_list : LBRKT RBRKT {$<pval>$ = P_BUILD("general_list", P_TOKEN("LBRKT ", $<ival>1), P_TOKEN("RBRKT ", $<ival>2),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | LBRKT general_terms RBRKT {$<pval>$ = P_BUILD("general_list", P_TOKEN("LBRKT ", $<ival>1), $<pval>2, P_TOKEN("RBRKT ", $<ival>3),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

general_terms : general_term {$<pval>$ = P_BUILD("general_terms", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | general_term COMMA general_terms {$<pval>$ = P_BUILD("general_terms", $<pval>1, P_TOKEN("COMMA ", $<ival>2), $<pval>3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

name : atomic_word {$<pval>$ = P_BUILD("name", $<pval>1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | integer {$<pval>$ = P_BUILD("name", P_TOKEN("integer ", $<ival>1),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

atomic_word : lower_word {$<pval>$ = P_BUILD("atomic_word", P_TOKEN("lower_word ", $<ival>1),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | single_quoted {$<pval>$ = P_BUILD("atomic_word", P_TOKEN("single_quoted ", $<ival>1),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

atomic_defined_word : dollar_word {$<pval>$ = P_BUILD("atomic_defined_word", P_TOKEN("dollar_word ", $<ival>1),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

atomic_system_word : dollar_dollar_word {$<pval>$ = P_BUILD("atomic_system_word", P_TOKEN("dollar_dollar_word ", $<ival>1),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

number : integer {$<pval>$ = P_BUILD("number", P_TOKEN("integer ", $<ival>1),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | rational {$<pval>$ = P_BUILD("number", P_TOKEN("rational ", $<ival>1),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | real {$<pval>$ = P_BUILD("number", P_TOKEN("real ", $<ival>1),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

file_name : single_quoted {$<pval>$ = P_BUILD("file_name", P_TOKEN("single_quoted ", $<ival>1),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

null : {$<pval>$ = P_BUILD("null",NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    ;

