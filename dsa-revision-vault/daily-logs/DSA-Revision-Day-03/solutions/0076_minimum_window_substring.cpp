class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        unordered_map<char, int> need, window;

        for (char c : t) {
            need[c]++;
        }

        int required = need.size();
        int formed = 0;

        int l = 0;
        int bestLen = INT_MAX;
        int bestStart = 0;

        for (int r = 0; r < s.size(); r++) {
            char c = s[r];
            window[c]++;

            if (need.count(c) && window[c] == need[c]) {
                formed++;
            }

            while (formed == required) {
                if (r - l + 1 < bestLen) {
                    bestLen = r - l + 1;
                    bestStart = l;
                }

                char leftChar = s[l];
                window[leftChar]--;

                if (need.count(leftChar) && window[leftChar] < need[leftChar]) {
                    formed--;
                }

                l++;
            }
        }

        return bestLen == INT_MAX ? "" : s.substr(bestStart, bestLen);
    }
};
