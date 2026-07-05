// Q4. Palindromic Subarray Sum
// Status: Red
// Topic: Manacher's algorithm on array + prefix sum
// Time: O(n)
// Space: O(n)

class Solution {
public:
    long long getSum(vector<int>& nums) {
        int n = nums.size();

        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }

        auto rangeSum = [&](int l, int r) -> long long {
            return pref[r + 1] - pref[l];
        };

        vector<int> d1(n);
        vector<int> d2(n);

        int l = 0, r = -1;

        for (int i = 0; i < n; i++) {
            int k = 1;

            if (i <= r) {
                k = min(d1[l + r - i], r - i + 1);
            }

            while (i - k >= 0 && i + k < n && nums[i - k] == nums[i + k]) {
                k++;
            }

            d1[i] = k;

            if (i + k - 1 > r) {
                l = i - k + 1;
                r = i + k - 1;
            }
        }

        l = 0;
        r = -1;

        for (int i = 0; i < n; i++) {
            int k = 0;

            if (i <= r) {
                k = min(d2[l + r - i + 1], r - i + 1);
            }

            while (i - k - 1 >= 0 && i + k < n && nums[i - k - 1] == nums[i + k]) {
                k++;
            }

            d2[i] = k;

            if (i + k - 1 > r) {
                l = i - k;
                r = i + k - 1;
            }
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int radius = d1[i];

            int left = i - radius + 1;
            int right = i + radius - 1;

            ans = max(ans, rangeSum(left, right));
        }

        for (int i = 0; i < n; i++) {
            int radius = d2[i];

            if (radius == 0) continue;

            int left = i - radius;
            int right = i + radius - 1;

            ans = max(ans, rangeSum(left, right));
        }

        return ans;
    }
};
