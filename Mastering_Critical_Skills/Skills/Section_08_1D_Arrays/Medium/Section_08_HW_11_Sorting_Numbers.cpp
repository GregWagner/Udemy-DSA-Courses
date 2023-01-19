/*
 * Soring numbers
 * Count sort algorithm - the most efficient algorithm if values are small
 */
#include <iostream>
#include <vector>

void sort(const std::vector<int> &a) {
    // values are between 0 and 500
    std::vector<int> results(501, 0);
    for (const auto &ele : a) {
        ++results[ele];
    }

    for (size_t i {}; i < results.size(); ++i) {
        if (results[i]) {
            for (int j {}; j < results[i]; ++j) {
                std::cout << i << ' ';
            }
        }
    }
    std::cout << '\n';
}

auto main() -> int {
    std::vector<int> a {1, 5, 5, 2, 5, 7, 2, 3, 3, 3, 5, 2, 7};
    sort(a);
}