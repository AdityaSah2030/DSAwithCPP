#include <iostream>
#include <queue>
using namespace std;

/*
 * File: 03_queue_front_size_empty.cpp
 * Description:
 *   Demonstrates how to use front(), size(), and empty() with std::queue.
 *   - front(): Returns a reference to the front element.
 *   - size(): Returns the number of elements.
 *   - empty(): Checks if the queue is empty.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 03_queue_front_size_empty.cpp -o 03_queue_front_size_empty
 *     ./03_queue_front_size_empty
 *
 *   Windows:
 *     g++ 03_queue_front_size_empty.cpp -o 03_queue_front_size_empty.exe
 *     03_queue_front_size_empty
 */

int main() {
    queue<int> q;

    // Check if queue is empty initially
    cout << "Is queue empty initially? " << (q.empty() ? "Yes" : "No") << endl; 
    // Expected: Yes

    // Push some elements
    q.push(100);
    q.push(200);
    q.push(300);

    cout << "\nQueue size after pushes: " << q.size() << endl; // Expected: 3
    cout << "Is queue empty now? " << (q.empty() ? "Yes" : "No") << endl; // Expected: No

    // Access the front element
    cout << "Front element: " << q.front() << endl; // Expected: 100

    // Modify the front element indirectly (requires a reference)
    // In practice, front() is read-only for the element's content in many use cases,
    // but you can do something like this if it were an object you can modify:
    // q.front() += 50; // if it were safe to do so
    // However, for int, we can't reassign like q.front() = q.front() + 50; 
    // because std::queue's front() returns a reference only if underlying container allows it.

    // We'll just pop to demonstrate
    q.pop();
    cout << "After pop, new front: " << q.front() << endl; // Expected: 200

    return 0;
}
