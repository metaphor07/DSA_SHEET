class Trie {
public:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;

        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; i++) children[i] = nullptr;
        }
    };

    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* cur = root;

        for (char c : word) {
            int idx = c - 'a';
            if (cur->children[idx] == nullptr) {
                cur->children[idx] = new TrieNode();
            }
            cur = cur->children[idx];
        }

        cur->isEnd = true;
    }

    bool search(string word) {
        TrieNode* cur = root;

        for (char c : word) {
            int idx = c - 'a';
            if (cur->children[idx] == nullptr) return false;
            cur = cur->children[idx];
        }

        return cur->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* cur = root;

        for (char c : prefix) {
            int idx = c - 'a';
            if (cur->children[idx] == nullptr) return false;
            cur = cur->children[idx];
        }

        return true;
    }
};
