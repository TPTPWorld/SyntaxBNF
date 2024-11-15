
import os
script_dir = os.path.dirname(os.path.abspath(__file__))
import re

import sys

if len(sys.argv) <= 1:
    print("Please provide the path to the BNF file")
    sys.exit()

file_path = sys.argv[1]
version = file_path.split("/")[-1].split("v")[-1].replace(".", "_")

lexer_rules = {'Or': '|', 'And': '&', 'Iff': '<=>', 'Impl': '=>', 'If': '<=', 'Niff': '<~>', 'Nor': '~|', 'Nand': '~&', 'Not': '~', 'ForallComb': '!!', 'TyForall': '!>', 'Infix_inequality': '!=', 'Infix_equality': '=', 'Forall': '!', 'ExistsComb': '??', 'TyExists': '?*', 'Exists': '?', 'Lambda': '^', 'ChoiceComb': '@@+', 'Choice': '@+', 'DescriptionComb': '@@-', 'Description': '@-', 'EqComb': '@=', 'App': '@', 'Assignment': '', 'Identical': '==', 'Arrow': '>', 'Star': '*', 'Plus': '+', 'Hash': '#', 'Subtype_sign': '<<', 'Gentzen_arrow': '-->'}


def get_optional_rules():
    file = open(file_path, "r")
    text = file.readlines()
    file.close()

    text = clean_up(text)
    
    optional_rules = []
    
    for line in text:
        if "|<null>" in line.replace(" ", ""):
            optional_rules.append(line.split(">")[0].split("<")[1])
    
    return optional_rules


def read_bnf_file(file_path):
    with open(file_path, "r") as file:
        lines = file.readlines()
    return lines


def write_antlr_file(antlr_lines, filename):
    file = open(f"g4/{filename}.g4", "w")
    
    new_lines = []
    
    lexer_rules = fr"""
grammar {filename};
WS : [ \r\t\n]+ -> skip ;
Comment_line : '%' ~[\r\n]* -> skip;
Comment_block : '/*' .*? '*/' -> skip;
"""
    
    
    
   

    for line in lexer_rules.split("\n"):
        if line != "":
            new_lines.append(line.strip())

    antlr_lines = new_lines + antlr_lines

    for line in antlr_lines:
        file.write(line + '\n')

    file.close()

  
def clean_up(bnf_lines):
    cleaned_bnf_text = []
    
    for line in bnf_lines:
        line = line.replace("><", "> <")
        cleaned_bnf_text.append(line)
        
    cleaned_bnf_text = [s.replace('\n', ' ') for s in cleaned_bnf_text]
        
    if len(cleaned_bnf_text) > 1:
        i = 1
        while i < len(cleaned_bnf_text):
            if cleaned_bnf_text[i].startswith(" "):
                cleaned_bnf_text[i - 1] += cleaned_bnf_text[i].lstrip()
                cleaned_bnf_text.pop(i)
            else:
                i += 1
                
    return cleaned_bnf_text


def another_clean_up(raw_lines):
    symbols = {
        # "|": "Or",
        "&": "And",
        "<=>": "Iff",
        "=>": "Impl",
        "<=": "If",
        "<~>": "Niff",
        "~|": "Nor",
        "~&": "Nand",
        # "~": "Not",
        "!!": "ForallComb",
        "!>": "TyForall",
        "!=": "Infix_inequality",
        # "=": "Infix_equality",
        "!": "Forall",
        "??": "ExistsComb",
        "?*": "TyExists",
        "?": "Exists",
        "^": "Lambda",
        "@@+": "ChoiceComb",
        "@+": "Choice",
        "@@-": "DescriptionComb",
        "@-": "Description",
        "@=": "EqComb",
        "@": "App",
        # ":=": "Assignment",
        # "==": "Identical",
        "-->": "Gentzen_arrow",
        "<<": "Subtype_sign",
        # "*": "Star",
        # "+": "Plus",
        # ">": "Arrow",
        # "#": "Hash"
    }

    for index in range(len(raw_lines)):
        for key in symbols.keys():
            if key in raw_lines[index]:
                raw_lines[index] = raw_lines[index].replace(key, "<" + symbols[key] + ">")
                # print(raw_lines[index])
        
        index += 1
                
    return raw_lines

#comment is %
def convert_comment(line):
    return "//" + line



# semantic rule is :==
def convert_semantic_rule(line):
    
    line = line.replace("><", "> <")
    
    before_line = line.split(":==")[0].strip()
    before_line = before_line.replace(">", "")
    before_line = before_line.replace("<", "")
    
    after_line = line.split(":==")[1].strip()
    result_str = ""
    isInAlligator = False
    
    index = 0
    for char in after_line:
        if "<<" in after_line:
            return before_line + " : " + "'<<'" + ";"
        
        if char == "<" and after_line[index + 1].isalpha():
            isInAlligator = True
            
        if char == ">" and not isInAlligator:
            result_str += "'>'"
            
        if char == ">" and after_line[index - 1].isalpha():
            isInAlligator = False
            
        if not isInAlligator and char != "|" and char != ">" and char != " ":
            result_str += "'" + char + "'"
            
        elif isInAlligator and char != "<":
            result_str += char
            
        elif char == "|":
            result_str += " | "
        
        elif char == " ":
            result_str += " "
            
        index += 1
    
            
    return before_line + " : " + remove_quotes(result_str) + ";"


def remove_quotes(line):
    if "''" in line:
        return line.replace("''", "")
    else:
        return line




#~ CONVERT RULES


# grammar rule is ::=
def convert_grammar_rule(line, append_EOF=False):
    if append_EOF:
        return "tptp_file               : tptp_input* EOF;"
    elif line.startswith("<TPTP_input> "):
        return "tptp_input              : annotated_formula | include;"
    
    line = line.replace("><", "> <")
    
    before_line = line.split("::=")[0].strip()
    before_line = before_line.replace(">", "")
    before_line = before_line.replace("<", "")
    
    after_line = line.split("::=")[1].strip()
    result_str = ""
    isInAlligator = False
    
    index = 0
    for char in after_line:
        if "<<" in after_line:
            return before_line + " : " + "'<<'" + ";"
        
        if char == "<" and after_line[index + 1].isalpha():
            isInAlligator = True
            
        if char == ">" and not isInAlligator:
            result_str += "'>'"
            
        if char == ">" and after_line[index - 1].isalpha():
            isInAlligator = False
            
        if not isInAlligator and char != "|" and char != ">" and char != " ":
            result_str += "'" + char + "'"
            
        elif isInAlligator and char != "<":
            result_str += char
            
        elif char == "|":
            result_str += " | "
        
        elif char == " ":
            result_str += " "
            
        index += 1
    
            
    return before_line + " : " + remove_quotes(result_str) + ";"


# token rule is ::-
def convert_lexer_rule(line):
        
    if line.startswith("<do_char>"):
        return r"Do_char : '\\' ('" + '"' + r"' | '\\') ;"
    elif line.startswith("<sq_char>"):
        return r"Sq_char : '\\' ('\'' | '\\');"
    elif line.startswith("<viewable_char>"):
        return r"Viewable_char : '.\n';"
    elif line.startswith("<slosh_char>"):
        return r"Slosh_char : '\\\\';"
    elif line.startswith("<single_quote>"):
        return r"Single_quote : '\'';"
    elif line.startswith("<comment_line>"):
        return "///"
    elif line.startswith("<comment_block>"):
        return "///"
    elif line.startswith("<comment>"):
        return "///"
        
    line = line.replace("><", "> <")
    
    before_line = line.split("::-")[0].strip()
    before_line = before_line.replace(">", "")
    before_line = before_line.replace("<", "")
    
    after_line = line.split("::-")[1].strip()
    
    if bool(re.search(r'<[^>]+>', after_line)):
        after_line = after_line.replace("<", " ")
        after_line = after_line.replace(">", " ")
    
    else:
        if "[" in after_line:
            after_line = after_line.replace("[", "'")
            after_line = after_line.replace("]", "'")
    
    first_char = before_line[0].upper()
    before_line = first_char + before_line[1:]
    
    return before_line + " : " + after_line + ";"


# token rule is :::
def convert_character_classes(line):
    
    if line.startswith("<viewable_char>"):
        return r"Viewable_char : '.\n';"
    elif line.startswith("<slosh_char>"):
        return r"Slosh_char : '\\\\';"
    elif line.startswith("<single_quote>"):
        return r"Single_quote : '\'';"
    elif line.startswith("<not_star_slash>"):
        return r"Not_star_slash : (~'*')* '**' ~('/' | '*')*;"
    elif line.startswith("<do_char>"):
        return r"fragment Do_char : [\u0020-\u0021\u0023-\u005B\u005D-\u007E] | '\\'[" + '"\\\\];'
    elif line.startswith("<sq_char>"):
        return r"fragment Sq_char : [\u0020-\u0026\u0028-\u005B\u005D-\u007E] | '\\\\' | '\\\'';"
    elif line.startswith("<sign>"):
        return r"fragment Sign : [+-];"
    elif line.startswith("<exponent>"):
        return r"fragment Exponent : [Ee];"
    elif line.startswith("<non_zero_numeric>"):
        return r"fragment Non_zero_numeric : [1-9];"
    elif line.startswith("<numeric>"):
        return r"fragment Numeric : [0-9];"
    elif line.startswith("<lower_alpha>"):
        return r"fragment Lower_alpha : [a-z];"
    elif line.startswith("<upper_alpha>"):
        return r"fragment Upper_alpha : [A-Z];"
    elif line.startswith("<alpha_numeric>"):
        return r"fragment Alpha_numeric : Lower_alpha | Upper_alpha | Numeric | '_';"
    elif line.startswith("<comment_line>"):
        return "///"
    elif line.startswith("<comment_block>"):
        return "///"
    elif line.startswith("<comment>"):
        return "///"
        
    line = line.replace("><", "> <")
    
    before_line = line.split(":::")[0].strip()
    before_line = before_line.replace(">", "")
    before_line = before_line.replace("<", "")
    
    after_line = line.split(":::")[1].strip()
    after_line = after_line.replace("<", " ")
    after_line = after_line.replace(">", " ")
    
    first_char = before_line[0].upper()
    before_line = first_char + before_line[1:]
    
    return before_line + " : " + after_line + ";"


def replace_capitals(lines):
    
    lexer_rules = []
    
    for line in lines:
        if line[0].isupper():
            lexer_rules.append(line.split(":")[0].strip().lower())
            
    lexer_rules.append("comment_line")
    lexer_rules.append("do_char")
    lexer_rules.append("sq_char")
    lexer_rules.append("sign")
    lexer_rules.append("exponent")
    lexer_rules.append("non_zero_numeric")
    lexer_rules.append("numeric")
    lexer_rules.append("lower_alpha")
    lexer_rules.append("upper_alpha")
    lexer_rules.append("alpha_numeric")
            
    pattern = r'\b(' + '|'.join(re.escape(word) for word in lexer_rules) + r')\b'
    
    def replace_func(match):
        return match.group(0).capitalize()
    
    return [re.sub(pattern, replace_func, line) for line in lines]


def get_all_semantic_rules(bnf_lines):
    all_semantic_rules = []
    
    for line in bnf_lines:
        if ":==" in line and not line.startswith("%"):
            all_semantic_rules.append(line.split(":==")[0].strip())
            
    return all_semantic_rules


def main():
    
    
    bnf_lines = read_bnf_file(file_path)
    antlr_lines = []
    token_rules = []
    bnf_line = ""
    
    # all_semantic_rules = get_all_semantic_rules(bnf_lines)
    all_semantic_rules = []
    
    # run a clean up
    bnf_lines = clean_up(bnf_lines)
    # bnf_lines = another_clean_up(bnf_lines)
    grammar_count = 0
    errCount = 0 
    for index in range(len(bnf_lines)):
        
        # comment is %
        if bnf_lines[index].startswith("%"):
            bnf_line = convert_comment(bnf_lines[index])
            antlr_lines.append(bnf_line)
               
        # grammar rule is ::=
        elif "::=" in bnf_lines[index]:
            if bnf_lines[index].split("::=")[0].strip() in all_semantic_rules:
                bnf_line = convert_comment(bnf_lines[index])
            else:
                if grammar_count == 0:
                    bnf_line = convert_grammar_rule(bnf_lines[index], append_EOF=True)
                else:
                    bnf_line = convert_grammar_rule(bnf_lines[index])
                    
            grammar_count += 1
            antlr_lines.append(bnf_line)
            
        # token rule is ::-
        elif "::-" in bnf_lines[index]:
            bnf_line = convert_lexer_rule(bnf_lines[index])
            token_rules.append(bnf_line)
            # antlr_lines.append(bnf_line)
            
        # token rule is :::
        elif  ":::" in bnf_lines[index]:
            bnf_line = convert_character_classes(bnf_lines[index])
            token_rules.append(bnf_line)
            # antlr_lines.append(bnf_line)
            
        # semantic rule is :==
        elif ":==" in bnf_lines[index]:
            # bnf_line = convert_semantic_rule(bnf_lines[index])
            bnf_line = convert_comment(bnf_lines[index])
            antlr_lines.append(bnf_line)
        else:
            if is_empty_line(bnf_lines[index]):
                print(f"empty newline character in SyntaxBNF at line: {index + 1},  {bnf_lines[index]}, please either comment or fix definition")
                errCount += 1
            else:
                print(f"unknown characters in SynxtaxBNF at line : {index + 1},  {bnf_lines[index]}, please either comment or fix definition")
                errCount +=1
    if errCount != 0:
        print("-" * 100)
        print(f"errors in BNF, writing cancelled, please fix then re-run!")
        print(f"BNF file path is : {file_path}")
        exit()
    else:
        antlr_lines = replace_capitals(["//# HERE ARE THE LEXER RULES\n"] + token_rules + ["\n//# END THE LEXER RULES\n\n"] + antlr_lines)
        # antlr_lines = replace_capitals(antlr_lines)
        write_antlr_file(antlr_lines, f"TPTP_v{version}")
        write_antlr_file(antlr_lines, f"TPTP")
        print("bnf to antlr conversion complete")
        
def is_empty_line(line):
    return line.strip() == ""
main()
