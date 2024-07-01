// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description/?envType=daily-question&envId=2024-05-29
// 1404. Number of Steps to Reduce a Number in Binary Representation to One

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        
        while (s.length() > 1) {
            if (s.back() == '0') {
                s.pop_back(); 
            } else {
                // Add 1 to make it even
                int i = s.length() - 1;
                while (i >= 0 && s[i] == '1') {
                    s[i] = '0';
                    i--;
                }
                if (i >= 0) {
                    s[i] = '1';
                } else {
                    
                    s = '1' + s;
                }
            }
            steps++;
        }
        
        return steps;
    }
};
