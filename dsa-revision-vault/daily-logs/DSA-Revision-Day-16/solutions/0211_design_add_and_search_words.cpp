class WordDictionary {
    struct TrieNode {
        TrieNode* children[26];
        bool isEndOfWord;

        TrieNode() {
            isEndOfWord = false;
            for (int i = 0; i < 26; i++) children[i] = nullptr;
        }
    };

    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* cur = root;

        for (char c : word) {
            int idx = c - 'a';

            if (cur->children[idx] == nullptr) {
                cur->children[idx] = new TrieNode();
            }

            cur = cur->children[idx];
        }

        cur->isEndOfWord = true;
    }

    bool dfs(string& word, int index, TrieNode* node) {
        if (node == nullptr) return false;

        if (index == word.size()) return node->isEndOfWord;

        char c = word[index];

        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->children[i] != nullptr) {
                    if (dfs(word, index + 1, node->children[i])) return true;
                }
            }
            return false;
        }

        int idx = c - 'a';
        return dfs(word, index + 1, node->children[idx]);
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};
