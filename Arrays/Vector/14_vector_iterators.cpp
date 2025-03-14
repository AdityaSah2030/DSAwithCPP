#include <iostream>
#include <vector>
using namespace std;

/*
 * Program: 14_vector_iterators.cpp
 * Description:
 *   Demonstrates how to use various types of iterators with std::vector:
 *
 *   1. begin() and end():
 *        - Return non-const iterators to the beginning and one-past-the-end.
 *        - Allow modification of the elements.
 *        - If not using auto, you can declare:
 *              vector<int>::iterator it = v.begin();
 *
 *   2. cbegin() and cend():
 *        - Return const iterators (read-only) to the beginning and one-past-the-end.
 *        - If not using auto, you can declare:
 *              vector<int>::const_iterator cit = v.cbegin();
 *
 *   3. rbegin() and rend():
 *        - Return non-const reverse iterators.
 *        - rbegin() points to the last element.
 *        - rend() points to the element before the first.
 *        - Allow reverse traversal and modification.
 *        - If not using auto, you can declare:
 *              vector<int>::reverse_iterator rit = v.rbegin();
 *
 *   4. crbegin() and crend():
 *        - Return const reverse iterators (read-only).
 *        - If not using auto, you can declare:
 *              vector<int>::const_reverse_iterator crit = v.crbegin();
 *
 * Steps to Compile and Run (Linux/Mac):
 *   g++ 14_vector_iterators.cpp -o 14_vector_iterators
 *   ./14_vector_iterators
 *
 * Steps to Compile and Run (Windows):
 *   g++ 14_vector_iterators.cpp -o 14_vector_iterators.exe
 *   14_vector_iterators
 */

int main() {
    // Initialize a vector with some values.
    vector<int> v {10, 20, 30, 40, 50};

    // Using begin() and end() for forward iteration (modifiable)
    cout << "Forward iteration using begin() and end():" << endl;
    // Using auto:
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";  // Dereference to access the element
    }
    // If not using auto, you could write:
    // for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) { ... }
    cout << endl;

    // Modify elements using non-const iterators.
    cout << "\nDoubling elements using non-const iterators:" << endl;
    for (auto it = v.begin(); it != v.end(); ++it) {
        *it = (*it) * 2;
    }
    // Print modified vector.
    cout << "After modification: ";
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Using cbegin() and cend() for forward iteration (read-only)
    cout << "\nForward iteration using cbegin() and cend() (read-only):" << endl;
    for (auto cit = v.cbegin(); cit != v.cend(); ++cit) {
        cout << *cit << " ";
        // If not using auto, declare as:
        // for (vector<int>::const_iterator cit = v.cbegin(); cit != v.cend(); ++cit) { ... }
        // *cit = 100; // Not allowed because cit is a const_iterator
    }
    cout << endl;

    // Using rbegin() and rend() for reverse iteration (modifiable)
    cout << "\nReverse iteration using rbegin() and rend():" << endl;
    for (auto rit = v.rbegin(); rit != v.rend(); ++rit) {
        cout << *rit << " ";
        // If not using auto, declare as:
        // for (vector<int>::reverse_iterator rit = v.rbegin(); rit != v.rend(); ++rit) { ... }
        // Let's subtract 5 from each element during reverse traversal for demonstration.
        *rit -= 5;
    }
    cout << "\nAfter modifying in reverse, vector elements:" << endl;
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Using crbegin() and crend() for reverse iteration (read-only)
    cout << "\nReverse iteration using crbegin() and crend() (read-only):" << endl;
    for (auto crit = v.crbegin(); crit != v.crend(); ++crit) {
        cout << *crit << " ";
        // If not using auto, declare as:
        // for (vector<int>::const_reverse_iterator crit = v.crbegin(); crit != v.crend(); ++crit) { ... }
    }
    cout << endl;

    return 0;
}
