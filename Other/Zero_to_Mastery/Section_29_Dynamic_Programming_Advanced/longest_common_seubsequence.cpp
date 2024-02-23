/*
 * Longest Common Subsequence
 *
 * Example:
 *  Given
 *      apple
 *      ample
 *  Answer is aple -> 4
 *
 *  leetode 1143
 */
#include <iostream>

// recursive solution (slow)
int lcs_recursive(const std::string& s1, size_t i, const std::string& s2, size_t j) {
    if (i == s1.size() || j == s2.size()) {
        return 0;
    }
    if (s1[i - 1] == s2[j - 1]) {
        return 1 + lcs_recursive(s1, i + 1, s2, j + 1);
    }
    return std::max(lcs_recursive(s1, i, s2, j + 1),
            lcs_recursive(s1, i + 1, s2, j));
}

// DP Solution
// dp[i][j] = lcs for i character of s1 and j characcters for s2
// so answer is dp[# of character in s1][# of characters in s2]
int longestCommonSubsequence(const std::string& s1,
        const std::string& s2) {
    int m = s1.size();
    int n = s2.size();
    int dp[m + 1][n + 1];

    for (int i {}; i <= m; ++i) {
        for (int j {}; j <= n; ++j) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

int main() {
    std::cout << std::boolalpha;
    std::cout << (longestCommonSubsequence("avcde", "ace") == 3) <<'\n';
    std::cout << (longestCommonSubsequence("abc", "abc") == 3) <<'\n';
    std::cout << (longestCommonSubsequence("abc", "def") == 0) <<'\n';
}
