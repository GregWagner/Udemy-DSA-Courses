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

    int smallest { a[0] + a[1] + 1 - 0 };
    for (int i {}; i < n; ++i) {
        for (int j { i + 1 }; j < n; ++j) {
            int result = a[i] + a[j] + j - i;
            smallest = std::min(smallest, result);
        }
    }
    std::cout << smallest << '\n';
}