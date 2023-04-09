#include <iostream>
#include <vector>
#include <queue>

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& item : row) {
            std::cout << item << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

void printDFS(const std::vector<std::vector<int>>& matrix,
        int startingVertex, std::vector<bool> &visited) {
    std::cout << startingVertex << '\n';
    visited[startingVertex] = true;
    for (size_t i {}; i < matrix.size(); ++i) {
        if (matrix[startingVertex][i] == 1 && visited[i] == false) {
            printDFS(matrix, i, visited);
        }
    }
}

void dfs(const std::vector<std::vector<int>>& matrix) {
    int count {};
    std::vector<bool> visited (matrix.size(), false);
    for (size_t i {}; i < matrix.size(); ++i) {
        if (!visited[i]) {
            ++count;
            std::cout << "--------------------\n";
            printDFS(matrix, i, visited);
        }
    }
    std::cout << "Number of connected components is " << count << '\n';
}

void printBFS(const std::vector<std::vector<int>>& matrix,
        int startingVertex, std::vector<bool> &visited) {
    std::queue<int> q;
    q.push(startingVertex);
    visited[startingVertex] = true;

    while (!q.empty()) {
        int item = q.front();
        q.pop();
        std::cout << item << ' ';
        for (size_t i {}; i < matrix.size(); ++i) {
            if (matrix[item][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    std::cout << '\n';
}

void bfs(const std::vector<std::vector<int>>& matrix) {
    int count {};
    std::vector<bool> visited (matrix.size(), false);
    for (size_t i {}; i < visited.size(); ++i) {
        if (!visited[i]) {
            ++count;
            std::cout << "--------------------\n";
            printBFS(matrix, i, visited);
        }
    }
    std::cout << "Number of connected components is " << count << '\n';
}

int main() {
    int n {};
    std::cout << "Enter number of vertices: ";
    std::cin >> n;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));

    int e {};
    std::cout << "Enter number of edges: ";
    std::cin >> e;

    for (int i {}; i < e; ++i) {
        std::cout << "Enter starting and ending vertex: ";
        int startingVertex {};
        int endingVertex {};
        std::cin >> startingVertex >> endingVertex;
        matrix[startingVertex][endingVertex] = 1;
        matrix[endingVertex][startingVertex] = 1;
    }
    printMatrix(matrix);

    std::cout << "DFS:\n";
    dfs(matrix);

    std::cout << "BFS:\n";
    bfs(matrix);
}
