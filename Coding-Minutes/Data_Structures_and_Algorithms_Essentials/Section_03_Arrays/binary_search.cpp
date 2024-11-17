// binary_search.cpp Video 12

#include <algorithm>
#include <iostream>
#include <vector>

const int NOT_FOUND{ -1 };

template <typename T>
T binary_search(const std::vector<T>& a, T key) {
    size_t start{};
    size_t end{ a.size() -1 };
    while (start <= end) {
        // avoid overflow
        size_t middle{start + (end - start) / 2};
        if (a[middle] == key) {
            return static_cast<T>(middle);
        }
        if (a[middle] < key) {
            start = middle + 1;
        } else {
            end = middle - 1;
        }
    }
    return NOT_FOUND;
}

int main() {
    std::vector<int> a{ 10, 20, 30, 45, 60, 70, 89 };
    std::sort(std::begin(a), std::end(a));

    int key{45};
    auto index = binary_search(a, key);
    std::cout << key << (index == NOT_FOUND
        ? " was NOT found\n"
        : " is present at index " + std::to_string(index) + '\n');

    key = 123;
    index = binary_search(a, key);
    std::cout << key << (index == NOT_FOUND
        ? " was NOT found\n"
        : " is present at index " + std::to_string(index) + '\n');
}
