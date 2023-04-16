#include <iostream>

auto main() -> int {
    std::cout << "Enter depth, rows and columns: ";
    int depth {}, rows {}, columns {};
    std::cin >> depth >> rows >> columns;

    std::cout << "Enter 1 to convert from 3D to 1D\n"
              << "Enter 2 to convert from 1D to 3D\n: ";
    int choice {};
    std::cin >> choice;

    switch (choice) {
    case 1:
        break;
    case 2:
        break;
    default:
        std::cout << "Invald choice\n";
    }
}