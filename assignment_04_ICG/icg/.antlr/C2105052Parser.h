
    #include <iostream>
    #include <fstream>
    #include <string>
    #include <cstdlib>
    #include "C2105052Lexer.h"

    extern std::ofstream parserLogFile;
    extern std::ofstream errorFile;

    extern int syntaxErrorCount;
    // extern std::ofstream parserLogFile;
    
    #include "2105052_symbol_table.hpp"
	extern SymbolTable *symbolTable;


// Generated from d:/apps/icg/C2105052Parser.g4 by ANTLR 4.13.1

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

   
  };

  StartContext* start();

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    std::vector<std::string> code;
    int line;
    C2105052Parser::ProgramContext *p = nullptr;
    C2105052Parser::UnitContext *u = nullptr;
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnitContext *unit();
    ProgramContext *program();

   
  };

  ProgramContext* program();
  ProgramContext* program(int precedence);
  class  UnitContext : public antlr4::ParserRuleContext {
  public:
    std::vector<string> unit_code;
    int line;
    C2105052Parser::Var_declarationContext *v = nullptr;
    C2105052Parser::Func_declarationContext *f = nullptr;
    C2105052Parser::Func_definitionContext *f_def = nullptr;
    UnitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Var_declarationContext *var_declaration();
    Func_declarationContext *func_declaration();
    Func_definitionContext *func_definition();

   
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

   
  };

  Declaration_listContext* declaration_list();
  Declaration_listContext* declaration_list(int precedence);
  class  Declaration_list_errContext : public antlr4::ParserRuleContext {
  public:
    std::string error_name;
    Declaration_list_errContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
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

   
  };

  Rel_expressionContext* rel_expression();

  class  Simple_expressionContext : public antlr4::ParserRuleContext {
  public:
    vector<string> terms;
    int line;
    C2105052Parser::Simple_expressionContext *s = nullptr;
    C2105052Parser::TermContext *t = nullptr;
    antlr4::Token *addopToken = nullptr;
    antlr4::Token *ad = nullptr;
    antlr4::Token *as = nullptr;
    C2105052Parser::TermContext *t2 = nullptr;
    Simple_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TermContext *term();
    antlr4::tree::TerminalNode *ADDOP();
    Simple_expressionContext *simple_expression();
    antlr4::tree::TerminalNode *ASSIGNOP();

   
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

   
  };

  FactorContext* factor();

  class  Argument_listContext : public antlr4::ParserRuleContext {
  public:
    std::vector<std::string> arg;
    C2105052Parser::ArgumentsContext *ar = nullptr;
    Argument_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ArgumentsContext *arguments();

   
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

