#include <iostream>
#include <vector>
#include <algorithm>  // For std::sort
using namespace std;

/*
 * File: 02_sort_vector.cpp
 * Description:
 *   Demonstrates how to sort a std::vector using std::sort(v.begin(), v.end()).
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 02_sort_vector.cpp -o 02_sort_vector
 *     ./02_sort_vector
 *
 *   Windows:
 *     g++ 02_sort_vector.cpp -o 02_sort_vector.exe
 *     02_sort_vector
 */

int main() {
    vector<int> v = {5, 2, 9, 1, 5, 6};

    cout << "Original vector: ";
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;

    // Sort in ascending order
    sort(v.begin(), v.end());

    cout << "Sorted vector (ascending): ";
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;

    // Sort in descending order using built-in comparator
    sort(v.begin(), v.end(), greater<int>());

    cout << "Sorted vector (descending): ";
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
