#include <iostream>
#include <vector>
using namespace std;

/*
 * Program: 18_insertion_sort.cpp
 * Description:
 *   Demonstrates the Insertion Sort algorithm in C++.
 *   Insertion Sort builds the sorted array one element at a time by repeatedly
 *   taking the next element and inserting it into its correct position within
 *   the already sorted part of the array.
 *
 * Algorithm Overview:
 *   - Start from the second element (index 1) of the array.
 *   - For each element, compare it with the elements in the sorted portion
 *     (to its left) and shift all larger elements one position to the right.
 *   - Insert the current element into its correct position.
 *
 * Time Complexity:
 *   - Worst-case: O(n^2) when the array is sorted in reverse order.
 *   - Best-case: O(n) when the array is already sorted.
 *
 * Space Complexity:
 *   - O(1) extra space.
 *
 * Example Test Cases:
 *   1) arr = [12, 11, 13, 5, 6]
 *      Expected Sorted output: [5, 6, 11, 12, 13]
 *
 *   2) arr = [4, 3, 2, 10, 12, 1, 5, 6]
 *      Expected Sorted output: [1, 2, 3, 4, 5, 6, 10, 12]
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 18_insertion_sort.cpp -o 18_insertion_sort
 *     ./18_insertion_sort
 *
 *   Windows:
 *     g++ 18_insertion_sort.cpp -o 18_insertion_sort.exe
 *     18_insertion_sort
 */

// Function to perform Insertion Sort on the array 'arr'
void insertionSort(vector<int>& arr) {
    int n = arr.size();

    // Loop from the second element to the end of the array
    for (int i = 1; i < n; i++) {
        // 'key' is the element to be inserted into the sorted portion
        int key = arr[i];
        int j = i - 1;

        // Shift elements of arr[0..i-1] that are greater than 'key' to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        // Insert the 'key' at its correct position
        arr[j + 1] = key;
    }
}

// Helper function to print the elements of the array
void printArray(const vector<int>& arr) {
    cout << "[";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i != arr.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    // Test Case 1
    vector<int> arr1 = {12, 11, 13, 5, 6};
    cout << "Test Case 1: ";
    printArray(arr1);
    insertionSort(arr1);
    cout << "Sorted: ";
    printArray(arr1);
    // Expected output: [5, 6, 11, 12, 13]

    cout << endl;

    // Test Case 2
    vector<int> arr2 = {4, 3, 2, 10, 12, 1, 5, 6};
    cout << "Test Case 2: ";
    printArray(arr2);
    insertionSort(arr2);
    cout << "Sorted: ";
    printArray(arr2);
    // Expected output: [1, 2, 3, 4, 5, 6, 10, 12]

    cout << endl;

    // Test Case 3 (Already Sorted)
    vector<int> arr3 = {1, 2, 3, 4, 5};
    cout << "Test Case 3 (Already Sorted): ";
    printArray(arr3);
    insertionSort(arr3);
    cout << "Sorted: ";
    printArray(arr3);
    // Expected output: [1, 2, 3, 4, 5]

    return 0;
}
