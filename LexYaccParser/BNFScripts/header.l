
%{
//-----------------------------------------------------------------------------
#include <string.h>
#include <stdlib.h>
#include "y.tab.h"
//-----------------------------------------------------------------------------
//----Compile with -DP_VERBOSE=2 to list tokens as they are seen.
#ifndef P_VERBOSE
#  define P_VERBOSE 0
#  endif
int verbose2 = P_VERBOSE;

//----If tptp_prev_tok == PERIOD, you are outside any sentence.
#ifndef PERIOD
#  define PERIOD 46
#  endif

#define TPTP_STORE_SIZE 4194304
// #define YY_READ_BUF_SIZE 65536
// #define YYLMAX 65536

//----These have to be external as they are references from other code that
//----is generated by lex/yacc.
int tptp_prev_tok = PERIOD;
int tptp_store_size = TPTP_STORE_SIZE;
char* tptp_lval[TPTP_STORE_SIZE];
//-----------------------------------------------------------------------------
void tptp_print_tok(char* lval) { 

    printf("%3d:%s;\n", tptp_prev_tok, lval);

    return; 
}
//-----------------------------------------------------------------------------
int tptp_update_lval(char* lval) { 

    static int tptp_next_store = 0;
    int next = tptp_next_store;

    free(tptp_lval[tptp_next_store]);
    tptp_lval[tptp_next_store] = strdup(lval);
    tptp_next_store = (tptp_next_store+1) % TPTP_STORE_SIZE;
    if (verbose2 == 2) {
        tptp_print_tok(lval);
    }

    return next; 
}
//-----------------------------------------------------------------------------
//----%Start: INITIAL begin sentence, B before formula. No others.
%}

