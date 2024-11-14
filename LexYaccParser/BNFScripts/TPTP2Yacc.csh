#!/bin/csh -f

#---Goal for this script is to extract lines that belong in the parser.
#----Goal for this script is to change rules with * to recursive,
#----and do final formating for yacc.

#----We need echo to collapse \\ to \.  Sadly, this is not standard.
set thisOS = `uname -s`
set ECHO = echo
if ($thisOS == Linux) set ECHO = (/bin/echo -e)
if ($thisOS == SunOs) set ECHO = (/bin/echo)

setenv LANG C

cat header.y

#----Find the start symbol
gawk '$2 == "_GRR" {print "%start ", $1;exit;}' $1

#----Find the tokens in the lex file.
grep 'return(' $2 | \
sed -e 's/.*return(\([^)]*\));.*/%token <ival> \1/' | \
sort -u

$ECHO '%%'
$ECHO ''

#----Rules for yacc next; all tokens should appear in yacc file (they don't yet)
grep "_GRR" $1 | \
sed -f ChangeSimpleRepeatToRecurse.sed | \
gawk -f ChangeComplexRepeatToRecurse.awk | \
sed -f AddP_ACTCalls.sed | \
gawk -f ConvertToYaccRules.awk
