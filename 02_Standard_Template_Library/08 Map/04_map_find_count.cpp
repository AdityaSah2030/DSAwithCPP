#include <iostream>
#include <map>
#include <string>
using namespace std;

/*
 * File: 04_map_find_count.cpp
 * Description:
 *   Demonstrates how to find elements in a std::map and how to use count().
 *
 *   - find(key): Returns an iterator to the element if found, or end() if not found.
 *   - count(key): Returns the number of elements matching key (0 or 1 in a std::map).
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 04_map_find_count.cpp -o 04_map_find_count
 *     ./04_map_find_count
 *
 *   Windows:
 *     g++ 04_map_find_count.cpp -o 04_map_find_count.exe
 *     04_map_find_count
 */

int main() {
    map<string, int> m = {
        {"Alice", 25},
        {"Bob", 30},
        {"Charlie", 20}
    };

    // Using find()
    auto it = m.find("Bob");
    if (it != m.end()) {
        cout << "Found 'Bob' with value: " << it->second << endl;
    } else {
        cout << "'Bob' not found in map.\n";
    }

    // Using count()
    cout << "\nCount of 'Alice' in map: " << m.count("Alice") << endl;   // Expected: 1
    cout << "Count of 'David' in map: " << m.count("David") << endl; // Expected: 0

    // Example usage of find() for potential modifications
    auto it2 = m.find("Charlie");
    if (it2 != m.end()) {
        it2->second = 100; // Modify the value
    }

    // Print final map
    cout << "\nFinal map contents:\n";
    for (auto &entry : m) {
        cout << entry.first << " -> " << entry.second << endl;
    }

    return 0;
}
