#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include <vector>
#include <queue>
#include <set>
#include <climits>
using namespace std;
class NaiveGraph {
public:
    int V;
    vector<vector<pair<int, int>>> adj;
    NaiveGraph(int V);
    void addEdge(int u, int v, int w);
    vector<int> dijkstra(int src);
};

class Graph {
public:
    int V;
    vector<vector<pair<int, int>>> adj;
    Graph(int V);
    void addEdge(int u, int v, int w);
    vector<int> dijkstra(int src);
};

#endif