// Q4. Find the Sum of the Power of All Subsequences
// Bottom-up optimized version
// Time: O(n * k), Space: O(k)

class Solution {
public:
    int sumOfPower(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;

        vector<long long> dp(k + 1, 0);
        dp[0] = 1;

        for (int x : nums) {
            vector<long long> ndp(k + 1, 0);

            for (int sum = 0; sum <= k; sum++) {
                ndp[sum] = (ndp[sum] + 2LL * dp[sum]) % MOD;

                if (sum + x <= k) {
                    ndp[sum + x] = (ndp[sum + x] + dp[sum]) % MOD;
                }
            }

            dp = ndp;
        }

        return dp[k];
    }
};
