#include <iostream>

auto main() -> int {
    int n {};
    std::cout << "Enter n: ";
    std::cin >> n;

    int count {};
    int i {};
    while (count < n) {
        if (i % 3 == 0 && i % 4 != 0) {
            ++count;
            std::cout << i << ' ';
        }
        ++i;
    }
    std::cout << '\n';
}