// Q3. Maximum Area of Two Non-Overlapping Square Submatrices
// Maximal Square DP + Binary Search

class Solution {
public:
    int rows, cols;
    vector<vector<int>> dp;

    bool canMake(int k) {
        vector<pair<int, int>> squares;
        vector<int> bottomExists(rows, 0);
        vector<int> rightExists(cols, 0);

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (dp[r][c] >= k) {
                    int top = r - k + 1;
                    int left = c - k + 1;

                    squares.push_back({top, left});
                    bottomExists[r] = 1;
                    rightExists[c] = 1;
                }
            }
        }

        if (squares.size() < 2) return false;

        vector<int> prefixBottom(rows, 0);
        vector<int> prefixRight(cols, 0);

        for (int i = 0; i < rows; i++) {
            prefixBottom[i] = bottomExists[i];
            if (i > 0) prefixBottom[i] |= prefixBottom[i - 1];
        }

        for (int j = 0; j < cols; j++) {
            prefixRight[j] = rightExists[j];
            if (j > 0) prefixRight[j] |= prefixRight[j - 1];
        }

        for (auto& square : squares) {
            int top = square.first;
            int left = square.second;

            if (top > 0 && prefixBottom[top - 1]) return true;
            if (left > 0 && prefixRight[left - 1]) return true;
        }

        return false;
    }

    int maxArea(vector<vector<int>>& mat) {
        rows = mat.size();
        cols = mat[0].size();

        dp.assign(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 0) {
                    dp[i][j] = 0;
                } else if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                }
            }
        }

        int low = 1, high = min(rows, cols), ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canMake(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans * ans;
    }
};
