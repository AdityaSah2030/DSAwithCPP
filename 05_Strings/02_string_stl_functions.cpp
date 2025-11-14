#include <iostream>
#include <string>
#include <algorithm> // For transform, etc.
using namespace std;

/*
 * File: 02_string_stl_functions.cpp
 * Description:
 *   Demonstrates modern C++ std::string usage:
 *     - Input methods (cin, getline)
 *     - Common functions (length, substr, find, push_back, pop_back, etc.)
 *     - Loops over strings
 *     - Basic transformations (to uppercase, etc.)
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 02_string_stl_functions.cpp -o 02_string_stl_functions
 *     ./02_string_stl_functions
 *
 *   Windows:
 *     g++ 02_string_stl_functions.cpp -o 02_string_stl_functions.exe
 *     02_string_stl_functions
 */

int main() {
    // 1) Basic input with std::string
    //    a) Using cin (stops at space)
    string firstName;
    cout << "Enter your first name: ";
    cin >> firstName; // e.g. if user types "Alice Bob", only "Alice" is read
    cout << "Hello, " << firstName << "!\n";

    // Clear input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //    b) Using getline (reads entire line)
    string fullLine;
    cout << "\nEnter a full sentence: ";
    getline(cin, fullLine);
    cout << "You entered: " << fullLine << endl;

    // 2) Common string functions
    cout << "\n2) Common std::string functions:\n";
    //    a) length() / size()
    cout << "Length of the sentence: " << fullLine.size() << endl;

    //    b) append / +
    fullLine.append(" [appended]");
    cout << "After append: " << fullLine << endl;
    // or fullLine = fullLine + " [appended2]";

    //    c) substr(pos, n)
    if (fullLine.size() >= 5) {
        string sub = fullLine.substr(0, 5); // first 5 chars
        cout << "First 5 chars: " << sub << endl;
    }

    //    d) find(str)
    size_t pos = fullLine.find("appended");
    if (pos != string::npos) {
        cout << "Found 'appended' at index: " << pos << endl;
    } else {
        cout << "'appended' not found\n";
    }

    //    e) erase(pos, n)
    if (pos != string::npos) {
        // remove "[appended]" from the string
        fullLine.erase(pos - 1); // from space before 'appended' to end
        cout << "After erasing from the space before 'appended': " << fullLine << endl;
    }

    //    f) push_back / pop_back
    // push_back
    fullLine.push_back('!');
    cout << "After push_back('!'): " << fullLine << endl;

    // pop_back
    fullLine.pop_back();
    cout << "After pop_back(): " << fullLine << endl;

    //    g) front() and back()
    if (!fullLine.empty()) {
        cout << "front() = " << fullLine.front() << ", back() = " << fullLine.back() << endl;
    }

    //    h) clear() and empty()
    // fullLine.clear(); // empties the string
    // if (fullLine.empty()) { ... }

    // 3) Loops over a string
    cout << "\n3) Loops over a string:\n";
    cout << "Method a) Range-based for loop:\n";
    for (char c : fullLine) {
        cout << c << " ";
    }
    cout << endl;

    cout << "Method b) Classic for loop:\n";
    for (size_t i = 0; i < fullLine.size(); i++) {
        cout << fullLine[i] << " ";
    }
    cout << endl;

    // 4) Basic transformations
    cout << "\n4) Basic transformations (to uppercase):\n";
    // Convert fullLine to uppercase using std::transform
    // (Need #include <algorithm>)
    string upperStr = fullLine; // copy
    transform(upperStr.begin(), upperStr.end(), upperStr.begin(), ::toupper);
    cout << "Uppercase: " << upperStr << endl;

    // Similarly, we can do tolower, etc.

    return 0;
}
