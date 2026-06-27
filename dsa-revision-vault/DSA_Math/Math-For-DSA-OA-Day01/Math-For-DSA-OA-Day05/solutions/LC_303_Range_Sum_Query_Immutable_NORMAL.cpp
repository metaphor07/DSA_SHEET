#include <bits/stdc++.h>
using namespace std;

/*
Priority: Normal
Topic: Prefix Sum
Pattern: Build prefix array of size n + 1
Time: O(n) constructor, O(1) per query
Space: O(n)
*/

class NumArray {
public:
    vector<int> prefix;

    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix.assign(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};
