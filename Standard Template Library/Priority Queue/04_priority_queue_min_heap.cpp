#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
 * File: 04_priority_queue_min_heap.cpp
 * Description:
 *   Demonstrates how to create a min-heap using std::priority_queue by providing
 *   a custom comparator (greater<int>).
 *
 *   By default, std::priority_queue<int> is a max-heap.
 *   To create a min-heap, we can define:
 *     priority_queue<int, vector<int>, greater<int>> pq;
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 04_priority_queue_min_heap.cpp -o 04_priority_queue_min_heap
 *     ./04_priority_queue_min_heap
 *
 *   Windows:
 *     g++ 04_priority_queue_min_heap.cpp -o 04_priority_queue_min_heap.exe
 *     04_priority_queue_min_heap
 */

int main() {
    // Define a min-heap for integers
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Push elements
    minHeap.push(50);
    minHeap.push(10);
    minHeap.push(40);
    minHeap.push(20);

    cout << "Size of minHeap after pushes: " << minHeap.size() << endl; // Expected: 4

    // Pop elements in ascending order (smallest first)
    while (!minHeap.empty()) {
        cout << "Top (smallest): " << minHeap.top() << endl;
        minHeap.pop();
    }
    // Expected pop order: 10, 20, 40, 50

    return 0;
}
