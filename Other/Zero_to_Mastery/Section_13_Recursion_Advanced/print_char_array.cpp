/*
 * Print character array
 */
#include <iostream>

void print(char *a) {
    if (a[0] == '\0') {
        return;
    }
    std::cout << a[0];
    print(a + 1);
}

void reverse_print(char *a) {
    if (a[0] == '\0') {
        return;
    }
    reverse_print(a + 1);
    std::cout << a[0];
}

int main() {
    char a[] {"abc"};
    print(a);
    std::cout << '\n';
    reverse_print(a);
    std::cout << '\n';
}
