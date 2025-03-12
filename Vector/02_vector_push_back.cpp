#include <iostream>
#include <vector>
using namespace std;

/*
 * Program: 02_vector_push_back.cpp
 * Description:
 *   Demonstrates how to add elements to the end of a vector using push_back().
 *
 * Expected Console Output:
 *   Vector elements after push_back: 10 20 30 
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 02_vector_push_back.cpp -o 02_vector_push_back
 *     ./02_vector_push_back
 *   Windows:
 *     g++ 02_vector_push_back.cpp -o 02_vector_push_back.exe
 *     02_vector_push_back
 */

int main() {
    vector<int> v;  // Start with an empty vector
    // Initial vector state: []

    // Add elements one by one using push_back()
    v.push_back(10);  // After this, vector state: [10]
    v.push_back(20);  // Now, vector state: [10, 20]
    v.push_back(30);  // Now, vector state: [10, 20, 30]

    // Print the vector elements
    cout << "Vector elements after push_back: ";
    for (int x : v) {
        cout << x << " ";  // Will print: 10 20 30 
    }
    cout << endl;
    
    // Inline expected output:
    // Vector elements after push_back: 10 20 30 

    return 0;
}
