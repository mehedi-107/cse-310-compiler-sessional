// Generated from d:/apps/icg/C2105052Parser.g4 by ANTLR 4.13.1

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

import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class C2105052Parser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		LINE_COMMENT=1, BLOCK_COMMENT=2, STRING=3, WS=4, IF=5, ELSE=6, FOR=7, 
		WHILE=8, PRINTLN=9, RETURN=10, INT=11, FLOAT=12, VOID=13, LPAREN=14, RPAREN=15, 
		LCURL=16, RCURL=17, LTHIRD=18, RTHIRD=19, SEMICOLON=20, COMMA=21, ADDOP=22, 
		SUBOP=23, MULOP=24, INCOP=25, DECOP=26, NOT=27, RELOP=28, LOGICOP=29, 
		ASSIGNOP=30, ID=31, CONST_INT=32, CONST_FLOAT=33, UNRECOGNIZED=34;
	public static final int
		RULE_start = 0, RULE_program = 1, RULE_unit = 2, RULE_func_declaration = 3, 
		RULE_func_definition = 4, RULE_compound_statement = 5, RULE_var_declaration = 6, 
		RULE_declaration_list = 7, RULE_declaration_list_err = 8, RULE_type_specifier = 9, 
		RULE_parameter_list = 10, RULE_statements = 11, RULE_statement = 12, RULE_expression_statement = 13, 
		RULE_variable = 14, RULE_expression = 15, RULE_logic_expression = 16, 
		RULE_rel_expression = 17, RULE_simple_expression = 18, RULE_term = 19, 
		RULE_unary_expression = 20, RULE_factor = 21, RULE_argument_list = 22, 
		RULE_arguments = 23;
	private static String[] makeRuleNames() {
		return new String[] {
			"start", "program", "unit", "func_declaration", "func_definition", "compound_statement", 
			"var_declaration", "declaration_list", "declaration_list_err", "type_specifier", 
			"parameter_list", "statements", "statement", "expression_statement", 
			"variable", "expression", "logic_expression", "rel_expression", "simple_expression", 
			"term", "unary_expression", "factor", "argument_list", "arguments"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, null, null, null, "'if'", "'else'", "'for'", "'while'", "'println'", 
			"'return'", "'int'", "'float'", "'void'", "'('", "')'", "'{'", "'}'", 
			"'['", "']'", "';'", "','", null, null, null, "'++'", "'--'", "'!'", 
			null, null, "'='", null, null, null, "'#'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "LINE_COMMENT", "BLOCK_COMMENT", "STRING", "WS", "IF", "ELSE", 
			"FOR", "WHILE", "PRINTLN", "RETURN", "INT", "FLOAT", "VOID", "LPAREN", 
			"RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "SEMICOLON", "COMMA", 
			"ADDOP", "SUBOP", "MULOP", "INCOP", "DECOP", "NOT", "RELOP", "LOGICOP", 
			"ASSIGNOP", "ID", "CONST_INT", "CONST_FLOAT", "UNRECOGNIZED"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "C2105052Parser.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }


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


	public C2105052Parser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StartContext extends ParserRuleContext {
		public ProgramContext p;
		public ProgramContext program() {
			return getRuleContext(ProgramContext.class,0);
		}
		public StartContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_start; }
	}

	public final StartContext start() throws RecognitionException {
		StartContext _localctx = new StartContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_start);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(48);
			((StartContext)_localctx).p = program(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ProgramContext extends ParserRuleContext {
		public std::vector<std::string> code;
		public int line;
		public UnitContext unit() {
			return getRuleContext(UnitContext.class,0);
		}
		public ProgramContext program() {
			return getRuleContext(ProgramContext.class,0);
		}
		public ProgramContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_program; }
	}

	public final ProgramContext program() throws RecognitionException {
		return program(0);
	}

	private ProgramContext program(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ProgramContext _localctx = new ProgramContext(_ctx, _parentState);
		ProgramContext _prevctx = _localctx;
		int _startState = 2;
		enterRecursionRule(_localctx, 2, RULE_program, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(51);
			unit();
			}
			_ctx.stop = _input.LT(-1);
			setState(57);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,0,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ProgramContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_program);
					setState(53);
					if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
					setState(54);
					unit();
					}
					} 
				}
				setState(59);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,0,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class UnitContext extends ParserRuleContext {
		public std::vector<string> unit_code;
		public int line;
		public Var_declarationContext var_declaration() {
			return getRuleContext(Var_declarationContext.class,0);
		}
		public Func_declarationContext func_declaration() {
			return getRuleContext(Func_declarationContext.class,0);
		}
		public Func_definitionContext func_definition() {
			return getRuleContext(Func_definitionContext.class,0);
		}
		public UnitContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unit; }
	}

	public final UnitContext unit() throws RecognitionException {
		UnitContext _localctx = new UnitContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_unit);
		try {
			setState(63);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,1,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(60);
				var_declaration();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(61);
				func_declaration();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(62);
				func_definition();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Func_declarationContext extends ParserRuleContext {
		public string func_def;
		public int line;
		public Type_specifierContext t;
		public Token id;
		public Parameter_listContext pl;
		public TerminalNode LPAREN() { return getToken(C2105052Parser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(C2105052Parser.RPAREN, 0); }
		public TerminalNode SEMICOLON() { return getToken(C2105052Parser.SEMICOLON, 0); }
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public TerminalNode ID() { return getToken(C2105052Parser.ID, 0); }
		public Parameter_listContext parameter_list() {
			return getRuleContext(Parameter_listContext.class,0);
		}
		public Func_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_func_declaration; }
	}

	public final Func_declarationContext func_declaration() throws RecognitionException {
		Func_declarationContext _localctx = new Func_declarationContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_func_declaration);
		try {
			setState(80);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,2,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(65);
				((Func_declarationContext)_localctx).t = type_specifier();
				setState(66);
				((Func_declarationContext)_localctx).id = match(ID);
				setState(67);
				match(LPAREN);
				setState(68);
				((Func_declarationContext)_localctx).pl = parameter_list(0);
				setState(69);
				match(RPAREN);
				setState(70);
				match(SEMICOLON);

				          std::string funcName = ((Func_declarationContext)_localctx).id->getText();
				          std::string funcType = ((Func_declarationContext)_localctx).t.txt;
				          insertFunctionToSymbolTable(funcName, funcType, ((Func_declarationContext)_localctx).pl.params, ((Func_declarationContext)_localctx).id->getLine());
				      
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(73);
				((Func_declarationContext)_localctx).t = type_specifier();
				setState(74);
				((Func_declarationContext)_localctx).id = match(ID);
				setState(75);
				match(LPAREN);
				setState(76);
				match(RPAREN);
				setState(77);
				match(SEMICOLON);

				          std::string funcName = ((Func_declarationContext)_localctx).id->getText();
				          std::string funcType = ((Func_declarationContext)_localctx).t.txt;
				            insertFunctionToSymbolTable(funcName, funcType, vector<pair<string,string>>(), ((Func_declarationContext)_localctx).id->getLine());

				      
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Func_definitionContext extends ParserRuleContext {
		public vector<string> code;
		public int line;
		public Type_specifierContext t;
		public Token id;
		public Parameter_listContext pl;
		public Compound_statementContext c;
		public Compound_statementContext compound_statement;
		public Compound_statementContext cs;
		public TerminalNode LPAREN() { return getToken(C2105052Parser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(C2105052Parser.RPAREN, 0); }
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public TerminalNode ID() { return getToken(C2105052Parser.ID, 0); }
		public Parameter_listContext parameter_list() {
			return getRuleContext(Parameter_listContext.class,0);
		}
		public Compound_statementContext compound_statement() {
			return getRuleContext(Compound_statementContext.class,0);
		}
		public Func_definitionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_func_definition; }
	}

	public final Func_definitionContext func_definition() throws RecognitionException {
		Func_definitionContext _localctx = new Func_definitionContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_func_definition);
		try {
			setState(99);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(82);
				((Func_definitionContext)_localctx).t = type_specifier();
				setState(83);
				((Func_definitionContext)_localctx).id = match(ID);
				setState(84);
				match(LPAREN);
				setState(85);
				((Func_definitionContext)_localctx).pl = parameter_list(0);
				setState(86);
				match(RPAREN);

				         insertFunctionToSymbolTable(((Func_definitionContext)_localctx).id->getText(), ((Func_definitionContext)_localctx).t.txt, ((Func_definitionContext)_localctx).pl.params, ((Func_definitionContext)_localctx).id->getLine());
				        if(((Func_definitionContext)_localctx).id->getText()=="main"){
				            asmFile << "main PROC" << endl;
				            asmFile << "\tMOV AX, @DATA" << endl;
				            asmFile << "\tMOV DS, AX" << endl;
				           
				        } 
				        else{
				            // cout<<"Function name: "<<((Func_definitionContext)_localctx).id->getText()<<endl;
				            string ab = ((Func_definitionContext)_localctx).id->getText()+" PROC\t\t; line " + std::to_string(((Func_definitionContext)_localctx).id->getLine());
				            asmFile << ab << endl;;

				        }
				        // curr_func_name = ((Func_definitionContext)_localctx).id->getText();
				        asmFile<< "\tPUSH BP" << endl;
				        asmFile<< "\tMOV BP, SP" << endl;
				        stack_offset = 0;
				        func_return_label = label_count; // Store the label index for the function return
				        label_count++;
				      
				setState(88);
				((Func_definitionContext)_localctx).c = ((Func_definitionContext)_localctx).compound_statement = compound_statement(((Func_definitionContext)_localctx).pl.params);

				        ((Func_definitionContext)_localctx).code =  vector<string>();
				         writeIntoparserLogFile("Line " + std::to_string(((Func_definitionContext)_localctx).c.line) + ": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n");
				          std::string funcName = ((Func_definitionContext)_localctx).id->getText();
				          std::string funcType =((Func_definitionContext)_localctx).t.txt;
				          string str = funcType + " " + funcName + "(";
				            for (size_t i = 0; i < ((Func_definitionContext)_localctx).pl.params.size(); ++i){
				                str += ((Func_definitionContext)_localctx).pl.params[i].first;
				                if(((Func_definitionContext)_localctx).pl.params[i].second!="")
				                    str +=" "+ ((Func_definitionContext)_localctx).pl.params[i].second;
				                
				                if (i < ((Func_definitionContext)_localctx).pl.params.size() - 1) {
				                    str += ",";
				                }
				            }
				            str += ")";
				            for (const auto &line : ((Func_definitionContext)_localctx).compound_statement.code) {
				                str += line;
				                _localctx.code.push_back(str);
				                writeIntoparserLogFile(str);
				                str = "";
				            }
				            writeIntoparserLogFile("");
				            ((Func_definitionContext)_localctx).line =  ((Func_definitionContext)_localctx).c.line;



				        if(((Func_definitionContext)_localctx).id->getText()!="main"){
				            str = "L" + std::to_string(func_return_label) + ":";
				            label_count++;
				            asmFile << str << endl;
				            str = "\tMOV SP, BP";
				            asmFile << str << endl;
				            str = "\tPOP BP";
				            asmFile << str << endl;
				            str ="\tRET";
				            if(((Func_definitionContext)_localctx).pl.params.size() > 0) {
				                str += " " + std::to_string(((Func_definitionContext)_localctx).pl.params.size() * 2);
				            }
				            asmFile << str << endl;
				            str = ((Func_definitionContext)_localctx).id->getText() + " ENDP";
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
				            str = ((Func_definitionContext)_localctx).id->getText() + " ENDP";
				            asmFile << str << endl;
				        }
				        




				      
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(91);
				((Func_definitionContext)_localctx).t = type_specifier();
				setState(92);
				((Func_definitionContext)_localctx).id = match(ID);
				setState(93);
				match(LPAREN);
				setState(94);
				match(RPAREN);

				          // Function definition (no parameters)
				          std::string funcName = ((Func_definitionContext)_localctx).id->getText();
				          std::string funcType = ((Func_definitionContext)_localctx).t.txt;
				          SymbolInfo *existing2 = symbolTable->look_up(funcName);
				          insertFunctionToSymbolTable(funcName, funcType, vector<pair<string,string>>(), ((Func_definitionContext)_localctx).id->getLine());
				          if(((Func_definitionContext)_localctx).id->getText()=="main"){
				            asmFile << "main PROC" << endl;
				            asmFile << "\tMOV AX, @DATA" << endl;
				            asmFile << "\tMOV DS, AX" << endl;
				           
				          }
				          else{
				            // cout<<"Function name: "<<((Func_definitionContext)_localctx).id->getText()<<endl;
				            string ab = ((Func_definitionContext)_localctx).id->getText()+" PROC\t\t; line " + std::to_string(((Func_definitionContext)_localctx).id->getLine());
				            asmFile << ab << endl;;

				        }
				            // curr_func_name = ((Func_definitionContext)_localctx).id->getText();
				        asmFile<< "\tPUSH BP" << endl;
				        asmFile<< "\tMOV BP, SP" << endl;
				            func_return_label = label_count; // Store the label index for the function return
				            label_count++;
				        stack_offset = 0;
				      
				setState(96);
				((Func_definitionContext)_localctx).cs = compound_statement(vector<pair<string,string>>());

				        ((Func_definitionContext)_localctx).code =  vector<string>();
				        writeIntoparserLogFile("Line " + std::to_string(((Func_definitionContext)_localctx).cs.line) + ": func_definition : type_specifier ID LPAREN RPAREN compound_statement\n");
				        funcName = ((Func_definitionContext)_localctx).id->getText();
				         funcType = ((Func_definitionContext)_localctx).t.txt;
				        string str = funcType + " " + funcName + "()";
				        for (const auto &line : ((Func_definitionContext)_localctx).cs.code) {
				            str+=line;
				            _localctx.code.push_back(str);
				            writeIntoparserLogFile(str);
				            str="";
				        }
				        writeIntoparserLogFile("");
				        ((Func_definitionContext)_localctx).line =  ((Func_definitionContext)_localctx).cs.line; 

				        if(((Func_definitionContext)_localctx).id->getText()!="main"){
				            str = "L" + std::to_string(func_return_label) + ":";
				            asmFile << str << endl;
				            str = "\tMOV SP, BP";
				            asmFile << str << endl;
				            str = "\tPOP BP";
				            asmFile << str << endl;
				            str ="\tRET";
				            asmFile << str << endl;
				            str = ((Func_definitionContext)_localctx).id->getText() + " ENDP";
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
				            str = ((Func_definitionContext)_localctx).id->getText() + " ENDP";
				            asmFile << str << endl;
				        }
				        
				      
				      
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Compound_statementContext extends ParserRuleContext {
		public vector<pair<string,string>> params;
		public vector<string> code;
		public int line;
		public StatementsContext st;
		public Token RCURL;
		public TerminalNode LCURL() { return getToken(C2105052Parser.LCURL, 0); }
		public TerminalNode RCURL() { return getToken(C2105052Parser.RCURL, 0); }
		public StatementsContext statements() {
			return getRuleContext(StatementsContext.class,0);
		}
		public Compound_statementContext(ParserRuleContext parent, int invokingState) { super(parent, invokingState); }
		public Compound_statementContext(ParserRuleContext parent, int invokingState, vector<pair<string,string>> params) {
			super(parent, invokingState);
			this.params = params;
		}
		@Override public int getRuleIndex() { return RULE_compound_statement; }
	}

	public final Compound_statementContext compound_statement(vector<pair<string,string>> params) throws RecognitionException {
		Compound_statementContext _localctx = new Compound_statementContext(_ctx, getState(), params);
		enterRule(_localctx, 10, RULE_compound_statement);
		try {
			setState(110);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(101);
				match(LCURL);

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
				            
				            
				setState(103);
				((Compound_statementContext)_localctx).st = statements(0);
				setState(104);
				((Compound_statementContext)_localctx).RCURL = match(RCURL);

				            writeIntoparserLogFile("Line " + std::to_string(((Compound_statementContext)_localctx).RCURL->getLine()) + ": compound_statement : LCURL statements RCURL\n");
				            ((Compound_statementContext)_localctx).code =  vector<string>();
				            _localctx.code.push_back("{");
				            writeIntoparserLogFile("{");
				            int te=0;
				            for (const auto &line : ((Compound_statementContext)_localctx).st.code) {
				                writeIntoparserLogFile(line);
				                te++;
				                _localctx.code.push_back(line);
				            }
				            _localctx.code.push_back("}");
				            // // cout<<te<<endl;
				            string str = "}\n";
				            writeIntoparserLogFile(str);
				            symbolTable->print_all_scope_in_file(parserLogFile);
				            writeIntoparserLogFile("");
				            symbolTable->exit_scope();
				          
				            ((Compound_statementContext)_localctx).line =  ((Compound_statementContext)_localctx).RCURL->getLine();
				            
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(107);
				match(LCURL);
				setState(108);
				((Compound_statementContext)_localctx).RCURL = match(RCURL);

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
				            writeIntoparserLogFile("Line " + std::to_string(((Compound_statementContext)_localctx).RCURL->getLine()) + ": compound_statement : LCURL RCURL\n");
				            ((Compound_statementContext)_localctx).code =  vector<string>();
				            _localctx.code.push_back("{}");
				            writeIntoparserLogFile("{}\n");
				            symbolTable->print_all_scope_in_file(parserLogFile);
				            writeIntoparserLogFile("");
				            symbolTable->exit_scope();
				            ((Compound_statementContext)_localctx).line =  ((Compound_statementContext)_localctx).RCURL->getLine();
				            
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Var_declarationContext extends ParserRuleContext {
		public std::string txt;
		public int line;
		public Type_specifierContext t;
		public Declaration_listContext dl;
		public Token sm;
		public Declaration_list_errContext de;
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public Declaration_listContext declaration_list() {
			return getRuleContext(Declaration_listContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(C2105052Parser.SEMICOLON, 0); }
		public Declaration_list_errContext declaration_list_err() {
			return getRuleContext(Declaration_list_errContext.class,0);
		}
		public Var_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_var_declaration; }
	}

	public final Var_declarationContext var_declaration() throws RecognitionException {
		Var_declarationContext _localctx = new Var_declarationContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_var_declaration);
		try {
			setState(122);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,5,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(112);
				((Var_declarationContext)_localctx).t = type_specifier();
				setState(113);
				((Var_declarationContext)_localctx).dl = declaration_list(0);
				setState(114);
				((Var_declarationContext)_localctx).sm = match(SEMICOLON);

				            // // cout<<"Declaration list size: "<<((Var_declarationContext)_localctx).dl.nameList.size()<<endl;
				            writeIntoparserLogFile("Line " + std::to_string(((Var_declarationContext)_localctx).sm->getLine()) + ": var_declaration : type_specifier declaration_list SEMICOLON\n");
				            string txt = ((Var_declarationContext)_localctx).t.txt;
				            txt += " ";
				            for (const auto &name : ((Var_declarationContext)_localctx).dl.nameList) {
				                txt += name;
				                string str;
				                bool isArray = false;
				                // cout<<"Name: "<<name<<endl;
				                for(int i=0;i<name.size();i++) {if(name[i]!='[') {str+=name[i];} else {isArray = true;break;}}
				                string type = ((Var_declarationContext)_localctx).t.txt;
				                if(isArray) {
				                    type += "_array";
				                }
				                
				                SymbolInfo *s = symbolTable->look_up(str);
				                if(s->getType()== "ID")
				                    s->setType(type);
				                if (&name != &(((Var_declarationContext)_localctx).dl.nameList.back())) {
				                    txt += ",";
				                }
				                if(s->getScopeId()==1){
				                    print_global_var(name,type);
				                }
				                handle_var_declaration(s,stack_offset,name,type);
				            }
				            txt+=";";
				            // // cout<<"Declaraction list size: "<<((Var_declarationContext)_localctx).dl.nameList.size()<<endl;
				            if(((Var_declarationContext)_localctx).t.type == "VOID") {
				                writeIntoErrorFile("Error at line " + std::to_string(((Var_declarationContext)_localctx).sm->getLine()) + ": Variable type cannot be void\n");
				                syntaxErrorCount++;
				                writeIntoparserLogFile("Error at line " + std::to_string(((Var_declarationContext)_localctx).sm->getLine()) + ": Variable type cannot be void\n");
				            }

				            writeIntoparserLogFile(txt + "\n");
				            ((Var_declarationContext)_localctx).txt =  txt;
				            ((Var_declarationContext)_localctx).line =  ((Var_declarationContext)_localctx).sm->getLine();
				        
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(117);
				((Var_declarationContext)_localctx).t = type_specifier();
				setState(118);
				((Var_declarationContext)_localctx).de = declaration_list_err();
				setState(119);
				((Var_declarationContext)_localctx).sm = match(SEMICOLON);

				          writeIntoErrorFile(
				              std::string("Line# ") + std::to_string(((Var_declarationContext)_localctx).sm->getLine()) +
				              " with error name: " + ((Var_declarationContext)_localctx).de.error_name +
				              " - Syntax error at declaration list of variable declaration"
				          );
				          syntaxErrorCount++;
				      
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Declaration_listContext extends ParserRuleContext {
		public std::vector<std::string> nameList;
		public Declaration_listContext dl;
		public Declaration_listContext pl;
		public Token ID;
		public Token CONST_INT;
		public Token first;
		public Token op;
		public Token second;
		public Token ADDOP;
		public List<TerminalNode> ID() { return getTokens(C2105052Parser.ID); }
		public TerminalNode ID(int i) {
			return getToken(C2105052Parser.ID, i);
		}
		public TerminalNode LTHIRD() { return getToken(C2105052Parser.LTHIRD, 0); }
		public TerminalNode CONST_INT() { return getToken(C2105052Parser.CONST_INT, 0); }
		public TerminalNode RTHIRD() { return getToken(C2105052Parser.RTHIRD, 0); }
		public TerminalNode ADDOP() { return getToken(C2105052Parser.ADDOP, 0); }
		public TerminalNode COMMA() { return getToken(C2105052Parser.COMMA, 0); }
		public Declaration_listContext declaration_list() {
			return getRuleContext(Declaration_listContext.class,0);
		}
		public Declaration_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declaration_list; }
	}

	public final Declaration_listContext declaration_list() throws RecognitionException {
		return declaration_list(0);
	}

	private Declaration_listContext declaration_list(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Declaration_listContext _localctx = new Declaration_listContext(_ctx, _parentState);
		Declaration_listContext _prevctx = _localctx;
		int _startState = 14;
		enterRecursionRule(_localctx, 14, RULE_declaration_list, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(136);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,6,_ctx) ) {
			case 1:
				{
				setState(125);
				((Declaration_listContext)_localctx).ID = match(ID);

				          ((Declaration_listContext)_localctx).nameList =  std::vector<std::string>();
				          _localctx.nameList.push_back(((Declaration_listContext)_localctx).ID->getText());
				            insertIdInSymbolTable(((Declaration_listContext)_localctx).ID->getText(), "ID", ((Declaration_listContext)_localctx).ID->getLine());
				            writeIntoparserLogFile("Line " + std::to_string(((Declaration_listContext)_localctx).ID->getLine()) + ": declaration_list : ID\n");
				            writeIntoparserLogFile(((Declaration_listContext)_localctx).ID->getText()+ "\n");
				      
				}
				break;
			case 2:
				{
				setState(127);
				((Declaration_listContext)_localctx).ID = match(ID);
				setState(128);
				match(LTHIRD);
				setState(129);
				((Declaration_listContext)_localctx).CONST_INT = match(CONST_INT);
				setState(130);
				match(RTHIRD);

				          ((Declaration_listContext)_localctx).nameList =  std::vector<std::string>();
				          _localctx.nameList.push_back(((Declaration_listContext)_localctx).ID->getText() + "[" + ((Declaration_listContext)_localctx).CONST_INT->getText() + "]");
				            insertIdInSymbolTable(((Declaration_listContext)_localctx).ID->getText(), "ID", ((Declaration_listContext)_localctx).ID->getLine());
				            writeIntoparserLogFile("Line " + std::to_string(((Declaration_listContext)_localctx).ID->getLine()) + ": declaration_list : ID LTHIRD CONST_INT RTHIRD\n");
				            writeIntoparserLogFile(((Declaration_listContext)_localctx).ID->getText() + "[" + ((Declaration_listContext)_localctx).CONST_INT->getText() + "]\n");
				      
				}
				break;
			case 3:
				{
				setState(132);
				((Declaration_listContext)_localctx).first = match(ID);
				setState(133);
				((Declaration_listContext)_localctx).op = match(ADDOP);
				setState(134);
				((Declaration_listContext)_localctx).second = match(ID);

				            writeIntoparserLogFile("Line " + std::to_string(((Declaration_listContext)_localctx).op->getLine()) + ": declaration_list : ID\n");
				            writeIntoparserLogFile(((Declaration_listContext)_localctx).first->getText()+"\n");
				            insertIdInSymbolTable(((Declaration_listContext)_localctx).first->getText(), "ID", ((Declaration_listContext)_localctx).first->getLine());
				            writeIntoErrorFile("Error at line " + std::to_string(((Declaration_listContext)_localctx).op->getLine()) + ": syntax error, unexpected ADDOP, expecting COMMA or SEMICOLON\n");
				            syntaxErrorCount++;
				            writeIntoparserLogFile("Error at line " + std::to_string(((Declaration_listContext)_localctx).op->getLine()) + ": syntax error, unexpected ADDOP, expecting COMMA or SEMICOLON\n");
				            ((Declaration_listContext)_localctx).nameList =  std::vector<std::string>();
				             _localctx.nameList.push_back(((Declaration_listContext)_localctx).first->getText());
				      
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(157);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,8,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(155);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,7,_ctx) ) {
					case 1:
						{
						_localctx = new Declaration_listContext(_parentctx, _parentState);
						_localctx.dl = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_declaration_list);
						setState(138);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(139);
						match(COMMA);
						setState(140);
						((Declaration_listContext)_localctx).ID = match(ID);

						                    ((Declaration_listContext)_localctx).nameList =  ((Declaration_listContext)_localctx).dl.nameList;
						                    _localctx.nameList.push_back(((Declaration_listContext)_localctx).ID->getText());
						                      insertIdInSymbolTable(((Declaration_listContext)_localctx).ID->getText(), "ID", ((Declaration_listContext)_localctx).ID->getLine());
						                    writeIntoparserLogFile("Line " + std::to_string(((Declaration_listContext)_localctx).ID->getLine()) + ": declaration_list : declaration_list COMMA ID\n");
						                      string str ;
						                      for (const auto &name : _localctx.nameList) {
						                         str+= name;
						                         if (&name != &(_localctx.nameList.back())) {
						                             str += ",";
						                         }
						                      }
						                      writeIntoparserLogFile(str + "\n");
						                
						}
						break;
					case 2:
						{
						_localctx = new Declaration_listContext(_parentctx, _parentState);
						_localctx.dl = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_declaration_list);
						setState(142);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(143);
						match(COMMA);
						setState(144);
						((Declaration_listContext)_localctx).ID = match(ID);
						setState(145);
						match(LTHIRD);
						setState(146);
						((Declaration_listContext)_localctx).CONST_INT = match(CONST_INT);
						setState(147);
						match(RTHIRD);

						                    ((Declaration_listContext)_localctx).nameList =  ((Declaration_listContext)_localctx).dl.nameList;
						                    insertIdInSymbolTable(((Declaration_listContext)_localctx).ID->getText(), "ID", ((Declaration_listContext)_localctx).ID->getLine());
						                    string str = ((Declaration_listContext)_localctx).ID->getText() + "[" + ((Declaration_listContext)_localctx).CONST_INT->getText() + "]";
						                    _localctx.nameList.push_back(str);
						                    writeIntoparserLogFile("Line " + std::to_string(((Declaration_listContext)_localctx).ID->getLine()) + ": declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n");
						                      string str2;
						                      for (const auto &name : _localctx.nameList) {
						                          str2 += name;
						                          if (&name != &(_localctx.nameList.back())) {
						                              str2 += ",";
						                          }
						                      }
						                      writeIntoparserLogFile(str2 + "\n");
						                
						}
						break;
					case 3:
						{
						_localctx = new Declaration_listContext(_parentctx, _parentState);
						_localctx.pl = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_declaration_list);
						setState(149);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(150);
						match(COMMA);
						setState(151);
						((Declaration_listContext)_localctx).ID = match(ID);
						setState(152);
						((Declaration_listContext)_localctx).ADDOP = match(ADDOP);
						setState(153);
						((Declaration_listContext)_localctx).ID = match(ID);

						                      // This is an error case, where ADDOP is used incorrectly
						                      writeIntoErrorFile("Error at line " + std::to_string(((Declaration_listContext)_localctx).ADDOP->getLine()) + ": syntax error, unexpected ADDOP, expecting COMMA or RTHIRD\n");
						                      syntaxErrorCount++;
						                      writeIntoparserLogFile("Error at line " + std::to_string(((Declaration_listContext)_localctx).ADDOP->getLine()) + ": syntax error, unexpected ADDOP, expecting COMMA or RTHIRD\n");
						                      ((Declaration_listContext)_localctx).nameList =  ((Declaration_listContext)_localctx).pl.nameList;
						                      // // cout<<"Matched with declaration_list COMMA ID ADDOP ID"<<endl;
						                      _localctx.nameList.push_back(((Declaration_listContext)_localctx).ID->getText());
						                
						}
						break;
					}
					} 
				}
				setState(159);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,8,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Declaration_list_errContext extends ParserRuleContext {
		public std::string error_name;
		public Declaration_list_errContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declaration_list_err; }
	}

	public final Declaration_list_errContext declaration_list_err() throws RecognitionException {
		Declaration_list_errContext _localctx = new Declaration_list_errContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_declaration_list_err);
		try {
			enterOuterAlt(_localctx, 1);
			{

			    ((Declaration_list_errContext)_localctx).error_name =  "Error in declaration list";

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Type_specifierContext extends ParserRuleContext {
		public std::string txt;
		public std::string type;
		public Token INT;
		public Token FLOAT;
		public Token VOID;
		public TerminalNode INT() { return getToken(C2105052Parser.INT, 0); }
		public TerminalNode FLOAT() { return getToken(C2105052Parser.FLOAT, 0); }
		public TerminalNode VOID() { return getToken(C2105052Parser.VOID, 0); }
		public Type_specifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type_specifier; }
	}

	public final Type_specifierContext type_specifier() throws RecognitionException {
		Type_specifierContext _localctx = new Type_specifierContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_type_specifier);
		try {
			setState(168);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case INT:
				enterOuterAlt(_localctx, 1);
				{
				setState(162);
				((Type_specifierContext)_localctx).INT = match(INT);
				 
				        // // cout<<"INT at"<<((Type_specifierContext)_localctx).INT->getLine()<<endl;
				       ((Type_specifierContext)_localctx).txt =  ((Type_specifierContext)_localctx).INT->getText();
				         ((Type_specifierContext)_localctx).type =  "INT";
				       writeIntoparserLogFile("Line " + std::to_string(((Type_specifierContext)_localctx).INT->getLine()) + ": type_specifier : INT\n");
				       writeIntoparserLogFile(((Type_specifierContext)_localctx).INT->getText() + "\n");
				    
				}
				break;
			case FLOAT:
				enterOuterAlt(_localctx, 2);
				{
				setState(164);
				((Type_specifierContext)_localctx).FLOAT = match(FLOAT);

				            ((Type_specifierContext)_localctx).txt =  ((Type_specifierContext)_localctx).FLOAT->getText();
				            ((Type_specifierContext)_localctx).type =  "FLOAT";
				         writeIntoparserLogFile("Line " + std::to_string(((Type_specifierContext)_localctx).FLOAT->getLine()) + ": type_specifier : FLOAT\n");
				            writeIntoparserLogFile(((Type_specifierContext)_localctx).FLOAT->getText() + "\n");
				     
				}
				break;
			case VOID:
				enterOuterAlt(_localctx, 3);
				{
				setState(166);
				((Type_specifierContext)_localctx).VOID = match(VOID);
				 
				            ((Type_specifierContext)_localctx).txt =  ((Type_specifierContext)_localctx).VOID->getText();
				            ((Type_specifierContext)_localctx).type =  "VOID";
				         writeIntoparserLogFile("Line " + std::to_string(((Type_specifierContext)_localctx).VOID->getLine()) + ": type_specifier : VOID\n");
				            writeIntoparserLogFile(((Type_specifierContext)_localctx).VOID->getText() + "\n");
				      
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Parameter_listContext extends ParserRuleContext {
		public std::vector<std::pair<std::string,std::string>> params;
		public Parameter_listContext pl;
		public Type_specifierContext t;
		public Token id;
		public Token ADDOP;
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public TerminalNode ID() { return getToken(C2105052Parser.ID, 0); }
		public TerminalNode ADDOP() { return getToken(C2105052Parser.ADDOP, 0); }
		public TerminalNode COMMA() { return getToken(C2105052Parser.COMMA, 0); }
		public Parameter_listContext parameter_list() {
			return getRuleContext(Parameter_listContext.class,0);
		}
		public Parameter_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameter_list; }
	}

	public final Parameter_listContext parameter_list() throws RecognitionException {
		return parameter_list(0);
	}

	private Parameter_listContext parameter_list(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Parameter_listContext _localctx = new Parameter_listContext(_ctx, _parentState);
		Parameter_listContext _prevctx = _localctx;
		int _startState = 20;
		enterRecursionRule(_localctx, 20, RULE_parameter_list, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(179);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,10,_ctx) ) {
			case 1:
				{
				setState(171);
				((Parameter_listContext)_localctx).t = type_specifier();
				setState(172);
				((Parameter_listContext)_localctx).id = match(ID);

				        // first parameter: start fresh
				        ((Parameter_listContext)_localctx).params =  {};
				        _localctx.params.emplace_back(((Parameter_listContext)_localctx).t.txt, ((Parameter_listContext)_localctx).id->getText());
				        writeIntoparserLogFile("Line " + std::to_string(((Parameter_listContext)_localctx).id->getLine()) + ": parameter_list : type_specifier ID\n");
				        writeIntoparserLogFile(((Parameter_listContext)_localctx).t.txt + " " + ((Parameter_listContext)_localctx).id->getText() + "\n");
				        
				    
				}
				break;
			case 2:
				{
				setState(175);
				((Parameter_listContext)_localctx).t = type_specifier();
				setState(176);
				((Parameter_listContext)_localctx).ADDOP = match(ADDOP);

				        writeIntoparserLogFile("Line " + std::to_string(((Parameter_listContext)_localctx).ADDOP->getLine()) + ": parameter_list : type_specifier\n");

				        writeIntoparserLogFile(((Parameter_listContext)_localctx).t.txt+"\n");

				        writeIntoErrorFile("Error at line " + std::to_string(((Parameter_listContext)_localctx).ADDOP->getLine()) + ": syntax error, unexpected ADDOP, expecting RPAREN or COMMA\n");
				        syntaxErrorCount++;
				        writeIntoparserLogFile("Error at line " + std::to_string(((Parameter_listContext)_localctx).ADDOP->getLine()) + ": syntax error, unexpected ADDOP, expecting RPAREN or COMMA\n");
				        ((Parameter_listContext)_localctx).params =  {};
				        _localctx.params.emplace_back(((Parameter_listContext)_localctx).t.txt, "");
				    
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(189);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,11,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new Parameter_listContext(_parentctx, _parentState);
					_localctx.pl = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_parameter_list);
					setState(181);
					if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
					setState(182);
					match(COMMA);
					setState(183);
					((Parameter_listContext)_localctx).t = type_specifier();
					setState(184);
					((Parameter_listContext)_localctx).id = match(ID);

					                  // additional parameter: copy old list then append
					                  ((Parameter_listContext)_localctx).params =  ((Parameter_listContext)_localctx).pl.params;
					                  pair<string, string> newParam(((Parameter_listContext)_localctx).t.txt, ((Parameter_listContext)_localctx).id->getText());
					                  string str;
					                  for (const auto &p : _localctx.params) {
					                      if (p.first == newParam.first && p.second == newParam.second) {
					                          writeIntoErrorFile("Error at line " + std::to_string(((Parameter_listContext)_localctx).id->getLine()) + ": Multiple declaration of " + ((Parameter_listContext)_localctx).id->getText() + " in parameter\n");
					                          syntaxErrorCount++;
					                          writeIntoparserLogFile("Error at line " + std::to_string(((Parameter_listContext)_localctx).id->getLine()) + ": Multiple declaration of " + ((Parameter_listContext)_localctx).id->getText() + " in parameter\n");
					                          
					                      }
					                      str+= p.first + " " + p.second+",";
					                  }
					                  
					                  str+= ((Parameter_listContext)_localctx).t.txt + " " + ((Parameter_listContext)_localctx).id->getText();
					                  _localctx.params.push_back(newParam);
					                  writeIntoparserLogFile("Line " + std::to_string(((Parameter_listContext)_localctx).id->getLine()) + ": parameter_list : parameter_list COMMA type_specifier ID\n");
					                  writeIntoparserLogFile(str + "\n");
					              
					}
					} 
				}
				setState(191);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,11,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StatementsContext extends ParserRuleContext {
		public vector<string> code;
		public int line;
		public StatementsContext ss;
		public StatementContext st;
		public StatementContext s;
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public StatementsContext statements() {
			return getRuleContext(StatementsContext.class,0);
		}
		public StatementsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statements; }
	}

	public final StatementsContext statements() throws RecognitionException {
		return statements(0);
	}

	private StatementsContext statements(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		StatementsContext _localctx = new StatementsContext(_ctx, _parentState);
		StatementsContext _prevctx = _localctx;
		int _startState = 22;
		enterRecursionRule(_localctx, 22, RULE_statements, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(193);
			((StatementsContext)_localctx).st = statement();

			        writeIntoparserLogFile("Line " + std::to_string(((StatementsContext)_localctx).st.line) + ": statements : statement\n");
			        ((StatementsContext)_localctx).code =  ((StatementsContext)_localctx).st.code;
			        ((StatementsContext)_localctx).line =  ((StatementsContext)_localctx).st.line;
			        for (const auto &line : _localctx.code) {
			            writeIntoparserLogFile(line + "\n");

			        }
			    
			}
			_ctx.stop = _input.LT(-1);
			setState(202);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new StatementsContext(_parentctx, _parentState);
					_localctx.ss = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_statements);
					setState(196);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(197);
					((StatementsContext)_localctx).s = statement();

					                  writeIntoparserLogFile("Line " + std::to_string(((StatementsContext)_localctx).s.line) + ": statements : statements statement\n");
					                  ((StatementsContext)_localctx).code =  ((StatementsContext)_localctx).ss.code;
					                  for (const auto &line : ((StatementsContext)_localctx).s.code) {
					                      _localctx.code.push_back(line);
					                  }
					                  ((StatementsContext)_localctx).line =  ((StatementsContext)_localctx).s.line;
					                  for (const auto &line : _localctx.code) {
					                      writeIntoparserLogFile(line);
					                  }
					                  writeIntoparserLogFile("");
					              
					}
					} 
				}
				setState(204);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StatementContext extends ParserRuleContext {
		public vector<string> code;
		public int line;
		public Var_declarationContext var;
		public Expression_statementContext es;
		public Compound_statementContext c;
		public Expression_statementContext e1;
		public Expression_statementContext e2;
		public ExpressionContext e3;
		public StatementContext s;
		public ExpressionContext expression;
		public ExpressionContext ex;
		public StatementContext s1;
		public StatementContext s2;
		public StatementContext statement;
		public Token ID;
		public Token RETURN;
		public ExpressionContext expr;
		public Var_declarationContext var_declaration() {
			return getRuleContext(Var_declarationContext.class,0);
		}
		public List<Expression_statementContext> expression_statement() {
			return getRuleContexts(Expression_statementContext.class);
		}
		public Expression_statementContext expression_statement(int i) {
			return getRuleContext(Expression_statementContext.class,i);
		}
		public Compound_statementContext compound_statement() {
			return getRuleContext(Compound_statementContext.class,0);
		}
		public TerminalNode FOR() { return getToken(C2105052Parser.FOR, 0); }
		public TerminalNode LPAREN() { return getToken(C2105052Parser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(C2105052Parser.RPAREN, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public TerminalNode IF() { return getToken(C2105052Parser.IF, 0); }
		public TerminalNode ELSE() { return getToken(C2105052Parser.ELSE, 0); }
		public TerminalNode WHILE() { return getToken(C2105052Parser.WHILE, 0); }
		public TerminalNode PRINTLN() { return getToken(C2105052Parser.PRINTLN, 0); }
		public TerminalNode ID() { return getToken(C2105052Parser.ID, 0); }
		public TerminalNode SEMICOLON() { return getToken(C2105052Parser.SEMICOLON, 0); }
		public TerminalNode RETURN() { return getToken(C2105052Parser.RETURN, 0); }
		public StatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statement; }
	}

	public final StatementContext statement() throws RecognitionException {
		StatementContext _localctx = new StatementContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_statement);
		try {
			setState(266);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,13,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(205);
				((StatementContext)_localctx).var = var_declaration();
				 
				        writeIntoparserLogFile("Line " + std::to_string(((StatementContext)_localctx).var.line) + ": statement : var_declaration\n");
				        ((StatementContext)_localctx).code =  vector<string>();
				        _localctx.code.push_back(((StatementContext)_localctx).var.txt);
				        ((StatementContext)_localctx).line =  ((StatementContext)_localctx).var.line;
				        writeIntoparserLogFile(((StatementContext)_localctx).var.txt + "\n");
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(208);
				((StatementContext)_localctx).es = expression_statement();
				 
				        writeIntoparserLogFile("Line " + std::to_string(((StatementContext)_localctx).es.line) + ": statement : expression_statement\n");
				        ((StatementContext)_localctx).code =  vector<string>();
				        _localctx.code.push_back(((StatementContext)_localctx).es.str);
				        ((StatementContext)_localctx).line =  ((StatementContext)_localctx).es.line;
				        writeIntoparserLogFile(((StatementContext)_localctx).es.str + "\n");
				    
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(211);
				((StatementContext)_localctx).c = compound_statement(vector<pair<string,string>>());


				        writeIntoparserLogFile("Line " + std::to_string(((StatementContext)_localctx).c.line) + ": statement : compound_statement\n");
				        ((StatementContext)_localctx).code =  vector<string>();
				        for (const auto &line : ((StatementContext)_localctx).c.code) {
				            _localctx.code.push_back(line);
				        }
				        ((StatementContext)_localctx).line =  ((StatementContext)_localctx).c.line;
				        for (const auto &line : _localctx.code) {
				            writeIntoparserLogFile(line);
				        }
				        writeIntoparserLogFile("");
				    
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(214);
				match(FOR);
				setState(215);
				match(LPAREN);
				setState(216);
				((StatementContext)_localctx).e1 = expression_statement();

				        int loop_end_label_index = -1;
				        int statement_label_index = -1;
				        int increment_label = -1;
				        int loop_condition_label = -1;
				        string ab = "L" + std::to_string(label_count) + ":";
				        loop_condition_label = label_count;
				        label_count++;
				        asmFile << ab << endl;;

				    
				setState(218);
				((StatementContext)_localctx).e2 = expression_statement();

				        ab = "\tPOP AX\t\t; line " + std::to_string(((StatementContext)_localctx).e2.line);
				        asmFile << ab << endl;;
				        stack_offset -= 2; // Decrease stack offset by 2 for loop condition
				        ab = "\tCMP AX, 0\t\t; line " + std::to_string(((StatementContext)_localctx).e2.line);
				        asmFile << ab << endl;;
				        ab = "\tJE L" + std::to_string(label_count) + "\t\t; line " + std::to_string(((StatementContext)_localctx).e2.line);
				        asmFile << ab << endl;;
				        loop_end_label_index = label_count; // Store the index of the loop end label for later use
				        label_count++; // Increment label count for the next label
				        ab = "\tJMP L" + std::to_string(label_count) + "\t\t; line " + std::to_string(((StatementContext)_localctx).e2.line);
				        asmFile << ab << endl;;
				        statement_label_index = label_count; // Store the index of the statement label for later use
				        label_count++; // Increment label count for the next label
				        increment_label = label_count;
				    
				setState(220);
				((StatementContext)_localctx).e3 = expression();
				setState(221);
				match(RPAREN);

				        ab = "\tJMP L" + std::to_string(loop_condition_label) + "\t\t; line " + std::to_string(((StatementContext)_localctx).e3.line);
				        asmFile << ab << endl;;
				        ab = "L" + std::to_string(statement_label_index) + ":";
				        asmFile << ab << endl;;
				    
				setState(223);
				((StatementContext)_localctx).s = statement();

				        writeIntoparserLogFile("Line " + std::to_string(((StatementContext)_localctx).s.line) + ": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n");
				        ((StatementContext)_localctx).code =  vector<string>();
				        string ss = "for(" + ((StatementContext)_localctx).e1.str + ((StatementContext)_localctx).e2.str + ((StatementContext)_localctx).e3.str + ")";
				        for (const auto &line : ((StatementContext)_localctx).s.code) {
				            ss += line;
				            _localctx.code.push_back(ss);
				            writeIntoparserLogFile(ss);
				            ss = "";
				        }
				        ((StatementContext)_localctx).line =  ((StatementContext)_localctx).s.line;
				        writeIntoparserLogFile("");


				        
				        ss = "L" + std::to_string(label_count) + ":";
				        label_count++;
				        asmFile << ss << endl;


				        ss = "\tJMP L" + std::to_string(increment_label) + "\t\t; line " + std::to_string(((StatementContext)_localctx).s.line);
				        asmFile << ss << endl;
				        ss = "L" + std::to_string(loop_end_label_index) + ":";
				        asmFile << ss << endl;



				    
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(226);
				match(IF);
				setState(227);
				match(LPAREN);
				setState(228);
				((StatementContext)_localctx).expression = expression();
				setState(229);
				match(RPAREN);

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
				    
				setState(231);
				((StatementContext)_localctx).s = statement();

				        str = "L" + std::to_string(if_label_index) + ":";
				        asmFile << str << endl;
				        writeIntoparserLogFile("Line " + std::to_string(((StatementContext)_localctx).s.line) + ": statement : IF LPAREN expression RPAREN statement\n");
				        ((StatementContext)_localctx).code =  vector<string>();
				        string ss= "if(" + ((StatementContext)_localctx).expression.str + ")";
				        for (const auto &line : ((StatementContext)_localctx).s.code) {
				            ss+= line;
				            _localctx.code.push_back(ss);
				            writeIntoparserLogFile(ss);
				            ss="";
				        }
				        ((StatementContext)_localctx).line =  ((StatementContext)_localctx).s.line;
				        writeIntoparserLogFile("");


				        


				    
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(234);
				match(IF);
				setState(235);
				match(LPAREN);
				setState(236);
				((StatementContext)_localctx).ex = expression();
				setState(237);
				match(RPAREN);

				        int if_label_index = -1;

				        string str = "\tPOP AX\t\t; line " + std::to_string(((StatementContext)_localctx).ex.line);
				        asmFile << str << endl;
				        stack_offset -= 2; // Decrease stack offset by 2 for if condition
				        str = "\tCMP AX, 0\t\t; line " + std::to_string(((StatementContext)_localctx).ex.line);
				        asmFile << str << endl;
				        str = "\tJE L" + std::to_string(label_count) + "\t\t; line " + std::to_string(((StatementContext)_localctx).ex.line);
				        asmFile << str << endl;
				        if_label_index = label_count; // Store the index of the if label for later use
				        label_count++; // Increment label count for the next label

				        



				    
				setState(239);
				((StatementContext)_localctx).s1 = statement();

				        int jump_at_end = label_count;
				         str = "\tJMP L" + std::to_string(label_count) + "\t\t; line " + std::to_string(((StatementContext)_localctx).s1.line);
				        asmFile << str << endl;
				        label_count++; // Increment label count for the next label
				    
				setState(241);
				match(ELSE);

				        str = "L" + std::to_string(if_label_index) + ":";
				        asmFile << str << endl;
				        
				        if_label_index = -1; // Reset the index after using it
				    
				setState(243);
				((StatementContext)_localctx).s2 = statement();

				        writeIntoparserLogFile("Line " + std::to_string(((StatementContext)_localctx).s2.line) + ": statement : IF LPAREN expression RPAREN statement ELSE statement\n");
				        ((StatementContext)_localctx).code =  vector<string>();
				        string ss = "if(" + ((StatementContext)_localctx).ex.str + ")";
				        for (const auto &line : ((StatementContext)_localctx).s1.code) {
				            ss += line;
				            
				            
				            // if line is not the last element of s1.code 
				            if (&line != &(((StatementContext)_localctx).s1.code.back())) {
				                _localctx.code.push_back(ss);
				                writeIntoparserLogFile(ss);
				                ss = "";
				            }
				        }
				        ss += "else ";
				        for (const auto &line : ((StatementContext)_localctx).s2.code) {
				            ss += line;
				            _localctx.code.push_back(ss);
				            writeIntoparserLogFile(ss);
				            ss = "";
				        }
				        ((StatementContext)_localctx).line =  ((StatementContext)_localctx).s2.line;
				        writeIntoparserLogFile("");


				        str = "L" + std::to_string(jump_at_end) + ":";
				        asmFile << str << endl;

				        


				    
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(246);
				match(WHILE);

				        int while_loop_condition_label = -1;
				        int while_loop_end_label_index = -1;
				        
				        string cd = "L" + std::to_string(label_count) + ":";
				        while_loop_condition_label = label_count;
				        label_count++;
				        asmFile << cd << endl;;

				    
				setState(248);
				match(LPAREN);
				setState(249);
				((StatementContext)_localctx).expression = expression();

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
				    
				setState(251);
				match(RPAREN);
				setState(252);
				((StatementContext)_localctx).statement = statement();

				        writeIntoparserLogFile("Line " + std::to_string(((StatementContext)_localctx).statement.line) + ": statement : WHILE LPAREN expression RPAREN statement\n");
				        ((StatementContext)_localctx).code =  vector<string>();
				        string ss = "while(" + ((StatementContext)_localctx).expression.str + ")";
				        for (const auto &line : ((StatementContext)_localctx).statement.code) {
				            ss += line;
				            _localctx.code.push_back(ss);
				            writeIntoparserLogFile(ss);
				            ss = "";
				        }
				        ((StatementContext)_localctx).line =  ((StatementContext)_localctx).statement.line;
				        writeIntoparserLogFile("");

				        ss = "\tJMP L" + std::to_string(while_loop_condition_label) + "\t\t; line " + std::to_string(((StatementContext)_localctx).statement.line);
				        asmFile << ss << endl;
				        ss = "L" + std::to_string(while_loop_end_label_index) + ":";
				        asmFile << ss << endl;

				    
				}
				break;
			case 8:
				enterOuterAlt(_localctx, 8);
				{
				setState(255);
				match(PRINTLN);
				setState(256);
				match(LPAREN);
				setState(257);
				((StatementContext)_localctx).ID = match(ID);
				setState(258);
				match(RPAREN);
				setState(259);
				match(SEMICOLON);

				        writeIntoparserLogFile("Line " + std::to_string(((StatementContext)_localctx).ID->getLine()) + ": statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n");
				        ((StatementContext)_localctx).code =  vector<string>();
				        _localctx.code.push_back("printf(" + ((StatementContext)_localctx).ID->getText() + ");");
				        writeIntoparserLogFile(_localctx.code.back() + "\n");
				        ((StatementContext)_localctx).line =  ((StatementContext)_localctx).ID->getLine();
				        string str;
				        SymbolInfo *s = symbolTable->look_up_in_all_scope(((StatementContext)_localctx).ID->getText());
				        






				        str+="L"+std::to_string(label_count) + ":";
				        label_count++;
				        asmFile << str << endl;
				        if(s!=nullptr){ 
				            if(s->getScopeId()==1){
				                str = "\tMOV AX, " + ((StatementContext)_localctx).ID->getText() + "\t\t; line" + std::to_string(((StatementContext)_localctx).ID->getLine());
				                asmFile << str << endl;
				                str = "\tCALL print_output";
				                asmFile << str << endl;
				                str = "\tCALL new_line";
				                asmFile << str << endl;
				            }
				            else{

				                str = "\tMOV AX, [BP" + std::string((s->getOffset() >= 0) ? "-" : "+") + std::to_string(std::abs(s->getOffset())) + "]\t\t; line " + std::to_string(((StatementContext)_localctx).ID->getLine());
				                asmFile << str << endl;
				                str = "\tCALL print_output";
				                asmFile << str << endl;
				                str = "\tCALL new_line";
				                asmFile << str << endl;
				            }
				        }
				        else{
				            str = "\tMOV AX, " + ((StatementContext)_localctx).ID->getText() + "\t\t; line" + std::to_string(((StatementContext)_localctx).ID->getLine());
				            asmFile << str << endl;
				            str = "\tCALL print_output";
				            asmFile << str << endl;
				            str = "\tCALL new_line";
				            asmFile << str << endl;
				        }
				        

				        
				    
				}
				break;
			case 9:
				enterOuterAlt(_localctx, 9);
				{
				setState(261);
				((StatementContext)_localctx).RETURN = match(RETURN);
				setState(262);
				((StatementContext)_localctx).expr = expression();
				setState(263);
				match(SEMICOLON);

				        writeIntoparserLogFile("Line " + std::to_string(((StatementContext)_localctx).expr.line) + ": statement : RETURN expression SEMICOLON\n");
				        ((StatementContext)_localctx).code =  vector<string>();
				        _localctx.code.push_back(((StatementContext)_localctx).RETURN->getText() + " " + ((StatementContext)_localctx).expr.str + ";");
				        writeIntoparserLogFile(_localctx.code.back() + "\n");
				        ((StatementContext)_localctx).line =  ((StatementContext)_localctx).expr.line;
				        

				        string str;
				        str = "L" + std::to_string(label_count) + ":";
				        label_count++;
				        asmFile << str << endl;
				        SymbolInfo *s = symbolTable->look_up_in_all_scope(((StatementContext)_localctx).expr.str);
				        if(s!=nullptr){
				            if(s->getScopeId()==1){
				                str = "\tMOV AX, " + ((StatementContext)_localctx).expr.str + "\t\t; line " + std::to_string(((StatementContext)_localctx).expr.line);
				                asmFile << str << endl;   
				            }
				            else{
				                str = "\tMOV AX, [BP" + std::string((s->getOffset() >= 0) ? "-" : "+") + std::to_string(std::abs(s->getOffset())) + "]\t\t; line " + std::to_string(((StatementContext)_localctx).expr.line);
				                asmFile << str << endl;
				            }
				        }
				        else{
				            str = "\tPOP AX\t\t; line " + std::to_string(((StatementContext)_localctx).expr.line);
				            asmFile << str << endl;
				        }
				        str = "\tJMP L" + std::to_string(func_return_label) + "\t\t; line " + std::to_string(((StatementContext)_localctx).expr.line);
				        asmFile << str << endl;
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Expression_statementContext extends ParserRuleContext {
		public string str;
		public int line;
		public Token SEMICOLON;
		public ExpressionContext exp;
		public TerminalNode SEMICOLON() { return getToken(C2105052Parser.SEMICOLON, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public Expression_statementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression_statement; }
	}

	public final Expression_statementContext expression_statement() throws RecognitionException {
		Expression_statementContext _localctx = new Expression_statementContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_expression_statement);
		try {
			setState(274);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case SEMICOLON:
				enterOuterAlt(_localctx, 1);
				{
				setState(268);
				((Expression_statementContext)_localctx).SEMICOLON = match(SEMICOLON);

				        writeIntoparserLogFile("Line " + std::to_string(((Expression_statementContext)_localctx).SEMICOLON->getLine()) + ": expression_statement : SEMICOLON\n");
				        ((Expression_statementContext)_localctx).str =  ";";
				        ((Expression_statementContext)_localctx).line =  ((Expression_statementContext)_localctx).SEMICOLON->getLine();
				        writeIntoparserLogFile(_localctx.str + "\n");
				    
				}
				break;
			case LPAREN:
			case ADDOP:
			case NOT:
			case ID:
			case CONST_INT:
			case CONST_FLOAT:
				enterOuterAlt(_localctx, 2);
				{
				setState(270);
				((Expression_statementContext)_localctx).exp = expression();
				setState(271);
				match(SEMICOLON);
				 
				        writeIntoparserLogFile("Line " + std::to_string(((Expression_statementContext)_localctx).exp.line) + ": expression_statement : expression SEMICOLON\n");
				        ((Expression_statementContext)_localctx).str =  ((Expression_statementContext)_localctx).exp.str;
				        ((Expression_statementContext)_localctx).line =  ((Expression_statementContext)_localctx).exp.line;
				        if (_localctx.str.empty()) {
				            ((Expression_statementContext)_localctx).str =  ";";
				        } else {
				            _localctx.str += ";";
				        }
				        writeIntoparserLogFile(_localctx.str + "\n");
				    
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class VariableContext extends ParserRuleContext {
		public std::string varName;
		public int line;
		public Token ID;
		public ExpressionContext expression;
		public TerminalNode ID() { return getToken(C2105052Parser.ID, 0); }
		public TerminalNode LTHIRD() { return getToken(C2105052Parser.LTHIRD, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode RTHIRD() { return getToken(C2105052Parser.RTHIRD, 0); }
		public VariableContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variable; }
	}

	public final VariableContext variable() throws RecognitionException {
		VariableContext _localctx = new VariableContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_variable);
		try {
			setState(284);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,15,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(276);
				((VariableContext)_localctx).ID = match(ID);

				        writeIntoparserLogFile("Line " + std::to_string(((VariableContext)_localctx).ID->getLine()) + ": variable : ID\n");
				        writeIntoparserLogFile(((VariableContext)_localctx).ID->getText() + "\n");
				        ((VariableContext)_localctx).varName =  ((VariableContext)_localctx).ID->getText();
				        ((VariableContext)_localctx).line =  ((VariableContext)_localctx).ID->getLine();
				     
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(278);
				((VariableContext)_localctx).ID = match(ID);
				setState(279);
				match(LTHIRD);
				setState(280);
				((VariableContext)_localctx).expression = expression();
				setState(281);
				match(RTHIRD);
				 
				        writeIntoparserLogFile("Line " + std::to_string(((VariableContext)_localctx).ID->getLine()) + ": variable : ID LTHIRD expression RTHIRD\n");
				        string str = ((VariableContext)_localctx).ID->getText() + "[" + ((VariableContext)_localctx).expression.str + "]";
				        writeIntoparserLogFile(((VariableContext)_localctx).ID->getText() + "[" + ((VariableContext)_localctx).expression.str + "]\n");
				        ((VariableContext)_localctx).varName =  ((VariableContext)_localctx).ID->getText() + "[" + ((VariableContext)_localctx).expression.str + "]";
				        if (((VariableContext)_localctx).expression.str.empty()) {
				            writeIntoErrorFile("Error at line " + std::to_string(((VariableContext)_localctx).ID->getLine()) + ": Empty expression in array index\n");
				            syntaxErrorCount++;
				        }
				        ((VariableContext)_localctx).line =  ((VariableContext)_localctx).ID->getLine();
				        



				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionContext extends ParserRuleContext {
		public string str;
		public int line;
		public Logic_expressionContext l_expr;
		public VariableContext var;
		public Logic_expressionContext logic_expression() {
			return getRuleContext(Logic_expressionContext.class,0);
		}
		public TerminalNode ASSIGNOP() { return getToken(C2105052Parser.ASSIGNOP, 0); }
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
	}

	public final ExpressionContext expression() throws RecognitionException {
		ExpressionContext _localctx = new ExpressionContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_expression);
		try {
			setState(294);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,16,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(286);
				((ExpressionContext)_localctx).l_expr = logic_expression();

				        writeIntoparserLogFile("Line " + std::to_string(((ExpressionContext)_localctx).l_expr.line) + ": expression : logic_expression\n");
				        ((ExpressionContext)_localctx).str =  "";
				        for (const auto &term : ((ExpressionContext)_localctx).l_expr.rel_expr) {
				            _localctx.str += term;
				        }
				        ((ExpressionContext)_localctx).line =  ((ExpressionContext)_localctx).l_expr.line;
				        writeIntoparserLogFile(_localctx.str + "\n");
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(289);
				((ExpressionContext)_localctx).var = variable();
				setState(290);
				match(ASSIGNOP);
				setState(291);
				((ExpressionContext)_localctx).l_expr = logic_expression();

				        writeIntoparserLogFile("Line " + std::to_string(((ExpressionContext)_localctx).l_expr.line) + ": expression : variable ASSIGNOP logic_expression\n");
				        ((ExpressionContext)_localctx).str =  ((ExpressionContext)_localctx).var.varName + "=";
				        string logicExpr;
				        for (const auto &term : ((ExpressionContext)_localctx).l_expr.rel_expr){
				            _localctx.str += term;
				            logicExpr += term;
				        }
				        ((ExpressionContext)_localctx).line =  ((ExpressionContext)_localctx).l_expr.line;
				        writeIntoparserLogFile(_localctx.str + "\n");
				        

				        handle_assign_op(symbolTable, ((ExpressionContext)_localctx).var.varName, stack_offset);
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Logic_expressionContext extends ParserRuleContext {
		public vector<string> rel_expr;
		public int line;
		public Rel_expressionContext r_expr;
		public Rel_expressionContext r1;
		public Token LOGICOP;
		public Rel_expressionContext r2;
		public List<Rel_expressionContext> rel_expression() {
			return getRuleContexts(Rel_expressionContext.class);
		}
		public Rel_expressionContext rel_expression(int i) {
			return getRuleContext(Rel_expressionContext.class,i);
		}
		public TerminalNode LOGICOP() { return getToken(C2105052Parser.LOGICOP, 0); }
		public Logic_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_logic_expression; }
	}

	public final Logic_expressionContext logic_expression() throws RecognitionException {
		Logic_expressionContext _localctx = new Logic_expressionContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_logic_expression);
		try {
			setState(306);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,17,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(296);
				((Logic_expressionContext)_localctx).r_expr = rel_expression();

				        writeIntoparserLogFile("Line " + std::to_string(((Logic_expressionContext)_localctx).r_expr.line) + ": logic_expression : rel_expression\n");
				        ((Logic_expressionContext)_localctx).rel_expr =  ((Logic_expressionContext)_localctx).r_expr.simple_expr;
				        ((Logic_expressionContext)_localctx).line =  ((Logic_expressionContext)_localctx).r_expr.line;
				        string str;
				        for (const auto &term : _localctx.rel_expr) {
				            str += term;
				        }
				        writeIntoparserLogFile(str + "\n");

				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(299);
				((Logic_expressionContext)_localctx).r1 = rel_expression();

				        string str;
				        string temp = "L" + std::to_string(label_count) + ":";
				        label_count++;
				        asmFile << temp << endl;

				            str = "\tPOP AX\t\t; line " + std::to_string(((Logic_expressionContext)_localctx).r1.line);
				            asmFile << str << endl;
				            stack_offset -= 2; // Decrease stack offset by 2 for logic expression
				        

				    
				setState(301);
				((Logic_expressionContext)_localctx).LOGICOP = match(LOGICOP);

				        temp = ((Logic_expressionContext)_localctx).LOGICOP->getText();
				        int logic_op_on_false_jump_label = -1; // Initialize the logic operation jump label index
				        int logic_op_on_true_jump_label = -1; // Initialize the logic operation jump label index
				        if(temp=="||"){
				            temp = "\tCMP AX, 0";
				            asmFile << temp << endl;
				            temp = "\tJNE L" + std::to_string(label_count) + "\t\t; line " + std::to_string(((Logic_expressionContext)_localctx).r1.line);
				            asmFile << temp << endl;
				            logic_op_on_true_jump_label = label_count; // Store the index of the logic operation jump label for later use
				            label_count++; // Increment label count for the next label
				            
				        }
				        else if(temp=="&&"){
				            temp = "\tCMP AX, 0";
				            asmFile << temp << endl;
				            temp = "\tJE L" + std::to_string(label_count) + "\t\t; line " + std::to_string(((Logic_expressionContext)_localctx).r1.line);
				            asmFile << temp << endl;
				            logic_op_on_false_jump_label = label_count; // Store the index of the logic operation jump label for later use
				            label_count++; // Increment label count for the next label
				        }



				    
				setState(303);
				((Logic_expressionContext)_localctx).r2 = rel_expression();

				        writeIntoparserLogFile("Line " + std::to_string(((Logic_expressionContext)_localctx).r1.line) + ": logic_expression : rel_expression LOGICOP rel_expression\n");
				        ((Logic_expressionContext)_localctx).rel_expr =  ((Logic_expressionContext)_localctx).r1.simple_expr;
				        _localctx.rel_expr.push_back(((Logic_expressionContext)_localctx).LOGICOP->getText());
				        for (const auto &term : ((Logic_expressionContext)_localctx).r2.simple_expr){
				            _localctx.rel_expr.push_back(term);
				        }
				        ((Logic_expressionContext)_localctx).line =  ((Logic_expressionContext)_localctx).r1.line;
				        for (const auto &term : _localctx.rel_expr) {
				            str += term;
				        }
				        writeIntoparserLogFile(str + "\n");



				        


				        if(((Logic_expressionContext)_localctx).LOGICOP->getText()=="||"){

				                str = "\tPOP AX";
				                asmFile << str << endl;
				                stack_offset -= 2;
				            

				            str = "\tCMP AX, 0";
				            asmFile << str << endl;
				            str = "\tJE L" + std::to_string(label_count) + "\t\t; line " + std::to_string(((Logic_expressionContext)_localctx).r1.line);
				            asmFile << str << endl;

				            str = "L" + std::to_string(logic_op_on_true_jump_label) + ":";
				            asmFile << str << endl;
				            str = "\tMOV AX, 1";
				            asmFile << str << endl;
				            str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string(((Logic_expressionContext)_localctx).r1.line);
				            asmFile << str << endl;
				            str = "L" + std::to_string(label_count) + ":";
				            label_count++;
				            asmFile << str << endl;
				            str = "\tMOV AX, 0\t\t; line " + std::to_string(((Logic_expressionContext)_localctx).r1.line);
				            asmFile << str << endl;

				            str = "L" + std::to_string(label_count) + ":";
				            asmFile << str << endl;
				            str = "\tPUSH AX\t\t; line " + std::to_string(((Logic_expressionContext)_localctx).r1.line);
				            asmFile << str << endl;
				            stack_offset += 2; // Increase stack offset by 2 for logic expression
				            label_count++;
				        }

				        else if(((Logic_expressionContext)_localctx).LOGICOP->getText() == "&&"){

				                str = "\tPOP AX";
				                asmFile << str << endl;
				                stack_offset -= 2;


				            str = "\tCMP AX, 0";
				            asmFile << str << endl;
				            str = "\tJE L" + std::to_string(logic_op_on_false_jump_label) + "\t\t; line " + std::to_string(((Logic_expressionContext)_localctx).r1.line);
				            asmFile << str << endl;

				            str = "L" + std::to_string(label_count) + ":";
				            label_count++;
				            asmFile << str << endl;
				            str = "\tMOV AX, 1";
				            asmFile << str << endl;
				            str = "\tJMP L" + std::to_string(label_count) + "\t\t; line " + std::to_string(((Logic_expressionContext)_localctx).r1.line);
				            asmFile << str << endl;
				            str = "L" + std::to_string(logic_op_on_false_jump_label) + ":";
				            asmFile << str << endl;
				            str = "\tMOV AX, 0\t\t; line " + std::to_string(((Logic_expressionContext)_localctx).r1.line);
				            asmFile << str << endl;

				            str = "L" + std::to_string(label_count) + ":";
				            asmFile << str << endl;
				            str = "\tPUSH AX\t\t; line " + std::to_string(((Logic_expressionContext)_localctx).r1.line);
				            asmFile << str << endl;
				            stack_offset += 2; // Increase stack offset by 2 for logic expression
				            label_count++;
				        
				        }





				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Rel_expressionContext extends ParserRuleContext {
		public vector<string> simple_expr;
		public int line;
		public Simple_expressionContext s_expr;
		public Token RELOP;
		public Simple_expressionContext ss;
		public List<Simple_expressionContext> simple_expression() {
			return getRuleContexts(Simple_expressionContext.class);
		}
		public Simple_expressionContext simple_expression(int i) {
			return getRuleContext(Simple_expressionContext.class,i);
		}
		public TerminalNode RELOP() { return getToken(C2105052Parser.RELOP, 0); }
		public Rel_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_rel_expression; }
	}

	public final Rel_expressionContext rel_expression() throws RecognitionException {
		Rel_expressionContext _localctx = new Rel_expressionContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_rel_expression);
		try {
			setState(316);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,18,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(308);
				((Rel_expressionContext)_localctx).s_expr = simple_expression(0);

				        writeIntoparserLogFile("Line " + std::to_string(((Rel_expressionContext)_localctx).s_expr.line) + ": rel_expression : simple_expression\n");
				        ((Rel_expressionContext)_localctx).simple_expr =  ((Rel_expressionContext)_localctx).s_expr.terms;
				        ((Rel_expressionContext)_localctx).line =  ((Rel_expressionContext)_localctx).s_expr.line;
				        string str;
				        for (const auto &term : _localctx.simple_expr) {
				            str += term;
				        }
				        writeIntoparserLogFile(str + "\n");
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(311);
				((Rel_expressionContext)_localctx).s_expr = simple_expression(0);
				setState(312);
				((Rel_expressionContext)_localctx).RELOP = match(RELOP);
				setState(313);
				((Rel_expressionContext)_localctx).ss = simple_expression(0);

				        writeIntoparserLogFile("Line " + std::to_string(((Rel_expressionContext)_localctx).s_expr.line) + ": rel_expression : simple_expression RELOP simple_expression\n");
				        ((Rel_expressionContext)_localctx).simple_expr =  ((Rel_expressionContext)_localctx).s_expr.terms;
				        _localctx.simple_expr.push_back(((Rel_expressionContext)_localctx).RELOP->getText());
				        for (const auto &term : ((Rel_expressionContext)_localctx).ss.terms) {
				            _localctx.simple_expr.push_back(term);
				        }
				        ((Rel_expressionContext)_localctx).line =  ((Rel_expressionContext)_localctx).s_expr.line;
				        string str;
				        for (const auto &term : _localctx.simple_expr) {
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
				        
				        if(((Rel_expressionContext)_localctx).RELOP->getText() == "<="){
				            str = "\tCMP AX, DX";
				            asmFile << str << endl;
				            str = "\tJLE L" + std::to_string(label_count) + "\t\t; line " + std::to_string(((Rel_expressionContext)_localctx).s_expr.line);
				            asmFile << str << endl;
				            str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string(((Rel_expressionContext)_localctx).s_expr.line);
				            asmFile << str << endl;
				            str = "L" + std::to_string(label_count) + ":";
				            label_count++;
				            asmFile << str << endl;
				            str = "\tMOV AX, 1\t\t; line " + std::to_string(((Rel_expressionContext)_localctx).s_expr.line);
				            asmFile << str << endl;
				            str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string(((Rel_expressionContext)_localctx).s_expr.line);
				            asmFile << str << endl;
				            str = "L" + std::to_string(label_count) + ":";
				            label_count++;
				            asmFile << str << endl;
				            str = "\tMOV AX, 0\t\t; line " + std::to_string(((Rel_expressionContext)_localctx).s_expr.line);
				            asmFile << str << endl;
				            str = "L" + std::to_string(label_count) + ":";
				            label_count++;
				            asmFile << str << endl;
				            str = "\tPUSH AX\t\t; line " + std::to_string(((Rel_expressionContext)_localctx).s_expr.line);
				            asmFile << str << endl;
				            stack_offset += 2;
				            
				        }


				        else if(((Rel_expressionContext)_localctx).RELOP->getText() == "<"){
				            str = "\tCMP AX, DX";
				            asmFile << str << endl;
				            str = "\tJL L" + std::to_string(label_count) + "\t\t; line " + std::to_string(((Rel_expressionContext)_localctx).s_expr.line);
				            asmFile << str << endl;
				            str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string(((Rel_expressionContext)_localctx).s_expr.line);
				            asmFile << str << endl;
				            str = "L" + std::to_string(label_count) + ":";
				            label_count++;
				            asmFile << str << endl;
				            str = "\tMOV AX, 1\t\t; line " + std::to_string(((Rel_expressionContext)_localctx).s_expr.line);
				            asmFile << str << endl;
				            str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string(((Rel_expressionContext)_localctx).s_expr.line);
				            asmFile << str << endl;
				            str = "L" + std::to_string(label_count) + ":";
				            label_count++;
				            asmFile << str << endl;
				            str = "\tMOV AX, 0\t\t; line " + std::to_string(((Rel_expressionContext)_localctx).s_expr.line);
				            asmFile << str << endl;
				            str = "L" + std::to_string(label_count) + ":";
				            label_count++;
				            asmFile << str << endl;
				            str = "\tPUSH AX\t\t; line " + std::to_string(((Rel_expressionContext)_localctx).s_expr.line);
				            asmFile << str << endl;
				            stack_offset += 2;
				        }
				        else if(((Rel_expressionContext)_localctx).RELOP->getText() == ">="){
				            str = "\tCMP AX, DX";
				            asmFile << str << endl;
				            str = "\tJGE L" + std::to_string(label_count) + "\t\t; line " + std::to_string(((Rel_expressionContext)_localctx).s_expr.line);
				            asmFile << str << endl;
				            str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string(((Rel_expressionContext)_localctx).s_expr.line);
				            asmFile << str << endl;
				            str = "L" + std::to_string(label_count) + ":";
				            label_count++;
				            asmFile << str << endl;
				            str = "\tMOV AX, 1\t\t; line " + std::to_string(((Rel_expressionContext)_localctx).s_expr.line);
				            asmFile << str << endl;
				            str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string(((Rel_expressionContext)_localctx).s_expr.line);
				            asmFile << str << endl;
				            str = "L" + std::to_string(label_count) + ":";
				            label_count++;
				            asmFile << str << endl;
				            str = "\tMOV AX, 0\t\t; line " + std::to_string(((Rel_expressionContext)_localctx).s_expr.line);
				            asmFile << str << endl;
				            str = "L" + std::to_string(label_count) + ":";
				            label_count++;
				            asmFile << str << endl;
				            str = "\tPUSH AX\t\t; line " + std::to_string(((Rel_expressionContext)_localctx).s_expr.line);
				            asmFile << str << endl;
				            stack_offset += 2;
				        }

				        else if(((Rel_expressionContext)_localctx).RELOP->getText() == ">"){
				            str = "\tCMP AX, DX";
				            asmFile << str << endl;
				            str = "\tJG L" + std::to_string(label_count) + "\t\t; line " + std::to_string(((Rel_expressionContext)_localctx).s_expr.line);
				            asmFile << str << endl;
				            str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string(((Rel_expressionContext)_localctx).s_expr.line);
				            asmFile << str << endl;
				            str = "L" + std::to_string(label_count) + ":";
				            label_count++;
				            asmFile << str << endl;
				            str = "\tMOV AX, 1\t\t; line " + std::to_string(((Rel_expressionContext)_localctx).s_expr.line);
				            asmFile << str << endl;
				            str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string(((Rel_expressionContext)_localctx).s_expr.line);
				            asmFile << str << endl;
				            str = "L" + std::to_string(label_count) + ":";
				            label_count++;
				            asmFile << str << endl;
				            str = "\tMOV AX, 0\t\t; line " + std::to_string(((Rel_expressionContext)_localctx).s_expr.line);
				            asmFile << str << endl;
				            str = "L" + std::to_string(label_count) + ":";
				            label_count++;
				            asmFile << str << endl;
				            str = "\tPUSH AX\t\t; line " + std::to_string(((Rel_expressionContext)_localctx).s_expr.line);
				            asmFile << str << endl;
				            stack_offset += 2;
				        }
				        else if(((Rel_expressionContext)_localctx).RELOP->getText() == "=="){
				            str = "\tCMP AX, DX";
				            asmFile << str << endl;
				            str = "\tJE L" + std::to_string(label_count) + "\t\t; line " + std::to_string(((Rel_expressionContext)_localctx).s_expr.line);
				            asmFile << str << endl;
				            str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string(((Rel_expressionContext)_localctx).s_expr.line);
				            asmFile << str << endl;
				            str = "L" + std::to_string(label_count) + ":";
				            label_count++;
				            asmFile << str << endl;
				            str = "\tMOV AX, 1\t\t; line " + std::to_string(((Rel_expressionContext)_localctx).s_expr.line);
				            asmFile << str << endl;
				            str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string(((Rel_expressionContext)_localctx).s_expr.line);
				            asmFile << str << endl;
				            str = "L" + std::to_string(label_count) + ":";
				            label_count++;
				            asmFile << str << endl;
				            str = "\tMOV AX, 0\t\t; line " + std::to_string(((Rel_expressionContext)_localctx).s_expr.line);
				            asmFile << str << endl;
				            str = "L" + std::to_string(label_count) + ":";
				            label_count++;
				            asmFile << str << endl;
				            str = "\tPUSH AX\t\t; line " + std::to_string(((Rel_expressionContext)_localctx).s_expr.line);
				            asmFile << str << endl;
				            stack_offset += 2; 
				        }
				        else if(((Rel_expressionContext)_localctx).RELOP->getText() == "!="){
				            str = "\tCMP AX, DX";
				            asmFile << str << endl;
				            str = "\tJNE L" + std::to_string(label_count) + "\t\t; line " + std::to_string(((Rel_expressionContext)_localctx).s_expr.line);
				            asmFile << str << endl;
				            str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string(((Rel_expressionContext)_localctx).s_expr.line);
				            asmFile << str << endl;
				            str = "L" + std::to_string(label_count) + ":";
				            label_count++;
				            asmFile << str << endl;
				            str = "\tMOV AX, 1\t\t; line " + std::to_string(((Rel_expressionContext)_localctx).s_expr.line);
				            asmFile << str << endl;
				            str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string(((Rel_expressionContext)_localctx).s_expr.line);
				            asmFile << str << endl;
				            str = "L" + std::to_string(label_count) + ":";
				            label_count++;
				            asmFile << str << endl;
				            str = "\tMOV AX, 0\t\t; line " + std::to_string(((Rel_expressionContext)_localctx).s_expr.line);
				            asmFile << str << endl;
				            str = "L" + std::to_string(label_count) + ":";
				            label_count++;
				            asmFile << str << endl;
				            str = "\tPUSH AX\t\t; line " + std::to_string(((Rel_expressionContext)_localctx).s_expr.line);
				            asmFile << str << endl;
				            stack_offset += 2;
				        }



				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Simple_expressionContext extends ParserRuleContext {
		public vector<string> terms;
		public int line;
		public Simple_expressionContext s;
		public TermContext t;
		public Token ADDOP;
		public TermContext term() {
			return getRuleContext(TermContext.class,0);
		}
		public TerminalNode ADDOP() { return getToken(C2105052Parser.ADDOP, 0); }
		public Simple_expressionContext simple_expression() {
			return getRuleContext(Simple_expressionContext.class,0);
		}
		public Simple_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_simple_expression; }
	}

	public final Simple_expressionContext simple_expression() throws RecognitionException {
		return simple_expression(0);
	}

	private Simple_expressionContext simple_expression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Simple_expressionContext _localctx = new Simple_expressionContext(_ctx, _parentState);
		Simple_expressionContext _prevctx = _localctx;
		int _startState = 36;
		enterRecursionRule(_localctx, 36, RULE_simple_expression, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(319);
			((Simple_expressionContext)_localctx).t = term(0);

			        writeIntoparserLogFile("Line " + std::to_string(((Simple_expressionContext)_localctx).t.line) + ": simple_expression : term\n");
			        ((Simple_expressionContext)_localctx).terms =  { ((Simple_expressionContext)_localctx).t.trm };
			        ((Simple_expressionContext)_localctx).line =  ((Simple_expressionContext)_localctx).t.line;
			        writeIntoparserLogFile(((Simple_expressionContext)_localctx).t.trm + "\n");
			    
			}
			_ctx.stop = _input.LT(-1);
			setState(329);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,19,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new Simple_expressionContext(_parentctx, _parentState);
					_localctx.s = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_simple_expression);
					setState(322);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(323);
					((Simple_expressionContext)_localctx).ADDOP = match(ADDOP);
					setState(324);
					((Simple_expressionContext)_localctx).t = term(0);

					                  writeIntoparserLogFile("Line " + std::to_string(((Simple_expressionContext)_localctx).s.line) + ": simple_expression : simple_expression ADDOP term\n");
					                  ((Simple_expressionContext)_localctx).terms =  ((Simple_expressionContext)_localctx).s.terms;
					                  _localctx.terms.push_back(((Simple_expressionContext)_localctx).ADDOP->getText());
					                  _localctx.terms.push_back(((Simple_expressionContext)_localctx).t.trm);
					                  // // cout<< ((Simple_expressionContext)_localctx).t.trm << endl;
					                  ((Simple_expressionContext)_localctx).line =  ((Simple_expressionContext)_localctx).s.line;
					                  string str;
					                  for (const auto &term : _localctx.terms) {
					                      str += term;
					                  }
					                  _localctx.terms.clear();
					                  _localctx.terms.push_back(str);
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
					                  for (const auto &term : ((Simple_expressionContext)_localctx).s.terms) {
					                      s_term_merge += term;
					                  }


					                      str = "\tPOP AX";
					                      asmFile << str << endl;
					                      stack_offset -= 2;
					                  
					                  if (((Simple_expressionContext)_localctx).ADDOP->getText() == "+") {
					                      str = "\tADD AX, DX";
					                      asmFile << str << endl;
					                      str = "\tPUSH AX\t\t; line " + std::to_string(((Simple_expressionContext)_localctx).s.line);
					                      asmFile << str << endl;
					                      stack_offset += 2;
					                  }
					                  else if (((Simple_expressionContext)_localctx).ADDOP->getText() == "-") {
					                      str = "\tSUB AX, DX";
					                      asmFile << str << endl;
					                      str = "\tPUSH AX\t\t; line " + std::to_string(((Simple_expressionContext)_localctx).s.line);
					                      asmFile << str << endl;
					                      stack_offset += 2;
					                  } 



					              
					}
					} 
				}
				setState(331);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,19,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class TermContext extends ParserRuleContext {
		public string trm;
		public int line;
		public TermContext t;
		public Unary_expressionContext u_expr;
		public Token MULOP;
		public Unary_expressionContext u;
		public Token UNRECOGNIZED;
		public Unary_expressionContext unary_expression() {
			return getRuleContext(Unary_expressionContext.class,0);
		}
		public TerminalNode MULOP() { return getToken(C2105052Parser.MULOP, 0); }
		public TermContext term() {
			return getRuleContext(TermContext.class,0);
		}
		public TerminalNode UNRECOGNIZED() { return getToken(C2105052Parser.UNRECOGNIZED, 0); }
		public TermContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_term; }
	}

	public final TermContext term() throws RecognitionException {
		return term(0);
	}

	private TermContext term(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		TermContext _localctx = new TermContext(_ctx, _parentState);
		TermContext _prevctx = _localctx;
		int _startState = 38;
		enterRecursionRule(_localctx, 38, RULE_term, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(333);
			((TermContext)_localctx).u_expr = unary_expression();

			        writeIntoparserLogFile("Line " + std::to_string(((TermContext)_localctx).u_expr.line) + ": term : unary_expression\n");
			        ((TermContext)_localctx).trm =  ((TermContext)_localctx).u_expr.unary_expr;
			        ((TermContext)_localctx).line =  ((TermContext)_localctx).u_expr.line;
			        writeIntoparserLogFile(_localctx.trm + "\n");
			    
			}
			_ctx.stop = _input.LT(-1);
			setState(346);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,21,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(344);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,20,_ctx) ) {
					case 1:
						{
						_localctx = new TermContext(_parentctx, _parentState);
						_localctx.t = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_term);
						setState(336);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(337);
						((TermContext)_localctx).MULOP = match(MULOP);
						setState(338);
						((TermContext)_localctx).u = unary_expression();

						                  writeIntoparserLogFile("Line " + std::to_string(((TermContext)_localctx).t.line) + ": term : term MULOP unary_expression\n");
						                  ((TermContext)_localctx).trm =  ((TermContext)_localctx).t.trm  + ((TermContext)_localctx).MULOP->getText() + ((TermContext)_localctx).u.unary_expr;
						                  ((TermContext)_localctx).line =  ((TermContext)_localctx).t.line;
						                  writeIntoparserLogFile(_localctx.trm + "\n");



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
						                  if (((TermContext)_localctx).MULOP->getText() == "*") {
						                      str = "\tMUL CX";
						                      asmFile << str << endl;
						                      str = "\tPUSH AX\t\t; line " + std::to_string(((TermContext)_localctx).t.line);
						                      asmFile << str << endl;
						                      stack_offset += 2;

						                  } 
						                  else if( ((TermContext)_localctx).MULOP->getText() == "/") {
						                      str = "\tDIV CX";
						                      asmFile << str << endl;
						                      str = "\tPUSH AX\t\t; line " + std::to_string(((TermContext)_localctx).t.line);
						                      asmFile << str << endl;
						                      stack_offset += 2;
						                  }
						                  else{
						                      str = "\tDIV CX";
						                      asmFile << str << endl;
						                      str = "\tPUSH DX\t\t; line " + std::to_string(((TermContext)_localctx).t.line);
						                      asmFile << str << endl;
						                      stack_offset += 2;
						                  }
						                  
						              
						}
						break;
					case 2:
						{
						_localctx = new TermContext(_parentctx, _parentState);
						_localctx.t = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_term);
						setState(341);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(342);
						((TermContext)_localctx).UNRECOGNIZED = match(UNRECOGNIZED);

						                  writeIntoErrorFile("Error at line " + std::to_string(((TermContext)_localctx).UNRECOGNIZED->getLine()) + ": Unrecognized character " + ((TermContext)_localctx).UNRECOGNIZED->getText()+"\n");
						                  writeIntoparserLogFile("Error at line " + std::to_string(((TermContext)_localctx).UNRECOGNIZED->getLine()) + ": Unrecognized character " + ((TermContext)_localctx).UNRECOGNIZED->getText()+"\n");
						                  syntaxErrorCount++;
						                  // // cout<<"Error at line "<<((TermContext)_localctx).UNRECOGNIZED->getLine()<<": "<<((TermContext)_localctx).UNRECOGNIZED->getText()<<" is not a valid token"<<endl;
						                  ((TermContext)_localctx).trm = ((TermContext)_localctx).t.trm;
						                  // // cout<<"Term at "<<((TermContext)_localctx).t.line<<": "<<_localctx.trm<<endl;
						                  ((TermContext)_localctx).line =  ((TermContext)_localctx).t.line;
						              
						}
						break;
					}
					} 
				}
				setState(348);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,21,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Unary_expressionContext extends ParserRuleContext {
		public std::string unary_expr;
		public int line;
		public Token ADDOP;
		public Unary_expressionContext unary_expression;
		public FactorContext fact;
		public TerminalNode ADDOP() { return getToken(C2105052Parser.ADDOP, 0); }
		public Unary_expressionContext unary_expression() {
			return getRuleContext(Unary_expressionContext.class,0);
		}
		public TerminalNode NOT() { return getToken(C2105052Parser.NOT, 0); }
		public FactorContext factor() {
			return getRuleContext(FactorContext.class,0);
		}
		public Unary_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unary_expression; }
	}

	public final Unary_expressionContext unary_expression() throws RecognitionException {
		Unary_expressionContext _localctx = new Unary_expressionContext(_ctx, getState());
		enterRule(_localctx, 40, RULE_unary_expression);
		try {
			setState(360);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case ADDOP:
				enterOuterAlt(_localctx, 1);
				{
				setState(349);
				((Unary_expressionContext)_localctx).ADDOP = match(ADDOP);
				setState(350);
				((Unary_expressionContext)_localctx).unary_expression = unary_expression();

				        writeIntoparserLogFile("Line " + std::to_string(((Unary_expressionContext)_localctx).unary_expression.line) + ": unary_expression : ADDOP unary_expression\n");
				        ((Unary_expressionContext)_localctx).unary_expr =  ((Unary_expressionContext)_localctx).ADDOP->getText() + ((Unary_expressionContext)_localctx).unary_expression.unary_expr;
				        ((Unary_expressionContext)_localctx).line =  ((Unary_expressionContext)_localctx).unary_expression.line;
				        writeIntoparserLogFile(_localctx.unary_expr + "\n");


				        string str;
				        str = "L" + std::to_string(label_count) + ":";
				            label_count++;
				            asmFile << str << endl;

				            str = "\tPOP AX";
				            asmFile << str << endl;
				            stack_offset -= 2;

				        if (((Unary_expressionContext)_localctx).ADDOP->getText() == "+") {
				            str = "\tPUSH AX\t\t; line " + std::to_string(((Unary_expressionContext)_localctx).unary_expression.line);
				            asmFile << str << endl;
				            stack_offset += 2;
				        }
				        else if (((Unary_expressionContext)_localctx).ADDOP->getText() == "-") {
				            str = "\tNEG AX\t\t; line " + std::to_string(((Unary_expressionContext)_localctx).unary_expression.line);
				            asmFile << str << endl;
				            str = "\tPUSH AX\t\t; line " + std::to_string(((Unary_expressionContext)_localctx).unary_expression.line);
				            asmFile << str << endl;
				            stack_offset += 2;
				        }



				    
				}
				break;
			case NOT:
				enterOuterAlt(_localctx, 2);
				{
				setState(353);
				match(NOT);
				setState(354);
				((Unary_expressionContext)_localctx).unary_expression = unary_expression();

				        writeIntoparserLogFile("Line " + std::to_string(((Unary_expressionContext)_localctx).unary_expression.line) + ": unary_expression : NOT unary_expression\n");
				        ((Unary_expressionContext)_localctx).unary_expr =  "!" + ((Unary_expressionContext)_localctx).unary_expression.unary_expr;
				        ((Unary_expressionContext)_localctx).line =  ((Unary_expressionContext)_localctx).unary_expression.line;
				        writeIntoparserLogFile(_localctx.unary_expr + "\n");


				        string str;
				        str = "L" + std::to_string(label_count) + ":";
				        label_count++;
				        asmFile << str << endl;
				        str = "\tPOP AX\t\t; line " + std::to_string(((Unary_expressionContext)_localctx).unary_expression.line);
				        asmFile << str << endl;
				        stack_offset -= 2; // Decrease stack offset by 2 for unary expression
				        str = "\tCMP AX, 0";
				        asmFile << str << endl;
				        str = "\tJE L" + std::to_string(label_count) + "\t\t; line " + std::to_string(((Unary_expressionContext)_localctx).unary_expression.line);
				        asmFile << str << endl;
				        str = "\tMOV AX, 0";
				        asmFile << str << endl;
				        str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string(((Unary_expressionContext)_localctx).unary_expression.line);
				        asmFile << str << endl;
				        str = "L" + std::to_string(label_count) + ":";
				        asmFile << str << endl;
				        label_count++;
				        str = "\tMOV AX, 1\t\t; line " + std::to_string(((Unary_expressionContext)_localctx).unary_expression.line);
				        asmFile << str << endl;
				        str = "L" + std::to_string(label_count) + ":";
				        asmFile << str << endl;
				        label_count++;
				        str = "\tPUSH AX\t\t; line " + std::to_string(((Unary_expressionContext)_localctx).unary_expression.line);
				        asmFile << str << endl;
				        stack_offset += 2; // Increase stack offset by 2 for unary expression


				    
				}
				break;
			case LPAREN:
			case ID:
			case CONST_INT:
			case CONST_FLOAT:
				enterOuterAlt(_localctx, 3);
				{
				setState(357);
				((Unary_expressionContext)_localctx).fact = factor();

				        ((Unary_expressionContext)_localctx).unary_expr =  ((Unary_expressionContext)_localctx).fact.factorName;
				        ((Unary_expressionContext)_localctx).line =  ((Unary_expressionContext)_localctx).fact.line;

				  
				    
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class FactorContext extends ParserRuleContext {
		public std::string factorName;
		public int line;
		public VariableContext var;
		public Token ID;
		public Argument_listContext ar;
		public ExpressionContext exp;
		public Token c_int;
		public Token c_float;
		public VariableContext variable;
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public TerminalNode ID() { return getToken(C2105052Parser.ID, 0); }
		public TerminalNode LPAREN() { return getToken(C2105052Parser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(C2105052Parser.RPAREN, 0); }
		public Argument_listContext argument_list() {
			return getRuleContext(Argument_listContext.class,0);
		}
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode CONST_INT() { return getToken(C2105052Parser.CONST_INT, 0); }
		public TerminalNode CONST_FLOAT() { return getToken(C2105052Parser.CONST_FLOAT, 0); }
		public TerminalNode INCOP() { return getToken(C2105052Parser.INCOP, 0); }
		public TerminalNode DECOP() { return getToken(C2105052Parser.DECOP, 0); }
		public FactorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_factor; }
	}

	public final FactorContext factor() throws RecognitionException {
		FactorContext _localctx = new FactorContext(_ctx, getState());
		enterRule(_localctx, 42, RULE_factor);
		try {
			setState(388);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,23,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(362);
				((FactorContext)_localctx).var = variable();
				 
				        ((FactorContext)_localctx).factorName =  ((FactorContext)_localctx).var.varName;
				        ((FactorContext)_localctx).line =  ((FactorContext)_localctx).var.line;


				        string str;
				        string var;
				        int pos = ((FactorContext)_localctx).var.varName.find("[");
				        if (pos != std::string::npos) {
				            var = ((FactorContext)_localctx).var.varName.substr(0, pos);
				        } else {
				            var = ((FactorContext)_localctx).var.varName;
				        }
				        str = "L" + std::to_string(label_count) + ":";
				        label_count++;
				        asmFile << str << endl;
				        if(((FactorContext)_localctx).var.varName != var){
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
				            SymbolInfo *s = symbolTable->look_up_in_all_scope(((FactorContext)_localctx).var.varName);
				            if(s!=nullptr){
				                if(s->getScopeId()==1){
				                    str = "\tMOV AX, " + ((FactorContext)_localctx).var.varName + "\t\t; line " + std::to_string(((FactorContext)_localctx).var.line);
				                    asmFile << str << endl;
				                }
				                else{
				                    str = "\tMOV AX, [BP" + std::string((s->getOffset() >= 0) ? "-" : "+") + std::to_string(std::abs(s->getOffset())) + "]\t\t; line " + std::to_string(((FactorContext)_localctx).var.line);
				                    asmFile << str << endl;
				                }
				            }
				            else{
				                str = "\tPOP AX";
				                asmFile << str << endl;
				                stack_offset -= 2;
				            }
				            str = "\tPUSH AX\t\t; line " + std::to_string(((FactorContext)_localctx).var.line);
				            asmFile << str << endl;
				            stack_offset += 2;
				        }

				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(365);
				((FactorContext)_localctx).ID = match(ID);
				setState(366);
				match(LPAREN);
				setState(367);
				((FactorContext)_localctx).ar = argument_list();
				setState(368);
				match(RPAREN);
				 
				        ((FactorContext)_localctx).factorName =  ((FactorContext)_localctx).ID->getText() + "(";
				        for (const auto &term : ((FactorContext)_localctx).ar.arg) {
				            _localctx.factorName += term;
				            if (&term != &(((FactorContext)_localctx).ar.arg.back())) {
				                _localctx.factorName += ",";
				            }
				        }
				        _localctx.factorName += ")";
				        ((FactorContext)_localctx).line =  ((FactorContext)_localctx).ID->getLine();



				        string str;
				        str = "L" + std::to_string(label_count) + ":";
				        label_count++;
				        asmFile << str << endl;
				        str = "\tCALL " + ((FactorContext)_localctx).ID->getText() + "\t\t; line " + std::to_string(((FactorContext)_localctx).ID->getLine());
				        asmFile << str << endl;
				        str = "\tPUSH AX\t\t; line " + std::to_string(((FactorContext)_localctx).ID->getLine());
				        asmFile << str << endl;
				        stack_offset += 2;
				    
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(371);
				match(LPAREN);
				setState(372);
				((FactorContext)_localctx).exp = expression();
				setState(373);
				match(RPAREN);

				        ((FactorContext)_localctx).factorName =  "(" + ((FactorContext)_localctx).exp.str + ")";
				        ((FactorContext)_localctx).line =  ((FactorContext)_localctx).exp.line;
				    
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(376);
				((FactorContext)_localctx).c_int = match(CONST_INT);

				        ((FactorContext)_localctx).factorName =  ((FactorContext)_localctx).c_int->getText();
				        ((FactorContext)_localctx).line =  ((FactorContext)_localctx).c_int->getLine();

				        string str;
				        str+="L"+std::to_string(label_count)+ ":";
				        label_count++;
				        asmFile << str << endl;
				        str = "\tMOV AX, "+((FactorContext)_localctx).c_int->getText()+"\t\t; line "+std::to_string(((FactorContext)_localctx).c_int->getLine());
				        asmFile << str << endl;
				        str = "\tPUSH AX";
				        asmFile << str << endl;
				        stack_offset += 2;
				        
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(378);
				((FactorContext)_localctx).c_float = match(CONST_FLOAT);

				        ((FactorContext)_localctx).factorName =  ((FactorContext)_localctx).c_float->getText();
				        ((FactorContext)_localctx).line =  ((FactorContext)_localctx).c_float->getLine();
				    
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(380);
				((FactorContext)_localctx).variable = variable();
				setState(381);
				match(INCOP);
				 
				        ((FactorContext)_localctx).factorName =  ((FactorContext)_localctx).variable.varName + "++";
				        ((FactorContext)_localctx).line =  ((FactorContext)_localctx).variable.line;


				        string str;
				        string var;
				        int pos = ((FactorContext)_localctx).variable.varName.find("[");
				        if (pos != std::string::npos) {
				            var = ((FactorContext)_localctx).variable.varName.substr(0, pos);
				        } 
				        else {
				            var = ((FactorContext)_localctx).variable.varName;
				        }
				        if(((FactorContext)_localctx).variable.varName != var){
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
				        SymbolInfo *s = symbolTable->look_up_in_all_scope(((FactorContext)_localctx).variable.varName);
				         
				        str = "L" + std::to_string(label_count) + ":";
				        label_count++;
				        asmFile << str << endl;

				        if(s!=nullptr){
				            if(s->getScopeId()==1){
				                str = "\tMOV AX, " + ((FactorContext)_localctx).variable.varName + "\t\t; line " + std::to_string(((FactorContext)_localctx).variable.line);
				                asmFile << str << endl;
				            }
				            else{
				                str = "\tMOV AX, [BP" + std::string((s->getOffset() >= 0) ? "-" : "+") + std::to_string(std::abs(s->getOffset())) + "]\t\t; line " + std::to_string(((FactorContext)_localctx).variable.line);
				                asmFile << str << endl;
				            }
				        }
				        else{
				            str = "\tPOP AX";
				            asmFile << str << endl;
				            stack_offset -= 2;
				        }
				        str = "\tPUSH AX\t\t; line " + std::to_string(((FactorContext)_localctx).variable.line);
				        asmFile << str << endl;
				        stack_offset += 2;
				        str = "\tINC AX\t\t; line " + std::to_string(((FactorContext)_localctx).variable.line);
				        asmFile << str << endl;

				        str = "\tMOV [BP" + std::string((s->getOffset() >= 0) ? "-" : "+") + std::to_string(std::abs(s->getOffset())) + "], AX\t\t; line " + std::to_string(((FactorContext)_localctx).variable.line);
				        asmFile << str << endl;
				        }

				    
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(384);
				((FactorContext)_localctx).variable = variable();
				setState(385);
				match(DECOP);

				        ((FactorContext)_localctx).factorName =  ((FactorContext)_localctx).variable.varName + "--";
				        ((FactorContext)_localctx).line =  ((FactorContext)_localctx).variable.line;


				        string str;
				        string var;
				        int pos = ((FactorContext)_localctx).variable.varName.find("[");
				        if (pos != std::string::npos) {
				            var = ((FactorContext)_localctx).variable.varName.substr(0, pos);
				        } 
				        else {
				            var = ((FactorContext)_localctx).variable.varName;
				        }
				        if(((FactorContext)_localctx).variable.varName != var){
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
				        SymbolInfo *s = symbolTable->look_up_in_all_scope(((FactorContext)_localctx).variable.varName);
				        str = "L" + std::to_string(label_count) + ":";
				        label_count++;
				        asmFile << str << endl;

				        if(s!=nullptr){
				            if(s->getScopeId()==1){
				                str = "\tMOV AX, " + ((FactorContext)_localctx).variable.varName + "\t\t; line " + std::to_string(((FactorContext)_localctx).variable.line);
				                asmFile << str << endl;
				            }
				            else{
				                str = "\tMOV AX, [BP" + std::string((s->getOffset() >= 0) ? "-" : "+") + std::to_string(std::abs(s->getOffset())) + "]\t\t; line " + std::to_string(((FactorContext)_localctx).variable.line);
				                asmFile << str << endl;
				            }
				        }
				        else{
				            str = "\tPOP AX";
				            asmFile << str << endl;
				            stack_offset -= 2;
				        }
				        str = "\tPUSH AX\t\t; line " + std::to_string(((FactorContext)_localctx).variable.line);
				        asmFile << str << endl;
				        stack_offset += 2;
				        str = "\tDEC AX\t\t; line " + std::to_string(((FactorContext)_localctx).variable.line);
				        asmFile << str << endl;
				        str = "\tMOV [BP" + std::string((s->getOffset() >= 0) ? "-" : "+") + std::to_string(std::abs(s->getOffset())) + "], AX\t\t; line " + std::to_string(((FactorContext)_localctx).variable.line);
				        asmFile << str << endl;

				        }
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Argument_listContext extends ParserRuleContext {
		public std::vector<std::string> arg;
		public ArgumentsContext ar;
		public ArgumentsContext arguments() {
			return getRuleContext(ArgumentsContext.class,0);
		}
		public Argument_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_argument_list; }
	}

	public final Argument_listContext argument_list() throws RecognitionException {
		Argument_listContext _localctx = new Argument_listContext(_ctx, getState());
		enterRule(_localctx, 44, RULE_argument_list);
		try {
			setState(394);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LPAREN:
			case ADDOP:
			case NOT:
			case ID:
			case CONST_INT:
			case CONST_FLOAT:
				enterOuterAlt(_localctx, 1);
				{
				setState(390);
				((Argument_listContext)_localctx).ar = arguments(0);
				 
				        ((Argument_listContext)_localctx).arg =  ((Argument_listContext)_localctx).ar.arg;
				    
				}
				break;
			case RPAREN:
				enterOuterAlt(_localctx, 2);
				{
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ArgumentsContext extends ParserRuleContext {
		public std::vector<std::string> arg;
		public int line;
		public ArgumentsContext ar;
		public Logic_expressionContext l;
		public Logic_expressionContext logic_expression() {
			return getRuleContext(Logic_expressionContext.class,0);
		}
		public TerminalNode COMMA() { return getToken(C2105052Parser.COMMA, 0); }
		public ArgumentsContext arguments() {
			return getRuleContext(ArgumentsContext.class,0);
		}
		public ArgumentsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arguments; }
	}

	public final ArgumentsContext arguments() throws RecognitionException {
		return arguments(0);
	}

	private ArgumentsContext arguments(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ArgumentsContext _localctx = new ArgumentsContext(_ctx, _parentState);
		ArgumentsContext _prevctx = _localctx;
		int _startState = 46;
		enterRecursionRule(_localctx, 46, RULE_arguments, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(397);
			((ArgumentsContext)_localctx).l = logic_expression();
			 
			        ((ArgumentsContext)_localctx).arg =  std::vector<std::string>();
			        for (const auto &term : ((ArgumentsContext)_localctx).l.rel_expr) {
			            _localctx.arg.push_back(term);
			        }
			        string str;
			        for (const auto &term : _localctx.arg) {
			            str += term;
			        }
			        _localctx.arg.clear();
			        _localctx.arg.push_back(str);
			        ((ArgumentsContext)_localctx).line =  ((ArgumentsContext)_localctx).l.line;

			    
			}
			_ctx.stop = _input.LT(-1);
			setState(407);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,25,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ArgumentsContext(_parentctx, _parentState);
					_localctx.ar = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_arguments);
					setState(400);
					if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
					setState(401);
					match(COMMA);
					setState(402);
					((ArgumentsContext)_localctx).l = logic_expression();
					 
					                  ((ArgumentsContext)_localctx).arg =  ((ArgumentsContext)_localctx).ar.arg;
					                  string ab;
					                  for (const auto &term : ((ArgumentsContext)_localctx).l.rel_expr) {
					                      ab += term;
					                  }
					                  _localctx.arg.push_back(ab);
					                  ((ArgumentsContext)_localctx).line =  ((ArgumentsContext)_localctx).l.line;
					              
					}
					} 
				}
				setState(409);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,25,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 1:
			return program_sempred((ProgramContext)_localctx, predIndex);
		case 7:
			return declaration_list_sempred((Declaration_listContext)_localctx, predIndex);
		case 10:
			return parameter_list_sempred((Parameter_listContext)_localctx, predIndex);
		case 11:
			return statements_sempred((StatementsContext)_localctx, predIndex);
		case 18:
			return simple_expression_sempred((Simple_expressionContext)_localctx, predIndex);
		case 19:
			return term_sempred((TermContext)_localctx, predIndex);
		case 23:
			return arguments_sempred((ArgumentsContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean program_sempred(ProgramContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 2);
		}
		return true;
	}
	private boolean declaration_list_sempred(Declaration_listContext _localctx, int predIndex) {
		switch (predIndex) {
		case 1:
			return precpred(_ctx, 6);
		case 2:
			return precpred(_ctx, 5);
		case 3:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean parameter_list_sempred(Parameter_listContext _localctx, int predIndex) {
		switch (predIndex) {
		case 4:
			return precpred(_ctx, 2);
		}
		return true;
	}
	private boolean statements_sempred(StatementsContext _localctx, int predIndex) {
		switch (predIndex) {
		case 5:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean simple_expression_sempred(Simple_expressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 6:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean term_sempred(TermContext _localctx, int predIndex) {
		switch (predIndex) {
		case 7:
			return precpred(_ctx, 2);
		case 8:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean arguments_sempred(ArgumentsContext _localctx, int predIndex) {
		switch (predIndex) {
		case 9:
			return precpred(_ctx, 2);
		}
		return true;
	}

	public static final String _serializedATN =
		"\u0004\u0001\"\u019b\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002"+
		"\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002"+
		"\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b\u0002"+
		"\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002\u000f\u0007\u000f"+
		"\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011\u0002\u0012\u0007\u0012"+
		"\u0002\u0013\u0007\u0013\u0002\u0014\u0007\u0014\u0002\u0015\u0007\u0015"+
		"\u0002\u0016\u0007\u0016\u0002\u0017\u0007\u0017\u0001\u0000\u0001\u0000"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0005\u0001"+
		"8\b\u0001\n\u0001\f\u0001;\t\u0001\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0003\u0002@\b\u0002\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003"+
		"\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003"+
		"\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0003\u0003"+
		"Q\b\u0003\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0003\u0004d\b\u0004\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0003\u0005"+
		"o\b\u0005\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006"+
		"\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0003\u0006"+
		"{\b\u0006\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007"+
		"\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007"+
		"\u0001\u0007\u0003\u0007\u0089\b\u0007\u0001\u0007\u0001\u0007\u0001\u0007"+
		"\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007"+
		"\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007"+
		"\u0001\u0007\u0001\u0007\u0005\u0007\u009c\b\u0007\n\u0007\f\u0007\u009f"+
		"\t\u0007\u0001\b\u0001\b\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001"+
		"\t\u0003\t\u00a9\b\t\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001"+
		"\n\u0001\n\u0001\n\u0003\n\u00b4\b\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001"+
		"\n\u0001\n\u0005\n\u00bc\b\n\n\n\f\n\u00bf\t\n\u0001\u000b\u0001\u000b"+
		"\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b"+
		"\u0005\u000b\u00c9\b\u000b\n\u000b\f\u000b\u00cc\t\u000b\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0003\f\u010b\b\f\u0001\r\u0001"+
		"\r\u0001\r\u0001\r\u0001\r\u0001\r\u0003\r\u0113\b\r\u0001\u000e\u0001"+
		"\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001"+
		"\u000e\u0003\u000e\u011d\b\u000e\u0001\u000f\u0001\u000f\u0001\u000f\u0001"+
		"\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0003\u000f\u0127"+
		"\b\u000f\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001"+
		"\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0003\u0010\u0133"+
		"\b\u0010\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001"+
		"\u0011\u0001\u0011\u0001\u0011\u0003\u0011\u013d\b\u0011\u0001\u0012\u0001"+
		"\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0001"+
		"\u0012\u0001\u0012\u0005\u0012\u0148\b\u0012\n\u0012\f\u0012\u014b\t\u0012"+
		"\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013"+
		"\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013"+
		"\u0005\u0013\u0159\b\u0013\n\u0013\f\u0013\u015c\t\u0013\u0001\u0014\u0001"+
		"\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001"+
		"\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0003\u0014\u0169\b\u0014\u0001"+
		"\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001"+
		"\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001"+
		"\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001"+
		"\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001"+
		"\u0015\u0001\u0015\u0003\u0015\u0185\b\u0015\u0001\u0016\u0001\u0016\u0001"+
		"\u0016\u0001\u0016\u0003\u0016\u018b\b\u0016\u0001\u0017\u0001\u0017\u0001"+
		"\u0017\u0001\u0017\u0001\u0017\u0001\u0017\u0001\u0017\u0001\u0017\u0001"+
		"\u0017\u0005\u0017\u0196\b\u0017\n\u0017\f\u0017\u0199\t\u0017\u0001\u0017"+
		"\u0000\u0007\u0002\u000e\u0014\u0016$&.\u0018\u0000\u0002\u0004\u0006"+
		"\b\n\f\u000e\u0010\u0012\u0014\u0016\u0018\u001a\u001c\u001e \"$&(*,."+
		"\u0000\u0000\u01ad\u00000\u0001\u0000\u0000\u0000\u00022\u0001\u0000\u0000"+
		"\u0000\u0004?\u0001\u0000\u0000\u0000\u0006P\u0001\u0000\u0000\u0000\b"+
		"c\u0001\u0000\u0000\u0000\nn\u0001\u0000\u0000\u0000\fz\u0001\u0000\u0000"+
		"\u0000\u000e\u0088\u0001\u0000\u0000\u0000\u0010\u00a0\u0001\u0000\u0000"+
		"\u0000\u0012\u00a8\u0001\u0000\u0000\u0000\u0014\u00b3\u0001\u0000\u0000"+
		"\u0000\u0016\u00c0\u0001\u0000\u0000\u0000\u0018\u010a\u0001\u0000\u0000"+
		"\u0000\u001a\u0112\u0001\u0000\u0000\u0000\u001c\u011c\u0001\u0000\u0000"+
		"\u0000\u001e\u0126\u0001\u0000\u0000\u0000 \u0132\u0001\u0000\u0000\u0000"+
		"\"\u013c\u0001\u0000\u0000\u0000$\u013e\u0001\u0000\u0000\u0000&\u014c"+
		"\u0001\u0000\u0000\u0000(\u0168\u0001\u0000\u0000\u0000*\u0184\u0001\u0000"+
		"\u0000\u0000,\u018a\u0001\u0000\u0000\u0000.\u018c\u0001\u0000\u0000\u0000"+
		"01\u0003\u0002\u0001\u00001\u0001\u0001\u0000\u0000\u000023\u0006\u0001"+
		"\uffff\uffff\u000034\u0003\u0004\u0002\u000049\u0001\u0000\u0000\u0000"+
		"56\n\u0002\u0000\u000068\u0003\u0004\u0002\u000075\u0001\u0000\u0000\u0000"+
		"8;\u0001\u0000\u0000\u000097\u0001\u0000\u0000\u00009:\u0001\u0000\u0000"+
		"\u0000:\u0003\u0001\u0000\u0000\u0000;9\u0001\u0000\u0000\u0000<@\u0003"+
		"\f\u0006\u0000=@\u0003\u0006\u0003\u0000>@\u0003\b\u0004\u0000?<\u0001"+
		"\u0000\u0000\u0000?=\u0001\u0000\u0000\u0000?>\u0001\u0000\u0000\u0000"+
		"@\u0005\u0001\u0000\u0000\u0000AB\u0003\u0012\t\u0000BC\u0005\u001f\u0000"+
		"\u0000CD\u0005\u000e\u0000\u0000DE\u0003\u0014\n\u0000EF\u0005\u000f\u0000"+
		"\u0000FG\u0005\u0014\u0000\u0000GH\u0006\u0003\uffff\uffff\u0000HQ\u0001"+
		"\u0000\u0000\u0000IJ\u0003\u0012\t\u0000JK\u0005\u001f\u0000\u0000KL\u0005"+
		"\u000e\u0000\u0000LM\u0005\u000f\u0000\u0000MN\u0005\u0014\u0000\u0000"+
		"NO\u0006\u0003\uffff\uffff\u0000OQ\u0001\u0000\u0000\u0000PA\u0001\u0000"+
		"\u0000\u0000PI\u0001\u0000\u0000\u0000Q\u0007\u0001\u0000\u0000\u0000"+
		"RS\u0003\u0012\t\u0000ST\u0005\u001f\u0000\u0000TU\u0005\u000e\u0000\u0000"+
		"UV\u0003\u0014\n\u0000VW\u0005\u000f\u0000\u0000WX\u0006\u0004\uffff\uffff"+
		"\u0000XY\u0003\n\u0005\u0000YZ\u0006\u0004\uffff\uffff\u0000Zd\u0001\u0000"+
		"\u0000\u0000[\\\u0003\u0012\t\u0000\\]\u0005\u001f\u0000\u0000]^\u0005"+
		"\u000e\u0000\u0000^_\u0005\u000f\u0000\u0000_`\u0006\u0004\uffff\uffff"+
		"\u0000`a\u0003\n\u0005\u0000ab\u0006\u0004\uffff\uffff\u0000bd\u0001\u0000"+
		"\u0000\u0000cR\u0001\u0000\u0000\u0000c[\u0001\u0000\u0000\u0000d\t\u0001"+
		"\u0000\u0000\u0000ef\u0005\u0010\u0000\u0000fg\u0006\u0005\uffff\uffff"+
		"\u0000gh\u0003\u0016\u000b\u0000hi\u0005\u0011\u0000\u0000ij\u0006\u0005"+
		"\uffff\uffff\u0000jo\u0001\u0000\u0000\u0000kl\u0005\u0010\u0000\u0000"+
		"lm\u0005\u0011\u0000\u0000mo\u0006\u0005\uffff\uffff\u0000ne\u0001\u0000"+
		"\u0000\u0000nk\u0001\u0000\u0000\u0000o\u000b\u0001\u0000\u0000\u0000"+
		"pq\u0003\u0012\t\u0000qr\u0003\u000e\u0007\u0000rs\u0005\u0014\u0000\u0000"+
		"st\u0006\u0006\uffff\uffff\u0000t{\u0001\u0000\u0000\u0000uv\u0003\u0012"+
		"\t\u0000vw\u0003\u0010\b\u0000wx\u0005\u0014\u0000\u0000xy\u0006\u0006"+
		"\uffff\uffff\u0000y{\u0001\u0000\u0000\u0000zp\u0001\u0000\u0000\u0000"+
		"zu\u0001\u0000\u0000\u0000{\r\u0001\u0000\u0000\u0000|}\u0006\u0007\uffff"+
		"\uffff\u0000}~\u0005\u001f\u0000\u0000~\u0089\u0006\u0007\uffff\uffff"+
		"\u0000\u007f\u0080\u0005\u001f\u0000\u0000\u0080\u0081\u0005\u0012\u0000"+
		"\u0000\u0081\u0082\u0005 \u0000\u0000\u0082\u0083\u0005\u0013\u0000\u0000"+
		"\u0083\u0089\u0006\u0007\uffff\uffff\u0000\u0084\u0085\u0005\u001f\u0000"+
		"\u0000\u0085\u0086\u0005\u0016\u0000\u0000\u0086\u0087\u0005\u001f\u0000"+
		"\u0000\u0087\u0089\u0006\u0007\uffff\uffff\u0000\u0088|\u0001\u0000\u0000"+
		"\u0000\u0088\u007f\u0001\u0000\u0000\u0000\u0088\u0084\u0001\u0000\u0000"+
		"\u0000\u0089\u009d\u0001\u0000\u0000\u0000\u008a\u008b\n\u0006\u0000\u0000"+
		"\u008b\u008c\u0005\u0015\u0000\u0000\u008c\u008d\u0005\u001f\u0000\u0000"+
		"\u008d\u009c\u0006\u0007\uffff\uffff\u0000\u008e\u008f\n\u0005\u0000\u0000"+
		"\u008f\u0090\u0005\u0015\u0000\u0000\u0090\u0091\u0005\u001f\u0000\u0000"+
		"\u0091\u0092\u0005\u0012\u0000\u0000\u0092\u0093\u0005 \u0000\u0000\u0093"+
		"\u0094\u0005\u0013\u0000\u0000\u0094\u009c\u0006\u0007\uffff\uffff\u0000"+
		"\u0095\u0096\n\u0001\u0000\u0000\u0096\u0097\u0005\u0015\u0000\u0000\u0097"+
		"\u0098\u0005\u001f\u0000\u0000\u0098\u0099\u0005\u0016\u0000\u0000\u0099"+
		"\u009a\u0005\u001f\u0000\u0000\u009a\u009c\u0006\u0007\uffff\uffff\u0000"+
		"\u009b\u008a\u0001\u0000\u0000\u0000\u009b\u008e\u0001\u0000\u0000\u0000"+
		"\u009b\u0095\u0001\u0000\u0000\u0000\u009c\u009f\u0001\u0000\u0000\u0000"+
		"\u009d\u009b\u0001\u0000\u0000\u0000\u009d\u009e\u0001\u0000\u0000\u0000"+
		"\u009e\u000f\u0001\u0000\u0000\u0000\u009f\u009d\u0001\u0000\u0000\u0000"+
		"\u00a0\u00a1\u0006\b\uffff\uffff\u0000\u00a1\u0011\u0001\u0000\u0000\u0000"+
		"\u00a2\u00a3\u0005\u000b\u0000\u0000\u00a3\u00a9\u0006\t\uffff\uffff\u0000"+
		"\u00a4\u00a5\u0005\f\u0000\u0000\u00a5\u00a9\u0006\t\uffff\uffff\u0000"+
		"\u00a6\u00a7\u0005\r\u0000\u0000\u00a7\u00a9\u0006\t\uffff\uffff\u0000"+
		"\u00a8\u00a2\u0001\u0000\u0000\u0000\u00a8\u00a4\u0001\u0000\u0000\u0000"+
		"\u00a8\u00a6\u0001\u0000\u0000\u0000\u00a9\u0013\u0001\u0000\u0000\u0000"+
		"\u00aa\u00ab\u0006\n\uffff\uffff\u0000\u00ab\u00ac\u0003\u0012\t\u0000"+
		"\u00ac\u00ad\u0005\u001f\u0000\u0000\u00ad\u00ae\u0006\n\uffff\uffff\u0000"+
		"\u00ae\u00b4\u0001\u0000\u0000\u0000\u00af\u00b0\u0003\u0012\t\u0000\u00b0"+
		"\u00b1\u0005\u0016\u0000\u0000\u00b1\u00b2\u0006\n\uffff\uffff\u0000\u00b2"+
		"\u00b4\u0001\u0000\u0000\u0000\u00b3\u00aa\u0001\u0000\u0000\u0000\u00b3"+
		"\u00af\u0001\u0000\u0000\u0000\u00b4\u00bd\u0001\u0000\u0000\u0000\u00b5"+
		"\u00b6\n\u0002\u0000\u0000\u00b6\u00b7\u0005\u0015\u0000\u0000\u00b7\u00b8"+
		"\u0003\u0012\t\u0000\u00b8\u00b9\u0005\u001f\u0000\u0000\u00b9\u00ba\u0006"+
		"\n\uffff\uffff\u0000\u00ba\u00bc\u0001\u0000\u0000\u0000\u00bb\u00b5\u0001"+
		"\u0000\u0000\u0000\u00bc\u00bf\u0001\u0000\u0000\u0000\u00bd\u00bb\u0001"+
		"\u0000\u0000\u0000\u00bd\u00be\u0001\u0000\u0000\u0000\u00be\u0015\u0001"+
		"\u0000\u0000\u0000\u00bf\u00bd\u0001\u0000\u0000\u0000\u00c0\u00c1\u0006"+
		"\u000b\uffff\uffff\u0000\u00c1\u00c2\u0003\u0018\f\u0000\u00c2\u00c3\u0006"+
		"\u000b\uffff\uffff\u0000\u00c3\u00ca\u0001\u0000\u0000\u0000\u00c4\u00c5"+
		"\n\u0001\u0000\u0000\u00c5\u00c6\u0003\u0018\f\u0000\u00c6\u00c7\u0006"+
		"\u000b\uffff\uffff\u0000\u00c7\u00c9\u0001\u0000\u0000\u0000\u00c8\u00c4"+
		"\u0001\u0000\u0000\u0000\u00c9\u00cc\u0001\u0000\u0000\u0000\u00ca\u00c8"+
		"\u0001\u0000\u0000\u0000\u00ca\u00cb\u0001\u0000\u0000\u0000\u00cb\u0017"+
		"\u0001\u0000\u0000\u0000\u00cc\u00ca\u0001\u0000\u0000\u0000\u00cd\u00ce"+
		"\u0003\f\u0006\u0000\u00ce\u00cf\u0006\f\uffff\uffff\u0000\u00cf\u010b"+
		"\u0001\u0000\u0000\u0000\u00d0\u00d1\u0003\u001a\r\u0000\u00d1\u00d2\u0006"+
		"\f\uffff\uffff\u0000\u00d2\u010b\u0001\u0000\u0000\u0000\u00d3\u00d4\u0003"+
		"\n\u0005\u0000\u00d4\u00d5\u0006\f\uffff\uffff\u0000\u00d5\u010b\u0001"+
		"\u0000\u0000\u0000\u00d6\u00d7\u0005\u0007\u0000\u0000\u00d7\u00d8\u0005"+
		"\u000e\u0000\u0000\u00d8\u00d9\u0003\u001a\r\u0000\u00d9\u00da\u0006\f"+
		"\uffff\uffff\u0000\u00da\u00db\u0003\u001a\r\u0000\u00db\u00dc\u0006\f"+
		"\uffff\uffff\u0000\u00dc\u00dd\u0003\u001e\u000f\u0000\u00dd\u00de\u0005"+
		"\u000f\u0000\u0000\u00de\u00df\u0006\f\uffff\uffff\u0000\u00df\u00e0\u0003"+
		"\u0018\f\u0000\u00e0\u00e1\u0006\f\uffff\uffff\u0000\u00e1\u010b\u0001"+
		"\u0000\u0000\u0000\u00e2\u00e3\u0005\u0005\u0000\u0000\u00e3\u00e4\u0005"+
		"\u000e\u0000\u0000\u00e4\u00e5\u0003\u001e\u000f\u0000\u00e5\u00e6\u0005"+
		"\u000f\u0000\u0000\u00e6\u00e7\u0006\f\uffff\uffff\u0000\u00e7\u00e8\u0003"+
		"\u0018\f\u0000\u00e8\u00e9\u0006\f\uffff\uffff\u0000\u00e9\u010b\u0001"+
		"\u0000\u0000\u0000\u00ea\u00eb\u0005\u0005\u0000\u0000\u00eb\u00ec\u0005"+
		"\u000e\u0000\u0000\u00ec\u00ed\u0003\u001e\u000f\u0000\u00ed\u00ee\u0005"+
		"\u000f\u0000\u0000\u00ee\u00ef\u0006\f\uffff\uffff\u0000\u00ef\u00f0\u0003"+
		"\u0018\f\u0000\u00f0\u00f1\u0006\f\uffff\uffff\u0000\u00f1\u00f2\u0005"+
		"\u0006\u0000\u0000\u00f2\u00f3\u0006\f\uffff\uffff\u0000\u00f3\u00f4\u0003"+
		"\u0018\f\u0000\u00f4\u00f5\u0006\f\uffff\uffff\u0000\u00f5\u010b\u0001"+
		"\u0000\u0000\u0000\u00f6\u00f7\u0005\b\u0000\u0000\u00f7\u00f8\u0006\f"+
		"\uffff\uffff\u0000\u00f8\u00f9\u0005\u000e\u0000\u0000\u00f9\u00fa\u0003"+
		"\u001e\u000f\u0000\u00fa\u00fb\u0006\f\uffff\uffff\u0000\u00fb\u00fc\u0005"+
		"\u000f\u0000\u0000\u00fc\u00fd\u0003\u0018\f\u0000\u00fd\u00fe\u0006\f"+
		"\uffff\uffff\u0000\u00fe\u010b\u0001\u0000\u0000\u0000\u00ff\u0100\u0005"+
		"\t\u0000\u0000\u0100\u0101\u0005\u000e\u0000\u0000\u0101\u0102\u0005\u001f"+
		"\u0000\u0000\u0102\u0103\u0005\u000f\u0000\u0000\u0103\u0104\u0005\u0014"+
		"\u0000\u0000\u0104\u010b\u0006\f\uffff\uffff\u0000\u0105\u0106\u0005\n"+
		"\u0000\u0000\u0106\u0107\u0003\u001e\u000f\u0000\u0107\u0108\u0005\u0014"+
		"\u0000\u0000\u0108\u0109\u0006\f\uffff\uffff\u0000\u0109\u010b\u0001\u0000"+
		"\u0000\u0000\u010a\u00cd\u0001\u0000\u0000\u0000\u010a\u00d0\u0001\u0000"+
		"\u0000\u0000\u010a\u00d3\u0001\u0000\u0000\u0000\u010a\u00d6\u0001\u0000"+
		"\u0000\u0000\u010a\u00e2\u0001\u0000\u0000\u0000\u010a\u00ea\u0001\u0000"+
		"\u0000\u0000\u010a\u00f6\u0001\u0000\u0000\u0000\u010a\u00ff\u0001\u0000"+
		"\u0000\u0000\u010a\u0105\u0001\u0000\u0000\u0000\u010b\u0019\u0001\u0000"+
		"\u0000\u0000\u010c\u010d\u0005\u0014\u0000\u0000\u010d\u0113\u0006\r\uffff"+
		"\uffff\u0000\u010e\u010f\u0003\u001e\u000f\u0000\u010f\u0110\u0005\u0014"+
		"\u0000\u0000\u0110\u0111\u0006\r\uffff\uffff\u0000\u0111\u0113\u0001\u0000"+
		"\u0000\u0000\u0112\u010c\u0001\u0000\u0000\u0000\u0112\u010e\u0001\u0000"+
		"\u0000\u0000\u0113\u001b\u0001\u0000\u0000\u0000\u0114\u0115\u0005\u001f"+
		"\u0000\u0000\u0115\u011d\u0006\u000e\uffff\uffff\u0000\u0116\u0117\u0005"+
		"\u001f\u0000\u0000\u0117\u0118\u0005\u0012\u0000\u0000\u0118\u0119\u0003"+
		"\u001e\u000f\u0000\u0119\u011a\u0005\u0013\u0000\u0000\u011a\u011b\u0006"+
		"\u000e\uffff\uffff\u0000\u011b\u011d\u0001\u0000\u0000\u0000\u011c\u0114"+
		"\u0001\u0000\u0000\u0000\u011c\u0116\u0001\u0000\u0000\u0000\u011d\u001d"+
		"\u0001\u0000\u0000\u0000\u011e\u011f\u0003 \u0010\u0000\u011f\u0120\u0006"+
		"\u000f\uffff\uffff\u0000\u0120\u0127\u0001\u0000\u0000\u0000\u0121\u0122"+
		"\u0003\u001c\u000e\u0000\u0122\u0123\u0005\u001e\u0000\u0000\u0123\u0124"+
		"\u0003 \u0010\u0000\u0124\u0125\u0006\u000f\uffff\uffff\u0000\u0125\u0127"+
		"\u0001\u0000\u0000\u0000\u0126\u011e\u0001\u0000\u0000\u0000\u0126\u0121"+
		"\u0001\u0000\u0000\u0000\u0127\u001f\u0001\u0000\u0000\u0000\u0128\u0129"+
		"\u0003\"\u0011\u0000\u0129\u012a\u0006\u0010\uffff\uffff\u0000\u012a\u0133"+
		"\u0001\u0000\u0000\u0000\u012b\u012c\u0003\"\u0011\u0000\u012c\u012d\u0006"+
		"\u0010\uffff\uffff\u0000\u012d\u012e\u0005\u001d\u0000\u0000\u012e\u012f"+
		"\u0006\u0010\uffff\uffff\u0000\u012f\u0130\u0003\"\u0011\u0000\u0130\u0131"+
		"\u0006\u0010\uffff\uffff\u0000\u0131\u0133\u0001\u0000\u0000\u0000\u0132"+
		"\u0128\u0001\u0000\u0000\u0000\u0132\u012b\u0001\u0000\u0000\u0000\u0133"+
		"!\u0001\u0000\u0000\u0000\u0134\u0135\u0003$\u0012\u0000\u0135\u0136\u0006"+
		"\u0011\uffff\uffff\u0000\u0136\u013d\u0001\u0000\u0000\u0000\u0137\u0138"+
		"\u0003$\u0012\u0000\u0138\u0139\u0005\u001c\u0000\u0000\u0139\u013a\u0003"+
		"$\u0012\u0000\u013a\u013b\u0006\u0011\uffff\uffff\u0000\u013b\u013d\u0001"+
		"\u0000\u0000\u0000\u013c\u0134\u0001\u0000\u0000\u0000\u013c\u0137\u0001"+
		"\u0000\u0000\u0000\u013d#\u0001\u0000\u0000\u0000\u013e\u013f\u0006\u0012"+
		"\uffff\uffff\u0000\u013f\u0140\u0003&\u0013\u0000\u0140\u0141\u0006\u0012"+
		"\uffff\uffff\u0000\u0141\u0149\u0001\u0000\u0000\u0000\u0142\u0143\n\u0001"+
		"\u0000\u0000\u0143\u0144\u0005\u0016\u0000\u0000\u0144\u0145\u0003&\u0013"+
		"\u0000\u0145\u0146\u0006\u0012\uffff\uffff\u0000\u0146\u0148\u0001\u0000"+
		"\u0000\u0000\u0147\u0142\u0001\u0000\u0000\u0000\u0148\u014b\u0001\u0000"+
		"\u0000\u0000\u0149\u0147\u0001\u0000\u0000\u0000\u0149\u014a\u0001\u0000"+
		"\u0000\u0000\u014a%\u0001\u0000\u0000\u0000\u014b\u0149\u0001\u0000\u0000"+
		"\u0000\u014c\u014d\u0006\u0013\uffff\uffff\u0000\u014d\u014e\u0003(\u0014"+
		"\u0000\u014e\u014f\u0006\u0013\uffff\uffff\u0000\u014f\u015a\u0001\u0000"+
		"\u0000\u0000\u0150\u0151\n\u0002\u0000\u0000\u0151\u0152\u0005\u0018\u0000"+
		"\u0000\u0152\u0153\u0003(\u0014\u0000\u0153\u0154\u0006\u0013\uffff\uffff"+
		"\u0000\u0154\u0159\u0001\u0000\u0000\u0000\u0155\u0156\n\u0001\u0000\u0000"+
		"\u0156\u0157\u0005\"\u0000\u0000\u0157\u0159\u0006\u0013\uffff\uffff\u0000"+
		"\u0158\u0150\u0001\u0000\u0000\u0000\u0158\u0155\u0001\u0000\u0000\u0000"+
		"\u0159\u015c\u0001\u0000\u0000\u0000\u015a\u0158\u0001\u0000\u0000\u0000"+
		"\u015a\u015b\u0001\u0000\u0000\u0000\u015b\'\u0001\u0000\u0000\u0000\u015c"+
		"\u015a\u0001\u0000\u0000\u0000\u015d\u015e\u0005\u0016\u0000\u0000\u015e"+
		"\u015f\u0003(\u0014\u0000\u015f\u0160\u0006\u0014\uffff\uffff\u0000\u0160"+
		"\u0169\u0001\u0000\u0000\u0000\u0161\u0162\u0005\u001b\u0000\u0000\u0162"+
		"\u0163\u0003(\u0014\u0000\u0163\u0164\u0006\u0014\uffff\uffff\u0000\u0164"+
		"\u0169\u0001\u0000\u0000\u0000\u0165\u0166\u0003*\u0015\u0000\u0166\u0167"+
		"\u0006\u0014\uffff\uffff\u0000\u0167\u0169\u0001\u0000\u0000\u0000\u0168"+
		"\u015d\u0001\u0000\u0000\u0000\u0168\u0161\u0001\u0000\u0000\u0000\u0168"+
		"\u0165\u0001\u0000\u0000\u0000\u0169)\u0001\u0000\u0000\u0000\u016a\u016b"+
		"\u0003\u001c\u000e\u0000\u016b\u016c\u0006\u0015\uffff\uffff\u0000\u016c"+
		"\u0185\u0001\u0000\u0000\u0000\u016d\u016e\u0005\u001f\u0000\u0000\u016e"+
		"\u016f\u0005\u000e\u0000\u0000\u016f\u0170\u0003,\u0016\u0000\u0170\u0171"+
		"\u0005\u000f\u0000\u0000\u0171\u0172\u0006\u0015\uffff\uffff\u0000\u0172"+
		"\u0185\u0001\u0000\u0000\u0000\u0173\u0174\u0005\u000e\u0000\u0000\u0174"+
		"\u0175\u0003\u001e\u000f\u0000\u0175\u0176\u0005\u000f\u0000\u0000\u0176"+
		"\u0177\u0006\u0015\uffff\uffff\u0000\u0177\u0185\u0001\u0000\u0000\u0000"+
		"\u0178\u0179\u0005 \u0000\u0000\u0179\u0185\u0006\u0015\uffff\uffff\u0000"+
		"\u017a\u017b\u0005!\u0000\u0000\u017b\u0185\u0006\u0015\uffff\uffff\u0000"+
		"\u017c\u017d\u0003\u001c\u000e\u0000\u017d\u017e\u0005\u0019\u0000\u0000"+
		"\u017e\u017f\u0006\u0015\uffff\uffff\u0000\u017f\u0185\u0001\u0000\u0000"+
		"\u0000\u0180\u0181\u0003\u001c\u000e\u0000\u0181\u0182\u0005\u001a\u0000"+
		"\u0000\u0182\u0183\u0006\u0015\uffff\uffff\u0000\u0183\u0185\u0001\u0000"+
		"\u0000\u0000\u0184\u016a\u0001\u0000\u0000\u0000\u0184\u016d\u0001\u0000"+
		"\u0000\u0000\u0184\u0173\u0001\u0000\u0000\u0000\u0184\u0178\u0001\u0000"+
		"\u0000\u0000\u0184\u017a\u0001\u0000\u0000\u0000\u0184\u017c\u0001\u0000"+
		"\u0000\u0000\u0184\u0180\u0001\u0000\u0000\u0000\u0185+\u0001\u0000\u0000"+
		"\u0000\u0186\u0187\u0003.\u0017\u0000\u0187\u0188\u0006\u0016\uffff\uffff"+
		"\u0000\u0188\u018b\u0001\u0000\u0000\u0000\u0189\u018b\u0001\u0000\u0000"+
		"\u0000\u018a\u0186\u0001\u0000\u0000\u0000\u018a\u0189\u0001\u0000\u0000"+
		"\u0000\u018b-\u0001\u0000\u0000\u0000\u018c\u018d\u0006\u0017\uffff\uffff"+
		"\u0000\u018d\u018e\u0003 \u0010\u0000\u018e\u018f\u0006\u0017\uffff\uffff"+
		"\u0000\u018f\u0197\u0001\u0000\u0000\u0000\u0190\u0191\n\u0002\u0000\u0000"+
		"\u0191\u0192\u0005\u0015\u0000\u0000\u0192\u0193\u0003 \u0010\u0000\u0193"+
		"\u0194\u0006\u0017\uffff\uffff\u0000\u0194\u0196\u0001\u0000\u0000\u0000"+
		"\u0195\u0190\u0001\u0000\u0000\u0000\u0196\u0199\u0001\u0000\u0000\u0000"+
		"\u0197\u0195\u0001\u0000\u0000\u0000\u0197\u0198\u0001\u0000\u0000\u0000"+
		"\u0198/\u0001\u0000\u0000\u0000\u0199\u0197\u0001\u0000\u0000\u0000\u001a"+
		"9?Pcnz\u0088\u009b\u009d\u00a8\u00b3\u00bd\u00ca\u010a\u0112\u011c\u0126"+
		"\u0132\u013c\u0149\u0158\u015a\u0168\u0184\u018a\u0197";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}