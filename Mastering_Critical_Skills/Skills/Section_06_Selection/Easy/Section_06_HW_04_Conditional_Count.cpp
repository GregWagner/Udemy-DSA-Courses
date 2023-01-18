#include <iostream>

auto main() -> int {
    int x {};
    std::cout << "Enter the base number: ";
    std::cin >> x;

    int d {};
    int e {};
    int b {};
    int c {};
    int a {};
    std::cout << "Enter 5 more numbers: ";
    std::cin >> a >> b >> c >> d >> e;

    int larger {};
    larger += (a <= x);
    larger += (b <= x);
    larger += (c <= x);
    larger += (d <= x);
    larger += (e <= x);

    std::cout << 5 - larger << ' ' << larger << '\n';
}