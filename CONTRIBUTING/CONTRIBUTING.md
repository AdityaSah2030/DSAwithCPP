# Contributing Guidelines

Thank you for contributing. To maintain consistency and quality, follow the rules below.

---

## 1. Folder Structure

Place files strictly inside the correct topic folder:

- 01_Theoretical_Concepts
- 02_Standard_Template_Library
- 03_Arrays
- 04_Sorting_and_Search
- 05_Strings
- 06_Linked_List
- 07_Recursion
- 08_Bit_Manipulation
- 09_Stacks_and_Queues
- 10_Sliding_Window_and_Two_Pointers
- 11_Heaps
- 12_Greedy_Algorithms
- 13_Binary_Trees
- 14_Binary_Search_Trees
- 15_Graphs
- 16_Dynamic_Programming
- 17_Tries
- 18_Advanced_Strings
- 99_Templates_and_Utils

Inside each topic:

```
<topic>/
  01_Lec_Notes/
  02_Problems/
    Easy/
    Medium/
    Hard/
  03_Solutions/
  04_Extras/
```

---

## 2. File Naming Rules

**Problem file format:**

```
NN_problem-name.ext
```

Examples:

```
001_two-sum.cpp
014_longest-common-prefix.py
027_merge-intervals.cpp
```

Rules:
- Use numbers with leading zeroes (001, 002, 003…)
- Use lowercase names
- Use hyphens, not spaces or underscores
- Use the same filename in `02_Problems/` and `03_Solutions/`

---

## 3. Code Style

### Mandatory in every solution file:

Add a header comment:

```cpp
// Problem: Two Sum
// Difficulty: Easy
// Link: https://leetcode.com/problems/two-sum/
// Time Complexity: O(n)
// Space Complexity: O(n)
```

### Clean and readable code:

- No unnecessary prints
- No unused variables
- Always mention time and space complexity
- Add short explanation for tricky logic

---

## 4. Commit Message Format

Follow this exact structure:

```
[Topic] Added <problem-name> (NN)
```

Examples:

```
[Arrays] Added two-sum (001)
[Binary Trees] Added inorder-traversal (003)
[DP] Added longest-increasing-subsequence (014)
```

---

## 5. Pull Request Rules

Your PR must include:

1. **What problem you solved**
2. **Which folder it belongs to**
3. **Time & space complexity**
4. **Link to the problem**

Example PR message:

```
Added problem 001 - two-sum under 03_Arrays.
Included solution with O(n) complexity and explanation.
Problem link: https://leetcode.com/problems/two-sum/
```

---

## 6. Do Not Add

- Duplicate solutions
- Poorly structured files
- Files outside the folder structure
- Code without complexity analysis
- Unnamed or unnumbered problems

---

## 7. Templates

If needed, use the template from:

```
99_Templates_and_Utils/CODE_TEMPLATE.cpp
```

---

## 8. Language Support

Allowed languages:

- C++
- Python

Use consistent extensions:

```
.cpp  for C++
.py   for Python
```

---

## 9. Branch Naming

```
topic/problem-name
```

Examples:

```
arrays/two-sum
graphs/bfs
dp/longest-palindromic-subsequence
```

---

## 10. Final Note

Stick to the numbering, folder structure, and naming rules.
This keeps the repo clean, professional, and easy to navigate.