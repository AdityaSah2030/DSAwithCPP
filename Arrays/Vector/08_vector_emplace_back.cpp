#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 * Program: 08_vector_emplace_back.cpp
 * Description:
 *   Demonstrates how to add elements to a vector using emplace_back().
 *   emplace_back() constructs the element in place, potentially avoiding
 *   unnecessary copies compared to push_back().
 *
 * Example:
 *   1) Using emplace_back() with integers
 *   2) Using emplace_back() with a user-defined struct or object
 *
 * Steps to Compile and Run (Linux/Mac):
 *   g++ 08_vector_emplace_back.cpp -o 08_vector_emplace_back
 *   ./08_vector_emplace_back
 *
 * Steps to Compile and Run (Windows):
 *   g++ 08_vector_emplace_back.cpp -o 08_vector_emplace_back.exe
 *   08_vector_emplace_back
 */

struct Person {
    string name;
    int age;
    // Constructor for demonstration
    Person(const string &n, int a) : name(n), age(a) {
        cout << "Constructing Person: " << n << ", age " << a << endl;
    }
};

int main() {
    // Example 1: emplace_back with integers
    vector<int> vInt;
    vInt.emplace_back(10);
    vInt.emplace_back(20);
    vInt.emplace_back(30);

    cout << "Vector of integers after emplace_back: ";
    for (int val : vInt) {
        cout << val << " ";
    }
    cout << endl;
    // Expected output: 10 20 30

    cout << endl;

    // Example 2: emplace_back with user-defined type
    vector<Person> people;
    // Notice how the constructor messages appear when using emplace_back
    people.emplace_back("Alice", 25);
    people.emplace_back("Bob", 30);

    cout << "\nPeople in vector: " << endl;
    for (auto &p : people) {
        cout << p.name << " (" << p.age << ")" << endl;
    }
    // Expected output (plus constructor messages):
    // Constructing Person: Alice, age 25
    // Constructing Person: Bob, age 30
    // People in vector:
    // Alice (25)
    // Bob (30)

    return 0;
}
