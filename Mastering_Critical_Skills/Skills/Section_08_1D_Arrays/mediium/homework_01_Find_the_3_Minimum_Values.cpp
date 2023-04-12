#include <iostream>

auto main() -> int {
    std::cout << "Enter n: ";
    int n {};
    std::cin >> n;

    int min_01 { 9999 };
    int min_02 { 9999 };
    int min_03 { 9999 };

    int value;
    for (int i {}; i < n; ++i) {
        std::cin >> value;
        if (value < min_01) {
            min_03 = min_02;
            min_02 = min_01;
            min_01 = value;
        } else if (value < min_02) {
            min_03 = min_02;
            min_02 = value;
        } else if (value < min_03) {
            min_03 = value;
        }
    }

    std::cout << min_01 << ' ' << min_02 << ' ' << min_03 << '\n';
}