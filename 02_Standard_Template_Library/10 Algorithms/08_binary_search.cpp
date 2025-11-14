#include <iostream>
#include <algorithm> // For binary_search
#include <vector>
using namespace std;

/*
 * File: 08_binary_search.cpp
 * Description:
 *   Demonstrates how to use std::binary_search to check if a value exists
 *   in a sorted range.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 08_binary_search.cpp -o 08_binary_search
 *     ./08_binary_search
 *
 *   Windows:
 *     g++ 08_binary_search.cpp -o 08_binary_search.exe
 *     08_binary_search
 */

int main() {
    // Must be sorted for binary_search to work correctly
    vector<int> v = {1, 2, 4, 5, 7, 9, 10};
    
    cout << "Sorted vector elements: ";
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;

    int target1 = 5;
    int target2 = 6;

    // std::binary_search returns true if found, false otherwise
    bool found1 = binary_search(v.begin(), v.end(), target1);
    bool found2 = binary_search(v.begin(), v.end(), target2);

    cout << "Searching for " << target1 << ": "
         << (found1 ? "Found" : "Not found") << endl;
    // Expected: Found

    cout << "Searching for " << target2 << ": "
         << (found2 ? "Found" : "Not found") << endl;
    // Expected: Not found

    // We can also provide a custom comparator if needed
    // e.g. binary_search(v.begin(), v.end(), target, customComparator);

    return 0;
}
