#----Self-defining tokens are those that appear literally on the right side
#----of some grammar rule.

#----If their strings have any letters, their token names are based on
#----_LIT_string.  Exception: Beginning $, then letters goes to _DLR_string.
#----_LIT_ is stripped or _DLR_ is replaced by [$] to recover string from
#----token name later, so the transforms must be inverses of each other.
$2 ~ "^_GR" {
    for (i=3;i<=NF;i++) {
        if ($i ~ "^[A-Za-z][A-Za-z0-9_]*$") {
            z="_LIT_" $i;
            sub($i,z,$i);
        } 
        if ($i ~ "^[$][A-Za-z][A-Za-z0-9_]*$") {
            sub("^[$]","_DLR_",$i);
        } 
    }
#----If their strings are known symbols or symbol sequences, their token names
#----are the symbols, spelled out in capital letters, separated by underscore.
#----A nonterminal name could conceivably clash with such a token name.
    gsub("[.][.][.]", " ETC_ETC ");
    gsub("/<star>",   " SLASH_STAR ");
    gsub("<star>/",   " STAR_SLASH ");
    gsub("[!][!]",    " EXCLAMATION_EXCLAMATION ");
    gsub("[!]>",      " EXCLAMATION_GREATER ");
    gsub("[?][?]",    " QUESTION_QUESTION ");
    gsub("[?][*]",    " QUESTION_STAR ");
    gsub("[@][@][+]", " AT_AT_SIGN_PLUS ");
    gsub("[@][@][-]", " AT_AT_SIGN_MINUS ");
    gsub("[@][=]",    " AT_SIGN_EQUALS ");
    gsub("[@][+]",    " AT_SIGN_PLUS ");
    gsub("[@][-]",    " AT_SIGN_MINUS ");
    gsub("<=>",       " LESS_EQUALS_GREATER ");
    gsub("<~>",       " LESS_TILDE_GREATER ");
    gsub("~[&]",      " TILDE_AMPERSAND ");
    gsub("~<vline>",  " TILDE_VLINE ");
    gsub("=>",        " EQUALS_GREATER ");
    gsub("-->",       " MINUS_MINUS_GREATER ");
    gsub("->",        " MINUS_GREATER ");
    gsub("<=",        " LESS_EQUALS ");
    gsub("!=",        " EXCLAMATION_EQUALS ");
    gsub("==",        " EQUALS_EQUALS ");
    gsub(":=",        " COLON_EQUALS ");
    gsub("[+][+]",    " PLUS_PLUS ");
    gsub("[-][-]",    " MINUS_MINUS ");
    gsub("<<",        " LESS_LESS ");

    gsub("%",         " PERCENT ");
    gsub("<star>",    " STAR ");
    gsub("[!]",       " EXCLAMATION ");
    gsub("[?]",       " QUESTION ");
    gsub("[&]",       " AMPERSAND ");
    gsub("<vline>",   " VLINE ");
    gsub("=",         " EQUALS ");
    gsub("[+]",       " PLUS ");
    gsub("[-]",       " MINUS ");
    gsub(":",         " COLON ");
    gsub("[@]",       " AT_SIGN ");
    gsub(";",         " SEMICOLON ");
    gsub("[\\^]",     " CARET ");
    gsub("[~]",       " TILDE ");
    gsub("[/]",       " SLASH ");
    gsub("\"",        " DQUOTE ");
    gsub("[']",       " SQUOTE ");
    gsub("[`]",       " BQUOTE ");
    gsub(",",         " COMMA ");
    gsub("[.]",       " PERIOD ");
    gsub("[[]",       " LBRKT ");
    gsub("]",         " RBRKT ");
    gsub("[(]",       " LPAREN ");
    gsub("[)]",       " RPAREN ");
    gsub("[{]",       " LBRACE ");
    gsub("[}]",       " RBRACE ");
    gsub("[$]",       " DOLLAR ");
#----Remove <> from nonterminal symbols. Must be done after others, as others
#----are left after this.
    for (i=1;i<=NF;i++) {
        if ($i ~ "^<[A-Za-z][A-Za-z0-9_]*>$") {
            sub("<","",$i);
            sub(">","",$i);
        }
    }
#----Translation of standalone > and < done last to avoid confusion with
#----non-terminals.
    gsub("[>]",       " GREATER ");
    gsub("[<]",       " LESS ");
    print;
    next;
}

{
    print;
}
