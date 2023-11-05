/*
 * Minimum Distance
 * (Edit Distance)
 * leet code 72
 */
#include <iostream>

// recursive solution (slow)
int editDistance(const std::string& s1, int m, const std::string& s2, int n) {
    if (m == 0) {
        return n;   // insert all of s2
    }
    if (n == 0) {
        return m;   // delete all characters of s1
    }

    // check if last chacters match
    if (s1[m - 1] == s2[n - 1]) {
        return editDistance(s1, m - 1, s2, n - 1);
    }

    int insertCharacter = editDistance(s1, m, s2, n - 1);
    int deleteCharacter = editDistance(s1, m - 1, s2, n);
    int replaceCharacter = editDistance(s1, m - 1, s2, n - 1);

    return 1 + std::min(insertCharacter, 
            std::min(deleteCharacter, replaceCharacter));
}

int minDistance(const std::string& s1, const std::string& s2) {
    //return editDistance(s1, s1.size(), s2, s2.size());
    int m = s1.size();
    int n = s2.size();
    int dp[m + 1][n + 1];

    for (int i {}; i <= m; ++i) {
        for (int j {}; j <= n; ++j) {
            if (i == 0) {
                dp[i][j] = j;       // insert all s2 characters
            } else if (j == 0) {
                dp[i][j] = i;       //  delete all s1 characters
            } else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                int insertCharacter = dp[i][j - 1];
                int deleteCharacter = dp[i - 1][j];
                int replaceCharacter = dp[i - 1][j - 1];

                dp[i][j] = 1 + std::min(insertCharacter,
                        std::min(deleteCharacter, replaceCharacter));
            }
        }
    }
    return dp[m][n];
}

int main() {
    std::cout << std::boolalpha;
    std::cout << (minDistance("horse", "ros") == 3) << '\n';
    std::cout << (minDistance("intention", "execution") == 5) << '\n';
}

