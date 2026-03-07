#include <iostream>
#include <fstream>
#include <string>
#include "antlr4-runtime.h"
#include "C2105052Lexer.h"
#include "C2105052Parser.h"
#include "optimizer.cpp"
using namespace antlr4;
using namespace std;

ofstream parserLogFile; // global output stream
ofstream errorFile; // global error stream
ofstream lexLogFile; // global lexer log stream
ofstream asmFile; // global asm file stream
ofstream tempFile; // global temp file stream

vector<pair<string, string>> global_vars; // global variable storage
int syntaxErrorCount;
int inFunc=0;
SymbolTable *symbolTable = new SymbolTable(7);

int main(int argc, const char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    // ---- Input File ----
    ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        cerr << "Error opening input file: " << argv[1] << endl;
        return 1;
    }

    string outputDirectory = "output/";
    string parserLogFileName = outputDirectory + argv[2];
    string errorFileName = outputDirectory + argv[3];
    string lexLogFileName = outputDirectory +  argv[4];
    string asmFileName = outputDirectory + argv[5];

    // create output directory if it doesn't exist
    system(("mkdir -p " + outputDirectory).c_str());

    // ---- Output Files ----
    parserLogFile.open(parserLogFileName);
    if (!parserLogFile.is_open()) {
        cerr << "Error opening parser log file: " << parserLogFileName << endl;
        return 1;
    }

    errorFile.open(errorFileName);
    if (!errorFile.is_open()) {
        cerr << "Error opening error log file: " << errorFileName << endl;
        return 1;
    }

    lexLogFile.open(lexLogFileName);
    if (!lexLogFile.is_open()) {
        cerr << "Error opening lexer log file: " << lexLogFileName << endl;
        return 1;
    }
    asmFile.open("temp_file.txt");
    if (!asmFile.is_open()) {
        cerr << "Error opening asm file: " << asmFileName << endl;
        return 1;
    }
    tempFile.open(asmFileName);
    // ---- Parsing Flow ----
    ANTLRInputStream input(inputFile);
    C2105052Lexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    C2105052Parser parser(&tokens);

    // this is necessary to avoid the default error listener and use our custom error handling
    parser.removeErrorListeners();

    // start parsing at the 'start' rule
    tempFile << ".MODEL SMALL" << endl;
    tempFile<< ".STACK 1000H" << endl;
    tempFile << ".DATA" << endl;
    tempFile << "\tnumber DB \"00000$\"" << endl;
    parser.start();
    tempFile << ".CODE" << endl;
    string str = "new_line proc\n\tpush ax\n\tpush dx\n\tmov ah,2\n\tmov dl,0Dh\n\tint 21h\n\tmov ah,2\n\tmov dl,0Ah\n\tint 21h\n\tpop dx\n\tpop ax\n\tret\nnew_line endp\nprint_output proc  ;print what is in ax\n\tpush ax\n\tpush bx\n\tpush cx\n\tpush dx\n\tpush si\n\tlea si,number\n\tmov bx,10\n\tadd si,4\n\tcmp ax,0\n\tjnge negate\nprint:\n\txor dx,dx\n\tdiv bx\n\tmov [si],dl\n\tadd [si],'0'\n\tdec si\n\tcmp ax,0\n\tjne print\n\tinc si\n\tlea dx,si\n\tmov ah,9\n\tint 21h\n\tpop si\n\tpop dx\n\tpop cx\n\tpop bx\n\tpop ax\n\tret\nnegate:\n\tpush ax\n\tmov ah,2\n\tmov dl,'-'\n\tint 21h\n\tpop ax\n\tneg ax\n\tjmp print\nprint_output endp\nEND main";
    asmFile << str << endl;
    // clean up
    asmFile.close();
    tempFile.close();
    // merge the temp file into the asm file
    ifstream tempInput("temp_file.txt");
    if (!tempInput.is_open()) {
        cerr << "Error opening temp file for reading." << endl;
        return 1;
    }
    ofstream asmFile(asmFileName, ios::app);
    string line;
    while (getline(tempInput, line)) {
        asmFile << line << endl;
    }
    tempInput.close();
    



    inputFile.close();
    parserLogFile.close();

    errorFile.close();
    lexLogFile.close();

    asmFile.close();
    tempFile.close();
    // Run optimizations on the generated assembly code
    string optfile = outputDirectory + "optimized_" + argv[5];
    string optLogFile = outputDirectory + "optimization_"+argv[2] + ".log";
    generate_optimized_code(asmFileName, optfile, optLogFile);

    cout<<"Code generation and optimization for " << argv[1] << " completed successfully!" << endl;
    // cout << "Parsing completed. Check the output files for details." << endl;
    return 0;
}
