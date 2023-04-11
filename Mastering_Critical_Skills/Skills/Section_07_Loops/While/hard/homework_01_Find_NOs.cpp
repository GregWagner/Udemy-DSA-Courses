#include <iostream>

auto main() -> int {
    std::cout << "Enter the number of strings: ";
    int n {};
    std::cin >> n;

    while (n--) {
        std::string s {};
        std::cin >> s;

        if (s.size() == 2) {
            if ((std::tolower(s[0]) == 'n' && std::tolower(s[1]) == 'o') || (std::tolower(s[0]) == 'o' && std::tolower(s[1]) == 'n')) {
                std::cout << s << ' ';
            }
        }
    }
    std::cout << '\n';
}