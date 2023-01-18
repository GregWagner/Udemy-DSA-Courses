#include <iostream>

auto main() -> int {
    int x {};
    std::cout << "Enter a number: ";
    std::cin >> x;

    int num { 1 };
    while (num <= x) {
        if (num % 3 == 0) {
            std::cout << num << ' ';
        }
        ++num;
    }
    std::cout << '\n';
}