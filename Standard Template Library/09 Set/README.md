# Set

## Overview
A set is an associative container in the C++ STL that stores unique elements in a specific order (typically sorted). Sets automatically sort their elements according to a comparison function (by default `std::less<T>`), and guarantee uniqueness of all stored values. They are typically implemented as balanced binary search trees, most commonly red-black trees.

## Behavior and Characteristics

- **Unique Elements**: No duplicates allowed; inserting an existing value has no effect
- **Ordered Storage**: Elements are always sorted according to the comparison function
- **No Direct Modification**: Elements cannot be modified directly (they are immutable once inserted)
- **Fast Lookups**: Efficient search, insertion, and deletion operations
- **No Random Access**: Elements can only be accessed via iterators

## Implementation Details

### Under the Hood
- Typically implemented as a self-balancing binary search tree (most often a red-black tree)
- Each node in the tree contains a single key value
- The tree structure enables O(log n) search, insertion, and deletion operations
- Tree balancing ensures that the tree doesn't degenerate into a linked list, maintaining logarithmic time operations

### Template Definition
```cpp
template <
    class Key,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<Key>
> class set;
```

Where:
- `Key` is the type of elements stored
- `Compare` is the comparison function (defaults to `std::less<Key>`)
- `Allocator` is the allocator used (defaults to `std::allocator<Key>`)

## Comparison with Similar Containers

### Set vs Unordered Set
- **Set** keeps elements in sorted order with O(log n) operations
- **Unordered Set** uses a hash table with average O(1) operations but no guaranteed order
- Set provides consistent iteration order; unordered_set's iteration order can vary
- Set consumes less memory than unordered_set but has slower average access time

### Set vs Multiset
- **Set** allows only unique elements
- **Multiset** allows duplicate elements
- Both maintain sorting order
- Multiset's `count()` can return values greater than 1

### Set vs Map
- **Set** stores only keys
- **Map** stores key-value pairs
- Both maintain keys in sorted order
- In a set, the value itself is the key; in a map, each key has an associated value

## Time Complexities

| Operation | Time Complexity | Notes |
|-----------|-----------------|-------|
| Insertion (`insert()`, `emplace()`) | O(log n) | Includes search time to maintain order |
| Deletion (`erase()`) | O(log n) | Requires rebalancing the tree |
| Search (`find()`, `count()`) | O(log n) | Binary search tree property |
| `lower_bound()`, `upper_bound()` | O(log n) | Finding position in sorted sequence |
| `equal_range()` | O(log n) | Finding range of equivalent elements |
| Size operations (`size()`, `empty()`) | O(1) | Constant time |
| Traversal (iterating) | O(n) | Linear in container size |
| Clearing (`clear()`) | O(n) | Must destruct all elements |
| `swap()` | O(1) | Usually constant (swaps internal pointers) |

## Key Functions and Usage

### Construction and Initialization
```cpp
// Default constructor
std::set<int> s1;

// From initializer list
std::set<int> s2 = {1, 2, 3, 4, 5};

// With custom comparator
struct CustomCompare {
    bool operator()(const int& a, const int& b) const {
        return a > b; // Descending order
    }
};
std::set<int, CustomCompare> s3 = {1, 2, 3, 4, 5}; // Will be stored in descending order

// Iterator range constructor
std::vector<int> v = {5, 1, 3, 2, 4};
std::set<int> s4(v.begin(), v.end()); // Will be stored as {1, 2, 3, 4, 5}

// Copy constructor
std::set<int> s5(s4);
```

### Element Access and Modifiers
```cpp
// Insertion
s.insert(value);                   // Insert single element
s.insert(it_pos, value);           // Insert with position hint
s.insert(it_begin, it_end);        // Insert range of elements
s.emplace(args...);                // Construct element in-place

// Removal
s.erase(value);                    // Remove element by value
s.erase(it);                       // Remove element at iterator
s.erase(it_begin, it_end);         // Remove range of elements
s.clear();                         // Remove all elements

// Lookup
auto it = s.find(value);           // Find element (returns iterator)
size_t count = s.count(value);     // Count occurrences (always 0 or 1 for set)
auto lb = s.lower_bound(value);    // Iterator to first element not less than value
auto ub = s.upper_bound(value);    // Iterator to first element greater than value
auto range = s.equal_range(value); // Pair of lower_bound and upper_bound
```

### Iterators and Traversal
```cpp
// Iterators
auto it_begin = s.begin();         // Iterator to first element
auto it_end = s.end();             // Iterator to one past last element
auto it_rbegin = s.rbegin();       // Reverse iterator to last element
auto it_rend = s.rend();           // Reverse iterator to one before first element

// Traversal
for (const auto& element : s) {    // Range-based for loop
    std::cout << element << " ";
}

// Manual traversal
for (auto it = s.begin(); it != s.end(); ++it) {
    std::cout << *it << " ";
}
```

### Capacity and Comparison
```cpp
size_t n = s.size();               // Number of elements
bool is_empty = s.empty();         // Check if set is empty
size_t max_size = s.max_size();    // Maximum potential size

// Comparison operators
bool equal = (s1 == s2);           // Check equality
bool not_equal = (s1 != s2);       // Check inequality
bool less = (s1 < s2);             // Lexicographical comparison
```

## Best Practices and Optimization Tips

1. **Use `emplace()` Instead of `insert()`**:
   - For complex objects, `emplace()` constructs in-place, avoiding temporary objects
   - Example: `s.emplace("key")` instead of `s.insert(std::string("key"))`

2. **Use Iterator Hints**:
   - When inserting multiple elements in order, provide iterator hints
   - Example: `auto it = s.end(); it = s.insert(it, value);`

3. **Use `lower_bound()` for Insertion Points**:
   - Find the position first, then use it as a hint
   - Example: `auto pos = s.lower_bound(value); s.insert(pos, value);`

4. **Consider Custom Comparators for Special Ordering**:
   - Define custom comparison functor or lambda for special ordering needs
   - Example: case-insensitive string set

5. **Use Set Operations for Set Algebra**:
   - Utilize algorithms like `set_union`, `set_intersection`, etc.
   - Example: `std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(result, result.begin()));`

6. **Leverage Range-Based Queries**:
   - Use `equal_range()`, `lower_bound()`, and `upper_bound()` for efficient range queries
   - Example: finding all elements in a range

7. **Check Insertion Success**:
   - `insert()` returns a pair with an iterator and a boolean indicating success
   - Example: `auto [it, success] = s.insert(value);`

## Common Use Cases

- **Eliminating Duplicates**: Automatically ensure uniqueness
- **Ordered Data Storage**: When elements need to be maintained in sorted order
- **Fast Lookups**: When search operations are frequent
- **Range Queries**: Finding all elements between two values
- **Set-Theoretic Operations**: Computing unions, intersections, differences
- **Implementing Dictionaries**: Where only the keys matter (not values)
- **Collecting Unique Visitors/IDs**: When tracking unique occurrences

## Multiset and Unordered Set Variants

### Multiset
```cpp
#include <set>
std::multiset<int> ms = {1, 2, 2, 3, 3, 3};  // Allows duplicates
// ms contains: {1, 2, 2, 3, 3, 3} (sorted, with duplicates)
```

### Unordered Set
```cpp
#include <unordered_set>
std::unordered_set<int> us = {3, 1, 4, 1, 5};  // Uses hash table
// us contains: {1, 3, 4, 5} (unique, in arbitrary order)
```

## Limitations

- **No Direct Element Modification**: Cannot modify elements in-place (must remove and reinsert)
- **Not Optimized for Random Access**: No direct indexing like vectors
- **Overhead**: Binary tree structure has higher memory overhead than contiguous containers
- **No Bidirectional Iterators**: Cannot move backward from `begin()` or forward from `end()`
- **Not Cache-Friendly**: Non-contiguous memory storage leads to more cache misses than vectors
