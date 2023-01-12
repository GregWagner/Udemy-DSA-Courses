#include <iostream>

auto main() -> int {
    int x {};
    std::cout << "Enter x: ";
    std::cin >> x;

    int e3;
    int s3;
    int e2;
    int s2;
    int e1;
    int s1;
    std::cout << "Enter 3 starting/ending internals: ";
    std::cin >> s1 >> e1 >> s2 >> e2 >> s3 >> e3;

    int interval_count {};
    if (x >= s1 && x <= e1) {
        ++interval_count;
    }
    if (x >= s2 && x <= e2) {
        ++interval_count;
    }
    if (x >= s3 && x <= e3) {
        ++interval_count;
    }
    std::cout << x << " belongs to " << interval_count << " intervals\n";
}