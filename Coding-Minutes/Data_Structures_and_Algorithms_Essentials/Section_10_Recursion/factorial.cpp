#include <iostream>

int64_t fact(int64_t n) {
    if (n <= 1) {
        return 1;
    }
    return n * fact(n - 1);
}

int main() {
    std::cout << fact(5) << '\n';
}
