#include <iostream>
#include <set>
using namespace std;

/*
 * File: 03_set_size_empty.cpp
 * Description:
 *   Demonstrates how to check the size of a std::set, and whether it is empty.
 *   - size(): Returns the number of elements in the set.
 *   - empty(): Returns true if the set is empty, false otherwise.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 03_set_size_empty.cpp -o 03_set_size_empty
 *     ./03_set_size_empty
 *
 *   Windows:
 *     g++ 03_set_size_empty.cpp -o 03_set_size_empty.exe
 *     03_set_size_empty
 */

int main() {
    set<int> s;

    // Check if empty initially
    cout << "Is set empty initially? " << (s.empty() ? "Yes" : "No") << endl; 
    // Expected: Yes

    // Insert some elements
    s.insert(10);
    s.insert(20);
    s.insert(30);

    cout << "\nSet size after insertions: " << s.size() << endl; // e.g. 3
    cout << "Is set empty now? " << (s.empty() ? "Yes" : "No") << endl; // Expected: No

    // Print the set
    cout << "\nCurrent set contents:\n";
    for (int val : s) {
        cout << val << " ";
    }
    cout << endl;

    // Clear the set
    s.clear();
    cout << "\nAfter clear(), size: " << s.size() << endl; // Expected: 0
    cout << "Is set empty after clear()? " << (s.empty() ? "Yes" : "No") << endl; // Expected: Yes

    return 0;
}
