#include <iostream>
#include <vector>
#include <algorithm> // For min() function
using namespace std;

/*
 * Program: 06_container_with_most_water.cpp
 * Description:
 *   Given n non-negative integers a1, a2, ..., an, where each represents
 *   a point at coordinate (i, ai). n vertical lines are drawn such that
 *   the two endpoints of the ith line are (i, 0) and (i, ai). Find two
 *   lines that, together with the x-axis, form a container that contains
 *   the most water. Return the maximum amount of water a container can store.
 *
 * Approach (Two-Pointer Method):
 *   1. Initialize two pointers: left = 0, right = n-1.
 *   2. Calculate the current area:
 *        - height = min(height[left], height[right])
 *        - width = right - left
 *        - area = height * width
 *      Update maxArea if the current area is greater.
 *   3. Move the pointer that has the smaller height inward, because
 *      moving the larger-height pointer won't help in getting a bigger area.
 *   4. Repeat until left meets right.
 *   5. Time Complexity: O(n), Space Complexity: O(1).
 *
 * Example Test Cases:
 *
 *   1) height = [1, 8, 6, 2, 5, 4, 8, 3, 7]
 *      Expected output: 49
 *
 *   2) height = [1, 1]
 *      Expected output: 1
 *
 *   3) height = [4, 3, 2, 1, 4]
 *      Expected output: 16
 *
 *   4) height = [1, 2, 1]
 *      Expected output: 2
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 06_container_with_most_water.cpp -o 06_container_with_most_water
 *     ./06_container_with_most_water
 *
 *   Windows:
 *     g++ 06_container_with_most_water.cpp -o 06_container_with_most_water.exe
 *     06_container_with_most_water
 */

// Function to calculate maximum water container using two-pointer approach
int maxArea(const vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int maxAreaVal = 0;

    while (left < right) {
        // Calculate the current area
        int currentHeight = min(height[left], height[right]);
        int currentWidth = right - left;
        int currentArea = currentHeight * currentWidth;

        // Update max area if needed
        if (currentArea > maxAreaVal) {
            maxAreaVal = currentArea;
        }

        // Move the pointer that has the smaller height
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxAreaVal;
}

int main() {
    // Test Case 1
    vector<int> heights1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Test Case 1: [1, 8, 6, 2, 5, 4, 8, 3, 7]" << endl;
    cout << "Maximum Water: " << maxArea(heights1) << endl;
    // Expected output: 49

    cout << endl;

    // Test Case 2
    vector<int> heights2 = {1, 1};
    cout << "Test Case 2: [1, 1]" << endl;
    cout << "Maximum Water: " << maxArea(heights2) << endl;
    // Expected output: 1

    cout << endl;

    // Test Case 3
    vector<int> heights3 = {4, 3, 2, 1, 4};
    cout << "Test Case 3: [4, 3, 2, 1, 4]" << endl;
    cout << "Maximum Water: " << maxArea(heights3) << endl;
    // Expected output: 16

    cout << endl;

    // Test Case 4
    vector<int> heights4 = {1, 2, 1};
    cout << "Test Case 4: [1, 2, 1]" << endl;
    cout << "Maximum Water: " << maxArea(heights4) << endl;
    // Expected output: 2

    return 0;
}
