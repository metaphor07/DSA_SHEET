// Q3. Maximum Product of First and Last Elements of a Subsequence
// Topic: suffix min/max while scanning from right
// Time: O(n)
// Space: O(1)

class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n = nums.size();

        long long ans = LLONG_MIN;

        int maxEle = INT_MIN;
        int minEle = INT_MAX;

        for (int i = n - m; i >= 0; i--) {
            int rightIndex = i + m - 1;

            maxEle = max(maxEle, nums[rightIndex]);
            minEle = min(minEle, nums[rightIndex]);

            long long val = nums[i];

            if (val < 0) {
                ans = max(ans, val * minEle);
            } else {
                ans = max(ans, val * maxEle);
            }
        }

        return ans;
    }
};
