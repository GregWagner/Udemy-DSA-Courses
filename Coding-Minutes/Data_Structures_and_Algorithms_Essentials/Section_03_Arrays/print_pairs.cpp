// Print all the pairs of an array Video 14

#include <iostream>
#include <vector>

template <typename T>
void printAllPairs(const std::vector<T>& a) {
    auto size = a.size();
    for (size_t i{}; i < size - 1; ++i) {
        for (size_t j { i + 1 }; j < size; ++j) {
            std::cout << a[i] << ", " << a[j] << '\n';
        }
        std::cout << '\n';
    }
}

int main() {
    std::vector<int> a { 10, 20, 30, 40, 50, 60 };

    printAllPairs(a);
}
