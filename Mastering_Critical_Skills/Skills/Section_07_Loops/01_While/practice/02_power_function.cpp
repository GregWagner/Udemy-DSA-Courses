#include <iostream>

auto main() -> int {
    std::cout << "Enter 2 integers: ";
    int x {}, power {};
    std::cin >> x >> power;

    int answer { 1 };
    while (power > 0) {
        answer *= x;
        --power;
    }
    std::cout << answer << '\n';
}
