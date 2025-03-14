#include <iostream>
#include <set>
using namespace std;

/*
 * File: 02_set_erase_find_count.cpp
 * Description:
 *   Demonstrates how to erase elements, and how to use find() and count() in a std::set.
 *
 *   - erase(value): Removes 'value' if it exists, returns the number of elements removed (0 or 1).
 *   - find(value): Returns an iterator to 'value' if found, or end() if not found.
 *   - count(value): Returns how many times 'value' appears (0 or 1 in std::set).
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 02_set_erase_find_count.cpp -o 02_set_erase_find_count
 *     ./02_set_erase_find_count
 *
 *   Windows:
 *     g++ 02_set_erase_find_count.cpp -o 02_set_erase_find_count.exe
 *     02_set_erase_find_count
 */

int main() {
    set<int> s = {10, 20, 30, 40, 50};

    cout << "Original set contents:\n";
    for (int val : s) {
        cout << val << " ";
    }
    cout << endl;

    // count(value)
    cout << "\nCount of 20 in set: " << s.count(20) << endl; // Expected: 1
    cout << "Count of 25 in set: " << s.count(25) << endl; // Expected: 0

    // find(value)
    auto it = s.find(30);
    if (it != s.end()) {
        cout << "\nFound 30 in the set." << endl;
    } else {
        cout << "\n30 not found in the set." << endl;
    }

    // erase(value)
    size_t removed = s.erase(40);
    cout << "\nRemoving 40, number of elements removed: " << removed << endl;
    // Expected: 1

    cout << "Set after erasing 40:\n";
    for (int val : s) {
        cout << val << " ";
    }
    cout << endl;
    // Expected: 10, 20, 30, 50

    // Erase by iterator
    it = s.find(10);
    if (it != s.end()) {
        s.erase(it); // removes 10
    }

    cout << "\nSet after erasing 10 by iterator:\n";
    for (int val : s) {
        cout << val << " ";
    }
    cout << endl;
    // Expected: 20, 30, 50

    return 0;
}
