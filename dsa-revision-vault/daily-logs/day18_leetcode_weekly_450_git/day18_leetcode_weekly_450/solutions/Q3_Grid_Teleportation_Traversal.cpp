// Q3. Grid Teleportation Traversal
// Topic: 0-1 BFS
// Time: O(m*n + total portal cells)
// Space: O(m*n)

class Solution {
public:
    int minMoves(vector<string>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        if (matrix[0][0] == '#' || matrix[m - 1][n - 1] == '#') {
            return -1;
        }

        vector<vector<pair<int, int>>> portals(26);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char ch = matrix[i][j];

                if (ch >= 'A' && ch <= 'Z') {
                    portals[ch - 'A'].push_back({i, j});
                }
            }
        }

        const int INF = 1e9;

        vector<vector<int>> dist(m, vector<int>(n, INF));
        vector<bool> usedPortal(26, false);

        deque<pair<int, int>> dq;

        dist[0][0] = 0;
        dq.push_front({0, 0});

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();

            int curDist = dist[r][c];

            if (r == m - 1 && c == n - 1) {
                return curDist;
            }

            char ch = matrix[r][c];

            if (ch >= 'A' && ch <= 'Z' && !usedPortal[ch - 'A']) {
                usedPortal[ch - 'A'] = true;

                for (auto [nr, nc] : portals[ch - 'A']) {
                    if (dist[nr][nc] > curDist) {
                        dist[nr][nc] = curDist;
                        dq.push_front({nr, nc});
                    }
                }
            }

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
                if (matrix[nr][nc] == '#') continue;

                if (dist[nr][nc] > curDist + 1) {
                    dist[nr][nc] = curDist + 1;
                    dq.push_back({nr, nc});
                }
            }
        }

        return -1;
    }
};
