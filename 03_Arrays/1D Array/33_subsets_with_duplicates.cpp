#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * File: 33_subsets_with_duplicates.cpp
 * Description (LeetCode #90):
 *   Given an integer array nums that may contain duplicates, return all possible
 *   subsets (the power set). The solution set must not contain duplicate subsets.
 *   Return the subsets in any order.
 *
 * Example 1:
 *   Input: nums = [1,2,2]
 *   Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
 *
 * Example 2:
 *   Input: nums = [0]
 *   Output: [[],[0]]
 *
 * Approach (Backtracking with Duplicate Skips):
 *   1) Sort nums so duplicates are adjacent.
 *   2) Use a recursive function that, at each level, decides whether to include
 *      each distinct element. For i in [start..end]:
 *        - If i > start and nums[i] == nums[i-1], skip to avoid duplicate subsets at this level.
 *        - Otherwise, include nums[i], recurse, then backtrack.
 *   3) We store subsets in a global or pass-by-reference vector of vectors.
 *   4) Time complexity is O(2^n) in the worst case, but duplicates are pruned.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 33_subsets_with_duplicates.cpp -o subsets_with_duplicates
 *     ./subsets_with_duplicates
 *
 *   Windows:
 *     g++ 33_subsets_with_duplicates.cpp -o subsets_with_duplicates.exe
 *     subsets_with_duplicates
 */

// Recursive backtracking function
void backtrack(const vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& result) {
    // Add the current subset to result
    result.push_back(current);

    for (int i = start; i < (int)nums.size(); i++) {
        // Skip duplicates at the same level
        if (i > start && nums[i] == nums[i-1]) {
            continue;
        }

        // Include nums[i]
        current.push_back(nums[i]);
        // Recurse with i+1
        backtrack(nums, i + 1, current, result);
        // Backtrack
        current.pop_back();
    }
}

// Main function returning all unique subsets
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    // Sort to ensure duplicates are adjacent
    sort(nums.begin(), nums.end());
    // Backtracking from index 0
    backtrack(nums, 0, current, result);
    return result;
}

int main() {
    // Example usage
    {
        vector<int> nums = {1, 2, 2};
        cout << "Input: [1,2,2]" << endl;
        vector<vector<int>> ans = subsetsWithDup(nums);
        cout << "Output subsets:\n";
        for (auto &subset : ans) {
            cout << "[";
            for (int i = 0; i < (int)subset.size(); i++) {
                cout << subset[i];
                if (i + 1 < (int)subset.size()) cout << ",";
            }
            cout << "] ";
        }
        cout << endl;
        // Expected: [[],[1],[1,2],[1,2,2],[2],[2,2]] (order may vary)
    }

    cout << endl;

    // Custom input
    {
        cout << "Enter number of elements: ";
        int n;
        cin >> n;
        vector<int> arr(n);
        cout << "Enter elements (may contain duplicates): ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<vector<int>> ans = subsetsWithDup(arr);
        cout << "Unique subsets:\n";
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
