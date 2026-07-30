class Solution {
public:
    int rows, cols;

    void dfs(int r, int c, vector<vector<char>>& board) {
        if (r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] != 'O') return;

        board[r][c] = '#';

        dfs(r + 1, c, board);
        dfs(r - 1, c, board);
        dfs(r, c + 1, board);
        dfs(r, c - 1, board);
    }

    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();

        for (int r = 0; r < rows; r++) {
            dfs(r, 0, board);
            dfs(r, cols - 1, board);
        }

        for (int c = 0; c < cols; c++) {
            dfs(0, c, board);
            dfs(rows - 1, c, board);
        }

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] == 'O') board[r][c] = 'X';
                else if (board[r][c] == '#') board[r][c] = 'O';
            }
        }
    }
};
