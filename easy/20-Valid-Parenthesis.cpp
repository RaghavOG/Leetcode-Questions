#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        stack<char> parenStack;

        for (char c : s) {
            if (isOpen(c)) {
                parenStack.push(c);
            } else if (isClosed(c)) {
                if (parenStack.empty() || !isMatching(parenStack.top(), c)) {
                    return false;
                }
                parenStack.pop();
            } else {
                
            }
        }

        return parenStack.empty();
    }

private:
    bool isOpen(char c) { return c == '(' || c == '{' || c == '['; }

    bool isClosed(char c) { return c == ')' || c == '}' || c == ']'; }

    bool isMatching(char open, char close) {
        return (open == '(' && close == ')') || (open == '{' && close == '}') ||
               (open == '[' && close == ']');
    }
};
