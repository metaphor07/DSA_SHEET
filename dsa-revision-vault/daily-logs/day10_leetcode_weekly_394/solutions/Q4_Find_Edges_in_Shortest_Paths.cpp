// Q4. Find Edges in Shortest Paths
// Status: Red
// Topic: Dijkstra from source and target
// Time: O((n + m) log n)
// Space: O(n + m)

class Solution {
public:
    vector<long long> dijkstra(int n, vector<vector<pair<int,int>>>& graph, int src) {
        const long long INF = 4e18;

        vector<long long> dist(n, INF);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d != dist[node]) continue;

            for (auto &[next, wt] : graph[node]) {
                if (d + wt < dist[next]) {
                    dist[next] = d + wt;
                    pq.push({dist[next], next});
                }
            }
        }

        return dist;
    }

    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> graph(n);

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        vector<long long> distFromStart = dijkstra(n, graph, 0);
        vector<long long> distFromEnd = dijkstra(n, graph, n - 1);

        long long shortest = distFromStart[n - 1];

        vector<bool> ans;

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];

            bool ok = false;

            if (distFromStart[u] + w + distFromEnd[v] == shortest) ok = true;
            if (distFromStart[v] + w + distFromEnd[u] == shortest) ok = true;

            ans.push_back(ok);
        }

        return ans;
    }
};
