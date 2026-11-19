#----Build the lex/yacc TPTP parsers from a SyntaxBNF file:
#----    make BNF=../SyntaxBNF-v10.0.0.1
#----Needs Python 3, flex, a yacc (GNU Bison or Berkeley yacc), and a C compiler.
#----Override tools as usual, e.g., make BNF=... YACC=byacc  or  YACC="bison -y"

LEX     = flex
YACC    = bison
PYTHON  = python3
CC      = gcc
CFLAGS  = -O2 -Wall -Wno-unused-function
#----Set to 1 to accept yacc conflicts (they are resolved silently by yacc,
#----which usually means the BNF is ambiguous for an LALR(1) parser).
ALLOW_CONFLICTS = 0

export LANG = C
export LC_ALL = C

GENERATOR = Generator/BNF2LexYacc.py
GEN_DEPS  = $(GENERATOR) Generator/header.l Generator/header.y
PARSERS   = SyntaxBNF-yl-parser SyntaxBNF-yl-parser-verbose \
            SyntaxBNF-yl-parser-double SyntaxBNF-yl-parser-clickable
#----The same parsers with SystemOnTPTP's SZS output (see README.md)
SZS_PARSERS = BNFParser BNFParserTree BNFParserDrill
SOURCES   = lex.yy.c y.tab.c

.PHONY: all clean check FORCE
.DELETE_ON_ERROR:

all: $(PARSERS) $(SZS_PARSERS)

#----Remember which BNF was used, so that changing BNF= rebuilds everything,
#----and later runs of make without BNF= use the same one.
BNF ?= $(shell cat .bnf-name 2>/dev/null)

.bnf-name: FORCE
ifeq ($(strip $(BNF)),)
	$(error BNF is not defined. Use make BNF=SyntaxBNF_file_name)
endif
	@echo '$(abspath $(BNF))' | cmp -s - $@ || echo '$(abspath $(BNF))' > $@

#----The generator writes both files in one run.
SyntaxBNF.l: $(BNF) $(GEN_DEPS) .bnf-name
	$(PYTHON) $(GENERATOR) $(BNF) --lex SyntaxBNF.l --yacc SyntaxBNF.y

SyntaxBNF.y: SyntaxBNF.l
	@test -f $@ || $(PYTHON) $(GENERATOR) $(BNF) --lex SyntaxBNF.l --yacc SyntaxBNF.y

#----flex has no -Werror, so fail on any warning, e.g. "rule cannot be matched".
lex.yy.c: SyntaxBNF.l
	$(LEX) -o $@ SyntaxBNF.l 2> lex.log; status=$$?; cat lex.log; \
	    if [ $$status -ne 0 ] || grep -q . lex.log; then rm -f $@; exit 1; fi

#----y.output records conflicts in the same way for Bison and Berkeley yacc.
y.tab.c: SyntaxBNF.y
	$(YACC) -t -d -v -o $@ SyntaxBNF.y
	@if [ "$(ALLOW_CONFLICTS)" != 1 ] && grep -qi 'conflict' y.output; then \
	    grep -i 'conflict' y.output | head -5; \
	    echo "yacc reported conflicts (see y.output); use ALLOW_CONFLICTS=1 to accept them"; \
	    rm -f $@; exit 1; fi

y.tab.h: y.tab.c
	@test -f $@ || { rm -f y.tab.c; $(MAKE) y.tab.c; }

SyntaxBNF-yl-parser: $(SOURCES) y.tab.h
	$(CC) $(CFLAGS) -o $@ $(SOURCES)

SyntaxBNF-yl-parser-verbose: $(SOURCES) y.tab.h
	$(CC) $(CFLAGS) -DP_VERBOSE=1 -o $@ $(SOURCES)

SyntaxBNF-yl-parser-double: $(SOURCES) y.tab.h UserProcs/doublefeature.c
	$(CC) $(CFLAGS) -DP_VERBOSE=1 -DP_USERPROC_FILE='"UserProcs/doublefeature.c"' -o $@ $(SOURCES)

SyntaxBNF-yl-parser-clickable: $(SOURCES) y.tab.h UserProcs/clickable.c
	$(CC) $(CFLAGS) -DP_VERBOSE=1 -DP_USERPROC_FILE='"UserProcs/clickable.c"' -o $@ $(SOURCES)

BNFParser: $(SOURCES) y.tab.h
	$(CC) $(CFLAGS) -DP_SZS=1 -o $@ $(SOURCES)

BNFParserTree: $(SOURCES) y.tab.h
	$(CC) $(CFLAGS) -DP_VERBOSE=1 -DP_SZS=2 -o $@ $(SOURCES)

BNFParserDrill: $(SOURCES) y.tab.h UserProcs/clickable.c
	$(CC) $(CFLAGS) -DP_VERBOSE=1 -DP_SZS=3 -DP_USERPROC_FILE='"UserProcs/clickable.c"' -o $@ $(SOURCES)

#----Quick sanity check of the built parsers.
check: SyntaxBNF-yl-parser $(SZS_PARSERS)
	@sh Tests/run-tests.sh ./SyntaxBNF-yl-parser
	@sh Tests/run-szs-tests.sh .

clean:
	rm -f $(PARSERS) $(SZS_PARSERS) SyntaxBNF.l SyntaxBNF.y lex.yy.c y.tab.c y.tab.h y.output \
	    lex.log .bnf-name SyntaxBNF.l.tmp SyntaxBNF.y.tmp
