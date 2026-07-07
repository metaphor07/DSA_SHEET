// Critics Special
// Tree + sorted candidates + timestamp marking
//
// For each node v, inspected nodes are v and its direct neighbours.
// Need highest popularity uninspected node, or 0 if none.
// Sort nodes by popularity descending. For each v, mark v and neighbours,
// then scan sorted nodes and take first unmarked node.

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<int> P(N + 1);
    for (int i = 1; i <= N; i++) cin >> P[i];

    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> nodes(N);
    iota(nodes.begin(), nodes.end(), 1);

    sort(nodes.begin(), nodes.end(), [&](int a, int b) {
        return P[a] > P[b];
    });

    vector<int> mark(N + 1, 0);
    int timer = 0;

    for (int v = 1; v <= N; v++) {
        timer++;

        mark[v] = timer;
        for (int nei : adj[v]) {
            mark[nei] = timer;
        }

        int ans = 0;
        for (int candidate : nodes) {
            if (mark[candidate] != timer) {
                ans = candidate;
                break;
            }
        }

        cout << ans << (v == N ? '\n' : ' ');
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}
