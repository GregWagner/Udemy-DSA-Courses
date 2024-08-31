#include <iostream>

auto main() -> int {
    std::cout << "Enter number: ";
    int num {};
    std::cin >> num;

    int answer {};
    if (num % 2 == 0) {
        // if even, print last digit
        answer = num % 10;
    } else {
        if (num < 1000) {
            answer = num % 100;
        } else if (num < 1000000) {
            answer = num % 10000;
        } else {
            answer = -num;
        }
    }
    std::cout << answer << '\n';
}