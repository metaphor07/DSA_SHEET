// Q1. Longest Strictly Increasing or Strictly Decreasing Subarray
// Status: Green
// User solution
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;

        int ans = 1, inccur = 1, deccur = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i - 1] < nums[i]) {
                inccur++;
                deccur = 1;
            } else if (nums[i - 1] > nums[i]) {
                deccur++;
                inccur = 1;
            } else {
                deccur = 1;
                inccur = 1;
            }

            ans = max(ans, max(inccur, deccur));
        }

        return ans;
    }
};
