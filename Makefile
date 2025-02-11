#----Set TPTP_HOME if not already imported from environment
TPTP_HOME ?= /home/tptp
HERE = $(shell pwd)

ifneq ($(TARGET),"install_html")
    ifndef BNF
        $(error BNF is not defined. Define when calling make with BNF=BNF_file_name)
    else
        FULLBNF = $(HERE)/$(BNF)
        $(info BNF is $(FULLBNF))
    endif
endif 

all: html lexyacc_parser

install: install_html

html: $(FULLBNF)
	sed -f BNFLinker.sedscript $(FULLBNF) > SyntaxBNF.html

install_html: html
	mv SyntaxBNF.html $(TPTP_HOME)/public_html/UserDocs/TPTPLanguage/SyntaxBNF.html

lexyacc_parser: $(FULLBNF)
	rm -f LexYaccParser/SyntaxBNF.l
	rm -f LexYaccParser/SyntaxBNF.y
	make -C LexYaccParser BNF=$(FULLBNF)

javascript_parser: antlr_grammar
	cd ANTLRParsers && java -jar antlr-4.13.2-complete.jar -Dlanguage=JavaScript ANTLRGrammar/TPTP.g4 -o JavaScriptParser -Xexact-output-dir

antlr_grammar: $(FULLBNF)
	cd ANTLRParsers/BNF2ANTLR && python3 bnf2antlr.py $(FULLBNF) ../ANTLRGrammar

clean:
	rm -f SyntaxBNF.html
