// https://leetcode.com/problems/roman-to-integer/submissions/1263787520/

#include<bits/stdc++.h>
using namespace std;

#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        // Map to store the value of each Roman numeral
        unordered_map<char, int> romanValues = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int total = 0;
        int n = s.length();

     
        for (int i = 0; i < n; ++i) {
            
            if (i < n - 1 && romanValues[s[i]] < romanValues[s[i + 1]]) {
                total -= romanValues[s[i]];
            } else {
                
                total += romanValues[s[i]];
            }
        }

        return total;
    }
};
