#include <iostream>

auto main() -> int {
    int num {};
    std::cout << "Enter a number: ";
    std::cin >> num;

    if (num < 10000) {
        std::cout << num << " is a small number.\n";
    } else {
        int first_digit { num % 10 };
        int second_digit { num % 100 / 10 };
        int third_digit { num % 1000 / 100 };
        int sum { first_digit + second_digit + third_digit };

        if (sum % 2 != 0) { // handles negative numbers
            std::cout << sum << " is a greater number ";
        } else {
            if (first_digit % 2 == 1 || second_digit % 2 == 1 || third_digit % 2 == 1) {
                std::cout << "and it is a lucky number.\n";
            } else {
                std::cout << "and it is a bad number.\n";
            }
        }
    }
}