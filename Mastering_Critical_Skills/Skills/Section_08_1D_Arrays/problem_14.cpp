/*
 * Count increasing subarrays
 * Count how many subarrays are increasing in the array
 * easy with 3 nested loops
 * medium with 2 loops
 * hard with 1 loop
 */
#include <iostream>
#include <vector>

// Note: There is a linear solution using a formula
int count_increasing_subarray(const std::vector<int> &a) {
    int count {};

    for (size_t i {}; i < a.size(); ++i) {
        ++count;        // all single values are increasing
        size_t current {i};
        size_t next {i + 1};
        while (next < a.size() && a[current] < a[next]) {
            ++count;
            ++current;
            ++next;
        }
    }
    return count;
}

int main() {
    std::cout << std::boolalpha;
    std::vector<int> a {1, 2, 3, 4};
    std::cout << (count_increasing_subarray(a) == 10) << '\n';
    std::vector<int> b {4, 3, 2, 1};
    std::cout << (count_increasing_subarray(b) == 4) << '\n';
    std::vector<int> c {10, 20, 1, 5};
    std::cout << (count_increasing_subarray(c) == 6) << '\n';
}