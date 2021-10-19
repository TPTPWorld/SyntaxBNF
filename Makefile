LANG=C
LY_SCRIPT_DIR=BNFScripts
LY_SCRIPT=TPTP2LYFiles.csh
CUSTOMDIR=UserProcs
TMPDIR=LYtmp
SRCDIR=LYsrc
LEX=lex
YACC=yacc
#----The order of these libs matters (insane) (swapped them when it was
#----doing nothing, and suddenly it works again - INSANE).
#----libl.a missing, so I made a dummy one from garbage.c, in .
LYLIBS= -ly -ll
#---For flex 
# LEX=flex
# YACC=bison
# LYLIBS=-ll -lfl
CFLAGS=
#--- -g for debugging

all: SyntaxBNF-yl-parser SyntaxBNF-yl-parser-verbose SyntaxBNF-yl-parser-double SyntaxBNF-yl-parser-clickable clean

SyntaxBNF-yl-parser: lex.yy.c y.tab.c
	gcc $(CFLAGS) -o $@ lex.yy.c y.tab.c $(LYLIBS)

SyntaxBNF-yl-parser-verbose: lex.yy.c y.tab.c
	gcc $(CFLAGS) -DP_VERBOSE=1 -o $@ lex.yy.c y.tab.c $(LYLIBS)

SyntaxBNF-yl-parser-double: lex.yy.c y.tab.c $(CUSTOMDIR)/doublefeature.c
	cp $(CUSTOMDIR)/doublefeature.c p_user_proc.c
	gcc $(CFLAGS) -DP_VERBOSE=1 -DP_USERPROC=1 -o $@ lex.yy.c y.tab.c $(LYLIBS)
	rm p_user_proc.c

SyntaxBNF-yl-parser-clickable: lex.yy.c y.tab.c $(CUSTOMDIR)/clickable.c
	cp $(CUSTOMDIR)/clickable.c p_user_proc.c
	gcc $(CFLAGS) -DP_VERBOSE=1 -DP_USERPROC=1 -o $@ lex.yy.c y.tab.c $(LYLIBS)
	rm p_user_proc.c

lex.yy.c: SyntaxBNF.l
	$(LEX) -l SyntaxBNF.l

y.tab.c: SyntaxBNF.y
	$(YACC) -t -d -v -o y.tab.c SyntaxBNF.y

SyntaxBNF.l: LYFiles

SyntaxBNF.y: LYFiles

LYFiles: $(BNF)
	cd $(LY_SCRIPT_DIR);$(LY_SCRIPT) ../$(BNF);cd ..
	mv $(TMPDIR)/$(BNF).l SyntaxBNF.l
	mv $(TMPDIR)/$(BNF).y SyntaxBNF.y

clean:
	mv y.output $(TMPDIR)
	mv SyntaxBNF.l SyntaxBNF.y lex.yy.c y.tab.c y.tab.h $(SRCDIR)
