// Q2. User's incremental approach
// This is also optimal.

class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long total = 0;
        long long previous = 0;

        for (char ch : s) {
            if (ch == c) {
                total += previous + 1;
                previous++;
            }
        }

        return total;
    }
};
