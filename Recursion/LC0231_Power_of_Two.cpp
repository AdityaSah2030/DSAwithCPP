class Solution {
public:
    bool isPowerOfTwo(int n) {
        // First, check the edge case. n must be positive.
        // Then, apply the bitwise trick.
        // If n is a power of two (e.g., 8, binary 1000),
        // n-1 will be one less (e.g., 7, binary 0111).
        // The bitwise AND (n & (n-1)) will be 0.
        return n > 0 && (n & (n - 1)) == 0;
    }
};