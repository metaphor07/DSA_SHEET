// Q4. Find the Sum of the Power of All Subsequences
// Recursive memoized version close to user's approach
// Time: O(n * k), Space: O(n * k)

class Solution {
public:
    static const int MOD = 1e9 + 7;

    int recFun(int ind, int k, vector<int>& nums, vector<vector<int>>& dp) {
        if (ind == nums.size()) return k == 0;

        if (dp[ind][k] != -1) return dp[ind][k];

        // Not picked in target subsequence.
        // It can still be absent/present in larger subsequence => factor 2.
        long long not_pick = 2LL * recFun(ind + 1, k, nums, dp) % MOD;

        long long pick = 0;
        if (k >= nums[ind]) {
            pick = recFun(ind + 1, k - nums[ind], nums, dp);
        }

        return dp[ind][k] = (not_pick + pick) % MOD;
    }

    int sumOfPower(vector<int>& nums, int k) {
        vector<vector<int>> dp(nums.size(), vector<int>(k + 1, -1));
        return recFun(0, k, nums, dp);
    }
};
