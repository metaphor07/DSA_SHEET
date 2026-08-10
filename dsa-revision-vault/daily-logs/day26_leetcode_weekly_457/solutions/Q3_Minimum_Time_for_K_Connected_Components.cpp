// Q3. Minimum Time for K Connected Components
// Topic: Binary search on answer + DSU
// Time: O(E log T * alpha(N))
// Space: O(N)

class DSU {
public:
    vector<int> parent, size;
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

    void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            swap(pu, pv);
        }

        parent[pv] = pu;
        size[pu] += size[pv];
        components--;
    }
};

class Solution {
public:
    bool canMake(int n, vector<vector<int>>& edges, int k, int time) {
        DSU dsu(n);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int removeTime = e[2];

            if (removeTime > time) {
                dsu.unionBySize(u, v);
            }
        }

        return dsu.components >= k;
    }

    int minTime(int n, vector<vector<int>>& edges, int k) {
        int low = 0;
        int high = 0;

        for (auto& e : edges) {
            high = max(high, e[2]);
        }

        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canMake(n, edges, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
