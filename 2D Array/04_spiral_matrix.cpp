#include <iostream>
#include <vector>
using namespace std;

/*
 * File: 04_spiral_matrix.cpp
 * Description (LeetCode #54):
 *   Given an m x n matrix, return all elements of the matrix in spiral order.
 *
 * Example 1:
 *   matrix = [
 *     [1, 2, 3],
 *     [4, 5, 6],
 *     [7, 8, 9]
 *   ]
 *   Output: [1, 2, 3, 6, 9, 8, 7, 4, 5]
 *
 * Approach (Layer-by-Layer):
 *   We maintain four boundaries: top, bottom, left, right.
 *   - Traverse from left to right on the top row, then increment top.
 *   - Traverse from top to bottom on the right column, then decrement right.
 *   - If top <= bottom, traverse from right to left on the bottom row, then decrement bottom.
 *   - If left <= right, traverse from bottom to top on the left column, then increment left.
 *   - Continue until all elements are covered.
 *
 * Time Complexity: O(m*n), as each element is visited exactly once.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 04_spiral_matrix.cpp -o spiral_matrix
 *     ./spiral_matrix
 *
 *   Windows:
 *     g++ 04_spiral_matrix.cpp -o spiral_matrix.exe
 *     spiral_matrix
 */

// Function to get the spiral order of a 2D matrix
vector<int> spiralOrder(const vector<vector<int>>& matrix) {
    vector<int> result;
    int m = matrix.size();
    if (m == 0) return result;
    int n = matrix[0].size();
    if (n == 0) return result;

    // Boundaries
    int top = 0;
    int bottom = m - 1;
    int left = 0;
    int right = n - 1;

    while (left <= right && top <= bottom) {
        // Traverse from left to right on the top row
        for (int col = left; col <= right; col++) {
            result.push_back(matrix[top][col]);
        }
        top++;

        // Traverse from top to bottom on the right column
        for (int row = top; row <= bottom; row++) {
            result.push_back(matrix[row][right]);
        }
        right--;

        // Check if top <= bottom before traversing bottom row
        if (top <= bottom) {
            // Traverse from right to left on the bottom row
            for (int col = right; col >= left; col--) {
                result.push_back(matrix[bottom][col]);
            }
            bottom--;
        }

        // Check if left <= right before traversing left column
        if (left <= right) {
            // Traverse from bottom to top on the left column
            for (int row = bottom; row >= top; row--) {
                result.push_back(matrix[row][left]);
            }
            left++;
        }
    }

    return result;
}

int main() {
    // Example usage
    {
        vector<vector<int>> matrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };
        cout << "Matrix:\n";
        for (auto &row : matrix) {
            for (auto &val : row) {
                cout << val << " ";
            }
            cout << endl;
        }

        cout << "\nSpiral order: ";
        vector<int> result = spiralOrder(matrix);
        for (int val : result) {
            cout << val << " ";
        }
        cout << endl;
        // Expected: 1 2 3 6 9 8 7 4 5
    }

    cout << endl;

    // Another test
    {
        vector<vector<int>> matrix = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9,10,11,12}
        };
        cout << "Matrix:\n";
        for (auto &row : matrix) {
            for (auto &val : row) {
                cout << val << " ";
            }
            cout << endl;
        }

        cout << "\nSpiral order: ";
        vector<int> result = spiralOrder(matrix);
        for (int val : result) {
            cout << val << " ";
        }
        cout << endl;
        // Expected: 1 2 3 4 8 12 11 10 9 5 6 7
    }

    cout << endl;

    // Optional user input
    {
        cout << "Enter dimensions (m n): ";
        int m, n;
        cin >> m >> n;
        vector<vector<int>> matrix(m, vector<int>(n));
        cout << "Enter matrix elements row by row:\n";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        vector<int> result = spiralOrder(matrix);
        cout << "Spiral order: ";
        for (int val : result) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
