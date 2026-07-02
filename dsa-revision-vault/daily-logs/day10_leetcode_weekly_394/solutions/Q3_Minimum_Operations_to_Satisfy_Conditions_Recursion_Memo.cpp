// Q3. Minimum Number of Operations to Satisfy Conditions
// Status: Yellow
// Topic: Recursion + memoization
// Time: O(m*n + n*11*10)
// Space: O(n*11)

class Solution {
public:
    int m, n;
    vector<vector<int>> cost;
    vector<vector<int>> dp;

    int solve(int col, int prevDigit) {
        if (col == n) return 0;

        if (dp[col][prevDigit + 1] != -1) {
            return dp[col][prevDigit + 1];
        }

        int ans = 1e9;

        for (int digit = 0; digit <= 9; digit++) {
            if (digit == prevDigit) continue;
            ans = min(ans, cost[col][digit] + solve(col + 1, digit));
        }

        return dp[col][prevDigit + 1] = ans;
    }

    int minimumOperations(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        cost.assign(n, vector<int>(10, 0));

        for (int col = 0; col < n; col++) {
            vector<int> freq(10, 0);

            for (int row = 0; row < m; row++) {
                freq[grid[row][col]]++;
            }

            for (int digit = 0; digit <= 9; digit++) {
                cost[col][digit] = m - freq[digit];
            }
        }

        dp.assign(n, vector<int>(11, -1));

        return solve(0, -1);
    }
};
