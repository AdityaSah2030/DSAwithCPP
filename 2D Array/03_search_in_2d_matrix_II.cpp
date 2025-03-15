#include <iostream>
#include <vector>
using namespace std;

/*
 * File: 03_search_in_2d_matrix_II.cpp
 * Description (LeetCode #240):
 *   Write an efficient algorithm that searches for a value target in an m x n
 *   integer matrix matrix. This matrix has the following properties:
 *     1) Integers in each row are sorted in ascending from left to right.
 *     2) Integers in each column are sorted in ascending from top to bottom.
 *
 * Example:
 *   matrix = [
 *     [1, 4,  7, 11, 15],
 *     [2, 5,  8, 12, 19],
 *     [3, 6,  9, 16, 22],
 *     [10, 13, 14, 17, 24],
 *     [18, 21, 23, 26, 30]
 *   ], target = 5
 *   Output: true
 *
 * Approach (Start from Top-Right Corner, O(m + n)):
 *   1) Let row = 0, col = n-1 (top-right corner).
 *   2) While row < m and col >= 0:
 *        - If matrix[row][col] == target, return true.
 *        - If matrix[row][col] > target, col-- (move left).
 *        - Else, row++ (move down).
 *   3) If we exit the loop, return false.
 *
 * Time Complexity: O(m + n)
 *   - In each step we discard a row or a column.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 03_search_in_2d_matrix_II.cpp -o search_2d_matrix_II
 *     ./search_2d_matrix_II
 *
 *   Windows:
 *     g++ 03_search_in_2d_matrix_II.cpp -o search_2d_matrix_II.exe
 *     search_2d_matrix_II
 */

// Function to search for target in a 2D matrix
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0) return false;
    int n = matrix[0].size();
    if (n == 0) return false;

    // Start from top-right corner
    int row = 0;
    int col = n - 1;

    while (row < m && col >= 0) {
        if (matrix[row][col] == target) {
            return true;
        } else if (matrix[row][col] > target) {
            col--; // move left
        } else {
            row++; // move down
        }
    }

    return false;
}

int main() {
    // Example usage
    vector<vector<int>> matrix = {
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14,17, 24},
        {18, 21, 23,26, 30}
    };

    int target = 5;
    cout << "Matrix:\n";
    for (auto &row : matrix) {
        for (auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    cout << "\nTarget: " << target << endl;
    bool found = searchMatrix(matrix, target);
    cout << "Found? " << (found ? "true" : "false") << endl;
    // Expected: true

    cout << endl;

    // Another test
    target = 20;
    cout << "Target: " << target << endl;
    found = searchMatrix(matrix, target);
    cout << "Found? " << (found ? "true" : "false") << endl;
    // Expected: false

    // Optional user input
    cout << "\nEnter a target to search: ";
    cin >> target;
    found = searchMatrix(matrix, target);
    cout << "Found? " << (found ? "true" : "false") << endl;

    return 0;
}
