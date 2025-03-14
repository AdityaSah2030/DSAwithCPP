#include <iostream>
#include <deque>
using namespace std;

/*
 * File: 04_deque_clear_empty.cpp
 * Description:
 *   Demonstrates how to clear a std::deque and check if it is empty.
 *   - clear(): Removes all elements from the deque.
 *   - empty(): Returns true if the deque is empty.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 04_deque_clear_empty.cpp -o 04_deque_clear_empty
 *     ./04_deque_clear_empty
 *
 *   Windows:
 *     g++ 04_deque_clear_empty.cpp -o 04_deque_clear_empty.exe
 *     04_deque_clear_empty
 */

int main() {
    deque<int> dq = {10, 20, 30, 40, 50};

    cout << "Original deque: ";
    for (int x : dq) {
        cout << x << " ";
    }
    cout << endl;

    cout << "Is deque empty? " << (dq.empty() ? "Yes" : "No") << endl; // Expected: No

    // Clear the deque
    dq.clear();
    cout << "\nAfter clear, size: " << dq.size() << endl;            // Expected: 0
    cout << "Is deque empty now? " << (dq.empty() ? "Yes" : "No") << endl; // Expected: Yes

    return 0;
}
