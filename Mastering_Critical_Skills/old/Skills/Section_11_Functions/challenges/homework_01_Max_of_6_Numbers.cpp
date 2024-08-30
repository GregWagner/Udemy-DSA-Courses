#include <iostream>

auto max(int a, int b, int c) -> int {
    std::max(a, std::max(b, c));
}

auto max(int a, int b, int c, int d) -> int {
    return std::max(max(a, b, c), d);
}

auto max(int a, int b, int c, int d, int e) -> int {
    return std::max(max(a, b, c, d), e);
}

auto max(int a, int b, int c, int d, int e, int f) -> int {
    return std::max(max(a, b, c, d, e), f);
}

auto main() -> int {
    std::cout << "Enter to 6 numbers: ";
    int a {}, b {}, c {}, d {}, e {}, f {};
    std::cin >> a >> b >> c >> d >> e >> f;

    std::cout << max(a, b, c, d, e, f) << '\n';
}