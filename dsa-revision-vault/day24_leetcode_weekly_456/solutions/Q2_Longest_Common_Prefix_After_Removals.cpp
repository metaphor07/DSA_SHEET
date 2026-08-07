// Q2. Longest Common Prefix Between Adjacent Strings After Removals
// Topic: LCP + multiset
// Time: O(n * L * log n)
// Space: O(n)

class Solution {
public:
    int lcp(string& a, string& b) {
        int len = min(a.size(), b.size());

        int i = 0;
        while (i < len && a[i] == b[i]) {
            i++;
        }

        return i;
    }

    vector<int> longestCommonPrefix(vector<string>& words) {
        int n = words.size();

        multiset<int> ms;

        for (int i = 0; i + 1 < n; i++) {
            ms.insert(lcp(words[i], words[i + 1]));
        }

        vector<int> ans(n, 0);

        auto removePair = [&](int i, int j) {
            if (i >= 0 && j < n && i < j) {
                int val = lcp(words[i], words[j]);
                auto it = ms.find(val);

                if (it != ms.end()) {
                    ms.erase(it);
                }
            }
        };

        auto addPair = [&](int i, int j) {
            if (i >= 0 && j < n && i < j) {
                ms.insert(lcp(words[i], words[j]));
            }
        };

        for (int i = 0; i < n; i++) {
            removePair(i - 1, i);
            removePair(i, i + 1);

            addPair(i - 1, i + 1);

            if (!ms.empty()) {
                ans[i] = *ms.rbegin();
            }

            removePair(i - 1, i + 1);

            addPair(i - 1, i);
            addPair(i, i + 1);
        }

        return ans;
    }
};
