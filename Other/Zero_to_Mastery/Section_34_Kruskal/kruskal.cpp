/*
 * Turn graph into minimum spanninng tree (greedy)
 * 1) Sort the edges by weights
 * 2) Pick the sorted edges one by one and add to spanning
 *    tree as long as edge does not make a cycle
 *
 * For spanning tree you need
 *  n vertexes
 *  n-1 edges
 *
 *  Disjoint-set (for cycle detection in Kruskal)
 *  - makeSet - create set with 1 element
 *  - union   - take 2 sets and merge them into 1
 *  - find    - return a representive elemennt for that set
 *  Note: set means component
 *  If 2 elements lies in the same set, they live in the same
 *  connect component
 */

#include <iostream>
#include <vector>
#include <algorithm>

void makeSet(int n, int parent[]) {
    for (int i {}; i < n; ++i) {
        parent[i] = i;
    }
}

int find(int i, int parent[]) {
    while (parent[i] != i) {
        i = parent[i];
    }
    return i;
}

bool compare(std::vector<int>& a, std::vector<int>& b) {
    return a[2] < b[2];
}

int msg_kruskal(int n, std::vector<std::vector<int>>& edges) {
    std::sort(edges.begin(), edges.end(), compare);
    
    int parent[n + 1];
    makeSet(n, parent);
    int cost {};
    for (int i {}; i < edges.size(); ++i) {
        int s = edges[i][0];
        int d = edges[i][1];
        int rS = find(s, parent);
        int rD = find(d, parent);
        if (rS != rD) {
            cost += edges[i][2];
            parent[rS] = rD; //union
        }
    }
    return cost;
}
