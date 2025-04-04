/*
 * See Zonal Computing Olympiad 2014.
 *
 * In ICO School, all students have to participate regularly
 * in SUPW. There is a different SUPW activity each day and
 * each activity has its own duration. The SUPW schedule
 * for the next term has been announced, including informmation
 * about the number of minutes taken by each activity.
 * You have been assigned to assign SUPW duties to students,
 * including yourself. The rules say that no student can go
 * 3 days in a row without any SUPW duty.
 * Find the minimum number of minutes you spend overall on SUPW.
 *
 * Every 3 day window, you must pick at least 1 activity.
 *
 * Greedy - pick the minimimm in each 3 day window.
 *    This does not always work:
 *    2 2 3 2 2  - greedy picks right most element in each group of 3:
 *      2 + 2, but correct answer is 3
 *
 * DP
 *    State --> f(i) = the minimum number of minutes
 *                     spent in SUPW duty if
 *                     a[0,...i] and the duty ends on
 *                     the ith day
 *   For example 2 2 3 2 2
 *          f(i) 2 2 3 4 3
 *   Answer is the min of the last 3 indexs (i.e. 3)
 *
 *   So the actual recursive relation is
 *     f(i) = min(f(i-1), f(i--2), f(i-3)) + a[i]
 *   For example
 *          3 2 1 1 2 3 1 3 2 1
 *          3 2 1 2 3 4 3 6 5 4
 *   and answer is min(last 3) -> 4
 */
#include <algorithm>
#include <iostream>
#include <vector>

int solve(const std::vector<int>& a) {
    std::vector<int> dp(a.size());

    for (int i {}; i < 3; ++i) {
        dp[i] = a[i];
    }

    for (size_t i { 3 }; i < a.size(); ++i) {
        dp[i] = std::min({ dp[i - 1], dp[i - 2], dp[i - 3] })
            + a[i];
    }

    return std::min({ dp[a.size() - 1],
        dp[a.size() - 2], dp[a.size() - 3] });
}

int main() {
    std::vector<int> a { 3, 2, 1, 1, 2, 3, 1, 3, 2, 1 };
    std::cout << std::boolalpha;
    std::cout << (solve(a) == 4) << '\n';

    std::vector<int> b { 3, 2, 3, 2, 3, 5, 1, 3 };
    std::cout << std::boolalpha;
    std::cout << (solve(b) == 5) << '\n';
}
