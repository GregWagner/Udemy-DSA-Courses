#include <iostream>

auto main() -> int {
    int a{}, b{}, c{}, d{}, e{}, f{}, g{}, h{};
    std::cin >> a >> b >> c >> d >> e >> f >> g >> h;

    std::cout << b + d + f + h << ' ';
    std::cout << a + c + e + g << '\n';
}
