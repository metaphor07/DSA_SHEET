#include <bits/stdc++.h>
using namespace std;

/*
Priority: Normal
Topic: Prefix Sum
Pattern: left sum == right sum
Time: O(n)
Space: O(1)
*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int left = 0;

        for (int i = 0; i < nums.size(); i++) {
            int right = total - left - nums[i];

            if (left == right) return i;

            left += nums[i];
        }

        return -1;
    }
};
