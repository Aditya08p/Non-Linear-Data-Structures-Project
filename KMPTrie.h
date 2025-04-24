#ifndef KMPTRIE_H
#define KMPTRIE_H
#include <unordered_map>
#include <vector>
#include <string>

struct TrieNode {
    std::unordered_map<char, TrieNode*> children;
    bool isEnd = false;
};

class NaiveTrie {
    TrieNode* root;
public:
    NaiveTrie();
    void insert(const std::string& word);
    std::vector<std::string> searchInText(const std::string& text);
};

class KMPTrie {
    TrieNode* root;
    std::unordered_map<std::string, std::vector<int>> lpsMap;
public:
    KMPTrie();
    void insert(const std::string& word);
    std::vector<std::string> searchInText(const std::string& text);
private:
    std::vector<int> computeLPS(const std::string& pattern);
};

#endif