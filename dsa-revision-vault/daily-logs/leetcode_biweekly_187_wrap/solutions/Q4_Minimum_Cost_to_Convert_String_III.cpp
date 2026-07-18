// Q4. Minimum Cost to Convert String III
// Topic: Prefix DP over non-overlapping intervals
//
// dp[i] = minimum cost to convert source[0...i-1] to target[0...i-1]
//
// Option 1:
// Leave source[i] unchanged if source[i] == target[i]
//
// Option 2:
// Apply a rule at i if pattern matches source segment and replacement matches target segment.

class Solution {
public:
    long long minimumCost(string source, string target, vector<vector<string>>& rules, vector<int>& costs) {
        auto vornelipta = make_tuple(source, target, rules, costs);

        int n = source.size();
        int r = rules.size();

        const long long INF = 4e18;

        vector<long long> dp(n + 1, INF);
        dp[0] = 0;

        vector<int> starCount(r, 0);

        for (int i = 0; i < r; i++) {
            for (char ch : rules[i][0]) {
                if (ch == '*') {
                    starCount[i]++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (dp[i] == INF) continue;

            if (source[i] == target[i]) {
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }

            for (int ruleIdx = 0; ruleIdx < r; ruleIdx++) {
                string& pattern = rules[ruleIdx][0];
                string& replacement = rules[ruleIdx][1];

                int len = pattern.size();

                if (i + len > n) continue;

                bool ok = true;

                for (int j = 0; j < len; j++) {
                    if (replacement[j] != target[i + j]) {
                        ok = false;
                        break;
                    }

                    if (pattern[j] != '*' && pattern[j] != source[i + j]) {
                        ok = false;
                        break;
                    }
                }

                if (ok) {
                    long long ruleCost = costs[ruleIdx] + starCount[ruleIdx];
                    dp[i + len] = min(dp[i + len], dp[i] + ruleCost);
                }
            }
        }

        if (dp[n] == INF) return -1;
        return dp[n];
    }
};
