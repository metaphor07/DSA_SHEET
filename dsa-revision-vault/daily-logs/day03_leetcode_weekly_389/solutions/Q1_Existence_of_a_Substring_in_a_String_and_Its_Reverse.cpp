// Q1. Existence of a Substring in a String and Its Reverse
// Topic: String / seen pairs
// Time: O(n)
// Space: O(26 * 26)

class Solution {
public:
    bool isSubstringPresent(string s) {
        int n = s.size();

        vector<vector<bool>> seen(26, vector<bool>(26, false));

        for (int i = 0; i < n - 1; i++) {
            int a = s[i] - 'a';
            int b = s[i + 1] - 'a';

            if (seen[b][a]) return true;

            seen[a][b] = true;
        }

        return false;
    }
};
