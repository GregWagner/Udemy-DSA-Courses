/*
 * Replace character in char array
 */
#include <iostream>

void replaceChar(char a[]) {
    if (a[0] == '\0') {
        return;
    }
    if (a[0] == 'a') {
        a[0] = 'x';
    }
    replaceChar(a + 1);
}

int main() {
    char input[] = "greg was here";
    replaceChar(input);
    std::cout << input << '\n';
}
