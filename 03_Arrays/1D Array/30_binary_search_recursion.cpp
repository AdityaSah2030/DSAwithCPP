#include <iostream>
#include <vector>
using namespace std;

/*
 * File: 30_binary_search_recursion.cpp
 * Description:
 *   Performs a recursive binary search on a sorted array. Returns the index of
 *   the target if found, otherwise -1.
 *
 * Time Complexity: O(log n).
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 30_binary_search_recursion.cpp -o binary_search_recursion
 *     ./binary_search_recursion
 *
 *   Windows:
 *     g++ 30_binary_search_recursion.cpp -o binary_search_recursion.exe
 *     binary_search_recursion
 */

// Recursive helper function
int binarySearchHelper(const vector<int>& arr, int left, int right, int target) {
    // Base case: if range is invalid
    if (left > right) {
        return -1; // not found
    }

    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] < target) {
        return binarySearchHelper(arr, mid + 1, right, target);
    } else {
        return binarySearchHelper(arr, left, mid - 1, target);
    }
}

// Wrapper function for recursive binary search
int binarySearchRecursive(const vector<int>& arr, int target) {
    return binarySearchHelper(arr, 0, arr.size() - 1, target);
}

int main() {
    // Example usage
    cout << "Enter number of elements in the sorted array: ";
    int n;
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the sorted elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter target to search: ";
    int target;
    cin >> target;

    int index = binarySearchRecursive(arr, target);
    if (index == -1) {
        cout << "Target not found in the array." << endl;
    } else {
        cout << "Target found at index: " << index << endl;
    }

    return 0;
}
