// Q4. Longest Palindromic Path in Graph
// Topic: Bitmask DP + two endpoints

class Solution {
public:
    int maxLen(int n, vector<vector<int>>& edges, string label) {
        vector<vector<int>> graph(n);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int totalMask = 1 << n;

        vector<vector<vector<char>>> dp(
            totalMask,
            vector<vector<char>>(n, vector<char>(n, 0))
        );

        queue<tuple<int, int, int>> q;
        int ans = 1;

        for (int i = 0; i < n; i++) {
            int mask = 1 << i;

            dp[mask][i][i] = 1;
            q.push({mask, i, i});
        }

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            if (label[u] == label[v]) {
                int mask = (1 << u) | (1 << v);

                if (!dp[mask][u][v]) {
                    dp[mask][u][v] = 1;
                    q.push({mask, u, v});
                }

                if (!dp[mask][v][u]) {
                    dp[mask][v][u] = 1;
                    q.push({mask, v, u});
                }

                ans = max(ans, 2);
            }
        }

        while (!q.empty()) {
            auto [mask, left, right] = q.front();
            q.pop();

            ans = max(ans, __builtin_popcount((unsigned)mask));

            for (int newLeft : graph[left]) {
                if (mask & (1 << newLeft)) {
                    continue;
                }

                for (int newRight : graph[right]) {
                    if (mask & (1 << newRight)) {
                        continue;
                    }

                    if (newLeft == newRight) {
                        continue;
                    }

                    if (label[newLeft] != label[newRight]) {
                        continue;
                    }

                    int newMask = mask | (1 << newLeft) | (1 << newRight);

                    if (!dp[newMask][newLeft][newRight]) {
                        dp[newMask][newLeft][newRight] = 1;
                        q.push({newMask, newLeft, newRight});
                    }
                }
            }
        }

        return ans;
    }
};
