#include <iostream>
#include <vector>
using namespace std;

/*
 * Program: 17_selection_sort.cpp
 * Description:
 *   Demonstrates the Selection Sort algorithm in C++.
 *   In Selection Sort, we repeatedly find the minimum element
 *   from the unsorted part of the array and place it at the beginning
 *   of the unsorted part.
 *
 * Time Complexity:
 *   - O(n^2) in the worst and average case
 *   - O(n^2) in the best case (since we still do comparisons)
 * Space Complexity:
 *   - O(1) extra space
 *
 * Example Test Cases:
 *   1) arr = [64, 25, 12, 22, 11]
 *      Sorted output: [11, 12, 22, 25, 64]
 *
 *   2) arr = [5, 1, 4, 2, 8]
 *      Sorted output: [1, 2, 4, 5, 8]
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 17_selection_sort.cpp -o 17_selection_sort
 *     ./17_selection_sort
 *
 *   Windows:
 *     g++ 17_selection_sort.cpp -o 17_selection_sort.exe
 *     17_selection_sort
 */

// Function to perform Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();

    // One by one, move the boundary of the unsorted subarray
    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in the unsorted subarray arr[i...n-1]
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element of the unsorted subarray
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// Helper function to print the elements of an array
void printArray(const vector<int>& arr) {
    cout << "[";
    for (int i = 0; i < (int)arr.size(); i++) {
        cout << arr[i];
        if (i < (int)arr.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    // Test Case 1
    vector<int> arr1 = {64, 25, 12, 22, 11};
    cout << "Test Case 1: ";
    printArray(arr1);
    selectionSort(arr1);
    cout << "Sorted: ";
    printArray(arr1);
    // Expected output: [11, 12, 22, 25, 64]

    cout << endl;

    // Test Case 2
    vector<int> arr2 = {5, 1, 4, 2, 8};
    cout << "Test Case 2: ";
    printArray(arr2);
    selectionSort(arr2);
    cout << "Sorted: ";
    printArray(arr2);
    // Expected output: [1, 2, 4, 5, 8]

    cout << endl;

    // Test Case 3 (already sorted)
    vector<int> arr3 = {1, 2, 3, 4, 5};
    cout << "Test Case 3 (already sorted): ";
    printArray(arr3);
    selectionSort(arr3);
    cout << "Sorted: ";
    printArray(arr3);
    // Expected output: [1, 2, 3, 4, 5]

    return 0;
}
