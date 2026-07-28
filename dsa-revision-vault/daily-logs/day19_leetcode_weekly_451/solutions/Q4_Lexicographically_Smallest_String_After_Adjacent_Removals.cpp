// Q4. Lexicographically Smallest String After Adjacent Removals
// Topic: Interval DP + suffix DP
// Time: O(n^3)
// Space: O(n^2)

class Solution {
public:
    bool isConsecutive(char a, char b) {
        int diff = abs(a - b);
        return diff == 1 || diff == 25;
    }

    string lexicographicallySmallestString(string s) {
        int n = s.size();

        vector<vector<bool>> can(n, vector<bool>(n, false));

        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;

                if (isConsecutive(s[l], s[r])) {
                    if (len == 2 || can[l + 1][r - 1]) {
                        can[l][r] = true;
                    }
                }

                if (!can[l][r]) {
                    for (int k = l + 1; k < r; k += 2) {
                        if (can[l][k] && can[k + 1][r]) {
                            can[l][r] = true;
                            break;
                        }
                    }
                }
            }
        }

        vector<string> dp(n + 1);
        dp[n] = "";

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = s[i] + dp[i + 1];

            for (int j = i; j < n; j++) {
                if (can[i][j]) {
                    dp[i] = min(dp[i], dp[j + 1]);
                }
            }
        }

        return dp[0];
    }
};
