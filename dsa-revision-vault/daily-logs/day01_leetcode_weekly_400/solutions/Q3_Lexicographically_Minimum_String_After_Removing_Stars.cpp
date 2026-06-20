// Q3. Lexicographically Minimum String After Removing Stars
// Topic: Greedy + 26 stacks
// Time: O(26 * number_of_stars + n) = O(n)
// Space: O(n)

class Solution {
public:
    string clearStars(string s) {
        int n = s.size();

        vector<vector<int>> pos(26);
        vector<bool> removed(n, false);

        for (int i = 0; i < n; i++) {
            if (s[i] != '*') {
                pos[s[i] - 'a'].push_back(i);
            } else {
                removed[i] = true;

                // Remove the rightmost occurrence of the smallest available character.
                for (int ch = 0; ch < 26; ch++) {
                    if (!pos[ch].empty()) {
                        int idx = pos[ch].back();
                        pos[ch].pop_back();
                        removed[idx] = true;
                        break;
                    }
                }
            }
        }

        string ans;
        for (int i = 0; i < n; i++) {
            if (!removed[i]) ans += s[i];
        }

        return ans;
    }
};
