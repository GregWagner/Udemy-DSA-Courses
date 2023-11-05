/*
 * Prinnt all positions of an element
 */
#include <iostream>
#include <vector>

void printAllPosition(const std::vector<int> &a, int key, size_t i = 0) {
    if (i > a.size()) {
        return;
    }
    if (a[i] == key) {
        std::cout << i << ' ';
    }
    printAllPosition(a, key, i + 1);

}

int main() {
    std::vector<int> a {5, 5, 6, 5, 6};
    printAllPosition(a, 5);
    std::cout << '\n';
    printAllPosition(a, 10);
    std::cout << '\n';
}
