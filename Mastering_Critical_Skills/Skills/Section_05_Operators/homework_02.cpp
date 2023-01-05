#include <iostream>

int main() {
    int a = 1, b = 1, c;

    std::cout << (c = a + b, a = b, b = c,
        c = a + b, a = b, b = c,
        c = a + b, a = b, b = c,
        c = a + b, a = b, b = c)
              << std::endl;
}

/*
    c = 1 + 1 = 2,
    a = 1, b = 2, c = 2

    c = 1 + 2 = 3
    a = 2, b = 3, c = 3

    c = 2 + 3 = 5,
    a = 3, b = 5,

    c = 3 + 5 = 8, a = 5, b = 8)
    cout << 8 << '\n';


*/