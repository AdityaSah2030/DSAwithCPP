#include <iostream>
#include <vector>
using namespace std;

/*
 * File: 20_sieve_of_eratosthenes.cpp
 * Description:
 *   Given an integer n, return the number of prime numbers strictly less than n,
 *   using the Sieve of Eratosthenes algorithm.
 *
 * Algorithm (Sieve of Eratosthenes):
 *   1) If n <= 2, return 0 (no primes < 2).
 *   2) Create a boolean vector "isPrime" of size n, initialized to true (index 0..n-1).
 *   3) Mark 0 and 1 as not prime (false).
 *   4) For each number i starting from 2 up to sqrt(n):
 *       - If isPrime[i] is true, mark all multiples of i (i*i, i*i+i, ...) as not prime.
 *   5) Count how many entries in "isPrime" are true from index 2 to n-1.
 *   6) Return that count.
 *
 * Example:
 *   Input: n = 10
 *   Output: 4
 *   Explanation: primes less than 10 are {2, 3, 5, 7}
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 20_sieve_of_eratosthenes.cpp -o 20_sieve_of_eratosthenes
 *     ./20_sieve_of_eratosthenes
 *
 *   Windows:
 *     g++ 20_sieve_of_eratosthenes.cpp -o 20_sieve_of_eratosthenes.exe
 *     20_sieve_of_eratosthenes
 */

// Function to count primes < n using the Sieve of Eratosthenes
int countPrimes(int n) {
    if (n <= 2) {
        return 0;
    }

    vector<bool> isPrime(n, true);

    // 0 and 1 are not prime
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i * i < n; i++) {
        if (isPrime[i]) {
            // Mark multiples of i, starting from i*i
            for (long long j = (long long)i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // Count how many are true
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            count++;
        }
    }
    return count;
}

int main() {
    // Example Test 1
    {
        int n = 10;
        cout << "Input: " << n << endl;
        int result = countPrimes(n);
        cout << "Output: " << result << endl; // Expected: 4 (2,3,5,7)
    }

    cout << endl;

    // Example Test 2
    {
        int n = 1;
        cout << "Input: " << n << endl;
        int result = countPrimes(n);
        cout << "Output: " << result << endl; // Expected: 0
    }

    cout << endl;

    // Custom user input
    {
        int n;
        cout << "Enter an integer n to count primes less than n: ";
        cin >> n;
        int result = countPrimes(n);
        cout << "Number of primes less than " << n << " is: " << result << endl;
    }

    return 0;
}
