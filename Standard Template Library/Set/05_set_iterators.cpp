#include <iostream>
#include <set>
using namespace std;

/*
 * File: 05_set_iterators.cpp
 * Description:
 *   Demonstrates how to iterate over a std::set using various iterators.
 *
 *   - begin() / end(): Forward iteration in ascending order.
 *   - cbegin() / cend(): Const-forward iteration.
 *   - rbegin() / rend(): Reverse iteration in descending order.
 *   - crbegin() / crend(): Const-reverse iteration.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 05_set_iterators.cpp -o 05_set_iterators
 *     ./05_set_iterators
 *
 *   Windows:
 *     g++ 05_set_iterators.cpp -o 05_set_iterators.exe
 *     05_set_iterators
 */

int main() {
    set<int> s = {10, 20, 30, 40, 50};

    // Forward iteration (begin/end)
    cout << "Forward iteration (begin/end):" << endl;
    for (auto it = s.begin(); it != s.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Reverse iteration (rbegin/rend)
    cout << "\nReverse iteration (rbegin/rend):" << endl;
    for (auto rit = s.rbegin(); rit != s.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;

    // Const-forward iteration (cbegin/cend)
    cout << "\nConst-forward iteration (cbegin/cend):" << endl;
    for (auto cit = s.cbegin(); cit != s.cend(); ++cit) {
        cout << *cit << " ";
    }
    cout << endl;

    // Const-reverse iteration (crbegin/crend)
    cout << "\nConst-reverse iteration (crbegin/crend):" << endl;
    for (auto crit = s.crbegin(); crit != s.crend(); ++crit) {
        cout << *crit << " ";
    }
    cout << endl;

    return 0;
}
