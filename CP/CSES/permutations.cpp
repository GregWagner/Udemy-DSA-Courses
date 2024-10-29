#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n{};
    std::cin >> n;

    if (n <= 1) {
        std::cout << "NO SOLUTION\n";
        return 0;
    }

    for (size_t i{ 1 }; i < n + 1; ++i) {
        std::cout << i << ' ';
    }
}
