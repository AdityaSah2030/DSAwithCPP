#include <iostream>
#include <map>
#include <string>
using namespace std;

/*
 * File: 06_map_iterators.cpp
 * Description:
 *   Demonstrates how to iterate over a std::map using various iterators.
 *
 *   - begin() and end(): Forward iteration in sorted order of keys.
 *   - cbegin() and cend(): Const-forward iteration.
 *   - rbegin() and rend(): Reverse iteration in descending order of keys.
 *   - crbegin() and crend(): Const-reverse iteration.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 06_map_iterators.cpp -o 06_map_iterators
 *     ./06_map_iterators
 *
 *   Windows:
 *     g++ 06_map_iterators.cpp -o 06_map_iterators.exe
 *     06_map_iterators
 */

int main() {
    map<string, int> m = {
        {"Alice", 25},
        {"Bob", 30},
        {"Charlie", 20},
        {"David", 40}
    };

    // Forward iteration using begin() and end()
    cout << "Forward iteration (begin/end):" << endl;
    for (auto it = m.begin(); it != m.end(); ++it) {
        cout << it->first << " -> " << it->second << endl;
    }
    // If not using auto: map<string,int>::iterator it = m.begin();

    // Reverse iteration using rbegin() and rend()
    cout << "\nReverse iteration (rbegin/rend):" << endl;
    for (auto rit = m.rbegin(); rit != m.rend(); ++rit) {
        cout << rit->first << " -> " << rit->second << endl;
    }
    // If not using auto: map<string,int>::reverse_iterator rit = m.rbegin();

    // Const-forward iteration using cbegin() and cend()
    cout << "\nConst-forward iteration (cbegin/cend):" << endl;
    for (auto cit = m.cbegin(); cit != m.cend(); ++cit) {
        cout << cit->first << " -> " << cit->second << endl;
        // Can't modify elements here
    }

    // Const-reverse iteration using crbegin() and crend()
    cout << "\nConst-reverse iteration (crbegin/crend):" << endl;
    for (auto crit = m.crbegin(); crit != m.crend(); ++crit) {
        cout << crit->first << " -> " << crit->second << endl;
        // Can't modify elements here
    }

    return 0;
}
