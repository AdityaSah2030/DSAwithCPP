#include <iostream>
#include <string>
using namespace std;

/*
 * Program: 04_remove_all_occurrences_of_substring_stl.cpp
 * Description:
 *   This program removes all occurrences of a given substring from a string.
 *   It uses the STL functions `.find()` and `.erase()` to efficiently locate
 *   and remove substrings until none remain.
 *
 * Approach:
 *   - Use `s.find(part)` to locate the first occurrence of `part` in `s`.
 *   - Use `s.erase(pos, part.length())` to remove `part` from `s`.
 *   - Repeat the process until `find(part)` returns `string::npos` (meaning no more occurrences).
 *
 * Example:
 *   Input: s = "daabcbaabcbc", part = "abc"
 *   Output: "dab"
 *
 * Compilation & Execution:
 *   g++ 04_remove_all_occurrences_of_substring_stl.cpp -o remove_substring
 *   ./remove_substring
 */

// Function to remove all occurrences of 'part' in 's'
string removeOccurrences(string s, const string &part) {
    size_t pos;
    while ((pos = s.find(part)) != string::npos) {
        s.erase(pos, part.length());  // Erase 'part' from 's'
    }
    return s;
}

int main() {
    // Example 1
    {
        string s = "daabcbaabcbc";
        string part = "abc";
        cout << "Input: s = \"" << s << "\", part = \"" << part << "\"" << endl;
        string ans = removeOccurrences(s, part);
        cout << "Output: \"" << ans << "\"" << endl;  // Expected: "dab"
    }

    cout << endl;

    // Example 2
    {
        string s = "axxxxyyyyb";
        string part = "xy";
        cout << "Input: s = \"" << s << "\", part = \"" << part << "\"" << endl;
        string ans = removeOccurrences(s, part);
        cout << "Output: \"" << ans << "\"" << endl;  // Expected: "axxxyb"
    }

    cout << endl;

    // Custom user input
    {
        cout << "Enter a string (s): ";
        string s;
        getline(cin, s);

        cout << "Enter the substring to remove (part): ";
        string part;
        getline(cin, part);

        string ans = removeOccurrences(s, part);
        cout << "Final string after removals: " << ans << endl;
    }

    return 0;
}
