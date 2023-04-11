#include <iostream>

auto main() -> int {
    std::cout << "Enter n: ";
    int n {};
    std::cin >> n;

    int step { 1 };
    while (step <= n) {
        int stars { 1 };
        while (stars <= step) {
            std::cout << '*' << ' ';
            ++stars;
        }
        std::cout << '\n';
        ++step;
    }
}