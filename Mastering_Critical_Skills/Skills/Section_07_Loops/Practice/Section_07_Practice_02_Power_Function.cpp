#include <iostream>

auto main() -> int {
    int x {}, y {};
    std::cout << "Enter x and y: ";
    std::cin >> x >> y;

    int answer { 1 };
    while (y) {
        answer *= x;
        --y;
    }
    std::cout << answer << '\n';
}