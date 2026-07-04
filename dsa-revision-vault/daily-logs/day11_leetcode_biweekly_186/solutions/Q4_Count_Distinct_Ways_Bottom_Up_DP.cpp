// Q4. Count Distinct Ways to Form Target from Two Strings
// Topic: DP + prefix sums
// Time: O(target.length * word1.length * word2.length)
// Space: O(word1.length * word2.length)

class Solution {
public:
    int interleaveCharacters(string word1, string word2, string target) {
        const int MOD = 1e9 + 7;

        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        dp[0][0] = 1;

        for (char ch : target) {
            vector<vector<int>> ndp(n + 1, vector<int>(m + 1, 0));

            // Choose current target character from word1.
            for (int j = 0; j <= m; j++) {
                long long prefixSum = 0;

                for (int i = 1; i <= n; i++) {
                    prefixSum = (prefixSum + dp[i - 1][j]) % MOD;

                    if (word1[i - 1] == ch) {
                        ndp[i][j] = (ndp[i][j] + prefixSum) % MOD;
                    }
                }
            }

            // Choose current target character from word2.
            for (int i = 0; i <= n; i++) {
                long long prefixSum = 0;

                for (int j = 1; j <= m; j++) {
                    prefixSum = (prefixSum + dp[i][j - 1]) % MOD;

                    if (word2[j - 1] == ch) {
                        ndp[i][j] = (ndp[i][j] + prefixSum) % MOD;
                    }
                }
            }

            dp = ndp;
        }

        long long ans = 0;

        // At least one character must be chosen from both word1 and word2.
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                ans = (ans + dp[i][j]) % MOD;
            }
        }

        return ans;
    }
};
