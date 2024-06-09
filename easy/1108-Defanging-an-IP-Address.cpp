#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/defanging-an-ip-address/description/


class Solution {
public:
    string defangIPaddr(string address) {
        string result;
        for (char ch : address) {
            if (ch == '.') {
                result += "[.]";
            } else {
                result += ch;
            }
        }
        return result;
    }
};
