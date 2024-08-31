#include <iostream>
#include <vector>

auto main() -> int {
    std::cout << "Enter n: ";
    int n {};
    std::cin >> n;

    std::vector<bool> a(501, 0);
    std::vector<int> values(n);

    int count {};
    for (int i {}; i < n; ++i) {
        int value;
        std::cin >> value;
        if (!a[value]) {
            a[value] = true;
            values[count++] = value;
        }
    }

    for (int i {}; i < count; ++i) {
        std::cout << values[i] << ' ';
    }
    std::cout << '\n';
}