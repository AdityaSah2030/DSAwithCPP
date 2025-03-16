# Stack

## Overview
A stack is a container adapter in the C++ STL that provides a LIFO (Last-In-First-Out) data structure. Unlike sequence containers (vector, list, deque), stack is an adapter that uses an underlying container to store its elements, providing a specific interface optimized for stack operations.

## Behavior and Characteristics

- **LIFO Principle**: Last element added is the first one to be removed
- **Restricted Access**: Elements can only be added/removed from the top of the stack
- **Adapter Design**: Not a standalone container, but an interface that adapts another container
- **No Iterators**: Does not provide iterators for traversal
- **No Direct Element Access**: No way to access elements other than the top element

## Implementation Details

### Under the Hood
- Stack is implemented as a container adapter that uses another container as its underlying storage
- By default, it uses `std::deque`, but can also be implemented using `std::vector` or `std::list`
- The adapter provides a simplified interface focused on stack operations

### Template Definition
```cpp
template <class T, class Container = std::deque<T>>
class stack;
```

Where:
- `T` is the type of elements
- `Container` is the type of the underlying container (defaults to `std::deque<T>`)

## Comparison with Similar Containers

### Stack vs Queue
- **Stack** follows LIFO (Last-In-First-Out)
- **Queue** follows FIFO (First-In-First-Out)
- Both are container adapters that restrict access to their elements

### Stack vs Priority Queue
- **Stack** always accesses the most recently added element
- **Priority Queue** always accesses the highest priority element (determined by comparison function)
- Both provide restricted access, but priority queue reorders elements based on priority

### Stack vs Vector (when used as a stack)
- **Stack** provides a cleaner interface specific to stack operations
- **Vector** used as a stack (with `push_back`/`pop_back`) provides more flexibility but allows operations that could violate stack semantics
- Performance is identical when vector is the underlying container

## Time Complexities

| Operation | Time Complexity | Notes |
|-----------|-----------------|-------|
| `push()` | Same as underlying container's `push_back()` | O(1) amortized when using vector or deque |
| `pop()` | Same as underlying container's `pop_back()` | O(1) with any standard underlying container |
| `top()` | Same as underlying container's `back()` | O(1) with any standard underlying container |
| `size()` | O(1) | Returns number of elements |
| `empty()` | O(1) | Checks if stack is empty |
| `emplace()` | Same as underlying container's `emplace_back()` | O(1) amortized, constructs element in-place |
| `swap()` | O(1) or O(n) | O(1) if using reference semantics, O(n) if copying elements |

## Key Functions and Usage

### Construction
```cpp
// Default constructor (uses deque)
std::stack<int> s1;

// Using a specific container type
std::stack<int, std::vector<int>> s2;

// Copy constructor
std::stack<int> s3(s1);

// From an existing container
std::vector<int> v = {1, 2, 3};
std::stack<int, std::vector<int>> s4(v);
```

### Basic Operations
```cpp
s.push(10);        // Add element to top
s.emplace(20);     // Construct element in-place at top
s.pop();           // Remove top element (void return)
s.top();           // Access top element
s.size();          // Get number of elements
s.empty();         // Check if stack is empty
s.swap(other_s);   // Swap contents with another stack
```

### Using Different Underlying Containers
```cpp
// Using vector as underlying container
std::stack<int, std::vector<int>> stack_vector;

// Using list as underlying container
std::stack<int, std::list<int>> stack_list;

// Using default (deque)
std::stack<int> stack_deque;
```

## Best Practices and Optimization Tips

1. **Check Before Pop**:
   - Always check if the stack is not empty before calling `pop()` or `top()`
   - Neither function performs bounds checking, leading to undefined behavior if the stack is empty

2. **Choose the Right Underlying Container**:
   - Use the default `std::deque` for most cases
   - Consider `std::vector` if memory usage is a concern and you won't have large stacks
   - Use `std::list` only if you need stable references to elements

3. **Use `emplace()` for Complex Objects**:
   - `emplace()` constructs the element in-place, avoiding temporary object creation
   - More efficient than `push()` for non-trivial types

4. **Consider Custom Allocators**:
   - If managing many small stacks, a custom allocator can improve performance
   - Pass the allocator to the underlying container

5. **No Need to Clear**:
   - Unlike some containers, there is no `clear()` method
   - To clear a stack, pop all elements or swap with an empty stack

## Common Use Cases

- **Function Call Management**: Track function calls in recursive algorithms
- **Expression Evaluation**: Parsing and evaluating expressions (e.g., infix to postfix conversion)
- **Backtracking Algorithms**: Storing states that need to be restored in reverse order
- **Undo Functionality**: Maintaining a history of operations that can be undone in reverse order
- **Depth-First Search**: Tracking nodes to visit in graph algorithms
- **Syntax Parsing**: Validating expressions with matching delimiters (e.g., brackets, parentheses)

## Custom Stack Implementation Example

While you'll typically use the STL stack, here's a simple illustration of how a stack might be implemented using a vector:

```cpp
template <typename T>
class SimpleStack {
private:
    std::vector<T> data;

public:
    void push(const T& value) {
        data.push_back(value);
    }
    
    void pop() {
        if (!empty()) {
            data.pop_back();
        }
    }
    
    T& top() {
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

- **No Iterator Support**: Cannot traverse all elements
- **No Direct Access**: Elements other than top cannot be accessed
- **Void Return on Pop**: Unlike some other language implementations, `pop()` doesn't return the removed element
- **No `clear()` Method**: Must pop elements individually or swap with empty stack
