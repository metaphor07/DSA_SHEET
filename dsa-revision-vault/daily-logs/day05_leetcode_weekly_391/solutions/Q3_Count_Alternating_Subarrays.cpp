// Q3. Count Alternating Subarrays
// Topic: Sliding window / counting
// Time: O(n)
// Space: O(1)

class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long ans = 0;
        long long len = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] != nums[i - 1]) {
                len++;
            } else {
                len = 1;
            }

            ans += len;
        }

        return ans;
    }
};
