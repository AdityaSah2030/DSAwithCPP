#include <iostream>
#include <vector>
using namespace std;

/*
 * Program: 04_vector_front.cpp
 * Description:
 *   Demonstrates how to access the first element of a vector using front().
 *
 * Expected Console Output:
 *   The first element (front) is: 10
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 04_vector_front.cpp -o 04_vector_front
 *     ./04_vector_front
 *   Windows:
 *     g++ 04_vector_front.cpp -o 04_vector_front.exe
 *     04_vector_front
 */

int main() {
    // Initialize a vector with some elements
    vector<int> v {10, 20, 30, 40};  
    // Vector state: [10, 20, 30, 40]

    // Access the first element using front()
    cout << "The first element (front) is: " << v.front() << endl;
    // Expected output: The first element (front) is: 10

    return 0;
}
