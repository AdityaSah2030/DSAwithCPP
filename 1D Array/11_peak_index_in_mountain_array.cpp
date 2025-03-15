#include <iostream>
#include <vector>
using namespace std;

/*
 * Program: 11_peak_index_in_mountain_array.cpp
 * Description:
 *   We have a "mountain array" where elements strictly increase
 *   to a peak, then strictly decrease. We need to find the index
 *   of the peak element (the highest value).
 *
 *   This solution uses a binary search approach to achieve O(log n) time.
 *
 * Approach (Binary Search for Peak):
 *   1. Initialize two pointers: left = 0, right = n - 1.
 *   2. While left < right:
 *      - mid = left + (right - left) / 2
 *      - If arr[mid] < arr[mid + 1], then the peak must be to the right,
 *        so set left = mid + 1.
 *      - Otherwise, the peak is at mid or to the left, so set right = mid.
 *   3. After the loop, left == right, which is the index of the peak.
 *
 * Example Test Cases:
 *   1) arr = [0, 1, 0]
 *      - Peak index: 1
 *
 *   2) arr = [0, 2, 1, 0]
 *      - Peak index: 1
 *
 *   3) arr = [0, 10, 5, 2]
 *      - Peak index: 1
 *
 * Constraints:
 *   - 3 <= arr.length <= 10^5
 *   - 0 <= arr[i] <= 10^6
 *   - arr is guaranteed to be a mountain array (strictly increasing, then strictly decreasing).
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 11_peak_index_in_mountain_array.cpp -o 11_peak_index_in_mountain_array
 *     ./11_peak_index_in_mountain_array
 *
 *   Windows:
 *     g++ 11_peak_index_in_mountain_array.cpp -o 11_peak_index_in_mountain_array.exe
 *     11_peak_index_in_mountain_array
 */

// Function to find the peak index in a mountain array
int peakIndexInMountainArray(const vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;

    // Binary search loop
    while (left < right) {
        int mid = left + (right - left) / 2;

        // Compare arr[mid] and arr[mid + 1]
        if (arr[mid] < arr[mid + 1]) {
            // Peak is to the right
            left = mid + 1;
        } else {
            // Peak is at mid or to the left
            right = mid;
        }
    }

    // When the loop ends, left == right, which should be the peak index
    return left;
}

int main() {
    // Test Case 1
    vector<int> arr1 = {0, 1, 0};
    cout << "Test Case 1: [0, 1, 0]" << endl;
    cout << "Peak Index: " << peakIndexInMountainArray(arr1) << endl;
    // Expected output: 1

    cout << endl;

    // Test Case 2
    vector<int> arr2 = {0, 2, 1, 0};
    cout << "Test Case 2: [0, 2, 1, 0]" << endl;
    cout << "Peak Index: " << peakIndexInMountainArray(arr2) << endl;
    // Expected output: 1

    cout << endl;

    // Test Case 3
    vector<int> arr3 = {0, 10, 5, 2};
    cout << "Test Case 3: [0, 10, 5, 2]" << endl;
    cout << "Peak Index: " << peakIndexInMountainArray(arr3) << endl;
    // Expected output: 1

    return 0;
}
