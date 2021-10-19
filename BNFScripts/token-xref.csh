#!/bin/csh -f
setenv LANG C
awk '/^awk/&&/_GR" {gsub/&&/" [A-Z]/ {sub("[^(]*[(]","",$5);sub(",$","",$5); print $7, $5;if($7=="LBRKT"||$7=="LPAREN"||$7=="LBRACE"){sub("[^(]*[(]","",$8);sub(",.$","",$8); print $9, $8; }}' tptp-trans.csh | sort
