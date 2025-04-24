#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include <vector>
#include <queue>
#include <set>
#include <climits>

class NaiveGraph {
public:
    int V;
    std::vector<std::vector<std::pair<int, int>>> adj;
    NaiveGraph(int V);
    void addEdge(int u, int v, int w);
    std::vector<int> dijkstra(int src);
};

class Graph {
public:
    int V;
    std::vector<std::vector<std::pair<int, int>>> adj;
    Graph(int V);
    void addEdge(int u, int v, int w);
    std::vector<int> dijkstra(int src);
};

#endif