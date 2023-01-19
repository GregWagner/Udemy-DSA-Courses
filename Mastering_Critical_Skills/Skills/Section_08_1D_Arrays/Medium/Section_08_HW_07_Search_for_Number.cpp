/*
 * Search for a number
 * Find the last occurrence in the array and print its index
 */
#include <iostream>
#include <vector>

// brute force
auto search_for_01(const std::vector<int>& a, int number) -> int {
    for (size_t i { a.size() - 1 }; i > 0; --i) {
        if (a[i] == number) {
            return i;
        }
    }
    return -1;
}

// using frequency array
auto search_for(const std::vector<int>& a, int number) -> int {
    std::vector<int> freq(501, -1);

    for (size_t i {}; i < a.size(); ++i) {
        freq[a[i]] = i;
    }
    return freq[number];
}

auto main() -> int {
    std::cout << std::boolalpha;
    std::vector<int> a { 1, 2, 7, 3, 7 };
    std::cout << (search_for(a, 7) == 4) << '\n';
    std::cout << (search_for(a, 9) == -1) << '\n';
    std::cout << (search_for(a, 2) == 1) << '\n';
}