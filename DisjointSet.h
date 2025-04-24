#ifndef DISJOINTSET_H
#define DISJOINTSET_H
#include <vector>

class NaiveDisjointSet {
    std::vector<int> parent;
public:
    NaiveDisjointSet(int n);
    int find(int x);
    void unite(int x, int y);
};

class DisjointSet {
    std::vector<int> parent, rank;
public:
    DisjointSet(int n);
    int find(int x);
    void unite(int x, int y);
};

#endif