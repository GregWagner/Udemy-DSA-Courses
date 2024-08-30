#include <iostream>

auto main() -> int {
    std::cout << "Enter a number: ";
    int num {};
    std::cin >> num;

    if (num < 10000) {
        std::cout << num << " is a small number\n";
    } else {
        int num1 { num % 10 };
        int num2 { num / 10 % 10 };
        int num3 { num / 100 % 10 };
        int sum { num1 + num2 + num3 };

        if (sum % 2 != 0) {
            std::cout << num << " is a great number\n";
        } else {
            if (num1 % 2 != 0 || num2 % 2 != 0 || num3 % 2 != 0) {
                std::cout << num << " is a good number\n";
            } else {
                std::cout << num << " is a bad number\n";
            }
        }
    }
}