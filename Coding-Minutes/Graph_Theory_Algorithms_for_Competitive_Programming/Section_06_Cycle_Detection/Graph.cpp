/*
 * Cycle Detection in an Undirected Graph using dfs (containsCycle)
 * Undirected Graph     Video 27
 * Directed Graph       Video 29
 */

#include <iostream>
#include <list>
#include <memory>
#include <queue>

class Graph {
    public:
        explicit Graph(int numberOfVertices)
            : mNumberOfVertices{numberOfVertices},
              mAdjacencyList{new std::list<int>[mNumberOfVertices]} {
        }

        void addEdge(int i, int j, bool undirectional = true) {
            mAdjacencyList[i].push_back(j);
            if (undirectional) {
                mAdjacencyList[j].push_back(i);
            }
        }

        bool undirectedGraphContainsCycle() {
            // Graph must be a single component (all nodes connected)
            std::vector<bool> visited(mNumberOfVertices, false);
            return dfs_undirected_graph(0, visited, -1);
        }

        bool directedGraphContainsCycle() {
            std::vector<bool> visited(mNumberOfVertices, false);
            std::vector<bool> stack(mNumberOfVertices, false);

            for (int i {}; i < mNumberOfVertices; ++i) {
                if (!visited[i]) {
                    if (dfs_directed_graph(i, visited, stack)) {
                        return true;
                    }
                }
            }
            return false;
        }

    private:
        int mNumberOfVertices {};
        std::list<int>* mAdjacencyList;

        // Cycle Detection in Undirected Graph
        bool dfs_undirected_graph(int node, std::vector<bool> &visited, int parent) {
            visited[node] = true;

            for (auto neighbor : mAdjacencyList[node]) {
                if (!visited[neighbor]) {
                    bool foundCycle = dfs_undirected_graph(neighbor, visited, node);
                    if (foundCycle) {
                        return true;
                    }
                } else if (neighbor != parent) {
                    // neighbor has already been visited and its not the
                    // parent of the current node in the current dfs call
                    return true;
                }
            }
            return false;
        }

        // Cycle Detection in Directed Graph
        bool dfs_directed_graph(int node, std::vector<bool> &visited,
                std::vector<bool> &stack ) {
            visited[node] = true;
            stack[node] = true;

            for (const auto &neighbor : mAdjacencyList[node]) {
                if (stack[neighbor] == true) {
                    return true;
                }
                if (!visited[neighbor]) {
                    bool foundCycle = dfs_directed_graph(neighbor, visited, stack);
                    if (foundCycle) {
                        return true;
                    }
                }
            }

            // going back
            stack[node] = false;
            return false;
        }
};

int main() {
    Graph g(3);
    g.addEdge(0, 1, false);
    g.addEdge(1, 2, false);
    g.addEdge(2, 0, false);

    std::cout << std::boolalpha;
    std::cout << g.undirectedGraphContainsCycle() << '\n';
    std::cout << g.directedGraphContainsCycle() << '\n';
}
