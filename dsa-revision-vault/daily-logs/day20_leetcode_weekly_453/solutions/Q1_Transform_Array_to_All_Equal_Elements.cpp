// Q1. Transform Array to All Equal Elements
// Topic: Adjacent flip greedy
// Time: O(n)
// Space: O(n)

class Solution {
public:
    bool check(vector<int>& nums, int k, int target) {
        int n = nums.size();

        vector<int> temp = nums;
        int ops = 0;

        for (int i = 0; i < n - 1; i++) {
            if (temp[i] != target) {
                temp[i] *= -1;
                temp[i + 1] *= -1;
                ops++;
            }
        }

        return temp[n - 1] == target && ops <= k;
    }

    bool canMakeEqual(vector<int>& nums, int k) {
        return check(nums, k, 1) || check(nums, k, -1);
    }
};
