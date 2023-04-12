#include <iostream>
#include <vector>

auto main() -> int {
    std::cout << "Enter n: ";
    int n {};
    std::cin >> n;

    std::vector<int> frequency(10, 0);
    while (n--) {
        int value {};
        std::cin >> value;
        if (value == 0) {
            ++frequency[0];
        }
        
        while (value > 0) {
            ++frequency[value % 10];
            value /= 10;
        }
    }

    for (size_t i {}; i < frequency.size(); ++i) {
        std::cout << i << "  " << frequency[i] << '\n';
    }
}