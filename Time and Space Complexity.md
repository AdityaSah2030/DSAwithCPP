# Time and Space Complexity Analysis with Big O Notation

## Table of Contents
1. [Introduction](#introduction)
2. [Asymptotic Notation](#asymptotic-notation)
   - [Big O Notation](#big-o-notation)
   - [Other Notations: Theta and Omega](#other-notations-theta-and-omega)
3. [Common Time Complexities](#common-time-complexities)
   - [O(1) - Constant Time](#o1---constant-time)
   - [O(log n) - Logarithmic Time](#olog-n---logarithmic-time)
   - [O(n) - Linear Time](#on---linear-time)
   - [O(n log n) - Linearithmic Time](#on-log-n---linearithmic-time)
   - [O(n²) - Quadratic Time](#on²---quadratic-time)
   - [O(n³) - Cubic Time](#on³---cubic-time)
   - [O(2ⁿ) - Exponential Time](#o2ⁿ---exponential-time)
   - [O(n!) - Factorial Time](#on---factorial-time)
4. [Space Complexity](#space-complexity)
   - [Definition and Importance](#definition-and-importance)
   - [Common Space Complexities](#common-space-complexities)
   - [Relationship with Time Complexity](#relationship-with-time-complexity)
5. [Analysis Techniques](#analysis-techniques)
   - [Loop Analysis](#loop-analysis)
   - [Recursion Analysis](#recursion-analysis)
   - [Amortized Analysis](#amortized-analysis)
6. [Practical Considerations](#practical-considerations)
   - [Best, Average, and Worst Case](#best-average-and-worst-case)
   - [Upper and Lower Bounds](#upper-and-lower-bounds)
7. [Algorithm Comparison](#algorithm-comparison)
   - [Sorting Algorithms](#sorting-algorithms)
   - [Search Algorithms](#search-algorithms)
   - [Data Structure Operations](#data-structure-operations)
8. [Optimization Strategies](#optimization-strategies)
9. [Conclusion](#conclusion)

## Introduction

Computational complexity is a framework for analyzing algorithms based on the resources they require. The two primary resources are:

- **Time complexity**: How runtime grows as input size increases
- **Space complexity**: How memory usage grows as input size increases

Understanding complexity allows us to predict an algorithm's performance, compare alternative solutions, and identify potential bottlenecks before implementation.

## Asymptotic Notation

### Big O Notation

Big O notation describes the upper bound of an algorithm's growth rate, focusing on how it scales with increasing input rather than exact execution time.

**Formal Definition**: For functions f(n) and g(n), we say f(n) = O(g(n)) if there exist positive constants c and n₀ such that f(n) ≤ c·g(n) for all n ≥ n₀.

**Key Properties**:
- Ignores constant factors: O(2n) = O(n)
- Focuses on dominant terms: O(n² + n) = O(n²)
- Represents worst-case scenario
- Describes growth rate, not actual execution time

### Other Notations: Theta and Omega

While Big O represents the upper bound, other notations provide additional insights:

- **Theta (Θ) Notation**: Tight bound (both upper and lower)
  - f(n) = Θ(g(n)) if f(n) is bounded both above and below by g(n)
  
- **Omega (Ω) Notation**: Lower bound
  - f(n) = Ω(g(n)) if f(n) is bounded below by g(n)

## Common Time Complexities

### O(1) - Constant Time

**Characteristics**:
- Execution time is independent of input size
- Performance remains constant regardless of data quantity

**Examples**:
- Array element access by index
- Hash table insertion/lookup (amortized)
- Stack push/pop operations

**Code Example**:
```cpp
int getFirstElement(int arr[], int size) {
    if (size > 0) {
        return arr[0];
    } else {
        return -1; // Indicates empty array
    }
}
```

### O(log n) - Logarithmic Time

**Characteristics**:
- Runtime grows logarithmically with input size
- Common in algorithms that divide the problem in half each step

**Examples**:
- Binary search
- Balanced tree operations (insertion, deletion, search)
- Certain divide-and-conquer algorithms

**Code Example**:
```cpp
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1; // Target not found
}
```

### O(n) - Linear Time

**Characteristics**:
- Runtime grows linearly with input size
- Each input element requires a constant amount of processing

**Examples**:
- Array traversal
- Linear search
- Finding minimum/maximum in an unsorted array

**Code Example**:
```cpp
int findMaximum(int arr[], int size) {
    if (size <= 0) {
        return -1; // Error: empty array
    }
    
    int maxValue = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }
    
    return maxValue;
}
```

### O(n log n) - Linearithmic Time

**Characteristics**:
- More efficient than quadratic but less efficient than linear
- Common in efficient sorting algorithms

**Examples**:
- Merge sort
- Heap sort
- Quick sort (average case)

**Code Example** (Merge Sort):
```cpp
void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0, j = 0, k = 0;
    
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    
    // Copy remaining elements
    while (i < leftSize) {
        arr[k++] = left[i++];
    }
    
    while (j < rightSize) {
        arr[k++] = right[j++];
    }
}

void mergeSort(int arr[], int size) {
    if (size <= 1) {
        return;
    }
    
    int mid = size / 2;
    int leftSize = mid;
    int rightSize = size - mid;
    
    // Create left and right subarrays
    int left[leftSize];
    int right[rightSize];
    
    // Copy data to subarrays
    for (int i = 0; i < leftSize; i++) {
        left[i] = arr[i];
    }
    for (int i = 0; i < rightSize; i++) {
        right[i] = arr[mid + i];
    }
    
    // Recursively sort the subarrays
    mergeSort(left, leftSize);
    mergeSort(right, rightSize);
    
    // Merge the sorted subarrays
    merge(arr, left, leftSize, right, rightSize);
}
```

### O(n²) - Quadratic Time

**Characteristics**:
- Runtime grows with the square of input size
- Often involves nested iterations over the data

**Examples**:
- Bubble sort
- Selection sort
- Insertion sort
- Simple matrix multiplication

**Code Example**:
```cpp
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
```

### O(n³) - Cubic Time

**Characteristics**:
- Runtime grows with the cube of input size
- Often involves three nested loops

**Examples**:
- Naive matrix multiplication
- Certain dynamic programming solutions
- Floyd-Warshall algorithm for all-pairs shortest paths

**Code Example**:
```cpp
void naiveMatrixMultiply(int A[][100], int B[][100], int C[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
```

### O(2ⁿ) - Exponential Time

**Characteristics**:
- Runtime doubles with each additional input element
- Becomes impractical quickly as input size grows

**Examples**:
- Naive recursive Fibonacci
- The Tower of Hanoi
- Generating all subsets of a set

**Code Example**:
```cpp
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}
```

### O(n!) - Factorial Time

**Characteristics**:
- Among the slowest growing complexity classes
- Becomes impractical even for very small inputs

**Examples**:
- Brute force traveling salesman problem
- Generating all permutations of a set

**Code Example**:
```cpp
void generatePermutations(int arr[], int start, int end) {
    if (start == end) {
        // Print or process the current permutation
        for (int i = 0; i <= end; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }
    
    for (int i = start; i <= end; i++) {
        // Swap to create a new permutation
        int temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
        
        // Recursively generate permutations for remaining elements
        generatePermutations(arr, start + 1, end);
        
        // Backtrack (restore the array)
        temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
    }
}
```

## Space Complexity

### Definition and Importance

Space complexity measures the total amount of memory an algorithm needs relative to input size, including:

- **Auxiliary space**: Extra space used by the algorithm (excluding input)
- **Input space**: Space used to store the input

Space complexity is particularly important for:
- Memory-constrained environments
- Large datasets
- Systems where memory allocation is expensive

### Common Space Complexities

- **O(1) - Constant Space**:
  - Fixed amount of memory regardless of input size
  - Example: In-place sorting algorithms like insertion sort

- **O(log n) - Logarithmic Space**:
  - Memory usage grows logarithmically with input
  - Example: Binary tree traversal with recursion depth log(n)

- **O(n) - Linear Space**:
  - Memory usage grows linearly with input
  - Example: Creating a new array of the same size as input

- **O(n²) - Quadratic Space**:
  - Memory usage grows with the square of input size
  - Example: Adjacency matrix for graph representation

### Relationship with Time Complexity

- **Time-Space Tradeoff**: Often, reducing time complexity increases space complexity and vice versa
- **Example**: Hash tables offer O(1) average time complexity for lookups at the cost of O(n) space
- **Consideration**: The optimal solution depends on specific constraints and requirements

## Analysis Techniques

### Loop Analysis

1. **Simple loops**: If a loop runs from 1 to n, it's generally O(n)
   ```cpp
   for (int i = 0; i < n; i++) {
       // O(1) operations
   }
   // Total: O(n)
   ```

2. **Nested loops**: Multiply the complexities of each loop
   ```cpp
   for (int i = 0; i < n; i++) {
       for (int j = 0; j < n; j++) {
           // O(1) operations
       }
   }
   // Total: O(n²)
   ```

3. **Loops with variable bounds**:
   ```cpp
   for (int i = 0; i < n; i++) {
       for (int j = 0; j < i; j++) {
           // O(1) operations
       }
   }
   // Total: O(n²) (though actually n(n-1)/2 operations)
   ```

### Recursion Analysis

For recursive algorithms, the complexity depends on:
1. Number of times the function is called
2. Complexity of each function call

**Recurrence relations** help analyze recursive algorithms:

- **Example** (Binary search):
  - T(n) = T(n/2) + O(1)
  - Solution: T(n) = O(log n)

- **Example** (Merge sort):
  - T(n) = 2T(n/2) + O(n)
  - Solution: T(n) = O(n log n)

**Master Theorem** provides a systematic way to solve many recurrence relations.

### Amortized Analysis

Amortized analysis considers the average performance over a sequence of operations rather than focusing on individual worst-case scenarios.

**Example**: Dynamic array resizing
- Single resize operation: O(n)
- Series of n insertions: O(n) total for all resizing operations
- Amortized cost per insertion: O(1)

## Practical Considerations

### Best, Average, and Worst Case

Algorithms can have different complexities depending on the input:

- **Best Case**: Minimum time required (most favorable input)
- **Average Case**: Expected time with random input
- **Worst Case**: Maximum time required (least favorable input)

**Example** (Quick Sort):
- Best/Average case: O(n log n)
- Worst case: O(n²)

### Upper and Lower Bounds

- **Upper Bound** (Big O): Algorithm won't do worse than this
- **Tight Bound** (Theta): Algorithm performs exactly at this rate asymptotically
- **Lower Bound** (Omega): Algorithm won't do better than this

These bounds help establish the fundamental limits of algorithm performance.

## Algorithm Comparison

### Sorting Algorithms

| Algorithm     | Best Case   | Average Case | Worst Case  | Space Complexity |
|---------------|-------------|--------------|-------------|------------------|
| Bubble Sort   | O(n)        | O(n²)        | O(n²)       | O(1)             |
| Selection Sort| O(n²)       | O(n²)        | O(n²)       | O(1)             |
| Insertion Sort| O(n)        | O(n²)        | O(n²)       | O(1)             |
| Merge Sort    | O(n log n)  | O(n log n)   | O(n log n)  | O(n)             |
| Quick Sort    | O(n log n)  | O(n log n)   | O(n²)       | O(log n)         |
| Heap Sort     | O(n log n)  | O(n log n)   | O(n log n)  | O(1)             |
| Radix Sort    | O(nk)       | O(nk)        | O(nk)       | O(n+k)           |

### Search Algorithms

| Algorithm      | Best Case | Average Case | Worst Case | Space Complexity |
|----------------|-----------|--------------|------------|------------------|
| Linear Search  | O(1)      | O(n)         | O(n)       | O(1)             |
| Binary Search  | O(1)      | O(log n)     | O(log n)   | O(1)             |
| Hash Table     | O(1)      | O(1)         | O(n)       | O(n)             |
| BST Search     | O(1)      | O(log n)     | O(n)       | O(1)             |
| AVL Tree Search| O(1)      | O(log n)     | O(log n)   | O(1)             |

### Data Structure Operations

| Data Structure | Access    | Search    | Insertion | Deletion  | Space     |
|----------------|-----------|-----------|-----------|-----------|-----------|
| Array          | O(1)      | O(n)      | O(n)      | O(n)      | O(n)      |
| Linked List    | O(n)      | O(n)      | O(1)      | O(1)      | O(n)      |
| Hash Table     | N/A       | O(1) avg  | O(1) avg  | O(1) avg  | O(n)      |
| BST            | O(log n)* | O(log n)* | O(log n)* | O(log n)* | O(n)      |
| Heap           | O(1)**    | O(n)      | O(log n)  | O(log n)  | O(n)      |

\* For balanced trees; can degrade to O(n)
\** For min/max element only

## Optimization Strategies

1. **Algorithm Selection**: Choose algorithms with appropriate complexity for your constraints
   - For small datasets, constant factors may matter more than asymptotic complexity
   - For large datasets, choose algorithms with better asymptotic bounds

2. **Data Structure Selection**: Choose data structures that optimize critical operations
   - Example: Use hash tables for frequent lookups
   - Example: Use heaps for priority queue operations

3. **Space-Time Tradeoffs**: Consider caching or preprocessing
   - Example: Dynamic programming stores results to avoid recalculation
   - Example: Precomputing values can reduce runtime at the cost of memory

4. **Constant Factor Optimization**: After selecting the right algorithm
   - Optimize inner loops
   - Reduce function call overhead
   - Improve memory access patterns
   - Compiler optimizations

## Conclusion

Time and space complexity analysis with Big O notation provides a framework for understanding algorithm efficiency independent of implementation details or hardware. By analyzing how resource requirements scale with input size, we can make informed decisions about algorithm selection and design.

Key takeaways:
- Big O notation describes the upper bound growth rate
- Complexity analysis helps predict performance at scale
- Different problems have different inherent complexity requirements
- The most efficient algorithm depends on specific constraints and use cases

Understanding complexity enables you to:
1. Select appropriate algorithms for your specific needs
2. Predict performance bottlenecks before they occur
3. Make informed tradeoffs between time and space requirements
4. Communicate efficiently about algorithm performance
