#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
 * File: 02_stack_emplace.cpp
 * Description:
 *   Demonstrates how to use emplace() with std::stack.
 *   emplace() constructs an element in place at the top of the stack,
 *   potentially avoiding unnecessary copies or moves.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 02_stack_emplace.cpp -o 02_stack_emplace
 *     ./02_stack_emplace
 *
 *   Windows:
 *     g++ 02_stack_emplace.cpp -o 02_stack_emplace.exe
 *     02_stack_emplace
 */

// Simple struct to demonstrate emplace()
struct Person {
    string name;
    int age;
    Person(const string &n, int a) : name(n), age(a) {
        cout << "Constructing Person: " << name << ", age " << age << endl;
    }
};

int main() {
    stack<Person> personStack;

    // Use emplace() to construct a Person in place
    personStack.emplace("Alice", 25);
    personStack.emplace("Bob", 30);

    // Check top element
    cout << "\nTop of stack: " << personStack.top().name
         << " (" << personStack.top().age << ")" << endl;
    // Expected: Bob (30)

    // Pop one element
    personStack.pop();
    cout << "After pop, new top: " << personStack.top().name
         << " (" << personStack.top().age << ")" << endl;
    // Expected: Alice (25)

    return 0;
}
