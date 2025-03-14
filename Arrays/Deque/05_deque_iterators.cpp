#include <iostream>
#include <deque>
using namespace std;

/*
 * File: 05_deque_iterators.cpp
 * Description:
 *   Demonstrates how to use iterators with std::deque.
 *
 *   Iterator Types:
 *     1. begin() and end():
 *          - Return non-const iterators for forward traversal (modifiable).
 *          - Example: deque<int>::iterator it = dq.begin();
 *
 *     2. cbegin() and cend():
 *          - Return const iterators for forward traversal (read-only).
 *          - Example: deque<int>::const_iterator cit = dq.cbegin();
 *
 *     3. rbegin() and rend():
 *          - Return non-const reverse iterators for backward traversal (modifiable).
 *          - Example: deque<int>::reverse_iterator rit = dq.rbegin();
 *
 *     4. crbegin() and crend():
 *          - Return const reverse iterators for backward traversal (read-only).
 *          - Example: deque<int>::const_reverse_iterator crit = dq.crbegin();
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 05_deque_iterators.cpp -o 05_deque_iterators
 *     ./05_deque_iterators
 *
 *   Windows:
 *     g++ 05_deque_iterators.cpp -o 05_deque_iterators.exe
 *     05_deque_iterators
 */

int main() {
    deque<int> dq = {10, 20, 30, 40, 50};

    // 1. Forward iteration using begin() and end()
    cout << "Forward iteration (begin/end): ";
    for (auto it = dq.begin(); it != dq.end(); ++it) {
        cout << *it << " ";
    }
    // If not using auto: deque<int>::iterator it = dq.begin();
    cout << endl;

    // 2. Reverse iteration using rbegin() and rend()
    cout << "Reverse iteration (rbegin/rend): ";
    for (auto rit = dq.rbegin(); rit != dq.rend(); ++rit) {
        cout << *rit << " ";
    }
    // If not using auto: deque<int>::reverse_iterator rit = dq.rbegin();
    cout << endl;

    // 3. Forward iteration using cbegin() and cend() (read-only)
    cout << "Forward iteration (cbegin/cend) read-only: ";
    for (auto cit = dq.cbegin(); cit != dq.cend(); ++cit) {
        cout << *cit << " ";
    }
    // If not using auto: deque<int>::const_iterator cit = dq.cbegin();
    cout << endl;

    // 4. Reverse iteration using crbegin() and crend() (read-only)
    cout << "Reverse iteration (crbegin/crend) read-only: ";
    for (auto crit = dq.crbegin(); crit != dq.crend(); ++crit) {
        cout << *crit << " ";
    }
    // If not using auto: deque<int>::const_reverse_iterator crit = dq.crbegin();
    cout << endl;

    return 0;
}
