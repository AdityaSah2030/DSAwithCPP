#include <iostream>
#include <utility> // For std::pair and std::make_pair
#include <string>  // For std::string
#include <tuple>   // For std::tie (optional)
using namespace std;

/*
 * Program: 01_pair_basics.cpp
 * Description:
 *   Demonstrates how to use the pair data type in C++.
 *   A pair holds two values, accessible via 'first' and 'second'.
 *   We also show how to create nested pairs and use make_pair.
 *
 * Steps to Compile and Run (Linux/Mac):
 *   g++ 01_pair_basics.cpp -o 01_pair_basics
 *   ./01_pair_basics
 *
 * Steps to Compile and Run (Windows):
 *   g++ 01_pair_basics.cpp -o 01_pair_basics.exe
 *   01_pair_basics
 */

int main() {
    // 1) Basic pair of integers
    pair<int, int> p1 = {3, 5};
    cout << "p1.first = " << p1.first << ", p1.second = " << p1.second << endl;

    // 2) Pair with different types (char, int)
    pair<char, int> p2 = {'a', 1};
    cout << "p2.first = " << p2.first << ", p2.second = " << p2.second << endl;

    // 3) Nested pair (pair of an int and another pair<int,int>)
    pair<int, pair<int, int>> p3 = {1, {2, 3}};
    cout << "p3.first = " << p3.first << endl;
    cout << "p3.second.first = " << p3.second.first << endl;
    cout << "p3.second.second = " << p3.second.second << endl;

    // 4) Using make_pair to create a pair
    auto p4 = make_pair(string("hello"), 10);
    cout << "p4.first = " << p4.first << ", p4.second = " << p4.second << endl;

    // 5) (Optional) Unpacking a pair using tie
    int x, y;
    tie(x, y) = p1;  // p1 was {3, 5}
    cout << "Unpacked p1 using tie: x = " << x << ", y = " << y << endl;

    return 0;
}
