#include <iostream>
#include <vector>
using namespace std;

/*
 * File: 31_subsets_recursion.cpp
 * Description:
 *   Prints all subsets (powerset) of a given set of integers using recursion.
 *   Each subset is printed on a separate line.
 *
 * Approach (Include/Exclude):
 *   1) If we are at index i:
 *      - "Include" arr[i] in the current subset, recurse for i+1.
 *      - "Exclude" arr[i] from the current subset, recurse for i+1.
 *   2) Base case: if i == arr.size(), print the current subset (ans).
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 31_subsets_recursion.cpp -o subsets_recursion
 *     ./subsets_recursion
 *
 *   Windows:
 *     g++ 31_subsets_recursion.cpp -o subsets_recursion.exe
 *     subsets_recursion
 */

// Recursive function to print all subsets
void printSubsets(const vector<int>& arr, vector<int>& current, int i) {
    // If we've reached the end of the array, print the current subset
    if (i == (int)arr.size()) {
        cout << "{ ";
        for (int val : current) {
            cout << val << " ";
        }
        cout << "}" << endl;
        return;
    }

    // 1) INCLUDE arr[i]
    current.push_back(arr[i]);
    printSubsets(arr, current, i + 1);

    // Backtrack (remove the included element)
    current.pop_back();

    // 2) EXCLUDE arr[i]
    printSubsets(arr, current, i + 1);
}

int main() {
    // Example usage
    cout << "Enter the number of elements in the set: ";
    int n;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // This vector will hold the current subset we are building
    vector<int> current;

    cout << "\nAll possible subsets:\n";
    printSubsets(arr, current, 0);

    return 0;
}
