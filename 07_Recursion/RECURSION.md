# Recursion: A Comprehensive Guide

## Table of Contents
1. [Introduction to Recursion](#introduction-to-recursion)
2. [Understanding the Call Stack](#understanding-the-call-stack)
3. [Base Case and Recursive Case](#base-case-and-recursive-case)
4. [Types of Recursion](#types-of-recursion)
   - [Direct vs Indirect Recursion](#direct-vs-indirect-recursion)
   - [Linear Recursion](#linear-recursion)
   - [Binary (or Tree) Recursion](#binary-or-tree-recursion)
   - [Tail Recursion](#tail-recursion)
5. [Mathematical Analysis of Recursion](#mathematical-analysis-of-recursion)
   - [Recurrence Relations](#recurrence-relations)
   - [Methods for Solving Recurrence Relations](#methods-for-solving-recurrence-relations)
   - [Recurrence Trees](#recurrence-trees)
   - [Master Theorem](#master-theorem)
6. [Time and Space Complexity Analysis](#time-and-space-complexity-analysis)
   - [Time Complexity](#time-complexity)
   - [Space Complexity](#space-complexity)
7. [Backtracking](#backtracking)
8. [Memoization and Dynamic Programming](#memoization-and-dynamic-programming)
9. [Best Practices and Optimization](#best-practices-and-optimization)
10. [When to Use (and Not Use) Recursion](#when-to-use-and-not-use-recursion)

## Introduction to Recursion

Recursion is a programming technique where a function calls itself in order to solve a problem. It's a powerful concept in computer science that allows for elegant solutions to certain types of problems, particularly those with self-similar structure.

In recursive algorithms, we divide a problem into smaller instances of the same problem until we reach a simple case that can be solved directly (known as the base case).

### Simple C++ Example: Factorial

```cpp
int factorial(int n) {
    // Base case
    if (n == 0 || n == 1) {
        return 1;
    }
    // Recursive case
    else {
        return n * factorial(n - 1);
    }
}
```

## Understanding the Call Stack

The call stack is a data structure that keeps track of function calls in a program. When a function is called, a new stack frame is created that contains:

1. The function's parameters and local variables
2. The return address (where to go after the function completes)
3. Other bookkeeping information

When a recursive function calls itself, a new stack frame is created for each call, which is why recursion can lead to stack overflow errors if the base case is never reached or if recursion is too deep.

### Call Stack Visualization for factorial(4)

```
Call 1: factorial(4)
  - n = 4
  - Create new stack frame
  - Call factorial(3)
  
    Call 2: factorial(3)
    - n = 3
    - Create new stack frame
    - Call factorial(2)
    
      Call 3: factorial(2)
      - n = 2
      - Create new stack frame
      - Call factorial(1)
      
        Call 4: factorial(1)
        - n = 1
        - Base case reached, return 1
        
      - Return from factorial(1) is 1
      - Calculate 2 * 1 = 2
      - Return 2
    
    - Return from factorial(2) is 2
    - Calculate 3 * 2 = 6
    - Return 6
  
  - Return from factorial(3) is 6
  - Calculate 4 * 6 = 24
  - Return 24

Result: 24
```

## Base Case and Recursive Case

Every recursive function must have:

1. **Base Case**: A condition that stops the recursion. Without it, the function would call itself indefinitely.
2. **Recursive Case**: A part where the function calls itself, usually with a modified parameter to progress toward the base case.

```cpp
void countdown(int n) {
    // Base case
    if (n <= 0) {
        std::cout << "Blastoff!" << std::endl;
        return;
    }
    
    // Process current value
    std::cout << n << std::endl;
    
    // Recursive case (getting closer to base case)
    countdown(n - 1);
}
```

## Types of Recursion

### Direct vs Indirect Recursion

- **Direct Recursion**: A function calls itself directly.
- **Indirect Recursion**: Function A calls function B, which in turn calls function A, forming a cycle.

### Linear Recursion

The function makes at most one recursive call each time it's invoked.

```cpp
int sum(int arr[], int n) {
    // Base case
    if (n <= 0) {
        return 0;
    }
    // Recursive case
    return arr[n-1] + sum(arr, n-1);
}
```

### Binary (or Tree) Recursion

The function makes two recursive calls each time it's invoked.

```cpp
int fibonacci(int n) {
    // Base cases
    if (n <= 0) return 0;
    if (n == 1) return 1;
    
    // Recursive case (two calls)
    return fibonacci(n-1) + fibonacci(n-2);
}
```

### Tail Recursion

A recursive call is the last operation in a function. Many compilers can optimize tail recursion into iteration.

```cpp
// Non-tail recursive factorial
int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n-1);  // Must do multiplication after recursive call returns
}

// Tail recursive factorial
int factorialTail(int n, int accumulator = 1) {
    if (n == 0) return accumulator;
    return factorialTail(n-1, n * accumulator);  // No pending operations after recursion
}
```

## Mathematical Analysis of Recursion

### Recurrence Relations

A recurrence relation is a mathematical equation that defines a sequence recursively, where the next term(s) of the sequence are defined as a function of the previous terms.

#### Formal Definition

A recurrence relation for the sequence {a_n} is an equation that expresses a_n in terms of previous terms of the sequence.

For example, the Fibonacci sequence can be defined by the recurrence relation:
- F(0) = 0 (base case)
- F(1) = 1 (base case)
- F(n) = F(n-1) + F(n-2) for n > 1 (recursive case)

#### Common Recurrence Relations in Algorithms

1. **Linear Recurrence Relations**:
   - Example: T(n) = T(n-1) + c
   - Solution: T(n) = T(1) + c(n-1) = O(n)

2. **Divide and Conquer Recurrence Relations**:
   - Binary Search: T(n) = T(n/2) + c
   - Merge Sort: T(n) = 2T(n/2) + cn
   - Quick Sort (average case): T(n) = 2T(n/2) + cn

3. **General Form**:
   - T(n) = aT(n/b) + f(n)
   - Where 'a' is the number of subproblems, 'b' is the factor by which the problem size is reduced, and f(n) is the work done at the current level.

### Methods for Solving Recurrence Relations

#### 1. Substitution Method

In this method, we guess a bound and then prove it using mathematical induction.

**Example**: T(n) = 2T(n/2) + n, T(1) = 1

1. Guess: T(n) = O(n log n)
2. Assume: T(k) ≤ c·k log k for all k < n
3. Prove: T(n) ≤ c·n log n
   ```
   T(n) = 2T(n/2) + n
   ≤ 2·c·(n/2)·log(n/2) + n
   = c·n·log(n/2) + n
   = c·n·(log n - log 2) + n
   = c·n·log n - c·n + n
   ≤ c·n·log n when c ≥ 1
   ```

#### 2. Recursion Tree Method

The recursion tree method visualizes the recurrence relation as a tree, where each node represents the cost of a single subproblem.

#### 3. Master Method

The Master Method provides a direct solution for recurrence relations of the form T(n) = aT(n/b) + f(n), where a ≥ 1 and b > 1.

### Recurrence Trees

A recurrence tree is a visual representation of a recurrence relation. Each node in the tree represents a function call, and the value in the node represents the amount of work done in that call (excluding recursive calls).

#### Example: T(n) = 2T(n/2) + n

```
             n
           /   \
         n/2   n/2
        /  \   /  \
     n/4  n/4 n/4 n/4
     / \  / \ / \  / \
    ... ... ... ... ...
```

At each level:
- Level 0: Work = n
- Level 1: Work = 2 × (n/2) = n
- Level 2: Work = 4 × (n/4) = n
- ...
- Level log n: Work = n

Total work = n × (log n + 1) = O(n log n)

#### Example: T(n) = T(n-1) + 1

```
              1
              |
              1
              |
              1
              |
             ...
              |
              1
```

Total work = n × 1 = O(n)

#### Example: Fibonacci: T(n) = T(n-1) + T(n-2) + 1

```
                    1
                /       \
               1         1
            /    \     /   \
           1      1   1     1
          / \    / \ / \   / \
         ... ... ... ... ... ...
```

This forms a binary tree where each level grows exponentially, resulting in O(2^n) time complexity.

### Master Theorem

The Master Theorem provides a method for solving recurrence relations of the form:

T(n) = aT(n/b) + f(n)

Where a ≥ 1, b > 1, and f(n) is an asymptotically positive function.

#### Three Cases:

1. **Case 1**: If f(n) = O(n^(log_b(a)-ε)) for some ε > 0, then T(n) = Θ(n^(log_b(a)))

2. **Case 2**: If f(n) = Θ(n^(log_b(a)) × log^k(n)) for k ≥ 0, then T(n) = Θ(n^(log_b(a)) × log^(k+1)(n))

3. **Case 3**: If f(n) = Ω(n^(log_b(a)+ε)) for some ε > 0, and if a × f(n/b) ≤ c × f(n) for some c < 1 and all sufficiently large n, then T(n) = Θ(f(n))

#### Examples:

1. **Binary Search**: T(n) = T(n/2) + 1
   - a = 1, b = 2, f(n) = 1
   - log_b(a) = log_2(1) = 0
   - f(n) = 1 = n^0
   - Case 2 applies: T(n) = Θ(log n)

2. **Merge Sort**: T(n) = 2T(n/2) + n
   - a = 2, b = 2, f(n) = n
   - log_b(a) = log_2(2) = 1
   - f(n) = n = n^1
   - Case 2 applies: T(n) = Θ(n log n)

3. **Strassen's Matrix Multiplication**: T(n) = 7T(n/2) + n^2
   - a = 7, b = 2, f(n) = n^2
   - log_b(a) = log_2(7) ≈ 2.81
   - f(n) = n^2 = O(n^(2.81-ε))
   - Case 1 applies: T(n) = Θ(n^(log_2(7))) ≈ Θ(n^2.81)

## Time and Space Complexity Analysis

### Time Complexity

#### Simple Formula
```
Time Complexity = Number of Recursive Calls × Work Done in Each Call
```

For example, in a simple linear recursion with n calls where each call does O(1) work:
```
T(n) = n × O(1) = O(n)
```

In binary recursion like Fibonacci, where each call branches into two more calls:
```
T(n) = 2^n × O(1) = O(2^n)
```

#### Mathematical Analysis Using Recurrence Relations

For recursive algorithms, the time complexity T(n) can be modeled as a recurrence relation:

1. **Linear Recursion** (e.g., factorial):
   - T(n) = T(n-1) + O(1)
   - Expanding: T(n) = T(n-2) + O(1) + O(1) = ... = T(1) + (n-1) × O(1) = O(n)

2. **Divide and Conquer** (e.g., binary search):
   - T(n) = T(n/2) + O(1)
   - Solution using Master Theorem: T(n) = O(log n)

3. **Multiple Recursion** (e.g., Fibonacci):
   - T(n) = T(n-1) + T(n-2) + O(1)
   - Forms a binary tree of calls, resulting in exponential complexity: O(2^n)

### Space Complexity

#### Simple Formula
```
Space Complexity = Maximum Depth of Recursion × Space Used in Each Call
```

For a simple linear recursion with depth n where each call uses O(1) space:
```
S(n) = n × O(1) = O(n)
```

#### Formal Analysis

The space complexity of a recursive algorithm includes:
1. Memory used by function parameters and local variables
2. Memory used by the call stack

For recursive functions, the space complexity is proportional to the maximum depth of the recursion:

```
S(n) = O(depth of recursion)
```

For a linear recursion (like factorial), the space complexity is O(n). For a binary recursion (like Merge Sort), the space complexity is O(log n) if only one branch is recursively explored at a time.

## Backtracking

Backtracking is a recursive technique for problems where we need to build a solution incrementally and abandon a partial solution ("backtrack") when we determine it cannot lead to a valid complete solution.

### General Approach:
1. Choose: Make a choice to explore a path
2. Explore: Recursively explore that path
3. Unchoose: If the path doesn't lead to a solution, undo the choice and try another

### Structure of a Backtracking Algorithm:

```cpp
void backtrack(state, choices) {
    if (isGoalReached(state)) {
        // Add solution to result
        return;
    }
    
    for (choice in choices) {
        if (isValid(state, choice)) {
            // Make choice
            applyChoice(state, choice);
            
            // Explore further
            backtrack(state, remainingChoices);
            
            // Undo choice (backtrack)
            undoChoice(state, choice);
        }
    }
}
```

## Memoization and Dynamic Programming

Memoization is a technique to optimize recursive solutions by storing previously computed results to avoid redundant calculations.

### Basic Approach:
1. Before computing a result, check if it's already computed
2. If yes, return the stored result
3. If no, compute it, store it, and then return it

```cpp
// Memoized function structure
Result solveProblem(Parameters params, HashMap<Parameters, Result> memo) {
    // Check if result is already in memo
    if (memo.contains(params)) {
        return memo.get(params);
    }
    
    // Base case
    if (isBaseCase(params)) {
        Result baseResult = solveBaseCase(params);
        memo.put(params, baseResult);
        return baseResult;
    }
    
    // Recursive case
    Result result = combineResults(solveProblem(reducedParams, memo));
    
    // Store result in memo
    memo.put(params, result);
    
    return result;
}
```

## Best Practices and Optimization

1. **Always define a proper base case**: Ensure that recursion will terminate.

2. **Avoid redundant calculations**: Use memoization or dynamic programming when subproblems overlap.

3. **Consider tail recursion**: Many compilers can optimize tail-recursive functions into iteration.

4. **Be mindful of stack limitations**: Deep recursion can cause stack overflow.

5. **Use recursion wisely**: Sometimes an iterative solution might be more efficient.

6. **Understand the problem structure**: Recursion works best for problems with self-similar structure.

7. **Consider space complexity**: Every recursive call adds a frame to the call stack.

## When to Use (and Not Use) Recursion

### Use Recursion When:
- The problem naturally breaks down into similar subproblems
- Tree-like data structures are involved (e.g., binary trees)
- The problem can be solved using divide-and-conquer
- Backtracking is necessary
- The solution is more elegant and readable with recursion

### Avoid Recursion When:
- Simple iteration can solve the problem
- The recursion depth could be very large
- Performance is critical (due to function call overhead)
- You're working with limited stack memory
- The problem doesn't naturally break down into self-similar subproblems