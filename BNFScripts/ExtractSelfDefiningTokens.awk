#----Look in the RHS of GRR rules for self-defining tokens
$2 ~ "^_GRR" {
    for (i = 3; i <= NF; i++) {
        if ($i ~ "^[A-Z][A-Z0-9_]*$" || $i ~ "_LIT_[A-Za-z][A-Za-z0-9_]*$" || 
$i ~ "_DLR_[A-Za-z][A-Za-z0-9_]*$") {
            print $i;
        }
    }
}
