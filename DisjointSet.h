#ifndef DISJOINTSET_H
#define DISJOINTSET_H
#include <vector>
using namespace std;
class NaiveDisjointSet {
    vector<int> parent;
public:
    NaiveDisjointSet(int n);
    int find(int x);
    void unite(int x, int y);
};

class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n);
    int find(int x);
    void unite(int x, int y);
};
NaiveDisjointSet::NaiveDisjointSet(int n) : parent(n) {
    for (int i = 0; i < n; ++i) parent[i] = i;
}
int NaiveDisjointSet::find(int x) {
    while (x != parent[x]) x = parent[x];
    return x;
}
void NaiveDisjointSet::unite(int x, int y) {
    int rootX = find(x), rootY = find(y);
    if (rootX != rootY) parent[rootY] = rootX;
}

DisjointSet::DisjointSet(int n) : parent(n), rank(n, 0) {
    for (int i = 0; i < n; ++i) parent[i] = i;
}
int DisjointSet::find(int x) {
    if (x != parent[x]) parent[x] = find(parent[x]);
    return parent[x];
}
void DisjointSet::unite(int x, int y) {
    int rootX = find(x), rootY = find(y);
    if (rootX == rootY) return;
    if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
    } else if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}
#endif