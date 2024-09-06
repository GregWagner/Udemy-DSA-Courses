#include <iostream>

auto main() -> int {
    //                      U  R  D  L
    const int dirX[] { 99, -1, 0, 1, 0 };
    const int dirY[] { 99, 0, 1, 0, -1 };

    int posX {}, posY {};

    std::cout << "Enter the number of rows and columns: ";
    int rows {}, columns {};
    std::cin >> rows >> columns;

    std::cout << "Enter number of commands: ";
    int cmds {};
    std::cin >> cmds;

    std::cout << "Enter direction (1=up, 2=right, 3=down, 4=left)\n"
              << "then enter the number of steps: ";
    while (cmds--) {
        int direction {};
        std::cin >> direction;
        int steps {};
        std::cin >> steps;

        posX += dirX[direction] * steps;
        if (posX < 0) {
            posX += rows;
        } else if (posX > rows) {
            posX %= rows;
        }

        posY += dirY[direction] * steps;
        if (posY < 0) {
            posY += columns;
        } else if (posY > columns) {
            posY %= columns;
        }

        std::cout << '(' << posX << ", " << posY << ')' << '\n';
    }
}