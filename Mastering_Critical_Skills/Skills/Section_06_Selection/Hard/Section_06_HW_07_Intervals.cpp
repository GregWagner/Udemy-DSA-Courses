#include <iostream>

auto main() -> int {
    int x {};
    std::cout << "Enter x: ";
    std::cin >> x;

    int e1 {}, s1 {};
    int e2 {}, s2 {};
    int e3 {}, s3 {};
    std::cout << "Enter 3 starting/ending internals: ";
    std::cin >> s1 >> e1 >> s2 >> e2 >> s3 >> e3;

    int interval_count {};
    interval_count += (x >= s1 && x <= e1);
    interval_count += (x >= s2 && x <= e2);
    interval_count += (x >= s3 && x <= e3);

    std::cout << x << " belongs to " << interval_count << " intervals\n";
}