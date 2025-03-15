#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
 * Program: 13_book_allocation.cpp
 * Description:
 *   You have N books, each with a certain number of pages. You need to allocate
 *   these books to M students such that:
 *     - Each student gets at least one book.
 *     - Allotment of books to each student is contiguous (no gaps).
 *     - The goal is to minimize the maximum number of pages allocated to any student.
 *   If it's not possible to allocate, return -1.
 *
 * Approach (Binary Search on the Answer):
 *   1. If M > N, it's impossible to allocate (each student needs at least one book).
 *      Return -1 in that case.
 *   2. Define the search space:
 *      - The lower bound (low) is the maximum number of pages of a single book,
 *        because no student can be allocated less than that if they receive that book.
 *      - The upper bound (high) is the sum of all pages (if only one student gets all the books).
 *   3. Use binary search between low and high:
 *      - mid = (low + high) / 2
 *      - Check if it is possible to allocate the books to M students so that
 *        no student gets more than mid pages.
 *      - If it is possible, we try to find a better (smaller) solution by moving high = mid - 1.
 *      - If it is not possible, we move low = mid + 1.
 *   4. The final value of low after the loop ends is the minimized maximum number of pages.
 *
 * Time Complexity: O(N log(sum of pages))
 * Space Complexity: O(1) extra space
 *
 * Example Test Cases:
 *   1) pages = [12, 34, 67, 90], M = 2
 *      - Output: 113
 *      Explanation:
 *        One allocation is: [12, 34] and [67, 90]
 *        - Student 1 gets 46 pages
 *        - Student 2 gets 157 pages
 *        This is not optimal. Another allocation is: [12, 34, 67] and [90]
 *        - Student 1 gets 113 pages
 *        - Student 2 gets 90 pages
 *        The maximum is 113, which is the minimum possible.
 *
 *   2) pages = [5, 5, 5, 5], M = 2
 *      - Output: 10
 *      Explanation:
 *        One optimal allocation is: [5, 5] and [5, 5]
 *        Each student gets 10 pages.
 *
 *   3) pages = [5, 10, 20, 10, 5], M = 5
 *      - Output: 20
 *      Explanation:
 *        Since M = 5 and there are 5 books, each student must take exactly one book.
 *        The largest single book is 20 pages, so the answer is 20.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 13_book_allocation.cpp -o 13_book_allocation
 *     ./13_book_allocation
 *
 *   Windows:
 *     g++ 13_book_allocation.cpp -o 13_book_allocation.exe
 *     13_book_allocation
 */

// Helper function to check if it's possible to allocate books so that
// no student gets more than 'maxPages'.
bool canAllocate(const vector<int>& pages, int M, int maxPages) {
    int studentCount = 1;  // Start with one student
    int currentSum = 0;

    for (int pageCount : pages) {
        // If a single book exceeds maxPages, allocation is impossible
        if (pageCount > maxPages) {
            return false;
        }

        // If adding this book to the current student exceeds maxPages,
        // allocate this book to the next student
        if (currentSum + pageCount > maxPages) {
            studentCount++;
            currentSum = pageCount;

            // If we exceed the number of students, return false
            if (studentCount > M) {
                return false;
            }
        } else {
            // Otherwise, add the book to the current student's allocation
            currentSum += pageCount;
        }
    }

    return true;
}

// Main function that returns the minimized maximum pages
int allocateBooks(const vector<int>& pages, int M) {
    int N = pages.size();

    // If there are more students than books, allocation is impossible
    if (M > N) {
        return -1;
    }

    // Define the search space for the maximum pages
    // Lower bound: max(pages), Upper bound: sum(pages)
    int low = 0;   // Will be set to max(pages) below
    int high = 0;  // Will be set to sum(pages)
    for (int pageCount : pages) {
        if (pageCount > low) {
            low = pageCount;  // max page
        }
        high += pageCount;    // sum of pages
    }

    int result = -1;

    // Binary search in [low, high]
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if we can allocate with 'mid' as the limit
        if (canAllocate(pages, M, mid)) {
            result = mid;         // This is a valid allocation
            high = mid - 1;       // Try for a better (smaller) maximum
        } else {
            low = mid + 1;        // Need to increase the limit
        }
    }

    return result;
}

int main() {
    // Test Case 1
    vector<int> pages1 = {12, 34, 67, 90};
    int M1 = 2;
    cout << "Test Case 1: pages = [12, 34, 67, 90], M = 2" << endl;
    cout << "Minimized Maximum Pages: " << allocateBooks(pages1, M1) << endl;
    // Expected Output: 113

    cout << endl;

    // Test Case 2
    vector<int> pages2 = {5, 5, 5, 5};
    int M2 = 2;
    cout << "Test Case 2: pages = [5, 5, 5, 5], M = 2" << endl;
    cout << "Minimized Maximum Pages: " << allocateBooks(pages2, M2) << endl;
    // Expected Output: 10

    cout << endl;

    // Test Case 3
    vector<int> pages3 = {5, 10, 20, 10, 5};
    int M3 = 5;
    cout << "Test Case 3: pages = [5, 10, 20, 10, 5], M = 5" << endl;
    cout << "Minimized Maximum Pages: " << allocateBooks(pages3, M3) << endl;
    // Expected Output: 20

    cout << endl;

    // Additional Test Case: If M > N
    vector<int> pages4 = {10, 20, 30};
    int M4 = 5;  // More students than books
    cout << "Test Case 4: pages = [10, 20, 30], M = 5" << endl;
    cout << "Minimized Maximum Pages: " << allocateBooks(pages4, M4) << endl;
    // Expected Output: -1 (impossible to allocate)

    return 0;
}
