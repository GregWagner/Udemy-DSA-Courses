/*
 * Find the minimum number of steps from n to 1 using
 * only the following operations:
 * 1) Decrement by 1
 * 2) Divide by 2 - allowed if n % 2 == 0
 * 2) Divide by 3 - allowed if n % 3 == 0
 *
 * n = 7
 * 7 -> 6 -> 3 -> 1
 * or 
 * 7 -> 6 -> 2 -> 1
 */
#include <iostream>
#include <vector>
#include <climits>

// greedy approach
// n = 10   10 -> 5 -> 4 -> 2 -> 1      4 steps
// sb       10 -> 9 -> 3 -> 3           3 steps

// Brute Forcce O(2^n)
int steps1(int n) {
    if (n <= 1) {
        return 0;
    }

    int a = steps1(n - 1);

    int b {INT_MAX};
    if (n % 3 == 0) {
        b = steps1(n / 3);
    }

    int c {INT_MAX};
    if (n % 2 == 0) {
        c = steps1(n / 2);
    }
    return 1 + std::min(a, std::min(b, c));
}

// Top Down (Memoization) O(n)
int steps(int n, std::vector<int>& dp) {
    if (n <= 1) {
        return 0;
    }

    if (dp[n] == 0) {
        int a = steps(n - 1, dp);

        if (n % 3 == 0) {
            a = std::min(a, steps(n / 3, dp));
        }

        if (n % 2 == 0) {
            a = std::min(a, steps(n / 2, dp));
        }
        dp[n] =  1 + a;
    }
    return dp[n];
}

// Bottom Up 
int steps(int n) {
    std::vector<int> dp (n + 1, 0);
    dp[0] = 0;
    dp[1] = 0;

    for (int i {2}; i <= n; ++i) {
         int a = dp[i - 1];
         if (i % 3 == 0) {
             a = std::min(a, dp[i / 3]);
         }
         if (i % 2 == 0) {
             a = std::min(a, dp[i / 2]);
         }
         dp[i] = 1 + a;
    }
    return dp[n];
}

int main() {
    std::vector<int> a (100, 0);
    std::cout << std::boolalpha;
    std::cout << (steps(7, a) == 3) << '\n';
    std::cout << (steps(10, a) == 3) << '\n';
    std::cout << (steps(11, a) == 4) << '\n';
    std::cout << (steps(7) == 3) << '\n';
    std::cout << (steps(10) == 3) << '\n';
    std::cout << (steps(11) == 4) << '\n';
}
