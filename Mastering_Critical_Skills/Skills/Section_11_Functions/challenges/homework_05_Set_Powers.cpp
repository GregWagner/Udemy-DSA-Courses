#include <cmath>
#include <iostream>

// this is actually wronng
auto set_powers(int a[], int len = 5, int m = 2) -> void {
    for (int i {}; i < len; ++i) {
        a[i] = std::pow(m, i);
    }
}

auto print(int a[], int size = 5) {
    for (int i {}; i < size; ++i) {
        std::cout << a[i] << ' ';
    }
    std::cout << '\n';
}

auto main() -> int {
    int a[100];
    set_powers(a);
    print(a);

    set_powers(a, 6);
    print(a, 6);

    set_powers(a, 4, 3);
    print(a, 4);
}
