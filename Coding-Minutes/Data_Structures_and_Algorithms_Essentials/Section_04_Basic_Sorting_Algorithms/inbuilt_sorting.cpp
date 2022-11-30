#include <algorithm>
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
bool compare(T a, T b) {
    return a > b;
}

int main() {
    std::vector<int> a { 6, 2, 7, 4, 8, 1, 3 };
    // std::sort(begin(a), end(a), compare);
    // std::sort(begin(a), end(a), std::greater<int>());
    std::sort(begin(a), end(a), [](int a, int b) { return a > b; });
    print(a);
}
