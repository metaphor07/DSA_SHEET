// Q3. Kth Smallest Amount With Single Denomination Combination
// Status: Red
// Topic: Binary search on answer + inclusion-exclusion
// Time: O(log(answer) * 2^n * n)
// Space: O(1)

class Solution {
public:
    long long gcdll(long long a, long long b) {
        while (b) {
            long long r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

    long long lcmll(long long a, long long b) {
        return a / gcdll(a, b) * b;
    }

    long long countValid(long long x, vector<int>& coins) {
        int n = coins.size();
        long long cnt = 0;

        for (int mask = 1; mask < (1 << n); mask++) {
            long long lcm = 1;
            int bits = 0;
            bool tooBig = false;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    bits++;
                    lcm = lcmll(lcm, coins[i]);

                    if (lcm > x) {
                        tooBig = true;
                        break;
                    }
                }
            }

            if (tooBig) continue;

            if (bits % 2 == 1) cnt += x / lcm;
            else cnt -= x / lcm;
        }

        return cnt;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(), coins.end());

        long long low = 1;
        long long high = 1LL * coins[0] * k;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (countValid(mid, coins) >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
