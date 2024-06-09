#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/word-break-ii/description/

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> memo;
        return wordBreakHelper(s, wordSet, 0, memo);
    }
    
private:
    vector<string> wordBreakHelper(const string& s, const unordered_set<string>& wordSet, int start, unordered_map<int, vector<string>>& memo) {
        if (memo.find(start) != memo.end()) {
            return memo[start];
        }
        
        vector<string> result;
        if (start == s.size()) {
            result.push_back("");
        }
        
        for (int end = start + 1; end <= s.size(); ++end) {
            string word = s.substr(start, end - start);
            if (wordSet.find(word) != wordSet.end()) {
                vector<string> sublist = wordBreakHelper(s, wordSet, end, memo);
                for (const string& sub : sublist) {
                    result.push_back(word + (sub.empty() ? "" : " ") + sub);
                }
            }
        }
        
        memo[start] = result;
        return result;
    }
};