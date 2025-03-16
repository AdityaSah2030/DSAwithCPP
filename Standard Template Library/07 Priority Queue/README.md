# Priority Queue

## Overview
A priority queue is a container adapter in the C++ STL that provides a queue with priority-based ordering. Unlike a regular queue which follows FIFO (First-In-First-Out), a priority queue always provides access to the highest priority element (by default, the largest element according to the specified comparison function). It is commonly implemented as a heap data structure.

## Behavior and Characteristics

- **Priority Ordering**: Elements are ordered according to their priority
- **Top Access**: Only the highest priority element can be accessed directly
- **Implicit Heap Structure**: Typically implemented as a max heap by default
- **Adapter Design**: Not a standalone container, but an interface that adapts another container
- **No Iterators**: Does not provide iterators for traversal
- **No Direct Element Access**: No access to elements other than the top (highest priority) element

## Implementation Details

### Under the Hood
- Implemented as a container adapter using a binary heap data structure
- By default, uses `std::vector` as the underlying container
- Uses `std::less<T>` by default as the comparison function (creating a max heap)
- Maintains the heap property after each insertion and removal
- The heap is not sorted, but organized to allow O(1) access to the highest priority element

### Template Definition
```cpp
template <
    class T,
    class Container = std::vector<T>,
    class Compare = std::less<typename Container::value_type>
> class priority_queue;
```

Where:
- `T` is the type of elements
- `Container` is the type of the underlying container (defaults to `std::vector<T>`)
- `Compare` is the comparison function type (defaults to `std::less<T>`)

## Comparison with Similar Containers

### Priority Queue vs Queue
- **Priority Queue** processes elements based on priority
- **Queue** processes elements in insertion order (FIFO)
- Both are container adapters with restricted access patterns
- Priority queue typically uses `std::vector` while queue uses `std::deque` by default

### Priority Queue vs Set
- **Priority Queue** provides O(1) access to highest priority element, but no direct access to other elements
- **Set** provides O(log n) access to any element and maintains full sorting
- Priority queue is more efficient for just accessing the highest priority element
- Set allows iteration through all elements in sorted order

### Priority Queue vs Heap Algorithms
- **Priority Queue** is a container adapter providing a higher-level interface
- **Heap algorithms** (`std::make_heap`, `std::push_heap`, etc.) operate on any random access container
- Both use the same underlying heap mechanics
- Heap algorithms provide more flexibility but require more manual management

## Time Complexities

| Operation | Time Complexity | Notes |
|-----------|-----------------|-------|
| `push()`, `emplace()` | O(log n) | Insertion maintains heap property |
| `pop()` | O(log n) | Removal and reheapification |
| `top()` | O(1) | Access to highest priority element |
| `size()` | O(1) | Returns number of elements |
| `empty()` | O(1) | Checks if priority queue is empty |
| `swap()` | O(1) | Swaps internal pointers |

## Key Functions and Usage

### Construction
```cpp
// Default constructor (max heap)
std::priority_queue<int> pq1;

// With custom comparison (min heap)
std::priority_queue<int, std::vector<int>, std::greater<int>> pq2;

// From a range of elements
std::vector<int> v = {3, 1, 4, 1, 5, 9};
std::priority_queue<int> pq3(v.begin(), v.end());

// Copy constructor
std::priority_queue<int> pq4(pq1);

// Using a custom comparator class
struct CompareCustom {
    bool operator()(const int& a, const int& b) {
        return a % 10 < b % 10;  // Compare by last digit
    }
};
std::priority_queue<int, std::vector<int>, CompareCustom> pq5;
```

### Basic Operations
```cpp
pq.push(10);        // Add element
pq.emplace(20);     // Construct element in-place
pq.pop();           // Remove highest priority element (void return)
pq.top();           // Access highest priority element
pq.size();          // Get number of elements
pq.empty();         // Check if priority queue is empty
pq.swap(other_pq);  // Swap contents with another priority queue
```

### Creating Min Heap vs Max Heap
```cpp
// Max heap (default)
std::priority_queue<int> max_heap;  // Largest element at top

// Min heap (using greater comparison)
std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;  // Smallest element at top
```

### Using with Custom Types
```cpp
struct Task {
    int priority;
    std::string name;
    
    // For direct comparison of Task objects
    bool operator<(const Task& other) const {
        return priority < other.priority;  // Note: Lower numeric value means higher priority here
    }
};

// Option 1: Using built-in operator<
std::priority_queue<Task> task_queue;

// Option 2: Using custom comparator
struct TaskCompare {
    bool operator()(const Task& a, const Task& b) const {
        return a.priority > b.priority;  // Reverse order: lower value = higher priority
    }
};
std::priority_queue<Task, std::vector<Task>, TaskCompare> task_queue2;
```

## Best Practices and Optimization Tips

1. **Check Before Access and Pop**:
   - Always check if the priority queue is not empty before calling `pop()` or `top()`
   - These functions don't perform bounds checking, leading to undefined behavior if the queue is empty
   ```cpp
   if (!pq.empty()) {
       int highest = pq.top();
       pq.pop();
   }
   ```

2. **Choose the Right Comparison Function**:
   - Use `std::less<T>` (default) for max heap (largest element at top)
   - Use `std::greater<T>` for min heap (smallest element at top)
   - Create custom comparators for complex priority logic
   ```cpp
   // Custom comparator using lambda
   auto cmp = [](const auto& a, const auto& b) { return a.value > b.value; };
   std::priority_queue<MyType, std::vector<MyType>, decltype(cmp)> pq(cmp);
   ```

3. **Use `emplace()` for Complex Objects**:
   - `emplace()` constructs the element in-place, avoiding temporary object creation
   - More efficient than `push()` for non-trivial types
   ```cpp
   std::priority_queue<std::pair<int, std::string>> pq;
   pq.emplace(5, "Five");  // Constructs pair in-place
   ```

4. **Preallocate Capacity for Large Queues**:
   - If you know approximately how many elements you'll need, initialize the underlying container with that capacity
   ```cpp
   std::vector<int> v;
   v.reserve(1000);
   std::priority_queue<int> pq(std::less<int>(), std::move(v));
   ```

5. **No Combined Top-and-Pop Operation**:
   - Unlike some other language implementations, there's no function that both returns and removes the top element
   - You need to manually call `top()` followed by `pop()`
   ```cpp
   template <typename T, typename Container, typename Compare>
   T pop_and_return(std::priority_queue<T, Container, Compare>& pq) {
       T value = pq.top();
       pq.pop();
       return value;
   }
   ```

6. **Consider Heap Algorithms for More Control**:
   - If you need more flexibility, consider using the heap algorithms directly with a vector
   ```cpp
   std::vector<int> v = {3, 1, 4, 1, 5, 9};
   std::make_heap(v.begin(), v.end());
   // Now v is a heap and you can use push_heap, pop_heap, etc.
   ```

## Common Use Cases

- **Task Scheduling**: Managing tasks based on priority levels
- **Event-Driven Simulation**: Processing events in order of their time of occurrence
- **Dijkstra's Algorithm**: Finding shortest paths in a graph
- **Huffman Coding**: Building optimal prefix trees
- **Median Maintenance**: Efficiently finding the median of a stream of numbers (using two priority queues)
- **K Largest/Smallest Elements**: Efficiently finding top k elements in a large dataset
- **Bandwidth Management**: Allocating resources based on priority

## Implementation of a Min Heap Priority Queue

A min heap priority queue can be created using `std::greater` as the comparison function:

```cpp
#include <iostream>
#include <queue>
#include <vector>

int main() {
    // Define a min heap
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    
    // Add elements
    min_heap.push(30);
    min_heap.push(10);
    min_heap.push(20);
    min_heap.push(5);
    min_heap.push(1);
    
    // Process elements in priority order (smallest first)
    while (!min_heap.empty()) {
        std::cout << min_heap.top() << " ";
        min_heap.pop();
    }
    // Output: 1 5 10 20 30
    
    return 0;
}
```

## Advanced Example: Using Priority Queue with Custom Types

```cpp
#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct Process {
    int pid;
    int priority;
    std::string name;
    
    // Constructor for convenience
    Process(int p, int pr, std::string n) : pid(p), priority(pr), name(n) {}
};

// Custom comparator for Process
struct ProcessCompare {
    bool operator()(const Process& a, const Process& b) const {
        // Higher priority value means higher process priority
        return a.priority < b.priority;
    }
};

int main() {
    // Create a priority queue of processes
    std::priority_queue<Process, std::vector<Process>, ProcessCompare> process_queue;
    
    // Add processes
    process_queue.emplace(1001, 10, "System");
    process_queue.emplace(1002, 5, "User App");
    process_queue.emplace(1003, 8, "Database");
    process_queue.emplace(1004, 3, "Background Task");
    process_queue.emplace(1005, 15, "Critical Service");
    
    // Process in priority order
    std::cout << "Processing in priority order:\n";
    while (!process_queue.empty()) {
        const Process& p = process_queue.top();
        std::cout << "Process: " << p.name << " (PID: " << p.pid 
                  << ", Priority: " << p.priority << ")\n";
        process_queue.pop();
    }
    
    return 0;
}
```

## Limitations

- **No Iterators**: Cannot traverse or access elements in any order
- **No Direct Access**: Elements other than the top cannot be accessed
- **No Modification After Insertion**: Cannot update an element's priority after insertion
- **Void Return on Pop**: Does not return the removed element when calling `pop()`
- **No Search Functionality**: Cannot check if an element exists except by comparing with the top element
- **No Decrease/Increase Key Operation**: Cannot modify priority of existing elements (must remove and reinsert)
