#include <iostream>

auto main() -> int {
    std::cout << "Enter five numbers: ";
    int a, b, c, d, e;
    std::cin >> a >> b >> c >> d >> e;

    // part a: print the average
    std::cout << (a + b + c + d + e) / 5.0 << '\n';

    // part b: the sum of the first 3 divided by the sum of the last 2
    double first_three_numbers = a + b + c;
    double last_two_numbers = d + e;
    std::cout << (first_three_numbers / last_two_numbers) << '\n';

    // part c: The average of the first 3 numbers diivided by the average of the last 2 numbers
    std::cout << (first_three_numbers / 3.0) / (last_two_numbers / 2.0) << '\n';
}