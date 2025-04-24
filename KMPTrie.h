#ifndef KMPTRIE_H
#define KMPTRIE_H
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEnd = false;
};

class NaiveTrie {
    TrieNode* root;
public:
    NaiveTrie();
    void insert(const string& word);
    vector<string> searchInText(const string& text);
};

class KMPTrie {
    TrieNode* root;
    unordered_map<string, vector<int>> lpsMap;
public:
    KMPTrie();
    void insert(const string& word);
    vector<string> searchInText(const string& text);
private:
    vector<int> computeLPS(const string& pattern);
};

#endif