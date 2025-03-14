#include <iostream>
#include <stack>
using namespace std;

/*
 * File: 03_stack_top_size_empty.cpp
 * Description:
 *   Demonstrates how to use top(), size(), and empty() with std::stack.
 *   - top(): Returns a reference to the top element.
 *   - size(): Returns the number of elements.
 *   - empty(): Checks if the stack is empty.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 03_stack_top_size_empty.cpp -o 03_stack_top_size_empty
 *     ./03_stack_top_size_empty
 *
 *   Windows:
 *     g++ 03_stack_top_size_empty.cpp -o 03_stack_top_size_empty.exe
 *     03_stack_top_size_empty
 */

int main() {
    stack<int> s;

    // Check if stack is empty initially
    cout << "Is stack empty initially? " << (s.empty() ? "Yes" : "No") << endl; 
    // Expected: Yes

    // Push some elements
    s.push(100);
    s.push(200);
    s.push(300);

    cout << "\nStack size after pushes: " << s.size() << endl; // Expected: 3
    cout << "Is stack empty now? " << (s.empty() ? "Yes" : "No") << endl; // Expected: No

    // Access the top element
    cout << "Top element: " << s.top() << endl; // Expected: 300

    // Modify the top element
    s.top() += 50;
    cout << "Top element after modification: " << s.top() << endl; // Expected: 350

    return 0;
}
