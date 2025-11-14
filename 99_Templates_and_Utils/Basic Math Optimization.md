# Basic Maths Optimisations

This document provides optimized algorithms for common mathematical operations in competitive programming and algorithm development.

## 1. Counting Number of Digits

### Method 1: Logarithmic Approach

```cpp
int countDigits(int n) {
    // Handle edge case
    if (n == 0) return 1;
    
    // Handle negative numbers
    n = abs(n);
    
    // Log10(n) + 1 gives the number of digits
    return floor(log10(n) + 1);
}
```

### Method 2: Iterative Approach

```cpp
int countDigits(int n) {
    // Handle edge case
    if (n == 0) return 1;
    
    // Handle negative numbers
    n = abs(n);
    
    int count = 0;
    while (n > 0) {
        n /= 10;
        count++;
    }
    return count;
}
```

**Time Complexity**: O(log n) for both methods
**Space Complexity**: O(1)

## 2. Print All Divisors of a Number

### Optimized Approach

```cpp
vector<int> printDivisors(int n) {
    vector<int> divisors;
    
    // Iterate only till square root of n
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            // If divisors are equal, print only one
            divisors.push_back(i);
            
            // Otherwise print both
            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }
    
    // Sort for ascending order
    sort(divisors.begin(), divisors.end());
    return divisors;
}
```

**Time Complexity**: O(sqrt(n) + k log k) where k is the number of divisors
**Space Complexity**: O(k) where k is the number of divisors

## 3. Check for Prime Number

### Optimized Approach

```cpp
bool isPrime(int n) {
    // Handle edge cases
    if (n <= 1) return false;
    if (n <= 3) return true;
    
    // Skip middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    // Check through all numbers of form 6k ± 1
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    
    return true;
}
```

**Time Complexity**: O(sqrt(n))
**Space Complexity**: O(1)

## 4. Print Prime Factors of a Number

### Optimized Approach

```cpp
vector<int> primeFactors(int n) {
    vector<int> factors;
    
    // Print all 2s that divide n
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }
    
    // n must be odd at this point
    // Iterate only for odd numbers, starting from 3
    for (int i = 3; i * i <= n; i += 2) {
        // While i divides n, print i and divide n
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    
    // If n is a prime number greater than 2
    if (n > 2) {
        factors.push_back(n);
    }
    
    return factors;
}
```

**Time Complexity**: O(sqrt(n))
**Space Complexity**: O(log n)

## 5. Fast Exponentiation (Binary Exponentiation)

### Recursive Approach

```cpp
long long fastPow(long long base, long long exp) {
    // Base cases
    if (exp == 0) return 1;
    if (exp == 1) return base;
    
    // Recursive case: compute half of the exponentiation
    long long half = fastPow(base, exp / 2);
    
    // If exponent is even, return half * half
    if (exp % 2 == 0) return half * half;
    
    // If exponent is odd, return half * half * base
    return half * half * base;
}
```

### Iterative Approach (More efficient)

```cpp
long long fastPow(long long base, long long exp) {
    long long result = 1;
    
    // Continue until exp becomes 0
    while (exp > 0) {
        // If exp is odd, multiply result with base
        if (exp & 1) {
            result *= base;
        }
        
        // Divide exp by 2 and square base
        base *= base;
        exp >>= 1;
    }
    
    return result;
}
```

### Modular Exponentiation

```cpp
long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    
    // Update base to base % mod
    base %= mod;
    
    while (exp > 0) {
        // If exp is odd, multiply result with base
        if (exp & 1) {
            result = (result * base) % mod;
        }
        
        // Divide exp by 2 and square base
        base = (base * base) % mod;
        exp >>= 1;
    }
    
    return result;
}
```

**Time Complexity**: O(log n)
**Space Complexity**: O(1) for iterative, O(log n) for recursive due to call stack

## 6. Sieve of Eratosthenes

### Basic Implementation

```cpp
vector<bool> sieveOfEratosthenes(int n) {
    // Create a boolean array "isPrime" and initialize all entries as true
    vector<bool> isPrime(n + 1, true);
    
    // Mark 0 and 1 as non-prime
    isPrime[0] = isPrime[1] = false;
    
    // Start iterating from 2
    for (int i = 2; i * i <= n; i++) {
        // If isPrime[i] is true, then it's a prime
        if (isPrime[i]) {
            // Mark all multiples of i as non-prime
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    return isPrime;
}
```

### Optimized Implementation (marking only odd numbers)

```cpp
vector<bool> sieveOfEratosthenes(int n) {
    // Handle edge cases
    if (n <= 1) return vector<bool>(n + 1, false);
    
    // Create a boolean array and initialize
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    
    // Mark all even numbers > 2 as non-prime
    for (int i = 4; i <= n; i += 2) {
        isPrime[i] = false;
    }
    
    // Mark multiples of odd numbers
    for (int i = 3; i * i <= n; i += 2) {
        if (isPrime[i]) {
            // Mark all multiples of i starting from i*i
            for (int j = i * i; j <= n; j += 2 * i) {
                isPrime[j] = false;
            }
        }
    }
    
    return isPrime;
}
```

**Time Complexity**: O(n log log n)
**Space Complexity**: O(n)

## 7. Count Primes in Range [L, R]

### Using Segmented Sieve

```cpp
int countPrimesInRange(long long L, long long R) {
    // Generate all primes up to sqrt(R)
    int limit = sqrt(R);
    vector<bool> mark(limit + 1, true);
    vector<int> primes;
    
    // Standard Sieve of Eratosthenes to find primes up to sqrt(R)
    for (int i = 2; i <= limit; i++) {
        if (mark[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= limit; j += i) {
                mark[j] = false;
            }
        }
    }
    
    // Now use these primes to mark all non-primes in range [L, R]
    vector<bool> isPrime(R - L + 1, true);
    
    // If L is 1, mark it as non-prime
    if (L == 1) isPrime[0] = false;
    
    // Mark all multiples of primes in range [L, R]
    for (int i : primes) {
        // Find the first multiple of i in range [L, R]
        long long firstMultiple = (L / i) * i;
        if (firstMultiple < L) firstMultiple += i;
        
        // Make sure we don't mark the prime itself as non-prime
        if (firstMultiple == i) firstMultiple += i;
        
        // Mark all multiples of i in range [L, R] as non-prime
        for (long long j = firstMultiple; j <= R; j += i) {
            isPrime[j - L] = false;
        }
    }
    
    // Count all primes in range [L, R]
    int count = 0;
    for (bool prime : isPrime) {
        if (prime) count++;
    }
    
    return count;
}
```

**Time Complexity**: O(sqrt(R) + (R-L+1) log log R)
**Space Complexity**: O(sqrt(R) + (R-L+1))

## 8. Smallest Prime Factor of a Number

### Using Sieve

```cpp
vector<int> smallestPrimeFactor(int n) {
    vector<int> spf(n + 1);
    
    // Initialize SPF for every number
    for (int i = 1; i <= n; i++) {
        spf[i] = i;  // Initially, SPF is the number itself
    }
    
    // Apply Sieve
    for (int i = 2; i * i <= n; i++) {
        // If i is prime (its SPF is still i)
        if (spf[i] == i) {
            // Mark SPF for all multiples of i
            for (int j = i * i; j <= n; j += i) {
                // Update if not already updated
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
    
    return spf;
}
```

### Using SPF to Find Prime Factorization

```cpp
vector<int> primeFactorization(int n, const vector<int>& spf) {
    vector<int> factors;
    
    // Extract prime factors using SPF
    while (n > 1) {
        factors.push_back(spf[n]);
        n /= spf[n];
    }
    
    return factors;
}
```

**Time Complexity**:

- Preprocessing (computing SPF): O(n log log n)
- Finding prime factorization: O(log n)
**Space Complexity**: O(n) for the SPF array

## Summary of Time & Space Complexities

| Algorithm | Time Complexity | Space Complexity |
|-----------|-----------------|------------------|
| Counting Digits | O(log n) | O(1) |
| Print All Divisors | O(sqrt(n) + k log k) | O(k) |
| Check for Prime | O(sqrt(n)) | O(1) |
| Prime Factorization | O(sqrt(n)) | O(log n) |
| Fast Exponentiation | O(log n) | O(1) |
| Sieve of Eratosthenes | O(n log log n) | O(n) |
| Count Primes in Range | O(sqrt(R) + (R-L+1) log log R) | O(sqrt(R) + (R-L+1)) |
| Smallest Prime Factor | O(n log log n) | O(n) |
