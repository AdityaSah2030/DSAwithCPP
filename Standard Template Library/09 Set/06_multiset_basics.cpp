#include <iostream>
#include <set>  // for std::multiset
using namespace std;

/*
 * File: 06_multiset_basics.cpp
 * Description:
 *   Demonstrates std::multiset, which is like std::set but allows multiple
 *   identical elements. Elements are still sorted by default.
 *
 * Differences from std::set:
 *   - Duplicates are allowed (insertion of the same value doesn't fail).
 *   - No operator[] (same as set).
 *   - Otherwise, usage is very similar (insert, emplace, erase, find, etc.).
 *
 * Example Operations:
 *   - insert(value)
 *   - emplace(value)
 *   - erase(value)
 *   - find(value)
 *   - count(value)
 *   - size(), empty()
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 06_multiset_basics.cpp -o 06_multiset_basics
 *     ./06_multiset_basics
 *
 *   Windows:
 *     g++ 06_multiset_basics.cpp -o 06_multiset_basics.exe
 *     06_multiset_basics
 */

int main() {
    multiset<int> ms;

    // Insert duplicates
    ms.insert(10);
    ms.insert(20);
    ms.insert(10);  // Duplicate of 10
    ms.insert(15);

    // Emplace another 15
    ms.emplace(15);

    cout << "Contents of the multiset (duplicates allowed, sorted):\n";
    for (int val : ms) {
        cout << val << " ";
    }
    cout << endl;
    // Expected sorted order, e.g. 10 10 15 15 20

    // count(value) -> how many times 'value' appears
    cout << "\nCount of 10: " << ms.count(10) << endl; // Possibly 2
    cout << "Count of 15: " << ms.count(15) << endl;   // Possibly 2

    // Erase one occurrence of 10 by iterator
    auto it = ms.find(10);
    if (it != ms.end()) {
        ms.erase(it); // remove a single '10'
    }

    cout << "\nAfter erasing one '10':\n";
    for (int val : ms) {
        cout << val << " ";
    }
    cout << endl;
    // Now only one '10' remains

    return 0;
}
