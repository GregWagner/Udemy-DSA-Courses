/*
 * Reverse a string (character array)
 */
#include <iostream>

size_t length(char input[]) {
    size_t count {};
    for (int i {}; input[i] != '\0'; ++i) {
        ++count;
    }
    return count;
}

void reverse(char s[]) {
    size_t startingIndex {0};
    size_t endingIndex {length(s) - 1};
    
    while (startingIndex < endingIndex) {
        std::swap(s[startingIndex], s[endingIndex]);
        ++startingIndex;
        --endingIndex;
    }
}

int main() {
    int const SIZE {100};
    char s[SIZE] {};
    std::cout << "Enter a string: ";
    std::cin.getline(s, SIZE);
    reverse(s);
    std::cout << "Reversed string: " << s << '\n';
}
