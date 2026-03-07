#!/bin/bash

JAR_PATH="/usr/local/lib/antlr-4.13.2-complete.jar"
ANTLR="java -Xmx500M -cp $JAR_PATH:$CLASSPATH org.antlr.v4.Tool"

$ANTLR -Dlanguage=Cpp C2105052Lexer.g4
$ANTLR -Dlanguage=Cpp C2105052Parser.g4
g++ -std=c++17 -w -I/usr/local/include/antlr4-runtime -c icg.cpp C2105052Lexer.cpp C2105052Parser.cpp C2105052.cpp
g++ -std=c++17 -w icg.o C2105052Lexer.o C2105052Parser.o C2105052.o -L/usr/local/lib/ -lantlr4-runtime -o C2105052.out -pthread
LD_LIBRARY_PATH=/usr/local/lib ./C2105052.out $1 $2 $3 $4 $5