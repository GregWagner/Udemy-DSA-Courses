#include <iostream>

auto main() -> int {
    std::cout << "Enter an integer: ";
    int n {};
    std::cin >> n;

    // print top
    int stars { 1 };
    int spaces { n - 1 };
    int row { 1 };
    while (row <= n) {
        int spaceCount {};
        while (spaceCount < spaces) {
            std::cout << ' ';
            ++spaceCount;
        }

        int starsCount {};
        while (starsCount < stars) {
            std::cout << '*';
            ++starsCount;
        }
        std::cout << '\n';

        stars += 2;
        --spaces;
        ++row;
    }

    // print bottom
    spaces = 0;
    stars -= 2;
    while (row--) {
        int spaceCount {};
        while (spaceCount < spaces) {
            std::cout << ' ';
            ++spaceCount;
        }

        int starsCount {};
        while (starsCount < stars) {
            std::cout << '*';
            ++starsCount;
        }
        std::cout << '\n';

        stars -= 2;
        ++spaces;
    }
}