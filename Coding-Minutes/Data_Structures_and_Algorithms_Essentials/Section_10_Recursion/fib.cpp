#include <cstdint>
#include <iostream>

uint64_t fib(uint64_t n) {
    if (n <= 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int main() {
    std::cout << fib(6) << '\n';
}
