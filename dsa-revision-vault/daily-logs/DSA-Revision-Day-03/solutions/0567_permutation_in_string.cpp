class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if (n > m) return false;

        vector<int> need(26, 0), window(26, 0);

        for (char c : s1) {
            need[c - 'a']++;
        }

        for (int r = 0; r < m; r++) {
            window[s2[r] - 'a']++;

            if (r >= n) {
                window[s2[r - n] - 'a']--;
            }

            if (window == need) {
                return true;
            }
        }

        return false;
    }
};
