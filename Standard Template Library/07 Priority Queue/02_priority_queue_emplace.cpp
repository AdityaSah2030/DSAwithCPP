#include <iostream>
#include <queue>
#include <string>
using namespace std;

/*
 * File: 02_priority_queue_emplace.cpp
 * Description:
 *   Demonstrates how to use emplace() with std::priority_queue.
 *   emplace() constructs an element in place, potentially avoiding copies or moves.
 *   By default, std::priority_queue uses max-heap behavior.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 02_priority_queue_emplace.cpp -o 02_priority_queue_emplace
 *     ./02_priority_queue_emplace
 *
 *   Windows:
 *     g++ 02_priority_queue_emplace.cpp -o 02_priority_queue_emplace.exe
 *     02_priority_queue_emplace
 */

// Simple struct to demonstrate emplace()
struct Person {
    string name;
    int age;
    Person(const string &n, int a) : name(n), age(a) {
        cout << "Constructing Person: " << name << ", age " << age << endl;
    }
};

// A comparator for Person to create a max-heap based on age
struct PersonComparator {
    bool operator()(const Person &p1, const Person &p2) {
        // Return true if p1 < p2 (meaning p1 should go after p2 in a max-heap)
        return p1.age < p2.age;
    }
};

int main() {
    // priority_queue with a custom comparator
    priority_queue<Person, vector<Person>, PersonComparator> pq;

    // Use emplace() to construct Person in place
    pq.emplace("Alice", 25);
    pq.emplace("Bob", 30);
    pq.emplace("Zara", 20);

    // The top will be the Person with the highest age (Bob, 30)
    cout << "\nTop of priority_queue: " << pq.top().name
         << " (Age: " << pq.top().age << ")" << endl;

    // Pop one element
    pq.pop(); // removes Bob (30)
    cout << "After pop, new top: " << pq.top().name
         << " (Age: " << pq.top().age << ")" << endl;
    // Expected top: Alice (25)

    return 0;
}
