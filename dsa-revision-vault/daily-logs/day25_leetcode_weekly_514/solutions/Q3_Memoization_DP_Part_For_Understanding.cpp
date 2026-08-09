// Q3 memoization only for Maximal Square DP part

class SolutionMemoPart {
public:
    int rows, cols;
    vector<vector<int>> memo;

    int dfs(int i, int j, vector<vector<int>>& mat) {
        if (i >= rows || j >= cols) return 0;
        if (mat[i][j] == 0) return 0;

        if (memo[i][j] != -1) return memo[i][j];

        int down = dfs(i + 1, j, mat);
        int right = dfs(i, j + 1, mat);
        int diagonal = dfs(i + 1, j + 1, mat);

        return memo[i][j] = 1 + min({down, right, diagonal});
    }
};
