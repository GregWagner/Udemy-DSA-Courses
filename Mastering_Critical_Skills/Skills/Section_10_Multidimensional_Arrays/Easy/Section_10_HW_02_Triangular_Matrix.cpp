#include <iostream>

auto main() -> int {
    int n {};
    std::cout << "Enter n: ";
    std::cin >> n;

    int sum_upper {};
    int sum_lower {};
    for (int i {}; i < n; ++i) {
        for (int j {}; j < n; ++j) {
            int value {};
            std::cin >> value;
            if (i <= j) {
                sum_lower += value;
            }
            if (i >= j) {
                sum_upper += value;
            }
        }
    }
    std::cout << sum_upper << ' ' << sum_lower << '\n';
}