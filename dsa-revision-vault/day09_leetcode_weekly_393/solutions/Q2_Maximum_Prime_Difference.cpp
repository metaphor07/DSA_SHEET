// Q2. Maximum Prime Difference
// Status: Green
// Time: O(n * sqrt(max(nums[i])))
// Space: O(1)

class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;

        for (long long i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }

        return true;
    }

    int maximumPrimeDifference(vector<int>& nums) {
        int firstPrimeIndex = -1;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (isPrime(nums[i])) {
                if (firstPrimeIndex == -1) {
                    firstPrimeIndex = i;
                }

                ans = i - firstPrimeIndex;
            }
        }

        return ans;
    }
};
