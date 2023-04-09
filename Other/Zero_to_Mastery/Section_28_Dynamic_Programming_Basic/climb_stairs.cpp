// leetcode 70
#include <iostream>
#include <vector>

// recursive code is very slow
int countSteps(int n) {
    if (n <= 1) {
        return 1;
    }
    return countSteps(n - 1) + countSteps(n - 2);
}

int climbStairs(int n) {
    std::vector<int> dp (n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i {2}; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    std::cout << std::boolalpha;
    std::cout << (climbStairs(2) == 2) << '\n';
    std::cout << (climbStairs(3) == 3) << '\n';
}
