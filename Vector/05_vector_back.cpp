#include <iostream>
#include <vector>
using namespace std;

/*
 * Program: 05_vector_back.cpp
 * Description:
 *   Demonstrates how to access the last element of a vector using back().
 *
 * Expected Console Output:
 *   The last element (back) is: 40
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 05_vector_back.cpp -o 05_vector_back
 *     ./05_vector_back
 *   Windows:
 *     g++ 05_vector_back.cpp -o 05_vector_back.exe
 *     05_vector_back
 */

int main() {
    // Initialize a vector with some elements
    vector<int> v {10, 20, 30, 40};  
    // Vector state: [10, 20, 30, 40]

    // Access the last element using back()
    cout << "The last element (back) is: " << v.back() << endl;
    // Expected output: The last element (back) is: 40

    return 0;
}
