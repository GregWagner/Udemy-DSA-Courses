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

    bool isIncreasing { true };
    for (int i { 1 }; i < n; ++i) {
        if (a[i - 1] > a[i]) {
            isIncreasing = false;
            break;
        }
    }
    std::cout << (isIncreasing ? "Yes" : "NO") << '\n';
}