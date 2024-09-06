#include <iostream>

auto main() -> int {
    std::cout << "Enter 2 strings: ";
    std::string s {};
    std::string t {};
    std::cin >> s >> t;

    std::string concString{};

    size_t index {};
    while (index < s.size() && index < t.size()) {
        concString += s[index];
        concString += t[index];
        ++index;
    }

    while (index < s.size()) {
        concString += s[index++];
    }
    while (index < t.size()) {
        concString += t[index++];
    }
    std::cout << concString << '\n';
}
