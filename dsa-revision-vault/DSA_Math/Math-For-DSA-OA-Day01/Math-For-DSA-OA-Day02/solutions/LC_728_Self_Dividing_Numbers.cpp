#include <bits/stdc++.h>
using namespace std;

/*
Topic: Digit Math
Pattern: Check every digit divides original number
Time: O((right-left+1) * digits)
Space: O(1) extra
*/

class Solution {
public:
    bool check(int num) {
        int original = num;
        while (num > 0) {
            int digit = num % 10;
            if (digit == 0) return false;
            if (original % digit != 0) return false;
            num /= 10;
        }
        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int num = left; num <= right; num++) {
            if (check(num)) ans.push_back(num);
        }
        return ans;
    }
};
