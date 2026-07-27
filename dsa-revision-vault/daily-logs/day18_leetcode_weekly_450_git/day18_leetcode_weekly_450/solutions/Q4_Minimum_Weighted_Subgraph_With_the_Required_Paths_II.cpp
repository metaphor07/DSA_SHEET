// Q4. Minimum Weighted Subgraph With the Required Paths II
// Topic: LCA + weighted tree distance
// Time: O((n + q) log n)
// Space: O(n log n)
//
// For query (a, b, c), minimum subtree connecting these 3 nodes has weight:
// (dist(a,b) + dist(a,c) + dist(b,c)) / 2

class Solution {
public:
    int LOG;
    vector<vector<pair<int, int>>> graph;
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
        int ancestor = lca(a, b);
        return rootDist[a] + rootDist[b] - 2LL * rootDist[ancestor];
    }

    vector<int> minimumWeight(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;

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
            int src1 = q[0];
            int src2 = q[1];
            int dest = q[2];

            long long d12 = dist(src1, src2);
            long long d1d = dist(src1, dest);
            long long d2d = dist(src2, dest);

            long long total = (d12 + d1d + d2d) / 2;

            ans.push_back((int)total);
        }

        return ans;
    }
};
