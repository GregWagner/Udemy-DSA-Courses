#include <algorithm>
#include <iostream>

auto main() -> int {
    std::cout << "Enter n: ";
    int n {};
    std::cin >> n;

    int a[200];

    std::cout << "Enter n numbers: ";
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
        for (int i { 2 }; i < n; ++i) {
            if (a[i] > max_01) {
                max_02 = max_01;
                max_01 = a[i];
            } else if (a[i] > max_02) {
                max_02 = a[i];
            }
        }
        std::cout << max_01 << ' ' << max_02 << '\n';
    }
}