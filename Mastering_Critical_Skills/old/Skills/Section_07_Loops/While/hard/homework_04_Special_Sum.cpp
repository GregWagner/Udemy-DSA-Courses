#include <cmath>
#include <iostream>

auto main() -> int {
    std::cout << "Enter number of test cases: ";
    int t {};
    std::cin >> t;

    while (t--) {
        std::cout << "Enter n: ";
        int n {};
        std::cin >> n;

        std::cout << "Enter n numbers: ";
        int number {};
        int sum {};
        int count { 1 };
        while (n--) {
            std::cin >> number;
            sum += std::pow(number, count);
            ++count;
        }
        std::cout << sum << '\n';
    }
}