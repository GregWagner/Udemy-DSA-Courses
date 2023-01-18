/*
 * Replace MinMax
 * Print the array after doing the following:
 *      Find min number
 *      Find max number
 *      Replace each min number with max number and visa versa
 */
#include <algorithm>
#include <iostream>
#include <vector>

void replace_min_max(std::vector<int>& a) {
    const auto [min, max] = std::minmax_element(begin(a), end(a));
    // not sure why this is needed
    int minValue { *min };
    int maxValue { *max };
    for (size_t i {}; i < a.size(); ++i) {
        if (a[i] == minValue) {
            a[i] = maxValue;
        } else if (a[i] == maxValue) {
            a[i] = minValue;
        }
    }
}

auto main() -> int {
    std::vector<int> a { 4, 1, 3, 10, 8, 10, 10 };
    replace_min_max(a);
    for (const auto& e : a) {
        std::cout << e << ' ';
    }
    std::cout << '\n';
}
