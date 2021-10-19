#----Replace meta-symbols ::= :== ::- ::: with _GRR _GRS _TRT _TRM respectively.
#----_GR[RS] denotes "grammar rule" and _TR[TM] denotes "token rule".
{
    gsub("::="," _GRR ");
    gsub(":=="," _GRS ");
    gsub("::-"," _TRT ");
    gsub(":::"," _TRM ");
}

#----Put spaces around all characters that have to be recognized
$2 ~ "^_GR" {
    gsub(">[*]", "> *");
    gsub("><", "> <");
    gsub("[[]", " [ ");
    gsub("]"," ] ");
    gsub("[(]", " ( ");
    gsub("[)]"," ) ");
    gsub("[{]", " { ");
    gsub("[}]"," } ");
    gsub("\""," \" ");
    gsub("[']"," ' ");
    gsub("[`]"," ` ");
    gsub(","," , ");
    gsub(";"," ; ");
    print;
    next;
}

{
    print;
}
