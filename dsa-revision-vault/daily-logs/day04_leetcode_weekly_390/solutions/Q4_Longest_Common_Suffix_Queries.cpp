// Q4. Longest Common Suffix Queries
// Topic: Trie on reversed words
// Time: O(total length of container words + total length of query words)
// Space: O(total trie nodes)

class Solution {
public:
    struct Node {
        int child[26];
        int bestIndex;

        Node() {
            for (int i = 0; i < 26; i++) child[i] = -1;
            bestIndex = -1;
        }
    };

    vector<Node> trie;
    vector<string> words;

    bool better(int newIdx, int oldIdx) {
        if (oldIdx == -1) return true;

        if (words[newIdx].size() != words[oldIdx].size()) {
            return words[newIdx].size() < words[oldIdx].size();
        }

        return newIdx < oldIdx;
    }

    void updateBest(int node, int idx) {
        if (better(idx, trie[node].bestIndex)) {
            trie[node].bestIndex = idx;
        }
    }

    void insertWord(string &word, int idx) {
        int node = 0;
        updateBest(node, idx);

        for (int i = word.size() - 1; i >= 0; i--) {
            int c = word[i] - 'a';

            if (trie[node].child[c] == -1) {
                trie[node].child[c] = trie.size();
                trie.push_back(Node());
            }

            node = trie[node].child[c];
            updateBest(node, idx);
        }
    }

    int queryWord(string &q) {
        int node = 0;
        int ans = trie[node].bestIndex;

        for (int i = q.size() - 1; i >= 0; i--) {
            int c = q[i] - 'a';

            if (trie[node].child[c] == -1) break;

            node = trie[node].child[c];
            ans = trie[node].bestIndex;
        }

        return ans;
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        words = wordsContainer;

        trie.clear();
        trie.push_back(Node());

        for (int i = 0; i < wordsContainer.size(); i++) {
            insertWord(wordsContainer[i], i);
        }

        vector<int> ans;

        for (string &q : wordsQuery) {
            ans.push_back(queryWord(q));
        }

        return ans;
    }
};
