#include <iostream>

auto main() -> int {
    int rows {};
    std::cout << "Enter number of rows: ";
    std::cin >> rows;

    int stars { 1 };
    while (rows--) {
        for (int i {}; i < stars; ++i) {
            std::cout << "*";
        }
        std::cout << '\n';
        ++stars;
    }
}