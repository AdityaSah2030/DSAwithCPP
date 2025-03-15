#include <iostream>
#include <vector>
using namespace std;

/*
 * Program: 03_pair_sum_two_pointer.cpp
 * Description:
 *   Given a sorted array of integers and a target sum, find two elements
 *   in the array such that their sum is equal to the target. We use the
 *   two-pointer approach, which runs in O(n) time.
 *
 * Example Test Cases:
 * 
 *   1) arr = [2, 7, 11, 15], target = 26
 *      Explanation: 11 + 15 = 26
 *      Expected Output: Pair found: (11, 15)
 *
 *   2) arr = [1, 2, 3, 9], target = 8
 *      Explanation: No pair adds up to 8
 *      Expected Output: No pair found
 *
 *   3) arr = [2, 7, 11, 15], target = 9
 *      Explanation: 2 + 7 = 9
 *      Expected Output: Pair found: (2, 7)
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 03_pair_sum_two_pointer.cpp -o 03_pair_sum_two_pointer
 *     ./03_pair_sum_two_pointer
 *
 *   Windows:
 *     g++ 03_pair_sum_two_pointer.cpp -o 03_pair_sum_two_pointer.exe
 *     03_pair_sum_two_pointer
 */

// Function that uses two-pointer technique to find a pair with given target sum
// Returns true if a pair is found, and sets pairVal1 and pairVal2 to that pair's values.
bool twoPointerPairSum(const vector<int>& arr, int target, int &pairVal1, int &pairVal2) {
    // Initialize two pointers: 
    // left at the start (0) and right at the end (arr.size() - 1).
    int left = 0;
    int right = arr.size() - 1;

    // While left pointer is less than right pointer
    while (left < right) {
        int currentSum = arr[left] + arr[right];

        // If we found the target sum, update pairVal1, pairVal2 and return true
        if (currentSum == target) {
            pairVal1 = arr[left];
            pairVal2 = arr[right];
            return true;
        }
        // If current sum is too large, move the right pointer left
        else if (currentSum > target) {
            right--;
        }
        // If current sum is too small, move the left pointer right
        else {
            left++;
        }
    }

    // If we exit the loop, no pair was found
    return false;
}

int main() {
    // Test Case 1
    vector<int> arr1 = {2, 7, 11, 15};
    int target1 = 26;
    int val1, val2;
    cout << "Test Case 1: arr = [2, 7, 11, 15], target = 26" << endl;
    if (twoPointerPairSum(arr1, target1, val1, val2)) {
        cout << "Pair found: (" << val1 << ", " << val2 << ")" << endl;
    } else {
        cout << "No pair found" << endl;
    }
    // Expected Output: Pair found: (11, 15)

    cout << endl;

    // Test Case 2
    vector<int> arr2 = {1, 2, 3, 9};
    int target2 = 8;
    cout << "Test Case 2: arr = [1, 2, 3, 9], target = 8" << endl;
    if (twoPointerPairSum(arr2, target2, val1, val2)) {
        cout << "Pair found: (" << val1 << ", " << val2 << ")" << endl;
    } else {
        cout << "No pair found" << endl;
    }
    // Expected Output: No pair found

    cout << endl;

    // Test Case 3
    vector<int> arr3 = {2, 7, 11, 15};
    int target3 = 9;
    cout << "Test Case 3: arr = [2, 7, 11, 15], target = 9" << endl;
    if (twoPointerPairSum(arr3, target3, val1, val2)) {
        cout << "Pair found: (" << val1 << ", " << val2 << ")" << endl;
    } else {
        cout << "No pair found" << endl;
    }
    // Expected Output: Pair found: (2, 7)

    return 0;
}
