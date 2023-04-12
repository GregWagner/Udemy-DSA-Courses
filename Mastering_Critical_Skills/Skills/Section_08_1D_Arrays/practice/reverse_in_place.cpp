#include <algorithm>
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

    int start {};
    int end { n - 1 };
    while (start < end) {
        std::swap(a[start++], a[end--]);
    }

    for (const auto& ele : a) {
        std::cout << ele << ' ';
    }
    std::cout << '\n';
}