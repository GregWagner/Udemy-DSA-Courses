#include <iostream>

auto print(const char a[10][10], int d) {
    for (int i { 1 }; i <= d; ++i) {
        for (int j { 1 }; j <= d; ++j) {
            std::cout << a[i][j];
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

auto gameWon(const char a[10][10], int d) -> bool {
    bool gameWon { true };
    for (int r {}; r < d; ++r) {
        for (int c { 1 }; c < d; ++c) {
            if (a[r][c - 1] != a[r][c]) {
                gameWon = false;
                break;
            }
        }
    }
    if (gameWon) {
        return true;
    }
    return false;
}

auto main() -> int {
    char a[10][10];

    std::cout << "Enter the dimension: ";
    int dimension {};
    std::cin >> dimension;
    for (int i { 1 }; i <= dimension; ++i) {
        for (int j { 1 }; j <= dimension; ++j) {
            a[i][j] = '.';
        }
    }

    bool gameOver {};

    bool playerXTurn { true };
    int playsLeft { dimension * dimension };

    print(a, dimension);
    while (!gameOver) {
        bool isValid {};
        while (!isValid) {
            std::cout << "Player " << (playerXTurn ? 'X' : 'Y')
                      << " turn. Enter empty location (r, c): ";
            int r {}, c {};
            std::cin >> r >> c;
            if (r > 0 && r <= dimension && c > 0 && c <= dimension) {
                if (a[r][c] == '.') {
                    a[r][c] = playerXTurn ? 'X' : 'Y';
                    isValid = true;
                    break;
                }
            }
            std::cout << "That was not a valid move. Try again.\n";
        }
        print(a, dimension);

        if (gameWon(a, dimension)) {
            break;
        }

        if (--playsLeft == 0) {
            std::cout << "Game has tied.\n";
            gameOver = true;
        }

        playerXTurn = !playerXTurn;
    }
}