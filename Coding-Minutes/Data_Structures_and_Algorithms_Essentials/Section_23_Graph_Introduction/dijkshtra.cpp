#include <iostream>
#include <list>
#include <set>
#include <vector>
#include <climits>

class Graph {
private:
    int nummber_of_vertices;
    std::list<std::pair<int,int> > *l;

public:
    /**
     * Constructor for the Graph class.
     *
     * @param v the number of vertices in the graph
     * @return N/A
     * @throws N/A
     */
    explicit Graph(int v) : nummber_of_vertices {v} {
        l = new std::list<std::pair<int, int>>[nummber_of_vertices];
    }

    /**
     * Adds an edge between two vertices in a graph.
     *
     * @param u the first vertex
     * @param v the second vertex
     * @param weight the weight of the edge
     * @param undir whether the edge is undirected (default is true)
     */
    void addEdge(int u, int v, int weight, bool undir = true){
        l[u].push_back({weight, v});
        if(undir) {
            l[v].push_back({weight, u});
        }
    }

    // Single Source Shortest Paths for weighted graphs
    // Time Complexity: O(E log V)
    // Space Complexity: O(V)
    // Algorithm: Dijkstra's Algorithm
    //
    // Returns the shortest distance from the source node to the destination node
    // in a weighted graph
    //
    int dijkstra(int src, int dest) {
        std::vector<int> dist(nummber_of_vertices, INT_MAX); // distances from source
        std::set<std::pair<int, int>> s; // set of <distance, node> pairs

        // initialize
        dist[src] = 0;
        s.insert({ 0, src });

        while (!s.empty()) {
            auto it = s.begin(); // iterator to the pair with the minimum distance
            int currentDistance = it->first; // distance of the current node
            int node = it->second; // the current node
            s.erase(it); // remove from the set (no pop in set)

            // iterate over the neighbors of the node
            for (auto neighborPair : l[node]) {
                int currentEdge = neighborPair.first; // weight of the edge
                int neighbor = neighborPair.second; // node connected by the edge

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

/**
 * The main function that creates a graph, adds edges, and performs Dijkstra's algorithm to find the shortest path from a source vertex to a destination vertex.
 *
 * @param None
 * @return None
 * @throws None
 */
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
