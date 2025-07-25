#include <iostream>
#include <vector>
#include <numeric> // For std::accumulate, though not used in this approach

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> currentCombination;
        // Start the backtracking process from index 0
        backtrack(result, candidates, target, currentCombination, 0, 0);
        return result;
    }

private:
    void backtrack(
        vector<vector<int>>& result,
        const vector<int>& candidates,
        int target,
        vector<int>& currentCombination,
        int currentSum,
        int start) {

        // Base case: success! Found a valid combination.
        if (currentSum == target) {
            result.push_back(currentCombination);
            return;
        }

        // Base case: failure. This path is invalid.
        if (currentSum > target) {
            return;
        }

        // Loop through candidates starting from the 'start' index
        for (int i = start; i < candidates.size(); ++i) {
            // 1. Choose the candidate
            currentCombination.push_back(candidates[i]);
            
            // 2. Explore: Recurse. Pass 'i' itself to allow reuse of the same element.
            backtrack(result, candidates, target, currentCombination, currentSum + candidates[i], i);
            
            // 3. Unchoose (Backtrack): Remove the candidate to try the next one
            currentCombination.pop_back();
        }
    }
};