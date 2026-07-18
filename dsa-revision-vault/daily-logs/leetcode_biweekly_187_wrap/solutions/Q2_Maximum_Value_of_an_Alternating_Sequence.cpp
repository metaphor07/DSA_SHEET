// Q2. Maximum Value of an Alternating Sequence
// Topic: Math / greedy construction
//
// first peak = s + m
// every next peak adds m - 1

class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if (n == 1) return s;

        long long peaks = n / 2;
        long long ans = 1LL * s + m + (peaks - 1) * 1LL * (m - 1);

        return ans;
    }
};
