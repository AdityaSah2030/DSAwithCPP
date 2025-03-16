#include <iostream>
#include <vector>
using namespace std;

/*
 * Program: 06_vector_at.cpp
 * Description:
 *   Demonstrates how to access elements at a specific index using at().
 *   The at() function provides bounds checking.
 *
 * Expected Console Output:
 *   Element at index 2 is: 30
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 06_vector_at.cpp -o 06_vector_at
 *     ./06_vector_at
 *   Windows:
 *     g++ 06_vector_at.cpp -o 06_vector_at.exe
 *     06_vector_at
 */

int main() {
    // Initialize a vector with some elements
    vector<int> v {10, 20, 30, 40};  
    // Vector state: [10, 20, 30, 40]

    // Access the element at index 2 (third element)
    cout << "Element at index 2 is: " << v.at(2) << endl;
    // Expected output: Element at index 2 is: 30

    // To demonstrate bounds checking, you can uncomment the try-catch block below.
    /*
    try {
        // Attempting to access an out-of-range index
        cout << "Element at index 10 is: " << v.at(10) << endl;
    } catch (const out_of_range &e) {
        cerr << "Error: " << e.what() << endl;
        // Expected output: Error: vector::_M_range_check: __n (which is 10) >= this->size() (which is 4)
    }
    */

    return 0;
}
