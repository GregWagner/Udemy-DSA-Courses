#include <iostream>

int main() {
    int n {}, m {};
    std::cout << "Enter n and m: ";
    std::cin >> n >> m;

    int x { 1 }, y { 1 };

    while (x <= n) {
        while (y <= m) {
            std::cout << x << " x " << y << " = " << x * y << '\n';
            ++y;
        }
        y = 1;
        ++x;
    }
}