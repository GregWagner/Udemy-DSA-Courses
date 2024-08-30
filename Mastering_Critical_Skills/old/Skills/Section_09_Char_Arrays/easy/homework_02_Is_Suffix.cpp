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

    bool isSuffix { true };
    size_t inputIndex { input.size() - str.size() };

    for (size_t i {}; i < str.size(); ++i) {
        if (input[inputIndex++] != str[i]) {
            isSuffix = false;
        }
    }
    std::cout << (isSuffix ? "YES" : "NO") << '\n';
}