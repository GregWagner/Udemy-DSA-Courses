#include <iostream>

auto main() -> int {
    int n {};
    std::cout << "Enter the number of strings: ";
    std::cin >> n;

    while (n--) {
        std::string s;
        std::cin >> s;
        if (s.size() == 2) {
            // could have just done 8 string compares
            if ((s[0] == 'n' || s[0] == 'N') && (s[1] == 'o' || s[1] == 'O')) {
                std::cout << s << ' ';
            } else if ((s[1] == 'n' || s[1] == 'N') && (s[0] == 'o' || s[0] == 'O')) {
                std::cout << s << ' ';
            }
        }
    }
    std::cout << '\n';
}