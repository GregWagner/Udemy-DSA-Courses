/*
 * Given an array of coin denominations and an integer M
 * representing target money, Find the minimum number of
 * coins required to make change.
 * coins = [1, 3, 7, 10]
 * m = 15
 * output = 3 using (7 + 7 + 1)
 *
 * For this example the subproblems are:
 * If using the 1 coin, 1 + f(15 - 1) = 1 + f(14)
 * If using the 3 coin, 1 + f(15 - 3) = 1 + f(12)
 * If using the 7 coin, 1 + f(15 - 7) = 1 + f(8)
 * If using the 10 coin, 1 + f(15 - 10) = 1 + f(5)
 * and you need to take the minimum of all of these
 */
#include <climits>
#include <iostream>
#include <vector>

// Bottom Up Approach
int minNumberOfCoinsForChange(int n, const std::vector<int>& coins) {
    std::vector<int> dp(n + 1, INT_MAX);

    for (int i { 1 }; i <= n; ++i) {
        for (int coinValue : coins) {
            if (i - coinValue >= 0 && dp[i - coinValue] != INT_MAX) {
                dp[i] = std::min(dp[i], dp[i - coinValue] + 1);
            }
        }
    }
    return dp[n] == INT_MAX ? -1 : dp[n];
}

int main() {
    std::vector<int> coin_denom { 1, 3, 7, 10 };
    std::cout << minNumberOfCoinsForChange(8, coin_denom) << '\n';
    std::cout << minNumberOfCoinsForChange(16, coin_denom) << '\n';
}
