// Q2. Count Special Triplets
// Topic: left/right frequency maps
// Time: O(n)
// Space: O(n)

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1000000007;

        unordered_map<long long, long long> leftFreq;
        unordered_map<long long, long long> rightFreq;

        for (int x : nums) {
            rightFreq[x]++;
        }

        long long ans = 0;

        for (int j = 0; j < nums.size(); j++) {
            long long mid = nums[j];

            rightFreq[mid]--;

            long long target = 2LL * mid;

            long long leftCount = leftFreq[target];
            long long rightCount = rightFreq[target];

            ans = (ans + leftCount * rightCount) % MOD;

            leftFreq[mid]++;
        }

        return (int)ans;
    }
};
