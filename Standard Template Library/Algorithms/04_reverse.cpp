#include <iostream>
#include <algorithm> // For std::reverse
#include <vector>
using namespace std;

/*
 * File: 04_reverse.cpp
 * Description:
 *   Demonstrates how to reverse a sequence using std::reverse.
 *   We show both a raw array and a std::vector example.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 04_reverse.cpp -o 04_reverse
 *     ./04_reverse
 *
 *   Windows:
 *     g++ 04_reverse.cpp -o 04_reverse.exe
 *     04_reverse
 */

int main() {
    // 1) Reverse a raw array
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Reverse the entire array
    reverse(arr, arr + n);

    cout << "Reversed array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 2) Reverse a std::vector
    vector<int> v = {10, 20, 30, 40, 50};

    cout << "\nOriginal vector: ";
    for (int val : v) {
        cout << val << " ";
    }
    cout << endl;

    reverse(v.begin(), v.end());

    cout << "Reversed vector: ";
    for (int val : v) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
