#include <iostream>
#include <vector>
using namespace std;

/*
 * File: 32_subsets_return.cpp
 * Description (LeetCode #78):
 *   Given an integer array nums of unique elements, return all possible
 *   subsets (the power set). The solution set must not contain duplicate subsets.
 *
 * Example:
 *   Input: nums = [1,2,3]
 *   Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 *
 * Approach (Backtracking):
 *   1) We define a helper function that explores two choices at each index i:
 *        - Include nums[i] in the current subset.
 *        - Exclude nums[i].
 *   2) When we reach i == nums.size(), we have formed one subset, so we add it to the result.
 *   3) We store all subsets in a global or pass-by-reference vector<vector<int>>.
 *   4) Time complexity is O(2^n) to generate all subsets, each subset can be up to length n.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 32_subsets_return.cpp -o subsets_return
 *     ./subsets_return
 *
 *   Windows:
 *     g++ 32_subsets_return.cpp -o subsets_return.exe
 *     subsets_return
 */

// Recursive helper to build subsets
void backtrack(const vector<int>& nums, int i, vector<int>& current, vector<vector<int>>& result) {
    // If we've considered all elements, store the current subset
    if (i == (int)nums.size()) {
        result.push_back(current);
        return;
    }

    // 1) Exclude nums[i]
    backtrack(nums, i + 1, current, result);

    // 2) Include nums[i]
    current.push_back(nums[i]);
    backtrack(nums, i + 1, current, result);
    // Backtrack
    current.pop_back();
}

// Main function that returns all subsets
vector<vector<int>> subsets(const vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    backtrack(nums, 0, current, result);
    return result;
}

int main() {
    // Example usage with a fixed array
    {
        vector<int> nums = {1, 2, 3};
        cout << "Input: [1,2,3]" << endl;
        vector<vector<int>> ans = subsets(nums);

        cout << "All subsets (power set):" << endl;
        for (auto &subset : ans) {
            cout << "[";
            for (int i = 0; i < (int)subset.size(); i++) {
                cout << subset[i];
                if (i + 1 < (int)subset.size()) cout << ",";
            }
            cout << "] ";
        }
        cout << endl;
        // Expected: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]] (order may vary)
    }

    cout << endl;

    // Custom input
    {
        cout << "Enter the size of the array: ";
        int n;
        cin >> n;
        vector<int> arr(n);
        cout << "Enter the " << n << " unique elements:\n";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<vector<int>> ans = subsets(arr);

        cout << "Subsets:\n";
        for (auto &subset : ans) {
            cout << "[";
            for (int i = 0; i < (int)subset.size(); i++) {
                cout << subset[i];
                if (i + 1 < (int)subset.size()) cout << ",";
            }
            cout << "] ";
        }
        cout << endl;
    }

    return 0;
}
