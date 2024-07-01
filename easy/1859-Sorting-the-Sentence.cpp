// https://leetcode.com/problems/sorting-the-sentence/description/
// 1859. Sorting the Sentence

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string sortSentence(string s) {
       
        istringstream iss(s);
        vector<string> words;
        string word;
        while (iss >> word) {
            words.push_back(word);
        }
        
        
        vector<string> sortedWords(words.size());
        
        
        for (const string& w : words) {
            int pos = w.back() - '0';  
            sortedWords[pos - 1] = w.substr(0, w.size() - 1);  
        }
        
    
        string result;
        for (int i = 0; i < sortedWords.size(); ++i) {
            if (i > 0) {
                result += " ";
            }
            result += sortedWords[i];
        }
        
        return result;
    }
};
