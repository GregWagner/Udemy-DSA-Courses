/*
 * Bubble Sort
 */
#include <iostream>
#include <vector>

void sort(std::vector<int> &a) {
    // only need to go through n - 1 times
    for (size_t i {1}; i <= a.size() - 1; ++i) {
        bool swap {};
        for (size_t j {}; j <= a.size() - 2; ++j) {
            if (a[j] > a[j + 1]) {
                std::swap(a[j], a[j + 1]);
                swap = true;
            }
        }
        // done if no swappes where needed in the last iteration
        if (!swap) {
            break;
        }
    }
}

void print(const std::vector<int> &a) {
    for (auto const &e : a) {
        std::cout << e << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> a {7, 5, 3, 6, 8};
    sort(a);
    print(a);

    std::vector<int> b {1, 2, 3, 4, 5};
    sort(b);
    print(b);

    std::vector<int> c {5, 4, 3, 2, 1};
    sort(c);
    print(c);
}
