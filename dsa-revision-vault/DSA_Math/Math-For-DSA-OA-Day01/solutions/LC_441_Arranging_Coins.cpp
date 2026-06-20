/*
Topic: Basic Math / Formula + Binary Search
Pattern: Find largest k such that k * (k + 1) / 2 <= n
Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        long long low = 1, high = n;
        long long ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long coins = mid * (mid + 1) / 2;

            if (coins <= n) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return (int)ans;
    }
};
