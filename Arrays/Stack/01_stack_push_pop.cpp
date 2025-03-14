#include <iostream>
#include <stack>
using namespace std;

/*
 * File: 01_stack_push_pop.cpp
 * Description:
 *   Demonstrates how to use push() and pop() with std::stack.
 *   - push(x): Inserts an element x on top of the stack.
 *   - pop(): Removes the top element.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 01_stack_push_pop.cpp -o 01_stack_push_pop
 *     ./01_stack_push_pop
 *
 *   Windows:
 *     g++ 01_stack_push_pop.cpp -o 01_stack_push_pop.exe
 *     01_stack_push_pop
 */

int main() {
    stack<int> s;

    // Push elements onto the stack
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Stack size after pushes: " << s.size() << endl; // Expected: 3

    // Pop an element from the stack
    s.pop(); // Removes 30
    cout << "Stack size after one pop: " << s.size() << endl; // Expected: 2

    // Pop another element
    s.pop(); // Removes 20
    cout << "Stack size after second pop: " << s.size() << endl; // Expected: 1

    return 0;
}
