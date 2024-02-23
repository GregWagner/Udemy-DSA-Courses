/*
 * Length of character array
 */
#include <iostream>

int length(char a[]) {
    if (a[0] == '\0') {
        return 0;
    }
    return 1 + length(a + 1);
}

int main() {
    char input[] = "Greg was here";
    std::cout << length(input) << '\n';
}
