#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/permutation-difference-between-two-strings/

class Solution1 {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char, int> indexMap;
        
        // Map each character in s to its index
        for (int i = 0; i < s.length(); ++i) {
            indexMap[s[i]] = i;
        }
        
        int permutationDifference = 0;
        
        // Calculate the permutation difference
        for (int i = 0; i < t.length(); ++i) {
            permutationDifference += abs(indexMap[t[i]] - i);
        }
        
        return permutationDifference;
    }
};

class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char, int> indexMap;
        
        // Map each character in s to its index
        for (int i = 0; i < s.length(); ++i) {
            indexMap[s[i]] = i;
        }
        
        int permutationDifference = 0;
        
        // Calculate the permutation difference
        for (int i = 0; i < t.length(); ++i) {
            permutationDifference += abs(indexMap[t[i]] - i);
        }
        
        return permutationDifference;
    }
};
