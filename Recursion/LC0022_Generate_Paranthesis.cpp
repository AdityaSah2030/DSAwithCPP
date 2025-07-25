#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        // Start the backtracking process
        backtrack(result, "", n, n);
        return result;
    }

private:
    // Helper function to perform backtracking
    // current: the string being built
    // openLeft: number of '(' remaining to be placed
    // closeLeft: number of ')' remaining to be placed
    void backtrack(vector<string>& result, string current, int openLeft, int closeLeft) {
        // Base case: if we've used all parentheses, we've found a valid combination
        if (openLeft == 0 && closeLeft == 0) {
            result.push_back(current);
            return;
        }

        // --- Recursive Step 1: Try placing an open parenthesis ---
        // We can only do this if we have any open parentheses left
        if (openLeft > 0) {
            backtrack(result, current + '(', openLeft - 1, closeLeft);
        }

        // --- Recursive Step 2: Try placing a closing parenthesis ---
        // We can only do this if the number of closing parentheses left is
        // greater than the number of open ones left. This elegantly ensures
        // that we never have more ')' than '(' in any prefix of the string.
        if (closeLeft > openLeft) {
            backtrack(result, current + ')', openLeft, closeLeft - 1);
        }
    }
};