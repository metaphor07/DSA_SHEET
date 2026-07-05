class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for (int x : nums) total += x;

        if (abs(target) > total) return 0;
        if ((total + target) % 2 != 0) return 0;

        int sum = (total + target) / 2;

        vector<int> dp(sum + 1, 0);
        dp[0] = 1;

        for (int num : nums) {
            for (int x = sum; x >= num; x--) {
                dp[x] += dp[x - num];
            }
        }

        return dp[sum];
    }
};
