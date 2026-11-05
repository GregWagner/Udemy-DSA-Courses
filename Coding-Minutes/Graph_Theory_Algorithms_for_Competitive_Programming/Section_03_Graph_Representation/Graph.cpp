/*
 * Using an Adjacency List to represent a graph
 * Video 15
 */
#include <iostream>
#include <list>

class Graph {

public:
  explicit Graph(int numberOfVertices)
      : mNumberOfVertices{numberOfVertices},
        mAdjacencyList{new std::list<int>[mNumberOfVertices]} {}

  // srcNode and destNode are the connected nodes
  void addEdge(int srcNode, int destNode, bool undirectional = true) {
    mAdjacencyList[srcNode].push_back(destNode);
    if (undirectional) {
      mAdjacencyList[destNode].push_back(srcNode);
    }
  }

  void printAdjacencyList() {
    for (int i{}; i < mNumberOfVertices; ++i) {
      std::cout << i << " --> ";
      bool first{true};
      for (const auto &vertice : mAdjacencyList[i]) {
        std::cout << (first ? "" : ", ");
        first = false;
        std::cout << vertice;
      }
      std::cout << '\n';
    }
  }

private:
  int mNumberOfVertices{};
  // this could also be an array/vector of lists or a hashmaap
  std::list<int> *mAdjacencyList;
};

int main() {
  Graph graph(6);
  graph.addEdge(0, 1);
  graph.addEdge(0, 4);
  graph.addEdge(2, 1);
  graph.addEdge(3, 4);
  graph.addEdge(4, 5);
  graph.addEdge(2, 3);
  graph.addEdge(3, 5);

  graph.printAdjacencyList();
}
