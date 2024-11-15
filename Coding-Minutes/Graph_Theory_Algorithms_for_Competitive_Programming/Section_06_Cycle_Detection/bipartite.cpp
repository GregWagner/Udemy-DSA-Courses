/*
* Bipartite Graph       Video 31
*/
#include <iostream>
#include <vector>

const int NOT_VISITED {};

bool dfs_helper(const std::vector<int> graph[], int node, int* visited, int parent, int color) {
    visited[node] = color;  // 1 or 2 both mean visited

    for (const auto &neighbor : graph[node]) {
        if (visited[neighbor] == NOT_VISITED) {
            int subProblem = dfs_helper(graph, neighbor, visited, node, 3 - color);
            if (!subProblem) {
                return false;
            }
        } else if (neighbor != parent && color == visited[neighbor]) {
            return false;
        }
    }
    return true;
}

// check if graph is bipartite using dfs
bool isGraphBipartite(std::vector<int> graph[], int n) {
    // 0 - not visited, 1  - visited Color is 1, 2 - visited Color is 2
    int visited[n] = {};
    int color {1};
    int answer = dfs_helper(graph, 0, visited, -1, color);

    // print colors
    for (int i {}; i < n; ++i) {
        std::cout << i << " - Color " << visited[i] << '\n';
    }
    return answer;
}

int main() {
    int numberOfNodes, numberOfEdges;
    std::cout << "Enter number of nodes and number of edges\n";
    std::cin >> numberOfNodes >> numberOfEdges;

    std::vector<int> graph[numberOfNodes];

    while (numberOfEdges--) {
        int x, y;
        std::cin >> x >> y;

        // undirected graph
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    // bfs or dfs by coloring the nodes at each step
    // (current node has color 1, neighbors should have
    // color 2)
    std::cout << (isGraphBipartite(graph, numberOfNodes) ? "Yes, its bipartite" : "No, not bipartite") << '\n';
}
