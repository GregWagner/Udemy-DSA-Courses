#include <iostream>
#include <vector>

template <typename T>
void print(const std::vector<T>& a) {
    for (const auto& ele : a) {
        std::cout << ele << ' ';
    }
    std::cout << '\n';
}

template <typename T>
void insertationSort(std::vector<T>& a) {
    if (a.size() <= 1) {
        return;
    }

    for (size_t i { 1 }; i < a.size(); ++i) {
        int current_value { a[i] };
        size_t previous = i;
        // shift to the right until correct spot found
        while ((previous > 0) && (a[previous - 1] > current_value)) {
            a[previous] = a[previous - 1];
            --previous;
        }
        a[previous] = current_value;
    }
}

int main() {
    std::vector<int> a { 6, 2, 7, 4, 8, 1, 3 };
    insertationSort(a);
    print(a);
}
