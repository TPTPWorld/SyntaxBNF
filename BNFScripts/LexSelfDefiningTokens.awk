#----Self-defining tokens are those that appear literally on the right side
#----of some grammar rule.
#----If their strings have any letters, their token names are based on
#----_LIT_string.  Exception: Beginning $, then letters goes to _DLR_string.
#----_LIT_ is stripped or _DLR_ is replaced by [$] to recover string from
#----token name later, so the transforms must be inverses of each other.
#----If their strings are known symbols or symbol sequences, their token names
#----are the symbols, spelled out in capital letters, separated by underscore.
#----A nonterminal name could conceivably clash with such a token name.
#----token-xref.csh helps to keep in sync with tptp-trans.csh.

function print_for_token(begin_line,token,token_word) {
    if (begin_line == "B") {
        printf "<INITIAL>";
    }
    printf "\"%s\" {\n",token;
    if (begin_line != "") {
        printf "    BEGIN %s;\n",begin_line;
    }
    printf "    tptp_prev_tok=%s;\n",token_word;
    printf "    yylval.ival = tptp_update_lval(yytext);\n"
    printf "    return(%s);\n",token_word;
    printf "}\n";
}
/^AMPERSAND$/ {
    print_for_token("","&",$1);
    next;
}
/^AT_SIGN$/ {
    print_for_token("","@",$1);
    next;
}
/^BQUOTE$/ {
    print_for_token("","",$1);
    next;
}
/^CARET$/ {
    print_for_token("","^",$1);
    next;
}
/^COLON$/ {
    print_for_token("",":",$1);
    next;
}
/^COMMA$/ {
    print_for_token("",",",$1);
    next;
}
/^DOLLAR$/ {
    print_for_token("","$",$1);
    next;
}
/^DQUOTE$/ {
    print_for_token("","\"",$1);
    next;
}
/^EQUALS$/ {
    print_for_token("","=",$1);
    next;
}
/^EXCLAMATION_GREATER$/ {
    print_for_token("","!>",$1);
    next;
}
/^EXCLAMATION_EXCLAMATION$/ {
    print_for_token("","!!",$1);
    next;
}
/^EXCLAMATION$/ {
    print_for_token("","!",$1);
    next;
}
/^QUESTION_STAR$/ {
    print_for_token("","?*",$1);
    next;
}
/^QUESTION_QUESTION$/ {
    print_for_token("","??",$1);
    next;
}
/^AT_AT_SIGN_PLUS$/ {
    print_for_token("","@@+",$1);
    next;
}
/^AT_AT_SIGN_MINUS$/ {
    print_for_token("","@@-",$1);
    next;
}
/^AT_SIGN_EQUALS$/ {
    print_for_token("","@=",$1);
    next;
}
/^AT_SIGN_PLUS$/ {
    print_for_token("","@+",$1);
    next;
}
/^AT_SIGN_MINUS$/ {
    print_for_token("","@-",$1);
    next;
}
/^QUESTION$/ {
    print_for_token("","?",$1);
    next;
}
/^COLON_EQUALS$/ {
    print_for_token("",":=",$1);
    next;
}
/^EQUALS_EQUALS$/ {
    print_for_token("","==",$1);
    next;
}
/^GREATER$/ {
    print_for_token("",">",$1);
    next;
}
/^LESS_EQUALS$/ {
    print_for_token("","<=",$1);
    next;
}
/^LESS_EQUALS_GREATER$/ {
    print_for_token("","<=>",$1);
    next;
}
/^EQUALS_GREATER$/ {
    print_for_token("","=>",$1);
    next;
}
/^LBRACE$/ {
    print_for_token("","{",$1);
    next;
}
/^LBRKT$/ {
    print_for_token("","[",$1);
    next;
}
/^LESS_LESS$/ {
    print_for_token("","<<",$1);
    next;
}
/^LESS$/ {
    print_for_token("","<",$1);
    next;
}
/^LBRACE$/ {
    print_for_token("","{",$1);
    next;
}
/^RBRACE$/ {
    print_for_token("","}",$1);
    next;
}
/^LPAREN$/ {
    print_for_token("","(",$1);
    next;
}
/^MINUS_MINUS_GREATER$/ {
    print_for_token("","-->",$1);
    next;
}
/^MINUS_GREATER$/ {
    print_for_token("","->",$1);
    next;
}
/^MINUS$/ {
    print_for_token("","-",$1);
    next;
}
/^MINUS_MINUS$/ {
    print_for_token("","--",$1);
    next;
}
/^TILDE_AMPERSAND$/ {
    print_for_token("","~&",$1);
    next;
}
/^EXCLAMATION_EQUALS$/ {
    print_for_token("","!=",$1);
    next;
}
/^LESS_TILDE_GREATER$/ {
    print_for_token("","<~>",$1);
    next;
}
/^TILDE_VLINE$/ {
    print_for_token("","~|",$1);
    next;
}
/^PERCENT$/ {
    print_for_token("","%",$1);
    next;
}
/^PERIOD$/ {
    print_for_token("INITIAL",".",$1);
    next;
}
/^PLUS$/ {
    print_for_token("","+",$1);
    next;
}
/^PLUS_PLUS$/ {
    print_for_token("","++",$1);
    next;
}
/^RBRACE$/ {
    print_for_token("","}",$1);
    next;
}
/^RBRKT$/ {
    print_for_token("","]",$1);
    next;
}
/^RPAREN$/ {
    print_for_token("",")",$1);
    next;
}
/^SEMICOLON$/ {
    print_for_token("",";",$1);
    next;
}
/^SLASH$/ {
    print_for_token("","/",$1);
    next;
}
/^SLASH_STAR$/ {
    print_for_token("","/*",$1);
    next;
}
/^SQUOTE$/ {
    print_for_token("","'",$1);
    next;
}
/^STAR$/ {
    print_for_token("","*",$1);
    next;
}
/^STAR_SLASH$/ {
    print_for_token("","*/",$1);
    next;
}
/^TILDE$/ {
    print_for_token("","~",$1);
    next;
}
/^VLINE$/ {
    print_for_token("","|",$1);
    next;
}
/^_LIT_[cft][nofh]f$/ || /^_LIT_include$/ {
    z=substr($0,6,999);
    print_for_token("B",z,$1);
    next;
}
/^_LIT_/ {
    z=substr($0,6,999); 
    print_for_token("",z,$1);
    next;
}
/^_DLR_/ {
    z=substr($0,6,999); 
    z = "$" z;
    print_for_token("",z,$1);
    next;
}
/^[A-Z][A-Z_0-9]*$/ {
    print_for_token("",$0,$1);
    next;
}

{
    print;
}
