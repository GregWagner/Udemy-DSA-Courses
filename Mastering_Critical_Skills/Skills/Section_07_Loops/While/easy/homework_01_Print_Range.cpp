#include <iostream>

auto main() -> int {
    std::cout << "Enter starting and ending numbers: ";
    int start {}, end {};
    std::cin >> start >> end;

    while (start <= end) {
        std::cout << start << '\n';
        ++start;
    }
}
