// Q3. Maximum Subarray Sum After Multiplier
// Status: Red
// Key idea: Kadane + 3 states
// Time: O(n)
// Space: O(1)

class Solution {
public:
    long long solve(vector<int>& nums, int k, bool multiply) {
        long long dp0 = nums[0];
        long long modified = multiply ? 1LL * nums[0] * k : nums[0] / k;

        long long dp1 = modified;
        long long dp2 = LLONG_MIN / 4;

        long long ans = dp1;

        for (int i = 1; i < nums.size(); i++) {
            long long x = nums[i];
            long long y = multiply ? x * k : x / k;

            long long newDp0 = max(x, dp0 + x);

            long long newDp1 = max({
                y,
                dp0 + y,
                dp1 + y
            });

            long long newDp2 = max(
                dp1 + x,
                dp2 + x
            );

            dp0 = newDp0;
            dp1 = newDp1;
            dp2 = newDp2;

            ans = max({ans, dp1, dp2});
        }

        return ans;
    }

    long long maxSubarraySum(vector<int>& nums, int k) {
        return max(solve(nums, k, true), solve(nums, k, false));
    }
};
