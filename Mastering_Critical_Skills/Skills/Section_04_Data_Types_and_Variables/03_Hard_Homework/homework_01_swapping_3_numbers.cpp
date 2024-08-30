#include <iostream>

auto main() -> int {
    int num1{};
    int num2{};
    int num3{};
    std::cin >> num1 >> num2 >> num3;

    int temp = num1;
    num1 = num2;
    num2 = num3;
    num3 = temp;

    std::cout << num1 << ' ' << num2 << ' ' << num3 << '\n';
}
