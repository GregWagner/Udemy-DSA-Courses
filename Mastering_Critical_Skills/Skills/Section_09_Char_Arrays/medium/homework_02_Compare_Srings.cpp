#include <iostream>

auto main() -> int {
    std::cout << "Enter 2 strings: ";
    std::string s {};
    std::string t {};
    std::cin >> s >> t;

    size_t index {};
    bool isEqual { true };
    while (index < s.size() && index < t.size()) {
        if (s[index] != t[index]) {
            isEqual = false;
        }
        ++index;
    }
    std::cout << ((isEqual && index == s.size() && index == t.size())
            ? "YES"
            : "NO")
              << '\n';
}