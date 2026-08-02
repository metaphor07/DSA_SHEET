// Q3. Count Partitions With Max-Min at Most K
// Brute check version for learning only.
// Time: O(n^3), may TLE.

class Solution {
public:
    const int MOD = 1000000007;
    vector<int> dp;

    bool check(vector<int>& nums, int k, int start, int end) {
        int maxEle = *max_element(nums.begin() + start, nums.begin() + end + 1);
        int minEle = *min_element(nums.begin() + start, nums.begin() + end + 1);

        return (maxEle - minEle) <= k;
    }

    int recFun(int start, vector<int>& nums, int k) {
        int n = nums.size();

        if (start == n) {
            return 1;
        }

        if (dp[start] != -1) {
            return dp[start];
        }

        long long ans = 0;

        for (int end = start; end < n; end++) {
            if (check(nums, k, start, end)) {
                ans += recFun(end + 1, nums, k);
                ans %= MOD;
            }
        }

        return dp[start] = ans;
    }

    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        dp.assign(n, -1);
        return recFun(0, nums, k);
    }
};
