/*
 * Given a matrix of size M x N, there are large number of queries to find submatrix
 * sums. Inputs to queries are left top and right bottom indexes of submatrix whose
 * sum is to find out.
 *
 * How to preprocess the matrix so that submatrix sum queries can be performed
 * in O(1) time.
 *
 * Hint: Pre Compute Cumilative Sums of every index i,j.
 */

#include <iostream>
#include <vector>

int sum(std::vector<std::vector<int>> v, int starting_row, int starting_column,
    int ending_row, int ending_column) {
    size_t m { v.size() };
    size_t n { v[0].size() };

    std::vector<std::vector<int>> aux = v;
    std::vector<std::vector<int>> mat = v;

    for (size_t i {}; i < n; ++i) {
        aux[0][i] = mat[0][i];
    }

    // do column wise sum
    for (size_t i { 1 }; i < m; ++i) {
        for (size_t j {}; j < n; ++j) {
            aux[i][j] = mat[i][j] + aux[i - 1][j];
        }
    }

    // Do row wise sum
    for (size_t i {}; i < m; ++i) {
        for (size_t j { 1 }; j < n; ++j) {
            aux[i][j] += aux[i][j - 1];
        }
    }

    int answer = aux[ending_row][ending_column];

    // Remove elements between (0, 0) and (starting_row-1, ending_column)
    if (starting_row > 0) {
        answer -= aux[starting_row - 1][ending_column];
    }

    // Remove elements between (0, 0) and (ending_row, starting_column-1)
    if (starting_column > 0) {
        answer -= aux[ending_row][starting_column - 1];
    }

    // Add aux[starting_row-1][starting_column-1] as elements between (0, 0)
    // and (starting_row-1, starting_column-1) are subtracted twice
    if (starting_row > 0 && starting_column > 0) {
        answer += aux[starting_row - 1][starting_column - 1];
    }

    return answer;
}

int main() {
}
