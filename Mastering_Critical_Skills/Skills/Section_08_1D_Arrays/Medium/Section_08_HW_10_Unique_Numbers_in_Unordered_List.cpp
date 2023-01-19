/*
 * Unique numbers of unordered list
 */
#include <iostream>
#include <vector>
#include <unordered_map>

void print_unique_numbers(const std::vector<int> &a) {
    std::unordered_map<int, int> m;
    for (const auto &ele : a) {
        if (m.count(ele) == 0) {
            std::cout << ele << ' ';
            m[ele] = 1;
        }
    }
    std::cout << '\n';
}

auto main() -> int {
    std::vector<int> a {1, 5, 5, 2, 5, 7, 2, 3, 3, 3, 5, 2, 7};
    print_unique_numbers(a);
}