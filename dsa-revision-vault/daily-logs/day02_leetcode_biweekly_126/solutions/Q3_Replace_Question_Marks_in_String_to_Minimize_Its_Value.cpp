// Q3. Replace Question Marks in String to Minimize Its Value
// Time: O(n * 26 + q log q), Space: O(n)

class Solution {
public:
    string minimizeStringValue(string s) {
        vector<int> freq(26, 0);

        for (char c : s) {
            if (c != '?') freq[c - 'a']++;
        }

        vector<char> chosen;

        for (char c : s) {
            if (c == '?') {
                int best = 0;

                for (int ch = 1; ch < 26; ch++) {
                    if (freq[ch] < freq[best]) {
                        best = ch;
                    }
                }

                chosen.push_back(char('a' + best));
                freq[best]++;
            }
        }

        sort(chosen.begin(), chosen.end());

        int ptr = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '?') s[i] = chosen[ptr++];
        }

        return s;
    }
};
