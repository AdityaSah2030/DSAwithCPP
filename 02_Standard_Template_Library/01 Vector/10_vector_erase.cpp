#include <iostream>
#include <vector>
using namespace std;

/*
 * Program: 10_vector_erase.cpp
 * Description:
 *   Demonstrates how to remove elements from a vector using erase().
 *   erase() can remove a single element by iterator or a range of elements.
 *
 * Steps to Compile and Run (Linux/Mac):
 *   g++ 10_vector_erase.cpp -o 10_vector_erase
 *   ./10_vector_erase
 *
 * Steps to Compile and Run (Windows):
 *   g++ 10_vector_erase.cpp -o 10_vector_erase.exe
 *   10_vector_erase
 */

int main() {
    vector<int> v {10, 20, 30, 40, 50};

    cout << "Initial vector: ";
    for (int x : v) cout << x << " ";
    cout << endl;
    // Expected: 10 20 30 40 50

    // Erase single element (e.g., element at index 2 -> 30)
    v.erase(v.begin() + 2);

    cout << "After erasing element at index 2: ";
    for (int x : v) cout << x << " ";
    cout << endl;
    // Expected: 10 20 40 50

    // Erase a range of elements (e.g., from index 1 to index 2 (exclusive of end))
    // So this removes elements at indices [1..2)
    v.erase(v.begin() + 1, v.begin() + 2);

    cout << "After erasing range (index 1 to 2): ";
    for (int x : v) cout << x << " ";
    cout << endl;
    // Expected: 10 50

    return 0;
}
