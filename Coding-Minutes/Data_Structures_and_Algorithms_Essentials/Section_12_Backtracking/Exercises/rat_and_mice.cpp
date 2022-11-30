/*
 * You are given an N*M grid. Each cell (i,j) in the
 * grid is either blocked, or empty. The rat can move
 * from a position towards left, right, up or down on
 * the grid.
 *
 * Initially the rat is on the position (1,1). It wants
 * to each position (N,M) where its mice is waiting
 * for. There exits a unique path in the grid . Find
 * that path and help the rat reach its mice.
 */
#include <iostream>
#include <vector>

bool canPlace(std::vector<std::string>& arr, std::vector<std::vector<int>>& res, int r, int c, int n, int m) {
    return r >= 0 && r < n && c >= 0 && c < m && arr[r][c] != 'X' && res[r][c] != 1;
}

bool findPath(std::vector<std::string>& arr, std::vector<std::vector<int>>& res, int r, int c, int n, int m) {
    if (r == n - 1 && c == m - 1) {
        res[r][c] = 1;
        return true;
    }
    if (canPlace(arr, res, r, c, n, m)) {
        res[r][c] = 1;
        if (findPath(arr, res, r + 1, c, n, m)
            || findPath(arr, res, r - 1, c, n, m)
            || findPath(arr, res, r, c + 1, n, m)
            || findPath(arr, res, r, c - 1, n, m)) {
            return true;
        }
        // backtrack
        res[r][c] = 0;
        return false;
    }
}

std::vector<std::vector<int>> ratAndMice(std::vector<std::string> arr) {
    int n = arr.size();
    int m = arr[0].size();

    std::vector<std::vector<int>> res(n, std::vector<int>(m, 0));
    findPath(arr, res, 0, 0, n, m);
    return res;
}

int main() {
}