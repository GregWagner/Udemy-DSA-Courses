#include <iostream>
#include <vector>

auto main() -> int {
    std::cout << "Enter n: ";
    int n {};
    std::cin >> n;

    std::vector<int> a(500 + 1, -1);

    int num {};
    for (int i{}; i < n; ++i) {
        std::cin >> num;
        // array will always have the last index for the number
        a[num] = i;
    }

    int q{};
    std::cout << "Enter number of queries: ";
    std::cin >> q;

    while (q--) {
        std::cin >> num;
        std::cout << a[num] << '\n';
    }
}

auto old_main() -> int {
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
    return 0;
}
