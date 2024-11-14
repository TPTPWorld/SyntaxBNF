#!/bin/csh -f

#----Goal for this script is to extract lines that belong in the lexical 
#----analyzer.
#----Meta-symbols ::= :== ::- ::: were replaced with _GRR _GRS _TRT _TRM resp.
#----_GR[RS] denotes "grammar rule" and _TR[TM] denotes "token rule".
#----_GRR is "relaxed" grammar rule, actually being parsed.
#----_TRT is token rule defining a token; _TRM defines a macro for other tokens.

if ($#argv != 1) then
	echo Usage: $0 tptp-1.txt NEED BETTER DESCRIPTION
	exit $#argv
endif

# We need echo to collapse \\ to \.  Sadly, this is not standard.
set thisOS = `uname -s`
set ECHO = echo
if ($thisOS == Linux) set ECHO = (/bin/echo -e)
if ($thisOS == SunOs) set ECHO = (/bin/echo)

setenv LANG C

cat header.l

#----Output definitions for lex, from _TR[TM] lines
gawk -f LexDefinitionsFromBNF.awk $1

$ECHO ''
$ECHO '%Start B FF SQ1 SQ2 Q1 Q2'
$ECHO '%%'
$ECHO ''

#----Rules for lex next; all tokens should appear in yacc file (maybe future)
#----Only self-defining tokens that appear on the right side of a relaxed 
#----grammar rule (_GRR) will have lex rules set up for them in this pass.

gawk -f ExtractSelfDefiningTokens.awk $1 | \
sort -u | \
gawk -f LexSelfDefiningTokens.awk
$ECHO ''

#----All token rules (_TRT) go to lex, whether they are referenced or not.
#----Use the generic rule for _TRT on non-ETC_ETC cases.
gawk -f LexTokensFromBNF.awk $1

$ECHO '{comment}    tptp_update_lval(yytext);'
$ECHO '[ \\t\\n]    ;'
$ECHO '[\\000-\\040]|[\\177]    ;'
$ECHO '[\\041-\\176]    return(unrecognized);'
$ECHO '%%'
$ECHO ''

# awk '/^system_comment/{print "[ \\t\\n]" "    " ";";next;}{print;}' | \
