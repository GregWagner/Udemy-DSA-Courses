/*
 * Note this coulld have been done with :
 * Spaces are n - row
 * Stars are 2 * row - 1
 */
#include <iostream>

auto main() -> int {
    int n {};
    std::cout << "Enter n: ";
    std::cin >> n;

    int rows { n };
    int stars { 1 };
    int spaces { n - stars };
    while (rows--) {
        int spaces_printed {};
        while (spaces_printed < spaces) {
            std::cout << ' ';
            ++spaces_printed;
        }
        int stars_printed {};
        while (stars_printed < stars) {
            std::cout << '*';
            ++stars_printed;
        }
        stars += 2;
        --spaces;
        std::cout << '\n';
    }

    stars -= 2;
    ++spaces;

    rows = n;
    while (rows--) {
        int spaces_printed {};
        while (spaces_printed < spaces) {
            std::cout << ' ';
            ++spaces_printed;
        }
        int stars_printed {};
        while (stars_printed < stars) {
            std::cout << '*';
            ++stars_printed;
        }
        stars -= 2;
        ++spaces;
        std::cout << '\n';
    }
}