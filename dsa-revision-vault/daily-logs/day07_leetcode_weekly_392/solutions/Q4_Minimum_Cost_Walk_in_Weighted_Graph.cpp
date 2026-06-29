// Q4. Minimum Cost Walk in Weighted Graph
// Status: Red
// Topic: DSU + bitwise AND of component edges
// Time: O((n + edges + queries) * alpha(n))
// Space: O(n)

class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if (pa == pb) return;

        if (size[pa] < size[pb]) swap(pa, pb);

        parent[pb] = pa;
        size[pa] += size[pb];
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU dsu(n);

        for (auto &e : edges) {
            dsu.unite(e[0], e[1]);
        }

        vector<int> componentAnd(n, -1);

        for (auto &e : edges) {
            int root = dsu.find(e[0]);
            int w = e[2];

            if (componentAnd[root] == -1) componentAnd[root] = w;
            else componentAnd[root] &= w;
        }

        vector<int> ans;

        for (auto &q : query) {
            int s = q[0];
            int t = q[1];

            int ps = dsu.find(s);
            int pt = dsu.find(t);

            if (ps != pt) ans.push_back(-1);
            else ans.push_back(componentAnd[ps]);
        }

        return ans;
    }
};
