#!/bin/csh -f

if ($#argv != 1) then
	echo Usage: $0 BNF_file
	exit $#argv
endif

setenv LANG C
set BNFDir=`dirname $1`
set BNFName=`basename $1`
set TMPDir="$BNFDir/LYtmp"
mkdir $TMPDir >& /dev/null

#----Clean the BNF for processing
echo "Making $TMPDir/$BNFName.txt"
cat $1 | \
    sed -e '/^%/d' -e '/^ *$/d' | \
    gawk -f SingleLineRules.awk | \
    gawk -f SpaceOutGrammarRules.awk | \
    gawk -f MakeGrammarTerminalWords.awk | \
    sed -f FixTokenNonTerminalsRHS.sed | \
    gawk -f FixTokenLHS.awk > $TMPDir/$BNFName.txt
echo "Made $TMPDir/$BNFName.txt"

#----Create .l file for lex
echo "Making $TMPDir/$BNFName.l"
TPTP2Lex.csh $TMPDir/$BNFName.txt > $TMPDir/$BNFName.l
echo "Made $TMPDir/$BNFName.l"

#----Create .y file for yacc
echo "Making $TMPDir/$BNFName.y"
TPTP2Yacc.csh $TMPDir/$BNFName.txt $TMPDir/$BNFName.l | \
gawk -f ReplaceYaccP_ACT.awk > $TMPDir/$BNFName.y
echo "Made $TMPDir/$BNFName.y"
