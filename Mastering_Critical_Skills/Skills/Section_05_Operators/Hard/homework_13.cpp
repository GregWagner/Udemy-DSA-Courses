#include <iostream>

auto main() -> int {
    int num {};
    std::cout << "Enter a number: ";
    std::cin >> num;

    bool is_even = num % 2 == 0;
    int answer = is_even * 100 + !is_even * 7;
    std::cout << answer << '\n';
}