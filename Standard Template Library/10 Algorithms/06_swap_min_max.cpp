#include <iostream>
#include <algorithm> // For std::swap, std::min, std::max
#include <string>
using namespace std;

/*
 * File: 06_swap_min_max.cpp
 * Description:
 *   Demonstrates how to use std::swap, std::min, and std::max.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 06_swap_min_max.cpp -o 06_swap_min_max
 *     ./06_swap_min_max
 *
 *   Windows:
 *     g++ 06_swap_min_max.cpp -o 06_swap_min_max.exe
 *     06_swap_min_max
 */

int main() {
    // 1) Demonstrate std::swap
    int a = 10, b = 20;
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    swap(a, b);
    cout << "After swap: a = " << a << ", b = " << b << endl;

    // 2) Demonstrate std::min and std::max
    int x = 5, y = 7;
    cout << "\nmin(5, 7) = " << min(x, y) << endl; // Expected: 5
    cout << "max(5, 7) = " << max(x, y) << endl;   // Expected: 7

    // We can also use min and max with strings (lexicographical comparison)
    string s1 = "apple";
    string s2 = "banana";
    cout << "\nmin(\"apple\", \"banana\") = " << min(s1, s2) << endl;
    cout << "max(\"apple\", \"banana\") = " << max(s1, s2) << endl;

    // 3) Using min and max with multiple arguments (C++11)
    cout << "\nmin of {3, 1, 5, 2} = " << std::min({3, 1, 5, 2}) << endl; // 1
    cout << "max of {3, 1, 5, 2} = " << std::max({3, 1, 5, 2}) << endl;   // 5

    return 0;
}
