#include <bits/stdc++.h>

// 1 3 5 7 9
// _ 1 3 5 7
// 9 1 3 5 7
// _ 9 1 3 5
// 7 9 1 3 5

std::vector<int> kRotate(std::vector<int> a, int k) {
   for (int i{}; i < k; i++) {
        int temp = a[a.size() - 1];
        for (size_t j{ a.size() - 1 }; j > 0; --j) {
            a[j] = a[j - 1];
        }
        a[0] = temp;
   }
   return a;
}

int main() {
    std::vector<int> a{1, 3, 5 , 7, 9};
    auto x = kRotate(a, 2);
    std::cout << "main\n";
    for (const auto& e : x) {
        std::cout << e << ' ';
    }
    std::cout << '\n';
}
