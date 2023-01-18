/*
 * Unique numbers in ordered list
 * Print the unique list of numbers, but preserve the given order
 */
#include <iostream>
#include <vector>

auto unique_numbers_in_ordered_list(const std::vector<int>& a) -> std::vector<int> {
    std::vector<int> results { a[0] };
    int currentElement { a[0] };
    for (size_t i { 1 }; i < a.size(); ++i) {
        if (a[i] != currentElement) {
            results.push_back(a[i]);
            currentElement = a[i];
        }
    }
    return results;
}

auto unique_numbers_in_ordered_list_1(const std::vector<int>& a) -> void {
    int currentElement { a[0] };
    std::cout << currentElement << ' ';
    for (size_t i { 1 }; i < a.size(); ++i) {
        if (a[i] != currentElement) {
            currentElement = a[i];
            std::cout << currentElement << ' ';
        }
    }
    std::cout << '\n';
}

auto main() -> int {
    std::vector<int> a { 1, 1, 2, 2, 2, 5, 6, 6, 7, 8, 9, 9 };
    auto result = unique_numbers_in_ordered_list(a);
    for (const auto& e : result) {
        std::cout << e << ' ';
    }
    std::cout << '\n';

    unique_numbers_in_ordered_list_1(a);
}