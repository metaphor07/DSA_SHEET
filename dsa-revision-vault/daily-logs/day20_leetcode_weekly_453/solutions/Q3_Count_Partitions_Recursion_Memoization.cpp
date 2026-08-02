// Q3. Count Partitions With Max-Min at Most K
// Topic: Partition DP + recursion memoization
// Time: O(n^2)
// Space: O(n)

class Solution {
public:
    const int MOD = 1000000007;
    vector<int> dp;

    int recFun(int start, vector<int>& nums, int k) {
        int n = nums.size();

        if (start == n) {
            return 1;
        }

        if (dp[start] != -1) {
            return dp[start];
        }

        long long ans = 0;

        int maxEle = INT_MIN;
        int minEle = INT_MAX;

        for (int end = start; end < n; end++) {
            maxEle = max(maxEle, nums[end]);
            minEle = min(minEle, nums[end]);

            if (maxEle - minEle <= k) {
                ans += recFun(end + 1, nums, k);
                ans %= MOD;
            } else {
                break;
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
