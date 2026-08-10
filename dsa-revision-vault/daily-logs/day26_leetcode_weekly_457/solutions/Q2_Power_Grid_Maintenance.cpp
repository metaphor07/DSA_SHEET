// Q2. Power Grid Maintenance
// Topic: DSU + sorted active set per component
// Time: O((n + e) alpha(n) + q log n)
// Space: O(n + e)

class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if (parent[node] == node) {
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            swap(pu, pv);
        }

        parent[pv] = pu;
        size[pu] += size[pv];
    }
};

class Solution {
public:
    vector<int> processQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        DSU dsu(n);

        for (auto& e : edges) {
            dsu.unionBySize(e[0], e[1]);
        }

        unordered_map<int, set<int>> component;

        for (int node = 1; node <= n; node++) {
            int root = dsu.findParent(node);
            component[root].insert(node);
        }

        vector<int> ans;

        for (auto& q : queries) {
            int type = q[0];
            int node = q[1];

            int root = dsu.findParent(node);

            if (type == 1) {
                if (component[root].count(node)) {
                    ans.push_back(node);
                } else if (!component[root].empty()) {
                    ans.push_back(*component[root].begin());
                } else {
                    ans.push_back(-1);
                }
            } else {
                component[root].erase(node);
            }
        }

        return ans;
    }
};
