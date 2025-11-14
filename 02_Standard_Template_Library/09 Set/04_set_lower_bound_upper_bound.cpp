#include <iostream>
#include <set>
using namespace std;

/*
 * File: 04_set_lower_bound_upper_bound.cpp
 * Description:
 *   Demonstrates how to use lower_bound() and upper_bound() in a std::set.
 *
 *   - lower_bound(x): Returns an iterator to the first element >= x.
 *   - upper_bound(x): Returns an iterator to the first element > x.
 *
 *   Both functions perform O(log n) lookups.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 04_set_lower_bound_upper_bound.cpp -o 04_set_lower_bound_upper_bound
 *     ./04_set_lower_bound_upper_bound
 *
 *   Windows:
 *     g++ 04_set_lower_bound_upper_bound.cpp -o 04_set_lower_bound_upper_bound.exe
 *     04_set_lower_bound_upper_bound
 */

int main() {
    set<int> s = {10, 20, 30, 40, 50};

    cout << "Set contents: ";
    for (int val : s) {
        cout << val << " ";
    }
    cout << endl;

    // lower_bound(x)
    auto lb = s.lower_bound(30);
    if (lb != s.end()) {
        cout << "\nlower_bound(30) points to: " << *lb << endl; // Expected: 30
    } else {
        cout << "\nlower_bound(30) is end()\n";
    }

    // If we do lower_bound(35), the first element >= 35 is 40
    auto lb35 = s.lower_bound(35);
    if (lb35 != s.end()) {
        cout << "lower_bound(35) points to: " << *lb35 << endl; // Expected: 40
    } else {
        cout << "lower_bound(35) is end()\n";
    }

    // upper_bound(x)
    auto ub = s.upper_bound(30);
    if (ub != s.end()) {
        cout << "\nupper_bound(30) points to: " << *ub << endl; // Expected: 40
    } else {
        cout << "\nupper_bound(30) is end()\n";
    }

    // If we do upper_bound(50), it should return end()
    auto ub50 = s.upper_bound(50);
    if (ub50 == s.end()) {
        cout << "upper_bound(50) is end()\n";
    } else {
        cout << "upper_bound(50) points to: " << *ub50 << endl;
    }

    return 0;
}
