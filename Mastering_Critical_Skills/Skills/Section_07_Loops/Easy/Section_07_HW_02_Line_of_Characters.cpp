#include <iostream>

auto main() -> int {
    int n {};
    char c {};
    std::cout << "Enter count and a character: ";
    std::cin >> n >> c;

    while (n--) {
        std::cout << c;
    }
    std::cout << '\n';
}