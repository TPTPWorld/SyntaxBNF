

import antlr4 from 'antlr4';
import TPTPv9Lexer from '../IDVApp/tptp/TPTPLexer.js';
import TPTPv9Parser from '../IDVApp/tptp/TPTPParser.js';

import fs from 'fs';

const filePath = './testfiles/simple.s';

let fileContent;
try {
  fileContent = fs.readFileSync(filePath, 'utf8');
} catch (err) {
  console.error('Error reading file:', err);
}

const input = fileContent;
const chars = new antlr4.InputStream(input);
const lexer = new TPTPv9Lexer(chars);
const tokens = new antlr4.CommonTokenStream(lexer);
const parser = new TPTPv9Parser(tokens);

const tree = parser.tptp_file();

// Print the AST
function printTree(node, indent = 0) {
  const nodeName = parser.ruleNames[node.ruleIndex];
  console.log(' '.repeat(indent), nodeName, node.getText());

  for (let i = 0; i < node.getChildCount(); i++) {
    printTree(node.getChild(i), indent + 2);
  }
}

printTree(tree);