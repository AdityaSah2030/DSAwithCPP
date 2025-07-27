#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int rows = grid.size();
        int cols = grid[0].size();
        int perimeter = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                // We only care about land cells
                if (grid[r][c] == 1) {
                    // Check top boundary
                    if (r == 0 || grid[r - 1][c] == 0) {
                        perimeter++;
                    }
                    // Check bottom boundary
                    if (r == rows - 1 || grid[r + 1][c] == 0) {
                        perimeter++;
                    }
                    // Check left boundary
                    if (c == 0 || grid[r][c - 1] == 0) {
                        perimeter++;
                    }
                    // Check right boundary
                    if (c == cols - 1 || grid[r][c + 1] == 0) {
                        perimeter++;
                    }
                }
            }
        }
        return perimeter;
    }
};