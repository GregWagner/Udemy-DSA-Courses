#include <iostream>

auto main() -> int {
    std::cout << "Enter a number: ";
    std::string s {};
    std::cin >> s;

    std::cout << std::boolalpha;
    bool carry {};
    for (int i { 1 }; i <= 4; ++i) {
        int index = s.size() - i;
        int ch = carry ? s[index] - '0' + 6 : s[index] - '0' + 5;
        carry = ch >= 10;
        s[index] = (ch % 10) + '0';
        std::cout << ch << ' ' << carry << ' ' << s[index] << '\n';
    }
    if (carry) {
        // need to handle this case!!!
    }
    std::cout << s << '\n';
}