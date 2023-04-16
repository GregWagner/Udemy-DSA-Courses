#include <iostream>

auto main() -> int {
    std::cout << "Enter a number: ";
    std::string input {};
    std::cin >> input;

    int num {};
    for (auto const& c : input) {
        num *= 10;
        num += c - '0';
    }
    std::cout << num << ' ' << num * 3 << '\n';
}