// Q3. Process String with Special Operations II
// Topic: final length + reverse index tracing

class Solution {
public:
    char processStr(string s, long long k) {
        long long len = 0;
        const long long LIMIT = (long long)4e18;

        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                len++;
            } else if (c == '*') {
                if (len > 0) {
                    len--;
                }
            } else if (c == '#') {
                len *= 2;
            } else if (c == '%') {
                continue;
            }

            if (len > LIMIT) {
                len = LIMIT;
            }
        }

        if (k >= len) {
            return '.';
        }

        for (int i = (int)s.size() - 1; i >= 0; i--) {
            char c = s[i];

            if (c >= 'a' && c <= 'z') {
                if (k == len - 1) {
                    return c;
                }

                len--;
            } else if (c == '*') {
                len++;
            } else if (c == '#') {
                long long half = len / 2;
                k %= half;
                len = half;
            } else if (c == '%') {
                k = len - 1 - k;
            }
        }

        return '.';
    }
};
