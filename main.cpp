#include <iostream>
#include <chrono>
#include <cstdlib>
#include "Dijkstra.h"
#include "Dijkstra.cpp"
#include "KMPTrie.h"
#include "KMPTrie.cpp"
#include "DisjointSet.h"
#include "DisjointSet.cpp"
using namespace std;
int main() {
    while (true) {
        std::cout << "\nChoose an algorithm to run:\n";
        std::cout << "1. Dijkstra's Algorithm (Naive vs Optimized)\n";
        std::cout << "2. Pattern Search (Naive Trie vs KMP + Trie)\n";
        std::cout << "3. Union-Find (Naive vs Optimized)\n";
        std::cout << "4. Run All Comparisons\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter choice: ";

        int choice;
        std::cin >> choice;
        if (choice == 0) break;

        if (choice == 1 || choice == 4) {
            std::cout << "\n[Running Dijkstra Comparison]\n";
            const int N = 1000;
            NaiveGraph ng(N);
            Graph og(N);
            for (int i = 0; i < N - 1; ++i) {
                int w = 1 + rand() % 10;
                ng.addEdge(i, i + 1, w);
                og.addEdge(i, i + 1, w);
            }
            for (int i = 0; i < 10000; ++i) {
                int u = rand() % N, v = rand() % N;
                if (u != v) {
                    int w = 1 + rand() % 10;
                    ng.addEdge(u, v, w);
                    og.addEdge(u, v, w);
                }
            }
            ng.dijkstra(0);
            og.dijkstra(0);
            auto start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < 10; ++i) ng.dijkstra(0);
            auto end = std::chrono::high_resolution_clock::now();
            auto t1 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
            start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < 10; ++i) og.dijkstra(0);
            end = std::chrono::high_resolution_clock::now();
            auto t2 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
            std::cout << "Naive:      (avg over 10 runs): " << t1 / 10.0 << " ms\n";
            std::cout << "Optimized:  (avg over 10 runs): " << t2 / 10.0 << " ms\n";
        }

        if (choice == 2 || choice == 4) {
            std::cout << "\n[Running Pattern Search Comparison]\n";
            std::string text(10000, 'a');
            for (int i = 1000; i < 1100; ++i) text[i] = "catbatrat"[rand() % 9];
            std::vector<std::string> words = {"cat", "bat", "rat", "aaa", "aab"};
            NaiveTrie nt;
            KMPTrie kt;
            for (const auto& w : words) {
                nt.insert(w);
                kt.insert(w);
            }
            nt.searchInText(text);
            kt.searchInText(text);
            auto start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < 100; ++i) nt.searchInText(text);
            auto end = std::chrono::high_resolution_clock::now();
            auto t1 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
            start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < 100; ++i) kt.searchInText(text);
            end = std::chrono::high_resolution_clock::now();
            auto t2 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
            std::cout << "Naive:      (avg over 100 runs): " << t1 / 100.0 << " ms\n";
            std::cout << "Optimized:  (avg over 100 runs): " << t2 / 100.0 << " ms\n";
        }

        if (choice == 3 || choice == 4) {
            std::cout << "\n[Running Union-Find Comparison]\n";
            const int N = 1000;
            NaiveDisjointSet nds(N);
            DisjointSet ds(N);
            std::vector<std::pair<int, int>> ops;
            for (int i = 0; i < 10000; ++i) {
                int u = rand() % N, v = rand() % N;
                if (u != v) ops.emplace_back(u, v);
            }
            auto start = std::chrono::high_resolution_clock::now();
            for (const auto& p : ops) nds.unite(p.first, p.second);
            for (int i = 0; i < N; ++i) nds.find(i);
            auto end = std::chrono::high_resolution_clock::now();
            auto t1 = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
            start = std::chrono::high_resolution_clock::now();
            for (const auto& p : ops) ds.unite(p.first, p.second);
            for (int i = 0; i < N; ++i) ds.find(i);
            end = std::chrono::high_resolution_clock::now();
            auto t2 = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
            std::cout << "Naive:      (total): " << t1 / 1000.0 << " ms\n";
            std::cout << "Optimized:  (total): " << t2 / 1000.0 << " ms\n";
        }
    }
    return 0;
}