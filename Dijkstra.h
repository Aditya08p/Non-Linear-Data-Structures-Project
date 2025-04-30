// ===================== Dijkstra.h =====================
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
NaiveGraph::NaiveGraph(int V) : V(V) { adj.resize(V); }
void NaiveGraph::addEdge(int u, int v, int w) {
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
}
vector<int> NaiveGraph::dijkstra(int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, src});
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto& edge : adj[u]) {
            int v = edge.first, w = edge.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

Graph::Graph(int V) : V(V) { adj.resize(V); }
void Graph::addEdge(int u, int v, int w) {
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
}
vector<int> Graph::dijkstra(int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    set<pair<int, int>> pq;
    pq.insert({0, src});
    while (!pq.empty()) {
        int u = pq.begin()->second;
        pq.erase(pq.begin());
        for (auto& edge : adj[u]) {
            int v = edge.first, w = edge.second;
            if (dist[u] + w < dist[v]) {
                pq.erase({dist[v], v});
                dist[v] = dist[u] + w;
                pq.insert({dist[v], v});
            }
        }
    }
    return dist;
}
#endif