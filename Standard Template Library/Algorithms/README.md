# C++ STL Algorithms

## Overview
The C++ Standard Template Library (STL) provides a rich collection of algorithms that operate on ranges of elements. These algorithms are defined in the `<algorithm>` header and are designed to work with any container that provides iterators, making them highly reusable and generic.

## Key Characteristics

- **Generic Programming**: Algorithms are not tied to specific container types
- **Iterator-Based**: Operate on ranges defined by iterators, not directly on containers
- **Efficiency**: Optimized implementations for common operations
- **Composability**: Can be combined with function objects, lambdas, and other algorithms
- **No Memory Management**: Algorithms do not handle memory allocation/deallocation

## Categories of STL Algorithms

### Non-modifying Sequence Operations

Algorithms that don't modify the elements they operate on:

| Algorithm | Description | Time Complexity | Example Use Case |
|-----------|-------------|-----------------|------------------|
| `std::find` | Finds first occurrence of value | O(n) | Searching for a value in a container |
| `std::find_if` | Finds first element satisfying predicate | O(n) | Searching with custom criteria |
| `std::count` | Counts occurrences of value | O(n) | Counting specific elements |
| `std::count_if` | Counts elements satisfying predicate | O(n) | Counting elements that meet criteria |
| `std::equal` | Compares ranges for equality | O(n) | Checking if two ranges are identical |
| `std::search` | Searches for subsequence | O(n*m) | Finding a subrange within a range |
| `std::for_each` | Applies function to each element | O(n) | Processing each element in a container |
| `std::all_of`, `std::any_of`, `std::none_of` | Tests if predicate is true for all/any/none | O(n) | Validating all elements meet criteria |

### Modifying Sequence Operations

Algorithms that modify elements or structure of the ranges they operate on:

| Algorithm | Description | Time Complexity | Example Use Case |
|-----------|-------------|-----------------|------------------|
| `std::copy` | Copies range of elements | O(n) | Duplicating elements to another container |
| `std::move` | Moves range of elements | O(n) | Transferring elements to another container |
| `std::transform` | Applies function and stores result | O(n) | Transforming elements using a function |
| `std::replace` | Replaces values | O(n) | Replacing specific values |
| `std::replace_if` | Replaces values satisfying predicate | O(n) | Replacing values that meet criteria |
| `std::fill` | Assigns value to range | O(n) | Initializing a range with a specific value |
| `std::generate` | Assigns generator results to range | O(n) | Filling a range with generated values |
| `std::remove`, `std::remove_if` | Removes elements (logical removal) | O(n) | Removing unwanted elements |
| `std::unique` | Removes consecutive duplicates | O(n) | Eliminating adjacent duplicates |
| `std::reverse` | Reverses order of elements | O(n) | Reversing a range of elements |
| `std::rotate` | Rotates elements in range | O(n) | Shifting elements by a specified amount |
| `std::shuffle` | Randomly reorders elements | O(n) | Randomizing the order of elements |
| `std::swap` | Exchanges values of two objects | O(1) | Swapping two values |

### Sorting and Related Operations

Algorithms for ordering and organizing elements:

| Algorithm | Description | Time Complexity | Example Use Case |
|-----------|-------------|-----------------|------------------|
| `std::sort` | Sorts elements in range | O(n log n) | Ordering elements |
| `std::partial_sort` | Sorts part of range | O(n log m) | Sorting only the first m elements |
| `std::stable_sort` | Stable sorting algorithm | O(n log n) or O(n log² n) | Preserving relative order of equal elements |
| `std::nth_element` | Partially sorts to partition at nth element | O(n) average | Finding the nth smallest element |
| `std::is_sorted` | Checks if range is sorted | O(n) | Verifying if a range is already sorted |
| `std::binary_search` | Checks if value exists in sorted range | O(log n) | Testing if value exists in sorted container |
| `std::lower_bound` | Finds first element not less than value | O(log n) | Finding insertion point in sorted range |
| `std::upper_bound` | Finds first element greater than value | O(log n) | Finding end of range of values in sorted range |
| `std::equal_range` | Finds range of elements equal to value | O(log n) | Finding all occurrences in sorted range |
| `std::merge` | Merges two sorted ranges | O(n + m) | Combining two sorted containers |
| `std::inplace_merge` | Merges consecutive sorted ranges | O(n) to O(n log n) | Merging sorted subranges within container |
| `std::includes` | Tests if sorted range includes another | O(n + m) | Checking for subset relationship |
| `std::set_union`, `std::set_intersection`, etc. | Set operations on sorted ranges | O(n + m) | Performing set operations |

### Numeric Operations (from `<numeric>` header)

Algorithms for numeric calculations:

| Algorithm | Description | Time Complexity | Example Use Case |
|-----------|-------------|-----------------|------------------|
| `std::accumulate` | Computes sum or applies binary operation | O(n) | Summing values in a range |
| `std::inner_product` | Computes inner product or custom operation | O(n) | Computing dot product or similar operations |
| `std::adjacent_difference` | Computes differences between adjacent elements | O(n) | Calculating derivative-like sequences |
| `std::partial_sum` | Computes partial sums | O(n) | Computing running totals |
| `std::iota` | Fills range with successive increments | O(n) | Generating sequence of consecutive values |
| `std::reduce` (C++17) | Parallel reduction operation | O(n) | Summing values potentially in parallel |
| `std::transform_reduce` (C++17) | Transforms and reduces | O(n) | Mapping and summing in one operation |

### Min/Max Operations

Algorithms for finding minimum and maximum values:

| Algorithm | Description | Time Complexity | Example Use Case |
|-----------|-------------|-----------------|------------------|
| `std::min`, `std::max` | Returns smaller/larger of two values | O(1) | Choosing the min/max of two values |
| `std::minmax` | Returns both min and max of two values | O(1) | Getting both extremes in one operation |
| `std::min_element`, `std::max_element` | Finds min/max in range | O(n) | Finding smallest/largest element |
| `std::minmax_element` | Finds both min and max in range | O(n) | Finding both extremes in one pass |
| `std::clamp` (C++17) | Constrains value between bounds | O(1) | Limiting a value to a specific range |

### Permutation Operations

Algorithms for generating permutations:

| Algorithm | Description | Time Complexity | Example Use Case |
|-----------|-------------|-----------------|------------------|
| `std::next_permutation` | Transforms to next permutation | O(n) | Generating all permutations of a range |
| `std::prev_permutation` | Transforms to previous permutation | O(n) | Generating permutations in reverse order |
| `std::is_permutation` | Tests if range is permutation of another | O(n²) or O(n log n) | Checking if sequences contain same elements |

## Key Implementation Details

### Sorting Implementation

- `std::sort` is typically implemented as Introsort (hybrid of quicksort, heapsort, and insertion sort)
- Provides average O(n log n) performance with worst-case guarantees
- Not guaranteed to be stable (relative order of equal elements may change)
- `std::stable_sort` preserves the relative order of equal elements (usually implemented as merge sort)

### Partitioning

- Many algorithms use partitioning internally (separating elements into two groups)
- QuickSort-style partitioning is common in sort implementations
- `std::partition` rearranges elements so those satisfying the predicate come before those that don't

### Removal Semantics

- Algorithms like `std::remove` don't actually delete elements or change container size
- They perform a "logical removal" by moving non-removed elements to the front
- Return an iterator to the new logical end
- Must be followed by an explicit call to the container's `erase()` method to physically remove elements

```cpp
// Example: Remove-erase idiom
auto new_end = std::remove(v.begin(), v.end(), value_to_remove);
v.erase(new_end, v.end());
```

### Binary Search Requirements

- Binary search algorithms (`std::binary_search`, `std::lower_bound`, etc.) require a sorted range
- They use the fact that the range is sorted to achieve logarithmic complexity
- Using these algorithms on unsorted ranges leads to undefined behavior

## Comparison with Container-Specific Methods

| STL Algorithm | Container Method | When to Use Algorithm | When to Use Container Method |
|---------------|------------------|----------------------|------------------------------|
| `std::find` | `std::map::find` | For sequential containers | For associative containers (O(log n) vs O(n)) |
| `std::remove` | `std::list::remove` | For most containers | For list (avoids erase-remove idiom) |
| `std::sort` | `std::list::sort` | For random-access containers | For list (uses specialized list sort) |
| `std::lower_bound` | `std::set::lower_bound` | For sorted sequences | For associative containers (O(log n) for both) |

## Performance Considerations

- **Algorithm Selection**: Choose the right algorithm for the task (e.g., `std::nth_element` vs. full `std::sort`)
- **Iterator Types**: Random-access iterators enable more efficient implementations
- **Execution Policies** (C++17): Parallel execution for many algorithms
- **Predicate Complexity**: Complex predicates can dominate runtime
- **Memory Allocation**: Algorithms don't allocate memory; use `std::back_inserter` with `reserve()` for efficiency
- **Move Semantics**: Many algorithms have move-aware overloads for better performance with movable types

## C++17/20 Execution Policies

C++17 introduced parallel execution policies:

```cpp
// Sequential execution (same as no policy)
std::sort(std::execution::seq, v.begin(), v.end());

// Parallel execution
std::sort(std::execution::par, v.begin(), v.end());

// Parallel and vectorized execution
std::sort(std::execution::par_unseq, v.begin(), v.end());
```

## Range-based Algorithms (C++20)

C++20 introduces ranges, which simplify algorithm usage:

```cpp
// C++17
std::sort(vec.begin(), vec.end());

// C++20 with ranges
std::ranges::sort(vec);
```

## Common Pitfalls

1. **Forgetting Erase-Remove Idiom**: `remove()` doesn't change container size
2. **Using Unordered Containers with Ordering Algorithms**: Many algorithms assume ordered elements
3. **Invalidating Iterators**: Modifying containers can invalidate iterators used by algorithms
4. **Ignoring Return Values**: Many algorithms return important iterators or values
5. **Using Binary Search on Unsorted Data**: Must ensure data is sorted first
6. **Algorithm Inefficiency with Linked Structures**: Some algorithms are optimized for random-access containers
7. **Overlooking Specialized Container Methods**: Sometimes container-specific methods are more efficient

## Conclusion

The STL algorithms library provides a powerful, generic toolset for operating on sequences of elements. By understanding the different categories of algorithms, their requirements, and performance characteristics, developers can write more efficient, maintainable, and expressive code. The algorithms are designed to work with iterators, allowing them to be used with any container that provides the necessary iterator capabilities, which embodies the flexibility and reusability principles of the STL.
