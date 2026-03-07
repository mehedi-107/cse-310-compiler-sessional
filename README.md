# CSE 310 — Compiler Sessional

> **Bangladesh University of Engineering and Technology (BUET)**
> Department of Computer Science and Engineering
> **Course:** CSE 310 — Compiler Sessional
> **Student ID:** 2105052

A complete, end-to-end compiler pipeline built incrementally across four assignments — from symbol-table management all the way to x86-16 assembly code generation and peephole optimization — for a subset of the C programming language.

---

## Table of Contents

- [Overview](#overview)
- [Repository Structure](#repository-structure)
- [Assignment 1 — Symbol Table](#assignment-1--symbol-table)
  - [Features](#11-features)
  - [Data Structures](#12-data-structures)
  - [Hash Functions](#13-hash-functions)
  - [Supported Commands](#14-supported-commands)
  - [Build & Run](#15-build--run)
- [Assignment 2 — Lexical Analysis](#assignment-2--lexical-analysis)
  - [Features](#21-features)
  - [Token Categories](#22-token-categories)
  - [Build & Run](#23-build--run)
- [Assignment 3 — Syntax & Semantic Analysis](#assignment-3--syntax--semantic-analysis)
  - [Features](#31-features)
  - [Grammar Overview](#32-grammar-overview)
  - [Semantic Checks](#33-semantic-checks)
  - [Build & Run](#34-build--run)
- [Assignment 4 — Intermediate Code Generation & Optimization](#assignment-4--intermediate-code-generation--optimization)
  - [Features](#41-features)
  - [Code Generation Details](#42-code-generation-details)
  - [Peephole Optimizer](#43-peephole-optimizer)
  - [Build & Run](#44-build--run)
- [Tools & Technologies](#tools--technologies)
- [How to Use](#how-to-use)
- [Compiler Pipeline Summary](#compiler-pipeline-summary)

---

## Overview

This repository contains the solutions for all four offline assignments of CSE 310 (Compiler Sessional). Together, the assignments implement a simplified compiler for a C-like language, covering the four classical compiler phases:

| Phase | Assignment | Description |
|-------|-----------|-------------|
| **1** | Symbol Table | Hash-table–based symbol table with scope management |
| **2** | Lexical Analysis | Flex-based tokenizer with symbol table integration |
| **3** | Syntax & Semantic Analysis | ANTLR4-based parser with type checking & error reporting |
| **4** | Intermediate Code Generation | x86-16 assembly generation + peephole optimization |

Each assignment folder (`assignment_0X_*/2105052/`) contains the complete, self-contained solution.

---

## Repository Structure

```
compiler_cse_310/
├── README.md
│
├── assignment_01_symbol_table/
│   ├── 2105052/
│   │   ├── 2105052_main.cpp            # Driver program
│   │   ├── 2105052_symbol_table.hpp    # SymbolTable, ScopeTable, SymbolInfo classes
│   │   ├── 2105052_hash_func.hpp       # Three hash function implementations
│   │   └── 2105052_report.cpp          # Collision-ratio comparison report
│   └── Jan25_CSE310_Offline1_Resources (1)/
│       ├── sample_input.txt
│       └── sample_output.txt
│
├── assignment_02_lexical_analysis/
│   └── 2105052/
│       ├── 2105052.l                   # Flex specification
│       ├── 2105052_symbol_table.hpp    # Symbol table (reused from A1)
│       ├── 2105052_hash_func.hpp       # Hash functions (reused from A1)
│       ├── key.txt                     # Keyword list
│       ├── operator.txt                # Operator → token-name mapping
│       └── run.sh                      # Build & run script
│
├── assignment_03_syntex_analysis/
│   └── 2105052/
│       ├── C2105052Lexer.g4            # ANTLR4 lexer grammar
│       ├── C2105052Parser.g4           # ANTLR4 parser grammar (with embedded actions)
│       ├── C2105052.cpp                # Driver / main entry point
│       ├── 2105052_symbol_table.hpp    # Symbol table (extended)
│       ├── 2105052_hash_func.hpp       # Hash functions
│       ├── run-script.sh               # Build & run script
│       ├── check.sh                    # Automated test runner (diff-based)
│       └── clean-script.sh             # Clean generated files
│
├── assignment_04_ICG/
│   ├── 2105052/                        # Source (pre-build)
│   │   ├── C2105052Lexer.g4            # Lexer grammar (extended for ICG)
│   │   ├── C2105052Parser.g4           # Parser grammar (extended with code-gen actions)
│   │   ├── C2105052.cpp                # Driver
│   │   ├── 2105052_symbol_table.hpp    # Symbol table (extended)
│   │   ├── 2105052_hash_func.hpp       # Hash functions
│   │   ├── optimizer.cpp               # Peephole optimizer
│   │   ├── run-script.sh               # Build & run script
│   │   └── check.sh                    # Test runner
│   └── icg/                            # Build artifacts & working directory
│       ├── icg.cpp / icg.hpp           # ICG helper functions
│       ├── optimizer.cpp               # Peephole optimizer (same source)
│       ├── code.asm                    # Generated unoptimized assembly
│       ├── optcode.asm                 # Optimized assembly output
│       ├── input/                      # Test input programs
│       └── output/                     # Generated outputs
```

---

## Assignment 1 — Symbol Table

### 1.1 Features

- **Multi-scope symbol table** — supports nested scopes via a stack of `ScopeTable` instances.
- **Chained hashing** — each `ScopeTable` is a hash table with separate chaining for collision resolution.
- **Three hash functions** for performance comparison (see [§1.3](#13-hash-functions)).
- **Rich symbol metadata** — variables, functions (with parameter lists & return types), structs, and unions.
- **Collision reporting** — tracks and outputs collision statistics per hash function.

### 1.2 Data Structures

| Class | Responsibility |
|-------|----------------|
| `SymbolInfo` | Stores a single symbol: name, type, and optional function/struct parameters. |
| `ScopeTable` | Hash table (array of linked-list chains) representing one lexical scope. Tracks its own scope ID and parent pointer. |
| `SymbolTable` | Manages a stack of `ScopeTable` objects. Provides `insert`, `look_up`, `remove`, `enter_scope`, and `exit_scope` operations. |
| `Parameter` | Holds `(name, type)` pairs for function/struct parameters. |

### 1.3 Hash Functions

Three hash functions are implemented in `2105052_hash_func.hpp` and can be selected at runtime:

| # | Name | Algorithm |
|---|------|-----------|
| 1 | **SDBMHash** | `hash = (c) + (hash << 6) + (hash << 16) - hash` |
| 2 | **djb2** | `hash = hash * 33 + c` (Dan Bernstein's classic) |
| 3 | **FNV-1a** | XOR-then-multiply with FNV offset basis & prime |

The report program (`2105052_report.cpp`) benchmarks all three functions and compares their collision ratios.

### 1.4 Supported Commands

| Command | Description |
|---------|-------------|
| `I <name> <type> [params...]` | Insert symbol into current scope |
| `L <name>` | Look up symbol (current → outer scopes) |
| `D <name>` | Delete symbol from current scope |
| `S` | Enter a new (child) scope |
| `E` | Exit the current scope |
| `P C` | Print the current scope table |
| `P A` | Print all scope tables |
| `Q` | Quit |

### 1.5 Build & Run

```bash
cd assignment_01_symbol_table/2105052/
g++ -o main 2105052_main.cpp
./main <num_buckets> <input_file> <output_file> [hash_function]
```

- `num_buckets` — size of each scope's hash table.
- `hash_function` — optional, selects `1` (SDBM), `2` (djb2), or `3` (FNV-1a). Default: `1`.

---

## Assignment 2 — Lexical Analysis

### 2.1 Features

- **Flex-based scanner** for a C-like language.
- **Symbol table integration** — identifiers are inserted into the symbol table from Assignment 1 on discovery; duplicate declarations are reported.
- **Scope tracking** — `{` enters a new scope, `}` exits the current scope.
- **Multi-line comment handling** — tracks line numbers across `/* ... */` blocks; detects unterminated comments.
- **String literal processing** — supports escape sequences (`\n`, `\t`, `\\`, `\"`, etc.); detects unterminated strings.
- **Error reporting** with line numbers for unrecognized characters, unterminated strings, and unterminated comments.

### 2.2 Token Categories

| Category | Tokens / Lexemes |
|----------|-----------------|
| **Keywords** (20) | `if`, `else`, `goto`, `for`, `while`, `long`, `do`, `break`, `short`, `int`, `char`, `static`, `float`, `double`, `unsigned`, `void`, `return`, `switch`, `case`, `default`, `continue` |
| **Arithmetic** | `ADDOP` (`+`, `-`), `MULOP` (`*`, `/`, `%`) |
| **Increment / Decrement** | `INCOP` (`++`), `DECOP` (`--`) |
| **Relational** | `RELOP` (`<`, `<=`, `>`, `>=`, `==`, `!=`) |
| **Logical** | `LOGICOP` (`&&`, `\|\|`), `NOT` (`!`) |
| **Assignment** | `ASSIGNOP` (`=`) |
| **Punctuation** | `LPAREN`, `RPAREN`, `LCURL`, `RCURL`, `LTHIRD`, `RTHIRD`, `SEMICOLON`, `COMMA` |
| **Literals** | `CONST_INT`, `CONST_FLOAT`, `STRING` |
| **Identifiers** | `ID` |
| **Comments** | Single-line (`//`), multi-line (`/* */`) — consumed, not emitted |

### 2.3 Build & Run

```bash
cd assignment_02_lexical_analysis/2105052/
lex 2105052.l               # or: flex 2105052.l
g++ -o scanner lex.yy.c
./scanner <input_file> <log_output> <token_output>
```

**Output files:**
| File | Contents |
|------|----------|
| Log file | Detailed per-token info: line number, token class, lexeme |
| Token file | Space-separated token stream (consumed by the parser) |

---

## Assignment 3 — Syntax & Semantic Analysis

### 3.1 Features

- **ANTLR4-based parser** (C++17 target) with a custom lexer and parser grammar.
- **Full semantic analysis** embedded in parser actions.
- **Type checking** — integer vs. float, array vs. non-array mismatches.
- **Function validation** — return-type consistency, argument count/type matching, void-function-in-expression detection.
- **Scope-aware symbol table** — declarations checked against all visible scopes.
- **Detailed error & log output** with line numbers.

### 3.2 Grammar Overview

The grammar (split across `C2105052Lexer.g4` and `C2105052Parser.g4`) defines a subset of C:

```
program        → unit+
unit           → var_declaration | func_declaration | func_definition

type_specifier → INT | FLOAT | VOID

var_declaration    → type_specifier declaration_list SEMICOLON
declaration_list   → ID | ID LTHIRD CONST_INT RTHIRD | declaration_list COMMA ...

func_declaration   → type_specifier ID LPAREN parameter_list? RPAREN SEMICOLON
func_definition    → type_specifier ID LPAREN parameter_list? RPAREN compound_statement
parameter_list     → type_specifier ID (, type_specifier ID)*

compound_statement → LCURL statements RCURL

statement → var_declaration
          | expression_statement
          | compound_statement
          | IF LPAREN expression RPAREN statement (ELSE statement)?
          | WHILE LPAREN expression RPAREN statement
          | FOR LPAREN expression_statement expression_statement expression? RPAREN statement
          | RETURN expression? SEMICOLON
          | PRINTLN LPAREN ID RPAREN SEMICOLON

expression          → variable ASSIGNOP logic_expression | logic_expression
logic_expression    → rel_expression (LOGICOP rel_expression)*
rel_expression      → simple_expression (RELOP simple_expression)*
simple_expression   → term (ADDOP term)*
term                → unary_expression (MULOP unary_expression)*
unary_expression    → ADDOP unary_expression | NOT unary_expression | factor
factor              → variable | ID LPAREN argument_list? RPAREN | LPAREN expression RPAREN
                    | CONST_INT | CONST_FLOAT | variable INCOP | variable DECOP
variable            → ID | ID LTHIRD expression RTHIRD
```

**Lexer tokens** include keywords (`if`, `else`, `for`, `while`, `int`, `float`, `void`, `return`, `printf`), operators, punctuation, identifiers, integer/float constants, strings, and comments.

### 3.3 Semantic Checks

| # | Check | Example Error |
|---|-------|---------------|
| 1 | **Undeclared variable** | `Undeclared variable x` |
| 2 | **Multiple declaration** | `Multiple declaration of y` |
| 3 | **Return type mismatch** | `Return type mismatch of func` |
| 4 | **Argument count mismatch** | `Total number of arguments mismatch with declaration in function foo` |
| 5 | **Argument type mismatch** | `2th argument mismatch in function bar` |
| 6 | **Array used without index** | `Type mismatch, arr is an array` |
| 7 | **Non-array indexed** | `x not an array` |
| 8 | **Non-integer array index** | `Expression inside third brackets not an integer` |
| 9 | **Void function in expression** | `Void function used in expression` |
| 10 | **Return from void function** | `Cannot return value from function main with void return type` |
| 11 | **Modulus by zero** | `Modulus by Zero` |
| 12 | **Non-integer mod operand** | `Non-Integer operand on modulus operator` |
| 13 | **Type mismatch in assignment** | `Type Mismatch` |

### 3.4 Build & Run

**Prerequisites:** ANTLR 4.13.2 JAR, ANTLR4 C++ runtime.

```bash
cd assignment_03_syntex_analysis/2105052/

# Build & run on a single input:
chmod +x run-script.sh
./run-script.sh <input.txt> <parser_log.txt> <error_log.txt> <lex_log.txt>

# Automated testing against sample I/O (5 test cases):
chmod +x check.sh
./check.sh
```

**Output files:**
| File | Contents |
|------|----------|
| Parser log | Full parse trace with grammar-rule reductions and reconstructed source |
| Error log | Semantic errors with line numbers |
| Lex log | Token-level lexer output |

---

## Assignment 4 — Intermediate Code Generation & Optimization

### 4.1 Features

- **Full x86-16 assembly generation** from the parsed AST via ANTLR4 embedded actions.
- **Global and local variable support** — globals in `.DATA` segment, locals on the stack (BP-relative addressing).
- **Array support** — multi-word stack/data allocation.
- **Function call convention** — arguments pushed on stack, `CALL`/`RET`, BP-based frame management.
- **Control flow** — `if`/`else`, `while`, `for` loops compiled to labeled jumps (`JMP`, `JE`, `JNE`, `JL`, `JLE`, `JG`, `JGE`).
- **`printf` support** — built-in `print_output` procedure for signed integer printing.
- **Post-generation peephole optimizer** for assembly-level code improvement.

### 4.2 Code Generation Details

#### Memory Layout

```
.MODEL SMALL
.STACK 1000H

.DATA
    ; Global variables declared here
    x DW 0          ; Simple variable
    arr DW 10 DUP(0) ; Array of size 10

.CODE
```

#### Function Prologue / Epilogue

```asm
func_name PROC
    PUSH BP
    MOV BP, SP
    SUB SP, <local_var_bytes>   ; Allocate space for locals
    ; ... function body ...
Lreturn:
    MOV SP, BP                  ; Deallocate locals
    POP BP
    RET <param_bytes>           ; Clean up parameters
func_name ENDP
```

For `main`, the prologue additionally initializes the data segment (`MOV AX, @DATA ; MOV DS, AX`).

#### Expression Evaluation

- All expressions evaluated into `AX`.
- Binary operators: left operand pushed, right evaluated into `AX`, left popped into `BX`, result in `AX`.
- Relational operators: compiled using `CMP` + conditional jumps.
- Increment/Decrement: in-place `ADD`/`SUB` on the variable's memory location.

#### Runtime Support Procedures

| Procedure | Purpose |
|-----------|---------|
| `new_line` | Outputs carriage-return + line-feed (INT 21h) |
| `print_output` | Prints the signed 16-bit integer in AX as decimal to stdout |

### 4.3 Peephole Optimizer

The optimizer (`optimizer.cpp`) performs four passes of peephole optimization on the generated `.asm` file:

| # | Optimization | Pattern Removed | Example |
|---|-------------|-----------------|---------|
| 1 | **Redundant MOV removal** | `MOV X, AX` followed by `MOV AX, X` | Eliminates the second MOV |
| 2 | **Consecutive PUSH/POP elimination** | `PUSH R` immediately followed by `POP R` (same register) | Both instructions removed |
| 3 | **Identity-operation removal** | `ADD X, 0` / `SUB X, 0` / `MUL X, 1` / `DIV X, 1` / `OR X, 0` / `XOR X, 0` | No-op instruction removed |
| 4 | **Consecutive label merging** | Multiple labels at the same address | Merged into one; all jump targets updated |

The optimizer produces:
- **Optimized assembly file** — ready for assembly.
- **Optimization log** — lists every removed/modified instruction with its reason.

### 4.4 Build & Run

**Prerequisites:** ANTLR 4.13.2 JAR, ANTLR4 C++ runtime.

```bash
cd assignment_04_ICG/2105052/

# Build & run (generates assembly):
chmod +x run-script.sh
./run-script.sh <input.txt> <parser_log.txt> <error_log.txt> <lex_log.txt>

# Run optimizer on generated assembly:
g++ -o optimizer optimizer.cpp
./optimizer <input.asm> <output.asm> <optimization_log.txt>
```

**Output files:**
| File | Contents |
|------|----------|
| `code.asm` | Unoptimized x86-16 assembly |
| `optcode.asm` | Optimized assembly output |
| Parser/Error/Lex logs | Same as Assignment 3 |
| Optimization log | Removed instructions + reasons |

The generated `.asm` files target **8086 / MASM / TASM** and can be assembled and run under **DOSBox** or **emu8086**.

---

## Tools & Technologies

| Tool | Version | Used In | Purpose |
|------|---------|---------|---------|
| **C++17** | GCC / G++ | All | Implementation language |
| **Flex** | — | Assignment 2 | Lexical analyzer generator |
| **ANTLR4** | 4.13.2 | Assignments 3 & 4 | Parser / lexer generator (C++ target) |
| **ANTLR4 C++ Runtime** | — | Assignments 3 & 4 | Runtime library for generated parsers |
| **Java** | — | Assignments 3 & 4 | Required to run the ANTLR4 tool |
| **x86-16 ASM** | MASM/TASM | Assignment 4 | Target assembly language |
| **Bash** | — | All (except A1) | Build & test automation |

---

## How to Use

### Prerequisites

1. **G++** with C++17 support.
2. **Flex** (for Assignment 2).
3. **Java JRE/JDK** (for ANTLR4, Assignments 3 & 4).
4. **ANTLR 4.13.2** — download `antlr-4.13.2-complete.jar` and place at `/usr/local/lib/` (or update the `JAR_PATH` in run scripts).
5. **ANTLR4 C++ runtime** — install headers to `/usr/local/include/antlr4-runtime/` and shared library to `/usr/local/lib/`.

### Quick Start

```bash
# Clone the repository
git clone <repo-url>
cd compiler_cse_310

# --- Assignment 1: Symbol Table ---
cd assignment_01_symbol_table/2105052/
g++ -o main 2105052_main.cpp
./main 7 ../Jan25_CSE310_Offline1_Resources\ \(1\)/sample_input.txt output.txt

# --- Assignment 2: Lexical Analyzer ---
cd ../../assignment_02_lexical_analysis/2105052/
chmod +x run.sh
./run.sh

# --- Assignment 3: Syntax & Semantic Analyzer ---
cd ../../assignment_03_syntex_analysis/2105052/
chmod +x run-script.sh check.sh
./run-script.sh input.txt log.txt error.txt lexLog.txt

# --- Assignment 4: Code Generation + Optimization ---
cd ../../assignment_04_ICG/2105052/
chmod +x run-script.sh
./run-script.sh input.txt log.txt error.txt lexLog.txt
g++ -o optimizer optimizer.cpp
./optimizer code.asm optcode.asm opt_log.txt
```

---

## Compiler Pipeline Summary

```
                 ┌─────────────────────────────────────────────────────┐
                 │               CSE 310 Compiler Pipeline             │
                 └─────────────────────────────────────────────────────┘

  Source Code (.c)
       │
       ▼
  ┌─────────────────────┐
  │  Lexical Analysis    │  Assignment 2 — Flex
  │  (Tokenizer)         │  Tokens: keywords, operators, IDs, literals
  └──────────┬──────────┘
             │  Token Stream
             ▼
  ┌─────────────────────┐
  │  Syntax Analysis     │  Assignment 3 — ANTLR4
  │  (Parser)            │  Grammar-driven parsing, parse tree
  └──────────┬──────────┘
             │  Parse Tree + Semantic Info
             ▼
  ┌─────────────────────┐
  │  Semantic Analysis   │  Assignment 3 — Embedded actions
  │  (Type Checking)     │  Scope resolution, type compat, error reporting
  └──────────┬──────────┘
             │  Validated AST
             ▼
  ┌─────────────────────┐
  │  Code Generation     │  Assignment 4 — ANTLR4 actions
  │  (ICG → x86-16 ASM) │  Register allocation, stack frames, control flow
  └──────────┬──────────┘
             │  Unoptimized .asm
             ▼
  ┌─────────────────────┐
  │  Peephole Optimizer  │  Assignment 4 — optimizer.cpp
  │  (ASM → ASM)         │  Redundant MOV, PUSH/POP, identity ops, labels
  └──────────┬──────────┘
             │  Optimized .asm
             ▼
       x86-16 Assembly
     (Ready for MASM/TASM)

  ┌─────────────────────┐
  │  Symbol Table        │  Assignment 1 — Used by ALL phases
  │  (Scope Management)  │  Hash table with chaining, nested scopes
  └─────────────────────┘
```

---

## License

This repository is for academic/educational purposes as part of the CSE 310 course at BUET. All rights belong to the respective author.
