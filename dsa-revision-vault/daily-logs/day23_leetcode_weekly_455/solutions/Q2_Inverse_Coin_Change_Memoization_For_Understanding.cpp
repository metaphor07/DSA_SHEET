// Q2. Inverse Coin Change - Memoization version for understanding
// This is not the preferred submission version.
// Preferred version is tabulation DP reconstruction.

class Solution {
public:
    vector<int> coins;
    vector<vector<long long>> memo;

    long long countWays(int idx, int amount) {
        if (amount == 0) return 1;
        if (idx == coins.size()) return 0;

        if (memo[idx][amount] != -1) {
            return memo[idx][amount];
        }

        long long notTake = countWays(idx + 1, amount);

        long long take = 0;
        if (amount >= coins[idx]) {
            take = countWays(idx, amount - coins[idx]);
        }

        return memo[idx][amount] = take + notTake;
    }

    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size();
        coins.clear();

        for (int amount = 1; amount <= n; amount++) {
            memo.assign(coins.size() + 1, vector<long long>(n + 1, -1));

            long long currentWays = countWays(0, amount);
            long long targetWays = numWays[amount - 1];

            if (currentWays == targetWays) {
                continue;
            }

            if (currentWays + 1 == targetWays) {
                coins.push_back(amount);
            } else {
                return {};
            }
        }

        return coins;
    }
};
