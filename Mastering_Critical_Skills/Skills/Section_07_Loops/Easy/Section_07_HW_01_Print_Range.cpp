#include <iostream>

auto main() -> int {
    int start {};
    int end {};
    std::cout << "Enter start and end of range: ";
    std::cin >> start >> end;

    while (start <= end) {
        std::cout << start << '\n';
        ++start;
    }
}