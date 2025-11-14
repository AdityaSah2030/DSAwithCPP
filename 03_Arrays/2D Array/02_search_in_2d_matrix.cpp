#include <iostream>
#include <vector>
using namespace std;

/*
 * File: 02_search_in_2d_matrix.cpp
 * Description (LeetCode #74):
 *   You are given an m x n integer matrix with the following two properties:
 *     1) Each row is sorted in non-decreasing order.
 *     2) The first integer of each row is greater than the last integer of the previous row.
 *
 *   Given an integer target, return true if target is in the matrix or false otherwise.
 *   You must write a solution in O(log(m*n)) time complexity.
 *
 * Example:
 *   matrix = [
 *     [1, 3, 5, 7],
 *     [10,11,16,20],
 *     [23,30,34,60]
 *   ], target = 3
 *   Output: true
 *
 * Approach (Binary Search on Flattened Index):
 *   1) Let total elements = m * n.
 *   2) We'll do a binary search on the range [0 .. m*n - 1].
 *   3) mid = (left + right) / 2
 *   4) row = mid / n, col = mid % n
 *   5) Compare matrix[row][col] with target:
 *        - If matrix[row][col] == target, return true.
 *        - If matrix[row][col] < target, move left boundary up.
 *        - Else, move right boundary down.
 *   6) If we exit the loop, return false.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 02_search_in_2d_matrix.cpp -o search_2d_matrix
 *     ./search_2d_matrix
 *
 *   Windows:
 *     g++ 02_search_in_2d_matrix.cpp -o search_2d_matrix.exe
 *     search_2d_matrix
 */

// Function to search target in a 2D matrix with the given properties
bool searchMatrix(const vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0) return false;
    int n = matrix[0].size();
    if (n == 0) return false;

    // Binary search over range [0 .. m*n - 1]
    int left = 0;
    int right = m * n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Map mid to 2D indices
        int row = mid / n;
        int col = mid % n;

        if (matrix[row][col] == target) {
            return true;
        } else if (matrix[row][col] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}

int main() {
    // Example usage with a 3x4 matrix
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10,11,16,20},
        {23,30,34,60}
    };
    int target = 3;

    cout << "Matrix:" << endl;
    for (auto &row : matrix) {
        for (auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    cout << "\nSearching for target = " << target << endl;
    bool found = searchMatrix(matrix, target);
    cout << "Found? " << (found ? "true" : "false") << endl;
    // Expected: true

    cout << endl;

    // Another test
    target = 13;
    cout << "Searching for target = " << target << endl;
    found = searchMatrix(matrix, target);
    cout << "Found? " << (found ? "true" : "false") << endl;
    // Expected: false

    cout << endl;

    // Optional: user input
    cout << "Enter target to search: ";
    cin >> target;
    found = searchMatrix(matrix, target);
    cout << "Found? " << (found ? "true" : "false") << endl;

    return 0;
}
