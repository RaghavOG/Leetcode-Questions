// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        int row = m - 1;
        int col = 0;

        while (row >= 0 && col < n) {
            if (grid[row][col] < 0) {
                // All elements in this row to the right are negative
                count += (n - col);
                row--; // Move up one row
            } else {
                col++; // Move right one column
            }
        }

        return count;
    }
};