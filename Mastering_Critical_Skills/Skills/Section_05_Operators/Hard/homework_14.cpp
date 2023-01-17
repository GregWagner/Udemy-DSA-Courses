#include <iostream>

auto main() -> int {
    const int MONTHS_IN_YEAR { 12 };
    const int DAYS_IN_MONTH { 30 };
    const int DAYS_IN_YEAR { DAYS_IN_MONTH * MONTHS_IN_YEAR };

    int age {};
    std::cout << "Enter age: ";
    std::cin >> age;

    int year = age / DAYS_IN_YEAR;

    age %= DAYS_IN_YEAR;
    int months = age / DAYS_IN_MONTH;

    age %= DAYS_IN_MONTH;
    std::cout << year << ' ' << months << ' ' << age << '\n';
}