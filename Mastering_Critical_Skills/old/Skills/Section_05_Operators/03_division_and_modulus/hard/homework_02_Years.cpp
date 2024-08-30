#include <iostream>

auto main() -> int {
    std::cout << "Enter number of days: ";
    int days {};
    std::cin >> days;

    int totalYears { days / 360 };
    days -= totalYears * 360;

    int totalMonths { days / 30 };
    days -= totalMonths * 30;

    std::cout << totalYears << '\t' << totalMonths
              << '\t' << days << '\n';
}