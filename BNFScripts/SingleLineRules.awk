#----Put continuations all on one line.

BEGIN {
    s = "";
}
/^</ {
    if (s != "") {
        gsub("  *"," ",s);
        print s;
    }
    s = $0;
    next;
}
/^ / {
    s = s $0;
    next;
}
END {
    if (s != "") {
        gsub("  *"," ",s);
        print s;
    }
}
