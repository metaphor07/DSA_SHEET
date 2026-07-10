// Q3. Minimum Array End
// Easier-to-understand bit filling

class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = x;
        long long num = n - 1;

        long long bit = 1;

        while (num > 0) {
            while (ans & bit) {
                bit <<= 1;
            }

            if (num & 1) {
                ans |= bit;
            }

            num >>= 1;
            bit <<= 1;
        }

        return ans;
    }
};
