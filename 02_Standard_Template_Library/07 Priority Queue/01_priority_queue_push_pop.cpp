#include <iostream>
#include <queue>
using namespace std;

/*
 * File: 01_priority_queue_push_pop.cpp
 * Description:
 *   Demonstrates how to use push() and pop() with std::priority_queue.
 *   By default, std::priority_queue creates a max-heap (largest element on top).
 *
 *   - push(x): Inserts element x into the priority queue.
 *   - pop(): Removes the top (largest) element in the default comparator.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 01_priority_queue_push_pop.cpp -o 01_priority_queue_push_pop
 *     ./01_priority_queue_push_pop
 *
 *   Windows:
 *     g++ 01_priority_queue_push_pop.cpp -o 01_priority_queue_push_pop.exe
 *     01_priority_queue_push_pop
 */

int main() {
    // By default, it's a max-heap
    priority_queue<int> pq;

    // Push elements
    pq.push(10);
    pq.push(5);
    pq.push(20);
    pq.push(15);

    cout << "Size of priority_queue after pushes: " << pq.size() << endl; // Expected: 4

    // Pop elements one by one, printing the top each time
    while (!pq.empty()) {
        cout << "Top: " << pq.top() << endl; // Largest element first
        pq.pop();
    }
    // Expected pop order: 20, 15, 10, 5

    return 0;
}
