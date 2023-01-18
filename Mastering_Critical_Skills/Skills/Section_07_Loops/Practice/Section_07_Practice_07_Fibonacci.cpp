#include <iostream>

auto main() -> int {
    int n {};
    std::cout << "Enter n: ";
    std::cin >> n;

    int a {}, b { 1 }, fib { 1 };
    for (int i { 2 }; i < n; ++i) {
        a = b;
        b = fib;
        fib = a + b;
    }
    std::cout << fib << '\n';
}