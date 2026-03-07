
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



#include "C2105052Parser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct C2105052ParserStaticData final {
  C2105052ParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  C2105052ParserStaticData(const C2105052ParserStaticData&) = delete;
  C2105052ParserStaticData(C2105052ParserStaticData&&) = delete;
  C2105052ParserStaticData& operator=(const C2105052ParserStaticData&) = delete;
  C2105052ParserStaticData& operator=(C2105052ParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag c2105052parserParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
C2105052ParserStaticData *c2105052parserParserStaticData = nullptr;

void c2105052parserParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (c2105052parserParserStaticData != nullptr) {
    return;
  }
#else
  assert(c2105052parserParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<C2105052ParserStaticData>(
    std::vector<std::string>{
      "start", "program", "unit", "func_declaration", "func_definition", 
      "compound_statement", "var_declaration", "declaration_list", "declaration_list_err", 
      "type_specifier", "parameter_list", "statements", "statement", "expression_statement", 
      "variable", "expression", "logic_expression", "rel_expression", "simple_expression", 
      "term", "unary_expression", "factor", "argument_list", "arguments"
    },
    std::vector<std::string>{
      "", "", "", "", "", "'if'", "'else'", "'for'", "'while'", "'println'", 
      "'return'", "'int'", "'float'", "'void'", "'('", "')'", "'{'", "'}'", 
      "'['", "']'", "';'", "','", "", "", "", "'++'", "'--'", "'!'", "", 
      "", "'='", "", "", "", "'#'"
    },
    std::vector<std::string>{
      "", "LINE_COMMENT", "BLOCK_COMMENT", "STRING", "WS", "IF", "ELSE", 
      "FOR", "WHILE", "PRINTLN", "RETURN", "INT", "FLOAT", "VOID", "LPAREN", 
      "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "SEMICOLON", "COMMA", 
      "ADDOP", "SUBOP", "MULOP", "INCOP", "DECOP", "NOT", "RELOP", "LOGICOP", 
      "ASSIGNOP", "ID", "CONST_INT", "CONST_FLOAT", "UNRECOGNIZED"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,34,417,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,
  	1,60,8,1,10,1,12,1,63,9,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,74,
  	8,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,3,3,91,
  	8,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,
  	4,3,4,110,8,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,3,5,121,8,5,1,6,1,6,
  	1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,133,8,6,1,7,1,7,1,7,1,7,1,7,1,7,1,
  	7,1,7,1,7,1,7,1,7,1,7,3,7,147,8,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,
  	1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,5,7,166,8,7,10,7,12,7,169,9,7,1,8,1,8,
  	1,9,1,9,1,9,1,9,1,9,1,9,3,9,179,8,9,1,10,1,10,1,10,1,10,1,10,1,10,1,10,
  	1,10,1,10,3,10,190,8,10,1,10,1,10,1,10,1,10,1,10,1,10,5,10,198,8,10,10,
  	10,12,10,201,9,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,5,11,211,8,
  	11,10,11,12,11,214,9,11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,3,12,268,8,12,1,13,1,13,1,13,1,13,1,13,1,13,3,13,276,8,13,1,14,1,
  	14,1,14,1,14,1,14,1,14,1,14,1,14,3,14,286,8,14,1,15,1,15,1,15,1,15,1,
  	15,1,15,1,15,1,15,3,15,296,8,15,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,
  	16,3,16,306,8,16,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,3,17,316,8,17,
  	1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,
  	1,18,1,18,5,18,334,8,18,10,18,12,18,337,9,18,1,19,1,19,1,19,1,19,1,19,
  	1,19,1,19,1,19,1,19,1,19,1,19,1,19,5,19,351,8,19,10,19,12,19,354,9,19,
  	1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,3,20,367,8,20,
  	1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,
  	1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,3,21,395,
  	8,21,1,22,1,22,1,22,1,22,3,22,401,8,22,1,23,1,23,1,23,1,23,1,23,1,23,
  	1,23,1,23,1,23,5,23,412,8,23,10,23,12,23,415,9,23,1,23,0,7,2,14,20,22,
  	36,38,46,24,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,
  	42,44,46,0,0,436,0,48,1,0,0,0,2,51,1,0,0,0,4,73,1,0,0,0,6,90,1,0,0,0,
  	8,109,1,0,0,0,10,120,1,0,0,0,12,132,1,0,0,0,14,146,1,0,0,0,16,170,1,0,
  	0,0,18,178,1,0,0,0,20,189,1,0,0,0,22,202,1,0,0,0,24,267,1,0,0,0,26,275,
  	1,0,0,0,28,285,1,0,0,0,30,295,1,0,0,0,32,305,1,0,0,0,34,315,1,0,0,0,36,
  	317,1,0,0,0,38,338,1,0,0,0,40,366,1,0,0,0,42,394,1,0,0,0,44,400,1,0,0,
  	0,46,402,1,0,0,0,48,49,3,2,1,0,49,50,6,0,-1,0,50,1,1,0,0,0,51,52,6,1,
  	-1,0,52,53,3,4,2,0,53,54,6,1,-1,0,54,61,1,0,0,0,55,56,10,2,0,0,56,57,
  	3,4,2,0,57,58,6,1,-1,0,58,60,1,0,0,0,59,55,1,0,0,0,60,63,1,0,0,0,61,59,
  	1,0,0,0,61,62,1,0,0,0,62,3,1,0,0,0,63,61,1,0,0,0,64,65,3,12,6,0,65,66,
  	6,2,-1,0,66,74,1,0,0,0,67,68,3,6,3,0,68,69,6,2,-1,0,69,74,1,0,0,0,70,
  	71,3,8,4,0,71,72,6,2,-1,0,72,74,1,0,0,0,73,64,1,0,0,0,73,67,1,0,0,0,73,
  	70,1,0,0,0,74,5,1,0,0,0,75,76,3,18,9,0,76,77,5,31,0,0,77,78,5,14,0,0,
  	78,79,3,20,10,0,79,80,5,15,0,0,80,81,5,20,0,0,81,82,6,3,-1,0,82,91,1,
  	0,0,0,83,84,3,18,9,0,84,85,5,31,0,0,85,86,5,14,0,0,86,87,5,15,0,0,87,
  	88,5,20,0,0,88,89,6,3,-1,0,89,91,1,0,0,0,90,75,1,0,0,0,90,83,1,0,0,0,
  	91,7,1,0,0,0,92,93,3,18,9,0,93,94,5,31,0,0,94,95,5,14,0,0,95,96,3,20,
  	10,0,96,97,5,15,0,0,97,98,6,4,-1,0,98,99,3,10,5,0,99,100,6,4,-1,0,100,
  	110,1,0,0,0,101,102,3,18,9,0,102,103,5,31,0,0,103,104,5,14,0,0,104,105,
  	5,15,0,0,105,106,6,4,-1,0,106,107,3,10,5,0,107,108,6,4,-1,0,108,110,1,
  	0,0,0,109,92,1,0,0,0,109,101,1,0,0,0,110,9,1,0,0,0,111,112,5,16,0,0,112,
  	113,6,5,-1,0,113,114,3,22,11,0,114,115,5,17,0,0,115,116,6,5,-1,0,116,
  	121,1,0,0,0,117,118,5,16,0,0,118,119,5,17,0,0,119,121,6,5,-1,0,120,111,
  	1,0,0,0,120,117,1,0,0,0,121,11,1,0,0,0,122,123,3,18,9,0,123,124,3,14,
  	7,0,124,125,5,20,0,0,125,126,6,6,-1,0,126,133,1,0,0,0,127,128,3,18,9,
  	0,128,129,3,16,8,0,129,130,5,20,0,0,130,131,6,6,-1,0,131,133,1,0,0,0,
  	132,122,1,0,0,0,132,127,1,0,0,0,133,13,1,0,0,0,134,135,6,7,-1,0,135,136,
  	5,31,0,0,136,147,6,7,-1,0,137,138,5,31,0,0,138,139,5,18,0,0,139,140,5,
  	32,0,0,140,141,5,19,0,0,141,147,6,7,-1,0,142,143,5,31,0,0,143,144,5,22,
  	0,0,144,145,5,31,0,0,145,147,6,7,-1,0,146,134,1,0,0,0,146,137,1,0,0,0,
  	146,142,1,0,0,0,147,167,1,0,0,0,148,149,10,6,0,0,149,150,5,21,0,0,150,
  	151,5,31,0,0,151,166,6,7,-1,0,152,153,10,5,0,0,153,154,5,21,0,0,154,155,
  	5,31,0,0,155,156,5,18,0,0,156,157,5,32,0,0,157,158,5,19,0,0,158,166,6,
  	7,-1,0,159,160,10,1,0,0,160,161,5,21,0,0,161,162,5,31,0,0,162,163,5,22,
  	0,0,163,164,5,31,0,0,164,166,6,7,-1,0,165,148,1,0,0,0,165,152,1,0,0,0,
  	165,159,1,0,0,0,166,169,1,0,0,0,167,165,1,0,0,0,167,168,1,0,0,0,168,15,
  	1,0,0,0,169,167,1,0,0,0,170,171,6,8,-1,0,171,17,1,0,0,0,172,173,5,11,
  	0,0,173,179,6,9,-1,0,174,175,5,12,0,0,175,179,6,9,-1,0,176,177,5,13,0,
  	0,177,179,6,9,-1,0,178,172,1,0,0,0,178,174,1,0,0,0,178,176,1,0,0,0,179,
  	19,1,0,0,0,180,181,6,10,-1,0,181,182,3,18,9,0,182,183,5,31,0,0,183,184,
  	6,10,-1,0,184,190,1,0,0,0,185,186,3,18,9,0,186,187,5,22,0,0,187,188,6,
  	10,-1,0,188,190,1,0,0,0,189,180,1,0,0,0,189,185,1,0,0,0,190,199,1,0,0,
  	0,191,192,10,2,0,0,192,193,5,21,0,0,193,194,3,18,9,0,194,195,5,31,0,0,
  	195,196,6,10,-1,0,196,198,1,0,0,0,197,191,1,0,0,0,198,201,1,0,0,0,199,
  	197,1,0,0,0,199,200,1,0,0,0,200,21,1,0,0,0,201,199,1,0,0,0,202,203,6,
  	11,-1,0,203,204,3,24,12,0,204,205,6,11,-1,0,205,212,1,0,0,0,206,207,10,
  	1,0,0,207,208,3,24,12,0,208,209,6,11,-1,0,209,211,1,0,0,0,210,206,1,0,
  	0,0,211,214,1,0,0,0,212,210,1,0,0,0,212,213,1,0,0,0,213,23,1,0,0,0,214,
  	212,1,0,0,0,215,216,3,12,6,0,216,217,6,12,-1,0,217,268,1,0,0,0,218,219,
  	3,26,13,0,219,220,6,12,-1,0,220,268,1,0,0,0,221,222,3,10,5,0,222,223,
  	6,12,-1,0,223,268,1,0,0,0,224,225,5,7,0,0,225,226,5,14,0,0,226,227,3,
  	26,13,0,227,228,3,26,13,0,228,229,3,30,15,0,229,230,5,15,0,0,230,231,
  	3,24,12,0,231,232,6,12,-1,0,232,268,1,0,0,0,233,234,5,5,0,0,234,235,5,
  	14,0,0,235,236,3,30,15,0,236,237,5,15,0,0,237,238,3,24,12,0,238,239,6,
  	12,-1,0,239,268,1,0,0,0,240,241,5,5,0,0,241,242,5,14,0,0,242,243,3,30,
  	15,0,243,244,5,15,0,0,244,245,3,24,12,0,245,246,5,6,0,0,246,247,3,24,
  	12,0,247,248,6,12,-1,0,248,268,1,0,0,0,249,250,5,8,0,0,250,251,5,14,0,
  	0,251,252,3,30,15,0,252,253,5,15,0,0,253,254,3,24,12,0,254,255,6,12,-1,
  	0,255,268,1,0,0,0,256,257,5,9,0,0,257,258,5,14,0,0,258,259,5,31,0,0,259,
  	260,5,15,0,0,260,261,5,20,0,0,261,268,6,12,-1,0,262,263,5,10,0,0,263,
  	264,3,30,15,0,264,265,5,20,0,0,265,266,6,12,-1,0,266,268,1,0,0,0,267,
  	215,1,0,0,0,267,218,1,0,0,0,267,221,1,0,0,0,267,224,1,0,0,0,267,233,1,
  	0,0,0,267,240,1,0,0,0,267,249,1,0,0,0,267,256,1,0,0,0,267,262,1,0,0,0,
  	268,25,1,0,0,0,269,270,5,20,0,0,270,276,6,13,-1,0,271,272,3,30,15,0,272,
  	273,5,20,0,0,273,274,6,13,-1,0,274,276,1,0,0,0,275,269,1,0,0,0,275,271,
  	1,0,0,0,276,27,1,0,0,0,277,278,5,31,0,0,278,286,6,14,-1,0,279,280,5,31,
  	0,0,280,281,5,18,0,0,281,282,3,30,15,0,282,283,5,19,0,0,283,284,6,14,
  	-1,0,284,286,1,0,0,0,285,277,1,0,0,0,285,279,1,0,0,0,286,29,1,0,0,0,287,
  	288,3,32,16,0,288,289,6,15,-1,0,289,296,1,0,0,0,290,291,3,28,14,0,291,
  	292,5,30,0,0,292,293,3,32,16,0,293,294,6,15,-1,0,294,296,1,0,0,0,295,
  	287,1,0,0,0,295,290,1,0,0,0,296,31,1,0,0,0,297,298,3,34,17,0,298,299,
  	6,16,-1,0,299,306,1,0,0,0,300,301,3,34,17,0,301,302,5,29,0,0,302,303,
  	3,34,17,0,303,304,6,16,-1,0,304,306,1,0,0,0,305,297,1,0,0,0,305,300,1,
  	0,0,0,306,33,1,0,0,0,307,308,3,36,18,0,308,309,6,17,-1,0,309,316,1,0,
  	0,0,310,311,3,36,18,0,311,312,5,28,0,0,312,313,3,36,18,0,313,314,6,17,
  	-1,0,314,316,1,0,0,0,315,307,1,0,0,0,315,310,1,0,0,0,316,35,1,0,0,0,317,
  	318,6,18,-1,0,318,319,3,38,19,0,319,320,6,18,-1,0,320,335,1,0,0,0,321,
  	322,10,2,0,0,322,323,5,22,0,0,323,324,3,38,19,0,324,325,6,18,-1,0,325,
  	334,1,0,0,0,326,327,10,1,0,0,327,328,5,22,0,0,328,329,5,30,0,0,329,330,
  	6,18,-1,0,330,331,3,38,19,0,331,332,6,18,-1,0,332,334,1,0,0,0,333,321,
  	1,0,0,0,333,326,1,0,0,0,334,337,1,0,0,0,335,333,1,0,0,0,335,336,1,0,0,
  	0,336,37,1,0,0,0,337,335,1,0,0,0,338,339,6,19,-1,0,339,340,3,40,20,0,
  	340,341,6,19,-1,0,341,352,1,0,0,0,342,343,10,2,0,0,343,344,5,24,0,0,344,
  	345,3,40,20,0,345,346,6,19,-1,0,346,351,1,0,0,0,347,348,10,1,0,0,348,
  	349,5,34,0,0,349,351,6,19,-1,0,350,342,1,0,0,0,350,347,1,0,0,0,351,354,
  	1,0,0,0,352,350,1,0,0,0,352,353,1,0,0,0,353,39,1,0,0,0,354,352,1,0,0,
  	0,355,356,5,22,0,0,356,357,3,40,20,0,357,358,6,20,-1,0,358,367,1,0,0,
  	0,359,360,5,27,0,0,360,361,3,40,20,0,361,362,6,20,-1,0,362,367,1,0,0,
  	0,363,364,3,42,21,0,364,365,6,20,-1,0,365,367,1,0,0,0,366,355,1,0,0,0,
  	366,359,1,0,0,0,366,363,1,0,0,0,367,41,1,0,0,0,368,369,3,28,14,0,369,
  	370,6,21,-1,0,370,395,1,0,0,0,371,372,5,31,0,0,372,373,5,14,0,0,373,374,
  	3,44,22,0,374,375,5,15,0,0,375,376,6,21,-1,0,376,395,1,0,0,0,377,378,
  	5,14,0,0,378,379,3,30,15,0,379,380,5,15,0,0,380,381,6,21,-1,0,381,395,
  	1,0,0,0,382,383,5,32,0,0,383,395,6,21,-1,0,384,385,5,33,0,0,385,395,6,
  	21,-1,0,386,387,3,28,14,0,387,388,5,25,0,0,388,389,6,21,-1,0,389,395,
  	1,0,0,0,390,391,3,28,14,0,391,392,5,26,0,0,392,393,6,21,-1,0,393,395,
  	1,0,0,0,394,368,1,0,0,0,394,371,1,0,0,0,394,377,1,0,0,0,394,382,1,0,0,
  	0,394,384,1,0,0,0,394,386,1,0,0,0,394,390,1,0,0,0,395,43,1,0,0,0,396,
  	397,3,46,23,0,397,398,6,22,-1,0,398,401,1,0,0,0,399,401,1,0,0,0,400,396,
  	1,0,0,0,400,399,1,0,0,0,401,45,1,0,0,0,402,403,6,23,-1,0,403,404,3,32,
  	16,0,404,405,6,23,-1,0,405,413,1,0,0,0,406,407,10,2,0,0,407,408,5,21,
  	0,0,408,409,3,32,16,0,409,410,6,23,-1,0,410,412,1,0,0,0,411,406,1,0,0,
  	0,412,415,1,0,0,0,413,411,1,0,0,0,413,414,1,0,0,0,414,47,1,0,0,0,415,
  	413,1,0,0,0,27,61,73,90,109,120,132,146,165,167,178,189,199,212,267,275,
  	285,295,305,315,333,335,350,352,366,394,400,413
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  c2105052parserParserStaticData = staticData.release();
}

}

C2105052Parser::C2105052Parser(TokenStream *input) : C2105052Parser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

C2105052Parser::C2105052Parser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  C2105052Parser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *c2105052parserParserStaticData->atn, c2105052parserParserStaticData->decisionToDFA, c2105052parserParserStaticData->sharedContextCache, options);
}

C2105052Parser::~C2105052Parser() {
  delete _interpreter;
}

const atn::ATN& C2105052Parser::getATN() const {
  return *c2105052parserParserStaticData->atn;
}

std::string C2105052Parser::getGrammarFileName() const {
  return "C2105052Parser.g4";
}

const std::vector<std::string>& C2105052Parser::getRuleNames() const {
  return c2105052parserParserStaticData->ruleNames;
}

const dfa::Vocabulary& C2105052Parser::getVocabulary() const {
  return c2105052parserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView C2105052Parser::getSerializedATN() const {
  return c2105052parserParserStaticData->serializedATN;
}


//----------------- StartContext ------------------------------------------------------------------

C2105052Parser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105052Parser::ProgramContext* C2105052Parser::StartContext::program() {
  return getRuleContext<C2105052Parser::ProgramContext>(0);
}


size_t C2105052Parser::StartContext::getRuleIndex() const {
  return C2105052Parser::RuleStart;
}


C2105052Parser::StartContext* C2105052Parser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, C2105052Parser::RuleStart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(48);
    antlrcpp::downCast<StartContext *>(_localctx)->p = program(0);

              writeIntoparserLogFile("Line " + std::to_string( antlrcpp::downCast<StartContext *>(_localctx)->p->line) + ": start : program\n");
              // Print the complete symbol table
              std::streambuf *oldCout3 = std::cout.rdbuf(parserLogFile.rdbuf());
              symbolTable->print_all_scope_in_file(parserLogFile);
              writeIntoparserLogFile("");
              writeIntoparserLogFile("Total number of lines: " + std::to_string(antlrcpp::downCast<StartContext *>(_localctx)->p->line));
                writeIntoparserLogFile("Total number of errors: " + std::to_string(syntaxErrorCount));        
              std::cout.rdbuf(oldCout3);
          
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramContext ------------------------------------------------------------------

C2105052Parser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105052Parser::UnitContext* C2105052Parser::ProgramContext::unit() {
  return getRuleContext<C2105052Parser::UnitContext>(0);
}

C2105052Parser::ProgramContext* C2105052Parser::ProgramContext::program() {
  return getRuleContext<C2105052Parser::ProgramContext>(0);
}


size_t C2105052Parser::ProgramContext::getRuleIndex() const {
  return C2105052Parser::RuleProgram;
}



C2105052Parser::ProgramContext* C2105052Parser::program() {
   return program(0);
}

C2105052Parser::ProgramContext* C2105052Parser::program(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105052Parser::ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, parentState);
  C2105052Parser::ProgramContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, C2105052Parser::RuleProgram, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(52);
    antlrcpp::downCast<ProgramContext *>(_localctx)->u = unit();

            writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<ProgramContext *>(_localctx)->u->line) + ": program : unit\n");
            antlrcpp::downCast<ProgramContext *>(_localctx)->code =  std::vector<std::string>();
            for (const auto &line : antlrcpp::downCast<ProgramContext *>(_localctx)->u->unit_code) {
                _localctx->code.push_back(line);
                writeIntoparserLogFile(line);
            }
            antlrcpp::downCast<ProgramContext *>(_localctx)->line =  antlrcpp::downCast<ProgramContext *>(_localctx)->u->line;
            writeIntoparserLogFile("");
        
    _ctx->stop = _input->LT(-1);
    setState(61);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ProgramContext>(parentContext, parentState);
        _localctx->p = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleProgram);
        setState(55);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(56);
        antlrcpp::downCast<ProgramContext *>(_localctx)->u = unit();

                          writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<ProgramContext *>(_localctx)->u->line) + ": program : program unit\n");
                          antlrcpp::downCast<ProgramContext *>(_localctx)->code =  antlrcpp::downCast<ProgramContext *>(_localctx)->p->code;
                          for (const auto &line : antlrcpp::downCast<ProgramContext *>(_localctx)->u->unit_code) {
                              _localctx->code.push_back(line);
                          }
                          for (const auto &line : _localctx->code) {
                              writeIntoparserLogFile(line);
                          }
                          writeIntoparserLogFile("");
                          antlrcpp::downCast<ProgramContext *>(_localctx)->line =  antlrcpp::downCast<ProgramContext *>(_localctx)->u->line;
                       
      }
      setState(63);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- UnitContext ------------------------------------------------------------------

C2105052Parser::UnitContext::UnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105052Parser::Var_declarationContext* C2105052Parser::UnitContext::var_declaration() {
  return getRuleContext<C2105052Parser::Var_declarationContext>(0);
}

C2105052Parser::Func_declarationContext* C2105052Parser::UnitContext::func_declaration() {
  return getRuleContext<C2105052Parser::Func_declarationContext>(0);
}

C2105052Parser::Func_definitionContext* C2105052Parser::UnitContext::func_definition() {
  return getRuleContext<C2105052Parser::Func_definitionContext>(0);
}


size_t C2105052Parser::UnitContext::getRuleIndex() const {
  return C2105052Parser::RuleUnit;
}


C2105052Parser::UnitContext* C2105052Parser::unit() {
  UnitContext *_localctx = _tracker.createInstance<UnitContext>(_ctx, getState());
  enterRule(_localctx, 4, C2105052Parser::RuleUnit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(73);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(64);
      antlrcpp::downCast<UnitContext *>(_localctx)->v = var_declaration();

              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<UnitContext *>(_localctx)->v->line) + ": unit : var_declaration\n");
              writeIntoparserLogFile(antlrcpp::downCast<UnitContext *>(_localctx)->v->txt+ "\n"); 
              antlrcpp::downCast<UnitContext *>(_localctx)->unit_code =  std::vector<string>();
              _localctx->unit_code.push_back(antlrcpp::downCast<UnitContext *>(_localctx)->v->txt);
              antlrcpp::downCast<UnitContext *>(_localctx)->line =  antlrcpp::downCast<UnitContext *>(_localctx)->v->line;
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(67);
      antlrcpp::downCast<UnitContext *>(_localctx)->f = func_declaration();

              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<UnitContext *>(_localctx)->f->line) + ": unit : func_declaration\n");
              writeIntoparserLogFile(antlrcpp::downCast<UnitContext *>(_localctx)->f->func_def + "\n");
              antlrcpp::downCast<UnitContext *>(_localctx)->unit_code =  std::vector<string>();
              _localctx->unit_code.push_back(antlrcpp::downCast<UnitContext *>(_localctx)->f->func_def);
              antlrcpp::downCast<UnitContext *>(_localctx)->line =  antlrcpp::downCast<UnitContext *>(_localctx)->f->line;
          
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(70);
      antlrcpp::downCast<UnitContext *>(_localctx)->f_def = func_definition();
       
              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<UnitContext *>(_localctx)->f_def->line) + ": unit : func_definition\n");
              antlrcpp::downCast<UnitContext *>(_localctx)->unit_code =  std::vector<string>();
              for (const auto &line : antlrcpp::downCast<UnitContext *>(_localctx)->f_def->code) {
                  writeIntoparserLogFile(line);
                  _localctx->unit_code.push_back(line);
              }
              writeIntoparserLogFile("");
              
              antlrcpp::downCast<UnitContext *>(_localctx)->line =  antlrcpp::downCast<UnitContext *>(_localctx)->f_def->line;
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_declarationContext ------------------------------------------------------------------

C2105052Parser::Func_declarationContext::Func_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105052Parser::Func_declarationContext::LPAREN() {
  return getToken(C2105052Parser::LPAREN, 0);
}

tree::TerminalNode* C2105052Parser::Func_declarationContext::RPAREN() {
  return getToken(C2105052Parser::RPAREN, 0);
}

tree::TerminalNode* C2105052Parser::Func_declarationContext::SEMICOLON() {
  return getToken(C2105052Parser::SEMICOLON, 0);
}

C2105052Parser::Type_specifierContext* C2105052Parser::Func_declarationContext::type_specifier() {
  return getRuleContext<C2105052Parser::Type_specifierContext>(0);
}

tree::TerminalNode* C2105052Parser::Func_declarationContext::ID() {
  return getToken(C2105052Parser::ID, 0);
}

C2105052Parser::Parameter_listContext* C2105052Parser::Func_declarationContext::parameter_list() {
  return getRuleContext<C2105052Parser::Parameter_listContext>(0);
}


size_t C2105052Parser::Func_declarationContext::getRuleIndex() const {
  return C2105052Parser::RuleFunc_declaration;
}


C2105052Parser::Func_declarationContext* C2105052Parser::func_declaration() {
  Func_declarationContext *_localctx = _tracker.createInstance<Func_declarationContext>(_ctx, getState());
  enterRule(_localctx, 6, C2105052Parser::RuleFunc_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(90);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(75);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->t = type_specifier();
      setState(76);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->id = match(C2105052Parser::ID);
      setState(77);
      match(C2105052Parser::LPAREN);
      setState(78);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->pl = parameter_list(0);
      setState(79);
      match(C2105052Parser::RPAREN);
      setState(80);
      match(C2105052Parser::SEMICOLON);

                // Function declaration insertion
                std::string funcName = antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getText();
                std::string funcType = antlrcpp::downCast<Func_declarationContext *>(_localctx)->t->txt;
              
                writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getLine()) + ": func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n");
                string str = funcType + " " + funcName + "(";
                  for (size_t i = 0; i < antlrcpp::downCast<Func_declarationContext *>(_localctx)->pl->params.size(); ++i) {
                      str += antlrcpp::downCast<Func_declarationContext *>(_localctx)->pl->params[i].first + " " + antlrcpp::downCast<Func_declarationContext *>(_localctx)->pl->params[i].second;
                      if (i < antlrcpp::downCast<Func_declarationContext *>(_localctx)->pl->params.size() - 1) {
                          str += ",";
                      }
                  }
                  str += ");";
                  antlrcpp::downCast<Func_declarationContext *>(_localctx)->func_def =  str;
                  antlrcpp::downCast<Func_declarationContext *>(_localctx)->line =  antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getLine();
                writeIntoparserLogFile(str + "\n");
                insertFunctionToSymbolTable(funcName, funcType, antlrcpp::downCast<Func_declarationContext *>(_localctx)->pl->params, antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getLine());
            
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(83);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->t = type_specifier();
      setState(84);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->id = match(C2105052Parser::ID);
      setState(85);
      match(C2105052Parser::LPAREN);
      setState(86);
      match(C2105052Parser::RPAREN);
      setState(87);
      match(C2105052Parser::SEMICOLON);

                // Function declaration (no parameters)
                std::string funcName = antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getText();
                std::string funcType = antlrcpp::downCast<Func_declarationContext *>(_localctx)->t->txt;
                SymbolInfo *existing2 = symbolTable->look_up(funcName);
                  writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getLine()) + ": func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n");
                  string str2 = funcType + " " + funcName + "();";
                  antlrcpp::downCast<Func_declarationContext *>(_localctx)->func_def =  str2;
                  antlrcpp::downCast<Func_declarationContext *>(_localctx)->line =  antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getLine();
                  writeIntoparserLogFile(str2 + "\n");
                  insertFunctionToSymbolTable(funcName, funcType, vector<pair<string,string>>(), antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getLine());

            
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_definitionContext ------------------------------------------------------------------

C2105052Parser::Func_definitionContext::Func_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105052Parser::Func_definitionContext::LPAREN() {
  return getToken(C2105052Parser::LPAREN, 0);
}

tree::TerminalNode* C2105052Parser::Func_definitionContext::RPAREN() {
  return getToken(C2105052Parser::RPAREN, 0);
}

C2105052Parser::Type_specifierContext* C2105052Parser::Func_definitionContext::type_specifier() {
  return getRuleContext<C2105052Parser::Type_specifierContext>(0);
}

tree::TerminalNode* C2105052Parser::Func_definitionContext::ID() {
  return getToken(C2105052Parser::ID, 0);
}

C2105052Parser::Parameter_listContext* C2105052Parser::Func_definitionContext::parameter_list() {
  return getRuleContext<C2105052Parser::Parameter_listContext>(0);
}

C2105052Parser::Compound_statementContext* C2105052Parser::Func_definitionContext::compound_statement() {
  return getRuleContext<C2105052Parser::Compound_statementContext>(0);
}


size_t C2105052Parser::Func_definitionContext::getRuleIndex() const {
  return C2105052Parser::RuleFunc_definition;
}


C2105052Parser::Func_definitionContext* C2105052Parser::func_definition() {
  Func_definitionContext *_localctx = _tracker.createInstance<Func_definitionContext>(_ctx, getState());
  enterRule(_localctx, 8, C2105052Parser::RuleFunc_definition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(109);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(92);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->t = type_specifier();
      setState(93);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->id = match(C2105052Parser::ID);
      setState(94);
      match(C2105052Parser::LPAREN);
      setState(95);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl = parameter_list(0);
      setState(96);
      match(C2105052Parser::RPAREN);

               insertFunctionToSymbolTable(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText(), antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->txt, antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl->params, antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getLine());
               for (const auto &param : antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl->params) {
                  std::string paramName = param.second;
                  std::string paramType = param.first;
                  // cout<<"paramName: "<<paramName<<endl;
                  // cout<<"paramType: "<<paramType<<endl;
                  // if(paramName=="")
                      // cout<<"paramName is empty"<<endl;
                  //symbolTable->insert(new SymbolInfo(paramName, paramType));
               }

            
      setState(98);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->c = antlrcpp::downCast<Func_definitionContext *>(_localctx)->compound_statementContext = compound_statement(antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl->params);

              antlrcpp::downCast<Func_definitionContext *>(_localctx)->code =  vector<string>();
               voidFuncRetTypeCheck(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText(), antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->txt, antlrcpp::downCast<Func_definitionContext *>(_localctx)->c->code, antlrcpp::downCast<Func_definitionContext *>(_localctx)->c->line);
               writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->c->line) + ": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n");
                std::string funcName = antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText();
                std::string funcType =antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->txt;
                string str = funcType + " " + funcName + "(";
                  for (size_t i = 0; i < antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl->params.size(); ++i){
                      str += antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl->params[i].first;
                      if(antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl->params[i].second!="")
                          str +=" "+ antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl->params[i].second;
                      
                      if (i < antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl->params.size() - 1) {
                          str += ",";
                      }
                  }
                  str += ")";
                  for (const auto &line : antlrcpp::downCast<Func_definitionContext *>(_localctx)->compound_statementContext->code) {
                      str += line;
                      _localctx->code.push_back(str);
                      writeIntoparserLogFile(str);
                      str = "";
                  }
                  writeIntoparserLogFile("");
                  antlrcpp::downCast<Func_definitionContext *>(_localctx)->line =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->c->line;

            
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(101);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->t = type_specifier();
      setState(102);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->id = match(C2105052Parser::ID);
      setState(103);
      match(C2105052Parser::LPAREN);
      setState(104);
      match(C2105052Parser::RPAREN);

                // Function definition (no parameters)
                std::string funcName = antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText();
                std::string funcType = antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->txt;
                SymbolInfo *existing2 = symbolTable->look_up(funcName);
                  insertFunctionToSymbolTable(funcName, funcType, vector<pair<string,string>>(), antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getLine());
            
      setState(106);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs = compound_statement(vector<pair<string,string>>());

              antlrcpp::downCast<Func_definitionContext *>(_localctx)->code =  vector<string>();
              voidFuncRetTypeCheck(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText(), antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->txt, antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->code, antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->line);
              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->line) + ": func_definition : type_specifier ID LPAREN RPAREN compound_statement\n");
              funcName = antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText();
               funcType = antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->txt;
              string str = funcType + " " + funcName + "()";
              for (const auto &line : antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->code) {
                  str+=line;
                  _localctx->code.push_back(str);
                  writeIntoparserLogFile(str);
                  str="";
              }
              writeIntoparserLogFile("");
              

              antlrcpp::downCast<Func_definitionContext *>(_localctx)->line =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->line;
            
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Compound_statementContext ------------------------------------------------------------------

C2105052Parser::Compound_statementContext::Compound_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105052Parser::Compound_statementContext::Compound_statementContext(ParserRuleContext *parent, size_t invokingState, vector<pair<string,string>> params)
  : ParserRuleContext(parent, invokingState) {
  this->params = params;
}

tree::TerminalNode* C2105052Parser::Compound_statementContext::LCURL() {
  return getToken(C2105052Parser::LCURL, 0);
}

tree::TerminalNode* C2105052Parser::Compound_statementContext::RCURL() {
  return getToken(C2105052Parser::RCURL, 0);
}

C2105052Parser::StatementsContext* C2105052Parser::Compound_statementContext::statements() {
  return getRuleContext<C2105052Parser::StatementsContext>(0);
}


size_t C2105052Parser::Compound_statementContext::getRuleIndex() const {
  return C2105052Parser::RuleCompound_statement;
}


C2105052Parser::Compound_statementContext* C2105052Parser::compound_statement(vector<pair<string,string>> params) {
  Compound_statementContext *_localctx = _tracker.createInstance<Compound_statementContext>(_ctx, getState(), params);
  enterRule(_localctx, 10, C2105052Parser::RuleCompound_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(120);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(111);
      match(C2105052Parser::LCURL);

                      symbolTable->enter_scope();
                      for (const auto &param : params) {
                          string paramName = param.second;
                          string paramType = param.first;
                          // cout<<"paramName: "<<paramName<<endl;
                          // cout<<"paramType: "<<paramType<<endl;
                          if(paramName!="")
                          symbolTable->insert(new SymbolInfo(paramName, paramType));
                          // else cout<<"paramName is empsdfty"<<endl;
                      }
                  
                  
      setState(113);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->st = statements(0);
      setState(114);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken = match(C2105052Parser::RCURL);

                  writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken->getLine()) + ": compound_statement : LCURL statements RCURL\n");
                  antlrcpp::downCast<Compound_statementContext *>(_localctx)->code =  vector<string>();
                  _localctx->code.push_back("{");
                  writeIntoparserLogFile("{");
                  int te=0;
                  for (const auto &line : antlrcpp::downCast<Compound_statementContext *>(_localctx)->st->code) {
                      writeIntoparserLogFile(line);
                      te++;
                      _localctx->code.push_back(line);
                  }
                  _localctx->code.push_back("}");
                  // cout<<te<<endl;
                  string str = "}\n";
                  writeIntoparserLogFile(str);
                  symbolTable->print_all_scope_in_file(parserLogFile);
                  writeIntoparserLogFile("");
                  symbolTable->exit_scope();
                
                  antlrcpp::downCast<Compound_statementContext *>(_localctx)->line =  antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken->getLine();
                  
              
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(117);
      match(C2105052Parser::LCURL);
      setState(118);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken = match(C2105052Parser::RCURL);

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
                  writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken->getLine()) + ": compound_statement : LCURL RCURL\n");
                  antlrcpp::downCast<Compound_statementContext *>(_localctx)->code =  vector<string>();
                  _localctx->code.push_back("{}");
                  writeIntoparserLogFile("{}\n");
                  symbolTable->print_all_scope_in_file(parserLogFile);
                  writeIntoparserLogFile("");
                  symbolTable->exit_scope();
                  antlrcpp::downCast<Compound_statementContext *>(_localctx)->line =  antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken->getLine();
                  
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_declarationContext ------------------------------------------------------------------

C2105052Parser::Var_declarationContext::Var_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105052Parser::Type_specifierContext* C2105052Parser::Var_declarationContext::type_specifier() {
  return getRuleContext<C2105052Parser::Type_specifierContext>(0);
}

C2105052Parser::Declaration_listContext* C2105052Parser::Var_declarationContext::declaration_list() {
  return getRuleContext<C2105052Parser::Declaration_listContext>(0);
}

tree::TerminalNode* C2105052Parser::Var_declarationContext::SEMICOLON() {
  return getToken(C2105052Parser::SEMICOLON, 0);
}

C2105052Parser::Declaration_list_errContext* C2105052Parser::Var_declarationContext::declaration_list_err() {
  return getRuleContext<C2105052Parser::Declaration_list_errContext>(0);
}


size_t C2105052Parser::Var_declarationContext::getRuleIndex() const {
  return C2105052Parser::RuleVar_declaration;
}


C2105052Parser::Var_declarationContext* C2105052Parser::var_declaration() {
  Var_declarationContext *_localctx = _tracker.createInstance<Var_declarationContext>(_ctx, getState());
  enterRule(_localctx, 12, C2105052Parser::RuleVar_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(132);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(122);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->t = type_specifier();
      setState(123);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl = declaration_list(0);
      setState(124);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm = match(C2105052Parser::SEMICOLON);

                  // cout<<"Declaration list size: "<<antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl->nameList.size()<<endl;
                  writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getLine()) + ": var_declaration : type_specifier declaration_list SEMICOLON\n");
                  string txt = antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->txt;
                  txt += " ";
                  for (const auto &name : antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl->nameList) {
                      txt += name;
                      string str;
                      bool isArray = false;
                      for(int i=0;i<name.size();i++) {if(name[i]!='[') {str+=name[i];} else {isArray = true;break;}}
                      string type = antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->txt;
                      if(isArray) {
                          type += "_array";
                      }
                      
                      SymbolInfo *s = symbolTable->look_up(str);
                      if(s->getType()== "ID")
                          s->setType(type);
                      if (&name != &(antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl->nameList.back())) {
                          txt += ",";
                      }
                  }
                  txt+=";";
                  // cout<<"Declaraction list size: "<<antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl->nameList.size()<<endl;
                  if(antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->type == "VOID") {
                      writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getLine()) + ": Variable type cannot be void\n");
                      syntaxErrorCount++;
                      writeIntoparserLogFile("Error at line " + std::to_string(antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getLine()) + ": Variable type cannot be void\n");
                  }

                  writeIntoparserLogFile(txt + "\n");
                  antlrcpp::downCast<Var_declarationContext *>(_localctx)->txt =  txt;
                  antlrcpp::downCast<Var_declarationContext *>(_localctx)->line =  antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getLine();
              
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(127);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->t = type_specifier();
      setState(128);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->de = declaration_list_err();
      setState(129);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm = match(C2105052Parser::SEMICOLON);

                writeIntoErrorFile(
                    std::string("Line# ") + std::to_string(antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getLine()) +
                    " with error name: " + antlrcpp::downCast<Var_declarationContext *>(_localctx)->de->error_name +
                    " - Syntax error at declaration list of variable declaration"
                );
                syntaxErrorCount++;
            
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Declaration_listContext ------------------------------------------------------------------

C2105052Parser::Declaration_listContext::Declaration_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> C2105052Parser::Declaration_listContext::ID() {
  return getTokens(C2105052Parser::ID);
}

tree::TerminalNode* C2105052Parser::Declaration_listContext::ID(size_t i) {
  return getToken(C2105052Parser::ID, i);
}

tree::TerminalNode* C2105052Parser::Declaration_listContext::LTHIRD() {
  return getToken(C2105052Parser::LTHIRD, 0);
}

tree::TerminalNode* C2105052Parser::Declaration_listContext::CONST_INT() {
  return getToken(C2105052Parser::CONST_INT, 0);
}

tree::TerminalNode* C2105052Parser::Declaration_listContext::RTHIRD() {
  return getToken(C2105052Parser::RTHIRD, 0);
}

tree::TerminalNode* C2105052Parser::Declaration_listContext::ADDOP() {
  return getToken(C2105052Parser::ADDOP, 0);
}

tree::TerminalNode* C2105052Parser::Declaration_listContext::COMMA() {
  return getToken(C2105052Parser::COMMA, 0);
}

C2105052Parser::Declaration_listContext* C2105052Parser::Declaration_listContext::declaration_list() {
  return getRuleContext<C2105052Parser::Declaration_listContext>(0);
}


size_t C2105052Parser::Declaration_listContext::getRuleIndex() const {
  return C2105052Parser::RuleDeclaration_list;
}



C2105052Parser::Declaration_listContext* C2105052Parser::declaration_list() {
   return declaration_list(0);
}

C2105052Parser::Declaration_listContext* C2105052Parser::declaration_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105052Parser::Declaration_listContext *_localctx = _tracker.createInstance<Declaration_listContext>(_ctx, parentState);
  C2105052Parser::Declaration_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 14;
  enterRecursionRule(_localctx, 14, C2105052Parser::RuleDeclaration_list, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(146);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      setState(135);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C2105052Parser::ID);

                antlrcpp::downCast<Declaration_listContext *>(_localctx)->nameList =  std::vector<std::string>();
                _localctx->nameList.push_back(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText());
                  insertIdInSymbolTable(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText(), "ID", antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine());
                  writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine()) + ": declaration_list : ID\n");
                  writeIntoparserLogFile(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText()+ "\n");
            
      break;
    }

    case 2: {
      setState(137);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C2105052Parser::ID);
      setState(138);
      match(C2105052Parser::LTHIRD);
      setState(139);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken = match(C2105052Parser::CONST_INT);
      setState(140);
      match(C2105052Parser::RTHIRD);

                antlrcpp::downCast<Declaration_listContext *>(_localctx)->nameList =  std::vector<std::string>();
                _localctx->nameList.push_back(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText() + "[" + antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken->getText() + "]");
                  insertIdInSymbolTable(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText(), "ID", antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine());
                  writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine()) + ": declaration_list : ID LTHIRD CONST_INT RTHIRD\n");
                  writeIntoparserLogFile(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText() + "[" + antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken->getText() + "]\n");
            
      break;
    }

    case 3: {
      setState(142);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->first = match(C2105052Parser::ID);
      setState(143);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->op = match(C2105052Parser::ADDOP);
      setState(144);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->second = match(C2105052Parser::ID);

                  writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->op->getLine()) + ": declaration_list : ID\n");
                  writeIntoparserLogFile(antlrcpp::downCast<Declaration_listContext *>(_localctx)->first->getText()+"\n");
                  insertIdInSymbolTable(antlrcpp::downCast<Declaration_listContext *>(_localctx)->first->getText(), "ID", antlrcpp::downCast<Declaration_listContext *>(_localctx)->first->getLine());
                  writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->op->getLine()) + ": syntax error, unexpected ADDOP, expecting COMMA or SEMICOLON\n");
                  syntaxErrorCount++;
                  writeIntoparserLogFile("Error at line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->op->getLine()) + ": syntax error, unexpected ADDOP, expecting COMMA or SEMICOLON\n");
                  antlrcpp::downCast<Declaration_listContext *>(_localctx)->nameList =  std::vector<std::string>();
                   _localctx->nameList.push_back(antlrcpp::downCast<Declaration_listContext *>(_localctx)->first->getText());
            
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(167);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(165);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(148);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(149);
          match(C2105052Parser::COMMA);
          setState(150);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C2105052Parser::ID);

                              antlrcpp::downCast<Declaration_listContext *>(_localctx)->nameList =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->nameList;
                              _localctx->nameList.push_back(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText());
                                insertIdInSymbolTable(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText(), "ID", antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine());
                              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine()) + ": declaration_list : declaration_list COMMA ID\n");
                                string str ;
                                for (const auto &name : _localctx->nameList) {
                                   str+= name;
                                   if (&name != &(_localctx->nameList.back())) {
                                       str += ",";
                                   }
                                }
                                writeIntoparserLogFile(str + "\n");
                          
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(152);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(153);
          match(C2105052Parser::COMMA);
          setState(154);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C2105052Parser::ID);
          setState(155);
          match(C2105052Parser::LTHIRD);
          setState(156);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken = match(C2105052Parser::CONST_INT);
          setState(157);
          match(C2105052Parser::RTHIRD);

                              antlrcpp::downCast<Declaration_listContext *>(_localctx)->nameList =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->nameList;
                              insertIdInSymbolTable(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText(), "ID", antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine());
                              string str = antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText() + "[" + antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken->getText() + "]";
                              _localctx->nameList.push_back(str);
                              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine()) + ": declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n");
                                string str2;
                                for (const auto &name : _localctx->nameList) {
                                    str2 += name;
                                    if (&name != &(_localctx->nameList.back())) {
                                        str2 += ",";
                                    }
                                }
                                writeIntoparserLogFile(str2 + "\n");
                          
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->pl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(159);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(160);
          match(C2105052Parser::COMMA);
          setState(161);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C2105052Parser::ID);
          setState(162);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->addopToken = match(C2105052Parser::ADDOP);
          setState(163);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C2105052Parser::ID);

                                // This is an error case, where ADDOP is used incorrectly
                                writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->addopToken->getLine()) + ": syntax error, unexpected ADDOP, expecting COMMA or RTHIRD\n");
                                syntaxErrorCount++;
                                writeIntoparserLogFile("Error at line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->addopToken->getLine()) + ": syntax error, unexpected ADDOP, expecting COMMA or RTHIRD\n");
                                antlrcpp::downCast<Declaration_listContext *>(_localctx)->nameList =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->pl->nameList;
                                // cout<<"Matched with declaration_list COMMA ID ADDOP ID"<<endl;
                                _localctx->nameList.push_back(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText());
                          
          break;
        }

        default:
          break;
        } 
      }
      setState(169);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Declaration_list_errContext ------------------------------------------------------------------

C2105052Parser::Declaration_list_errContext::Declaration_list_errContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t C2105052Parser::Declaration_list_errContext::getRuleIndex() const {
  return C2105052Parser::RuleDeclaration_list_err;
}


C2105052Parser::Declaration_list_errContext* C2105052Parser::declaration_list_err() {
  Declaration_list_errContext *_localctx = _tracker.createInstance<Declaration_list_errContext>(_ctx, getState());
  enterRule(_localctx, 16, C2105052Parser::RuleDeclaration_list_err);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

        antlrcpp::downCast<Declaration_list_errContext *>(_localctx)->error_name =  "Error in declaration list";

   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_specifierContext ------------------------------------------------------------------

C2105052Parser::Type_specifierContext::Type_specifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105052Parser::Type_specifierContext::INT() {
  return getToken(C2105052Parser::INT, 0);
}

tree::TerminalNode* C2105052Parser::Type_specifierContext::FLOAT() {
  return getToken(C2105052Parser::FLOAT, 0);
}

tree::TerminalNode* C2105052Parser::Type_specifierContext::VOID() {
  return getToken(C2105052Parser::VOID, 0);
}


size_t C2105052Parser::Type_specifierContext::getRuleIndex() const {
  return C2105052Parser::RuleType_specifier;
}


C2105052Parser::Type_specifierContext* C2105052Parser::type_specifier() {
  Type_specifierContext *_localctx = _tracker.createInstance<Type_specifierContext>(_ctx, getState());
  enterRule(_localctx, 18, C2105052Parser::RuleType_specifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(178);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C2105052Parser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(172);
        antlrcpp::downCast<Type_specifierContext *>(_localctx)->intToken = match(C2105052Parser::INT);
         
                // cout<<"INT at"<<antlrcpp::downCast<Type_specifierContext *>(_localctx)->intToken->getLine()<<endl;
               antlrcpp::downCast<Type_specifierContext *>(_localctx)->txt =  antlrcpp::downCast<Type_specifierContext *>(_localctx)->intToken->getText();
                 antlrcpp::downCast<Type_specifierContext *>(_localctx)->type =  "INT";
               writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Type_specifierContext *>(_localctx)->intToken->getLine()) + ": type_specifier : INT\n");
               writeIntoparserLogFile(antlrcpp::downCast<Type_specifierContext *>(_localctx)->intToken->getText() + "\n");
            
        break;
      }

      case C2105052Parser::FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(174);
        antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken = match(C2105052Parser::FLOAT);

                    antlrcpp::downCast<Type_specifierContext *>(_localctx)->txt =  antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken->getText();
                    antlrcpp::downCast<Type_specifierContext *>(_localctx)->type =  "FLOAT";
                 writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken->getLine()) + ": type_specifier : FLOAT\n");
                    writeIntoparserLogFile(antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken->getText() + "\n");
             
        break;
      }

      case C2105052Parser::VOID: {
        enterOuterAlt(_localctx, 3);
        setState(176);
        antlrcpp::downCast<Type_specifierContext *>(_localctx)->voidToken = match(C2105052Parser::VOID);
         
                    antlrcpp::downCast<Type_specifierContext *>(_localctx)->txt =  antlrcpp::downCast<Type_specifierContext *>(_localctx)->voidToken->getText();
                    antlrcpp::downCast<Type_specifierContext *>(_localctx)->type =  "VOID";
                 writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Type_specifierContext *>(_localctx)->voidToken->getLine()) + ": type_specifier : VOID\n");
                    writeIntoparserLogFile(antlrcpp::downCast<Type_specifierContext *>(_localctx)->voidToken->getText() + "\n");
              
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parameter_listContext ------------------------------------------------------------------

C2105052Parser::Parameter_listContext::Parameter_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105052Parser::Type_specifierContext* C2105052Parser::Parameter_listContext::type_specifier() {
  return getRuleContext<C2105052Parser::Type_specifierContext>(0);
}

tree::TerminalNode* C2105052Parser::Parameter_listContext::ID() {
  return getToken(C2105052Parser::ID, 0);
}

tree::TerminalNode* C2105052Parser::Parameter_listContext::ADDOP() {
  return getToken(C2105052Parser::ADDOP, 0);
}

tree::TerminalNode* C2105052Parser::Parameter_listContext::COMMA() {
  return getToken(C2105052Parser::COMMA, 0);
}

C2105052Parser::Parameter_listContext* C2105052Parser::Parameter_listContext::parameter_list() {
  return getRuleContext<C2105052Parser::Parameter_listContext>(0);
}


size_t C2105052Parser::Parameter_listContext::getRuleIndex() const {
  return C2105052Parser::RuleParameter_list;
}



C2105052Parser::Parameter_listContext* C2105052Parser::parameter_list() {
   return parameter_list(0);
}

C2105052Parser::Parameter_listContext* C2105052Parser::parameter_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105052Parser::Parameter_listContext *_localctx = _tracker.createInstance<Parameter_listContext>(_ctx, parentState);
  C2105052Parser::Parameter_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 20;
  enterRecursionRule(_localctx, 20, C2105052Parser::RuleParameter_list, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(189);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      setState(181);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->t = type_specifier();
      setState(182);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->id = match(C2105052Parser::ID);

              // first parameter: start fresh
              antlrcpp::downCast<Parameter_listContext *>(_localctx)->params =  {};
              _localctx->params.emplace_back(antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->txt, antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText());
              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getLine()) + ": parameter_list : type_specifier ID\n");
              writeIntoparserLogFile(antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->txt + " " + antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText() + "\n");
              
          
      break;
    }

    case 2: {
      setState(185);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->t = type_specifier();
      setState(186);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->addopToken = match(C2105052Parser::ADDOP);

              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->addopToken->getLine()) + ": parameter_list : type_specifier\n");

              writeIntoparserLogFile(antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->txt+"\n");

              writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->addopToken->getLine()) + ": syntax error, unexpected ADDOP, expecting RPAREN or COMMA\n");
              syntaxErrorCount++;
              writeIntoparserLogFile("Error at line " + std::to_string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->addopToken->getLine()) + ": syntax error, unexpected ADDOP, expecting RPAREN or COMMA\n");
              antlrcpp::downCast<Parameter_listContext *>(_localctx)->params =  {};
              _localctx->params.emplace_back(antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->txt, "");
          
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(199);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Parameter_listContext>(parentContext, parentState);
        _localctx->pl = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleParameter_list);
        setState(191);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(192);
        match(C2105052Parser::COMMA);
        setState(193);
        antlrcpp::downCast<Parameter_listContext *>(_localctx)->t = type_specifier();
        setState(194);
        antlrcpp::downCast<Parameter_listContext *>(_localctx)->id = match(C2105052Parser::ID);

                          // additional parameter: copy old list then append
                          antlrcpp::downCast<Parameter_listContext *>(_localctx)->params =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->pl->params;
                          pair<string, string> newParam(antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->txt, antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText());
                          string str;
                          for (const auto &p : _localctx->params) {
                              if (p.first == newParam.first && p.second == newParam.second) {
                                  writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getLine()) + ": Multiple declaration of " + antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText() + " in parameter\n");
                                  syntaxErrorCount++;
                                  writeIntoparserLogFile("Error at line " + std::to_string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getLine()) + ": Multiple declaration of " + antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText() + " in parameter\n");
                                  
                              }
                              str+= p.first + " " + p.second+",";
                          }
                          
                          str+= antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->txt + " " + antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText();
                          _localctx->params.push_back(newParam);
                          writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getLine()) + ": parameter_list : parameter_list COMMA type_specifier ID\n");
                          writeIntoparserLogFile(str + "\n");
                       
      }
      setState(201);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StatementsContext ------------------------------------------------------------------

C2105052Parser::StatementsContext::StatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105052Parser::StatementContext* C2105052Parser::StatementsContext::statement() {
  return getRuleContext<C2105052Parser::StatementContext>(0);
}

C2105052Parser::StatementsContext* C2105052Parser::StatementsContext::statements() {
  return getRuleContext<C2105052Parser::StatementsContext>(0);
}


size_t C2105052Parser::StatementsContext::getRuleIndex() const {
  return C2105052Parser::RuleStatements;
}



C2105052Parser::StatementsContext* C2105052Parser::statements() {
   return statements(0);
}

C2105052Parser::StatementsContext* C2105052Parser::statements(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105052Parser::StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, parentState);
  C2105052Parser::StatementsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, C2105052Parser::RuleStatements, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(203);
    antlrcpp::downCast<StatementsContext *>(_localctx)->st = statement();

            writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<StatementsContext *>(_localctx)->st->line) + ": statements : statement\n");
            antlrcpp::downCast<StatementsContext *>(_localctx)->code =  antlrcpp::downCast<StatementsContext *>(_localctx)->st->code;
            antlrcpp::downCast<StatementsContext *>(_localctx)->line =  antlrcpp::downCast<StatementsContext *>(_localctx)->st->line;
            for (const auto &line : _localctx->code) {
                writeIntoparserLogFile(line + "\n");

            }
        
    _ctx->stop = _input->LT(-1);
    setState(212);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<StatementsContext>(parentContext, parentState);
        _localctx->ss = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleStatements);
        setState(206);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(207);
        antlrcpp::downCast<StatementsContext *>(_localctx)->s = statement();

                          writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<StatementsContext *>(_localctx)->s->line) + ": statements : statements statement\n");
                          antlrcpp::downCast<StatementsContext *>(_localctx)->code =  antlrcpp::downCast<StatementsContext *>(_localctx)->ss->code;
                          for (const auto &line : antlrcpp::downCast<StatementsContext *>(_localctx)->s->code) {
                              _localctx->code.push_back(line);
                          }
                          antlrcpp::downCast<StatementsContext *>(_localctx)->line =  antlrcpp::downCast<StatementsContext *>(_localctx)->s->line;
                          for (const auto &line : _localctx->code) {
                              writeIntoparserLogFile(line);
                          }
                          writeIntoparserLogFile("");
                       
      }
      setState(214);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

C2105052Parser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105052Parser::Var_declarationContext* C2105052Parser::StatementContext::var_declaration() {
  return getRuleContext<C2105052Parser::Var_declarationContext>(0);
}

std::vector<C2105052Parser::Expression_statementContext *> C2105052Parser::StatementContext::expression_statement() {
  return getRuleContexts<C2105052Parser::Expression_statementContext>();
}

C2105052Parser::Expression_statementContext* C2105052Parser::StatementContext::expression_statement(size_t i) {
  return getRuleContext<C2105052Parser::Expression_statementContext>(i);
}

C2105052Parser::Compound_statementContext* C2105052Parser::StatementContext::compound_statement() {
  return getRuleContext<C2105052Parser::Compound_statementContext>(0);
}

tree::TerminalNode* C2105052Parser::StatementContext::FOR() {
  return getToken(C2105052Parser::FOR, 0);
}

tree::TerminalNode* C2105052Parser::StatementContext::LPAREN() {
  return getToken(C2105052Parser::LPAREN, 0);
}

tree::TerminalNode* C2105052Parser::StatementContext::RPAREN() {
  return getToken(C2105052Parser::RPAREN, 0);
}

C2105052Parser::ExpressionContext* C2105052Parser::StatementContext::expression() {
  return getRuleContext<C2105052Parser::ExpressionContext>(0);
}

std::vector<C2105052Parser::StatementContext *> C2105052Parser::StatementContext::statement() {
  return getRuleContexts<C2105052Parser::StatementContext>();
}

C2105052Parser::StatementContext* C2105052Parser::StatementContext::statement(size_t i) {
  return getRuleContext<C2105052Parser::StatementContext>(i);
}

tree::TerminalNode* C2105052Parser::StatementContext::IF() {
  return getToken(C2105052Parser::IF, 0);
}

tree::TerminalNode* C2105052Parser::StatementContext::ELSE() {
  return getToken(C2105052Parser::ELSE, 0);
}

tree::TerminalNode* C2105052Parser::StatementContext::WHILE() {
  return getToken(C2105052Parser::WHILE, 0);
}

tree::TerminalNode* C2105052Parser::StatementContext::PRINTLN() {
  return getToken(C2105052Parser::PRINTLN, 0);
}

tree::TerminalNode* C2105052Parser::StatementContext::ID() {
  return getToken(C2105052Parser::ID, 0);
}

tree::TerminalNode* C2105052Parser::StatementContext::SEMICOLON() {
  return getToken(C2105052Parser::SEMICOLON, 0);
}

tree::TerminalNode* C2105052Parser::StatementContext::RETURN() {
  return getToken(C2105052Parser::RETURN, 0);
}


size_t C2105052Parser::StatementContext::getRuleIndex() const {
  return C2105052Parser::RuleStatement;
}


C2105052Parser::StatementContext* C2105052Parser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 24, C2105052Parser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(267);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(215);
      antlrcpp::downCast<StatementContext *>(_localctx)->var = var_declaration();
       
              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->var->line) + ": statement : var_declaration\n");
              antlrcpp::downCast<StatementContext *>(_localctx)->code =  vector<string>();
              _localctx->code.push_back(antlrcpp::downCast<StatementContext *>(_localctx)->var->txt);
              antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->var->line;
              writeIntoparserLogFile(antlrcpp::downCast<StatementContext *>(_localctx)->var->txt + "\n");
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(218);
      antlrcpp::downCast<StatementContext *>(_localctx)->es = expression_statement();
       
              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->es->line) + ": statement : expression_statement\n");
              antlrcpp::downCast<StatementContext *>(_localctx)->code =  vector<string>();
              _localctx->code.push_back(antlrcpp::downCast<StatementContext *>(_localctx)->es->str);
              antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->es->line;
              writeIntoparserLogFile(antlrcpp::downCast<StatementContext *>(_localctx)->es->str + "\n");
          
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(221);
      antlrcpp::downCast<StatementContext *>(_localctx)->c = compound_statement(vector<pair<string,string>>());


              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->c->line) + ": statement : compound_statement\n");
              antlrcpp::downCast<StatementContext *>(_localctx)->code =  vector<string>();
              for (const auto &line : antlrcpp::downCast<StatementContext *>(_localctx)->c->code) {
                  _localctx->code.push_back(line);
              }
              antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->c->line;
              for (const auto &line : _localctx->code) {
                  writeIntoparserLogFile(line);
              }
              writeIntoparserLogFile("");
          
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(224);
      match(C2105052Parser::FOR);
      setState(225);
      match(C2105052Parser::LPAREN);
      setState(226);
      antlrcpp::downCast<StatementContext *>(_localctx)->e1 = expression_statement();
      setState(227);
      antlrcpp::downCast<StatementContext *>(_localctx)->e2 = expression_statement();
      setState(228);
      antlrcpp::downCast<StatementContext *>(_localctx)->e3 = expression();
      setState(229);
      match(C2105052Parser::RPAREN);
      setState(230);
      antlrcpp::downCast<StatementContext *>(_localctx)->s = statement();

              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->s->line) + ": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n");
              antlrcpp::downCast<StatementContext *>(_localctx)->code =  vector<string>();
              string ss = "for(" + antlrcpp::downCast<StatementContext *>(_localctx)->e1->str + antlrcpp::downCast<StatementContext *>(_localctx)->e2->str + antlrcpp::downCast<StatementContext *>(_localctx)->e3->str + ")";
              for (const auto &line : antlrcpp::downCast<StatementContext *>(_localctx)->s->code) {
                  ss += line;
                  _localctx->code.push_back(ss);
                  writeIntoparserLogFile(ss);
                  ss = "";
              }
              antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->s->line;
              writeIntoparserLogFile("");
          
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(233);
      match(C2105052Parser::IF);
      setState(234);
      match(C2105052Parser::LPAREN);
      setState(235);
      antlrcpp::downCast<StatementContext *>(_localctx)->expressionContext = expression();
      setState(236);
      match(C2105052Parser::RPAREN);
      setState(237);
      antlrcpp::downCast<StatementContext *>(_localctx)->s = statement();
       
              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->s->line) + ": statement : IF LPAREN expression RPAREN statement\n");
              antlrcpp::downCast<StatementContext *>(_localctx)->code =  vector<string>();
              string ss= "if(" + antlrcpp::downCast<StatementContext *>(_localctx)->expressionContext->str + ")";
              for (const auto &line : antlrcpp::downCast<StatementContext *>(_localctx)->s->code) {
                  ss+= line;
                  _localctx->code.push_back(ss);
                  writeIntoparserLogFile(ss);
                  ss="";
              }
              antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->s->line;
              writeIntoparserLogFile("");
          
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(240);
      match(C2105052Parser::IF);
      setState(241);
      match(C2105052Parser::LPAREN);
      setState(242);
      antlrcpp::downCast<StatementContext *>(_localctx)->ex = expression();
      setState(243);
      match(C2105052Parser::RPAREN);
      setState(244);
      antlrcpp::downCast<StatementContext *>(_localctx)->s1 = statement();
      setState(245);
      match(C2105052Parser::ELSE);
      setState(246);
      antlrcpp::downCast<StatementContext *>(_localctx)->s2 = statement();

              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->s2->line) + ": statement : IF LPAREN expression RPAREN statement ELSE statement\n");
              antlrcpp::downCast<StatementContext *>(_localctx)->code =  vector<string>();
              string ss = "if(" + antlrcpp::downCast<StatementContext *>(_localctx)->ex->str + ")";
              for (const auto &line : antlrcpp::downCast<StatementContext *>(_localctx)->s1->code) {
                  ss += line;
                  
                  
                  // if line is not the last element of s1.code 
                  if (&line != &(antlrcpp::downCast<StatementContext *>(_localctx)->s1->code.back())) {
                      _localctx->code.push_back(ss);
                      writeIntoparserLogFile(ss);
                      ss = "";
                  }
              }
              ss += "else ";
              for (const auto &line : antlrcpp::downCast<StatementContext *>(_localctx)->s2->code) {
                  ss += line;
                  _localctx->code.push_back(ss);
                  writeIntoparserLogFile(ss);
                  ss = "";
              }
              antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->s2->line;
              writeIntoparserLogFile("");
          
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(249);
      match(C2105052Parser::WHILE);
      setState(250);
      match(C2105052Parser::LPAREN);
      setState(251);
      antlrcpp::downCast<StatementContext *>(_localctx)->expressionContext = expression();
      setState(252);
      match(C2105052Parser::RPAREN);
      setState(253);
      antlrcpp::downCast<StatementContext *>(_localctx)->statementContext = statement();

              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->statementContext->line) + ": statement : WHILE LPAREN expression RPAREN statement\n");
              antlrcpp::downCast<StatementContext *>(_localctx)->code =  vector<string>();
              string ss = "while(" + antlrcpp::downCast<StatementContext *>(_localctx)->expressionContext->str + ")";
              for (const auto &line : antlrcpp::downCast<StatementContext *>(_localctx)->statementContext->code) {
                  ss += line;
                  _localctx->code.push_back(ss);
                  writeIntoparserLogFile(ss);
                  ss = "";
              }
              antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->statementContext->line;
              writeIntoparserLogFile("");
          
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(256);
      match(C2105052Parser::PRINTLN);
      setState(257);
      match(C2105052Parser::LPAREN);
      setState(258);
      antlrcpp::downCast<StatementContext *>(_localctx)->idToken = match(C2105052Parser::ID);
      setState(259);
      match(C2105052Parser::RPAREN);
      setState(260);
      match(C2105052Parser::SEMICOLON);

              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getLine()) + ": statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n");
              isValidVariable(antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getText(), antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getText(), antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getLine());
              antlrcpp::downCast<StatementContext *>(_localctx)->code =  vector<string>();
              _localctx->code.push_back("printf(" + antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getText() + ");");
              writeIntoparserLogFile(_localctx->code.back() + "\n");
              antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getLine();
          
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(262);
      antlrcpp::downCast<StatementContext *>(_localctx)->returnToken = match(C2105052Parser::RETURN);
      setState(263);
      antlrcpp::downCast<StatementContext *>(_localctx)->expr = expression();
      setState(264);
      match(C2105052Parser::SEMICOLON);

              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->expr->line) + ": statement : RETURN expression SEMICOLON\n");
              antlrcpp::downCast<StatementContext *>(_localctx)->code =  vector<string>();
              _localctx->code.push_back(antlrcpp::downCast<StatementContext *>(_localctx)->returnToken->getText() + " " + antlrcpp::downCast<StatementContext *>(_localctx)->expr->str + ";");
              writeIntoparserLogFile(_localctx->code.back() + "\n");
              antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->expr->line;
              
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression_statementContext ------------------------------------------------------------------

C2105052Parser::Expression_statementContext::Expression_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105052Parser::Expression_statementContext::SEMICOLON() {
  return getToken(C2105052Parser::SEMICOLON, 0);
}

C2105052Parser::ExpressionContext* C2105052Parser::Expression_statementContext::expression() {
  return getRuleContext<C2105052Parser::ExpressionContext>(0);
}


size_t C2105052Parser::Expression_statementContext::getRuleIndex() const {
  return C2105052Parser::RuleExpression_statement;
}


C2105052Parser::Expression_statementContext* C2105052Parser::expression_statement() {
  Expression_statementContext *_localctx = _tracker.createInstance<Expression_statementContext>(_ctx, getState());
  enterRule(_localctx, 26, C2105052Parser::RuleExpression_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(275);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C2105052Parser::SEMICOLON: {
        enterOuterAlt(_localctx, 1);
        setState(269);
        antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken = match(C2105052Parser::SEMICOLON);

                writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken->getLine()) + ": expression_statement : SEMICOLON\n");
                antlrcpp::downCast<Expression_statementContext *>(_localctx)->str =  ";";
                antlrcpp::downCast<Expression_statementContext *>(_localctx)->line =  antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken->getLine();
                writeIntoparserLogFile(_localctx->str + "\n");
            
        break;
      }

      case C2105052Parser::LPAREN:
      case C2105052Parser::ADDOP:
      case C2105052Parser::NOT:
      case C2105052Parser::ID:
      case C2105052Parser::CONST_INT:
      case C2105052Parser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(271);
        antlrcpp::downCast<Expression_statementContext *>(_localctx)->exp = expression();
        setState(272);
        match(C2105052Parser::SEMICOLON);
         
                writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Expression_statementContext *>(_localctx)->exp->line) + ": expression_statement : expression SEMICOLON\n");
                antlrcpp::downCast<Expression_statementContext *>(_localctx)->str =  antlrcpp::downCast<Expression_statementContext *>(_localctx)->exp->str;
                antlrcpp::downCast<Expression_statementContext *>(_localctx)->line =  antlrcpp::downCast<Expression_statementContext *>(_localctx)->exp->line;
                if (_localctx->str.empty()) {
                    antlrcpp::downCast<Expression_statementContext *>(_localctx)->str =  ";";
                } else {
                    _localctx->str += ";";
                }
                writeIntoparserLogFile(_localctx->str + "\n");
            
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

C2105052Parser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105052Parser::VariableContext::ID() {
  return getToken(C2105052Parser::ID, 0);
}

tree::TerminalNode* C2105052Parser::VariableContext::LTHIRD() {
  return getToken(C2105052Parser::LTHIRD, 0);
}

C2105052Parser::ExpressionContext* C2105052Parser::VariableContext::expression() {
  return getRuleContext<C2105052Parser::ExpressionContext>(0);
}

tree::TerminalNode* C2105052Parser::VariableContext::RTHIRD() {
  return getToken(C2105052Parser::RTHIRD, 0);
}


size_t C2105052Parser::VariableContext::getRuleIndex() const {
  return C2105052Parser::RuleVariable;
}


C2105052Parser::VariableContext* C2105052Parser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 28, C2105052Parser::RuleVariable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(285);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(277);
      antlrcpp::downCast<VariableContext *>(_localctx)->idToken = match(C2105052Parser::ID);

              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine()) + ": variable : ID\n");
              isValidVariable(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText(),antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText(), antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine());
              writeIntoparserLogFile(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() + "\n");
              antlrcpp::downCast<VariableContext *>(_localctx)->varName =  antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText();
              antlrcpp::downCast<VariableContext *>(_localctx)->line =  antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine();
           
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(279);
      antlrcpp::downCast<VariableContext *>(_localctx)->idToken = match(C2105052Parser::ID);
      setState(280);
      match(C2105052Parser::LTHIRD);
      setState(281);
      antlrcpp::downCast<VariableContext *>(_localctx)->expressionContext = expression();
      setState(282);
      match(C2105052Parser::RTHIRD);
       
              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine()) + ": variable : ID LTHIRD expression RTHIRD\n");
              string str = antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() + "[" + antlrcpp::downCast<VariableContext *>(_localctx)->expressionContext->str + "]";
              isValidVariable(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText(),str, antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine());
              writeIntoparserLogFile(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() + "[" + antlrcpp::downCast<VariableContext *>(_localctx)->expressionContext->str + "]\n");
              antlrcpp::downCast<VariableContext *>(_localctx)->varName =  antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() + "[" + antlrcpp::downCast<VariableContext *>(_localctx)->expressionContext->str + "]";
              if (antlrcpp::downCast<VariableContext *>(_localctx)->expressionContext->str.empty()) {
                  writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine()) + ": Empty expression in array index\n");
                  syntaxErrorCount++;
              }
              antlrcpp::downCast<VariableContext *>(_localctx)->line =  antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine();
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

C2105052Parser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105052Parser::Logic_expressionContext* C2105052Parser::ExpressionContext::logic_expression() {
  return getRuleContext<C2105052Parser::Logic_expressionContext>(0);
}

tree::TerminalNode* C2105052Parser::ExpressionContext::ASSIGNOP() {
  return getToken(C2105052Parser::ASSIGNOP, 0);
}

C2105052Parser::VariableContext* C2105052Parser::ExpressionContext::variable() {
  return getRuleContext<C2105052Parser::VariableContext>(0);
}


size_t C2105052Parser::ExpressionContext::getRuleIndex() const {
  return C2105052Parser::RuleExpression;
}


C2105052Parser::ExpressionContext* C2105052Parser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 30, C2105052Parser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(295);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(287);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->l_expr = logic_expression();

              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<ExpressionContext *>(_localctx)->l_expr->line) + ": expression : logic_expression\n");
              antlrcpp::downCast<ExpressionContext *>(_localctx)->str =  "";
              for (const auto &term : antlrcpp::downCast<ExpressionContext *>(_localctx)->l_expr->rel_expr) {
                  _localctx->str += term;
              }
              antlrcpp::downCast<ExpressionContext *>(_localctx)->line =  antlrcpp::downCast<ExpressionContext *>(_localctx)->l_expr->line;
              writeIntoparserLogFile(_localctx->str + "\n");
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(290);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->var = variable();
      setState(291);
      match(C2105052Parser::ASSIGNOP);
      setState(292);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->l_expr = logic_expression();

              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<ExpressionContext *>(_localctx)->l_expr->line) + ": expression : variable ASSIGNOP logic_expression\n");
              antlrcpp::downCast<ExpressionContext *>(_localctx)->str =  antlrcpp::downCast<ExpressionContext *>(_localctx)->var->varName + "=";
              string logicExpr;
              for (const auto &term : antlrcpp::downCast<ExpressionContext *>(_localctx)->l_expr->rel_expr) {
                  _localctx->str += term;
                  logicExpr += term;
              }
              assignOpcheck(antlrcpp::downCast<ExpressionContext *>(_localctx)->var->varName, logicExpr, antlrcpp::downCast<ExpressionContext *>(_localctx)->l_expr->line);
              antlrcpp::downCast<ExpressionContext *>(_localctx)->line =  antlrcpp::downCast<ExpressionContext *>(_localctx)->l_expr->line;
              writeIntoparserLogFile(_localctx->str + "\n");
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Logic_expressionContext ------------------------------------------------------------------

C2105052Parser::Logic_expressionContext::Logic_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<C2105052Parser::Rel_expressionContext *> C2105052Parser::Logic_expressionContext::rel_expression() {
  return getRuleContexts<C2105052Parser::Rel_expressionContext>();
}

C2105052Parser::Rel_expressionContext* C2105052Parser::Logic_expressionContext::rel_expression(size_t i) {
  return getRuleContext<C2105052Parser::Rel_expressionContext>(i);
}

tree::TerminalNode* C2105052Parser::Logic_expressionContext::LOGICOP() {
  return getToken(C2105052Parser::LOGICOP, 0);
}


size_t C2105052Parser::Logic_expressionContext::getRuleIndex() const {
  return C2105052Parser::RuleLogic_expression;
}


C2105052Parser::Logic_expressionContext* C2105052Parser::logic_expression() {
  Logic_expressionContext *_localctx = _tracker.createInstance<Logic_expressionContext>(_ctx, getState());
  enterRule(_localctx, 32, C2105052Parser::RuleLogic_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(305);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(297);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r_expr = rel_expression();

              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r_expr->line) + ": logic_expression : rel_expression\n");
              antlrcpp::downCast<Logic_expressionContext *>(_localctx)->rel_expr =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r_expr->simple_expr;
              antlrcpp::downCast<Logic_expressionContext *>(_localctx)->line =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r_expr->line;
              string str;
              for (const auto &term : _localctx->rel_expr) {
                  str += term;
              }
              writeIntoparserLogFile(str + "\n");
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(300);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r1 = rel_expression();
      setState(301);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken = match(C2105052Parser::LOGICOP);
      setState(302);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r2 = rel_expression();

              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r1->line) + ": logic_expression : rel_expression LOGICOP rel_expression\n");
              antlrcpp::downCast<Logic_expressionContext *>(_localctx)->rel_expr =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r1->simple_expr;
              _localctx->rel_expr.push_back(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken->getText());
              for (const auto &term : antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r2->simple_expr) {
                  _localctx->rel_expr.push_back(term);
              }
              antlrcpp::downCast<Logic_expressionContext *>(_localctx)->line =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r1->line;
              string str;
              for (const auto &term : _localctx->rel_expr) {
                  str += term;
              }
              writeIntoparserLogFile(str + "\n");
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Rel_expressionContext ------------------------------------------------------------------

C2105052Parser::Rel_expressionContext::Rel_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<C2105052Parser::Simple_expressionContext *> C2105052Parser::Rel_expressionContext::simple_expression() {
  return getRuleContexts<C2105052Parser::Simple_expressionContext>();
}

C2105052Parser::Simple_expressionContext* C2105052Parser::Rel_expressionContext::simple_expression(size_t i) {
  return getRuleContext<C2105052Parser::Simple_expressionContext>(i);
}

tree::TerminalNode* C2105052Parser::Rel_expressionContext::RELOP() {
  return getToken(C2105052Parser::RELOP, 0);
}


size_t C2105052Parser::Rel_expressionContext::getRuleIndex() const {
  return C2105052Parser::RuleRel_expression;
}


C2105052Parser::Rel_expressionContext* C2105052Parser::rel_expression() {
  Rel_expressionContext *_localctx = _tracker.createInstance<Rel_expressionContext>(_ctx, getState());
  enterRule(_localctx, 34, C2105052Parser::RuleRel_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(315);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(307);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr = simple_expression(0);

              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr->line) + ": rel_expression : simple_expression\n");
              antlrcpp::downCast<Rel_expressionContext *>(_localctx)->simple_expr =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr->terms;
              antlrcpp::downCast<Rel_expressionContext *>(_localctx)->line =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr->line;
              string str;
              for (const auto &term : _localctx->simple_expr) {
                  str += term;
              }
              writeIntoparserLogFile(str + "\n");
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(310);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr = simple_expression(0);
      setState(311);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken = match(C2105052Parser::RELOP);
      setState(312);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->ss = simple_expression(0);

              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr->line) + ": rel_expression : simple_expression RELOP simple_expression\n");
              antlrcpp::downCast<Rel_expressionContext *>(_localctx)->simple_expr =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr->terms;
              _localctx->simple_expr.push_back(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getText());
              for (const auto &term : antlrcpp::downCast<Rel_expressionContext *>(_localctx)->ss->terms) {
                  _localctx->simple_expr.push_back(term);
              }
              antlrcpp::downCast<Rel_expressionContext *>(_localctx)->line =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr->line;
              string str;
              for (const auto &term : _localctx->simple_expr) {
                  str += term;
              }
              writeIntoparserLogFile(str + "\n");
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_expressionContext ------------------------------------------------------------------

C2105052Parser::Simple_expressionContext::Simple_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105052Parser::TermContext* C2105052Parser::Simple_expressionContext::term() {
  return getRuleContext<C2105052Parser::TermContext>(0);
}

tree::TerminalNode* C2105052Parser::Simple_expressionContext::ADDOP() {
  return getToken(C2105052Parser::ADDOP, 0);
}

C2105052Parser::Simple_expressionContext* C2105052Parser::Simple_expressionContext::simple_expression() {
  return getRuleContext<C2105052Parser::Simple_expressionContext>(0);
}

tree::TerminalNode* C2105052Parser::Simple_expressionContext::ASSIGNOP() {
  return getToken(C2105052Parser::ASSIGNOP, 0);
}


size_t C2105052Parser::Simple_expressionContext::getRuleIndex() const {
  return C2105052Parser::RuleSimple_expression;
}



C2105052Parser::Simple_expressionContext* C2105052Parser::simple_expression() {
   return simple_expression(0);
}

C2105052Parser::Simple_expressionContext* C2105052Parser::simple_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105052Parser::Simple_expressionContext *_localctx = _tracker.createInstance<Simple_expressionContext>(_ctx, parentState);
  C2105052Parser::Simple_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 36;
  enterRecursionRule(_localctx, 36, C2105052Parser::RuleSimple_expression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(318);
    antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t = term(0);

            writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->line) + ": simple_expression : term\n");
            antlrcpp::downCast<Simple_expressionContext *>(_localctx)->terms =  { antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->trm };
            antlrcpp::downCast<Simple_expressionContext *>(_localctx)->line =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->line;
            writeIntoparserLogFile(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->trm + "\n");
        
    _ctx->stop = _input->LT(-1);
    setState(335);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(333);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Simple_expressionContext>(parentContext, parentState);
          _localctx->s = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleSimple_expression);
          setState(321);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(322);
          antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken = match(C2105052Parser::ADDOP);
          setState(323);
          antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t = term(0);

                            writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->s->line) + ": simple_expression : simple_expression ADDOP term\n");
                            antlrcpp::downCast<Simple_expressionContext *>(_localctx)->terms =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->s->terms;
                            _localctx->terms.push_back(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken->getText());
                            _localctx->terms.push_back(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->trm);
                            // cout<< antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->trm << endl;
                            antlrcpp::downCast<Simple_expressionContext *>(_localctx)->line =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->s->line;
                            string str;
                            for (const auto &term : _localctx->terms) {
                                str += term;
                            }
                            writeIntoparserLogFile(str + "\n");
                        
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Simple_expressionContext>(parentContext, parentState);
          _localctx->s = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleSimple_expression);
          setState(326);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(327);
          antlrcpp::downCast<Simple_expressionContext *>(_localctx)->ad = match(C2105052Parser::ADDOP);
          setState(328);
          antlrcpp::downCast<Simple_expressionContext *>(_localctx)->as = match(C2105052Parser::ASSIGNOP);

                            antlrcpp::downCast<Simple_expressionContext *>(_localctx)->terms =  vector<string>();
                            writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->ad->getLine()) + ": syntax error, unexpected ASSIGNOP\n");
                            writeIntoparserLogFile("Error at line " + std::to_string(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->ad->getLine()) + ": syntax error, unexpected ASSIGNOP\n");
                            syntaxErrorCount++;
                        
          setState(330);
          antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t2 = term(0);

                            writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t2->line) + ": simple_expression : term\n");
                            writeIntoparserLogFile(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t2->trm+"\n");
                            _localctx->terms.push_back(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t2->trm);
                            antlrcpp::downCast<Simple_expressionContext *>(_localctx)->line =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t2->line;
                        
          break;
        }

        default:
          break;
        } 
      }
      setState(337);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

C2105052Parser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105052Parser::Unary_expressionContext* C2105052Parser::TermContext::unary_expression() {
  return getRuleContext<C2105052Parser::Unary_expressionContext>(0);
}

tree::TerminalNode* C2105052Parser::TermContext::MULOP() {
  return getToken(C2105052Parser::MULOP, 0);
}

C2105052Parser::TermContext* C2105052Parser::TermContext::term() {
  return getRuleContext<C2105052Parser::TermContext>(0);
}

tree::TerminalNode* C2105052Parser::TermContext::UNRECOGNIZED() {
  return getToken(C2105052Parser::UNRECOGNIZED, 0);
}


size_t C2105052Parser::TermContext::getRuleIndex() const {
  return C2105052Parser::RuleTerm;
}



C2105052Parser::TermContext* C2105052Parser::term() {
   return term(0);
}

C2105052Parser::TermContext* C2105052Parser::term(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105052Parser::TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, parentState);
  C2105052Parser::TermContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 38;
  enterRecursionRule(_localctx, 38, C2105052Parser::RuleTerm, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(339);
    antlrcpp::downCast<TermContext *>(_localctx)->u_expr = unary_expression();

            writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<TermContext *>(_localctx)->u_expr->line) + ": term : unary_expression\n");
            antlrcpp::downCast<TermContext *>(_localctx)->trm =  antlrcpp::downCast<TermContext *>(_localctx)->u_expr->unary_expr;
            antlrcpp::downCast<TermContext *>(_localctx)->line =  antlrcpp::downCast<TermContext *>(_localctx)->u_expr->line;
            writeIntoparserLogFile(_localctx->trm + "\n");
        
    _ctx->stop = _input->LT(-1);
    setState(352);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(350);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<TermContext>(parentContext, parentState);
          _localctx->t = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleTerm);
          setState(342);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(343);
          antlrcpp::downCast<TermContext *>(_localctx)->mulopToken = match(C2105052Parser::MULOP);
          setState(344);
          antlrcpp::downCast<TermContext *>(_localctx)->u = unary_expression();

                            writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<TermContext *>(_localctx)->t->line) + ": term : term MULOP unary_expression\n");
                            antlrcpp::downCast<TermContext *>(_localctx)->trm =  antlrcpp::downCast<TermContext *>(_localctx)->t->trm  + antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getText() + antlrcpp::downCast<TermContext *>(_localctx)->u->unary_expr;
                            antlrcpp::downCast<TermContext *>(_localctx)->line =  antlrcpp::downCast<TermContext *>(_localctx)->t->line;
                            termExprCheck(antlrcpp::downCast<TermContext *>(_localctx)->u->unary_expr, antlrcpp::downCast<TermContext *>(_localctx)->u->line);
                            termMulOpCheck(antlrcpp::downCast<TermContext *>(_localctx)->t->trm, antlrcpp::downCast<TermContext *>(_localctx)->u->unary_expr, antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getText(), antlrcpp::downCast<TermContext *>(_localctx)->t->line);
                            writeIntoparserLogFile(_localctx->trm + "\n");
                        
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<TermContext>(parentContext, parentState);
          _localctx->t = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleTerm);
          setState(347);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(348);
          antlrcpp::downCast<TermContext *>(_localctx)->unrecognizedToken = match(C2105052Parser::UNRECOGNIZED);

                            writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<TermContext *>(_localctx)->unrecognizedToken->getLine()) + ": Unrecognized character " + antlrcpp::downCast<TermContext *>(_localctx)->unrecognizedToken->getText()+"\n");
                            writeIntoparserLogFile("Error at line " + std::to_string(antlrcpp::downCast<TermContext *>(_localctx)->unrecognizedToken->getLine()) + ": Unrecognized character " + antlrcpp::downCast<TermContext *>(_localctx)->unrecognizedToken->getText()+"\n");
                            syntaxErrorCount++;
                            // cout<<"Error at line "<<antlrcpp::downCast<TermContext *>(_localctx)->unrecognizedToken->getLine()<<": "<<antlrcpp::downCast<TermContext *>(_localctx)->unrecognizedToken->getText()<<" is not a valid token"<<endl;
                            antlrcpp::downCast<TermContext *>(_localctx)->trm = antlrcpp::downCast<TermContext *>(_localctx)->t->trm;
                            // cout<<"Term at "<<antlrcpp::downCast<TermContext *>(_localctx)->t->line<<": "<<_localctx->trm<<endl;
                            antlrcpp::downCast<TermContext *>(_localctx)->line =  antlrcpp::downCast<TermContext *>(_localctx)->t->line;
                        
          break;
        }

        default:
          break;
        } 
      }
      setState(354);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Unary_expressionContext ------------------------------------------------------------------

C2105052Parser::Unary_expressionContext::Unary_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105052Parser::Unary_expressionContext::ADDOP() {
  return getToken(C2105052Parser::ADDOP, 0);
}

C2105052Parser::Unary_expressionContext* C2105052Parser::Unary_expressionContext::unary_expression() {
  return getRuleContext<C2105052Parser::Unary_expressionContext>(0);
}

tree::TerminalNode* C2105052Parser::Unary_expressionContext::NOT() {
  return getToken(C2105052Parser::NOT, 0);
}

C2105052Parser::FactorContext* C2105052Parser::Unary_expressionContext::factor() {
  return getRuleContext<C2105052Parser::FactorContext>(0);
}


size_t C2105052Parser::Unary_expressionContext::getRuleIndex() const {
  return C2105052Parser::RuleUnary_expression;
}


C2105052Parser::Unary_expressionContext* C2105052Parser::unary_expression() {
  Unary_expressionContext *_localctx = _tracker.createInstance<Unary_expressionContext>(_ctx, getState());
  enterRule(_localctx, 40, C2105052Parser::RuleUnary_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(366);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C2105052Parser::ADDOP: {
        enterOuterAlt(_localctx, 1);
        setState(355);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->addopToken = match(C2105052Parser::ADDOP);
        setState(356);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expressionContext = unary_expression();

                writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expressionContext->line) + ": unary_expression : ADDOP unary_expression\n");
                antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expr =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->addopToken->getText() + antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expressionContext->unary_expr;
                antlrcpp::downCast<Unary_expressionContext *>(_localctx)->line =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expressionContext->line;
                writeIntoparserLogFile(_localctx->unary_expr + "\n");
            
        break;
      }

      case C2105052Parser::NOT: {
        enterOuterAlt(_localctx, 2);
        setState(359);
        match(C2105052Parser::NOT);
        setState(360);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expressionContext = unary_expression();

                writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expressionContext->line) + ": unary_expression : NOT unary_expression\n");
                antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expr =  "!" + antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expressionContext->unary_expr;
                antlrcpp::downCast<Unary_expressionContext *>(_localctx)->line =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expressionContext->line;
                writeIntoparserLogFile(_localctx->unary_expr + "\n");
            
        break;
      }

      case C2105052Parser::LPAREN:
      case C2105052Parser::ID:
      case C2105052Parser::CONST_INT:
      case C2105052Parser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 3);
        setState(363);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->fact = factor();

                writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->fact->line) + ": unary_expression : factor\n");
                antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expr =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->fact->factorName;
                antlrcpp::downCast<Unary_expressionContext *>(_localctx)->line =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->fact->line;
                writeIntoparserLogFile(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->fact->factorName + "\n");

            
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

C2105052Parser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105052Parser::VariableContext* C2105052Parser::FactorContext::variable() {
  return getRuleContext<C2105052Parser::VariableContext>(0);
}

tree::TerminalNode* C2105052Parser::FactorContext::ID() {
  return getToken(C2105052Parser::ID, 0);
}

tree::TerminalNode* C2105052Parser::FactorContext::LPAREN() {
  return getToken(C2105052Parser::LPAREN, 0);
}

tree::TerminalNode* C2105052Parser::FactorContext::RPAREN() {
  return getToken(C2105052Parser::RPAREN, 0);
}

C2105052Parser::Argument_listContext* C2105052Parser::FactorContext::argument_list() {
  return getRuleContext<C2105052Parser::Argument_listContext>(0);
}

C2105052Parser::ExpressionContext* C2105052Parser::FactorContext::expression() {
  return getRuleContext<C2105052Parser::ExpressionContext>(0);
}

tree::TerminalNode* C2105052Parser::FactorContext::CONST_INT() {
  return getToken(C2105052Parser::CONST_INT, 0);
}

tree::TerminalNode* C2105052Parser::FactorContext::CONST_FLOAT() {
  return getToken(C2105052Parser::CONST_FLOAT, 0);
}

tree::TerminalNode* C2105052Parser::FactorContext::INCOP() {
  return getToken(C2105052Parser::INCOP, 0);
}

tree::TerminalNode* C2105052Parser::FactorContext::DECOP() {
  return getToken(C2105052Parser::DECOP, 0);
}


size_t C2105052Parser::FactorContext::getRuleIndex() const {
  return C2105052Parser::RuleFactor;
}


C2105052Parser::FactorContext* C2105052Parser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 42, C2105052Parser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(394);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(368);
      antlrcpp::downCast<FactorContext *>(_localctx)->var = variable();
       
              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->var->line) + ": factor : variable\n");
              antlrcpp::downCast<FactorContext *>(_localctx)->factorName =  antlrcpp::downCast<FactorContext *>(_localctx)->var->varName;
              antlrcpp::downCast<FactorContext *>(_localctx)->line =  antlrcpp::downCast<FactorContext *>(_localctx)->var->line;
              writeIntoparserLogFile(antlrcpp::downCast<FactorContext *>(_localctx)->var->varName + "\n");
              // if (symbolTable->look_up(antlrcpp::downCast<FactorContext *>(_localctx)->var->varName) == nullptr) {
              //     writeIntoErrorFile("Line# " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->var->line) + ": variable " + antlrcpp::downCast<FactorContext *>(_localctx)->var->varName + " not declared");
              //     syntaxErrorCount++;
              // }
        
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(371);
      antlrcpp::downCast<FactorContext *>(_localctx)->idToken = match(C2105052Parser::ID);
      setState(372);
      match(C2105052Parser::LPAREN);
      setState(373);
      antlrcpp::downCast<FactorContext *>(_localctx)->ar = argument_list();
      setState(374);
      match(C2105052Parser::RPAREN);
       
              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getLine()) + ": factor : ID LPAREN argument_list RPAREN\n");
              antlrcpp::downCast<FactorContext *>(_localctx)->factorName =  antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText() + "(";
              for (const auto &term : antlrcpp::downCast<FactorContext *>(_localctx)->ar->arg) {
                  _localctx->factorName += term;
                  if (&term != &(antlrcpp::downCast<FactorContext *>(_localctx)->ar->arg.back())) {
                      _localctx->factorName += ",";
                  }
              }
              _localctx->factorName += ")";
              antlrcpp::downCast<FactorContext *>(_localctx)->line =  antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getLine();
              isValidParameterList(antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText(), antlrcpp::downCast<FactorContext *>(_localctx)->ar->arg, antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getLine());
              writeIntoparserLogFile(_localctx->factorName + "\n");
          
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(377);
      match(C2105052Parser::LPAREN);
      setState(378);
      antlrcpp::downCast<FactorContext *>(_localctx)->exp = expression();
      setState(379);
      match(C2105052Parser::RPAREN);

              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->exp->line) + ": factor : LPAREN expression RPAREN\n");
              antlrcpp::downCast<FactorContext *>(_localctx)->factorName =  "(" + antlrcpp::downCast<FactorContext *>(_localctx)->exp->str + ")";
              antlrcpp::downCast<FactorContext *>(_localctx)->line =  antlrcpp::downCast<FactorContext *>(_localctx)->exp->line;
              writeIntoparserLogFile(_localctx->factorName + "\n");
          
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(382);
      antlrcpp::downCast<FactorContext *>(_localctx)->c_int = match(C2105052Parser::CONST_INT);

              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->c_int->getLine()) + ": factor : CONST_INT\n");
              antlrcpp::downCast<FactorContext *>(_localctx)->factorName =  antlrcpp::downCast<FactorContext *>(_localctx)->c_int->getText();
              antlrcpp::downCast<FactorContext *>(_localctx)->line =  antlrcpp::downCast<FactorContext *>(_localctx)->c_int->getLine();
              // cout<<"CONST_INT at "<<antlrcpp::downCast<FactorContext *>(_localctx)->c_int->getLine()<<endl;
              writeIntoparserLogFile(antlrcpp::downCast<FactorContext *>(_localctx)->c_int->getText() + "\n");
          
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(384);
      antlrcpp::downCast<FactorContext *>(_localctx)->c_float = match(C2105052Parser::CONST_FLOAT);

              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->c_float->getLine()) + ": factor : CONST_FLOAT\n");
              antlrcpp::downCast<FactorContext *>(_localctx)->factorName =  antlrcpp::downCast<FactorContext *>(_localctx)->c_float->getText();
              antlrcpp::downCast<FactorContext *>(_localctx)->line =  antlrcpp::downCast<FactorContext *>(_localctx)->c_float->getLine();
              writeIntoparserLogFile(antlrcpp::downCast<FactorContext *>(_localctx)->c_float->getText() + "\n");
          
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(386);
      antlrcpp::downCast<FactorContext *>(_localctx)->variableContext = variable();
      setState(387);
      match(C2105052Parser::INCOP);
       
              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->line) + ": factor : variable INCOP\n");
              antlrcpp::downCast<FactorContext *>(_localctx)->factorName =  antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->varName + "++";
              antlrcpp::downCast<FactorContext *>(_localctx)->line =  antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->line;
              writeIntoparserLogFile(_localctx->factorName + "\n");
          
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(390);
      antlrcpp::downCast<FactorContext *>(_localctx)->variableContext = variable();
      setState(391);
      match(C2105052Parser::DECOP);

              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->line) + ": factor : variable DECOP\n");
              antlrcpp::downCast<FactorContext *>(_localctx)->factorName =  antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->varName + "--";
              antlrcpp::downCast<FactorContext *>(_localctx)->line =  antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->line;
              writeIntoparserLogFile(_localctx->factorName + "\n");
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Argument_listContext ------------------------------------------------------------------

C2105052Parser::Argument_listContext::Argument_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105052Parser::ArgumentsContext* C2105052Parser::Argument_listContext::arguments() {
  return getRuleContext<C2105052Parser::ArgumentsContext>(0);
}


size_t C2105052Parser::Argument_listContext::getRuleIndex() const {
  return C2105052Parser::RuleArgument_list;
}


C2105052Parser::Argument_listContext* C2105052Parser::argument_list() {
  Argument_listContext *_localctx = _tracker.createInstance<Argument_listContext>(_ctx, getState());
  enterRule(_localctx, 44, C2105052Parser::RuleArgument_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(400);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C2105052Parser::LPAREN:
      case C2105052Parser::ADDOP:
      case C2105052Parser::NOT:
      case C2105052Parser::ID:
      case C2105052Parser::CONST_INT:
      case C2105052Parser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 1);
        setState(396);
        antlrcpp::downCast<Argument_listContext *>(_localctx)->ar = arguments(0);
         
                writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Argument_listContext *>(_localctx)->ar->line) + ": argument_list : arguments\n");
                antlrcpp::downCast<Argument_listContext *>(_localctx)->arg =  antlrcpp::downCast<Argument_listContext *>(_localctx)->ar->arg;
                string str;
                for (const auto &term : _localctx->arg) {
                    str += term;
                    if (&term != &(_localctx->arg.back())) {
                        str += ",";
                    }
                }
                writeIntoparserLogFile(str + "\n");

            
        break;
      }

      case C2105052Parser::RPAREN: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentsContext ------------------------------------------------------------------

C2105052Parser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105052Parser::Logic_expressionContext* C2105052Parser::ArgumentsContext::logic_expression() {
  return getRuleContext<C2105052Parser::Logic_expressionContext>(0);
}

tree::TerminalNode* C2105052Parser::ArgumentsContext::COMMA() {
  return getToken(C2105052Parser::COMMA, 0);
}

C2105052Parser::ArgumentsContext* C2105052Parser::ArgumentsContext::arguments() {
  return getRuleContext<C2105052Parser::ArgumentsContext>(0);
}


size_t C2105052Parser::ArgumentsContext::getRuleIndex() const {
  return C2105052Parser::RuleArguments;
}



C2105052Parser::ArgumentsContext* C2105052Parser::arguments() {
   return arguments(0);
}

C2105052Parser::ArgumentsContext* C2105052Parser::arguments(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105052Parser::ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, parentState);
  C2105052Parser::ArgumentsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 46;
  enterRecursionRule(_localctx, 46, C2105052Parser::RuleArguments, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(403);
    antlrcpp::downCast<ArgumentsContext *>(_localctx)->l = logic_expression();
     
            writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<ArgumentsContext *>(_localctx)->l->line) + ": arguments : logic_expression\n");
            antlrcpp::downCast<ArgumentsContext *>(_localctx)->arg =  std::vector<std::string>();
            for (const auto &term : antlrcpp::downCast<ArgumentsContext *>(_localctx)->l->rel_expr) {
                _localctx->arg.push_back(term);
            }
            string str;
            for (const auto &term : _localctx->arg) {
                str += term;
                if (&term != &(_localctx->arg.back())) {
                    str += ",";
                }
            }
            writeIntoparserLogFile(str + "\n");
            antlrcpp::downCast<ArgumentsContext *>(_localctx)->line =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->l->line;

        
    _ctx->stop = _input->LT(-1);
    setState(413);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ArgumentsContext>(parentContext, parentState);
        _localctx->ar = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleArguments);
        setState(406);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(407);
        match(C2105052Parser::COMMA);
        setState(408);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->l = logic_expression();
         
                          writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<ArgumentsContext *>(_localctx)->l->line) + ": arguments : arguments COMMA logic_expression\n");
                          antlrcpp::downCast<ArgumentsContext *>(_localctx)->arg =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->ar->arg;
                          for (const auto &term : antlrcpp::downCast<ArgumentsContext *>(_localctx)->l->rel_expr) {
                              _localctx->arg.push_back(term);
                          }
                          string str;
                          for (const auto &term : _localctx->arg) {
                              str += term;
                              if (&term != &(_localctx->arg.back())) {
                                  str += ",";
                              }
                          }
                          writeIntoparserLogFile(str + "\n");
                          antlrcpp::downCast<ArgumentsContext *>(_localctx)->line =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->l->line;
                       
      }
      setState(415);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool C2105052Parser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return programSempred(antlrcpp::downCast<ProgramContext *>(context), predicateIndex);
    case 7: return declaration_listSempred(antlrcpp::downCast<Declaration_listContext *>(context), predicateIndex);
    case 10: return parameter_listSempred(antlrcpp::downCast<Parameter_listContext *>(context), predicateIndex);
    case 11: return statementsSempred(antlrcpp::downCast<StatementsContext *>(context), predicateIndex);
    case 18: return simple_expressionSempred(antlrcpp::downCast<Simple_expressionContext *>(context), predicateIndex);
    case 19: return termSempred(antlrcpp::downCast<TermContext *>(context), predicateIndex);
    case 23: return argumentsSempred(antlrcpp::downCast<ArgumentsContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool C2105052Parser::programSempred(ProgramContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool C2105052Parser::declaration_listSempred(Declaration_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 6);
    case 2: return precpred(_ctx, 5);
    case 3: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C2105052Parser::parameter_listSempred(Parameter_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool C2105052Parser::statementsSempred(StatementsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C2105052Parser::simple_expressionSempred(Simple_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 6: return precpred(_ctx, 2);
    case 7: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C2105052Parser::termSempred(TermContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 8: return precpred(_ctx, 2);
    case 9: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C2105052Parser::argumentsSempred(ArgumentsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 10: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void C2105052Parser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  c2105052parserParserInitialize();
#else
  ::antlr4::internal::call_once(c2105052parserParserOnceFlag, c2105052parserParserInitialize);
#endif
}
