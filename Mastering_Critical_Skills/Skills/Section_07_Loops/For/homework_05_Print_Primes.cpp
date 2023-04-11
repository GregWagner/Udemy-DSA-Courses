#include <iostream>

auto main() -> int {
    std::cout << "Enter integer: ";
    int n {};
    std::cin >> n;

    bool firstNumber { true };

    for (int i { 2 }; i <= n; ++i) {
        bool isPrime { true };
        for (int j { 2 }; j <= i / 2; ++j) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            if (firstNumber) {
                firstNumber = false;
            } else {
                std::cout << ", ";
            }
            std::cout << i;
        }
    }
    std::cout << '\n';
}