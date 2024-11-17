// linear_search.cpp Video 10

#include <iostream>
#include <vector>

const int NOT_FOUND{ -1 };

template <typename T>
int linear_search(const std::vector<T>& a, T key) {
    for (size_t index{}; index < a.size(); ++index) {
        if (a[index] == key) {
            return static_cast<int>(index);
        }
    }
    return NOT_FOUND;
}

template <typename T>
int linear_search_using_stl(const std::vector<T>& a, const T& key) {
    auto begin = a.cbegin();
    auto end = a.cend();
    auto it = std::find(begin, end, key);
    return (it != end) ? static_cast<int>(std::distance(begin, it)) : NOT_FOUND;
}

int main() {
    std::vector<int> a{ 10, 15, 12, 9, 6, 4, 3, 10, 8 };

    int key{4};
    auto index = linear_search(a, key);

    std::cout << key << (index == NOT_FOUND
        ? " was NOT found\n"
        : " is present at index " + std::to_string(index) + '\n');

    key = 123;
    index = linear_search(a, key);
    std::cout << key << (index == NOT_FOUND
        ? " was NOT found\n"
        : " is present at index " + std::to_string(index) + '\n');
}
