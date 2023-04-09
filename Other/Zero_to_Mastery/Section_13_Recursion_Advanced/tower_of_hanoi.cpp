/*
 * Towers of Hanoi
 */
#include <iostream>

// count the number of steps
int toh(int n) {
    if (n == 0) {
        return 0;
    }
    // move n - 1  disks from a to b
    // move 1 disk from a to c
    // move n - 1 disks from b to c
    return toh(n - 1) + 1 + toh(n - 1);
}

void printToh(int n, char source, char dest, char helper) {
    if (n == 0) {
        return;
    }
    printToh(n - 1, source, helper, dest);
    std::cout << "Moving disk " << n << " from " << source
        << " to " << dest << '\n';
    printToh(n - 1, helper, dest, source);

}

int main() {
    std::cout << toh(5) << '\n';
    printToh(5, 'A', 'B', 'C');
}
