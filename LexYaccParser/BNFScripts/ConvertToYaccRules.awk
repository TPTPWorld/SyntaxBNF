/^\/\*/ {
    print;
    next;
} 

/^[A-za-z0-9_]* *:/ {
    gsub(" [|]","\n                    |");
    gsub(" ;$","\n                    ;\n");
    print;
    next;
} 

{
    print;
    next;
}

