#include <iostream>
using namespace std;

/*
 * File: 21_euclids_algorithm.cpp
 * Description:
 *   Demonstrates how to find the GCD (Greatest Common Divisor) of two numbers
 *   using Euclid's Algorithm.
 *
 * Euclid's Algorithm (Recursive Explanation):
 *   gcd(a, b):
 *     1) If b == 0, gcd = a.
 *     2) Otherwise, gcd(a, b) = gcd(b, a % b).
 *
 * Example:
 *   gcd(12, 8):
 *     - gcd(8, 12 % 8) = gcd(8, 4)
 *     - gcd(8, 4) = gcd(4, 8 % 4) = gcd(4, 0) = 4
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 21_euclids_algorithm.cpp -o 21_euclids_algorithm
 *     ./21_euclids_algorithm
 *
 *   Windows:
 *     g++ 21_euclids_algorithm.cpp -o 21_euclids_algorithm.exe
 *     21_euclids_algorithm
 */

// Recursive function to compute GCD using Euclid's Algorithm
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    // Example usage
    cout << "Enter two integers to find their GCD: ";
    int x, y;
    cin >> x >> y;

    int result = gcd(x, y);
    cout << "GCD(" << x << ", " << y << ") = " << result << endl;

    // Additional demonstration
    cout << "\nAnother example: gcd(36, 24) = " << gcd(36, 24) << endl;  // Expected: 12

    return 0;
}
