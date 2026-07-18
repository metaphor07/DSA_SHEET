// Q3. Minimum Adjacent Swaps to Partition Array
// Topic: Inversion counting on categories
//
// nums[i] < a       => 0
// a <= nums[i] <= b => 1
// nums[i] > b       => 2
//
// Final categories should be sorted: 0 0 1 1 2 2
// Minimum adjacent swaps = inversion count.

class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        const long long MOD = 1000000007LL;

        long long cnt0 = 0;
        long long cnt1 = 0;
        long long cnt2 = 0;
        long long ans = 0;

        for (int x : nums) {
            int cat;

            if (x < a) {
                cat = 0;
            } else if (x <= b) {
                cat = 1;
            } else {
                cat = 2;
            }

            if (cat == 0) {
                ans += cnt1 + cnt2;
                cnt0++;
            } else if (cat == 1) {
                ans += cnt2;
                cnt1++;
            } else {
                cnt2++;
            }

            ans %= MOD;
        }

        return ans;
    }
};
