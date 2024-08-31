#include <iostream>

auto reverse_str(const std::string& str) -> std::string {
    std::string answer {};
    for (const auto& c : str) {
        answer = c + answer;
    }
    return answer;
}

auto main() -> int {
    std::cout << "Enter a string: ";
    std::string s {};
    std::cin >> s;

    std::cout << reverse_str(s) << '\n';
}