class Solution {
public:
    // Define the modulus as a constant
    long long MOD = 1e9 + 7;

    // Recursive function to compute (base^exp) % MOD in O(log exp) time
    long long power(long long base, long long exp) {
        // Base case: anything to the power of 0 is 1
        if (exp == 0) {
            return 1;
        }

        // Calculate power for half the exponent
        long long half = power(base, exp / 2);

        // Result is (half * half). All multiplications are under MOD.
        long long result = (half * half) % MOD;

        // If the exponent is odd, we need to multiply by the base one more time
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        
        return result;
    }

    int countGoodNumbers(long long n) {
        // Number of odd positions (indices 1, 3, 5...)
        long long odd_indices = n / 2;
        
        // Number of even positions (indices 0, 2, 4...)
        long long even_indices = (n + 1) / 2; // or n - odd_indices

        // Calculate (5^even_indices) % MOD
        long long count_even = power(5, even_indices);
        
        // Calculate (4^odd_indices) % MOD
        long long count_odd = power(4, odd_indices);

        // Final result is (count_even * count_odd) % MOD
        return (count_even * count_odd) % MOD;
    }
};