// Q1. Maximum Total Sum of K Selected Elements
// Status: Solved in one attempt
// Time: O(n log n)
// Space: O(1) extra, ignoring sort

class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        long long total_sum = 0;

        for (int i = n - 1; i >= n - k; i--) {
            if (mul > 0) {
                total_sum += 1LL * nums[i] * mul;
                mul--;
            } else {
                total_sum += nums[i];
            }
        }

        return total_sum;
    }
};
