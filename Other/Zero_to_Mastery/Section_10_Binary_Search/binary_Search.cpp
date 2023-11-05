/*
 * Binary Search
 */
#include <iostream>
#include <vector>

int binary_search(std::vector<int> a, int key) {
    int low {};
    int high = a.size();
    while (low <= high) {
        int middle = (low + high) / 2;
        if (a[middle] == key) {
            return middle;
        }
        if (a[middle] > key) {
            high = middle - 1;
        } else {
            low = middle + 1;
        }
    }
    return -1;
}

int main() {
    std::vector<int> a {1, 3, 5, 7, 9};
    std::cout << binary_search(a, 9) << '\n';
}
