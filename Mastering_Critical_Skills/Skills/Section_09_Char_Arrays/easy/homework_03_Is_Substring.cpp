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

    size_t index {};
    for (size_t i {}; i < input.size(); ++i) {
        index = 0;
        for (size_t j {}; j < str.size(); ++j) {
            if (input[index] != str[j]) {
                continue;
            }
            ++index;
        }
    }
    std::cout << (index == str.size() ? "YES" : "NO") << '\n';
}