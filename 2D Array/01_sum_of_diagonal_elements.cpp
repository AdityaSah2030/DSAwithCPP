#include <iostream>
using namespace std;

/*
 * File: 01_sum_of_diagonal_elements.cpp
 * Description:
 *   This program reads an n x n matrix using a 2D array (without vectors) and computes
 *   the sum of its main diagonal elements. The summation itself is done in O(n) time
 *   (since it processes only n elements: arr[0][0], arr[1][1], ..., arr[n-1][n-1]).
 *
 *   Note: Reading the matrix from input takes O(n²) time, but once the matrix is in memory,
 *         summing the diagonal elements is O(n).
 *
 * Example:
 *   Input:
 *     3
 *     1 2 3
 *     4 5 6
 *     7 8 9
 *   Output:
 *     15
 *   Explanation:
 *     The main diagonal elements are 1, 5, 9 and their sum is 15.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 01_sum_of_diagonal_elements.cpp -o sum_diagonal
 *     ./sum_diagonal
 *
 *   Windows:
 *     g++ 01_sum_of_diagonal_elements.cpp -o sum_diagonal.exe
 *     sum_diagonal
 */

int main() {
    // Read the dimension of the square matrix
    int n;
    cout << "Enter the dimension n of the square matrix: ";
    cin >> n;

    // Declare a 2D array (assume n is not larger than 100 for this example)
    int arr[100][100];

    // Read the matrix elements (O(n²) time for input)
    cout << "Enter the elements of the " << n << " x " << n << " matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    // Sum the main diagonal elements in O(n) time
    int diagonalSum = 0;
    for (int i = 0; i < n; i++) {
        diagonalSum += arr[i][i];
    }

    cout << "Sum of main diagonal elements = " << diagonalSum << endl;
    return 0;
}
