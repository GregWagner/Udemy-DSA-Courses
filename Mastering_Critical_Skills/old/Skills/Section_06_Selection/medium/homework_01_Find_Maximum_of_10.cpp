#include <iostream>

auto main() -> int {

    int max {};
    std::cout << "Enter 10 integers: ";
    std::cin >> max;

    int num {};
    std::cin >> num;
    if (num > max)
        max = num;
    std::cin >> num;
    if (num > max)
        max = num;
    std::cin >> num;
    if (num > max)
        max = num;
    std::cin >> num;
    if (num > max)
        max = num;
    std::cin >> num;
    if (num > max)
        max = num;
    std::cin >> num;
    if (num > max)
        max = num;
    std::cin >> num;
    if (num > max)
        max = num;
    std::cin >> num;
    if (num > max)
        max = num;
    std::cin >> num;
    if (num > max)
        max = num;

    std::cout << max << '\n';
}