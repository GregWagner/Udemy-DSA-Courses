#include <iostream>

auto main() -> int {
    std::cout << "Enter eight digits: ";
    int even_01, even_02, even_03, even_04;
    int odd_01, odd_02, odd_03, odd_04;
    std::cin >> even_01 >> odd_01 >> even_02 >> odd_02
        >> even_03 >> odd_03 >> even_04 >> odd_04;

    std::cout << (odd_01 + odd_02 + odd_03 + odd_04) << ' '
              << (even_01 + even_02 + even_03 + even_04) << '\n';
}