// https://leetcode.com/problems/final-value-of-variable-after-performing-operations/description/
#include<bits/stdc++.h>
using namespace std;

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int X = 0;
        for (const string& op : operations) {
            if (op == "++X" || op == "X++") {
                X++;
            } else if (op == "--X" || op == "X--") {
                X--;
            }
        }
        return X;
    }
};
