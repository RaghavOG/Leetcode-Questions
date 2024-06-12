// https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/description/?envType=daily-question&envId=2024-05-27

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for (int x = 0; x <= n; ++x) {
            // Find how many numbers are greater than or equal to x
            int count = count_if(nums.begin(), nums.end(), [x](int num) { return num >= x; });
            if (count == x) {
                return x;
            }
        }
        
        return -1;
    }
};