#----Output lex definitions (macros) from _TR[TM] lines.
#----Each RHS is wrapped in parentheses. The Makefile runs lex with -l (AT&T
#----lex compatibility), and in that mode {name} is expanded as plain text,
#----not as a group. Without the parentheses an alternation inside a
#----definition (e.g., <exp_integer> ::: <signed_exp_integer>|<integer_digits>)
#----escapes into the enclosing pattern and changes its meaning.
$2 ~ "^_TR" {
    L=length($1);
    LHS=substr($1,2,L-2);
    RHS=$0;
    sub("^.* _TR. *", "",RHS);
    sub(" *$", "",RHS);
    printf "%-20s  (%s)\n", LHS, RHS;
    next;
}
