// Q4. Count Distinct Ways to Form Target from Two Strings
// Topic: Recursion + memoization
// State: rec(pos, last1, last2, usedMask)
// Note: This version is easier to understand, but bottom-up DP is more efficient.

class Solution {
public:
    const int MOD = 1e9 + 7;

    string w1, w2, tar;
    int n, m, t;

    vector<vector<int>> pos1, pos2;
    unordered_map<long long, int> memo;

    long long makeKey(int pos, int last1, int last2, int mask) {
        long long key = pos;
        key = key * (n + 1) + (last1 + 1);
        key = key * (m + 1) + (last2 + 1);
        key = key * 4 + mask;
        return key;
    }

    int rec(int pos, int last1, int last2, int mask) {
        if (pos == t) {
            return mask == 3;
        }

        long long key = makeKey(pos, last1, last2, mask);

        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        long long ans = 0;
        int ch = tar[pos] - 'a';

        // Choose current target character from word1.
        auto &v1 = pos1[ch];
        auto it1 = upper_bound(v1.begin(), v1.end(), last1);

        while (it1 != v1.end()) {
            int idx = *it1;
            ans += rec(pos + 1, idx, last2, mask | 1);
            ans %= MOD;
            it1++;
        }

        // Choose current target character from word2.
        auto &v2 = pos2[ch];
        auto it2 = upper_bound(v2.begin(), v2.end(), last2);

        while (it2 != v2.end()) {
            int idx = *it2;
            ans += rec(pos + 1, last1, idx, mask | 2);
            ans %= MOD;
            it2++;
        }

        return memo[key] = ans;
    }

    int interleaveCharacters(string word1, string word2, string target) {
        w1 = word1;
        w2 = word2;
        tar = target;

        n = w1.size();
        m = w2.size();
        t = tar.size();

        pos1.assign(26, {});
        pos2.assign(26, {});

        for (int i = 0; i < n; i++) {
            pos1[w1[i] - 'a'].push_back(i);
        }

        for (int i = 0; i < m; i++) {
            pos2[w2[i] - 'a'].push_back(i);
        }

        memo.clear();

        return rec(0, -1, -1, 0);
    }
};
