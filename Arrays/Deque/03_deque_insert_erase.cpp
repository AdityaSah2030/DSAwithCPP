#include <iostream>
#include <deque>
using namespace std;

/*
 * File: 03_deque_insert_erase.cpp
 * Description:
 *   Demonstrates how to insert and erase elements in a std::deque.
 *   - insert(pos, value): Inserts value before iterator pos.
 *   - erase(pos): Removes the element at iterator pos.
 *   - erase(start, end): Removes elements in the range [start, end).
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 03_deque_insert_erase.cpp -o 03_deque_insert_erase
 *     ./03_deque_insert_erase
 *
 *   Windows:
 *     g++ 03_deque_insert_erase.cpp -o 03_deque_insert_erase.exe
 *     03_deque_insert_erase
 */

int main() {
    deque<int> dq = {10, 20, 30, 40};

    cout << "Original deque: ";
    for (int x : dq) {
        cout << x << " ";
    }
    cout << endl;

    // Insert 15 before element 20
    auto it = dq.begin();
    while (it != dq.end() && *it != 20) {
        ++it;
    }
    dq.insert(it, 15); // Deque becomes: 10, 15, 20, 30, 40
    cout << "After inserting 15 before 20: ";
    for (int x : dq) {
        cout << x << " ";
    }
    cout << endl;

    // Erase element 30
    it = dq.begin();
    while (it != dq.end() && *it != 30) {
        ++it;
    }
    if (it != dq.end()) {
        dq.erase(it);
    }
    cout << "After erasing 30: ";
    for (int x : dq) {
        cout << x << " ";
    }
    cout << endl;
    // Expected final: 10, 15, 20, 40

    return 0;
}
