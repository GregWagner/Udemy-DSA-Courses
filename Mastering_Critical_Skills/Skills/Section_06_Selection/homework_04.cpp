#include <iostream>

int main() {
    int x {};
    std::cout << "Enter the base number: ";
    std::cin >> x;

    int a {}, b {}, c {}, d {}, e {};
    std::cout << "Enter 5 more numbers: ";
    std::cin >> a >> b >> c >> d >> e;

    int larger {};
    if (a > x) {
        ++larger;
    }
    if (b > x) {
        ++larger;
    }
    if (c > x) {
        ++larger;
    }
    if (d > x) {
        ++larger;
    }
    if (e > x) {
        ++larger;
    }
    std::cout << 5 - larger << ' ' << larger << '\n';
}