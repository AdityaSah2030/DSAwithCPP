#include <iostream>
#include <string>
#include <cctype>   // For isalnum, tolower
using namespace std;

/*
 * Program: 03_valid_palindrome.cpp
 * Description:
 *   Given a string s, return true if it is a palindrome, or false otherwise.
 *   We ignore cases, remove all non-alphanumeric characters, and then check
 *   if the resulting string reads the same forward and backward.
 *
 * Example Test Cases:
 *
 *   1) s = "A man, a plan, a canal: Panama"
 *      Output: true
 *      Explanation: "amanaplanacanalpanama" is a palindrome.
 *
 *   2) s = "race a car"
 *      Output: false
 *      Explanation: "raceacar" is not a palindrome.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 03_valid_palindrome.cpp -o 03_valid_palindrome
 *     ./03_valid_palindrome
 *
 *   Windows:
 *     g++ 03_valid_palindrome.cpp -o 03_valid_palindrome.exe
 *     03_valid_palindrome
 */

// Function to check if a given string is a palindrome ignoring non-alphanumeric chars
// and case differences
bool isValidPalindrome(const string &s) {
    // 1) Create a filtered, lowercase-only alphanumeric string
    string filtered;
    filtered.reserve(s.size());
    for (char c : s) {
        if (isalnum(static_cast<unsigned char>(c))) {
            filtered.push_back(tolower(static_cast<unsigned char>(c)));
        }
    }

    // 2) Use two pointers to check if 'filtered' is a palindrome
    int left = 0;
    int right = filtered.size() - 1;
    while (left < right) {
        if (filtered[left] != filtered[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    // Demonstration / Test Cases
    string s1 = "A man, a plan, a canal: Panama";
    cout << "Input: \"" << s1 << "\"" << endl;
    cout << "Output: " << (isValidPalindrome(s1) ? "true" : "false") << endl;
    // Expected: true

    cout << endl;

    string s2 = "race a car";
    cout << "Input: \"" << s2 << "\"" << endl;
    cout << "Output: " << (isValidPalindrome(s2) ? "true" : "false") << endl;
    // Expected: false

    cout << endl;

    // Optionally, let user input a string to test
    cout << "Enter a string to check palindrome: ";
    string userInput;
    getline(cin, userInput);

    bool result = isValidPalindrome(userInput);
    cout << "Is it a valid palindrome (ignoring non-alphanumeric & case)? "
         << (result ? "Yes" : "No") << endl;

    return 0;
}
