// Q1. Maximize Pair Strength Using GCD
// Topic: Brute force pairs + gcd
// Time: O(n^2 log(max(nums)))
// Space: O(1)

class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long g = gcd(nums[i], nums[j]);
                long long a = nums[i] / g;
                long long b = nums[j] / g;
                ans = max(ans, a * b);
            }
        }

        return ans;
    }
};
