// Q3. Minimum Array End
// Status: Yellow
// Topic: Bit manipulation
// Time: O(64)
// Space: O(1)

class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = x;
        long long add = n - 1;

        int bit = 0;

        for (int pos = 0; pos < 63; pos++) {
            if (((long long)x & (1LL << pos)) == 0) {
                if (add & (1LL << bit)) {
                    ans |= (1LL << pos);
                }

                bit++;
            }
        }

        return ans;
    }
};
