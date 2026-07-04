// Q3. Minimum Operations to Transform Binary String
// Topic: Recursion + memoization
// State: recFun(index, currentBit)
// Time: O(n * 2)
// Space: O(n * 2)

class Solution {
public:
    int n;
    string s1, s2;
    const int INF = 1e9;
    vector<vector<int>> dp;

    int recFun(int ind, int curBit) {
        if (ind == n) return 0;

        if (dp[ind][curBit] != -1) return dp[ind][curBit];

        int ans = INF;

        // Case 1: Fix current position alone if possible.
        if (s2[ind] == '1') {
            // 0 -> 1 is allowed.
            int cost = (curBit == 0 ? 1 : 0);

            int nextBit = 0;
            if (ind + 1 < n) {
                nextBit = s1[ind + 1] - '0';
            }

            ans = min(ans, cost + recFun(ind + 1, nextBit));
        } else {
            // s2[ind] == '0'
            // 1 -> 0 alone is not allowed.
            if (curBit == 0) {
                int nextBit = 0;
                if (ind + 1 < n) {
                    nextBit = s1[ind + 1] - '0';
                }

                ans = min(ans, recFun(ind + 1, nextBit));
            }
        }

        // Case 2: Use pair operation on ind and ind + 1.
        if (ind + 1 < n) {
            int nextBit = s1[ind + 1] - '0';

            int cost = 0;

            // Pair operation needs both bits to be 1 first.
            if (curBit == 0) cost++;
            if (nextBit == 0) cost++;

            // Operation: 11 -> 00
            cost++;

            // After pair operation, current bit becomes 0.
            // If target wants 1, restore current bit.
            if (s2[ind] == '1') {
                cost++;
            }

            // ind + 1 becomes 0 because of pair operation.
            ans = min(ans, cost + recFun(ind + 1, 0));
        }

        return dp[ind][curBit] = ans;
    }

    int minOperations(string a, string b) {
        if (a.size() != b.size()) return -1;

        s1 = a;
        s2 = b;
        n = s1.size();

        dp.assign(n, vector<int>(2, -1));

        int startBit = s1[0] - '0';

        int ans = recFun(0, startBit);

        if (ans >= INF) return -1;
        return ans;
    }
};
