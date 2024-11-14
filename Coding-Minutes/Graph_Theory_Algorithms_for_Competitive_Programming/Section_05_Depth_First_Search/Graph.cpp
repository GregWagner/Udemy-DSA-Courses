/*
 * Depth First Search      Video 24
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

        void printAdjacencyList() {
            for (int i {}; i < mNumberOfVertices; ++i) {
                std::cout << i << " --> ";
                bool first {true};
                for (const auto &vertice : mAdjacencyList[i]) {
                    std::cout << (first ? "" : ", ");
                    first = false;
                    std::cout << vertice;
                }
                std::cout << '\n';
            }
        }

        void dfs(int source) {
            bool *visited = new bool[mNumberOfVertices] {};
            dfsHelper(source, visited);
            std::cout << '\n';
        }

    private:
        int mNumberOfVertices {};
        std::list<int> *mAdjacencyList;

        void dfsHelper(int node, bool* visited) {
            visited[node] = true;
            std::cout << node << ' ';

            // make a recursive call on all its unvisted neighbors
            for (auto neighbor : mAdjacencyList[node]) {
                if (!visited[neighbor]) {
                    dfsHelper(neighbor, visited);
                }
            }
        }
};

int main() {
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(2, 1);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(5, 6);

    g.dfs(1);
}
