#include <iostream>
#include <queue>
#include <string>
using namespace std;

/*
 * File: 02_queue_emplace.cpp
 * Description:
 *   Demonstrates how to use emplace() with std::queue.
 *   emplace() constructs an element in place at the back of the queue,
 *   potentially avoiding unnecessary copies or moves.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 02_queue_emplace.cpp -o 02_queue_emplace
 *     ./02_queue_emplace
 *
 *   Windows:
 *     g++ 02_queue_emplace.cpp -o 02_queue_emplace.exe
 *     02_queue_emplace
 */

// A small struct to demonstrate emplace()
struct Person {
    string name;
    int age;
    Person(const string &n, int a) : name(n), age(a) {
        cout << "Constructing Person: " << name << ", age " << age << endl;
    }
};

int main() {
    queue<Person> personQueue;

    // Use emplace() to construct Person in place at the back
    personQueue.emplace("Alice", 25);
    personQueue.emplace("Bob", 30);

    // Access the front element
    cout << "\nFront of queue: " << personQueue.front().name
         << " (" << personQueue.front().age << ")" << endl;
    // Expected: Alice (25)

    // Pop one element
    personQueue.pop();
    cout << "After pop, new front: " << personQueue.front().name
         << " (" << personQueue.front().age << ")" << endl;
    // Expected: Bob (30)

    return 0;
}
