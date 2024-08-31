#include <iostream>

auto main() -> int {
    std::cout << "Enter 2 integers: ";
    int num1 {}, num2 {};
    std::cin >> num1 >> num2;

    int min { num1 }; // assume first number is smaller
    if (num1 > num2) {
        min = num2;
    }

    std::cout << min << '\n';
}