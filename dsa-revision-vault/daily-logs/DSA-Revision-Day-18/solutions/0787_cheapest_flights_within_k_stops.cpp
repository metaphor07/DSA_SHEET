class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        vector<int> cost(n, INT_MAX);
        cost[src] = 0;

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            int stops = front.first;
            int node = front.second.first;
            int currCost = front.second.second;

            if (stops > k) continue;

            for (auto& [nei, price] : adj[node]) {
                int newCost = currCost + price;

                if (newCost < cost[nei]) {
                    cost[nei] = newCost;
                    q.push({stops + 1, {nei, newCost}});
                }
            }
        }

        return cost[dst] == INT_MAX ? -1 : cost[dst];
    }
};
