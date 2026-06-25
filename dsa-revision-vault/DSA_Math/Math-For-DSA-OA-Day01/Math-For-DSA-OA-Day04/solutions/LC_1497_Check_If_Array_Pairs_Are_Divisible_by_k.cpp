#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> freq(k, 0);
        int count = 0;

        for (int num : arr) {
            int rem = ((num % k) + k) % k;
            int need = (k - rem) % k;

            if (freq[need] > 0) {
                count++;
                freq[need]--;
            } else {
                freq[rem]++;
            }
        }

        return count == n / 2;
    }
};
