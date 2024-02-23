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

int main() {
    std::vector<int> a{ 10, 15, 12, 9, 6, 4, 3, 10, 8 };

    int key{};
    std::cout << "Enter the value to search for: ";
    std::cin >> key;

    auto index = linear_search(a, key);

    if (index == NOT_FOUND) {
        std::cout << key << " was NOT found\n";
    } else {
        std::cout << key << " is present at index " << index << '\n';
    }
}
