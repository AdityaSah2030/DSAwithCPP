#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // If the array is empty, there are no duplicates to remove.
        if (nums.empty()) {
            return 0;
        }

        // `insert_index` is the slow-runner. It points to the position
        // where the next unique element should be placed.
        // It starts at 1 because nums[0] is always in its correct place.
        int insert_index = 1;

        // We use a fast-runner `i` to iterate through the array starting from the second element.
        for (int i = 1; i < nums.size(); i++) {
            // Compare the current element with the previous one.
            // Since the array is sorted, duplicates will be consecutive.
            if (nums[i] != nums[i - 1]) {
                // If it's a new, unique element, place it at the `insert_index`.
                nums[insert_index] = nums[i];
                // Move the `insert_index` for the next unique element.
                insert_index++;
            }
        }
        
        // `insert_index` now holds the count of unique elements, which is our k.
        return insert_index;
    }
};