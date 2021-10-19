#----Change entry points with * repeat to left recursive (why not in sed?)
#----If it ends with * take "a _GRR b1 ... bn c *"  and save 
#----    a into recurse_entry
#----    b1 into recurse_repeat
#----    c into repeated
#----    b1 b2 b3 ... bn into recurse_final
#----Do not output - wait for the repeating bit which must come next.
$NF=="*" {
    star=1;
    recurse_entry=$1;
    repeated = $(NF-1);
    recurse_repeat=$3;
    recurse_final=$3;
    for (i=4;i<=NF-2;i++) {
        recurse_final = recurse_final " " $i;
    };
    next;
} 

#----If a repeating rule was found, if current rule does not start with
#----repeating part (must come next) then warning. Otherwise make a new
#----rule      a _GRR b1 b2 b3 ... bn | b1 local_bit a
#----Assumes the local bit is one word.
star==1 {
    if ($1 != repeated) {
        print "/*WARNING:",repeated,"THEN",$1,"*/";
        print;
    } else {
        printf "%-19s _GRR ",recurse_entry; 
        print recurse_final, "|", recurse_repeat, $3, recurse_entry;
        star="";
    }
    next;
}

{
    print;
}

