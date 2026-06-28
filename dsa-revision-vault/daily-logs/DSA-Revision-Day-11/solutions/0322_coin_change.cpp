class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int x = 1; x <= amount; x++) {
            for (int coin : coins) {
                if (x - coin >= 0) {
                    dp[x] = min(dp[x], 1 + dp[x - coin]);
                }
            }
        }

        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};
