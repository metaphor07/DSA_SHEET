// Q4. Maximize Spanning Tree Stability with Upgrades
// Topic: DSU + Binary Search on Answer
// Time: O(E log(MAX_STRENGTH) * alpha(N))
// Space: O(N + E)

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
    int nGlobal;
    int kGlobal;
    vector<vector<int>> edgesGlobal;

    bool canMake(int limit) {
        DSU dsu(nGlobal);

        for (auto& e : edgesGlobal) {
            int u = e[0];
            int v = e[1];
            int strength = e[2];
            int must = e[3];

            if (must == 1) {
                if (strength < limit) {
                    return false;
                }

                if (!dsu.unite(u, v)) {
                    return false;
                }
            }
        }

        for (auto& e : edgesGlobal) {
            int u = e[0];
            int v = e[1];
            int strength = e[2];
            int must = e[3];

            if (must == 0 && strength >= limit) {
                dsu.unite(u, v);
            }
        }

        int upgradesLeft = kGlobal;

        for (auto& e : edgesGlobal) {
            int u = e[0];
            int v = e[1];
            int strength = e[2];
            int must = e[3];

            if (must == 0 && strength < limit && 2LL * strength >= limit) {
                if (dsu.findParent(u) != dsu.findParent(v)) {
                    if (upgradesLeft == 0) {
                        continue;
                    }

                    dsu.unite(u, v);
                    upgradesLeft--;
                }
            }
        }

        return dsu.components == 1;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        nGlobal = n;
        edgesGlobal = edges;
        kGlobal = k;

        DSU mustDsu(n);

        for (auto& e : edges) {
            if (e[3] == 1) {
                if (!mustDsu.unite(e[0], e[1])) {
                    return -1;
                }
            }
        }

        DSU allDsu(n);

        for (auto& e : edges) {
            allDsu.unite(e[0], e[1]);
        }

        if (allDsu.components > 1) {
            return -1;
        }

        int low = 1;
        int high = 200000;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canMake(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
