/*
 * Combination Formula
 * nCr = n! / (r!(n-r)!)
 *
 * If you have A B C D E F G
 * how many ways can you select 3 items
 */
#include <iostream>

long factorial_iter(long n) {
    long results {1};
    for (int i {1}; i <= n; ++i) {
        results *= i;
    }
    return results;
}

// O(n)
long nCr_iter(int n, int r) {
    long t1 = factorial_iter(n);
    long t2 = factorial_iter(r);
    long t3 = factorial_iter(n - r);

    return t1 / (t2 * t3);
}

// Recursive using Pascal's Triangle
// First row is 0C0
// Second row is 1c0 and 1c1
// Third row is 2C0, 2C1, and 2C2
int nCr(int n, int r) {
    if (n == r || r == 0) {
        return 1;
    }
    return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

int main() {
    std::cout << nCr_iter(4, 2) << '\n';
    std::cout << nCr(4, 2) << '\n';
}
