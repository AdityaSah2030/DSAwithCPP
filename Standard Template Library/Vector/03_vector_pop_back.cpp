#include <iostream>
#include <vector>
using namespace std;

/*
 * Program: 03_vector_pop_back.cpp
 * Description:
 *   Demonstrates how to remove the last element from a vector using pop_back().
 *
 * Expected Console Output:
 *   Initial vector: 10 20 30 40 
 *   After pop_back: 10 20 30 
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 03_vector_pop_back.cpp -o 03_vector_pop_back
 *     ./03_vector_pop_back
 *   Windows:
 *     g++ 03_vector_pop_back.cpp -o 03_vector_pop_back.exe
 *     03_vector_pop_back
 */

int main() {
    // Initialize a vector with 4 elements
    vector<int> v {10, 20, 30, 40};  
    // Initial vector state: [10, 20, 30, 40]

    // Print initial state of the vector
    cout << "Initial vector: ";
    for (int x : v) {
        cout << x << " ";  // Will print: 10 20 30 40
    }
    cout << endl;
    // Expected output line: Initial vector: 10 20 30 40 

    // Remove the last element using pop_back()
    v.pop_back();  
    // Updated vector state: [10, 20, 30]

    // Print the vector after pop_back
    cout << "After pop_back: ";
    for (int x : v) {
        cout << x << " ";  // Will print: 10 20 30
    }
    cout << endl;
    // Expected output line: After pop_back: 10 20 30 

    return 0;
}
