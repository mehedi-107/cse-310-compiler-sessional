lex 2105052.l
g++ lex.yy.c
mkdir -p output
./a.out test/input1.txt output/input1_log.txt output/input1_token.txt
./a.out test/input2.txt output/input2_log.txt output/input2_token.txt
./a.out test/input3.txt output/input3_log.txt output/input3_token.txt
diff output/input1_log.txt test/input1_log.txt
diff output/input1_token.txt test/input1_token.txt
diff output/input2_log.txt test/input2_log.txt
diff output/input2_token.txt test/input2_token.txt
diff output/input3_log.txt test/input3_log.txt
diff output/input3_token.txt test/input3_token.txt
