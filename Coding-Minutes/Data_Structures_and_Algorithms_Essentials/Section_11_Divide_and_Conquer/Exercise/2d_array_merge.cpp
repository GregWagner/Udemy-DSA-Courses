/*
 * Implemennt merge sort for 1 2D array. In case of
 * off dimeennsion, the first givision contains
 * more numbers than the second one. The complete
 * execution of merge sort arranges the elements in
 * increasing order either moving row-wise or
 * column-wise
 *
 * Hint : Divide, sort row - wise, sort col - wise
 */
#include <iostream>
#include <vector>

void printMatrix(std::vector<std::vector<int>>& a) {
    for (const auto& v : a) {
        for (const auto& e : v) {
            std::cout << e << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

void merge_row(std::vector<std::vector<int>>& mat, int i, int cs, int cm, int ce) {
    std::vector<int> sorted;
    int x { cs };
    int y { cm + 1 };
    // std::cout << x << " " << cm << " " << y << " " << ce << endl;
    while (x <= cm && y <= ce) {
        if (mat[i][x] < mat[i][y]) {
            sorted.push_back(mat[i][x]);
            x++;
        } else {
            sorted.push_back(mat[i][y]);
            y++;
        }
    }

    while (x <= cm) {
        sorted.push_back(mat[i][x]);
        x++;
    }
    while (y <= ce) {
        sorted.push_back(mat[i][y]);
        y++;
    }
    int k {};
    for (int j = cs; j <= ce; j++) {
        mat[i][j] = sorted[k];
        k++;
    }
}

void merge_col(std::vector<std::vector<int>>& mat, int j, int rs, int rm, int re) {
    std::vector<int> sorted;
    int x { rs };
    int y { rm + 1 };
    while (x <= rm && y <= re) {
        if (mat[x][j] < mat[y][j]) {
            sorted.push_back(mat[x][j]);
            x++;
        } else {
            sorted.push_back(mat[y][j]);
            y++;
        }
    }
    while (x <= rm) {
        sorted.push_back(mat[x][j]);
        x++;
    }
    while (y <= re) {
        sorted.push_back(mat[y][j]);
        y++;
    }
    int k {};
    for (int i = rs; i <= re; i++) {
        mat[i][j] = sorted[k];
        k++;
    }
}

void merge(int m, int n, std::vector<std::vector<int>>& mat, int rs, int rm, int re, int cs, int cm, int ce) {

    // for sorting rows
    for (int i = rs; i <= re; i++) {
        merge_row(mat, i, cs, cm, ce);
    }

    // for sorting columns
    for (int j = cs; j <= ce; j++) {
        merge_col(mat, j, rs, rm, re);
    }
}

void merge_sort(int m, int n, std::vector<std::vector<int>>& mat, int rs, int re, int cs, int ce) {
    if (rs >= re && cs >= ce) {
        return;
    }

    int rm = (rs + re) / 2;
    int cm = (cs + ce) / 2;

    // for dividing into subarrays
    merge_sort(m, n, mat, rs, rm, cs, cm);
    merge_sort(m, n, mat, rm + 1, re, cs, cm);
    merge_sort(m, n, mat, rs, rm, cm + 1, ce);
    merge_sort(m, n, mat, rm + 1, re, cm + 1, ce);

    // for merging sorted subarrays
    merge(m, n, mat, rs, rm, re, cs, cm, ce);
}

std::vector<std::vector<int>> mergeSort(int m, int n, std::vector<std::vector<int>> v) {
    merge_sort(m, n, v, 0, m - 1, 0, n - 1);
    return v;
}

int main() {
    std::vector<std::vector<int>> a {
        {18,  4,  16, 8 },
        { 23, 13, 20, 11},
        { 28, 24, 26, 25},
        { 1,  30, 15, 19}
    };
    auto answer = mergeSort(4, 4, a);
    printMatrix(answer);

    std::vector<std::vector<int>> b {
        {18,  9,  11},
        { 1,  4,  15},
        { 13, 23, 20}
    };
    answer = mergeSort(3, 3, b);
    printMatrix(answer);
}
