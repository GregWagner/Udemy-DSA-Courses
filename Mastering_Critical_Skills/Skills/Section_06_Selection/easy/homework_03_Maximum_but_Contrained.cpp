#include <iostream>

auto main() -> int {
    std::cout << "Enter 3 integers: ";
    int num1 {}, num2 {}, num3 {};
    std::cin >> num1 >> num2 >> num3;

    int max { -1 };

    if (num1 < 100) {
        max = num1;
    }
    if (num2 < 100 && num2 > max) {
        max = num2;
    }
    if (num3 < 100 && num3 > max) {
        max = num3;
    }

    std::cout << max << '\n';
}