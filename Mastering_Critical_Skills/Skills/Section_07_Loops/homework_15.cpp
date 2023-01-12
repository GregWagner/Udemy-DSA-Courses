#include <iostream>

auto main() -> int {
    int count {};
    for (int x { 50 }; x <= 300; ++x) {
        int y_start { 70 };
        if (y_start < x + 1) {
            y_start = x + 1;
        }
        for (int y { y_start }; y <= 400; ++y) {
            count += (x + y) % 7 == 0;
        }
    }
    std::cout << count << '\n';
}