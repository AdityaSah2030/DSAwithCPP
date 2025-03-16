#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * File: 27_4sum.cpp
 * Description (LeetCode #18):
 *   Given an array of n integers nums and an integer target, return all the
 *   unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
 *     - 0 <= a < b < c < d < n
 *     - nums[a] + nums[b] + nums[c] + nums[d] == target
 *   The solution set must not contain duplicate quadruplets.
 *
 * Approach (Sorting + Two-Pointer Nested):
 *   1) Sort nums.
 *   2) Outer loop over i from 0..n-4:
 *        - Skip duplicates for nums[i].
 *     3) Next loop over j from i+1..n-3:
 *          - Skip duplicates for nums[j].
 *       4) Then do a two-pointer approach for left = j+1, right = n-1:
 *            sum = nums[i] + nums[j] + nums[left] + nums[right]
 *            if sum == target, record quadruplet, skip duplicates for left, right
 *            else if sum < target, left++
 *            else sum > target, right--
 *   5) Return the collected quadruplets.
 *
 * Time Complexity: O(n^3), which is acceptable for typical constraints.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 27_4sum.cpp -o 4sum
 *     ./4sum
 *
 *   Windows:
 *     g++ 27_4sum.cpp -o 4sum.exe
 *     4sum
 */

// Function to find all unique quadruplets summing to target
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        // Skip duplicates for i
        if (i > 0 && nums[i] == nums[i-1]) {
            continue;
        }
        for (int j = i + 1; j < n; j++) {
            // Skip duplicates for j
            if (j > i + 1 && nums[j] == nums[j-1]) {
                continue;
            }

            long long twoSum = (long long)target - (long long)nums[i] - (long long)nums[j];
            int left = j + 1;
            int right = n - 1;

            while (left < right) {
                long long sumLR = (long long)nums[left] + (long long)nums[right];
                if (sumLR == twoSum) {
                    // Found a quadruplet
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});

                    // Skip duplicates for left
                    int leftVal = nums[left];
                    while (left < right && nums[left] == leftVal) {
                        left++;
                    }
                    // Skip duplicates for right
                    int rightVal = nums[right];
                    while (left < right && nums[right] == rightVal) {
                        right--;
                    }
                } else if (sumLR < twoSum) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }

    return result;
}

int main() {
    // Example usage
    {
        vector<int> nums = {1, 0, -1, 0, -2, 2};
        int target = 0;
        cout << "Input: nums = ";
        for (auto val : nums) {
            cout << val << " ";
        }
        cout << ", target = " << target << endl;

        vector<vector<int>> ans = fourSum(nums, target);
        cout << "Output quadruplets:\n";
        for (auto &quad : ans) {
            cout << "[";
            for (int i = 0; i < (int)quad.size(); i++) {
                cout << quad[i] << (i+1 < (int)quad.size() ? "," : "");
            }
            cout << "] ";
        }
        cout << endl;
        // Expected: [[-1,0,0,1],[-2,-1,1,2]]
    }

    // Custom input
    {
        cout << "\nEnter number of elements: ";
        int n;
        cin >> n;
        vector<int> arr(n);
        cout << "Enter the elements: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << "Enter target: ";
        int tgt;
        cin >> tgt;

        vector<vector<int>> ans = fourSum(arr, tgt);
        cout << "Quadruplets that sum to " << tgt << ":\n";
        for (auto &quad : ans) {
            cout << "[";
            for (int i = 0; i < (int)quad.size(); i++) {
                cout << quad[i] << (i+1 < (int)quad.size() ? "," : "");
            }
            cout << "] ";
        }
        cout << endl;
    }

    return 0;
}
