/*
 * Sum numbers from 1 to n
 */
#include <iostream>

auto main() -> int {
    int n {};
    std::cout << "Enter a number: ";
    std::cin >> n;

    std::cout << (n * (n + 1)) / 2 << '\n';
}