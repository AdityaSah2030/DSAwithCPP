#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        // Iterate from the rightmost digit to the left.
        for (int i = n - 1; i >= 0; i--) {
            // Case 1: The current digit is less than 9.
            // We can just increment and we're done.
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }

            // Case 2: The current digit is 9.
            // We set it to 0 and the carry-over will be handled by the next loop iteration.
            digits[i] = 0;
        }

        // Case 3: If we are here, it means the entire number was nines (e.g., 99, 999).
        // The array is now all zeros (e.g., [0, 0]).
        // We need to add a 1 to the front.
        digits.insert(digits.begin(), 1);
        
        return digits;
    }
};