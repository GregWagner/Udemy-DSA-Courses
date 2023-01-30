#include <iostream>

bool isPrime(int n) {
    for (int i { 2 }; i < n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int a[101][101];
    int n {}, m {};
    std::cout << "Enter n and m: ";
    std::cin >> n >> m;

    for (int r {}; r < n; ++r) {
        for (int c {}; c < m; ++c) {
            std::cin >> a[r][c];
        }
    }

    int q {};
    std::cout << "Enter number of queries: ";
    std::cin >> q;

    for (int query {}; query < q; ++query) {
        int i {}, j {}, r {}, c {};
        std::cout << "Enter i, j, r, c: ";
        std::cin >> i >> j >> r >> c;

        int prime_count {};
        for (int row { i }; row <= r; ++row) {
            for (int col { j }; col < c; ++col) {
                prime_count += isPrime(a[row][col]);
            }
        }
        std::cout << "There were " << prime_count << " prime numbers\n";
    }
}