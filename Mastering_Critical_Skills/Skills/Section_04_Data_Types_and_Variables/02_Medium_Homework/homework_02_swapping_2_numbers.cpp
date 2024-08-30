#include <iostream>

auto main() -> int {
    int num1{};
    int num2{};
    std::cin >> num1 >> num2;

    int temp = num1;
    num1 = num2;
    num2 = temp;

    std::cout << num1 << ' ' << num2 << '\n';
}
