#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> freq(60, 0);
        int ans = 0;

        for (int t : time) {
            int rem = t % 60;
            int need = (60 - rem) % 60;

            ans += freq[need];
            freq[rem]++;
        }

        return ans;
    }
};
