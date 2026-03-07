chmod +x run-script.sh
./run-script.sh sampleio_abs/input1.txt log1.txt error1.txt lexLog1.txt
./run-script.sh sampleio_abs/input2.txt log2.txt error2.txt lexLog2.txt
./run-script.sh sampleio_abs/input3.txt log3.txt error3.txt lexLog3.txt
./run-script.sh sampleio_abs/input4.txt log4.txt error4.txt lexLog4.txt
./run-script.sh sampleio_abs/input5.txt log5.txt error5.txt lexLog5.txt

diff -u sampleio_abs/log1.txt output/log1.txt
echo "Log1.txt comparison done"
diff -u sampleio_abs/log2.txt output/log2.txt
echo "Log2.txt comparison done"
diff -u sampleio_abs/log3.txt output/log3.txt
echo "Log3.txt comparison done"
diff -u sampleio_abs/log4.txt output/log4.txt
echo "Log4.txt comparison done"

diff -u sampleio_abs/error1.txt output/error1.txt
echo "Error1.txt comparison done"
diff -u sampleio_abs/error2.txt output/error2.txt
echo "Error2.txt comparison done"
diff -u sampleio_abs/error3.txt output/error3.txt
echo "Error3.txt comparison done"
diff -u sampleio_abs/error4.txt output/error4.txt
echo "Error4.txt comparison done"
diff -u sampleio_abs/error5.txt output/error5.txt
echo "Error5.txt comparison done"