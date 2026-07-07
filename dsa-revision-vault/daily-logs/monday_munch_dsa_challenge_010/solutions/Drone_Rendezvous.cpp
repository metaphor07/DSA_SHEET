// Drone Rendezvous
// BFS from both starts.
// Answer = min over clear cells of max(distAlpha[cell], distBeta[cell]).

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> bfs(const vector<vector<int>>& grid, int K, int sx, int sy) {
    int N = grid.size();
    int M = grid[0].size();

    vector<vector<int>> dist(N, vector<int>(M, -1));
    queue<pair<int,int>> q;

    if (grid[sx][sy] == 1) return dist;

    vector<pair<int,int>> moves;
    for (int dx = -K; dx <= K; dx++) {
        int rem = K - abs(dx);
        for (int dy = -rem; dy <= rem; dy++) {
            if (dx == 0 && dy == 0) continue;
            moves.push_back({dx, dy});
        }
    }

    dist[sx][sy] = 0;
    q.push({sx, sy});

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy] : moves) {
            int nx = x + dx;
            int ny = y + dy;

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (grid[nx][ny] == 1) continue;
            if (dist[nx][ny] != -1) continue;

            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    return dist;
}

void solve() {
    int N, M, K1, K2;
    cin >> N >> M >> K1 >> K2;

    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    auto d1 = bfs(grid, K1, 0, 0);
    auto d2 = bfs(grid, K2, 0, M - 1);

    int ans = INT_MAX;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == 1) continue;
            if (d1[i][j] != -1 && d2[i][j] != -1) {
                ans = min(ans, max(d1[i][j], d2[i][j]));
            }
        }
    }

    cout << (ans == INT_MAX ? -1 : ans) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}
