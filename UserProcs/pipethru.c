/* define yacc procedures */

#  define P_ACT(ss) if(verbose)printf("%7d %s\n",yylineno,ss);
#  define P_BUILD(sym,A,B,C,D,E,F,G,H,I,J) mBuildTree(sym,A,B,C,D,E,F,G,H,I,J)
#  define P_TOKEN(tok,symIdx) mToken(tok,symIdx)
#  define P_PRINT(ss) if(verbose){printf("\n\n");mPrintTree(ss,0);}


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

typedef struct mTreeNode * mTree;
struct mTreeNode {char* sym; int symIdx; mTree ch[MAX_CH+1];};

mTree mBuildTree(char* sym, mTree A, mTree B, mTree C, mTree D,
    mTree E, mTree F, mTree G, mTree H, mTree I, mTree J);
mTree mBuildTree(char* sym, mTree A, mTree B, mTree C, mTree D,
    mTree E, mTree F, mTree G, mTree H, mTree I, mTree J)
{ mTree ss = (mTree)calloc(1,sizeof(struct mTreeNode));
  ss->sym = sym;
  ss->symIdx = -1;
  ss->ch[0] = A; ss->ch[1] = B; ss->ch[2] = C; ss->ch[3] = D;
  ss->ch[4] = E; ss->ch[5] = F; ss->ch[6] = G; ss->ch[7] = H;
  ss->ch[8] = I; ss->ch[9] = J; ss->ch[10] = 0;
  return ss; }

mTree mToken(char* tok, int symIdx);
mTree mToken(char* tok, int symIdx)
{ mTree ss;
  char* sym = tptp_lval[symIdx];
  char* safeSym;
  strncpy(mTokenBuf, tok, 39);
  strncat(mTokenBuf, sym, 8193);
  safeSym = strdup(mTokenBuf);
  ss = mBuildTree(safeSym,0,0,0,0,0,0,0,0,0,0);
  ss->symIdx = symIdx;
  return ss; }

void mPrintComments(int start, int depth);
void mPrintComments(int start, int depth)
{ int d, j;
  char c1[4] = "%", c2[4] = "/*";
  j = start;
  while (tptp_lval[j] != NULL
  && (tptp_lval[j][0]==c1[0] || (tptp_lval[j][0]==c2[0] && tptp_lval[j][1]==c2[1])))
    { for (d=0; d<depth; d++) printf("  ");
      printf("%s\n",tptp_lval[j]);
      j = (j+1)%tptp_store_size; }
  return; }

void mPrintTree(mTree ss, int depth);

void mPrintTree(mTree ss, int depth)
{ int i, d;
  char* buf;
  if (mPrintIdx >= 0)
    { mPrintComments(mPrintIdx, 0); mPrintIdx = -1;}
  if (ss == NULL) return;
//  for (d = 0; d < depth; d++) printf("  ."); 
  if ((ss->ch[0] == 0) && (strcmp(ss->sym, "null") != 0))
//  printf("%s", ss->sym);
    { buf=strchr(ss->sym,' '); buf++; printf("%s", buf);}
//  else printf("<%s>\n", ss->sym); 
  if (strcmp(ss->sym, "PERIOD .") == 0)
  { mPrintIdx = (ss->symIdx+1)%tptp_store_size; printf("\n"); }
  if (ss->symIdx >= 0)
    mPrintComments((ss->symIdx+1)%tptp_store_size, depth);
  i = 0;
  while(ss->ch[i] != 0) {mPrintTree(ss->ch[i], depth+1); i++;}
  return; }

/*
void mPrintTree(mTree ss, int depth)
{ int i, d;
  char* buf;
  if (mPrintIdx >= 0)
    { mPrintComments(mPrintIdx, 0); mPrintIdx = -1;}
  if (ss == NULL) return;
//  for (d = 0; d < depth; d++) printf("  "); 
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
