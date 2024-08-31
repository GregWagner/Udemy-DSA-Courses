#include <iostream>

auto main() -> int {
    /*
        int count {};
        for (int a { 1 }; a <= 200; ++a) {
            for (int b { 1 }; b <= 200; ++b) {
                for (int c { 1 }; c <= 200; ++c) {
                    for (int d { 1 }; d <= 200; ++d) {
                        if (a + b == c + d) {
                            ++count;
                        }
                    }
                }
            }
        }
        std::cout << count << '\n';
    */
    int count {};
    for (int a { 1 }; a <= 200; ++a) {
        for (int b { 1 }; b <= 200; ++b) {
            for (int c { 1 }; c <= 200; ++c) {
                int d { a + b - c };
                if (d >= 1 && d <= 200) {
                    ++count;
                }
            }
        }
    }
    std::cout << count << '\n';
}