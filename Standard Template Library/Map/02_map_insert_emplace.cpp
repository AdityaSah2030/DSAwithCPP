#include <iostream>
#include <map>
#include <string>
using namespace std;

/*
 * File: 02_map_insert_emplace.cpp
 * Description:
 *   Demonstrates how to insert elements into a std::map using insert() and emplace().
 *
 *   - insert({key, value}): Inserts a pair if the key does not already exist.
 *   - emplace(key, value): Constructs the pair in place (potentially avoiding copies).
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 02_map_insert_emplace.cpp -o 02_map_insert_emplace
 *     ./02_map_insert_emplace
 *
 *   Windows:
 *     g++ 02_map_insert_emplace.cpp -o 02_map_insert_emplace.exe
 *     02_map_insert_emplace
 */

int main() {
    map<string, int> m;

    // Using insert with an initializer list
    m.insert({"Alice", 25});
    m.insert({"Bob", 30});

    // Using emplace
    m.emplace("Charlie", 20);

    // Insert returns a pair<iterator, bool>. The bool indicates success or failure.
    auto result = m.insert({"Bob", 50}); // "Bob" already exists, so insertion should fail
    if (!result.second) {
        cout << "Insertion of 'Bob' failed because 'Bob' already exists with value = "
             << result.first->second << endl;
    }

    // Let's see the map contents
    cout << "\nMap contents after insert and emplace:\n";
    for (auto &entry : m) {
        cout << entry.first << " -> " << entry.second << endl;
    }
    // Keys: "Alice", "Bob", "Charlie"

    // Another way to insert using pair and map's insert
    pair<string,int> p("David", 40);
    m.insert(p);

    cout << "\nAfter inserting 'David':\n";
    for (auto &entry : m) {
        cout << entry.first << " -> " << entry.second << endl;
    }

    return 0;
}
