int main() {

    int a, b, c, d, x, y, z;
    a = 10;
    b = 5;
    c = 8;
    d = 15;
    x = 3;
    y = 7;
    z = 0;

    if (a > b) {
        println(a);
        if (c < d) {
            println(c);
            if (x == 3) {
                println(x);
            }
            else {
                println(z);
            }
        }
        else {
            println(d);
        }
    }

    if (b > 0) {
        println(b);
    }
    else if (a == 10) {
        println(a);
    }
    else {
        println(z);
    }

    if (x < y) {
        println(y);
        if (y - x > 3) {
            println(y);
        }
        else {
            println(x);
        }
    }

    if (a + b > c + d) {
        println(a);
    }
    else if (b + c == d) {
        println(b);
    }
    else if (d - c < a) {
        if (x > 1) {
            println(x);
            if (y > 5) {
                println(y);
            }
            else {
                println(z);
            }
        }
    }
    else {
        println(z);
    }

    if (z == 0) {
        println(z);
        if (a == 10) {
            println(a);
            if (b == 5) {
                println(b);
            }
        }
    }

    if (a > 0) {
        if (b > 0) {
            if (c > 0) {
                if (d > 0) {
                    println(d);
                }
                else {
                    println(c);
                }
            }
        }
    }

    if (x == 3 && y == 7) {
        println(x);
        println(y);
    }
    else if (x == 3 || z == 1) {
        println(z);
    }
    else {
        println(a);
    }

    return 0;
}
