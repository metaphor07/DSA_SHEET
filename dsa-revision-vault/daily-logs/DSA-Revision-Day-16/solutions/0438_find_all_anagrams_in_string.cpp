class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();

        if (n < m) return {};

        vector<int> need(26, 0);
        vector<int> window(26, 0);

        for (char c : p) need[c - 'a']++;

        for (int i = 0; i < m; i++) {
            window[s[i] - 'a']++;
        }

        vector<int> ans;

        if (window == need) ans.push_back(0);

        for (int r = m; r < n; r++) {
            window[s[r - m] - 'a']--;
            window[s[r] - 'a']++;

            if (window == need) ans.push_back(r - m + 1);
        }

        return ans;
    }
};
