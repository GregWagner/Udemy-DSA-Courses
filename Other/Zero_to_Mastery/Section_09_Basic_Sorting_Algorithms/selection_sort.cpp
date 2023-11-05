/*
 * Selection Sort
 */
#include <iostream>
#include <vector>

void sort(std::vector<int> &a) {
    int n = a.size();
    for (int i {}; i <= n - 2; ++i) {
        int smallestIndex {i};
        for (int j {i + 1}; j <= n - 1; ++j) {
            if (a[smallestIndex] > a[j]) {
                smallestIndex = j;
            }
        }
        std::swap(a[i], a[smallestIndex]);
    }
}

int main() {
    std::vector<int> a {7, 5, 3, 6, 8};
    sort(a);
    for (auto e : a) {
        std::cout << e << ' ';
    }
    std::cout << '\n';
}
