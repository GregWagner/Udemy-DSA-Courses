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

     // Fast way
    int sub_problem{ power(a, n / 2) };
    sub_problem *= sub_problem;
    // check if even or odd
    return n & 1 ? a * sub_problem : sub_problem;
}

int main() {
    std::cout << power(2, 3) << '\n';
}
