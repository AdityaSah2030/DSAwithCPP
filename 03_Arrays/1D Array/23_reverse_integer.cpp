#include <iostream>
#include <climits> // For INT_MAX, INT_MIN
using namespace std;

/*
 * File: 23_reverse_integer.cpp
 * Description:
 *   Given a 32-bit signed integer x, return x with its digits reversed.
 *   If reversing x causes the value to go outside the signed 32-bit range,
 *   return 0.
 *
 *   Example 1:
 *     Input: x = 123
 *     Output: 321
 *
 *   Example 2:
 *     Input: x = -123
 *     Output: -321
 *
 * Approach:
 *   1) Store sign of x, convert x to positive if needed.
 *   2) Build the reversed number digit by digit (pop from x, push into result).
 *   3) Check for overflow/underflow before each push:
 *      - If result > INT_MAX/10, or result == INT_MAX/10 and pop > 7, overflow -> return 0.
 *   4) Multiply final result by sign.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 23_reverse_integer.cpp -o 23_reverse_integer
 *     ./23_reverse_integer
 *
 *   Windows:
 *     g++ 23_reverse_integer.cpp -o 23_reverse_integer.exe
 *     23_reverse_integer
 */

int reverseInteger(int x) {
    // Determine sign
    int sign = (x < 0) ? -1 : 1;
    // Convert x to positive for easier handling (watch out for INT_MIN)
    // Using long long to handle edge case if x = INT_MIN
    long long lx = static_cast<long long>(x) * sign;

    long long result = 0;

    while (lx > 0) {
        int pop = lx % 10; // get last digit
        lx /= 10;          // remove last digit

        // Check for overflow before pushing pop
        // 32-bit signed range: [-2^31, 2^31 - 1] => [-2147483648, 2147483647]
        if (result > INT_MAX / 10) {
            return 0; // overflow
        }
        if (result == INT_MAX / 10 && pop > 7) {
            return 0; // overflow
        }

        result = result * 10 + pop;
    }

    // Apply sign
    result = result * sign;

    // Final check if result is within 32-bit int range
    if (result < INT_MIN || result > INT_MAX) {
        return 0;
    }

    return static_cast<int>(result);
}

int main() {
    // Example 1
    {
        int x = 123;
        cout << "Input: " << x << endl;
        int ans = reverseInteger(x);
        cout << "Output: " << ans << endl;  // Expected: 321
    }

    cout << endl;

    // Example 2
    {
        int x = -123;
        cout << "Input: " << x << endl;
        int ans = reverseInteger(x);
        cout << "Output: " << ans << endl;  // Expected: -321
    }

    cout << endl;

    // Overflow example
    {
        int x = 1534236469; // Reversed is beyond 32-bit
        cout << "Input: " << x << endl;
        int ans = reverseInteger(x);
        cout << "Output (should be 0 due to overflow): " << ans << endl;
    }

    cout << endl;

    // Custom user input
    {
        cout << "Enter an integer to reverse: ";
        int x;
        cin >> x;
        int ans = reverseInteger(x);
        cout << "Reversed: " << ans << endl;
    }

    return 0;
}
