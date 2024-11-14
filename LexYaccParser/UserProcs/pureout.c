#  define P_ACT(ss) if(verbose)printf("%7d %s\n",yylineno,ss);
#  define P_BUILD(sym,A,B,C,D,E,F,G,H,I,J) pBuildTree(sym,A,B,C,D,E,F,G,H,I,J)
#  define P_TOKEN(tok,symIdx) pToken(tok,symIdx)
#  define P_PRINT(ss) {pPrintTreemod(ss,0);}



void pPrintTreemod(pTree ss, int depth)
{ int i;
  char* buf;
  if (pPrintIdx >= 0)
    { pPrintComments(pPrintIdx, 0); pPrintIdx = -1;}
  if (ss == NULL) return;
//  for (d = 0; d < depth; d++) printf("  "); 
  if ((ss->ch[0] == 0) && (strcmp(ss->sym, "null") != 0))
    { buf=strchr(ss->sym,' '); buf++; printf("%s", buf);}
//  else printf("<%s>\n", ss->sym); 
  if (strcmp(ss->sym, "PERIOD .") == 0)
  { pPrintIdx = (ss->symIdx+1)%tptp_store_size; printf("\n"); }
  if (ss->symIdx >= 0)
    pPrintComments((ss->symIdx+1)%tptp_store_size, depth);
  i = 0;
  while(ss->ch[i] != 0) {pPrintTreemod(ss->ch[i], depth+1); i++;}
  return; }
