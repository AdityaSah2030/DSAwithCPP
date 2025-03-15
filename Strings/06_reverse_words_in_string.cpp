#include <iostream>
#include <algorithm>  // for std::reverse
#include <string>
using namespace std;

/*
 * File: 06_reverse_words_in_string.cpp
 * Description (LeetCode #151):
 *   Given an input string s, reverse the order of the words.
 *   A word is defined as a sequence of non-space characters.
 *   The words are separated by at least one space.
 *   Return a string of the words in reverse order, with a single space between words,
 *   and no leading or trailing spaces.
 *
 * Example:
 *   Input:  "the sky is blue"
 *   Output: "blue is sky the"
 *
 * Approach:
 *   1) Reverse the entire string 's'.
 *   2) Parse the reversed string to extract each word (split by spaces).
 *   3) Reverse each extracted word to restore its characters in correct order.
 *   4) Accumulate these reversed words (with a single space) in 'ans'.
 *   5) Return 'ans' (trim leading space if it exists).
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 06_reverse_words_in_string.cpp -o reverse_words
 *     ./reverse_words
 *
 *   Windows:
 *     g++ 06_reverse_words_in_string.cpp -o reverse_words.exe
 *     reverse_words
 */

// Function to reverse the words in a string
string reverseWords(string s) {
    int n = s.length();

    // 1) Reverse the entire string
    reverse(s.begin(), s.end());

    // 2) Parse reversed string to get each word
    string ans;
    for (int i = 0; i < n; ) {
        // Skip any spaces
        if (s[i] == ' ') {
            i++;
            continue;
        }

        // Accumulate characters for the current word
        string word;
        while (i < n && s[i] != ' ') {
            word.push_back(s[i]);
            i++;
        }

        // 3) Reverse the extracted word so its characters are in original order
        reverse(word.begin(), word.end());

        // 4) Append to 'ans' if 'word' is non-empty
        if (!word.empty()) {
            ans += " " + word;
        }
    }

    // 5) Trim leading space if 'ans' is not empty
    // The first character of 'ans' will be ' ' if we added any word
    if (!ans.empty()) {
        return ans.substr(1); // remove the leading space
    }
    return ans;
}

int main() {
    // Example 1
    {
        string input = "the sky is blue";
        cout << "Input: \"" << input << "\"" << endl;
        string output = reverseWords(input);
        cout << "Output: \"" << output << "\"" << endl;
        // Expected: "blue is sky the"
    }

    cout << endl;

    // Example 2
    {
        string input = "  hello world  ";
        cout << "Input: \"" << input << "\"" << endl;
        string output = reverseWords(input);
        cout << "Output: \"" << output << "\"" << endl;
        // Expected: "world hello"
    }

    cout << endl;

    // Let user test with custom input
    {
        cout << "Enter a string to reverse its words: ";
        string userInput;
        getline(cin, userInput);
        string output = reverseWords(userInput);
        cout << "Reversed words: \"" << output << "\"" << endl;
    }

    return 0;
}
