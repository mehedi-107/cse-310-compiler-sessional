
// Generated from C2105052Parser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "C2105052ParserListener.h"


/**
 * This class provides an empty implementation of C2105052ParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  C2105052ParserBaseListener : public C2105052ParserListener {
public:

  virtual void enterStart(C2105052Parser::StartContext * /*ctx*/) override { }
  virtual void exitStart(C2105052Parser::StartContext * /*ctx*/) override { }

  virtual void enterProgram_program_unit(C2105052Parser::Program_program_unitContext * /*ctx*/) override { }
  virtual void exitProgram_program_unit(C2105052Parser::Program_program_unitContext * /*ctx*/) override { }

  virtual void enterProgram_unit(C2105052Parser::Program_unitContext * /*ctx*/) override { }
  virtual void exitProgram_unit(C2105052Parser::Program_unitContext * /*ctx*/) override { }

  virtual void enterUnit(C2105052Parser::UnitContext * /*ctx*/) override { }
  virtual void exitUnit(C2105052Parser::UnitContext * /*ctx*/) override { }

  virtual void enterFunc_declaration(C2105052Parser::Func_declarationContext * /*ctx*/) override { }
  virtual void exitFunc_declaration(C2105052Parser::Func_declarationContext * /*ctx*/) override { }

  virtual void enterFunc_definition(C2105052Parser::Func_definitionContext * /*ctx*/) override { }
  virtual void exitFunc_definition(C2105052Parser::Func_definitionContext * /*ctx*/) override { }

  virtual void enterCompound_statement(C2105052Parser::Compound_statementContext * /*ctx*/) override { }
  virtual void exitCompound_statement(C2105052Parser::Compound_statementContext * /*ctx*/) override { }

  virtual void enterVar_declaration(C2105052Parser::Var_declarationContext * /*ctx*/) override { }
  virtual void exitVar_declaration(C2105052Parser::Var_declarationContext * /*ctx*/) override { }

  virtual void enterDeclaration_list(C2105052Parser::Declaration_listContext * /*ctx*/) override { }
  virtual void exitDeclaration_list(C2105052Parser::Declaration_listContext * /*ctx*/) override { }

  virtual void enterDeclaration_list_err(C2105052Parser::Declaration_list_errContext * /*ctx*/) override { }
  virtual void exitDeclaration_list_err(C2105052Parser::Declaration_list_errContext * /*ctx*/) override { }

  virtual void enterType_specifier(C2105052Parser::Type_specifierContext * /*ctx*/) override { }
  virtual void exitType_specifier(C2105052Parser::Type_specifierContext * /*ctx*/) override { }

  virtual void enterParameter_list(C2105052Parser::Parameter_listContext * /*ctx*/) override { }
  virtual void exitParameter_list(C2105052Parser::Parameter_listContext * /*ctx*/) override { }

  virtual void enterStatements(C2105052Parser::StatementsContext * /*ctx*/) override { }
  virtual void exitStatements(C2105052Parser::StatementsContext * /*ctx*/) override { }

  virtual void enterStatement(C2105052Parser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(C2105052Parser::StatementContext * /*ctx*/) override { }

  virtual void enterExpression_statement(C2105052Parser::Expression_statementContext * /*ctx*/) override { }
  virtual void exitExpression_statement(C2105052Parser::Expression_statementContext * /*ctx*/) override { }

  virtual void enterVariable(C2105052Parser::VariableContext * /*ctx*/) override { }
  virtual void exitVariable(C2105052Parser::VariableContext * /*ctx*/) override { }

  virtual void enterExpression(C2105052Parser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(C2105052Parser::ExpressionContext * /*ctx*/) override { }

  virtual void enterLogic_expression(C2105052Parser::Logic_expressionContext * /*ctx*/) override { }
  virtual void exitLogic_expression(C2105052Parser::Logic_expressionContext * /*ctx*/) override { }

  virtual void enterRel_expression(C2105052Parser::Rel_expressionContext * /*ctx*/) override { }
  virtual void exitRel_expression(C2105052Parser::Rel_expressionContext * /*ctx*/) override { }

  virtual void enterSimple_expression(C2105052Parser::Simple_expressionContext * /*ctx*/) override { }
  virtual void exitSimple_expression(C2105052Parser::Simple_expressionContext * /*ctx*/) override { }

  virtual void enterTerm(C2105052Parser::TermContext * /*ctx*/) override { }
  virtual void exitTerm(C2105052Parser::TermContext * /*ctx*/) override { }

  virtual void enterUnary_expression(C2105052Parser::Unary_expressionContext * /*ctx*/) override { }
  virtual void exitUnary_expression(C2105052Parser::Unary_expressionContext * /*ctx*/) override { }

  virtual void enterFactor(C2105052Parser::FactorContext * /*ctx*/) override { }
  virtual void exitFactor(C2105052Parser::FactorContext * /*ctx*/) override { }

  virtual void enterArgument_list(C2105052Parser::Argument_listContext * /*ctx*/) override { }
  virtual void exitArgument_list(C2105052Parser::Argument_listContext * /*ctx*/) override { }

  virtual void enterArguments(C2105052Parser::ArgumentsContext * /*ctx*/) override { }
  virtual void exitArguments(C2105052Parser::ArgumentsContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

