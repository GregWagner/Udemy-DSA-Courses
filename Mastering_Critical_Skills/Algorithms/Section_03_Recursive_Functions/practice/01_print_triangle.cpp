#include <iostream>

auto print_triangle(int levels) {
    if (levels == 0) {
        return;
    }

    // print starting with one line
    print_triangle(levels - 1);

    for (int i{}; i < levels; ++i) {
        std::cout << '*';
    }
    std::cout << '\n';

    // print starting with n lines
    // print_triangle(levels - 1);
}

auto main() -> int {
    print_triangle(5);
}
