// Q2. Minimize Maximum Component Cost
// Topic: Kruskal / DSU

class DSU {
public:
    vector<int> parent;
    vector<int> size;
    int components;

    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        components = n;

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if (parent[node] == node) {
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    bool unite(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv) {
            return false;
        }

        if (size[pu] < size[pv]) {
            swap(pu, pv);
        }

        parent[pv] = pu;
        size[pu] += size[pv];
        components--;

        return true;
    }
};

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        if (k == n) {
            return 0;
        }

        sort(edges.begin(), edges.end(), [](auto& a, auto& b) {
            return a[2] < b[2];
        });

        DSU dsu(n);
        int ans = 0;

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            if (dsu.unite(u, v)) {
                ans = w;

                if (dsu.components == k) {
                    return ans;
                }
            }
        }

        return ans;
    }
};
