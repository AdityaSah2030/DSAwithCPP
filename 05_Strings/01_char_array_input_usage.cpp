#include <iostream>
#include <cstring>  // For strlen, strcpy, etc.
using namespace std;

/*
 * File: 01_char_array_input_usage.cpp
 * Description:
 *   Demonstrates how to handle character arrays (C-style strings) in C++.
 *   - Taking input into a character array
 *   - Basic string manipulation using <cstring> functions
 *   - Differences and limitations compared to std::string
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 01_char_array_input_usage.cpp -o 01_char_array_input_usage
 *     ./01_char_array_input_usage
 *
 *   Windows:
 *     g++ 01_char_array_input_usage.cpp -o 01_char_array_input_usage.exe
 *     01_char_array_input_usage
 */

int main() {
    // 1) Basic input using cin (stops at whitespace)
    char name[50];
    cout << "Enter your first name (cin stops at space): ";
    cin >> name; // e.g., if user types "John Doe", 'name' will only get "John"
    cout << "You entered: " << name << endl;

    // Clear input buffer before next usage
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // 2) Using cin.getline() to read a line with spaces
    char sentence[100];
    cout << "\nEnter a full sentence (getline can include spaces): ";
    cin.getline(sentence, 100);  // read up to 99 chars + null terminator
    cout << "You entered: " << sentence << endl;

    // 3) Demonstrate some <cstring> functions
    //    a) strlen -> get length
    cout << "\nLength of sentence: " << strlen(sentence) << endl;

    //    b) strcpy -> copy one char array to another
    char copy[100];
    strcpy(copy, sentence);
    cout << "Copied sentence into 'copy': " << copy << endl;

    //    c) strcat -> concatenate strings (be careful about buffer size!)
    strcat(copy, " (added text)");
    cout << "After strcat: " << copy << endl;

    //    d) strcmp -> compare two strings
    // Compare 'copy' with 'sentence'
    if (strcmp(copy, sentence) == 0) {
        cout << "'copy' and 'sentence' are the same.\n";
    } else {
        cout << "'copy' and 'sentence' differ.\n";
    }

    // 4) Limitations of character arrays:
    //    - Need a fixed buffer size
    //    - Risk of overflow if input is too large
    //    - Harder to manipulate compared to std::string

    return 0;
}
