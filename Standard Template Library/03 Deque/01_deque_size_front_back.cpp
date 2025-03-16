#include <iostream>
#include <deque>
using namespace std;

/*
 * File: 01_deque_size_front_back.cpp
 * Description:
 *   Demonstrates how to initialize a std::deque, display its elements,
 *   and access its size, front, and back.
 *
 *   - size(): Returns the number of elements.
 *   - front(): Returns the first element.
 *   - back(): Returns the last element.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 01_deque_size_front_back.cpp -o 01_deque_size_front_back
 *     ./01_deque_size_front_back
 *
 *   Windows:
 *     g++ 01_deque_size_front_back.cpp -o 01_deque_size_front_back.exe
 *     01_deque_size_front_back
 */

int main() {
    // Initialize a deque with some elements
    deque<int> dq = {10, 20, 30, 40, 50};

    cout << "Deque elements: ";
    for (int x : dq) {
        cout << x << " ";
    }
    cout << endl;

    cout << "Size of deque: " << dq.size() << endl;       // Expected: 5
    cout << "First element (front): " << dq.front() << endl; // Expected: 10
    cout << "Last element (back): " << dq.back() << endl;    // Expected: 50

    return 0;
}
