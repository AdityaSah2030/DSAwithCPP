class Solution {
public:
    bool isPowerOfFour(int n) {
        // We combine three checks in one line:
        // 1. n > 0: Must be positive.
        // 2. (n & (n - 1)) == 0: Must be a power of two.
        // 3. (n - 1) % 3 == 0: The specific property of powers of four.
        return n > 0 && (n & (n - 1)) == 0 && (n - 1) % 3 == 0;
    }
};