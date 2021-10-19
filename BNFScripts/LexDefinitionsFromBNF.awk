$2 ~ "^_TR" {
    L=length($1);
    LHS=substr($1,2,L-2);
    RHS=$0;
    sub("^.* _TR. *", "",RHS);
    printf "%-20s  %s\n", LHS, RHS;
    next;
}
