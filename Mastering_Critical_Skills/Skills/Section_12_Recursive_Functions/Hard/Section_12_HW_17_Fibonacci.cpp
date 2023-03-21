#include <iostream>

auto fib(int n) {
    if (n <= 1) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

auto main() -> int {
    std::cout << std::boolalpha;
    std::cout << (fib(6) == 13) << '\n';
}