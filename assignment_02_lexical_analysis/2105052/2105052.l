%option noyywrap
%x STRING COMMENT LINE_COMMENT

%{
#include <string>
#include <fstream>
#include <map>
#include <iostream>
#include "2105052_symbol_table.hpp"
#define dbg(x) cout<<#x<<" = "<<x<<endl;
using namespace std;

int line_count   = 1;
int error_count  = 0;
int str_line     = 0;
int last_back   = 0;
void inLc() {
    line_count++;
}

string buffer0;
string buffer1;

string token_file;
SymbolTable symbol_table(7);
map<string, bool> keyword;
map<string, string> operator_name;
%}

alpha [a-zA-Z]
alpha_Un [a-zA-Z_]
digit [0-9]
alphanum [a-zA-Z0-9_]
op_n_punc [\+\-*/%<>=!&|(){}\[\],;]
nothing[^a-zA-Z_\+\-*/%<>=!&|(){}\[\],\.;\n]

%%

\n {
    // cout<<"line "<<line_count<<endl;
    line_count++;
    }
[ \t]+ {}

"/*" {
    BEGIN(COMMENT);
    buffer0.clear();
    buffer0 += "/*";
    str_line=line_count;
}
<COMMENT>"*/" {BEGIN(INITIAL);buffer0 += "*/";
    cout << "Line no " << line_count << ": Token <COMMENT> Lexeme " << buffer0 << " found" << endl <<endl;
    // cout<<endl;

}
<COMMENT>\n {
    inLc();
    buffer0 +='\n';
}

<COMMENT><<EOF>> {
    cout << "Error at line no " << str_line << ": Unterminated comment " << buffer0 << endl<<endl;
    error_count++;
    BEGIN(INITIAL);
}
<COMMENT>. {
    string str(yytext);
    buffer0 += yytext;
}

"//" {
    BEGIN(LINE_COMMENT);
    buffer0.clear();
    buffer0 += "//"; 
    str_line=line_count;
}
<LINE_COMMENT>\n {
    inLc(); 
    if (!last_back) {
        cout << "Line no " << line_count-1 << ": Token <COMMENT> Lexeme " << buffer0 << " found" << endl;
        cout<<endl;
        BEGIN(INITIAL); 
    }
    else
        buffer0 += '\n';
}
<LINE_COMMENT>. {
    if(yytext[0] == '\\')
        last_back = 1;
    else
        last_back = 0;
    buffer0 += yytext;
    }


"\"" {
    BEGIN(STRING);
    buffer0.clear();
    buffer1.clear();
    buffer0 += '"';
    // buffer1 += '"';
    last_back = 0;
    str_line = line_count;
}

<STRING>\\\" {
    buffer0 += "\\\"";
    buffer1 += '"';
    last_back = 0;
}

<STRING>\\\\ {
    buffer0 += "\\\\";
    buffer1 += "\\";
    last_back = 0;
}

<STRING>\\\n {
    inLc();
    buffer0 += "\\\n";
    last_back = 0;
}

<STRING>[^\\\"\n]+ {
    buffer0 += yytext;
    buffer1 += yytext;
    last_back = 0;
}

<STRING>\" { 
    buffer0 += '"';
    // buffer1 += '"';
    cout << "Line no " << line_count << ": Token <STRING> Lexeme " << buffer0 << " found --> <STRING, " << buffer1 << ">" << endl;
    cout<<endl;
    ofstream token(token_file, ios::app);
    token << "<STRING, "<<buffer1<<"> ";
    token.close();
    BEGIN(INITIAL);
}

<STRING>\n {
    cout << "Error at line no " << str_line << ": Unterminated string " << buffer0 << endl<<endl;
    error_count++;
    inLc();
    BEGIN(INITIAL);
}

<STRING><<EOF>> {
    cout << "Error at line no " << str_line << ": Unterminated string " << buffer0 << endl<<endl;
    error_count++;
    BEGIN(INITIAL);
}

{op_n_punc}|"++"|"--"|"<="|">="|"=="|"!="|"&&"|"||"  {
    string str(yytext);
    cout << "Line no " << line_count << ": Token <" << operator_name[str] << "> Lexeme " << str << " found" << endl;
    cout<<endl;
    ofstream token(token_file, ios::app);
    token << "<" << operator_name[str] << ", " << str << "> ";
    token.close();
    if(str == "{"){
        symbol_table.enter_scope();
    }
    else if(str == "}"){
        symbol_table.exit_scope();
    }
}

{alpha_Un}{alphanum}* {
    string lexeme(yytext);

    if (keyword[lexeme]==false) {
        // dbg(lexeme);
        SymbolInfo *symbol = new SymbolInfo(lexeme, "ID");
        cout<<"Line no "<<line_count<<": Token <ID> Lexeme "<<lexeme<<" found"<<endl;
        cout<<endl;
        SymbolInfo *symbol1 = symbol_table.look_up(lexeme);
        ofstream token(token_file, ios::app);
        token << "<ID, "<<lexeme<<"> ";
        token.close();
        if(symbol1 != NULL){
        cout<<"< "<<lexeme<<" : ID > already exists in ScopeTable# "<< symbol_table.getCurrentScope()->getName()<<" at position "<< symbol1->i<<", "<<symbol1->j<<endl<<endl;
        }
        else{   
        bool x = symbol_table.insert(symbol);

        if(x){
            symbol_table.print_all_scope_lex();
            cout<<endl;
        }
        }
    }
    else{
        string str = lexeme;
        for (auto &c : lexeme) c = toupper(c);
        cout << "Line no " << line_count<< ": Token <" << lexeme << "> Lexeme " << str << " found" << endl;
        cout<<endl;
        ofstream token(token_file, ios::app);
        token << "<"<<lexeme << "> ";
        token.close();
    }
}

{digit}*[\.]{digit}*({digit}*[\.]{digit}*)+ {
    string num(yytext);
    // cout<<"too = "<<num<<endl;
    cout<<"Error at line no " << line_count << ": Too many decimal points " << num << endl;
    cout<<endl<<endl;
    error_count++;
}

({digit}+|({digit}*"."{digit}+)+)[eE][\-]?({digit}*"."{digit}*)+ {
    string num(yytext);
    // cout<<"Ill = "<<num<<endl;

    cout<<"Error at line no " << line_count << ": Ill formed number " << num << endl;
    cout<<endl<<endl;
    error_count++;
}

{digit}+{alpha_Un}{alphanum}* {
    string str(yytext);
    // cout<<"suff = "<<str<<endl;
    cout<<"Error at line no " << line_count << ": Invalid prefix on ID or invalid suffix on Number " << str << endl;
    cout<<endl;
    error_count++;
}

\'([^\\'\n]|\\.)([^\\'\n]|\\.)+\' {
    string str(yytext);
    cout<<"Error at line no " << line_count << ": Multi character constant error " << str << endl;
    cout<<endl<<endl;
    error_count++;
}

\'([^\\'\n]|\\.)?$ {
    string str(yytext);
    cout<<"Error at line no " << line_count << ": Unterminated character " << str << endl;
    cout<<endl<<endl;
    error_count++;
}

\'\' {
    string str(yytext);
    cout<<"Error at line no " << line_count << ": Empty character constant error " << str << endl;
    cout<<endl<<endl;
    error_count++;
}


({digit}+)?"."{digit}+|({digit}+("."[0-9]+)?[eE]"-"?{digit}+) {
    string num(yytext);
    for(int i = 0;i<num.size();i++){
        // if(num[i]=='E')
        //     num[i]='e';
    }
    cout<<"Line no " << line_count << ": Token <CONST_FLOAT> Lexeme " << num << " found" << endl;
    cout<<endl;
    SymbolInfo *symbol = new SymbolInfo(num, "CONST_FLOAT");
    SymbolInfo *symbol1 = symbol_table.look_up(num);
        ofstream token(token_file, ios::app);
        token << "<CONST_FLOAT, "<<num<<"> ";
        token.close();
    if(symbol1 != NULL){
        cout<<"< "<<num<<" : CONST_FLOAT > already exists in ScopeTable# "<< symbol_table.getCurrentScope()->getName()<<" at position "<< symbol1->i<<", "<<symbol1->j<<endl<<endl;
    }
    else{
    bool x = symbol_table.insert(symbol);

    if(x){
        symbol_table.print_all_scope_lex();
        cout<<endl;
    }
    }
}



{digit}+ {
        string num(yytext);
    // cout<<"num ="<< num<<endl;
    SymbolInfo *symbol = new SymbolInfo(num, "CONST_INT");
    cout<<"Line no " << line_count << ": Token <CONST_INT> Lexeme " << num << " found" << endl<<endl;
    SymbolInfo *symbol1 = symbol_table.look_up(num);
    ofstream token(token_file, ios::app);
    token << "<CONST_INT, "<<num<<"> ";
    token.close();
    if(symbol1 != NULL){
        cout<<"< "<<num<<" : CONST_INT > already exists in ScopeTable# "<< symbol_table.getCurrentScope()->getName()<<" at position "<< symbol1->i<<", "<<symbol1->j<<endl<<endl;
    }
    else {
    bool x = symbol_table.insert(symbol);
    if(x){
        symbol_table.print_all_scope_lex();
        cout<<endl;
    }
    }
}

\'{alpha}\' {
    string str(yytext);
    string str1 = str.substr(1, str.length() - 2);
    // cout<<"StR_CNr"<<str<<endl;
    cout << "Line no " << line_count << ": Token <CONST_CHAR> Lexeme " << str << " found --> <CONST_CHAR, "<<str1<<">" << endl<<endl;
    SymbolInfo *symbol = new SymbolInfo(str, "CONST_CHAR");
    SymbolInfo *symbol1 = symbol_table.look_up(str);
        ofstream token(token_file, ios::app);
        token << "<CONST_CHAR, "<<str1<<"> ";
        token.close();
    if(symbol1 != NULL){
        cout<<"< "<<str<<" : CONST_CHAR > already exists in ScopeTable# "<< symbol_table.getCurrentScope()->getName()<<" at position "<< symbol1->i<<", "<<symbol1->j<<endl<<endl;
    }
    else {
    bool x = symbol_table.insert(symbol);

    if(x){
        symbol_table.print_all_scope_lex();
        cout<<endl;
    }
    }
}

'\\[ntafrbv0\\]' {
    string str(yytext);
    char c;
    switch(str[2]){
        case 'n':
            c = '\n';
            break;
        case 't':
            c = '\t';
            break;
        case 'a':
            c = '\a';
            break;
        case 'f':
            c = '\f';
            break;
        case 'r':
            c = '\r';
            break;
        case 'b':
            c = '\b';
            break;
        case 'v':
            c = '\v';
            break;
        case '0':
            c = '\0';
            break;
        case '\\':
            c = '\\';
            break;
    }
    cout << "Line no " << line_count << ": Token <CONST_CHAR> Lexeme " << str << " found --> <CONST_CHAR, "<<c<<">" << endl<<endl;
    SymbolInfo *symbol = new SymbolInfo(str, "CONST_CHAR");
    SymbolInfo *symbol1 = symbol_table.look_up(str);
        ofstream token(token_file, ios::app);
        token << "<CONST_CHAR, "<<c<<"> ";
        token.close();
    if(symbol1 != NULL){
        cout<<"< "<<str<<" : CONST_CHAR > already exists in ScopeTable# "<< symbol_table.getCurrentScope()->getName()<<" at position "<< symbol1->i<<", "<<symbol1->j<<endl<<endl;
    }
    else{
    bool x = symbol_table.insert(symbol);

    if(x){
        symbol_table.print_all_scope_lex();
        cout<<endl;
    }
    }
}


{nothing} {
    string str(yytext);
    cout<<"Error at line no " << line_count << ": Unrecognized character " << str << endl;
    cout<<endl;
    error_count++;
}



%%

int main(int argc, char *argv[]) {
    if (argc != 4) {
        cout << "Please provide input file name and try again" << endl;
        return 0;
    }
    
    FILE *fin = fopen(argv[1], "r");
    if (!fin) {
        cout << "Cannot open specified file" << endl;
        return 0;
    }
    freopen(argv[2], "w", stdout);
    
    token_file = argv[3];
    ofstream token(argv[3], ios::trunc);
    token.close();

    ifstream key_file("key.txt");
    string line;
    while (getline(key_file, line)) {
        if (!line.empty() && (line.back() == '\r' || line.back() == '\n'))
            line.pop_back();
        keyword[line] = true;
        /* dbg(line);
        dbg(keyword[line]); */
    }
    key_file.close();
    ifstream op_file("operator.txt");
    while (getline(op_file, line)) {
        if (!line.empty() && (line.back() == '\r' || line.back() == '\n'))
            line.pop_back();
        string line2;
        getline(op_file, line2);
        operator_name[line] = line2;
    }
    op_file.close();







    yyin = fin;
    yylex();
    fclose(fin);
    symbol_table.print_all_scope_lex();
    cout<<endl;
    cout << "Total lines: " << line_count << endl;
    cout << "Total errors: " << error_count << endl;
    return 0;
}
