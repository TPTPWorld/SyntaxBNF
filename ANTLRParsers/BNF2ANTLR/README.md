# HOW TO CONVERT BNF TO ANTLR

**Make sure your current working directory is `BNF2ANTLR`!**

## Step 1.

bnf2antlr.py will take input from the BNF file given as a command line argument ,convert it 
all to antlr grammar, and then outputs it to g4/TPTP.g4

- To convert files, run this command:

```bash
python3 bnf2antlr.py SyntaxBNF-vR.E.P.F output_directory_eg_../ANTLRGrammar
```

- If this fails run this:

```bash
  python bnf2antlr.py
```

