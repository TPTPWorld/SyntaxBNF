# HOW TO CONVERT BNF TO ANTLR

**Make sure your current working directory is `BNF2ANTLR`!**

## Step 1.

bnf2antlr.py will take input from the file "bnf/SyntaxBNF" ,convert it all to antlr grammar, and then outputs it to g4/TPTP.g4

- To convert files, run this command:

```bash
python3 bnf2antlr.py
```

- If this fails run this:

```bash
  python bnf2antlr.py
```

## Step 2.

- This will build a JavaScript parser for the antlr grammar.

```bash
cd g4; antlr4 -Dlanguage=JavaScript TPTP.g4 -o ../../IDVApp/tptp; cd ..
```

- If you don't have antlr4, you can install it with:

```bash
pip install antlr4-tools
```

- Output JS antlr parsers will be in IDVApp for the electron app to use
