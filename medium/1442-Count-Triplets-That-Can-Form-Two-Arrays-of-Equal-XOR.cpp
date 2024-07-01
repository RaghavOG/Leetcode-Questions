// https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description/?envType=daily-question&envId=2024-05-30
// 1442. Count Triplets That Can Form Two Arrays of Equal XOR

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefixXor(n + 1, 0);
        
        // Compute prefix XOR
        for (int i = 0; i < n; ++i) {
            prefixXor[i + 1] = prefixXor[i] ^ arr[i];
        }
        
        int count = 0;
        
        // Iterate over all pairs (i, k) and find valid j's
        for (int i = 0; i < n; ++i) {
            for (int k = i + 1; k < n; ++k) {
                if (prefixXor[i] == prefixXor[k + 1]) {
                    count += (k - i);  // All j's between i+1 to k are valid
                }
            }
        }
        
        return count;
    }
};
