// Q2. Weighted Sum of a Tree
// parent array -> children list -> BFS depth

class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();

        vector<vector<int>> tree(n);

        for (int i = 1; i < n; i++) {
            tree[parent[i]].push_back(i);
        }

        vector<int> depth(n, 0);
        queue<int> q;

        q.push(0);
        depth[0] = 1;

        int height = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            height = max(height, depth[node]);

            for (int child : tree[node]) {
                depth[child] = depth[node] + 1;
                q.push(child);
            }
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long multiplier = height - depth[i] + 1;
            ans += 1LL * nums[i] * multiplier;
        }

        return ans;
    }
};
