// Q4. Find the Median of the Uniqueness Array
// Status: Red
// Topic: Binary search on answer + sliding window
// Time: O(n log n)
// Space: O(n)

class Solution {
public:
    long long countAtMostK(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        int left = 0;
        int distinct = 0;
        long long count = 0;

        for (int right = 0; right < nums.size(); right++) {
            freq[nums[right]]++;

            if (freq[nums[right]] == 1) {
                distinct++;
            }

            while (distinct > k) {
                freq[nums[left]]--;

                if (freq[nums[left]] == 0) {
                    distinct--;
                }

                left++;
            }

            count += right - left + 1;
        }

        return count;
    }

    int medianOfUniquenessArray(vector<int>& nums) {
        int n = nums.size();

        long long totalSubarrays = 1LL * n * (n + 1) / 2;
        long long medianPosition = (totalSubarrays + 1) / 2;

        int low = 1;
        int high = n;
        int ans = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (countAtMostK(nums, mid) >= medianPosition) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
