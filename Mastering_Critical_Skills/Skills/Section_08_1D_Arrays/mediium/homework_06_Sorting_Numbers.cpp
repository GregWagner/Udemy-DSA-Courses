#include <iostream>
#include <vector>

auto main() -> int {
    std::cout << "Enter n: ";
    int n {};
    std::cin >> n;

    std::vector<int> frequency(501, 0);
    for (int i {}; i < n; ++i) {
        int value {};
        std::cin >> value;
        ++frequency[value];
    }

    for (size_t i {}; i < frequency.size(); ++i) {
        if (frequency[i]) {
            while (frequency[i]--) {
                std::cout << i << ' ';
            }
        }
    }
    std::cout << '\n';
}