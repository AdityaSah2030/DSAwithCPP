#include <iostream>
#include <vector>
using namespace std;

/*
 * Program: 01_vector_size.cpp
 * Description:
 *   Demonstrates how to get the size of a vector using size().
 *
 * Expected Console Output:
 *   The size of the vector is: 5
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 01_vector_size.cpp -o 01_vector_size
 *     ./01_vector_size
 *   Windows:
 *     g++ 01_vector_size.cpp -o 01_vector_size.exe
 *     01_vector_size
 */

int main() {
    // Create a vector with 5 integer elements
    vector<int> v {1, 2, 3, 4, 5};  
    // Vector state: [1, 2, 3, 4, 5]

    // Output the size of the vector
    cout << "The size of the vector is: " << v.size() << endl;
    // Expected output: The size of the vector is: 5

    return 0;
}
