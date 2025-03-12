#include <iostream>
#include <cmath>  // For comparison, if needed
using namespace std;

/*
 * Program: 05_pow_x_n.cpp
 * Description:
 *   Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).
 *   We use a fast exponentiation (binary exponentiation) approach.
 *
 * Algorithm (Fast Exponentiation):
 *   1. Handle negative exponents:
 *      - If n is negative, we convert the problem to pow(1/x, -n).
 *   2. Use a loop (or recursion) to repeatedly square x and reduce n by half:
 *      - While n > 0:
 *         a) If n is odd, multiply the result by x.
 *         b) Square x (x = x * x).
 *         c) Divide n by 2 (integer division).
 *   3. Return the result.
 *
 * Example Test Cases:
 *
 *   1) Input: x = 2.00000, n = 10
 *      Output: 1024.00000
 *
 *   2) Input: x = 2.10000, n = 3
 *      Output: 9.26100
 *
 *   3) Input: x = 2.00000, n = -2
 *      Output: 0.25000
 *
 * Constraints (from the problem statement):
 *   - -100.0 <= x <= 100.0
 *   - -2^31 <= n <= 2^31 - 1
 *   - n is an integer
 *   - Either x != 0 or n > 0
 *   - -10^4 <= x^n <= 10^4
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 05_pow_x_n.cpp -o 05_pow_x_n
 *     ./05_pow_x_n
 *
 *   Windows:
 *     g++ 05_pow_x_n.cpp -o 05_pow_x_n.exe
 *     05_pow_x_n
 */

// Function to calculate x^n using fast exponentiation
double myPow(double x, int n) {
    // If n is 0, x^0 = 1 (except x=0, but that case isn't typically asked for here)
    if (n == 0) return 1.0;

    // Handle negative exponents: x^(-n) = 1 / x^n
    long long exponent = n;  // Use long long to handle edge case n = -2^31
    if (exponent < 0) {
        x = 1 / x;
        exponent = -exponent;
    }

    double result = 1.0;
    // Fast exponentiation (iterative)
    while (exponent > 0) {
        // If the current exponent is odd, multiply result by x
        if (exponent & 1) {  // same as (exponent % 2 == 1)
            result *= x;
        }
        // Square x and halve the exponent
        x *= x;
        exponent >>= 1;  // same as exponent = exponent / 2
    }

    return result;
}

int main() {
    // Example Test Case 1
    double x1 = 2.00000;
    int n1 = 10;
    cout << "Test Case 1: x = " << x1 << ", n = " << n1 << endl;
    cout << "Result: " << myPow(x1, n1) << endl;
    // Expected Output: 1024.00000

    cout << endl;

    // Example Test Case 2
    double x2 = 2.10000;
    int n2 = 3;
    cout << "Test Case 2: x = " << x2 << ", n = " << n2 << endl;
    cout << "Result: " << myPow(x2, n2) << endl;
    // Expected Output: 9.26100

    cout << endl;

    // Example Test Case 3
    double x3 = 2.00000;
    int n3 = -2;
    cout << "Test Case 3: x = " << x3 << ", n = " << n3 << endl;
    cout << "Result: " << myPow(x3, n3) << endl;
    // Expected Output: 0.25000

    return 0;
}
