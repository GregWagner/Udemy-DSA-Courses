#include <iostream>

// Question #1
int fun1(int n) {
    static int i {1};
    if (n > 5) {
        return n;
    }
    n += i;
    ++i;
    return fun1(n);
}

// Question #2
void fun2(int n, int sum) {
    if (n == 0) {
        return;
    }
    int k {n % 10};
    int j {n / 10};
    sum += k;
    fun2(j, sum);
    std::cout << k << ' ';
}

// Question 3
int fun3(int& x, int c) {
    --c;
    if (c == 0) {
        return 1;
    }
    ++x;
    return fun3(x, c) * x;
}

// Question 4
int fun4(int n) { 
    int x {1};
    if (n == 1) {
        return x;
    }
    for (int k {1}; k < n; ++k) {
        x = x + fun4(k) * fun4(n - k); 
    }
    return x; 
}

// Question 5
void fun5(int n) {
    static int d = 1;
    std::cout << n << ' ' << d << ' ';
    ++d;
    if (n > 1) {
        fun5(n - 1);
    }
    std::cout << d << ' ';
}

int main () {
    std::cout << fun1(1) << '\n';

    fun2(2048, 0);
    std::cout << 0 << '\n';

    int p = 5;
    std::cout << fun3(p, p) << '\n';

    std::cout << fun4(5) << '\n';

    fun5(3);
    std::cout << '\n';
}
