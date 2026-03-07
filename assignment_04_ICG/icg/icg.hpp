#ifndef ICG_HPP
#define ICG_HPP

#include <bits/stdc++.h>
#include "2105052_symbol_table.hpp"
using namespace std;

void initialize_asm_file(ofstream &asmFile);
void handle_main_func_initialization(vector<string> &code);
void write_code_into_asm_file(const vector<string> &code, ofstream &asmFile);
void function_initialization(vector<string> &code);
void handle_var_declaration(vector<string> &code, SymbolInfo *symbol, int& stack_offset,string name, string type, ofstream &asmFile);
void handle_assign_op(vector<string> &code, SymbolTable *symbolTable, const string &varName, int &stack_offset, ofstream &asmFile);

#endif // ICG_HPP
