#include <iostream>

int main() {
    int a {}, b {}, c {};
    std::cout << "Enter three numbers: ";
    std::cin >> a >> b >> c;

    int smallest = std::min(a, std::min(b, c));
    int largest = std::max(a, std::max(b, c));
    int sum = a + b + c;

    std::cout << smallest << ' ' << sum - smallest - largest
              << ' ' << largest << '\n';
}