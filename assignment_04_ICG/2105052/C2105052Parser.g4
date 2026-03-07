// C2105052Parser.g4
parser grammar C2105052Parser;

options {
	tokenVocab = C2105052Lexer;
}

@parser::header {
    #include <iostream>
    #include <fstream>
    #include <string> 
    #include <cstdlib>
    #include "C2105052Lexer.h"

    extern std::ofstream parserLogFile;
    extern std::ofstream errorFile;
    extern std::ofstream tempFile; // global temp file stream
    extern std::ofstream asmFile; // global asm file stream
    extern int syntaxErrorCount;
    
    #include "2105052_symbol_table.hpp"
	extern SymbolTable *symbolTable;
}

@parser::members {
    int stack_offset=0;
    int label_count = 1;
    int func_return_label = -1;

    void writeIntoparserLogFile(const std::string message) {
        if (!parserLogFile) {
            std::cout << "Error opening parserLogFile.txt" << std::endl;
            return;
        }
        parserLogFile << message << std::endl;
        parserLogFile.flush();
    }

    void writeIntoErrorFile(const std::string message) {
        if (!errorFile) {
            std::cout << "Error opening errorLog.txt" << std::endl;
            return;
        }
        errorFile << message << std::endl;
        errorFile.flush();
    }



    void print_global_var(string name,string type) {
        if(type == "int"){
            tempFile << "\t"<< name << " DW 1 DUP (0000H)" <<endl;
        }
        if(type == "int_array"){
            // extracting name and size from var.first
            string Name, size_str;
            size_t pos = name.find('[');
            if (pos != string::npos) {
                Name = name.substr(0, pos);
                size_str = name.substr(pos + 1);
                size_str = size_str.substr(0, size_str.size() - 1); // remove ']'
            } 
            int size = stoi(size_str);
            tempFile << "\t" << Name << " DW " << size << " DUP (0000H)" << endl;
        
         }
         
    }


    void handle_assign_op(SymbolTable *symbolTable, const string &varName, int &stack_offset) {
    string var;
    // Check if the variable is an array
    if (varName.find('[') != string::npos) {
        var = varName.substr(0, varName.find('['));
    } else {
        var = varName;
    }
    SymbolInfo *symbol = symbolTable->look_up_in_all_scope(var);
    // // cout<<"Assigning "<<varName<<" with scope id "<<endl;
    if(symbol==nullptr) {return;}
    if(symbol->getScopeId()==1){
        string str = "\tPOP AX";
        asmFile << str << endl;
        if(var!=varName){
            str = "\tPOP BX";
            asmFile << str << endl;
            str = "\tPUSH AX";
            asmFile << str << endl;
            str = "\tMOV AX, 2";
            asmFile << str << endl;
            str = "\tMUL BX";
            asmFile << str << endl;
            str = "\tMOV BX, AX";
            asmFile << str << endl;
            str = "\tPOP AX";
            asmFile << str << endl;
            str = "\tMOV " + var +"[BX], AX";
        }
        else
            str = "\tMOV " + symbol->getName() + ", AX";
        asmFile << str << endl;
        stack_offset -= 2;
    }
    else {
        string str = "\tPOP AX";
        int offset = symbol->getOffset();
        asmFile << str << endl;
        if(var!=varName){
            str = "\tPOP BX";
            asmFile << str << endl;
            str = "\tPUSH AX";
            asmFile << str << endl;
            str = "\tMOV AX, 2";
            asmFile << str << endl;
            str = "\tMUL BX";
            asmFile << str << endl;
            str = "\tMOV BX, AX";
            asmFile << str << endl;
            str = "\tMOV AX, " + std::to_string(offset);
            asmFile << str << endl;
            str = "\tSUB AX, BX";
            asmFile << str << endl;
            str = "\tMOV BX, AX";
            asmFile << str << endl;
            str = "\tPOP AX";
            asmFile << str << endl;
            str = "\tMOV SI, BX";
            asmFile << str << endl;
            str = "\tNEG SI";
            asmFile << str << endl;
            str = "\tMOV [BP + SI], AX";
        }
        else
        str = "\tMOV [BP" + std::string(offset>=0 ? "-" : "+") + std::to_string(abs(offset)) + "], AX";
        asmFile << str << endl;

        stack_offset -= 2;
    }
    // // cout<<"done assigning "<<varName<<" with scope id "<<symbol->getScopeId()<<endl;
}



void handle_var_declaration(SymbolInfo *symbol, int& stack_offset,string name, string type) {
    if(symbol->getScopeId()==1) return;
    if(type=="int"){
    stack_offset += 2;
    symbol->setOffset(stack_offset);
    // cout<<"Variable "<<symbol->getName()<<" declared with offset "<<stack_offset<<endl;
    asmFile << "\tSUB SP, 2" <<endl;
    }
    else if(type=="int_array"){
        // extracting size from name
        string size_str;
        size_t pos = name.find('[');
        if (pos != string::npos) {
            size_str = name.substr(pos + 1);
            size_str = size_str.substr(0, size_str.size() - 1); // remove ']'
        } else {
            size_str = "1"; // default size if not specified
        }
        int size = stoi(size_str);
        stack_offset += 2 * size;
        symbol->setOffset(stack_offset);
        // cout<<"Array "<<symbol->getName()<<" declared with offset "<<stack_offset<<endl;
        string ab = "\tSUB SP, " + std::to_string(2 * size);
        asmFile << ab << endl;
    }
}











    void insertFunctionToSymbolTable(string funcName, string funcType, vector<pair<string, string>> params, int line) {
            string type = "FUNCTION " + funcType;
            for (const auto &param : params) {
                type += " " + param.first;
            }
            SymbolInfo *sym = new SymbolInfo(funcName, type);
            symbolTable->insert(sym);
    }



    void insertIdInSymbolTable(string name, string type, int line) { 
        SymbolInfo *existing = symbolTable->look_up(name);
        if (existing != nullptr) {
            writeIntoErrorFile("Error at line " + std::to_string(line) + ": Multiple declaration of " + name + "\n");
            writeIntoparserLogFile("Error at line " + std::to_string(line) + ": Multiple declaration of " + name + "\n");
            syntaxErrorCount++;
        } else {
            SymbolInfo *sym = new SymbolInfo(name, type);
            symbolTable->insert(sym);
        }
    }

}

start: p = program;

program
	returns[std::vector<std::string> code, int line]:
	program unit
	| unit;

unit
	returns[std::vector<string>unit_code, int line]:
	var_declaration
	| func_declaration
	| func_definition;

func_declaration
	returns[string func_def, int line]:
	t = type_specifier id = ID LPAREN pl = parameter_list RPAREN SEMICOLON {
          std::string funcName = $id->getText();
          std::string funcType = $t.txt;
          insertFunctionToSymbolTable(funcName, funcType, $pl.params, $id->getLine());
      }
	| t = type_specifier id = ID LPAREN RPAREN SEMICOLON {
          std::string funcName = $id->getText();
          std::string funcType = $t.txt;
            insertFunctionToSymbolTable(funcName, funcType, vector<pair<string,string>>(), $id->getLine());

      };

func_definition
	returns[vector<string> code, int line]:
	t = type_specifier id = ID LPAREN pl = parameter_list RPAREN {
         insertFunctionToSymbolTable($id->getText(), $t.txt, $pl.params, $id->getLine());
        if($id->getText()=="main"){
            asmFile << "main PROC" << endl;
            asmFile << "\tMOV AX, @DATA" << endl;
            asmFile << "\tMOV DS, AX" << endl;
           
        } 
        else{
            // cout<<"Function name: "<<$id->getText()<<endl;
            string ab = $id->getText()+" PROC\t\t; line " + std::to_string($id->getLine());
            asmFile << ab << endl;;

        }
        // curr_func_name = $id->getText();
        asmFile<< "\tPUSH BP" << endl;
        asmFile<< "\tMOV BP, SP" << endl;
        stack_offset = 0;
        func_return_label = label_count; // Store the label index for the function return
        label_count++;
      } c = compound_statement[$pl.params] {
        $code = vector<string>();
         writeIntoparserLogFile("Line " + std::to_string($c.line) + ": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n");
          std::string funcName = $id->getText();
          std::string funcType =$t.txt;
          string str = funcType + " " + funcName + "(";
            for (size_t i = 0; i < $pl.params.size(); ++i){
                str += $pl.params[i].first;
                if($pl.params[i].second!="")
                    str +=" "+ $pl.params[i].second;
                
                if (i < $pl.params.size() - 1) {
                    str += ",";
                }
            }
            str += ")";
            for (const auto &line : $compound_statement.code) {
                str += line;
                $code.push_back(str);
                writeIntoparserLogFile(str);
                str = "";
            }
            writeIntoparserLogFile("");
            $line = $c.line;



        if($id->getText()!="main"){
            str = "L" + std::to_string(func_return_label) + ":";
            label_count++;
            asmFile << str << endl;
            str = "\tMOV SP, BP";
            asmFile << str << endl;
            str = "\tPOP BP";
            asmFile << str << endl;
            str ="\tRET";
            if($pl.params.size() > 0) {
                str += " " + std::to_string($pl.params.size() * 2);
            }
            asmFile << str << endl;
            str = $id->getText() + " ENDP";
            asmFile << str << endl;
        }
        else{
            string str = "L" + std::to_string(func_return_label) + ":";
            asmFile << str << endl;
            str = "\tMOV SP, BP";
            asmFile << str << endl;
            str = "\tPOP BP";
            asmFile << str << endl;
            str = "\tMOV AX, 4CH";
            asmFile << str << endl;
            str = "\tINT 21H";
            asmFile << str << endl;
            str = $id->getText() + " ENDP";
            asmFile << str << endl;
        }
        




      }
	| t = type_specifier id = ID LPAREN RPAREN {
          // Function definition (no parameters)
          std::string funcName = $id->getText();
          std::string funcType = $t.txt;
          SymbolInfo *existing2 = symbolTable->look_up(funcName);
          insertFunctionToSymbolTable(funcName, funcType, vector<pair<string,string>>(), $id->getLine());
          if($id->getText()=="main"){
            asmFile << "main PROC" << endl;
            asmFile << "\tMOV AX, @DATA" << endl;
            asmFile << "\tMOV DS, AX" << endl;
           
          }
          else{
            // cout<<"Function name: "<<$id->getText()<<endl;
            string ab = $id->getText()+" PROC\t\t; line " + std::to_string($id->getLine());
            asmFile << ab << endl;;

        }
            // curr_func_name = $id->getText();
        asmFile<< "\tPUSH BP" << endl;
        asmFile<< "\tMOV BP, SP" << endl;
            func_return_label = label_count; // Store the label index for the function return
            label_count++;
        stack_offset = 0;
      } cs = compound_statement[vector<pair<string,string>>()] {
        $code = vector<string>();
        writeIntoparserLogFile("Line " + std::to_string($cs.line) + ": func_definition : type_specifier ID LPAREN RPAREN compound_statement\n");
        funcName = $id->getText();
         funcType = $t.txt;
        string str = funcType + " " + funcName + "()";
        for (const auto &line : $cs.code) {
            str+=line;
            $code.push_back(str);
            writeIntoparserLogFile(str);
            str="";
        }
        writeIntoparserLogFile("");
        $line = $cs.line; 

        if($id->getText()!="main"){
            str = "L" + std::to_string(func_return_label) + ":";
            asmFile << str << endl;
            str = "\tMOV SP, BP";
            asmFile << str << endl;
            str = "\tPOP BP";
            asmFile << str << endl;
            str ="\tRET";
            asmFile << str << endl;
            str = $id->getText() + " ENDP";
            asmFile << str << endl;
        }
        else{
            string str = "L" + std::to_string(func_return_label) + ":";
            asmFile << str << endl;
            str = "\tMOV SP, BP";
            asmFile << str << endl;
            str = "\tPOP BP";
            asmFile << str << endl;
            str = "\tMOV AX, 4CH";
            asmFile << str << endl;
            str = "\tINT 21H";
            asmFile << str << endl;
            str = $id->getText() + " ENDP";
            asmFile << str << endl;
        }
        
      
      };

compound_statement[vector<pair<string,string>> params]
	returns[vector<string> code, int line]:
	LCURL {
                symbolTable->enter_scope();
                int offset = -2-2*params.size();
                for (const auto &param : params) {
                    string paramName = param.second;
                    string paramType = param.first;
                    // // cout<<"paramName: "<<paramName<<endl;
                    // // cout<<"paramType: "<<paramType<<endl;
                    if(paramName!=""){
                    SymbolInfo* existing = new SymbolInfo(paramName, paramType);
                    symbolTable->insert(existing);
                    existing->setOffset(offset);
                    offset += 2;
                    }
                    
                    // else // cout<<"paramName is empsdfty"<<endl;
                }
            
            } st = statements RCURL {
            writeIntoparserLogFile("Line " + std::to_string($RCURL->getLine()) + ": compound_statement : LCURL statements RCURL\n");
            $code = vector<string>();
            $code.push_back("{");
            writeIntoparserLogFile("{");
            int te=0;
            for (const auto &line : $st.code) {
                writeIntoparserLogFile(line);
                te++;
                $code.push_back(line);
            }
            $code.push_back("}");
            // // cout<<te<<endl;
            string str = "}\n";
            writeIntoparserLogFile(str);
            symbolTable->print_all_scope_in_file(parserLogFile);
            writeIntoparserLogFile("");
            symbolTable->exit_scope();
          
            $line = $RCURL->getLine();
            }
	| LCURL RCURL {
            symbolTable->enter_scope();
            for(const auto &param : params) {
                string paramName = param.second;
                string paramType = param.first;
                // // cout<<"paramName: "<<paramName<<endl;
                // // cout<<"paramType: "<<paramType<<endl;
                if(paramName!="")
                symbolTable->insert(new SymbolInfo(paramName, paramType));
                // else // cout<<"paramName is empty"<<endl;
            }
            writeIntoparserLogFile("Line " + std::to_string($RCURL->getLine()) + ": compound_statement : LCURL RCURL\n");
            $code = vector<string>();
            $code.push_back("{}");
            writeIntoparserLogFile("{}\n");
            symbolTable->print_all_scope_in_file(parserLogFile);
            writeIntoparserLogFile("");
            symbolTable->exit_scope();
            $line = $RCURL->getLine();
            };
var_declaration
	returns[std::string txt, int line]:
	t = type_specifier dl = declaration_list sm = SEMICOLON {
            // // cout<<"Declaration list size: "<<$dl.nameList.size()<<endl;
            writeIntoparserLogFile("Line " + std::to_string($sm->getLine()) + ": var_declaration : type_specifier declaration_list SEMICOLON\n");
            string txt = $t.txt;
            txt += " ";
            for (const auto &name : $dl.nameList) {
                txt += name;
                string str;
                bool isArray = false;
                // cout<<"Name: "<<name<<endl;
                for(int i=0;i<name.size();i++) {if(name[i]!='[') {str+=name[i];} else {isArray = true;break;}}
                string type = $t.txt;
                if(isArray) {
                    type += "_array";
                }
                
                SymbolInfo *s = symbolTable->look_up(str);
                if(s->getType()== "ID")
                    s->setType(type);
                if (&name != &($dl.nameList.back())) {
                    txt += ",";
                }
                if(s->getScopeId()==1){
                    print_global_var(name,type);
                }
                handle_var_declaration(s,stack_offset,name,type);
            }
            txt+=";";
            // // cout<<"Declaraction list size: "<<$dl.nameList.size()<<endl;
            if($t.type == "VOID") {
                writeIntoErrorFile("Error at line " + std::to_string($sm->getLine()) + ": Variable type cannot be void\n");
                syntaxErrorCount++;
                writeIntoparserLogFile("Error at line " + std::to_string($sm->getLine()) + ": Variable type cannot be void\n");
            }

            writeIntoparserLogFile(txt + "\n");
            $txt = txt;
            $line = $sm->getLine();
        }
	| t = type_specifier de = declaration_list_err sm = SEMICOLON {
          writeIntoErrorFile(
              std::string("Line# ") + std::to_string($sm->getLine()) +
              " with error name: " + $de.error_name +
              " - Syntax error at declaration list of variable declaration"
          );
          syntaxErrorCount++;
      };

declaration_list
	returns[std::vector<std::string> nameList]:
	dl = declaration_list COMMA ID {
          $nameList = $dl.nameList;
          $nameList.push_back($ID->getText());
            insertIdInSymbolTable($ID->getText(), "ID", $ID->getLine());
          writeIntoparserLogFile("Line " + std::to_string($ID->getLine()) + ": declaration_list : declaration_list COMMA ID\n");
            string str ;
            for (const auto &name : $nameList) {
               str+= name;
               if (&name != &($nameList.back())) {
                   str += ",";
               }
            }
            writeIntoparserLogFile(str + "\n");
      }
	| dl = declaration_list COMMA ID LTHIRD CONST_INT RTHIRD {
          $nameList = $dl.nameList;
          insertIdInSymbolTable($ID->getText(), "ID", $ID->getLine());
          string str = $ID->getText() + "[" + $CONST_INT->getText() + "]";
          $nameList.push_back(str);
          writeIntoparserLogFile("Line " + std::to_string($ID->getLine()) + ": declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n");
            string str2;
            for (const auto &name : $nameList) {
                str2 += name;
                if (&name != &($nameList.back())) {
                    str2 += ",";
                }
            }
            writeIntoparserLogFile(str2 + "\n");
      }
	| ID {
          $nameList = std::vector<std::string>();
          $nameList.push_back($ID->getText());
            insertIdInSymbolTable($ID->getText(), "ID", $ID->getLine());
            writeIntoparserLogFile("Line " + std::to_string($ID->getLine()) + ": declaration_list : ID\n");
            writeIntoparserLogFile($ID->getText()+ "\n");
      }
	| ID LTHIRD CONST_INT RTHIRD {
          $nameList = std::vector<std::string>();
          $nameList.push_back($ID->getText() + "[" + $CONST_INT->getText() + "]");
            insertIdInSymbolTable($ID->getText(), "ID", $ID->getLine());
            writeIntoparserLogFile("Line " + std::to_string($ID->getLine()) + ": declaration_list : ID LTHIRD CONST_INT RTHIRD\n");
            writeIntoparserLogFile($ID->getText() + "[" + $CONST_INT->getText() + "]\n");
      }
	| first = ID op = ADDOP second = ID {
            writeIntoparserLogFile("Line " + std::to_string($op->getLine()) + ": declaration_list : ID\n");
            writeIntoparserLogFile($first->getText()+"\n");
            insertIdInSymbolTable($first->getText(), "ID", $first->getLine());
            writeIntoErrorFile("Error at line " + std::to_string($op->getLine()) + ": syntax error, unexpected ADDOP, expecting COMMA or SEMICOLON\n");
            syntaxErrorCount++;
            writeIntoparserLogFile("Error at line " + std::to_string($op->getLine()) + ": syntax error, unexpected ADDOP, expecting COMMA or SEMICOLON\n");
            $nameList = std::vector<std::string>();
             $nameList.push_back($first->getText());
      }
	| pl = declaration_list COMMA ID ADDOP ID {
            // This is an error case, where ADDOP is used incorrectly
            writeIntoErrorFile("Error at line " + std::to_string($ADDOP->getLine()) + ": syntax error, unexpected ADDOP, expecting COMMA or RTHIRD\n");
            syntaxErrorCount++;
            writeIntoparserLogFile("Error at line " + std::to_string($ADDOP->getLine()) + ": syntax error, unexpected ADDOP, expecting COMMA or RTHIRD\n");
            $nameList = $pl.nameList;
            // // cout<<"Matched with declaration_list COMMA ID ADDOP ID"<<endl;
            $nameList.push_back($ID->getText());
      };

declaration_list_err
	returns[std::string error_name]:
	{
    $error_name = "Error in declaration list";
};

type_specifier
	returns[std::string txt, std::string type]:
	INT { 
        // // cout<<"INT at"<<$INT->getLine()<<endl;
       $txt = $INT->getText();
         $type = "INT";
       writeIntoparserLogFile("Line " + std::to_string($INT->getLine()) + ": type_specifier : INT\n");
       writeIntoparserLogFile($INT->getText() + "\n");
    }
	| FLOAT {
            $txt = $FLOAT->getText();
            $type = "FLOAT";
         writeIntoparserLogFile("Line " + std::to_string($FLOAT->getLine()) + ": type_specifier : FLOAT\n");
            writeIntoparserLogFile($FLOAT->getText() + "\n");
     }
	| VOID { 
            $txt = $VOID->getText();
            $type = "VOID";
         writeIntoparserLogFile("Line " + std::to_string($VOID->getLine()) + ": type_specifier : VOID\n");
            writeIntoparserLogFile($VOID->getText() + "\n");
      };

parameter_list
	returns[std::vector<std::pair<std::string,std::string>> params]:
	t = type_specifier id = ID {
        // first parameter: start fresh
        $params = {};
        $params.emplace_back($t.txt, $id->getText());
        writeIntoparserLogFile("Line " + std::to_string($id->getLine()) + ": parameter_list : type_specifier ID\n");
        writeIntoparserLogFile($t.txt + " " + $id->getText() + "\n");
        
    }
	| pl = parameter_list COMMA t = type_specifier id = ID {
        // additional parameter: copy old list then append
        $params = $pl.params;
        pair<string, string> newParam($t.txt, $id->getText());
        string str;
        for (const auto &p : $params) {
            if (p.first == newParam.first && p.second == newParam.second) {
                writeIntoErrorFile("Error at line " + std::to_string($id->getLine()) + ": Multiple declaration of " + $id->getText() + " in parameter\n");
                syntaxErrorCount++;
                writeIntoparserLogFile("Error at line " + std::to_string($id->getLine()) + ": Multiple declaration of " + $id->getText() + " in parameter\n");
                
            }
            str+= p.first + " " + p.second+",";
        }
        
        str+= $t.txt + " " + $id->getText();
        $params.push_back(newParam);
        writeIntoparserLogFile("Line " + std::to_string($id->getLine()) + ": parameter_list : parameter_list COMMA type_specifier ID\n");
        writeIntoparserLogFile(str + "\n");
    }
	| t = type_specifier ADDOP {
        writeIntoparserLogFile("Line " + std::to_string($ADDOP->getLine()) + ": parameter_list : type_specifier\n");

        writeIntoparserLogFile($t.txt+"\n");

        writeIntoErrorFile("Error at line " + std::to_string($ADDOP->getLine()) + ": syntax error, unexpected ADDOP, expecting RPAREN or COMMA\n");
        syntaxErrorCount++;
        writeIntoparserLogFile("Error at line " + std::to_string($ADDOP->getLine()) + ": syntax error, unexpected ADDOP, expecting RPAREN or COMMA\n");
        $params = {};
        $params.emplace_back($t.txt, "");
    };

statements
	returns[vector<string> code, int line]:
	st = statement {
        writeIntoparserLogFile("Line " + std::to_string($st.line) + ": statements : statement\n");
        $code = $st.code;
        $line = $st.line;
        for (const auto &line : $code) {
            writeIntoparserLogFile(line + "\n");

        }
    }
	| ss = statements s = statement {
        writeIntoparserLogFile("Line " + std::to_string($s.line) + ": statements : statements statement\n");
        $code = $ss.code;
        for (const auto &line : $s.code) {
            $code.push_back(line);
        }
        $line = $s.line;
        for (const auto &line : $code) {
            writeIntoparserLogFile(line);
        }
        writeIntoparserLogFile("");
    };

statement
	returns[vector<string> code, int line]:
	var = var_declaration { 
        writeIntoparserLogFile("Line " + std::to_string($var.line) + ": statement : var_declaration\n");
        $code = vector<string>();
        $code.push_back($var.txt);
        $line = $var.line;
        writeIntoparserLogFile($var.txt + "\n");
    }
	| es = expression_statement { 
        writeIntoparserLogFile("Line " + std::to_string($es.line) + ": statement : expression_statement\n");
        $code = vector<string>();
        $code.push_back($es.str);
        $line = $es.line;
        writeIntoparserLogFile($es.str + "\n");
    }
	| c = compound_statement[vector<pair<string,string>>()] {

        writeIntoparserLogFile("Line " + std::to_string($c.line) + ": statement : compound_statement\n");
        $code = vector<string>();
        for (const auto &line : $c.code) {
            $code.push_back(line);
        }
        $line = $c.line;
        for (const auto &line : $code) {
            writeIntoparserLogFile(line);
        }
        writeIntoparserLogFile("");
    }
	| FOR LPAREN e1 = expression_statement {
        int loop_end_label_index = -1;
        int statement_label_index = -1;
        int increment_label = -1;
        int loop_condition_label = -1;
        string ab = "L" + std::to_string(label_count) + ":";
        loop_condition_label = label_count;
        label_count++;
        asmFile << ab << endl;;

    } e2 = expression_statement {
        ab = "\tPOP AX\t\t; line " + std::to_string($e2.line);
        asmFile << ab << endl;;
        stack_offset -= 2; // Decrease stack offset by 2 for loop condition
        ab = "\tCMP AX, 0\t\t; line " + std::to_string($e2.line);
        asmFile << ab << endl;;
        ab = "\tJE L" + std::to_string(label_count) + "\t\t; line " + std::to_string($e2.line);
        asmFile << ab << endl;;
        loop_end_label_index = label_count; // Store the index of the loop end label for later use
        label_count++; // Increment label count for the next label
        ab = "\tJMP L" + std::to_string(label_count) + "\t\t; line " + std::to_string($e2.line);
        asmFile << ab << endl;;
        statement_label_index = label_count; // Store the index of the statement label for later use
        label_count++; // Increment label count for the next label
        increment_label = label_count;
    } e3 = expression RPAREN {
        ab = "\tJMP L" + std::to_string(loop_condition_label) + "\t\t; line " + std::to_string($e3.line);
        asmFile << ab << endl;;
        ab = "L" + std::to_string(statement_label_index) + ":";
        asmFile << ab << endl;;
    } s = statement {
        writeIntoparserLogFile("Line " + std::to_string($s.line) + ": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n");
        $code = vector<string>();
        string ss = "for(" + $e1.str + $e2.str + $e3.str + ")";
        for (const auto &line : $s.code) {
            ss += line;
            $code.push_back(ss);
            writeIntoparserLogFile(ss);
            ss = "";
        }
        $line = $s.line;
        writeIntoparserLogFile("");


        
        ss = "L" + std::to_string(label_count) + ":";
        label_count++;
        asmFile << ss << endl;


        ss = "\tJMP L" + std::to_string(increment_label) + "\t\t; line " + std::to_string($s.line);
        asmFile << ss << endl;
        ss = "L" + std::to_string(loop_end_label_index) + ":";
        asmFile << ss << endl;



    }
	| IF LPAREN expression RPAREN {
        string str;
        str = "L" + std::to_string(label_count) + ":";
        label_count++;
        asmFile << str << endl;
        int if_label_index = -1;

        str = "\tPOP AX\t\t; line ";
        asmFile << str << endl;
        stack_offset -= 2; // Decrease stack offset by 2 for if condition
        str = "\tCMP AX, 0\t\t; line " ;
        asmFile << str << endl;
        str = "\tJE L" + std::to_string(label_count);
        asmFile << str << endl;
        if_label_index = label_count; // Store the index of the if label for later use
        label_count++; // Increment label count for the next label
    } s = statement {
        str = "L" + std::to_string(if_label_index) + ":";
        asmFile << str << endl;
        writeIntoparserLogFile("Line " + std::to_string($s.line) + ": statement : IF LPAREN expression RPAREN statement\n");
        $code = vector<string>();
        string ss= "if(" + $expression.str + ")";
        for (const auto &line : $s.code) {
            ss+= line;
            $code.push_back(ss);
            writeIntoparserLogFile(ss);
            ss="";
        }
        $line = $s.line;
        writeIntoparserLogFile("");


        


    }
	| IF LPAREN ex = expression RPAREN {
        int if_label_index = -1;

        string str = "\tPOP AX\t\t; line " + std::to_string($ex.line);
        asmFile << str << endl;
        stack_offset -= 2; // Decrease stack offset by 2 for if condition
        str = "\tCMP AX, 0\t\t; line " + std::to_string($ex.line);
        asmFile << str << endl;
        str = "\tJE L" + std::to_string(label_count) + "\t\t; line " + std::to_string($ex.line);
        asmFile << str << endl;
        if_label_index = label_count; // Store the index of the if label for later use
        label_count++; // Increment label count for the next label

        



    } s1 = statement {
        int jump_at_end = label_count;
         str = "\tJMP L" + std::to_string(label_count) + "\t\t; line " + std::to_string($s1.line);
        asmFile << str << endl;
        label_count++; // Increment label count for the next label
    } ELSE {
        str = "L" + std::to_string(if_label_index) + ":";
        asmFile << str << endl;
        
        if_label_index = -1; // Reset the index after using it
    } s2 = statement {
        writeIntoparserLogFile("Line " + std::to_string($s2.line) + ": statement : IF LPAREN expression RPAREN statement ELSE statement\n");
        $code = vector<string>();
        string ss = "if(" + $ex.str + ")";
        for (const auto &line : $s1.code) {
            ss += line;
            
            
            // if line is not the last element of s1.code 
            if (&line != &($s1.code.back())) {
                $code.push_back(ss);
                writeIntoparserLogFile(ss);
                ss = "";
            }
        }
        ss += "else ";
        for (const auto &line : $s2.code) {
            ss += line;
            $code.push_back(ss);
            writeIntoparserLogFile(ss);
            ss = "";
        }
        $line = $s2.line;
        writeIntoparserLogFile("");


        str = "L" + std::to_string(jump_at_end) + ":";
        asmFile << str << endl;

        


    }
	| WHILE {
        int while_loop_condition_label = -1;
        int while_loop_end_label_index = -1;
        
        string cd = "L" + std::to_string(label_count) + ":";
        while_loop_condition_label = label_count;
        label_count++;
        asmFile << cd << endl;;

    } LPAREN expression {
        string ab;
        ab = "\tPOP AX";
        asmFile << ab << endl;;
        stack_offset -= 2; // Decrease stack offset by 2 for loop condition
        ab = "\tCMP AX, 0";
        asmFile << ab << endl;;
        ab = "\tJE L" + std::to_string(label_count);
        asmFile << ab << endl;;
        while_loop_end_label_index = label_count; // Store the index of the loop end label for later use
        label_count++; // Increment label count for the next label
    } RPAREN statement {
        writeIntoparserLogFile("Line " + std::to_string($statement.line) + ": statement : WHILE LPAREN expression RPAREN statement\n");
        $code = vector<string>();
        string ss = "while(" + $expression.str + ")";
        for (const auto &line : $statement.code) {
            ss += line;
            $code.push_back(ss);
            writeIntoparserLogFile(ss);
            ss = "";
        }
        $line = $statement.line;
        writeIntoparserLogFile("");

        ss = "\tJMP L" + std::to_string(while_loop_condition_label) + "\t\t; line " + std::to_string($statement.line);
        asmFile << ss << endl;
        ss = "L" + std::to_string(while_loop_end_label_index) + ":";
        asmFile << ss << endl;

    }
	| PRINTLN LPAREN ID RPAREN SEMICOLON {
        writeIntoparserLogFile("Line " + std::to_string($ID->getLine()) + ": statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n");
        $code = vector<string>();
        $code.push_back("printf(" + $ID->getText() + ");");
        writeIntoparserLogFile($code.back() + "\n");
        $line = $ID->getLine();
        string str;
        SymbolInfo *s = symbolTable->look_up_in_all_scope($ID->getText());
        






        str+="L"+std::to_string(label_count) + ":";
        label_count++;
        asmFile << str << endl;
        if(s!=nullptr){ 
            if(s->getScopeId()==1){
                str = "\tMOV AX, " + $ID->getText() + "\t\t; line" + std::to_string($ID->getLine());
                asmFile << str << endl;
                str = "\tCALL print_output";
                asmFile << str << endl;
                str = "\tCALL new_line";
                asmFile << str << endl;
            }
            else{

                str = "\tMOV AX, [BP" + std::string((s->getOffset() >= 0) ? "-" : "+") + std::to_string(std::abs(s->getOffset())) + "]\t\t; line " + std::to_string($ID->getLine());
                asmFile << str << endl;
                str = "\tCALL print_output";
                asmFile << str << endl;
                str = "\tCALL new_line";
                asmFile << str << endl;
            }
        }
        else{
            str = "\tMOV AX, " + $ID->getText() + "\t\t; line" + std::to_string($ID->getLine());
            asmFile << str << endl;
            str = "\tCALL print_output";
            asmFile << str << endl;
            str = "\tCALL new_line";
            asmFile << str << endl;
        }
        

        
    }
	| RETURN expr = expression SEMICOLON {
        writeIntoparserLogFile("Line " + std::to_string($expr.line) + ": statement : RETURN expression SEMICOLON\n");
        $code = vector<string>();
        $code.push_back($RETURN->getText() + " " + $expr.str + ";");
        writeIntoparserLogFile($code.back() + "\n");
        $line = $expr.line;
        

        string str;
        str = "L" + std::to_string(label_count) + ":";
        label_count++;
        asmFile << str << endl;
        SymbolInfo *s = symbolTable->look_up_in_all_scope($expr.str);
        if(s!=nullptr){
            if(s->getScopeId()==1){
                str = "\tMOV AX, " + $expr.str + "\t\t; line " + std::to_string($expr.line);
                asmFile << str << endl;   
            }
            else{
                str = "\tMOV AX, [BP" + std::string((s->getOffset() >= 0) ? "-" : "+") + std::to_string(std::abs(s->getOffset())) + "]\t\t; line " + std::to_string($expr.line);
                asmFile << str << endl;
            }
        }
        else{
            str = "\tPOP AX\t\t; line " + std::to_string($expr.line);
            asmFile << str << endl;
        }
        str = "\tJMP L" + std::to_string(func_return_label) + "\t\t; line " + std::to_string($expr.line);
        asmFile << str << endl;
    };

expression_statement
	returns[ string str, int line]:
	SEMICOLON {
        writeIntoparserLogFile("Line " + std::to_string($SEMICOLON->getLine()) + ": expression_statement : SEMICOLON\n");
        $str = ";";
        $line = $SEMICOLON->getLine();
        writeIntoparserLogFile($str + "\n");
    }
	| exp = expression SEMICOLON { 
        writeIntoparserLogFile("Line " + std::to_string($exp.line) + ": expression_statement : expression SEMICOLON\n");
        $str = $exp.str;
        $line = $exp.line;
        if ($str.empty()) {
            $str = ";";
        } else {
            $str += ";";
        }
        writeIntoparserLogFile($str + "\n");
    };

variable
	returns[std::string varName, int line]:
	ID {
        writeIntoparserLogFile("Line " + std::to_string($ID->getLine()) + ": variable : ID\n");
        writeIntoparserLogFile($ID->getText() + "\n");
        $varName = $ID->getText();
        $line = $ID->getLine();
     }
	| ID LTHIRD expression RTHIRD { 
        writeIntoparserLogFile("Line " + std::to_string($ID->getLine()) + ": variable : ID LTHIRD expression RTHIRD\n");
        string str = $ID->getText() + "[" + $expression.str + "]";
        writeIntoparserLogFile($ID->getText() + "[" + $expression.str + "]\n");
        $varName = $ID->getText() + "[" + $expression.str + "]";
        if ($expression.str.empty()) {
            writeIntoErrorFile("Error at line " + std::to_string($ID->getLine()) + ": Empty expression in array index\n");
            syntaxErrorCount++;
        }
        $line = $ID->getLine();
        



    };

expression
	returns[string str, int line]:
	l_expr = logic_expression {
        writeIntoparserLogFile("Line " + std::to_string($l_expr.line) + ": expression : logic_expression\n");
        $str = "";
        for (const auto &term : $l_expr.rel_expr) {
            $str += term;
        }
        $line = $l_expr.line;
        writeIntoparserLogFile($str + "\n");
    }
	| var = variable ASSIGNOP l_expr = logic_expression {
        writeIntoparserLogFile("Line " + std::to_string($l_expr.line) + ": expression : variable ASSIGNOP logic_expression\n");
        $str = $var.varName + "=";
        string logicExpr;
        for (const auto &term : $l_expr.rel_expr){
            $str += term;
            logicExpr += term;
        }
        $line = $l_expr.line;
        writeIntoparserLogFile($str + "\n");
        

        handle_assign_op(symbolTable, $var.varName, stack_offset);
    };

logic_expression
	returns[vector<string> rel_expr, int line]:
	r_expr = rel_expression {
        writeIntoparserLogFile("Line " + std::to_string($r_expr.line) + ": logic_expression : rel_expression\n");
        $rel_expr = $r_expr.simple_expr;
        $line = $r_expr.line;
        string str;
        for (const auto &term : $rel_expr) {
            str += term;
        }
        writeIntoparserLogFile(str + "\n");

    }
	| r1 = rel_expression {
        string str;
        string temp = "L" + std::to_string(label_count) + ":";
        label_count++;
        asmFile << temp << endl;

            str = "\tPOP AX\t\t; line " + std::to_string($r1.line);
            asmFile << str << endl;
            stack_offset -= 2; // Decrease stack offset by 2 for logic expression
        

    } LOGICOP {
        temp = $LOGICOP->getText();
        int logic_op_on_false_jump_label = -1; // Initialize the logic operation jump label index
        int logic_op_on_true_jump_label = -1; // Initialize the logic operation jump label index
        if(temp=="||"){
            temp = "\tCMP AX, 0";
            asmFile << temp << endl;
            temp = "\tJNE L" + std::to_string(label_count) + "\t\t; line " + std::to_string($r1.line);
            asmFile << temp << endl;
            logic_op_on_true_jump_label = label_count; // Store the index of the logic operation jump label for later use
            label_count++; // Increment label count for the next label
            
        }
        else if(temp=="&&"){
            temp = "\tCMP AX, 0";
            asmFile << temp << endl;
            temp = "\tJE L" + std::to_string(label_count) + "\t\t; line " + std::to_string($r1.line);
            asmFile << temp << endl;
            logic_op_on_false_jump_label = label_count; // Store the index of the logic operation jump label for later use
            label_count++; // Increment label count for the next label
        }



    } r2 = rel_expression {
        writeIntoparserLogFile("Line " + std::to_string($r1.line) + ": logic_expression : rel_expression LOGICOP rel_expression\n");
        $rel_expr = $r1.simple_expr;
        $rel_expr.push_back($LOGICOP->getText());
        for (const auto &term : $r2.simple_expr){
            $rel_expr.push_back(term);
        }
        $line = $r1.line;
        for (const auto &term : $rel_expr) {
            str += term;
        }
        writeIntoparserLogFile(str + "\n");



        


        if($LOGICOP->getText()=="||"){

                str = "\tPOP AX";
                asmFile << str << endl;
                stack_offset -= 2;
            

            str = "\tCMP AX, 0";
            asmFile << str << endl;
            str = "\tJE L" + std::to_string(label_count) + "\t\t; line " + std::to_string($r1.line);
            asmFile << str << endl;

            str = "L" + std::to_string(logic_op_on_true_jump_label) + ":";
            asmFile << str << endl;
            str = "\tMOV AX, 1";
            asmFile << str << endl;
            str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string($r1.line);
            asmFile << str << endl;
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            asmFile << str << endl;
            str = "\tMOV AX, 0\t\t; line " + std::to_string($r1.line);
            asmFile << str << endl;

            str = "L" + std::to_string(label_count) + ":";
            asmFile << str << endl;
            str = "\tPUSH AX\t\t; line " + std::to_string($r1.line);
            asmFile << str << endl;
            stack_offset += 2; // Increase stack offset by 2 for logic expression
            label_count++;
        }

        else if($LOGICOP->getText() == "&&"){

                str = "\tPOP AX";
                asmFile << str << endl;
                stack_offset -= 2;


            str = "\tCMP AX, 0";
            asmFile << str << endl;
            str = "\tJE L" + std::to_string(logic_op_on_false_jump_label) + "\t\t; line " + std::to_string($r1.line);
            asmFile << str << endl;

            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            asmFile << str << endl;
            str = "\tMOV AX, 1";
            asmFile << str << endl;
            str = "\tJMP L" + std::to_string(label_count) + "\t\t; line " + std::to_string($r1.line);
            asmFile << str << endl;
            str = "L" + std::to_string(logic_op_on_false_jump_label) + ":";
            asmFile << str << endl;
            str = "\tMOV AX, 0\t\t; line " + std::to_string($r1.line);
            asmFile << str << endl;

            str = "L" + std::to_string(label_count) + ":";
            asmFile << str << endl;
            str = "\tPUSH AX\t\t; line " + std::to_string($r1.line);
            asmFile << str << endl;
            stack_offset += 2; // Increase stack offset by 2 for logic expression
            label_count++;
        
        }





    };

rel_expression
	returns[vector<string> simple_expr, int line]:
	s_expr = simple_expression {
        writeIntoparserLogFile("Line " + std::to_string($s_expr.line) + ": rel_expression : simple_expression\n");
        $simple_expr = $s_expr.terms;
        $line = $s_expr.line;
        string str;
        for (const auto &term : $simple_expr) {
            str += term;
        }
        writeIntoparserLogFile(str + "\n");
    }
	| s_expr = simple_expression RELOP ss = simple_expression {
        writeIntoparserLogFile("Line " + std::to_string($s_expr.line) + ": rel_expression : simple_expression RELOP simple_expression\n");
        $simple_expr = $s_expr.terms;
        $simple_expr.push_back($RELOP->getText());
        for (const auto &term : $ss.terms) {
            $simple_expr.push_back(term);
        }
        $line = $s_expr.line;
        string str;
        for (const auto &term : $simple_expr) {
            str += term;
        }
        writeIntoparserLogFile(str + "\n");



          str = "L" + std::to_string(label_count) + ":";
            label_count++;
            asmFile << str << endl;
            str = "\tPOP AX";
            asmFile << str << endl;
            stack_offset -= 2;
            str = "\tMOV DX, AX";
            asmFile << str << endl;
        
            str = "\tPOP AX";
            asmFile << str << endl;
            stack_offset -= 2;
        
        if($RELOP->getText() == "<="){
            str = "\tCMP AX, DX";
            asmFile << str << endl;
            str = "\tJLE L" + std::to_string(label_count) + "\t\t; line " + std::to_string($s_expr.line);
            asmFile << str << endl;
            str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string($s_expr.line);
            asmFile << str << endl;
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            asmFile << str << endl;
            str = "\tMOV AX, 1\t\t; line " + std::to_string($s_expr.line);
            asmFile << str << endl;
            str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string($s_expr.line);
            asmFile << str << endl;
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            asmFile << str << endl;
            str = "\tMOV AX, 0\t\t; line " + std::to_string($s_expr.line);
            asmFile << str << endl;
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            asmFile << str << endl;
            str = "\tPUSH AX\t\t; line " + std::to_string($s_expr.line);
            asmFile << str << endl;
            stack_offset += 2;
            
        }


        else if($RELOP->getText() == "<"){
            str = "\tCMP AX, DX";
            asmFile << str << endl;
            str = "\tJL L" + std::to_string(label_count) + "\t\t; line " + std::to_string($s_expr.line);
            asmFile << str << endl;
            str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string($s_expr.line);
            asmFile << str << endl;
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            asmFile << str << endl;
            str = "\tMOV AX, 1\t\t; line " + std::to_string($s_expr.line);
            asmFile << str << endl;
            str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string($s_expr.line);
            asmFile << str << endl;
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            asmFile << str << endl;
            str = "\tMOV AX, 0\t\t; line " + std::to_string($s_expr.line);
            asmFile << str << endl;
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            asmFile << str << endl;
            str = "\tPUSH AX\t\t; line " + std::to_string($s_expr.line);
            asmFile << str << endl;
            stack_offset += 2;
        }
        else if($RELOP->getText() == ">="){
            str = "\tCMP AX, DX";
            asmFile << str << endl;
            str = "\tJGE L" + std::to_string(label_count) + "\t\t; line " + std::to_string($s_expr.line);
            asmFile << str << endl;
            str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string($s_expr.line);
            asmFile << str << endl;
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            asmFile << str << endl;
            str = "\tMOV AX, 1\t\t; line " + std::to_string($s_expr.line);
            asmFile << str << endl;
            str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string($s_expr.line);
            asmFile << str << endl;
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            asmFile << str << endl;
            str = "\tMOV AX, 0\t\t; line " + std::to_string($s_expr.line);
            asmFile << str << endl;
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            asmFile << str << endl;
            str = "\tPUSH AX\t\t; line " + std::to_string($s_expr.line);
            asmFile << str << endl;
            stack_offset += 2;
        }

        else if($RELOP->getText() == ">"){
            str = "\tCMP AX, DX";
            asmFile << str << endl;
            str = "\tJG L" + std::to_string(label_count) + "\t\t; line " + std::to_string($s_expr.line);
            asmFile << str << endl;
            str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string($s_expr.line);
            asmFile << str << endl;
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            asmFile << str << endl;
            str = "\tMOV AX, 1\t\t; line " + std::to_string($s_expr.line);
            asmFile << str << endl;
            str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string($s_expr.line);
            asmFile << str << endl;
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            asmFile << str << endl;
            str = "\tMOV AX, 0\t\t; line " + std::to_string($s_expr.line);
            asmFile << str << endl;
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            asmFile << str << endl;
            str = "\tPUSH AX\t\t; line " + std::to_string($s_expr.line);
            asmFile << str << endl;
            stack_offset += 2;
        }
        else if($RELOP->getText() == "=="){
            str = "\tCMP AX, DX";
            asmFile << str << endl;
            str = "\tJE L" + std::to_string(label_count) + "\t\t; line " + std::to_string($s_expr.line);
            asmFile << str << endl;
            str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string($s_expr.line);
            asmFile << str << endl;
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            asmFile << str << endl;
            str = "\tMOV AX, 1\t\t; line " + std::to_string($s_expr.line);
            asmFile << str << endl;
            str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string($s_expr.line);
            asmFile << str << endl;
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            asmFile << str << endl;
            str = "\tMOV AX, 0\t\t; line " + std::to_string($s_expr.line);
            asmFile << str << endl;
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            asmFile << str << endl;
            str = "\tPUSH AX\t\t; line " + std::to_string($s_expr.line);
            asmFile << str << endl;
            stack_offset += 2; 
        }
        else if($RELOP->getText() == "!="){
            str = "\tCMP AX, DX";
            asmFile << str << endl;
            str = "\tJNE L" + std::to_string(label_count) + "\t\t; line " + std::to_string($s_expr.line);
            asmFile << str << endl;
            str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string($s_expr.line);
            asmFile << str << endl;
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            asmFile << str << endl;
            str = "\tMOV AX, 1\t\t; line " + std::to_string($s_expr.line);
            asmFile << str << endl;
            str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string($s_expr.line);
            asmFile << str << endl;
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            asmFile << str << endl;
            str = "\tMOV AX, 0\t\t; line " + std::to_string($s_expr.line);
            asmFile << str << endl;
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            asmFile << str << endl;
            str = "\tPUSH AX\t\t; line " + std::to_string($s_expr.line);
            asmFile << str << endl;
            stack_offset += 2;
        }



    };

simple_expression
	returns[vector<string> terms, int line]:
	t = term {
        writeIntoparserLogFile("Line " + std::to_string($t.line) + ": simple_expression : term\n");
        $terms = { $t.trm };
        $line = $t.line;
        writeIntoparserLogFile($t.trm + "\n");
    }
	| s = simple_expression ADDOP t = term {
        writeIntoparserLogFile("Line " + std::to_string($s.line) + ": simple_expression : simple_expression ADDOP term\n");
        $terms = $s.terms;
        $terms.push_back($ADDOP->getText());
        $terms.push_back($t.trm);
        // // cout<< $t.trm << endl;
        $line = $s.line;
        string str;
        for (const auto &term : $terms) {
            str += term;
        }
        $terms.clear();
        $terms.push_back(str);
        writeIntoparserLogFile(str + "\n");


        str = "L" + std::to_string(label_count) + ":";
        label_count++;
        asmFile << str << endl;
        
            str = "\tPOP AX";
            asmFile << str << endl;
            stack_offset -= 2;
        
        str = "\tMOV DX, AX";
        asmFile << str << endl;
        

        string s_term_merge;
        for (const auto &term : $s.terms) {
            s_term_merge += term;
        }


            str = "\tPOP AX";
            asmFile << str << endl;
            stack_offset -= 2;
        
        if ($ADDOP->getText() == "+") {
            str = "\tADD AX, DX";
            asmFile << str << endl;
            str = "\tPUSH AX\t\t; line " + std::to_string($s.line);
            asmFile << str << endl;
            stack_offset += 2;
        }
        else if ($ADDOP->getText() == "-") {
            str = "\tSUB AX, DX";
            asmFile << str << endl;
            str = "\tPUSH AX\t\t; line " + std::to_string($s.line);
            asmFile << str << endl;
            stack_offset += 2;
        } 



    }
    
;



term
	returns[string trm, int line]:
	u_expr = unary_expression {
        writeIntoparserLogFile("Line " + std::to_string($u_expr.line) + ": term : unary_expression\n");
        $trm = $u_expr.unary_expr;
        $line = $u_expr.line;
        writeIntoparserLogFile($trm + "\n");
    }
	| t = term MULOP u = unary_expression {
        writeIntoparserLogFile("Line " + std::to_string($t.line) + ": term : term MULOP unary_expression\n");
        $trm = $t.trm  + $MULOP->getText() + $u.unary_expr;
        $line = $t.line;
        writeIntoparserLogFile($trm + "\n");



        string str;

        str+="L"+std::to_string(label_count) + ":";
        label_count++;
        asmFile << str << endl;

        str = "\tPOP AX";
        asmFile << str << endl;
        str = "\tMOV CX, AX";
        asmFile << str << endl;
        stack_offset -= 2;

        str = "\tPOP AX";
        asmFile << str << endl;
        stack_offset -= 2;

        asmFile << "\tCWD" << endl;
        if ($MULOP->getText() == "*") {
            str = "\tMUL CX";
            asmFile << str << endl;
            str = "\tPUSH AX\t\t; line " + std::to_string($t.line);
            asmFile << str << endl;
            stack_offset += 2;

        } 
        else if( $MULOP->getText() == "/") {
            str = "\tDIV CX";
            asmFile << str << endl;
            str = "\tPUSH AX\t\t; line " + std::to_string($t.line);
            asmFile << str << endl;
            stack_offset += 2;
        }
        else{
            str = "\tDIV CX";
            asmFile << str << endl;
            str = "\tPUSH DX\t\t; line " + std::to_string($t.line);
            asmFile << str << endl;
            stack_offset += 2;
        }
        
    }
	| t = term UNRECOGNIZED {
        writeIntoErrorFile("Error at line " + std::to_string($UNRECOGNIZED->getLine()) + ": Unrecognized character " + $UNRECOGNIZED->getText()+"\n");
        writeIntoparserLogFile("Error at line " + std::to_string($UNRECOGNIZED->getLine()) + ": Unrecognized character " + $UNRECOGNIZED->getText()+"\n");
        syntaxErrorCount++;
        // // cout<<"Error at line "<<$UNRECOGNIZED->getLine()<<": "<<$UNRECOGNIZED->getText()<<" is not a valid token"<<endl;
        $trm =$t.trm;
        // // cout<<"Term at "<<$t.line<<": "<<$trm<<endl;
        $line = $t.line;
    };

unary_expression
	returns[std::string unary_expr, int line]:
	ADDOP unary_expression {
        writeIntoparserLogFile("Line " + std::to_string($unary_expression.line) + ": unary_expression : ADDOP unary_expression\n");
        $unary_expr = $ADDOP->getText() + $unary_expression.unary_expr;
        $line = $unary_expression.line;
        writeIntoparserLogFile($unary_expr + "\n");


        string str;
        str = "L" + std::to_string(label_count) + ":";
            label_count++;
            asmFile << str << endl;

            str = "\tPOP AX";
            asmFile << str << endl;
            stack_offset -= 2;

        if ($ADDOP->getText() == "+") {
            str = "\tPUSH AX\t\t; line " + std::to_string($unary_expression.line);
            asmFile << str << endl;
            stack_offset += 2;
        }
        else if ($ADDOP->getText() == "-") {
            str = "\tNEG AX\t\t; line " + std::to_string($unary_expression.line);
            asmFile << str << endl;
            str = "\tPUSH AX\t\t; line " + std::to_string($unary_expression.line);
            asmFile << str << endl;
            stack_offset += 2;
        }



    }
	| NOT unary_expression {
        writeIntoparserLogFile("Line " + std::to_string($unary_expression.line) + ": unary_expression : NOT unary_expression\n");
        $unary_expr = "!" + $unary_expression.unary_expr;
        $line = $unary_expression.line;
        writeIntoparserLogFile($unary_expr + "\n");


        string str;
        str = "L" + std::to_string(label_count) + ":";
        label_count++;
        asmFile << str << endl;
        str = "\tPOP AX\t\t; line " + std::to_string($unary_expression.line);
        asmFile << str << endl;
        stack_offset -= 2; // Decrease stack offset by 2 for unary expression
        str = "\tCMP AX, 0";
        asmFile << str << endl;
        str = "\tJE L" + std::to_string(label_count) + "\t\t; line " + std::to_string($unary_expression.line);
        asmFile << str << endl;
        str = "\tMOV AX, 0";
        asmFile << str << endl;
        str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string($unary_expression.line);
        asmFile << str << endl;
        str = "L" + std::to_string(label_count) + ":";
        asmFile << str << endl;
        label_count++;
        str = "\tMOV AX, 1\t\t; line " + std::to_string($unary_expression.line);
        asmFile << str << endl;
        str = "L" + std::to_string(label_count) + ":";
        asmFile << str << endl;
        label_count++;
        str = "\tPUSH AX\t\t; line " + std::to_string($unary_expression.line);
        asmFile << str << endl;
        stack_offset += 2; // Increase stack offset by 2 for unary expression


    }
	| fact = factor {
        $unary_expr = $fact.factorName;
        $line = $fact.line;

  
    };

factor
	returns[std::string factorName, int line]:
	var = variable { 
        $factorName = $var.varName;
        $line = $var.line;


        string str;
        string var;
        int pos = $var.varName.find("[");
        if (pos != std::string::npos) {
            var = $var.varName.substr(0, pos);
        } else {
            var = $var.varName;
        }
        str = "L" + std::to_string(label_count) + ":";
        label_count++;
        asmFile << str << endl;
        if($var.varName != var){
        string str2;
        str2 = "\tPOP BX";
        asmFile << str2 << endl;;
        stack_offset -= 2; // Decrease stack offset by 2 for array index
        str2 = "\tMOV AX, " + std::to_string(2);
        asmFile << str2 << endl;;
        str2 = "\tMUL BX";
        asmFile << str2 << endl;;
        str2 = "\tMOV BX, AX";
        asmFile << str2 << endl;;

        SymbolInfo *s = symbolTable->look_up_in_all_scope(var);

        if(s->getScopeId()==1){
            str2 = "\tMOV AX, " + var +"[BX]";
            asmFile << str2 << endl;;
            str2 = "\tPUSH AX";
            asmFile << str2 << endl;;
            stack_offset += 2; // Increase stack offset by 2 for array index
        }
        else{
            str2 = "\tMOV AX, "+ std::to_string(s->getOffset());
            asmFile << str2 << endl;;
            str2 = "\tSUB AX, BX";
            asmFile << str2 << endl;;
            str2 = "\tMOV BX, AX";
            asmFile << str2 << endl;;
            str2 = "\tMOV SI, BX";
            asmFile << str2 << endl;;
            str2 = "\tNEG SI";
            asmFile << str2 << endl;;
            str2 = "\tMOV AX, [BP + SI]";
            asmFile << str2 << endl;;
            str2 = "\tPUSH AX";
            asmFile << str2 << endl;;
            stack_offset += 2; // Increase stack offset by 2 for array index
            }
        }

        else{
            SymbolInfo *s = symbolTable->look_up_in_all_scope($var.varName);
            if(s!=nullptr){
                if(s->getScopeId()==1){
                    str = "\tMOV AX, " + $var.varName + "\t\t; line " + std::to_string($var.line);
                    asmFile << str << endl;
                }
                else{
                    str = "\tMOV AX, [BP" + std::string((s->getOffset() >= 0) ? "-" : "+") + std::to_string(std::abs(s->getOffset())) + "]\t\t; line " + std::to_string($var.line);
                    asmFile << str << endl;
                }
            }
            else{
                str = "\tPOP AX";
                asmFile << str << endl;
                stack_offset -= 2;
            }
            str = "\tPUSH AX\t\t; line " + std::to_string($var.line);
            asmFile << str << endl;
            stack_offset += 2;
        }

    }
	| ID LPAREN ar = argument_list RPAREN { 
        $factorName = $ID->getText() + "(";
        for (const auto &term : $ar.arg) {
            $factorName += term;
            if (&term != &($ar.arg.back())) {
                $factorName += ",";
            }
        }
        $factorName += ")";
        $line = $ID->getLine();



        string str;
        str = "L" + std::to_string(label_count) + ":";
        label_count++;
        asmFile << str << endl;
        str = "\tCALL " + $ID->getText() + "\t\t; line " + std::to_string($ID->getLine());
        asmFile << str << endl;
        str = "\tPUSH AX\t\t; line " + std::to_string($ID->getLine());
        asmFile << str << endl;
        stack_offset += 2;
    }
	| LPAREN exp = expression RPAREN {
        $factorName = "(" + $exp.str + ")";
        $line = $exp.line;
    }
	| c_int = CONST_INT {
        $factorName = $c_int->getText();
        $line = $c_int->getLine();

        string str;
        str+="L"+std::to_string(label_count)+ ":";
        label_count++;
        asmFile << str << endl;
        str = "\tMOV AX, "+$c_int->getText()+"\t\t; line "+std::to_string($c_int->getLine());
        asmFile << str << endl;
        str = "\tPUSH AX";
        asmFile << str << endl;
        stack_offset += 2;
        }
	| c_float = CONST_FLOAT {
        $factorName = $c_float->getText();
        $line = $c_float->getLine();
    }
	| variable INCOP { 
        $factorName = $variable.varName + "++";
        $line = $variable.line;


        string str;
        string var;
        int pos = $variable.varName.find("[");
        if (pos != std::string::npos) {
            var = $variable.varName.substr(0, pos);
        } 
        else {
            var = $variable.varName;
        }
        if($variable.varName != var){
        str = "L" + std::to_string(label_count) + ":";
        label_count++;
        asmFile << str << endl;

        string str2;
        str2 = "\tPOP BX";
        asmFile << str2 << endl;;
        stack_offset -= 2; // Decrease stack offset by 2 for array index
        str2 = "\tMOV AX, " + std::to_string(2);
        asmFile << str2 << endl;;
        str2 = "\tMUL BX";
        asmFile << str2 << endl;;
        str2 = "\tMOV BX, AX";
        asmFile << str2 << endl;;

        SymbolInfo *s = symbolTable->look_up_in_all_scope(var);

        if(s->getScopeId()==1){
            str2 = "\tMOV AX, " + var +"[BX]";
            asmFile << str2 << endl;;
            str2 = "\tPUSH AX";
            asmFile << str2 << endl;;
            stack_offset += 2; // Increase stack offset by 2 for array index
            str2 = "\tINC AX";
            asmFile << str2 << endl;;
            str2 = "\tMOV " + var + "[BX], AX";
            asmFile << str2 << endl;;

        }
        else{
            str2 = "\tMOV AX, "+ std::to_string(s->getOffset());
            asmFile << str2 << endl;;
            str2 = "\tSUB AX, BX";
            asmFile << str2 << endl;;
            str2 = "\tMOV BX, AX";
            asmFile << str2 << endl;;
            str2 = "\tMOV SI, BX";
            asmFile << str2 << endl;;
            str2 = "\tNEG SI";
            asmFile << str2 << endl;;
            str2 = "\tMOV AX, [BP + SI]";
            asmFile << str2 << endl;;
            str2 = "\tPUSH AX";
            asmFile << str2 << endl;;
            stack_offset += 2; // Increase stack offset by 2 for array index
            str2 = "\tINC AX";
            asmFile << str2 << endl;;
            str2 = "\tMOV [BP + SI], AX";
            asmFile << str2 << endl;;
            } 
        }


        else{
        SymbolInfo *s = symbolTable->look_up_in_all_scope($variable.varName);
         
        str = "L" + std::to_string(label_count) + ":";
        label_count++;
        asmFile << str << endl;

        if(s!=nullptr){
            if(s->getScopeId()==1){
                str = "\tMOV AX, " + $variable.varName + "\t\t; line " + std::to_string($variable.line);
                asmFile << str << endl;
            }
            else{
                str = "\tMOV AX, [BP" + std::string((s->getOffset() >= 0) ? "-" : "+") + std::to_string(std::abs(s->getOffset())) + "]\t\t; line " + std::to_string($variable.line);
                asmFile << str << endl;
            }
        }
        else{
            str = "\tPOP AX";
            asmFile << str << endl;
            stack_offset -= 2;
        }
        str = "\tPUSH AX\t\t; line " + std::to_string($variable.line);
        asmFile << str << endl;
        stack_offset += 2;
        str = "\tINC AX\t\t; line " + std::to_string($variable.line);
        asmFile << str << endl;

        str = "\tMOV [BP" + std::string((s->getOffset() >= 0) ? "-" : "+") + std::to_string(std::abs(s->getOffset())) + "], AX\t\t; line " + std::to_string($variable.line);
        asmFile << str << endl;
        }

    }
	| variable DECOP {
        $factorName = $variable.varName + "--";
        $line = $variable.line;


        string str;
        string var;
        int pos = $variable.varName.find("[");
        if (pos != std::string::npos) {
            var = $variable.varName.substr(0, pos);
        } 
        else {
            var = $variable.varName;
        }
        if($variable.varName != var){
                    str = "L" + std::to_string(label_count) + ":";
        label_count++;
        asmFile << str << endl;

            string str2;
        str2 = "\tPOP BX";
        asmFile << str2 << endl;;
        stack_offset -= 2; // Decrease stack offset by 2 for array index
        str2 = "\tMOV AX, " + std::to_string(2);
        asmFile << str2 << endl;;
        str2 = "\tMUL BX";
        asmFile << str2 << endl;;
        str2 = "\tMOV BX, AX";
        asmFile << str2 << endl;;

        SymbolInfo *s = symbolTable->look_up_in_all_scope(var);

        if(s->getScopeId()==1){
            str2 = "\tMOV AX, " + var +"[BX]";
            asmFile << str2 << endl;;
            str2 = "\tPUSH AX";
            asmFile << str2 << endl;;
            stack_offset += 2; // Increase stack offset by 2 for array index
            str2 = "\tINC AX";
            asmFile << str2 << endl;;
            str2 = "\tMOV " + var + "[BX], AX";
            asmFile << str2 << endl;;

        }
        else{
            str2 = "\tMOV AX, "+ std::to_string(s->getOffset());
            asmFile << str2 << endl;;
            str2 = "\tSUB AX, BX";
            asmFile << str2 << endl;;
            str2 = "\tMOV BX, AX";
            asmFile << str2 << endl;;
            str2 = "\tMOV SI, BX";
            asmFile << str2 << endl;;
            str2 = "\tNEG SI";
            asmFile << str2 << endl;;
            str2 = "\tMOV AX, [BP + SI]";
            asmFile << str2 << endl;;
            str2 = "\tPUSH AX";
            asmFile << str2 << endl;;
            stack_offset += 2; // Increase stack offset by 2 for array index
            str2 = "\tINC AX";
            asmFile << str2 << endl;;
            str2 = "\tMOV [BP + SI], AX";
            asmFile << str2 << endl;;
            } 
        }
        else{
        SymbolInfo *s = symbolTable->look_up_in_all_scope($variable.varName);
        str = "L" + std::to_string(label_count) + ":";
        label_count++;
        asmFile << str << endl;

        if(s!=nullptr){
            if(s->getScopeId()==1){
                str = "\tMOV AX, " + $variable.varName + "\t\t; line " + std::to_string($variable.line);
                asmFile << str << endl;
            }
            else{
                str = "\tMOV AX, [BP" + std::string((s->getOffset() >= 0) ? "-" : "+") + std::to_string(std::abs(s->getOffset())) + "]\t\t; line " + std::to_string($variable.line);
                asmFile << str << endl;
            }
        }
        else{
            str = "\tPOP AX";
            asmFile << str << endl;
            stack_offset -= 2;
        }
        str = "\tPUSH AX\t\t; line " + std::to_string($variable.line);
        asmFile << str << endl;
        stack_offset += 2;
        str = "\tDEC AX\t\t; line " + std::to_string($variable.line);
        asmFile << str << endl;
        str = "\tMOV [BP" + std::string((s->getOffset() >= 0) ? "-" : "+") + std::to_string(std::abs(s->getOffset())) + "], AX\t\t; line " + std::to_string($variable.line);
        asmFile << str << endl;

        }
    };

argument_list
	returns[std::vector<std::string> arg]:
	ar = arguments { 
        $arg = $ar.arg;
    }
	|;

arguments
	returns[std::vector<std::string> arg, int line]:
	ar = arguments COMMA l = logic_expression { 
        $arg = $ar.arg;
        string ab;
        for (const auto &term : $l.rel_expr) {
            ab += term;
        }
        $arg.push_back(ab);
        $line = $l.line;
    }
	| l = logic_expression { 
        $arg = std::vector<std::string>();
        for (const auto &term : $l.rel_expr) {
            $arg.push_back(term);
        }
        string str;
        for (const auto &term : $arg) {
            str += term;
        }
        $arg.clear();
        $arg.push_back(str);
        $line = $l.line;

    };