#include <iostream>
#include <list>
using namespace std;

/*
 * File: 05_list_clear_empty.cpp
 * Description:
 *   Demonstrates how to clear a std::list and check if it is empty.
 *
 *   - clear(): Removes all elements from the list.
 *   - empty(): Returns true if the list is empty.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 05_list_clear_empty.cpp -o 05_list_clear_empty
 *     ./05_list_clear_empty
 *
 *   Windows:
 *     g++ 05_list_clear_empty.cpp -o 05_list_clear_empty.exe
 *     05_list_clear_empty
 */

int main() {
    list<int> lst = {10, 20, 30, 40, 50};
    
    cout << "Original list: ";
    for (int x : lst) {
        cout << x << " ";
    }
    cout << endl;
    
    cout << "Is list empty? " << (lst.empty() ? "Yes" : "No") << endl;  // Expected: No
    
    // Clear the list
    lst.clear();
    cout << "\nAfter clear, list size: " << lst.size() << endl;         // Expected: 0
    cout << "Is list empty now? " << (lst.empty() ? "Yes" : "No") << endl; // Expected: Yes
    
    return 0;
}
