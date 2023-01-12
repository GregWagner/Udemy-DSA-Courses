#include <iostream>
#include <string>

auto is_substring(std::string& s1, size_t s1_index, std::string& s2, size_t s2_index = 0) -> bool {
    for (size_t i { s2_index }; i < s2.size(); ++i) {
        if (s1[s1_index++] != s2[s2_index++]) {
            return false;
        }
    }
    return true;
}

auto main() -> int {
    std::string s1;
    std::string s2;
    std::cout << "Enter 2 strings: ";
    std::cin >> s1 >> s2;

    if (s1.size() < s2.size()) {
        std::cout << "NO\n";
        return 0;
    }

    size_t s1_index {};
    while (s1_index < s1.size()) {
        if (is_substring(s1, s1_index, s2, 0)) {
            std::cout << "YES\n";
            return 0;
        }
        ++s1_index;
    }
    std::cout << "NO\n";
}