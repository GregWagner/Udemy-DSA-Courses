#include <iostream>

auto main() -> int {
    int n {};
    std::cout << "Enter a number: ";
    std::cin >> n;

    if (n % 2 == 0) {
        std::cout << "Even: Last digit is " << n % 10 << '\n';
    } else {
        if (n < 1000) {
            std::cout << "Odd and lt 1000: Last 2 digits are " << n % 100 << '\n';
        } else if (n < 1000000) {
            std::cout << "Odd and lt 1000000: Last 4 digits are " << n % 10000 << '\n';
        } else {
            std::cout << "Negative of number is " << -n << '\n';
        }
    }
}