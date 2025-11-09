/*
 * Example 2 - Video 11
 * Compute the nth fibonacci number
 */
#include <iostream>

auto fibonaci(long n) -> long {
    // base case
    if (n <= 1) {
        return n;
    }

    // recursive case
    return fibonaci(n - 1) + fibonaci(n - 2);
}

auto main() -> int {
    std::cout << "1: " << fibonaci(1) << '\n';
    std::cout << "2: " << fibonaci(2) << '\n';
    std::cout << "3: " << fibonaci(3) << '\n';
    std::cout << "4: " << fibonaci(4) << '\n';
    std::cout << "5: " << fibonaci(5) << '\n';
    std::cout << "6: " << fibonaci(6) << '\n';
}
