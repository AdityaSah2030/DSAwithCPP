int fib(int n) {
    // Base cases
    if (n <= 1) {
        return n;
    }

    // Iterative approach with O(1) space
    int a = 0; // Represents F(i-2)
    int b = 1; // Represents F(i-1)

    // Loop from 2 to n to calculate F(n)
    for (int i = 2; i <= n; ++i) {
        int sum = a + b;
        a = b;
        b = sum;
    }

    return b; // b holds the final F(n)
}