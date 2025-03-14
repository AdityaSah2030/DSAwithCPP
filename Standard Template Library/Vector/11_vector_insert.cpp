#include <iostream>
#include <vector>
using namespace std;

/*
 * Program: 11_vector_insert.cpp
 * Description:
 *   Demonstrates how to insert elements into a vector using insert().
 *   insert() can insert a single element or a range of elements at a specific position.
 *
 * Steps to Compile and Run (Linux/Mac):
 *   g++ 11_vector_insert.cpp -o 11_vector_insert
 *   ./11_vector_insert
 *
 * Steps to Compile and Run (Windows):
 *   g++ 11_vector_insert.cpp -o 11_vector_insert.exe
 *   11_vector_insert
 */

int main() {
    vector<int> v {10, 20, 30};

    cout << "Initial vector: ";
    for (int x : v) cout << x << " ";
    cout << endl;
    // Expected: 10 20 30

    // Insert single element at the beginning
    v.insert(v.begin(), 5);
    cout << "After inserting 5 at the beginning: ";
    for (int x : v) cout << x << " ";
    cout << endl;
    // Expected: 5 10 20 30

    // Insert single element at index 2
    v.insert(v.begin() + 2, 15);
    cout << "After inserting 15 at index 2: ";
    for (int x : v) cout << x << " ";
    cout << endl;
    // Expected: 5 10 15 20 30

    // Insert multiple elements at once (e.g., two copies of 25 at the end - 1)
    v.insert(v.end() - 1, 2, 25);
    cout << "After inserting two 25s before the last element: ";
    for (int x : v) cout << x << " ";
    cout << endl;
    // Expected: 5 10 15 20 25 25 30

    // Insert a range of elements from another vector
    vector<int> toInsert {100, 200};
    v.insert(v.begin() + 1, toInsert.begin(), toInsert.end());
    cout << "After inserting [100, 200] at index 1: ";
    for (int x : v) cout << x << " ";
    cout << endl;
    // Expected: 5 100 200 10 15 20 25 25 30

    return 0;
}
