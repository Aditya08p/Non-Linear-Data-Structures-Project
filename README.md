# ⚙️ Naive vs Optimized Algorithms (C++ Implementation)

This project explores and compares naive and optimized versions of three foundational algorithms:

- **Dijkstra’s Algorithm**
- **String Matching using Trie (with KMP Hybrid)**
- **Union-Find (Disjoint Set)**

Each algorithm is implemented in its own header file, and driven from a `main.cpp` runner.

---

## 📁 Project Structure

```
├── Dijkstra.h        # Naive and optimized Dijkstra's algorithm
├── DisjointSet.h     # Naive and optimized Union-Find (Disjoint Set)
├── KMPTrie.h         # Trie-based pattern matching and KMP-Trie hybrid
├── main.cpp          # Entry point: allows you to test all implementations
└── main.exe          # Precompiled executable (for Windows)
```

---

## 🚀 How to Run

### 🖥️ Compile (on any system with a C++ compiler)

```bash
g++ main.cpp -o main
./main
```

Or, on Windows if you prefer:

```bash
g++ main.cpp -o main.exe
main.exe
```

> You can also directly use the provided `main.exe` if you're on Windows.

---

## 📌 Algorithm Overview

### 1. Dijkstra’s Algorithm

| Version   | Description                                       | Time Complexity     |
|-----------|---------------------------------------------------|---------------------|
| Naive     | Scans all vertices to find minimum distance       | O(V²)               |
| Optimized | Uses min-heap (priority queue) for fast selection | O((V + E) log V)    |

---

### 2. String Matching (Trie vs KMP-Trie Hybrid)

| Version        | Description                                                                 | Time Complexity     |
|----------------|-----------------------------------------------------------------------------|---------------------|
| Naive Trie     | Basic trie, character-by-character search                                   | O(m) per pattern    |
| KMP-Trie Hybrid| Uses KMP’s LPS array to skip unnecessary comparisons during search          | O(m + k)            |

Where:
- `m` = pattern length
- `k` = number of matches in the text

---

### 3. Union-Find (Disjoint Set)

| Version   | Description                                             | Time Complexity     |
|-----------|---------------------------------------------------------|---------------------|
| Naive     | Simple tree structure, no balancing                     | O(n)                |
| Optimized | Path Compression + Union by Rank for flat trees         | O(α(n)) (amortized) |

Where:
- `α(n)` is the inverse Ackermann function, practically constant

---

## 📊 Benchmarking

> Benchmark tests are run within `main.cpp` for side-by-side comparisons of performance between naive and optimized versions.

You can customize input sizes and operations inside `main.cpp` for your own benchmarking.

---

## 💡 Learn More

This project is great for:

- Understanding the importance of data structures in algorithm performance
- Studying the effect of optimization techniques like heaps, path compression, and KMP
- Comparing real-world runtimes of theoretical complexities

---

## 📝 License

This project is open-source and licensed under the MIT License.

