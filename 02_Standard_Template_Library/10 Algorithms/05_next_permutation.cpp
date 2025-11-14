#include <iostream>
#include <algorithm> // For std::next_permutation
#include <vector>
using namespace std;

/*
 * File: 05_next_permutation.cpp
 * Description:
 *   Demonstrates how to use std::next_permutation to generate permutations
 *   in lexicographical order. We show an example with a std::vector.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 05_next_permutation.cpp -o 05_next_permutation
 *     ./05_next_permutation
 *
 *   Windows:
 *     g++ 05_next_permutation.cpp -o 05_next_permutation.exe
 *     05_next_permutation
 */

int main() {
    vector<int> v = {1, 2, 3};

    cout << "Original vector: ";
    for (int val : v) {
        cout << val << " ";
    }
    cout << endl;

    cout << "\nAll permutations in ascending (lexicographical) order:\n";

    // First, ensure the vector is sorted in ascending order to start from the lowest permutation
    sort(v.begin(), v.end());

    do {
        for (int val : v) {
            cout << val << " ";
        }
        cout << endl;
    } while (next_permutation(v.begin(), v.end()));
    // This loop continues until next_permutation returns false, which means
    // we've cycled back to the first (lowest) permutation.

    return 0;
}
