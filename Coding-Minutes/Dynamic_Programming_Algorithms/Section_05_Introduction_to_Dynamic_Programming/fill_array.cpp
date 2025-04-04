/*
 * Leetcode 600. Non-negative Integers without Consecutive Ones
 * but you need memoization to solve this problem
 *
 * What is the number of ways to fill an array with
 * 0's and 1's such that there are no consecutive 1's.
 *
 * Note: This is really just the fibonacci problem
 *  answer = fib(n + 2)
 *
 * State:
 *  f(index) -> number of ways of filling array
 */
#include <iostream>

// return number of ways to fill array
// since n does not change - this is a 2D DP problem so
// you would need an n x 2 table to memoize
int fillArray(int index, int n, bool previousIndexAOne = false) {
    // base case
    if (index == n + 1) {
        return 1;
    }

    // place 0
    int answer = fillArray(index + 1, n, false);

    // place 1 (can only do if we previously added a zero)
    if (!previousIndexAOne) {
        answer += fillArray(index + 1, n, true);
    }
    return answer;
}

int main() {
    for (int i { 1 }; i < 10; ++i) {
        std::cout << fillArray(1, i) << '\n';
    }
}
