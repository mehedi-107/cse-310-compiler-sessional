chmod +x run-script.sh
./run-script.sh input/exp.c log_exp.txt error_exp.txt lexlog_exp.txt code_exp.asm
./run-script.sh input/func.c log_func.txt error_func.txt lexlog_func.txt code_func.asm
./run-script.sh input/loop.c log_loop.txt error_loop.txt lexlog_loop.txt code_loop.asm
./run-script.sh input/test1_i.c log1.txt error1.txt lexlog1.txt code1.asm
./run-script.sh input/test2_i.c log2.txt error2.txt lexlog2.txt code2.asm
./run-script.sh input/test3_i.c log3.txt error3.txt lexlog3.txt code3.asm
./run-script.sh input/test4_i.c log4.txt error4.txt lexlog4.txt code4.asm
./run-script.sh input/test5_i.c log5.txt error5.txt lexlog5.txt code5.asm
./run-script.sh input/test6_i.c log6.txt error6.txt lexlog6.txt code6.asm
./run-script.sh input/test7_i.c log7.txt error7.txt lexlog7.txt code7.asm
./run-script.sh input/bonustest1_i.c log8.txt error8.txt lexlog8.txt code8.asm
./run-script.sh input/bonustest2_i.c log9.txt error9.txt lexlog9.txt code9.asm

rm -f output/*.txt