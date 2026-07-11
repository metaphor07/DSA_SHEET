// Q3. Minimum Length of Anagram Concatenation
// Status: Green
// Topic: Divisors + frequency comparison
// Time: O(number_of_divisors * n * 26)
// Space: O(26)

class Solution {
public:
    bool isAnagramBlockLength(int len, string& s) {
        int n = s.size();

        vector<int> base(26, 0);

        for (int i = 0; i < len; i++) {
            base[s[i] - 'a']++;
        }

        for (int start = len; start < n; start += len) {
            vector<int> cur(26, 0);

            for (int j = start; j < start + len; j++) {
                cur[s[j] - 'a']++;
            }

            if (cur != base) return false;
        }

        return true;
    }

    int minAnagramLength(string s) {
        int n = s.size();

        for (int len = 1; len <= n; len++) {
            if (n % len == 0 && isAnagramBlockLength(len, s)) {
                return len;
            }
        }

        return n;
    }
};
