class WordDictionary {
public:
    struct Node {
        bool isEnd = false;
        Node* child[26];

        Node() {
            for (int i = 0; i < 26; i++) child[i] = NULL;
        }
    };

    Node* root;

    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node* curr = root;

        for (char c : word) {
            int idx = c - 'a';

            if (curr->child[idx] == NULL) {
                curr->child[idx] = new Node();
            }

            curr = curr->child[idx];
        }

        curr->isEnd = true;
    }

    bool dfs(int i, string& word, Node* node) {
        if (node == NULL) return false;
        if (i == word.size()) return node->isEnd;

        char c = word[i];

        if (c == '.') {
            for (int k = 0; k < 26; k++) {
                if (dfs(i + 1, word, node->child[k])) {
                    return true;
                }
            }

            return false;
        }

        return dfs(i + 1, word, node->child[c - 'a']);
    }

    bool search(string word) {
        return dfs(0, word, root);
    }
};
