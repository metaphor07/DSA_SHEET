// Q1. Latest Time You Can Obtain After Replacing Characters
// Status: Green
// Time: O(1)
// Space: O(1)

class Solution {
public:
    string findLatestTime(string s) {
        // Format: "hh:mm", valid time range: 00:00 to 11:59.

        if (s[0] == '?') {
            if (s[1] == '?' || s[1] <= '1') s[0] = '1';
            else s[0] = '0';
        }

        if (s[1] == '?') {
            if (s[0] == '1') s[1] = '1';
            else s[1] = '9';
        }

        if (s[3] == '?') s[3] = '5';
        if (s[4] == '?') s[4] = '9';

        return s;
    }
};
