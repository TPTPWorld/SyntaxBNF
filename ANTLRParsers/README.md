- To compile a Java parser  NEEDS UPDATING
cd TPTP-ANTLR4-Grammar
mkdir JavaParser
cd JavaParser
ln -s ../antlr-4.13.2-complete.jar
cd ..
java -jar antlr-4.13.2-complete.jar -o JavaParser TPTPv8.g4
cd JavaParser
javac -cp "antlr-4.13.2-complete.jar:$CLASSPATH" *.java
java -cp "antlr-4.13.2-complete.jar:$CLASSPATH" org.antlr.v4.gui.TestRig TPTPv8 tptp_file -tree FILENAME

- To produce a JavaScript parser
antlr4 -Dlanguage=JavaScript path_to_grammar.g4 -o path_to_output -Xexact-output-dir

But I need antlr 4.13.2, which is not on quenda, so ...
java -jar antlr-4.13.2-complete.jar -Dlanguage=JavaScript path_to_grammar.g4 -o path_to_output -Xexact-output-dir
