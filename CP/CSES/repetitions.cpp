#include <iostream>

int main() {
    std::string s;
    std::cin >> s;

    int maxCount{1};
    char currentChar{ s[0] };
    int currentCount{ 1 };
    size_t i{ 1 };
    while (i < s.size()) {
        while (s[i] == currentChar) {
            ++currentCount;
            ++i;
            if (i == s.size()) break;
        }
        maxCount = std::max(maxCount, currentCount);
        currentChar = s[i];
        currentCount = 1;
        ++i;
    }
    std::cout << maxCount << '\n';
}
