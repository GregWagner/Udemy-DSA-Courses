/*
 * First index of element
 */
#include <iostream>
#include <vector>

int firstIndex(std::vector<int> const &a, int element, size_t index=0) {
    if (index == a.size()) {
        return -1;
    }
    if (a[index] == element) {
        return index;
    }
    return firstIndex(a, element, index + 1);
}

int main() {
    std::vector<int> a {5, 5, 6, 5, 6};
    std::cout << firstIndex(a, 5) << '\n';
    std::cout << firstIndex(a, 6) << '\n';
    std::cout << firstIndex(a, 9) << '\n';
}
