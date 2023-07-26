#include <iostream>
#include <vector>

auto main() -> int {
    std::cout << "Enter n: ";
    int n;
    std::cin >> n;

    std::vector<int> a(n);

    std::cout << "Enter " << n << " distinct integers: ";
    for (int i {}; i < n; ++i) {
        std::cin >> a[i];
    }

    int max_01 {}, max_02 {};
    if (n > 2) {
        max_01 = a[0];
        max_02 = a[1];
        if (a[0] < a[1]) {
            std::swap(max_01, max_02);
        }
        for (int i { 1 }; i < n; ++i) {
            if (a[i] > max_01) {
                max_02 = max_01;
                max_01 = a[i];
            } else if (a[i] > max_02) {
                max_02 = a[i];
            }
        }
        std::cout << max_01 + max_02 << '\n';
    }
}