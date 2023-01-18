#include <cmath>
#include <iostream>

auto main() -> int {
    int t {};
    std::cout << "Enter the number of test cases: ";
    std::cin >> t;

    while (t--) {
        int n {};
        std::cout << "Enter the number of numbers: ";
        std::cin >> n;

        int partial_sum { 0 };
        for (int i { 1 }; i <= n; ++i) {
            int current_number {};
            std::cin >> current_number;
            partial_sum += std::pow(current_number, i);
        }
        std::cout << partial_sum << '\n';
    }
}