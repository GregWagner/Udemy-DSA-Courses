/*
 * Smallest Pair
 * Print the smallest possible result of A[i] + A[j] + j - i
 */
#include <climits>
#include <iostream>
#include <vector>

auto smallest_pair(const std::vector<int>& a) -> int {
    size_t answer = INT_MAX;
    for (size_t i {}; i < a.size(); ++i) {
        for (size_t j { i + 1 }; j < a.size(); ++j) {
            answer = std::min(answer, a[i] + a[j] + j - i);
        }
    }
    return answer;
}

auto main() -> int {
    std::cout << std::boolalpha;
    std::vector<int> a { 20, 1, 9, 4 };
    std::cout << (smallest_pair(a) == 7) << '\n';
}
