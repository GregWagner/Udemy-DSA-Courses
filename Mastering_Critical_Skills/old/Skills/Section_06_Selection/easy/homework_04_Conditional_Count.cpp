#include <iostream>

auto main() -> int {
    std::cout << "Enter x and then 5 other numbers: ";
    int x {}, num1 {}, num2 {}, num3 {}, num4 {}, num5 {};
    std::cin >> x >> num1 >> num2 >> num3 >> num4 >> num5;

    int numbersLargerThanX {};
    int numbersSmallestThanX {};

    num1 <= x ? ++numbersSmallestThanX : ++numbersLargerThanX;
    num2 <= x ? ++numbersSmallestThanX : ++numbersLargerThanX;
    num3 <= x ? ++numbersSmallestThanX : ++numbersLargerThanX;
    num4 <= x ? ++numbersSmallestThanX : ++numbersLargerThanX;
    num5 <= x ? ++numbersSmallestThanX : ++numbersLargerThanX;

    std::cout << numbersSmallestThanX << ' ' << numbersLargerThanX << '\n';
}