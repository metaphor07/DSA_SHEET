#include <bits/stdc++.h>
using namespace std;

/*
Priority: Normal
Topic: Prefix Sum + Hashmap
Pattern: currentPrefix - previousPrefix = k
Time: O(n)
Space: O(n)
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1;

        int prefix = 0;
        int ans = 0;

        for (int x : nums) {
            prefix += x;

            int need = prefix - k;
            ans += freq[need];

            freq[prefix]++;
        }

        return ans;
    }
};
