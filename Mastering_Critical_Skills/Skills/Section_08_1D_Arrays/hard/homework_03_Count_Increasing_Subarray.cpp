#include <iostream>
#include <vector>

auto main() -> int {
    std::cout << "Enter n: ";
    int n {};
    std::cin >> n;

    std::vector<int> a(n);
    for (int i {}; i < n; ++i) {
        std::cin >> a[i];
    }

    // Using 3 nested loops
    int count {};
    for (unsigned start {}; start < a.size(); ++start) {
        for (unsigned end { start + 1 }; end < a.size(); ++end) {

        }
    }
}