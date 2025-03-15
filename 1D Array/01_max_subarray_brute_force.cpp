#include <iostream>
#include <vector>
#include <climits>  // For INT_MIN
using namespace std;

/*
 * Program: 01_max_subarray_brute_force.cpp
 * Description:
 *   Finds the subarray within an integer array that has the largest sum using
 *   a brute force approach (O(n^2) time complexity).
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
 *     g++ 01_max_subarray_brute_force.cpp -o 01_max_subarray_brute_force
 *     ./01_max_subarray_brute_force
 *
 *   For Windows:
 *     g++ 01_max_subarray_brute_force.cpp -o 01_max_subarray_brute_force.exe
 *     01_max_subarray_brute_force
 */

// Brute force function to find maximum subarray sum
int maxSubArrayBruteForce(const vector<int>& nums) {
    int n = nums.size();
    int maxSum = INT_MIN;

    // Check every possible subarray from i to j
    for (int i = 0; i < n; i++) {
        int currentSum = 0;
        for (int j = i; j < n; j++) {
            // Add the current element to the running sum
            currentSum += nums[j];
            // Update maxSum if needed
            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
        }
    }

    return maxSum;
}

int main() {
    // Example test case 1
    vector<int> nums1 = {1, 2, 3, -2, 5};
    cout << "Test Case 1: [1, 2, 3, -2, 5]" << endl;
    cout << "Maximum Subarray Sum (Brute Force): " 
         << maxSubArrayBruteForce(nums1) << endl;
    // Expected output: 9

    cout << endl;

    // Example test case 2
    vector<int> nums2 = {-2, -3, -1};
    cout << "Test Case 2: [-2, -3, -1]" << endl;
    cout << "Maximum Subarray Sum (Brute Force): " 
         << maxSubArrayBruteForce(nums2) << endl;
    // Expected output: -1

    cout << endl;

    // Example test case 3
    vector<int> nums3 = {5, 4, -1, 7, 8};
    cout << "Test Case 3: [5, 4, -1, 7, 8]" << endl;
    cout << "Maximum Subarray Sum (Brute Force): " 
         << maxSubArrayBruteForce(nums3) << endl;
    // Expected output: 23

    return 0;
}
