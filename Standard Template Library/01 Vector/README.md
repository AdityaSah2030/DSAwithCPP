# Vector

## Overview
A vector is a sequence container that represents a dynamic array, allowing for efficient random access and automatic resizing when elements are inserted or removed. It is one of the most versatile and commonly used containers in the C++ Standard Template Library (STL).

## Behavior and Characteristics

- **Dynamic Size**: Vectors can grow or shrink at runtime, automatically managing memory allocation.
- **Contiguous Memory**: Elements are stored in contiguous memory locations, allowing for efficient random access.
- **Automatic Reallocation**: When a vector needs to grow beyond its current capacity, it allocates a new, larger block of memory, copies/moves existing elements, and deallocates the old memory.
- **End-Focused Operations**: Most efficient for adding and removing elements at the end.

## Implementation Details

### Under the Hood
- Implemented as a dynamic array that manages three pointers:
  - `_start`: Points to the beginning of the allocated memory
  - `_finish`: Points to one past the last constructed element
  - `_end_of_storage`: Points to one past the last allocated memory slot

### Memory Management
- **Capacity vs Size**: 
  - `size` is the number of elements currently in the vector
  - `capacity` is the total number of elements the vector can hold before reallocation
- **Growth Strategy**:
  - When capacity is reached, most implementations double the capacity (growth factor of 2)
  - This amortizes the cost of reallocation over time, resulting in O(1) amortized time complexity for `push_back`

## Comparison with Similar Containers

### Vector vs Array
- **Arrays** have fixed size, while **vectors** can dynamically resize
- Both provide O(1) random access
- Arrays have no overhead, while vectors require additional memory for capacity management

### Vector vs Deque
- Both allow O(1) random access
- **Deque** (double-ended queue) allows efficient insertion/deletion at both ends, while **vector** is efficient only at the end
- Deque's memory isn't contiguous, making some operations slower and pointer arithmetic unsafe
- Vector typically provides better cache locality due to contiguous memory

### Vector vs List
- **List** is implemented as a doubly linked list
- Vector has O(1) random access, while list has O(n) access
- List provides O(1) insertion/deletion anywhere with valid iterators
- Vector requires element shifts for insertion/deletion, potentially resulting in O(n) operations

## Time Complexities

| Operation | Time Complexity | Notes |
|-----------|-----------------|-------|
| Random access (`operator[]`, `at()`) | O(1) | Constant time regardless of vector size |
| `push_back()` | O(1) amortized | May trigger reallocation (O(n)) but happens infrequently |
| `pop_back()` | O(1) | Removing from the end |
| `insert()` | O(n) | Elements after insertion point must be shifted |
| `erase()` | O(n) | Elements after erasure point must be shifted |
| `front()`, `back()` | O(1) | Accessing first or last element |
| `size()`, `capacity()` | O(1) | Getting current size or capacity |
| `empty()` | O(1) | Checking if vector is empty |
| `clear()` | O(n) | Destroying all elements |
| `reserve()` | O(n) | Allocating memory without constructing elements |
| `resize()` | O(n) | May construct or destroy elements |
| `emplace_back()` | O(1) amortized | In-place construction at the end |
| Iterator operations | O(1) | Moving to next/previous element |

## Key Functions and Usage

### Construction and Sizing
```cpp
std::vector<int> vec;              // Empty vector
std::vector<int> vec(10);          // Vector with 10 elements initialized to 0
std::vector<int> vec(10, 5);       // Vector with 10 elements initialized to 5
std::vector<int> vec = {1, 2, 3};  // Vector with 3 elements using initializer list

vec.size();                        // Returns number of elements
vec.capacity();                    // Returns current capacity
vec.empty();                       // Checks if vector is empty
vec.reserve(100);                  // Reserves space for 100 elements
vec.resize(20);                    // Resizes to 20 elements
vec.shrink_to_fit();               // Reduces capacity to fit size
```

### Element Access
```cpp
vec[0];                // Access first element (no bounds checking)
vec.at(0);             // Access first element (with bounds checking)
vec.front();           // Access first element
vec.back();            // Access last element
vec.data();            // Get pointer to underlying array
```

### Modifiers
```cpp
vec.push_back(10);     // Add element to end
vec.emplace_back(10);  // Construct element in-place at end
vec.pop_back();        // Remove last element
vec.insert(pos, val);  // Insert at iterator position
vec.emplace(pos, args);// Construct in-place at iterator position
vec.erase(pos);        // Remove element at iterator position
vec.clear();           // Remove all elements
```

### Iterators
```cpp
vec.begin();           // Iterator to first element
vec.end();             // Iterator to one past last element
vec.rbegin();          // Reverse iterator to last element
vec.rend();            // Reverse iterator to one before first element
```

## Best Practices and Optimization Tips

1. **Reserve Memory**:
   - Use `reserve()` when you know approximately how many elements you'll need to avoid repeated reallocations
   
2. **Prefer `emplace_back()` Over `push_back()`**:
   - For complex objects, `emplace_back()` constructs the object in-place, avoiding temporary object creation

3. **Prefer Range-Based Insertion**:
   - Use range-based versions of `insert()` when adding multiple elements to minimize reallocation overhead

4. **Be Careful with Iterators**:
   - Iterators, pointers, and references can be invalidated when vector resizes
   
5. **Use `shrink_to_fit()` Strategically**:
   - Call after large reduction in size to free unused memory, but be aware it may cause reallocation

6. **Consider `std::vector<bool>` Specialization**:
   - Optimized for space, but behaves differently from other vectors (bit-level storage)

## Common Use Cases

- **Dynamic Collections**: When the number of elements is not known at compile time
- **Stack Implementation**: Using `push_back()` and `pop_back()`
- **Buffer Management**: For efficient memory management of variable-sized data
- **Algorithm Input**: Many STL algorithms work efficiently with vectors due to random access iterators
- **Performance-Critical Applications**: Where memory locality and cache performance are important
