#include <iostream>

int main() {
    int depth {}, rows {}, cols {};
    std::cout << "Enter depth, rows, columns: ";
    std::cin >> depth >> rows >> cols;

    int direction {};
    std::cout << "Enter 1 to convert 3D to 1D or 2 to covert 1D to 3D: ";
    std::cin >> direction;

    if (direction == 1) {
        // Convert 3D to 1d
    } else if (direction == 2) {
        // convert 1D to 3D
    }
}