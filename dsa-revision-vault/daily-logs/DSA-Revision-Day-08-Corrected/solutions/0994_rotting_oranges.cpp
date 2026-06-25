class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if (fresh == 0) return 0;

        vector<int> dr = {1, -1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};

        int minutes = 0;

        while (!q.empty()) {
            int size = q.size();
            bool rottedThisMinute = false;

            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr < 0 || nc < 0 || nr >= n || nc >= m || grid[nr][nc] != 1) {
                        continue;
                    }

                    grid[nr][nc] = 2;
                    fresh--;
                    rottedThisMinute = true;
                    q.push({nr, nc});
                }
            }

            if (rottedThisMinute) minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};
