#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

/*
 * File: 08_unordered_map_basics.cpp
 * Description:
 *   Demonstrates how to use std::unordered_map, which stores key-value pairs
 *   in a hash table. Keys are NOT stored in sorted order.
 *
 * Differences from std::map:
 *   - Not sorted (uses hashing).
 *   - Average O(1) lookup/insertion, but worst-case O(n).
 *   - Key type must be hashable (e.g., int, string).
 *   - Buckets and load factor can be manipulated, but typically not needed for basic usage.
 *
 * Example Operations:
 *   - operator[](key), at(key)
 *   - insert({key, value}), emplace(key, value)
 *   - erase(key)
 *   - find(key), count(key)
 *   - size(), empty(), clear()
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 08_unordered_map_basics.cpp -o 08_unordered_map_basics
 *     ./08_unordered_map_basics
 *
 *   Windows:
 *     g++ 08_unordered_map_basics.cpp -o 08_unordered_map_basics.exe
 *     08_unordered_map_basics
 */

int main() {
    unordered_map<string, int> um;

    // Insert using operator[]
    um["Alice"] = 25;
    um["Bob"] = 30;
    um["Charlie"] = 20;

    // Insert using insert
    um.insert({"David", 40});
    // Insert using emplace
    um.emplace("Eve", 28);

    cout << "unordered_map contents (no guaranteed order):\n";
    for (auto &entry : um) {
        cout << entry.first << " -> " << entry.second << endl;
    }
    // The iteration order will be based on hashing, not alphabetical

    // Access an element
    cout << "\nValue of 'Alice': " << um["Alice"] << endl; // 25

    // Check if a key exists
    if (um.find("Zara") == um.end()) {
        cout << "'Zara' not found in unordered_map.\n";
    }

    // erase(key)
    um.erase("Bob");

    // Print final contents
    cout << "\nAfter erasing 'Bob':\n";
    for (auto &entry : um) {
        cout << entry.first << " -> " << entry.second << endl;
    }

    return 0;
}
