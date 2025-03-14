#include <iostream>
#include <stack>
using namespace std;

/*
 * File: 04_stack_swap.cpp
 * Description:
 *   Demonstrates how to swap two stacks using the swap() method.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 04_stack_swap.cpp -o 04_stack_swap
 *     ./04_stack_swap
 *
 *   Windows:
 *     g++ 04_stack_swap.cpp -o 04_stack_swap.exe
 *     04_stack_swap
 */

void printStack(const string &label, stack<int> s) {
    cout << label;
    // Copy by value, so we can pop without affecting the original
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s1;
    stack<int> s2;

    // Push some elements in s1
    s1.push(1);
    s1.push(2);
    s1.push(3);

    // Push some elements in s2
    s2.push(10);
    s2.push(20);

    cout << "Before swap:" << endl;
    printStack("s1: ", s1); // Expected top-> 3,2,1
    printStack("s2: ", s2); // Expected top-> 20,10

    // Swap the stacks
    s1.swap(s2);

    cout << "\nAfter swap:" << endl;
    printStack("s1: ", s1); // Expected top-> 20,10
    printStack("s2: ", s2); // Expected top-> 3,2,1

    return 0;
}
