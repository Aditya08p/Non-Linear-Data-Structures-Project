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

#endif