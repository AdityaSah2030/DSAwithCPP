#include <iostream>
using namespace std;

/*
 * File: 22_lcm_euclid.cpp
 * Description:
 *   Demonstrates how to find the LCM (Least Common Multiple) of two integers.
 *   We use the relationship:
 *     LCM(a, b) = (a * b) / GCD(a, b)
 *
 *   GCD is computed via Euclid's Algorithm.
 *
 * Example:
 *   - gcd(12, 18) = 6
 *   - lcm(12, 18) = (12 * 18) / 6 = 36
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 22_lcm_euclid.cpp -o 22_lcm_euclid
 *     ./22_lcm_euclid
 *
 *   Windows:
 *     g++ 22_lcm_euclid.cpp -o 22_lcm_euclid.exe
 *     22_lcm_euclid
 */

// Euclid's Algorithm to find GCD of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Compute LCM using gcd
long long lcm(int a, int b) {
    // Use 1LL to ensure 64-bit multiplication if needed
    // (a / gcd(a, b)) * b is another safe approach to avoid overflow
    return static_cast<long long>(a) * b / gcd(a, b);
}

int main() {
    cout << "Enter two integers to find their LCM: ";
    int x, y;
    cin >> x >> y;

    long long result = lcm(x, y);
    cout << "LCM(" << x << ", " << y << ") = " << result << endl;

    // Additional demonstration
    cout << "\nAnother example: LCM(12, 18) = " << lcm(12, 18) << endl;  // Expected: 36

    return 0;
}
