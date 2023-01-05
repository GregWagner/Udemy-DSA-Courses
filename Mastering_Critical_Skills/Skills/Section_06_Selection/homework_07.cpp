#include <iostream>

int main() {
    int x {};
    std::cout << "Enter x: ";
    std::cin >> x;

    int s1, e1, s2, e2, s3, e3;
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
    std::cout << x << " belons to " << interval_count << " intervals\n";
}