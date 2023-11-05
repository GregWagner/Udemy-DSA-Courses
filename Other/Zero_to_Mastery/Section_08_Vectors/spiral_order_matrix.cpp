/*
 * Spiral Matrix
 * LeetCode 54
 */
#include <iostream>
#include <vector>

struct Solution {
    std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        std::vector<int> results;
        if (m == 0 || n == 0) {
            return results;
        }

        int startingRow {};
        int endingRow {m - 1};
        int startingColumn {};
        int endingColumn {n - 1};

        int count {};
        int total {n * m};

        while (startingRow <= endingRow && startingColumn <= endingColumn) {
            // do the top row
            for (int i {startingColumn}; i <= endingColumn; ++i) {
                // std::cout << "Top Row:  " << startingRow << ": " << i << '\n';
                results.push_back(matrix[startingRow][i]);
                ++count;
            }
            ++startingRow;
            if (count == total) {
                return results;
            }

            // do the last column
            for (int i {startingRow}; i <= endingRow; ++i) {
                // std::cout << "Last Col: " << i << ": " << endingColumn << '\n';
                results.push_back(matrix[i][endingColumn]);
                ++count;
            }
            --endingColumn;
            if (count == total) {
                return results;
            }

            // do the Last row
            for (int i {endingColumn}; i >= startingColumn; --i) {
                // std::cout << "Last Row: " << endingRow << ": " << i << '\n';
                results.push_back(matrix[endingRow][i]);
                ++count;
            }
            --endingRow;
            if (count == total) {
                return results;
            }

            // do the first column
            for (int i {endingRow}; i >= startingRow; --i) {
                // std::cout << "1st Col:  " << i << ": " << startingColumn << '\n';
                results.push_back(matrix[i][startingColumn]);
                ++count;
            }
            ++startingColumn;
            if (count == total) {
                return results;
            }
        }
        return results;
    }
};

int main() {
    std::vector<std::vector<int>> matrix {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    Solution s;
    std::vector<int> a = s.spiralOrder(matrix);
    for (auto const & e : a) {
        std::cout << e << ' ';
    }
    std::cout << '\n';
}
