// Q2. Lexicographically Smallest String After Operations With Constraint
// Status: Green
// Time: O(n)
// Space: O(1) excluding output

class Solution {
public:
    string getSmallestString(string s, int k) {
        string ans = "";

        for (char c : s) {
            int costToA = min(c - 'a', 'z' - c + 1);

            if (costToA <= k) {
                ans += 'a';
                k -= costToA;
            } else {
                char newC = c - k;
                ans += newC;
                k = 0;
            }
        }

        return ans;
    }
};
