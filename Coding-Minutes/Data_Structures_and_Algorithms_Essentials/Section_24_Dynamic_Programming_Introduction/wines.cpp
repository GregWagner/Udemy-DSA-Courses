/*
 * Wines Problem
 * There is a collection of N wines placed linearly on a sheld.
 * The price of he ith wine it pi.
 * Since wines get better every year, suppose today is year 1, and
 * on year y, the price of the ith wine will be y * pi (i.e.
 * y-times the current year value).
 * You want to sell all the wines you have, but you want to sell
 * exactly one wine per year, starting this year. One other
 * constraint - each year you can sell either the leftmost or
 * rightmost wine without re-ordering. Find the maximum profit you
 * can get it you see all the wines in the optimal order.
 *
 * Greedy does not always work (i.e pick the smallest of either the
 * left or right most wine)
 *  {2, 3, 5, 1, 4};
 *  max = 49
 *  2*1 + 3*2 + 4*3 + 1*4 + 5*5 = 49
 * The actual max is 50
 *  2*1 + 4*2 + 1*3 + 3*4 + 5*5 = 50
 *
 * At each step, need to try both sides and determine which on
 * will result in the max price.
 *
 *  f(left, right, year)
 *    max(
 *      price[left] * y + f(left + 1, right, year + 1)
 *      price[right] * y + f(left, right - 1, year + 1)
 *    )_
 *
 *For 2, 3, 5, 1, 4 the bottom up solution is:
 * 10 23 43 45 50
 * 0  15 37 40 48
 * 0   0 25 29 41
 * 0   0  0  5 24
 * 0   0  0  0 20
 */
#include <iostream>
#include <vector>

// Top Down DP
int wines(int dp[][10], int prices[], int left, int right, int year) {
    // base case
    if (left > right) {
        return 0;
    }

    // has state already been computed
    if (dp[left][right] != 0) {
        return dp[left][right];
    }

    int pick_left = year * prices[left] + wines(dp, prices, left + 1, right, year + 1);
    int pick_right = year * prices[right] + wines(dp, prices, left, right - 1, year + 1);

    return dp[left][right] = std::max(pick_left, pick_right);
}

// bottom up approach
int wines_bottom_up(int prices[], int n) {
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));

    for (int i { n - 1 }; i >= 0; --i) {
        // fill in from bottom row to top row
        for (int j {}; j < n; ++j) {
            // check if only one bottle left
            if (i == j) {
                dp[i][j] = n * prices[i];

            // everything below the diagonal is zero
            } else if (i < j) {
                int year = n - (j - i);
                int pick_left = prices[i] * year + dp[i + 1][j];
                int pick_right = prices[j] * year + dp[i][j - 1];

                dp[i][j] = std::max(pick_left, pick_right);
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    int a[] { 2, 3, 5, 1, 4 };
    int n = 5;
    int dp[10][10] {};

    std::cout << "Top Down:\n";
    std::cout << wines(dp, a, 0, n - 1, 1) << '\n';

#if 0
    // print out DP table
    for (int i {}; i < n; ++i) {
        for (int j {}; j < n; ++j) {
            std::cout << dp[i][j] << ' ';
        }
        std::cout << '\n';
    }
#endif

    std::cout << "\nBottom Up:\n";
    std::cout << wines_bottom_up(a, n) << '\n';
}
