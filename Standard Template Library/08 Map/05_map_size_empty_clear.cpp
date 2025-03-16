#include <iostream>
#include <map>
#include <string>
using namespace std;

/*
 * File: 05_map_size_empty_clear.cpp
 * Description:
 *   Demonstrates how to check size, emptiness, and how to clear a std::map.
 *
 *   - size(): Returns the number of elements in the map.
 *   - empty(): Checks if the map is empty.
 *   - clear(): Removes all elements from the map.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 05_map_size_empty_clear.cpp -o 05_map_size_empty_clear
 *     ./05_map_size_empty_clear
 *
 *   Windows:
 *     g++ 05_map_size_empty_clear.cpp -o 05_map_size_empty_clear.exe
 *     05_map_size_empty_clear
 */

int main() {
    map<string, int> m;

    // Check if empty initially
    cout << "Is map empty initially? " << (m.empty() ? "Yes" : "No") << endl; 
    // Expected: Yes

    // Insert some elements
    m["Alice"] = 25;
    m["Bob"] = 30;
    m["Charlie"] = 20;

    cout << "\nMap size after insertions: " << m.size() << endl; // Expected: 3
    cout << "Is map empty now? " << (m.empty() ? "Yes" : "No") << endl; // Expected: No

    // Print the map
    cout << "\nCurrent map contents:\n";
    for (auto &entry : m) {
        cout << entry.first << " -> " << entry.second << endl;
    }

    // Clear the map
    m.clear();
    cout << "\nAfter clear(), map size: " << m.size() << endl; // Expected: 0
    cout << "Is map empty after clear()? " << (m.empty() ? "Yes" : "No") << endl; // Expected: Yes

    return 0;
}
