/*
 * Nim Game
 * You are playing the following Nim Game:
 * - Initially, there is a heap of stones on the table
 * - You alternate taking turns and you go first
 * - Seach person can remove 1 to 3 stones
 * - The one who removes the last stone is the winner
 *
 * Given n, the nuber of stones in the heap, return true if
 * you can win the game.
 */
#include <iostream>

bool canWinNim(int n) {
    return n % 4 != 0;
}

int main() {
    std::cout << std::boolalpha;
    std::cout << (canWinNim(1) == true) << '\n';
    std::cout << (canWinNim(2) == true) << '\n';
    std::cout << (canWinNim(3) == true) << '\n';
    std::cout << (canWinNim(4) == false) << '\n';
    std::cout << (canWinNim(5) == true) << '\n';
}