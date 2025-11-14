#include <iostream>
#include <list>
using namespace std;

/*
 * File: 04_list_insert_erase.cpp
 * Description:
 *   Demonstrates how to insert and erase elements in a std::list.
 *
 *   - insert(pos, value): Inserts value before the iterator pos.
 *   - erase(pos): Removes the element at the iterator pos.
 *   - erase(start, end): Removes all elements in the range [start, end).
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 04_list_insert_erase.cpp -o 04_list_insert_erase
 *     ./04_list_insert_erase
 *
 *   Windows:
 *     g++ 04_list_insert_erase.cpp -o 04_list_insert_erase.exe
 *     04_list_insert_erase
 */

int main() {
    list<int> lst = {10, 20, 30, 40};
    
    cout << "Original list: ";
    for (int x : lst) {
        cout << x << " ";
    }
    cout << endl;
    
    // Insert 15 before element 20.
    auto it = lst.begin();
    while (it != lst.end() && *it != 20) {
        ++it;
    }
    lst.insert(it, 15); // List becomes: 10, 15, 20, 30, 40
    cout << "After inserting 15 before 20: ";
    for (int x : lst) {
        cout << x << " ";
    }
    cout << endl;
    
    // Erase element 30.
    it = lst.begin();
    while (it != lst.end() && *it != 30) {
        ++it;
    }
    if (it != lst.end()) {
        lst.erase(it);
    }
    cout << "After erasing 30: ";
    for (int x : lst) {
        cout << x << " ";
    }
    cout << endl;
    // Expected final list: 10, 15, 20, 40
    
    return 0;
}
