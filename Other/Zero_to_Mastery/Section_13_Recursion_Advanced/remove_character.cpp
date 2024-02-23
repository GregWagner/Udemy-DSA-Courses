/*
 * Remoave character
 */
#include <iostream>

void removeChar(char a[], char ch) {
    if (a[0] == '\0') {
        return;
    }
    if (a[0] == ch) {
        for (size_t i {}; a[i] != '\0'; ++i) {
            a[i] = a[i + 1];
        }
        removeChar(a, ch);
    }
    removeChar(a + 1, ch);
}

int main() {
    char input[] {"greg was here"};
    removeChar(input, 'g');
    std::cout << input << '\n';
}
