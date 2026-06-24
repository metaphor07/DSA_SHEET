// Q2. Count Substrings Starting and Ending with Given Character
// Topic: Counting / combinatorics
// Time: O(n)
// Space: O(1)

class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long cnt = 0;

        for (char ch : s) {
            if (ch == c) {
                cnt++;
            }
        }

        return cnt * (cnt + 1) / 2;
    }
};
