#----Goal for this script is to replace P_ACT by P_BUILD, P_TOKEN, and P_PRINT.

BEGIN {
    inrule = ""; 
    MAX_CH = 10; 
    ntoks = 0;
}

#----Save away all the tokens for future recognition
/^%token/ {
    ntoks++; 
    tokens[$NF] = ntoks; 
    print; 
    next;
}

/^[A-za-z][A-Za-z0-9_]*file *:/ {
    inrule = "TPTP_file"; 
}
/^[A-za-z][A-Za-z0-9_]*input *:/ {
    inrule = "TPTP_input"; 
}

#----Have come to the end of a rule, so reset and loop
/^ *[;]/ {
    inrule = ""; 
    print; 
    next;
}

#----Don't do anything for the whole file
inrule == "TPTP_file" {
    sub("{P_ACT.*}","{}"); 
    print; 
    next;
}

inrule == "TPTP_input" {
    if ($1 ~ "[A-za-z][A-Za-z0-9_]*input") {
        i = 3; 
    } else {
        i = 2;
    }
    s = $i;
    if (s in tokens) {
        arg = "P_TOKEN(\"" s " \", $<ival>1)";
    } else {
        arg = "$<pval>$";
        }
    repl = "{P_PRINT(" arg ");}";
    sub("{P_ACT.*}", repl);
    print;
    next;
}

#----If a rule
/^[A-Za-z0-9_][A-Za-z0-9_]* *:/ { 
    inrule = $1;
    n = NF - 3;
    repl = "{$<pval>$ = P_BUILD(\"" inrule "\"";
    for (i = 1; i <= n; i++) {
        j = i + 2; 
        s = $j;
        if (s in tokens) {
            arg = "P_TOKEN(\"" s " \", $<ival>" i ")";
        } else {
            arg = "$<pval>" i;
        } 
        repl = repl ", " arg;
    }
    for (i = n+1; i <= MAX_CH; i++) { 
        repl = repl ",NULL"; 
    }
    if (inrule ~ "f_formula") {
        repl = repl ");}";
    } else {
        repl = repl ");}";
    }
    sub("{P_ACT.*}",repl);
    print; 
    next;
}

#----If an alternative
/^ *[|]/ {
    n = NF - 2;
    repl = "{$<pval>$ = P_BUILD(\"" inrule "\"";
    for (i = 1; i <= n; i++) {
        j = i + 1; 
        s = $j;
        if (s in tokens) {
            arg = "P_TOKEN(\"" s " \", $<ival>" i ")";
        } else {
            arg = "$<pval>" i;
        } 
        repl = repl ", " arg;
    }
    for (i = n+1; i <= MAX_CH; i++) { 
        repl = repl ",NULL"; 
    }
    if (inrule ~ "f_formula") {
        repl = repl ");}";
    } else {
        repl = repl ");}";
    }
    sub("{P_ACT.*}",repl);
    print; 
    next;
}

#----All other cases just echo the line
{
    print;
}
