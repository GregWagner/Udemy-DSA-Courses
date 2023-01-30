#include <iostream>

auto starts_with(const std::string& input, const std::string& pattern, int pos) -> bool {
    for (size_t i { 0 }; i < pattern.size(); ++i) {
        if (input[pos + i] != pattern[i]) {
            return false;
        }
    }
    return true;
}

auto replace_str(std::string input, std::string pattern, std::string to) -> std::string {
    std::string new_string {};
    for (size_t i {}; i < input.size(); ++i) {
        if (starts_with(input, pattern, i)) {
            new_string += to;
            i += pattern.size() - 1;
        } else {
            new_string += input[i];
        }
    }
    return new_string;
}

auto main() -> int {
    std::cout << std::boolalpha;
    std::cout << (replace_str("aabcabaaad", "aa", "x") == "xbcabxad") << '\n';
    std::cout << (replace_str("aabcabaaad", "aa", "aaaa") == "aaaabcabaaaaad") << '\n';
    std::cout << (replace_str("aabcabaaad", "aa", "") == "bcabad") << '\n';
}