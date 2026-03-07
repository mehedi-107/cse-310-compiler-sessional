#include "icg.hpp"

void initialize_asm_file(ofstream &asmFile) {
    asmFile << ".MODEL SMALL" << endl;
    asmFile << ".STACK 1000H" << endl;
    asmFile << ".DATA" << endl;
}

void handle_main_func_initialization(vector<string> &code) {
    code.push_back("main PROC");
    code.push_back("\tMOV AX, @DATA");
    code.push_back("\tMOV DS, AX");
}

void function_initialization(vector<string> &code){
    code.push_back("\tPUSH BP");
    code.push_back("\tMOV BP, SP");
}

void print_global_var(vector<pair<string,string>> &global_vars, ofstream &asmFile) {
    
    asmFile << "\tnumber DB \"00000$\"" << endl;
     if (global_vars.empty()) {asmFile << ".CODE" << endl;return;}
    for(const auto &var : global_vars) {
        if(var.second == "int"){
            asmFile << "\t"<< var.first << " DW 1 DUP (0000H)" <<endl;
        }
        if(var.second == "int_array"){
            // extracting name and size from var.first
            string name, size_str;
            size_t pos = var.first.find('[');
            if (pos != string::npos) {
                name = var.first.substr(0, pos);
                size_str = var.first.substr(pos + 1);
                size_str = size_str.substr(0, size_str.size() - 1); // remove ']'
            } else {
                name = var.first;
                size_str = "1"; // default size if not specified
            }
            int size = stoi(size_str);
            asmFile << "\t" << name << " DW " << size << " DUP (0000H)" << endl;
        }
    }
    asmFile << ".CODE" << endl;
}

void write_code_into_asm_file(const vector<string> &code, ofstream &asmFile) {
    for (const auto &line : code) {
        asmFile << line << endl;
    }
}

void handle_var_declaration(vector<string> &code, SymbolInfo *symbol, int& stack_offset,string name, string type, ofstream &asmFile) {
    if(symbol->getScopeId()==1) return;
    if(type=="int"){
    stack_offset += 2;
    symbol->setOffset(stack_offset);
    cout<<"Variable "<<symbol->getName()<<" declared with offset "<<stack_offset<<endl;
    code.push_back("\tSUB SP, 2");
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
        cout<<"Array "<<symbol->getName()<<" declared with offset "<<stack_offset<<endl;
        code.push_back("\tSUB SP, " + std::to_string(2 * size));
    }
}




void handle_assign_op(vector<string> &code, SymbolTable *symbolTable, const string &varName, int &stack_offset, ofstream &asmFile) {
    string var;
    // Check if the variable is an array
    if (varName.find('[') != string::npos) {
        var = varName.substr(0, varName.find('['));
    } else {
        var = varName;
    }
    SymbolInfo *symbol = symbolTable->look_up_in_all_scope(var);
    cout<<"Assigning "<<varName<<" with scope id "<<endl;
    if(symbol==nullptr) {cout<<"null"<<endl;return;}
    if(symbol->getScopeId()==1){
        string str = "\tPOP AX";
        code.push_back(str);
        if(var!=varName){
            str = "\tPOP BX";
            code.push_back(str);
            str = "\tPUSH AX";
            code.push_back(str);
            str = "\tMOV AX, 2";
            code.push_back(str);
            str = "\tMUL BX";
            code.push_back(str);
            str = "\tMOV BX, AX";
            code.push_back(str);
            str = "\tPOP AX";
            code.push_back(str);
            str = "\tMOV " + var +"[BX], AX";
        }
        else
            str = "\tMOV " + symbol->getName() + ", AX";
        code.push_back(str);
        stack_offset -= 2;
    }
    else {
        string str = "\tPOP AX";
        int offset = symbol->getOffset();
        code.push_back(str);
        if(var!=varName){
            str = "\tPOP BX";
            code.push_back(str);
            str = "\tPUSH AX";
            code.push_back(str);
            str = "\tMOV AX, 2";
            code.push_back(str);
            str = "\tMUL BX";
            code.push_back(str);
            str = "\tMOV BX, AX";
            code.push_back(str);
            str = "\tMOV AX, " + std::to_string(offset);
            code.push_back(str);
            str = "\tSUB AX, BX";
            code.push_back(str);
            str = "\tMOV BX, AX";
            code.push_back(str);
            str = "\tPOP AX";
            code.push_back(str);
            str = "\tMOV SI, BX";
            code.push_back(str);
            str = "\tNEG SI";
            code.push_back(str);
            str = "\tMOV [BP + SI], AX";
        }
        else
        str = "\tMOV [BP" + std::string(offset>=0 ? "-" : "+") + std::to_string(abs(offset)) + "], AX";
        code.push_back(str);

        stack_offset -= 2;
    }
}