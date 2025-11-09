/*
 * Tower of Hanio - Video 19 and 20
 */
#include <iostream>

void towerOfHanio(int n, char from, char helper, char to) {
    // base case
    if (n == 0) {
        return;
    }

    // move n - 1 smallest disks to helper
    towerOfHanio(n - 1, from, to, helper);
    // move largest disk to final place
    std::cout << "Move " << from << " to " << to << '\n';
    // move n - 1 smallest disks to final
    towerOfHanio(n - 1, helper, from, to);
}

int main() {
    towerOfHanio(3, 'A', 'B', 'C');
}
