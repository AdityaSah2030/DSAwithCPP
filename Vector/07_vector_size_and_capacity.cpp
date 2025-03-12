#include <iostream>
#include <vector>
using namespace std;

/*
 * Program: 07_vector_size_and_capacity.cpp
 * Description:
 *   Demonstrates how a vector's size and capacity work.
 *   - size(): The current number of elements in the vector.
 *   - capacity(): The total amount of memory allocated for the vector (which may be more than its current size).
 *
 * The program:
 *   1. Prints the initial size and capacity of an empty vector.
 *   2. Adds elements using push_back() in a loop while printing the updated size and capacity.
 *   3. Uses reserve() to preallocate memory and shows how capacity changes.
 *   4. Adds more elements after reserving additional capacity.
 *
 * Expected Console Output (Note: Actual capacity values may vary depending on your implementation):
 *
 *   Initial vector state:
 *   Size: 0
 *   Capacity: 0
 *
 *   Adding elements to vector:
 *   After push_back(1): Size = 1, Capacity = 1
 *   After push_back(2): Size = 2, Capacity = 2
 *   After push_back(3): Size = 3, Capacity = 4
 *   After push_back(4): Size = 4, Capacity = 4
 *   After push_back(5): Size = 5, Capacity = 8
 *   After push_back(6): Size = 6, Capacity = 8
 *   After push_back(7): Size = 7, Capacity = 8
 *   After push_back(8): Size = 8, Capacity = 8
 *   After push_back(9): Size = 9, Capacity = 16
 *   After push_back(10): Size = 10, Capacity = 16
 *
 *   Using reserve() to preallocate memory:
 *   After reserve(20): Size = 10, Capacity = 20
 *
 *   Adding more elements after reserve():
 *   After push_back(11): Size = 11, Capacity = 20
 *   After push_back(12): Size = 12, Capacity = 20
 *   After push_back(13): Size = 13, Capacity = 20
 *   After push_back(14): Size = 14, Capacity = 20
 *   After push_back(15): Size = 15, Capacity = 20
 *
 *   Final vector elements: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 
 *
 * Steps to Compile and Run:
 *   For Linux/Mac:
 *     g++ 07_vector_size_and_capacity.cpp -o 07_vector_size_and_capacity
 *     ./07_vector_size_and_capacity
 *
 *   For Windows:
 *     g++ 07_vector_size_and_capacity.cpp -o 07_vector_size_and_capacity.exe
 *     07_vector_size_and_capacity
 */

int main() {
    // Create an empty vector of integers.
    vector<int> v;
    
    cout << "Initial vector state:" << endl;
    cout << "Size: " << v.size() << endl;      // Expected: 0
    cout << "Capacity: " << v.capacity() << endl; // Expected: 0 (or an implementation-specific value)

    // Add elements using push_back() and print size and capacity after each insertion.
    cout << "\nAdding elements to vector:" << endl;
    for (int i = 1; i <= 10; i++) {
        v.push_back(i);
        // The capacity may double or increase non-linearly as elements are added.
        cout << "After push_back(" << i << "): Size = " 
             << v.size() << ", Capacity = " << v.capacity() << endl;
    }

    // Reserve additional capacity. This preallocates memory for at least 20 elements.
    cout << "\nUsing reserve() to preallocate memory:" << endl;
    v.reserve(20);
    cout << "After reserve(20): Size = " << v.size() 
         << ", Capacity = " << v.capacity() << endl;
    // Note: Size remains unchanged; only capacity is updated if it was less than 20.

    // Add more elements after reserving extra space.
    cout << "\nAdding more elements after reserve():" << endl;
    for (int i = 11; i <= 15; i++) {
        v.push_back(i);
        cout << "After push_back(" << i << "): Size = " 
             << v.size() << ", Capacity = " << v.capacity() << endl;
    }

    // Print final vector contents.
    cout << "\nFinal vector elements: ";
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
