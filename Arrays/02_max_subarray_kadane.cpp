#include <iostream>
#include <vector>
#include <climits>  // For INT_MIN
using namespace std;

/*
 * Program: 02_max_subarray_kadane.cpp
 * Description:
 *   Finds the subarray within an integer array that has the largest sum using
 *   Kadane's Algorithm (O(n) time complexity).
 *
 * Example Test Cases:
 *
 *   1) nums = [1, 2, 3, -2, 5]
 *      Maximum subarray: [1, 2, 3, -2, 5]
 *      Expected result: 9
 *
 *   2) nums = [-2, -3, -1]
 *      Maximum subarray: [-1]
 *      Expected result: -1
 *
 *   3) nums = [5, 4, -1, 7, 8]
 *      Maximum subarray: [5, 4, -1, 7, 8]
 *      Expected result: 23
 *
 * Steps to Compile and Run:
 *   For Linux/Mac:
 *     g++ 02_max_subarray_kadane.cpp -o 02_max_subarray_kadane
 *     ./02_max_subarray_kadane
 *
 *   For Windows:
 *     g++ 02_max_subarray_kadane.cpp -o 02_max_subarray_kadane.exe
 *     02_max_subarray_kadane
 */

// Kadane's Algorithm to find maximum subarray sum
int maxSubArrayKadane(const vector<int>& nums) {
    // Initialize with the first element or INT_MIN if array could be empty
    int maxSoFar = INT_MIN;     
    int maxEndingHere = 0;

    for (int num : nums) {
        // At each step, either take the current number alone or extend the previous subarray
        maxEndingHere = max(num, maxEndingHere + num);
        // Update the overall max if needed
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    return maxSoFar;
}

int main() {
    // Example test case 1
    vector<int> nums1 = {1, 2, 3, -2, 5};
    cout << "Test Case 1: [1, 2, 3, -2, 5]" << endl;
    cout << "Maximum Subarray Sum (Kadane): " 
         << maxSubArrayKadane(nums1) << endl;
    // Expected output: 9

    cout << endl;

    // Example test case 2
    vector<int> nums2 = {-2, -3, -1};
    cout << "Test Case 2: [-2, -3, -1]" << endl;
    cout << "Maximum Subarray Sum (Kadane): " 
         << maxSubArrayKadane(nums2) << endl;
    // Expected output: -1

    cout << endl;

    // Example test case 3
    vector<int> nums3 = {5, 4, -1, 7, 8};
    cout << "Test Case 3: [5, 4, -1, 7, 8]" << endl;
    cout << "Maximum Subarray Sum (Kadane): " 
         << maxSubArrayKadane(nums3) << endl;
    // Expected output: 23

    return 0;
}
