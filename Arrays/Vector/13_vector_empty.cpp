#include <iostream>
#include <vector>
using namespace std;

/*
 * Program: 13_vector_empty.cpp
 * Description:
 *   Demonstrates how to check if a vector is empty using empty().
 *   Also shows how empty() behaves after operations like pop_back() or clear().
 *
 * Steps to Compile and Run (Linux/Mac):
 *   g++ 13_vector_empty.cpp -o 13_vector_empty
 *   ./13_vector_empty
 *
 * Steps to Compile and Run (Windows):
 *   g++ 13_vector_empty.cpp -o 13_vector_empty.exe
 *   13_vector_empty
 */

int main() {
    vector<int> v;

    // Check if empty initially
    if (v.empty()) {
        cout << "Initially, vector is empty." << endl;
    }

    // Add some elements
    v.push_back(10);
    v.push_back(20);

    cout << "After pushing elements, empty() returns: " 
         << (v.empty() ? "true" : "false") << endl;
    // Expected: false

    // Remove elements
    v.pop_back();
    v.pop_back();

    cout << "After popping all elements, empty() returns: "
         << (v.empty() ? "true" : "false") << endl;
    // Expected: true

    // Another example with clear
    v.push_back(1);
    v.push_back(2);
    cout << "Size before clear: " << v.size() << endl;
    v.clear();
    cout << "After clear, empty() returns: " 
         << (v.empty() ? "true" : "false") << endl;
    // Expected: true

    return 0;
}
