# Queue

## Overview
A queue is a container adapter in the C++ STL that provides a FIFO (First-In-First-Out) data structure. Similar to stack, queue is not a standalone container but an adapter that uses an underlying container (by default `std::deque`) to store elements. It provides a restricted interface optimized for queue operations, where elements are inserted at one end and removed from the other.

## Behavior and Characteristics

- **FIFO Principle**: First element added is the first one to be removed
- **Restricted Access**: Elements can only be added at the back and removed from the front
- **Adapter Design**: Not a standalone container, but an interface that adapts another container
- **No Iterators**: Does not provide iterators for traversal
- **No Direct Element Access**: No random access to elements except front and back

## Implementation Details

### Under the Hood
- Implemented as a container adapter that uses another container as its underlying storage
- By default, it uses `std::deque`, but can also be implemented using `std::list`
- Cannot use `std::vector` as an underlying container since it doesn't efficiently support `pop_front()`
- Provides a simplified interface that maps to specific operations of the underlying container

### Template Definition
```cpp
template <class T, class Container = std::deque<T>>
class queue;
```

Where:
- `T` is the type of elements
- `Container` is the type of the underlying container (defaults to `std::deque<T>`)

## Comparison with Similar Containers

### Queue vs Stack
- **Queue** follows FIFO (First-In-First-Out)
- **Stack** follows LIFO (Last-In-First-Out)
- Both are container adapters with restricted access patterns
- Both typically use `std::deque` as their default underlying container

### Queue vs Deque
- **Queue** provides a restricted interface for FIFO operations
- **Deque** (double-ended queue) allows insertion and removal at both ends plus random access
- Deque is more flexible but doesn't enforce FIFO semantics
- Queue uses deque by default as its underlying container

### Queue vs Priority Queue
- **Queue** processes elements in insertion order (FIFO)
- **Priority Queue** processes elements based on priority (determined by comparison function)
- Both are container adapters but with different ordering semantics
- Priority queue uses a heap implementation, typically backed by `std::vector`

## Time Complexities

| Operation | Time Complexity | Notes |
|-----------|-----------------|-------|
| `push()` | Same as underlying container's `push_back()` | O(1) with deque or list |
| `pop()` | Same as underlying container's `pop_front()` | O(1) with deque or list |
| `front()` | Same as underlying container's `front()` | O(1) with any standard underlying container |
| `back()` | Same as underlying container's `back()` | O(1) with any standard underlying container |
| `size()` | O(1) | Returns number of elements |
| `empty()` | O(1) | Checks if queue is empty |
| `emplace()` | Same as underlying container's `emplace_back()` | O(1) with deque or list |
| `swap()` | O(1) or O(n) | O(1) if using reference semantics, O(n) if copying elements |

## Key Functions and Usage

### Construction
```cpp
// Default constructor (uses deque)
std::queue<int> q1;

// Using a specific container type
std::queue<int, std::list<int>> q2;

// Copy constructor
std::queue<int> q3(q1);

// From an existing container
std::deque<int> d = {1, 2, 3};
std::queue<int> q4(d);
```

### Basic Operations
```cpp
q.push(10);        // Add element to back
q.emplace(20);     // Construct element in-place at back
q.pop();           // Remove front element (void return)
q.front();         // Access front element
q.back();          // Access back element
q.size();          // Get number of elements
q.empty();         // Check if queue is empty
q.swap(other_q);   // Swap contents with another queue
```

### Using Different Underlying Containers
```cpp
// Using list as underlying container
std::queue<int, std::list<int>> queue_list;

// Using default (deque)
std::queue<int> queue_deque;

// Cannot use vector (no push_front/pop_front support)
// std::queue<int, std::vector<int>> queue_vector; // ERROR
```

## Best Practices and Optimization Tips

1. **Check Before Access and Pop**:
   - Always check if the queue is not empty before calling `pop()`, `front()`, or `back()`
   - These functions don't perform bounds checking, leading to undefined behavior if the queue is empty
   ```cpp
   if (!q.empty()) {
       int value = q.front();
       q.pop();
   }
   ```

2. **Choose the Right Underlying Container**:
   - Use the default `std::deque` for most cases
   - Consider `std::list` only if you need stable references to elements or have specific requirements
   - Remember that `std::vector` cannot be used as it lacks efficient `pop_front()`

3. **Use `emplace()` for Complex Objects**:
   - `emplace()` constructs the element in-place, avoiding temporary object creation
   - More efficient than `push()` for non-trivial types
   ```cpp
   std::queue<std::string> q;
   q.emplace("Hello");  // Constructs string in-place
   ```

4. **No Combined Front-and-Pop Operation**:
   - Unlike some other language implementations, there's no function that both returns and removes the front element
   - You need to manually call `front()` followed by `pop()`
   - Consider creating a helper function if you need this operation frequently
   ```cpp
   template <typename T, typename Container>
   T pop_and_return(std::queue<T, Container>& q) {
       T value = q.front();
       q.pop();
       return value;
   }
   ```

5. **Use Queue for FIFO Semantics Only**:
   - If you need more complex operations, consider using a deque directly
   - Queue provides a cleaner interface when you only need FIFO behavior

## Common Use Cases

- **Task Scheduling**: Processing tasks in the order they were received
- **Breadth-First Search**: Exploring nodes in level order in graph algorithms
- **Buffering**: Managing data flow between processes running at different rates
- **Print Spooling**: Managing print jobs in the order received
- **Event Handling**: Processing events in the order they occur
- **Resource Pooling**: Managing shared resources in a fair, first-come-first-served manner
- **Message Queues**: Implementing communication between threads or processes

## Custom Queue Implementation Example

While you'll typically use the STL queue, here's a simple illustration of how a queue might be implemented using a deque:

```cpp
template <typename T>
class SimpleQueue {
private:
    std::deque<T> data;

public:
    void push(const T& value) {
        data.push_back(value);
    }
    
    void pop() {
        if (!empty()) {
            data.pop_front();
        }
    }
    
    T& front() {
        return data.front();
    }
    
    T& back() {
        return data.back();
    }
    
    bool empty() const {
        return data.empty();
    }
    
    size_t size() const {
        return data.size();
    }
};
```

## Limitations

- **No Iterators**: Cannot traverse or access arbitrary elements
- **No Direct Access**: Elements other than front and back cannot be accessed
- **Void Return on Pop**: Does not return the removed element when calling `pop()`
- **No `clear()` Method**: Must pop elements individually or swap with an empty queue
- **Limited Functionality**: By design, provides only the minimal interface for FIFO operations
