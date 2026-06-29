// Q3. Minimum Operations to Make Median of Array Equal to K
// Status: Yellow
// Time: O(n log n)
// Space: O(1) extra excluding sort

class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int mid = n / 2;
        long long ans = 0;

        if (nums[mid] < k) {
            for (int i = mid; i < n; i++) {
                if (nums[i] < k) ans += k - nums[i];
            }
        } else {
            for (int i = 0; i <= mid; i++) {
                if (nums[i] > k) ans += nums[i] - k;
            }
        }

        return ans;
    }
};
