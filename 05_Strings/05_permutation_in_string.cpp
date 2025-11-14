#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 * Program: 05_permutation_in_string.cpp
 * Description:
 *   Given two strings s1 and s2, return true if s2 contains a permutation of s1,
 *   or false otherwise. In other words, return true if one of the substrings of s2
 *   is a rearrangement of s1.
 *
 * Approach (Sliding Window):
 *   1) If s1 is longer than s2, it's impossible for s2 to contain a permutation of s1 -> return false.
 *   2) Maintain a frequency count of characters in s1 (freqS1).
 *   3) Use a sliding window of length s1.size() in s2 to check each substring of that length.
 *      - Maintain a frequency count for the current window in s2 (freqWin).
 *      - After moving the window, update freqWin accordingly (increment for new char, decrement for removed char).
 *      - If freqWin == freqS1 at any point, we have found a valid permutation -> return true.
 *   4) If we finish scanning without a match, return false.
 *
 * Example:
 *   s1 = "ab", s2 = "eidbaooo"
 *   Substrings of length 2 in s2: "ei", "id", "db", "ba", "ao", "oo", "oo"
 *   "ba" is a permutation of "ab" -> return true
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 05_permutation_in_string.cpp -o 05_permutation_in_string
 *     ./05_permutation_in_string
 *
 *   Windows:
 *     g++ 05_permutation_in_string.cpp -o 05_permutation_in_string.exe
 *     05_permutation_in_string
 */

// Check if s2 contains a permutation of s1
bool checkInclusion(const string &s1, const string &s2) {
    int n1 = s1.size();
    int n2 = s2.size();

    // Quick check: if s1 is longer than s2, no solution
    if (n1 > n2) return false;

    // Frequency arrays for 'a' to 'z'
    vector<int> freqS1(26, 0), freqWin(26, 0);

    // Build frequency for s1
    for (char c : s1) {
        freqS1[c - 'a']++;
    }

    // Initialize the first window of size n1 in s2
    for (int i = 0; i < n1; i++) {
        freqWin[s2[i] - 'a']++;
    }

    // If the first window matches freqS1, return true
    if (freqWin == freqS1) return true;

    // Slide over s2
    for (int i = n1; i < n2; i++) {
        // Add new char
        freqWin[s2[i] - 'a']++;
        // Remove old char
        freqWin[s2[i - n1] - 'a']--;

        // Check if matches freqS1
        if (freqWin == freqS1) {
            return true;
        }
    }

    return false;
}

int main() {
    // Example Test 1
    {
        string s1 = "ab";
        string s2 = "eidbaooo";
        cout << "s1 = \"" << s1 << "\", s2 = \"" << s2 << "\" -> ";
        bool ans = checkInclusion(s1, s2);
        cout << (ans ? "true" : "false") << endl; // Expected: true
    }

    // Example Test 2
    {
        string s1 = "ab";
        string s2 = "eidboaoo";
        cout << "s1 = \"" << s1 << "\", s2 = \"" << s2 << "\" -> ";
        bool ans = checkInclusion(s1, s2);
        cout << (ans ? "true" : "false") << endl; // Expected: false
    }

    // Custom user input
    cout << "\nEnter s1: ";
    string s1, s2;
    cin >> s1;
    cout << "Enter s2: ";
    cin >> s2;

    bool ans = checkInclusion(s1, s2);
    cout << (ans ? "Yes, s2 contains a permutation of s1" : "No, s2 does not contain any permutation of s1") << endl;

    return 0;
}
