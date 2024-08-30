#include <iostream>

auto main() -> int {
    std::cout << "Enter 2 strings: ";
    std::string input {};
    std::string str {};
    std::cin >> input >> str;

    if (input.size() < str.size()) {
        std::cout << "NO\n";
        return 0;
    }

    size_t strIndex {};
    for (size_t i {}; i < input.size(); ++i) {
        if (input[i] == str[strIndex]) {
            ++strIndex;
        }
    }
    std::cout << (strIndex == str.size() ? "YES" : "NO") << '\n';
}