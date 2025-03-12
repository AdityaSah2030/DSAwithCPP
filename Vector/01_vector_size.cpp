#include <iostream>
#include <vector>
using namespace std;

/*
 * Demonstrates how to get the size of a vector using size().
 * 
 * Instructions to compile and run (Linux/Mac):
 * 1. Compile:  g++ 01_vector_size.cpp -o 01_vector_size
 * 2. Run:      ./01_vector_size
 *
 * Instructions to compile and run (Windows):
 * 1. Compile:  g++ 01_vector_size.cpp -o 01_vector_size.exe
 * 2. Run:      01_vector_size
 */

int main() {
    // Create a vector with some integer elements
    vector<int> v {1, 2, 3, 4, 5};

    // Print the size of the vector
    cout << "The size of the vector is: " << v.size() << endl;

    return 0;
}
