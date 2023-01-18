#include <iostream>

auto main() -> int {
    int num {};
    std::cout << "Enter a number: ";
    std::cin >> num;

    num = num < 0 ? -num : num;

    int number_of_digits {};
    while (num) {
        ++number_of_digits;
        num /= 10;
    }
    std::cout << (number_of_digits == 0 ? 1 : number_of_digits) << '\n';
}