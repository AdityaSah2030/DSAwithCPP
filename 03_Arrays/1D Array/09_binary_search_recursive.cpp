#include <iostream>
#include <vector>
using namespace std;

/*
 * Program: 09_binary_search_recursive.cpp
 * Description:
 *   Performs a recursive binary search on a sorted array (ascending order).
 *   Returns the index of the target element if found, otherwise -1.
 *
 * Approach (Recursive):
 *   1. Define a helper function that takes the array, start index, end index, and target.
 *   2. Base Case:
 *      - If start > end, return -1 (not found).
 *   3. Recursive Case:
 *      - mid = start + (end - start) / 2
 *      - If arr[mid] == target, return mid.
 *      - If arr[mid] < target, recursively search in arr[mid+1 ... end].
 *      - Else, search in arr[start ... mid-1].
 *
 * Example Test Cases:
 *   1) arr = [1, 2, 3, 4, 5], target = 4 -> Expected index: 3
 *   2) arr = [10, 20, 30, 40, 50], target = 50 -> Expected index: 4
 *   3) arr = [10, 20, 30, 40, 50], target = 5 -> Expected index: -1 (not found)
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 09_binary_search_recursive.cpp -o 09_binary_search_recursive
 *     ./09_binary_search_recursive
 *
 *   Windows:
 *     g++ 09_binary_search_recursive.cpp -o 09_binary_search_recursive.exe
 *     09_binary_search_recursive
 */

// Recursive helper function
int binarySearchRecursiveHelper(const vector<int>& arr, int start, int end, int target) {
    // Base Case: if start exceeds end, target not found
    if (start > end) {
        return -1;
    }

    // Calculate mid to avoid potential overflow
    int mid = start + (end - start) / 2;

    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] < target) {
        // Search in the right half
        return binarySearchRecursiveHelper(arr, mid + 1, end, target);
    } else {
        // Search in the left half
        return binarySearchRecursiveHelper(arr, start, mid - 1, target);
    }
}

// Wrapper function for recursive binary search
int binarySearchRecursive(const vector<int>& arr, int target) {
    return binarySearchRecursiveHelper(arr, 0, arr.size() - 1, target);
}

int main() {
    // Test Case 1
    vector<int> arr1 = {1, 2, 3, 4, 5};
    int target1 = 4;
    cout << "Test Case 1: arr = [1, 2, 3, 4, 5], target = 4" << endl;
    int index1 = binarySearchRecursive(arr1, target1);
    cout << "Index of target (4): " << index1 << endl;
    // Expected index: 3

    cout << endl;

    // Test Case 2
    vector<int> arr2 = {10, 20, 30, 40, 50};
    int target2 = 50;
    cout << "Test Case 2: arr = [10, 20, 30, 40, 50], target = 50" << endl;
    int index2 = binarySearchRecursive(arr2, target2);
    cout << "Index of target (50): " << index2 << endl;
    // Expected index: 4

    cout << endl;

    // Test Case 3
    vector<int> arr3 = {10, 20, 30, 40, 50};
    int target3 = 5;
    cout << "Test Case 3: arr = [10, 20, 30, 40, 50], target = 5" << endl;
    int index3 = binarySearchRecursive(arr3, target3);
    cout << "Index of target (5): " << index3 << endl;
    // Expected index: -1

    return 0;
}
