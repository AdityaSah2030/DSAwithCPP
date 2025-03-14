#include <iostream>
#include <unordered_set>
using namespace std;

/*
 * File: 07_unordered_set_basics.cpp
 * Description:
 *   Demonstrates std::unordered_set, which is like std::set but uses a hash table
 *   instead of being sorted. No duplicates allowed.
 *
 * Differences from std::set:
 *   - No sorted order (hash-based).
 *   - Average O(1) insertion, lookup, removal (worst-case O(n)).
 *   - No lower_bound() or upper_bound() (those require ordering).
 *
 * Example Operations:
 *   - insert(value)
 *   - emplace(value)
 *   - erase(value)
 *   - find(value)
 *   - count(value)
 *   - size(), empty(), clear()
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 07_unordered_set_basics.cpp -o 07_unordered_set_basics
 *     ./07_unordered_set_basics
 *
 *   Windows:
 *     g++ 07_unordered_set_basics.cpp -o 07_unordered_set_basics.exe
 *     07_unordered_set_basics
 */

int main() {
    unordered_set<int> us;

    // Insert elements
    us.insert(10);
    us.insert(20);
    us.insert(10); // Duplicate insertion -> fails, no error, no insertion

    // Emplace
    us.emplace(30);
    us.emplace(20); // Duplicate, won't be inserted

    cout << "Contents of the unordered_set (no specific order, unique elements):\n";
    for (int val : us) {
        cout << val << " ";
    }
    cout << endl;
    // Could be any order, e.g. 20 30 10 or 10 20 30

    // find(value)
    auto it = us.find(20);
    if (it != us.end()) {
        cout << "\nFound 20 in the unordered_set.\n";
    } else {
        cout << "\n20 not found.\n";
    }

    // count(value)
    cout << "Count of 10: " << us.count(10) << endl; // 1 if present, else 0

    // Erase a value
    us.erase(10);

    cout << "\nAfter erasing 10:\n";
    for (int val : us) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
