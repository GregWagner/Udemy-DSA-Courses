#include <iostream>

auto main() -> int {
    std::cout << "Enter a string: ";
    std::string s {};
    std::cin >> s;

    char previousCharacter = s[0];
    size_t index {};
    while (index < s.size()) {
        int count {};
        while (s[index] == previousCharacter) {
            ++count;
            ++index;
        }
        std::cout << previousCharacter << count;
        previousCharacter = s[index];
        std::cout << (index == s.size() ? '\n' : '_');
    }
}