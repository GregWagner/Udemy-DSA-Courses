#include <iostream>

int main() {
    int num {};
    std::cin >> num;

    bool is_even1 = num % 2 == 0;
    bool is_even2 = (num / 2) * 2 == num;
    bool is_even3 = num % 10 == 0 || num % 10 == 2 || num % 10 == 4 || num % 10 == 6 || num % 10 == 8;

    std::cout << std::boolalpha
              << is_even1 << ' '
              << is_even2 << ' '
              << is_even3 << '\n';
}