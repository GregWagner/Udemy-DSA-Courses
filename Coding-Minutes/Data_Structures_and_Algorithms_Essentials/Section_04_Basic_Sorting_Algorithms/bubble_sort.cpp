#include <iostream>
#include <vector>

// optimaized bubble sort
template <typename T>
void bubbleSort(std::vector<T>& a) {
    bool swap_made { true };
    size_t ending_index { a.size() - 1 };
    while (swap_made) {
        swap_made = false;
        for (size_t i {}; i < ending_index; ++i) {
            if (a[i] > a[i + 1]) {
                std::swap(a[i], a[i + 1]);
                swap_made = true;
            }
        }
        --ending_index;
    }
}

template <typename T>
void bubbleSort1(std::vector<T>& a) {
    size_t n = a.size();
    for (size_t times { 1 }; times < n - 1; ++times) {
        for (size_t j {}; j < n - times; ++j) {
            if (a[j] > a[j + 1]) {
                std::swap(a[j], a[j + 1]);
            }
        }
    }
}

template <typename T>
void print(const std::vector<T>& a) {
    for (const auto& ele : a) {
        std::cout << ele << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> a { 6, 2, 7, 4, 8, 1, 3 };
    bubbleSort(a);
    print(a);
}
