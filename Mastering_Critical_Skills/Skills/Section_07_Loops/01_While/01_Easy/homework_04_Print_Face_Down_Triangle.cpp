#include <iostream>

auto main() -> int {
    std::cout << "Enter n: ";
    int n {};
    std::cin >> n;

    while (n) {
        int stars { 1 };
        while (stars <= n) {
            std::cout << '*' << ' ';
            ++stars;
        }
        std::cout << '\n';
        --n;
    }
}