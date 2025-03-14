#include <iostream>
#include <algorithm>  // For std::sort
using namespace std;

/*
 * File: 01_sort_array.cpp
 * Description:
 *   Demonstrates how to sort a raw array using std::sort(arr, arr + n).
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 01_sort_array.cpp -o 01_sort_array
 *     ./01_sort_array
 *
 *   Windows:
 *     g++ 01_sort_array.cpp -o 01_sort_array.exe
 *     01_sort_array
 */

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Sort in ascending order
    sort(arr, arr + n);

    cout << "Sorted array (ascending): ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Sort in descending order using built-in comparator
    sort(arr, arr + n, greater<int>());

    cout << "Sorted array (descending): ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
