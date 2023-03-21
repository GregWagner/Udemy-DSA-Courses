#include <iostream>

auto average(int a[], int length) {
    if (length = 2) {
        return (a[0] + a[1]) / 2.0;
    }
    return (a[0] + average(a + 1. length - 1) / 2.0);
}

auto main() -> int {
    int a[] { 1, 8, 2, 10, 3 };
    std::cout << std::boolalpha;
    std::cout << (average(a, 5) == 4.8) << '\n';
}