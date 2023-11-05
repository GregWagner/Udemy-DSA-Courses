/*
 * Last index of element
 */
#include <vector>
#include <iostream>

int lastElement(std::vector<int> a, int n, int key) {
    if (n < 0) {
        return -1;
    }
    if (a[n] == key) {
        return n;
    }
    return lastElement(a, n - 1, key);
}

int main() {
    std::cout << std::boolalpha;
    std::vector<int> a {5, 5, 6, 5, 6};
    std::cout << (lastElement(a, 5, 5) == 3) << '\n';
    std::cout << (lastElement(a, 5, 6) == 4) << '\n';
    std::cout << (lastElement(a, 5, 10) == -1) << '\n';
}
