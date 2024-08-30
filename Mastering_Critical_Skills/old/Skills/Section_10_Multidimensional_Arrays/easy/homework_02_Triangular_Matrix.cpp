#include <iostream>

auto main() -> int {
    int a[101][101];

    std::cout << "Enter size of matrix: ";
    unsigned n {};
    std::cin >> n;

    for (size_t r {}; r < n; ++r) {
        for (size_t c {}; c < n; ++c) {
            std::cin >> a[r][c];
        }
    }

    int lowerSum {};
    for (size_t r {}; r < n; ++r) {
        for (size_t c {}; c <= r; ++c) {
            lowerSum += a[r][c];
        }
    }

    int upperSum {};
    for (size_t r {}; r < n; ++r) {
        for (size_t c { r }; c < n; ++c) {
            upperSum += a[r][c];
        }
    }

    std::cout << lowerSum << ' ' << upperSum << '\n';
}