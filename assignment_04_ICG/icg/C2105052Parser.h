
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


// Generated from C2105052Parser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  C2105052Parser : public antlr4::Parser {
public:
  enum {
    LINE_COMMENT = 1, BLOCK_COMMENT = 2, STRING = 3, WS = 4, IF = 5, ELSE = 6, 
    FOR = 7, WHILE = 8, PRINTLN = 9, RETURN = 10, INT = 11, FLOAT = 12, 
    VOID = 13, LPAREN = 14, RPAREN = 15, LCURL = 16, RCURL = 17, LTHIRD = 18, 
    RTHIRD = 19, SEMICOLON = 20, COMMA = 21, ADDOP = 22, SUBOP = 23, MULOP = 24, 
    INCOP = 25, DECOP = 26, NOT = 27, RELOP = 28, LOGICOP = 29, ASSIGNOP = 30, 
    ID = 31, CONST_INT = 32, CONST_FLOAT = 33, UNRECOGNIZED = 34
  };

  enum {
    RuleStart = 0, RuleProgram = 1, RuleUnit = 2, RuleFunc_declaration = 3, 
    RuleFunc_definition = 4, RuleCompound_statement = 5, RuleVar_declaration = 6, 
    RuleDeclaration_list = 7, RuleDeclaration_list_err = 8, RuleType_specifier = 9, 
    RuleParameter_list = 10, RuleStatements = 11, RuleStatement = 12, RuleExpression_statement = 13, 
    RuleVariable = 14, RuleExpression = 15, RuleLogic_expression = 16, RuleRel_expression = 17, 
    RuleSimple_expression = 18, RuleTerm = 19, RuleUnary_expression = 20, 
    RuleFactor = 21, RuleArgument_list = 22, RuleArguments = 23
  };

  explicit C2105052Parser(antlr4::TokenStream *input);

  C2105052Parser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~C2105052Parser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


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



  class StartContext;
  class ProgramContext;
  class UnitContext;
  class Func_declarationContext;
  class Func_definitionContext;
  class Compound_statementContext;
  class Var_declarationContext;
  class Declaration_listContext;
  class Declaration_list_errContext;
  class Type_specifierContext;
  class Parameter_listContext;
  class StatementsContext;
  class StatementContext;
  class Expression_statementContext;
  class VariableContext;
  class ExpressionContext;
  class Logic_expressionContext;
  class Rel_expressionContext;
  class Simple_expressionContext;
  class TermContext;
  class Unary_expressionContext;
  class FactorContext;
  class Argument_listContext;
  class ArgumentsContext; 

  class  StartContext : public antlr4::ParserRuleContext {
  public:
    C2105052Parser::ProgramContext *p = nullptr;
    StartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ProgramContext *program();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StartContext* start();

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    std::vector<std::string> code;
    int line;
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnitContext *unit();
    ProgramContext *program();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ProgramContext* program();
  ProgramContext* program(int precedence);
  class  UnitContext : public antlr4::ParserRuleContext {
  public:
    std::vector<string> unit_code;
    int line;
    UnitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Var_declarationContext *var_declaration();
    Func_declarationContext *func_declaration();
    Func_definitionContext *func_definition();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  UnitContext* unit();

  class  Func_declarationContext : public antlr4::ParserRuleContext {
  public:
    string func_def;
    int line;
    C2105052Parser::Type_specifierContext *t = nullptr;
    antlr4::Token *id = nullptr;
    C2105052Parser::Parameter_listContext *pl = nullptr;
    Func_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *SEMICOLON();
    Type_specifierContext *type_specifier();
    antlr4::tree::TerminalNode *ID();
    Parameter_listContext *parameter_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Func_declarationContext* func_declaration();

  class  Func_definitionContext : public antlr4::ParserRuleContext {
  public:
    vector<string> code;
    int line;
    C2105052Parser::Type_specifierContext *t = nullptr;
    antlr4::Token *id = nullptr;
    C2105052Parser::Parameter_listContext *pl = nullptr;
    C2105052Parser::Compound_statementContext *c = nullptr;
    C2105052Parser::Compound_statementContext *compound_statementContext = nullptr;
    C2105052Parser::Compound_statementContext *cs = nullptr;
    Func_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    Type_specifierContext *type_specifier();
    antlr4::tree::TerminalNode *ID();
    Parameter_listContext *parameter_list();
    Compound_statementContext *compound_statement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Func_definitionContext* func_definition();

  class  Compound_statementContext : public antlr4::ParserRuleContext {
  public:
    vector<pair<string,string>> params;
    vector<string> code;
    int line;
    C2105052Parser::StatementsContext *st = nullptr;
    antlr4::Token *rcurlToken = nullptr;
    Compound_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    Compound_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState, vector<pair<string,string>> params);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LCURL();
    antlr4::tree::TerminalNode *RCURL();
    StatementsContext *statements();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Compound_statementContext* compound_statement(vector<pair<string,string>> params);

  class  Var_declarationContext : public antlr4::ParserRuleContext {
  public:
    std::string txt;
    int line;
    C2105052Parser::Type_specifierContext *t = nullptr;
    C2105052Parser::Declaration_listContext *dl = nullptr;
    antlr4::Token *sm = nullptr;
    C2105052Parser::Declaration_list_errContext *de = nullptr;
    Var_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_specifierContext *type_specifier();
    Declaration_listContext *declaration_list();
    antlr4::tree::TerminalNode *SEMICOLON();
    Declaration_list_errContext *declaration_list_err();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Var_declarationContext* var_declaration();

  class  Declaration_listContext : public antlr4::ParserRuleContext {
  public:
    std::vector<std::string> nameList;
    C2105052Parser::Declaration_listContext *dl = nullptr;
    C2105052Parser::Declaration_listContext *pl = nullptr;
    antlr4::Token *idToken = nullptr;
    antlr4::Token *const_intToken = nullptr;
    antlr4::Token *first = nullptr;
    antlr4::Token *op = nullptr;
    antlr4::Token *second = nullptr;
    antlr4::Token *addopToken = nullptr;
    Declaration_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    antlr4::tree::TerminalNode *LTHIRD();
    antlr4::tree::TerminalNode *CONST_INT();
    antlr4::tree::TerminalNode *RTHIRD();
    antlr4::tree::TerminalNode *ADDOP();
    antlr4::tree::TerminalNode *COMMA();
    Declaration_listContext *declaration_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Declaration_listContext* declaration_list();
  Declaration_listContext* declaration_list(int precedence);
  class  Declaration_list_errContext : public antlr4::ParserRuleContext {
  public:
    std::string error_name;
    Declaration_list_errContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Declaration_list_errContext* declaration_list_err();

  class  Type_specifierContext : public antlr4::ParserRuleContext {
  public:
    std::string txt;
    std::string type;
    antlr4::Token *intToken = nullptr;
    antlr4::Token *floatToken = nullptr;
    antlr4::Token *voidToken = nullptr;
    Type_specifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *VOID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Type_specifierContext* type_specifier();

  class  Parameter_listContext : public antlr4::ParserRuleContext {
  public:
    std::vector<std::pair<std::string,std::string>> params;
    C2105052Parser::Parameter_listContext *pl = nullptr;
    C2105052Parser::Type_specifierContext *t = nullptr;
    antlr4::Token *id = nullptr;
    antlr4::Token *addopToken = nullptr;
    Parameter_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_specifierContext *type_specifier();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *ADDOP();
    antlr4::tree::TerminalNode *COMMA();
    Parameter_listContext *parameter_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Parameter_listContext* parameter_list();
  Parameter_listContext* parameter_list(int precedence);
  class  StatementsContext : public antlr4::ParserRuleContext {
  public:
    vector<string> code;
    int line;
    C2105052Parser::StatementsContext *ss = nullptr;
    C2105052Parser::StatementContext *st = nullptr;
    C2105052Parser::StatementContext *s = nullptr;
    StatementsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatementContext *statement();
    StatementsContext *statements();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StatementsContext* statements();
  StatementsContext* statements(int precedence);
  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    vector<string> code;
    int line;
    C2105052Parser::Var_declarationContext *var = nullptr;
    C2105052Parser::Expression_statementContext *es = nullptr;
    C2105052Parser::Compound_statementContext *c = nullptr;
    C2105052Parser::Expression_statementContext *e1 = nullptr;
    C2105052Parser::Expression_statementContext *e2 = nullptr;
    C2105052Parser::ExpressionContext *e3 = nullptr;
    C2105052Parser::StatementContext *s = nullptr;
    C2105052Parser::ExpressionContext *expressionContext = nullptr;
    C2105052Parser::ExpressionContext *ex = nullptr;
    C2105052Parser::StatementContext *s1 = nullptr;
    C2105052Parser::StatementContext *s2 = nullptr;
    C2105052Parser::StatementContext *statementContext = nullptr;
    antlr4::Token *idToken = nullptr;
    antlr4::Token *returnToken = nullptr;
    C2105052Parser::ExpressionContext *expr = nullptr;
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Var_declarationContext *var_declaration();
    std::vector<Expression_statementContext *> expression_statement();
    Expression_statementContext* expression_statement(size_t i);
    Compound_statementContext *compound_statement();
    antlr4::tree::TerminalNode *FOR();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    ExpressionContext *expression();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *ELSE();
    antlr4::tree::TerminalNode *WHILE();
    antlr4::tree::TerminalNode *PRINTLN();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *RETURN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StatementContext* statement();

  class  Expression_statementContext : public antlr4::ParserRuleContext {
  public:
    string str;
    int line;
    antlr4::Token *semicolonToken = nullptr;
    C2105052Parser::ExpressionContext *exp = nullptr;
    Expression_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Expression_statementContext* expression_statement();

  class  VariableContext : public antlr4::ParserRuleContext {
  public:
    std::string varName;
    int line;
    antlr4::Token *idToken = nullptr;
    C2105052Parser::ExpressionContext *expressionContext = nullptr;
    VariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LTHIRD();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RTHIRD();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VariableContext* variable();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    string str;
    int line;
    C2105052Parser::Logic_expressionContext *l_expr = nullptr;
    C2105052Parser::VariableContext *var = nullptr;
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Logic_expressionContext *logic_expression();
    antlr4::tree::TerminalNode *ASSIGNOP();
    VariableContext *variable();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExpressionContext* expression();

  class  Logic_expressionContext : public antlr4::ParserRuleContext {
  public:
    vector<string> rel_expr;
    int line;
    C2105052Parser::Rel_expressionContext *r_expr = nullptr;
    C2105052Parser::Rel_expressionContext *r1 = nullptr;
    antlr4::Token *logicopToken = nullptr;
    C2105052Parser::Rel_expressionContext *r2 = nullptr;
    Logic_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Rel_expressionContext *> rel_expression();
    Rel_expressionContext* rel_expression(size_t i);
    antlr4::tree::TerminalNode *LOGICOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Logic_expressionContext* logic_expression();

  class  Rel_expressionContext : public antlr4::ParserRuleContext {
  public:
    vector<string> simple_expr;
    int line;
    C2105052Parser::Simple_expressionContext *s_expr = nullptr;
    antlr4::Token *relopToken = nullptr;
    C2105052Parser::Simple_expressionContext *ss = nullptr;
    Rel_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Simple_expressionContext *> simple_expression();
    Simple_expressionContext* simple_expression(size_t i);
    antlr4::tree::TerminalNode *RELOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Rel_expressionContext* rel_expression();

  class  Simple_expressionContext : public antlr4::ParserRuleContext {
  public:
    vector<string> terms;
    int line;
    C2105052Parser::Simple_expressionContext *s = nullptr;
    C2105052Parser::TermContext *t = nullptr;
    antlr4::Token *addopToken = nullptr;
    Simple_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TermContext *term();
    antlr4::tree::TerminalNode *ADDOP();
    Simple_expressionContext *simple_expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Simple_expressionContext* simple_expression();
  Simple_expressionContext* simple_expression(int precedence);
  class  TermContext : public antlr4::ParserRuleContext {
  public:
    string trm;
    int line;
    C2105052Parser::TermContext *t = nullptr;
    C2105052Parser::Unary_expressionContext *u_expr = nullptr;
    antlr4::Token *mulopToken = nullptr;
    C2105052Parser::Unary_expressionContext *u = nullptr;
    antlr4::Token *unrecognizedToken = nullptr;
    TermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Unary_expressionContext *unary_expression();
    antlr4::tree::TerminalNode *MULOP();
    TermContext *term();
    antlr4::tree::TerminalNode *UNRECOGNIZED();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TermContext* term();
  TermContext* term(int precedence);
  class  Unary_expressionContext : public antlr4::ParserRuleContext {
  public:
    std::string unary_expr;
    int line;
    antlr4::Token *addopToken = nullptr;
    C2105052Parser::Unary_expressionContext *unary_expressionContext = nullptr;
    C2105052Parser::FactorContext *fact = nullptr;
    Unary_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ADDOP();
    Unary_expressionContext *unary_expression();
    antlr4::tree::TerminalNode *NOT();
    FactorContext *factor();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Unary_expressionContext* unary_expression();

  class  FactorContext : public antlr4::ParserRuleContext {
  public:
    std::string factorName;
    int line;
    C2105052Parser::VariableContext *var = nullptr;
    antlr4::Token *idToken = nullptr;
    C2105052Parser::Argument_listContext *ar = nullptr;
    C2105052Parser::ExpressionContext *exp = nullptr;
    antlr4::Token *c_int = nullptr;
    antlr4::Token *c_float = nullptr;
    C2105052Parser::VariableContext *variableContext = nullptr;
    FactorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableContext *variable();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    Argument_listContext *argument_list();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *CONST_INT();
    antlr4::tree::TerminalNode *CONST_FLOAT();
    antlr4::tree::TerminalNode *INCOP();
    antlr4::tree::TerminalNode *DECOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FactorContext* factor();

  class  Argument_listContext : public antlr4::ParserRuleContext {
  public:
    std::vector<std::string> arg;
    C2105052Parser::ArgumentsContext *ar = nullptr;
    Argument_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ArgumentsContext *arguments();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Argument_listContext* argument_list();

  class  ArgumentsContext : public antlr4::ParserRuleContext {
  public:
    std::vector<std::string> arg;
    int line;
    C2105052Parser::ArgumentsContext *ar = nullptr;
    C2105052Parser::Logic_expressionContext *l = nullptr;
    ArgumentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Logic_expressionContext *logic_expression();
    antlr4::tree::TerminalNode *COMMA();
    ArgumentsContext *arguments();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ArgumentsContext* arguments();
  ArgumentsContext* arguments(int precedence);

  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool programSempred(ProgramContext *_localctx, size_t predicateIndex);
  bool declaration_listSempred(Declaration_listContext *_localctx, size_t predicateIndex);
  bool parameter_listSempred(Parameter_listContext *_localctx, size_t predicateIndex);
  bool statementsSempred(StatementsContext *_localctx, size_t predicateIndex);
  bool simple_expressionSempred(Simple_expressionContext *_localctx, size_t predicateIndex);
  bool termSempred(TermContext *_localctx, size_t predicateIndex);
  bool argumentsSempred(ArgumentsContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

