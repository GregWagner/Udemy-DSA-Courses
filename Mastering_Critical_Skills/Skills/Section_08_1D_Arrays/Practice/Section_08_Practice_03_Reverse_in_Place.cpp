#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

// Reverse in place
auto main() -> int {
    size_t n {};
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    std::vector<int> a(n);
    for (size_t i {}; i < a.size(); ++i) {
        std::cin >> a[i];
    }
    size_t start {};
    size_t end { a.size() - 1 };
    while (start < end) {
        std::cout << "Swapping\n";
        std::swap(a[start], a[end]);
        ++start;
        --end;
    }

    for (const auto& ele : a) {
        std::cout << ele << ' ';
    }
    std::cout << '\n';
}