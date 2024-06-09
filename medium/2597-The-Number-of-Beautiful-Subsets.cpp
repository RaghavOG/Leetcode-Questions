#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/the-number-of-beautiful-subsets/description/?envType=daily-question&envId=2024-05-23 

class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 0;
        vector<int> current;
        backtrack(nums, k, 0, current, count);
        return count;
    }

private:
    void backtrack(vector<int>& nums, int k, int start, vector<int>& current, int& count) {
        if (!current.empty()) {
            count++;
        }
        for (int i = start; i < nums.size(); ++i) {
            if (isValid(current, nums[i], k)) {
                current.push_back(nums[i]);
                backtrack(nums, k, i + 1, current, count);
                current.pop_back();
            }
        }
    }

    bool isValid(vector<int>& current, int num, int k) {
        for (int n : current) {
            if (abs(n - num) == k) {
                return false;
            }
        }
        return true;
    }
};