#include <iostream>
#include <list>
#include <set>
#include <vector>
#include <climits>

class Graph{
private:
    int nummber_of_vertices;
    std::list<std::pair<int,int> > *l;

public:
    explicit Graph(int v) : nummber_of_vertices {v} {
        l = new std::list<std::pair<int, int>>[nummber_of_vertices];
    }

    void addEdge(int u, int v, int weight, bool undir = true){
        l[u].push_back({weight, v});
        if(undir) {
            l[v].push_back({weight, u});
        }
    }

    // Single Source Shortest Paths for weighted graphs
    int dijkstra(int src, int dest) {
        std::vector<int> dist(nummber_of_vertices, INT_MAX);
        std::set<std::pair<int, int>> s;

        // initialize
        dist[src] = 0;
        s.insert({ 0, src });

        while (!s.empty()) {
            auto it = s.begin();
            int currentDistance = it->first;
            int node = it->second;
            s.erase(it); // remove from the set (no pop in set)

            // iterate over the neighbors of the node
            for (auto neighborPair : l[node]) {
                int currentEdge = neighborPair.first;
                int neighbor = neighborPair.second;

                if (currentDistance + currentEdge < dist[neighbor]) {
                    // remove if neighbor already exits in set
                    auto f = s.find({ dist[neighbor], neighbor });
                    if (f != s.end()) {
                        s.erase(f);
                    }
                    // insert updated value with new distancce
                    dist[neighbor] = currentDistance + currentEdge;
                    s.insert(std::make_pair(dist[neighbor], neighbor));
                }
            }
        }
        // print out single source shortest distance to all nodes
        for (int i {}; i < nummber_of_vertices; ++i) {
            std::cout << "Node " << i << ", Distance: " << dist[i] << '\n';
        }
        return dist[dest];
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(0, 2, 4);
    g.addEdge(0, 3, 7);
    g.addEdge(3, 2, 2);
    g.addEdge(3, 4, 3);

    std::cout << g.dijkstra(0, 4) << '\n';
}
