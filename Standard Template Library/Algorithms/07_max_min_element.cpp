#include <iostream>
#include <algorithm> // For max_element, min_element
#include <vector>
using namespace std;

/*
 * File: 07_max_min_element.cpp
 * Description:
 *   Demonstrates how to use std::max_element and std::min_element to find
 *   the largest and smallest elements in a range.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 07_max_min_element.cpp -o 07_max_min_element
 *     ./07_max_min_element
 *
 *   Windows:
 *     g++ 07_max_min_element.cpp -o 07_max_min_element.exe
 *     07_max_min_element
 */

int main() {
    vector<int> v = {5, 2, 9, 1, 5, 6};

    cout << "Vector elements: ";
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;

    // max_element returns an iterator to the largest element
    auto maxIt = max_element(v.begin(), v.end());
    if (maxIt != v.end()) {
        cout << "Max element: " << *maxIt << endl;
    }

    // min_element returns an iterator to the smallest element
    auto minIt = min_element(v.begin(), v.end());
    if (minIt != v.end()) {
        cout << "Min element: " << *minIt << endl;
    }

    // We can also use custom comparators, for example, to find
    // the element with the smallest absolute value, etc.

    return 0;
}
