// Q1. Transform Array to All Equal Elements
// Optimized without copying
// Time: O(n)
// Space: O(1)

class Solution {
public:
    bool check(vector<int>& nums, int k, int target) {
        int n = nums.size();

        int ops = 0;
        int flip = 1;

        for (int i = 0; i < n - 1; i++) {
            int cur = nums[i] * flip;

            if (cur == target) {
                flip = 1;
            } else {
                ops++;
                flip = -1;
            }
        }

        return ops <= k && nums[n - 1] * flip == target;
    }

    bool canMakeEqual(vector<int>& nums, int k) {
        return check(nums, k, 1) || check(nums, k, -1);
    }
};
