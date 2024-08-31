#include <iostream>
#include <vector>

auto main() -> int {
    std::cout << "Enter n: ";
    int n {};
    std::cin >> n;

    std::vector<int> a(n);

    int min { 2001 };
    int max { -1 };

    for (int i {}; i < n; ++i) {
        std::cin >> a[i];
        min = std::min(min, a[i]);
        max = std::max(max, a[i]);
    }

    for (int i {}; i < n; ++i) {
        if (a[i] == min) {
            a[i] = max;
        } else if (a[i] == max) {
            a[i] = min;
        }
    }

    for (const auto& ele : a) {
        std::cout << ele << ' ';
    }
    std::cout << '\n';
}