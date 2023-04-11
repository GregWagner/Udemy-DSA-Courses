#include <iostream>

auto main() -> int {
    std::cout << "Enter an integer: ";
    int n {};
    std::cin >> n;

    int num {};
    while (num <= n) {
        // note: the ifs could be combined with ||
        if (num % 8 == 0) {
            std::cout << num << ' ';
        } else if (num % 3 == 0 && num % 4 == 0) {
            std::cout << num << ' ';
        }
        ++num;
    }
    std::cout << '\n';
}