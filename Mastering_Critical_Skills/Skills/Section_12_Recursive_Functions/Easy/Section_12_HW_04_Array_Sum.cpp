#include <iostream>

auto sum(int a[], int length) -> int {
    if (length == 1) {
        return a[0];
    }
    return a[0] + sum(a + 1, length - 1);
}

auto main() -> int {
    int a[] { 1, 8, 2, 10, 3 };
    std::cout << std::boolalpha;
    std::cout << (sum(a, 5) == 24) << '\n';
}