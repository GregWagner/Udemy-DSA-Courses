#include <iostream>

auto main() -> int {
    std::cout << "Enter the ending value: ";
    int end {};
    std::cin >> end;

    int start { 1 };
    while (start <= end) {
        if (start % 3 == 0) {
            std::cout << start << ' ';
        }
        ++start;
    }
    std::cout << '\n';
}