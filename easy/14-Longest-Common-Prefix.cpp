#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-common-prefix/description/

class Solution1 {
public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) {  // Handle empty input
      return "";
    }
    string prefix = strs[0];
    for (int i = 1; i < strs.size(); i++) {
      while (strs[i].find(prefix) != 0 && !prefix.empty()) {
        
        prefix = prefix.substr(0, prefix.size() - 1);
      }
    }
    return prefix;
  }
};

class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) {
      return "";
    }
    int minLen = INT_MAX;
    for (const string& str : strs) {
      minLen = min(minLen, (int)str.size()); // Find shortest string length
    }

    int i = 0;
    while (i < minLen && all_of(strs.begin(), strs.end(), [&](const string& str) {
             return str[i] == strs[0][i]; // Check all strings at current index
           })) {
      i++;
    }
    return strs[0].substr(0, i);
  }
};