#include <iostream>
#include <vector>
using namespace std;

/*
 * Program: 12_single_element_in_sorted_array.cpp
 * Description:
 *   You are given a sorted array consisting of only integers where every element
 *   appears exactly twice, except for one element which appears exactly once.
 *   Return that single element. The solution must run in O(log n) time and O(1) space.
 *
 * Approach (Binary Search on Pairs):
 *   - We know the array is sorted, and all elements except one appear in pairs.
 *   - Use a binary search to find the index of the single element:
 *     1. Let mid be the midpoint of the current range.
 *     2. We want to compare pairs (mid with mid+1) or (mid with mid-1),
 *        but we need to ensure mid is always pointing to the start of a pair.
 *     3. If mid is even, we'll compare nums[mid] with nums[mid + 1].
 *        If they are equal, it means the single element must be in the second half
 *        (move left = mid + 2). Otherwise, it's in the first half (right = mid).
 *     4. If mid is odd, we'll compare nums[mid] with nums[mid - 1].
 *        If they are equal, the single element is in the second half (left = mid + 1),
 *        otherwise in the first half (right = mid - 1).
 *   - Eventually, when left == right, that index will be the single element.
 *
 * Example Test Cases:
 *   1) nums = [1,1,2,3,3,4,4,8,8]
 *      Output: 2
 *   2) nums = [3,3,7,7,10,11,11]
 *      Output: 10
 *
 * Constraints:
 *   - 1 <= nums.length <= 10^5
 *   - 0 <= nums[i] <= 10^5
 *   - nums.length is odd.
 *   - There is exactly one element that appears once, and all others appear twice.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 12_single_element_in_sorted_array.cpp -o 12_single_element_in_sorted_array
 *     ./12_single_element_in_sorted_array
 *
 *   Windows:
 *     g++ 12_single_element_in_sorted_array.cpp -o 12_single_element_in_sorted_array.exe
 *     12_single_element_in_sorted_array
 */

// Function to find the single element using binary search
int singleNonDuplicate(const vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        // Check if mid is even or odd to align with pair start
        bool isMidEven = (mid % 2 == 0);

        if (isMidEven) {
            // If mid is even, compare with mid + 1
            if (nums[mid] == nums[mid + 1]) {
                // Single element is in the second half
                left = mid + 2;
            } else {
                // Single element is in the first half
                right = mid;
            }
        } else {
            // If mid is odd, compare with mid - 1
            if (nums[mid] == nums[mid - 1]) {
                // Single element is in the second half
                left = mid + 1;
            } else {
                // Single element is in the first half
                right = mid - 1;
            }
        }
    }

    // When left == right, we've found the single element
    return nums[left];
}

int main() {
    // Test Case 1
    vector<int> nums1 = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << "Test Case 1: [1, 1, 2, 3, 3, 4, 4, 8, 8]" << endl;
    cout << "Single Element: " << singleNonDuplicate(nums1) << endl;
    // Expected output: 2

    cout << endl;

    // Test Case 2
    vector<int> nums2 = {3, 3, 7, 7, 10, 11, 11};
    cout << "Test Case 2: [3, 3, 7, 7, 10, 11, 11]" << endl;
    cout << "Single Element: " << singleNonDuplicate(nums2) << endl;
    // Expected output: 10

    cout << endl;

    // Additional Test Case
    vector<int> nums3 = {1, 1, 2};
    cout << "Test Case 3: [1, 1, 2]" << endl;
    cout << "Single Element: " << singleNonDuplicate(nums3) << endl;
    // Expected output: 2

    return 0;
}
