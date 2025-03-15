#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 * File: 07_string_compression.cpp
 * Description (LeetCode #443):
 *   Given an array of characters chars, compress it using the following algorithm:
 *
 *   1) Begin with an empty string s. For each group of consecutive repeating characters in chars:
 *        - If the group's length is 1, append the character to s.
 *        - Otherwise, append the character followed by the group's length.
 *   2) The compressed string should not be returned separately, but instead be stored in the input array chars.
 *   3) After you are done modifying the input array, return the new length of the array.
 *   4) You must write an algorithm that uses constant extra space.
 *
 * Example 1:
 *   Input: chars = ["a","a","b","b","c","c","c"]
 *   Output: Return 6, and the first 6 chars of chars should be ["a","2","b","2","c","3"]
 *
 * Example 2:
 *   Input: chars = ["a"]
 *   Output: Return 1, and the first 1 char of chars should be ["a"]
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 07_string_compression.cpp -o string_compression
 *     ./string_compression
 *
 *   Windows:
 *     g++ 07_string_compression.cpp -o string_compression.exe
 *     string_compression
 */

// Function to compress the character array in-place
int compress(vector<char>& chars) {
    int n = chars.size();
    if (n == 0) return 0;

    int writeIndex = 0; // position to write compressed result
    int i = 0;          // read index

    while (i < n) {
        char currentChar = chars[i];
        int count = 0;

        // Count how many times currentChar repeats
        while (i < n && chars[i] == currentChar) {
            i++;
            count++;
        }

        // Write the character
        chars[writeIndex] = currentChar;
        writeIndex++;

        // If count > 1, write the digits of count
        if (count > 1) {
            // Convert count to string
            string countStr = to_string(count);
            for (char c : countStr) {
                chars[writeIndex] = c;
                writeIndex++;
            }
        }
    }

    return writeIndex; // new length
}

int main() {
    // Example 1
    {
        vector<char> chars = {'a','a','b','b','c','c','c'};
        cout << "Input: ";
        for (char c : chars) cout << c;
        cout << endl;

        int newLen = compress(chars);

        cout << "Output new length: " << newLen << endl;
        cout << "Compressed chars: ";
        for (int i = 0; i < newLen; i++) {
            cout << chars[i];
        }
        cout << endl;
        // Expected: newLen = 6, compressed = ["a","2","b","2","c","3"]
    }

    cout << endl;

    // Example 2
    {
        vector<char> chars = {'a'};
        cout << "Input: ";
        for (char c : chars) cout << c;
        cout << endl;

        int newLen = compress(chars);

        cout << "Output new length: " << newLen << endl;
        cout << "Compressed chars: ";
        for (int i = 0; i < newLen; i++) {
            cout << chars[i];
        }
        cout << endl;
        // Expected: newLen = 1, compressed = ["a"]
    }

    cout << endl;

    // Custom input
    {
        cout << "Enter a string (no spaces) to compress: ";
        string s;
        cin >> s;
        vector<char> chars(s.begin(), s.end());

        int newLen = compress(chars);

        cout << "Compressed length: " << newLen << endl;
        cout << "Compressed chars: ";
        for (int i = 0; i < newLen; i++) {
            cout << chars[i];
        }
        cout << endl;
    }

    return 0;
}
