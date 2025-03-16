#include <iostream>
#include <vector>
#include <algorithm> // for sort
#include <unordered_set>
using namespace std;

/*
 * File: 25_3sum_hashing.cpp
 * Description (LeetCode #15):
 *   Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
 *   such that nums[i] + nums[j] + nums[k] = 0, and i, j, k are distinct.
 *   The solution set must not contain duplicate triplets.
 *
 * Approach (Hashing):
 *   - For each element nums[i], we want to find two-sum = -nums[i] in the subarray i+1..end.
 *   - We'll use an unordered_set (or map) to find pairs that sum up to -nums[i].
 *   - We also need to ensure no duplicates in the final answer.
 *
 * Steps:
 *   1) Sort the array (optional, but helps with deduping final results).
 *   2) Iterate i from 0 to n-2:
 *        - If i > 0 and nums[i] == nums[i-1], skip to avoid duplicates for the i-th element.
 *        - For each i, define target = -nums[i].
 *        - Use a set or map to find pairs in subarray i+1..end that sum to target.
 *        - Insert found triplets into a set (or we can handle duplicates carefully).
 *   3) Convert the set to a vector of vectors to return.
 *
 * Time Complexity: O(n^2) on average if using an efficient hash set approach.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 25_3sum_hashing.cpp -o 3sum_hashing
 *     ./3sum_hashing
 *
 *   Windows:
 *     g++ 25_3sum_hashing.cpp -o 3sum_hashing.exe
 *     3sum_hashing
 */

vector<vector<int>> threeSumHashing(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end()); // sort for easy dedup

    int n = nums.size();
    for (int i = 0; i < n; i++) {
        // Avoid duplicates for nums[i]
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        int target = -nums[i];
        unordered_set<int> seen;
        for (int j = i + 1; j < n; j++) {
            int needed = target - nums[j];
            if (seen.find(needed) != seen.end()) {
                // Found a pair (nums[j], needed) that sums to target
                vector<int> triplet = {nums[i], nums[j], needed};
                sort(triplet.begin(), triplet.end());
                result.push_back(triplet);
                // Avoid duplicates for the second element
                while (j + 1 < n && nums[j] == nums[j + 1]) {
                    j++;
                }
            } else {
                seen.insert(nums[j]);
            }
        }
    }

    // We might have duplicates in result if the same triplet is formed multiple times
    // so we can deduplicate them now
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());

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

        vector<vector<int>> ans = threeSumHashing(nums);
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

        vector<vector<int>> ans = threeSumHashing(arr);
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
