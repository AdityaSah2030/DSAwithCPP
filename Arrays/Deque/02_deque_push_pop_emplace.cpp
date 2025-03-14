#include <iostream>
#include <deque>
#include <string>
using namespace std;

/*
 * File: 02_deque_push_pop_emplace.cpp
 * Description:
 *   Demonstrates how to add and remove elements in a std::deque using:
 *     - push_back(), push_front()
 *     - pop_back(), pop_front()
 *     - emplace_back(), emplace_front()
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 02_deque_push_pop_emplace.cpp -o 02_deque_push_pop_emplace
 *     ./02_deque_push_pop_emplace
 *
 *   Windows:
 *     g++ 02_deque_push_pop_emplace.cpp -o 02_deque_push_pop_emplace.exe
 *     02_deque_push_pop_emplace
 */

// A small struct to demonstrate emplace_back/emplace_front
struct Person {
    string name;
    int age;
    Person(const string &n, int a) : name(n), age(a) {
        cout << "Constructing Person: " << name << ", age " << age << endl;
    }
};

int main() {
    // 1) Demonstrate push_front, push_back, pop_front, pop_back with int
    deque<int> dq;

    // push_back
    dq.push_back(20);
    dq.push_back(30);
    dq.push_back(40);

    // push_front
    dq.push_front(10);
    dq.push_front(5);

    cout << "Deque after push_front and push_back: ";
    for (int x : dq) {
        cout << x << " ";
    }
    cout << endl;
    // Expected: 5 10 20 30 40

    // pop_front
    dq.pop_front(); // removes 5
    // pop_back
    dq.pop_back();  // removes 40

    cout << "Deque after pop_front and pop_back: ";
    for (int x : dq) {
        cout << x << " ";
    }
    cout << endl;
    // Expected: 10 20 30

    // 2) Demonstrate emplace_back, emplace_front with Person
    deque<Person> people;

    people.emplace_back("Alice", 25);
    people.emplace_back("Bob", 30);
    people.emplace_front("Zara", 20);

    cout << "\nDeque of Person after emplace_front/back:" << endl;
    for (auto &p : people) {
        cout << p.name << " (" << p.age << ")  ";
    }
    cout << endl;
    // Expected order: Zara(20), Alice(25), Bob(30)

    return 0;
}
