#include <iostream>

void tower(int n, int from, int use, int to) {
    if (n > 0) {
        tower(n - 1, from, to, use);
        std::cout << "Move Disk from " << from << " to " << to << '\n';
        tower(n - 1, use, from, to);
    }
}

int main() {
    tower(3, 1, 2, 3);
}
