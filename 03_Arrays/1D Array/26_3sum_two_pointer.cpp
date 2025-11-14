#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * File: 26_3sum_two_pointer.cpp
 * Description (LeetCode #15):
 *   Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
 *   such that nums[i] + nums[j] + nums[k] = 0, and i, j, k are distinct.
 *   The solution set must not contain duplicate triplets.
 *
 * Approach (Sorting + Two Pointers):
 *   1) Sort nums.
 *   2) For each i in [0..n-3]:
 *        - If i > 0 and nums[i] == nums[i-1], skip (avoid duplicates).
 *        - Let left = i+1, right = n-1
 *        - While left < right:
 *            sum = nums[i] + nums[left] + nums[right]
 *            if sum == 0, we found a triplet -> push to result, move left, right
 *              skip duplicates for left, skip duplicates for right
 *            else if sum < 0, move left++
 *            else if sum > 0, move right--
 *   3) Return result.
 *
 * Time Complexity: O(n^2).
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 26_3sum_two_pointer.cpp -o 3sum_two_pointer
 *     ./3sum_two_pointer
 *
 *   Windows:
 *     g++ 26_3sum_two_pointer.cpp -o 3sum_two_pointer.exe
 *     3sum_two_pointer
 */

vector<vector<int>> threeSumTwoPointer(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        // Skip duplicates for i
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                // Found a triplet
                result.push_back({nums[i], nums[left], nums[right]});

                // Move left, skipping duplicates
                int leftVal = nums[left];
                while (left < right && nums[left] == leftVal) {
                    left++;
                }

                // Move right, skipping duplicates
                int rightVal = nums[right];
                while (left < right && nums[right] == rightVal) {
                    right--;
                }
            } else if (sum < 0) {
                left++;
            } else { // sum > 0
                right--;
            }
        }
    }

    return result;
}

int main() {
    // Example usage
    {
        vector<int> nums = {-1, 0, 1, 2, -1, -4};
        cout << "Input: ";
        for (auto val : nums) {
            cout << val << " ";
        }
        cout << endl;

        vector<vector<int>> ans = threeSumTwoPointer(nums);
        cout << "Output triplets:\n";
        for (auto &trip : ans) {
            cout << "[";
            for (int i = 0; i < (int)trip.size(); i++) {
                cout << trip[i] << (i+1 < (int)trip.size() ? "," : "");
            }
            cout << "] ";
        }
        cout << endl;
        // Expected: [[-1,-1,2],[-1,0,1]] (order may vary)
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

        vector<vector<int>> ans = threeSumTwoPointer(arr);
        cout << "Triplets that sum to 0:\n";
        for (auto &trip : ans) {
            cout << "[";
            for (int i = 0; i < (int)trip.size(); i++) {
                cout << trip[i] << (i+1 < (int)trip.size() ? "," : "");
            }
            cout << "] ";
        }
        cout << endl;
    }

    return 0;
}
