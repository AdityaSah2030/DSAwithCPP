#include <iostream>
#include <map>
#include <string>
using namespace std;

/*
 * File: 01_map_insertion_access.cpp
 * Description:
 *   Demonstrates how to insert key-value pairs into a std::map
 *   using operator[] and how to access elements.
 *
 *   - operator[](key): Inserts a default-constructed value if key does not exist.
 *   - at(key): Returns a reference to the mapped value, throws out_of_range if not found.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 01_map_insertion_access.cpp -o 01_map_insertion_access
 *     ./01_map_insertion_access
 *
 *   Windows:
 *     g++ 01_map_insertion_access.cpp -o 01_map_insertion_access.exe
 *     01_map_insertion_access
 */

int main() {
    // Create a map from string to int
    map<string, int> m;

    // Insert using operator[]
    m["Alice"] = 25;
    m["Bob"] = 30;
    m["Charlie"] = 20;

    cout << "Map contents (using operator[]):\n";
    for (auto &entry : m) {
        cout << entry.first << " -> " << entry.second << endl;
    }
    // Keys are sorted lexicographically: "Alice", "Bob", "Charlie"

    // Access an element using at()
    cout << "\nUsing at() to access 'Bob': " << m.at("Bob") << endl; // Expected: 30

    // Attempt to access a non-existing key with at() -> throws exception
    try {
        cout << "Trying to access 'David': " << m.at("David") << endl;
    } catch (const out_of_range &e) {
        cerr << "Exception: " << e.what() << endl;
    }

    // Using operator[] on a new key "Eve" -> inserts default value (0 for int)
    cout << "\nValue of 'Eve' before assignment: " << m["Eve"] << endl;
    // Now 'Eve' is in the map with value 0
    m["Eve"] = 27;

    cout << "Value of 'Eve' after assignment: " << m["Eve"] << endl; // Expected: 27

    // Final map contents
    cout << "\nFinal map contents:\n";
    for (auto &entry : m) {
        cout << entry.first << " -> " << entry.second << endl;
    }

    return 0;
}
