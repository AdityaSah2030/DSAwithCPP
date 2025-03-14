#include <iostream>
#include <queue>
using namespace std;

/*
 * File: 01_queue_push_pop.cpp
 * Description:
 *   Demonstrates how to use push() and pop() with std::queue.
 *   - push(x): Inserts an element x at the back of the queue.
 *   - pop(): Removes the element at the front of the queue.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 01_queue_push_pop.cpp -o 01_queue_push_pop
 *     ./01_queue_push_pop
 *
 *   Windows:
 *     g++ 01_queue_push_pop.cpp -o 01_queue_push_pop.exe
 *     01_queue_push_pop
 */

int main() {
    queue<int> q;

    // Push elements into the queue
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Queue size after pushes: " << q.size() << endl; // Expected: 3

    // Pop an element from the queue
    q.pop(); // Removes 10 (the front)
    cout << "Queue size after one pop: " << q.size() << endl; // Expected: 2

    // Pop another element
    q.pop(); // Removes 20
    cout << "Queue size after second pop: " << q.size() << endl; // Expected: 1

    return 0;
}
