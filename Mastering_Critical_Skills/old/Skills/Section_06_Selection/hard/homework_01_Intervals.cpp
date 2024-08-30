#include <iostream>

auto main() -> int {
    std::cout << "Enter x than 6 numbers: ";
    int x {}, start1 {}, end1 {}, start2 {}, end2 {},
        start3 {}, end3 {};
    std::cin >> x >> start1 >> end1 >> start2 >> end2
        >> start3 >> end3;

    int numberOfIntervals {};

    if (start1 <= x && x <= end1) {
        ++numberOfIntervals;
    }
    if (start2 <= x && x <= end2) {
        ++numberOfIntervals;
    }
    if (start3 <= x && x <= end3) {
        ++numberOfIntervals;
    }

    std::cout << numberOfIntervals << '\n';
}