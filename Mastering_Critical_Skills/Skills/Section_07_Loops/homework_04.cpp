#include <iostream>

int main() {
    int n {};
    std::cout << "Enter the number of rows: ";
    std::cin >> n;

    while (n > 0) {
        int stars = n;
        while (stars > 0) {
            std::cout << "*";
            --stars;
        }
        std::cout << '\n';
        --n;
    }
}