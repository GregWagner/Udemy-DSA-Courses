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

    bool isPrefix { true };
    for (size_t i {}; i < str.size(); ++i) {
        if (input[i] != str[i]) {
            isPrefix = false;
            break;
        }
    }
    std::cout << (isPrefix ? "YES" : "NO") << '\n';
}