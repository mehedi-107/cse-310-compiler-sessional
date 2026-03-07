#include <stdio.h>

int factorial(int n) {
    if(n <= 1)
        return 1;
    return n * factorial(n - 1);
}

int digitSum(int n) {
    if(n == 0)
        return 0;

    int lastDigit = n % 10;
    int rest = n;

    // simulate rest = n / 10
    rest = rest - lastDigit;
    int count = 0;
    while(rest >= 10) {
        rest = rest - 10;
        count++;
    }

    return lastDigit + digitSum(count);
}

int combinedCalc(int n) {
    int i, sum, fact;
    sum = 0;
    for(i = 1; i <= n; i++) {
        fact = factorial(i);
        if(fact > 0 && fact < 10000) {
            sum = sum + digitSum(fact);
        } else {
            sum = sum + (i % 10);
        }
    }
    return sum;
}

int divideBy2(int x) {
    int half = 0;
    while(x >= 2) {
        x = x - 2;
        half = half + 1;
    }
    return half;
}

int conditionTest(int x) {
    if(x < 10) {
        if(x % 2 == 0)
            return x * 2;
        else if(x % 3 == 0)
            return x + 3;
        else
            return x - 1;
    } else {
        return divideBy2(x);  // instead of x / 2
    }
}

int main() {
    int a, b, result, i, arr[5];
    a = 6;
    b = 3;
    result = combinedCalc(a);
    printf("%d\n", result);  // Expected: sum of digits of factorial(1..6)

    for(i = 0; i < 5; i++) {
        arr[i] = conditionTest(i + b);
    }

    for(i = 0; i < 5; i++) {
        if(arr[i] % 2 == 0 && arr[i] > 0) {
            result = result + arr[i];
        } else {
            result = result - arr[i];
        }
    }

    if(result > 20) {
        printf("%d\n", result);
    } else {
        result = result + factorial(3);
        printf("%d\n", result);
    }

    return 0;
}
