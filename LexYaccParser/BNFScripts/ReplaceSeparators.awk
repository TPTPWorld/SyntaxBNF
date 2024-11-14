#----Replace meta-symbols ::= :== ::- ::: with _GRR _GRS _TRT _TRM respectively.
#----_GR[RS] denotes "grammar rule" and _TR[TM] denotes "token rule".
{
    gsub("::="," _GRR ");
    gsub(":=="," _GRS ");
    gsub("::-"," _TRT ");
    gsub(":::"," _TRM ");
    print;
}
