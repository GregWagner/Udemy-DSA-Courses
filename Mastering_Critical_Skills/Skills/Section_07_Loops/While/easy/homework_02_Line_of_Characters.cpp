#include <iostream>

auto main() -> int {
    std::cout << "Enter n and a character: ";
    int n {};
    char c {};
    std::cin >> n >> c;

    while (n--) {
        std::cout << c;
    }
    std::cout << '\n';
}
