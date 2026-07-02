class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& heights, vector<vector<bool>>& visited) {
        visited[row][col] = true;

        int rows = heights.size();
        int cols = heights[0].size();

        vector<int> dr = {1, -1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};

        for (int k = 0; k < 4; k++) {
            int nr = row + dr[k];
            int nc = col + dc[k];

            if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) continue;
            if (visited[nr][nc]) continue;

            if (heights[nr][nc] >= heights[row][col]) {
                dfs(nr, nc, heights, visited);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++) {
            dfs(i, 0, heights, pacific);
            dfs(i, cols - 1, heights, atlantic);
        }

        for (int j = 0; j < cols; j++) {
            dfs(0, j, heights, pacific);
            dfs(rows - 1, j, heights, atlantic);
        }

        vector<vector<int>> ans;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
