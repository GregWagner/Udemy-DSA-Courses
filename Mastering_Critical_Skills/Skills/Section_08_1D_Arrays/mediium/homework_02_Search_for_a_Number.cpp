#include <iostream>
#include <vector>

auto main() -> int {
    std::cout << "Enter n: ";
    int n {};
    std::cin >> n;

    std::vector<int> a(n);

    for (int i {}; i < n; ++i) {
        std::cin >> a[i];
    }

    std::cout << "Enter number of queries: ";
    int q {};
    std::cin >> q;

    while (q--) {
        int num {};
        std::cin >> num;
        int index { -1 };
        for (int i { n - 1 }; i >= 0; --i) {
            if (a[i] == num) {
                index = i;
                break;
            }
        }
        std::cout << index << '\n';
    }
}