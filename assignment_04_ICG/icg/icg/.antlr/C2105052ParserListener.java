// Generated from d:/apps/offline3/C2105052Parser.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link C2105052Parser}.
 */
public interface C2105052ParserListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link C2105052Parser#start}.
	 * @param ctx the parse tree
	 */
	void enterStart(C2105052Parser.StartContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105052Parser#start}.
	 * @param ctx the parse tree
	 */
	void exitStart(C2105052Parser.StartContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105052Parser#program}.
	 * @param ctx the parse tree
	 */
	void enterProgram(C2105052Parser.ProgramContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105052Parser#program}.
	 * @param ctx the parse tree
	 */
	void exitProgram(C2105052Parser.ProgramContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105052Parser#unit}.
	 * @param ctx the parse tree
	 */
	void enterUnit(C2105052Parser.UnitContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105052Parser#unit}.
	 * @param ctx the parse tree
	 */
	void exitUnit(C2105052Parser.UnitContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105052Parser#func_declaration}.
	 * @param ctx the parse tree
	 */
	void enterFunc_declaration(C2105052Parser.Func_declarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105052Parser#func_declaration}.
	 * @param ctx the parse tree
	 */
	void exitFunc_declaration(C2105052Parser.Func_declarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105052Parser#func_definition}.
	 * @param ctx the parse tree
	 */
	void enterFunc_definition(C2105052Parser.Func_definitionContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105052Parser#func_definition}.
	 * @param ctx the parse tree
	 */
	void exitFunc_definition(C2105052Parser.Func_definitionContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105052Parser#compound_statement}.
	 * @param ctx the parse tree
	 */
	void enterCompound_statement(C2105052Parser.Compound_statementContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105052Parser#compound_statement}.
	 * @param ctx the parse tree
	 */
	void exitCompound_statement(C2105052Parser.Compound_statementContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105052Parser#var_declaration}.
	 * @param ctx the parse tree
	 */
	void enterVar_declaration(C2105052Parser.Var_declarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105052Parser#var_declaration}.
	 * @param ctx the parse tree
	 */
	void exitVar_declaration(C2105052Parser.Var_declarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105052Parser#declaration_list}.
	 * @param ctx the parse tree
	 */
	void enterDeclaration_list(C2105052Parser.Declaration_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105052Parser#declaration_list}.
	 * @param ctx the parse tree
	 */
	void exitDeclaration_list(C2105052Parser.Declaration_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105052Parser#declaration_list_err}.
	 * @param ctx the parse tree
	 */
	void enterDeclaration_list_err(C2105052Parser.Declaration_list_errContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105052Parser#declaration_list_err}.
	 * @param ctx the parse tree
	 */
	void exitDeclaration_list_err(C2105052Parser.Declaration_list_errContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105052Parser#type_specifier}.
	 * @param ctx the parse tree
	 */
	void enterType_specifier(C2105052Parser.Type_specifierContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105052Parser#type_specifier}.
	 * @param ctx the parse tree
	 */
	void exitType_specifier(C2105052Parser.Type_specifierContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105052Parser#parameter_list}.
	 * @param ctx the parse tree
	 */
	void enterParameter_list(C2105052Parser.Parameter_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105052Parser#parameter_list}.
	 * @param ctx the parse tree
	 */
	void exitParameter_list(C2105052Parser.Parameter_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105052Parser#statements}.
	 * @param ctx the parse tree
	 */
	void enterStatements(C2105052Parser.StatementsContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105052Parser#statements}.
	 * @param ctx the parse tree
	 */
	void exitStatements(C2105052Parser.StatementsContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105052Parser#statement}.
	 * @param ctx the parse tree
	 */
	void enterStatement(C2105052Parser.StatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105052Parser#statement}.
	 * @param ctx the parse tree
	 */
	void exitStatement(C2105052Parser.StatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105052Parser#expression_statement}.
	 * @param ctx the parse tree
	 */
	void enterExpression_statement(C2105052Parser.Expression_statementContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105052Parser#expression_statement}.
	 * @param ctx the parse tree
	 */
	void exitExpression_statement(C2105052Parser.Expression_statementContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105052Parser#variable}.
	 * @param ctx the parse tree
	 */
	void enterVariable(C2105052Parser.VariableContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105052Parser#variable}.
	 * @param ctx the parse tree
	 */
	void exitVariable(C2105052Parser.VariableContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105052Parser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExpression(C2105052Parser.ExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105052Parser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExpression(C2105052Parser.ExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105052Parser#logic_expression}.
	 * @param ctx the parse tree
	 */
	void enterLogic_expression(C2105052Parser.Logic_expressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105052Parser#logic_expression}.
	 * @param ctx the parse tree
	 */
	void exitLogic_expression(C2105052Parser.Logic_expressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105052Parser#rel_expression}.
	 * @param ctx the parse tree
	 */
	void enterRel_expression(C2105052Parser.Rel_expressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105052Parser#rel_expression}.
	 * @param ctx the parse tree
	 */
	void exitRel_expression(C2105052Parser.Rel_expressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105052Parser#simple_expression}.
	 * @param ctx the parse tree
	 */
	void enterSimple_expression(C2105052Parser.Simple_expressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105052Parser#simple_expression}.
	 * @param ctx the parse tree
	 */
	void exitSimple_expression(C2105052Parser.Simple_expressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105052Parser#term}.
	 * @param ctx the parse tree
	 */
	void enterTerm(C2105052Parser.TermContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105052Parser#term}.
	 * @param ctx the parse tree
	 */
	void exitTerm(C2105052Parser.TermContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105052Parser#unary_expression}.
	 * @param ctx the parse tree
	 */
	void enterUnary_expression(C2105052Parser.Unary_expressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105052Parser#unary_expression}.
	 * @param ctx the parse tree
	 */
	void exitUnary_expression(C2105052Parser.Unary_expressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105052Parser#factor}.
	 * @param ctx the parse tree
	 */
	void enterFactor(C2105052Parser.FactorContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105052Parser#factor}.
	 * @param ctx the parse tree
	 */
	void exitFactor(C2105052Parser.FactorContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105052Parser#argument_list}.
	 * @param ctx the parse tree
	 */
	void enterArgument_list(C2105052Parser.Argument_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105052Parser#argument_list}.
	 * @param ctx the parse tree
	 */
	void exitArgument_list(C2105052Parser.Argument_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105052Parser#arguments}.
	 * @param ctx the parse tree
	 */
	void enterArguments(C2105052Parser.ArgumentsContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105052Parser#arguments}.
	 * @param ctx the parse tree
	 */
	void exitArguments(C2105052Parser.ArgumentsContext ctx);
}