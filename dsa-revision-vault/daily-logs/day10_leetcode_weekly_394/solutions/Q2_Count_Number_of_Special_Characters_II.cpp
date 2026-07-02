// Q2. Count the Number of Special Characters II
// Status: Green
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lastLower(26, -1);
        vector<int> firstUpper(26, 1e9);

        for (int i = 0; i < word.size(); i++) {
            char c = word[i];

            if ('a' <= c && c <= 'z') {
                lastLower[c - 'a'] = i;
            } else {
                firstUpper[c - 'A'] = min(firstUpper[c - 'A'], i);
            }
        }

        int ans = 0;

        for (int i = 0; i < 26; i++) {
            if (lastLower[i] != -1 && firstUpper[i] != 1e9 && lastLower[i] < firstUpper[i]) {
                ans++;
            }
        }

        return ans;
    }
};
