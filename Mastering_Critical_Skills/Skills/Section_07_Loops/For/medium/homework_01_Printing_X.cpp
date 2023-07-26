#include <iostream>

auto main() -> int {
    std::cout << "Enter n (must be odd): ";
    int n {};
    std::cin >> n;

    bool goingDown { true };
    int spacesBefore {};
    int spacesAfter { n - 2 };
    for (int row { 1 }; row <= n; ++row) {
        for (int i {}; i <= spacesBefore; ++i) {
            std::cout << ' ';
        }
        std::cout << '*';
        for (int i {}; i < spacesAfter; ++i) {
            std::cout << ' ';
        }
        std::cout << "*\n";

        if (goingDown) {
            ++spacesBefore;
            spacesAfter -= 2;
        } else {
            --spacesBefore;
            spacesAfter += 2;
        }
        if (spacesAfter <= 0) {
            for (int i {}; i <= spacesBefore; ++i) {
                std::cout << ' ';
            }
            std::cout << "*\n";
            goingDown = false;
            ++row;
            --spacesBefore;
            spacesAfter = 1;
        }
    }
}