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
NaiveTrie::NaiveTrie() { root = new TrieNode(); }
void NaiveTrie::insert(const string& word) {
    TrieNode* node = root;
    for (char c : word) {
        if (!node->children[c]) node->children[c] = new TrieNode();
        node = node->children[c];
    }
    node->isEnd = true;
}
vector<string> NaiveTrie::searchInText(const string& text) {
    vector<string> found;
    for (int i = 0; i < text.size(); ++i) {
        TrieNode* node = root;
        string word;
        for (int j = i; j < text.size(); ++j) {
            char c = text[j];
            if (!node->children.count(c)) break;
            word += c;
            node = node->children[c];
            if (node->isEnd) found.push_back(word);
        }
    }
    return found;
}

KMPTrie::KMPTrie() { root = new TrieNode(); }
void KMPTrie::insert(const string& word) {
    TrieNode* node = root;
    for (char c : word) {
        if (!node->children[c]) node->children[c] = new TrieNode();
        node = node->children[c];
    }
    node->isEnd = true;
    lpsMap[word] = computeLPS(word);
}
vector<string> KMPTrie::searchInText(const string& text) {
    vector<string> found;
    for (auto it = lpsMap.begin(); it != lpsMap.end(); ++it) {
        string pattern = it->first;
        vector<int> lps = it->second;
        int m = pattern.size(), n = text.size();
        int i = 0, j = 0;
        while (i < n) {
            if (text[i] == pattern[j]) {
                i++; j++;
                if (j == m) {
                    found.push_back(pattern);
                    j = lps[j - 1];
                }
            } else if (j > 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return found;
}
vector<int> KMPTrie::computeLPS(const string& pattern) {
    vector<int> lps(pattern.size(), 0);
    int len = 0;
    for (int i = 1; i < pattern.size(); ) {
        if (pattern[i] == pattern[len]) {
            lps[i++] = ++len;
        } else if (len) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }
    return lps;
}
#endif