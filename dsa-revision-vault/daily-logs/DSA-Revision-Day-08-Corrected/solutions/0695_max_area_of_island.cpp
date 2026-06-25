class Solution {
public:
    int dfs(int r, int c, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (r < 0 || c < 0 || r >= n || c >= m || grid[r][c] == 0) {
            return 0;
        }

        grid[r][c] = 0;

        int area = 1;
        area += dfs(r + 1, c, grid);
        area += dfs(r - 1, c, grid);
        area += dfs(r, c + 1, grid);
        area += dfs(r, c - 1, grid);

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    ans = max(ans, dfs(i, j, grid));
                }
            }
        }

        return ans;
    }
};
