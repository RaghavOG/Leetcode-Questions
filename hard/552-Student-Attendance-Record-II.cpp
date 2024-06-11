#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/student-attendance-record-ii/?envType=daily-question&envId=2024-05-26 

#include <vector>

using namespace std;

class Solution {
public:
    int checkRecord(int n) {
        const int MOD = 1000000007;
        if (n == 1) return 3;

        // dp arrays to store the number of valid sequences without 'A'
        vector<vector<long long>> dp(n + 1, vector<long long>(3, 0));
        
        // Base cases for dp
        dp[1][0] = 1; // "P"
        dp[1][1] = 1; // "L"
        dp[1][2] = 0; // "LL" is not valid for length 1
        
        // Fill dp table for sequences without 'A'
        for (int i = 2; i <= n; ++i) {
            dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % MOD;
            dp[i][1] = dp[i-1][0] % MOD;
            dp[i][2] = dp[i-1][1] % MOD;
        }
        
        // Total number of valid sequences without 'A'
        long long totalWithoutA = (dp[n][0] + dp[n][1] + dp[n][2]) % MOD;
        
        // Calculate the total number of valid sequences including 'A'
        long long totalWithA = 0;
        for (int i = 1; i <= n; ++i) {
            long long left = (i == 1) ? 1 : (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % MOD;
            long long right = (i == n) ? 1 : (dp[n-i][0] + dp[n-i][1] + dp[n-i][2]) % MOD;
            totalWithA = (totalWithA + (left * right) % MOD) % MOD;
        }
        
        // Total number of valid sequences is the sum of sequences with and without 'A'
        return (totalWithoutA + totalWithA) % MOD;
    }
};
