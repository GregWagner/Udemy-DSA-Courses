#include <iostream>

auto main() -> int {
    std::cout << "Enter 2 integers: ";
    int x {}, y {};
    std::cin >> x >> y;

    int answer { 1 };
    while (y > 0) {
        answer *= x;
        --y;
    }
    std::cout << answer << '\n';
}