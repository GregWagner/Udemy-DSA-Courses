#include <iostream>

int main() {
    int n {}, m {};
    std::cout << "Enter n and m: ";
    std::cin >> n >> m;

    int k {};
    std::cout << "Enter number of commands: ";
    std::cin >> k;

    int x {}, y {};
    for (int i {}; i < k; ++i) {
        int direction {}, steps {};
        std::cout << "Enter command (dir, steps): ";
        std::cin >> direction >> steps;

        switch (direction) {
        case 1: // up
            if (x - steps < 0) {
                x = n + x - steps;
            } else {
                x -= steps;
            }
            break;

        case 2: // right
            if (y + steps > m) {
                std::cout << "Circulate\n";
                y = (y + steps) - m;
            } else {
                y += steps;
            }
            break;

        case 3: // down
            if (x + steps > n) {
                std::cout << "Circulate\n";
                x = (x + steps) - n;
            } else {
                x += steps;
            }
            break;

        case 4: // left
            if (y - steps < 0) {
                std::cout << "Circulate\n";
                y = m + y - steps;
            } else {
                y -= steps;
            }
            break;
        }
        std::cout << "(" << x << ", " << y << ")\n";
    }
}