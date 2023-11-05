/*
 * Linear Search
 */
#include <iostream>
#include <vector>

int linearSearch(const std::vector<int> &a, int key) {
    for (size_t i {}; i < a.size(); ++i) {
        if (a[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    std::vector<int> a {2, 5, 7, 1, 3, 4};
    std::cout << linearSearch(a, 4) << '\n';
}
