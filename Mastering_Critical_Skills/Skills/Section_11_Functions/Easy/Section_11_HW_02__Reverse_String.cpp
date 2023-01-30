#include <iostream>

auto reverse_string(const std::string& s) -> std::string {
    std::string reversed { s };
    size_t start {};
    size_t end { s.size() - 1 };
    while (start < end) {
        std::swap(reversed[start], reversed[end]);
        ++start;
        --end;
    }
    return reversed;
}

auto main() -> int {
    std::cout << reverse_string("abcde") << '\n';
}