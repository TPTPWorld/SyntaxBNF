#----Change *file entry point (the start - what a hack) with * or + repeat
#----to left recursive
/^[A-Za-z][A-Za-z0-9_]*file/s/\([A-Za-z0-9_]*\)\( *_GRR *\)\([A-Za-z0-9_]*\) *[*]/\1\2nothing | \1 \3/
/^[A-Za-z][A-Za-z0-9_]*file/s/\([A-Za-z0-9_]*\)\( *_GRR *\)\([A-Za-z0-9_]*\) *[+]/\1\2\3 | \1 \3/
#----Change other entry points with + repeat to left recursive
s/\([A-Za-z0-9_]*\)\( *_GRR *\)\([A-Za-z0-9_]*\) *[+]/\1\2\3 | \3 \1/

