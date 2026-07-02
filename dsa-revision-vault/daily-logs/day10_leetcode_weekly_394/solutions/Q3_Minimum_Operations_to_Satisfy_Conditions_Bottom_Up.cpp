// Q3. Minimum Number of Operations to Satisfy Conditions
// Status: Yellow
// Topic: Column cost + DP
// Time: O(m*n + n*10*10)
// Space: O(n*10)

class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> cost(n, vector<int>(10, 0));

        for (int col = 0; col < n; col++) {
            vector<int> freq(10, 0);

            for (int row = 0; row < m; row++) {
                freq[grid[row][col]]++;
            }

            for (int digit = 0; digit <= 9; digit++) {
                cost[col][digit] = m - freq[digit];
            }
        }

        vector<vector<int>> dp(n, vector<int>(10, 1e9));

        for (int digit = 0; digit <= 9; digit++) {
            dp[0][digit] = cost[0][digit];
        }

        for (int col = 1; col < n; col++) {
            for (int digit = 0; digit <= 9; digit++) {
                for (int prev = 0; prev <= 9; prev++) {
                    if (prev == digit) continue;
                    dp[col][digit] = min(dp[col][digit], dp[col - 1][prev] + cost[col][digit]);
                }
            }
        }

        int ans = 1e9;

        for (int digit = 0; digit <= 9; digit++) {
            ans = min(ans, dp[n - 1][digit]);
        }

        return ans;
    }
};
