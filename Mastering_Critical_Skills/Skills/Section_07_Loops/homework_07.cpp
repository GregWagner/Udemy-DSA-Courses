#include <iostream>

int main() {
    int n {};
    std::cout << "Enter max nummber: ";
    std::cin >> n;

    int i {};
    while (i <= n) {
        if (i % 8 == 0 || (i % 4 == 0 && i % 3 == 0)) {
            std::cout << i << ' ';
        }
        ++i;
    }
    std::cout << '\n';
}