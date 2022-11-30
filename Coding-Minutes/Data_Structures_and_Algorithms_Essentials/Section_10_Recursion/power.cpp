/*
 * Compute a^n
 */
#include <iostream>

int power(int a, int n) {
    if (n == 0) {
        return 1;
    }

    /*
     * Slow way
     * return a * power(a, n - 1);
     */

    int subProblem { power(a, n / 2) };
    subProblem *= subProblem;
    return n & 1 ? a * subProblem : subProblem;
}

int main() {
    std::cout << power(2, 3) << '\n';
}
