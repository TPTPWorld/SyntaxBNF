#----Change LHS of token rules from <...> to {...}

$2 ~ "^_TR[MT]" {
    if ($1 ~ "<[A-Za-z][A-Za-z0-9_]*>") {
        gsub("<","{",$1);
        gsub(">","}",$1);
    }
    print;
    next;
} 

{
    print;
}
