#include <iostream>
#include <vector>
#include <algorithm>  // For std::sort
#include <string>
using namespace std;

/*
 * File: 03_sort_custom_comparator.cpp
 * Description:
 *   Demonstrates how to use a custom comparator with std::sort.
 *
 *   We'll sort:
 *     1) A vector of pairs with a custom rule.
 *     2) A vector of a custom struct using a lambda comparator.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 03_sort_custom_comparator.cpp -o 03_sort_custom_comparator
 *     ./03_sort_custom_comparator
 *
 *   Windows:
 *     g++ 03_sort_custom_comparator.cpp -o 03_sort_custom_comparator.exe
 *     03_sort_custom_comparator
 */

// A simple struct
struct Person {
    string name;
    int age;
};

// Custom comparator function for pairs
// Sort by first ascending, then by second descending
bool pairComparator(const pair<int, int>& p1, const pair<int, int>& p2) {
    if (p1.first == p2.first) {
        // If first elements are equal, sort by second in descending order
        return p1.second > p2.second;
    }
    // Otherwise, sort by first in ascending order
    return p1.first < p2.first;
}

int main() {
    // 1) Sort a vector of pairs using a custom comparator function
    vector<pair<int, int>> vp = {{2, 5}, {2, 10}, {1, 5}, {3, 1}, {2, 7}};

    cout << "Original vector of pairs:\n";
    for (auto &p : vp) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    // Sort using pairComparator
    sort(vp.begin(), vp.end(), pairComparator);

    cout << "\nAfter custom sort (first ascending, second descending if firsts are equal):\n";
    for (auto &p : vp) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    // 2) Sort a vector of custom structs (Person) using a lambda
    vector<Person> people = {
        {"Alice", 30},
        {"Bob", 25},
        {"Charlie", 30},
        {"Dave", 20}
    };

    cout << "\nOriginal vector of Person:\n";
    for (auto &pr : people) {
        cout << pr.name << " (" << pr.age << ")  ";
    }
    cout << endl;

    // Sort by age ascending, then by name ascending
    sort(people.begin(), people.end(), [](const Person &a, const Person &b) {
        if (a.age == b.age) {
            return a.name < b.name;  // If ages are equal, sort by name
        }
        return a.age < b.age;        // Otherwise, sort by age
    });

    cout << "\nAfter custom sort on Person (age ascending, then name ascending):\n";
    for (auto &pr : people) {
        cout << pr.name << " (" << pr.age << ")  ";
    }
    cout << endl;

    return 0;
}
