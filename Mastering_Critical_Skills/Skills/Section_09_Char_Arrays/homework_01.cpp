/*
 * Is Prefix
 */
#include <iostream>
#include <string>

auto main() -> int {
    std::string s1;
    std::string s2;
    std::cout << "Enter 2 strings: ";
    std::cin >> s1 >> s2;

    bool is_prefix { true };
    if (s1.size() < s2.size()) {
        std::cout << "NO\n";
        return 0;
    }

    for (size_t i {}; i < s2.size(); ++i) {
        if (s1[i] != s2[i]) {
            is_prefix = false;
            break;
        }
    }
    std::cout << (is_prefix ? "YES" : "NO") << '\n';
}