// Reverse an array Video 13

#include <algorithm>
#include <iostream>
#include <vector>

// Reverse array using 2 pointers
// O(1) space, O(n) time
template <typename T>
void reverse_array(std::vector<T>& a) {
    size_t left {};
    size_t right { a.size() - 1 };
    while (left < right) {
        std::swap(a[left++], a[right--]);
    }
}

template <typename T>
void reverse_array_using_stl(std::vector<T>& a) {
    std::reverse(a.begin(), a.end());
}

template <typename T>
void print_array(const std::vector<T>& a) {
    for (size_t i{}; i < a.size(); ++i) {
        std::cout << a[i] << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> a { 10, 20, 30, 45, 60, 80, 90 };

    print_array(a);
    reverse_array(a);
    print_array(a);
}
