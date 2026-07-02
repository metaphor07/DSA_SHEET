// Q1. Count the Number of Special Characters I
// Status: Green
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> lower(26, false), upper(26, false);

        for (char c : word) {
            if ('a' <= c && c <= 'z') lower[c - 'a'] = true;
            else upper[c - 'A'] = true;
        }

        int ans = 0;

        for (int i = 0; i < 26; i++) {
            if (lower[i] && upper[i]) ans++;
        }

        return ans;
    }
};
