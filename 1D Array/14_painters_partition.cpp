#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
 * Program: 14_painters_partition.cpp
 * Description:
 *   Given N boards, each of length boards[i], and M painters.
 *   Each painter takes 1 unit of time to paint 1 unit of board length.
 *
 *   We need to distribute the boards among M painters such that:
 *     - Each painter paints a contiguous segment of boards.
 *     - All boards must be painted.
 *     - We want to minimize the maximum time any single painter takes.
 *
 * Approach (Binary Search on the Answer):
 *   1. If M > N, it's impossible to allocate boards so that each painter has at least one
 *      contiguous section. However, in some formulations, extra painters might just get no boards.
 *      We'll assume each painter must paint at least some part (if the problem statement implies that).
 *      Adjust this condition based on problem specifics. If each painter must paint something,
 *      return an error or handle accordingly. Otherwise, we can still proceed with the same approach.
 *
 *   2. Define the search space for the "maximum time" a painter can take:
 *      - low = max(boards) (at least one board, the largest one).
 *      - high = sum(boards) (if only one painter does all the painting).
 *
 *   3. Perform binary search between low and high:
 *      - mid = (low + high) / 2
 *      - Check if it's possible to paint all boards with M painters such that
 *        no painter takes more than mid time.
 *      - If possible, try to lower high to mid - 1 (to find a smaller feasible maximum).
 *      - If not possible, increase low to mid + 1.
 *
 *   4. The final value of low after the loop ends is the minimized maximum time.
 *
 * Time Complexity: O(N log(sum(boards)))
 * Space Complexity: O(1) extra space
 *
 * Example Test Cases:
 *   1) boards = [10, 20, 30, 40], M = 2
 *      - Output: 60
 *      Explanation:
 *         One optimal allocation is: (10, 20, 30) and (40)
 *         - Painter 1 time = 10 + 20 + 30 = 60
 *         - Painter 2 time = 40
 *         Maximum = 60, which is minimal among all allocations.
 *
 *   2) boards = [10, 10, 10, 10], M = 2
 *      - Output: 20
 *      Explanation:
 *         One optimal allocation is: (10, 10) and (10, 10)
 *         - Painter 1 time = 20
 *         - Painter 2 time = 20
 *         Maximum = 20
 *
 *   3) boards = [5, 10, 15, 20, 25], M = 3
 *      - Output: 30
 *      Explanation:
 *         One optimal allocation is: (5, 10, 15), (20), (25)
 *         - Painter 1 time = 30
 *         - Painter 2 time = 20
 *         - Painter 3 time = 25
 *         Maximum = 30
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 14_painters_partition.cpp -o 14_painters_partition
 *     ./14_painters_partition
 *
 *   Windows:
 *     g++ 14_painters_partition.cpp -o 14_painters_partition.exe
 *     14_painters_partition
 */

// Helper function to check if we can paint all boards
// with M painters such that no painter paints more than maxTime.
bool canPaint(const vector<int>& boards, int M, int maxTime) {
    int painterCount = 1;  // Start with 1 painter
    int currentSum = 0;

    for (int length : boards) {
        // If a single board exceeds maxTime, we can't paint in that limit
        if (length > maxTime) {
            return false;
        }

        // If adding this board exceeds maxTime, allocate to next painter
        if (currentSum + length > maxTime) {
            painterCount++;
            currentSum = length;  // This board is now painted by the new painter

            // If we exceed the number of painters, it's not possible
            if (painterCount > M) {
                return false;
            }
        } else {
            // Otherwise, add it to the current painter's load
            currentSum += length;
        }
    }

    return true; // Successfully allocated within maxTime
}

// Main function to find the minimized maximum time
int paintersPartition(const vector<int>& boards, int M) {
    int N = boards.size();

    // If problem states each painter must paint at least one board,
    // and M > N, it's impossible to allocate:
    if (M > N) {
        // Depending on problem statement, you might return -1 or handle differently.
        // We'll just proceed with the same approach, but let's handle the "impossible" case:
        return -1;
    }

    // Calculate search space boundaries
    int low = 0;   // Will be set to max(boards) below
    int high = 0;  // Will be sum of all boards
    for (int length : boards) {
        if (length > low) {
            low = length; // largest single board
        }
        high += length;   // total length
    }

    int result = -1;

    // Binary search for the optimal (minimized) maximum time
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check feasibility
        if (canPaint(boards, M, mid)) {
            result = mid;
            high = mid - 1; // Try to find a better (smaller) max
        } else {
            low = mid + 1;  // Increase the time limit
        }
    }

    return result;
}

int main() {
    // Test Case 1
    vector<int> boards1 = {10, 20, 30, 40};
    int M1 = 2;
    cout << "Test Case 1: boards = [10, 20, 30, 40], M = 2" << endl;
    cout << "Minimized Maximum Time: " << paintersPartition(boards1, M1) << endl;
    // Expected Output: 60

    cout << endl;

    // Test Case 2
    vector<int> boards2 = {10, 10, 10, 10};
    int M2 = 2;
    cout << "Test Case 2: boards = [10, 10, 10, 10], M = 2" << endl;
    cout << "Minimized Maximum Time: " << paintersPartition(boards2, M2) << endl;
    // Expected Output: 20

    cout << endl;

    // Test Case 3
    vector<int> boards3 = {5, 10, 15, 20, 25};
    int M3 = 3;
    cout << "Test Case 3: boards = [5, 10, 15, 20, 25], M = 3" << endl;
    cout << "Minimized Maximum Time: " << paintersPartition(boards3, M3) << endl;
    // Expected Output: 30

    cout << endl;

    // Additional Test Case: If M > N
    vector<int> boards4 = {5, 10};
    int M4 = 3;  // More painters than boards
    cout << "Test Case 4: boards = [5, 10], M = 3" << endl;
    cout << "Minimized Maximum Time: " << paintersPartition(boards4, M4) << endl;
    // Expected Output: -1 (if each painter must paint something)

    return 0;
}
