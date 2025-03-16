#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
 * File: 28_subarray_sum_equals_k.cpp
 * Description (LeetCode #560):
 *   Given an array of integers nums and an integer k, return the total number
 *   of subarrays whose sum equals k.
 *   A subarray is a contiguous non-empty sequence of elements within an array.
 *
 * Example 1:
 *   Input: nums = [1,1,1], k = 2
 *   Output: 2
 *   Explanation:
 *     Subarrays [1,1] (the first two elements) and [1,1] (the last two elements) both sum to 2.
 *
 * Example 2:
 *   Input: nums = [1,2,3], k = 3
 *   Output: 2
 *   Explanation:
 *     Subarrays [1,2], [3] both sum to 3.
 *
 * Approach (Prefix Sum + Hashing):
 *   1) Maintain a running prefix sum 'currSum' as we iterate through nums.
 *   2) We store counts of prefix sums in an unordered_map 'prefixCount'.
 *   3) For each 'currSum':
 *        - The number of subarrays ending here with sum k is prefixCount[currSum - k].
 *        - Then increment prefixCount[currSum].
 *   4) Initialize prefixCount[0] = 1 (empty prefix).
 *   5) The final count is the total number of subarrays summing to k.
 *
 * Time Complexity: O(n), where n is the length of nums.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 28_subarray_sum_equals_k.cpp -o subarray_sum_k
 *     ./subarray_sum_k
 *
 *   Windows:
 *     g++ 28_subarray_sum_equals_k.cpp -o subarray_sum_k.exe
 *     subarray_sum_k
 */

// Function to count subarrays summing to k
int subarraySum(vector<int>& nums, int k) {
    unordered_map<long long,int> prefixCount; 
    prefixCount[0] = 1;  // One way to have sum 0 with no elements

    long long currSum = 0;
    int count = 0;

    for (int num : nums) {
        currSum += num;
        // Check if (currSum - k) exists in prefixCount
        long long need = currSum - k;
        if (prefixCount.find(need) != prefixCount.end()) {
            count += prefixCount[need];
        }
        // Update prefixCount for currSum
        prefixCount[currSum]++;
    }

    return count;
}

int main() {
    // Example usage 1
    {
        vector<int> nums = {1, 1, 1};
        int k = 2;
        cout << "Input nums = [1,1,1], k = 2" << endl;
        int result = subarraySum(nums, k);
        cout << "Output: " << result << endl;  // Expected: 2
    }

    cout << endl;

    // Example usage 2
    {
        vector<int> nums = {1, 2, 3};
        int k = 3;
        cout << "Input nums = [1,2,3], k = 3" << endl;
        int result = subarraySum(nums, k);
        cout << "Output: " << result << endl;  // Expected: 2
    }

    cout << endl;

    // Custom input
    {
        cout << "Enter the size of array: ";
        int n; 
        cin >> n;
        vector<int> arr(n);
        cout << "Enter the elements of the array: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << "Enter the value of k: ";
        int k; 
        cin >> k;

        int result = subarraySum(arr, k);
        cout << "Number of subarrays summing to " << k << " is: " << result << endl;
    }

    return 0;
}
