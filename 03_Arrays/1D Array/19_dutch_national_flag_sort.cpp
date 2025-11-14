#include <iostream>
#include <vector>
using namespace std;

/*
 * Program: 19_dutch_national_flag_sort.cpp
 * Description:
 *   Implements the Dutch National Flag algorithm to sort an array of 0s, 1s, and 2s
 *   (commonly referred to as the "Sort Colors" problem in LeetCode #75).
 *
 * Algorithm (Dutch National Flag):
 *   - We maintain three pointers: low, mid, and high.
 *   - low tracks the position where the next 0 should go.
 *   - mid is the current index we are examining.
 *   - high tracks the position where the next 2 should go.
 *   - The algorithm proceeds as follows:
 *       1) If nums[mid] == 0, swap nums[low] and nums[mid], then increment low and mid.
 *       2) If nums[mid] == 2, swap nums[mid] and nums[high], then decrement high
 *          (do not increment mid here, because we need to check the swapped element).
 *       3) If nums[mid] == 1, just increment mid.
 *   - This method ensures all 0s are moved to the front, all 2s to the back, and 1s remain in the middle.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * Example Test Cases:
 *   1) nums = [2, 0, 2, 1, 1, 0]
 *      Expected Output: [0, 0, 1, 1, 2, 2]
 *
 *   2) nums = [2, 0, 1]
 *      Expected Output: [0, 1, 2]
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 19_dutch_national_flag_sort.cpp -o 19_dutch_national_flag_sort
 *     ./19_dutch_national_flag_sort
 *
 *   Windows:
 *     g++ 19_dutch_national_flag_sort.cpp -o 19_dutch_national_flag_sort.exe
 *     19_dutch_national_flag_sort
 */

// Function implementing the Dutch National Flag algorithm
void dutchNationalFlagSort(vector<int>& nums) {
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            // Swap with nums[low], move both pointers
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if (nums[mid] == 2) {
            // Swap with nums[high], move high pointer only
            swap(nums[mid], nums[high]);
            high--;
            // Do not increment mid here
        } else {
            // nums[mid] == 1, just move mid
            mid++;
        }
    }
}

// Helper function to print the array
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
    vector<int> nums1 = {2, 0, 2, 1, 1, 0};
    cout << "Test Case 1 (Before): ";
    printArray(nums1);
    dutchNationalFlagSort(nums1);
    cout << "Test Case 1 (After):  ";
    printArray(nums1);
    // Expected Output: [0, 0, 1, 1, 2, 2]

    cout << endl;

    // Test Case 2
    vector<int> nums2 = {2, 0, 1};
    cout << "Test Case 2 (Before): ";
    printArray(nums2);
    dutchNationalFlagSort(nums2);
    cout << "Test Case 2 (After):  ";
    printArray(nums2);
    // Expected Output: [0, 1, 2]

    cout << endl;

    // Additional Test Case (all zeros)
    vector<int> nums3 = {0, 0, 0};
    cout << "Test Case 3 (Before): ";
    printArray(nums3);
    dutchNationalFlagSort(nums3);
    cout << "Test Case 3 (After):  ";
    printArray(nums3);
    // Expected Output: [0, 0, 0] (unchanged)

    return 0;
}
