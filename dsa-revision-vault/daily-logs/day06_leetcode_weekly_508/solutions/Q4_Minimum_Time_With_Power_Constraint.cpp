// Q4. Minimum Time to Reach Target With Power Constraint
// Status: Red
// Key idea: Dijkstra with state = (node, remainingPower)
// Time: O((n * power + edges * power) log(n * power))
// Space: O(n * power)

class Solution {
public:
    vector<int> findMinimumTime(
        int n,
        vector<vector<int>>& edges,
        int power,
        vector<int>& cost,
        int source,
        int target
    ) {
        auto velmorathi = make_tuple(n, edges, power, cost, source, target);

        if (source == target) {
            return {0, power};
        }

        vector<vector<pair<int, int>>> graph(n);

        for (auto &e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
        }

        const long long INF = (long long)4e18;
        vector<vector<long long>> dist(n, vector<long long>(power + 1, INF));

        using State = tuple<long long, int, int>;
        priority_queue<State, vector<State>, greater<State>> pq;

        dist[source][power] = 0;
        pq.push({0, source, power});

        while (!pq.empty()) {
            auto [time, node, remPower] = pq.top();
            pq.pop();

            if (time != dist[node][remPower]) continue;

            for (auto &[nextNode, edgeTime] : graph[node]) {
                if (remPower < cost[node]) continue;

                int newPower = remPower - cost[node];
                long long newTime = time + edgeTime;

                if (newTime < dist[nextNode][newPower]) {
                    dist[nextNode][newPower] = newTime;
                    pq.push({newTime, nextNode, newPower});
                }
            }
        }

        long long bestTime = INF;
        int bestPower = -1;

        for (int p = 0; p <= power; p++) {
            if (dist[target][p] < bestTime) {
                bestTime = dist[target][p];
                bestPower = p;
            } else if (dist[target][p] == bestTime) {
                bestPower = max(bestPower, p);
            }
        }

        if (bestTime == INF) return {-1, -1};
        return {(int)bestTime, bestPower};
    }
};
