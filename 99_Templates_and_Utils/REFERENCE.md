# 99_Templates_and_Utils - Reference Guide

## 📌 Overview
This folder contains reusable code templates and utility functions for competitive programming and DSA problem-solving. Use these as starting points or reference materials for your solutions.

---

## 📂 Folder Structure

```
99_Templates_and_Utils/
│
├── 01_Code_Templates/
│   ├── template.cpp                    # General competitive programming template
│   ├── template_recursion.cpp          # Recursion and backtracking patterns
│   ├── template_graph.cpp              # Graph algorithms (BFS, DFS, Dijkstra, etc.)
│   ├── template_dp.cpp                 # Dynamic programming patterns
│   ├── template_binary_search.cpp      # Binary search variations
│   └── template_tree.cpp               # Binary tree operations
│
├── 02_Utils/
│   ├── math_utils.cpp                  # GCD, LCM, prime checks, modular arithmetic
│   ├── bit_utils.cpp                   # Bit manipulation operations
│   ├── array_utils.cpp                 # Array operations (rotate, prefix sum, etc.)
│   ├── string_utils.cpp                # String utilities (palindrome, anagram, etc.)
│   └── graph_utils.cpp                 # Graph utilities (cycle detection, topological sort)
│
├── 03_Debug/
│   ├── debug.cpp                       # Debug macros for printing variables
│   └── print_helpers.cpp               # Helper functions for printing data structures
│
└── 04_Testing/
    ├── input_generator.cpp             # Generate random test cases
    └── test_runner.sh                  # Shell script to run multiple test cases
```

---

## 🚀 Quick Reference

### 01_Code_Templates/

#### **template.cpp**
General template with:
- Fast I/O setup
- Common macros (`ll`, `pb`, `all`, etc.)
- Constants (MOD, INF)
- Utility functions (GCD, LCM, power)
- Multi-test case structure

**Use for:** Any competitive programming problem

---

#### **template_recursion.cpp**
Includes:
- Basic recursion pattern
- Backtracking template
- Divide and conquer template
- Memoization pattern

**Use for:** N-Queens, subset generation, permutations, combination problems

---

#### **template_graph.cpp**
Features:
- Graph class with adjacency list
- BFS traversal
- DFS traversal
- Dijkstra's shortest path
- Cycle detection (undirected)

**Use for:** Graph traversal problems, shortest path, connectivity

---

#### **template_dp.cpp**
Includes:
- 1D DP template
- 2D DP template
- 0/1 Knapsack
- Longest Common Subsequence (LCS)
- Longest Increasing Subsequence (LIS)
- Coin Change problem

**Use for:** Optimization problems, counting problems, decision problems

---

#### **template_binary_search.cpp**
Contains:
- Standard binary search
- Lower bound (first >= target)
- Upper bound (first > target)
- Find first occurrence
- Find last occurrence
- Binary search on answer

**Use for:** Search problems, finding boundaries, optimization problems

---

#### **template_tree.cpp**
Features:
- TreeNode structure
- Inorder, Preorder, Postorder traversals
- Level order traversal (BFS)
- Height calculation
- Count nodes
- Check if balanced
- Lowest Common Ancestor (LCA)
- Diameter of tree

**Use for:** Binary tree problems, tree traversals, tree properties

---

### 02_Utils/

#### **math_utils.cpp**
Functions:
- `gcd(a, b)` - Greatest Common Divisor
- `lcm(a, b)` - Least Common Multiple
- `power(base, exp, mod)` - Fast exponentiation
- `modInverse(a, mod)` - Modular inverse
- `isPrime(n)` - Prime check
- `sieve(n)` - Sieve of Eratosthenes
- `primeFactors(n)` - Prime factorization
- `nCr(n, r)` - Combinations
- `fibonacci(n)` - Fibonacci number
- `countDigits(n)`, `sumDigits(n)`, `reverseNumber(n)`

**Use for:** Number theory, mathematical calculations, modular arithmetic

---

#### **bit_utils.cpp**
Functions:
- `isSet(n, k)` - Check if kth bit is set
- `setBit(n, k)` - Set kth bit
- `clearBit(n, k)` - Clear kth bit
- `toggleBit(n, k)` - Toggle kth bit
- `countSetBits(n)` - Count 1s in binary
- `isPowerOf2(n)` - Check power of 2
- `generateSubsets(nums)` - All subsets using bitmask
- `singleNumber(nums)` - Find unique element (XOR)

**Use for:** Bit manipulation problems, subsets, XOR tricks

---

#### **array_utils.cpp**
Functions:
- `printArray(arr)` - Print array
- `reverseArray(arr)` - Reverse in-place
- `rotateArray(arr, k)` - Rotate by k positions
- `findMax(arr)`, `findMin(arr)` - Min/Max element
- `sumArray(arr)` - Sum of elements
- `prefixSum(arr)` - Prefix sum array
- `suffixSum(arr)` - Suffix sum array
- `removeDuplicates(arr)` - Remove duplicates
- `frequencyMap(arr)` - Element frequency
- `maxSubarraySum(arr)` - Kadane's algorithm
- `hasPairWithSum(arr, target)` - Two pointer
- `maxInWindow(arr, k)` - Sliding window maximum

**Use for:** Array manipulation, prefix/suffix arrays, sliding window

---

#### **string_utils.cpp**
Functions:
- `isPalindrome(s)` - Check palindrome
- `reverseString(s)` - Reverse string
- `countVowels(s)`, `countConsonants(s)` - Character counts
- `toLowerCase(s)`, `toUpperCase(s)` - Case conversion
- `removeSpaces(s)` - Remove whitespace
- `countWords(s)` - Word count
- `split(s, delimiter)` - Split string
- `join(arr, delimiter)` - Join strings
- `isAnagram(s1, s2)` - Anagram check
- `charFrequency(s)` - Character frequency map
- `removeDuplicates(s)` - Remove duplicate chars
- `countSubstring(main, sub)` - Count occurrences
- `longestCommonPrefix(strs)` - LCP of array

**Use for:** String manipulation, pattern matching, parsing

---

#### **graph_utils.cpp**
Functions:
- `isConnected(adj)` - Check if graph is connected
- `topologicalSort(adj)` - DFS-based topo sort
- `kahnsAlgorithm(adj)` - BFS-based topo sort
- `hasCycleDirected(adj)` - Cycle in directed graph
- `findAllPaths(adj, src, dest)` - All paths between nodes
- `isBipartite(adj)` - Check if bipartite
- `countComponents(adj)` - Count connected components

**Use for:** Advanced graph problems, topological ordering, cycle detection

---

### 03_Debug/

#### **debug.cpp**
Features:
- `debug(x)` macro for printing variables
- Supports: int, long long, double, char, string, bool
- Supports: vector, set, multiset, pair, map
- `Timer` class for execution time measurement

**Use for:** Debugging during development, performance analysis

---

#### **print_helpers.cpp**
Functions:
- `print1D(arr, name)` - Print 1D vector
- `print2D(mat, name)` - Print 2D matrix
- `printMap(m, name)` - Print map
- `printSet(s, name)` - Print set
- `printPair(p, name)` - Print pair
- `printGraph(adj, name)` - Print adjacency list
- `printTree(root)` - Print tree level-wise
- `printSeparator()`, `printHeader(text)` - Formatting

**Use for:** Pretty printing data structures, visualizing outputs

---

### 04_Testing/

#### **input_generator.cpp**
Functions to generate:
- Random integers in range
- Random arrays (sorted/unsorted)
- Random strings
- Random graphs (directed/undirected)
- Random trees
- Edge cases (empty, single element, max size)

**Use for:** Stress testing, generating test cases, corner case testing

---

#### **test_runner.sh**
Bash script features:
- Run solution against multiple test files
- Compare output with expected results
- Measure execution time
- Generate test reports
- Color-coded pass/fail results

**Use for:** Automated testing, regression testing, time analysis

---

## 💡 How to Use

### Method 1: Copy Template to Your Solution
```cpp
// Copy template.cpp content to your solution file
// Modify the solve() function with your logic
```

### Method 2: Include as Header (if in same directory)
```cpp
#include "02_Utils/math_utils.cpp"

int main() {
    cout << gcd(12, 18) << endl;  // Use utility function
    return 0;
}
```

### Method 3: Copy Specific Functions
```cpp
// Copy only the functions you need from utils
// Paste them directly into your solution file
```

---

## 🎯 Best Practices

1. **For Contests**: Copy the entire `template.cpp` as your starting point
2. **For Practice**: Use specific templates based on problem type
3. **For Debugging**: Include `debug.cpp` during development, remove before submission
4. **For Testing**: Use `input_generator.cpp` to create stress tests
5. **Keep Updated**: Add new patterns and utilities as you learn them

---

## 📝 Notes

- All templates use `#include <bits/stdc++.h>` for convenience
- Fast I/O is included in competitive templates
- Constants like MOD and INF are pre-defined
- Functions use `const` references where applicable for efficiency
- Debug macros are disabled with `ONLINE_JUDGE` flag

---

## 🔗 Related Folders

- Use **01_Theoretical_Concepts/** for algorithm explanations
- Use **02_Standard_Template_Library/** for STL reference
- Practice problems are in respective topic folders

---

**Happy Coding! 🚀**