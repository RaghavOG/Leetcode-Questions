#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/
// 1614. Maximum Nesting Depth of the Parentheses
class Solution {
public:
    int maxDepth(string s) {
        int max_depth = 0;
        int current_depth = 0;
        
        for (char c : s) {
            if (c == '(') {
                current_depth++;
                if (current_depth > max_depth) {
                    max_depth = current_depth;
                }
            } else if (c == ')') {
                current_depth--;
            }
        }
        
        return max_depth;
    }
};
