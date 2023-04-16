#include <iostream>

auto starts_with(const std::string& input, const std::string& pattern, int pos) -> bool {
    if (pos + pattern.size() > input.size()) {
        return false;
    }
    for (size_t i {}; i < pattern.size(); ++i) {
        if (input[i + pos] != pattern[i]) {
            return false;
        }
    }
    return true;
}

auto replace_str(const std::string& input, const std::string& pattern, const std::string_view& to) -> std::string {
    std::string answer {};
    size_t index {};
    while (index < input.size()) {
        if (starts_with(input, pattern, index)) {
            answer += to;
            index += pattern.size();
        } else {
            answer += input[index];
            ++index;
        }
    }
    return answer;
}

auto main() -> int {
    std::cout << std::boolalpha;

    std::cout << (replace_str("aabcabaaad", "aa", "x") == "xbcabxad") << '\n';
    std::cout << (replace_str("aabcabaaad", "aa", "aaaa") == "aaaabcabaaaaad") << '\n';
    std::cout << (replace_str("aabcabaaad", "aa", "") == "bcabad") << '\n';
}