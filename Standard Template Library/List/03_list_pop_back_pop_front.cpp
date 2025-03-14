#include <iostream>
#include <list>
using namespace std;

/*
 * File: 03_list_pop_back_pop_front.cpp
 * Description:
 *   Demonstrates how to remove elements from a std::list using pop_back() and pop_front().
 *
 *   - pop_back(): Removes the last element from the list.
 *   - pop_front(): Removes the first element from the list.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 03_list_pop_back_pop_front.cpp -o 03_list_pop_back_pop_front
 *     ./03_list_pop_back_pop_front
 *
 *   Windows:
 *     g++ 03_list_pop_back_pop_front.cpp -o 03_list_pop_back_pop_front.exe
 *     03_list_pop_back_pop_front
 */

int main() {
    list<int> lst = {5, 10, 20, 30, 40};

    cout << "Original list: ";
    for (int x : lst) {
        cout << x << " ";
    }
    cout << endl;
    
    // Remove the first element using pop_front()
    lst.pop_front();  // removes 5
    cout << "After pop_front: ";
    for (int x : lst) {
        cout << x << " ";
    }
    cout << endl;
    
    // Remove the last element using pop_back()
    lst.pop_back();  // removes 40
    cout << "After pop_back: ";
    for (int x : lst) {
        cout << x << " ";
    }
    cout << endl;
    
    // Expected final list: 10 20 30
    
    return 0;
}
