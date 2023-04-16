#include <iostream>

auto arr_max(const int *a, int length) {
    if (length == 1) {
        return a[0];
    }
    return std::max(a[0], arr_max(a + 1, length - 1));
}

auto main() -> int {
    int a[] { 1, 8, 2, 10, 3 };
    std::cout << std::boolalpha;
    std::cout << (arr_max(a, 5) == 10) << '\n';
}