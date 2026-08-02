// Q2. Count the Number of Computer Unlocking Permutations
// Topic: Math / observation
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        const int MOD = 1000000007;

        int n = complexity.size();

        for (int i = 1; i < n; i++) {
            if (complexity[i] <= complexity[0]) {
                return 0;
            }
        }

        long long ans = 1;

        for (int i = 1; i <= n - 1; i++) {
            ans = (ans * i) % MOD;
        }

        return ans;
    }
};
