#include <iostream>
#include <list>
using namespace std;

/*
 * File: 01_list_size.cpp
 * Description:
 *   Demonstrates how to initialize a std::list, display its elements, and access its
 *   size, front, and back.
 *
 * Functions used:
 *   - size(): Returns the number of elements in the list.
 *   - front(): Returns the first element.
 *   - back(): Returns the last element.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 01_list_size.cpp -o 01_list_size
 *     ./01_list_size
 *
 *   Windows:
 *     g++ 01_list_size.cpp -o 01_list_size.exe
 *     01_list_size
 */

int main() {
    list<int> lst = {10, 20, 30, 40, 50};

    cout << "List elements: ";
    for (int x : lst) {
        cout << x << " ";
    }
    cout << endl;

    cout << "Size of list: " << lst.size() << endl;       // Expected: 5
    cout << "First element (front): " << lst.front() << endl; // Expected: 10
    cout << "Last element (back): " << lst.back() << endl;    // Expected: 50

    return 0;
}
