#include <iostream>
#include <vector>
using namespace std;

/*
 * Program: 04_majority_element_moores.cpp
 * Description:
 *   Given an array of size n, return the majority element.
 *   The majority element is the one that appears more than n/2 times.
 *   It is guaranteed (by the problem statement) that a majority element always exists.
 *
 *   This solution uses Moore's Voting Algorithm, which runs in O(n) time
 *   and O(1) extra space.
 *
 * Moore's Voting Algorithm Steps:
 *   1. Initialize two variables: candidate (any value) and count = 0.
 *   2. Traverse the array:
 *      - If count == 0, set candidate = current element.
 *      - If the current element == candidate, increment count.
 *      - Else, decrement count.
 *   3. The candidate after the first pass is the majority element.
 *      (Given the problem guarantees that a majority element exists, no second pass is required.)
 *
 * Example Test Cases:
 *   1) nums = [3, 2, 3]
 *      Majority element: 3
 *
 *   2) nums = [2, 2, 1, 1, 1, 2, 2]
 *      Majority element: 2
 *
 *   3) nums = [1]
 *      Majority element: 1
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 04_majority_element_moores.cpp -o 04_majority_element_moores
 *     ./04_majority_element_moores
 *
 *   Windows:
 *     g++ 04_majority_element_moores.cpp -o 04_majority_element_moores.exe
 *     04_majority_element_moores
 */

// Function implementing Moore's Voting Algorithm
int majorityElement(const vector<int>& nums) {
    int candidate = 0;
    int count = 0;

    // 1st pass: Find the candidate
    for (int num : nums) {
        if (count == 0) {
            candidate = num;  // Set a new candidate
            count = 1;        // Reset count
        } else if (num == candidate) {
            count++;          // Same as candidate, increment count
        } else {
            count--;          // Different from candidate, decrement count
        }
    }

    // Given the problem statement guarantees a majority element, we do not need a second pass.
    // If a second pass was required for verification, we would count the occurrences of 'candidate'
    // and check if it exceeds nums.size() / 2.

    return candidate;
}

int main() {
    // Test Case 1
    vector<int> nums1 = {3, 2, 3};
    cout << "Test Case 1: [3, 2, 3]" << endl;
    cout << "Majority Element: " << majorityElement(nums1) << endl;
    // Expected output: 3

    cout << endl;

    // Test Case 2
    vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
    cout << "Test Case 2: [2, 2, 1, 1, 1, 2, 2]" << endl;
    cout << "Majority Element: " << majorityElement(nums2) << endl;
    // Expected output: 2

    cout << endl;

    // Test Case 3
    vector<int> nums3 = {1};
    cout << "Test Case 3: [1]" << endl;
    cout << "Majority Element: " << majorityElement(nums3) << endl;
    // Expected output: 1

    return 0;
}
