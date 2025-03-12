#include <iostream>
#include <vector>
using namespace std;

/*
 * Program: 07_product_of_array_except_self.cpp
 * Description:
 *   Given an integer array nums, return an array answer such that answer[i]
 *   is equal to the product of all the elements of nums except nums[i].
 *   The product of any prefix or suffix of nums is guaranteed to fit in a
 *   32-bit integer.
 *
 *   The solution should run in O(n) time and not use the division operator.
 *
 * Approach (Prefix and Suffix Products):
 *   1. Create an output array (answer) of the same length as nums.
 *   2. First pass (prefix products):
 *      - Initialize a variable prefix = 1.
 *      - Iterate from left to right:
 *        answer[i] = prefix
 *        prefix *= nums[i]
 *   3. Second pass (suffix products):
 *      - Initialize a variable suffix = 1.
 *      - Iterate from right to left:
 *        answer[i] *= suffix
 *        suffix *= nums[i]
 *   4. Return answer.
 *
 *   This way, answer[i] gets the product of all elements to the left (from the prefix pass)
 *   multiplied by the product of all elements to the right (from the suffix pass).
 *
 * Constraints:
 *   - 2 <= nums.length <= 10^5
 *   - -30 <= nums[i] <= 30
 *   - The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 07_product_of_array_except_self.cpp -o 07_product_of_array_except_self
 *     ./07_product_of_array_except_self
 *
 *   Windows:
 *     g++ 07_product_of_array_except_self.cpp -o 07_product_of_array_except_self.exe
 *     07_product_of_array_except_self
 */

// Function to compute the product of array except self
vector<int> productExceptSelf(const vector<int>& nums) {
    int n = nums.size();
    vector<int> answer(n, 1); // This will hold the final products

    // Step 1: Build prefix products
    // prefix holds the product of all elements to the left of the current index
    int prefix = 1;
    for (int i = 0; i < n; i++) {
        answer[i] = prefix;
        prefix *= nums[i];
    }

    // Step 2: Build suffix products
    // suffix holds the product of all elements to the right of the current index
    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        answer[i] *= suffix; // multiply the existing prefix product with suffix
        suffix *= nums[i];
    }

    return answer;
}

int main() {
    // Test Case 1
    vector<int> nums1 = {1, 2, 3, 4};
    cout << "Test Case 1: [1, 2, 3, 4]" << endl;
    vector<int> result1 = productExceptSelf(nums1);
    cout << "Output: [";
    for (int i = 0; i < (int)result1.size(); i++) {
        cout << result1[i];
        if (i < (int)result1.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    // Expected output: [24, 12, 8, 6]

    cout << endl;

    // Test Case 2
    vector<int> nums2 = {-1, 1, 0, -3};
    cout << "Test Case 2: [-1, 1, 0, -3]" << endl;
    vector<int> result2 = productExceptSelf(nums2);
    cout << "Output: [";
    for (int i = 0; i < (int)result2.size(); i++) {
        cout << result2[i];
        if (i < (int)result2.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    // Expected output: [0, 0, -3 * -1, 0] = [0, 0, 3, 0]
    // Explanation:
    // - For index 0 (-1), product of [1, 0, -3] = 0
    // - For index 1 (1), product of [-1, 0, -3] = 0
    // - For index 2 (0), product of [-1, 1, -3] = 3
    // - For index 3 (-3), product of [-1, 1, 0] = 0

    return 0;
}
