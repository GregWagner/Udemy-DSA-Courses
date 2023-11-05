/*
 * Calculate the nth fibonacci number
 */
#include <iostream>
#include <array>

// O(n)
int fib(int n) {
    static std::array<int, 100> a {};

    if (n <= 1) {
        a[n] = n;
        return n;
    }

    // memoization
    a[n - 2] = a[n - 2] > 0 ? a[n - 2] : fib(n - 2);
    a[n - 1] = a[n - 1] > 0 ? a[n - 1] : fib(n - 1);

    return a[n - 2] + a[n - 1];
}

// O(2^n)
int slow_fib(int n) {
    if (n <= 1) {
        return n;
    }
    return slow_fib(n - 2) + slow_fib(n - 1);
}

// O(n)
int fib_iter(int n) {
    if (n <= 1) {
        return n;
    }
    int t0 {}, t1 {1}, results {};
    for (int i = 2; i <= n; ++i) {
        results = t0 + t1;
        t0 = t1;
        t1 = results;
    }
    return results;
}

int main() {
    std::cout << slow_fib(6) << '\n';
    std::cout << fib(6) << '\n';
    std::cout << fib_iter(6) << '\n';
    std::cout << slow_fib(7) << '\n';
    std::cout << fib(7) << '\n';
    std::cout << fib_iter(7) << '\n';
}
