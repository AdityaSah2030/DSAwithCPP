#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

// Using directive to avoid std:: prefix
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            return result;
        }

        unordered_map<char, string> mapping = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        
        backtrack(result, digits, mapping, 0, "");
        return result;
    }

private:
    void backtrack(
        vector<string>& result, 
        const string& digits, 
        const unordered_map<char, string>& mapping, 
        int index, 
        string currentCombination) { // Passed by value

        if (index == digits.length()) {
            result.push_back(currentCombination);
            return;
        }

        char currentDigit = digits[index];
        string letters = mapping.at(currentDigit);

        for (char letter : letters) {
            // Creates a new string and passes it to the next call
            backtrack(result, digits, mapping, index + 1, currentCombination + letter);
        }
    }
};