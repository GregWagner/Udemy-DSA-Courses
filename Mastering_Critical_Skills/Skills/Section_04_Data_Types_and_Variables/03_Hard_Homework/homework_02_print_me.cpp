#include <iostream>

auto main() -> int {
    std::cout << "Enter two integers (this 2nd must be either -1 or 1): ";
    int a{}, b{};
    std::cin >> a >> b;

    // convert -1 and 1 to 0 and 1
    std::cout << ((b + 1) / 2) * (a * a) + ((b - 1) / -2) * (a * a + 1) << '\n';
}

/*
   -1 + 1 = 0 / 2 = 0
    1 + 1 = 2 / 2 = 1

   -1 - 1 = -2 / -2 = 1
    1 - 1 = 0 / -2 = 0
*/
