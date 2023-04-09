/*
 * Geometric Sum
 * 1 + 1/2 + 1/2^2 + 1/2^3 ....1/2^k-1 + 1/2^k
 */
#include <iostream>
#include <cmath>

double geometricSum(int k) {
    if (k == 0) {
        return 1;
    }
    return (1.0 / std::pow(2, k)) + geometricSum(k - 1);
}

int main() {
    std::cout << geometricSum(3) << '\n';
}
