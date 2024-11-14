/* define yacc procedures */

#  define P_ACT(ss) if(verbose)printf("%7d %s\n",yylineno,ss);
#  define P_BUILD(sym,A,B,C,D,E,F,G,H,I,J) mBuildTree(sym,0,A,B,C,D,E,F,G,H,I,J)
#  define P_TOKEN(tok,symIdx) mToken(tok,symIdx)
#  define P_PRINT(ss) if(verbose){doubleFeature(ss,0);}


/* code for defines */

#define MAX_CH 12
extern int yylineno;
extern int yychar;
extern char yytext[];
extern int tptp_store_size;
extern char* tptp_lval[];

/* int yyerror( char *s ) { fprintf( stderr, "%s in line %d, char %d at item \"%s\"\n.", s, yylineno, yychar, yytext); } */

/* int verbose = P_VERBOSE; */
char mTokenBuf[8240];
/* mPrintIdx is where to find top-level comments to print
   before a sentence. yywrap() gets those after last sentence. */
int mPrintIdx = 0;
int nPrintIdx = 0;

typedef struct mTreeNode * mTree;
struct mTreeNode {char* sym; int symIdx; mTree parent; mTree ch[MAX_CH+1];};

mTree mBuildTree(char* sym, mTree parent, mTree A, mTree B, mTree C, mTree D,
    mTree E, mTree F, mTree G, mTree H, mTree I, mTree J);
mTree mBuildTree(char* sym, mTree parent, mTree A, mTree B, mTree C, mTree D,
    mTree E, mTree F, mTree G, mTree H, mTree I, mTree J)
{ mTree ss = (mTree)calloc(1,sizeof(struct mTreeNode));
  ss->sym = sym;
  ss->parent = parent;
  ss->symIdx = -1;
  ss->ch[0] = A; ss->ch[1] = B; ss->ch[2] = C; ss->ch[3] = D;
  ss->ch[4] = E; ss->ch[5] = F; ss->ch[6] = G; ss->ch[7] = H;
  ss->ch[8] = I; ss->ch[9] = J; ss->ch[10] = 0;
  int d;
  for (d=0; d<10; d++) {
   if (ss->ch[d] != NULL) (ss->ch[d])->parent = ss;
  } 
  return ss; }

mTree mToken(char* tok, int symIdx);
mTree mToken(char* tok, int symIdx)
{ mTree ss;
  char* sym = tptp_lval[symIdx];
  char* safeSym;
  strncpy(mTokenBuf, tok, 39);
  strncat(mTokenBuf, sym, 8193);
  safeSym = strdup(mTokenBuf);
  ss = mBuildTree(safeSym,0,0,0,0,0,0,0,0,0,0,0);
  ss->symIdx = symIdx;
  return ss; }

void mPrintComments(int start, int depth);
void mPrintComments(int start, int depth)
{ int j;
  char c1[4] = "%", c2[4] = "/*";
  j = start;
  while (tptp_lval[j] != NULL
  && (tptp_lval[j][0]==c1[0] || (tptp_lval[j][0]==c2[0] && tptp_lval[j][1]==c2[1])))
  { //for (d=0; d<depth; d++) printf("| ");
      //printf("%s\n",tptp_lval[j]);
      j = (j+1)%tptp_store_size; }
  return; }

void nPrintComments(int start, int depth);
void nPrintComments(int start, int depth)
{ int j;
  char c1[4] = "%", c2[4] = "/*";
  j = start;
  while (tptp_lval[j] != NULL
  && (tptp_lval[j][0]==c1[0] || (tptp_lval[j][0]==c2[0] && tptp_lval[j][1]==c2[1])))
  { //for (d=0; d<depth; d++) printf("| ");
      //printf("%s\n",tptp_lval[j]);
      j = (j+1)%tptp_store_size; }
  return; }


void doubleFeature(mTree ss, int depth);
  
void nPrintTree(mTree ss, int depth);
/*
void nPrintTree(mTree ss, int depth)
{ int i, d;
  if (nPrintIdx >= 0)
  {   mPrintComments(nPrintIdx, 0);
      nPrintIdx = -1;}
  if (ss == NULL) return;
  for (d = 0; d < depth-1; d++) printf("| ");
  printf("%1d ",depth % 10);
  if (ss->ch[0] == 0) printf("%s\n", ss->sym);
  else printf("<%s>\n", ss->sym);
  if (strcmp(ss->sym, "PERIOD .") == 0)
  { nPrintIdx = (ss->symIdx+1)%tptp_store_size; printf("\n\n\n");}
  if (ss->symIdx >= 0)
      mPrintComments((ss->symIdx+1)%tptp_store_size, depth);
  i = 0;
  while(ss->ch[i] != 0) {nPrintTree(ss->ch[i], depth+1); i++;}
  return; }
*/

void nPrintTree(mTree ss, int depth)
{ int i, d;
 printf("%s","%");
  if (nPrintIdx >= 0)
    { nPrintComments(nPrintIdx, 0); nPrintIdx = -1;}
  if (ss == NULL) return;
  for (d = 0; d < depth-1; d++) printf("| ");
  printf("%1d ",depth % 10);
  if (ss->ch[0] == 0) printf("%s\n", ss->sym);
  else printf("<%s>\n", ss->sym);
  if (strcmp(ss->sym, "PERIOD .") == 0)
    {nPrintIdx = (ss->symIdx+1)%tptp_store_size; printf("\n\n\n");}
  if (ss->symIdx >= 0)
    nPrintComments((ss->symIdx+1)%tptp_store_size, depth);
  i = 0;
  while(ss->ch[i] != 0) {nPrintTree(ss->ch[i], depth+1); i++;} 
  return; }

int mPrintTree(mTree ss, int depth);

int mPrintTree(mTree ss, int depth)
{ int i, d;
  char* buf;
  char* symbol;
  if (mPrintIdx >= 0)
    { mPrintComments(mPrintIdx, 0); mPrintIdx = -1;}
  if (ss == NULL) return depth;
//  for (d = 0; d < depth; d++) printf("| ");
// Prefix:
  if (strcmp(ss->sym, "thf_formula")==0)
  {printf("\n");depth+=4;for (d = 0; d < depth; d++) printf(" ");}

// No children: 
  if ((ss->ch[0] == 0) && (strcmp(ss->sym, "null") != 0))
  {
    symbol=strdup(ss->sym);
    buf=strchr(symbol,' '); *buf=0; buf++;
//    if (strcmp(symbol, "COLON")==0) printf("(%s)",(ss->parent)->sym);
    if ((strcmp(symbol, "VLINE")==0)||(strcmp(symbol, "TILDE_VLINE")==0)||(strcmp(symbol, "TILDE_AMPERSAND")==0)||
        (strcmp(symbol, "TILDE")==0)||(strcmp(symbol, "AMPERSAND")==0)||(strcmp(symbol, "EQUALS")==0)||
        (strcmp(symbol, "CARET")==0)||(strcmp(symbol, "EQUALS_GREATER")==0)||(strcmp(symbol, "LESS_EQUALS_GREATER")==0))
    {printf("\n");for (d = 0; d < depth; d++) printf(" ");}
    printf("%s", buf);
    if (strcmp(symbol, "LPAREN")==0) depth++;
//    if ((strcmp(symbol, "RPAREN")==0) && (strcmp((ss->parent)->sym,"thf_binary_type")!=0) && (strcmp((ss->parent)->sym,"thf_unitary_type")!=0))
//    {printf("\n");for (d = 0; d < depth; d++) printf(" ");depth--;}
    if (strcmp(symbol, "RPAREN")==0) depth--;
    if ((strcmp(symbol, "EQUALS")==0)||(strcmp(symbol, "EQUALS_GREATER")==0)||(strcmp(symbol, "LESS_EQUALS_GREATER")==0))
    {printf("\n");for (d = 0; d < depth; d++) printf(" ");}
    if ((strcmp(symbol, "COLON")==0) && ((strcmp((ss->parent)->sym,"thf_quantified_var")==0) || (strcmp((ss->parent)->sym,"thf_abstraction")==0)))
    {printf("\n");depth++;for (d = 0; d < depth; d++) printf(" ");}
  }
  if (strcmp(ss->sym, "PERIOD .") == 0)
  { mPrintIdx = (ss->symIdx+1)%tptp_store_size; printf("\n\n"); }
  if (ss->symIdx >= 0)
    mPrintComments((ss->symIdx+1)%tptp_store_size, depth);
  i = 0;
  while(ss->ch[i] != 0) {depth=mPrintTree(ss->ch[i], depth); i++;}

// Postfix:

  return depth; }


void doubleFeature(mTree ss, int depth)
{ mPrintTree(ss, depth);
  nPrintTree(ss, depth);
}


/*
void mPrintTree(mTree ss, int depth)
{ int i, d;
  char* buf;
  if (mPrintIdx >= 0)
    { mPrintComments(mPrintIdx, 0); mPrintIdx = -1;}
  if (ss == NULL) return;
//  for (d = 0; d < depth; d++) printf("| "); 
  if ((ss->ch[0] == 0) && (strcmp(ss->sym, "null") != 0))
    { buf=strchr(ss->sym,' '); buf++; printf("%s", buf);}
//  else printf("<%s>\n", ss->sym); 
  if (strcmp(ss->sym, "PERIOD .") == 0)
  { mPrintIdx = (ss->symIdx+1)%tptp_store_size; printf("\n"); }
  if (ss->symIdx >= 0)
    mPrintComments((ss->symIdx+1)%tptp_store_size, depth);
  i = 0;
  while(ss->ch[i] != 0) {mPrintTree(ss->ch[i], depth+1); i++;}
  return; }
*/
