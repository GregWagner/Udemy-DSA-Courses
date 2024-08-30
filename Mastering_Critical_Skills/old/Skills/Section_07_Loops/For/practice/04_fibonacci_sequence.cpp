#include <iostream>

auto main() -> int {
    std::cout << "Enter nummber: ";
    int n;
    std::cin >> n;

    int a {};
    int b { 1 };

    int sum { a + b };
    for (int i { 1 }; i <= n; ++i) {
        sum = a + b;
        a = b;
        b = sum;
        std::cout << sum << ' ';
    }
    std::cout << '\n';
}