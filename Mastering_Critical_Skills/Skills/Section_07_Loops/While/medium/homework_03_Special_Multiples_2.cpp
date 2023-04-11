#include <iostream>

auto main() -> int {
    std::cout << "Enter an integer: ";
    int n;
    std::cin >> n;

    int num { 1 };
    int count {};
    while (count < n) {
        if (num % 3 == 0 && num % 4 != 0) {
            std::cout << num << ' ';
            ++count;
        }
        ++num;
    }
    std::cout << '\n';
}