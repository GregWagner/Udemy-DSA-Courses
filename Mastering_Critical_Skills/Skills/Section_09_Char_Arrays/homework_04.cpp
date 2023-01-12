#include <iostream>
#include <string>

auto main() -> int {
    std::string s1;
    std::string s2;
    std::cout << "Enter 2 strings: ";
    std::cin >> s1 >> s2;

    for (size_t index {}; index < s1.size(); ++index) {
        size_t s1_index { index };
        size_t s2_index {};
        while (s1_index < s1.size()) {
            if (s1[s1_index] == s2[s2_index]) {
                // are we done (at last character)
                if (s2_index == s2.size() - 1) {
                    std::cout << "YES\n";
                    return 0;
                }
                ++s2_index;
            }
            ++s1_index;
        }
    }
    std::cout << "NO\n";
}