#include <iostream>
#include <vector>

// O(2^n)
int fib1(int n) {
    if (n <= 1) {
        return n;
    }
    return fib1(n - 1) + fib1(n - 2);
}

// Top down DP (Memoization)
// O(n)
long long fib(int n, std::vector<long long>& a) {
    if (n <= 1) {
        return n;
    }

    if (a[n] == 0) {
        a[n] = fib(n - 1, a) + fib(n - 2, a);
    }
    return a[n];
}

// Bottom Up (Iterative)
// O(n)
long long fib(int n) {
    std::vector<long long> a (n + 1, 0);
    a[0] = 0;
    a[1] = 1;

    for (int i {2}; i <= n; ++i) {
        a[i] = a[i - 1] + a[i - 2];
    }
    return a[n];
}

int main() {
    std::vector<long long> a (50, 0);
    std::cout << fib(45, a) << '\n';
    std::cout << fib(45) << '\n';
    std::cout << fib1(45) << '\n';
}
