/*
 * Triplets
 *
 * Given an array containing N integers and a number S denoting a target
 * sum, find all distinct integers that can add up to form the target
 * sum. The numbers in each triplet should be ordered in ascending order,
 * and the triplets should be ordered also.
 * Return an empty array if no such triplet exists.
 *
 * Input
 *    [1, 2, 3, 4, 5, 6, 7, 8, 9, 15]
 *    targetSum = 18
 *
 * Output:
 *    [[1, 2, 15],
 *     [3, 7, 8],
 *     [4, 6, 8],
 *     [5, 6, 7]]
 *
 * 1) Brute Force
 *    3 for loops = O(n^3)
 * 2) For each number in the array
 *    Calculate new sum needed
 *    Handle same as we did with pairs (unordered_set)
 *    O(n^2) time and O(n) space
 * 3) Sort array  - O(n log n)
 *    For each number
 *       Use pairSum to find other numbers using 2 pointer approach
 *           (one at 1st and one at last)
 *           to increase sum move left, to decrease sum move right
 *           This takes a total of O(n^2)
 *   NOTE: You can't use this for the orginal pairSum since the sorting
 *   would be the bottleneck.
 */

#include <algorithm>
#include <iostream>
#include <vector>

auto triplets(std::vector<int>& a, const int targetSum) -> std::vector<std::vector<int>> {
    std::vector<std::vector<int>> results;

    std::sort(a.begin(), a.end());

    // pick every element and solve pair sum for remaining part
    const size_t n = a.size();
    for (int i {}; i <= n - 3; ++i) {

        // 2 pointer approach
        // point to the next element and the last element
        int start { i + 1 };
        size_t end { n - 1 };

        while (start < end) {
            if (const int currentSum = a[i] + a[start] + a[end]; currentSum == targetSum) {
                results.push_back({ a[i], a[start], a[end] });
                ++start; // setup to look for more pairs
                --end;
            } else if (currentSum > targetSum) {
                --end;          // too high, try moving left
            } else {
                ++start;        // too low, try moving right
            }
        }
    }
    return results;
}

auto main() -> int {
    std::vector<int> a { 1, 2, 3, 4, 5, 6, 7, 8, 9, 15 };
    const int targetSum {18};

    auto p = triplets(a, targetSum);

    if (p.empty()) {
        std::cout << "No such pair exists\n";
    } else {
        for (auto e : p) {
            std::cout << "[" << e[0] << ", " << e[1] << ", " << e[2] << "]\n";
        }
    }
}
