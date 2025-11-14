#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Pointer for the last element of the initial nums1
        int p1 = m - 1;
        // Pointer for the last element of nums2
        int p2 = n - 1;
        // Pointer for the last position in the final merged array (nums1)
        int p = m + n - 1;

        // Iterate backwards from the end of both arrays
        while (p2 >= 0) {
            // If p1 is still valid and its element is larger, place it at the end
            if (p1 >= 0 && nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } else {
                // Otherwise, the element from nums2 is larger or p1 is exhausted
                nums1[p] = nums2[p2];
                p2--;
            }
            // Move to the next position to fill
            p--;
        }
    }
};