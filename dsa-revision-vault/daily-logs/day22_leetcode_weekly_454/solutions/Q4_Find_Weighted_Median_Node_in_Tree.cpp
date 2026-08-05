// Q4. Find Weighted Median Node in Tree
// Topic: LCA + binary lifting by weighted distance
// Time: O((n + q) log n)
// Space: O(n log n)
//
// Weighted median for query (u, v):
// first node x on path u -> v such that distance(u, x) >= half of distance(u, v).
// Use threshold = ceil(totalDistance / 2).

class Solution {
public:
    int LOG;
    vector<vector<pair<int, long long>>> graph;
    vector<vector<int>> up;
    vector<int> depth;
    vector<long long> rootDist;

    void dfs(int node, int parent) {
        up[0][node] = parent;

        for (auto [nei, wt] : graph[node]) {
            if (nei == parent) continue;

            depth[nei] = depth[node] + 1;
            rootDist[nei] = rootDist[node] + wt;

            dfs(nei, node);
        }
    }

    int lca(int a, int b) {
        if (depth[a] < depth[b]) {
            swap(a, b);
        }

        int diff = depth[a] - depth[b];

        for (int bit = LOG - 1; bit >= 0; bit--) {
            if (diff & (1 << bit)) {
                a = up[bit][a];
            }
        }

        if (a == b) return a;

        for (int bit = LOG - 1; bit >= 0; bit--) {
            if (up[bit][a] != up[bit][b]) {
                a = up[bit][a];
                b = up[bit][b];
            }
        }

        return up[0][a];
    }

    long long dist(int a, int b) {
        int g = lca(a, b);
        return rootDist[a] + rootDist[b] - 2LL * rootDist[g];
    }

    int climbUpToReach(int u, int anc, long long need) {
        long long acc = 0;
        int cur = u;

        for (int bit = LOG - 1; bit >= 0; bit--) {
            int nxt = up[bit][cur];

            if (depth[nxt] >= depth[anc]) {
                long long jumpDist = rootDist[cur] - rootDist[nxt];

                if (acc + jumpDist < need) {
                    acc += jumpDist;
                    cur = nxt;
                }
            }
        }

        return up[0][cur];
    }

    int climbDownToReach(int anc, int v, long long needDown) {
        int cur = v;

        for (int bit = LOG - 1; bit >= 0; bit--) {
            int candidate = up[bit][cur];

            if (depth[candidate] >= depth[anc]) {
                long long distFromAnc = rootDist[candidate] - rootDist[anc];

                if (distFromAnc >= needDown) {
                    cur = candidate;
                }
            }
        }

        return cur;
    }

    vector<int> findMedian(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        LOG = 1;

        while ((1 << LOG) <= n) {
            LOG++;
        }

        graph.assign(n, {});

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        up.assign(LOG, vector<int>(n, 0));
        depth.assign(n, 0);
        rootDist.assign(n, 0);

        dfs(0, 0);

        for (int bit = 1; bit < LOG; bit++) {
            for (int node = 0; node < n; node++) {
                up[bit][node] = up[bit - 1][up[bit - 1][node]];
            }
        }

        vector<int> ans;

        for (auto& q : queries) {
            int u = q[0];
            int v = q[1];

            if (u == v) {
                ans.push_back(u);
                continue;
            }

            int g = lca(u, v);

            long long total = dist(u, v);
            long long need = (total + 1) / 2;

            long long upPart = rootDist[u] - rootDist[g];

            if (need <= upPart) {
                ans.push_back(climbUpToReach(u, g, need));
            } else {
                long long needDown = need - upPart;
                ans.push_back(climbDownToReach(g, v, needDown));
            }
        }

        return ans;
    }
};
