#include <iostream>
#include <queue>
using namespace std;

/*
 * File: 04_queue_swap.cpp
 * Description:
 *   Demonstrates how to swap two queues using the swap() method.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 04_queue_swap.cpp -o 04_queue_swap
 *     ./04_queue_swap
 *
 *   Windows:
 *     g++ 04_queue_swap.cpp -o 04_queue_swap.exe
 *     04_queue_swap
 */

// Helper function to print a queue's contents without modifying the original
void printQueue(const string &label, queue<int> q) {
    cout << label;
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q1;
    queue<int> q2;

    // Push some elements in q1
    q1.push(1);
    q1.push(2);
    q1.push(3);

    // Push some elements in q2
    q2.push(10);
    q2.push(20);

    cout << "Before swap:" << endl;
    printQueue("q1: ", q1); // front-> 1,2,3
    printQueue("q2: ", q2); // front-> 10,20

    // Swap the queues
    q1.swap(q2);

    cout << "\nAfter swap:" << endl;
    printQueue("q1: ", q1); // front-> 10,20
    printQueue("q2: ", q2); // front-> 1,2,3

    return 0;
}
