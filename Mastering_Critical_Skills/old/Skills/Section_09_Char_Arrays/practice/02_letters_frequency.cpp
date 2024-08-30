#include <iostream>
#include <vector>

auto main() -> int {
    std::cout << "Enter a string: ";
    std::string s {};
    std::cin >> s;

    std::vector<int> frequency(27, 0);

    for (const auto& ch : s) {
        if ('a' <= ch && ch <= 'z') {
            ++frequency[ch];
        }
    }

    for (char ch { 'a' }; ch <= 'z'; ++ch) {
        if (frequency[ch]) {
            std::cout << ch << ' ' << frequency[ch] << '\n';
        }
    }
}