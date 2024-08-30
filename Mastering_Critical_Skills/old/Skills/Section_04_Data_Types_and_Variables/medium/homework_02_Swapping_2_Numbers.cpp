#include <iostream>

auto main() -> int {
    std::cout << "Enter 2 numbers: ";
    int num1 {};
    int num2 {};
    std::cin >> num1 >> num2;

    std::cout << "Before swap: " << num1 << ' ' << num2 << '\n';

    int temp {num1};
    num1 = num2;
    num2 = temp;
    std::cout << "After swap:  " << num1 << ' ' << num2 << '\n';
}
