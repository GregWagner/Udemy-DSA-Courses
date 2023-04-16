#include <iostream>

auto main() -> int {
    std::cout << "Enter a string: ";
    std::string s {};
    std::cin >> s;

    char previousCharacter { s[0] };
    for (const auto& currentCharacter : s) {
        if (currentCharacter != previousCharacter) {
            std::cout << ' ';
            previousCharacter = currentCharacter;
        }
        std::cout << currentCharacter;
    }
    std::cout << '\n';
}