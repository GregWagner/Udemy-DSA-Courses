#include <iostream>

int main() {
    int a[] {2, 4, 6, 8, 10};

    a[0] = 12;
    a[1] = 12;
    a[2] = 25;

    std::cout << sizeof a << '\n';
    std::cout << a[1] << '\n';
    printf("%d\n", a[2]);

    for (const auto x: a) {
        std::cout << x << '\n';
    }
}
