/*
 * Print character array
 */
#include <iostream>

void print(char *a) {
    if (a[0] == '\0') {
        std::cout << '\n';
        return;
    }
    std::cout << a[0];
    print(a + 1);
}

void reverse_print(char *a) {
    if (a[0] == '\0') {
        std::cout << '\n';
        return;
    }
    reverse_print(a + 1);
    std::cout << a[0];
}

int main() {
    char a[] {"abc"};
    print(a);
    reverse_print(a);
}
