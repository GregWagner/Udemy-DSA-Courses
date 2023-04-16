#include <iostream>

auto main() -> int {
    std::cout << "Enter a string: ";
    std::string s {};
    std::cin >> s;

    const std::string to { "YZIMNESTODUAPWXHQFBRJKCGVL" };
    const std::string to_digits { "!@#$%^&*()" };

    for (size_t i {}; i < s.size(); ++i) {
        char ch { s[i] };
        if ('a' <= ch && ch <= 'z') {
            std::cout << to[ch - 'a'];
        } else if ('0' <= ch && ch <= '9') {
            std::cout << to_digits[ch - '0'];
        } else {
            std::cout << ch;
        }
    }
    std::cout << '\n';
}