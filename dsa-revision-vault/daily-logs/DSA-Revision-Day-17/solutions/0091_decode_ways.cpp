class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);

        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }

            if (i >= 2) {
                int two = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');

                if (two >= 10 && two <= 26) {
                    dp[i] += dp[i - 2];
                }
            }
        }

        return dp[n];
    }
};
