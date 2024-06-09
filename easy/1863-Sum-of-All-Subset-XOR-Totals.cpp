#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/sum-of-all-subset-xor-totals/submissions/1263785510/

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        
        
        for (int i = 0; i < (1 << n); ++i) {
            int subsetXOR = 0;
            
           
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    subsetXOR ^= nums[j];
                }
            }
            
                
            total += subsetXOR;
        }
        
        return total;
    }
};