#include <iostream>
#include <list>
#include <string>
using namespace std;

/*
 * File: 02_list_push_back_push_front.cpp
 * Description:
 *   Demonstrates how to add elements to a std::list using:
 *     - push_back() / push_front()
 *     - emplace_back() / emplace_front()
 *
 *   push_back(x): Inserts x at the end (requires an existing object x).
 *   push_front(x): Inserts x at the front.
 *
 *   emplace_back(args...): Constructs an element in-place at the end,
 *                          potentially avoiding copies/moves.
 *   emplace_front(args...): Constructs an element in-place at the front.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 02_list_push_back_push_front.cpp -o 02_list_push_back_push_front
 *     ./02_list_push_back_push_front
 *
 *   Windows:
 *     g++ 02_list_push_back_push_front.cpp -o 02_list_push_back_push_front.exe
 *     02_list_push_back_push_front
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
    // 1) Basic integer list demonstration
    list<int> lst;

    // Insert elements using push_back()
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);

    // Insert elements using push_front()
    lst.push_front(10);
    lst.push_front(5);

    cout << "List of integers after push_back() and push_front(): ";
    for (int x : lst) {
        cout << x << " ";
    }
    cout << endl;
    // Expected output: 5 10 20 30 40

    // 2) Demonstrate emplace_back and emplace_front
    //    We'll use a separate list of Persons for clarity.
    list<Person> people;

    // emplace_back() constructs Person in-place at the end
    people.emplace_back("Alice", 25);
    people.emplace_back("Bob", 30);

    // emplace_front() constructs Person in-place at the front
    people.emplace_front("Zara", 20);

    cout << "\nList of Persons after emplace_front() and emplace_back():" << endl;
    for (auto &p : people) {
        cout << p.name << " (" << p.age << ")  ";
    }
    cout << endl;
    // Expected order: Zara (20), Alice (25), Bob (30)

    return 0;
}
