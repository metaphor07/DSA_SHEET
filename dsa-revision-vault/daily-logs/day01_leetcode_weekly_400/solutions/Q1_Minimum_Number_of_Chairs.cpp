// Q1. Minimum Number of Chairs in a Waiting Room
// Topic: Simulation / Counting
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int minimumChairs(string s) {
        int curr = 0;
        int ans = 0;

        for (char c : s) {
            if (c == 'E') {
                curr++;
                ans = max(ans, curr);
            } else {
                curr--;
            }
        }

        return ans;
    }
};
