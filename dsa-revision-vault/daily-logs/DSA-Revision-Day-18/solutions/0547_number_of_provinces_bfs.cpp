class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;

            provinces++;
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int nei = 0; nei < n; nei++) {
                    if (isConnected[node][nei] == 1 && !visited[nei]) {
                        visited[nei] = true;
                        q.push(nei);
                    }
                }
            }
        }

        return provinces;
    }
};
