
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


#include "C2105052ParserListener.h"

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
std::unique_ptr<C2105052ParserStaticData> c2105052parserParserStaticData = nullptr;

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
  	4,1,34,411,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,1,0,1,0,1,1,1,1,1,1,1,1,1,1,5,1,56,8,1,10,1,12,
  	1,59,9,1,1,2,1,2,1,2,3,2,64,8,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
  	3,1,3,1,3,1,3,1,3,1,3,3,3,81,8,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,
  	1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,100,8,4,1,5,1,5,1,5,1,5,1,5,1,5,1,
  	5,1,5,1,5,3,5,111,8,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,123,
  	8,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,3,7,137,8,7,1,7,1,
  	7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,5,7,156,
  	8,7,10,7,12,7,159,9,7,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,3,9,169,8,9,1,10,
  	1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,3,10,180,8,10,1,10,1,10,1,10,
  	1,10,1,10,1,10,5,10,188,8,10,10,10,12,10,191,9,10,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,5,11,201,8,11,10,11,12,11,204,9,11,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,3,12,267,8,12,1,13,1,13,1,13,1,13,1,13,1,13,3,13,275,8,13,1,
  	14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,3,14,285,8,14,1,15,1,15,1,15,1,
  	15,1,15,1,15,1,15,1,15,3,15,295,8,15,1,16,1,16,1,16,1,16,1,16,1,16,1,
  	16,1,16,1,16,1,16,3,16,307,8,16,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,
  	17,3,17,317,8,17,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,5,18,328,
  	8,18,10,18,12,18,331,9,18,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,
  	1,19,1,19,1,19,5,19,345,8,19,10,19,12,19,348,9,19,1,20,1,20,1,20,1,20,
  	1,20,1,20,1,20,1,20,1,20,1,20,1,20,3,20,361,8,20,1,21,1,21,1,21,1,21,
  	1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,
  	1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,3,21,389,8,21,1,22,1,22,1,22,
  	1,22,3,22,395,8,22,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,5,23,
  	406,8,23,10,23,12,23,409,9,23,1,23,0,7,2,14,20,22,36,38,46,24,0,2,4,6,
  	8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,0,0,429,0,
  	48,1,0,0,0,2,50,1,0,0,0,4,63,1,0,0,0,6,80,1,0,0,0,8,99,1,0,0,0,10,110,
  	1,0,0,0,12,122,1,0,0,0,14,136,1,0,0,0,16,160,1,0,0,0,18,168,1,0,0,0,20,
  	179,1,0,0,0,22,192,1,0,0,0,24,266,1,0,0,0,26,274,1,0,0,0,28,284,1,0,0,
  	0,30,294,1,0,0,0,32,306,1,0,0,0,34,316,1,0,0,0,36,318,1,0,0,0,38,332,
  	1,0,0,0,40,360,1,0,0,0,42,388,1,0,0,0,44,394,1,0,0,0,46,396,1,0,0,0,48,
  	49,3,2,1,0,49,1,1,0,0,0,50,51,6,1,-1,0,51,52,3,4,2,0,52,57,1,0,0,0,53,
  	54,10,2,0,0,54,56,3,4,2,0,55,53,1,0,0,0,56,59,1,0,0,0,57,55,1,0,0,0,57,
  	58,1,0,0,0,58,3,1,0,0,0,59,57,1,0,0,0,60,64,3,12,6,0,61,64,3,6,3,0,62,
  	64,3,8,4,0,63,60,1,0,0,0,63,61,1,0,0,0,63,62,1,0,0,0,64,5,1,0,0,0,65,
  	66,3,18,9,0,66,67,5,31,0,0,67,68,5,14,0,0,68,69,3,20,10,0,69,70,5,15,
  	0,0,70,71,5,20,0,0,71,72,6,3,-1,0,72,81,1,0,0,0,73,74,3,18,9,0,74,75,
  	5,31,0,0,75,76,5,14,0,0,76,77,5,15,0,0,77,78,5,20,0,0,78,79,6,3,-1,0,
  	79,81,1,0,0,0,80,65,1,0,0,0,80,73,1,0,0,0,81,7,1,0,0,0,82,83,3,18,9,0,
  	83,84,5,31,0,0,84,85,5,14,0,0,85,86,3,20,10,0,86,87,5,15,0,0,87,88,6,
  	4,-1,0,88,89,3,10,5,0,89,90,6,4,-1,0,90,100,1,0,0,0,91,92,3,18,9,0,92,
  	93,5,31,0,0,93,94,5,14,0,0,94,95,5,15,0,0,95,96,6,4,-1,0,96,97,3,10,5,
  	0,97,98,6,4,-1,0,98,100,1,0,0,0,99,82,1,0,0,0,99,91,1,0,0,0,100,9,1,0,
  	0,0,101,102,5,16,0,0,102,103,6,5,-1,0,103,104,3,22,11,0,104,105,5,17,
  	0,0,105,106,6,5,-1,0,106,111,1,0,0,0,107,108,5,16,0,0,108,109,5,17,0,
  	0,109,111,6,5,-1,0,110,101,1,0,0,0,110,107,1,0,0,0,111,11,1,0,0,0,112,
  	113,3,18,9,0,113,114,3,14,7,0,114,115,5,20,0,0,115,116,6,6,-1,0,116,123,
  	1,0,0,0,117,118,3,18,9,0,118,119,3,16,8,0,119,120,5,20,0,0,120,121,6,
  	6,-1,0,121,123,1,0,0,0,122,112,1,0,0,0,122,117,1,0,0,0,123,13,1,0,0,0,
  	124,125,6,7,-1,0,125,126,5,31,0,0,126,137,6,7,-1,0,127,128,5,31,0,0,128,
  	129,5,18,0,0,129,130,5,32,0,0,130,131,5,19,0,0,131,137,6,7,-1,0,132,133,
  	5,31,0,0,133,134,5,22,0,0,134,135,5,31,0,0,135,137,6,7,-1,0,136,124,1,
  	0,0,0,136,127,1,0,0,0,136,132,1,0,0,0,137,157,1,0,0,0,138,139,10,6,0,
  	0,139,140,5,21,0,0,140,141,5,31,0,0,141,156,6,7,-1,0,142,143,10,5,0,0,
  	143,144,5,21,0,0,144,145,5,31,0,0,145,146,5,18,0,0,146,147,5,32,0,0,147,
  	148,5,19,0,0,148,156,6,7,-1,0,149,150,10,1,0,0,150,151,5,21,0,0,151,152,
  	5,31,0,0,152,153,5,22,0,0,153,154,5,31,0,0,154,156,6,7,-1,0,155,138,1,
  	0,0,0,155,142,1,0,0,0,155,149,1,0,0,0,156,159,1,0,0,0,157,155,1,0,0,0,
  	157,158,1,0,0,0,158,15,1,0,0,0,159,157,1,0,0,0,160,161,6,8,-1,0,161,17,
  	1,0,0,0,162,163,5,11,0,0,163,169,6,9,-1,0,164,165,5,12,0,0,165,169,6,
  	9,-1,0,166,167,5,13,0,0,167,169,6,9,-1,0,168,162,1,0,0,0,168,164,1,0,
  	0,0,168,166,1,0,0,0,169,19,1,0,0,0,170,171,6,10,-1,0,171,172,3,18,9,0,
  	172,173,5,31,0,0,173,174,6,10,-1,0,174,180,1,0,0,0,175,176,3,18,9,0,176,
  	177,5,22,0,0,177,178,6,10,-1,0,178,180,1,0,0,0,179,170,1,0,0,0,179,175,
  	1,0,0,0,180,189,1,0,0,0,181,182,10,2,0,0,182,183,5,21,0,0,183,184,3,18,
  	9,0,184,185,5,31,0,0,185,186,6,10,-1,0,186,188,1,0,0,0,187,181,1,0,0,
  	0,188,191,1,0,0,0,189,187,1,0,0,0,189,190,1,0,0,0,190,21,1,0,0,0,191,
  	189,1,0,0,0,192,193,6,11,-1,0,193,194,3,24,12,0,194,195,6,11,-1,0,195,
  	202,1,0,0,0,196,197,10,1,0,0,197,198,3,24,12,0,198,199,6,11,-1,0,199,
  	201,1,0,0,0,200,196,1,0,0,0,201,204,1,0,0,0,202,200,1,0,0,0,202,203,1,
  	0,0,0,203,23,1,0,0,0,204,202,1,0,0,0,205,206,3,12,6,0,206,207,6,12,-1,
  	0,207,267,1,0,0,0,208,209,3,26,13,0,209,210,6,12,-1,0,210,267,1,0,0,0,
  	211,212,3,10,5,0,212,213,6,12,-1,0,213,267,1,0,0,0,214,215,5,7,0,0,215,
  	216,5,14,0,0,216,217,3,26,13,0,217,218,6,12,-1,0,218,219,3,26,13,0,219,
  	220,6,12,-1,0,220,221,3,30,15,0,221,222,5,15,0,0,222,223,6,12,-1,0,223,
  	224,3,24,12,0,224,225,6,12,-1,0,225,267,1,0,0,0,226,227,5,5,0,0,227,228,
  	5,14,0,0,228,229,3,30,15,0,229,230,5,15,0,0,230,231,6,12,-1,0,231,232,
  	3,24,12,0,232,233,6,12,-1,0,233,267,1,0,0,0,234,235,5,5,0,0,235,236,5,
  	14,0,0,236,237,3,30,15,0,237,238,5,15,0,0,238,239,6,12,-1,0,239,240,3,
  	24,12,0,240,241,6,12,-1,0,241,242,5,6,0,0,242,243,6,12,-1,0,243,244,3,
  	24,12,0,244,245,6,12,-1,0,245,267,1,0,0,0,246,247,5,8,0,0,247,248,6,12,
  	-1,0,248,249,5,14,0,0,249,250,3,30,15,0,250,251,6,12,-1,0,251,252,5,15,
  	0,0,252,253,3,24,12,0,253,254,6,12,-1,0,254,267,1,0,0,0,255,256,5,9,0,
  	0,256,257,5,14,0,0,257,258,5,31,0,0,258,259,5,15,0,0,259,260,5,20,0,0,
  	260,267,6,12,-1,0,261,262,5,10,0,0,262,263,3,30,15,0,263,264,5,20,0,0,
  	264,265,6,12,-1,0,265,267,1,0,0,0,266,205,1,0,0,0,266,208,1,0,0,0,266,
  	211,1,0,0,0,266,214,1,0,0,0,266,226,1,0,0,0,266,234,1,0,0,0,266,246,1,
  	0,0,0,266,255,1,0,0,0,266,261,1,0,0,0,267,25,1,0,0,0,268,269,5,20,0,0,
  	269,275,6,13,-1,0,270,271,3,30,15,0,271,272,5,20,0,0,272,273,6,13,-1,
  	0,273,275,1,0,0,0,274,268,1,0,0,0,274,270,1,0,0,0,275,27,1,0,0,0,276,
  	277,5,31,0,0,277,285,6,14,-1,0,278,279,5,31,0,0,279,280,5,18,0,0,280,
  	281,3,30,15,0,281,282,5,19,0,0,282,283,6,14,-1,0,283,285,1,0,0,0,284,
  	276,1,0,0,0,284,278,1,0,0,0,285,29,1,0,0,0,286,287,3,32,16,0,287,288,
  	6,15,-1,0,288,295,1,0,0,0,289,290,3,28,14,0,290,291,5,30,0,0,291,292,
  	3,32,16,0,292,293,6,15,-1,0,293,295,1,0,0,0,294,286,1,0,0,0,294,289,1,
  	0,0,0,295,31,1,0,0,0,296,297,3,34,17,0,297,298,6,16,-1,0,298,307,1,0,
  	0,0,299,300,3,34,17,0,300,301,6,16,-1,0,301,302,5,29,0,0,302,303,6,16,
  	-1,0,303,304,3,34,17,0,304,305,6,16,-1,0,305,307,1,0,0,0,306,296,1,0,
  	0,0,306,299,1,0,0,0,307,33,1,0,0,0,308,309,3,36,18,0,309,310,6,17,-1,
  	0,310,317,1,0,0,0,311,312,3,36,18,0,312,313,5,28,0,0,313,314,3,36,18,
  	0,314,315,6,17,-1,0,315,317,1,0,0,0,316,308,1,0,0,0,316,311,1,0,0,0,317,
  	35,1,0,0,0,318,319,6,18,-1,0,319,320,3,38,19,0,320,321,6,18,-1,0,321,
  	329,1,0,0,0,322,323,10,1,0,0,323,324,5,22,0,0,324,325,3,38,19,0,325,326,
  	6,18,-1,0,326,328,1,0,0,0,327,322,1,0,0,0,328,331,1,0,0,0,329,327,1,0,
  	0,0,329,330,1,0,0,0,330,37,1,0,0,0,331,329,1,0,0,0,332,333,6,19,-1,0,
  	333,334,3,40,20,0,334,335,6,19,-1,0,335,346,1,0,0,0,336,337,10,2,0,0,
  	337,338,5,24,0,0,338,339,3,40,20,0,339,340,6,19,-1,0,340,345,1,0,0,0,
  	341,342,10,1,0,0,342,343,5,34,0,0,343,345,6,19,-1,0,344,336,1,0,0,0,344,
  	341,1,0,0,0,345,348,1,0,0,0,346,344,1,0,0,0,346,347,1,0,0,0,347,39,1,
  	0,0,0,348,346,1,0,0,0,349,350,5,22,0,0,350,351,3,40,20,0,351,352,6,20,
  	-1,0,352,361,1,0,0,0,353,354,5,27,0,0,354,355,3,40,20,0,355,356,6,20,
  	-1,0,356,361,1,0,0,0,357,358,3,42,21,0,358,359,6,20,-1,0,359,361,1,0,
  	0,0,360,349,1,0,0,0,360,353,1,0,0,0,360,357,1,0,0,0,361,41,1,0,0,0,362,
  	363,3,28,14,0,363,364,6,21,-1,0,364,389,1,0,0,0,365,366,5,31,0,0,366,
  	367,5,14,0,0,367,368,3,44,22,0,368,369,5,15,0,0,369,370,6,21,-1,0,370,
  	389,1,0,0,0,371,372,5,14,0,0,372,373,3,30,15,0,373,374,5,15,0,0,374,375,
  	6,21,-1,0,375,389,1,0,0,0,376,377,5,32,0,0,377,389,6,21,-1,0,378,379,
  	5,33,0,0,379,389,6,21,-1,0,380,381,3,28,14,0,381,382,5,25,0,0,382,383,
  	6,21,-1,0,383,389,1,0,0,0,384,385,3,28,14,0,385,386,5,26,0,0,386,387,
  	6,21,-1,0,387,389,1,0,0,0,388,362,1,0,0,0,388,365,1,0,0,0,388,371,1,0,
  	0,0,388,376,1,0,0,0,388,378,1,0,0,0,388,380,1,0,0,0,388,384,1,0,0,0,389,
  	43,1,0,0,0,390,391,3,46,23,0,391,392,6,22,-1,0,392,395,1,0,0,0,393,395,
  	1,0,0,0,394,390,1,0,0,0,394,393,1,0,0,0,395,45,1,0,0,0,396,397,6,23,-1,
  	0,397,398,3,32,16,0,398,399,6,23,-1,0,399,407,1,0,0,0,400,401,10,2,0,
  	0,401,402,5,21,0,0,402,403,3,32,16,0,403,404,6,23,-1,0,404,406,1,0,0,
  	0,405,400,1,0,0,0,406,409,1,0,0,0,407,405,1,0,0,0,407,408,1,0,0,0,408,
  	47,1,0,0,0,409,407,1,0,0,0,26,57,63,80,99,110,122,136,155,157,168,179,
  	189,202,266,274,284,294,306,316,329,344,346,360,388,394,407
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  c2105052parserParserStaticData = std::move(staticData);
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

void C2105052Parser::StartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart(this);
}

void C2105052Parser::StartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart(this);
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

void C2105052Parser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void C2105052Parser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
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
    setState(51);
    unit();
    _ctx->stop = _input->LT(-1);
    setState(57);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ProgramContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleProgram);
        setState(53);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(54);
        unit(); 
      }
      setState(59);
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

void C2105052Parser::UnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnit(this);
}

void C2105052Parser::UnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnit(this);
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
    setState(63);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(60);
      var_declaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(61);
      func_declaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(62);
      func_definition();
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

void C2105052Parser::Func_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_declaration(this);
}

void C2105052Parser::Func_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_declaration(this);
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
    setState(80);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(65);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->t = type_specifier();
      setState(66);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->id = match(C2105052Parser::ID);
      setState(67);
      match(C2105052Parser::LPAREN);
      setState(68);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->pl = parameter_list(0);
      setState(69);
      match(C2105052Parser::RPAREN);
      setState(70);
      match(C2105052Parser::SEMICOLON);

                std::string funcName = antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getText();
                std::string funcType = antlrcpp::downCast<Func_declarationContext *>(_localctx)->t->txt;
                insertFunctionToSymbolTable(funcName, funcType, antlrcpp::downCast<Func_declarationContext *>(_localctx)->pl->params, antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getLine());
            
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(73);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->t = type_specifier();
      setState(74);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->id = match(C2105052Parser::ID);
      setState(75);
      match(C2105052Parser::LPAREN);
      setState(76);
      match(C2105052Parser::RPAREN);
      setState(77);
      match(C2105052Parser::SEMICOLON);

                std::string funcName = antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getText();
                std::string funcType = antlrcpp::downCast<Func_declarationContext *>(_localctx)->t->txt;
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

void C2105052Parser::Func_definitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_definition(this);
}

void C2105052Parser::Func_definitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_definition(this);
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
    setState(99);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(82);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->t = type_specifier();
      setState(83);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->id = match(C2105052Parser::ID);
      setState(84);
      match(C2105052Parser::LPAREN);
      setState(85);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl = parameter_list(0);
      setState(86);
      match(C2105052Parser::RPAREN);

               insertFunctionToSymbolTable(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText(), antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->txt, antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl->params, antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getLine());
              if(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText()=="main"){
                  asmFile << "main PROC" << endl;
                  asmFile << "\tMOV AX, @DATA" << endl;
                  asmFile << "\tMOV DS, AX" << endl;
                 
              } 
              else{
                  // cout<<"Function name: "<<antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText()<<endl;
                  string ab = antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText()+" PROC\t\t; line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getLine());
                  asmFile << ab << endl;;

              }
              // curr_func_name = antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText();
              asmFile<< "\tPUSH BP" << endl;
              asmFile<< "\tMOV BP, SP" << endl;
              stack_offset = 0;
              func_return_label = label_count; // Store the label index for the function return
              label_count++;
            
      setState(88);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->c = antlrcpp::downCast<Func_definitionContext *>(_localctx)->compound_statementContext = compound_statement(antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl->params);

              antlrcpp::downCast<Func_definitionContext *>(_localctx)->code =  vector<string>();
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



              if(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText()!="main"){
                  str = "L" + std::to_string(func_return_label) + ":";
                  label_count++;
                  asmFile << str << endl;
                  str = "\tMOV SP, BP";
                  asmFile << str << endl;
                  str = "\tPOP BP";
                  asmFile << str << endl;
                  str ="\tRET";
                  if(antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl->params.size() > 0) {
                      str += " " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl->params.size() * 2);
                  }
                  asmFile << str << endl;
                  str = antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() + " ENDP";
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
                  str = antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() + " ENDP";
                  asmFile << str << endl;
              }
              




            
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(91);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->t = type_specifier();
      setState(92);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->id = match(C2105052Parser::ID);
      setState(93);
      match(C2105052Parser::LPAREN);
      setState(94);
      match(C2105052Parser::RPAREN);

                // Function definition (no parameters)
                std::string funcName = antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText();
                std::string funcType = antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->txt;
                SymbolInfo *existing2 = symbolTable->look_up(funcName);
                insertFunctionToSymbolTable(funcName, funcType, vector<pair<string,string>>(), antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getLine());
                if(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText()=="main"){
                  asmFile << "main PROC" << endl;
                  asmFile << "\tMOV AX, @DATA" << endl;
                  asmFile << "\tMOV DS, AX" << endl;
                 
                }
                else{
                  // cout<<"Function name: "<<antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText()<<endl;
                  string ab = antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText()+" PROC\t\t; line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getLine());
                  asmFile << ab << endl;;

              }
                  // curr_func_name = antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText();
              asmFile<< "\tPUSH BP" << endl;
              asmFile<< "\tMOV BP, SP" << endl;
                  func_return_label = label_count; // Store the label index for the function return
                  label_count++;
              stack_offset = 0;
            
      setState(96);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs = compound_statement(vector<pair<string,string>>());

              antlrcpp::downCast<Func_definitionContext *>(_localctx)->code =  vector<string>();
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

              if(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText()!="main"){
                  str = "L" + std::to_string(func_return_label) + ":";
                  asmFile << str << endl;
                  str = "\tMOV SP, BP";
                  asmFile << str << endl;
                  str = "\tPOP BP";
                  asmFile << str << endl;
                  str ="\tRET";
                  asmFile << str << endl;
                  str = antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() + " ENDP";
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
                  str = antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() + " ENDP";
                  asmFile << str << endl;
              }
              
            
            
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

void C2105052Parser::Compound_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompound_statement(this);
}

void C2105052Parser::Compound_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompound_statement(this);
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
    setState(110);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(101);
      match(C2105052Parser::LCURL);

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
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->st = statements(0);
      setState(104);
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
                  // // cout<<te<<endl;
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
      setState(107);
      match(C2105052Parser::LCURL);
      setState(108);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken = match(C2105052Parser::RCURL);

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

void C2105052Parser::Var_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_declaration(this);
}

void C2105052Parser::Var_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_declaration(this);
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
    setState(122);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(112);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->t = type_specifier();
      setState(113);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl = declaration_list(0);
      setState(114);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm = match(C2105052Parser::SEMICOLON);

                  // // cout<<"Declaration list size: "<<antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl->nameList.size()<<endl;
                  writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getLine()) + ": var_declaration : type_specifier declaration_list SEMICOLON\n");
                  string txt = antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->txt;
                  txt += " ";
                  for (const auto &name : antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl->nameList) {
                      txt += name;
                      string str;
                      bool isArray = false;
                      // cout<<"Name: "<<name<<endl;
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
                      if(s->getScopeId()==1){
                          print_global_var(name,type);
                      }
                      handle_var_declaration(s,stack_offset,name,type);
                  }
                  txt+=";";
                  // // cout<<"Declaraction list size: "<<antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl->nameList.size()<<endl;
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
      setState(117);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->t = type_specifier();
      setState(118);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->de = declaration_list_err();
      setState(119);
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

void C2105052Parser::Declaration_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration_list(this);
}

void C2105052Parser::Declaration_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration_list(this);
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
    setState(136);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      setState(125);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C2105052Parser::ID);

                antlrcpp::downCast<Declaration_listContext *>(_localctx)->nameList =  std::vector<std::string>();
                _localctx->nameList.push_back(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText());
                  insertIdInSymbolTable(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText(), "ID", antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine());
                  writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine()) + ": declaration_list : ID\n");
                  writeIntoparserLogFile(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText()+ "\n");
            
      break;
    }

    case 2: {
      setState(127);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C2105052Parser::ID);
      setState(128);
      match(C2105052Parser::LTHIRD);
      setState(129);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken = match(C2105052Parser::CONST_INT);
      setState(130);
      match(C2105052Parser::RTHIRD);

                antlrcpp::downCast<Declaration_listContext *>(_localctx)->nameList =  std::vector<std::string>();
                _localctx->nameList.push_back(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText() + "[" + antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken->getText() + "]");
                  insertIdInSymbolTable(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText(), "ID", antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine());
                  writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine()) + ": declaration_list : ID LTHIRD CONST_INT RTHIRD\n");
                  writeIntoparserLogFile(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText() + "[" + antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken->getText() + "]\n");
            
      break;
    }

    case 3: {
      setState(132);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->first = match(C2105052Parser::ID);
      setState(133);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->op = match(C2105052Parser::ADDOP);
      setState(134);
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
    setState(157);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(155);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(138);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(139);
          match(C2105052Parser::COMMA);
          setState(140);
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
          setState(142);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(143);
          match(C2105052Parser::COMMA);
          setState(144);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C2105052Parser::ID);
          setState(145);
          match(C2105052Parser::LTHIRD);
          setState(146);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken = match(C2105052Parser::CONST_INT);
          setState(147);
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
          setState(149);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(150);
          match(C2105052Parser::COMMA);
          setState(151);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C2105052Parser::ID);
          setState(152);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->addopToken = match(C2105052Parser::ADDOP);
          setState(153);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C2105052Parser::ID);

                                // This is an error case, where ADDOP is used incorrectly
                                writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->addopToken->getLine()) + ": syntax error, unexpected ADDOP, expecting COMMA or RTHIRD\n");
                                syntaxErrorCount++;
                                writeIntoparserLogFile("Error at line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->addopToken->getLine()) + ": syntax error, unexpected ADDOP, expecting COMMA or RTHIRD\n");
                                antlrcpp::downCast<Declaration_listContext *>(_localctx)->nameList =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->pl->nameList;
                                // // cout<<"Matched with declaration_list COMMA ID ADDOP ID"<<endl;
                                _localctx->nameList.push_back(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText());
                          
          break;
        }

        default:
          break;
        } 
      }
      setState(159);
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

void C2105052Parser::Declaration_list_errContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration_list_err(this);
}

void C2105052Parser::Declaration_list_errContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration_list_err(this);
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

void C2105052Parser::Type_specifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_specifier(this);
}

void C2105052Parser::Type_specifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_specifier(this);
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
    setState(168);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C2105052Parser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(162);
        antlrcpp::downCast<Type_specifierContext *>(_localctx)->intToken = match(C2105052Parser::INT);
         
                // // cout<<"INT at"<<antlrcpp::downCast<Type_specifierContext *>(_localctx)->intToken->getLine()<<endl;
               antlrcpp::downCast<Type_specifierContext *>(_localctx)->txt =  antlrcpp::downCast<Type_specifierContext *>(_localctx)->intToken->getText();
                 antlrcpp::downCast<Type_specifierContext *>(_localctx)->type =  "INT";
               writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Type_specifierContext *>(_localctx)->intToken->getLine()) + ": type_specifier : INT\n");
               writeIntoparserLogFile(antlrcpp::downCast<Type_specifierContext *>(_localctx)->intToken->getText() + "\n");
            
        break;
      }

      case C2105052Parser::FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(164);
        antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken = match(C2105052Parser::FLOAT);

                    antlrcpp::downCast<Type_specifierContext *>(_localctx)->txt =  antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken->getText();
                    antlrcpp::downCast<Type_specifierContext *>(_localctx)->type =  "FLOAT";
                 writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken->getLine()) + ": type_specifier : FLOAT\n");
                    writeIntoparserLogFile(antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken->getText() + "\n");
             
        break;
      }

      case C2105052Parser::VOID: {
        enterOuterAlt(_localctx, 3);
        setState(166);
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

void C2105052Parser::Parameter_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter_list(this);
}

void C2105052Parser::Parameter_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter_list(this);
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
    setState(179);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      setState(171);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->t = type_specifier();
      setState(172);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->id = match(C2105052Parser::ID);

              // first parameter: start fresh
              antlrcpp::downCast<Parameter_listContext *>(_localctx)->params =  {};
              _localctx->params.emplace_back(antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->txt, antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText());
              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getLine()) + ": parameter_list : type_specifier ID\n");
              writeIntoparserLogFile(antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->txt + " " + antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText() + "\n");
              
          
      break;
    }

    case 2: {
      setState(175);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->t = type_specifier();
      setState(176);
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
    setState(189);
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
        setState(181);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(182);
        match(C2105052Parser::COMMA);
        setState(183);
        antlrcpp::downCast<Parameter_listContext *>(_localctx)->t = type_specifier();
        setState(184);
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
      setState(191);
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

void C2105052Parser::StatementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatements(this);
}

void C2105052Parser::StatementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatements(this);
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
    setState(193);
    antlrcpp::downCast<StatementsContext *>(_localctx)->st = statement();

            writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<StatementsContext *>(_localctx)->st->line) + ": statements : statement\n");
            antlrcpp::downCast<StatementsContext *>(_localctx)->code =  antlrcpp::downCast<StatementsContext *>(_localctx)->st->code;
            antlrcpp::downCast<StatementsContext *>(_localctx)->line =  antlrcpp::downCast<StatementsContext *>(_localctx)->st->line;
            for (const auto &line : _localctx->code) {
                writeIntoparserLogFile(line + "\n");

            }
        
    _ctx->stop = _input->LT(-1);
    setState(202);
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
        setState(196);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(197);
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
      setState(204);
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

void C2105052Parser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void C2105052Parser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
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
    setState(266);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(205);
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
      setState(208);
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
      setState(211);
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
      setState(214);
      match(C2105052Parser::FOR);
      setState(215);
      match(C2105052Parser::LPAREN);
      setState(216);
      antlrcpp::downCast<StatementContext *>(_localctx)->e1 = expression_statement();

              int loop_end_label_index = -1;
              int statement_label_index = -1;
              int increment_label = -1;
              int loop_condition_label = -1;
              string ab = "L" + std::to_string(label_count) + ":";
              loop_condition_label = label_count;
              label_count++;
              asmFile << ab << endl;;

          
      setState(218);
      antlrcpp::downCast<StatementContext *>(_localctx)->e2 = expression_statement();

              ab = "\tPOP AX\t\t; line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->e2->line);
              asmFile << ab << endl;;
              stack_offset -= 2; // Decrease stack offset by 2 for loop condition
              ab = "\tCMP AX, 0\t\t; line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->e2->line);
              asmFile << ab << endl;;
              ab = "\tJE L" + std::to_string(label_count) + "\t\t; line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->e2->line);
              asmFile << ab << endl;;
              loop_end_label_index = label_count; // Store the index of the loop end label for later use
              label_count++; // Increment label count for the next label
              ab = "\tJMP L" + std::to_string(label_count) + "\t\t; line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->e2->line);
              asmFile << ab << endl;;
              statement_label_index = label_count; // Store the index of the statement label for later use
              label_count++; // Increment label count for the next label
              increment_label = label_count;
          
      setState(220);
      antlrcpp::downCast<StatementContext *>(_localctx)->e3 = expression();
      setState(221);
      match(C2105052Parser::RPAREN);

              ab = "\tJMP L" + std::to_string(loop_condition_label) + "\t\t; line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->e3->line);
              asmFile << ab << endl;;
              ab = "L" + std::to_string(statement_label_index) + ":";
              asmFile << ab << endl;;
          
      setState(223);
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


              
              ss = "L" + std::to_string(label_count) + ":";
              label_count++;
              asmFile << ss << endl;


              ss = "\tJMP L" + std::to_string(increment_label) + "\t\t; line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->s->line);
              asmFile << ss << endl;
              ss = "L" + std::to_string(loop_end_label_index) + ":";
              asmFile << ss << endl;



          
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(226);
      match(C2105052Parser::IF);
      setState(227);
      match(C2105052Parser::LPAREN);
      setState(228);
      antlrcpp::downCast<StatementContext *>(_localctx)->expressionContext = expression();
      setState(229);
      match(C2105052Parser::RPAREN);

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
      antlrcpp::downCast<StatementContext *>(_localctx)->s = statement();

              str = "L" + std::to_string(if_label_index) + ":";
              asmFile << str << endl;
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
      setState(234);
      match(C2105052Parser::IF);
      setState(235);
      match(C2105052Parser::LPAREN);
      setState(236);
      antlrcpp::downCast<StatementContext *>(_localctx)->ex = expression();
      setState(237);
      match(C2105052Parser::RPAREN);

              int if_label_index = -1;

              string str = "\tPOP AX\t\t; line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->ex->line);
              asmFile << str << endl;
              stack_offset -= 2; // Decrease stack offset by 2 for if condition
              str = "\tCMP AX, 0\t\t; line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->ex->line);
              asmFile << str << endl;
              str = "\tJE L" + std::to_string(label_count) + "\t\t; line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->ex->line);
              asmFile << str << endl;
              if_label_index = label_count; // Store the index of the if label for later use
              label_count++; // Increment label count for the next label

              



          
      setState(239);
      antlrcpp::downCast<StatementContext *>(_localctx)->s1 = statement();

              int jump_at_end = label_count;
               str = "\tJMP L" + std::to_string(label_count) + "\t\t; line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->s1->line);
              asmFile << str << endl;
              label_count++; // Increment label count for the next label
          
      setState(241);
      match(C2105052Parser::ELSE);

              str = "L" + std::to_string(if_label_index) + ":";
              asmFile << str << endl;
              
              if_label_index = -1; // Reset the index after using it
          
      setState(243);
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


              str = "L" + std::to_string(jump_at_end) + ":";
              asmFile << str << endl;

              


          
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(246);
      match(C2105052Parser::WHILE);

              int while_loop_condition_label = -1;
              int while_loop_end_label_index = -1;
              
              string cd = "L" + std::to_string(label_count) + ":";
              while_loop_condition_label = label_count;
              label_count++;
              asmFile << cd << endl;;

          
      setState(248);
      match(C2105052Parser::LPAREN);
      setState(249);
      antlrcpp::downCast<StatementContext *>(_localctx)->expressionContext = expression();

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
      match(C2105052Parser::RPAREN);
      setState(252);
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

              ss = "\tJMP L" + std::to_string(while_loop_condition_label) + "\t\t; line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->statementContext->line);
              asmFile << ss << endl;
              ss = "L" + std::to_string(while_loop_end_label_index) + ":";
              asmFile << ss << endl;

          
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(255);
      match(C2105052Parser::PRINTLN);
      setState(256);
      match(C2105052Parser::LPAREN);
      setState(257);
      antlrcpp::downCast<StatementContext *>(_localctx)->idToken = match(C2105052Parser::ID);
      setState(258);
      match(C2105052Parser::RPAREN);
      setState(259);
      match(C2105052Parser::SEMICOLON);

              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getLine()) + ": statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n");
              antlrcpp::downCast<StatementContext *>(_localctx)->code =  vector<string>();
              _localctx->code.push_back("printf(" + antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getText() + ");");
              writeIntoparserLogFile(_localctx->code.back() + "\n");
              antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getLine();
              string str;
              SymbolInfo *s = symbolTable->look_up_in_all_scope(antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getText());
              






              str+="L"+std::to_string(label_count) + ":";
              label_count++;
              asmFile << str << endl;
              if(s!=nullptr){ 
                  if(s->getScopeId()==1){
                      str = "\tMOV AX, " + antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getText() + "\t\t; line" + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getLine());
                      asmFile << str << endl;
                      str = "\tCALL print_output";
                      asmFile << str << endl;
                      str = "\tCALL new_line";
                      asmFile << str << endl;
                  }
                  else{

                      str = "\tMOV AX, [BP" + std::string((s->getOffset() >= 0) ? "-" : "+") + std::to_string(std::abs(s->getOffset())) + "]\t\t; line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getLine());
                      asmFile << str << endl;
                      str = "\tCALL print_output";
                      asmFile << str << endl;
                      str = "\tCALL new_line";
                      asmFile << str << endl;
                  }
              }
              else{
                  str = "\tMOV AX, " + antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getText() + "\t\t; line" + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getLine());
                  asmFile << str << endl;
                  str = "\tCALL print_output";
                  asmFile << str << endl;
                  str = "\tCALL new_line";
                  asmFile << str << endl;
              }
              

              
          
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(261);
      antlrcpp::downCast<StatementContext *>(_localctx)->returnToken = match(C2105052Parser::RETURN);
      setState(262);
      antlrcpp::downCast<StatementContext *>(_localctx)->expr = expression();
      setState(263);
      match(C2105052Parser::SEMICOLON);

              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->expr->line) + ": statement : RETURN expression SEMICOLON\n");
              antlrcpp::downCast<StatementContext *>(_localctx)->code =  vector<string>();
              _localctx->code.push_back(antlrcpp::downCast<StatementContext *>(_localctx)->returnToken->getText() + " " + antlrcpp::downCast<StatementContext *>(_localctx)->expr->str + ";");
              writeIntoparserLogFile(_localctx->code.back() + "\n");
              antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->expr->line;
              

              string str;
              str = "L" + std::to_string(label_count) + ":";
              label_count++;
              asmFile << str << endl;
              SymbolInfo *s = symbolTable->look_up_in_all_scope(antlrcpp::downCast<StatementContext *>(_localctx)->expr->str);
              if(s!=nullptr){
                  if(s->getScopeId()==1){
                      str = "\tMOV AX, " + antlrcpp::downCast<StatementContext *>(_localctx)->expr->str + "\t\t; line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->expr->line);
                      asmFile << str << endl;   
                  }
                  else{
                      str = "\tMOV AX, [BP" + std::string((s->getOffset() >= 0) ? "-" : "+") + std::to_string(std::abs(s->getOffset())) + "]\t\t; line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->expr->line);
                      asmFile << str << endl;
                  }
              }
              else{
                  str = "\tPOP AX\t\t; line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->expr->line);
                  asmFile << str << endl;
              }
              str = "\tJMP L" + std::to_string(func_return_label) + "\t\t; line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->expr->line);
              asmFile << str << endl;
          
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

void C2105052Parser::Expression_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_statement(this);
}

void C2105052Parser::Expression_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_statement(this);
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
    setState(274);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C2105052Parser::SEMICOLON: {
        enterOuterAlt(_localctx, 1);
        setState(268);
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
        setState(270);
        antlrcpp::downCast<Expression_statementContext *>(_localctx)->exp = expression();
        setState(271);
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

void C2105052Parser::VariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable(this);
}

void C2105052Parser::VariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable(this);
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
    setState(284);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(276);
      antlrcpp::downCast<VariableContext *>(_localctx)->idToken = match(C2105052Parser::ID);

              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine()) + ": variable : ID\n");
              writeIntoparserLogFile(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() + "\n");
              antlrcpp::downCast<VariableContext *>(_localctx)->varName =  antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText();
              antlrcpp::downCast<VariableContext *>(_localctx)->line =  antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine();
           
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(278);
      antlrcpp::downCast<VariableContext *>(_localctx)->idToken = match(C2105052Parser::ID);
      setState(279);
      match(C2105052Parser::LTHIRD);
      setState(280);
      antlrcpp::downCast<VariableContext *>(_localctx)->expressionContext = expression();
      setState(281);
      match(C2105052Parser::RTHIRD);
       
              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine()) + ": variable : ID LTHIRD expression RTHIRD\n");
              string str = antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() + "[" + antlrcpp::downCast<VariableContext *>(_localctx)->expressionContext->str + "]";
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

void C2105052Parser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void C2105052Parser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
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
    setState(294);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(286);
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
      setState(289);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->var = variable();
      setState(290);
      match(C2105052Parser::ASSIGNOP);
      setState(291);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->l_expr = logic_expression();

              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<ExpressionContext *>(_localctx)->l_expr->line) + ": expression : variable ASSIGNOP logic_expression\n");
              antlrcpp::downCast<ExpressionContext *>(_localctx)->str =  antlrcpp::downCast<ExpressionContext *>(_localctx)->var->varName + "=";
              string logicExpr;
              for (const auto &term : antlrcpp::downCast<ExpressionContext *>(_localctx)->l_expr->rel_expr){
                  _localctx->str += term;
                  logicExpr += term;
              }
              antlrcpp::downCast<ExpressionContext *>(_localctx)->line =  antlrcpp::downCast<ExpressionContext *>(_localctx)->l_expr->line;
              writeIntoparserLogFile(_localctx->str + "\n");
              

              handle_assign_op(symbolTable, antlrcpp::downCast<ExpressionContext *>(_localctx)->var->varName, stack_offset);
          
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

void C2105052Parser::Logic_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogic_expression(this);
}

void C2105052Parser::Logic_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogic_expression(this);
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
    setState(306);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(296);
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
      setState(299);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r1 = rel_expression();

              string str;
              string temp = "L" + std::to_string(label_count) + ":";
              label_count++;
              asmFile << temp << endl;

                  str = "\tPOP AX\t\t; line " + std::to_string(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r1->line);
                  asmFile << str << endl;
                  stack_offset -= 2; // Decrease stack offset by 2 for logic expression
              

          
      setState(301);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken = match(C2105052Parser::LOGICOP);

              temp = antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken->getText();
              int logic_op_on_false_jump_label = -1; // Initialize the logic operation jump label index
              int logic_op_on_true_jump_label = -1; // Initialize the logic operation jump label index
              if(temp=="||"){
                  temp = "\tCMP AX, 0";
                  asmFile << temp << endl;
                  temp = "\tJNE L" + std::to_string(label_count) + "\t\t; line " + std::to_string(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r1->line);
                  asmFile << temp << endl;
                  logic_op_on_true_jump_label = label_count; // Store the index of the logic operation jump label for later use
                  label_count++; // Increment label count for the next label
                  
              }
              else if(temp=="&&"){
                  temp = "\tCMP AX, 0";
                  asmFile << temp << endl;
                  temp = "\tJE L" + std::to_string(label_count) + "\t\t; line " + std::to_string(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r1->line);
                  asmFile << temp << endl;
                  logic_op_on_false_jump_label = label_count; // Store the index of the logic operation jump label for later use
                  label_count++; // Increment label count for the next label
              }



          
      setState(303);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r2 = rel_expression();

              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r1->line) + ": logic_expression : rel_expression LOGICOP rel_expression\n");
              antlrcpp::downCast<Logic_expressionContext *>(_localctx)->rel_expr =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r1->simple_expr;
              _localctx->rel_expr.push_back(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken->getText());
              for (const auto &term : antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r2->simple_expr){
                  _localctx->rel_expr.push_back(term);
              }
              antlrcpp::downCast<Logic_expressionContext *>(_localctx)->line =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r1->line;
              for (const auto &term : _localctx->rel_expr) {
                  str += term;
              }
              writeIntoparserLogFile(str + "\n");



              


              if(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken->getText()=="||"){

                      str = "\tPOP AX";
                      asmFile << str << endl;
                      stack_offset -= 2;
                  

                  str = "\tCMP AX, 0";
                  asmFile << str << endl;
                  str = "\tJE L" + std::to_string(label_count) + "\t\t; line " + std::to_string(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r1->line);
                  asmFile << str << endl;

                  str = "L" + std::to_string(logic_op_on_true_jump_label) + ":";
                  asmFile << str << endl;
                  str = "\tMOV AX, 1";
                  asmFile << str << endl;
                  str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r1->line);
                  asmFile << str << endl;
                  str = "L" + std::to_string(label_count) + ":";
                  label_count++;
                  asmFile << str << endl;
                  str = "\tMOV AX, 0\t\t; line " + std::to_string(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r1->line);
                  asmFile << str << endl;

                  str = "L" + std::to_string(label_count) + ":";
                  asmFile << str << endl;
                  str = "\tPUSH AX\t\t; line " + std::to_string(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r1->line);
                  asmFile << str << endl;
                  stack_offset += 2; // Increase stack offset by 2 for logic expression
                  label_count++;
              }

              else if(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken->getText() == "&&"){

                      str = "\tPOP AX";
                      asmFile << str << endl;
                      stack_offset -= 2;


                  str = "\tCMP AX, 0";
                  asmFile << str << endl;
                  str = "\tJE L" + std::to_string(logic_op_on_false_jump_label) + "\t\t; line " + std::to_string(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r1->line);
                  asmFile << str << endl;

                  str = "L" + std::to_string(label_count) + ":";
                  label_count++;
                  asmFile << str << endl;
                  str = "\tMOV AX, 1";
                  asmFile << str << endl;
                  str = "\tJMP L" + std::to_string(label_count) + "\t\t; line " + std::to_string(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r1->line);
                  asmFile << str << endl;
                  str = "L" + std::to_string(logic_op_on_false_jump_label) + ":";
                  asmFile << str << endl;
                  str = "\tMOV AX, 0\t\t; line " + std::to_string(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r1->line);
                  asmFile << str << endl;

                  str = "L" + std::to_string(label_count) + ":";
                  asmFile << str << endl;
                  str = "\tPUSH AX\t\t; line " + std::to_string(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r1->line);
                  asmFile << str << endl;
                  stack_offset += 2; // Increase stack offset by 2 for logic expression
                  label_count++;
              
              }





          
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

void C2105052Parser::Rel_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRel_expression(this);
}

void C2105052Parser::Rel_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRel_expression(this);
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
    setState(316);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(308);
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
      setState(311);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr = simple_expression(0);
      setState(312);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken = match(C2105052Parser::RELOP);
      setState(313);
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
              
              if(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getText() == "<="){
                  str = "\tCMP AX, DX";
                  asmFile << str << endl;
                  str = "\tJLE L" + std::to_string(label_count) + "\t\t; line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr->line);
                  asmFile << str << endl;
                  str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr->line);
                  asmFile << str << endl;
                  str = "L" + std::to_string(label_count) + ":";
                  label_count++;
                  asmFile << str << endl;
                  str = "\tMOV AX, 1\t\t; line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr->line);
                  asmFile << str << endl;
                  str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr->line);
                  asmFile << str << endl;
                  str = "L" + std::to_string(label_count) + ":";
                  label_count++;
                  asmFile << str << endl;
                  str = "\tMOV AX, 0\t\t; line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr->line);
                  asmFile << str << endl;
                  str = "L" + std::to_string(label_count) + ":";
                  label_count++;
                  asmFile << str << endl;
                  str = "\tPUSH AX\t\t; line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr->line);
                  asmFile << str << endl;
                  stack_offset += 2;
                  
              }


              else if(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getText() == "<"){
                  str = "\tCMP AX, DX";
                  asmFile << str << endl;
                  str = "\tJL L" + std::to_string(label_count) + "\t\t; line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr->line);
                  asmFile << str << endl;
                  str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr->line);
                  asmFile << str << endl;
                  str = "L" + std::to_string(label_count) + ":";
                  label_count++;
                  asmFile << str << endl;
                  str = "\tMOV AX, 1\t\t; line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr->line);
                  asmFile << str << endl;
                  str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr->line);
                  asmFile << str << endl;
                  str = "L" + std::to_string(label_count) + ":";
                  label_count++;
                  asmFile << str << endl;
                  str = "\tMOV AX, 0\t\t; line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr->line);
                  asmFile << str << endl;
                  str = "L" + std::to_string(label_count) + ":";
                  label_count++;
                  asmFile << str << endl;
                  str = "\tPUSH AX\t\t; line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr->line);
                  asmFile << str << endl;
                  stack_offset += 2;
              }
              else if(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getText() == ">="){
                  str = "\tCMP AX, DX";
                  asmFile << str << endl;
                  str = "\tJGE L" + std::to_string(label_count) + "\t\t; line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr->line);
                  asmFile << str << endl;
                  str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr->line);
                  asmFile << str << endl;
                  str = "L" + std::to_string(label_count) + ":";
                  label_count++;
                  asmFile << str << endl;
                  str = "\tMOV AX, 1\t\t; line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr->line);
                  asmFile << str << endl;
                  str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr->line);
                  asmFile << str << endl;
                  str = "L" + std::to_string(label_count) + ":";
                  label_count++;
                  asmFile << str << endl;
                  str = "\tMOV AX, 0\t\t; line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr->line);
                  asmFile << str << endl;
                  str = "L" + std::to_string(label_count) + ":";
                  label_count++;
                  asmFile << str << endl;
                  str = "\tPUSH AX\t\t; line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr->line);
                  asmFile << str << endl;
                  stack_offset += 2;
              }

              else if(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getText() == ">"){
                  str = "\tCMP AX, DX";
                  asmFile << str << endl;
                  str = "\tJG L" + std::to_string(label_count) + "\t\t; line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr->line);
                  asmFile << str << endl;
                  str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr->line);
                  asmFile << str << endl;
                  str = "L" + std::to_string(label_count) + ":";
                  label_count++;
                  asmFile << str << endl;
                  str = "\tMOV AX, 1\t\t; line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr->line);
                  asmFile << str << endl;
                  str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr->line);
                  asmFile << str << endl;
                  str = "L" + std::to_string(label_count) + ":";
                  label_count++;
                  asmFile << str << endl;
                  str = "\tMOV AX, 0\t\t; line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr->line);
                  asmFile << str << endl;
                  str = "L" + std::to_string(label_count) + ":";
                  label_count++;
                  asmFile << str << endl;
                  str = "\tPUSH AX\t\t; line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr->line);
                  asmFile << str << endl;
                  stack_offset += 2;
              }
              else if(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getText() == "=="){
                  str = "\tCMP AX, DX";
                  asmFile << str << endl;
                  str = "\tJE L" + std::to_string(label_count) + "\t\t; line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr->line);
                  asmFile << str << endl;
                  str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr->line);
                  asmFile << str << endl;
                  str = "L" + std::to_string(label_count) + ":";
                  label_count++;
                  asmFile << str << endl;
                  str = "\tMOV AX, 1\t\t; line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr->line);
                  asmFile << str << endl;
                  str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr->line);
                  asmFile << str << endl;
                  str = "L" + std::to_string(label_count) + ":";
                  label_count++;
                  asmFile << str << endl;
                  str = "\tMOV AX, 0\t\t; line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr->line);
                  asmFile << str << endl;
                  str = "L" + std::to_string(label_count) + ":";
                  label_count++;
                  asmFile << str << endl;
                  str = "\tPUSH AX\t\t; line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr->line);
                  asmFile << str << endl;
                  stack_offset += 2; 
              }
              else if(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getText() == "!="){
                  str = "\tCMP AX, DX";
                  asmFile << str << endl;
                  str = "\tJNE L" + std::to_string(label_count) + "\t\t; line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr->line);
                  asmFile << str << endl;
                  str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr->line);
                  asmFile << str << endl;
                  str = "L" + std::to_string(label_count) + ":";
                  label_count++;
                  asmFile << str << endl;
                  str = "\tMOV AX, 1\t\t; line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr->line);
                  asmFile << str << endl;
                  str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr->line);
                  asmFile << str << endl;
                  str = "L" + std::to_string(label_count) + ":";
                  label_count++;
                  asmFile << str << endl;
                  str = "\tMOV AX, 0\t\t; line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr->line);
                  asmFile << str << endl;
                  str = "L" + std::to_string(label_count) + ":";
                  label_count++;
                  asmFile << str << endl;
                  str = "\tPUSH AX\t\t; line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s_expr->line);
                  asmFile << str << endl;
                  stack_offset += 2;
              }



          
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


size_t C2105052Parser::Simple_expressionContext::getRuleIndex() const {
  return C2105052Parser::RuleSimple_expression;
}

void C2105052Parser::Simple_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_expression(this);
}

void C2105052Parser::Simple_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_expression(this);
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
    setState(319);
    antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t = term(0);

            writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->line) + ": simple_expression : term\n");
            antlrcpp::downCast<Simple_expressionContext *>(_localctx)->terms =  { antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->trm };
            antlrcpp::downCast<Simple_expressionContext *>(_localctx)->line =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->line;
            writeIntoparserLogFile(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->trm + "\n");
        
    _ctx->stop = _input->LT(-1);
    setState(329);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Simple_expressionContext>(parentContext, parentState);
        _localctx->s = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleSimple_expression);
        setState(322);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(323);
        antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken = match(C2105052Parser::ADDOP);
        setState(324);
        antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t = term(0);

                          writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->s->line) + ": simple_expression : simple_expression ADDOP term\n");
                          antlrcpp::downCast<Simple_expressionContext *>(_localctx)->terms =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->s->terms;
                          _localctx->terms.push_back(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken->getText());
                          _localctx->terms.push_back(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->trm);
                          // // cout<< antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->trm << endl;
                          antlrcpp::downCast<Simple_expressionContext *>(_localctx)->line =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->s->line;
                          string str;
                          for (const auto &term : _localctx->terms) {
                              str += term;
                          }
                          _localctx->terms.clear();
                          _localctx->terms.push_back(str);
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
                          for (const auto &term : antlrcpp::downCast<Simple_expressionContext *>(_localctx)->s->terms) {
                              s_term_merge += term;
                          }


                              str = "\tPOP AX";
                              asmFile << str << endl;
                              stack_offset -= 2;
                          
                          if (antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken->getText() == "+") {
                              str = "\tADD AX, DX";
                              asmFile << str << endl;
                              str = "\tPUSH AX\t\t; line " + std::to_string(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->s->line);
                              asmFile << str << endl;
                              stack_offset += 2;
                          }
                          else if (antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken->getText() == "-") {
                              str = "\tSUB AX, DX";
                              asmFile << str << endl;
                              str = "\tPUSH AX\t\t; line " + std::to_string(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->s->line);
                              asmFile << str << endl;
                              stack_offset += 2;
                          } 



                       
      }
      setState(331);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
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

void C2105052Parser::TermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerm(this);
}

void C2105052Parser::TermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerm(this);
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
    setState(333);
    antlrcpp::downCast<TermContext *>(_localctx)->u_expr = unary_expression();

            writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<TermContext *>(_localctx)->u_expr->line) + ": term : unary_expression\n");
            antlrcpp::downCast<TermContext *>(_localctx)->trm =  antlrcpp::downCast<TermContext *>(_localctx)->u_expr->unary_expr;
            antlrcpp::downCast<TermContext *>(_localctx)->line =  antlrcpp::downCast<TermContext *>(_localctx)->u_expr->line;
            writeIntoparserLogFile(_localctx->trm + "\n");
        
    _ctx->stop = _input->LT(-1);
    setState(346);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(344);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<TermContext>(parentContext, parentState);
          _localctx->t = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleTerm);
          setState(336);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(337);
          antlrcpp::downCast<TermContext *>(_localctx)->mulopToken = match(C2105052Parser::MULOP);
          setState(338);
          antlrcpp::downCast<TermContext *>(_localctx)->u = unary_expression();

                            writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<TermContext *>(_localctx)->t->line) + ": term : term MULOP unary_expression\n");
                            antlrcpp::downCast<TermContext *>(_localctx)->trm =  antlrcpp::downCast<TermContext *>(_localctx)->t->trm  + antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getText() + antlrcpp::downCast<TermContext *>(_localctx)->u->unary_expr;
                            antlrcpp::downCast<TermContext *>(_localctx)->line =  antlrcpp::downCast<TermContext *>(_localctx)->t->line;
                            writeIntoparserLogFile(_localctx->trm + "\n");



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
                            if (antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getText() == "*") {
                                str = "\tMUL CX";
                                asmFile << str << endl;
                                str = "\tPUSH AX\t\t; line " + std::to_string(antlrcpp::downCast<TermContext *>(_localctx)->t->line);
                                asmFile << str << endl;
                                stack_offset += 2;

                            } 
                            else if( antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getText() == "/") {
                                str = "\tDIV CX";
                                asmFile << str << endl;
                                str = "\tPUSH AX\t\t; line " + std::to_string(antlrcpp::downCast<TermContext *>(_localctx)->t->line);
                                asmFile << str << endl;
                                stack_offset += 2;
                            }
                            else{
                                str = "\tDIV CX";
                                asmFile << str << endl;
                                str = "\tPUSH DX\t\t; line " + std::to_string(antlrcpp::downCast<TermContext *>(_localctx)->t->line);
                                asmFile << str << endl;
                                stack_offset += 2;
                            }
                            
                        
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<TermContext>(parentContext, parentState);
          _localctx->t = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleTerm);
          setState(341);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(342);
          antlrcpp::downCast<TermContext *>(_localctx)->unrecognizedToken = match(C2105052Parser::UNRECOGNIZED);

                            writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<TermContext *>(_localctx)->unrecognizedToken->getLine()) + ": Unrecognized character " + antlrcpp::downCast<TermContext *>(_localctx)->unrecognizedToken->getText()+"\n");
                            writeIntoparserLogFile("Error at line " + std::to_string(antlrcpp::downCast<TermContext *>(_localctx)->unrecognizedToken->getLine()) + ": Unrecognized character " + antlrcpp::downCast<TermContext *>(_localctx)->unrecognizedToken->getText()+"\n");
                            syntaxErrorCount++;
                            // // cout<<"Error at line "<<antlrcpp::downCast<TermContext *>(_localctx)->unrecognizedToken->getLine()<<": "<<antlrcpp::downCast<TermContext *>(_localctx)->unrecognizedToken->getText()<<" is not a valid token"<<endl;
                            antlrcpp::downCast<TermContext *>(_localctx)->trm = antlrcpp::downCast<TermContext *>(_localctx)->t->trm;
                            // // cout<<"Term at "<<antlrcpp::downCast<TermContext *>(_localctx)->t->line<<": "<<_localctx->trm<<endl;
                            antlrcpp::downCast<TermContext *>(_localctx)->line =  antlrcpp::downCast<TermContext *>(_localctx)->t->line;
                        
          break;
        }

        default:
          break;
        } 
      }
      setState(348);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
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

void C2105052Parser::Unary_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnary_expression(this);
}

void C2105052Parser::Unary_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnary_expression(this);
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
    setState(360);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C2105052Parser::ADDOP: {
        enterOuterAlt(_localctx, 1);
        setState(349);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->addopToken = match(C2105052Parser::ADDOP);
        setState(350);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expressionContext = unary_expression();

                writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expressionContext->line) + ": unary_expression : ADDOP unary_expression\n");
                antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expr =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->addopToken->getText() + antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expressionContext->unary_expr;
                antlrcpp::downCast<Unary_expressionContext *>(_localctx)->line =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expressionContext->line;
                writeIntoparserLogFile(_localctx->unary_expr + "\n");


                string str;
                str = "L" + std::to_string(label_count) + ":";
                    label_count++;
                    asmFile << str << endl;

                    str = "\tPOP AX";
                    asmFile << str << endl;
                    stack_offset -= 2;

                if (antlrcpp::downCast<Unary_expressionContext *>(_localctx)->addopToken->getText() == "+") {
                    str = "\tPUSH AX\t\t; line " + std::to_string(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expressionContext->line);
                    asmFile << str << endl;
                    stack_offset += 2;
                }
                else if (antlrcpp::downCast<Unary_expressionContext *>(_localctx)->addopToken->getText() == "-") {
                    str = "\tNEG AX\t\t; line " + std::to_string(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expressionContext->line);
                    asmFile << str << endl;
                    str = "\tPUSH AX\t\t; line " + std::to_string(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expressionContext->line);
                    asmFile << str << endl;
                    stack_offset += 2;
                }



            
        break;
      }

      case C2105052Parser::NOT: {
        enterOuterAlt(_localctx, 2);
        setState(353);
        match(C2105052Parser::NOT);
        setState(354);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expressionContext = unary_expression();

                writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expressionContext->line) + ": unary_expression : NOT unary_expression\n");
                antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expr =  "!" + antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expressionContext->unary_expr;
                antlrcpp::downCast<Unary_expressionContext *>(_localctx)->line =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expressionContext->line;
                writeIntoparserLogFile(_localctx->unary_expr + "\n");


                string str;
                str = "L" + std::to_string(label_count) + ":";
                label_count++;
                asmFile << str << endl;
                str = "\tPOP AX\t\t; line " + std::to_string(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expressionContext->line);
                asmFile << str << endl;
                stack_offset -= 2; // Decrease stack offset by 2 for unary expression
                str = "\tCMP AX, 0";
                asmFile << str << endl;
                str = "\tJE L" + std::to_string(label_count) + "\t\t; line " + std::to_string(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expressionContext->line);
                asmFile << str << endl;
                str = "\tMOV AX, 0";
                asmFile << str << endl;
                str = "\tJMP L" + std::to_string(label_count+1) + "\t\t; line " + std::to_string(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expressionContext->line);
                asmFile << str << endl;
                str = "L" + std::to_string(label_count) + ":";
                asmFile << str << endl;
                label_count++;
                str = "\tMOV AX, 1\t\t; line " + std::to_string(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expressionContext->line);
                asmFile << str << endl;
                str = "L" + std::to_string(label_count) + ":";
                asmFile << str << endl;
                label_count++;
                str = "\tPUSH AX\t\t; line " + std::to_string(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expressionContext->line);
                asmFile << str << endl;
                stack_offset += 2; // Increase stack offset by 2 for unary expression


            
        break;
      }

      case C2105052Parser::LPAREN:
      case C2105052Parser::ID:
      case C2105052Parser::CONST_INT:
      case C2105052Parser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 3);
        setState(357);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->fact = factor();

                antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expr =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->fact->factorName;
                antlrcpp::downCast<Unary_expressionContext *>(_localctx)->line =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->fact->line;

          
            
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

void C2105052Parser::FactorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFactor(this);
}

void C2105052Parser::FactorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFactor(this);
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
    setState(388);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(362);
      antlrcpp::downCast<FactorContext *>(_localctx)->var = variable();
       
              antlrcpp::downCast<FactorContext *>(_localctx)->factorName =  antlrcpp::downCast<FactorContext *>(_localctx)->var->varName;
              antlrcpp::downCast<FactorContext *>(_localctx)->line =  antlrcpp::downCast<FactorContext *>(_localctx)->var->line;


              string str;
              string var;
              int pos = antlrcpp::downCast<FactorContext *>(_localctx)->var->varName.find("[");
              if (pos != std::string::npos) {
                  var = antlrcpp::downCast<FactorContext *>(_localctx)->var->varName.substr(0, pos);
              } else {
                  var = antlrcpp::downCast<FactorContext *>(_localctx)->var->varName;
              }
              str = "L" + std::to_string(label_count) + ":";
              label_count++;
              asmFile << str << endl;
              if(antlrcpp::downCast<FactorContext *>(_localctx)->var->varName != var){
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
                  SymbolInfo *s = symbolTable->look_up_in_all_scope(antlrcpp::downCast<FactorContext *>(_localctx)->var->varName);
                  if(s!=nullptr){
                      if(s->getScopeId()==1){
                          str = "\tMOV AX, " + antlrcpp::downCast<FactorContext *>(_localctx)->var->varName + "\t\t; line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->var->line);
                          asmFile << str << endl;
                      }
                      else{
                          str = "\tMOV AX, [BP" + std::string((s->getOffset() >= 0) ? "-" : "+") + std::to_string(std::abs(s->getOffset())) + "]\t\t; line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->var->line);
                          asmFile << str << endl;
                      }
                  }
                  else{
                      str = "\tPOP AX";
                      asmFile << str << endl;
                      stack_offset -= 2;
                  }
                  str = "\tPUSH AX\t\t; line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->var->line);
                  asmFile << str << endl;
                  stack_offset += 2;
              }

          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(365);
      antlrcpp::downCast<FactorContext *>(_localctx)->idToken = match(C2105052Parser::ID);
      setState(366);
      match(C2105052Parser::LPAREN);
      setState(367);
      antlrcpp::downCast<FactorContext *>(_localctx)->ar = argument_list();
      setState(368);
      match(C2105052Parser::RPAREN);
       
              antlrcpp::downCast<FactorContext *>(_localctx)->factorName =  antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText() + "(";
              for (const auto &term : antlrcpp::downCast<FactorContext *>(_localctx)->ar->arg) {
                  _localctx->factorName += term;
                  if (&term != &(antlrcpp::downCast<FactorContext *>(_localctx)->ar->arg.back())) {
                      _localctx->factorName += ",";
                  }
              }
              _localctx->factorName += ")";
              antlrcpp::downCast<FactorContext *>(_localctx)->line =  antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getLine();



              string str;
              str = "L" + std::to_string(label_count) + ":";
              label_count++;
              asmFile << str << endl;
              str = "\tCALL " + antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText() + "\t\t; line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getLine());
              asmFile << str << endl;
              str = "\tPUSH AX\t\t; line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getLine());
              asmFile << str << endl;
              stack_offset += 2;
          
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(371);
      match(C2105052Parser::LPAREN);
      setState(372);
      antlrcpp::downCast<FactorContext *>(_localctx)->exp = expression();
      setState(373);
      match(C2105052Parser::RPAREN);

              antlrcpp::downCast<FactorContext *>(_localctx)->factorName =  "(" + antlrcpp::downCast<FactorContext *>(_localctx)->exp->str + ")";
              antlrcpp::downCast<FactorContext *>(_localctx)->line =  antlrcpp::downCast<FactorContext *>(_localctx)->exp->line;
          
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(376);
      antlrcpp::downCast<FactorContext *>(_localctx)->c_int = match(C2105052Parser::CONST_INT);

              antlrcpp::downCast<FactorContext *>(_localctx)->factorName =  antlrcpp::downCast<FactorContext *>(_localctx)->c_int->getText();
              antlrcpp::downCast<FactorContext *>(_localctx)->line =  antlrcpp::downCast<FactorContext *>(_localctx)->c_int->getLine();

              string str;
              str+="L"+std::to_string(label_count)+ ":";
              label_count++;
              asmFile << str << endl;
              str = "\tMOV AX, "+antlrcpp::downCast<FactorContext *>(_localctx)->c_int->getText()+"\t\t; line "+std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->c_int->getLine());
              asmFile << str << endl;
              str = "\tPUSH AX";
              asmFile << str << endl;
              stack_offset += 2;
              
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(378);
      antlrcpp::downCast<FactorContext *>(_localctx)->c_float = match(C2105052Parser::CONST_FLOAT);

              antlrcpp::downCast<FactorContext *>(_localctx)->factorName =  antlrcpp::downCast<FactorContext *>(_localctx)->c_float->getText();
              antlrcpp::downCast<FactorContext *>(_localctx)->line =  antlrcpp::downCast<FactorContext *>(_localctx)->c_float->getLine();
          
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(380);
      antlrcpp::downCast<FactorContext *>(_localctx)->variableContext = variable();
      setState(381);
      match(C2105052Parser::INCOP);
       
              antlrcpp::downCast<FactorContext *>(_localctx)->factorName =  antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->varName + "++";
              antlrcpp::downCast<FactorContext *>(_localctx)->line =  antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->line;


              string str;
              string var;
              int pos = antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->varName.find("[");
              if (pos != std::string::npos) {
                  var = antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->varName.substr(0, pos);
              } 
              else {
                  var = antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->varName;
              }
              if(antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->varName != var){
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
              SymbolInfo *s = symbolTable->look_up_in_all_scope(antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->varName);
               
              str = "L" + std::to_string(label_count) + ":";
              label_count++;
              asmFile << str << endl;

              if(s!=nullptr){
                  if(s->getScopeId()==1){
                      str = "\tMOV AX, " + antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->varName + "\t\t; line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->line);
                      asmFile << str << endl;
                  }
                  else{
                      str = "\tMOV AX, [BP" + std::string((s->getOffset() >= 0) ? "-" : "+") + std::to_string(std::abs(s->getOffset())) + "]\t\t; line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->line);
                      asmFile << str << endl;
                  }
              }
              else{
                  str = "\tPOP AX";
                  asmFile << str << endl;
                  stack_offset -= 2;
              }
              str = "\tPUSH AX\t\t; line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->line);
              asmFile << str << endl;
              stack_offset += 2;
              str = "\tINC AX\t\t; line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->line);
              asmFile << str << endl;

              str = "\tMOV [BP" + std::string((s->getOffset() >= 0) ? "-" : "+") + std::to_string(std::abs(s->getOffset())) + "], AX\t\t; line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->line);
              asmFile << str << endl;
              }

          
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(384);
      antlrcpp::downCast<FactorContext *>(_localctx)->variableContext = variable();
      setState(385);
      match(C2105052Parser::DECOP);

              antlrcpp::downCast<FactorContext *>(_localctx)->factorName =  antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->varName + "--";
              antlrcpp::downCast<FactorContext *>(_localctx)->line =  antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->line;


              string str;
              string var;
              int pos = antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->varName.find("[");
              if (pos != std::string::npos) {
                  var = antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->varName.substr(0, pos);
              } 
              else {
                  var = antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->varName;
              }
              if(antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->varName != var){
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
              SymbolInfo *s = symbolTable->look_up_in_all_scope(antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->varName);
              str = "L" + std::to_string(label_count) + ":";
              label_count++;
              asmFile << str << endl;

              if(s!=nullptr){
                  if(s->getScopeId()==1){
                      str = "\tMOV AX, " + antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->varName + "\t\t; line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->line);
                      asmFile << str << endl;
                  }
                  else{
                      str = "\tMOV AX, [BP" + std::string((s->getOffset() >= 0) ? "-" : "+") + std::to_string(std::abs(s->getOffset())) + "]\t\t; line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->line);
                      asmFile << str << endl;
                  }
              }
              else{
                  str = "\tPOP AX";
                  asmFile << str << endl;
                  stack_offset -= 2;
              }
              str = "\tPUSH AX\t\t; line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->line);
              asmFile << str << endl;
              stack_offset += 2;
              str = "\tDEC AX\t\t; line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->line);
              asmFile << str << endl;
              str = "\tMOV [BP" + std::string((s->getOffset() >= 0) ? "-" : "+") + std::to_string(std::abs(s->getOffset())) + "], AX\t\t; line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->line);
              asmFile << str << endl;

              }
          
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

void C2105052Parser::Argument_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgument_list(this);
}

void C2105052Parser::Argument_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgument_list(this);
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
    setState(394);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C2105052Parser::LPAREN:
      case C2105052Parser::ADDOP:
      case C2105052Parser::NOT:
      case C2105052Parser::ID:
      case C2105052Parser::CONST_INT:
      case C2105052Parser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 1);
        setState(390);
        antlrcpp::downCast<Argument_listContext *>(_localctx)->ar = arguments(0);
         
                antlrcpp::downCast<Argument_listContext *>(_localctx)->arg =  antlrcpp::downCast<Argument_listContext *>(_localctx)->ar->arg;
            
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

void C2105052Parser::ArgumentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArguments(this);
}

void C2105052Parser::ArgumentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105052ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArguments(this);
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
    setState(397);
    antlrcpp::downCast<ArgumentsContext *>(_localctx)->l = logic_expression();
     
            antlrcpp::downCast<ArgumentsContext *>(_localctx)->arg =  std::vector<std::string>();
            for (const auto &term : antlrcpp::downCast<ArgumentsContext *>(_localctx)->l->rel_expr) {
                _localctx->arg.push_back(term);
            }
            string str;
            for (const auto &term : _localctx->arg) {
                str += term;
            }
            _localctx->arg.clear();
            _localctx->arg.push_back(str);
            antlrcpp::downCast<ArgumentsContext *>(_localctx)->line =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->l->line;

        
    _ctx->stop = _input->LT(-1);
    setState(407);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ArgumentsContext>(parentContext, parentState);
        _localctx->ar = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleArguments);
        setState(400);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(401);
        match(C2105052Parser::COMMA);
        setState(402);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->l = logic_expression();
         
                          antlrcpp::downCast<ArgumentsContext *>(_localctx)->arg =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->ar->arg;
                          string ab;
                          for (const auto &term : antlrcpp::downCast<ArgumentsContext *>(_localctx)->l->rel_expr) {
                              ab += term;
                          }
                          _localctx->arg.push_back(ab);
                          antlrcpp::downCast<ArgumentsContext *>(_localctx)->line =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->l->line;
                       
      }
      setState(409);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
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
    case 6: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C2105052Parser::termSempred(TermContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 7: return precpred(_ctx, 2);
    case 8: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C2105052Parser::argumentsSempred(ArgumentsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 9: return precpred(_ctx, 2);

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
