#include <iostream>
#include <vector>

auto main() -> int {
    int n {};
    std::cout << "Enter n: ";
    std::cin >> n;

    std::vector<int> a(2, -1);
    for (int i {}; i < n; ++i) {
        int value {};
        std::cin >> value;
        if (a[0] < value) {
            a[1] = a[0];
            a[0] = value;
        } else {
            a[1] = std::max(a[1], value);
        }
    }
    std::cout << a[0] + a[1] << '\n';
}