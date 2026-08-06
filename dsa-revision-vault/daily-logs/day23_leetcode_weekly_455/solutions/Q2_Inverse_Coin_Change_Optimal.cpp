// Q2. Inverse Coin Change
// Topic: Greedy reconstruction + Coin Change 2 DP
// Time: O(n^2)
// Space: O(n)

class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size();

        vector<long long> dp(n + 1, 0);
        dp[0] = 1;

        vector<int> coins;

        for (int amount = 1; amount <= n; amount++) {
            long long target = numWays[amount - 1];

            if (dp[amount] == target) {
                continue;
            }

            if (dp[amount] + 1 == target) {
                coins.push_back(amount);

                for (int sum = amount; sum <= n; sum++) {
                    dp[sum] += dp[sum - amount];
                }
            } else {
                return {};
            }
        }

        return coins;
    }
};
