#include <iostream>

auto main() -> int {
    std::cout << "Enter 3 numbers: ";
    int num1 {};
    int num2 {};
    int num3 {};
    std::cin >> num1 >> num2 >> num3;

    std::cout << "Before swap: " << num1 << ' '
              << num2 << ' ' << num3 << '\n';

    int temp {num1};
    num1 = num2;
    num2 = num3;
    num3 = temp;
    std::cout << "After swap:  " << num1 << ' '
              << num2 << ' ' << num3 << '\n';
}
