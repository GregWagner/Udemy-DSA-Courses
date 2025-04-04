/*
 * Print the number of set bits for each number from
 * 1 to n.
 *
 * Brute force is O(n logn)
 * Recursive is O(n)
 *
 * Need to look at the numbers in pairs
 * For example 5 and 10 -- 5<<1 = 10 and since
 * 10 is even (i.e the last bit is zero) they
 * have the same number of bits.
 */
#include <iostream>

// brute force is logn
int return_set_bits(int n) {
    int count {};
    while (n) {
        n = n & (n - 1);
        ++count;
    }
    return count;
}

int main() {
    int n = 10;
    int dp[11] {};

    for (int i{}; i <= n; ++i) {
        dp[i] = dp[i / 2] + (i & 1);
        std::cout << i << ": " << dp[i] << '\n';
    }
}
