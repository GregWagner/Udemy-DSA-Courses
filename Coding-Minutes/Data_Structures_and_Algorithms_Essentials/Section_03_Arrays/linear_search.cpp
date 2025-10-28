// linear_search.cpp Video 10

#include <iostream>
#include <vector>

const int NOT_FOUND{ -1 };

template <typename T>
int linear_search(const std::vector<T>& arr, T key) {
    for (size_t index{}; index < arr.size(); ++index) {
        if (arr[index] == key) {
            return static_cast<int>(index);
        }
    }
    return NOT_FOUND;
}

template <typename T>
int linear_search_using_stl(const std::vector<T>& arr, const T& key) {
    auto begin = arr.cbegin();
    auto end = arr.cend();
    auto iter = std::find(begin, end, key);
    return (iter != end) ? static_cast<int>(std::distance(begin, iter))
        : NOT_FOUND;
}

int main() {
    std::vector<int> arr{ 10, 15, 12, 9, 6, 4, 3, 10, 8 };

    int key{4};
    auto index = linear_search(arr, key);

    std::cout << key << (index == NOT_FOUND
        ? " was NOT found\n"
        : " is present at index " + std::to_string(index) + '\n');

    key = 123;
    index = linear_search(arr, key);
    std::cout << key << (index == NOT_FOUND
        ? " was NOT found\n"
        : " is present at index " + std::to_string(index) + '\n');
}
