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
    #include "icg.hpp"
    extern std::ofstream parserLogFile;
    extern std::ofstream errorFile;
    extern std::vector<std::string> code;
    extern std::ofstream asmFile; // global asm file stream
    extern std::vector<std::pair<std::string, std::string>> global_vars; // global variable storage
    extern int inFunc; // global variable to track if we are inside a function
    extern int syntaxErrorCount;
    
    #include "2105052_symbol_table.hpp"
	extern SymbolTable *symbolTable;
}

@parser::members {
    int stack_offset=0;
    int label_count = 1;
    int curr_line = 0;
    int booked_label = 0;
    string curr_func_name = "";
    vector<int> if_label;
    int if_label_index = 0;
    vector<int> if_true_jump;
    int increment_label=0;
    int statement_label_index = 0;
    int loop_end_label_index =0;
    int loop_condition_label =0;
    int func_return_label = -1;
    int while_loop_end_label_index = 0;
    int while_loop_condition_label = 0;
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

    void insertFunctionToSymbolTable(string funcName, string funcType, vector<pair<string, string>> params, int line) {
        SymbolInfo *existing = symbolTable->look_up(funcName);
        if (existing != nullptr) {
            // cout<<existing->getName()<<endl;
            if(existing->isFunction()) {
                // cout<<"Function name: "<<funcName<<endl;
                // cout<<"Function type: "<<funcType<<endl;
                // cout<<"Existing function type: "<<existing->getReturnType()<<endl;
                if(existing->getReturnType() != funcType) {
                    writeIntoErrorFile("Error at line " + std::to_string(line) + ": Return type mismatch of " + funcName + "\n");
                    writeIntoparserLogFile("Error at line " + std::to_string(line) + ": Return type mismatch of " + funcName + "\n");
                    syntaxErrorCount++;
                }
                
                
                else if(params.size() != existing->getFuncParamType().size()) {
                    writeIntoErrorFile("Error at line " + std::to_string(line) + ": Total number of arguments mismatch with declaration in function " + funcName + "\n");
                    writeIntoparserLogFile("Error at line " + std::to_string(line) + ": Total number of arguments mismatch with declaration in function " + funcName + "\n");
                    syntaxErrorCount++;
                 }
                            
            }
            else {
                writeIntoErrorFile("Error at line " + std::to_string(line) + ": Multiple declaration of " + funcName + "\n");
                writeIntoparserLogFile("Error at line " + std::to_string(line) + ": Multiple declaration of " + funcName + "\n");
                syntaxErrorCount++;
            }

        }
        else{
            string type = "FUNCTION " + funcType;
            for (const auto &param : params) {
                type += " " + param.first;
            }
            SymbolInfo *sym = new SymbolInfo(funcName, type);
            symbolTable->insert(sym);
        } 
    }

    bool voidFuncRetTypeCheck(string funcName,string funcType, vector<string> code, int Line){
        if (funcType == "void") {
            for (const auto &line : code) {
                if (line.find("return") != std::string::npos) {
                    writeIntoErrorFile("Error at line " + std::to_string(Line) + ": Cannot return value from function " + funcName + " with void return type \n");
                    writeIntoparserLogFile("Error at line " + std::to_string(Line) + ": Cannot return value from function " + funcName + " with void return type \n");
                    syntaxErrorCount++;
                    return false;
                }
            }
        }
        return true;
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

    
    bool isValidParameterList(string funcName, vector<string> params,int line){
        SymbolInfo *func = symbolTable->look_up_in_all_scope(funcName);
        if(func == nullptr || !func->isFunction()){ 
            writeIntoErrorFile("Error at line " + std::to_string(line) + ": Undefined function " + funcName + "\n");
            writeIntoparserLogFile("Error at line " + std::to_string(line) + ": Undefined function " + funcName + "\n");
            syntaxErrorCount++;
            return false;
        }
        
        vector<string> funcParams = func->getFuncParamType();
        if(funcParams.size() != params.size()) {
            writeIntoErrorFile("Error at line " + std::to_string(line) + ": Total number of arguments mismatch with declaration in function " + funcName + "\n");
            writeIntoparserLogFile("Error at line " + std::to_string(line) + ": Total number of arguments mismatch with declaration in function " + funcName + "\n");
            syntaxErrorCount++;
            return false;
        }

        for(int i=0; i<params.size(); i++) {
            // cout<<"param: "<<params[i]<<endl;
            string param = params[i];
            bool isAllDigitswithdot = std::regex_match(param, std::regex("^[+-]?([0-9]*[.])?[0-9]+$"));
            if(funcParams[i] == "int" && isAllDigitswithdot==true && std::regex_match(param, std::regex("^[+-]?([0-9]*[.])+[0-9]*$"))==true) { 
                   writeIntoErrorFile("Error at line " + std::to_string(line) + ": " + to_string(i+1) + "th argument mismatch in function " + funcName + "\n");
                    writeIntoparserLogFile("Error at line " + std::to_string(line) + ": " + to_string(i+1) + "th argument mismatch in function " + funcName + "\n");
                    syntaxErrorCount++;
                    return false;
            }
            else if(funcParams[i] == "float" && isAllDigitswithdot==true && !std::regex_match(param, std::regex("^[+-]?([0-9]*[.])?[0-9]+$"))) { 
                writeIntoErrorFile("Error at line " + std::to_string(line) + ": " + to_string(i+1) + "th argument mismatch in function " + funcName + "\n");
                writeIntoparserLogFile("Error at line " + std::to_string(line) + ": " + to_string(i+1) + "th argument mismatch in function " + funcName + "\n");
                syntaxErrorCount++;
                return false;
            }
            
        }

        return true;
    }


    // variable using correctly

    bool isValidVariable(string var,string varName, int line) { 
        SymbolInfo *varInfo = symbolTable->look_up_in_all_scope(var);
        
        if (varInfo == nullptr) {
            // symbolTable->print_all_scope_in_file(parserLogFile);
            writeIntoErrorFile("Error at line " + std::to_string(line) + ": Undeclared variable " + varName + "\n");
            writeIntoparserLogFile("Error at line " + std::to_string(line) + ": Undeclared variable " + varName + "\n");
            syntaxErrorCount++;
            return false;
        }

        else if(varInfo->getType()=="int_array" || varInfo->getType()=="float_array") {
            bool isThirdBracket = false;
            for (char c : varName) {
                if (c == '[') {
                    isThirdBracket = true;
                    break;
                }
            }
            bool expressionInsideThirdBracketIsInt = true;
            if (isThirdBracket) {
                // Check if the expression inside the third bracket is an integer
                std::string expression = varName.substr(varName.find('[') + 1, varName.find(']') - varName.find('[') - 1);
                // cout<<"Expression inside third bracket: " << expression << endl;
                if (std::regex_match(expression, std::regex("^[+-]?([0-9]*[.])+[0-9]*+$"))) {
                    // cout<<"gotit"<<endl;
                    expressionInsideThirdBracketIsInt = false;
                }
            }
            if(expressionInsideThirdBracketIsInt==false){
                writeIntoErrorFile("Error at line " + std::to_string(line) + ": Expression inside third brackets not an integer\n");
                writeIntoparserLogFile("Error at line " + std::to_string(line) + ": Expression inside third brackets not an integer\n");
                syntaxErrorCount++;
                return false;
            }


            if (!isThirdBracket) {
                writeIntoErrorFile("Error at line " + std::to_string(line) + ": Type mismatch, " + varInfo->getName() + " is an array\n");
                writeIntoparserLogFile("Error at line " + std::to_string(line) + ": Type mismatch, " + varInfo->getName() + " is an array\n");
                syntaxErrorCount++;
                return false;
            }
        } 
        else if(varInfo->getType()=="int" || varInfo->getType()=="float") {
            bool isThirdBracket = false;
            for (char c : varName) {
                if (c == '[') {
                    isThirdBracket = true;
                    break;
                }
            }
            if (isThirdBracket) {
                writeIntoErrorFile("Error at line " + std::to_string(line) + ": "+ varInfo->getName() + " not an array\n");
                writeIntoparserLogFile("Error at line " + std::to_string(line) + ": " + varInfo->getName() + " not an array\n");
                syntaxErrorCount++;
                return false;
            }
        }
        
        return true;
    }

    bool isVoidFunction(string name){
        SymbolInfo *func = symbolTable->look_up_in_all_scope(name);
        if(func != nullptr && func->isFunction() && func->getReturnType() == "void") {
            return true;
        }
        return false;
    }

    bool isFuncInString(string str){ 
        // Check if the string contains a function call
        std::regex funcRegex(R"(\b[a-zA-Z_][a-zA-Z0-9_]*\s*\(.*?\))");
        return std::regex_search(str, funcRegex);
    }

    string getFuncNameFromString(string str) {
        // Extract the function name from the string
        std::regex funcRegex(R"(\b([a-zA-Z_][a-zA-Z0-9_]*)\s*\()");
        std::smatch match;
        if (std::regex_search(str, match, funcRegex)) {
            return match[1].str();
        }
        return "";
    }

    bool termExprCheck(string expr,int line) {
        if(isFuncInString(expr)){
            string funcName = getFuncNameFromString(expr);
            if(isVoidFunction(funcName)) {
                writeIntoErrorFile("Error at line " + std::to_string(line) + ": Void function used in expression\n");
                writeIntoparserLogFile("Error at line " + std::to_string(line) + ": Void function used in expression\n");
                syntaxErrorCount++;
                return false;
            }
        }
        return true;
    }

    string getArrayOrfuncName(string varName) {
       for(int i=0;i<varName.size();i++) {
            if(varName[i]=='[') {
                return varName.substr(0,i);
            }
            else if(varName[i]=='(') {
                return varName.substr(0,i);
            }
        }
        return varName;
    }

    bool isValidArrayVarCall(string varName){
        //check if [ is present and inside there is an int
        size_t pos = varName.find('[');
        if (pos != std::string::npos) {
            size_t endPos = varName.find(']', pos);
            if (endPos != std::string::npos) {
                std::string index = varName.substr(pos + 1, endPos - pos - 1);
                // Check if the index is an integer
                return std::regex_match(index, std::regex("^[0-9]+$"));
            }
        }
        return true;
    }

    bool isFloat(string str) {
        return std::regex_match(str, std::regex("^[+-]?([0-9]*[.])[0-9]+$"));
    }

    bool assignOpcheck(string left_side, string right_side, int line){
        string left = getArrayOrfuncName(left_side);
        string right = getArrayOrfuncName(right_side);
        SymbolInfo *leftInfo = symbolTable->look_up_in_all_scope(left);
        SymbolInfo *rightInfo = symbolTable->look_up_in_all_scope(right);
        bool isFloatRight = isFloat(right_side);
        if (leftInfo == nullptr) {
            return false;
        }
        else if(isFloatRight){ 
            if(leftInfo->getType() != "float" && leftInfo->getType() != "float_array") {
                writeIntoErrorFile("Error at line " + std::to_string(line) + ": Type Mismatch\n");
                writeIntoparserLogFile("Error at line " + std::to_string(line) + ": Type Mismatch\n");
                syntaxErrorCount++;
                return false;
            }
            return true;
        }
        else if(rightInfo == nullptr){
            return false;
        }

        else if (leftInfo->getType() != rightInfo->getType()) {
            if(rightInfo->getReturnType()=="void"){
                writeIntoErrorFile("Error at line " + std::to_string(line) + ": Void function used in expression\n");
                writeIntoparserLogFile("Error at line " + std::to_string(line) + ": Void function used in expression\n");
                syntaxErrorCount++;
                return false;
            }
            return false;
        }
        return true;    
    }



    bool termMulOpCheck(string left_side, string right_side, string mulop, int line){
        if(mulop == "%"){
            if(isFloat(right_side)==true){
                writeIntoErrorFile("Error at line " + std::to_string(line) + ": Non-Integer operand on modulus operator\n");
                writeIntoparserLogFile("Error at line " + std::to_string(line) + ": Non-Integer operand on modulus operator\n");
                syntaxErrorCount++;
                return false;
            }
            else if(right_side == "0"){
                writeIntoErrorFile("Error at line " + std::to_string(line) + ": Modulus by Zero\n");
                writeIntoparserLogFile("Error at line " + std::to_string(line) + ": Modulus by Zero\n");
                syntaxErrorCount++;
                return false;
            }
        }
        return true;
    }
}

start 
    : p = program {
          writeIntoparserLogFile("Line " + std::to_string( $p.line) + ": start : program\n");
          // Print the complete symbol table
          std::streambuf *oldCout3 = std::cout.rdbuf(parserLogFile.rdbuf());
          symbolTable->print_all_scope_in_file(parserLogFile);
          writeIntoparserLogFile("");
          writeIntoparserLogFile("Total number of lines: " + std::to_string($p.line));
            writeIntoparserLogFile("Total number of errors: " + std::to_string(syntaxErrorCount));        
          std::cout.rdbuf(oldCout3);
      }
    ; 

program returns [std::vector<std::string> code, int line]
    : p=program u=unit {
        writeIntoparserLogFile("Line " + std::to_string($u.line) + ": program : program unit\n");
        $code = $p.code;
        for (const auto &line : $u.unit_code) {
            $code.push_back(line);
        }
        for (const auto &line : $code) {
            writeIntoparserLogFile(line);
        }
        writeIntoparserLogFile("");
        $line = $u.line;
    } # Program_program_unit
    | u = unit {
        writeIntoparserLogFile("Line " + std::to_string($u.line) + ": program : unit\n");
        $code = std::vector<std::string>();
        for (const auto &line : $u.unit_code) {
            $code.push_back(line);
            writeIntoparserLogFile(line);
        }
        $line = $u.line;
        writeIntoparserLogFile("");

    } # Program_unit
    ;

unit returns [std::vector<string>unit_code, int line]
    : v=var_declaration {
        writeIntoparserLogFile("Line " + std::to_string($v.line) + ": unit : var_declaration\n");
        writeIntoparserLogFile($v.txt+ "\n"); 
        $unit_code = std::vector<string>();
        $unit_code.push_back($v.txt);
        $line = $v.line;
    }
    | f=func_declaration {
        writeIntoparserLogFile("Line " + std::to_string($f.line) + ": unit : func_declaration\n");
        writeIntoparserLogFile($f.func_def + "\n");
        $unit_code = std::vector<string>();
        $unit_code.push_back($f.func_def);
        $line = $f.line;
    }
    | f_def = func_definition { 
        writeIntoparserLogFile("Line " + std::to_string($f_def.line) + ": unit : func_definition\n");
        $unit_code = std::vector<string>();
        for (const auto &line : $f_def.code) {
            writeIntoparserLogFile(line);
            $unit_code.push_back(line);
        }
        writeIntoparserLogFile("");
        
        $line = $f_def.line;
    }
    ;

func_declaration returns [string func_def, int line]
    : t=type_specifier id=ID LPAREN pl=parameter_list RPAREN SEMICOLON {
          // Function declaration insertion
          std::string funcName = $id->getText();
          std::string funcType = $t.txt;
        
          writeIntoparserLogFile("Line " + std::to_string($id->getLine()) + ": func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n");
          string str = funcType + " " + funcName + "(";
            for (size_t i = 0; i < $pl.params.size(); ++i) {
                str += $pl.params[i].first + " " + $pl.params[i].second;
                if (i < $pl.params.size() - 1) {
                    str += ",";
                }
            }
            str += ");";
            $func_def = str;
            $line = $id->getLine();
          writeIntoparserLogFile(str + "\n");
          insertFunctionToSymbolTable(funcName, funcType, $pl.params, $id->getLine());
      }
    | t=type_specifier id=ID LPAREN RPAREN SEMICOLON {
          // Function declaration (no parameters)
          std::string funcName = $id->getText();
          std::string funcType = $t.txt;
          SymbolInfo *existing2 = symbolTable->look_up(funcName);
            writeIntoparserLogFile("Line " + std::to_string($id->getLine()) + ": func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n");
            string str2 = funcType + " " + funcName + "();";
            $func_def = str2;
            $line = $id->getLine();
            writeIntoparserLogFile(str2 + "\n");
            insertFunctionToSymbolTable(funcName, funcType, vector<pair<string,string>>(), $id->getLine());

      }
    ;

func_definition returns [vector<string> code, int line]
    : t=type_specifier id=ID LPAREN pl=parameter_list RPAREN {
         insertFunctionToSymbolTable($id->getText(), $t.txt, $pl.params, $id->getLine());
         for (const auto &param : $pl.params) {
            std::string paramName = param.second;
            std::string paramType = param.first;
         }
        if($id->getText()=="main"){
            handle_main_func_initialization(code);
           
        } 
        else{
            cout<<"Function name: "<<$id->getText()<<endl;
            string ab = $id->getText()+" PROC\t\t; line " + std::to_string($id->getLine());
            code.push_back(ab);

        }
        curr_func_name = $id->getText();
        function_initialization(code);
        inFunc++;
        stack_offset = 0;
      } c=compound_statement[$pl.params] {
        $code = vector<string>();
         voidFuncRetTypeCheck($id->getText(), $t.txt, $c.code, $c.line);
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
            inFunc--;



        if($id->getText()!="main"){
            str = "L" + std::to_string(label_count) + ":";
            if(func_return_label != -1) {
                code[func_return_label] = "\tJMP L" + std::to_string(label_count) + "\t\t; line " + std::to_string($c.line);
            func_return_label = -1; // Reset after using it
            }
            label_count++;
            code.push_back(str);
            str = "\tMOV SP, BP";
            code.push_back(str);
            str = "\tPOP BP";
            code.push_back(str);
            str ="\tRET";
            if($pl.params.size() > 0) {
                str += " " + std::to_string($pl.params.size() * 2);
            }
            code.push_back(str);
            str = $id->getText() + " ENDP";
            code.push_back(str);
        }
        else{
            string str = "L" + std::to_string(label_count) + ":";
            label_count++;
            code.push_back(str);
            str = "\tMOV SP, BP";
            code.push_back(str);
            str = "\tPOP BP";
            code.push_back(str);
            str = "\tMOV AX, 4CH";
            code.push_back(str);
            str = "\tINT 21H";
            code.push_back(str);
            str = $id->getText() + " ENDP";
            code.push_back(str);
        }
        




      }
    | t=type_specifier id=ID LPAREN RPAREN {
          // Function definition (no parameters)
          std::string funcName = $id->getText();
          std::string funcType = $t.txt;
          SymbolInfo *existing2 = symbolTable->look_up(funcName);
          insertFunctionToSymbolTable(funcName, funcType, vector<pair<string,string>>(), $id->getLine());
          if($id->getText()=="main"){
            handle_main_func_initialization(code);
          }
          else{
            cout<<"Function name: "<<$id->getText()<<endl;
            string ab = $id->getText()+" PROC\t\t; line " + std::to_string($id->getLine());
            code.push_back(ab);

        }
            curr_func_name = $id->getText();
            function_initialization(code);
        inFunc++;
        stack_offset = 0;
      } cs = compound_statement[vector<pair<string,string>>()] {
        $code = vector<string>();
        voidFuncRetTypeCheck($id->getText(), $t.txt, $cs.code, $cs.line);
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
        $line = $cs.line; inFunc--;

        if($id->getText()!="main"){
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            code.push_back(str);
            str = "\tMOV SP, BP";
            code.push_back(str);
            str = "\tPOP BP";
            code.push_back(str);
            str ="\tRET";
            code.push_back(str);
            str = $id->getText() + " ENDP";
            code.push_back(str);
        }
        else{
            string str = "L" + std::to_string(label_count) + ":";
            label_count++;
            code.push_back(str);
            str = "\tMOV SP, BP";
            code.push_back(str);
            str = "\tPOP BP";
            code.push_back(str);
            str = "\tMOV AX, 4CH";
            code.push_back(str);
            str = "\tINT 21H";
            code.push_back(str);
            str = $id->getText() + " ENDP";
            code.push_back(str);
        }
        
      
      }
    ;

compound_statement [vector<pair<string,string>> params] returns [vector<string> code, int line]
            : LCURL{
                symbolTable->enter_scope();
                int offset = -2-2*params.size();
                for (const auto &param : params) {
                    string paramName = param.second;
                    string paramType = param.first;
                    // cout<<"paramName: "<<paramName<<endl;
                    // cout<<"paramType: "<<paramType<<endl;
                    if(paramName!=""){
                    SymbolInfo* existing = new SymbolInfo(paramName, paramType);
                    symbolTable->insert(existing);
                    existing->setOffset(offset);
                    offset += 2;
                    }
                    
                    // else cout<<"paramName is empsdfty"<<endl;
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
            // cout<<te<<endl;
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
                // cout<<"paramName: "<<paramName<<endl;
                // cout<<"paramType: "<<paramType<<endl;
                if(paramName!="")
                symbolTable->insert(new SymbolInfo(paramName, paramType));
                // else cout<<"paramName is empty"<<endl;
            }
            writeIntoparserLogFile("Line " + std::to_string($RCURL->getLine()) + ": compound_statement : LCURL RCURL\n");
            $code = vector<string>();
            $code.push_back("{}");
            writeIntoparserLogFile("{}\n");
            symbolTable->print_all_scope_in_file(parserLogFile);
            writeIntoparserLogFile("");
            symbolTable->exit_scope();
            $line = $RCURL->getLine();
            }
 		    ;
var_declaration returns [std::string txt, int line]
    : t=type_specifier dl=declaration_list sm=SEMICOLON {
            // cout<<"Declaration list size: "<<$dl.nameList.size()<<endl;
            writeIntoparserLogFile("Line " + std::to_string($sm->getLine()) + ": var_declaration : type_specifier declaration_list SEMICOLON\n");
            string txt = $t.txt;
            txt += " ";
            for (const auto &name : $dl.nameList) {
                txt += name;
                string str;
                bool isArray = false;
                cout<<"Name: "<<name<<endl;
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
                if(inFunc==0){
                    global_vars.push_back(make_pair(name, type));
                }
                handle_var_declaration(code,s,stack_offset,name,type,asmFile);
            }
            txt+=";";
            // cout<<"Declaraction list size: "<<$dl.nameList.size()<<endl;
            if($t.type == "VOID") {
                writeIntoErrorFile("Error at line " + std::to_string($sm->getLine()) + ": Variable type cannot be void\n");
                syntaxErrorCount++;
                writeIntoparserLogFile("Error at line " + std::to_string($sm->getLine()) + ": Variable type cannot be void\n");
            }

            writeIntoparserLogFile(txt + "\n");
            $txt = txt;
            $line = $sm->getLine();
        }
       
    | t=type_specifier de=declaration_list_err sm=SEMICOLON {
          writeIntoErrorFile(
              std::string("Line# ") + std::to_string($sm->getLine()) +
              " with error name: " + $de.error_name +
              " - Syntax error at declaration list of variable declaration"
          );
          syntaxErrorCount++;
      }
    ;

declaration_list returns [std::vector<std::string> nameList]
    : dl=declaration_list COMMA ID {
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
    | dl=declaration_list COMMA ID LTHIRD CONST_INT RTHIRD {
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
    | first = ID op=ADDOP second = ID {
            writeIntoparserLogFile("Line " + std::to_string($op->getLine()) + ": declaration_list : ID\n");
            writeIntoparserLogFile($first->getText()+"\n");
            insertIdInSymbolTable($first->getText(), "ID", $first->getLine());
            writeIntoErrorFile("Error at line " + std::to_string($op->getLine()) + ": syntax error, unexpected ADDOP, expecting COMMA or SEMICOLON\n");
            syntaxErrorCount++;
            writeIntoparserLogFile("Error at line " + std::to_string($op->getLine()) + ": syntax error, unexpected ADDOP, expecting COMMA or SEMICOLON\n");
            $nameList = std::vector<std::string>();
             $nameList.push_back($first->getText());
      }
      | pl=declaration_list COMMA ID ADDOP ID {
            // This is an error case, where ADDOP is used incorrectly
            writeIntoErrorFile("Error at line " + std::to_string($ADDOP->getLine()) + ": syntax error, unexpected ADDOP, expecting COMMA or RTHIRD\n");
            syntaxErrorCount++;
            writeIntoparserLogFile("Error at line " + std::to_string($ADDOP->getLine()) + ": syntax error, unexpected ADDOP, expecting COMMA or RTHIRD\n");
            $nameList = $pl.nameList;
            // cout<<"Matched with declaration_list COMMA ID ADDOP ID"<<endl;
            $nameList.push_back($ID->getText());
      }
    ;

declaration_list_err returns [std::string error_name] : {
    $error_name = "Error in declaration list";
};

type_specifier returns [std::string txt, std::string type]
    : INT { 
        // cout<<"INT at"<<$INT->getLine()<<endl;
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
    | VOID  { 
            $txt = $VOID->getText();
            $type = "VOID";
         writeIntoparserLogFile("Line " + std::to_string($VOID->getLine()) + ": type_specifier : VOID\n");
            writeIntoparserLogFile($VOID->getText() + "\n");
      }
    ;

parameter_list
    returns [std::vector<std::pair<std::string,std::string>> params]
  : t=type_specifier id=ID {
        // first parameter: start fresh
        $params = {};
        $params.emplace_back($t.txt, $id->getText());
        writeIntoparserLogFile("Line " + std::to_string($id->getLine()) + ": parameter_list : type_specifier ID\n");
        writeIntoparserLogFile($t.txt + " " + $id->getText() + "\n");
        
    }
  | pl=parameter_list COMMA t=type_specifier id=ID {
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
    | t= type_specifier ADDOP {
        writeIntoparserLogFile("Line " + std::to_string($ADDOP->getLine()) + ": parameter_list : type_specifier\n");

        writeIntoparserLogFile($t.txt+"\n");

        writeIntoErrorFile("Error at line " + std::to_string($ADDOP->getLine()) + ": syntax error, unexpected ADDOP, expecting RPAREN or COMMA\n");
        syntaxErrorCount++;
        writeIntoparserLogFile("Error at line " + std::to_string($ADDOP->getLine()) + ": syntax error, unexpected ADDOP, expecting RPAREN or COMMA\n");
        $params = {};
        $params.emplace_back($t.txt, "");
    }
    
  ;


statements returns [vector<string> code, int line]
    : st = statement {
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
    }
    ;

statement returns [vector<string> code, int line]
    : var = var_declaration { 
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
    | c=compound_statement[vector<pair<string,string>>()] {

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
    | FOR LPAREN e1=expression_statement{
        string ab = "L" + std::to_string(label_count) + ":";
        loop_condition_label = label_count;
        label_count++;
        code.push_back(ab);
        curr_line = $LPAREN->getLine();

    } e2=expression_statement {
        ab = "\tPOP AX\t\t; line " + std::to_string($e2.line);
        code.push_back(ab);
        stack_offset -= 2; // Decrease stack offset by 2 for loop condition
        ab = "\tCMP AX, 0\t\t; line " + std::to_string($e2.line);
        code.push_back(ab);
        ab = "\tJE L" + std::to_string(label_count) + "\t\t; line " + std::to_string($e2.line);
        code.push_back(ab);
        loop_end_label_index = code.size() - 1; // Store the index of the loop end label for later use
        ab = "\tJMP ";
        code.push_back(ab);
        statement_label_index = code.size() - 1; // Store the index of the statement label for later use
        increment_label = label_count;
    } e3=expression RPAREN {
        ab = "\tJMP L" + std::to_string(loop_condition_label) + "\t\t; line " + std::to_string($e3.line);
        code.push_back(ab);
        code[statement_label_index] = "\tJMP L" + std::to_string(label_count) + "\t\t; line " + std::to_string($e3.line);
    } s=statement {
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
        code.push_back(ss);


        ss = "\tJMP L" + std::to_string(increment_label) + "\t\t; line " + std::to_string($s.line);
        code.push_back(ss);
        code[loop_end_label_index] = "\tJE L" + std::to_string(label_count) + "\t\t; line " + std::to_string($s.line);



    }
    | IF LPAREN expression RPAREN{
        string str;
        if(curr_line != $LPAREN->getLine()) {
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            code.push_back(str);
            curr_line = $LPAREN->getLine();
        }

        str = "\tPOP AX\t\t; line ";
        code.push_back(str);
        stack_offset -= 2; // Decrease stack offset by 2 for if condition
        str = "\tCMP AX, 0\t\t; line " ;
        code.push_back(str);
        str = "\tJE L" + std::to_string(label_count);
        code.push_back(str);
        if_label_index = code.size() - 1; // Store the index of the if label for later use
    } s=statement{
        cout<<"if_label_index: "<<if_label_index<<endl;
        cout<<"code size: "<<code.size()<<endl;
        cout<<"label_count: "<<label_count<<endl;
        code[if_label_index] = "\tJE L" + std::to_string(label_count) + "\t\t; line " + std::to_string($s.line);
        if_label_index= -1; // Reset the index after using it
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

        for(int i=0;i<if_label.size();i++){
            code[if_label[i]] = "\tJMP L" + std::to_string(label_count) + "\t\t; line " + std::to_string($s.line);    
        }
        if_label.clear();

        


    }
    | IF LPAREN ex = expression RPAREN{


        string str = "\tPOP AX\t\t; line " + std::to_string($ex.line);
        code.push_back(str);
        stack_offset -= 2; // Decrease stack offset by 2 for if condition
        str = "\tCMP AX, 0\t\t; line " + std::to_string($ex.line);
        code.push_back(str);
        str = "\tJE L" + std::to_string(label_count) + "\t\t; line " + std::to_string($ex.line);
        code.push_back(str);
        if_label_index = code.size() - 1; // Store the index of the if label for later use


        



    } s1=statement{

         str = "\tJMP L" + std::to_string(label_count + 1) + "\t\t; line " + std::to_string($s1.line);
        code.push_back(str);
        if_label.push_back(code.size() - 1); // Store the index of the if label for later use
    
    } ELSE{
        code[if_label_index] = "\tJE L" + std::to_string(label_count) + "\t\t; line " + std::to_string($ex.line);
        if_label_index = -1; // Reset the index after using it
    } s2=statement {
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


        if($s2.code.size()>0 && $s2.code[0]=="{"){
            for(int i=0;i<if_label.size();i++){
                code[if_label[i]] = "\tJMP L" + std::to_string(label_count) + "\t\t; line " + std::to_string($s2.line);    
            }
            if_label.clear();
        }
        


    }
    | WHILE {
        string cd = "L" + std::to_string(label_count) + ":";
        while_loop_condition_label = label_count;
        label_count++;
        code.push_back(cd);
        curr_line = $WHILE->getLine();
    }LPAREN expression {
        string ab;
        ab = "\tPOP AX";
        code.push_back(ab);
        stack_offset -= 2; // Decrease stack offset by 2 for loop condition
        ab = "\tCMP AX, 0";
        code.push_back(ab);
        ab = "\tJE L" + std::to_string(label_count);
        code.push_back(ab);
        while_loop_end_label_index = code.size() - 1; // Store the index of the loop end label for later use

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
        code.push_back(ss);
        code[while_loop_end_label_index] = "\tJE L" + std::to_string(label_count) + "\t\t; line " + std::to_string($statement.line);  


    }
    | PRINTLN LPAREN ID RPAREN SEMICOLON {
        writeIntoparserLogFile("Line " + std::to_string($ID->getLine()) + ": statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n");
        isValidVariable($ID->getText(), $ID->getText(), $ID->getLine());
        $code = vector<string>();
        $code.push_back("printf(" + $ID->getText() + ");");
        writeIntoparserLogFile($code.back() + "\n");
        $line = $ID->getLine();
        string str;
        SymbolInfo *s = symbolTable->look_up_in_all_scope($ID->getText());
        
        // if(s->getScopeId()==1){
        //     str="L" + std::to_string(label_count) + ":";
        //     label_count++;
        //     code.push_back(str);
        //     str = "\tMOV AX, " + $ID->getText()+"\t\t; line"+ std::to_string($ID->getLine());
        //     code.push_back(str);
        //     str = "\tCALL print_output";
        //     code.push_back(str);
        //     str = "\tCALL new_line";
        //     code.push_back(str);
        // }

        if(curr_line != $ID->getLine()) {
            str+="L"+std::to_string(label_count);
            str+=":";
            label_count++;
            code.push_back(str);
            curr_line = $ID->getLine();
        }

        if(s!=nullptr){ 
            if(s->getScopeId()==1){
                str = "\tMOV AX, " + $ID->getText() + "\t\t; line" + std::to_string($ID->getLine());
                code.push_back(str);
                str = "\tCALL print_output";
                code.push_back(str);
                str = "\tCALL new_line";
                code.push_back(str);
            }
            else{

                str = "\tMOV AX, [BP" + std::string((s->getOffset() >= 0) ? "-" : "+") + std::to_string(std::abs(s->getOffset())) + "]\t\t; line " + std::to_string($ID->getLine());
                code.push_back(str);
                str = "\tCALL print_output";
                code.push_back(str);
                str = "\tCALL new_line";
                code.push_back(str);
            }
        }
        else{
            str = "\tMOV AX, " + $ID->getText() + "\t\t; line" + std::to_string($ID->getLine());
            code.push_back(str);
            str = "\tCALL print_output";
            code.push_back(str);
            str = "\tCALL new_line";
            code.push_back(str);
        }
        

        
    }
    | RETURN expr = expression SEMICOLON {
        writeIntoparserLogFile("Line " + std::to_string($expr.line) + ": statement : RETURN expression SEMICOLON\n");
        $code = vector<string>();
        $code.push_back($RETURN->getText() + " " + $expr.str + ";");
        writeIntoparserLogFile($code.back() + "\n");
        $line = $expr.line;
        

        string str;
        if(curr_line != $expr.line) {
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            code.push_back(str);
            curr_line = $expr.line;
        }
        SymbolInfo *s = symbolTable->look_up_in_all_scope($expr.str);
        if(s!=nullptr){
            if(s->getScopeId()==1){
                str = "\tMOV AX, " + $expr.str + "\t\t; line " + std::to_string($expr.line);
                code.push_back(str);   
            }
            else{
                str = "\tMOV AX, [BP" + std::string((s->getOffset() >= 0) ? "-" : "+") + std::to_string(std::abs(s->getOffset())) + "]\t\t; line " + std::to_string($expr.line);
                code.push_back(str);
            }
        }
        else{
            str = "\tPOP AX\t\t; line " + std::to_string($expr.line);
            code.push_back(str);
        }
        str = "\tJMP L" + std::to_string(label_count) + "\t\t; line " + std::to_string($expr.line);
        code.push_back(str);
        func_return_label = code.size() - 1; // Store the index of the function return label for later use
    }
    ;

expression_statement returns [ string str, int line]
    : SEMICOLON {
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
    }
    ;

variable returns [std::string varName, int line]
    : ID{
        writeIntoparserLogFile("Line " + std::to_string($ID->getLine()) + ": variable : ID\n");
        isValidVariable($ID->getText(),$ID->getText(), $ID->getLine());
        writeIntoparserLogFile($ID->getText() + "\n");
        $varName = $ID->getText();
        $line = $ID->getLine();
     }
    | ID LTHIRD expression RTHIRD { 
        writeIntoparserLogFile("Line " + std::to_string($ID->getLine()) + ": variable : ID LTHIRD expression RTHIRD\n");
        string str = $ID->getText() + "[" + $expression.str + "]";
        isValidVariable($ID->getText(),str, $ID->getLine());
        writeIntoparserLogFile($ID->getText() + "[" + $expression.str + "]\n");
        $varName = $ID->getText() + "[" + $expression.str + "]";
        if ($expression.str.empty()) {
            writeIntoErrorFile("Error at line " + std::to_string($ID->getLine()) + ": Empty expression in array index\n");
            syntaxErrorCount++;
        }
        $line = $ID->getLine();
        



        // string str2;
        // str2 = "\tPOP BX\t\t; line " + std::to_string($ID->getLine());
        // code.push_back(str2);
        // stack_offset -= 2; // Decrease stack offset by 2 for array index
        // str2 = "\tMOV AX, " + std::to_string(2) + "\t\t; line " + std::to_string($ID->getLine());
        // code.push_back(str2);
        // str2 = "\tMUL BX\t\t; line " + std::to_string($ID->getLine());
        // code.push_back(str2);
        // str2 = "\tMOV BX, AX\t\t; line " + std::to_string($ID->getLine());
        // code.push_back(str2);

        // SymbolInfo *s = symbolTable->look_up_in_all_scope($ID->getText());

        // if(s->getScopeId()==1){
        //     str2 = "\tMOV AX, " + $ID->getText() + "[BX]\t\t; line " + std::to_string($ID->getLine());
        //     code.push_back(str2);
        // }
        // else{
        //     str2 = "\tMOV AX, "+ std::to_string(s->getOffset());
        //     code.push_back(str2);
        //     str2 = "\tSUB AX, BX\t\t; line " + std::to_string($ID->getLine());
        //     code.push_back(str2);
        //     str2 = "\tMOV BX, AX";
        //     code.push_back(str2);
        //     str2 = "\tMOV SI, BX";
        //     code.push_back(str2);
        //     str2 = "\tMOV AX, [BP + SI]";
        //     code.push_back(str2);
        //     str2 = "\tPUSH AX\t\t; line " + std::to_string($ID->getLine());
        //     code.push_back(str2);
        //     stack_offset += 2; // Increase stack offset by 2 for array index
            
        // }

        // str2 = "\tPUSH AX\t\t; line " + std::to_string($ID->getLine());
        //     code.push_back(str2);
        //     stack_offset += 2; // Increase stack offset by 2 for array index

    }
    ;

expression returns [string str, int line]
    : l_expr = logic_expression {
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
        assignOpcheck($var.varName, logicExpr, $l_expr.line);
        $line = $l_expr.line;
        writeIntoparserLogFile($str + "\n");

        handle_assign_op(code,symbolTable, $var.varName, stack_offset, asmFile);
    } 

    ;

logic_expression returns [vector<string> rel_expr, int line]
    : r_expr = rel_expression {
        writeIntoparserLogFile("Line " + std::to_string($r_expr.line) + ": logic_expression : rel_expression\n");
        $rel_expr = $r_expr.simple_expr;
        $line = $r_expr.line;
        string str;
        for (const auto &term : $rel_expr) {
            str += term;
        }
        writeIntoparserLogFile(str + "\n");

    }
    | r1=rel_expression LOGICOP r2=rel_expression {
        writeIntoparserLogFile("Line " + std::to_string($r1.line) + ": logic_expression : rel_expression LOGICOP rel_expression\n");
        $rel_expr = $r1.simple_expr;
        $rel_expr.push_back($LOGICOP->getText());
        for (const auto &term : $r2.simple_expr) {
            $rel_expr.push_back(term);
        }
        $line = $r1.line;
        string str;
        for (const auto &term : $rel_expr) {
            str += term;
        }
        writeIntoparserLogFile(str + "\n");



        
        if(curr_line != $r1.line){
            string str = "L" + std::to_string(label_count) + ":";
            label_count++;
            code.push_back(str);
            curr_line = $r1.line;
        }
        SymbolInfo *s = symbolTable->look_up_in_all_scope($r1.simple_expr.back());
        if(s!=nullptr){
            if(s->getScopeId()==1){
                str = "\tMOV AX, " + $r2.simple_expr.back() + "\t\t; line " + std::to_string($r2.line);
                code.push_back(str);    
            }
            else{
                str = "\tMOV AX, [BP" + std::string((s->getOffset() >= 0) ? "-" : "+") + std::to_string(std::abs(s->getOffset())) + "]";
                code.push_back(str);
            }
        }
        else{
            str = "\tPOP DX";
            code.push_back(str);
            stack_offset -= 2;
            str = "\tPOP AX";
            code.push_back(str);
            stack_offset -= 2;
            str = "\tPUSH DX";
            code.push_back(str);
            stack_offset += 2;
        }

        if($LOGICOP->getText()=="||"){
            str = "\tCMP AX, 0";
            code.push_back(str);
            str = "\tJNE L" + std::to_string(label_count) + "\t\t; line " + std::to_string($r1.line);
            code.push_back(str);
            s = symbolTable->look_up_in_all_scope($r2.simple_expr.back());
            if(s!=nullptr){
                if(s->getScopeId()==1){
                    str = "\tMOV AX, " + $r2.simple_expr.back() + "\t\t; line " + std::to_string($r2.line);
                    code.push_back(str);
                }
                else{
                    str = "\tMOV AX, [BP" + std::string((s->getOffset() >= 0) ? "-" : "+") + std::to_string(std::abs(s->getOffset())) + "]";
                    code.push_back(str);
                }
            }
            else{
                str = "\tPOP AX";
                code.push_back(str);
                stack_offset -= 2;
            }
            str = "\tCMP AX, 0";
            code.push_back(str);
            str = "\tJNE L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string($r1.line);
            code.push_back(str);

            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            code.push_back(str);
            str = "\tMOV AX, 1\t\t; line " + std::to_string($r1.line);
            code.push_back(str);
            str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string($r1.line);
            code.push_back(str);
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            code.push_back(str);
            str = "\tMOV AX, 0\t\t; line " + std::to_string($r1.line);
            code.push_back(str);
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            code.push_back(str);
            str = "\tPUSH AX\t\t; line " + std::to_string($r1.line);
            code.push_back(str);
            stack_offset += 2; 

        }

        else if($LOGICOP->getText() == "&&"){
            str = "\tCMP AX, 0";
            code.push_back(str);
            str = "\tJE L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string($r1.line);
            code.push_back(str);
            s = symbolTable->look_up_in_all_scope($r2.simple_expr.back());
            if(s!=nullptr){
                if(s->getScopeId()==1){
                    str = "\tMOV AX, " + $r2.simple_expr.back() + "\t\t; line " + std::to_string($r2.line);
                    code.push_back(str);
                }
                else{
                    str = "\tMOV AX, [BP" + std::string((s->getOffset() >= 0) ? "-" : "+") + std::to_string(std::abs(s->getOffset())) + "]";
                    code.push_back(str);
                }
            }
            else{
                str = "\tPOP AX";
                code.push_back(str);
                stack_offset -= 2;
            }
            str = "\tCMP AX, 0";
            code.push_back(str);
            str = "\tJE L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string($r1.line);
            code.push_back(str);

            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            code.push_back(str);
            str = "\tMOV AX, 1\t\t; line " + std::to_string($r1.line);
            code.push_back(str);
            str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string($r1.line);
            code.push_back(str);
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            code.push_back(str);
            str = "\tMOV AX, 0\t\t; line " + std::to_string($r1.line);
            code.push_back(str);
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            code.push_back(str);
            str = "\tPUSH AX\t\t; line " + std::to_string($r1.line);
            code.push_back(str);
            stack_offset += 2; 
        }














    }
    ;

rel_expression returns [vector<string> simple_expr, int line]
    : s_expr = simple_expression {
        writeIntoparserLogFile("Line " + std::to_string($s_expr.line) + ": rel_expression : simple_expression\n");
        $simple_expr = $s_expr.terms;
        $line = $s_expr.line;
        string str;
        for (const auto &term : $simple_expr) {
            str += term;
        }
        writeIntoparserLogFile(str + "\n");
    }
    | s_expr=simple_expression RELOP ss=simple_expression {
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




        if(curr_line != $s_expr.line){
            string str = "L" + std::to_string(label_count) + ":";
            label_count++;
            code.push_back(str);
            curr_line = $s_expr.line;
        }


        SymbolInfo *s = symbolTable->look_up_in_all_scope($ss.terms.back());
        if(s!=nullptr){
            if(s->getScopeId()==1){
                str = "\tMOV AX, " + $ss.terms.back() + "\t\t; line " + std::to_string($ss.line);
                code.push_back(str);    
                str = "\tMOV DX, AX";
                code.push_back(str);
            }
            else{
                str = "\tMOV AX, [BP" + std::string((s->getOffset() >= 0) ? "-" : "+") + std::to_string(std::abs(s->getOffset())) + "]\t\t; line " + std::to_string($ss.line);
                code.push_back(str);
                str = "\tMOV DX, AX";
                code.push_back(str);
            }
        }
        else{
            str = "\tPOP AX";
            code.push_back(str);
            stack_offset -= 2;
            str = "\tMOV DX, AX";
            code.push_back(str);
        }

        s = symbolTable->look_up_in_all_scope($s_expr.terms.back());
        if(s!=nullptr){
            if(s->getScopeId()==1){
                str = "\tMOV AX, " + $s_expr.terms.back() + "\t\t; line " + std::to_string($s_expr.line);
                code.push_back(str);
            }
            else{
                str = "\tMOV AX, [BP" + std::string((s->getOffset() >= 0) ? "-" : "+") + std::to_string(std::abs(s->getOffset())) + "]\t\t; line " + std::to_string($s_expr.line);
                code.push_back(str);
            }
        }
        else{
            str = "\tPOP AX";
            code.push_back(str);
            stack_offset -= 2;
        }
        if($RELOP->getText() == "<="){
            // if(booked_label < label_count) booked_label = label_count;
            str = "\tCMP AX, DX";
            code.push_back(str);
            str = "\tJLE L" + std::to_string(label_count) + "\t\t; line " + std::to_string($s_expr.line);
            code.push_back(str);
            booked_label++;
            str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string($s_expr.line);
            code.push_back(str);
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            code.push_back(str);
            str = "\tMOV AX, 1\t\t; line " + std::to_string($s_expr.line);
            code.push_back(str);
            str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string($s_expr.line);
            code.push_back(str);
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            code.push_back(str);
            str = "\tMOV AX, 0\t\t; line " + std::to_string($s_expr.line);
            code.push_back(str);
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            code.push_back(str);
            str = "\tPUSH AX\t\t; line " + std::to_string($s_expr.line);
            code.push_back(str);
            stack_offset += 2;
            
        }


        else if($RELOP->getText() == "<"){
            // if(booked_label < label_count) booked_label = label_count;
            str = "\tCMP AX, DX";
            code.push_back(str);
            str = "\tJL L" + std::to_string(label_count) + "\t\t; line " + std::to_string($s_expr.line);
            code.push_back(str);
            booked_label++;
            str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string($s_expr.line);
            code.push_back(str);
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            code.push_back(str);
            str = "\tMOV AX, 1\t\t; line " + std::to_string($s_expr.line);
            code.push_back(str);
            str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string($s_expr.line);
            code.push_back(str);
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            code.push_back(str);
            str = "\tMOV AX, 0\t\t; line " + std::to_string($s_expr.line);
            code.push_back(str);
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            code.push_back(str);
            str = "\tPUSH AX\t\t; line " + std::to_string($s_expr.line);
            code.push_back(str);
            stack_offset += 2;
        }
        else if($RELOP->getText() == ">="){
            // if(booked_label < label_count) booked_label = label_count;
            str = "\tCMP AX, DX";
            code.push_back(str);
            str = "\tJGE L" + std::to_string(label_count) + "\t\t; line " + std::to_string($s_expr.line);
            code.push_back(str);
            booked_label++;
            str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string($s_expr.line);
            code.push_back(str);
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            code.push_back(str);
            str = "\tMOV AX, 1\t\t; line " + std::to_string($s_expr.line);
            code.push_back(str);
            str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string($s_expr.line);
            code.push_back(str);
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            code.push_back(str);
            str = "\tMOV AX, 0\t\t; line " + std::to_string($s_expr.line);
            code.push_back(str);
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            code.push_back(str);
            str = "\tPUSH AX\t\t; line " + std::to_string($s_expr.line);
            code.push_back(str);
            stack_offset += 2;
        }

        else if($RELOP->getText() == ">"){
            // if(booked_label < label_count) booked_label = label_count;
            str = "\tCMP AX, DX";
            code.push_back(str);
            str = "\tJG L" + std::to_string(label_count) + "\t\t; line " + std::to_string($s_expr.line);
            code.push_back(str);
            booked_label++;
            str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string($s_expr.line);
            code.push_back(str);
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            code.push_back(str);
            str = "\tMOV AX, 1\t\t; line " + std::to_string($s_expr.line);
            code.push_back(str);
            str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string($s_expr.line);
            code.push_back(str);
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            code.push_back(str);
            str = "\tMOV AX, 0\t\t; line " + std::to_string($s_expr.line);
            code.push_back(str);
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            code.push_back(str);
            str = "\tPUSH AX\t\t; line " + std::to_string($s_expr.line);
            code.push_back(str);
            stack_offset += 2;
        }
        else if($RELOP->getText() == "=="){
            // if(booked_label < label_count) booked_label = label_count;
            str = "\tCMP AX, DX";
            code.push_back(str);
            str = "\tJE L" + std::to_string(label_count) + "\t\t; line " + std::to_string($s_expr.line);
            code.push_back(str);
            booked_label++;
            str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string($s_expr.line);
            code.push_back(str);
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            code.push_back(str);
            str = "\tMOV AX, 1\t\t; line " + std::to_string($s_expr.line);
            code.push_back(str);
            str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string($s_expr.line);
            code.push_back(str);
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            code.push_back(str);
            str = "\tMOV AX, 0\t\t; line " + std::to_string($s_expr.line);
            code.push_back(str);
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            code.push_back(str);
            str = "\tPUSH AX\t\t; line " + std::to_string($s_expr.line);
            code.push_back(str);
            stack_offset += 2; 
        }
        else if($RELOP->getText() == "!="){
            // if(booked_label < label_count) booked_label = label_count;
            str = "\tCMP AX, DX";
            code.push_back(str);
            str = "\tJNE L" + std::to_string(label_count) + "\t\t; line " + std::to_string($s_expr.line);
            code.push_back(str);
            booked_label++;
            str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string($s_expr.line);
            code.push_back(str);
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            code.push_back(str);
            str = "\tMOV AX, 1\t\t; line " + std::to_string($s_expr.line);
            code.push_back(str);
            str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string($s_expr.line);
            code.push_back(str);
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            code.push_back(str);
            str = "\tMOV AX, 0\t\t; line " + std::to_string($s_expr.line);
            code.push_back(str);
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            code.push_back(str);
            str = "\tPUSH AX\t\t; line " + std::to_string($s_expr.line);
            code.push_back(str);
            stack_offset += 2;
        }










    }
    ;

simple_expression returns [vector<string> terms, int line]
    : t=term {
        writeIntoparserLogFile("Line " + std::to_string($t.line) + ": simple_expression : term\n");
        $terms = { $t.trm };
        $line = $t.line;
        writeIntoparserLogFile($t.trm + "\n");
    }
    | s=simple_expression ADDOP t=term{
        writeIntoparserLogFile("Line " + std::to_string($s.line) + ": simple_expression : simple_expression ADDOP term\n");
        $terms = $s.terms;
        $terms.push_back($ADDOP->getText());
        $terms.push_back($t.trm);
        // cout<< $t.trm << endl;
        $line = $s.line;
        string str;
        for (const auto &term : $terms) {
            str += term;
        }
        writeIntoparserLogFile(str + "\n");


        // str="\tPOP AX";
        // code.push_back(str);
        // stack_offset -= 2;
        // str = "\tMOV DX, AX";
        // code.push_back(str);
        // str = "\tPOP AX";
        // code.push_back(str);
        // stack_offset -= 2;
        // str = "\tADD AX, DX";
        // code.push_back(str);
        // str = "\tPUSH AX";
        // code.push_back(str);
        // stack_offset += 2;

        if(curr_line != $s.line){
            string str = "L" + std::to_string(label_count) + ":";
            label_count++;
            code.push_back(str);
            curr_line = $s.line;
        }
        
        SymbolInfo *s= symbolTable->look_up_in_all_scope($t.trm);
        if(s!=nullptr){
            if(s->getScopeId()==1){
                str = "\tMOV AX, " + $t.trm + "\t\t; line " + std::to_string($t.line);
                code.push_back(str);
            }
            else{
                str = "\tMOV AX, [BP" + std::string((s->getOffset() >= 0) ? "-" : "+") + std::to_string(std::abs(s->getOffset())) + "]\t\t; line " + std::to_string($t.line);
                code.push_back(str);
            }
        }
        else{
            str = "\tPOP AX";
            code.push_back(str);
            stack_offset -= 2;
        }
        str = "\tMOV DX, AX";
        code.push_back(str);
        

        string s_term_merge;
        for (const auto &term : $s.terms) {
            s_term_merge += term;
        }


        s= symbolTable->look_up_in_all_scope(s_term_merge);
        cout<< "back: " << s_term_merge << endl;
        if(s!=nullptr){
            if(s->getScopeId()==1){
                str = "\tMOV AX, " + $s.terms.back() + "\t\t; line " + std::to_string($s.line);
                code.push_back(str);
            }
            else{
                str = "\tMOV AX, [BP" + std::string((s->getOffset() >= 0) ? "-" : "+") + std::to_string(std::abs(s->getOffset())) + "]\t\t; line " + std::to_string($s.line);
                code.push_back(str);
            }
        }
        else{
            str = "\tPOP AX";
            code.push_back(str);
            stack_offset -= 2;
        }
        if ($ADDOP->getText() == "+") {
            str = "\tADD AX, DX";
            code.push_back(str);
            str = "\tPUSH AX\t\t; line " + std::to_string($s.line);
            code.push_back(str);
            stack_offset += 2;
        }
        else if ($ADDOP->getText() == "-") {
            str = "\tSUB AX, DX";
            code.push_back(str);
            str = "\tPUSH AX\t\t; line " + std::to_string($s.line);
            code.push_back(str);
            stack_offset += 2;
        } 



    }
    | s=simple_expression ad=ADDOP as=ASSIGNOP{
        $terms = vector<string>();
        writeIntoErrorFile("Error at line " + std::to_string($ad->getLine()) + ": syntax error, unexpected ASSIGNOP\n");
        writeIntoparserLogFile("Error at line " + std::to_string($ad->getLine()) + ": syntax error, unexpected ASSIGNOP\n");
        syntaxErrorCount++;
    } t2=term {
        writeIntoparserLogFile("Line " + std::to_string($t2.line) + ": simple_expression : term\n");
        writeIntoparserLogFile($t2.trm+"\n");
        $terms.push_back($t2.trm);
        $line = $t2.line;
    }
    ;

term returns [string trm, int line]
    : u_expr = unary_expression {
        writeIntoparserLogFile("Line " + std::to_string($u_expr.line) + ": term : unary_expression\n");
        $trm = $u_expr.unary_expr;
        $line = $u_expr.line;
        writeIntoparserLogFile($trm + "\n");
    }
    | t=term MULOP u = unary_expression {
        writeIntoparserLogFile("Line " + std::to_string($t.line) + ": term : term MULOP unary_expression\n");
        $trm = $t.trm  + $MULOP->getText() + $u.unary_expr;
        $line = $t.line;
        termExprCheck($u.unary_expr, $u.line);
        termMulOpCheck($t.trm, $u.unary_expr, $MULOP->getText(), $t.line);
        writeIntoparserLogFile($trm + "\n");


        string str;
        SymbolInfo *s= symbolTable->look_up_in_all_scope($u.unary_expr);
        if(curr_line != $t.line){
            str+="L"+std::to_string(label_count);
            str+=":";
            label_count++;
            code.push_back(str);
            curr_line = $t.line;
        }

        if(s!=nullptr){
            if(s->getScopeId()==1){
                str = "\tMOV AX, " + $u.unary_expr + "\t\t; line " + std::to_string($u.line);
                code.push_back(str);
                str = "\tMOV CX, AX";
                code.push_back(str);
            }
            else{
                str = "\tMOV AX, [BP" + std::string((s->getOffset() >= 0) ? "-" : "+") + std::to_string(std::abs(s->getOffset())) + "]\t\t; line " + std::to_string($u.line);
                code.push_back(str);
                str = "\tMOV CX, AX";
                code.push_back(str);
            }
        }
        else{
            str = "\tPOP AX";
            code.push_back(str);
            str = "\tMOV CX, AX";
            code.push_back(str);
            stack_offset -= 2;
        }

        s= symbolTable->look_up_in_all_scope($t.trm);
        if(s!=nullptr){
            if(s->getScopeId()==1){
                str = "\tMOV AX, " + $t.trm + "\t\t; line " + std::to_string($t.line);
                code.push_back(str);
            }
            else{
                str = "\tMOV AX, [BP" + std::string((s->getOffset() >= 0) ? "-" : "+") + std::to_string(std::abs(s->getOffset())) + "]\t\t; line " + std::to_string($t.line);
                code.push_back(str);
            }
        }
        else{
            str = "\tPOP AX";
            code.push_back(str);
            stack_offset -= 2;
        }
        code.push_back("\tCWD");
        if ($MULOP->getText() == "*") {
            str = "\tMUL CX";
            code.push_back(str);
            str = "\tPUSH AX\t\t; line " + std::to_string($t.line);
            code.push_back(str);
            stack_offset += 2;

        } 
        else{
            str = "\tDIV CX";
            code.push_back(str);
            str = "\tPUSH DX\t\t; line " + std::to_string($t.line);
            code.push_back(str);
            stack_offset += 2;
        }
               
        

    }
    | t= term UNRECOGNIZED {
        writeIntoErrorFile("Error at line " + std::to_string($UNRECOGNIZED->getLine()) + ": Unrecognized character " + $UNRECOGNIZED->getText()+"\n");
        writeIntoparserLogFile("Error at line " + std::to_string($UNRECOGNIZED->getLine()) + ": Unrecognized character " + $UNRECOGNIZED->getText()+"\n");
        syntaxErrorCount++;
        // cout<<"Error at line "<<$UNRECOGNIZED->getLine()<<": "<<$UNRECOGNIZED->getText()<<" is not a valid token"<<endl;
        $trm =$t.trm;
        // cout<<"Term at "<<$t.line<<": "<<$trm<<endl;
        $line = $t.line;
    }

    ;

unary_expression returns [std::string unary_expr, int line]
    : ADDOP unary_expression {
        writeIntoparserLogFile("Line " + std::to_string($unary_expression.line) + ": unary_expression : ADDOP unary_expression\n");
        $unary_expr = $ADDOP->getText() + $unary_expression.unary_expr;
        $line = $unary_expression.line;
        writeIntoparserLogFile($unary_expr + "\n");


        string str;
        SymbolInfo *s = symbolTable->look_up_in_all_scope($unary_expression.unary_expr);
        if(curr_line != $unary_expression.line){
            str = "L" + std::to_string(label_count) + ":";
            label_count++;
            code.push_back(str);
            curr_line = $unary_expression.line; 
        }
        if(s!=nullptr){
            if(s->getScopeId()==1){
                str = "\tMOV AX, " + $unary_expression.unary_expr + "\t\t; line " + std::to_string($unary_expression.line);
                code.push_back(str);
            }
            else{
                str = "\tMOV AX, [BP" + std::string((s->getOffset() >= 0) ? "-" : "+") + std::to_string(std::abs(s->getOffset())) + "]\t\t; line " + std::to_string($unary_expression.line);
                code.push_back(str);
            }
        }
        else{
            str = "\tPOP AX";
            code.push_back(str);
            stack_offset -= 2;
        }
        if ($ADDOP->getText() == "+") {
            str = "\tPUSH AX\t\t; line " + std::to_string($unary_expression.line);
            code.push_back(str);
            stack_offset += 2;
        }
        else if ($ADDOP->getText() == "-") {
            str = "\tNEG AX\t\t; line " + std::to_string($unary_expression.line);
            code.push_back(str);
            str = "\tPUSH AX\t\t; line " + std::to_string($unary_expression.line);
            code.push_back(str);
            stack_offset += 2;
        }



    }
    | NOT unary_expression {
        writeIntoparserLogFile("Line " + std::to_string($unary_expression.line) + ": unary_expression : NOT unary_expression\n");
        $unary_expr = "!" + $unary_expression.unary_expr;
        $line = $unary_expression.line;
        writeIntoparserLogFile($unary_expr + "\n");
    }
    | fact=factor {
        writeIntoparserLogFile("Line " + std::to_string($fact.line) + ": unary_expression : factor\n");
        $unary_expr = $fact.factorName;
        $line = $fact.line;
        writeIntoparserLogFile($fact.factorName + "\n");

        





    }
    ;

factor returns [std::string factorName, int line]
    : var=variable { 
        writeIntoparserLogFile("Line " + std::to_string($var.line) + ": factor : variable\n");
        $factorName = $var.varName;
        $line = $var.line;
        writeIntoparserLogFile($var.varName + "\n");





        string str;
        // extracting [ from varName
        string var;
        int pos = $var.varName.find("[");
        if (pos != std::string::npos) {
            var = $var.varName.substr(0, pos);
        } else {
            var = $var.varName;
        }
        str = "L" + std::to_string(label_count) + ":";
        label_count++;
        code.push_back(str);
        if($var.varName != var){
            string str2;
        str2 = "\tPOP BX";
        code.push_back(str2);
        stack_offset -= 2; // Decrease stack offset by 2 for array index
        str2 = "\tMOV AX, " + std::to_string(2);
        code.push_back(str2);
        str2 = "\tMUL BX";
        code.push_back(str2);
        str2 = "\tMOV BX, AX";
        code.push_back(str2);

        SymbolInfo *s = symbolTable->look_up_in_all_scope(var);

        if(s->getScopeId()==1){
            str2 = "\tMOV AX, " + var +"[BX]";
            code.push_back(str2);
        }
        else{
            str2 = "\tMOV AX, "+ std::to_string(s->getOffset());
            code.push_back(str2);
            str2 = "\tSUB AX, BX";
            code.push_back(str2);
            str2 = "\tMOV BX, AX";
            code.push_back(str2);
            str2 = "\tMOV SI, BX";
            code.push_back(str2);
            str2 = "\tMOV AX, [BP + SI]";
            code.push_back(str2);
            str2 = "\tPUSH AX";
            code.push_back(str2);
            stack_offset += 2; // Increase stack offset by 2 for array index
            
        }

        str2 = "\tPUSH AX";
            code.push_back(str2);
            stack_offset += 2; // Increase stack offset by 2 for array index

        }




    }
    | ID LPAREN ar = argument_list RPAREN { 
        writeIntoparserLogFile("Line " + std::to_string($ID->getLine()) + ": factor : ID LPAREN argument_list RPAREN\n");
        $factorName = $ID->getText() + "(";
        for (const auto &term : $ar.arg) {
            $factorName += term;
            if (&term != &($ar.arg.back())) {
                $factorName += ",";
            }
        }
        $factorName += ")";
        $line = $ID->getLine();
        isValidParameterList($ID->getText(), $ar.arg, $ID->getLine());
        writeIntoparserLogFile($factorName + "\n");



        string str;
        str = "L" + std::to_string(label_count) + ":";
        label_count++;
        code.push_back(str);
        curr_line = $ID->getLine();

        for(int i=0;i<$ar.arg.size();i++){
            SymbolInfo *s = symbolTable->look_up_in_all_scope($ar.arg[i]);
            if(s!=nullptr){
                if(s->getScopeId()==1){
                    str = "\tMOV AX, " + $ar.arg[i] + "\t\t; line " + std::to_string($ID->getLine());
                    code.push_back(str);
                }
                else{
                    str = "\tMOV AX, [BP" + std::string((s->getOffset() >= 0) ? "-" : "+") + std::to_string(std::abs(s->getOffset())) + "]\t\t; line " + std::to_string($ID->getLine());
                    code.push_back(str);
                }
            }
            else{
                str = "\tPOP AX";
                code.push_back(str);
                stack_offset -= 2;
            }
            str = "\tPUSH AX\t\t; line " + std::to_string($ID->getLine());
            code.push_back(str);
            stack_offset += 2;
        }

        str = "\tCALL " + $ID->getText() + "\t\t; line " + std::to_string($ID->getLine());
        code.push_back(str);
        
        str = "\tPUSH AX\t\t; line " + std::to_string($ID->getLine());
        code.push_back(str);
        stack_offset += 2;





    }
    | LPAREN exp=expression RPAREN {
        writeIntoparserLogFile("Line " + std::to_string($exp.line) + ": factor : LPAREN expression RPAREN\n");
        $factorName = "(" + $exp.str + ")";
        $line = $exp.line;
        writeIntoparserLogFile($factorName + "\n");
    }
    | c_int = CONST_INT {
        writeIntoparserLogFile("Line " + std::to_string($c_int->getLine()) + ": factor : CONST_INT\n");
        $factorName = $c_int->getText();
        $line = $c_int->getLine();
        // cout<<"CONST_INT at "<<$c_int->getLine()<<endl;
        writeIntoparserLogFile($c_int->getText() + "\n");

        string str;
        
        if(curr_line != $c_int->getLine()){
            str+="L"+std::to_string(label_count);
            str+=":";
            label_count++;
            code.push_back(str);
            curr_line = $c_int->getLine();
        }
        str = "\tMOV AX, "+$c_int->getText()+"\t\t; line "+std::to_string($c_int->getLine());
        code.push_back(str);
        str = "\tPUSH AX";
        code.push_back(str);
        stack_offset += 2;
        }
    | c_float = CONST_FLOAT{
        writeIntoparserLogFile("Line " + std::to_string($c_float->getLine()) + ": factor : CONST_FLOAT\n");
        $factorName = $c_float->getText();
        $line = $c_float->getLine();
        writeIntoparserLogFile($c_float->getText() + "\n");
    }
    | variable INCOP { 
        writeIntoparserLogFile("Line " + std::to_string($variable.line) + ": factor : variable INCOP\n");
        $factorName = $variable.varName + "++";
        $line = $variable.line;
        writeIntoparserLogFile($factorName + "\n");




        string str;
        SymbolInfo *s = symbolTable->look_up_in_all_scope($variable.varName);
        // if(curr_line != $variable.line){
        //     str = "L" + std::to_string(label_count) + ":";
        //     label_count++;
        //     code.push_back(str);
        //     curr_line = $variable.line;
        // }   
        str = "L" + std::to_string(label_count) + ":";
        label_count++;
        code.push_back(str);
        curr_line = $variable.line;

        if(s!=nullptr){
            if(s->getScopeId()==1){
                str = "\tMOV AX, " + $variable.varName + "\t\t; line " + std::to_string($variable.line);
                code.push_back(str);
            }
            else{
                str = "\tMOV AX, [BP" + std::string((s->getOffset() >= 0) ? "-" : "+") + std::to_string(std::abs(s->getOffset())) + "]\t\t; line " + std::to_string($variable.line);
                code.push_back(str);
            }
        }
        else{
            str = "\tPOP AX";
            code.push_back(str);
            stack_offset -= 2;
        }
        str = "\tPUSH AX\t\t; line " + std::to_string($variable.line);
        code.push_back(str);
        stack_offset += 2;
        str = "\tINC AX\t\t; line " + std::to_string($variable.line);
        code.push_back(str);
        str = "\tMOV [BP" + std::string((s->getOffset() >= 0) ? "-" : "+") + std::to_string(std::abs(s->getOffset())) + "], AX\t\t; line " + std::to_string($variable.line);
        code.push_back(str);
        




    }
    | variable DECOP{
        writeIntoparserLogFile("Line " + std::to_string($variable.line) + ": factor : variable DECOP\n");
        $factorName = $variable.varName + "--";
        $line = $variable.line;
        writeIntoparserLogFile($factorName + "\n");





        string str;
        SymbolInfo *s = symbolTable->look_up_in_all_scope($variable.varName);
        // if(curr_line != $variable.line){
        //     str = "L" + std::to_string(label_count) + ":";
        //     label_count++;
        //     code.push_back(str);
        //     curr_line = $variable.line;
        // }   
        str = "L" + std::to_string(label_count) + ":";
        label_count++;
        code.push_back(str);
        curr_line = $variable.line;

        if(s!=nullptr){
            if(s->getScopeId()==1){
                str = "\tMOV AX, " + $variable.varName + "\t\t; line " + std::to_string($variable.line);
                code.push_back(str);
            }
            else{
                str = "\tMOV AX, [BP" + std::string((s->getOffset() >= 0) ? "-" : "+") + std::to_string(std::abs(s->getOffset())) + "]\t\t; line " + std::to_string($variable.line);
                code.push_back(str);
            }
        }
        else{
            str = "\tPOP AX";
            code.push_back(str);
            stack_offset -= 2;
        }
        str = "\tPUSH AX\t\t; line " + std::to_string($variable.line);
        code.push_back(str);
        stack_offset += 2;
        str = "\tDEC AX\t\t; line " + std::to_string($variable.line);
        code.push_back(str);
        str = "\tMOV [BP" + std::string((s->getOffset() >= 0) ? "-" : "+") + std::to_string(std::abs(s->getOffset())) + "], AX\t\t; line " + std::to_string($variable.line);
        code.push_back(str);

    }
    ;

argument_list returns [std::vector<std::string> arg]
    : ar = arguments { 
        writeIntoparserLogFile("Line " + std::to_string($ar.line) + ": argument_list : arguments\n");
        $arg = $ar.arg;
        string str;
        for (const auto &term : $arg) {
            str += term;
            if (&term != &($arg.back())) {
                str += ",";
            }
        }
        writeIntoparserLogFile(str + "\n");

    }
    | 
    ;

arguments returns [std::vector<std::string> arg, int line]
    : ar = arguments COMMA l = logic_expression { 
        writeIntoparserLogFile("Line " + std::to_string($l.line) + ": arguments : arguments COMMA logic_expression\n");
        $arg = $ar.arg;
        for (const auto &term : $l.rel_expr) {
            $arg.push_back(term);
        }
        string str;
        for (const auto &term : $arg) {
            str += term;
            if (&term != &($arg.back())) {
                str += ",";
            }
        }
        writeIntoparserLogFile(str + "\n");
        $line = $l.line;
    } 
    | l = logic_expression { 
        writeIntoparserLogFile("Line " + std::to_string($l.line) + ": arguments : logic_expression\n");
        $arg = std::vector<std::string>();
        for (const auto &term : $l.rel_expr) {
            $arg.push_back(term);
        }
        string str;
        for (const auto &term : $arg) {
            str += term;
            if (&term != &($arg.back())) {
                str += ",";
            }
        }
        writeIntoparserLogFile(str + "\n");
        $line = $l.line;

    }
    ;
