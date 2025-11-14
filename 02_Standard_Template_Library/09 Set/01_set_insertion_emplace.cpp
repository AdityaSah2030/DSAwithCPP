#include <iostream>
#include <set>
using namespace std;

/*
 * File: 01_set_insertion_emplace.cpp
 * Description:
 *   Demonstrates how to insert elements into a std::set using insert() and emplace().
 *
 *   - insert(value): Inserts 'value' if not already present (returns a pair<iterator,bool>).
 *   - emplace(value): Constructs the element in place (avoids copies if possible).
 *
 *   std::set is sorted in ascending order by default and does not allow duplicates.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 01_set_insertion_emplace.cpp -o 01_set_insertion_emplace
 *     ./01_set_insertion_emplace
 *
 *   Windows:
 *     g++ 01_set_insertion_emplace.cpp -o 01_set_insertion_emplace.exe
 *     01_set_insertion_emplace
 */

int main() {
    set<int> s;

    // Insert elements using insert()
    auto result1 = s.insert(10); // returns pair<iterator,bool>
    auto result2 = s.insert(20);
    auto result3 = s.insert(10); // 10 already exists, insertion fails

    // Check success of insertion
    cout << "Insertion of 10 first time: " << (result1.second ? "Succeeded" : "Failed") << endl;
    cout << "Insertion of 20: " << (result2.second ? "Succeeded" : "Failed") << endl;
    cout << "Insertion of 10 second time: " << (result3.second ? "Succeeded" : "Failed") << endl;

    // Emplace elements
    s.emplace(5);   // Insert 5
    s.emplace(15);  // Insert 15
    s.emplace(20);  // Already exists, fails

    cout << "\nSet contents after insert and emplace:\n";
    for (int val : s) {
        cout << val << " ";
    }
    cout << endl;
    // Expected sorted order: 5 10 15 20

    return 0;
}
