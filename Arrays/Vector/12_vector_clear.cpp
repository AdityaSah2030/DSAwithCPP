#include <iostream>
#include <vector>
using namespace std;

/*
 * Program: 12_vector_clear.cpp
 * Description:
 *   Demonstrates how to remove all elements from a vector using clear().
 *   clear() does not change the capacity of the vector, only the size.
 *
 * Steps to Compile and Run (Linux/Mac):
 *   g++ 12_vector_clear.cpp -o 12_vector_clear
 *   ./12_vector_clear
 *
 * Steps to Compile and Run (Windows):
 *   g++ 12_vector_clear.cpp -o 12_vector_clear.exe
 *   12_vector_clear
 */

int main() {
    vector<int> v {10, 20, 30, 40, 50};

    cout << "Initial vector: ";
    for (int x : v) cout << x << " ";
    cout << endl;
    // Expected: 10 20 30 40 50

    cout << "Size before clear: " << v.size() << endl;
    cout << "Capacity before clear: " << v.capacity() << endl;

    // Clear the vector
    v.clear();

    cout << "\nAfter clear():" << endl;
    cout << "Size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;
    // Note: capacity usually remains the same; size goes to 0

    // Check if vector is empty
    if (v.empty()) {
        cout << "Vector is now empty." << endl;
    }

    return 0;
}
