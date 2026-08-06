// Q3. Minimum Increments to Equalize Leaf Paths
// Topic: Tree DFS + greedy bottom-up
// Time: O(n)
// Space: O(n)
//
// Important bug fix:
// Edges are undirected. Build both directions and avoid parent during DFS.

class Solution {
public:
    long long ans = 0;
    vector<vector<int>> tree;

    long long dfs(int node, int parent, vector<int>& cost) {
        vector<long long> childSums;
        long long mx = 0;

        for (int child : tree[node]) {
            if (child == parent) continue;

            long long sum = dfs(child, node, cost);
            childSums.push_back(sum);
            mx = max(mx, sum);
        }

        if (childSums.empty()) {
            return cost[node];
        }

        for (long long sum : childSums) {
            if (sum < mx) {
                ans++;
            }
        }

        return cost[node] + mx;
    }

    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        tree.assign(n, {});

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        ans = 0;
        dfs(0, -1, cost);

        return (int)ans;
    }
};
