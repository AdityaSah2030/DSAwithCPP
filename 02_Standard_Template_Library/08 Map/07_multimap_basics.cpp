#include <iostream>
#include <map>
#include <string>
using namespace std;

/*
 * File: 07_multimap_basics.cpp
 * Description:
 *   Demonstrates how to use std::multimap, which allows multiple elements
 *   with the same key. Keys are stored in sorted order (like std::map),
 *   but each key can appear more than once.
 *
 * Differences from std::map:
 *   - No operator[] (must use insert/emplace).
 *   - The same key can appear multiple times.
 *
 * Example Operations:
 *   - insert({key, value})
 *   - emplace(key, value)
 *   - erase(key)  // Removes all elements matching 'key'
 *   - find(key), count(key)
 *   - lower_bound(key), upper_bound(key)
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 07_multimap_basics.cpp -o 07_multimap_basics
 *     ./07_multimap_basics
 *
 *   Windows:
 *     g++ 07_multimap_basics.cpp -o 07_multimap_basics.exe
 *     07_multimap_basics
 */

int main() {
    multimap<string, int> mm;

    // Insert multiple elements with the same key
    mm.insert({"Alice", 25});
    mm.insert({"Bob", 30});
    mm.insert({"Alice", 28});
    mm.insert({"Charlie", 20});
    mm.emplace("Alice", 29);  // Emplace another "Alice"

    // Print contents
    cout << "multimap contents (keys in sorted order, duplicates allowed):\n";
    for (auto &entry : mm) {
        cout << entry.first << " -> " << entry.second << endl;
    }
    // You might see "Alice" multiple times: 25, 28, 29

    // count(key) returns how many entries match 'key'
    cout << "\nCount of 'Alice': " << mm.count("Alice") << endl;

    // find(key) returns an iterator to the first occurrence of 'key'
    auto it = mm.find("Alice");
    if (it != mm.end()) {
        cout << "Found 'Alice' with value: " << it->second << endl;
    }

    // erase(key) removes all elements matching 'key'
    size_t removed = mm.erase("Alice");
    cout << "\nRemoved " << removed << " elements with key 'Alice'." << endl;

    // Print remaining contents
    cout << "\nRemaining multimap contents:\n";
    for (auto &entry : mm) {
        cout << entry.first << " -> " << entry.second << endl;
    }

    return 0;
}
