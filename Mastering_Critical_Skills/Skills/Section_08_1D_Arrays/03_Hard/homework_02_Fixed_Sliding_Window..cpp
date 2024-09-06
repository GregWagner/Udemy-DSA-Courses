#include <iostream>
#include <vector>

auto main() -> int {
    std::cout << "Enter k and n: ";
    int k {};
    int n {};
    std::cin >> k >> n;

    std::vector<int> a(n);
    std::cout << "Enter " << n << " integers: ";
    for (int i {}; i < n; ++i) {
        std::cin >> a[i];
    }

    // assumme the first k values hold the largest sum
    int bestSum {};
    for (int i {}; i < k; ++i) {
        bestSum += a[i];
    }
    int bestStart {};
    int bestEnd { k - 1 };

    int start {};
    int end { k - 1 };
    int currentSum { bestSum };
    while (end + 1 < n) {
        currentSum -= a[start++];
        currentSum += a[++end];
        if (bestSum < currentSum) {
            bestSum = currentSum;
            bestStart = start;
            bestEnd = end;
        }
    }
    std::cout << bestStart << ' ' << bestEnd << ' ' << bestSum << '\n';
}