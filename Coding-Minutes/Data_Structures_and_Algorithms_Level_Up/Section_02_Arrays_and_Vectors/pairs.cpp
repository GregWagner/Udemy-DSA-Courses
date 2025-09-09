/*
* Pairs
 *
 * Given an array containing N integers and a number totalSum denoting a
 * target sum, find two distinct integers that can pair up to form the
 * target sum. Assume that there will only be one such pair.
 *
 * Input:
 *    array = [10, 5, 2, 3, -6, 9,, 11]
 *    S = 4
 * Output:
 *    [10, -6]
 *
 * Possiblle Solutions
 * 1) Brute force Approach
 *    O(n^2)
 *    2 nested for loops
 * 2) Sort the array
 *    Determine the number needed
 *    Binary search for that number
 *    O(n log n)
 * 3) Hash table
 *    Can look up in O(1) time
 *    O(n)
 *    Go through the array and for each value check if the
 *    needed number is in the hash table, if not add it
 *    and move to the next number
 *    Note: creating the hash first may cause a problem if x + x = S
 */
#include <iostream>
#include <unordered_set>
#include <vector>

auto pairSumBad(const std::vector<int>& a, int totalSum) -> std::vector<int> {
    std::vector<int> results(2, 0);
    for (size_t i {}; i < a.size(); ++i) {
        for (size_t j {i + 1}; j < a.size(); ++j) {
            if (a[i] + a[j] == totalSum) {
                results[0]  = a[i];
                results[1]  = a[j];
                return results;
            }
        }
    }
    return results;
}

auto pairSum(const std::vector<int>& a, int totalSum) -> std::vector<int> {
    std::unordered_set<int> hash;
    std::vector<int> results(2, 0);

    for (auto const& value : a) {
        // check if the number needed has already been added to the hash
        if (hash.find(totalSum - value) != hash.end()) {
            // answer found
            results[0] = value;
            results[1] = totalSum - value;
            break;
        }
        hash.insert(value);
    }
    return results;
}

auto main() -> int {
    std::vector<int> a { 10, 5, 2, 3, -6, 9, 11 };
    const int totalSum {4};

    auto p = pairSum(a, totalSum);
    if (p.empty()) {
        std::cout << "No such pair exists\n";
    } else {
        std::cout << "[" << p[0] << ", " << p[1] << "]\n";
    }
}
