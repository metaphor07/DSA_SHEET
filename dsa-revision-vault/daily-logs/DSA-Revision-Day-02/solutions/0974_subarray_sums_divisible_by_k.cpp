// LeetCode 974: Subarray Sums Divisible by K
// Pattern: Prefix sum + remainder frequency
// Time: O(n)
// Space: O(k)

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> freq(k, 0);
        freq[0] = 1;

        int prefixSum = 0;
        int count = 0;

        for (int num : nums) {
            prefixSum += num;

            int rem = prefixSum % k;
            if (rem < 0) rem += k;

            count += freq[rem];
            freq[rem]++;
        }

        return count;
    }
};

