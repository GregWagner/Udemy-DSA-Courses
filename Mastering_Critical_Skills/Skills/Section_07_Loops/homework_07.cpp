#include <iostream>

auto main() -> int {
    int n {};
    std::cout << "Enter max number: ";
    std::cin >> n;

    int i {};
    while (i <= n) {
        if (i % 8 == 0 || (i % 4 == 0 && i % 3 == 0)) {
            std::cout << i << ' ';
        }
        ++i;
    }
    std::cout << '\n';
}