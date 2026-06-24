#include <bits/stdc++.h>
using namespace std;

/*
Topic: GCD
Pattern: GCD of minimum and maximum element
Time: O(n + log(maxVal))
Space: O(1)
*/

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        return gcd(mn, mx);
    }
};
