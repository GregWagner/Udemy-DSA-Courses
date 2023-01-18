#include <iostream>

auto main() -> int {
    int count {};
    for (int a { 1 }; a <= 200; ++a) {
        for (int b { 1 }; b <= 200; ++b) {
            for (int c { 1 }; c <= 200; ++c) {
                int temp { a + b - c };
                count += (temp >= 1 && temp <= 200);
            }
        }
    }
    std::cout << count << '\n';
}