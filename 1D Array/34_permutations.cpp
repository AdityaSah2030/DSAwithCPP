#include <iostream>
#include <vector>
using namespace std;

/*
 * File: 34_permutations.cpp
 * Description (LeetCode #46):
 *   Given an array nums of distinct integers, return all the possible permutations.
 *   You can return the answer in any order.
 *
 * Example 1:
 *   Input: nums = [1,2,3]
 *   Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 *
 * Example 2:
 *   Input: nums = [0,1]
 *   Output: [[0,1],[1,0]]
 *
 * Approach (Backtracking by Swapping):
 *   1) We define a recursive function permuteHelper(nums, start):
 *       - If start == nums.size(), we've formed a permutation -> store it.
 *       - Otherwise, for i in [start..end]:
 *           * swap(nums[start], nums[i])
 *           * recurse with start+1
 *           * swap back to restore
 *   2) This approach generates all permutations in O(n!) time.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 34_permutations.cpp -o permutations
 *     ./permutations
 *
 *   Windows:
 *     g++ 34_permutations.cpp -o permutations.exe
 *     permutations
 */

// Recursive helper function
void permuteHelper(vector<int>& nums, int start, vector<vector<int>>& result) {
    if (start == (int)nums.size()) {
        // We've formed a complete permutation
        result.push_back(nums);
        return;
    }

    for (int i = start; i < (int)nums.size(); i++) {
        // Swap nums[start] and nums[i]
        swap(nums[start], nums[i]);
        // Recurse for next index
        permuteHelper(nums, start + 1, result);
        // Swap back (backtrack)
        swap(nums[start], nums[i]);
    }
}

// Main function returning all permutations
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    permuteHelper(nums, 0, result);
    return result;
}

int main() {
    // Example usage 1
    {
        vector<int> nums = {1, 2, 3};
        cout << "Input: [1,2,3]" << endl;
        vector<vector<int>> ans = permute(nums);
        cout << "Permutations:\n";
        for (auto &perm : ans) {
            cout << "[";
            for (int i = 0; i < (int)perm.size(); i++) {
                cout << perm[i];
                if (i + 1 < (int)perm.size()) cout << ",";
            }
            cout << "] ";
        }
        cout << endl;
        // Expected: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
    }

    cout << endl;

    // Custom input
    {
        cout << "Enter the number of elements: ";
        int n;
        cin >> n;
        vector<int> arr(n);
        cout << "Enter the distinct elements:\n";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<vector<int>> ans = permute(arr);
        cout << "All permutations:\n";
        for (auto &perm : ans) {
            cout << "[";
            for (int i = 0; i < (int)perm.size(); i++) {
                cout << perm[i];
                if (i + 1 < (int)perm.size()) cout << ",";
            }
            cout << "] ";
        }
        cout << endl;
    }

    return 0;
}
