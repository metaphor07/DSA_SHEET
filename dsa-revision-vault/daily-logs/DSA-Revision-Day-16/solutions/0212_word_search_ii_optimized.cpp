class Solution {
public:
    struct TrieNode {
        TrieNode* children[26];
        string word;

        TrieNode() {
            word = "";
            for (int i = 0; i < 26; i++) children[i] = nullptr;
        }
    };

    TrieNode* root = new TrieNode();

    void insert(string& s) {
        TrieNode* cur = root;

        for (char c : s) {
            int idx = c - 'a';

            if (cur->children[idx] == nullptr) {
                cur->children[idx] = new TrieNode();
            }

            cur = cur->children[idx];
        }

        cur->word = s;
    }

    bool isLeaf(TrieNode* node) {
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) return false;
        }
        return true;
    }

    void dfs(int r, int c, TrieNode* parent, vector<vector<char>>& board, vector<string>& ans) {
        char ch = board[r][c];
        int idx = ch - 'a';

        TrieNode* cur = parent->children[idx];
        if (cur == nullptr) return;

        if (cur->word != "") {
            ans.push_back(cur->word);
            cur->word = "";
        }

        board[r][c] = '#';

        int rows = board.size();
        int cols = board[0].size();

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) continue;
            if (board[nr][nc] == '#') continue;

            int nextIdx = board[nr][nc] - 'a';

            if (cur->children[nextIdx] != nullptr) {
                dfs(nr, nc, cur, board, ans);
            }
        }

        board[r][c] = ch;

        if (cur->word == "" && isLeaf(cur)) {
            parent->children[idx] = nullptr;
            delete cur;
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (string& word : words) insert(word);

        vector<string> ans;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                int idx = board[i][j] - 'a';

                if (root->children[idx] != nullptr) {
                    dfs(i, j, root, board, ans);
                }
            }
        }

        return ans;
    }
};
