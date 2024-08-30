#include <iostream>

auto main() -> int {
    std::cout << "Enter 3 integers: ";
    int num1 {}, num2 {}, num3 {};
    std::cin >> num1 >> num2 >> num3;

    int min = num1; // assume 1st number is smaller
    if (num2 < min) {
        min = num2;
    }
    if (num3 < min) {
        min = num3;
    }

    std::cout << min << '\n';
}