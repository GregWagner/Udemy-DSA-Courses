#include <iostream>

auto main() -> int {
    std::cout << "Enter 4 numbers representing 2 intervals: ";
    int start1 {}, end1 {}, start2 {}, end2 {};
    std::cin >> start1 >> end1 >> start2 >> end2;

    int start { std::max(start1, start2) };
    int end { std::min(end1, end2) };

    if (start > end) {
        std::cout << "-1\n";
    } else {
        std::cout << start << ' ' << end << '\n';
    }
}