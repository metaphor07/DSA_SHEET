#include <bits/stdc++.h>
using namespace std;

/*
Priority: Important
Topic: Prefix Sum / Prefix Parity
Pattern:
A subarray has odd sum when current prefix parity and previous prefix parity are different.

Time: O(n)
Space: O(1)
*/

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;

        long long ans = 0;
        long long even = 1; // empty prefix sum = 0, even
        long long odd = 0;

        int prefix = 0;

        for (int x : arr) {
            prefix += x;

            if (prefix % 2 == 0) {
                ans += odd;
                even++;
            } else {
                ans += even;
                odd++;
            }

            ans %= MOD;
        }

        return ans;
    }
};
