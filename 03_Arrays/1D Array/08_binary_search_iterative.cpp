#include <iostream>
#include <vector>
using namespace std;

/*
 * Program: 08_binary_search_iterative.cpp
 * Description:
 *   Performs an iterative binary search on a sorted array (ascending order).
 *   Returns the index of the target element if found, otherwise -1.
 *
 * Approach (Iterative):
 *   1. Initialize two pointers: start = 0, end = n - 1 (where n is the size of the array).
 *   2. While start <= end:
 *      - mid = start + (end - start) / 2  (to avoid potential overflow).
 *      - If arr[mid] == target, return mid.
 *      - If arr[mid] < target, search the right half (start = mid + 1).
 *      - Else, search the left half (end = mid - 1).
 *   3. If the loop ends without finding the target, return -1.
 *
 * Example Test Cases:
 *   1) arr = [1, 2, 3, 4, 5], target = 3 -> Expected index: 2
 *   2) arr = [2, 4, 6, 8, 10], target = 8 -> Expected index: 3
 *   3) arr = [2, 4, 6, 8, 10], target = 1 -> Expected index: -1 (not found)
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 08_binary_search_iterative.cpp -o 08_binary_search_iterative
 *     ./08_binary_search_iterative
 *
 *   Windows:
 *     g++ 08_binary_search_iterative.cpp -o 08_binary_search_iterative.exe
 *     08_binary_search_iterative
 */

// Iterative binary search function
int binarySearchIterative(const vector<int>& arr, int target) {
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end) {
        // Calculate mid to avoid potential overflow
        int mid = start + (end - start) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            // Search in the right half
            start = mid + 1;
        } else {
            // Search in the left half
            end = mid - 1;
        }
    }

    // If not found, return -1
    return -1;
}

int main() {
    // Test Case 1
    vector<int> arr1 = {1, 2, 3, 4, 5};
    int target1 = 3;
    cout << "Test Case 1: arr = [1, 2, 3, 4, 5], target = 3" << endl;
    int index1 = binarySearchIterative(arr1, target1);
    cout << "Index of target (3): " << index1 << endl;
    // Expected index: 2

    cout << endl;

    // Test Case 2
    vector<int> arr2 = {2, 4, 6, 8, 10};
    int target2 = 8;
    cout << "Test Case 2: arr = [2, 4, 6, 8, 10], target = 8" << endl;
    int index2 = binarySearchIterative(arr2, target2);
    cout << "Index of target (8): " << index2 << endl;
    // Expected index: 3

    cout << endl;

    // Test Case 3
    vector<int> arr3 = {2, 4, 6, 8, 10};
    int target3 = 1;
    cout << "Test Case 3: arr = [2, 4, 6, 8, 10], target = 1" << endl;
    int index3 = binarySearchIterative(arr3, target3);
    cout << "Index of target (1): " << index3 << endl;
    // Expected index: -1

    return 0;
}
