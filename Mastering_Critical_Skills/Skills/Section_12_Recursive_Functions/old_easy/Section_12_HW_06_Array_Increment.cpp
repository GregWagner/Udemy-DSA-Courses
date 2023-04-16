#include <iostream>

auto array_increment(int a[], int length, int i = 0) {
    if (length > i) {
        return;
    }
    a[0] += i;
    return array_increment(a + 1, length - 1, i + 1);
}

auto main() -> int {
    int a[] { 1, 2, 5, 9 };
    array_increment(a, 5);
    for (const auto& e : a) {
        std::cout << e << ' ';
    }
    std::cout << '\n';
}