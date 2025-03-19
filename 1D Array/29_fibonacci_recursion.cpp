#include <iostream>
#include <vector>
using namespace std;

/*
 * File: 29_fibonacci_recursion.cpp
 * Description:
 *   Demonstrates how to compute and print the Fibonacci series up to n terms
 *   using a memoized recursive function (the most optimized recursive approach).
 *
 *   The naive recursion for Fibonacci is O(2^n), but with memoization, we achieve O(n).
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 29_fibonacci_recursion.cpp -o fib_recursion
 *     ./fib_recursion
 *
 *   Windows:
 *     g++ 29_fibonacci_recursion.cpp -o fib_recursion.exe
 *     fib_recursion
 */

// Recursive function with memoization to compute the nth Fibonacci number
long long fibMemo(int n, vector<long long> &memo) {
    // If already computed, return it
    if (memo[n] != -1) {
        return memo[n];
    }

    // Base cases
    if (n == 0) {
        memo[n] = 0;
        return 0;
    }
    if (n == 1) {
        memo[n] = 1;
        return 1;
    }

    // Recursive step with memo
    memo[n] = fibMemo(n-1, memo) + fibMemo(n-2, memo);
    return memo[n];
}

int main() {
    cout << "Enter the number of terms for the Fibonacci series: ";
    int n;
    cin >> n;

    if (n <= 0) {
        cout << "No terms to display." << endl;
        return 0;
    }

    // Create a memo array of size n (or n+1 for safety)
    vector<long long> memo(n+1, -1);

    cout << "Fibonacci series (first " << n << " terms):" << endl;
    for (int i = 0; i < n; i++) {
        cout << fibMemo(i, memo) << " ";
    }
    cout << endl;

    return 0;
}
