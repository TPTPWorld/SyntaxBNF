$2=="_TRT" {
    L=length($1); 
    z=substr($1,2,L-2); 
#----Comments are ignored later in TPTP2Lex.csh
    if (z !~ /^comment/) {
        printf "%s {\n",$1;
        printf "    tptp_prev_tok=%s;\n",z;
        printf "    yylval.ival = tptp_update_lval(yytext);\n"
        printf "    return(%s);\n",z;
        printf "}\n";
    }
}
