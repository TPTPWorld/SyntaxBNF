#----Add P_ACT for last option
/_GRR/s/$/ {P_ACT($<sval>$)} ;/
#----Add P_ACT for earlier options
/_GRR/s/[|]/{P_ACT($<sval>$)} |/g
#----Change _GRR to :
/^[^/]/s/ _GRR/ :/

