#include <iostream>
#include <vector>
using namespace std;

/*
 * Program: 09_vector_access_operator.cpp
 * Description:
 *   Demonstrates how to access elements in a vector using operator[] and at().
 *   Both are used to access elements by index, but at() performs bounds checking
 *   and throws an exception if the index is out of range.
 *
 * Steps to Compile and Run (Linux/Mac):
 *   g++ 09_vector_access_operator.cpp -o 09_vector_access_operator
 *   ./09_vector_access_operator
 *
 * Steps to Compile and Run (Windows):
 *   g++ 09_vector_access_operator.cpp -o 09_vector_access_operator.exe
 *   09_vector_access_operator
 */

int main() {
    vector<int> v {10, 20, 30, 40};

    // Access using operator[]
    cout << "Using operator[]:" << endl;
    cout << "v[0] = " << v[0] << endl; // Expected 10
    cout << "v[1] = " << v[1] << endl; // Expected 20
    cout << "v[2] = " << v[2] << endl; // Expected 30
    cout << "v[3] = " << v[3] << endl; // Expected 40

    // Access using at()
    cout << "\nUsing at():" << endl;
    cout << "v.at(0) = " << v.at(0) << endl; // Expected 10
    cout << "v.at(1) = " << v.at(1) << endl; // Expected 20
    cout << "v.at(2) = " << v.at(2) << endl; // Expected 30
    cout << "v.at(3) = " << v.at(3) << endl; // Expected 40

    // Demonstrate exception with at() if index is out of range
    cout << "\nAttempting out-of-range access using at():" << endl;
    try {
        cout << "v.at(10) = " << v.at(10) << endl;
    } catch (const out_of_range &e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}
