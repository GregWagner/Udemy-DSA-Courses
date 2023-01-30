#include <iostream>

auto max(int a, int b, int c) -> int {
    return std::max(a, std::max(b, c));
}

auto max(int a, int b, int c, int d) -> int {
    return std::max(a, max(b, c, d));
}

auto max(int a, int b, int c, int d, int e) -> int {
    return std::max(a, max(b, c, d, e));
}

auto max(int a, int b, int c, int d, int e, int f) -> int {
    return std::max(a, max(b, c, d, e, f));
}

auto main() -> int {
    std::cout << max(6, 5, 4, 3, 2, 1) << '\n';
}