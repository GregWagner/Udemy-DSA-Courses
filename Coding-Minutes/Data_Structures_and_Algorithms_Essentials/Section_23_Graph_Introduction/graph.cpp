#include <climits>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <vector>

class Graph {

    // Adjacency List Representations
private:
    int number_of_vertices;
    std::list<int>* l;

public:
    explicit Graph(int v)
        : number_of_vertices { v } {
        l = new std::list<int>[v];
    }

    void addEdge(int i, int j, bool undirected = true) {
        l[i].push_back(j);
        if (undirected) {
            l[j].push_back(i);
        }
    }

    void printAdjancyList() {
        for (int i {}; i < number_of_vertices; ++i) {
            std::cout << i << " --> ";
            for (auto node : l[i]) {
                std::cout << node << ' ';
            }
            std::cout << '\n';
        }
    }

    void bfs(int source) {
        std::queue<int> q;
        bool* visited = new bool[number_of_vertices] {};
        q.push(source);
        visited[source] = true;

        while (!q.empty()) {
            int f = q.front();
            std::cout << f << '\n';
            q.pop();

            // push the neighbors of current node if
            // they have not already been visited
            for (auto neighbor : l[f]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }

    void dfsHelper(int node, bool* visited) {
        visited[node] = true;
        std::cout << node << ' ';

        // make a dfs call of all univisted neighbors
        for (int neighbor : l[node]) {
            if (!visited[neighbor]) {
                dfsHelper(neighbor, visited);
            }
        }
    }

    void dfs(int source) {
        bool* isVisited = new bool[number_of_vertices] {};
        dfsHelper(source, isVisited);
        std::cout << '\n';
    }

    void topological_sort() {
        // calcullaate in-degree for all nodes
        std::vector<int> inDegree(number_of_vertices, 0);

        // iterate over all the edges to find the right indegree
        for (int i {}; i < number_of_vertices; ++i) {
            for (auto neighbor : l[i]) {
                ++inDegree[neighbor];
            }
        }

        // bfs
        std::queue<int> q;
        // initializee the queue with nodes having an inDegree of 0
        for (int i {}; i < number_of_vertices; ++i) {
//          std::cout << i << ": inDegree: " << inDegree[i] << '\n';
            if (inDegree[i] == 0) {
//              std::cout << "Node " << i << " has inDegree of 0\n";
                q.push(i);
            }
        }

        // starting poping
        while (!q.empty()) {
            int node = q.front();
            std::cout << node << ' ';
            q.pop();

            // iteraate over the neighbors of this node
            // and reduce the inDegree by 1
            for (auto neighbor : l[node]) {
                --inDegree[neighbor];
                if (inDegree[neighbor] == 0) {
//                  std::cout << "Node " << neighbor << " has indegree of 0\n";
                    q.push(neighbor);
                }
            }
        }
        std::cout << '\n';
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 2, false);
    g.addEdge(2, 3, false);
    g.addEdge(3, 5, false);
    g.addEdge(4, 5, false);
    g.addEdge(1, 4, false);
    g.addEdge(1, 2, false);

    g.printAdjancyList();
    g.bfs(1);
    std::cout << "-------------------------\n";
    g.dfs(1);
    std::cout << "-------------------------\n";
    g.topological_sort();
}
