#include <iostream>
#include <vector>
#include <algorithm> // For sort()
using namespace std;

/*
 * Program: 15_aggressive_cows.cpp
 * Description:
 *   You are given N stalls located along a straight line (each stall has a position xi).
 *   You have C cows and want to place them in these stalls so that the minimum distance
 *   between any two cows is as large as possible. Return that largest minimum distance.
 *
 * Input Format (Typical for AGGRCOW):
 *   - First line: T, the number of test cases.
 *   - For each test case:
 *       1) Read two integers: N (number of stalls), C (number of cows).
 *       2) Read N integers for the stall locations.
 *
 * Approach (Binary Search on the Answer):
 *   1. Sort the stall locations.
 *   2. Define search space for the minimum distance:
 *      - low = 0
 *      - high = (maxStallPosition - minStallPosition)
 *   3. While low <= high:
 *      - mid = (low + high) / 2
 *      - Check if we can place C cows such that the minimum distance between any two
 *        cows is at least mid.
 *      - If we can place them, it means we can try a larger distance -> low = mid + 1
 *      - If we cannot place them, we need a smaller distance -> high = mid - 1
 *   4. The final answer is high (after the loop ends), because when low goes beyond high,
 *      high is the last distance that worked.
 *
 * Time Complexity:
 *   - Sorting the stalls: O(N log N)
 *   - Binary search over distance: O(log(maxPosition - minPosition))
 *   - Checking feasibility for each mid: O(N) in the worst case
 *   => Overall: O(N log N + N log(maxPosition - minPosition))
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 15_aggressive_cows.cpp -o 15_aggressive_cows
 *     ./15_aggressive_cows
 *
 *   Windows:
 *     g++ 15_aggressive_cows.cpp -o 15_aggressive_cows.exe
 *     15_aggressive_cows
 */

// Helper function to check if we can place 'C' cows in 'stalls'
// such that the minimum distance between any two cows is at least 'dist'.
bool canPlaceCows(const vector<long long>& stalls, int C, long long dist) {
    // Place the first cow in the first stall
    long long lastPos = stalls[0];
    int count = 1; // number of cows placed so far

    // Try placing the remaining C-1 cows
    for (int i = 1; i < (int)stalls.size(); i++) {
        if (stalls[i] - lastPos >= dist) {
            // Place a cow here
            count++;
            lastPos = stalls[i];

            // If we've placed all cows, return true
            if (count == C) {
                return true;
            }
        }
    }

    return false; // Not all cows could be placed with at least 'dist' separation
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T; // Number of test cases

    while (T--) {
        int N, C;
        cin >> N >> C;

        vector<long long> stalls(N);
        for (int i = 0; i < N; i++) {
            cin >> stalls[i];
        }

        // Sort stall locations
        sort(stalls.begin(), stalls.end());

        // Define the search space for the distance
        long long low = 0;
        long long high = stalls.back() - stalls.front(); // max possible distance

        long long answer = 0;

        // Binary search to find the largest minimum distance
        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (canPlaceCows(stalls, C, mid)) {
                // If we can place all cows with at least 'mid' distance,
                // try for a bigger distance
                answer = mid;  // 'mid' is a valid distance
                low = mid + 1;
            } else {
                // Otherwise, try a smaller distance
                high = mid - 1;
            }
        }

        cout << answer << "\n";
    }

    return 0;
}
