// Q2. Subsequence After One Replacement
// Status: Yellow
// Topic: Prefix subsequence + suffix subsequence
// Time: O(n + m)
// Space: O(n)

class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();

        if (n > m) return false;

        const int INF = 1e9;

        vector<int> left(n + 1, INF);
        left[0] = 0;

        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < m && t[j] != s[i]) {
                j++;
            }

            if (j < m) {
                left[i + 1] = j + 1;
                j++;
            } else {
                break;
            }
        }

        if (left[n] != INF) return true;

        vector<int> right(n + 1, -1);
        right[n] = m;

        j = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            while (j >= 0 && t[j] != s[i]) {
                j--;
            }

            if (j >= 0) {
                right[i] = j;
                j--;
            } else {
                break;
            }
        }

        for (int p = 0; p < n; p++) {
            if (left[p] != INF && right[p + 1] != -1) {
                if (left[p] < right[p + 1]) {
                    return true;
                }
            }
        }

        return false;
    }
};
