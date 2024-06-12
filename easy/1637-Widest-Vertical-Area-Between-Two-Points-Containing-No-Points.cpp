// https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/description/
#include<bits/stdc++.h>
using namespace std;


class Solution1 {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
    
        vector<int> x_coords(points.size());
        for (int i = 0; i < points.size(); ++i) {
            x_coords[i] = points[i][0];
        }
        
    
        sort(x_coords.begin(), x_coords.end());
        
       
        int max_width = 0;
        for (int i = 1; i < x_coords.size(); ++i) {
            max_width = max(max_width, x_coords[i] - x_coords[i - 1]);
        }
        
        return max_width;
    }
};


class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        
        vector<int> x_coords;
        for (const auto& point : points) {
            x_coords.push_back(point[0]);
        }
        
        
        sort(x_coords.begin(), x_coords.end());
        
        
        int max_width = 0;
        for (int i = 1; i < x_coords.size(); ++i) {
            max_width = max(max_width, x_coords[i] - x_coords[i - 1]);
        }
        
        return max_width;
    }
};