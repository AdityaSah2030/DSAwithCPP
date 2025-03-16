#include <iostream>
#include <map>
#include <string>
using namespace std;

/*
 * File: 03_map_erase.cpp
 * Description:
 *   Demonstrates how to erase elements from a std::map.
 *
 *   - erase(key): Removes the element with the specified key, returns the number of elements removed (0 or 1).
 *   - erase(iterator): Removes the element at the given iterator.
 *   - erase(start, end): Removes elements in the range [start, end).
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 03_map_erase.cpp -o 03_map_erase
 *     ./03_map_erase
 *
 *   Windows:
 *     g++ 03_map_erase.cpp -o 03_map_erase.exe
 *     03_map_erase
 */

int main() {
    map<string, int> m = {
        {"Alice", 25},
        {"Bob", 30},
        {"Charlie", 20},
        {"David", 40}
    };

    cout << "Original map contents:\n";
    for (auto &entry : m) {
        cout << entry.first << " -> " << entry.second << endl;
    }

    // 1) Erase by key
    cout << "\nErasing 'Bob' by key...\n";
    size_t countRemoved = m.erase("Bob"); // Returns 1 if "Bob" was removed, 0 if not found
    cout << "Number of elements removed: " << countRemoved << endl;

    // 2) Erase by iterator (e.g., remove "Alice")
    auto it = m.find("Alice");
    if (it != m.end()) {
        m.erase(it); // remove the element pointed by it
    }

    // 3) Erase by range (e.g., remove from the first element to the next-to-last)
    //   Let's re-insert "Bob" for demonstration
    m["Bob"] = 35;
    cout << "\nRe-inserted 'Bob' -> 35\n";

    cout << "\nMap contents before range erase:\n";
    for (auto &entry : m) {
        cout << entry.first << " -> " << entry.second << endl;
    }

    // We'll erase from begin() to the element just before the last (i.e. last element remains)
    if (m.size() > 1) {
        auto lastElem = m.end();
        --lastElem; // This points to the last element
        m.erase(m.begin(), lastElem);
    }

    cout << "\nMap contents after range erase (begin to last-1):\n";
    for (auto &entry : m) {
        cout << entry.first << " -> " << entry.second << endl;
    }

    return 0;
}
