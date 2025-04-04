#include <iostream>
#include <cassert>

auto factorial(long n) -> long {
    // base case
    if (n <= 1) {
        return n;
    }

    // recursive case
    return n * factorial(n - 1);
}

auto main() -> int {
    // Test base case
    assert(factorial(0) == 0);
    assert(factorial(1) == 1);

    // Test positive numbers
    assert(factorial(2) == 2);
    assert(factorial(3) == 6);
    assert(factorial(5) == 120);

    std::cout << "All tests passed!" << std::endl;
}
