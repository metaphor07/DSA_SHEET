class Solution {
public:
    bool canSplit(vector<int>& nums, int k, int maxAllowed) {
        int groups = 1;
        int curr = 0;

        for (int x : nums) {
            if (curr + x > maxAllowed) {
                groups++;
                curr = 0;
            }

            curr += x;
        }

        return groups <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canSplit(nums, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
