/*
 * Staircase Problem
 * Number of ways to reach N from zero
 * You can take a jump at 1, 2, and 3
 * For example to reach 3:
 *      1, 1, 1
 *      1, 2
 *      2, 1
 *      3
 * This is the number of ways to reach n-1 + the number of ways to reach n-2 + the number of ways to reach n-3
 * i.e f(n) = f(n-1) + f(n-2) + f(n-3)
 */
#include <iostream>

int staircase(int n) {
    // base cases
    if (n == 0 || n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    return staircase(n - 1) + staircase(n - 2) + staircase(n - 3);
}

int main() {
    std::cout << staircase(3) << '\n';
    std::cout << staircase(4) << '\n';
}
