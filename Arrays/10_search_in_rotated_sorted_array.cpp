#include <iostream>
#include <vector>
using namespace std;

/*
 * Program: 10_search_in_rotated_sorted_array.cpp
 * Description:
 *   You are given an integer array nums sorted in ascending order (with distinct values).
 *   The array is possibly rotated at an unknown pivot index so that the resulting array
 *   may look like [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]].
 *
 *   Given nums (after rotation) and an integer target, return the index of target if it
 *   is in nums, or -1 if it is not in nums. We aim for O(log n) time complexity.
 *
 * Approach (Modified Binary Search):
 *   1. Initialize start = 0, end = n - 1.
 *   2. While start <= end:
 *      - mid = start + (end - start) / 2
 *      - If nums[mid] == target, return mid.
 *      - Check which half is sorted:
 *         a) If nums[start] <= nums[mid], then the left half [start...mid] is sorted.
 *            i) If target lies in [nums[start], nums[mid]], move end = mid - 1.
 *            ii) Else, move start = mid + 1.
 *         b) Else, the right half [mid...end] is sorted.
 *            i) If target lies in [nums[mid], nums[end]], move start = mid + 1.
 *            ii) Else, move end = mid - 1.
 *   3. If not found, return -1.
 *
 * Example Test Cases:
 *
 *   1) nums = [4,5,6,7,0,1,2], target = 0
 *      Expected output: 4
 *
 *   2) nums = [4,5,6,7,0,1,2], target = 3
 *      Expected output: -1 (not found)
 *
 *   3) nums = [1], target = 0
 *      Expected output: -1
 *
 *   4) nums = [1], target = 1
 *      Expected output: 0
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 10_search_in_rotated_sorted_array.cpp -o 10_search_in_rotated_sorted_array
 *     ./10_search_in_rotated_sorted_array
 *
 *   Windows:
 *     g++ 10_search_in_rotated_sorted_array.cpp -o 10_search_in_rotated_sorted_array.exe
 *     10_search_in_rotated_sorted_array
 */

// Function that implements modified binary search
int searchInRotatedSortedArray(const vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        // If we found the target
        if (nums[mid] == target) {
            return mid;
        }

        // Determine which half is sorted
        if (nums[start] <= nums[mid]) {
            // Left half is sorted
            if (target >= nums[start] && target < nums[mid]) {
                end = mid - 1;  // target is in the left half
            } else {
                start = mid + 1; // target is in the right half
            }
        } else {
            // Right half is sorted
            if (target > nums[mid] && target <= nums[end]) {
                start = mid + 1;  // target is in the right half
            } else {
                end = mid - 1;    // target is in the left half
            }
        }
    }

    // If we exit the loop, the target is not found
    return -1;
}

int main() {
    // Test Case 1
    vector<int> nums1 = {4,5,6,7,0,1,2};
    int target1 = 0;
    cout << "Test Case 1: nums = [4,5,6,7,0,1,2], target = 0" << endl;
    cout << "Result Index: " << searchInRotatedSortedArray(nums1, target1) << endl;
    // Expected output: 4

    cout << endl;

    // Test Case 2
    vector<int> nums2 = {4,5,6,7,0,1,2};
    int target2 = 3;
    cout << "Test Case 2: nums = [4,5,6,7,0,1,2], target = 3" << endl;
    cout << "Result Index: " << searchInRotatedSortedArray(nums2, target2) << endl;
    // Expected output: -1

    cout << endl;

    // Test Case 3
    vector<int> nums3 = {1};
    int target3 = 0;
    cout << "Test Case 3: nums = [1], target = 0" << endl;
    cout << "Result Index: " << searchInRotatedSortedArray(nums3, target3) << endl;
    // Expected output: -1

    cout << endl;

    // Test Case 4
    vector<int> nums4 = {1};
    int target4 = 1;
    cout << "Test Case 4: nums = [1], target = 1" << endl;
    cout << "Result Index: " << searchInRotatedSortedArray(nums4, target4) << endl;
    // Expected output: 0

    return 0;
}
