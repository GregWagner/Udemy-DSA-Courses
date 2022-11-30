/*
 * Given an MxN grid, find the number of
 * ways to reach the bottom right corner
 * starting from the top left. At each cell
 * you can move right or down
 *
 * At each cell, there are 2 sub-problems.
 * Going right and going down.
 * f(x, y) = f(x + 1, y) + f(x, y + 1)
 *
 * Note: There is a math trick to this. Calculate
 * the number of permutations of m-1 + n-1 moves since
 * you have to make this number of moves - it's just
 * the order that changes.
 *    (m + n - 2)!
 * -----------------
 *  (m - 1)!(n - 1)!
 */
#include <iostream>

int gridWays(int current_row, int current_col, int target_x, int target_y) {
    // base case - at the bottom right
    if (current_row == target_x - 1 && current_col == target_y - 1) {
        return 1;
    }
    // base case - off the grid
    if (current_row >= target_x || current_col >= target_y) {
        return 0;
    }
    return gridWays(current_row + 1, current_col, target_y, target_x)
        + gridWays(current_row, current_col + 1, target_y, target_x);
}

int main() {
    std::cout << gridWays(0, 0, 3, 3) << '\n';
}
