#include <iostream>
#include <queue>
using namespace std;

/*
 * File: 03_priority_queue_top_size_empty.cpp
 * Description:
 *   Demonstrates how to use top(), size(), and empty() with std::priority_queue.
 *   - top(): Returns a const reference to the largest element (default comparator).
 *   - size(): Returns the number of elements.
 *   - empty(): Checks if the priority_queue is empty.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 03_priority_queue_top_size_empty.cpp -o 03_priority_queue_top_size_empty
 *     ./03_priority_queue_top_size_empty
 *
 *   Windows:
 *     g++ 03_priority_queue_top_size_empty.cpp -o 03_priority_queue_top_size_empty.exe
 *     03_priority_queue_top_size_empty
 */

int main() {
    priority_queue<int> pq;

    // Check if priority_queue is empty initially
    cout << "Is priority_queue empty initially? " << (pq.empty() ? "Yes" : "No") << endl; 
    // Expected: Yes

    // Push some elements
    pq.push(50);
    pq.push(10);
    pq.push(40);

    cout << "\nPriority_queue size after pushes: " << pq.size() << endl; // Expected: 3
    cout << "Is priority_queue empty now? " << (pq.empty() ? "Yes" : "No") << endl; // Expected: No

    // Access the top element (largest in default max-heap)
    cout << "Top element: " << pq.top() << endl; // Expected: 50

    // Pop one element to see how top changes
    pq.pop(); // removes 50
    cout << "New top after one pop: " << pq.top() << endl; // Expected: 40

    return 0;
}
