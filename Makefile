#----Set TPTP_HOME if not already imported from environment
TPTP_HOME ?= /home/tptp
HERE = $(shell pwd)

.PHONY: all install html lexyacc_parser idv_bundle itv_bundle antlr_grammar javascript_parser clean

ifneq ($(TARGET),"install_html")
    ifndef BNF
        $(error BNF is not defined. Define when calling make with BNF=BNF_file_name)
    else
        FULLBNF = $(HERE)/$(BNF)
        $(info BNF is $(FULLBNF))
    endif
endif 

all: html lexyacc_parser javascript_parser idv_bundle itv_bundle

install: install_html

install_html: html
	@echo "---- Move  SyntaxBNF.html to UserDocs/TPTPLanguage"
	mv SyntaxBNF.html $(TPTP_HOME)/public_html/UserDocs/TPTPLanguage/SyntaxBNF.html
	@echo "---- Moved SyntaxBNF.html to UserDocs/TPTPLanguage"

html: $(FULLBNF)
	@echo "---- Make SyntaxBNF.html"
	sed -f BNFLinker.sedscript $(FULLBNF) > SyntaxBNF.html
	@echo "---- Made SyntaxBNF.html"

lexyacc_parser: $(FULLBNF)
	@echo "---- Make LexYacc parsers"
	rm -f LexYaccParser/SyntaxBNF.l
	rm -f LexYaccParser/SyntaxBNF.y
	make -C LexYaccParser BNF=$(FULLBNF)
	@echo "---- Made LexYacc parsers"

#----Required to make IDVbundle and ITVbundle
pre_bundle: javascript_parser
	@echo "---- Copy   TPTP*.js to static/js"
	cp ANTLRParsers/JavaScriptParser/TPTP*.js $(TPTP_HOME)/ServiceTools/IDVDir/BuildBundles/js
	@echo "---- Copied TPTP*.js to static/js"
	sed -i -e "s/import antlr4 from 'antlr4';/import antlr4 from '.\/antlr4.js';/" $(TPTP_HOME)/ServiceTools/IDVDir/BuildBundles/js/TPTP*.js
	@echo "---- Hacked path in static/js/TPTP*.js"

idv_bundle: pre_bundle
	@echo "---- Make IDVBundle.js"
	cd $(TPTP_HOME)/ServiceTools/IDVDir/BuildBundles/js && $(TPTP_HOME)/ServiceTools/IDVDir/BuildBundles/esbuild helpersIDV.js --bundle --outfile=IDVbundle.js
	@echo "---- Made IDVbundle.js"

itv_bundle: pre_bundle
	@echo "---- Make ITVbundle.js"
	cd $(TPTP_HOME)/ServiceTools/IDVDir/BuildBundles/js && $(TPTP_HOME)/ServiceTools/IDVDir/BuildBundles/esbuild helpersITV.js --bundle --outfile=ITVbundle.js
	@echo "---- Made ITVbundle.js"

javascript_parser: antlr_grammar
	@echo "---- Make JavaScript parser"
	cd ANTLRParsers && java -jar antlr-4.13.2-complete.jar -Dlanguage=JavaScript ANTLRGrammar/TPTP.g4 -o JavaScriptParser -Xexact-output-dir
	@echo "---- Made JavaScript parser"

python_parser: antlr_grammar
	@echo "---- Make Python parser"
	cd ANTLRParsers && java -jar antlr-4.13.2-complete.jar -Dlanguage=Python3 -visitor ANTLRGrammar/TPTP.g4 -o PythonParser -Xexact-output-dir
	@echo "---- Made Python parser"

antlr_grammar: $(FULLBNF)
	@echo "---- Make ANTLR grammar"
	cd ANTLRParsers/BNF2ANTLR && python3 bnf2antlr.py $(FULLBNF) ../ANTLRGrammar
	@echo "---- Made ANTLR grammar"

clean:
	rm -f SyntaxBNF.html
	@echo "---- Cleaned"
