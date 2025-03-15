#include <iostream>
#include <vector>
using namespace std;

/*
 * Program: 16_bubble_sort.cpp
 * Description:
 *   Demonstrates the Bubble Sort algorithm in C++.
 *   Bubble Sort repeatedly swaps adjacent elements if they are in the wrong order.
 *   This process is repeated until no more swaps are needed or the array is fully sorted.
 *
 *   Time Complexity: O(n^2) in the worst case
 *   Space Complexity: O(1) extra space
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
 *     g++ 16_bubble_sort.cpp -o 16_bubble_sort
 *     ./16_bubble_sort
 *
 *   Windows:
 *     g++ 16_bubble_sort.cpp -o 16_bubble_sort.exe
 *     16_bubble_sort
 */

// Function to perform Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    // We need up to (n-1) passes to ensure the array is sorted
    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        // In the i-th pass, compare each pair of adjacent elements
        // and swap if they are out of order
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }

        // If no swaps occurred in this pass, the array is already sorted
        if (!swapped) {
            break;
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
    bubbleSort(arr1);
    cout << "Sorted: ";
    printArray(arr1);
    // Expected output: [11, 12, 22, 25, 64]

    cout << endl;

    // Test Case 2
    vector<int> arr2 = {5, 1, 4, 2, 8};
    cout << "Test Case 2: ";
    printArray(arr2);
    bubbleSort(arr2);
    cout << "Sorted: ";
    printArray(arr2);
    // Expected output: [1, 2, 4, 5, 8]

    cout << endl;

    // Test Case 3 (already sorted)
    vector<int> arr3 = {1, 2, 3, 4, 5};
    cout << "Test Case 3 (already sorted): ";
    printArray(arr3);
    bubbleSort(arr3);
    cout << "Sorted: ";
    printArray(arr3);
    // Expected output: [1, 2, 3, 4, 5]

    return 0;
}
