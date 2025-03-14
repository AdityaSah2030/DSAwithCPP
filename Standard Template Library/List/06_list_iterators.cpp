#include <iostream>
#include <list>
using namespace std;

/*
 * File: 06_list_iterators.cpp
 * Description:
 *   Demonstrates how to use iterators with std::list.
 *
 *   Iterator Types:
 *     1. begin() and end():
 *          - Return non-const iterators for forward traversal.
 *          - Allow modification.
 *          - Explicit type (if not using auto): list<int>::iterator it = lst.begin();
 *
 *     2. cbegin() and cend():
 *          - Return const iterators for forward traversal (read-only).
 *          - Explicit type: list<int>::const_iterator cit = lst.cbegin();
 *
 *     3. rbegin() and rend():
 *          - Return non-const reverse iterators for reverse traversal.
 *          - Explicit type: list<int>::reverse_iterator rit = lst.rbegin();
 *
 *     4. crbegin() and crend():
 *          - Return const reverse iterators for reverse traversal (read-only).
 *          - Explicit type: list<int>::const_reverse_iterator crit = lst.crbegin();
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 06_list_iterators.cpp -o 06_list_iterators
 *     ./06_list_iterators
 *
 *   Windows:
 *     g++ 06_list_iterators.cpp -o 06_list_iterators.exe
 *     06_list_iterators
 */

int main() {
    list<int> lst = {10, 20, 30, 40, 50};

    // Forward iteration using begin() and end() (modifiable)
    cout << "Forward iteration using begin() and end():" << endl;
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        cout << *it << " ";
    }
    // Without auto, you would write:
    // for (list<int>::iterator it = lst.begin(); it != lst.end(); ++it) { ... }
    cout << endl;
    
    // Reverse iteration using rbegin() and rend() (modifiable)
    cout << "\nReverse iteration using rbegin() and rend():" << endl;
    for (auto rit = lst.rbegin(); rit != lst.rend(); ++rit) {
        cout << *rit << " ";
    }
    // Without auto: for (list<int>::reverse_iterator rit = lst.rbegin(); rit != lst.rend(); ++rit) { ... }
    cout << endl;
    
    // Forward iteration using cbegin() and cend() (read-only)
    cout << "\nForward iteration using cbegin() and cend() (read-only):" << endl;
    for (auto cit = lst.cbegin(); cit != lst.cend(); ++cit) {
        cout << *cit << " ";
    }
    // Without auto: list<int>::const_iterator cit = lst.cbegin();
    cout << endl;
    
    // Reverse iteration using crbegin() and crend() (read-only)
    cout << "\nReverse iteration using crbegin() and crend() (read-only):" << endl;
    for (auto crit = lst.crbegin(); crit != lst.crend(); ++crit) {
        cout << *crit << " ";
    }
    // Without auto: list<int>::const_reverse_iterator crit = lst.crbegin();
    cout << endl;

    return 0;
}
