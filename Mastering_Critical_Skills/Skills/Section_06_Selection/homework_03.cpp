#include <iostream>

int main() {
    int a {}, b {}, c {};
    std::cout << "Enter three integers: ";
    std::cin >> a >> b >> c;

    int max { -1 };
    if (a < 100) {
        max = a;
    } else if (b < 100) {
        max = b;
    } else if (c < 100) {
        max = c;
    }

    if (a < 100 && a > max) {
        max = a;
    }
    if (b < 100 && b > max) {
        max = b;
    }
    if (c < 100 && c > max) {
        max = c;
    }
    std::cout << max << '\n';
}